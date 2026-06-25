// BitWise for used for setting bit to 1

#include <stdio.h>
#include <stdlib.h>

// Main Entry
int main(void)
{
    // Octal Unsigned integer
    unsigned int num1 = 002u;
    unsigned int num2 = 003u;
    unsigned int itself = 010u;

    // Check for result
    unsigned int result = num1 | num2;

    // Bitwise OR on itslef
    unsigned int uResult = itself | itself;

    // Print the result
    printf("(%o, %d) | (%o, %d) = (%o, %d )\n",
        num1, num1, num2, num2, result, result
    );
    printf("(%o, %d) | (%o, %d) = (%o, %d)\n", 
        itself, itself, itself, itself, uResult, uResult
    ); 
    
    return EXIT_SUCCESS;
}
