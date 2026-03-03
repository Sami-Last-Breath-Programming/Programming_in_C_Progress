/*  Write a program that evaluates the following expression 
    and displays the results.
*/

#include <stdio.h>

#define EXIT_SUCCESS 0

int main(void)
{
    double val1 = 3.31e-8 * 2.01e-7;
    double val2 = 7.16e-6 + 2.01e-8;

    double result = val1 / val2;

    printf("The Answer is: %.4e \n", result);

    return EXIT_SUCCESS;
}