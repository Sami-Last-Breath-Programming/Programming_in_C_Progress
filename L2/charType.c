#include <stdio.h>

// return 0 to system
#define EXIT_SUCCESS 0

int main(void)
{   
    // In vertical
    char word1 = 'A';
    char word2 = 'b';
    char word3 = 'd';
    char word4 = 'u';
    char word5 = 'l';
    char space = ' ';
    char word6 = 'S';
    char word7 = 'a';
    char word8 = 'm';
    char word9 = 'i';

    
    char *words[10] = {
        &word1, &word2, &word3, &word4,
        &word5, &space, &word6, &word7, 
        &word8, &word9 
    };
    

    for (int i = 0; i < 10; i++)
    {
        printf("%c", *words[i]);
    }
    printf("\n");
    
    
    return EXIT_SUCCESS;
}