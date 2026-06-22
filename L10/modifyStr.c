// Mutable Strings 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// String Class
typedef struct consStr
{
    const size_t len;
    char *text;

}consStr;

typedef struct mulStr
{
    size_t len;
    char text[];

}mulStr;

// Main Entry
int main(void)
{
    // String objs
    consStr name1 = 
    {
        .len = 4,
        .text = "moon",
    };
    mulStr *name2 = malloc(sizeof(mulStr) + 5);
    name2->len = 4;
    
    // Copy to String obj 
    strcpy(name2->text, "moon");

    // modify the value 
    // name1.text[0] = 'n'; Read only
    name2->text[0] = 'n';

    // Print both Strings
    printf("%s\n", name1.text);
    printf("%s\n", name2->text);

    // Free Memory
    free(name2);

    return EXIT_SUCCESS;
}
