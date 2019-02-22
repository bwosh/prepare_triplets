#include <stdio.h>
#include <pthread.h>
#include "thread_data.hpp"
#include "triplets.hpp"

int main()
{
    int threads_number = 8;

    // create threads
    pthread_t *threads = new pthread_t[threads_number];
    ThreadData **thread_data = (ThreadData**) new void*[threads_number];
    //int thread_num = 0;
    for (int i=0;i<threads_number;i++)
    {
        thread_data[i] = new ThreadData(i);
        pthread_create(&(threads[i]), NULL, process_triplets, thread_data[i]);
    }

    // join threads
    for (int i=0;i<threads_number;i++)
    {
        pthread_join(threads[i], NULL);
        delete thread_data[i];
    }

    // old code
    #ifdef VERBOSE
    printf("DONE\n");
    #endif

    delete [] threads;
    delete [] thread_data;

    return 0;
}