#ifndef TIME_AND_DATE
#define TIME_AND_DATE

typedef struct time 
{
    int hr;
    int min;
    int sec;

} time;

typedef struct date
{
    int day;
    int month;
    int year;

}date;

typedef struct dateAndTime
{
    time st;
    date sd;

}dateAndTime;

enum printFlag
{
    CURRENT = 0,
    UPDATED = 1,
};

void updateTime(time *);
void updateDate(date *);
void showTimeDate(const dateAndTime *, enum printFlag);

#endif
