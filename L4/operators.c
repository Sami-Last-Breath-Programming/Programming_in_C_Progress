#include <stdio.h>

#define EXIT_SUCCESS 0;

int main(void)
{
    int num1 = 100; // a
    int num2 = 2;   // b
    int num3 = 25;  // c
    int num4 = 4;   // d

    // Addition
    printf("The sum of %i + %i is: %i \n",
        num1,
        num2,
        num1 + num2
    );

    // Subtraction
    printf("The Difference of %i - %i is: %i \n",
        num1,
        num2,
        num1 - num2
    );
    
    // Multiplication
    printf("The Product of %i x %i is: %i \n",
        num2,
        num3,
        num2 * num3
    );

    // Division
    printf("The Division of %i / %i is: %i \n",
        num1,
        num3,
        num1 / num3
    );

    // Precedence
    printf("The Result of %i + %i x %i is: %i \n",
        num1,
        num2,
        num3,
        num1 + num2 * num3
    );
    printf("The Result of %i x %i + %i x %i is: %i \n",
        num1,
        num2,
        num3,
        num4,
        num1 * num2 + num3 * num4
    );

    return EXIT_SUCCESS;
}