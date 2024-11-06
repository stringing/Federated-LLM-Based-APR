import os
import filecmp
import sys

def compare_files_in_directories(dir1, dir2):
    # Get a list of all files in both directories
    files_in_dir1 = set(os.listdir(dir1))
    files_in_dir2 = set(os.listdir(dir2))

    # Find common files in both directories
    common_files = files_in_dir1.intersection(files_in_dir2)

    # Compare the contents of each common file
    for file_name in common_files:
        file1_path = os.path.join(dir1, file_name)
        file2_path = os.path.join(dir2, file_name)

        # Check if both are files (not directories)
        if os.path.isfile(file1_path) and os.path.isfile(file2_path):
            # Compare the contents of the files
            if not filecmp.cmp(file1_path, file2_path, shallow=False):
                print(f"Different content: {file_name}")

# Example usage
dir1 = sys.argv[1]
dir2 = sys.argv[2]
compare_files_in_directories(dir1, dir2)