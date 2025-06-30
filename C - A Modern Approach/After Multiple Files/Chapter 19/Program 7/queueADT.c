#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queueADT.h"

struct node {
    Item content;
    struct node *next;
};
struct queue_type {
    struct node *top;
    struct node *bottom;
    int size;
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

    new_queue->top = NULL;
    new_queue->bottom = new_queue->top;
    new_queue->size = 0;
    return new_queue;
}
void destroy(Queue Q) {
    make_empty(Q);
    free(Q);
}

void queue_insert(Queue Q, Item i) {
    struct node *new_node = malloc(sizeof(struct node));
    if(new_node == NULL)
        terminate("Error Creating New Node, Memory allocation failed.");

    /*Case 1: If the Queue is Empty, new_node is added at the bottom, As this is the first node*/
    if(Q->size == 0) {
        new_node->content = i;
        new_node->next = Q->top;
        Q->bottom = new_node;
        Q->top = Q->bottom;
        Q->size++;
        return;
    }
    /*Case 2: In any other case the bottom remains the same and new_node is added at the top*/
    new_node->content = i;
    new_node->next = Q->top;
    Q->top = new_node;
    Q->size++;
}
Item queue_remove(Queue Q) {
    if(is_empty(Q))
        terminate("Error, Array already Empty.");

    struct node *prev, *cur;
    Item i = Q->bottom->content;

    for(cur = Q->top, prev = NULL;
        cur != NULL && cur != Q->bottom;
        prev = cur, cur = cur->next)
    ;

    Q->bottom = prev;
    free(cur);
    Q->size--;
    return i;
}
Item first_item(const Queue Q) {
    if(is_empty(Q))
        terminate("Error, Arraay is empty.");
    return Q->bottom->content;
}
Item last_item(const Queue Q) {
    return Q->top->content;
}

void make_empty(Queue Q) {
    struct node *old_top = Q->top;
    while (old_top != Q->bottom){
        Q->top = Q->top->next;
        free(old_top);
        old_top = Q->top;
    }
    free(old_top);
    Q->top = NULL;
    Q->bottom = Q->top;
    Q->size = 0;
}
bool is_empty(const Queue Q) {
    return Q->size == 0;
}