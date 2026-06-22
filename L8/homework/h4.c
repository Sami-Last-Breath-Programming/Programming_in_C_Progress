// Least Common Multiple

#include <stdio.h>
#include <stdlib.h>

int gcd(int, int);
int lcm(int, int);

int main(void)
{   
    int lcmRes;
    int nums[2] = {0};
    
    // Header 
    printf("\n------------------------------\n");
    printf("Welcome To LCM Calculator !\n");
    printf("Example: 50, 40 \n");
    printf("------------------------------\n");
    
    // Input of two Positive numbers
    scanf("%i , %i", &nums[0], &nums[1]);

    // Check for invalid numbers
    if (!(nums[0] > 0 && nums[1] > 0))
    {
        printf("Error: Invalid Numbers !\n");
        exit(EXIT_FAILURE);
    }

    // Find the Least Common Multiple
    lcmRes = lcm(nums[0], nums[1]);

    // Print The LCM
    printf("LCM of %i and %i = %i\n", nums[0], nums[1], lcmRes);

    return EXIT_SUCCESS;
}

int gcd(int num1, int num2)
{
    int divisor, divident, reminder;
    
    if (num1 > num2)
    {
        divisor = num2;
        divident = num1;
    }
    else
    {
        divisor = num1;
        divident = num2;
    };

    while (divisor != 0)
    {
        reminder = divident % divisor;
        divident = divisor;
        divisor = reminder;
    };

    return divident;
}

int lcm(int num1, int num2)
{
    int lcm = 1;
    int gcdFactor;
    
    while (num1 != 1 && num2 != 1)
    {
        gcdFactor = gcd(num1, num2);
        
        if (gcdFactor != 1)
        {
            // Get the new nums
            num1 = num1 / gcdFactor;
            num2 = num2 / gcdFactor;
            
            // Without Array Method 
            lcm *= gcdFactor;  
        }
        else
            return lcm *= num1 * num2;
    }

    // Without Array Method
    lcm *= num1 * num2;
    return lcm;
}