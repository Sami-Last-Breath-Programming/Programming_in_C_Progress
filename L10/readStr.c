// Read String from stdin 

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Array for Store
    char str1[10], str2[10], str3[10];

    // Header
    printf("Enter the Text: ");

    // Store Text from stdin
    scanf("%9s %9s %9s", str1, str2, str3);

    // Print the text
    printf("\nStr1: %s\nStr2: %s\nStr3: %s\n", str1, str2, str3);

    return EXIT_SUCCESS;
}
