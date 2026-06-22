// Sort Array in ascending or descending order

#include <stdio.h>
#include <stdlib.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"


typedef enum Order
{
    ASC = 1,
    DES = 2

} Order;

// Decelerations
void sort(size_t, int *, Order);
void sortAsc(size_t, int *);
void sortDes(size_t, int *);
void printArray(size_t, int *);


// Main Entery
int main(void)
{   
    // inti array 
    int array[] = {
        1, 6, 10, 30, 14
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    sort(size, array, ASC);
    printArray(size, array);

    sort(size, array, DES);
    printArray(size, array);

    return EXIT_SUCCESS;
}

void sort(size_t size, int *array, Order type)
{
    if (type == ASC)
        sortAsc(size, array);
    else if (type == DES)
        sortDes(size, array);
    else
    {
        printf("Error! Invalid Sort Type !\n");
        exit(EXIT_FAILURE);
    }
}

void sortDes(size_t size, int *array)
{
    // For a backup
    int temp;

    // Comparting The elements with each other (II1)
    for (size_t numIndex = 0; numIndex < size - 1; numIndex++)
    {   
        // Swaping the position if it's smaller (SI2)
        for (size_t nextNumIndex = numIndex + 1; nextNumIndex < size; nextNumIndex++)
        {
            if (array[numIndex] < array[nextNumIndex])
            {
                temp = array[numIndex];
                array[numIndex] = array[nextNumIndex];
                array[nextNumIndex] = temp;
            }
        }
    }
}

void sortAsc(size_t size, int *array)
{
    // For a backup
    int temp;

    // Comparting The elements with each other (II1)
    for (size_t numIndex = 0; numIndex < size - 1; numIndex++)
    {   
        // Swaping the position if it's smaller (SI2)
        for (size_t nextNumIndex = numIndex + 1; nextNumIndex < size; nextNumIndex++)
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

void printArray(size_t size, int *array)
{
    // Formating 
    printf("[");
    
    // Looping till array and pritning all items
    for (size_t index = 0; index < size; index++)
    {
        if (index < size - 1)
            printf("%i, ", array[index]);
        
        else printf("%i]", array[index]);
    }
    printf("\n");
}

#pragma clang diagnostic pop
