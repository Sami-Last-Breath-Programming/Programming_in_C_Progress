// Swap Two Numbers using  bitwise XOR

#include <stdio.h>
#include <stdlib.h>

// Main Entry 
int main(void)
{
    // Unsigned integer 
    unsigned int num1 = 024u;
    unsigned int num2 = 036u;
    
    // Swap the integers
    num1 ^= num2;
    num2 ^= num1;
    num1 ^= num2;

    // Print the Value 
    printf("Number 1 = %d\nNumber 2 = %d\n",
        num1, num2
    );
    
    return EXIT_SUCCESS;
}
