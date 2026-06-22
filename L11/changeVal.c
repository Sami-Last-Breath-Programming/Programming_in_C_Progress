#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Declarations 
    char character;
    char *ptr_char;

    // Init
    character = 'A';
    ptr_char = &character;
    // Change the value of character
    *ptr_char = 'S';

    // Print the Value of Character
    printf("Character: %c | PTR_CHAR: %c\n", character, *ptr_char);

    // Print the Address of Character Variable
    printf("PTR_CHAR: %p\n", (void *)ptr_char);

    return EXIT_SUCCESS;
}
