// typedef char (func)(int);
// typedef func *arr[10];

// char (*x[10])(int);
// arr x;



// typedef int arr[5];
// typedef arr *func(int);

// int (*x(int))[5];
// func x;



// typedef float *func1(int);
// typedef func1 *func2(void);

// float *(*x(void))(int);
// func2 x;



// typedef void func1(int);
// typedef func1 *func2(int , void (*y)(int));

// void (*x(int, void (*y)(int)))(int);
// func2 x;



// char *(*p)(char *);
// void (*f(struct t *p, long int n))(void);
// void (*a[4])(void) = {insert, search, update, print};
// struct t (*b[10])(int, int);