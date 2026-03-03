#include <stdio.h>

#define EXIT_SUCCESS 0
#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'
#define MOD '%'

void calculate(float num1, float num2, char operator)
{
    switch (operator)
    {
        case ADD:
            printf(": %.2f\n", num1 + num2);
            break;
       
        case SUB:
            printf(": %.2f\n", num1 - num2);
            break;
        
        case MUL:
        case 'x':
        case 'X':
            printf(": %.2f\n", num1 * num2);
            break;
        
        case DIV:
            (num2 == 0)? printf("Error! Divide By ZERO\n"): printf(
                ": %.2f\n", num1 / num2
            );
            break;
        
        case MOD:
            printf(" %.2i\n", (int)num1 % (int)num2);
            break;
       
        default:
            printf("Invalid OR Null Operator\n");
            break;
    }
}

int main(void)
{
    float num1, num2;
    char operator;

    printf("Enter the Expression: ");
    scanf("%f %c%f", &num1, &operator, &num2);

    calculate(num1, num2, operator);

    return EXIT_SUCCESS;
}
