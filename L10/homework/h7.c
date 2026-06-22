#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "h6/stringLib.h"

// Clang flags
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#pragma clang diagnostic ignored "-Wpadded"

// Errors
#define ERROR_PTR_NULL "Error: Can't Allocate memory Null ptr !\n"

// Declarations

typedef struct replaceFlag
{
    char *string;
    bool isTrue;

} replaceFlag;

void replaceString(char *, const char *, const char *, size_t, replaceFlag *);

// Main Entry
int main(void)
{    
    char *string;
    char *oldString;
    replaceFlag flag;
    
    // First run
    flag.isTrue = false;
    
    // Demo String
    string = malloc(sizeof(char) * 50);

    // Quick Handle Error
    if (string == NULL) exit(EXIT_FAILURE);

    // Copy the String literal to the pointer
    strcpy(string, "Hello Hi is Nice To Meet You");

    // Remove Spaces from the String
    do 
    {
        oldString = string;
        
        replaceString(string, " ", "", 1, &flag);
        
        if (flag.isTrue)
        {
            string = flag.string;
            free(oldString);
        }
    }
    while(flag.isTrue);

    // Print the string;
    printf("%s\n", string);

    // Free the pointer
    free(string);

    return EXIT_SUCCESS;
}
void replaceString(char *source, const char *str1, const char *str2, 
    size_t count, replaceFlag *flag
)
{   
    size_t tempStrlen = 0;
    size_t str2Len = 0;
    size_t index;
    
    int tempFindIndex;
    char *tempStr;
    char *temp;
    bool isFind;
    
    // Find the str1 in source 
    tempFindIndex = findString(source, str1);
    
    // Handle find string errors
    if (tempFindIndex == -1)
    {   
        isFind = 0;
        flag->isTrue = isFind;
        return; 
    }
    else
    {
        index = (size_t)tempFindIndex;
        isFind = 1;
    }

    // Remove string on that index
    tempStr = removeString(source, index, count);

    // Get the length of the tempStr
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
    insertString(tempStr, str2, index, tempStrlen + str2Len);

    // Modify the flags
    flag->isTrue = isFind;
    flag->string = tempStr;
}
#pragma clang diagnostic pop
