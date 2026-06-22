#include <stdio.h> 

#define EXIT_SUCCESS 0 

void greeting(void)
{
    printf("Greeting Function");
}

int main(void)
{
    for (int count= 1; count <=5; count++)
    {
        greeting();
        printf(" Called %i Times.\n", count);
    }
    
    return EXIT_SUCCESS;
}