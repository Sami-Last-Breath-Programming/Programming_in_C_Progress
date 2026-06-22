#include <stdio.h>
#include <stdlib.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

// Declarations
void readLine(char []);

// Main Entry
int main(void)
{
    // Buffer for each line
    char lineBuff[256];

    // Header
    printf("Enter the Line to Print: ");

    // Read the Line and store in LineBuff
    readLine(lineBuff);

    // Print The LineBuff
    printf("%s\n", lineBuff);

    return EXIT_SUCCESS;
}

void readLine(char buff[])
{
    char temp;
    int index = 0;

    // Logic for char grep
    do
    {
        temp = (char) getchar();
        buff[index] = temp;
        index++;
    }
    while (temp != '\n');

    // Add Null Term at last
    buff[index - 1] = '\0';
}
#pragma clang diagnostic pop
