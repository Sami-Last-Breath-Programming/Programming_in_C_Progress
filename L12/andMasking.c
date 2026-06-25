// Using Bitwise And to Mask the bits

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Bytes to be Bitwise And
    short num = 25;
    const short mask = 3;

    // Masking the num with 3 
    num &= mask;

    // Printing the result 
    printf("%d\n",num);
    
    return EXIT_SUCCESS;
}
