// A program to left shift bits

#include <stdio.h>
#include <stdlib.h>

#pragma clang diagnostic push 
#pragma clang diagnostic ignored "-Wgnu-binary-literal"

// Main Entry
int main(void)
{
    // Declarations
    int num;  
    int shift; 

    // Init
    num = 0b11; // 00000000 00000000 00000000 00000000 00000000 00000000 00000000 000000011
    shift = 0b1; // 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000001

    // Print the Orginal
    printf("Orginal: %i\n", num);

    // Left Shift
    num <<= shift; // 0000000 00000000 00000000 00000000 00000000 00000000 00000000 000000110

    // Print the results
    printf("Result: %i\n", num);
    
    return EXIT_SUCCESS;
}
