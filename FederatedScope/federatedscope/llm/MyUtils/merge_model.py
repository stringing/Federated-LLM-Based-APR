from transformers import AutoModelForCausalLM, AutoTokenizer
from peft import PeftModel
import shutil
import sys
import torch
import os

raw_model, path, output = f'/root/autodl-tmp/model/{sys.argv[1]}', f'/root/autodl-tmp/model/{sys.argv[2]}', f'/root/autodl-tmp/model/{sys.argv[3]}'

base_model = AutoModelForCausalLM.from_pretrained(
            raw_model,
            return_dict=True,
            low_cpu_mem_usage=True,
            torch_dtype=torch.float16,
            device_map="cpu",
        )
print('load model success...')
model = PeftModel.from_pretrained(base_model, path) # the model to be adapted and the path to the PEFT configuration
model = model.merge_and_unload()
print('merge model success...')
model.save_pretrained(output, safe_serialization=True)
print('save merged model success...')
tokenizer = AutoTokenizer.from_pretrained(raw_model, trust_remote_code=True)
tokenizer.pad_token = tokenizer.eos_token
tokenizer.padding_side = "right"
tokenizer.save_pretrained(output)