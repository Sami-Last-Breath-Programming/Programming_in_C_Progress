// Program to Find even Number in Unsigned interger using Bitwise And

#include <stdio.h>
#include <stdlib.h>

// Clang Flags
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

// Errors Macros
#define ERROR_ARGS "Error: Arguments Empty or more than one\n"

// Main Entry
int main(int argc, char **argv)
{
    unsigned int num;
    const unsigned int check = 001;
    
    // Handle No Args
    if (argc < 2 || argc > 2)
    {
        printf(ERROR_ARGS);
        exit(EXIT_FAILURE);
    }

    // Get the Number
    num = (unsigned) atoi(argv[argc - 1]);

    // Check if it even or odd
    if ((num & check) == 0) 
        printf("Number is Even !\n");
    else 
        printf("Number is Odd !\n");
    
    return EXIT_SUCCESS;
}
#pragma clang diagnostic pop
