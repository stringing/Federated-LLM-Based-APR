import subprocess
import os, glob
import sys
from datetime import datetime
import numpy as np
import json
                       

def test(name, model):
    compile_command = f"cd /root/eval_java/{model} && javac -cp .:lib/junit4-4.12.jar:lib/hamcrest-all-1.3.jar humaneval/buggy/{name}.java humaneval/TEST_{name}.java"
    print(compile_command)
    compile_process = subprocess.Popen(compile_command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    compile_process.communicate()
    print(f"{name} compilation: {compile_process.returncode}")
    returncode = compile_process.returncode
    if compile_process.returncode == 0:
        test_command = f"cd /root/eval_java/{model} && java -cp .:lib/junit4-4.12.jar:lib/hamcrest-all-1.3.jar org.junit.runner.JUnitCore humaneval.TEST_{name}"
        print(test_command)
        test_process = subprocess.Popen(test_command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        test_process.communicate()
        print(f"{name} test: {test_process.returncode}")
        returncode = test_process.returncode
    return returncode


fixed = []

os.makedirs(f'/root/eval_java/{sys.argv[1]}', exist_ok=True)

if len(sys.argv) == 2:
    calc_dir = 'evalrepair-java-res'
elif len(sys.argv) == 3:
    calc_dir = sys.argv[2]

for id in range(10):
    copy_command = f"cp -r /root/eval_java/humaneval /root/eval_java/{sys.argv[1]}/ && cp -r /root/eval_java/lib /root/eval_java/{sys.argv[1]}/ && cp /root/autodl-tmp/model/{sys.argv[1]}/{calc_dir}/fixed{id}/*.java /root/eval_java/{sys.argv[1]}/humaneval/buggy/"
    copy_process = subprocess.Popen(copy_command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    copy_process.communicate()
    print(f"copy result: {copy_process.returncode}")
    
    directory_path = f"/root/autodl-tmp/model/{sys.argv[1]}/{calc_dir}/fixed{id}/"
    if os.path.exists(directory_path) and os.path.isdir(directory_path):
        for file_path in sorted(glob.glob(os.path.join(directory_path, '*.java')), reverse=False):
            print(file_path)
            name = file_path.split('/')[-1].split('.')[0]
            if 'checkpoint' in name or name in fixed:
                continue
            ret = test(name, sys.argv[1])
            if ret == 0:
                fixed.append(name)



with open(f'/root/autodl-tmp/venn/{sys.argv[1]}.json', 'w') as json_file:
    json.dump(fixed, json_file)