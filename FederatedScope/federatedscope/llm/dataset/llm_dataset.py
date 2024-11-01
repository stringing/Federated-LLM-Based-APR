"""
Some code snippets are borrowed from the open-sourced stanford_alpaca (
    https://github.com/tatsu-lab/stanford_alpaca)
"""

import copy
import logging
import pandas as pd

from enum import Enum
from torch.utils.data import Dataset

logger = logging.getLogger(__name__)


class DefaultToken(Enum):
    PAD_TOKEN = "[PAD]"
    EOS_TOKEN = "</s>"
    BOS_TOKEN = "<s>"
    UNK_TOKEN = "<unk>"
    IGNORE_INDEX = -100


PROMPT_DICT = {
    "prompt_input": (
        "Below is an instruction that describes a task, "
        "paired with an input that provides further context. "
        "Write a response that appropriately completes the request.\n\n"
        "### Instruction:\n{instruction}\n\n### Input:"
        "\n{input}\n\n### Response:"),
    # "prompt_no_input": (
    #     "Below is an instruction that describes a task. "
    #     "Write a response that appropriately completes the request.\n\n"
    #     "### Instruction:\n{instruction}\n\n### Response:"),
    "prompt_no_input": ("{instruction}"),
    "prompt_text": ("{input1}{output1}{input2}{output2}"),
}


class LLMDataset(Dataset):
    """
    A dataset for language modeling tasks.

    This class inherits from torch.utils.data.Dataset and implements a
    dataset that can load and preprocess data for language modeling. It
    takes a list of data dictionaries, a tokenizer, and optional prompt
    templates as input, and creates input ids, labels, and categories as
    output. The input ids and labels are padded and masked according to
    the tokenizer settings and the source and target lengths. The
    categories are encoded as integers using pandas.Categorical.

    Attributes:
        input_ids: A list of torch.LongTensor objects of shape (max_length,)
            containing the padded input ids.
        labels: A list of torch.LongTensor objects of shape (max_length,)
            containing the padded labels.
        categories: A list of integers representing the category codes.
        tokenizer: A transformers.PreTrainedTokenizer object that can
            encode and decode text.
    """
    def __init__(self,
                 list_data_dict,
                 tokenizer,
                 mo=False,
                 prompt_input=PROMPT_DICT["prompt_input"],
                 prompt_no_input=PROMPT_DICT["prompt_no_input"],
                 prompt_text=PROMPT_DICT["prompt_text"]):
        """
        Initializes the dataset with the given arguments.

        Args:
            list_data_dict: A list of dictionaries, each containing input,
                output, and optionally category keys and values as strings.
            tokenizer: A transformers.PreTrainedTokenizer object that can
                encode and decode text.
            prompt_input: An optional string template for creating the source
                text when the input key is present in the data dictionary.
                The template can use {input}, {output}, and {category} as
                placeholders for the corresponding values. The default value
                is PROMPT_DICT["prompt_input"].
            prompt_no_input: An optional string template for creating the
                source text when the input key is not present in the data
                dictionary. The template can use {output} and {category} as
                placeholders for the corresponding values. The default value is
                PROMPT_DICT["prompt_no_input"].
        """
        super(LLMDataset, self).__init__()
        
        if mo:
            sources_1 = [
                f"{example['input1']}"
                for example in list_data_dict
            ]
            sources_2 = [
                f"{example['input2']}"
                for example in list_data_dict
            ]
            targets_1 = [
                f"{example['output1']}"
                for example in list_data_dict
            ]
            targets_2 = [
                f"{example['output2']}"
                for example in list_data_dict
            ]
            data_dict = self.mo_preprocess(sources_1, sources_2, targets_1, targets_2, tokenizer)
            
            self.input_ids = data_dict["input_ids"]
            self.labels = data_dict["labels"]
            self.mo = True
        else:
            sources = [
                prompt_input.format_map(example) if example.get("input", "") != ""
                else prompt_no_input.format_map(example)
                for example in list_data_dict
            ]
            targets = [
                f"{example['output']}{tokenizer.eos_token}"
                for example in list_data_dict
            ]

            data_dict = self.preprocess(sources, targets, tokenizer)

            self.input_ids = data_dict["input_ids"]
            self.labels = data_dict["labels"]
            self.mo = False

        categories = [
            example['category'] if 'category' in example else None
            for example in list_data_dict
        ]
        df = pd.DataFrame(categories, columns=["category"])
        self.categories = list(pd.Categorical(df["category"]).codes)

    def _tokenize_fn(self, strings, tokenizer):
        """
        Tokenizes a list of strings using the given tokenizer.

        Args:
            strings: A list of strings to be tokenized.
            tokenizer: A transformers.PreTrainedTokenizer object that can
                encode and decode text.

        Returns:
            A dictionary with the following keys and values:
                - input_ids: A list of torch.LongTensor objects of shape (
                    max_length,) containing the tokenized input ids.
                - labels: A list of torch.LongTensor objects of shape (
                    max_length,) containing the tokenized labels.
                - input_ids_lens: A list of integers representing the
                    lengths of the input ids before padding.
                - labels_lens: A list of integers representing the lengths of
                    the labels before padding.
        """
        tokenized_list = [
            tokenizer(
                text,
                return_tensors="pt",
                padding="longest",
                max_length=tokenizer.model_max_length,
                truncation=True,
            ) for text in strings
        ]
        input_ids = labels = [
            tokenized.input_ids[0] for tokenized in tokenized_list
        ]
        input_ids_lens = labels_lens = [
            tokenized.input_ids.ne(tokenizer.pad_token_id).sum().item()
            for tokenized in tokenized_list
        ]
        return dict(
            input_ids=input_ids,
            labels=labels,
            input_ids_lens=input_ids_lens,
            labels_lens=labels_lens,
        )
    
    def mo_preprocess(self, sources_1, sources_2, targets_1, targets_2, tokenizer):
        """
        Preprocesses the input text using the given tokenizer. Only for multi-objective training.

        Args:
            inputs: A list of strings representing the input texts.
            tokenizer: A transformers.PreTrainedTokenizer object that can
                encode and decode text.

        Returns:
            A dictionary with the following keys and values:
                - input_ids: A list of torch.LongTensor objects of shape (
                    max_length,) containing the padded input ids.
                - labels: A list of torch.LongTensor objects of shape (
                    max_length,) containing the padded labels.
        """
        eos_token_id = tokenizer.eos_token_id
        examples_1 = [s1 + t1 for s1, t1 in zip(sources_1, targets_1)]
        examples = [s1 + t1 + s2 + t2 for s1, t1, s2, t2 in zip(sources_1, targets_1, sources_2, targets_2)]
        examples_1_tokenized, examples_tokenized, sources_1_tokenized, sources_2_tokenized = [
            self._tokenize_fn(strings, tokenizer)
            for strings in (examples_1, examples, sources_1, sources_2)
        ]
        input_ids = examples_tokenized["input_ids"]
        labels = copy.deepcopy(input_ids)
        for label, example_1_len, source_1_len, source_2_len in zip(labels,
                                                     examples_1_tokenized["input_ids_lens"],
                                                     sources_1_tokenized["input_ids_lens"],
                                                     sources_2_tokenized["input_ids_lens"]):
            label[:source_1_len] = DefaultToken.IGNORE_INDEX.value
            label[example_1_len:example_1_len+source_2_len] = DefaultToken.IGNORE_INDEX.value
        
        return dict(input_ids=input_ids, labels=labels)
        
        

    def preprocess(self, sources, targets, tokenizer):
        """
        Preprocesses the sources and targets using the given tokenizer.

        Args:
            sources: A list of strings representing the source texts.
            targets: A list of strings representing the target texts.
            tokenizer: A transformers.PreTrainedTokenizer object that can
                encode and decode text.

        Returns:
            A dictionary with the following keys and values:
                - input_ids: A list of torch.LongTensor objects of shape (
                    max_length,) containing the padded input ids.
                - labels: A list of torch.LongTensor objects of shape (
                    max_length,) containing the padded labels.
        """
        examples = [s + t for s, t in zip(sources, targets)]
        examples_tokenized, sources_tokenized = [
            self._tokenize_fn(strings, tokenizer)
            for strings in (examples, sources)
        ]
        input_ids = examples_tokenized["input_ids"]
        labels = copy.deepcopy(input_ids)
        for label, source_len in zip(labels,
                                     sources_tokenized["input_ids_lens"]):
            label[:source_len] = DefaultToken.IGNORE_INDEX.value
        return dict(input_ids=input_ids, labels=labels)

    def __len__(self):
        return len(self.input_ids)

    def __getitem__(self, i):
        return dict(input_ids=self.input_ids[i],
                    labels=self.labels[i],
                    categories=self.categories[i],
                    mo=self.mo)
