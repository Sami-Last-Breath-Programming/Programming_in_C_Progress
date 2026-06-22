// PLaying with pointers

#include <stdio.h>
#include <stdlib.h>

// Main Entry
int main(void)
{
    // Integer Variable
    int a = 60;
    
    // Pointer
    void *hex_memory = (void *)&a;

    // Print the pointer
    printf("The Integer is: %i\n", *((int *)hex_memory));
    printf("The Double is: %f\n", *((double *)hex_memory));
    printf("The Character is: %c\n", *((char *)hex_memory));

    // Print complex
    printf("The Complex is: %i\n", *(int *)*(&hex_memory));

    return EXIT_SUCCESS;
}
