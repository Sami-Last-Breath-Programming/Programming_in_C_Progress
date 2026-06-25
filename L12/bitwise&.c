// Bitwise And use for masking, read write, and clearning bit

#include <stdio.h>
#include <stdlib.h>

// Main Entry
int main(void)
{
    // One byte integer
    char num1 = 2;
    char num2 = 3;

    // Octal Unsigned integer
    unsigned int itself = 077u;
    unsigned int val2 = 0150u;
    unsigned int vla3 = 0210u;

    // Check the result
    char result = num1 & num2;

    // Bitwise And of itself
    unsigned int uResult = itself & itself;

    // Bitwise And of three
    unsigned int aResult = itself & val2 & vla3;

    // Print the result 
    printf("%d\n", result);
    printf("%o, %u\n", uResult, uResult);
    printf("Result: %o, %u\n", aResult, aResult);

    return EXIT_SUCCESS;
}
