#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int evaluate_RPN_expression(const char *expression);

void main() {
    char exp[STACK_SIZE + 1];
    int answer;
    
    for(;;) {
        printf("\nEnter an RPN expression: ");
        fgets(exp, STACK_SIZE, stdin);

        answer = evaluate_RPN_expression(exp);
        printf("Value of Expression: %d", answer);
    }
}

int evaluate_RPN_expression(const char *expression) {
    char ch = 0;
    int j, k;

    make_empty();
    for (int i = 0; i < STACK_SIZE; i++) {
        ch = expression[i];

        if (ch >= '0' && ch <= '9')
            push(ch - '0');
        else if(ch == '\0')
            break;
        else {
            switch(ch) {
                case '+': push(pop() + pop()); break;
                case '-': j = pop(), k = pop(); push(k-j); break;   /*Correct Order, Couldn't think of anything else*/
                case '*': push(pop() * pop()); break;
                case '/': j = pop(), k = pop(); push(k/j); break;   /*Correct Order, Couldn't think of anything else*/
                case '=': return stack[--top];
                case ' ': break;
                default:  printf("Invalid Input\n"); exit(EXIT_FAILURE);
            }
        }
    }
}