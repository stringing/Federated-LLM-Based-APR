import json
import subprocess
import os
import uuid
import sys

def run_test(task_id, code_content):
    time_limit = 60
    tname = str(uuid.uuid4())
    code_path = f"tmp/{tname}.cpp"

    # Write the code to a temporary file
    with open(code_path, 'w') as f:
        f.write(code_content)

    # Compile and run the code
    command = f"g++ --std=c++17 {code_path} -lcrypto -o tmp/{tname} && timeout {time_limit} ./tmp/{tname}"
    # print(command)
    process = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = process.communicate()
    # print("Standard Output:", stdout.decode('utf-8', 'ignore'))
    # print("Standard Error:", stderr.decode('utf-8', 'ignore'))
    # print(process.returncode)
    return process.returncode


# Load JSONL data
result_path = sys.argv[1]
problem_path = sys.argv[2]
extend_path = sys.argv[3]
data = []
problem_data = {}
extend_data = {}
with open(problem_path, 'r') as problems:
    for item in json.load(problems):
        with open(os.path.join(extend_path, f"{item['category']}.cpp"), 'r') as extend:
            extend_data[item['category']] = extend.read()
        problem_data[item['category']] = item['instruction'].split('c++')[-1]

with open(result_path, 'r') as file:
    for line in file:
        sample = json.loads(line)
        sample['generation'] = problem_data[sample['task_id']] + '\n' + sample['generation'] + '\n\n' +  extend_data[sample['task_id']]
        data.append(sample)

cnt = {}
ac = {}
ac5 = {}
ac3 = {}
ac1 = {}
bug = 0

# print(data[0]['generation'])

# Assume data is a list of dictionaries
i = 0
for item in data:
    task_id = item['task_id']
    code_content = item['generation']
    item['sample_index'] = i % 10
    i += 1

    # Run the test
    result = run_test(task_id, code_content)

    # Update statistics based on result
    if result == 0:
        ac[task_id] = ac.get(task_id, 0) + 1
        if item['sample_index'] < 5:  
            ac5[task_id] = ac5.get(task_id, 0) + 1
        if item['sample_index'] < 3:  
            ac3[task_id] = ac3.get(task_id, 0) + 1
        if item['sample_index'] < 1:  
            ac1[task_id] = ac1.get(task_id, 0) + 1

# Calculate and print results
total_tasks = len(set([item['task_id'] for item in data]))  # Unique task_ids
print('TOP-10:', len(ac) / total_tasks * 100, 'TOP-5:', len(ac5) / total_tasks * 100, 'TOP-3:', len(ac3) / total_tasks * 100, 'TOP-1:', len(ac1) / total_tasks * 100)

# python federatedscope/llm/eval/eval_for_code/morepair_cal_v2.py /root/autodl-tmp/model/finetuned/_2_codellama7b.ckpt_morepair_answer.jsonl /root/autodl-tmp/data/morepair/morepair_cpp.json /root/morepair-1024/evalrepair-cpp-res/extend-test