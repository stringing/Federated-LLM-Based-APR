# When Fine-Tuning LLMs Meets Data Privacy: An Empirical Study of Federated Learning in LLM-Based Program Repair
This is the artifact for the work "When Fine-Tuning LLMs Meets Data Privacy: An Empirical Study of Federated Learning in LLM-Based Program Repair".

## I. Environments
- Ubuntu 20.04
- Transformers 4.38.2
- Federated learning package & others (e.g., Python, Pytorch, Cuda, etc.): Please refer to the installation of [FederatedScope](https://github.com/alibaba/FederatedScope/tree/llm)

## II. Project Structure
To be continued

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
The fine-tuning dataset TutorCode restrics its access to prevent data leakage caused by web crawlers, which collect web data as the pretraining corpora for LLMs. Please use the dataset via the official API of [TutorCode](https://github.com/buaabarty/CREF).

### Fine-tuning Dataset
After acquiring the original json files from the TutorCode API, the formatted fine-tuning dataset can be constructed by [extract_from_morepair.py](FederatedScope/federatedscope/llm/MyUtils/extract_from_tutorcode.py):
```
python extract_from_tutorcode.py <directory of the json files> <path to the fine-tuning dataset>
```

## V. Experiments
Set the current directory to the federated learning package:
```
cd ./FederatedScope
```
### RQ1. Effectiveness of Federated Fine-tuning
#### Federated Fine-tuning
```
python federatedscope/main.py --cfg federatedscope/llm/MyScripts/<model name>/rq1/finetune_<model name>.yaml
```
#### Centralized Fine-tuning
```
python federatedscope/main.py --cfg federatedscope/llm/MyScripts/<model name>/rq1/finetune_<model name>_global.yaml
```
#### Local fine-tuning
```
python federatedscope/main.py --cfg federatedscope/llm/MyScripts/<model name>/rq1/finetune_<model name>_local.yaml
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

#### Fine-tuning with Different Heterogeneity
Fine-tuning with the IID distribution:
```
python federatedscope/main.py --cfg federatedscope/llm/MyScripts/<model name>/rq2/<code feature>/finetune_<model name>.yaml
```
Fine-tuning with the Non-IID distribution:
```
python federatedscope/main.py --cfg federatedscope/llm/MyScripts/<model name>/rq2/<code feature>/finetune_<model name>_<non-iid degree>.yaml
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

## VI. Inference & Evaluation
