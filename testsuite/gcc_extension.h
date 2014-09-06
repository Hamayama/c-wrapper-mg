/*
  Unnamed struct/union fields within structs/unions
*/

struct foo {
    int a;
    union {
        float b;
        struct {
            int c;
            double d;
        };
    };
    int e;
    struct {
        int f;
        double g;
    };
};

#define FLOAT_MODE 1
#define STRUCT_MODE 2

extern void inc_foo(struct foo *v, int mode);
