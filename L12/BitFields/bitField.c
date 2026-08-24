// Pack data in bytes 
#include <stdio.h>
#include <stdlib.h>
#include "printBin.h"

// Macros
#define LIMIT_255(n) ((n) & 0xffU) 

// Start Clang Dig
ClangStart

// Main Entry 
int main(void)
{
	// Variable for packed data 
	unsigned int packed = 0b0U;
	unsigned int mask = ~(0xffU << 18U);
	
	// Pack flags in the data 
	packed |= (1U << (18U + 10U));  	// F1: 	(Offset + Index) = (18 + 10)
	packed |= (0U << (18U + 9U));	 	// F2:	(Offset + Index) = (18 + 09)
	packed |= (1U << (18U + 8U));		// F3:	(Offset + Index) = (18 + 08)

	// Pack the type 
	packed |= (7U << 18U);

	// Mask the type
	packed &= mask;

	// Full mask and add
	packed = (packed & mask ) | (LIMIT_255(4U) << 18U);
	
	// Output: 0001 1100 0001 0000 0000 0000 0000 0000
	printBin(packed);

	// Extract out flags 
	unsigned int f1 = (packed >> (18U + 10U)) & 1U; 
	unsigned int f2	= (packed >> (18U + 9U)) & 1U;
	unsigned int f3 = (packed >> (18U + 8U)) & 1U;

	// Print flags
	printBin(f1);
	printBin(f2);
	printBin(f3);
	
	return EXIT_SUCCESS;
}
// Stop Clang dig
ClangStop
