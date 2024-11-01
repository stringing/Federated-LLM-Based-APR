import os
import json
import sys
import re

def extract_prompt_contents(prompt_text):
    match = re.search(r'/\*([^*]*)\*/(.*)', prompt_text, re.DOTALL)
    if match:
        description = match.group(1).strip()
        function_head = match.group(2).strip()
    else:
        description = ""
        function_head = ""
    return description, function_head

def create_repair_dataset(buggy_dir, fixed_dir, prompt_dir):
    dataset = []

    if not os.path.isdir(buggy_dir) or not os.path.isdir(fixed_dir) or not os.path.isdir(prompt_dir):
        print("One or more directories do not exist.")
        return

    for i, filename in enumerate(os.listdir(buggy_dir)):
        if filename.endswith('.cpp'):
            buggy_file_path = os.path.join(buggy_dir, filename)
            fixed_file_path = os.path.join(fixed_dir, filename)
            prompt_file_path = os.path.join(prompt_dir, filename)

            if os.path.exists(fixed_file_path) and os.path.exists(prompt_file_path):
                with open(buggy_file_path, 'r') as buggy_file, \
                     open(fixed_file_path, 'r') as fixed_file, \
                     open(prompt_file_path, 'r') as prompt_file:

                    buggy_code = buggy_file.read()
                    fixed_code = fixed_file.read()
                    prompt_text = prompt_file.read()

                    description, head = extract_prompt_contents(prompt_text) 
                    
                    _, buggy = extract_prompt_contents(buggy_code)
                    _, fixed = extract_prompt_contents(fixed_code)

                    # prompt_text = 'This is a programming problem description:\n' + description + '\n'
                    prompt_text = ""
                    prompt_text += "This is an incorrect code (" + filename + ")\n```c++\n" + buggy_code + "\n```\n" 
                    prompt_text += 'You are a software engineer. Can you repair the incorrect code?\n'
                    prompt_text = '[INST]\n' + prompt_text + '[/INST]'
                    prompt_text += '\n```c++\n'
                    prompt_text += head

                    
                    
                    name = filename.split('.')[0]

                    dataset.append({
                        'instruction': prompt_text,
                        'output': fixed,
                        'category': name
                    })

    return dataset

def main():
    if len(sys.argv) != 5:
        print("Usage: python script.py <buggy_dir> <fixed_dir> <prompt_dir> <save_path>")
        sys.exit(1)

    buggy_dir = sys.argv[1]
    fixed_dir = sys.argv[2]
    prompt_dir = sys.argv[3]
    save_path = sys.argv[4]

    dataset = create_repair_dataset(buggy_dir, fixed_dir, prompt_dir)

    with open(save_path, 'w') as json_file:
        json.dump(dataset, json_file, indent=4)

    print(f"Dataset has been written to {save_path}")

if __name__ == "__main__":
    main()