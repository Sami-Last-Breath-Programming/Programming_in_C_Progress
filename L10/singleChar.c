#include <stdio.h>
#include <stdlib.h>

// Main Entry
int main(void)
{
    int word;

    // Header
    printf("Enter the one Word: ");

    // Grep the word from stdin buffer
    word = getchar();

    // Print the word
    printf("%c\n", word);

    return EXIT_SUCCESS;
}
