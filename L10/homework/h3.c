// Find String in a String

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Clang flags
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#pragma clang diagnostic ignored "-Wdeclaration-after-statement"
#pragma clang diagnostic ignored "-Wvla"

// Errors
#define ERROR_STRING_EMPTY_NULL "Error: Given Strings Arguments are Empty or NULL pointer !\n"

// Macros
#define STRING_EMPTY_NULL(str) (str == NULL || str[0] == '\0' || str[0] == '\n')

// Declarations
int findString(const char *, const char *);

// Main Entry
int main(void)
{   
    int result1;
    int result2;
    int result3;
    
    // Constant String
    const char str1[] = "a chatterbox";
    const char str2[] = "ababa";

    // Find the String in str
    result1 = findString(str1, "hat");
    result2 = findString(str1, "hgr");
    result3 = findString(str2, "bab");

    // Print the result
    printf("The String is at index: %i\n", result1);
    printf("The String is at index: %i\n", result2);
    printf("The String is at index: %i\n", result3);
    
    return EXIT_SUCCESS;
}

int findString(const char *source, const char *find)
{
    size_t index;
    size_t index2;

    // Handle Source or Find string empty or NULL
    if (STRING_EMPTY_NULL(source) || STRING_EMPTY_NULL(find))
    {
        printf(ERROR_STRING_EMPTY_NULL);
        exit(EXIT_FAILURE);
    }

    // Loop on the find String
    for (index = 0; source[index] != '\0'; index++)
    {   
        // Check Loop set it to zero
        index2 = 0;

        // Lopp till All Chracters matchs
        while (
            
            find[index2] != '\0' && 
            source[index + index2] != '\0' &&
            find[index2] == source[index + index2]
        )
            index2++;

        // Check if last Loop was a match
        if (find[index2] == '\0')
            return (int)index;    
    }
    
    // If no match
    return -1;
}
#pragma clang diagnostic pop
