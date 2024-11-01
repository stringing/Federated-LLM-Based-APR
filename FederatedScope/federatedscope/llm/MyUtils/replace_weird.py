import os
import sys

def replace_character_in_file(filepath, old_char, new_char):
    with open(filepath, 'r', encoding='utf-8') as file:
        content = file.read()
    
    new_content = content.replace(old_char, new_char)
    
    with open(filepath, 'w', encoding='utf-8') as file:
        file.write(new_content)

def process_directory(directory, old_char, new_char):
    for root, _, files in os.walk(directory):
        for file in files:
            if file.endswith('.java'):
                filepath = os.path.join(root, file)
                replace_character_in_file(filepath, old_char, new_char)
                print(f"Processed file: {filepath}")

if __name__ == "__main__":
    directory_path = sys.argv[1]
    replace_character = '➞'
    new_character = '=>'
    
    process_directory(directory_path, replace_character, new_character)
    print("Processing complete.")