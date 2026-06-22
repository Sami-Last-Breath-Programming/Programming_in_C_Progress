// String to float

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

// Limits
#define LIMIT 1000000000000000000000.0


// Declarations
double strToFloat(const char *);

// Main Entry
int main(void)
{
    // Two Char Array
    char str1[] = "-867.6921";
    char str2[] = "20.5";

    // Result of Addition
    printf("The Result of %lf + %lf = %lf\n",
        strToFloat(str1),
        strToFloat(str2),
        strToFloat(str1) + strToFloat(str2)
    );

    // Other Operations
    printf("Word in Num = %f\n", strToFloat("-1.6"));
    printf("Word in Num = %f\n", strToFloat("xxx"));
    
    return EXIT_SUCCESS;
}

double strToFloat(const char *str)
{
    size_t index = 0;
    
    double front = 0.0;
    double back = 0.0;
    double backIndex = 1.0;
    double *swap[] = {&front, &back};
    double *tmp;

    double final = 0.0, floatVal = 0.0;
    bool isNegative = false;
    bool isDot = false;

    // Check for Negative
    if (str[0] == '-')
    {
        index++;
        isNegative = true;
    }

    // Check if the Given String is a Number
    if (!(str[index] >= '0' && str[index] <= '9'))
    {
        printf("Warning: Not A Digit !\n");
        return final;
    }

    // Get the size of the after pointers decimals
    for (size_t count = 0; str[count] != '\0'; count++)
    {   
        if (backIndex >= LIMIT) break;
        if (isDot) backIndex *= 10;
        if (str[count] == '.') isDot = true;
    }
        
    // Convert to Number logic
    for (;  (str[index] >= '0' && 
            str[index] <= '9') ||
            str[index] == '.';index++
    )
    {
        // Check for decimal 
        if (str[index] == '.')
        {
            tmp = swap[0];
            swap[0] = swap[1];
            swap[1] = tmp;
            continue;
        }
        
        // Extract the Number
        floatVal = (double) str[index] - '0';

        // Fix the Base 10
        *swap[0] = (*swap[0] * 10) + floatVal;
    }

    // Get the whole number
    final = *swap[1] + (*swap[0] / backIndex);
    
    // Do Negative Math if flag
    if (isNegative)
    {
        final = -final;
        isNegative = false;
    }

    return final;
}
#pragma clang diagnostic pop
