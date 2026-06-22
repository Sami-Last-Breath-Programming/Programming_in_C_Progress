// Pointers as arguments to functions 

#include <stdio.h>
#include <stdlib.h>

// Declarations
void add_Fifty(int *);

// Main Entry
int main(void)
{
    int num = 50;
    int *num_Ptr = &num;

    // Before function call
    printf("Before: %i\n", *num_Ptr);

    // Function call
    add_Fifty(num_Ptr);

    // After function call
    printf("After: %i\n", *num_Ptr);
    
    return EXIT_SUCCESS;
}

void add_Fifty(int *ptr) {   *ptr += 50;   }
