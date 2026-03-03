/*  This program adds two integer numbers 
    and display it's results.
*/

#include <stdio.h>

int main(void)
{
    // Declaration of identifier
    int num1, num2, sum;
    
    // Assignment of identifier
    num1 = 50;
    num2 = 25;
    sum = num1 + num2;

    // Display the result
    printf("The sum of %i and %i is: %i\n",
        num1,
        num2,
        sum
    );
    return 0;
}