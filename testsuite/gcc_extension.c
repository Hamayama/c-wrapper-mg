#include "gcc_extension.h"

void inc_foo(struct foo *v, int mode)
{
    ++(v->a);
    switch (mode) {
    case FLOAT_MODE:
        ++(v->b);
        break;
    case STRUCT_MODE:
        ++(v->c);
        ++(v->d);
        break;
    default:
        break;
    }
    ++(v->e);
    ++(v->f);
    ++(v->g);
}
