#include <stdlib.h>
#include "fptr_array.h"

static int testfunc1()
{
    return 3;
}

static char *testfunc2(int *p)
{
    char *c = (char*) malloc(sizeof(char));
    *c = (char) (0xff & *p);
    return c;
}

void fptr_array_set(struct foo *s)
{
    s->fptr_array[1] = testfunc1;
    s->c[3] = testfunc2;
}

int *fptr_array_test(struct foo *s, int *p)
{
    int *results = (int*) malloc(sizeof(int) * 2);
    results[0] = (s->fptr_array[1])();
    results[1] = (int) (*(s->c[3])(p));
    return results;
}

