#include <stdio.h>
#include <stddef.h>

struct s{
    int a;
    char b;
    float c;
};

int main() {
    struct s test;
    
    printf("The size of member a of structure: %d\n", sizeof(test.a));
    printf("The size of member b of structure: %d\n", sizeof(test.b));
    printf("The size of member c of structure: %d\n", sizeof(test.c));

    printf("\nThe size of the structure: %d\n\n", sizeof(struct s));

    printf("The offset of member a of structure: %d\n", offsetof(struct s, a));
    printf("The offset of member a of structure: %d\n", offsetof(struct s, b));
    printf("The offset of member a of structure: %d\n", offsetof(struct s, c));

    return 0;
}