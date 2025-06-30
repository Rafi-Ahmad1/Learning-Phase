#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

struct node {
    Item content;
    struct node *next;
};
struct stack_type {
    struct node *top;
    int len;
};

static void terminate(const char *message) {
    printf("%s", message);
    exit(EXIT_FAILURE);
}

Stack create(void) {
    Stack new_stack = malloc(sizeof(struct stack_type));
    if(new_stack == NULL)
        terminate("Error Creating Stack, Memory could not be allocated.");
    
    new_stack->top = NULL;
    new_stack->len = 0;
    return new_stack;
}
void destroy(Stack S) {
    make_empty(S);
    free(S);
}

void push(Stack S, Item i) {
    struct node  *new_node = malloc(sizeof(struct node));
    if(new_node == NULL)
        terminate("Error, Memory allocation failed");

    new_node->content = i;
    new_node->next = S->top;
    S->top = new_node;
    S->len++;
}
Item pop(Stack S) {
    if(is_empty(S))
        terminate("Error, Stack is empty.");

    struct node *old_node = S->top;
    Item i = S->top->content;
    S->top = S->top->next;
    S->len--;
    free(old_node);
    return i;
}
Item peek(Stack S) {
    if(is_empty(S))
        terminate("Error, Stack is Empty.");
    return S->top->content;
}

void make_empty(Stack S) {
    while(S->top != NULL) {
        struct node *old_node = S->top;
        S->top = S->top->next;
        free(old_node);
    }
    S->len = 0;
}
bool is_empty(const Stack S) {
    return S->top == NULL;
}
int length(const Stack S) {
    return S->len;
}