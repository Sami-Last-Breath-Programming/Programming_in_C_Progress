// Fn = (second last) + (last) 

#include <stdio.h>

#define EXIT_SUCCESS 0 
#define Error 1
#define errorMSG "Error! System can't print more than 80 Fibonacci Numbers\n"

int main(void)
{
    int num;
    long int temp = 0;
    
    // Asking for how many to find
    printf("How Many Fibonacci Numbers to Find: ");
    scanf("%i", &num);

    // Checking if num is more than program limits
    if (num > 80)
    {
        printf(errorMSG);
        return Error;
    }   
    
    long int secondLast = 0, last = 1;

    // Loop till larget numbers and printing
    for (int count = 0; count <= num; count++)
    {
        if (count <= 1)
            printf("%i\n", count);
        else
        {   
            temp = secondLast + last;
            printf("%li\n", temp);

            secondLast = last;
            last = temp;
        }  
    }

    return EXIT_SUCCESS;
}