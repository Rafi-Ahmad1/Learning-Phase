#include <stdio.h>
#include "queueADT.h"

int main() {
    Queue q1, q2;
    int n;

    q1 = create();
    q2 = create();
    
    queue_insert(q1, 5);
    queue_insert(q1, 3);
    n = queue_remove(q1);
    printf("Popped %d from q1\n", n);

    queue_insert(q2, n);
    printf("First Item of q1: %d\n", first_item(q1));
    printf("Last Item of q2: %d\n", last_item(q2));
    
    destroy(q1);
    
    queue_insert(q2, 20);
    make_empty(q2);
    if(is_empty(q2))
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");

    destroy(q2);
    return 0;
}