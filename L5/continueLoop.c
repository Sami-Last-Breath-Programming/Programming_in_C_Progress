#include <stdio.h>

#define EXIT_SUCCESS 0
#define true 1
#define false 0

#define ANXIETY "I HATE 50, I AM TERMENATING PRESS 0 TO STOP!!! \n"

int main(void)
{
    int num;
    int flag = 0;

    printf("Enter The number to Count: ");
    scanf("%i", &num);

    for (int count = 1; count <= num; count++)
    {
        printf("%i \n", count);
        if (count == 50)
        {
            printf(ANXIETY);
            
            // Untill getchar grab \n run loop 
            while (getchar() != '\n');
            
            scanf("%i", &flag);
            if (flag == false) continue;
            else break;
        }
    }
    
    return EXIT_SUCCESS;
}