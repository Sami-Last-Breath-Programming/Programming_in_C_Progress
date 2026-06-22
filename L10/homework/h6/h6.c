// Replace String 
#include <stdio.h>
#include <stdlib.h>
#include "stringLib.h"

// Clang flags
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

// Errors
#define ERROR_PTR_NULL "Error: Can't Allocate memory Null ptr !\n"
#define ERROR_NO_MATCH_FOUND "Error: No match for given string found !\n"

// Decelarations
char *replaceString(char *, const char *, const char *, size_t);

// Main Entry
int main(void)
{ 
    char *result;
    char string[50] = "This is the end !";

    // Replace the string
    result = replaceString(string, "end", "start", 3);

    // Print the String
    printf("%s\n", result);

    // Free memory
    free(result);
    
    return EXIT_SUCCESS;
}

char *replaceString(char *source, const char *str1, const char *str2, 
    size_t count
)
{   
    size_t tempStrlen = 0;
    size_t str2Len = 0;
    size_t index;
    int tempFindIndex;
    char *tempStr;
    char *temp;
    
    // Find the str1 in source 
    tempFindIndex = findString(source, str1);

    // Handle find string errors
    if (tempFindIndex == -1)
    {
        printf(ERROR_NO_MATCH_FOUND);
        exit(EXIT_FAILURE);
    }
    else
        index = (size_t)tempFindIndex;

    // Remove string on that index
    tempStr = removeString(source, index, count);

    // Get the length of the tempString 
    while (tempStr[tempStrlen] != '\0')
        tempStrlen++;

    // Get the length of the str2 
    while (str2[str2Len] != '\0')
        str2Len++;

    // Reallocate the string 
    temp = realloc(tempStr, sizeof(char) * (tempStrlen + str2Len + 1));

    if (temp == NULL)
    {
        printf(ERROR_PTR_NULL);
        exit(EXIT_FAILURE);
    }

    tempStr = temp;
    
    //  Replace the String
    insertString(tempStr, str2, index, tempStrlen + str2Len + 1);

    return tempStr;
}
#pragma clang diagnostic pop
