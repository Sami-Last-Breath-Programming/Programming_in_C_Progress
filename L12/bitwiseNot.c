// The Ones Compliment Operator (~) BitwiseNot

#include <stdio.h>
#include <stdlib.h>

// Main Entry
int main(void)
{
    // Number
    char num1 = 0xA;

    // Bool to store
    unsigned int flags = 0x0;

    // Set the flags
    flags ^= 0x5;          // T F T
    // flags ^= 0x4;          // T F F

    // Compliment num1;
    printf("~%d = %d\n", num1, ~num1 & 0xFF);

    // Check the first flag
    if (flags ^ 0x4)
        printf("Yes, Last Flag True\n");
    else 
        printf("No, Last Flag not True\n");
    
    return EXIT_SUCCESS;
}

