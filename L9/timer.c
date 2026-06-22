/*  Linux Console Timer
    Only for linux, maybe 
    Unix but i hate windows
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

// Time Obj
struct time
{
    int hr;
    int min;
    int sec;
};

// Declarations
void startTimer(struct time *);
void timerLogic(struct time *);


// Main Entry
int main(void)
{
    // Define the timer obj
    struct time timer  = {
        .hr = 0,
        .min = 0,
        .sec = -1,
    };
    // Start Timer 
    startTimer(&timer);
    
    return EXIT_SUCCESS;
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
void startTimer(struct time * timer)
{   
    while (true)
    {
        // Time logic
        timerLogic(timer);
    
        // Sleep for one sec
        sleep(1);
        
        // Display Time
        system("clear"); // Heavy for system 
        printf("%02i:%02i:%02i\n", timer->hr, timer->min, timer->sec);
     
    }  
}
#pragma clang diagnostic pop

// Worst logic ever but works (someWhat)!
void timerLogic(struct time *timer)
{
    // Handle time logic
    if (timer->sec < 59)
        timer->sec += 1; // Increase the Sec
    else
    {
        // Set the Sec to 0
        timer->sec = 0;
        
        if (timer->min < 59)
            timer-> min += 1; // Increase the Min
        else
        {
            // Set the Min to 0
            timer->min = 0;
            
            if (timer->hr < 24)
                timer->hr += 1; // Increase the Hr
            else
                // Set the Hr to 0
                timer->hr = 0;
        }
        
    }  
}
