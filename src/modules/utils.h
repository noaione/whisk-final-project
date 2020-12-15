#ifndef MOD_UTILS_H
#define MOD_UTILS_H

#include <time.h>
#include <stdlib.h>

#define CLEAR system("cls||clear")
#define ENTER printf("Press enter to continue...")

/* Utility stuff */
void printalot(char ch, int amount, bool new_line);

/* Time handler */
typedef struct TimeData {
    int secs;
    int mins;
    int hours;
    int mdays;
    int months;
    int years;
    int wdays;
    int ydays;
    bool is_dst;

    // padded number
    char pmdays[3];
    char pydays[4];
    char psecs[3];
    char pmins[3];
    char phours[3];
    char pmonths[3];

    // mapped to string
    // weekdays
    char s3wdays[4]; // cut to first 3 chars
    // months days
    char s3months[4]; // cut to first 3 chars
    char swdays[10]; // full day name
    char smonths[10]; // full month name
} TimeData;

tm *currentTime();
TimeData *convertToTimeData(tm *time_info);

#endif /* MOD_UTILS_H */