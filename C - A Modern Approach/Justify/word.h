#ifndef WORD_H
#define WORD_H

/**************************************************************************
 * read_word: Reads the next word from the input and stores it in word.
 *            Makes word empty if no word could be read because of 
 *            end-of-file. Truncates the word if tis length exceeds len
 * 
 **************************************************************************/

void read_word(char *word, int len);

#endif