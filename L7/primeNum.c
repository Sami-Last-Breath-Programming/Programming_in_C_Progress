#include <stdio.h>

#define EXIT_SUCCESS 0
#define true 1
#define false 0

int LIMIT;
typedef _Bool bool;

// Check if the given number is prime or not.
bool checkPrime(int num, int *primeNum)
{   
    bool isPrime =  true;
    
    // Check the num by dividing with each prime.
    for (int index = 0; index < LIMIT; index++)
    {
        // if remender == zero not prime.
        if (num % primeNum[index] == 0)
        {
            isPrime = false;
            break;
        }   
        /*
            if any prime number in array is greater
            than square root of number then it is a 
            prime. (p^2 > n)
        */
       else if ((primeNum[index] * primeNum[index]) > num)
       {
            isPrime = true;
            break;
       }
    }
    return isPrime;
}


int main(void)
{   
    // Input from user for prime search Limit.
    printf("Enter the Limit to check Prime: ");
    scanf("%i", &LIMIT);

    // Array to store prime Numbers 
    int primeNum[LIMIT];
    
    // Track of known primes
    int currentPrimes = 2;
    
    // Default know Primes.
    primeNum[0] = 2;
    primeNum[1] = 3;

    // If input is out of sysetm limit don't process 
    if (LIMIT && LIMIT <= 2000000)
    {
        // Loop till max number leaving even numbers.
        for (int num = 5; num <= LIMIT; num +=2)
        {
            // Checking if num is prime or not 
            if (checkPrime(num, primeNum))
            {
                currentPrimes += 1;
                primeNum[currentPrimes - 1] = num;
            }
        }
        // Printing all found prime numbers.
        for (int index = 0; index < currentPrimes; index++)
        {
            printf("%i\n", primeNum[index]);
        }
    }
    else printf("\nError: Invalid Limit\n");

    return EXIT_SUCCESS;
}