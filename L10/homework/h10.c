// Int to Str

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Clang Flags 
#pragma clang diagnostic push 
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

// Errors
#define ERROR_ALLOCATION_ARRAY "Error: Can't allocate memory for array !\n"

// Macros
#define LEN(x) (x - 1)
#define DIFFERENCE 48
#define popNum(num) (num /= 10)
#define getNum(num) (num % 10)

// Declarations
char *intToStr(int, size_t);

// Main Entry 
int main(void)
{
    // Pointer for str
    char *str1;
    char *str2;
    char *str3;

    // The value
    int val1 = 56;
    int val2 = -56;
    int val3 = -100;
    
    // Convert to string 
    str1 = intToStr(val1, 2);
    str2 = intToStr(val2, 2);
    str3 = intToStr(val3, 3);

    // Print the string 
    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("%s\n", str3);

    // Free memory 
    free(str1);
    free(str2);
    free(str3);
   
    return EXIT_SUCCESS;
}

char *intToStr(int num, size_t digits)
{
    char *array;
    bool isNeg;
    size_t arrayLen;

    // On Start
    arrayLen = 0;
    isNeg = false;

    // Check if number is negative
    if (num < 0)
    {
        isNeg = true;
        num = -num;
    }
    
    // Length of the array
    arrayLen = (isNeg) ? LEN(digits + 2) : LEN(digits + 1);
    
    // Allocate Memory for array
    array = malloc(sizeof(char) * arrayLen + 1);

    // Hanlde Memory Error
    if (array != NULL) array[arrayLen] = '\0';
    else
    {
        printf(ERROR_ALLOCATION_ARRAY);
        exit(EXIT_FAILURE);
    }

    // Convert the numbers
    for (size_t index = arrayLen; index > 0; index--)
    {
        // Handle Negative
        if (isNeg && (index - 1) == 0)
        {
            array[index - 1] = '-';
            break;
        }
        
        // Extract, Convert and store in array
        array[index - 1] = (getNum(num) + DIFFERENCE);

        // Pop last num 
        popNum(num);
    }

    // Return Array pointer
    return array;
}
