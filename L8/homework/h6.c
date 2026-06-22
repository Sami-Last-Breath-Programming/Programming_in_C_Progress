#include <stdio.h>
#include <stdlib.h>

void sumArray(size_t size, int [size]);

int main(void)
{
    // Array data set
    int array[] = {5, 10, 15, 20};
    size_t size = sizeof(array) / sizeof(array[0]);
    
    // Sum the array
    sumArray(size, array);

    // Print the array
    printf("The sum of Array is %i\n", array[0]);
    
    return EXIT_SUCCESS;
}

void sumArray(size_t size, int array[size])
{
    for (size_t index = 1; index < size; index++)
    {
        array[0] += array[index];
    }
}