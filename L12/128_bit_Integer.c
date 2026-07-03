// Math on 128 bit integer on 64 bit CPU

#include <stdio.h>
#include <stdlib.h>

// Clang Fix
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

// Declarations
void print_uint128(__uint128_t n);

// Main Entry
int main(void)
{
    
    // 16 Bytes Integers
    __uint128_t num1 = 8999999999875787;
    __uint128_t num2 = 89958888888888868;
    

    // Multiply Both
    print_uint128(num1 * num2);
    
    return EXIT_SUCCESS;
}

// Helper function to print a 128-bit unsigned integer
void print_uint128(__uint128_t num) {
    
    char str[40]; // 128-bit int maxes out at 39 digits
    int i = 0;
    
    if (num == 0) {
        printf("0\n");
        return;
    }
    
    while (num > 0) {
        str[i++] = (char)('0' + (num % 10));
        num /= 10;
    }
    
    // Print the string in reverse
    while (i > 0) {
        putchar(str[--i]);
    }
    putchar('\n');
}
#pragma clang diagnostic pop
