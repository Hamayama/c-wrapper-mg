struct foo {
    int (*f1)(int a[static 10]);
    int (*f2)(int a[restrict]);
    int (*f3)(int a[const]);
    int (*f4)(int a[volatile]);
};
