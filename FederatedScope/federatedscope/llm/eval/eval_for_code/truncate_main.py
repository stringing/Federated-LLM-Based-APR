import os
import sys

def extract_before_main(code):
    # Split the code at "int main()"
    parts = code.split("int main()", 1)
    # Return the first part
    return parts[0].strip() + '\n\n'

def modify_cpp_files(directory):
    # Walk through the directory
    for dirpath, dirnames, filenames in os.walk(directory):
        for filename in filenames:
            # Check if the file is a C++ source file
            if filename.endswith('.cpp'):
                filepath = os.path.join(dirpath, filename)
                # Read the current contents of the file
                with open(filepath, 'r', encoding='utf-8') as file:
                    content = file.read()
                
                # Modify the content by truncating before "int main()"
                modified_content = extract_before_main(content)
                
                # Write the modified content back to the file
                with open(filepath, 'w', encoding='utf-8') as file:
                    file.write(modified_content)
                # print(f'Modified {filepath}')

modify_cpp_files(sys.argv[1])