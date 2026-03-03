#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0
#define true 1
#define false 0

typedef _Bool bool;

typedef struct
{
    bool flag;
    float answer;
    
}Result;

Result* divide(int num1, int num2)
{   
    Result *result = malloc(sizeof(Result));

    if (num2 != 0)
    {
        result->flag = true;
        result->answer = (float)num1 / (float) num2;
        return result;
    }
    else
    {
        result->flag = false;
        result->answer = 0.0f;
        return result;
    }
}

int main(void)
{
    int num1 , num2;
    
    printf("Enter Two Number : ");
    scanf("%i / %i", &num1, &num2);

    Result *result = divide(num1, num2);
    
    if (result->flag)
        printf(": %.3f\n", result->answer);
    else
        printf("Can't Divide by Zero\n");

    free(result);
    
    return EXIT_SUCCESS;
}