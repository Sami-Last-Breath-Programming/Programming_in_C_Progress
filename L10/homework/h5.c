#include <stdio.h>
#include <stdlib.h>

// Clang flags
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

// Erros
#define ERROR_STRING_EMPTY_NULL "Error: String is Empty or NULL pointer !\n"
#define ERROR_NO_EMPTY_SPACE "Error: Source String has no empty space or garbage !\n"

// Macros
#define STRING_EMPTY_NULL(str) (str == NULL || str[0] == '\n' || str[0] == '\0')

// Declarations
void insertString(char *, const char *, size_t, size_t);

// Main Entry
int main(void)
{
    // String
    char str1[50] = "The wrong son";
    char str2[50] = "world";
    char str3[50] = "Hello";
    char str4[50] = "I Love My Mom 2000";
    char str5[50] = "Yay";


    // Call insterString function
    insertString(str1, "per", 10, 50);
    insertString(str2, "Hello ", 0, 50);
    insertString(str3, "!", 5, 50);
    insertString(str4, "!", 100, 50);
    insertString(str5, "", 2, 50);

    // Print the string
    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("%s\n", str3);
    printf("%s\n", str4);
    printf("%s\n", str5);
    
    
    return EXIT_SUCCESS;
}

void insertString(char *source, const char *insert, size_t start, size_t source_size)
{
    size_t len = 0;
    size_t index = start;
    size_t insertLen = 0;
    size_t emptySpace = 0;
    
    // Handles Empty and Null ptr for source and NULL for insert
    if (STRING_EMPTY_NULL(source) || (insert == NULL || insert[0] == '\n'))
    {
        printf(ERROR_STRING_EMPTY_NULL);
        exit(EXIT_FAILURE);
    }

    // Handele Empty String for insert
    if (insert[0] == '\0')
        return;

    // Check the Empty space in source string
    for (size_t count = 0; count < source_size - 1; count++)
    {
        if (source[count] == '\0')
            emptySpace++;
    }
        
    // Get the size of insert array
    while (insert[insertLen] != '\0')
        insertLen++;

    // Handle not enought empty space for insertion
    if (emptySpace < insertLen)
    {
        printf(ERROR_NO_EMPTY_SPACE);
        exit(EXIT_FAILURE);
    }

    // Find the first empty space in source
    while (source[len] != '\0') len++;

    // Handle out of source insert
    if (start > len)
    {
        start = len;
        index = start;
    }

    // Loop backwards from start to index
    start = len + 1;
    while (start > index)
    {
        
        // Swap the character to insertLen
        source[start - 1 + insertLen] = source[start - 1];
        
        // decrease the start
        start--;
    }

    // Insert the string to new space
    for (size_t index2 = 0; index2 < insertLen; index2++)
        source[index + index2] = insert[index2];

}
#pragma clang diagnostic pop
