#include <stdio.h>

struct date {
    int day;
    int month;
    int year;
};

int compare_dates(struct date d1, struct date d2);

void main() {
    int earlier_date;
    struct date d1, d2;

    printf("Enter first date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &d1.day, &d1.month, &d1.year);
    printf("Enter Second date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &d2.day, &d2.month, &d2.year);

    earlier_date = compare_dates(d1, d2);
    if(earlier_date == 0)
        printf("The entered dates are the same.");
    else if(earlier_date == 1)
        printf("%d/%d/%d comes before %d/%d/%d.", d1.day, d1.month, d1.year, d2.day, d2.month, d2.year);
    else
        printf("%d/%d/%d comes before %d/%d/%d.", d2.day, d2.month, d2.year, d1.day, d1.month, d1.year);
}

/****************************************************************
 * compare_dates: Accepts two dates as arguments and compares   *
 *                them to see which comes first. Returns        *
 *                0 if they are same                            *
 *                1 if first is earlier                         *
 *                -1 if second is earlier                       *
 *                                                              *
 ****************************************************************/
int compare_dates(struct date d1, struct date d2) {
    if (d1.year != d2.year)
        return (d1.year < d2.year)? 1: -1;
    else if(d1.month != d2.month)
        return (d1.month < d2.month)? 1: -1;
    else if(d1.day != d2.day)
        return (d1.day < d2.day)? 1: -1;
    return 0;
}