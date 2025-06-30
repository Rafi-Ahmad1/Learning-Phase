#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

int read_exp(void);

int main() {
    while(read_exp());

    return 0;
}

int read_exp(void) {
    Stack S = create();
    char ch = 0;
    int i, j;

    printf("\nEnter an RPN expression: ");
    for (; ch != '\n';) {
        scanf(" %c",&ch);

        if (ch >= '0' && ch <= '9')
            push(S, ch - '0');
        else {
            switch(ch) {
                case '+': push(S, pop(S) + pop(S)); break;
                case '-': i = pop(S), j = pop(S); push(S, j-i); break;   /*Correct Order, Couldn't think of anything else*/
                case '*': push(S, pop(S) * pop(S)); break;
                case '/': i = pop(S), j = pop(S); push(S, j/i); break;   /*Correct Order, Couldn't think of anything else*/
                case '=': printf("Value of Expression: %d\n",pop(S)); make_empty(S); return 1;
                case 'Q': case 'q': printf("Exiting Progaram..."); return 0;
                default:  printf("Invalid Input\n"); exit(EXIT_FAILURE);
            }
        }
    }
    destroy(S);
}