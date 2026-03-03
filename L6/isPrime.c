#include <stdio.h>

#define EXIT_SUCCESS 0 
#define LIMIT 50
#define true 1
#define false 0

typedef _Bool bool;

bool checkIsPrime(int num)
{
    for (int divider = 2; divider < num; divider++)
    {
        if (num % divider == 0) return false;
    } 

    return true;
}

int main(void)
{
    bool isPrime;
    
    for (int num = 2; num <= LIMIT; num++)
    {
        isPrime = checkIsPrime(num);
        if (isPrime) printf("%i ", num);
    }
    printf("\n");

    return EXIT_SUCCESS;
}