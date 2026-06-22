// Count words leave others

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define isAlpha(c) ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

//  Declarations
int countWords(char *);

// Main Entry
int main(void)
{
    // Words array
    char word1[] = "Well, here goes.";
    char word2[] = "And here we go... again.";
    char word3[] = "Love my mom !! :)";
    char word4[] = "I'M Loving C !";

    // Print output
    printf("The Words are %i\n", countWords(word1));
    printf("The Words are %i\n", countWords(word2));
    printf("The Words are %i\n", countWords(word3));

    return EXIT_SUCCESS;
}

int countWords(char *array)
{
    bool isLastWord = true;
    int words = 0;

    // Loop on the array
    for (size_t index = 0; array[index] != '\0'; index++)
    {
        // Check the word
        if (isAlpha(array[index]))
        {
            if (isLastWord)
            {
                words++;
                isLastWord = false;
            }
        }
        else isLastWord = true;
    }

    // Return The count
    return  words;
}
#pragma clang diagnostic pop
