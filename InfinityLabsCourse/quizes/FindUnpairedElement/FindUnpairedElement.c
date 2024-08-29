#include <stddef.h>

int UnpairedElement(const int numbers[], size_t size)
{
    size_t i = 0; 
    int res = 0;
    
    for ( ; i < size; ++i)
    {
        res ^= numbers[i];
    }
    
    return res;
}
