/**
 *  c-ffi.c
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

#include "c-ffi.h"

#define FFI_ERROR_CHECK(x)                                              \
    do {                                                                \
        ffi_status _status = x;                                         \
        switch (_status) {                                              \
        case FFI_OK:                                                    \
            /* DO NOTHING */                                            \
            break;                                                      \
        case FFI_BAD_TYPEDEF:                                           \
            Scm_Error("One of the ffi_type objects that ffi_prep_cif came across is bad at line %S in %S", SCM_MAKE_INT(__LINE__), SCM_MAKE_STR_IMMUTABLE(__FILE__)); \
            break;                                                      \
        case FFI_BAD_ABI:                                               \
            Scm_Error("FFI_BAD_ABI error has occurred at line %S in %S", SCM_MAKE_INT(__LINE__), SCM_MAKE_STR_IMMUTABLE(__FILE__)); \
            break;                                                      \
        default:                                                        \
            Scm_Error("unknown error (ffi_status = %S) has occurred at line %S in %S", SCM_MAKE_INT(_status), SCM_MAKE_INT(__LINE__), SCM_MAKE_STR_IMMUTABLE(__FILE__)); \
            break;                                                      \
        }                                                               \
    } while (0)

ScmObj Scm_GetUnsignedFFIType(int size)
{
    ffi_type *type;
    switch (size) {
    case 1:
        type = &ffi_type_uint8;
        break;
    case 2:
        type = &ffi_type_uint16;
        break;
    case 4:
        type = &ffi_type_uint32;
        break;
    case 8:
        type = &ffi_type_uint64;
        break;
    default:
        Scm_Error("unsupported type: ~S", size);
        break;
    }

    SCM_RETURN(SCM_MAKE_FFI_TYPE(type));
}

ScmObj Scm_GetSignedFFIType(int size)
{
    ffi_type *type;
    switch (size) {
    case 1:
        type = &ffi_type_sint8;
        break;
    case 2:
        type = &ffi_type_sint16;
        break;
    case 4:
        type = &ffi_type_sint32;
        break;
    case 8:
        type = &ffi_type_sint64;
        break;
    default:
        Scm_Error("unsupported type: ~S", size);
        break;
    }

    SCM_RETURN(SCM_MAKE_FFI_TYPE(type));
}

static ScmObj Scm_PointerBufferOf(ScmObj ptrObj)
{
    static ScmObj buffer_of_proc = SCM_FALSE;
    ScmObj uvec;

    if (SCM_FALSEP(buffer_of_proc)) {
        buffer_of_proc = SCM_SYMBOL_VALUE(MODULE_NAME, "buffer-of");
    }

    SCM_RETURN(Scm_ApplyRec1(buffer_of_proc, ptrObj));
}

static void Scm_PointerSet(ScmObj ptrObj, void *ptr)
{
    ScmObj uvec = Scm_PointerBufferOf(ptrObj);
    memcpy(SCM_UVECTOR_ELEMENTS(uvec), &ptr, sizeof(void*));
}

void *Scm_PointerGet(ScmObj ptrObj)
{
    ScmObj uvec = Scm_PointerBufferOf(ptrObj);
    void *ptr;
    memcpy(&ptr, SCM_UVECTOR_ELEMENTS(uvec), sizeof(void*));
    return ptr;
}
        
ScmObj Scm_PtrClass(ScmObj cTypeClass)
{
    static ScmObj ptr_proc = SCM_FALSE;
    if (SCM_FALSEP(ptr_proc)) {
        ptr_proc = SCM_SYMBOL_VALUE(MODULE_NAME, "ptr");
    }
    SCM_RETURN(Scm_ApplyRec1(ptr_proc, cTypeClass));
}

ScmObj Scm_BufferOf(ScmObj ptrObj)
{
    static ScmObj bufferof_proc = SCM_FALSE;
    if (SCM_FALSEP(bufferof_proc)) {
        bufferof_proc = SCM_SYMBOL_VALUE(MODULE_NAME, "buffer-of");
    }
    SCM_RETURN(Scm_ApplyRec1(bufferof_proc, ptrObj));
}

ScmObj Scm_GetVoidPtrClass()
{
    static ScmObj voidptr_class = SCM_FALSE;
    if (SCM_FALSEP(voidptr_class)) {
        voidptr_class = PTR_CLASS(SCM_SYMBOL_VALUE(MODULE_NAME, "<c-void>"));
    }
    SCM_RETURN(voidptr_class);
}

ScmObj Scm_MakePointer(ScmObj klass, void *ptr)
{
    static ScmObj make_proc = SCM_FALSE;
    ScmObj ptrObj;
    ScmObj buf;

    if (SCM_FALSEP(make_proc)) {
        make_proc = SCM_SYMBOL_VALUE(MODULE_NAME, "make");
    }

    /*
           A (<uvector>)          (ptr A) (<uvector>)
      +----------+  +------+    +----------+  +---------------+
      |elements --->| data |    |elements --->|pointer of data|
      +----------+  +--^---+    +----------+  +-------|-------+
                       +------------------------------+  

      In this case, (ptr A) can be a dangling pointer when A is GCed and
      elements of (ptr A) are allocated with SCM_NEW_ATOMIC2.
      So we need to use SCM_NEW2 to allocate elements of (ptr A).
     */
    buf = Scm_MakeU8VectorFromArrayShared(sizeof(void*),
                                          SCM_NEW2(void*, sizeof(void*)));
    ptrObj = Scm_ApplyRec3(make_proc, klass, SCM_MAKE_KEYWORD("buffer"), buf);
    Scm_PointerSet(ptrObj, ptr);

    SCM_RETURN(ptrObj);
}

DEFINE_PREDICATE(PtrP, "<c-ptr>")
DEFINE_PREDICATE(BasicPtrP, "<c-basic-ptr>")

ScmObj Scm_Deref_uvector(ScmObj ptrObj, ScmObj size)
{
    ScmObj buf;
    unsigned char *p;

    p = (unsigned char*)POINTER_DATA(ptrObj);
    buf = Scm_MakeU8VectorFromArrayShared(Scm_GetInteger(size), p);
    if (p == NULL) {
        SCM_UVECTOR_ELEMENTS(buf) = p;
    }

    SCM_RETURN(buf);
}

ScmObj Scm_Deref(ScmObj ptrObj)
{
    static ScmObj orig_c_type_of_proc = SCM_FALSE;
    static ScmObj make_proc = SCM_FALSE;
    static ScmObj csizeof_proc = SCM_FALSE;
    ScmObj klass;
    ScmObj size;
    ScmObj obj;

    if (SCM_FALSEP(orig_c_type_of_proc)) {
        orig_c_type_of_proc = SCM_SYMBOL_VALUE(MODULE_NAME, "orig-c-type-of");
        make_proc = SCM_SYMBOL_VALUE(MODULE_NAME, "make");
        csizeof_proc = SCM_SYMBOL_VALUE(MODULE_NAME, "c-sizeof");
    }

    klass = Scm_ApplyRec1(orig_c_type_of_proc, SCM_OBJ(SCM_CLASS_OF(ptrObj)));
    size = Scm_ApplyRec1(csizeof_proc, klass);
    obj = Scm_ApplyRec3(make_proc, klass,
                        SCM_MAKE_KEYWORD("buffer"),
                        Scm_Deref_uvector(ptrObj, size));
    SCM_RETURN(obj);
}

ScmObj Scm_MakeFFIType(ffi_type *data)
{
    ScmFFIType *z = SCM_NEW(ScmFFIType);
    SCM_SET_CLASS(z, SCM_CLASS_FFI_TYPE);
    z->data = data;

    SCM_RETURN(SCM_OBJ(z));
}

ScmObj Scm_MakeFFICif(ffi_cif *data)
{
    ScmFFICif *z = SCM_NEW(ScmFFICif);
    SCM_SET_CLASS(z, SCM_CLASS_FFI_CIF);
    z->data = data;

    SCM_RETURN(SCM_OBJ(z));
}

ScmObj Scm_MakeFFIArrayType(ffi_type *elem_type, long size)
{
    ffi_type *array_type = SCM_NEW(ffi_type);

#if defined __x86_64__
    long i;

    array_type->size = elem_type->size * size;
    array_type->alignment = elem_type->alignment;
    array_type->type = FFI_TYPE_STRUCT;
    if (16 < array_type->size) {
        array_type->elements = NULL;
    } else {
        ffi_type *follow_elem_type = SCM_NEW(ffi_type);

        memcpy(follow_elem_type, elem_type, sizeof(ffi_type));
        follow_elem_type->alignment = 1;

        array_type->elements = SCM_NEW_ARRAY(ffi_type*, size + 1);
        for (i = 0; i < size; ++i) {
            if (i == 0) {
                array_type->elements[i] = elem_type;
            } else {
                array_type->elements[i] = follow_elem_type;
            }
        }
        array_type->elements[size] = NULL;
    }
#else
    array_type->size = elem_type->size * size;
    array_type->alignment = elem_type->alignment;
    array_type->type = elem_type->type;
    array_type->elements = elem_type->elements;
#endif

    SCM_RETURN(SCM_MAKE_FFI_TYPE(array_type));
}

ScmObj Scm_MakeFFIStructType(ScmObj elem_list)
{
    ffi_type *struct_type = SCM_NEW(ffi_type);
    ffi_cif dummy_cif;
    ScmObj p;
    int i = 0;

    if (Scm_Length(elem_list) == 0) {
        Scm_Error("can't define zero-member struct");
    }

    struct_type->size = 0;
    struct_type->alignment = 0;
    struct_type->type = FFI_TYPE_STRUCT;
    struct_type->elements = SCM_NEW_ARRAY(ffi_type*, Scm_Length(elem_list) + 1);
    SCM_FOR_EACH(p, elem_list) {
        if (!SCM_FFI_TYPEP(SCM_CAR(p))) {
            Scm_Error("<ffi-type> required, but got %S", SCM_CAR(p));
        }
        struct_type->elements[i] = SCM_FFI_TYPE_DATA(SCM_CAR(p));
        ++i;
    }
    struct_type->elements[i] = NULL;

    /* initialize aggregate */
    ffi_prep_cif(&dummy_cif, FFI_DEFAULT_ABI, 0, struct_type, NULL);

    SCM_RETURN(SCM_MAKE_FFI_TYPE(struct_type));
}
    
ScmObj Scm_FFIPrepCIF(ffi_type *rtype, ScmObj arglist)
{
    ffi_cif *cif = SCM_NEW(ffi_cif);
    int nargs = Scm_Length(arglist);
    ffi_type **atypes = SCM_NEW_ARRAY(ffi_type*, nargs);
    int i = 0;
    ffi_status status;
    ScmObj p;
    
    SCM_FOR_EACH(p, arglist) {
        atypes[i] = SCM_FFI_TYPE_DATA(SCM_CAR(p));
        ++i;
    }

    status = ffi_prep_cif(cif, FFI_DEFAULT_ABI, nargs, rtype, atypes);
    
    SCM_RETURN(Scm_Values2(SCM_MAKE_INT(status), SCM_MAKE_FFI_CIF(cif)));
}

STATIC_DEFINE_PREDICATE(ctype_p, "<c-type>")
STATIC_DEFINE_PREDICATE(cchar_p, "<c-char>")
STATIC_DEFINE_PREDICATE(cuchar_p, "<c-uchar>")
STATIC_DEFINE_PREDICATE(cshort_p, "<c-short>")
STATIC_DEFINE_PREDICATE(cushort_p, "<c-ushort>")
STATIC_DEFINE_PREDICATE(cfloat_p, "<c-float>")
STATIC_DEFINE_PREDICATE(cpromise_p, "<c-promise>")

static ffi_type *ffi_type_of(ScmObj ctype)
{
    static ScmObj slot = SCM_FALSE;
    ScmClass *klass;
    ScmObj p;
    ScmSlotAccessor *sa;

    if (SCM_FALSEP(slot)) {
        slot = SCM_INTERN("ffi-type");
    }

    klass = SCM_CLASS_OF(ctype);
    p = Scm_Assq(slot, klass->accessors);
    if (!SCM_PAIRP(p)) {
        Scm_Error("<ctype-meta> required, but got %S", ctype);
    } else if (!SCM_XTYPEP(SCM_CDR(p), SCM_CLASS_SLOT_ACCESSOR)) {
        Scm_Error("slot accessor information of class %S, slot %S is screwed up.", SCM_OBJ(klass), slot);
    }
    sa = SCM_SLOT_ACCESSOR(SCM_CDR(p));
    if (0 <= sa->slotNumber) {
        return SCM_FFI_TYPE_DATA(Scm_InstanceSlotRef(ctype, sa->slotNumber));
    } else {
        Scm_Error("wrong slot number: %d", sa->slotNumber);
    }
}

static void *basic_cast_arg(ffi_type *ftype, ScmObj arg)
{
    void *avalue = NULL;

#define SET_CAST_VALUE(avalue, type, func, v)           \
    if (SCM_INTP(v)) {                                  \
        avalue = SCM_MALLOC(sizeof(type));              \
        *((type*) avalue) = (type) SCM_INT_VALUE(v);    \
    } else if (SCM_NUMBERP(v)) {                        \
        avalue = SCM_MALLOC(sizeof(type));              \
        *((type*) avalue) = (type) func(v);             \
    } 

    switch (ftype->type) {
    case FFI_TYPE_INT:
        SET_CAST_VALUE(avalue, int, Scm_GetInteger, arg);
        break;
    case FFI_TYPE_UINT8:
        SET_CAST_VALUE(avalue, uint8_t, Scm_GetIntegerU, arg);
        break;
    case FFI_TYPE_SINT8:
        SET_CAST_VALUE(avalue, int8_t, Scm_GetInteger, arg);
        break;
    case FFI_TYPE_UINT16:
        SET_CAST_VALUE(avalue, uint16_t, Scm_GetIntegerU, arg);
        break;
    case FFI_TYPE_SINT16:
        SET_CAST_VALUE(avalue, int16_t, Scm_GetInteger, arg);
        break;
    case FFI_TYPE_UINT32:
        SET_CAST_VALUE(avalue, uint32_t, Scm_GetIntegerU, arg);
        break;
    case FFI_TYPE_SINT32:
        SET_CAST_VALUE(avalue, int32_t, Scm_GetInteger, arg);
        break;
    case FFI_TYPE_UINT64:
        SET_CAST_VALUE(avalue, uint64_t, Scm_GetIntegerU64, arg);
        break;
    case FFI_TYPE_SINT64:
        SET_CAST_VALUE(avalue, int64_t, Scm_GetInteger64, arg);
        break;
    case FFI_TYPE_FLOAT:
        SET_CAST_VALUE(avalue, float, Scm_GetDouble, arg);
        break;
    case FFI_TYPE_DOUBLE:
        SET_CAST_VALUE(avalue, double, Scm_GetDouble, arg);
        break;
    case FFI_TYPE_POINTER:
        if (SCM_STRINGP(arg)) {
            avalue = SCM_MALLOC(sizeof(void*));
            *((void**) avalue) = (void*) Scm_GetString(SCM_STRING(arg));
        } else if (SCM_FOREIGN_POINTER_P(arg)) {
            avalue = SCM_MALLOC(sizeof(void*));
            *((void**) avalue) = SCM_FOREIGN_POINTER_REF(void*, arg);
        }
        break;
    default:
        /* DO NOTHING */
        break;
    }

    return avalue;
}

static void *cast_arg(ffi_type *ftype, ScmObj ctype, ScmObj arg)
{
    static ScmObj cast_method = SCM_FALSE;
    void *avalue = NULL;
    ScmObj casted_arg;

    switch (ftype->type) {
    case FFI_TYPE_INT:
        /* FALLTHROUGH */
    case FFI_TYPE_UINT8:
        /* FALLTHROUGH */
    case FFI_TYPE_SINT8:
        /* FALLTHROUGH */
    case FFI_TYPE_UINT16:
        /* FALLTHROUGH */
    case FFI_TYPE_SINT16:
        /* FALLTHROUGH */
    case FFI_TYPE_UINT32:
        /* FALLTHROUGH */
    case FFI_TYPE_SINT32:
        /* FALLTHROUGH */
    case FFI_TYPE_UINT64:
        /* FALLTHROUGH */
    case FFI_TYPE_SINT64:
        /* FALLTHROUGH */
    case FFI_TYPE_FLOAT:
        /* FALLTHROUGH */
    case FFI_TYPE_DOUBLE:
        /* FALLTHROUGH */
    case FFI_TYPE_POINTER:
        avalue = basic_cast_arg(ftype, arg);
        if (avalue != NULL) {
            break;
        }
        /* FALLTHROUGH */
    case FFI_TYPE_STRUCT:
        /* FALLTHROUGH */
    default:
        casted_arg = arg;
        if (!SCM_ISA(arg, SCM_CLASS(ctype))) {
            if (SCM_FALSEP(cast_method)) {
                cast_method = SCM_SYMBOL_VALUE(MODULE_NAME, "cast");
            }
            casted_arg = Scm_ApplyRec2(cast_method, ctype, arg);
        }
        avalue = SCM_UVECTOR_ELEMENTS(Scm_BufferOf(casted_arg));
    }

    return avalue;
}

static ScmObj cforce(ScmObj arg)
{
    static ScmObj cforce_proc = SCM_FALSE;

    if (SCM_FALSEP(cforce_proc)) {
        cforce_proc = SCM_SYMBOL_VALUE(MODULE_NAME, "c-force");
    }

    SCM_RETURN(Scm_ApplyRec1(cforce_proc, arg));
}

static void *promote_arg(ScmObj arg, ffi_type **promoted_type)
{
    void *avalue = NULL;

#define SET_PROMOTE_VALUE(avalue, type, uvectype)                       \
    avalue = SCM_MALLOC((*promoted_type)->size);                        \
    *((type*) avalue) = (type) SCM_##uvectype##_ELEMENTS(Scm_BufferOf(arg))[0]; \

    *promoted_type = NULL;
    if (SCM_INTEGERP(arg)) {
        int oor = TRUE;
        if (!(Scm_GetInteger32Clamp(arg, SCM_CLAMP_NONE, &oor), oor)) {
            *promoted_type = &ffi_type_sint32;
            avalue = basic_cast_arg(*promoted_type, arg);
        } else if (!(Scm_GetIntegerU32Clamp(arg, SCM_CLAMP_NONE, &oor), oor)) {
            *promoted_type = &ffi_type_uint32;
            avalue = basic_cast_arg(*promoted_type, arg);
        } else if (!(Scm_GetInteger64Clamp(arg, SCM_CLAMP_NONE, &oor), oor)) {
            *promoted_type = &ffi_type_sint64;
            avalue = basic_cast_arg(*promoted_type, arg);
        } else if (!(Scm_GetIntegerU64Clamp(arg, SCM_CLAMP_NONE, &oor), oor)) {
            *promoted_type = &ffi_type_uint64;
            avalue = basic_cast_arg(*promoted_type, arg);
        } 
    } else if (SCM_REALP(arg)) { 
        *promoted_type = &ffi_type_double; 
        avalue = basic_cast_arg(*promoted_type, arg); 
    } else if (SCM_STRINGP(arg) || SCM_FOREIGN_POINTER_P(arg)) {
        *promoted_type = &ffi_type_pointer;
        avalue = basic_cast_arg(*promoted_type, arg);
    } else if (cchar_p(arg)) {
        *promoted_type = &ffi_type_sint32;
        SET_PROMOTE_VALUE(avalue, int32_t, S8VECTOR);
    } else if (cuchar_p(arg)) {
        *promoted_type = &ffi_type_sint32;
        SET_PROMOTE_VALUE(avalue, int32_t, U8VECTOR);
    } else if (cshort_p(arg)) {
        *promoted_type = &ffi_type_sint32;
        SET_PROMOTE_VALUE(avalue, int32_t, S16VECTOR);
    } else if (cushort_p(arg)) {
        *promoted_type = &ffi_type_sint32;
        SET_PROMOTE_VALUE(avalue, int32_t, U16VECTOR);
    } else if (cfloat_p(arg)) {
        *promoted_type = &ffi_type_double;
        SET_PROMOTE_VALUE(avalue, double, F32VECTOR);
    } else if (cpromise_p(arg)) {
        avalue = promote_arg(cforce(arg), promoted_type);
    } else if (ctype_p(arg)) {
        *promoted_type = ffi_type_of(SCM_OBJ(SCM_CLASS_OF(arg)));
        avalue = SCM_UVECTOR_ELEMENTS(Scm_BufferOf(arg));
    }

    if (*promoted_type == NULL) {
        Scm_Error("can't pass %S as va_arg", arg);
    }

    assert(avalue != NULL);

    return avalue;
}

ScmObj ConvertScmObj(ffi_type *ftype, ScmObj ctype, void *rvalue)
{
    static ScmObj make_method = SCM_FALSE;

#define SCM_CAST_VALUE(func, type, v) (func(*((type*)v)))

    switch (ftype->type) {
    case FFI_TYPE_INT:
        SCM_RETURN(SCM_CAST_VALUE(Scm_MakeInteger, int, rvalue));
    case FFI_TYPE_UINT8:
        SCM_RETURN(SCM_CAST_VALUE(Scm_MakeIntegerU, uint8_t, rvalue));
    case FFI_TYPE_SINT8:
        SCM_RETURN(SCM_CAST_VALUE(Scm_MakeInteger, int8_t, rvalue));
    case FFI_TYPE_UINT16:
        SCM_RETURN(SCM_CAST_VALUE(Scm_MakeIntegerU, uint16_t, rvalue));
    case FFI_TYPE_SINT16:
        SCM_RETURN(SCM_CAST_VALUE(Scm_MakeInteger, int16_t, rvalue));
    case FFI_TYPE_UINT32:
        SCM_RETURN(SCM_CAST_VALUE(Scm_MakeIntegerU, uint32_t, rvalue));
    case FFI_TYPE_SINT32:
        SCM_RETURN(SCM_CAST_VALUE(Scm_MakeInteger, int32_t, rvalue));
    case FFI_TYPE_UINT64:
        SCM_RETURN(SCM_CAST_VALUE(Scm_MakeIntegerU64, uint64_t, rvalue));
    case FFI_TYPE_SINT64:
        SCM_RETURN(SCM_CAST_VALUE(Scm_MakeInteger64, int64_t, rvalue));
    case FFI_TYPE_FLOAT:
        SCM_RETURN(SCM_CAST_VALUE(Scm_MakeFlonum, float, rvalue));
    case FFI_TYPE_DOUBLE:
        SCM_RETURN(SCM_CAST_VALUE(Scm_MakeFlonum, double, rvalue));
    case FFI_TYPE_VOID:
        SCM_RETURN(SCM_UNDEFINED);
    case FFI_TYPE_POINTER:
        /* FALLTHROUGH */
    case FFI_TYPE_STRUCT:
        /* FALLTHROUGH */
    default:
        if (SCM_FALSEP(make_method)) {
            make_method = SCM_SYMBOL_VALUE(MODULE_NAME, "make");
        }
        SCM_RETURN(Scm_ApplyRec3(make_method,
                                 ctype,
                                 SCM_MAKE_KEYWORD("buffer"),
                                 Scm_MakeU8VectorFromArrayShared(ftype->size, rvalue)));
    }
    /* NOTREACHED */
    SCM_RETURN(SCM_UNDEFINED);
}

#if defined(GAUCHE_WINDOWS) || defined(__CYGWIN__)

static void *lookup_symbol(const char *sym)
{
    void *addr;
    HANDLE hProcess;
    HMODULE *lphModules;
    DWORD needed;
    int i = 0;
        
    hProcess = GetCurrentProcess();
    if (!EnumProcessModules(hProcess, NULL, 0, &needed)) {
        Scm_Error("EnumProcessModules failed (1st call).\n");
    }
    lphModules = SCM_MALLOC(needed);
    if (!EnumProcessModules(hProcess, lphModules, needed, &needed)) {
        Scm_Error("EnumProcessModules failed (2nd call).\n");
    }
        
    addr = NULL;
    for (i = 0; i < needed/sizeof(HMODULE); ++i) {
        addr = GetProcAddress(lphModules[i], sym);
        CloseHandle(lphModules[i]);
        if (addr != NULL) {
            break;
        }
    }
    CloseHandle(hProcess);
        
    return addr;
}

#else

static void *lookup_symbol(const char *sym)
{
    return dlsym(RTLD_DEFAULT, sym);
}

#endif

static ScmObj c_subr_proc(ScmObj *args, int argc, void *data)
{
    CSubrInfo *c_subr_info = data;
    ffi_cif *cif;
    ffi_type **atypes = NULL;
    void **avalues;
    void *rvalue;
    int i = 0;
    ScmObj *passed_args;
    ScmObj p;
    int nargs;
    ffi_cif vaarg_cif;

    assert(c_subr_info->cif->nargs == argc || (c_subr_info->cif->nargs + 1) == argc);

    if (c_subr_info->fn == NULL) {
        void *fn = lookup_symbol(Scm_GetStringConst(SCM_SYMBOL_NAME(c_subr_info->identifier)));
        if (fn == NULL) {
            Scm_Error("function %S is not found.", c_subr_info->identifier);
        }
        c_subr_info->fn = fn;
    }
        
    if (c_subr_info->cif->nargs == argc) {
        nargs = argc;
    } else {
        assert(SCM_LISTP(args[argc - 1]));
        nargs = argc - 1 + Scm_Length(args[argc - 1]);
    }
    avalues = SCM_NEW_ARRAY(void*, nargs);
    
    passed_args = SCM_NEW_ARRAY(ScmObj, nargs);
    for (i = 0; i < c_subr_info->cif->nargs; ++i) {
        passed_args[i] = args[i];
    }
    if (c_subr_info->cif->nargs < argc) {
        SCM_FOR_EACH(p, args[argc - 1]) {
            passed_args[i] = SCM_CAR(p);
            ++i;
        }
    }

    for (i = 0; i < c_subr_info->cif->nargs; ++i) {
        avalues[i] = cast_arg(c_subr_info->cif->arg_types[i],
                              Scm_VectorRef(SCM_VECTOR(c_subr_info->arg_types), i, SCM_UNBOUND),
                              passed_args[i]);
    }

    /*
      We need to make new ffi_cif if optional arguments are exists.
    */
    if (c_subr_info->cif->nargs < nargs) {
        atypes = SCM_NEW_ARRAY(ffi_type*, nargs);
        memcpy(atypes, c_subr_info->cif->arg_types, sizeof(ffi_type*) * c_subr_info->cif->nargs);
        for (i = c_subr_info->cif->nargs; i < nargs; ++i) {
            avalues[i] = promote_arg(passed_args[i], &atypes[i]);
        }
        cif = &vaarg_cif;
        FFI_ERROR_CHECK(ffi_prep_cif(cif, c_subr_info->cif->abi, nargs, c_subr_info->cif->rtype, atypes));
    } else {
        cif = c_subr_info->cif;
    }

    rvalue = SCM_MALLOC(cif->rtype->size);
    
    TRY {
        if (cif->rtype->size < sizeof(ffi_arg)) {
            ffi_arg result;
            ffi_call(cif, FFI_FN(c_subr_info->fn), &result, avalues);
#ifdef WORDS_BIGENDIAN
            if (cif->rtype->type == FFI_TYPE_STRUCT) {
                memcpy(rvalue, &result, cif->rtype->size);
            } else {
                memcpy(rvalue, 
                       ((void*) &result) + sizeof(result) - cif->rtype->size, 
                       cif->rtype->size);
            }
#else
            memcpy(rvalue, &result, cif->rtype->size);
#endif
        } else {
            ffi_call(cif, FFI_FN(c_subr_info->fn), rvalue, avalues);
        }
    } CATCH(e) {
        THROW_EXCEPTION(e);
    }

    SCM_RETURN(ConvertScmObj(cif->rtype, c_subr_info->ret_type, rvalue));
}

ScmObj Scm_MakeCSubr(ScmObj fnptr, ScmObj ret_type, ScmObj arglist, ScmObj optional_p, ScmObj identifier)
{
    CSubrInfo *c_subr_info = SCM_NEW(CSubrInfo);
    int nargs = Scm_Length(arglist);
    ffi_type **atypes = SCM_NEW_ARRAY(ffi_type*, nargs);
    ffi_type *rtype = ffi_type_of(ret_type);
    ScmObj arg_types = Scm_MakeVector(nargs, SCM_UNBOUND);
    int i = 0;
    ScmObj p;
    ffi_status status;

    if (SCM_FALSEP(fnptr) && !SCM_SYMBOLP(identifier)) {
        Scm_Error("<symbol> required, but got %S", identifier);
    }

    /* make ffi_cif */
    i = 0;
    SCM_FOR_EACH(p, arglist) {
        atypes[i] = ffi_type_of(SCM_CAR(p));
        Scm_VectorSet(SCM_VECTOR(arg_types), i, SCM_CAR(p));
        ++i;
    }

    c_subr_info->cif = SCM_NEW(ffi_cif);
    FFI_ERROR_CHECK(ffi_prep_cif(c_subr_info->cif, FFI_DEFAULT_ABI, nargs, rtype, atypes));

    if (SCM_FALSEP(fnptr)) {
        c_subr_info->fn = NULL;
    } else {
        c_subr_info->fn = POINTER_DATA(fnptr);
    }
    c_subr_info->identifier = identifier;
    c_subr_info->arg_types = arg_types;
    c_subr_info->ret_type = ret_type;

    SCM_RETURN(Scm_MakeSubr(c_subr_proc, c_subr_info, nargs, SCM_TRUEP(optional_p), identifier));
}
    
ScmObj Scm_FFICall(ffi_cif *cif, ScmObj fnptr, ScmObj rvalueptr, ScmObj arglist)
{
    int nargs = Scm_Length(arglist);
    void **avalues = SCM_NEW_ARRAY(void*, nargs);
    void *fn;
    void *rvalue;
    int i = 0;
    ScmObj p;

    if (BASIC_POINTERP(fnptr)) {
        fn = POINTER_DATA(fnptr);
    } else {
        Scm_Error("<c-basic-ptr> required, but got %S", fnptr);
    }
    if (POINTERP(rvalueptr)) {
        rvalue = POINTER_DATA(rvalueptr);
    } else {
        Scm_Error("<c-ptr> required, but got %S", rvalueptr);
    }
    SCM_FOR_EACH(p, arglist) {
        if (!SCM_UVECTORP(SCM_CAR(p))) {
            Scm_Error("<uvector> required, but got %S", SCM_CAR(p));
        }
        avalues[i] = SCM_UVECTOR_ELEMENTS(SCM_CAR(p));
        ++i;
    }

    TRY {
        if (cif->rtype->size < sizeof(ffi_arg)) {
            ffi_arg result;
            ffi_call(cif, FFI_FN(fn), &result, avalues);
#ifdef WORDS_BIGENDIAN
            if (cif->rtype->type == FFI_TYPE_STRUCT) {
                memcpy(rvalue, &result, cif->rtype->size);
            } else {
                memcpy(rvalue, 
                       ((void*) &result) + sizeof(result) - cif->rtype->size, 
                       cif->rtype->size);
            }
#else
            memcpy(rvalue, &result, cif->rtype->size);
#endif
        } else {
            ffi_call(cif, FFI_FN(fn), rvalue, avalues);
        }
    } CATCH(e) {
        THROW_EXCEPTION(e);
    }

    SCM_RETURN(SCM_UNDEFINED);
}


static void closure_func(ffi_cif *cif, void *rvalue, void **avalues, void *data)
{
    ScmObj proc = SCM_OBJ(data);
    ScmObj arglist = SCM_NIL;
    void *proc_result_ptr;
    int i;

    for (i = 0; i < cif->nargs; ++i) {
        arglist = Scm_Cons(MAKE_VOID_POINTER(avalues[i]), arglist);
    }
    arglist = Scm_Reverse(arglist);

    proc_result_ptr = POINTER_DATA(Scm_ApplyRec(proc, arglist));
    if (cif->rtype->size < sizeof(ffi_arg)) {
        memset(rvalue, 0, sizeof(ffi_arg));
#ifdef WORDS_BIGENDIAN
        if (cif->rtype->type == FFI_TYPE_STRUCT) {
            memcpy(rvalue, proc_result_ptr, cif->rtype->size);
        } else {
            memcpy(rvalue + sizeof(ffi_arg) - cif->rtype->size,
                   proc_result_ptr, cif->rtype->size);
        }
#else
        memcpy(rvalue, proc_result_ptr, cif->rtype->size);
#endif
    } else {
        memcpy(rvalue, proc_result_ptr, cif->rtype->size);
    }
}

static void finalize_FFIClosure(ScmObj obj, void *data)
{
    ScmFFIClosure *z = SCM_FFI_CLOSURE(obj);
    if (z->data) {
        closure_free(z->data);
        z->data = NULL;
    }
}

ScmObj Scm_MakeFFIClosure(ffi_closure *data)
{
    ScmFFIClosure *z = SCM_NEW(ScmFFIClosure);
    SCM_SET_CLASS(z, SCM_CLASS_FFI_CLOSURE);
    Scm_RegisterFinalizer(SCM_OBJ(z), finalize_FFIClosure, NULL);
    z->data = data;

    SCM_RETURN(SCM_OBJ(z));
}


ScmObj Scm_FFIPrepClosure(ffi_cif *cif, ScmProcedure *proc)
{
    ffi_closure *closure = closure_alloc();
    ffi_status status = ffi_prep_closure(closure, cif, closure_func,
                                         (void*) proc);

    SCM_RETURN(Scm_Values2(SCM_MAKE_INT(status), Scm_MakeFFIClosure(closure)));
}

ScmObj FFI_dlopen(const char *path)
{
#if defined(GAUCHE_WINDOWS)
    void *handle = (void*)LoadLibrary(SCM_MBS2WCS(path));
#else
    void *handle = dlopen(path, RTLD_NOW | RTLD_GLOBAL);
#endif
    if (handle) {
        SCM_RETURN(MAKE_VOID_POINTER(handle));
    } else {
        SCM_RETURN(SCM_FALSE);
    }
}

ScmObj FFI_dlsym(const char *symbol)
{
    void *ptr = lookup_symbol(symbol);

    if (ptr) {
        SCM_RETURN(MAKE_VOID_POINTER(ptr));
    } else {
        SCM_RETURN(SCM_FALSE);
    }
}

ScmObj FFI_dlerror()
{
#if defined(GAUCHE_WINDOWS)
    char buf[80];
    sprintf(buf, "rror code %d", GetLastError());
    SCM_RETURN(SCM_MAKE_STR_COPYING(buf));
#else
    const char *errmsg = dlerror();
    if (errmsg) {
        SCM_RETURN(SCM_MAKE_STR_IMMUTABLE(errmsg));
    } else {
        SCM_RETURN(SCM_FALSE);
    }
#endif
}

ScmObj FFI_dlclose(ScmObj handle)
{
#if defined(GAUCHE_WINDOWS)
    (void)FreeLibrary((HMODULE) POINTER_DATA(handle));
    SCM_RETURN(SCM_MAKE_INT(0));
#else
    SCM_RETURN(SCM_MAKE_INT(dlclose(POINTER_DATA(handle))));
#endif
}

ScmObj Scm_CStructSymbol(ScmObj tagname)
{
    const char *tagname_str;
    char *struct_symbol_str;
    int tagname_len;
    
    if (!SCM_SYMBOLP(tagname)) {
        Scm_Error("<symbol> required, but got %S", tagname);
    }

    tagname_str = Scm_GetStringConst(SCM_SYMBOL_NAME(tagname));
    tagname_len = strlen(tagname_str);
    struct_symbol_str = SCM_NEW_ARRAY(char, tagname_len + 12);
    snprintf(struct_symbol_str, tagname_len + 12, "<c-struct:%s>", tagname_str);

    SCM_RETURN(SCM_INTERN(struct_symbol_str));
}

ScmObj Scm_CUnionSymbol(ScmObj tagname)
{
    const char *tagname_str;
    char *union_symbol_str;
    int tagname_len;
    
    if (!SCM_SYMBOLP(tagname)) {
        Scm_Error("<symbol> required, but got %S", tagname);
    }

    tagname_str = Scm_GetStringConst(SCM_SYMBOL_NAME(tagname));
    tagname_len = strlen(tagname_str);
    union_symbol_str = SCM_NEW_ARRAY(char, tagname_len + 11);
    snprintf(union_symbol_str, tagname_len + 12, "<c-union:%s>", tagname_str);

    SCM_RETURN(SCM_INTERN(union_symbol_str));
}

/*
 * Module initialization function.
 */
extern void Scm_Init_c_ffilib(ScmModule*);
#ifdef __OBJC__
extern void Scm_Init_ObjCError(ScmModule*);
#endif

ScmObj Scm_Init_c_ffi(void)
{
    ScmModule *mod;

    /* Register this DSO to Gauche */
    SCM_INIT_EXTENSION(c_ffi);

    /* Create the module if it doesn't exist yet. */
    mod = SCM_MODULE(SCM_FIND_MODULE(MODULE_NAME, TRUE));

    /* Register stub-generated procedures */
    Scm_Init_c_ffilib(mod);

#ifdef __OBJC__
    Scm_Init_ObjCError(mod);
#endif
}
