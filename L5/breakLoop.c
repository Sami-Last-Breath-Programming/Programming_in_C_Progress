#include <stdio.h>

#define EXIT_SUCCESS 0
#define true 1
#define false 0

int main(void)
{   
    int num;
    int flag;

    printf("Enter a Number to Count: ");
    scanf("%i", &num);

    for (int count = 1; count <= num; count++)
    {
        printf("%i \n", count);
        if (count == 50)
        {
            printf("Do you Want to terminate ?\n");
            scanf("%i", &flag);
            if (flag == true) break;
        }
    }
    
    
    return EXIT_SUCCESS;
}