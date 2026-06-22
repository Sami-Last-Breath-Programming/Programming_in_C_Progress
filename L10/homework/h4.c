#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Clang Flags
#pragma clang diagnostic push 
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

// Errors
#define ERROR_STRING_EMPTY_NULL "Error: Source String is Empty or NULL !\n"
#define ERROR_STRING_MEMORY_ALLOCATE "Error: Can't Allocate Memory for tempString !\n" 
// Macros
#define STRING_EMPTY_NULL(str) (str == NULL || str[0] == '\n'|| str[0] == '\0')

// Declarations
char *removeString(char *, size_t, size_t);

// Main Entry
int main(void)
{
    char *result1;
    char *result2;
    char *result3;
    char *result4;
    char *result5;
    
    // Source String
    char str1[] = "The wrong son";
    char str2[] = "Hello";

    // Remove the String from Source String
    result1 = removeString(str1, 4, 6);
    result2 = removeString(str2, 2, 20);
    result3 = removeString(str2, 0, 2);
    result4 = removeString(str2, 4, 1);
    result5 = removeString(str2, 5, 1);

    // Print the String
    printf("%s\n", result1);
    printf("%s\n", result2);
    printf("%s\n", result3);
    printf("%s\n", result4);
    printf("%s\n", result5);
    
    // Free the String Memory
    free(result1);
    free(result2);
    free(result3);
    free(result4);
    free(result5);

    return EXIT_SUCCESS;
}
char *removeString(char *source, size_t start, size_t count)
{
    char *tempStr;
    size_t sourceLen = 0;
    size_t tempLen;
    
    // Handle Null or Empty Source String
    if (STRING_EMPTY_NULL(source))
    {
        printf(ERROR_STRING_EMPTY_NULL);
        exit(EXIT_FAILURE);
    }

    // Get the lenght of source string
    while (source[sourceLen] != '\0')
        sourceLen++;
    

    // Handle the Memory case
    if (sourceLen < count || sourceLen < start)
    {
        tempStr = malloc(sizeof(char) * 21);

        strcpy(tempStr, "You think i am fool\n");
        return tempStr;
    }
    
    // Memory Allocate for tempString
    tempLen = sourceLen - count;
    tempStr = malloc(sizeof(char) * tempLen + 1);

    // Handle Memory Allocation Error
    if (tempStr == NULL)
    {
        printf(ERROR_STRING_MEMORY_ALLOCATE);
        exit(EXIT_FAILURE);
    }

    // Loop on the Source string
    for (size_t index = 0, index2 = 0; index < sourceLen; index++)
    {
        // Check if index equal to start 
        if (index == start)
        {
            // Skip the next count - 1 indexs
            while (count > 0 && index < sourceLen)
            {
                index++;
                count--;
            }
        }
        // If not equal then add to tempString
        if (index2 < tempLen + 1)
        {
            tempStr[index2] = source[index];
            index2++;
        }
            
    }

    // Add the NULL character
    tempStr[tempLen] = '\0';

    // Return Temp pointer
    return tempStr;
}
#pragma clang diagnostic pop
