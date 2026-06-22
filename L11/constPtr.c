// Constant with pointers

#include <stdio.h>
#include <stdlib.h>

// Main Entry
int main(void)
{   
    // Character Variable 
    char symbole = '^';

    // Pointer to character constant ptr point
    char * const ptr = &symbole; 

    // Changing the pointer will cause error
    // ptr = (char *)0;

    // Pointer to character constant ptr and value
    const char * const ptr2 = &symbole;
    
    // Change and Print the value of pointers
    printf("%c\n", (*ptr = 'A'));

    // Changing and printing will cause error
    // printf("%c\n", (*ptr2 = 'B'));
    symbole = 'B';
    printf("%c\n", *ptr2);

    return EXIT_SUCCESS;
}
