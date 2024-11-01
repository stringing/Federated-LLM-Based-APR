import json
import sys

# Load the JSON data from a file
input_file_path = sys.argv[1]
output_file_path = sys.argv[2]

try:
    with open(input_file_path, 'r', encoding='utf-8') as file:
        data = json.load(file)
except FileNotFoundError:
    print(f"Error: The file {input_file_path} does not exist.")
    exit()
except json.JSONDecodeError:
    print("Error: Failed to decode JSON.")
    exit()

# Process each element in the data
processed_data = []
for item in data:
    if 'text' in item:
        parts = item['text'].split("</s>")
        parts_1 = parts[1].split("#include")
        parts_2 = parts[2].split("#include")
        
        # Ensure there are at least three parts to proceed safely
        if len(parts) >= 3:
            input1 = parts[0] + parts_1[0] + "#include"
            output1 = parts_1[1] + "</s>"
            input2 = parts[0] + parts_2[0] + "#include"
            output2 = parts_2[1] + "</s>"
            processed_data.append({
                'input1': input1,
                'input2': input2,
                'output1': output1,
                'output2': output2
            })
        else:
            print("Warning: Not enough segments in text to process according to the requirements.")

# Save the processed data to another JSON file
try:
    with open(output_file_path, 'w', encoding='utf-8') as outfile:
        json.dump(processed_data, outfile, ensure_ascii=False, indent=4)
    print(f"Data has been processed and saved to {output_file_path}.")
except IOError:
    print(f"Error: Could not write to file {output_file_path}.")
    
# python federatedscope/llm/MyUtils/process_mo_dataset.py /root/morepair-1024/data/trainset/llama_llm.json /root/autodl-tmp/data/mo_train/llama_llm.json