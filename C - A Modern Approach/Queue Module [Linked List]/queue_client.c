#include <stdio.h>
#include "queue.h"

int main() {
    Queue Q;
    Q = create();
    
    queue_insert(Q, 5);
    queue_insert(Q, 3);
    queue_insert(Q, 10);
    Item i = queue_remove(Q);

    Item first = first_item(Q);
    Item last = last_item(Q);

    
    printf("%d\n%d\n%d\n", i, first, last);
    destroy(Q);
    return 0;
}