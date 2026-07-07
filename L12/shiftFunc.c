// A Shift Function

#include <stdio.h>
#include <stdlib.h>

// Clang Fix
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgnu-binary-literal"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

// Macros
#define Byte 8

// Declarations
void print_Bin(unsigned int flag);
unsigned int shift(unsigned int flag, int times);

// Main Entry
int main(void)
{
    // Flags

    unsigned int f1 = 0b11100001;
    unsigned int f2 = 0b00011110;

    // Print f0 bits
    print_Bin(f1);
    printf("\t");
    print_Bin(f2);
    printf("\n");
    
    // Header
    printf("--------------------------\n");

    // Shift f1 to 5 bits (left shift)
    print_Bin(shift(f1, 5)); 
    printf("\t");
    print_Bin(f1 << 5);
    printf("\n");

    // Shift f1 to -6 bits (right shift)
    print_Bin(shift(f1, -6));
    printf("\t");
    print_Bin(f1 >> 6);
    printf("\n");

    // Shift f2 to 0 bits (right shift)
    print_Bin(shift(f2, 0));
    printf("\t");
    print_Bin(f2 >> 0);
    printf("\n");

    // Shift f1 to -3 then 3 bits (right then left shift)
    print_Bin(shift(shift(f1, -3), 3));
    printf("\t");
    print_Bin((f1 >> 3) << 3);
    printf("\n");

    // Header close
    printf("--------------------------\n");

    return EXIT_SUCCESS;
}

// Function to left and right shift
unsigned int shift(unsigned int flag, int times)
{
    // Left Shift
    if (times > 0) flag <<= times;
    
    // Right Shift
    else flag >>= -times;

    // Zero Shift
    return flag;
}

// Function to print binary
void print_Bin(unsigned int flag)
{
    unsigned int bit_array[Byte];
    
    // Mask
    unsigned int mask = 0x1u;
    
    // Loop till last 8 bits
    for (size_t index = 0; index < Byte; index++)
    {
      // Store the bit in array
      bit_array[index] = (flag & mask) ? 1 : 0;

      // Set the next mask 
      mask <<= 0x1u; 
    }

    // Print the bytes
    for (size_t index = Byte; index > 0; index--)
    {
        printf("%i", bit_array[index - 1]);
    }
}
#pragma clang diagnostic pop
