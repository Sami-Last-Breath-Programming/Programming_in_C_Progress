#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Variables
    int num1, num2;
    
    // Ptr for Variables
    int *ptr1, *ptr2;

    // Assigement
    num1 = 5;
    ptr1 = &num1;
    ptr2 = ptr1;

    // Operation
    num2 = ((*ptr1) / 2) + 10;

    // Print the epressions 
    printf("num1: %i, num2: %i\nptr1: %i, ptr2: %i\n", 
        num1, num2, *ptr1, *ptr2
    );
    
    return EXIT_SUCCESS;
}
