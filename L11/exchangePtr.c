// Exchnage the value of pointers 

#include <stdio.h>
#include <stdlib.h>

// Declarations
void switch_Value(int * const, int * const);

// Main Entry 
int main(void)
{
    int num1 = -5, num2 = 66;
    int *ptr1 = &num1, *ptr2 = &num2;

    // Before the Switch 
    printf("Num1: %i, Num2: %i\n", *ptr1, *ptr2);

    switch_Value(ptr1, ptr2);

    // After the Switch
    printf("Num1: %i, Num2: %i\n", *ptr1, *ptr2);

    switch_Value(&num1, &num2);

    // After the Switch
    printf("Num1: %i, Num2: %i\n", *ptr1, *ptr2);
    
    return EXIT_SUCCESS;
}

void switch_Value(int * const ptr1, int * const ptr2)
{
    int temp;

    // Swap the values 
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
