#include <stdio.h> 

#define EXIT_SUCCES 0

int arrayMinNum(int [], size_t);

int main(void)
{
    int result;

    // Defining two arrays 
    int array1[] = {
        20, 40, -44, 60, 70, 78,
    };
    int array2[] = {
        -200, 577, -678, -993, 900, 332
    };

    // Finding and Printing Mininmum number in arrays
    result = arrayMinNum(
        array1, 
        sizeof(array1) / sizeof(array1[0])
    );
    printf("The Minimum Value in Array1 is : %i\n", result);

    result = arrayMinNum(
        array2,
        sizeof(array2) / sizeof(array2[0])
    );
    printf("The Minimum Value in Array2 is : %i\n", result);
        
    return EXIT_SUCCES;
}

int arrayMinNum(int array[], size_t size)
{
    int minNum =  array[0];

    // If found number smaller than minNum, minNum = number
    for (int index = 1; index < size - 1; index++)
        if (minNum > array[index]) minNum = array[index];
    
    return minNum;
}