#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queueADT.h"

#define QUEUE_SIZE 100

struct queue_type {
    Item contents[QUEUE_SIZE];
    int top;
    int bottom;
};

static void terminate(const char *message) {
    printf("%s", message);
    exit(EXIT_FAILURE);
}

Queue create(void) {
    Queue new_queue;
    new_queue = malloc(sizeof(struct queue_type));
    if(new_queue == NULL)
        terminate("Error Creating Structure, Memory could not be allocated.");

    new_queue->top = 0;
    new_queue->bottom = 0;
    return new_queue;
}
void destroy(Queue Q) {
    free(Q);
}

void queue_insert(Queue Q, Item i) {
    if(is_full(Q))
        terminate("Error, Array is Full.");

    Q->contents[Q->top] = i;
    Q->top = (Q->top + 1) % QUEUE_SIZE;
}
Item queue_remove(Queue Q) {
    if(is_empty(Q))
        terminate("Error, Array already Empty.");

    Item i = Q->contents[Q->bottom];
    Q->bottom = (Q->bottom + 1) % QUEUE_SIZE;
    return i;    
}
Item first_item(const Queue Q) {
    if(is_empty(Q))
        terminate("Error, Arraay is empty.");
    return Q->contents[Q->bottom];
}
Item last_item(const Queue Q) {
    return Q->contents[(Q->top - 1 + QUEUE_SIZE) % QUEUE_SIZE];
}

void make_empty(Queue Q) {
    Q->top = 0;
    Q->bottom = 0;
}
bool is_empty(const Queue Q) {
    return Q->bottom == Q->top;
}
bool is_full(const Queue Q) {
    return (Q->top + 1) % QUEUE_SIZE == Q->bottom;
}