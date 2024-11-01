import json
import numpy as np
from sklearn.cluster import KMeans
import sys
from federatedscope.llm.MyUtils import encode_style, clustering




if __name__ == "__main__":
    
    style_path = sys.argv[1]
    original_dataset_path = sys.argv[2]
    modified_dataset_path = sys.argv[3]
    k = sys.argv[4]

    vectors, names = encode_style.encode(style_path)

    # Load the JSON data from a file
    with open(original_dataset_path, 'r') as file:
        json_data = json.load(file)

    # Step 1: Cluster the vectors
    print('Start clustering...')
    # kmeans = KMeans(n_clusters=int(k), random_state=42)
    # labels = kmeans.fit_predict(vectors)
    bk = clustering.biKmeans()
    labels, dist = bk.biKmeans(vectors, int(k))
    print('Clustering finished...')

    # Step 2: Sort the file names, vectors, and labels
    sorted_data = sorted(zip(names, vectors, labels), key=lambda x: int(x[0].split('.')[0]))
    sorted_names, sorted_vectors, sorted_labels = zip(*sorted_data)

    # Step 3: Add "category" to each element in the JSON data
    print('Start adding categories...')
    for i, item in enumerate(json_data):
        item['category'] = int(sorted_labels[i])
    print('Adding finished...')

    print('Start Writing to file...')
    # Save the modified JSON data back to a file
    with open(modified_dataset_path, 'w') as file:
        json.dump(json_data, file, indent=4)
    print('Writing finished...')

    # Print the sorted results (for verification)
    # print("Sorted Names:", sorted_names)
    # print("Sorted Vectors:", sorted_vectors)
    # print("Sorted Labels:", sorted_labels)
    # print("Updated JSON Data:", json_data)
    
    # usage: python federatedscope/llm/MyUtils/style_clustering.py /root/autodl-tmp/data/TutorCode/author_style_original/ /root/autodl-tmp/data/TutorCode/TutorCode.json /root/autodl-tmp/data/TutorCode/TutorCode_k3.json 3