import os
import sys

def modify_java_files(directory):
    for root, _, files in os.walk(directory):
        for file in files:
            if file.endswith(".java"):
                file_path = os.path.join(root, file)
                with open(file_path, 'r') as f:
                    lines = f.readlines()

                if not lines[0].startswith("package"):
                    lines.insert(0, "package humaneval.buggy;\n")

                    with open(file_path, 'w') as f:
                        f.writelines(lines)

if __name__ == "__main__":
    modify_java_files(sys.argv[1])
    print("Modification complete.")