// Pointer or Array 

#include <stdio.h>
#include <stdlib.h>

// Clang Flags
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

#define LEN(x) (x - 1)
#define GET(x, y) (*(x + y))

// Main Entry 
int main(void)
{
    int element_4;
    int element_5;

    // Array of six elements
    int array[6] = {10, 20, 30, 40, 50, 60};

    // Get the elements of the array
    element_4 = *(array + LEN(4));
    element_5 = GET(array, LEN(5));

    // Print the elements
    printf("Element Four is: %i\n", element_4);
    printf("Element Five is: %i\n", element_5);

    // Print the array variable 
    printf("The Array Variable contains: %i\n", *array);
    
    return EXIT_SUCCESS;
}
#pragma clang diagnostic pop
