#include <stdio.h>

#define EXIT_SUCCESS 0 

_Bool isCentury(int year)
{   return (_Bool)(year % 100 == 0);   }

_Bool checkLeapYear(int year)
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

int main(void)
{   
    int year;
    
    printf("Enter Year: ");
    scanf("%i", &year);

    if (checkLeapYear(year) == 1) printf("Leap Year ! \n");
    else printf("Not a Leap Year \n");

    return EXIT_SUCCESS;
}