#ifndef SORT_H
#define SORT_H

/*Sorts the array containing strings using the quicksort algorithm*/
void quick_sort(char *a[], int low, int high);

/*Finds the pivot element of the array and splits and rearranges the array around the pivot*/
int split(char *a[], int low, int high);

#endif