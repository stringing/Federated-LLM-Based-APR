import subprocess
import os, glob
import sys
from datetime import datetime
import numpy as np


def pass_at_k(n, c, k):
    if n - c < k:
        return 1.0
    return 1.0 - np.prod(1.0 - k / np.arange(n - c + 1, n + 1))

def evaluate_pak(ans, n, k):
    paks = []
    for name, correct_num in ans.items():
        paks.append(pass_at_k(n, correct_num, k))
    for i in range(163 - len(ans)):
        paks.append(0)
    return np.array(paks).mean()
                       

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

ac10 = {}
ac5 = {}
ac1 = {}
ac = {}
bug = 0

ss = 0

os.makedirs(f'/root/eval_java/{sys.argv[1]}', exist_ok=True)

if len(sys.argv) == 2:
    calc_dir = 'evalrepair-java-res'
elif len(sys.argv) == 3:
    calc_dir = sys.argv[2]

for id in range(13):
    copy_command = f"cp -r /root/eval_java/humaneval /root/eval_java/{sys.argv[1]}/ && cp -r /root/eval_java/lib /root/eval_java/{sys.argv[1]}/ && cp /root/autodl-tmp/model/{sys.argv[1]}/{calc_dir}/fixed{id}/*.java /root/eval_java/{sys.argv[1]}/humaneval/buggy/"
    copy_process = subprocess.Popen(copy_command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    copy_process.communicate()
    print(f"copy result: {copy_process.returncode}")
    
    directory_path = f"/root/autodl-tmp/model/{sys.argv[1]}/{calc_dir}/fixed{id}/"
    if os.path.exists(directory_path) and os.path.isdir(directory_path):
        for file_path in sorted(glob.glob(os.path.join(directory_path, '*.java')), reverse=False):
            print(file_path)
            name = file_path.split('/')[-1].split('.')[0]
            if 'checkpoint' in name:
                continue
            ret = test(name, sys.argv[1])
            if ret == 0:
                ac[name] = ac.get(name, 0) + 1
                if id < 1:
                    ac1[name] = ac1.get(name, 0) + 1
                if id < 5:
                    ac5[name] = ac5.get(name, 0) + 1
                if id < 10:
                    ac10[name] = ac.get(name, 0) + 1

top10, top5, top1 = len(ac10) / 163 * 100, len(ac5) / 163 * 100, len(ac1) / 163 * 100
p10, p5, p3, p1 = evaluate_pak(ac, 13, 10), evaluate_pak(ac, 13, 5), evaluate_pak(ac, 13, 3), evaluate_pak(ac, 13, 1)

print('accuracy@10:', top10, 'accuracy@5:', top5, 'accuracy@1:', top1)
print('pass@10:', p10, 'pass@5:', p5, 'pass@3:', p3, 'pass@1:', p1)

logtxt = f'{datetime.now()} evaluated {sys.argv[1]} accuracy@1: {top1} accuracy@5: {top5} accuracy@10: {top10} pass@1: {p1} pass@3: {p3} pass@5: {p5} pass@10: {p10}'

with open('/root/FederatedScope/exp/calc_java_log.txt', 'a') as file:
    print(logtxt, file=file)