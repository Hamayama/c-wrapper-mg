#include "test_func.h"

void func_void()
{
    return;
}

int func_int_int(int a)
{
    return a;
}

double func_double_int(int a)
{
    return a * 2.5;
}

double func_double_double(double a)
{
    return a;
}

void func_intx32(int  v0, int  v1, int  v2, int  v3, int  v4, int  v5, int  v6, int  v7, int  v8, int  v9,
                 int v10, int v11, int v12, int v13, int v14, int v15, int v16, int v17, int v18, int v19,
                 int v20, int v21, int v22, int v23, int v24, int v25, int v26, int v27, int v28, int v29,
                 int v30, int v31)
{
    return;
}

void func_var(int a, ...)
{
    return;
}

#ifdef USE_STUB
extern void Scm_Init_test_funclib(ScmModule*);

ScmObj Scm_Init_test_func(void)
{
    ScmModule *mod;

    SCM_INIT_EXTENSION(test_func);

    mod = SCM_MODULE(SCM_FIND_MODULE("test_func", TRUE));

    Scm_Init_test_funclib(mod);
}
#endif

