// Assigment Operator and Array as Args in Function

#include <stdio.h> 

#define EXIT_SUCEESS 0

void mulBy2(float [], size_t);

int main(void)
{
    // Defining a Dynamic Array
    float array[] = {
        3.0f, 34.6f, 2.0f, 6.6f
    };

    // Size of Array
    size_t size = sizeof(array)/ sizeof(array[0]);

    // Multiplying each elements of array by 2
    mulBy2(array, size);

    // Printing each elements
    for (int index = 0; index < size; index++)
    {
        printf(": %07.4f\t", array[index]);
    }
    printf("\n");

    return EXIT_SUCEESS;
}

void mulBy2(float array[], size_t size)
{
    // Multiply each by 2
    for (int index = 0; index < size; index++)
    {
        array[index] *= 2;
    }
}