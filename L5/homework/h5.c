// minus in field weight 

#include <stdio.h>

#define EXIT_SUCCESS 0

int main(void)
{
    //counting till 100 leaving 10

    for (int count = 0; count <= 100; count +=10)
    {
        printf("--->      %-3i\n", count);
    }    
    return EXIT_SUCCESS;
}