#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "files.hpp"

#define FLOAT_BUFFER_SIZE 1024
#define TEMP_SIZE 128

inline float convert_to_float(const char *txt)
{
    float result = strtof(txt, NULL);
    return result;
}

float *get_floats(const char* text, size_t read, int& fcount){

    float results[FLOAT_BUFFER_SIZE];
    char temp[TEMP_SIZE];
    int count = 0;

    int start_index = 0;
    int stop_index = 0;
    int idx = 0;

    while(idx<(int)read)
    {
        char current = text[idx];

        if(current=='#')
        {
            break;
        }

        if( (current>='0' && current<='9') || current=='-' || current=='.' )
        {
            stop_index++;
        }else{

            if( start_index<stop_index)
            {
                memset(&temp, 0, TEMP_SIZE);

                for(int i=start_index;i<stop_index;i++)
                {
                    temp[i-start_index] = text[i];
                }

                results[count++] = convert_to_float(temp);
            }
            start_index=++stop_index;
        }

        idx++;
    }

    float *final_results = new float[count];
    memcpy(final_results, results, count*sizeof(float));
    fcount = count;
    return final_results;
}

std::tuple<std::list<float*> ,std::list<int>> read_input(const char* filepath)
{
    std::list<float*> results;
    std::list<int> result_sizes;
    
    std::tuple<std::list<float*> ,std::list<int>> data;

    FILE *fp = fopen(filepath, "r");
    char * line = NULL;
    size_t len = 0;
    ssize_t read;    

    while((read = getline(&line, &len, fp)) != -1)
    {
        int fcount = 0;
        float *floats = get_floats(line, read, fcount);
        results.push_back(floats);
        result_sizes.push_back(fcount);
        free(line);
        line = NULL;
    }

    fclose(fp);

    data = std::make_tuple(results, result_sizes);

    return data;
}