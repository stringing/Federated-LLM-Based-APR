from transformers import AutoTokenizer, AutoModel
import torch
import json
from sklearn.cluster import KMeans
import numpy as np
import time

model_path = '/root/autodl-tmp/download_from_hfm/codebert-base'
# model_path = '/root/autodl-tmp/model/CodeLlama-13b-Instruct-hf'
data_path = '/root/autodl-tmp/data/TutorCode/TutorCode.json'
output_path = '/root/autodl-tmp/data/TutorCode/TutorCode_clustered.json'

tokenizer = AutoTokenizer.from_pretrained(model_path, model_max_length=512)
model = AutoModel.from_pretrained(model_path)

print(tokenizer.model_max_length)

with open(data_path, 'r') as file:
    json_data = json.load(file)

max_length = 512
embeddings = []
start_time = time.time()
for i, line in enumerate(json_data):
    tokens = tokenizer.tokenize(line['instruction'] + line['output'])
    tokens = tokens + [tokenizer.eos_token]
    tokens_ids = tokenizer.convert_tokens_to_ids(tokens)
    tokens_ids = tokens_ids[:max_length-1] + [tokens_ids[-1]]
    context_embeddings = model(torch.tensor(tokens_ids)[None, :])[0]
    
    
    embeddings.append(context_embeddings.detach().numpy())

# Pad or truncate the embeddings to the maximum length
padded_embeddings = []
for embedding in embeddings:
    if embedding.shape[1] < max_length:
        # Pad the embedding with zeros
        pad_width = ((0, 0), (0, max_length - embedding.shape[1]), (0, 0))
        padded_embedding = np.pad(embedding, pad_width, mode='constant')
    else:
        # Truncate the embedding to the maximum length
        padded_embedding = embedding[:, :max_length, :]
    
    print(padded_embedding.shape)
    padded_embeddings.append(padded_embedding)

# Convert the list of padded embeddings to a numpy array
embeddings_array = np.concatenate(padded_embeddings, axis=0)

# Reshape the embeddings to a 2-dimensional array
flattened_embeddings = embeddings_array.reshape(embeddings_array.shape[0], -1)

np.save('/root/embeddings.npy', flattened_embeddings)
exit(0)

# Perform K-means clustering
num_clusters = 8  # Specify the desired number of clusters
kmeans = KMeans(n_clusters=num_clusters)
cluster_labels = kmeans.fit_predict(flattened_embeddings)

end_time = time.time()

print(end_time - start_time)

# Add the cluster labels to each JSON element
for i, label in enumerate(cluster_labels):
    json_data[i]['category'] = int(label)

# Save the updated JSON data to a new file
with open(output_path, 'w') as file:
    json.dump(json_data, file, indent=2)

print(f"Clustered JSON data saved to: {output_path}")