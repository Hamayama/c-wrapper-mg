struct foo {
    int (*fptr_array[3]) (void);
    char *(*c[10])(int *p);
};

extern void fptr_array_set(struct foo *s);
extern int *fptr_array_test(struct foo *s, int *p);
