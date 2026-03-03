#include <stdio.h>
#include <stdint.h>

#define EXIT_SUCCESS 0

int main(void)
{
    const int8_t LIMIT = 50; 

    // Delecration & Initialization
    // Can't use "LIMIT" here while init
    int16_t numArry[50] = {
        [0] = 1,
        [2] = 2,
        [3] = 3,
        [4] = 4
    };
    
    // Initialization of array (for loop)
    for (int8_t index = 5; index < LIMIT; index++)
    {
        numArry[index] = index * index;
    }
    
    // Print each element in list
    for (int8_t index = 0; index < LIMIT; index++)
    {
        printf("index %i: %i\n", index + 1, numArry[index]);
    }

    return EXIT_SUCCESS;
}