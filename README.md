# When Fine-Tuning LLMs Meets Data Privacy: An Empirical Study of Federated Learning in LLM-Based Program Repair
This is the artifact for the work "When Fine-Tuning LLMs Meets Data Privacy: An Empirical Study of Federated Learning in LLM-Based Program Repair".

## I. Environments
- Recommended system: Ubuntu 20.04
- Transformers version 4.38.2
- Federated learning package & others (e.g., Python, Pytorch, Cuda, etc.): Please refer to the installation of [FederatedScope](https://github.com/alibaba/FederatedScope/tree/llm)

## II. Main Project Structure
```
├── Model                      # directory where the llms and the fine-tuned llms are saved
├── Data                       # directory of the datasets
│   ├── eval_java              # the EvalRepair-Java benchmark
├── FederatedScope             # the federated learning package on which we develop our components
│   ├── federatedscope
│   ├──   ├── llm
│   ├──   ├──   ├── MyScripts  # the fine-tuning scripts
│   ├──   ├──   ├── MyUtils    # some preprocessing and intermediate utils
├── RoPGen                     # coding style extractor
```

## III. Model
The code LLMs used in this study are available via HuggingFace:
- [CodeLlama-13B-Instruct](https://huggingface.co/meta-llama/CodeLlama-13b-Instruct-hf)
- [CodeLlama-7B-Instruct](https://huggingface.co/meta-llama/CodeLlama-7b-Instruct-hf)
- [DeepseekCoder-7B-Instruct-V1.5](https://huggingface.co/deepseek-ai/deepseek-coder-7b-instruct-v1.5)
- [WizardCoder-15B-V1.0](https://huggingface.co/WizardLMTeam/WizardCoder-15B-V1.0)
- [Mistral-7B-Instruct-v0.2](https://huggingface.co/mistralai/Mistral-7B-Instruct-v0.2)
- [CodeQwen1.5-7B-Chat](https://huggingface.co/Qwen/CodeQwen1.5-7B-Chat)

## IV. Data
### TutorCode
The fine-tuning dataset TutorCode restricts its access to prevent data leakage caused by web crawlers, which collect web data as the pretraining corpora for LLMs. Please use the dataset via the official API of [TutorCode](https://github.com/buaabarty/CREF).

### Fine-tuning Dataset
After acquiring the original json files from the TutorCode API, the formatted fine-tuning dataset can be constructed by [extract_from_morepair.py](FederatedScope/federatedscope/llm/MyUtils/extract_from_tutorcode.py):
```
python extract_from_tutorcode.py <directory of the json files> <path to the fine-tuning dataset>
```

### Evaluation Benchmark
In the directory eval_java is the [EvalRepair-Java](https://github.com/buaabarty/morepair) benchmark, which consists of augmented test cases from HumanEval-Java.

## V. Experiments
### RQ1. Effectiveness of Federated Fine-tuning
#### Federated Fine-tuning
```
python FederatedScope/federatedscope/main.py --cfg federatedscope/llm/MyScripts/<model name>/rq1/finetune_<model name>.yaml
```
#### Centralized Fine-tuning
```
python FederatedScope/federatedscope/main.py --cfg federatedscope/llm/MyScripts/<model name>/rq1/finetune_<model name>_global.yaml
```
#### Local fine-tuning
```
python FederatedScope/federatedscope/main.py --cfg federatedscope/llm/MyScripts/<model name>/rq1/finetune_<model name>_local.yaml
```
The model name can be referred to as follows:
|Model|\<model name>|
|:---:|:---:|
|CodeLlama-13B-Instruct|codellama13b|
|CodeLlama-7B-Instruct|codellama7b|
|DeepseekCoder-7B-Instruct-V1.5|deepseek7b|
|WizardCoder-15B-V1.0|wizard15b|
|Mistral-7B-Instruct-v0.2|mistral7b|
|CodeQwen1.5-7B-Chat|codeqwen7b|
### RQ2. Impact of Data Heterogeneity
#### Construction of Heterogeneous Code
**1. Heterogeneous Coding Style**
```
# preprocessing
# extract cpp files from original crawled TutorCode json files and save it to the specified directory
python FederatedScope/federatedscope/llm/MyUtils/extract_cpp.py <directory of the original TutorCode json files> RoPGen/src/coding style attacks/author-style-transform/transform/program_file/target_author_file

# put each cpp file in a directory to satisfy the format of RoPGen input
python FederatedScope/federatedscope/llm/MyUtils/put_in_dir.py RoPGen/src/coding style attacks/author-style-transform/transform/program_file/target_author_file

# extract coding style
# the extracted coding styles will be saved in 'RoPGen/src/coding style attacks/author-style-transform/transform/author_style'
python RoPGen/src/coding style attacks/author-style-transform/transform/get_style.py

# encode and cluster coding styles
python FederatedScope/federatedscope/llm/MyUtils/style_clustering.py RoPGen/src/coding style attacks/author-style-transform/transform/author_style <fine-tuning dataset path> <clustered fine-tuning dataset path> <cluster number>
```

**2. Heterogeneous Code Complexity**
The numbers of modified hunks are used to indicate the code complexity of each bug-fix pair, as can be referred to in *data/TutorCode/hunks.json*.

**3. Heterogeneous Code Embedding**
We use [CodeBERT](https://huggingface.co/microsoft/codebert-base), which has been pretrained to capture the context information from the NL-PL pairs.
```
python FederatedScope/federatedscope/llm/MyUtils/extract_embeddings.py
```

#### Fine-tuning with Different Heterogeneity
Fine-tuning with the IID distribution:
```
python FederatedScope/federatedscope/main.py --cfg federatedscope/llm/MyScripts/<model name>/rq2/<code feature>/finetune_<model name>.yaml
```
Fine-tuning with the Non-IID distribution:
```
python FederatedScope/federatedscope/main.py --cfg federatedscope/llm/MyScripts/<model name>/rq2/<code feature>/finetune_<model name>_<non-iid degree>.yaml
```
The specific code features and Non-IID degrees can be referred to as follows:

|Code Feature|\<code feature>|
|:---:|:---:|
|Coding Style|cs|
|Code Complexity|cc|
|Code Embedding|ce|

|Non-IID Degree|\<non-iid degree>|
|:---:|:---:|
|Mild Non-IID|mild|
|Medium Non-IID|medium|
|Extreme Non-IID|ex|

### RQ3. Impact of Federated Algorithms
```
python FederatedScope/federatedscope/main.py --cfg federatedscope/llm/MyScripts/<model name>/rq3/finetune_<model name>_<algorithm>.yaml
```
The specific algorithms can be referred to as follows:

|Federated Algorithm|\<algorithm>|
|:---:|:---:|
|FedAvg|fedavg|
|FedOPT|fedopt|
|FedProx|fedprox|
|FedSWA|fedswa|
|pFedMe|per|

## VI. Inference & Evaluation
After fine-tuning the LLMs, merge the fine-tuned adapter with the base model:
```
python FederatedScope/federatedscope/llm/MyUtils/merge_model.py <directory of the original model> <directory of the fine-tuned adapter> <directory of the merged model>
```
### Inference
```
python FederatedScope/federatedscope/llm/eval/eval_for_code/inference_java.py <model name> <base model> <model name> <device> <directory of fixes>
```
### Evaluation
```
python FederatedScope/federatedscope/llm/eval/eval_for_code/calc_java.py <model name> <directory of fixes>
```
