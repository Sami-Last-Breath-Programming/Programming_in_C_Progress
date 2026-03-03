/*  Write a program that subtracts the value 15 from 87 and 
    displays the result, together with an appropriate message,
    at the terminal.
*/

#include <stdio.h>

int main(void)
{   
    int num1 = 87;
    int num2 = 15;

    int result = num1 - num2;
    
    printf("The Result of 15 subtracted from 87 is: %i\n",
        result
    );

    return 0;
}