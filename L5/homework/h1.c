/*  Write a program to generate and display a table of n 
    and n^2, for integer values of n ranging from 1 to 10. 
    Be certain to print appropriate column headings.
*/

#include <stdio.h>

#define EXIT_SUCCESS 0

int main(void)
{
    printf("\nThe Table of n and n\u00B2 \n");
    printf("------------------------\n");
    printf("    n              n\u00B2 \n");
    printf("------------------------\n");
    
    for (int n = 1; n <= 10; n++)
    {
        printf("   %2i           %3i \n", n, n*n);
    }
    
    return EXIT_SUCCESS;
}