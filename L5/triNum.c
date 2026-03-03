#include <stdio.h>

#define EXIT_SUCCESS 0

int main(void)
{
    int currentInt, triNum, rows;
    triNum = 0;
    rows = 200;
    
    for (currentInt =1; currentInt <=rows; currentInt++)
    {
        triNum += currentInt; 
    }
    
    printf("The %ith Triangular Number is: %i \n",
        rows, triNum     
    );
    
    return EXIT_SUCCESS;
}