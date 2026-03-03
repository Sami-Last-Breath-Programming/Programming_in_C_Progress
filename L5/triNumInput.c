#include <stdio.h>

#define EXIT_SUCCESS 0

int main(void)
{
    int currentNum, rows, triNum;

    triNum = 0;

    printf("Enter The Rows OF Triangle: ");
    scanf("%i", &rows);

    for (currentNum = 1; currentNum <= rows; currentNum++)
    {
        triNum += currentNum; 
    };
    printf("The %ith Triangular Number is %i \n",
        rows, triNum
    );
    
    return EXIT_SUCCESS;
}