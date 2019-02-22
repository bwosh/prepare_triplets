#include <math.h>

inline double cosine_similarity(double *A, double *B, unsigned int size)
{
    double mul = 0.0, d_a = 0.0, d_b = 0.0 ;

    for(unsigned int i = 0; i < size; ++i) 
    {
        mul += A[i] * B[i] ;
        d_a += A[i] * A[i] ;
        d_b += B[i] * B[i] ;
    }
    return mul / (sqrt(d_a) * sqrt(d_b)) ;
}

inline double cosine_distance(double *A, double *B, unsigned int size)
{
    return 1 - cosine_similarity(A,B,size);
}
