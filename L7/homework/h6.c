// Sieve of Eratosthenes Algorithm 

#include <stdio.h> 

#define EXIT_SUCCESS 0

int main(void)
{
    int numLimit;

    // Input from the user for prime numbers limit
    printf("Enter the Limt to find Prime Numbers: ");
    scanf("%i", &numLimit);

    // Not using zero index
    numLimit += 1;

    // Array for prime number find 
    int primes[numLimit];

    // We already know 
    primes[1] = 0;
    primes[2] = 1;

    // Asumming after 2 all are primes
    for (int index =  3; index <= numLimit; index++)
    {
        primes[index] = 1;
    }
    
    // Logic for prime find 
    for (int num = 3; num <= numLimit; num += 2)
    {
        for (int mult = 2; mult <= numLimit; mult ++)
        {
            if ((num * mult) > numLimit) break;
            else primes[num * mult] = 0;
        }
    }
    
    // Default prime
    printf("2\n");
    
    // Printing Primes 
    /*
        The Outer loop loops till the numLimit - 1 but the index += 2 takes the 
        number to the numLimit if numLimit is odd. else in case of even it just 
        stop as it become larger than numLimit.

    */
    for (int index = 3; index <= numLimit - 1; index +=2) 
    {
        if (primes[index] == 1)
            printf("%i\n", index);
    }
    
    return EXIT_SUCCESS;
}