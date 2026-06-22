// Pointers to a function

#include <stdio.h>
#include <stdlib.h>

// Declarations
int sum(int, int);

// Main Entry 
int main(void)
{
    // Two numbers 
    int num1, num2;
    
    // Pointer to a function
    int (*ptr_sum) (int, int); 

    // Init number
    num1 = 50;
    num2 = 50;

    // Init Pointer to a function 
    ptr_sum = sum;

    // Call the sum function pointer
    printf("The Result of %i and %i: %i\n", 
        num1, num2, ptr_sum(num1, num2)
    );
    
    return EXIT_SUCCESS;
}

int sum(int a, int b) {    return a + b;   }
