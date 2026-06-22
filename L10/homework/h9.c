// Smaller to Upper String Converter 

#include <stdio.h>
#include <stdlib.h>

// Clang Flags
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

// Errors
#define ERROR_STRING_NULL_EMPTY "Error: String is NULL or Empty !\n"

// Macros
#define STRING_NULL_EMPTY(str) (str == NULL || str[0] == '\0' || str[0] == '\n')
#define DIFFERENCE 32

// Declarations
void upperStr(char *);

// Main Entry
int main(void)
{
    // Test String
    char string[] = "Hello Guys !";

    // Uppercase the String
    upperStr(string);

    // Print the string
    printf("%s\n", string);

    return EXIT_SUCCESS;
}

void upperStr(char *str)
{
    // Check if the string is NULL or Empty 
    if (STRING_NULL_EMPTY(str))
    {
        printf(ERROR_STRING_NULL_EMPTY);
        exit(EXIT_FAILURE);
    }

    // Loop on the each character of the string
    for (size_t index = 0; str[index] != '\0'; index++)
    {
        // Handle Smaller Case Characters
        if (str[index] >= 'a' && str[index] <= 'z')
            str[index] -= DIFFERENCE;
    }
}
#pragma clang diagnostic pop
