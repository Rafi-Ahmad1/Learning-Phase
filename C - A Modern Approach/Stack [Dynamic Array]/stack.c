#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

#define STACK_SIZE 100

struct stack_type {
    Item *contents;
    int top;
    int size;
};

static void terminate(const char *message) {
    printf("%s", message);
    exit(EXIT_FAILURE);
}

Stack create(void) {
    Stack new_stack;
    new_stack = malloc(sizeof(struct stack_type));
    if(new_stack == NULL)
        terminate("Error Creating Stack, Memory could not be allocated.");
    
    new_stack->contents = malloc(STACK_SIZE * sizeof(Item));
    if(new_stack->contents == NULL)
        terminate("Error Dynamically allocating array.");
    
    new_stack->top = 0;
    new_stack->size = STACK_SIZE;
    return new_stack;
}
void destroy(Stack S) {
    free(S->contents);
    free(S);
}

void push(Stack S, Item i) {
    if(is_full(S)) {
        Item *updated_stack = realloc(S->contents, 2 * S->size * sizeof(Item));
        if(updated_stack != NULL) {
            S->contents = updated_stack;
            S->size *= 2;
        }
        else
            terminate("Error, Realloc Failed.");
    }

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
    return S->top == S->size;
}