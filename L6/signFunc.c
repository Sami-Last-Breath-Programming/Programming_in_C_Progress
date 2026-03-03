#include <stdio.h>

#define EXIT_SUCCESS 0

int main(void)
{
    int number, sign;

    printf("Enter The Number: ");
    scanf("%i", &number);

    if (number < 0) sign = -1;
    else if (number == 0) sign = 0;
    else sign = 1;
    
    printf("The Sign = %i \n", sign);
    
    
    return EXIT_SUCCESS;
}