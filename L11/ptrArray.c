#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Clang Flags
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wvla"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#pragma clang diagnostic ignored "-Wgnu-folding-constant"
#pragma clang diagnostic ignored "-Wnewline-eof"

// Declarations
void clearScr(unsigned int);

// Main Entry
int main(void)
{
    char *ptrStr;
    size_t input;
    
    // Constant
    const size_t size = 20;

    // Array of Characters
    char name[size] = "Sami";
    
    // Print the array
    for (size_t index = 0; index < size; index++)
    {
        // Print the Characters
        printf("| %c |\n", 
            (name[index] == '\0') ? '0': name[index]
        );
    }

    // Clear screen
    clearScr(2);

    // Pointer of the array
    ptrStr = name;

    // Print the Value 
    printf("ptrStr: %c, name: %c\n", *ptrStr, *name);

    // Clear screen
    clearScr(2);

    // Print untill reach NULL String
    while (*ptrStr != '\0')
    {
        printf("%c", *ptrStr);
        ptrStr++;
    }
    
    // Add NewLine
    printf("\n");

    // Clear screen
    clearScr(2);

    // Match the Index
    printf("Enter The index: ");
    input = (size_t)getchar();

    // Convert to integer
    input -= '0';

    // Loop on the name 
    ptrStr = name;
    while (*ptrStr != '\0')
    {
        if (*ptrStr == *(name + (input - 1)))
        {
            printf("Yes, %c at %zu\n", 
                *(name + (input - 1)), input
            );
            break;
        }

        ptrStr++;
    }

    return EXIT_SUCCESS;
}

void clearScr(unsigned int sec)
{
    sleep(sec);
    system("clear");
}

#pragma clang diagnostic pop
