import json
import sys

def modify_json_content(file_path, to_path):
    # Load the JSON data from the file
    with open(file_path, 'r') as file:
        data = json.load(file)

    # Iterate through each element in the JSON data
    for element in data:
        if 'instruction' in element:
            element['instruction'] = element['instruction'].replace("[INST]", "")
            element['instruction'] = element['instruction'].replace("[/INST]", "")
        
            
    
    # Write the modified data back to the file
    with open(to_path, 'w') as file:
        json.dump(data, file, indent=4)

# Specify the path to your JSON file
file_path = sys.argv[1]
to_path = sys.argv[2]

# Call the function
modify_json_content(file_path, to_path)