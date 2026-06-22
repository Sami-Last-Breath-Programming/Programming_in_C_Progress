// Count words leave others

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define isAlpha(word) ((word >= 'a' && word <= 'z') || (word >= 'A' && word <= 'Z'))

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

//  Declarations
int countWords(char *);
bool isNum(char );
bool isSpecial(char );

// Main Entry
int main(void)
{
    // Words array
    char word1[] = "Well, here goes.";
    char word2[] = "And here we go ... again.";
    char word3[] = "Love my mom !! :)";
    char word4[] = "I'm Loving C !";
    char word5[] = "IMG 2 PDF = -1 !";
    char word6[] = "2025";
    char word7[] = "-2025";
    
    // Print output
    printf("The Words are %i\n", countWords(word1));
    printf("The Words are %i\n", countWords(word2));
    printf("The Words are %i\n", countWords(word3));
    printf("The Words are %i\n", countWords(word4));
    printf("The Words are %i\n", countWords(word5));
    printf("The Words are %i\n", countWords(word6));
    printf("The Words are %i\n", countWords(word7));

    return EXIT_SUCCESS;
}

int countWords(char *array)
{
    bool inWord = false;
    int words = 0;

    // Loop on the array
    for (size_t index = 0; array[index] != '\0'; index++)
    {    
        // Check the Words, Numbers and Slash
        if (   
            isAlpha(array[index])   || 
            isNum(array[index])     || 
            array[index] == '\''
        )
        {
            if (!inWord)
            {
                words++;
                inWord = true;
            }
        }
        
        // Check for Negative Number
        else if (array[index] == '-' && isNum(array[index + 1]))
        {
            if(!inWord)
            {
                words++;
                inWord = true;
            }
        }

        // Check for Comma and Period in Numbers
        else if ((array[index] == ',' || array[index] == '.') &&
            isNum(array[index - 1]) &&
            isNum(array[index + 1]) &&
            index > 0               
        )
        {
          
            inWord = true;
        }
        
        // Check for Special Characters
        else if ((array[index] >= '!' && array[index] <= '~'))
        {
            words++;
        }
        
        // Check for Minus '-' 
        else if(array[index] == '-' && !isNum(array[index + 1]))
        {
            if (!inWord)
            {
                words++;
                inWord = true;
            }
        }
        
        // If got a Space or anything else it's not a Word 
        else inWord = false;
    }

    // Return The count
    return  words;
}

bool isNum(char word)
{
    if (word >= '0' && word <= '9')
        return true;
    else
        return false;
}
#pragma clang diagnostic pop
