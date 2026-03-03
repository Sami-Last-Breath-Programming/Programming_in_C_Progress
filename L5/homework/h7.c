#include <stdio.h>

#define EXIT_SUCCESS 0

int main(void)
{
    int currentNum = 1, triNum = 0, rows = 200;
    
    while (currentNum <= rows)
    {
        triNum += currentNum;
        currentNum++;
    }
    printf("The 200th Triangular Number is: %i \n", 
        triNum
    );
    
    return EXIT_SUCCESS;
}