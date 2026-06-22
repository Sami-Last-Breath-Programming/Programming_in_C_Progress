// Reads The Lines and Print them

#include <stdio.h>
#include <stdlib.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wvla"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

// Declarations
char **getLines(size_t);
void readLines(char **, size_t);

// Main Entry
int main(void)
{
    // Gets Lines Input from the User
    char **result = getLines(3);

    // Read and Print Lines
    readLines(result, 3);

    return EXIT_SUCCESS;
}

char **getLines(size_t lines)
{
    size_t line = 0;

    // Array to store lines buffer
    char **array = malloc(sizeof(char *) * lines);

    // Take Input
    while (line < lines)
    {
        int index = 0;
        char ch;

        // Buffer for each lines
        char *buff = malloc(256);

        // Header
        printf("Enter The %zu: ", line + 1);
        do
        {
            ch = (char) getchar();
            buff[index] = ch;
            index++;
        }
        while (ch != '\n');

        // Store the line addr in array
        array[line] = buff;

        // Increase line
        line++;
    }
    printf("\n");
    return array;
}

void readLines(char **array, size_t lines)
{
    // Reads throught Each Line
    for (size_t line = 0; line < lines; line++)
    {
        int index = 0;

        // Read each char of a line
        while (array[line][index] != '\n')
        {
            printf("%c", array[line][index]);
            index++;
        }
        printf("\n");
    }

    // Free Memory
    for (size_t line = 0; line < lines; line++)
    {
        free(array[line]);
    }
    free(array);
}
#pragma clang diagnostic pop
