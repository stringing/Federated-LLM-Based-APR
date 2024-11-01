import difflib
import re
import json
import os

def extract_functions(file_content):
    # Regex pattern to match C++ function definitions (simplified)
    function_pattern = re.compile(r'\b(?:\w+\s+)+\w+\s*\([^)]*\)\s*{')
    functions = {}
    matches = function_pattern.finditer(file_content)
    for match in matches:
        start = match.start()
        end = file_content.find('}', start) + 1  # Simplified block end finder
        func_name = match.group().split('(')[0].split()[-1]
        functions[func_name] = file_content[start:end]
    return functions

def read_json_file(file_path):
    with open(file_path, 'r', encoding='utf-8') as file:
        data = json.load(file)
    return data['incorrectCode'], data['groudTruthCode']

def compare_functions(buggy_functions, fixed_functions):
    differ = difflib.Differ()
    function_changes = {}

    for func in set(buggy_functions.keys()).union(set(fixed_functions.keys())):
        buggy_func_code = buggy_functions.get(func, "").splitlines()
        fixed_func_code = fixed_functions.get(func, "").splitlines()
        diff = list(differ.compare(buggy_func_code, fixed_func_code))
        
        changes = any(line.startswith(('-', '+')) for line in diff)
        if changes:
            function_changes[func] = diff
    
    return function_changes

def main(directory, dataset, modified_dataset):
    num_func = []
    for filename in os.listdir(directory):
        if filename.endswith(".json"):
            file_path = os.path.join(directory, filename)
            buggy_code, fixed_code = read_json_file(file_path)
            
            buggy_functions = extract_functions(buggy_code)
            fixed_functions = extract_functions(fixed_code)
            
            function_changes = compare_functions(buggy_functions, fixed_functions)
            
            num_functions_involved = len(function_changes)
            
            num_func.append(num_functions_involved)
            
            print(f'File: {filename}')
            print(f'Number of functions involved in the fix: {num_functions_involved}')
            print('---')
    with open(dataset, 'r') as file:
        json_data = json.load(file)
    for i, item in enumerate(json_data):
        item['category'] = num_func[i]
    with open(modified_dataset, 'w') as file:
        json.dump(json_data, file, indent=4)

if __name__ == "__main__":
    import sys
    
    
    directory = sys.argv[1]
    dataset = sys.argv[2]
    modified_dataset = sys.argv[3]
    
    main(directory, dataset, modified_dataset)
    
    # python ../diff_cal.py /root/autodl-tmp/data/TutorCode/original /root/autodl-tmp/data/TutorCode/TutorCode.json /root/autodl-tmp/data/TutorCode/TutorCode_df.json