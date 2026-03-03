#include <stdio.h>

#define EXIT_SUCCESS 0

int main(void)
{
    int lastRow = 5;
    int currentRow;
    int spacesPrinted;
    int starPrinted;
    int maxSpacePrint;

    // Start from First Row till Last Row
    for (currentRow = 1; currentRow <= lastRow; currentRow++)
    {
        maxSpacePrint = lastRow - currentRow;
        
        // Add Space at starting of each Row
        for (spacesPrinted = 0; spacesPrinted < maxSpacePrint ; spacesPrinted ++)
        {
            printf(" ");
        }

        // Drawing For '*' each Row
        for (starPrinted = 0; starPrinted < currentRow; starPrinted++)
        {
            printf("* ");
        }
        
        // New line after each Row
        printf("\n");
    };
    
    return EXIT_SUCCESS;
}