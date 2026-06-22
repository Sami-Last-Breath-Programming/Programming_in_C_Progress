// Linked List in c 

#include <stdio.h>
#include <stdlib.h>

// Clang Flags 
#pragma clang diagnostic push 
#pragma clang diagnostic ignored "-Wpadded"

// Linked List for Integer
typedef struct IntList
{
    int value;
    struct IntList *next;

}IntList;

// Main Entry
int main(void)
{
    // Declarations 
    IntList value1, value2, value3, value4;
    
    // Set the next ptr
    value1.next = &value2;
    value2.next = &value3;
    value3.next = &value4;
    value4.next = (IntList *) 0;

    // Set the values 
    value1.value = 10;
    value1.next->value = 20;
    value1.next->next->value = 30;
    value1.next->next->next->value = 40;

    // Print the Values
    printf("Integer LinkedList Value 1: %i\n", 
        value1.value
    );
    printf("Integer LinkedList Value 2: %i\n", 
        value1.next->value
    );
    printf("Integer LinkedList Value 3: %i\n", 
        value1.next->next->value
    );
    printf("Integer LinkedList Value 4: %i\n", 
        value1.next->next->next->value
    );
    
    return EXIT_SUCCESS;
}
#pragma clang diagnostic pop
