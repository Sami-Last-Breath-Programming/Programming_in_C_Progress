#include <stdio.h>

#define EXIT_SUCCESS 0

int main(void)
{
    int currentNum, triNum, rows;
    triNum = 0;
    rows = 10;

    // Heading And Table
    printf("\nThe Table of Triangular Numbers \n");
    printf("---------------------------------\n");
    printf(" Rows      Sum from 1 to Rows    \n");
    printf("------     ----------------------\n");
    
    for (currentNum = 1; currentNum <= rows ; currentNum++)
    {   
        triNum += currentNum;
        printf("   %2i                  %i          \n",
            currentNum, triNum
        );
    };
    
    return EXIT_SUCCESS;
}