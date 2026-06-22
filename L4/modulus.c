#include <stdio.h>

#define EXIT_SUCCESS 0 

void writeNewLine(char *str, int value)
{
    printf("%s = %i, \n", str, value);
}


int main(void)
{
    int num1, num2, num3, num4;
    num1 = 25, num2 = 5, num3 = 10, num4 = 7;

    // Printing Assigned Vaules
    writeNewLine("Num1", num1);
    writeNewLine("Num2", num2);
    writeNewLine("Num3", num3);
    writeNewLine("Num4", num4);

    // Num1 Divide by num2, num3 and num4
    printf("%i %% %i = %i \n", num1, num2, num1 % num2);
    printf("%i %% %i = %i \n", num1, num3, num1 % num3);
    printf("%i %% %i = %i \n", num1, num4, num1 % num4);

    // Precedence
    printf("%i / %i x %i + %i %% %i = %i \n", 
        num1,
        num4,
        num4,
        num1,
        num4,
        num1 / num4 * num4 + num1 % num4
    );

    // % Only works with Integers
    printf("15 %% 2 = %i \n",15 % 2);

    return EXIT_SUCCESS;
}