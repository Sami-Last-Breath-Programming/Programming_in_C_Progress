#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

// Clang
CLANG_START

// Main Entry
int main(void)
{
    // Numbers Arrays 
    int num_i[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float num_f[] = {10.0f, 20.0f, 30.0f, 40.0f, 50.0f, 60.0f, 70.0f, 80.0f, 90.0f, 100.00f};


    // Strings and Boolens Array
    bool tf[] = {1, 1, 0, 0, 1};
    char *str[] = {"Hello", "Nice", "To", "Meet", "You"};

    // Print Arrays
    printList(num_i, 10, INTEGER);
    printList(num_f, 10, FLOAT);
    printList(tf, 5, BOOLEAN);
    printList(str, 5, STRING);
    
    return EXIT_SUCCESS;
}
CLANG_END
