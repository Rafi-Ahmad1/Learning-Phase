#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

struct stack {
    int number;
    struct stack *next;
};
struct stack *top = NULL;

void make_empty(void) {
    struct stack *temp;
    
    while(top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}
bool is_empty(void) {
    return top == NULL;
}

bool push(int n) {
    struct stack *new_node = malloc(sizeof(struct stack));
    if(new_node == NULL)
        return false;
    
    new_node->number = n;
    new_node->next = top;
    top = new_node;
    return true;
}
int pop(void) {
    struct stack *p = top;
    int n = p->number;

    if (is_empty()) {
        printf("*** Stack underflow; program terminated. ***\n");
        exit(EXIT_FAILURE);
    }
    
    top = top->next;
    free(p);
    return n;
}