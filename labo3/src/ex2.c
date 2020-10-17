#include <stdio.h>

enum week_days {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
typedef enum week_days Week_days;

void display_week_day (int week_day)
{
    switch(week_day)
    {
        case 0:
            printf("Monday\n");
            break;
        case 1:
            printf("Tuesday\n");
            break;
        case 2:
            printf("Wednesday\n");
            break;
        case 3:
            printf("Thursday\n");
            break;
        case 4:
            printf("Friday\n");
            break;
        case 5:
            printf("Saturday\n");
            break;
        case 6:
            printf("Sunday\n");
            break;
        default:
            printf("Error\n"); 
    }
}

int main (void)
{
    Week_days day = Wednesday; 
    display_week_day(day);
}
