/*  Write a program that prints the following text.
    1. In C, lowercase letters are significant.
    2. main() is where program execution begins.
    3. Opening and closing braces enclose program statements in a routine.
    4. All program statements must be terminated by a semicolon
*/

#include <stdio.h>

char m1[] = "In C, lowercase letters are significant.";
char m2[] = "main() is where program execution begins.";
char m3[] = "Opening and closing braces enclose program statements in a routine.";
char m4[] = "All program statements must be terminated by a semicolon";

int main(void)
{
    printf("%s\n%s\n%s\n%s\n",
        m1,
        m2,
        m3,
        m4
    );
}
