#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lookupLib.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

#define BOTH_STRING_CHAR_SAME(index) str1[index] == str2[index]
#define BOTH_STRING_NOT_NULL(index) str1[index] != '\0' && str2[index] != '\0'
#define BOTH_STRING_NULL(index) str1[index] == '\0' && str2[index] == '\0'


// Define Externals
const size_t MAX_ENTRY_WORD_LEN = 16;
const size_t MAX_ENTRY_MEANING_LEN = 81;


Entry *newEntry(const char *word, const char *meaning)
{
    Entry *newEntry;
    
    // Check for Empty Word Meaning
    if (
        word[0] == ' ' || 
        meaning[0] == ' ' ||
        word[0] == '\n' || 
        meaning[0] == '\n' 
    )
    {
        printf(ENTRY_EMPTY);
        exit(EXIT_FAILURE);
    }

    // Memory Allocation for the Entry Struct
    newEntry = malloc(sizeof(Entry));

    // Check for Allocation
    if (newEntry != NULL)
    {
        // Copy the word to Entry struct
        for (size_t index = 0; word[index] != '\0'; index++)
        {
            // Check for Overflow
            if (index > MAX_ENTRY_WORD_LEN)
            {
                printf(ENTRY_WORD_OVERFLOW, MAX_ENTRY_WORD_LEN - 1);
                exit(EXIT_FAILURE);
            }
            
            newEntry->word[index] = word[index];
        }
        // Add the NULL at last 
        newEntry->word[MAX_ENTRY_WORD_LEN - 1] = '\0';

        // Copy the meaning to Entry struct
        for (size_t index = 0; meaning[index] != '\0'; index++)
        {
             // Check for Overflow
            if (index > MAX_ENTRY_MEANING_LEN)
            {
                printf(ENTRY_MEANING_OVERFLOW, MAX_ENTRY_MEANING_LEN - 1);
                exit(EXIT_FAILURE);
            }
            
            newEntry->meaning[index] = meaning[index];
        }
        // Add the NULL at last 
        newEntry->meaning[MAX_ENTRY_MEANING_LEN - 1] = '\0';

        // Return the Entry pointer
        return newEntry;
    }
    else
    {
        printf(ENTRY_ALLOCATION);
        exit(EXIT_FAILURE);
    }

}

size_t lookup(const char *word,  Entry **dic, size_t entries)
{
    // Check the word in dictionary 
    for (size_t index = 0; index < entries; index++)
    {   
        if(isStringEqual(word, dic[index]->word) == 0)
        return index + 1;
    }
    return 0;
}

size_t lookupBinarySearch(const char *word, Entry **dic, size_t entries)
{
    int Low = 0, Mid, result;
    int High = (int)entries - 1;

    // Loop untill Low is more than High
    while (Low <= High)
    {
        // Get the Medium of the dictionary
        Mid = Low + (High - Low) / 2;

        // Check the Strings 
        result = compareString(word, dic[Mid]->word);

        // Check the result 
        if (result == SMALL)
            High = Mid - 1;
        else if (result == GRATER)
           Low = Mid + 1;
        else
            return (size_t)Mid + 1;
    }

    // If not in dictionary
    return 0;
}

bool isStringEqual(const char *str1, char *str2)
{
    int index = 0;
    bool equal = false;
    
    while (BOTH_STRING_CHAR_SAME(index) && BOTH_STRING_NOT_NULL(index))
    {
        // Increase the index
        index++;

        // Check for End
        if (BOTH_STRING_NULL(index))
            equal = true;
        else
            equal = false;
    }
    return equal;
}

int compareString(const char *str1, char *str2)
{
    int index = 0;

    while (BOTH_STRING_CHAR_SAME(index) && BOTH_STRING_NOT_NULL(index))
    {
        // Increase the index
        index++;
    }
    
    // Check for Similar
    if (str1[index] < str2[index])
        return SMALL;
    else if (str1[index] > str2[index])
        return GRATER;
    else
        return EQUAL;
}
#pragma clang diagnostic pop
