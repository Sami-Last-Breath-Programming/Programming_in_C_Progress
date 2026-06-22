// Fn = (second last) + (last) 

#include <stdio.h>

#define EXIT_SUCCESS 0 
#define Error 1

#define fiboNum(secondLast, last) fibonacci[secondLast] + fibonacci[last] 
#define errorMSG "Error! System can't print more than 80 Fibonacci Numbers\n"

int main(void)
{
    int num; 
    
    // Asking for how many to find
    printf("How Many Fibonacci Numbers to Find: ");
    scanf("%i", &num);

    // Checking if num is more than program limits
    if (num > 80)
    {
        printf(errorMSG);
        return Error;
    }   
    
    // Defining Array to store each fibon number
    long int fibonacci[num];
    fibonacci[0] = 0; fibonacci[1] = 1;

    // Loop till larget numbers and store them in array
    for (int count = 2; count < num; count++)
    {
        fibonacci[count] = fiboNum(count - 2, count - 1);
    }

    // Showing Fibonacci Numbers 
    for (int count = 0; count < num; count++)
    {
        printf("Number %2i: \t%18li\n", count + 1, fibonacci[count]);
    }
    
    return EXIT_SUCCESS;
}