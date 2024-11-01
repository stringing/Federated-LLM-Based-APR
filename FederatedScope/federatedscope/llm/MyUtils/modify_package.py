import os
import sys

def modify_java_files(root_dir):
    """
    Traverse through the directory, find all .java files and modify the first line if it contains 'package'.

    :param root_dir: The root directory to start the traversal
    """
    for root, dirs, files in os.walk(root_dir):
        for file in files:
            if file.endswith(".java"):
                file_path = os.path.join(root, file)
                with open(file_path, 'r') as f:
                    lines = f.readlines()
                
                # Check if the first line contains 'package'
                if lines and lines[0].strip().startswith("package"):
                    lines[0] = "package humaneval.buggy;\n"  # Modify the first line as required
                    
                    # Write back the modified lines to the file
                    with open(file_path, 'w') as f:
                        f.writelines(lines)
                        # print(f"Modified: {file_path}")


modify_java_files(sys.argv[1])
