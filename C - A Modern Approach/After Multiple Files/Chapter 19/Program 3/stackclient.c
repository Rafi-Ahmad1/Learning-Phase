#include <stdio.h>
#include "stack.h"

int main() {
    Stack s1, s2;
    int n;
    int i = 1;

    s1 = create();
    s2 = create();

    push(s1, 1);
    printf("Now Length[%d]: %d\n", i++, length(s1));
    push(s1, 2);
    printf("Now Length[%d]: %d\n", i++, length(s1));

    n = pop(s1);
    printf("Popped %d from s1\n", n);
    printf("Now Length[%d]: %d\n", i++, length(s1));

    push(s2, n);
    printf("Now Length[%d]: %d\n", i++, length(s2));

    n = pop(s1);
    printf("Popped %d from s1\n", n);
    printf("Now Length[%d]: %d\n", i++, length(s1));

    push(s2, n);
    printf("Now Length[%d]: %d\n", i++, length(s2));

    destroy(s1);

    while(!is_empty(s2))
        printf("Popped %d from s2\n", pop(s2));

    printf("Now Length[%d]: %d\n", i++, length(s2));
    push(s2, 3);
    printf("Now Length[%d]: %d\n", i++, length(s2));
    make_empty(s2);
    printf("Now Length[%d]: %d\n", i++, length(s2));
    if(is_empty(s2))
        printf("s2 is empty\n");
    else
        printf("s2 is not empty\n");
    
    destroy(s2);
    return 0;
}