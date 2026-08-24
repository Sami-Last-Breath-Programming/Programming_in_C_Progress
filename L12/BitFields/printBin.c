#include <stdio.h>
#include "printBin.h"

// Function which prints binary of a Uint 
void printBin(unsigned int flag)
{
    unsigned int mask = MASK;
	unsigned int currentNibble = 0UL;

	// Loop over the Bits
    for (size_t index = 0; index < BITS; index++)
    {		
		// Handle End 
		if (index == END)
		{
			RIGHT_SHIFT;
			printf("%c ]\n", (flag & mask) ? '1' : '0');
			break;
		}
		
		// Handle Nibble 
		if (currentNibble + NIBLE - 1UL == index)
		{
			RIGHT_SHIFT;
			printf("%c ", (flag & mask) ? '1' : '0');
			currentNibble = currentNibble + NIBLE;
			continue;
		}
		
		// Check Others
		switch (index)
		{
			case START:
				printf("[ %c", (flag & MASK) ? '1' : '0');
				break;
			default:
				RIGHT_SHIFT;	
				printf("%c", (flag & mask) ? '1' : '0');
				break;
		}
    }
}
