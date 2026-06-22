#include <stdio.h>
#include <stdlib.h>

// Object Of Time
typedef struct time
{
    int hr;
    int min;
    int sec;

}time;

// Function Updates One Second 
void updateTime(time *);

// Main Entry 
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
int main(void)
{
    // Array for times 
    time times[] = {
        {4, 59, 59},
        {11, 59, 59},
        {23, 59, 59},
        {12, 0, 0},
    };

    // Size of Array
    size_t size = sizeof(times) / sizeof(times[0]);

    // Loop Throught Each Array
    for (size_t index = 0; index < size; index++)
    {
        // Pre Header 
        printf("Time is %.2i:%.2i:%.2i ",
            times[index].hr,
            times[index].min,
            times[index].sec
        );

        // Update time
        updateTime(&times[index]);

        // Post Header
        printf("and after one second %.2i:%.2i:%.2i\n",
            times[index].hr,
            times[index].min,
            times[index].sec
        );

    }
    return EXIT_SUCCESS;
}
#pragma clang diagnostic pop

void updateTime(time * now)
{
    // Increase The Sec By One
    now->sec++;

    // Update Min
    if (now->sec == 60)
    {
        now->sec = 0;
        
        // Increase The Min By One
        now->min++;

        // Update Hr
        if (now->min == 60)
        {
            now->min = 0;

            // Increase The Hr by One
            now->hr++;

            // Update To MidNight
            if (now->hr == 24)
                now->hr = 0;
        }
    }

}
