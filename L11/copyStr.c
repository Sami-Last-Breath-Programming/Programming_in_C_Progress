// Copy a string using pointers 

#include <stdio.h>
#include <stdlib.h>

// Clang Flag
#pragma clang diagnostic push 
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

// Declarations 
void copyString (char *, const char *);

// Main Entry 
int main(void)
{
    // Strings 
    char *newString;

    // Allocate memory for newString
    newString = malloc(15);

    // Handle Allocations Errors 
    if (newString == NULL) exit(EXIT_FAILURE);

    // Copy the constant string to new string
    copyString(newString, "Hello String !");

    // Print the new string 
    printf("New String: %s\n", newString);

    // Free new string 
    free(newString);
    
    return EXIT_SUCCESS;
}
void copyString (char *newStr, const char *constStr)
{
    // Loop untill null string
    while (*constStr)
    {
        *newStr++ = *constStr++;
    }

    // Add the null string
    *newStr = '\0';
}
#pragma clang diagnostic pop
