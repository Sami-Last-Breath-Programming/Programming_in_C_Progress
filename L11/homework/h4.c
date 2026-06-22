// Check out

#include <stdio.h>
#include <stdlib.h>

// Clang Flags
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#pragma clang diagnostic ignored "-Wformat-security"
#pragma clang diagnostic ignored "-Wformat-nonliteral"

// Main Entry 
int main(void)
{
    // Examples
    char *mess = "Low Level is Op !\n";
    char mess2[] = "Web Dev is doom!\n";
    char *format = "Num = %i\n";
    int num = 420;

    // Print the mess
    printf("%s", mess);
    printf(mess);

    printf("----------------------\n");

    // Print the mess2
    printf("%s", mess2);
    printf(mess2);
    printf("%s", &mess2[0]);

    printf("----------------------\n");

    // Print the format
    printf(format, num);
    printf(format + 2, num);

    return EXIT_SUCCESS;
}
#pragma clang diagnostic pop
