#include <stdio.h>

#define EXIT_SUCCESS 0

int main(void)
{
    float num1 = 23.0f;
    int num2 = 3;
    int num3 = 4;

    printf("The result is: %f \n", (num1 / num2) + num3);
    printf("The Negative result is: %f \n",
        (num1 / num2) + -num3
    );
    
    return EXIT_SUCCESS;
}