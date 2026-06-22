#include <stdio.h>
#include <stdlib.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

// Main Entry
int main(void)
{   
    char upper[] = {
        
        'A', 'B', 'C', 'D', 'E', 'F', 'G',
        'H', 'I', 'J', 'K', 'L', 'M', 'N',
        'O', 'P', 'Q', 'R', 'S', 'T', 'U',
        'V', 'W', 'X', 'Y', 'Z', '\0'
    };

    char lower[] = {
        
        'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't', 'u', 
        'v', 'w', 'x', 'y', 'z', '\0'
    };

    char stringNum[] = {
        
        '0', '1', '2', '3', '4', 
        '5', '6', '7', '8', '9',
        '*', ',', '\'', '\0'
    };


    // Print The Characters and its Integer value
    // Upper Case
    printf("\n----- Capital: A to Z -----\n");
    
    for (size_t index = 0; upper[index] != '\0'; index++)
    {
        printf("%2zu | %c : %3i | \n", 
            index + 1, 
            upper[index],
            upper[index]
        );
    }
    
    // Lower Case
    printf("\n------ Lower: a to z ------\n");

    for (size_t index = 0; lower[index] != '\0'; index++)
    {
        printf("%2zu | %c : %3i | \n", 
            index + 1, 
            lower[index],
            lower[index]
        );
    }

    // String Numbers
    printf("\n------ String Numbers ------\n");
    
    for (size_t index = 0; stringNum[index] != '\0'; index++)
    {    
        printf("| %zu: %i | \n", 
            index, 
            stringNum[index]
        );
    }

    return EXIT_SUCCESS;
}
#pragma clang diagnostic pop
