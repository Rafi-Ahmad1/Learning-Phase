#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN + 1];
int line_len = 0;
int num_words = 0;

void clear_line(void) {
    line[0] = '\0';
    line_len = 0;
    num_words = 0;
}

void add_word(const  char *word) {
    if(num_words > 0) {
        line[line_len] = ' ';
        line[line_len + 1] = '\0';
        line_len++;
    }
    strcat(line, word);
    line_len += strlen(word);
    num_words++;
}

int space_remaining(void) {
    return MAX_LINE_LEN - line_len;
}

void write_line(void) {
    static int left_biased = 1;
    int extra_spaces, spaces_per_gap, leftover, spaces_to_insert;
    int gap_index = 0, i, j;
    
    extra_spaces = MAX_LINE_LEN - line_len;
    spaces_per_gap = extra_spaces / (num_words - 1);
    leftover = extra_spaces % (num_words - 1);

    for(i = 0; i < line_len; i++) {
        if(line[i] != ' ')
        putchar(line[i]);
        else {
            spaces_to_insert = spaces_per_gap + 1;

            if(left_biased && gap_index < leftover)
                spaces_to_insert++;
            else if(!left_biased && gap_index >= (num_words - 1 - leftover))
                spaces_to_insert++;

            for(j = 1; j <= spaces_to_insert; j++) {
                putchar(' ');  
            }
            gap_index++;
        }
    }
    putchar('\n');

    left_biased = !left_biased;
}

void flush_line(void) {
    if(line_len > 0)
        puts(line);
}