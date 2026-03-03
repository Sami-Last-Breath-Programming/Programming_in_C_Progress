// Finding Table of 3

#include <stdio.h>

#define EXIT_SUCCESS 0

int main(void)
{
    printf("\nThe Table Of 3 \n");
    printf("-------------\n");
    
    
    for (int num = 3, multiplier = 1;
        multiplier <= 10; multiplier++
    )
    {
        printf("%2i x %2i = %2i \n",
            num, 
            multiplier,
            num * multiplier
        );
    }
    
    
    return EXIT_SUCCESS;
}