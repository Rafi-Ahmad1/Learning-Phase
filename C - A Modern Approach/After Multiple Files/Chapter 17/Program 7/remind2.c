#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

struct vstring {
    int len;
    char chars[]; /*C99 Only- Flexible Array Member*/
};

int read_line(char str[], int n);

int main(void) {
    struct vstring *reminders[MAX_REMIND];
    char day_str[3], msg_str[MSG_LEN + 1];
    int day, i, j, num_remind = 0;

    for(;;) {
        if(num_remind == MAX_REMIND) {
            printf("-- No Space left --n");
            break;
        }

        printf("Enter day and reminder: ");
        scanf("%2d", &day);
        if(day == 0)
            break;
        sprintf(day_str, "%2d", day);
        read_line(msg_str, MSG_LEN);

        for(i = 0; i < num_remind; i++)
            if(strcmp(day_str, reminders[i]->chars) < 0)
                break;
        for(j = num_remind; j > i; j--)
            reminders[j] = reminders[j-1];

        reminders[i] = malloc(2 + sizeof(struct vstring) + strlen(msg_str)); /*Dynamically Allocating Just enough memory for msg + day*/
        if(reminders[i] == NULL) {
            printf("-- No Space left--\n");
            break;
        }
        reminders[i]->len = strlen(msg_str);
        strcpy(reminders[i]->chars, day_str);
        strcat(reminders[i]->chars, msg_str);

        num_remind++;
    }

    printf("\nDay Reminder\n");
    for(i = 0; i < num_remind; i++) 
        printf(" %s\n", reminders[i]->chars);
    
        return 0;
}

int read_line(char str[], int n) {
    int ch, i = 0;
    
    while((ch = getchar()) != '\n')
        if(i < n)
            str[i++] = ch;

    str[i] = '\0';
    return i;
}