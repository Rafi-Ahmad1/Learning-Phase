#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "readword.h"

#define MAX_WORD_LEN 20

char *read_char(void) {
    char ch;
    int i;
    char *str = malloc((MAX_WORD_LEN + 1) * sizeof(char));

    if(str == NULL) {
        printf("Error Allocating Memory.");
        exit(EXIT_FAILURE);
    }

    while((ch = getchar()) == ' ');

    for(i = 0; i < MAX_WORD_LEN; i++) {
        if(isspace(ch)){
            str[i] = '\0';
            return str;
        }
        str[i] = ch;
        ch = getchar();
    }
    
}