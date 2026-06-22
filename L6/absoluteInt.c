#include <stdio.h>

#define EXIT_SUCCESS 0

int main(void)
{
    int number;

    printf("Enter A Number: ");
    scanf("%i", &number);

    if (number < 0)
    {
        number = -number;
    }
    printf("The |Number|: |%i| \n", number);
    
    return EXIT_SUCCESS;
}