# Prepare triplets

C++ app to prepare triplets out of set of data pairs [embedding, category_index]

## Status
It's very early stage - Work in progress.

### Input file format:
(lenght of embedding:int)
(number of entries:int)
(number of categories:int)
(embedding0: comma spearated double values)
(category0: 0-(N-1) category index int)
(...next lines with embeddings & categories)

### Output will have:
List of:
[anchor_index,positive_index,negative_index, a-p cosine_distance, a-n cosine distance]

### Settings:

planned:
- limiting number of pairs

### Dependencies:
- gcc compiler
- pthreads