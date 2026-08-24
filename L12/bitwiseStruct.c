// BitField using structs 

#include <stdio.h>
#include <stdlib.h>
#include "BitFields/printBin.h"

// Clang 
ClangStart

// Struct for packed flags
typedef struct packedFlags
{
	unsigned int :		3U;
	unsigned int f1:	1U;
	unsigned int f2:	1U;
	unsigned int f3:	1U;
	unsigned int type:	8U;
	unsigned int index: 18U;

}packedFlags;

// Main Entry
int main(void)
{
	// Set flags 
	packedFlags flags = {
		.f1 = 1U,
		.f2 = 0U,
		.f3 = 1U,
		.type = 4U,
	} ;
	
	// Print type 
	printBin(flags.type);

	// Print flags 
	printBin(flags.f1);
	printBin(flags.f2);
	printBin(flags.f3);
	
	return EXIT_SUCCESS;
}
ClangStop
