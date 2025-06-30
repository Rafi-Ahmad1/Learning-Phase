#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queueADT.h"

struct queue_type {
    Item *contents;
    int top;
    int bottom;
    int size;
};

static void terminate(const char *message) {
    printf("%s", message);
    exit(EXIT_FAILURE);
}

Queue create(int size) {
    Queue new_queue;
    new_queue = malloc(sizeof(struct queue_type));
    if(new_queue == NULL)
        terminate("Error Creating Structure, Memory could not be allocated.");

    new_queue->contents = malloc(size * sizeof(Item));
    if(new_queue->contents == NULL)
        terminate("Error Creating Queue, Memory could not be allocated.");

    new_queue->size = size;
    new_queue->top = 0;
    new_queue->bottom = 0;
    return new_queue;
}
void destroy(Queue Q) {
    free(Q->contents);
    free(Q);
}

void queue_insert(Queue Q, Item i) {
    if(is_full(Q))
        terminate("Error, Array is Full.");

    Q->contents[Q->top] = i;
    Q->top = (Q->top + 1) % Q->size;
}
Item queue_remove(Queue Q) {
    if(is_empty(Q))
        terminate("Error, Array already Empty.");

    Item i = Q->contents[Q->bottom];
    Q->bottom = (Q->bottom + 1) % Q->size;
    return i;    
}
Item first_item(const Queue Q) {
    if(is_empty(Q))
        terminate("Error, Arraay is empty.");
    return Q->contents[Q->bottom];
}
Item last_item(const Queue Q) {
    return Q->contents[(Q->top - 1 + Q->size) % Q->size];
}

void make_empty(Queue Q) {
    Q->top = 0;
    Q->bottom = 0;
}
bool is_empty(const Queue Q) {
    return Q->bottom == Q->top;
}
bool is_full(const Queue Q) {
    return (Q->top + 1) % Q->size == Q->bottom;
}