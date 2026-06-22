// Get length of strings using ptr operations

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// Clang Flags
#pragma clang diagnostic push 
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

// Macros
#define MESSAGE1 "Hello MOM !"
#define MESSAGE2 ""
#define MESSAGE3 "NoSpace"

// Declarations
ptrdiff_t getLength(const char *);

// Main Entry 
int main(void)
{
    // Print then Lenght of the Strings 
    printf("The Lenght of %s is %ld\n", 
        MESSAGE1, getLength(MESSAGE1)
    );
    printf("The Lenght of %s is %ld\n", 
        MESSAGE2, getLength(MESSAGE2)
    );
    printf("The Lenght of %s is %ld\n", 
        MESSAGE3, getLength(MESSAGE3)
    );
    
    return EXIT_SUCCESS;
}

ptrdiff_t getLength(const char *constStr)
{
    // Ptr for the end of string
    const char *endStr = constStr;
    
    // Loop till the end character
    while (*endStr) endStr++;

    // Return the length
    return endStr - constStr;
}
#pragma clang diagnostic pop
