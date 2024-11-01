import os
import json
import sys

# Define the input and output directory paths
input_dir = sys.argv[1]
output_dir = sys.argv[2]

# Ensure the output directory exists
os.makedirs(output_dir, exist_ok=True)

# Iterate over all files in the input directory
for filename in os.listdir(input_dir):
    if filename.endswith('.json'):
        input_file_path = os.path.join(input_dir, filename)
        
        # Read the JSON file
        with open(input_file_path, 'r') as json_file:
            try:
                data = json.load(json_file)
                
                # Extract the content of the key "incorrectCode"
                if 'incorrectCode' in data:
                    incorrect_code = data['incorrectCode']
                    
                    # Create an output file path with a .c extension
                    output_filename = os.path.splitext(filename)[0] + '.cpp'
                    output_file_path = os.path.join(output_dir, output_filename)
                    
                    # Write the extracted code to the .c file
                    with open(output_file_path, 'w') as c_file:
                        c_file.write(incorrect_code)
            except json.JSONDecodeError:
                print(f"Skipping {filename}: not a valid JSON file.")

print("Extraction complete.")