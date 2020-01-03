/*
   stddef_patch.h
   2020-1-3

   This is a patch for stddef.h in MSYS2/MinGW-w64 (32bit).
*/

typedef struct {
    double d1;
    double d2;
} float128_dummy_t;

#define __float128 float128_dummy_t

