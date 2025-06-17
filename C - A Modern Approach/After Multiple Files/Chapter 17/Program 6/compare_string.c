#include <string.h>
#include "compare_string.h"

/*Compare function for the qsort library function*/
int compare_string(const void *p, const void *q) {
    const char *str1 = p;
    const char *str2 = q;

    return strcmp(str1, str2);
}