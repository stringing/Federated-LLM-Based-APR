import os
import sys
from pathlib import Path
from transformers import pipeline
from transformers import AutoModelForCausalLM, AutoTokenizer, AutoTokenizer
import re
import torch


def extract_first_java_code(s: str) -> str:
    matches = re.findall(r'```java(.*?)```', s, re.DOTALL)
    return matches[0].strip() if matches else ""

BOF = '[INST]'
EOF = '[/INST]'

if sys.argv[2].startswith('codellama') or sys.argv[2].startswith('mistral'):
    BOF = '[INST]'
    EOF = '[/INST]'
elif sys.argv[2].startswith('starchat'):
    BOF = '<|system|>\n<|end|>\n<|user|>'
    EOF = '<|end|>\n<|assistant|>'
elif sys.argv[2].startswith('deepseek'):
    BOF = ''
    EOF = ''
else:
    print('parameter error ...', flush=True)
    sys.exit(0)

model_path = f'/root/autodl-tmp/model/{sys.argv[3]}/'

device = sys.argv[4]


if len(sys.argv) == 5:
    infer_dir = 'evalrepair-java-res'
elif len(sys.argv) == 6:
    infer_dir = sys.argv[5]


tokenizer = AutoTokenizer.from_pretrained(model_path)
model = AutoModelForCausalLM.from_pretrained(model_path, device_map=f"cuda:{device}", load_in_8bit=True)

pipe = pipeline("text-generation", model=model, tokenizer=tokenizer)

print('load model success ..', flush=True)

def cal(code, filename):
    prompt = BOF + " This is an incorrect code(" + filename + "):\n```java\n" + code + "\n```\nYou are a software engineer. Can you repair the incorrect code?\n" + EOF + "\n```java\n"
    print(prompt, flush=True)
    cnt = len(tokenizer.tokenize(prompt))
    max_d = 1024 - cnt
    while True:
        output = pipe(prompt, min_length=cnt+64, max_length=cnt+max_d, temperature=1.0, do_sample=True)
        full_text = output[0]['generated_text']
        print(full_text)
        if sys.argv[2].startswith('deepseek'):
            ret = extract_first_java_code(full_text.split('Can you repair the incorrect code?')[1])
        else:
            ret = extract_first_java_code(full_text.split('[/INST]')[1])
        print('code:', ret, flush=True)
        if ret.strip() != '':
            break
        max_d = min(3000 - cnt, max_d + 500)
    return [full_text, ret]


# arg1: fixed root path, arg2: model used, arg3: model path, arg4: device
# python federatedscope/llm/eval/eval_for_code/inference_cpp.py finetuned_qlora codellama CodeLlama-7b-hf 0

base_dir = '/root/morepair-1024/evalrepair-java/origin/'
fix_dir = '/root/autodl-tmp/model/' + sys.argv[1] + f'/{infer_dir}/fixed'

cnt = 0

for file_path in sorted(Path(base_dir).rglob('*.java'), reverse=True):
    full_path = str(file_path)
    print(full_path, flush=True)

    with open(full_path, 'r', encoding='utf-8') as file:
        content = file.read()

    print(content)

    for e in range(13):
        file_name = os.path.basename(full_path)
        if not os.path.exists(fix_dir + str(e)):
            os.makedirs(fix_dir + str(e))
        fix_name = os.path.join(fix_dir + str(e) + '/', file_name)
        if os.path.exists(fix_name):
            continue
        print(fix_name, flush=True)
        full, res = cal(content, file_name) # content of buggy code, file name of buggy code
        if full == None:
            continue
        with open(fix_name, 'w', encoding='utf-8') as file:
            print(res, file=file) # fixed code
        with open(fix_name + '.log', 'w', encoding='utf-8') as file:
            print(full, file=file)