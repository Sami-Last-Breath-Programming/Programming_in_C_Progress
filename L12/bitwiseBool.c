// A Program that usues bitwise operators for flags in integer

#include <stdio.h>
#include <stdlib.h>

// Clang Erros
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgnu-binary-literal"
#pragma clang diagnostic ignored "-Wunused-macros"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"


// Error Macros
#define ERROR_MALLOC "Error: Can't Allocate Dynamic Memory\n"

// Macros
#define ONE_BYTE_SIZE 8
#define MAX_DIGITS 4
#define NULL_BYTE 1
#define isA 0b1
#define isB 0b10
#define isC 0b100
#define isD 0b1000

// Main Entry
int main(void)
{
    // Variables
    size_t bits = 0;
    size_t termiBits = 0;
    
    int sfResult = 0, tmpChar;
    int byteArry[8] = {0};
    unsigned int flags = 0b0;
    char *digits = NULL, *tmp = NULL;

    // Default Message
    printf("Welcome To Flags Bitwise Example:\n");

    // Allocate Memory for digits
    digits = malloc(sizeof(char) * MAX_DIGITS + NULL_BYTE);

    // Handle Allocation Errors
    if (digits == NULL)
    {
        printf(ERROR_MALLOC);
        exit(EXIT_FAILURE);
    }

    // Set Last Byte Null String
    digits[MAX_DIGITS] = '\0';
    
    // Main Loop
    for (int loop = 0; loop < MAX_DIGITS; loop++)
    {
        printf("Enter the Digit: ");
        sfResult = scanf(" %c", &digits[loop]);

        // Handle Scanf Errors
        if (sfResult <= 0)
        {
            while((tmpChar = getchar()) != '\n' && tmpChar != EOF);
        }
    }

    // Check the digits
    tmp = digits;
    while (*tmp != '\0')
    {
        // Check for match
        switch (*tmp)
        {
            case 'A':
                flags |= isA;
                break;

            case 'B':
                flags |= isB;    
                break;

            case 'C':
                flags |= isC;    
                break;

            case 'D':
                flags |= isD;
                break;
            
            default:
                break;
        }
        
        // Increase the pointer
        tmp +=1;
    }

    // Find the bites
    bits = sizeof(unsigned int) * ONE_BYTE_SIZE;
    termiBits = bits - ONE_BYTE_SIZE;

    // Print the flags Value
    for (int index = 0; bits >= termiBits && index < ONE_BYTE_SIZE; bits--, index++)
    {
        // Store the last bit
        byteArry[index] = (flags & 0b1);

        // pop the last bit with right shift
        flags >>= 0b1;
    }

    // Print Reversed Array
    for (int index = ONE_BYTE_SIZE; index > 0; index--)
    {
        printf("%i ", byteArry[index - 1]);
    }
    printf("\n");

    // Free Memory
    free(digits);

    return EXIT_SUCCESS;
}
#pragma clang diagnostic pop
