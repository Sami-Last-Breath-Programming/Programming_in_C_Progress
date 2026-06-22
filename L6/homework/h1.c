#include <stdio.h>

#define EXIT_SUCCESS 0
#define true 1
#define false 0 

// Boolen Defination
typedef _Bool bool;

bool divideNum(int num1, int num2)
{   
    if (num2 != 0)
        return (num1 % num2 == 0) ? true : false;
    else 
    {
        printf("\nDivided By Zero !\n");
        return false;
    }
}

int main(void)
{
    int num1, num2;

    printf("Enter Two Number: ");
    scanf("%i /%i", &num1, &num2);
    
    if (divideNum(num1, num2))
        printf("Yes: %i is Divisible by %i\n", num1, num2);
    else
        printf("No: %i is not Divisible by %i\n", num1, num2);
    
    return EXIT_SUCCESS;
}