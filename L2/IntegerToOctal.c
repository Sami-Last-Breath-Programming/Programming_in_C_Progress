// Integer (Base 10) to Octal (Base 8)

#include <stdio.h>

int main(void)
{   
    int num;
    
    // Scanning for num from stdin
    printf("Enter an Integer: ");
    scanf("%i", &num);
    
    // Printing in Octal
    printf("In Octal: %o\n",num);
    printf("In Octal with zero: %#o\n", num);
    
    return 0;
}