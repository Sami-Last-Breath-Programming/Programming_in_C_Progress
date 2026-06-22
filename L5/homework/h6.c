// precision of float in formated string

#include <stdio.h>

#define EXIT_SUCCESS 0

int main(void)
{
    int dollars, cents, count = 1;

    for (; count <=10; count++)
    {
        printf("Enter Money in format $.\u00A2: ");
        scanf("%i.%i", &dollars, &cents);

        printf("The Money is $%i.%.2i\u00A2\n",
            dollars, cents
        );
    }

    printf("%.2s\n", "hello");
    
    return EXIT_SUCCESS;
}