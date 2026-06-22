#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Struct of the integer pointer
    struct IntPtr
    {
        int *ptr1;
        int *ptr2;
    };

    // Declarations
    struct IntPtr ptr;
    int num1, num2;
    
    // Init
    ptr.ptr1 = &num1;
    ptr.ptr2 = &num2;

    // Assignation
    num1 = 100;
    num2 = -97;

    // Print the values 
    printf("num1 = %i, *ptr.ptr1 = %i\nnum2 = %i, *ptr.ptr2 = %i\n",
        num1, *ptr.ptr1, num2, *ptr.ptr2
    );
    
    return EXIT_SUCCESS;
}
