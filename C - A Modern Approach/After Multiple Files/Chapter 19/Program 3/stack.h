#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef int Item;
typedef struct stack_type *Stack;

Stack create(void);
void destroy(Stack S);

void push(Stack S, Item i);
Item pop(Stack S);
Item peek(Stack S);

void make_empty(Stack S);
bool is_empty(const Stack S);
int length(const Stack S);

#endif