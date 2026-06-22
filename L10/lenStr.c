// Counting the Characters in a String

#include <stdio.h>
#include <stdlib.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

// String Class
typedef struct String
{
    size_t len;
    const char *text;

}String;

// Declarations
void getlen(String *);

int main(void)
{
    // String Obj
    String str = {
        .text = "Hello World !",
    };

    // Get the length of string 
    getlen(&str);

    // Print the length of string
    printf("The Length is %zu \n", str.len);

    return EXIT_SUCCESS;
}

void getlen(String *str)
{   
    str->len = 0;

    while (str->text[str->len] != '\0')
    {
        str->len++;
    }
}
#pragma clang diagnostic pop
