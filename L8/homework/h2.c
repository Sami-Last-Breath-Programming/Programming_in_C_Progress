// |x ^ n|

#include <stdio.h>
#include <stdlib.h>

long int cal_Power(int, int);

int main(void)
{
    int num = 0, pow = 0;
    
    // Header
    printf("\n----------------------------\n");
    printf("Welcome to Power Calculator \n");
    printf("Example: 5 ^ 2\n");
    printf("----------------------------\n");
    
    // Input from User
    int status = scanf("%i ^ %i", &num, &pow);

    // scanf error handle
    if (status <= 1) exit(EXIT_SUCCESS); 

    // Wrong Input Handle 
    if (num < 0 || pow < 0)
    {
        printf("Error: Invalid Input!\n");
        exit(EXIT_FAILURE);
    }
    
    // Calculate Power of given Number
    long int result = cal_Power(num, pow);

    // Print Result
    printf("The Power of %i ^ %i = %li\n",
        num, pow, result
    );
    
    return EXIT_SUCCESS;
}

long int cal_Power(int num, int pow)
{
    long int temp = num;
    
    if (pow == 0) return 1;

    // Multiply num to num pow times
    for (int count = 1; count < pow; count++)
        temp *= num;
    
    return temp;
}