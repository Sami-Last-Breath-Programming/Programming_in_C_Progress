#include <stdio.h>

#define EXIT_SUCCESS 0;
#define true 1
#define false 0

#define checkAccum if (*accum == 0) printf("Accumulator set to Zero\n"); 
#define printAccum printf("= %.6f\n", *accum);

typedef _Bool bool;

enum Operations
{
    ADD = '+',
    SUB = '-',
    MUL = '*',
    DIV = '/',
    MOD = '%',
    SET = 'S',
    END = 'E'
};

void calculator(
    float num,
    char operator,
    bool *isExit,
    float *accum
)
{
    switch (operator)
    {
        case SET:
            *accum = num;
            printAccum
            break;
        
        case END:
            printAccum
            *isExit = true;
            break;
        
        case ADD:
            checkAccum
            *accum += num;
            printAccum
            break;
        
        case SUB:
            checkAccum
            *accum -= num;
            printAccum
            break;
        
        case MUL:
            checkAccum
            *accum *= num;
            printAccum
            break;
        
        case DIV:
            checkAccum
            if (num == 0)
            {
                printf("Error Divided By Zero !\n");
                break;
            }
            *accum /= num;
            printAccum
            break;

        case MOD:
            checkAccum
            *accum = (float)((int)*accum % (int)num);
            printf("= %i\n", (int)*accum);
            break;
            
    }
}


void makeUI()
{   
    bool isExit = false;
    float num;
    float accum = 0;
    char operator;
    
    printf("\n-----------------------\n");
    printf("Welcome To Calculator: \n");
    printf("-----------------------\n");

    while (!isExit)
    {
        scanf("%f %c", &num, &operator);
        calculator(num, operator, &isExit, &accum);
    }
    printf("\n------------------\n");
    printf("Calculator Closed!\n");
    printf("------------------\n");
}

int main(void)
{
    makeUI();
    return EXIT_SUCCESS;
}