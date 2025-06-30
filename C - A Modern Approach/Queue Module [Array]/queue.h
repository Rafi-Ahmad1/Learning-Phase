#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef int Item;
typedef struct queue_type *Queue;

Queue create(int size);
void destroy(Queue Q);

void queue_insert(Queue Q, Item i);
Item queue_remove(Queue Q);
Item first_item(const Queue Q);
Item last_item(const Queue Q);

void make_empty(Queue Q);
bool is_empty(const Queue Q);
bool is_full(const Queue Q);

#endif