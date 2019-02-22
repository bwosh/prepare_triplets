#include <stdio.h>
#include "thread_data.hpp"
#include "settings.hpp"

void *process_triplets(void *data)
{
    ThreadData *v = (ThreadData*)data;
    #ifdef VERBOSE
    printf("[Starting thread %d]\n", v->GetId());
    #endif

    #ifdef VERBOSE
    printf("[Finishing thread %d]\n", v->GetId());
    #endif
}