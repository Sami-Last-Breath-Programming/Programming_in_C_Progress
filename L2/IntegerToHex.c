/*  Integer (Base 10) to Hexadecimal (Base 16) */

#include <stdio.h>

int main(void)
{
    int num;

    // Scanning for Integer from stdin
    printf("Enter an Integer: ");
    scanf("%d", &num);

    // Printing Hexadecimal value
    printf("In Hex: %x\n", num);
    printf("IN Hex++: %#x\n", num);
    printf("IN Hex++: %#X\n", num);
    
    return 0;
}