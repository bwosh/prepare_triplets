class EmbeddingData
{
    private:
        double **embeddings;
        int *categories;
        int embeddings_count;

    public:
        EmbeddingData(int embedding_length);
        void AddEmbedding(double *values, int category);
};
