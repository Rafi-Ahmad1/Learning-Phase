#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

#define STACK_SIZE 100

struct stack_type {
    Item contents[STACK_SIZE];
    int top;
};

static void terminate(const char *message) {
    printf("%s", message);
    exit(EXIT_FAILURE);
}

Stack create(void) {
    Stack new_stack = malloc(sizeof(struct stack_type));
    if(new_stack == NULL)
        terminate("Error Creating Stack, Memory could not be allocated.");
    
    new_stack->top = 0;
    return new_stack;
}
void destroy(Stack S) {
    free(S);
}

void push(Stack S, Item i) {
    if(is_full(S))
        terminate("Error, Stack is full");

    S->contents[S->top++] = i;
}
Item pop(Stack S) {
    if(is_empty(S))
        terminate("Error, Stack is empty.");

    return S->contents[--S->top];
}
Item peek(Stack S) {
    if(is_empty(S))
        terminate("Error, Stack is Empty.");
    return S->contents[S->top - 1];
}

void make_empty(Stack S) {
    S->top = 0;
}
bool is_empty(const Stack S) {
    return S->top == 0;
}
bool is_full(const Stack S) {
    return S->top == STACK_SIZE;
}