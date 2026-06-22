// Pre Increment and Post Increment

#include <stdio.h>
#include <stdlib.h>

// Clang Flags
#pragma clang diagnostic push 
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

// Main Entry
int main(void)
{
    int num1 =  50, num2 = 50;
    int change1, change2;
    int array[5] = {10, 20, 30, 40, 50};
    int *ptr_array;

    // Pre and Post inc with substraction 
    change1 = --num1;   // = 49
    change2 = num2--;   // = 50

    // Print both 
    printf("Change1: %i\nChange2: %i\n", change1, change2);

    // Pre and Post inc with addition
    change1 = (++num1) + 1;  // = 51
    change2 = (num2++) + 1;  // = 50
    
    // Print both 
    printf("Change1: %i\nChange2: %i\n", change1, change2);

    // Pre and Post on Array
    ptr_array = array;
    printf("Array Element 2 By Pre = %i\n", *(++ptr_array));    // = 20
    ptr_array = array;
    printf("Array Element 2 By Post = %i\n", *ptr_array++);     // = 10
    printf("Array Element 3 By Post = %i\n", *++ptr_array);     // = 30

    return EXIT_SUCCESS;
}
#pragma clang diagnostic pop
