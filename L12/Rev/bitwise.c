#include <stdio.h>
#include <stdlib.h>

// Macros
#define NIBLE 4
#define BYTE 8

// Declarations
void printBin(char);

int main()
{
    // Flags
    char flag1 = 0b00000001;  // 0000 0001;
    char flag2 = 0b00000001;  // 0000 0001;

    // Operation
    char result = flag1 >> flag2;

    // Print flags
    printBin(flag1);
    printBin(flag2);

    // Print binary 
    printBin(result);
    
    return EXIT_SUCCESS;
}

void printBin(char flag)
{
    char mask = 0b10000000;
    
    for (int index = 0; index < BYTE; index++)
    {
        if (index == 0) 
            printf("[ %c", (flag & mask) ? '1' : '0');
        else if (index == BYTE - 1)
        {
            mask = mask >> 1;
            printf("%c ]\n", (flag & mask) ? '1' : '0');
        }
        else if (index == NIBLE)
        {
            mask = mask >> 1;
            printf(" %c", (flag & mask) ? '1' : '0');
        }
        else 
        {
            mask = mask >> 1;
            printf("%c", (flag & mask) ? '1' : '0');
        }
    }
}