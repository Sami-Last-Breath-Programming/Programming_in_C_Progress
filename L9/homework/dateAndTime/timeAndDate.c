#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "timeAndDate.h"

bool checkLeapYear(int);
bool isCentury(int);

void showTimeDate(const dateAndTime *current, enum printFlag flag)
{
    printf("-----------------------------------------------------\n");
    
    printf("The %s Time and Date: %.2i:%.2i:%.2i | %.2i/%.2i/%.2i\n",
        (flag) ? "Updated" : "Current",
        current->st.hr,
        current->st.min,
        current->st.sec,
        current->sd.day,
        current->sd.month,
        current->sd.year
    );

    printf("-----------------------------------------------------\n");
}

void updateTime(time *t)
{
    // Update Second 
    t->sec++;

    if (t->sec == 60)
    {
        t->sec = 0;
        t->min++;  // Update Min

        if (t->min == 60)
        {
            t->min = 0;
            t->hr++; // Update Hr

            if(t->hr == 24)
                t->hr = 0;  // Midnight
        }
    }
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
void updateDate(date *d)
{
    // Max Days on each month
    int monthsMaxDay[12] = {
        31, 30, 31, 30, 31, 30, 
        31, 31,30, 31, 30, 31
    };

    // Leap Year Check 
    if (!checkLeapYear(d->year)) monthsMaxDay[1] = 28;
    else monthsMaxDay[1] = 29;

    // Date Update Logic    
    if (d->day == monthsMaxDay[d->month - 1])
    {
        d->day = 1;
        
        if (d->month == 12)
        {
            d->month = 1;
            d->year++;
        }
        else
            d->month++;
    }
    else
        d->day++;

}
#pragma clang diagnostic pop

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
