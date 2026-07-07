// A Program to Rotate Bits using Bitwise Operators

#include <stdio.h>
#include <stdlib.h>

// Clang Fix
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgnu-binary-literal"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#pragma clang diagnostic ignored "-Wsign-conversion"

// Macros
#define Int32 32

// Declarations 
void print_Bin(unsigned int flag);
unsigned int rotateBits(unsigned int flag, int bits);

// Main Entry 
int main(void)
{
    // Flags
    unsigned int f1 = 0b10000000000000000000000000000000u;
    unsigned int f2 = 0b00000000000000000000000000000001u;
    unsigned int f3 = 0b10100000000000000000000000000000u;
    unsigned int f4 = 0b10101011110011011110111100000000u;

    // Rotate Flag 1 to the Left
    printf("Flag 1: ");         
    print_Bin(rotateBits(f1, 1));       // Rotate left by 1 bits
    putchar('\n');                      // Newline

    // Rotate Flag 2 to the Right
    printf("Flag 2: ");
    print_Bin(rotateBits(f2, -1));      // Rotate right by 1 bits        
    putchar('\n');                      // Newline
    
    // Rotate Flag 3 to the Left
    printf("Flag 3: ");            
    print_Bin(rotateBits(f3, 3));       // Rotate left by 3 bits        
    putchar('\n');                      // Newline

    // Rotate Flag 4
    printf("Flag 4: ");            
    print_Bin(rotateBits(f4, 0));       // Rotate by 0 bits        
    putchar('\n');                      // Newline

    // Rotate Flag 4 - OverFlow
    printf("Flag 4: ");            
    print_Bin(rotateBits(f4, 44));      // Rotate left by 44 bits
    printf(" - OverFlow");        
    putchar('\n');                      // Newline

    // Rotate Flag 4 - UnderFlow
    printf("Flag 4: ");            
    print_Bin(rotateBits(f4, -44));     // Rotate right by 44 bits 
    printf(" - UnderFlow") ;    
    putchar('\n');                      // Newline

    return EXIT_SUCCESS;
}

// Function to print binary
void print_Bin(unsigned int flag)
{
    unsigned int bit_array[Int32];
    
    // Mask
    unsigned int mask = 0x1u;
    
    // Loop till 32 bits
    for (size_t index = 0; index < Int32; index++)
    {
      // Store the bit in array
      bit_array[index] = (flag & mask) ? 1 : 0;

      // Set the next mask 
      mask <<= 0x1u; 
    }

    // Print the bytes
    for (size_t index = Int32; index > 0; index--)
    {
        printf("%i", bit_array[index - 1]);
    }
}

// Function to Rotate bits
unsigned int rotateBits(unsigned int flag, int bits)
{
    unsigned int mask, result;
    
    // Clamp the range of bits
    if (bits > 0) 
        bits = bits % Int32;
    
    else  
        bits = -(-bits % Int32);
    
    
    // Check for Zero bits
    if (bits == 0) result = flag;
    
    else if  (bits > 0)
    {
        // Rotate bits to the left
        mask = flag >> (Int32 - bits);
        result = flag << bits | mask;
    }
    else 
    {
        // Rotate the bits Right
        bits = -bits; 
        mask = flag << (Int32 - bits);
        result = flag >> bits | mask;
    }
    return result;
}
#pragma clang diagnostic pop
