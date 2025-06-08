#include <stdio.h>

#define NUM_TIMES 8

struct {
    int departure_time;
    int arrival_time;
}times[NUM_TIMES] = {{(8 * 60),         (10 * 60) + 16},   //Departure 8:00 AM Arrival 10:16 AM
                     {(9 * 60) + 43,    (11 * 60) + 52},   // Departure 9:43 AM Arrival 11:52 AM
                     {(11 * 60) + 19,   (13 * 60) + 31},   // Departure 11:19 AM Arrival 1:31 PM
                     {(12 * 60) + 47,   (15 * 60)},        // Departure 12:47 PM Arrival 3:00 PM
                     {(14 * 60),        (16 * 60) + 8},    // Departure 2:00 PM Arrival 4:08 PM
                     {(15 * 60) + 45,   (17 * 60) + 55},   // Departure 3:45 PM Arrival 5:55 PM
                     {(19 * 60),        (21 * 60) + 20},   // Departure 7:00 PM Arrival 9:20 PM
                     {(21 * 60) + 45,   (23 * 60) + 58}    // Departure 9:45 PM Arrival 11:58 PM
};

int main()
{
    int hour, minute, mins_since_mdnght;

    printf("Enter Current time[24-hour]: ");
    scanf("%d:%d", &hour, &minute);

    mins_since_mdnght = minute + (hour * 60);
    
    printf("Closest departure time is ");

    for(int i = 0; i < NUM_TIMES; i++)
        if(mins_since_mdnght <= (times[i].departure_time + times[i+1].departure_time)/2 ) {
            printf("%.2d:%.2d, Arriving at %.2d:%.2d", 
                        times[i].departure_time/60, times[i].departure_time%60,
                        times[i].arrival_time/60, times[i].arrival_time%60);
            break;
        }
    
    return 0;
}