#include <stdio.h>
#include <stdlib.h>

int prime(int);

int main(int args, char **argv)
{
    int isPrime = 0;
    
    // If no arg or invalid arg
    if (args < 2 || args > 3)
    {
        printf("Please Enter A Valid Argument\n");
        exit(EXIT_FAILURE);
    }

    // Check the numnber for Prime
    isPrime = prime(atoi(argv[1]));
    
    // Print Result 
    (isPrime) ? printf("Yes\n") : printf("No \n");

}

int prime(int num)
{
    if (num < 2) return 0;    
    
    for (int divider = 2; divider < num; divider++)
    {
        if (num % divider == 0) return 0;
    } 
    return 1;
}