// Recursive Functions

#include <stdio.h>
#define EXIT_SUCCESS 0

// Typedef or unsigned int
typedef unsigned int uint; 
typedef long unsigned int luint;

luint factorial(uint num);

// Main Entry
int main(void)
{
    // Factorial of 0 To 10 
    for (uint num = 0; num <= 10; num++)
        printf("%3u! = %lu\n", num, factorial(num));

    return EXIT_SUCCESS;
}

luint factorial(uint num)
{
    // Return 1 if num 0
    if (num == 0)
        return 1;
    // Main Calculation
    else return num * factorial(num - 1);
}