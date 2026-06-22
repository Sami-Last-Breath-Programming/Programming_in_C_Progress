#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lookupLib.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#pragma clang diagnostic ignored "-Wvla"

int main(void)
{
    size_t entry;
    size_t entries;
    char inputBuff[20] = {0};

    // Data set
    Entry *dictionary[15] = 
    {
        newEntry(
            "Abacus", 
            "A manual computing device using sliding beads"
        ),
        newEntry(
            "Backbone", 
            "The series of vertebrae extending from the skull to the pelvis"
        ),
        newEntry(
            "Binary", 
            "A system of numerical notation to the base 2"
        ),
        newEntry(
            "Cache", 
            "A hardware or software component that stores data for future requests"
        ),
        newEntry(
            "Compiler", 
            "A program that translates computer code from one language to another"
        ),
        newEntry(
            "Data", 
            "Facts and statistics collected together for reference or analysis"
        ),
        newEntry(
            "Ethernet", 
            "A system for connecting a number of computer systems to form a LAN"
        ),
        newEntry(
            "Function", 
            "A relationship or expression involving one or more variables"
        ),
        newEntry(
            "Gateway", 
            "A device used to connect two different networks, especially a LAN to the internet"
        ),
        newEntry(
            "Hardware", 
            "The physical components of a computer system"
        ),
        newEntry(
            "Kernel", 
            "The central part of an operating system that manages operations"
        ),
        newEntry(
            "Linux", 
            "An open-source Unix-like operating system kernel"
        ),
        newEntry(
            "Network",
            "A group or system of interconnected people or things"
        ),
        newEntry(
            "Pointer", 
            "A variable that stores the memory address of another variable"
        ),
        newEntry(
            "Variable", 
            "An element, feature, or factor that is liable to vary or change"
        )
    };

    entries = 15;

    // Header 
    printf("---------------------------------------\n");
    printf("Welcome to Terminal Dictionary !\n");
    printf("---------------------------------------\n");

    // Take input from user 
    printf("Enter a Word: ");
    if (fgets(inputBuff, sizeof(inputBuff), stdin) != NULL)
    {
        size_t index;

        // Loop on the each char
        for (index = 0; inputBuff[index] != '\0'; index++)
        {
            // Strip if more then 16 Char
            if (index > MAX_ENTRY_WORD_LEN)
            { 
                printf("-> Striping word to %zu\n", MAX_ENTRY_WORD_LEN - 1);
                inputBuff[index - 2] = '\0';
                break;
            }

            // Remove the NewLine char
            if (inputBuff[index] == '\n')
                inputBuff[index] = '\0';

        }
    }
    else
    {
        printf("Error ! Word Can't Be Empty !\n");
        exit(EXIT_FAILURE);
    }

    // Check the word in dictionary
    // entry = lookup(inputBuff, dictionary, entries);
    entry = lookupBinarySearch(inputBuff, dictionary, entries);
    
    // Check the Results
    if (entry != 0)
    {
        printf("%s:\n: %s\n", 
            dictionary[entry - 1]->word,
            dictionary[entry - 1]->meaning
        );
    }
    else
    {
        printf("Sorry! The Word is not in Dictionary :(\n");
    }

    // End Header
    printf("---------------------------------------\n");

    // Clean Memory
    for (size_t index = 0; index < entries; index++)
    {
        free(dictionary[index]);
    }
    
    return EXIT_SUCCESS;
}
#pragma clang diagnostic pop
