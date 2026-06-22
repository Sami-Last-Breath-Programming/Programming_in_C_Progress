#include <stdio.h>

#define EXIT_SUCCESS 0

int main(void)
{
    int couting = 1;
    const int count =  100;  

    
    while (couting <= count)
    {
        printf("---> %3i \n",couting);
        couting++;
    }
        
    return EXIT_SUCCESS;
}