// Right Shift using Bitwise Right Shift

#include <stdio.h>
#include <stdlib.h>

// Main Entry 
int main(void)
{
    // Declare and Init different types of int
    char num0 = 0;
    short int num1 = 0;
    unsigned int num2 = 0;
    signed int num3 = 0;
    long int num4 = 0; // On linux 8 bytes and on windows 4 bytes
    long long int num5 = 0; // On linux and windows 8bytes
    __int128_t num6 = 0; // 16 bytes integer (2 bytes)

    // Print the sizes of all 
    printf("Char Integer Size: %zu\n",sizeof(num0));
    printf("Short Integer Size: %zu\n",sizeof(num1));
    printf("Unsigned Integer Size: %zu\n",sizeof(num2));
    printf("Signed Integer Size: %zu\n",sizeof(num3));
    printf("Long Integer Size: %zu\n",sizeof(num4));
    printf("Long Long Integer Size: %zu\n",sizeof(num5));
    printf("16 Bytes Integer Size: %zu\n", sizeof(num6));
    
    return EXIT_SUCCESS;
}
