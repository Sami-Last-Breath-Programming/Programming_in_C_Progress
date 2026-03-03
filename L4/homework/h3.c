/*   
    Write a program that converts 27® from degrees Fahrenheit
    to degrees Celsius.
    C = (F-32) / 1.8
*/

#include <stdio.h>

#define EXIT_SUCCESS 0;

int main(void)
{
    const float fahVal = 27.0f;
    
    printf("The Temperature in Celsius is %.3f°C \n",
        (fahVal - 32) / 1.8
    );
    
    return EXIT_SUCCESS;
}