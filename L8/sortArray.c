// Sorting an Array of Integers into Ascending Order

#include <stdio.h>

#define EXIT_SUCCESS 0

void sortArray(int [], size_t);
void printArray(int [], size_t);

int main(void)
{
    size_t size;
    
    // Two Array Defined And Inti
    int array1[] = {
        50, 30, 5, 7, 10
    };
    int array2[] = {
        12, 900, -3, 5,20
    };

    // Sorting the Array and Printing
    size = sizeof(array1) / sizeof(array1[0]);
    sortArray(array1, size);
    printArray(array1, size);

    size = sizeof(array2) / sizeof(array2[0]);
    sortArray(array2, size);
    printArray(array2, size);
    
    return EXIT_SUCCESS;
}

void sortArray(int array[], size_t size)
{
    // For a backup
    int temp;

    // Comparting The elements with each other (II1)
    for (int numIndex = 0; numIndex < size - 1; numIndex++)
    {   
        // Swaping the position if it's smaller (SI2)
        for (int nextNumIndex = numIndex + 1; nextNumIndex < size; nextNumIndex++)
        {
            if (array[numIndex] > array[nextNumIndex])
            {
                temp = array[numIndex];
                array[numIndex] = array[nextNumIndex];
                array[nextNumIndex] = temp;
            }
        }
    }  
}

void printArray(int array[], size_t size)
{
    // Formating 
    printf("[");
    
    // Looping till array and pritning all items
    for (int index = 0; index < size; index++)
    {
        if (index < size - 1)
            printf("%i, ", array[index]);
        
        else printf("%i]", array[index]);
    }
    printf("\n");
}