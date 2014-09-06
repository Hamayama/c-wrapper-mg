typedef int foo;

typedef struct {
    void (*foo)(void *);
} bar;

inline void *get_foo1(bar a) {
    return a.foo;
}

inline void *get_foo2(bar *a) {
    return a->foo;
}
