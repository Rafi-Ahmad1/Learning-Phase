#include <stdio.h>
#include <string.h>
#include "readline.h"

#define MAX_REMIND 50
#define MSG_LEN 60
#define TIME_LEN 6
#define DAY_LEN 6

int main(void) {
    char reminders[MAX_REMIND][MSG_LEN + 3];
    char day_str[DAY_LEN], msg_str[MSG_LEN + 1], time_str[TIME_LEN + 1];
    int day, month, i, j, num_remind = 0;

    for(;;) {
        if(num_remind == MAX_REMIND) {
            printf("-- No Space left --n");
            break;
        }

        printf("Enter day, time and reminder: ");
        scanf("%2d/%2d", &month, &day);
        if(day == 0 || month == 0)
            break;

        sprintf(day_str, "%2d", month);
        strcat(day_str, "/");
        sprintf(day_str + strlen(day_str), "%2d", day);
        fgets(time_str, TIME_LEN + 1, stdin);
        read_line(msg_str, MSG_LEN);
        
        if(month > 12 || month < 0 || day > 31 || day < 0) {
            printf("Error, Entered date is invalid\n");
            continue;
        }

        for(i = 0; i < num_remind; i++) {
            if(strcmp(day_str, reminders[i]) < 0)
                break;
            else if(strcmp(day_str, reminders[i]) == 0 && strcmp(time_str, reminders[i + DAY_LEN]) < 0)
                break;
        }
        for(j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j-1]);
        
        strcpy(reminders[i], day_str);
        strcat(reminders[i], time_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    printf("\n  Day  Time Reminder\n");
    for(i = 0; i < num_remind; i++) 
        printf(" %s\n", reminders[i]);
    
        return 0;
}