// Function to sort three integers

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Declarations
void sort3(int *, int *, int *);
void print3(int, int, int);

// Main Entry 
int main(void)
{
    // Three Intergers
    int num1, num2, num3;
    
    // Init Three Numbers
    num1 = 500;
    num2 = 500;
    num3 = -100;

    // Print original 
    print3(num1, num2, num3);

    // Sort Intergers
    sort3(&num1, &num2, &num3);

    // Print Sorted 
    print3(num1, num2, num3);

    // Again Init Three Numbers
    num1 = 56;
    num2 = 50;
    num3 = 0;

    // Print original 
    print3(num1, num2, num3);

    // Sort Intergers
    sort3(&num1, &num2, &num3);

    // Print Sorted 
    print3(num1, num2, num3);

    // Again Init Three Numbers
    num1 = 0;
    num2 = 100;
    num3 = 50;

    // Print original 
    print3(num1, num2, num3);

    // Sort Intergers
    sort3(&num1, &num2, &num3);

    // Print Sorted 
    print3(num1, num2, num3);

    return EXIT_SUCCESS;
}

// Function to sort three Integers Varaiables
void sort3(int *n1, int *n2, int *n3)
{
    int temp;
    
    // Swap the Values
    if (*n1 > *n2)
    {
        temp = *n1;
        *n1 = *n2;
        *n2 = temp;
    }

    if (*n1 > *n3)
    {
        temp = *n1;
        *n1 = *n3;
        *n3 = temp;
    }

    if (*n2 > *n3)
    {
        temp = *n2;
        *n2 = *n3;
        *n3 = temp;
    }
}

// Function to print
void print3(int n1, int n2, int n3)
{
    printf("[%i, %i, %i]\n", n1, n2, n3);
}
