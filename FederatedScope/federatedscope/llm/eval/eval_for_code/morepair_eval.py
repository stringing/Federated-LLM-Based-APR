import os
import torch
import json
import transformers
from transformers import GenerationConfig
from tqdm import tqdm

from federatedscope.core.configs.config import global_cfg
from federatedscope.core.cmd_args import parse_args, parse_client_cfg
from federatedscope.core.auxiliaries.utils import setup_seed
from federatedscope.core.auxiliaries.logging import update_logger
from federatedscope.llm.dataloader.dataloader import load_jsonl, load_json
from federatedscope.core.data.utils import download_url
from federatedscope.llm.misc.fschat import FSChatBot

transformers.logging.set_verbosity(40)

DEBUG = False
NUM_ANSWERS_PER_QUESTION = 10



@torch.no_grad()
def main():
    init_cfg = global_cfg.clone()
    args = parse_args()

    if args.cfg_file:
        init_cfg.merge_from_file(args.cfg_file)
    cfg_opt, client_cfg_opt = parse_client_cfg(args.opts)
    init_cfg.merge_from_list(cfg_opt)

    update_logger(init_cfg, clear_before_add=True)
    setup_seed(init_cfg.seed)

    # load your finetuned model (saved as xxx.ckpt)
    #    in yaml file federate.save_to
    fschatbot = FSChatBot(init_cfg)

    out_file = \
        f'{init_cfg.federate.save_to}_morepair_answer.jsonl'

    # Get test file
    fp = os.path.join('/root/autodl-tmp/data/morepair/morepair_cpp.json')
    list_data_dict = load_json(fp, instruction='instruction')

    answers = []
    for sample in tqdm(list_data_dict):
        input_text = sample['instruction']
        cnt = len(fschatbot.tokenizer.tokenize(input_text))
        max_d = 500
        for e in range(NUM_ANSWERS_PER_QUESTION):
            generation_config = GenerationConfig(
                temperature=0.1,
                # # # top_k=40,
                # # top_p=0.75,
                do_sample=True,
                # num_return_sequences=NUM_ANSWERS_PER_QUESTION,
                min_length=cnt+64,
                max_length=cnt+max_d
            )
            generate_kwargs = dict(
                generation_config=generation_config,
                pad_token_id=fschatbot.tokenizer.eos_token_id,
                max_new_tokens=128,
            )
            try:
                model_completions = fschatbot.generate(input_text,
                                                       generate_kwargs)
            except torch.cuda.OutOfMemoryError as error:
                print(error)
                model_completions = [
                    '' for _ in range(NUM_ANSWERS_PER_QUESTION)
                ]
                
            # for i, completion in enumerate(model_completions):
                # completion = clean_answer(completion, language_type='cpp')
            answers.append(
                dict(task_id=sample['category'], generation=model_completions))
            if DEBUG:
                print(f"task_id: {sample['category']},\n"
                      f"generation {i + 1}:\n{completion}\n\n")

    # Save as samples.jsonl for eval top@k score
    with open(out_file, 'w') as f:
        for answer in answers:
            json_str = json.dumps(answer)
            f.write(json_str + '\n')


if __name__ == "__main__":
    main()
