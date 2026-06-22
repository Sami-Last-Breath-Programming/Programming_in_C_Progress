#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringLib.h"

// Clang flags
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

// Functions
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

char *removeString(char *source, size_t start, size_t count)
{
    char *tempStr;
    size_t len = 0;
    size_t tempLen;
    
    // Handle Null or Empty Source String
    if (STRING_EMPTY_NULL(source))
    {
        printf(ERROR_STRING_EMPTY_NULL);
        exit(EXIT_FAILURE);
    }

    // Get the lenght of source string
    while (source[len] != '\0')
        len++;
    

    // Handle the Memory case
    if (len < count || len < start)
    {
        tempStr = malloc(sizeof(char) * 21);

        strcpy(tempStr, "You think i am fool\n");
        return tempStr;
    }
    
    // Memory Allocate for tempString
    tempLen = len - count;
    tempStr = malloc(sizeof(char) * tempLen + 1);

    // Handle Memory Allocation Error
    if (tempStr == NULL)
    {
        printf(ERROR_STRING_MEMORY_ALLOCATE);
        exit(EXIT_FAILURE);
    }

    // Loop on the Source string
    for (size_t index = 0, index2 = 0; index < len; index++)
    {
        // Check if index equal to start 
        if (index == start)
        {
            // Skip the next count - 1 indexs
            while (count > 0 && index < len)
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

void insertString(char *source, const char *insert, size_t start, size_t source_size)
{
    size_t len = 0;
    size_t index = start;
    size_t insertLen = 0;
    size_t emptySpace = 0;
    
    // Handles Empty and Null ptr for source and NULL for insert
    if (STRING_EMPTY_NULL(source) || (insert == NULL || insert[0] == '\n'))
    {
        printf(ERROR_STRING_EMPTY_NULL);
        exit(EXIT_FAILURE);
    }

    // Handele Empty String for insert
    if (insert[0] == '\0')
        return;

    // Check the Empty space in source string
    for (size_t count = 0; count < source_size - 1; count++)
    {
        if (source[count] == '\0')
            emptySpace++;
    }
        
    // Get the size of insert array
    while (insert[insertLen] != '\0')
        insertLen++;

    // Handle not enought empty space for insertion
    if (emptySpace < insertLen)
    {
        printf(ERROR_NO_EMPTY_SPACE);
        exit(EXIT_FAILURE);
    }

    // Find the first empty space in source
    while (source[len] != '\0') len++;

    // Handle out of source insert
    if (start > len)
    {
        start = len;
        index = start;
    }

    // Loop backwards from start to index
    start = len + 1;
    while (start > index)
    {
        
        // Swap the character to insertLen
        source[start - 1 + insertLen] = source[start - 1];
        
        // decrease the start
        start--;
    }

    // Insert the string to new space
    for (size_t index2 = 0; index2 < insertLen; index2++)
        source[index + index2] = insert[index2];
}

#pragma clang diagnostic pop
