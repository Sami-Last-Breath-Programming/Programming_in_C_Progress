#include <stdio.h>

#define EXIT_SUCCESS 0

int main(void)
{
    int last = 1;
    
    for (int index = 1;  index < 11; index++)
    {
        last *= 2;
        printf("%i ", last);
    }
       

    printf("\n");

    return EXIT_SUCCESS;
}