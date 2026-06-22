#include <stdio.h>
#include <stdlib.h>
#include "timeAndDate.h"

// Main Entry
int main(void)
{
    dateAndTime current = {
        {
            .hr = 5,
            .min = 59,
            .sec = 59
        },
        {
            .day = 13,
            .month = 4,
            .year = 2026
        },
    };

    // Print Current Time and Date
    showTimeDate(&current, CURRENT);

    // Update Time and Date
    updateTime(&current.st);
    updateDate(&current.sd);

    // Print Update Time and Date
    showTimeDate(&current, UPDATED);

    return EXIT_SUCCESS;
}
