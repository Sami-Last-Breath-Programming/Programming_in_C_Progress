// Factorial generating and printing

#include <stdio.h>

#define EXIT_SUCCESS 0

int factorial(int num)
{
    int result = 1;

    for (int count = 2; count <= num; count++)
    {
        result *= count;
    }
    return result;
}

void makeUI(void)
{
    printf("\n    N!      Factorial    \n");
    printf("-------------------------\n");
}

int main(void)
{
    const int totalNum = 10;
    
    makeUI();

    for (int currentNum = 1; currentNum <= totalNum; currentNum++)
    {
        printf("     %2i!      %7i            \n",
            currentNum, factorial(currentNum)
        );
    }
    
    
    return EXIT_SUCCESS;
}