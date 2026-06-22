// Return a pointer from a function 

#include <stdio.h>
#include <stdlib.h>

// Clang Flags
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"

// Integer Entry
typedef struct IntEntry
{
    int value;
    struct IntEntry *next;
}IntEntry;

// Declarations
IntEntry *findEntry(IntEntry *, int);

// Main Entry
int main(void)
{
    int num, result;
    IntEntry num1, num2, num3, num4, num5;
    IntEntry *start, *ptrResult;

    // Assign the values
    num1.value = 100;
    num2.value = 200;
    num3.value = 300;
    num4.value = 400;
    num5.value = 500;

    // Assign the pointers
    start = &num1;
    num1.next = &num2;
    num2.next = &num3;
    num3.next = &num4;
    num4.next = &num5;
    num5.next = (IntEntry *)0;
    
    // Take the input from the user 
    printf("Enter A Number To Find: ");
    result = scanf("%i", &num);

    // Check the input result 
    if (result < 0)
    {
        printf("Error: Input Scan Failed !\n");
        exit(EXIT_FAILURE);
    }

    // Call the function
    ptrResult = findEntry(start, num);

    // Check the result
    if (ptrResult != (IntEntry *)0)
        printf("The Number Found: %i\n", ptrResult->value);
    else
        printf("The Number Not Found !\n");

    return EXIT_SUCCESS;
}

IntEntry *findEntry(IntEntry *ptr, int value)
{   
    while (ptr != (IntEntry *)0)
    {
        if (ptr->value == value) return ptr;
        else ptr = ptr->next;
    }

    return (IntEntry *)0;
}
#pragma clang diagnostic pop
