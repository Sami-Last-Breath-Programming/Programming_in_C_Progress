#include <stdio.h> 

#define EXIT_SUCCESS 0


void gcd(int num1, int num2)
{
    int divisor, divident, reminder;
    
    if (num1 > num2)
    {
        divisor = num2;
        divident = num1;
    }
    else
    {
        divisor = num1;
        divident = num2;
    };

    while (divisor != 0)
    {
        reminder = divident % divisor;
        divident = divisor;
        divisor = reminder;
    };

    printf("The Gretest Common Factor of %i and %i is %i\n\n", 
        num1, num2, divident
    );
}

int main(void)
{
    int num1, num2;

    printf("\n---------------------------------\n");
    printf("Welcome to GCM Finder\n");
    printf("Example: 15, 10\n");
    printf("---------------------------------\n");
    scanf("%i , %i", &num1, &num2);

    gcd(num1, num2);

    return EXIT_SUCCESS;
}