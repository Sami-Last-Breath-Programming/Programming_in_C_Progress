#include <stdio.h>
#include <stdlib.h>

// Clang Flags
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

// Declarations 
int sumArray(int *, const size_t);
void printResult(int*, int,  const size_t);

// Main Entry
int main(void)
{
    // Declarations for results variable
    int result1, result2;
    
    // Test Arrays
    int array1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array2[10] = {3, 7, -9, 3, 6, -1, 7, 9, 1, -5 };

    // Sum the Array
    result1 = sumArray(array1, 10);
    result2 = sumArray(array2, 10);

    // Print the results 
    printResult(array1, result1, 10);
    printResult(array2, result2, 10);

    return EXIT_SUCCESS;
}

int sumArray(int *array, const size_t len)
{
    int sum; 
    int *array_Ptr;

    // On Start
    sum = 0;
    array_Ptr = array;

    // Loop on the Array till end
    while (array_Ptr < (array + len))
    {
        sum += *array_Ptr;
        array_Ptr++;
    }

    // Return the sum
    return sum;
}

void printResult(int *array, int sum, const size_t len)
{
    // Print the Array
    printf("[");
    for (size_t index = 0; index < len; index++)
    {
        printf("%i%s", 
            array[index],
            (index < len - 1)? ", ": "]\n");
    }
    
    // Print the Sum
    printf("The Sum = %i\n\n", sum);
}
#pragma clang diagnostic pop
