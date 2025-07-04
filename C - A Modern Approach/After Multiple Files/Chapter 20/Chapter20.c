#include <stdio.h>

union {
    float n;
    struct bin {
        unsigned int fraction: 23;
        unsigned int exponent: 8;
        unsigned int sign: 1;
    } IEEE_float;
} access_float;

int main() {
    access_float.IEEE_float.sign = 1;
    access_float.IEEE_float.exponent = 128;
    access_float.IEEE_float.fraction = 0;

    printf("%f", access_float.n);

    return 0;
}