// Escape Characters

#include <stdio.h>
#include <stdlib.h>

#define addLine() printf("---------------------------\n")

int main(void)
{
    // Alert & Backspace Escape Character
    printf("\aHELP!\b PLS HELP !\n");
    addLine();

    // Horizontal Tab Escape Character
    printf("%i\t%i\t%i\n", 10, 20, 30);
    addLine();

    // Vertical Tab Escape Character
    printf("%c\v%c\v%c\n", 'A', 'B', 'C');
    addLine();

    // Backslash Escape Character
    printf("\\a, \\b and \\t used above\n");
    addLine();

    // Double Quotation Escape Character
    printf("\"This is Double Quotated\"\n");
    addLine();

    // Feed Escape Character
    printf("1 \f2 \f3 \fGO...\n");
    addLine();

    // Universal Escape Character
    printf("2\u00B2 = %i\n", 2*2);
    addLine();

    return EXIT_SUCCESS;
}
