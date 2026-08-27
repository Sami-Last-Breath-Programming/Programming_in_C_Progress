// Logical Right Shift - Hardware Ignores Sign Bit
// Arithmetic Right Shift - Hardware Includes Sign Bit

// Program to check Right Shift

#include <stdio.h>
#include <stdlib.h>
#include "../BitFields/printBin.h"

// Clang Fix
ClangStart
ClangAdd("-Wswitch-default")
ClangAdd("-Wc23-extensions")

// Enum
typedef enum Type
{	UINT, SINT	}
Type;

// Declarations
void rightShift(void * num, int shift, Type type);

int main(void)
{
	// Two integers
	signed int iBytes = 25;
	unsigned int uBytes = 25;

	// Print both integer bytes
	printBin(UINT(iBytes));
	printBin(UINT(uBytes));

	// Right Shift both
	rightShift(&iBytes, 1, SINT);
	rightShift(&uBytes, 1, UINT);

	// Print newline
	printf("\n");

	// Print both integer bytes
	printBin(UINT(iBytes));
	printBin(UINT(uBytes));

	return EXIT_SUCCESS;
}

void rightShift(void *num, int shift, Type type)
{	
	// Match type 
	switch (type)
	{
		case SINT:
			// Cast void to signed int
			signed int *sTmp = (signed int *)num;
			// Right shift
			*sTmp >>= shift;
			break;
		
		case UINT:
			// Casr void to unsigned int
			unsigned int *uTmp = (unsigned int *)num;
			// Right shift
			*uTmp >>= shift;  
			break;
	}
}
ClangStop
