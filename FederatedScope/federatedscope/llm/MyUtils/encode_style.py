import os
import json
import numpy as np
from sklearn.preprocessing import MinMaxScaler
import sys

def read_files(directory):
    file_vectors = []
    file_names = []

    for filename in os.listdir(directory):
        if filename.endswith(".txt") and '.ipynb' not in filename:
            file_names.append(filename)
            with open(os.path.join(directory, filename), 'r') as file:
                file_content = file.read().strip().split('\n')
                vector = []
                for line in file_content:
                    data = json.loads(line)
                    if isinstance(data, dict):
                        vector.extend(list(data.values()))
                    elif isinstance(data, list):
                        vector.extend(data)
                last = vector.pop()
                vector.extend(last)
                file_vectors.append(vector)

    return file_vectors, file_names


def min_max_normalize(vectors):
    scaler = MinMaxScaler()
    normalized_vectors = scaler.fit_transform(vectors)
    return normalized_vectors

def encode(directory):
    file_vectors, file_names = read_files(directory)

    if not file_vectors:
        print("No .txt files found in the directory.")
        return

    # Perform min-max normalization
    normalized_vectors = min_max_normalize(file_vectors)
    
    return normalized_vectors, file_names


if __name__ == "__main__":
    directory = sys.argv[1]
    encode(directory)