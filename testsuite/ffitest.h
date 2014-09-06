/**
 *  ffitest.h
 *  
 *   Copyright (c) 2006 KOGURO, Naoki (naoki@koguro.net)
 *  
 *   Permission is hereby granted, free of charge, to any person 
 *   obtaining a copy of this software and associated 
 *   documentation files (the "Software"), to deal in the 
 *   Software without restriction, including without limitation 
 *   the rights to use, copy, modify, merge, publish, distribute, 
 *   sublicense, and/or sell copies of the Software, and to 
 *   permit persons to whom the Software is furnished to do so, 
 *   subject to the following conditions:
 *  
 *   The above copyright notice and this permission notice shall 
 *   be included in all copies or substantial portions of the 
 *   Software.
 *  
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY 
 *   KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE 
 *   WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR 
 *   PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS 
 *   OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR 
 *   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR 
 *   OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
 *   SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *  
 *   $Id: $
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>

extern char var_char;
extern short var_short;
extern int var_int;
extern long var_long;
extern long long var_longlong;
extern unsigned char var_uchar;
extern unsigned short var_ushort;
extern unsigned int var_uint;
extern unsigned long var_ulong;
extern unsigned long long var_ulonglong;
extern float var_float;
extern double var_double;
extern char *var_string;

extern void test_var(void);

struct test_uchar {
    char dummy;
    unsigned char value;
};

struct test_ushort {
    char dummy;
    unsigned short value;
};

struct test_uint {
    char dummy;
    unsigned int value;
};

struct test_ulong {
    char dummy;
    unsigned long value;
};

struct test_ulonglong {
    char dummy;
    unsigned long long value;
};

struct test_schar {
    char dummy;
    signed char value;
};

struct test_sshort {
    char dummy;
    signed short value;
};

struct test_sint {
    char dummy;
    signed int value;
};

struct test_slong {
    char dummy;
    signed long value;
};

struct test_slonglong {
    char dummy;
    signed long long value;
};

struct test_float {
    char dummy;
    float value;
};

struct test_double {
    char dummy;
    double value;
};

struct test_string {
    char dummy;
    char *value;
};

#define DEFINE_TEST_STRUCT_ARRAY(type, ctype) \
struct test_array_##type { \
    char dummy; \
    ctype value[3]; \
};

//DEFINE_TEST_STRUCT_ARRAY(uchar, unsigned char)

// ***** for debug *****
struct test_array_uchar {
    char dummy;
    unsigned char value[3];
};

DEFINE_TEST_STRUCT_ARRAY(ushort, unsigned short)
DEFINE_TEST_STRUCT_ARRAY(uint, unsigned int)
DEFINE_TEST_STRUCT_ARRAY(ulong, unsigned long)
DEFINE_TEST_STRUCT_ARRAY(ulonglong, unsigned long long)
DEFINE_TEST_STRUCT_ARRAY(schar, signed char)
DEFINE_TEST_STRUCT_ARRAY(sshort, signed short)
DEFINE_TEST_STRUCT_ARRAY(sint, signed int)
DEFINE_TEST_STRUCT_ARRAY(slong, signed long)
DEFINE_TEST_STRUCT_ARRAY(slonglong, signed long long)
DEFINE_TEST_STRUCT_ARRAY(float, float)
DEFINE_TEST_STRUCT_ARRAY(double, double)
DEFINE_TEST_STRUCT_ARRAY(string, char*)

extern struct test_uchar add_struct_uchar(struct test_uchar v1,
                                          struct test_uchar v2);
extern struct test_ushort add_struct_ushort(struct test_ushort v1,
                                            struct test_ushort v2);
extern struct test_uint add_struct_uint(struct test_uint v1,
                                        struct test_uint v2);
extern struct test_ulong add_struct_ulong(struct test_ulong v1,
                                          struct test_ulong v2);
extern struct test_ulonglong add_struct_ulonglong(struct test_ulonglong v1,
                                                  struct test_ulonglong v2);
extern struct test_schar add_struct_schar(struct test_schar v1,
                                          struct test_schar v2);
extern struct test_sshort add_struct_sshort(struct test_sshort v1,
                                            struct test_sshort v2);
extern struct test_sint add_struct_sint(struct test_sint v1,
                                        struct test_sint v2);
extern struct test_slong add_struct_slong(struct test_slong v1,
                                          struct test_slong v2);
extern struct test_slonglong add_struct_slonglong(struct test_slonglong v1,
                                                  struct test_slonglong v2);
extern struct test_float add_struct_float(struct test_float v1,
                                          struct test_float v2);
extern struct test_double add_struct_double(struct test_double v1,
                                            struct test_double v2);
extern struct test_string add_struct_string(struct test_string v1,
                                            struct test_string v2);

#define EXTERN_FUNC_TEST_STRUCT_ARRAY(type) \
extern struct test_array_##type \
add_struct_array_##type(struct test_array_##type v1, \
                        struct test_array_##type v2);

//EXTERN_FUNC_TEST_STRUCT_ARRAY(uchar)

// ***** for debug *****
extern struct test_array_uchar add_struct_array_uchar(struct test_array_uchar v1, struct test_array_uchar v2);

EXTERN_FUNC_TEST_STRUCT_ARRAY(ushort)
EXTERN_FUNC_TEST_STRUCT_ARRAY(uint)
EXTERN_FUNC_TEST_STRUCT_ARRAY(ulong)
EXTERN_FUNC_TEST_STRUCT_ARRAY(ulonglong)
EXTERN_FUNC_TEST_STRUCT_ARRAY(schar)
EXTERN_FUNC_TEST_STRUCT_ARRAY(sshort)
EXTERN_FUNC_TEST_STRUCT_ARRAY(sint)
EXTERN_FUNC_TEST_STRUCT_ARRAY(slong)
EXTERN_FUNC_TEST_STRUCT_ARRAY(slonglong)
EXTERN_FUNC_TEST_STRUCT_ARRAY(float)
EXTERN_FUNC_TEST_STRUCT_ARRAY(double)
EXTERN_FUNC_TEST_STRUCT_ARRAY(string)

extern unsigned char add_uchar(unsigned char v1, unsigned char v2);
extern signed char add_schar(signed char v1, signed char v2);
extern unsigned short add_ushort(unsigned short v1, unsigned short v2);
extern signed short add_sshort(signed short v1, signed short v2);
extern unsigned int add_uint(unsigned int v1, unsigned int v2);
extern signed int add_sint(signed int v1, signed int v2);
extern unsigned long add_ulong(unsigned long v1, unsigned long v2);
extern signed long add_slong(signed long v1, signed long v2);
extern unsigned long long add_ulonglong(unsigned long long v1,
                                        unsigned long long v2);
extern signed long long add_slonglong(signed long long v1, signed long long v2);
extern float add_float(float v1, float v2);
extern double add_double(double v1, double v2);
extern const char *add_string(const char *v1, const char *v2);

extern unsigned char *add_array_uchar(int size, unsigned char v1[],
                                      unsigned char v2[]);
extern signed char *add_array_schar(int size, signed char v1[],
                                    signed char v2[]);
extern unsigned short *add_array_ushort(int size, unsigned short v1[],
                                        unsigned short v2[]);
extern signed short *add_array_sshort(int size, signed short v1[],
                                      signed short v2[]);
extern unsigned int *add_array_uint(int size, unsigned int v1[],
                                    unsigned int v2[]);
extern signed int *add_array_sint(int size, signed int v1[], signed int v2[]);
extern unsigned long *add_array_ulong(int size, unsigned long v1[],
                                      unsigned long v2[]);
extern signed long *add_array_slong(int size, signed long v1[],
                                    signed long v2[]);
extern unsigned long long *add_array_ulonglong(int size, unsigned long long v1[], 
                                               unsigned long long v2[]);
extern signed long long *add_array_slonglong(int size, signed long long v1[], 
                                             signed long long v2[]);
extern float *add_array_float(int size, float v1[], float v2[]);
extern double *add_array_double(int size, double v1[], double v2[]);
extern char **add_array_string(int size, const char *v1[], const char *v2[]);

extern unsigned char callback_uchar(unsigned char (*fn)(unsigned char,
                                                        unsigned char),
                                    unsigned char v1, unsigned char v2);
extern signed char callback_schar(signed char (*)(signed char, signed char),
                                  signed char v1, signed char v2);
extern unsigned short callback_ushort(unsigned short (*fn)(unsigned short, 
                                                           unsigned short),
                                      unsigned short v1, unsigned short v2);
extern signed short callback_sshort(signed short (*fn)(signed short,
                                                       signed short),
                                    signed short v1, signed short v2);
extern unsigned int callback_uint(unsigned int (*fn)(unsigned int, unsigned int),
                                  unsigned int v1, unsigned int v2);
extern signed int callback_sint(signed int (*fn)(signed int, signed int),
                                signed int v1, signed int v2);
extern unsigned long callback_ulong(unsigned long (*fn)(unsigned long,
                                                        unsigned long),
                                    unsigned long v1, unsigned long v2);
extern signed long callback_slong(signed long (*fn)(signed long, signed long),
                                  signed long v1, signed long v2);
extern unsigned long long callback_ulonglong(unsigned long long (*fn)(unsigned long long,
                                                                      unsigned long long),
                                             unsigned long long v1, unsigned long long v2);
extern signed long long callback_slonglong(signed long long (*fn)(signed long long,
                                                                  signed long long),
                                           signed long long v1, signed long long v2);
extern float callback_float(float (*fn)(float, float), float v1, float v2);
extern double callback_double(double (*fn)(double, double), double v1, double v2);
extern const char *callback_string(const char *(*fn)(const char *, const char*),
                                   const char *v1, const char *v2);

#define EXTERN_FUNC_VAARG(type, ctype) extern ctype *vaarg_##type(int nargs, ...);
EXTERN_FUNC_VAARG(uint, unsigned int)
EXTERN_FUNC_VAARG(ulong, unsigned long)
EXTERN_FUNC_VAARG(ulonglong, unsigned long long)
EXTERN_FUNC_VAARG(sint, signed int)
EXTERN_FUNC_VAARG(slong, signed long)
EXTERN_FUNC_VAARG(slonglong, signed long long)
EXTERN_FUNC_VAARG(double, double)
EXTERN_FUNC_VAARG(string, char*)

union test {
    char c;
    short s;
    int i;
    long l;
    long long ll;
    float f;
    double d;
    char *str;
};
#define EXTERN_FUNC_TEST_UNION(name) extern union test test_union_##name(union test v1, union test v2);
EXTERN_FUNC_TEST_UNION(c)
EXTERN_FUNC_TEST_UNION(s)
EXTERN_FUNC_TEST_UNION(i)
EXTERN_FUNC_TEST_UNION(l)
EXTERN_FUNC_TEST_UNION(ll)
EXTERN_FUNC_TEST_UNION(f)
EXTERN_FUNC_TEST_UNION(d)
EXTERN_FUNC_TEST_UNION(str)

extern void test_modify(int *v);

extern int incomplete_array[];

extern int test_null_ptr(void *ptr1);
extern int test_null_func_ptr(int (*fn)(void *ptr));

extern int test_val;

extern int *test_ptr;
extern int test_array[];
extern void init_test_ptr();

#define post_pp(x) ((x)++)
#define post_mm(x) ((x)--)
#define pre_pp(x) (++(x))
#define pre_mm(x) (--(x))
#define plus(x, y) ((x)+(y))
#define minus(x, y) ((x)-(y))

struct bitfield_rec {
    signed v1 : 3;
    unsigned v2 : 3;
    signed dummy1 : 30;
    unsigned v3 : 2;
    signed v4 : 16;
    float dummy2;
    unsigned : 4;
    unsigned v5 : 3;
};
extern struct bitfield_rec test_bitfield(struct bitfield_rec dat);

struct bitfield_rec2 {
    void *p;
    short s;
    unsigned int v1 : 14;
    unsigned int v2 : 2;
};
extern int expected_sizeof_bitfield_rec2();
extern struct bitfield_rec2 test_bitfield2(struct bitfield_rec2 dat);

#define IFMAC(test,then_expr,else_expr) ((test)?(then_expr):(else_expr))

#define FUNCLIKE_MACRO_USING_TYPE_PARAM(type) ((int (*)(const type *)) foo())

/* test funcations for inline function */
inline int return_const()
{
    return 1;
}

inline char *return_string()
{
    return "foo";
}

inline int ref_array(int a[])
{
    return a[1];
}

inline void funccall1()
{
    init_test_ptr();
}

inline int funcall2(int a, int b)
{
    return add_sint(a, b);
}

inline int ref_struct1()
{
    struct test_sint a;
    a.value = 1;
    return a.value;
}

inline int ref_struct2(struct test_sint *p)
{
    return p->value;
}

inline int post_inc()
{
    int a = 1;
    a++;
    return a;
}

inline int post_dec()
{
    int a = 2;
    a--;
    return a;
}

inline int pre_inc()
{
    int a = 1;
    return ++a;
}

inline int pre_dec()
{
    int a = 2;
    return --a;
}

inline int unary_plus()
{
    return +1;
}

inline int unary_minus()
{
    return -1;
}

inline int unary_logneg(int a)
{
    return !a;
}

inline int unary_bitneg(int a)
{
    return ~a;
}

inline int unary_ref()
{
    int a;
    sscanf("123", "%d", &a);
    return a;
}

inline int *unary_deref()
{
    void *p0 = (int*) malloc(sizeof(int));
    int *p = (int*)p0;
    *p = 456;
    return p;
}

inline long op_sizeof()
{
    return sizeof(int);
}

inline int mul(int a, int b)
{
    return a*b;
}

inline int divi(int a, int b)
{
    return a/b;
}

inline int mod(int a, int b)
{
    return a%b;
}

inline int add(int a, int b)
{
    return a+b;
}

inline int sub(int a, int b)
{
    return a-b;
}

inline int left_shift(int a, int b)
{
    return a<<b;
}

inline int right_shift(int a, int b)
{
    return a>>b;
}

inline int op_lt(int a, int b)
{
    if (a<b) {
        return 1;
    } else 
        return 0;
}

inline int op_gt(int a, int b)
{
    if (a>b)
        return 1;
    else {
        return 0;
    }
}

inline int op_lteq(int a, int b)
{
    if (a<=b)
        return 1;
    else 
        return 0;
}

inline int op_gteq(int a, int b)
{
    if (a>=b) {
        return 1;
    } else {
        return 0;
    }
}

inline int op_eq(int a, int b)
{
    if (a==b) {
        return 1;
    } else {
        return 0;
    }
}

inline int op_noteq(int a, int b)
{
    if (a!=b) {
        return 1;
    } else {
        return 0;
    }
}

inline int bitand(int a, int b)
{
    return a&b;
}

inline int bitxor(int a, int b)
{
    return a ^ b;
}

inline int bitor(int a, int b)
{
    return a | b;
}

inline int op_logand(int a, int b, int c)
{
    if ((a == b) && (b == c)) {
        return 1;
    } else {
        return 0;
    }
}

inline int op_logor(int a, int b, int c)
{
    return ((a == b) || (b == c))?1:0;
}

inline int assign_mul(int a, int b)
{
    a *= b;
    return a;
}

inline int assign_div(int a, int b)
{
    a /= b;
    return a;
}

inline int assign_mod(int a, int b)
{
    a %= b;
    return a;
}

inline int assign_add(int a, int b)
{
    a += b;
    return a;
}

inline int assign_sub(int a, int b)
{
    a -= b;
    return a;
}

inline int assign_left_shift(int a, int b)
{
    a <<= b;
    return a;
}

inline int assign_right_shift(int a, int b)
{
    a >>= b;
    return a;
}

inline int assign_bitand(int a, int b)
{
    a &= b;
    return a;
}

inline int assign_bitor(int a, int b)
{
    a |= b;
    return a;
}

inline int assign_bitxor(int a, int b)
{
    a ^= b;
    return a;
}

inline int multi_expr(int a, int b)
{
    return (a + b), (a - b), (a * b);
}

inline int test_while()
{
    int i = 1;
    int sum = 0;
    while (i <= 10) {
        sum += i;
        ++i;
    }
    return sum;
}

inline int test_while_break()
{
    int i = 1;
    int sum = 0;
    while (1) {
        sum += i;
        ++i;
        if (i > 10) break;
    }
    return sum;
}

inline int test_while_continue()
{
    int i = -10;
    int sum = 0;
    while (i < 10) {
        if (i++ < 0) {
            continue;
        }
        sum += i;
    }
    return sum;
}

inline int test_dowhile()
{
    int i = 1;
    int sum = 0;
    do {
        sum += i++;
    } while (i <= 10);
    return sum;
}

inline int test_dowhile_break()
{
    int i = 1;
    int sum = 0;
    do {
        sum += i++;
        if (i > 10) break;
    } while (1);
    return sum;
}

inline int test_dowhile_continue()
{
    int i = -10;
    int sum = 0;
    do {
        if (++i <= 0) {
            continue;
        }
        sum += i;
    } while ((0 < i) && (i < 10));
    return sum;
}

inline int test_for()
{
    int i;
    int sum;
    for (i = 0, sum = 0; i <= 10; ++i) {
        sum += i;
    }
    return sum;
}

inline int test_for_noinit_notest_noupdate()
{
    int i = 0, sum = 0;
    for (;;) {
        sum += ++i;
        if (10 <= i) break;
    }
    return sum;
}

inline int test_for_noinit_notest()
{
    int i = 0, sum = 0;
    for (;;sum += ++i) {
        if (10 <= i) break;
    }
    return sum;
}

inline int test_for_noinit_noupdate()
{
    int i = 0, sum = 0;
    for (;i < 10;) {
        sum += ++i;
    }
    return sum;
}

inline int test_for_noinit()
{
    int i = 0, sum = 0;
    for (;i < 10; sum += ++i);
    return sum;
}

inline int test_for_notest_noupdate()
{
    int i, sum;
    for (i = 0, sum = 0;;) {
        sum += ++i;
        if (10 <= i) break;
    }
    return sum;
}

inline int test_for_notest()
{
    int i, sum;
    for (i = 0, sum = 0;;sum += ++i) {
        if (10 <= i) break;
    }
    return sum;
}

inline int test_for_noupdate()
{
    int i, sum;
    for (i = sum = 0;i < 10;) {
        sum += ++i;
    }
    return sum;
}

inline intptr_t offset_calc()
{
    return (intptr_t) &(((struct test_uchar*)0)->value);
}

inline void not_supported(int a)
{
    switch (a) {
    case 1:
        break;
    default:
        break;
    }
}
    
/* 
   ISO/IEC 9899:1999 6.7.5.3
   a declaration of a parameter as ``function returning type'' shall be
   adjusted to ``pointer to function returning type''
*/
extern char *param_func_test(void *allocator(size_t));

typedef signed int (*sint_adder)(signed int v1, signed int v2);
extern sint_adder get_fptr();

/*
  variable attribute 'mode'
*/

extern int test_qi __attribute__((__mode__(__QI__)));
extern int test_hi __attribute__((__mode__(__HI__)));
extern int test_si __attribute__((__mode__(__SI__)));
extern int test_di __attribute__((__mode__(__DI__)));
extern unsigned int test_uqi __attribute__((__mode__(__QI__))) ,
    test_uhi __attribute__((__mode__(__HI__))) ,
    test_usi __attribute__((__mode__(__SI__))) ,
    test_udi __attribute__((__mode__(__DI__)));
extern float test_sf __attribute__((__mode__(__SF__)));
extern float test_df __attribute__((__mode__(__DF__)));

struct test_attr_mode_rec {
    int test_qi __attribute__((__mode__(__QI__)));
    int test_hi __attribute__((__mode__(__HI__)));
    int test_si __attribute__((__mode__(__SI__)));
    int test_di __attribute__((__mode__(__DI__)));
    unsigned int test_uqi __attribute__((__mode__(__QI__))) ,
        test_uhi __attribute__((__mode__(__HI__))) ,
        test_usi __attribute__((__mode__(__SI__))) ,
        test_udi __attribute__((__mode__(__DI__)));
    float test_sf __attribute__((__mode__(__SF__)));
    float test_df __attribute__((__mode__(__DF__)));
};

extern void test_attr_mode(int qi __attribute__((__mode__(__QI__))),
                           int hi __attribute__((__mode__(__HI__))),
                           int si __attribute__((__mode__(__SI__))),
                           int di __attribute__((__mode__(__DI__))),
                           unsigned int uqi __attribute__((__mode__(__QI__))),
                           unsigned int uhi __attribute__((__mode__(__HI__))),
                           unsigned int usi __attribute__((__mode__(__SI__))),
                           unsigned int udi __attribute__((__mode__(__DI__))),
                           float sf __attribute__((__mode__(__SF__))),
                           float df __attribute__((__mode__(__DF__))));

#define COUNTER counter()
extern int counter();
extern void reset_counter();

/*
  Tricky code about function-like macro
*/
extern int confusing_func1(int a, int b);
#define confusing_func1(a, b) ((a)-(b))

inline int confusing_func2(int a, int b)
{
    return (confusing_func1)(a, b);
}

