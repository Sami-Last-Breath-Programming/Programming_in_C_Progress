#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#define stringNotEnd(i) str1->text[i] != '\0' && str2->text[i] != '\0'
#define stringEnd(i) str1->text[i] == '\0' && str2->text[i] == '\0'
#define END 1

// String Class
typedef struct str
{
    size_t len;
    char text[]; 

}str;

//Declaraions
str *initStr(char *);
size_t getLenght(char *);
bool isEqual(str *, str *);

// Main Entry
int main(void)
{
    // String Objs
    str *str1;
    str *str2;
    str *str3;
    str *str4;

    // Init Strings
    str1 = initStr("Mango");
    str2 = initStr("Cut");
    str3 = initStr("Mango");
    str4 = initStr("Man");

    // Check Equality of String 1 and String 2
    if (isEqual(str1, str2)) printf("Yes!\n");
    else printf("No!\n");

    // Check Equality of String 1 and String 3
    if (isEqual(str1, str3)) printf("Yes!\n");
    else printf("No!\n");

     // Check Equality of String 1 and String 4
    if (isEqual(str1, str4)) printf("Yes!\n");
    else printf("No!\n");

    // Free String Memory
    free(str1);
    free(str2);
    free(str3);
    free(str4);

    return EXIT_SUCCESS;
}

str *initStr(char *text)
{
    str *temp = malloc(sizeof(str) + getLenght(text) + END);
    if (temp != NULL)
    {
        temp->len = getLenght(text);
        strcpy(temp->text, text);
    }
    return temp;
}

size_t getLenght(char *text)
{
    size_t len = 0;
    while (text[len] != '\0')
    {
        len++;
    }
    return len;
}

bool isEqual(str *str1, str *str2)
{   
    size_t index;
    bool equal = false;
    
    for (index = 0; stringNotEnd(index); index++)
    {
        if (str1->text[index] == str2->text[index]) 
            equal = true;
        else equal = false;
    }

    // Check if Both ened 
    if (stringEnd(index)) equal = true;
    else equal = false;
    
    return equal;
}
#pragma clang diagnostic pop
