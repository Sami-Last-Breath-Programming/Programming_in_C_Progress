#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Macros
#define isAlpha(c) ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))

// Clang fix
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

// Declarations
char *readLine(void);
int countWords(char *);

// Main Entry
int main(void)
{
    int words = 0;
    char *line;
    bool isReturn = false;

    // Header
    printf("Welcome to Lines Word Reader !\n");
    printf("When done press RETURN Key\n\n");

    // Check Return flag
    while (!isReturn)
    {
        // Read each Line
        line = readLine();

        // Check for Null String
        if (line[0] == '\0')
        {
            isReturn = true;
            free(line);
        }
        else
        {
            words +=countWords(line);
            free(line);
        }
    }

    // Count and print words
    printf("The Total Words are: %i\n", words);

    return EXIT_SUCCESS;
}

char *readLine(void)
{
    int index = 0;
    char ch;
    char *buff = malloc(256);

    // Loop untill not new line
    do
    {
        ch = (char) getchar();
        buff[index] = ch;
        index++;
    }
    while(ch != '\n');

    // Add the Null at last
    buff[index - 1] = '\0';

    // return the line pointer
    return buff;
}

int countWords(char *line)
{
    bool isLastWord = true;
    int words = 0;

    // Loop on the line
    for (size_t index = 0; line[index] != '\0'; index++)
    {
        // Check the word
        if (isAlpha(line[index]))
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
