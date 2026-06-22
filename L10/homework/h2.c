#include <stdio.h>
#include <stdlib.h>

// Clang Flags
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

// Errors Macros
#define ERROR_EMPTY_NULL_STRING "Error: String Can't be Empty or Null pointer !\n"
#define ERROR_STRING_MALLOC "Error: Can't Allocate Memory For tempStr !\n"

// Macros for subString function
#define STRING_EMPTY(str) (str == NULL || str[0] == '\n' || str[0] == '\0')

// Declarations
char *subString(char *, size_t, size_t);

// Main Entry
int main(void)
{
    char *result;

    // String array
    char str1[] = "Character";
    char str2[] = "two words";

    // Get subString for str1
    result = subString(str1, 4, 3);
    
    // Print the array
    printf("Orginal: %s\nNew: %s\n", str1, result);

    // Free the str1 subString pointer
    free(result);

    // Get subString for str2
    result = subString(str2, 4, 20);

    // Print the array
    printf("Orginal: %s\nNew: %s\n", str2, result);

    // Free the str2 subString pointer
    free(result);

    return EXIT_SUCCESS;
}

char *subString(char *source, size_t start, size_t count)
{
    size_t index;
    size_t till;
    size_t indexTmp;
    char *tempStr;
    
    // Handle Empty String or Pointer
    if (STRING_EMPTY(source))
    {
        printf(ERROR_EMPTY_NULL_STRING);
        exit(EXIT_FAILURE);
    }

    // Allocate the bytes for subString
    tempStr = malloc(sizeof(char) * (count + 1));

    // Handle Allocation Errors
    if (tempStr == NULL)
    {
        printf(ERROR_STRING_MALLOC);
        exit(EXIT_FAILURE);
    }

    // Extract the String
    for (index = start, indexTmp = 0, till = count;
        till > 0 && source[index] != '\0'; 
        index++, indexTmp++, till--)
    {
        // Just store the character
        tempStr[indexTmp] = source[index];
    }

    // Add NULL Character last filled 
    tempStr[indexTmp] = '\0';

    // Return the pointer
    return tempStr;
}
#pragma clang diagnostic pop
