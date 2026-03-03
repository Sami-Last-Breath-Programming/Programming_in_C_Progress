#include <stdio.h>

#define EXIT_SUCCESS 0
#define ADD '+'
#define MUL '*'
#define SUB '-'
#define DIV '/'
#define MOD '%' 

void calculate(char operator, float num1, float num2)
{   
    if (operator == ADD) printf(": %.2f\n", num1 + num2);
    else if (operator == SUB) printf(": %.2f\n", num1 - num2 );
    else if (operator == MUL || operator == 'x') printf(
        ": %.2f\n", num1 * num2
    );
    else if (operator == DIV) (num2 == 0) ? printf("Error! Divided By Zero\n") 
    : printf(": %.2f\n", num1 / num2);
    
    else if (operator == MOD) printf(
        ": %i\n", (int)num1 % (int)num2
    );
    else printf("Null or Invalid Operator \n");
}


int main(void)
{   
    float num1, num2;
    char operator;
    
    printf("Enter Expression: ");
    scanf("%f %c %f", &num1, &operator, &num2);
    calculate(operator, num1, num2);
    
    return EXIT_SUCCESS;
}