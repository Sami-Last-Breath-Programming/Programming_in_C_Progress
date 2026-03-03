#include <stdio.h>

#define EXIT_SUCCESS 1

void checkEven(int num)
{
    if (num % 2 == 0) printf("Number is Even \n");
    else printf("Number is Odd \n");
}

int makeUI(void)
{
    int number;
    printf("Enter The Number: ");
    scanf("%i", &number);
    return number;
}

int main(void)
{
    checkEven(makeUI());
    return EXIT_SUCCESS;
}