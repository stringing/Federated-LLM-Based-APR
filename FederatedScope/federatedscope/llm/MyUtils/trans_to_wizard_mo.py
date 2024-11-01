import json
import sys

def modify_json_content(file_path, to_path):
    # Load the JSON data from the file
    with open(file_path, 'r') as file:
        data = json.load(file)

    # Iterate through each element in the JSON data
    for element in data:
        # Check and modify 'output1' if it exists in the element
        if 'output1' in element:
            element['output1'] = element['output1'].replace("</s>", "<|endoftext|>")
        
        # Check and modify 'output2' if it exists in the element
        if 'output2' in element:
            element['output2'] = element['output2'].replace("</s>", "<|endoftext|>")
            
    
    # Write the modified data back to the file
    with open(to_path, 'w') as file:
        json.dump(data, file, indent=4)

# Specify the path to your JSON file
file_path = sys.argv[1]
to_path = sys.argv[2]

# Call the function
modify_json_content(file_path, to_path)