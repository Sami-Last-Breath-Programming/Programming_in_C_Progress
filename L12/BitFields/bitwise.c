#include <stdio.h>
#include <stdlib.h>
#include "printBin.h"

// Clang
ClangStart

// Main Entry
int main(void)
{
    // Flags
    unsigned int flag1 = 0b01U;
    unsigned int flag2 = 0b10U;

    // Operation
    unsigned int result = flag1 << flag2;

    // Print flags
    printBin(flag1);
    printBin(flag2);

	// Line
	printf("___________________________________________\n");

    // Print binary 
    printBin(result);
    
    return EXIT_SUCCESS;
}
ClangStop
