import json
import os
import sys

if len(sys.argv) != 3:
    print("Usage: python script.py <directory_of_json_files> <path_to_new_json_file>")
    sys.exit(1)

json_files_dir = sys.argv[1]

output_file_path = sys.argv[2]


processed_records = []

for json_file in os.listdir(json_files_dir):
    if json_file.endswith('.json'):
        file_path = os.path.join(json_files_dir, json_file)
        if os.path.isfile(file_path):
            with open(file_path, 'r') as file:
                data = json.load(file)
                prompt = "This is a programming problem description:\n" + data.get('problemDescription') + "\n"
                judge_result = data.get('judgeResult')
                if judge_result.get('fileName', None) is not None:
                    prompt += "Your program should use file input and output. Read the input from a file named '" + judge_result['fileName'] + ".in' and write the output to a file named '" + judge_result['fileName'] + ".out'.\n\n"
                prompt += "### Time Limit\n" + str(judge_result['timeLimit']) + "ms\n\n"
                prompt += "### Memory Limit\n" + str(judge_result['memoryLimit']) + "KB\n\n"
                prompt += "This is an incorrect code to the problem:\n```c++\n" + data.get('incorrectCode') + "```\n\n" 
                prompt += "You are a software engineer. Can you repair the incorrect code?\n"
                prompt = "[INST]\n" + prompt + "\n[/INST]\n"
                prompt += "```c++\n#include"
                correct = data.get('groudTruthCode')
                split_word = '#include'
                pos = correct.find(split_word)
                record = {
                    'instruction': prompt,
                    'output': correct[pos+len(split_word):] + ' ```'
                }
                processed_records.append(record)

with open(output_file_path, 'w') as output_file:
    json.dump(processed_records, output_file, indent=4)

print(f"Data extracted and saved to {output_file_path}")