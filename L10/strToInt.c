#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

// Declarations
int strToInt(const char *);

// Main Entry
int main(void)
{
    // Two Char Array
    char str1[] = "500";
    char str2[] = "400";

    // Result of Addition
    printf("The Result of %i + %i = %i\n",
        strToInt(str1),
        strToInt(str2),
        strToInt(str1) + strToInt(str2)
    );

    // Other Operations
    printf("Word in Num = %i\n", strToInt("-80"));
    printf("Word in Num = %i\n", strToInt("xxx"));
    
    return EXIT_SUCCESS;
}

int strToInt(const char *str)
{
    int final = 0, intval = 0, index = 0;
    bool isNegative = false;

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
        
    // Convert to Number logic
    for (; str[index] >= '0' && 
        str[index] <= '9'; index++
    )
    {
        // Extract the Integer
        intval = str[index] - '0';

        // Fix the Base 10
        final = (final * 10) + intval;
    }

    // Do Negative Math if flag
    if (isNegative)
    {
        final = -final;
        isNegative = false;
    }

    return final;
}
#pragma clang diagnostic pop
