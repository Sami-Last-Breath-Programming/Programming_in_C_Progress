#include <stdio.h>
#include <stdlib.h>

#define PRINT_DAY(str, d) printf("%s %.2i/%.2i/%.2i\n", str, d->day, d->month, d->year) 

// Number of Days in a Week
enum days
{
	MONDAY = 1,
	TUESDAY = 2,
	WEDNESDAY = 3,
	THURSDAY = 4,
	FRIDAY = 5,
	SATURDAY = 6,
	SUNDAY = 0,
};

// Date Class
typedef struct date
{
	int day;
	int month;
	int year;

}date;

// Declerations
int convertToN(const date *);
int getDays(int);
void printDay_Date(int, const date *);

int main(void)
{
	// Date Obj
    date date1 = {
        .day = 8,
        .month = 8,
        .year = 2004,
    };
	
	// Convert to N then get day number
	int N = convertToN(&date1);
	printf("DEBUG N: %i\n", N);
	int result = getDays(N);
	printf("DEBUG WEEK DAY VAL: %i\n", result);

	// Check Day And Print
	printDay_Date(result, &date1);

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

int getDays(int N)
{
	const int sub = 621049;
	return (N - sub) % 7;
}

void printDay_Date(int result, const date *d)
{
	switch (result)
	{
		case MONDAY:
			PRINT_DAY("Monday", d);
			break;
		case TUESDAY:
			PRINT_DAY("Tuesday", d);
			break;
		case WEDNESDAY:
			PRINT_DAY("Wednesday", d);
			break;
		case THURSDAY:
			PRINT_DAY("Thursday", d);
			break;
		case FRIDAY:
			PRINT_DAY("Friday", d);
			break;
		case SATURDAY:
			PRINT_DAY("Saturday", d);
			break;
		case SUNDAY:
			PRINT_DAY("Sunday", d);
			break;
		default:
			printf("Error! Invalid Week Day!\n");
			break;
	}
}
