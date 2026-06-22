// Program to Concatenate Two Strings 

#include <stdio.h>
#include <stdlib.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

// String Class
typedef struct String
{
    size_t len;
    char *text;

}String;

// Declarations
String concat(const String *, const String *);
void printName(const String *);

// Main Entry
int main(void)
{
    // Strings Objs
    const String name1 = {
        .text = "Abdul ",
        .len = 7,
    };

    const String name2 = {
        .text = "Sami",
        .len = 5,
    };

    // Concat Both Names
    String joinedName = concat(&name1, &name2);

    // Print Name
    printName(&joinedName);

    //Free Memory
    free(joinedName.text);

    return EXIT_SUCCESS;
}

String concat(const String *s1, const String *s2)
{
    size_t tempTrack = 0;
    String temp = {
        .len = (s1->len + s2->len) - 1,
    };

    // Allocate Memory
    char *tempMem =  malloc(temp.len * 1);
    if (tempMem != NULL) temp.text = tempMem;
    else
    {
        printf("Error: Can't Allocate Memory !\n");
        exit(EXIT_FAILURE);
    }

    // Loop on String 1 
    for (size_t index = 0; index < s1->len - 1; index++)
    {
        // Store char of str 1 in temp
        temp.text[tempTrack] = s1->text[index];
        tempTrack++;

    }

    // Loop on String 2
    for (size_t index = 0; index < s2->len - 1; index++)
    {
        // Store char of str 1 in temp
        temp.text[tempTrack] = s2->text[index];
        tempTrack++;

    }
    
    // Add Null Term at last
    temp.text[temp.len - 1] = '\0';
    
    return temp; 
}

void printName(const String *str)
{
    for (size_t index = 0; index < str->len; index++)
    {
        printf("%c", str->text[index]);
    }
    printf("\n");
}
#pragma clang diagnostic pop
