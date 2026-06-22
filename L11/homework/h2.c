// Sort an array using pointers

#include <stdio.h>
#include <stdlib.h>

// Clang Flags
#pragma clang diagnostic push 
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

// Macros 
#define LEN(x) (x - 1)
#define SIZE(x) (sizeof(x) / sizeof(x[0]))

// Declarations
void sortArray(int *, size_t);
void printArray(int *, size_t);

// Main Enrty 
int main(void)
{
    // Demo Array
    int array[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};

    // Sort Array
    sortArray(array, SIZE(array));

    // Print Array
    printArray(array, SIZE(array));
    
    return EXIT_SUCCESS;
}

// Function to sort array
void sortArray(int *array, size_t size)
{
    // For a backup
    int temp;
    int *current, *next, *end;

    // On start
    current = array;
    end = array + LEN(size);

    // Comparting The elements with each other (II1)
    while (current <= end)
    {   
        // Swaping the position if it's smaller (SI2)
        for (next = current + 1; next <= end; next++)
        {
            if (*current > *next)
            {
                temp = *current;
                *current = *next;
                *next = temp;
            }
        }
        // Increase the pointer
        current++;
    }  
}

// Function to print array
void printArray(int *array, size_t size)
{
    int *current, *end;

    // On start
    current = array;
    end = array + LEN(size);

    // Formating 
    printf("[");
    
    // Looping till array and pritning all items
    while(current <= end)
    {
        if (current < end)
            printf("%i, ", *current);
        
        else printf("%i]", *current);

        // Increase the current
        current++;
    }
    printf("\n");
}
#pragma clang diagnostic pop
