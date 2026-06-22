// Triangular Number Return

#include <stdio.h> 
#include <stdlib.h>

int calculate_triNum(int num)
{
    int triNum = 0;
    
    // Adding till 1 to n for triNum
    for (int countNum = 1; countNum <= num; countNum++)
    {
        triNum +=countNum;
    }
    return triNum;
}

int main(void)
{   
    int num;

    // Number from Use
    printf("Enter the Number: ");
    scanf("%i", &num);

    // Calculate and Print Result
    printf("%ith Triangular Number is %i\n", 
        num, calculate_triNum(num)
    );
    
    return EXIT_SUCCESS;
}