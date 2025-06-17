#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"

#define MAX_LINE_LEN 60
#define MAX_WORD_LEN 20

struct line {
    char word[MAX_WORD_LEN + 3]; /*Max length of word + Null character + '*' + Space Character*/
    struct line *next;
};
struct line *first_word = NULL; /*The list is initially empty*/

int line_len = 0;
int num_words = 0;

void clear_line(void) {
    struct line *temp;
    while(first_word != NULL) {
        temp = first_word;
        first_word = first_word->next;
        free(temp);
    }
    line_len = 0;
    num_words = 0;
}

void add_word(const char *word) {
    struct line *new_word;

    new_word = malloc(sizeof(struct line));
    if(new_word == NULL) {
        fprintf(stderr, "Memory Allocation failed.");
        exit(EXIT_FAILURE);
    }

    new_word->word[0] = '\0';
    if(num_words > 0) {
        strcat(new_word->word, " ");
        line_len++;
    }

    strcat(new_word->word, word);
    new_word->next = first_word;
    first_word = new_word;

    line_len += strlen(word);
    num_words++;
}

int space_remaining(void) {
    return MAX_LINE_LEN - line_len;
}

void write_line(void) {
    struct line *p;
    int extra_spaces, spaces_to_insert, i;

    extra_spaces = MAX_LINE_LEN - line_len;
    spaces_to_insert = extra_spaces/(num_words - 1);
    for(p = first_word; p != NULL; p = p->next) {
        printf(p->word);
    
        for(i = 1; i <= spaces_to_insert + 1; i++)
            putchar(' ');
        extra_spaces -= spaces_to_insert;
        num_words--;
    }
    putchar('\n');
}

void flush_line(void) {
    struct line *p;
    if(line_len > 0)
        for(p = first_word; p != NULL; p = p->next) 
        puts(p->word);
}