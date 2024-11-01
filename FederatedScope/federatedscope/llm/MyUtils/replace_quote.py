import os
import sys

def replace_single_quotes(directory):
    for filename in os.listdir(directory):
        if filename.endswith(".txt"):
            file_path = os.path.join(directory, filename)
            with open(file_path, 'r') as file:
                content = file.read()

            # Replace single quotes with double quotes
            content = content.replace("'", '"')

            with open(file_path, 'w') as file:
                file.write(content)

if __name__ == "__main__":
    directory = sys.argv[1]
    replace_single_quotes(directory)