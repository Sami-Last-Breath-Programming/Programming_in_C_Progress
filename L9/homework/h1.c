// Number of elapsed days calculator

#include <stdio.h>
#include <stdlib.h>

#define DEBUG(arg) printf("DEBUG: %i\n", arg)

// Date Object 
typedef struct date 
{
    int day;
    int month;
    int year;

}date;

// Declerations
int convertToN(const date *);

// Main Entry
int main(void)
{
    // Dates
    date date1 = {
        .day = 8,
        .month = 8,
        .year = 2004,
    };
    date date2 = {
        .day = 22,
        .month = 2,
        .year = 2005,
    };

    // Calculate N's 
    int n1 = convertToN(&date1);
    int n2 = convertToN(&date2);
    
    DEBUG(n1);
    DEBUG(n2);

    // Print Days 
    printf("The Elapsed Days: %i\n", n2 - n1);
    
    return EXIT_SUCCESS;
}

int convertToN(const date *d)
{
    // Get the year
    int year = (d->month <= 2) ? d->year - 1 : d->year;
    
    // Get the month 
    int month = (d->month <= 2) ? d->month + 13 : d->month + 1;

    // Return N
    return 1461 * year / 4 + 153 * month / 5 + d->day; 
}
