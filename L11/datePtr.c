// Ptr of the Struct

#include <stdio.h>
#include <stdlib.h>

// Main Entry
int main(void)
{
    // Declarations 
    struct date 
    {
        int day;
        int month;
        int year;
    };
    
    struct date *datePtr;
    struct date today;

    // Reference
    datePtr =  &today;

    // Init
    today.day = 17;
    (*datePtr).month = 5;
    datePtr->year = 2026;

    // Print the date 
    printf("DATE: %02i/%02i/%04i\n", 
        today.day, (*datePtr).month, datePtr->year
    );
    
    return EXIT_SUCCESS;
}
