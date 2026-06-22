// Loop throught A linked List 

#include <stdio.h>
#include <stdlib.h>

// Clang Flags
#pragma clang diagnostic push 
#pragma clang diagnostic ignored "-Wpadded"

// Linked List 
typedef struct LinkedList
{
    int value;
    struct LinkedList *next;

}LinkedList;

// Main Entry
int main(void)
{
    // Declarations 
    LinkedList val1, val2, val3, val4;

    // Init
    val1.value = 100;
    val1.next = &val2;

    val2.value = 200;
    val2.next = &val3;

    val3.value = 300;
    val3.next = &val4;

    val4.value = 400;
    val4.next = (LinkedList *)0;

    // Loop Throught the LinkedList
    for (LinkedList *ptr = &val1;  ptr != (LinkedList *)0;
        ptr = ptr->next
    )
    {
        // Print the value of pointer
        printf("The Value: %i\n", (*ptr).value);
    }
    
    return EXIT_SUCCESS;
}
#pragma clang diagnostic pop
