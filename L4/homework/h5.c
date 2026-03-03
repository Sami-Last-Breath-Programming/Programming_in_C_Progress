/*  Write a program to evaluate the polynomial shown here:
    3x3 - 5x2 + 6
    for x = 2.55
*/

#include <stdio.h>

#define EXIT_SUCCESS 0;

int main(void)
{
    const float x = 2.55f;

    printf("The Result is: %.4f \n", 
        (3*(x*x*x)) - (5*(x*x)) + 6   
    );
    
    return EXIT_SUCCESS;
}