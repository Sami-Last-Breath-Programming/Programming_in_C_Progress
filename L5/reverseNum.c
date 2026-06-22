#include <stdio.h>

#define EXIT_SUCCESS 0

int popLastNum(int num)
{
    return num / 10;
}

int getLastNum(int num)
{
    return num % 10;
}

int main(void)
{
    int num;
    
    printf("Enter the Number to Reverse: ");
    scanf("%i", &num);

    if (num < 0)
    {
        printf("Negative Number Sign Ignored \n");
        num *= -1;
    }

    while (num != 0)
    {
        printf("%i", getLastNum(num));
        num = popLastNum(num);
    }

    printf("\n");
    
    return EXIT_SUCCESS;
}