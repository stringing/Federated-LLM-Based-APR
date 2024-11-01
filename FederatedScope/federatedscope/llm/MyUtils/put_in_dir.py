import os
import shutil
import sys

def organize_cpp_files(directory):
    # Ensure the directory exists
    if not os.path.exists(directory):
        print(f"Directory {directory} does not exist.")
        return
    
    # Iterate over all files in the directory
    for filename in os.listdir(directory):
        # Check if the file is a .cpp file
        if filename.endswith('.cpp'):
            # Get the file name without extension
            file_base_name = os.path.splitext(filename)[0]
            # Create a new directory with the file base name
            new_dir_path = os.path.join(directory, file_base_name)
            os.makedirs(new_dir_path, exist_ok=True)
            # Move the .cpp file to the new directory
            src_file_path = os.path.join(directory, filename)
            dest_file_path = os.path.join(new_dir_path, filename)
            shutil.move(src_file_path, dest_file_path)
            print(f"Moved {filename} to {new_dir_path}")

if __name__ == "__main__":
    # Specify the directory containing the .cpp files
    directory_path = sys.argv[1]
    organize_cpp_files(directory_path)
