/**
 *  ffi.h
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
 *   $Id$
 */

/* Prologue */
#ifndef GAUCHE_CWRAPPER_FFI_H
#define GAUCHE_CWRAPPER_FFI_H

#include <assert.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <inttypes.h>

#include <gauche.h>
#include <gauche/extend.h>
#include <gauche/class.h>
#include <gauche/uvector.h>

#if defined(GAUCHE_WINDOWS) || defined(__CYGWIN__)
#include <windows.h>
#include <psapi.h>
#endif

#include <ffi.h>
#include "closure_alloc.h"

#ifdef __OBJC__
#import <Foundation/Foundation.h>
#import "ObjCError.h"

#if defined GAUCHE_CHAR_ENCODING_EUC_JP
#define OBJC_STRING_ENCODING NSJapaneseEUCStringEncoding
#elif defined GAUCHE_CHAR_ENCODING_SJIS
#define OBJC_STRING_ENCODING NSShiftJISStringEncoding
#else
#define OBJC_STRING_ENCODING NSUTF8StringEncoding
#endif

#define TRY @try
#define CATCH(e) @catch(NSException *e)
#define THROW_EXCEPTION(e)                                              \
    do {                                                                \
        ScmObj name =                                                   \
            SCM_MAKE_STR_IMMUTABLE([[e name] cStringUsingEncoding: OBJC_STRING_ENCODING]); \
        ScmObj reason =                                                 \
            SCM_MAKE_STR_IMMUTABLE([[e reason] cStringUsingEncoding: OBJC_STRING_ENCODING]); \
        ScmObj objcerr = Scm_MakeObjCError(name, reason);               \
        Scm_Raise(objcerr);                                             \
    } while (0)

#else

#define TRY
#define CATCH(e)
#define THROW_EXCEPTION(e)

#endif

SCM_DECL_BEGIN

#define MODULE_NAME "c-wrapper.c-ffi"

#define DEFINE_PREDICATE(pred, class_name)                              \
    int pred(ScmObj obj)                                                \
    {                                                                   \
        ScmClass *klass = NULL;                                         \
        if (!klass) {                                                   \
            klass = SCM_CLASS(SCM_SYMBOL_VALUE(MODULE_NAME, class_name)); \
        }                                                               \
        return SCM_ISA(obj, klass);                                     \
    }

#define STATIC_DEFINE_PREDICATE(pred, class_name)                       \
    static int pred(ScmObj obj)                                         \
    {                                                                   \
        ScmClass *klass = NULL;                                         \
        if (!klass) {                                                   \
            klass = SCM_CLASS(SCM_SYMBOL_VALUE(MODULE_NAME, class_name)); \
        }                                                               \
        return SCM_ISA(obj, klass);                                     \
    }
        
/* pointer */
#define POINTER_DATA(x) Scm_PointerGet(x)
#define MAKE_VOID_POINTER(ptr) Scm_MakePointer(VOID_PTR_CLASS, (void*) ptr)
#define MAKE_POINTER(klass,ptr) Scm_MakePointer(klass, (void*) ptr)
#define BUFFER_OF(ptr) Scm_BufferOf(ptr)
#define PTR_CLASS(cTypeClass) Scm_PtrClass(SCM_OBJ(cTypeClass))
#define BASIC_POINTERP(obj) BasicPtrP(obj)
#define POINTERP(obj) PtrP(obj)
#define VOID_PTR_CLASS Scm_GetVoidPtrClass()

extern ScmObj Scm_MakePointer(ScmObj klass, void *ptr);
extern void *Scm_PointerGet(ScmObj ptrObj);
extern ScmObj Scm_Deref_uvector(ScmObj ptrObj, ScmObj size);
extern ScmObj Scm_Deref(ScmObj ptrObj);
extern ScmObj Scm_GetVoidPtrClass();
extern ScmObj Scm_BufferOf(ScmObj ptrObj);
extern ScmObj Scm_PtrClass(ScmObj cTypeClass);
extern int PtrP(ScmObj obj);
extern int BasicPtrP(ScmObj obj);

/* ffi_type */
typedef struct ScmFFITypeRec {
    SCM_HEADER;
    ffi_type *data;
} ScmFFIType;

SCM_CLASS_DECL(Scm_FFITypeClass);
#define SCM_CLASS_FFI_TYPE (&Scm_FFITypeClass)
#define SCM_FFI_TYPE(obj) ((ScmFFIType*)(obj))
#define SCM_FFI_TYPEP(obj) SCM_XTYPEP(obj, SCM_CLASS_FFI_TYPE)
#define SCM_FFI_TYPE_DATA(obj) (SCM_FFI_TYPE(obj)->data)
#define SCM_MAKE_FFI_TYPE(data) (Scm_MakeFFIType(data))

extern ScmObj Scm_GetUnsignedFFIType(int size);
extern ScmObj Scm_GetSignedFFIType(int size);
extern ScmObj Scm_MakeFFIType(ffi_type *data);
extern ScmObj Scm_MakeFFIArrayType(ffi_type *elem_type, long size);
extern ScmObj Scm_MakeFFIStructType(ScmObj elem_list);

/* ffi_cif */
typedef struct ScmFFICifRec {
    SCM_HEADER;
    ffi_cif *data;
} ScmFFICif;

SCM_CLASS_DECL(Scm_FFICifClass);
#define SCM_CLASS_FFI_CIF (&Scm_FFICifClass)
#define SCM_FFI_CIF(obj) ((ScmFFICif*)(obj))
#define SCM_FFI_CIFP(obj) SCM_XTYPEP(obj, SCM_CLASS_FFI_CIF)
#define SCM_FFI_CIF_DATA(obj) (SCM_FFI_CIF(obj)->data)
#define SCM_MAKE_FFI_CIF(data) (Scm_MakeFFICif(data))

extern ScmObj Scm_MakeFFICif(ffi_cif *data);

/* ffi_closure */
typedef struct ScmFFIClosureRec {
    SCM_HEADER;
    ffi_closure *data;
} ScmFFIClosure;

SCM_CLASS_DECL(Scm_FFIClosureClass);
#define SCM_CLASS_FFI_CLOSURE (&Scm_FFIClosureClass)
#define SCM_FFI_CLOSURE(obj) ((ScmFFIClosure*)(obj))
#define SCM_FFI_CLOSUREP(obj) SCM_XTYPEP(obj, SCM_CLASS_FFI_CLOSURE)
#define SCM_FFI_CLOSURE_DATA(obj) (SCM_FFI_CLOSURE(obj)->data)
#define SCM_MAKE_FFI_CLOSURE(data) (Scm_MakeFFIClosure(data))

/* C subr */
typedef struct CSubrInfoRec {
    ffi_cif *cif;
    void *fn;
    ScmObj identifier;
    ScmObj arg_types;
    ScmObj ret_type;
} CSubrInfo;
    
/* functions */
extern ScmObj Scm_FFIPrepCIF(ffi_type *rtype, ScmObj arglist);
extern ScmObj Scm_FFICall(ffi_cif *cif, ScmObj fnptr, ScmObj rvalueptr, ScmObj arglist);
extern ScmObj Scm_FFIPrepClosure(ffi_cif *cif, ScmProcedure *proc);
extern ScmObj Scm_MakeCSubr(ScmObj fnptr, ScmObj ret_type, ScmObj arg_types, ScmObj optional_p, ScmObj info);
extern ScmObj ConvertScmObj(ffi_type *ftype, ScmObj ctype, void *rvalue);
extern ScmObj FFI_dlopen(const char *path);
extern ScmObj FFI_dlsym(const char *symbol);
extern ScmObj FFI_dlerror();
extern ScmObj FFI_dlclose(ScmObj handle);
extern ScmObj Scm_CStructSymbol(ScmObj tagname);
extern ScmObj Scm_CUnionSymbol(ScmObj tagname);

/* BoehmGC 7.1 defines dlopen as GC_dlopen, but its header files doesn't have a prototype of GC_dlopen. */
extern void* GC_dlopen(const char *path, int mode);

/* Epilogue */
SCM_DECL_END

#endif  /* GAUCHE_CWRAPPER_FFI_H */
