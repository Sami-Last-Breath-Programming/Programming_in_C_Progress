// Get the Current date and tell the Tomorrow's date

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Date Struct
struct date 
{
    int day;
    int month;
    int year;
};

// Declarations
void greet(void);
void getNextDate(struct date *, struct date *);
bool checkLeapYear(int);
bool isCentury(int);

// Main Entry
int main(void)
{
    struct date current = {
        .day = 0,
        .month = 0,
        .year = 0,
    };
    struct date next = {
        .day = 0,
        .month = 0,
        .year = 0
    };
    
    // Welcome Header
    greet();

    // Storing the Current Date 
    scanf("%i / %i / %i", 
        &current.day, 
        &current.month, 
        &current.year
    );

    // Calculate Tomorrow's date
    getNextDate(&current, &next);

    // Print Tomorrow's date
    printf("Tomorrow's Date: %02i/%02i/%02i\n",
        next.day,
        next.month,
        next.year
    );

    return EXIT_SUCCESS;
}

void greet(void)
{
    printf("\n---------------------------\n");
    printf("Enter the current Date: \n");
    printf("Example: 10/4/26\n");
    printf("---------------------------\n");

}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
void getNextDate(struct date *current, struct date *next)
{
    // Max Days on each month
    int monthsMaxDay[12] = {
        31, 30, 31, 30, 31, 30, 
        31, 31,30, 31, 30, 31
    };

    // Leap Year Check 
    if (!checkLeapYear(current->year)) monthsMaxDay[1] = 28;
    else monthsMaxDay[1] = 29;

    if (current->day == monthsMaxDay[current->month - 1])
    {
        next->day = 1;
        
        if (current->month == 12)
        {
            next->month = 1;
            next->year = current->year + 1;
        }
        else
        {
            next->month = current->month + 1;
            next->year = current->year;
        }
    }
    else
    {
        next->day = current->day + 1;        
        next->month = current->month;
        next->year = current->year;
    }
}

bool isCentury(int year)
{   return (bool)(year % 100 == 0);   }

bool checkLeapYear(int year)
{
    if (isCentury(year))
    {
        if ((year % 400) == 0) return 1;
        else return 0;
    }
    else 
    {
        if ((year % 4) == 0) return 1;
        else return 0;
    }
}

#pragma clang diagnostic pop
