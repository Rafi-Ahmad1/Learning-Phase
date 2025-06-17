#include <stdio.h>
#include "qsort.h"
#include "readword.h"

#define MAX_WORD_LEN 20
#define NUM_WORDS 50

int main(void) {
    char *words[NUM_WORDS];
    int num_words;

    for(num_words = 0; num_words < NUM_WORDS; num_words++) {
        printf("Enter word: ");
        words[num_words] = read_char();
        if(*words[num_words] == '\0')
            break;
    }

    quick_sort(words, 0, num_words - 1);
    
    printf("\nIn sorted order: ");
    for(num_words = 0; num_words < NUM_WORDS; num_words++) {
        if(*words[num_words] == '\0')
            break;
        printf("%s ", words[num_words]);
    }
    printf("\n");
}