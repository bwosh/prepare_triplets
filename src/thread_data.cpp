#include <stdio.h>
#include "thread_data.hpp"
#include "settings.hpp"

ThreadData::ThreadData(int id)
{
    #ifdef VERBOSE
    printf("Setting id %d\n",id);
    #endif
    thread_id = id;
}

int ThreadData::GetId()
{
    #ifdef VERBOSE
    printf("Getting id %d\n", thread_id);
    #endif
    return thread_id;
}
