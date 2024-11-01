import json
import sys
import os
import uuid
import subprocess

def test(task_id, generation):
    time_limit = 60
    tname = str(uuid.uuid4())
    code_file_path = f"tmp/{tname}.cpp"
    executable_path = f"tmp/{tname}"
    os.makedirs("tmp", exist_ok=True)
    with open(code_file_path, 'w') as file:
        file.write(generation)
    
    command = f"g++ --std=c++17 {code_file_path} -lcrypto -o {executable_path} && timeout %d ./tmp/{tname}" % time_limit
    # print(command)
    process = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = process.communicate()
    # print("Standard Output:", stdout.decode('utf-8', 'ignore'))
    # print("Standard Error:", stderr.decode('utf-8', 'ignore'))
    # print(process.returncode)
    return process.returncode == 0

def extract_prefix_for_code(content):
    return content.split('```c++')[-1]

def calculate_top_k_accuracy(test_file_path, problem_file_path, extend_test_dir, k):
    task_accuracies = {}
    prefixes = {}
    with open(problem_file_path, 'r') as problem_file:
        samples = json.load(problem_file)
        for sample in samples:
            prefix = extract_prefix_for_code(sample['instruction'])
            prefixes[sample['category']] = prefix
            
    with open(test_file_path, 'r') as file:
        for line in file:
            data = json.loads(line)
            task_id = data['task_id']
            extend_test_file = os.path.join(extend_test_dir, f'{task_id}.cpp')
            with open(extend_test_file, 'r') as extend_test:
                extend_test_data = extend_test.read()
                    
            generation = data['generation']
            
            complete_code = prefixes[task_id] + '\n' + generation + '\n' + extend_test_data
            
            # print(complete_code)
            print(f'Current test: {task_id}')

            # Check if this task_id has been encountered before and initialize if not
            if task_id not in task_accuracies:
                task_accuracies[task_id] = [False] * k  # A list of boolean values for top-k samples
            
            # Update the accuracies list for the current task_id based on the generation correctness
            if test(task_id, complete_code):
                for i in range(k):
                    if not task_accuracies[task_id][i]:  # Only update if not already set to True
                        task_accuracies[task_id][i] = True
                        break  # Only mark the first unset (False) as True

    # Calculate the overall top-k accuracy
    correct_counts = sum([1 for accuracies in task_accuracies.values() if any(accuracies)])
    total_tasks = len(task_accuracies)
    top_k_accuracy = (correct_counts / total_tasks) * 100 if total_tasks > 0 else 0

    return top_k_accuracy

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python script.py <test_file_path> <problem_file_path> <extend_test_path> <top_k>")
        # python federatedscope/llm/eval/eval_for_code/morepair_cal.py /root/autodl-tmp/model/finetuned/_2_codellama7b.ckpt_morepair_answer.jsonl /root/autodl-tmp/data/morepair/morepair_cpp.json /root/morepair-1024/evalrepair-cpp-res/extend-test 1
        sys.exit(1)

    test_file_path = sys.argv[1]
    problem_file_path = sys.argv[2]
    extend_test_dir = sys.argv[3]
    top_k = int(sys.argv[4])

    accuracy = calculate_top_k_accuracy(test_file_path, problem_file_path, extend_test_dir, top_k)
    print(f"Top-{top_k} Accuracy: {accuracy:.2f}%")