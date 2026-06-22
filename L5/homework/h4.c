// Reformated program 

#include <stdio.h>

int main(void)
{
    int n = 0, result = 1;

    printf("\nTABLE OF POWERS OF TWO \n\n");
    printf("  n            2\u207F \n");
    printf(" ---          --- \n");

    for (; n <= 10; n++, result *= 2)
    {
        printf(" %2i         %4i\n", n, result);
    }

    return 0;
}