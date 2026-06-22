// Basic of Pointers

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Variable of type integer
    int num = 100;

    // Pointer to the variable
    int *ptr_num = &num;
    
    // Assign the value of integer to num2 and add 100
    int num2 = *ptr_num + 100;

    // Print num2
    printf("%i\n", num2);
    
    return EXIT_SUCCESS;
}
