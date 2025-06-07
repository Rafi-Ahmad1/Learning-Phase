#define CUBE(x) ((x)*(x)*(x))
#define REMAINDER(n) ((n)%4)
#define PRODUCT(x,y) (((x)*(y)) < 100? 1: 0)

#define NELMES(a) (((int)sizeof(a))/(sizeof(a[0])))

#define DOUBLE(x) 2*(x)

#define AVG(x,y) (((x) + (y)) / 2)
#define AREA(x,y) ((x) * (y))

#define TOUPPER(c) ('a' <= (c) && (c) <= 'z'? (c) - 'a' + 'A': (c))

#define DISP(f, x) printf(#f "(%g) = %g\n" , x, f(x))

#define GENERIC_MAX(type)         \
type (type)##_max(type x, type y) \
{                                 \
    return x > y ? x : y;         \
}                                 

#define str_helper(x) #x
#define str(x) str_helper(x)
#define LINE_FILE printf("Line" str(__LINE__) " of file " __FILE__)

#define CHECK(x,y,n) ((x) >= 0 && (y) >= 0 && (x) <= ((n)-1) && (y) <= ((n)-1))
#define MEDIAN(x,y,z) \
    ((x) > (y) ? \
        ((x) > (z) ? \
            ((y) > (z) ? \
                (y) : (z)) \
            : (x)) \
        : ((y) > (z) ? \
            ((x) > (z) ? \
                (x) : (z)) \
            : (y)))
#define POLYNOMIAL(x) ((3*(x)*(x)*(x)*(x)*(x)) + (2*(x)*(x)*(x)*(x)) - (5*(x)*(x)*(x)) - ((x)*(x)) + (7*(x)) - 6)

#define ERROR(...) fprintf(stderr, __VA_ARGS__)



#include <stdio.h>

#define N 100

void f(void);

int main(void) {
    f();
    #ifdef N
    #undef N
    #endif 
        return 0;
}

void f(void) {
    #if defined(N)
        printf("N is %d\n", N);
    #else 
        printf("N is undefined\n");
    #endif
}



#ifdef ENGLISH
    printf("Insert Disk 1");
#elif defined(FRENCH)
    printf("Inserez Le Disque 1");
#elif defined(SPANISH)
    printf("Inserte El Disco 1");
#endif

#define IDENT(x) PRAGMA(ident #x)
#define PRAGMA(x) _Pragma(#x)