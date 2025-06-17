#include <string.h>
#include <ctype.h>
#include "qsort.h"

void quick_sort(char *a[], int low, int high) {
    int pivot;

    if(low >= high)
        return;
    
    pivot = split(a, low, high);
    quick_sort(a, low, pivot - 1);
    quick_sort(a, pivot + 1, high);
}
int split(char *a[], int low, int high) {
    int part_element = low;
    char *pivot = a[part_element];

    if(low >= high)
        return part_element;

    for(;;) {
        while(low < high && strcmp(pivot, a[high]) <= 0)
            high--;
        if(low >= high)
            break;
        a[low] = a[high];
        low++;
    
        while(low < high && strcmp(pivot, a[low]) >= 0)
            low++;
        if(low >= high)
            break;
        a[high] = a[low];
        high--;
    }

    a[high] = pivot;
    return high;
}