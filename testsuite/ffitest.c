/**
 *  ffitest.c
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

#include "ffitest.h"

char var_char;
short var_short;
int var_int;
long var_long;
long long var_longlong;
unsigned char var_uchar;
unsigned short var_ushort;
unsigned int var_uint;
unsigned long var_ulong;
unsigned long long var_ulonglong;
float var_float;
double var_double;
char *var_string;

int incomplete_array[3] = {1, -2, 123};

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

void test_attr_mode(int qi __attribute__((__mode__(__QI__))),
                    int hi __attribute__((__mode__(__HI__))),
                    int si __attribute__((__mode__(__SI__))),
                    int di __attribute__((__mode__(__DI__))),
                    unsigned int uqi __attribute__((__mode__(__QI__))),
                    unsigned int uhi __attribute__((__mode__(__HI__))),
                    unsigned int usi __attribute__((__mode__(__SI__))),
                    unsigned int udi __attribute__((__mode__(__DI__))),
                    float sf __attribute__((__mode__(__SF__))),
                    float df __attribute__((__mode__(__DF__))))
{
    test_qi = qi;
    test_hi = hi;
    test_si = si;
    test_di = di;
    test_uqi = uqi;
    test_uhi = uhi;
    test_usi = usi;
    test_udi = udi;
    test_sf = sf;
    test_df = df;
}

unsigned char add_uchar(unsigned char v1, unsigned char v2)
{
    return v1 + v2;
}

signed char add_schar(signed char v1, signed char v2)
{
    return v1 + v2;
}

unsigned short add_ushort(unsigned short v1, unsigned short v2)
{
    return v1 + v2;
}

signed short add_sshort(signed short v1, signed short v2)
{
    return v1 + v2;
}

unsigned int add_uint(unsigned int v1, unsigned int v2)
{
    return v1 + v2;
}

signed int add_sint(signed int v1, signed int v2)
{
    return v1 + v2;
}

unsigned long add_ulong(unsigned long v1, unsigned long v2)
{
    return v1 + v2;
}

signed long add_slong(signed long v1, signed long v2)
{
    return v1 + v2;
}

unsigned long long add_ulonglong(unsigned long long v1, unsigned long long v2)
{
    return v1 + v2;
}

signed long long add_slonglong(signed long long v1, signed long long v2)
{
    return v1 + v2;
}

float add_float(float v1, float v2)
{
    return v1 + v2;
}

double add_double(double v1, double v2)
{
    return v1 + v2;
}

const char *add_string(const char *v1, const char *v2)
{
    /* memory leaks */
    char *result = (char*) malloc(strlen(v1) + strlen(v2) + 1);
    strcpy(result, v1);
    strcat(result, v2);

    return result;
}

unsigned char *add_array_uchar(int size, unsigned char v1[], unsigned char v2[])
{
    /* memory leaks */
    unsigned char *result = (unsigned char*) malloc(size * sizeof(unsigned char));
    int i;

    for (i = 0; i < size; ++i) {
        result[i] = v1[i] + v2[i];
    }
    return result;
}

signed char *add_array_schar(int size, signed char v1[], signed char v2[])
{
    /* memory leaks */
    signed char *result = (signed char*) malloc(size * sizeof(signed char));
    int i;

    for (i = 0; i < size; ++i) {
        result[i] = v1[i] + v2[i];
    }
    return result;
}

unsigned short *add_array_ushort(int size, unsigned short v1[], unsigned short v2[])
{
    /* memory leaks */
    unsigned short *result = (unsigned short*) malloc(size * sizeof(unsigned short));
    int i;

    for (i = 0; i < size; ++i) {
        result[i] = v1[i] + v2[i];
    }
    return result;
}

signed short *add_array_sshort(int size, signed short v1[], signed short v2[])
{
    /* memory leaks */
    signed short *result = (signed short*) malloc(size * sizeof(signed short));
    int i;

    for (i = 0; i < size; ++i) {
        result[i] = v1[i] + v2[i];
    }
    return result;
}

unsigned int *add_array_uint(int size, unsigned int v1[], unsigned int v2[])
{
    /* memory leaks */
    unsigned int *result = (unsigned int*) malloc(size * sizeof(unsigned int));
    int i;

    for (i = 0; i < size; ++i) {
        result[i] = v1[i] + v2[i];
    }
    return result;
}

signed int *add_array_sint(int size, signed int v1[], signed int v2[])
{
    /* memory leaks */
    signed int *result = (signed int*) malloc(size * sizeof(signed int));
    int i;

    for (i = 0; i < size; ++i) {
        result[i] = v1[i] + v2[i];
    }
    return result;
}

unsigned long *add_array_ulong(int size, unsigned long v1[], unsigned long v2[])
{
    /* memory leaks */
    unsigned long *result = (unsigned long*) malloc(size * sizeof(unsigned long));
    int i;

    for (i = 0; i < size; ++i) {
        result[i] = v1[i] + v2[i];
    }
    return result;
}

signed long *add_array_slong(int size, signed long v1[], signed long v2[])
{
    /* memory leaks */
    signed long *result = (signed long*) malloc(size * sizeof(signed long));
    int i;

    for (i = 0; i < size; ++i) {
        result[i] = v1[i] + v2[i];
    }
    return result;
}

unsigned long long *add_array_ulonglong(int size, unsigned long long v1[], 
                                        unsigned long long v2[])
{
    /* memory leaks */
    unsigned long long *result 
        = (unsigned long long*) malloc(size * sizeof(unsigned long long));
    int i;

    for (i = 0; i < size; ++i) {
        result[i] = v1[i] + v2[i];
    }
    return result;
}

signed long long *add_array_slonglong(int size, signed long long v1[], 
                                      signed long long v2[])
{
    /* memory leaks */
    signed long long *result 
        = (signed long long*) malloc(size * sizeof(signed long long));
    int i;

    for (i = 0; i < size; ++i) {
        result[i] = v1[i] + v2[i];
    }
    return result;
}

float *add_array_float(int size, float v1[], float v2[])
{
    /* memory leaks */
    float *result = (float*) malloc(size * sizeof(float));
    int i;

    for (i = 0; i < size; ++i) {
        result[i] = v1[i] + v2[i];
    }
    return result;
}

double *add_array_double(int size, double v1[], double v2[])
{
    /* memory leaks */
    double *result = (double*) malloc(size * sizeof(double));
    int i;

    for (i = 0; i < size; ++i) {
        result[i] = v1[i] + v2[i];
    }
    return result;
}

char **add_array_string(int size, const char *v1[], const char *v2[])
{
    /* memory leaks */
    char **result = (char**) malloc(size * sizeof(const char*));
    int i;

    for (i = 0; i < size; ++i) {
        result[i] = (char*) malloc(strlen(v1[i]) + strlen(v2[i]) + 1);
        strcpy(result[i], v1[i]);
        strcat(result[i], v2[i]);
    }
    return result;
}

unsigned char callback_uchar(unsigned char (*fn)(unsigned char, unsigned char),
                             unsigned char v1, unsigned char v2)
{
    return fn(v1, v2);
}

signed char callback_schar(signed char (*fn)(signed char, signed char),
                           signed char v1, signed char v2)
{
    return fn(v1, v2);
}

unsigned short callback_ushort(unsigned short (*fn)(unsigned short, 
                                                    unsigned short),
                             unsigned short v1, unsigned short v2)
{
    return fn(v1, v2);
}

signed short callback_sshort(signed short (*fn)(signed short, signed short),
                           signed short v1, signed short v2)
{
    return fn(v1, v2);
}

unsigned int callback_uint(unsigned int (*fn)(unsigned int, unsigned int),
                           unsigned int v1, unsigned int v2)
{
    return fn(v1, v2);
}

signed int callback_sint(signed int (*fn)(signed int, signed int),
                         signed int v1, signed int v2)
{
    return fn(v1, v2);
}

unsigned long callback_ulong(unsigned long (*fn)(unsigned long, unsigned long),
                             unsigned long v1, unsigned long v2)
{
    return fn(v1, v2);
}

signed long callback_slong(signed long (*fn)(signed long, signed long),
                           signed long v1, signed long v2)
{
    return fn(v1, v2);
}

unsigned long long callback_ulonglong(unsigned long long (*fn)(unsigned long long,
                                                               unsigned long long),
                                      unsigned long long v1, unsigned long long v2)
{
    return fn(v1, v2);
}

signed long long callback_slonglong(signed long long (*fn)(signed long long,
                                                           signed long long),
                                    signed long long v1, signed long long v2)
{
    return fn(v1, v2);
}

float callback_float(float (*fn)(float, float), float v1, float v2)
{
    return fn(v1, v2);
}

double callback_double(double (*fn)(double, double), double v1, double v2)
{
    return fn(v1, v2);
}

const char *callback_string(const char *(*fn)(const char *, const char*),
                            const char *v1, const char *v2)
{                               
    return fn(v1, v2);
}

#define DEFINE_FUNC_VAARG(type, ctype) \
ctype *vaarg_##type(int nargs, ...) \
{ \
    va_list argp; \
    ctype *result = (ctype*) malloc(sizeof(ctype) * nargs); \
    int i; \
    va_start(argp, nargs); \
    for (i = 0; i < nargs; ++i) { \
        result[i] = va_arg(argp, ctype); \
    } \
    va_end(argp); \
    return result;\
}

DEFINE_FUNC_VAARG(uint, unsigned int)
DEFINE_FUNC_VAARG(ulong, unsigned long)
DEFINE_FUNC_VAARG(ulonglong, unsigned long long)
DEFINE_FUNC_VAARG(sint, signed int)
DEFINE_FUNC_VAARG(slong, signed long)
DEFINE_FUNC_VAARG(slonglong, signed long long)
DEFINE_FUNC_VAARG(double, double)
DEFINE_FUNC_VAARG(string, char*)

struct test_uchar add_struct_uchar(struct test_uchar v1, struct test_uchar v2)
{
    struct test_uchar result = {0, 1};
    
    result.value = v1.value + v2.value;

    return result;
}

struct test_ushort add_struct_ushort(struct test_ushort v1, struct test_ushort v2)
{
    struct test_ushort result;

    result.value = v1.value + v2.value;

    return result;
}

struct test_uint add_struct_uint(struct test_uint v1, struct test_uint v2)
{
    struct test_uint result;

    result.value = v1.value + v2.value;

    return result;
}

struct test_ulong add_struct_ulong(struct test_ulong v1, struct test_ulong v2)
{
    struct test_ulong result;

    result.value = v1.value + v2.value;

    return result;
}

struct test_ulonglong add_struct_ulonglong(struct test_ulonglong v1,
                                           struct test_ulonglong v2)
{
    struct test_ulonglong result;

    result.value = v1.value + v2.value;

    return result;
}

struct test_schar add_struct_schar(struct test_schar v1, struct test_schar v2)
{
    struct test_schar result;

    result.value = v1.value + v2.value;

    return result;
}

struct test_sshort add_struct_sshort(struct test_sshort v1, struct test_sshort v2)
{
    struct test_sshort result;

    result.value = v1.value + v2.value;

    return result;
}

struct test_sint add_struct_sint(struct test_sint v1, struct test_sint v2)
{
    struct test_sint result;

    result.value = v1.value + v2.value;

    return result;
}

struct test_slong add_struct_slong(struct test_slong v1, struct test_slong v2)
{
    struct test_slong result;

    result.value = v1.value + v2.value;

    return result;
}

struct test_slonglong add_struct_slonglong(struct test_slonglong v1,
                                           struct test_slonglong v2)
{
    struct test_slonglong result;

    result.value = v1.value + v2.value;

    return result;
}

struct test_float add_struct_float(struct test_float v1, struct test_float v2)
{
    struct test_float result;

    result.value = v1.value + v2.value;

    return result;
}

struct test_double add_struct_double(struct test_double v1, struct test_double v2)
{
    struct test_double result;

    result.value = v1.value + v2.value;

    return result;
}

struct test_string add_struct_string(struct test_string v1, struct test_string v2)
{
    struct test_string result;

    /* memoery leaks */
    result.value = (char*) malloc(strlen(v1.value) + strlen(v2.value) + 1);
    strcpy(result.value, v1.value);
    strcat(result.value, v2.value);

    return result;
}

#define DEFINE_FUNC_TEST_STRUCT_ARRAY(type, ctype) \
struct test_array_##type add_struct_array_##type(struct test_array_##type v1, \
                                                 struct test_array_##type v2) \
{ \
    struct test_array_##type result; \
    int i; \
    for (i = 0; i < sizeof(result.value) / sizeof(ctype); ++i) { \
        result.value[i] = v1.value[i] + v2.value[i]; \
    } \
    return result; \
}

DEFINE_FUNC_TEST_STRUCT_ARRAY(uchar, unsigned char)
DEFINE_FUNC_TEST_STRUCT_ARRAY(ushort, unsigned short)
DEFINE_FUNC_TEST_STRUCT_ARRAY(uint, unsigned int)
DEFINE_FUNC_TEST_STRUCT_ARRAY(ulong, unsigned long)
DEFINE_FUNC_TEST_STRUCT_ARRAY(ulonglong, unsigned long long)
DEFINE_FUNC_TEST_STRUCT_ARRAY(schar, signed char)
DEFINE_FUNC_TEST_STRUCT_ARRAY(sshort, signed short)
DEFINE_FUNC_TEST_STRUCT_ARRAY(sint, signed int)
DEFINE_FUNC_TEST_STRUCT_ARRAY(slong, signed long)
DEFINE_FUNC_TEST_STRUCT_ARRAY(slonglong, signed long long)
DEFINE_FUNC_TEST_STRUCT_ARRAY(float, float)
DEFINE_FUNC_TEST_STRUCT_ARRAY(double, double)
struct test_array_string add_struct_array_string(struct test_array_string v1,
                                                 struct test_array_string v2)
{
    struct test_array_string result;
    int i;

    for (i = 0; i < sizeof(result.value) / sizeof(char*); ++i) {
        /* memoery leaks */
        result.value[i]
            = (char*) malloc(strlen(v1.value[i]) + strlen(v2.value[i]) + 1);
        strcpy(result.value[i], v1.value[i]);
        strcat(result.value[i], v2.value[i]);
    }

    return result;
}

#define DEFINE_FUNC_TEST_UNION(ctype, name) \
    union test test_union_##name(union test v1, union test v2) \
    { \
        union test result; \
        result.name = v1.name + v2.name; \
        return result; \
    } 
DEFINE_FUNC_TEST_UNION(signed char, c)
DEFINE_FUNC_TEST_UNION(signed short, s)
DEFINE_FUNC_TEST_UNION(signed int, i)
DEFINE_FUNC_TEST_UNION(signed long, l)
DEFINE_FUNC_TEST_UNION(signed long long, ll)
DEFINE_FUNC_TEST_UNION(float, f)
DEFINE_FUNC_TEST_UNION(double, d)

union test test_union_str(union test v1, union test v2)
{
    union test result;
    /* memoery leaks */
    result.str = (char*) malloc(strlen(v1.str) + strlen(v2.str) + 1);
    strcpy(result.str, v1.str);
    strcat(result.str, v2.str);
    return result;
} 

void test_modify(int *v)
{
    *v += 1;
}

void test_var()
{
    var_char += 1;
    var_short += 1;
    var_int += 1;
    var_long += 1;
    var_longlong += 1;
    var_uchar += 1;
    var_ushort += 1;
    var_uint += 1;
    var_ulong += 1;
    var_ulonglong += 1;
    var_float += 1.25;
    var_double += 1.25;
    strcat(var_string, "bar");
}

int test_null_ptr(void *ptr1)
{
    return ptr1 == NULL;
}

int test_null_func_ptr(int (*fn)(void *ptr))
{
    return fn == NULL;
}

int *test_ptr;
int test_array[5];
void init_test_ptr()
{
    test_array[0] = -2;
    test_array[1] = -1;
    test_array[2] = 0;
    test_array[3] = 1;
    test_array[4] = 2;
    test_ptr = &test_array[0];
}

int test_val;

struct bitfield_rec test_bitfield(struct bitfield_rec dat)
{
    dat.v1 -= 1;
    dat.v2 += 1;
    dat.v3 += 1;
    dat.v4 -= 1;
    dat.v5 += 1;
    return dat;
}

int expected_sizeof_bitfield_rec2()
{
    return sizeof(struct bitfield_rec2);
}

struct bitfield_rec2 test_bitfield2(struct bitfield_rec2 dat)
{
    dat.v1 += 1;
    dat.v2 += 1;
    return dat;
}

char *param_func_test(void *allocator(size_t))
{
    char *str = (char*) allocator(7);
    strncpy(str, "foobar", 7);

    return str;
}

sint_adder get_fptr()
{
    return add_sint;
}

static int count_num = 0;

int counter()
{
    return ++count_num;
}

void reset_counter()
{
    count_num = 0;
}

#undef confusing_func1
int confusing_func1(int a, int b)
{
    return a + b;
}

