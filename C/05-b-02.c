#include <stdio.h>
#include <stdlib.h>

struct mydate {
    int year;
    int month;
    int day;
};
struct mydate date;

struct mydate tomorrow(struct mydate date)
{
    switch (date.month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
            if (date.day == 31) {
                date.month += 1;
                date.day = 1;
            } else {
                date.day += 1;
            }
            break;
        
        case 4:
        case 6:
        case 9:
        case 11:
            if (date.day == 30) {
                date.month += 1;
                date.day = 1;
            } else {
                date.day += 1;
            }
            break;

        case 2:
            if (date.year % 4 == 0) {
                if (date.day == 29) {
                    date.month += 1;
                    date.day = 1;
                } else {
                    date.day += 1;
                }
            } else {
                if (date.day == 28) {
                    date.month += 1;
                    date.day = 1;
                } else {
                    date.day += 1;
                }
            }
            break;
    
        default:
            if (date.day == 31) {
                date.year += 1;
                date.month = 1;
                date.day = 1;
            } else {
                date.day += 1;
            }
            break;
    }

    return date;
}

void printdate(struct mydate date)
{
    scanf("%d %d %d", &(date.year), &(date.month), &(date.day));
    printf("Today is %04d/%02d/%02d\n", date.year, date.month, date.day);
    date = tomorrow(date);
    printf("Tomorrow is %04d/%02d/%02d\n", date.year, date.month, date.day);
    return;
}

int main()
{   
    printdate(date);

    return 0;
}
