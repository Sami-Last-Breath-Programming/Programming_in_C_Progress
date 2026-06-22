// Struct for Date

#include <stdio.h>
#include <stdlib.h>

struct date 
{
    int day;
    int month;
    int year;
};

// Main Entery 
int main(void)
{
    // Define and init a date 
    struct date today = {
        .day = 9,
        .month = 4,
        .year = 2016
    };

    // Print the date
    printf("The Date is %02i/%02i/%2i\n", 
        today.day, 
        today.month,
        today.year % 100
    );

    // year / 100 proof
    printf("%i\n", today.year / 100);
    
    return EXIT_SUCCESS;
}
