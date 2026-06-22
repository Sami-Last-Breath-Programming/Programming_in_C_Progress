#include <stdio.h>
#include <stdlib.h>

// Time Object
typedef struct time 
{
    int hr;
    int min;
    int sec;

}time;

// Declaration
time elapsed_time(time, time);

// Main Entry 
int main(void)
{     
    time t1 = {
        .hr = 3,
        .min = 45,
        .sec = 15,
    };
    time t2 = {
        .hr = 9,
        .min = 44,
        .sec = 03,
    };

    // Elapsed Time Object return
    time result = elapsed_time(t1, t2);

    // Printing Elapsed Time
    printf("Elapsed Time: %.2i:%.2i:%.2i\n", 
        result.hr,
        result.min,
        result.sec
    );

    return EXIT_SUCCESS;
}

time elapsed_time(time t1, time t2)
{
    time temp;
    
    // Check for Borrows
    if (t2.sec < t1.sec)
    {
        t2.sec += 60;
        t2.min--;
    }
    if (t2.min < t1.min)
    {
        t2.min += 60;
        t2.hr--;
    }
    
    // Calculation 
    temp.sec = t2.sec - t1.sec;
    temp.min = t2.min - t1.min;
    temp.hr = t2.hr - t1.hr;
    
    // MidNight Fix
    if (temp.hr < 0)
        temp.hr += 24;

    return temp;
}
