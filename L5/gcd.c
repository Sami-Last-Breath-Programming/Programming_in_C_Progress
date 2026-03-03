/*  Find the Greatest Common Divisor of 
    two Numbers
*/

#include <stdio.h>

#define EXIT_SUCCESS 0;

int main(void)
{
    int num1, num2, divisor, dividend, remainder;
    
    printf("Enter Two Numbers: ");
    scanf("%i%i", &num1, &num2);

    // settng divisor and divident
    if (num1 > num2)
    {
        divisor = num2;
        dividend = num1;
    }else
    {
        divisor = num1;
        dividend = num2;
    }

    // Loop untill remainder == 0
    while (divisor != 0)
    {
        remainder = dividend % divisor;
        dividend = divisor;
        divisor = remainder;
    }

    printf("The GCD OF %i and %i is: %i \n", 
        num1, num2, dividend
    );

    
    return EXIT_SUCCESS;
}