/**
 *  c-parser.c
 *
 *   Copyright (c) 2009 KOGURO, Naoki (naoki@koguro.net)
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without 
 *   modification, are permitted provided that the following conditions 
 *   are met:
 *
 *   1. Redistributions of source code must retain the above copyright 
 *      notice, this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright 
 *      notice, this list of conditions and the following disclaimer in the 
 *      documentation and/or other materials provided with the distribution.
 *   3. Neither the name of the authors nor the names of its contributors 
 *      may be used to endorse or promote products derived from this 
 *      software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED 
 *   TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
 *   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
 *   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
 *   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
 *   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "c-parser.h"

/* #define USE_PROFILER */
/* #define USE_EVAL_COUNTER */

#define rdtsc(x) __asm__ __volatile__ ("rdtsc" : "=A" (x));
#ifdef USE_PROFILER
#define START_PROFILE(x) long long _profile_start, _profile_end; rdtsc(_profile_start); _profile_##x##_count++;
#define END_PROFILE(x) rdtsc(_profile_end); _profile_##x##_time += _profile_end - _profile_start;
#else
#define START_PROFILE(x)
#define END_PROFILE(x)
#endif

#ifdef USE_EVAL_COUNTER
static long alloc_struct_counter = 0;
static long init_struct_counter = 0;
static long alloc_union_counter = 0;
static long init_union_counter = 0;
static long define_enum_counter = 0;
static long typedef_counter = 0;
static long define_inline_counter = 0;
static long define_extern_counter = 0;
static long alloc_objc_class_counter = 0;
static long init_objc_class_counter = 0;
static long define_objc_method_counter = 0;
static long define_cmacro_counter = 0;
static long define_cfunclike_macro_counter = 0;
#define TYPE_COUNTUP(type) ++(type##_counter)

static void show_eval_counter()
{
    fprintf(stderr, "alloc-struct: %d\n", alloc_struct_counter);
    fprintf(stderr, "init-struct: %d\n", init_struct_counter);
    fprintf(stderr, "alloc-union: %d\n", alloc_union_counter);
    fprintf(stderr, "init-union: %d\n", init_union_counter);
    fprintf(stderr, "define-enum: %d\n", define_enum_counter);
    fprintf(stderr, "typedef: %d\n", typedef_counter);
    fprintf(stderr, "define-inline: %d\n", define_inline_counter);
    fprintf(stderr, "define-extern: %d\n", define_extern_counter);
    fprintf(stderr, "alloc-objc-class: %d\n", alloc_objc_class_counter);
    fprintf(stderr, "init-objc-class: %d\n", init_objc_class_counter);
    fprintf(stderr, "define-objc-method: %d\n", define_objc_method_counter);
    fprintf(stderr, "define-cmacro: %d\n", define_cmacro_counter);
    fprintf(stderr, "define-cfunclike-macro: %d\n", define_cfunclike_macro_counter);
}
#else
#define TYPE_COUNTUP(type)
#endif 

int yyerror(const char *str);
int yylex();

#define CHECK_ARG(v) if (SCM_FALSEP(v)) SCM_RETURN(SCM_FALSE)

DEFINE_SYM(plus_op);
DEFINE_SYM(with_module);
DEFINE_SYM(c_wrapper);
DEFINE_SYM(c_wrapper_c_ffi);
DEFINE_SYM(c_wrapper_objc_ffi);
DEFINE_SYM(ptr);
DEFINE_SYM(quote);
DEFINE_SYM(char);
DEFINE_SYM(U_signed);
DEFINE_SYM(U_unsigned);
DEFINE_SYM(short);
DEFINE_SYM(int);
DEFINE_SYM(long);
DEFINE_SYM(float);
DEFINE_SYM(double);
DEFINE_SYM(void);
DEFINE_SYM(_Bool);
DEFINE_SYM(__builtin_va_list);
DEFINE_SYM(U_struct);
DEFINE_SYM(U_union);
DEFINE_SYM(U_enum);
DEFINE_SYM(c_char);
DEFINE_SYM(c_uchar);
DEFINE_SYM(c_short);
DEFINE_SYM(c_ushort);
DEFINE_SYM(c_int);
DEFINE_SYM(c_uint);
DEFINE_SYM(c_long);
DEFINE_SYM(c_ulong);
DEFINE_SYM(c_longlong);
DEFINE_SYM(c_ulonglong);
DEFINE_SYM(c_float);
DEFINE_SYM(c_double);
DEFINE_SYM(c_longdouble);
DEFINE_SYM(c_void);
DEFINE_SYM(c_struct);
DEFINE_SYM(c_union);
DEFINE_SYM(c_enum);
DEFINE_SYM(c_array);
DEFINE_SYM(c_func);
DEFINE_SYM(c_func_vaargs);
DEFINE_SYM(c_func_ptr);
DEFINE_SYM(c_func_vaargs_ptr);
DEFINE_SYM(c_bit_field);
DEFINE_SYM(U_typedef);
DEFINE_SYM(cast);
DEFINE_SYM(scm_cast);
DEFINE_SYM(integer);
DEFINE_SYM(list);
DEFINE_SYM(cons);
DEFINE_SYM(lambda);
DEFINE_SYM(args);
DEFINE_SYM(apply);
DEFINE_SYM(mode);
DEFINE_SYM(__mode__);
DEFINE_SYM(QI);
DEFINE_SYM(__QI__);
DEFINE_SYM(HI);
DEFINE_SYM(__HI__);
DEFINE_SYM(SI);
DEFINE_SYM(__SI__);
DEFINE_SYM(DI);
DEFINE_SYM(__DI__);
DEFINE_SYM(SF);
DEFINE_SYM(__SF__);
DEFINE_SYM(DF);
DEFINE_SYM(__DF__);
DEFINE_SYM(byte);
DEFINE_SYM(__byte__);
DEFINE_SYM(word);
DEFINE_SYM(__word__);
DEFINE_SYM(pointer);
DEFINE_SYM(__pointer__);
DEFINE_SYM(S_alloc_struct);
DEFINE_SYM(S_init_struct);
DEFINE_SYM(S_alloc_union);
DEFINE_SYM(S_init_union);
DEFINE_SYM(S_define_enum);
DEFINE_SYM(S_typedef);
DEFINE_SYM(S_define_inline);
DEFINE_SYM(S_define_extern);
DEFINE_SYM(S_alloc_objc_class);
DEFINE_SYM(S_init_objc_class);
DEFINE_SYM(S_define_objc_method);
DEFINE_SYM(S_define_cmacro);
DEFINE_SYM(S_define_cfunclike_macro);
DEFINE_SYM(S_define);
DEFINE_SYM(c_func);
DEFINE_SYM(make_c_func);
DEFINE_SYM(c_func_vaargs);
DEFINE_SYM(make_c_func_vaargs);
DEFINE_SYM(make_c_var);
DEFINE_SYM(S_identity);
DEFINE_SYM(S_define_c_struct);
DEFINE_SYM(S_define_c_union);
DEFINE_SYM(S_init_c_struct);
DEFINE_SYM(S_init_c_union);
DEFINE_SYM(objc_object);
DEFINE_SYM(objc_lookup_class);
DEFINE_SYM(objc_register_method);
DEFINE_SYM(c_delay);
DEFINE_SYM(c_cast);

DEFINE_PROC1(make_define_inline_expr, "c-wrapper.c-parser", "make-define-inline-expr");
DEFINE_PROC0(ffi_sandbox_module, "c-wrapper.c-ffi", "ffi-sandbox-module");

/* parser state */
static ScmObj arg_pool;
static ScmObj value_pool;
static ScmObj struct_pool;
static ScmObj union_pool;
static ScmObj referenced_identifier_list;
static ScmObj referenced_typename_list;

/* macro parser state */
static ScmObj is_use_return;
static ScmObj is_use_jump;
static ScmObj is_use_iterator;
static ScmObj macro_body;

static struct DefChunkDictRec {
    int size;
    ScmVector *chunk_vector;
    ScmHashTable *identifier_table;
    ScmHashTable *typename_table;
} defchunk_dict;

#define DEFCHUNK_VECTOR_INITIAL_SIZE 1024
#define DEFCHUNK_VECTOR_EXPAND_FACTOR 2

enum {
    TS_SIGNED   = 0,
    TS_UNSIGNED = 1 << 1,
    TS_CHAR     = 1 << 2,
    TS_SHORT    = 1 << 3,
    TS_INT      = 1 << 4,
    TS_FLOAT    = 1 << 5,
    TS_DOUBLE   = 1 << 6,
    /* We're interesting the number of 'long' (to distinct 'long' and 'long long'),
       so ts_long must be last. */
    TS_LONG     = 1 << 7,
};

ScmObj CParser_ctype2class_symbol(ScmObj sym)
{
    static ScmObj lt = SCM_UNBOUND;
    static ScmObj gt = SCM_UNBOUND;

    if (SCM_UNBOUNDP(lt)) {
        lt = SCM_MAKE_STR_IMMUTABLE("<");
        gt = SCM_MAKE_STR_IMMUTABLE(">");
    }

    SCM_RETURN(Scm_Intern(SCM_STRING(Scm_StringAppend(SCM_LIST3(lt, SCM_OBJ(SCM_SYMBOL_NAME(sym)), gt)))));
}

ScmObj CParser_List(ScmObj v)
{
    CHECK_ARG(v);
    SCM_RETURN(SCM_LIST1(v));
}

ScmObj CParser_Append(ScmObj v0, ScmObj v1)
{
    CHECK_ARG(v0);
    CHECK_ARG(v1);
    SCM_RETURN(Scm_Append2(v0, v1));
}

ScmObj CParser_AddList(ScmObj v0, ScmObj v1)
{
    CHECK_ARG(v0);
    CHECK_ARG(v1);
    SCM_RETURN(Scm_Append2(v0, SCM_LIST1(v1)));
}

ScmObj CParser_Typename(ScmObj v)
{
    CHECK_ARG(v);
    Scm_ReferencedTypenameListAdd(v);
    SCM_RETURN(SCM_LIST1(v));
}
        
ScmObj Scm_ArgPoolRef()
{
    SCM_RETURN(arg_pool);
}

ScmObj Scm_ArgPoolSet(ScmObj lst)
{
    arg_pool = lst;
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_ArgPoolAdd(ScmObj name)
{
    arg_pool = Scm_Cons(name, arg_pool);
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_ArgPoolClear()
{
    arg_pool = SCM_NIL;
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_InitValuePool()
{
    value_pool = Scm_MakeHashTableSimple(SCM_HASH_EQ, 0);
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_RegisterIdentifier(ScmObj name, ScmObj value)
{
    Scm_HashTableSet(SCM_HASH_TABLE(value_pool), name, value, 0);
    SCM_RETURN(value);
}

ScmObj Scm_RegisteredIdentifierP(ScmObj name)
{
    if (SCM_FALSEP(Scm_Memq(name, arg_pool))) {
        if (SCM_UNBOUNDP(Scm_HashTableRef(SCM_HASH_TABLE(value_pool), name, SCM_UNBOUND))) {
            SCM_RETURN(SCM_FALSE);
        } else {
            SCM_RETURN(SCM_TRUE);
        }
    } else {
        SCM_RETURN(SCM_TRUE);
    }
}

ScmObj Scm_LookupValue(ScmObj v)
{
    if (SCM_LISTP(v) && SCM_EQ(SCM_CAR(v), SYM(S_identity))) {
        SCM_RETURN(Scm_HashTableRef(SCM_HASH_TABLE(value_pool), SCM_CADR(v), SCM_FALSE));
    } else {
        SCM_RETURN(v);
    }
}

ScmObj Scm_InitStructPool()
{
    struct_pool = Scm_MakeHashTableSimple(SCM_HASH_EQ, 0);
    SCM_RETURN(SCM_UNDEFINED);
}

static void struct_pool_add(ScmObj tagname)
{
    Scm_HashTableSet(SCM_HASH_TABLE(struct_pool), tagname, SCM_TRUE, 0);
}

static int is_struct_pool_exists(ScmObj tagname)
{
    if (SCM_FALSEP(Scm_HashTableRef(SCM_HASH_TABLE(struct_pool), tagname, SCM_FALSE))) {
        return FALSE;
    } else {
        return TRUE;
    }
}

ScmObj Scm_InitUnionPool()
{
    union_pool = Scm_MakeHashTableSimple(SCM_HASH_EQ, 0);
    SCM_RETURN(SCM_UNDEFINED);
}

static void union_pool_add(ScmObj tagname)
{
    Scm_HashTableSet(SCM_HASH_TABLE(union_pool), tagname, SCM_TRUE, 0);
}

static int is_union_pool_exists(ScmObj tagname)
{
    if (SCM_FALSEP(Scm_HashTableRef(SCM_HASH_TABLE(union_pool), tagname, SCM_FALSE))) {
        return FALSE;
    } else {
        return TRUE;
    }
}

ScmObj Scm_InitMacroParserState()
{
    is_use_return = SCM_FALSE;
    is_use_jump = SCM_FALSE;
    is_use_iterator = SCM_FALSE;
    macro_body = SCM_FALSE;
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_UseReturnP()
{
    SCM_RETURN(is_use_return);
}

ScmObj Scm_UseReturnSet(ScmObj flag)
{
    is_use_return = flag;
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_UseJumpP()
{
    SCM_RETURN(is_use_jump);
}

ScmObj Scm_UseJumpSet(ScmObj flag)
{
    is_use_jump = flag;
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_UseIteratorP()
{
    SCM_RETURN(is_use_iterator);
}

ScmObj Scm_UseIteratorSet(ScmObj flag)
{
    is_use_iterator = flag;
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_MacroBodyRef()
{
    SCM_RETURN(macro_body);
}

ScmObj Scm_MacroBodySet(ScmObj body)
{
    macro_body = body;
    SCM_RETURN(SCM_UNDEFINED);
}
    
ScmObj Scm_ReferencedIdentifierListRef()
{
    SCM_RETURN(referenced_identifier_list);
}

ScmObj Scm_ReferencedIdentifierListAdd(ScmObj identifier)
{
    referenced_identifier_list = Scm_Cons(identifier, referenced_identifier_list);
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_ReferencedIdentifierListClear()
{
    referenced_identifier_list = SCM_NIL;
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_ReferencedTypenameListRef()
{
    SCM_RETURN(referenced_typename_list);
}

ScmObj Scm_ReferencedTypenameListAdd(ScmObj typename)
{
    referenced_typename_list = Scm_Cons(typename, referenced_typename_list);
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_ReferencedTypenameListClear()
{
    referenced_typename_list = SCM_NIL;
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_AllReferencedInfoClear()
{
    Scm_ArgPoolClear();
    Scm_ReferencedIdentifierListClear();
    Scm_ReferencedTypenameListClear();
    SCM_RETURN(SCM_UNDEFINED);
}

static ScmObj typespec2ctype_nonbasic(ScmObj type_spec_list)
{
    ScmObj car = SCM_CAR(type_spec_list);
    ScmObj cdr = SCM_CDR(type_spec_list);

    if (SCM_EQ(car, SYM(void))) {
        SCM_RETURN(SYM(c_void));
    } else if (SCM_EQ(car, SYM(_Bool))) {
        SCM_RETURN(SYM(c_int));
    } else if (SCM_EQ(car, SYM(__builtin_va_list))) {
        SCM_RETURN(SCM_LIST2(SCM_LIST3(SYM(with_module), SYM(c_wrapper_c_ffi), SYM(ptr)), SYM(c_void)));
    } else if (SCM_PAIRP(car) && SCM_EQ(SCM_CAR(car), SYM(U_struct))) {
        ScmObj tagname = SCM_CADR(car);
        ScmObj elem_alist = SCM_CADR(SCM_CDR(car));
        if (SCM_FALSEP(elem_alist)) {
            Scm_EmitAllocStruct(tagname);
        } else {
            Scm_EmitInitStruct(tagname, elem_alist);
        }
        /* `(c-struct ',tagname) */
        SCM_RETURN(Scm_CStructSymbol(tagname));
    } else if (SCM_PAIRP(car) && SCM_EQ(SCM_CAR(car), SYM(U_union))) {
        ScmObj tagname = SCM_CADR(car);
        ScmObj elem_alist = SCM_CADR(SCM_CDR(car));
        if (SCM_FALSEP(elem_alist)) {
            Scm_EmitAllocUnion(tagname);
        } else {
            Scm_EmitInitUnion(tagname, elem_alist);
        }
        /* `(c-union ',tagname) */
        SCM_RETURN(Scm_CUnionSymbol(tagname));
    } else if (SCM_PAIRP(car) && SCM_EQ(SCM_CAR(car), SYM(U_enum))) {
        ScmObj tagname = SCM_CADR(car);
        ScmObj enum_alist = SCM_CADR(SCM_CDR(car));
        Scm_EmitDefineEnum(tagname, enum_alist);
        /* `(c-enum ',tagname) -> <c-int> */
        SCM_RETURN(SYM(c_int));
    } else if (SCM_SYMBOLP(car) && SCM_NULLP(cdr)) {
        SCM_RETURN(CParser_ctype2class_symbol(car));
    }

    SCM_RETURN(SCM_FALSE);
}

static ScmObj typespec2ctype(ScmObj type_spec_list)
{
    ScmObj pair;
    int type_spec = 0;
    
    CHECK_ARG(type_spec_list);

    if ((!SCM_PAIRP(type_spec_list)) || SCM_EQ(type_spec_list, SCM_NIL)) {
        SCM_RETURN(SCM_FALSE);
    } 

    SCM_FOR_EACH(pair, type_spec_list) {
        if (SCM_EQ(SYM(U_signed), SCM_CAR(pair))) {
            type_spec |= TS_SIGNED;
        } else if (SCM_EQ(SYM(U_unsigned), SCM_CAR(pair))) {
            type_spec |= TS_UNSIGNED;
        } else if (SCM_EQ(SYM(char), SCM_CAR(pair))) {
            type_spec |= TS_CHAR;
        } else if (SCM_EQ(SYM(short), SCM_CAR(pair))) {
            type_spec |= TS_SHORT;
        } else if (SCM_EQ(SYM(int), SCM_CAR(pair))) {
            type_spec |= TS_INT;
        } else if (SCM_EQ(SYM(float), SCM_CAR(pair))) {
            type_spec |= TS_FLOAT;
        } else if (SCM_EQ(SYM(double), SCM_CAR(pair))) {
            type_spec |= TS_DOUBLE;
        } else if (SCM_EQ(SYM(long), SCM_CAR(pair))) {
            /*
              We're interesting the number of 'long' to distinct 'long' and 'long long'.
            */
            type_spec += TS_LONG;
        } else {
            SCM_RETURN(typespec2ctype_nonbasic(type_spec_list));
        }
    }

    switch (type_spec) {

    case TS_SIGNED + TS_CHAR:
        SCM_RETURN(SYM(c_char));
    case TS_UNSIGNED + TS_CHAR:
        SCM_RETURN(SYM(c_uchar));

    case TS_SIGNED + TS_SHORT:
    case TS_SIGNED + TS_SHORT + TS_INT:
        SCM_RETURN(SYM(c_short));
    case TS_UNSIGNED + TS_SHORT:
    case TS_UNSIGNED + TS_SHORT + TS_INT:
        SCM_RETURN(SYM(c_ushort));

    case TS_SIGNED:
    case TS_SIGNED + TS_INT:
        SCM_RETURN(SYM(c_int));
    case TS_UNSIGNED:
    case TS_UNSIGNED + TS_INT:
        SCM_RETURN(SYM(c_uint));
        

    case TS_SIGNED + TS_LONG:
    case TS_SIGNED + TS_LONG + TS_INT:
        SCM_RETURN(SYM(c_long));
    case TS_UNSIGNED + TS_LONG:
    case TS_UNSIGNED + TS_LONG + TS_INT:
        SCM_RETURN(SYM(c_ulong));
        
    case TS_SIGNED + TS_LONG + TS_LONG:
    case TS_SIGNED + TS_LONG + TS_LONG + TS_INT:
        SCM_RETURN(SYM(c_longlong));
    case TS_UNSIGNED + TS_LONG + TS_LONG:
    case TS_UNSIGNED + TS_LONG + TS_LONG + TS_INT:
        SCM_RETURN(SYM(c_ulonglong));

    case TS_FLOAT:
        SCM_RETURN(SYM(c_float));

    case TS_DOUBLE:
        SCM_RETURN(SYM(c_double));

    case TS_LONG + TS_DOUBLE:
        SCM_RETURN(SYM(c_longdouble));

    default:
        SCM_RETURN(SCM_FALSE);
    }
}

ScmObj Scm_MakeTypeDecl(ScmObj type_spec_list, ScmObj declarator)
{
    ScmObj lst = SCM_NIL;
    ScmObj pair;
    ScmObj ctype;
    DeclaratorProc *func;
    ScmTypeDecl *z = SCM_NEW(ScmTypeDecl);
    SCM_SET_CLASS(z, SCM_CLASS_TYPE_DECL);

    CHECK_ARG(type_spec_list);
    CHECK_ARG(declarator);

    if (!SCM_DECLARATORP(declarator)) {
        Scm_Error("<declarator> required, but got %S", declarator);
    }
    
    SCM_FOR_EACH(pair, type_spec_list) {
        if (SCM_EQ(SCM_CAR(pair), SYM(U_typedef))) {
            continue;
        }
        lst = Scm_Cons(SCM_CAR(pair), lst);
    }
    lst = Scm_Reverse(lst);

    ctype = typespec2ctype(lst);
    if (SCM_FALSEP(ctype)) {
        SCM_RETURN(SCM_FALSE);
    }

    z->type = ctype;
    z->name = SCM_FALSE;
    z->init_value = SCM_FALSE;

    func = SCM_DECLARATOR(declarator)->func;
    SCM_RETURN(func(SCM_OBJ(z), SCM_DECLARATOR(declarator)->data));
}

static ScmObj compose_declarator(ScmObj type_decl, ScmObj *data)
{
    ScmObj d1 = data[0];
    ScmObj d2 = data[1];
    DeclaratorProc *func1 = SCM_DECLARATOR(d1)->func;
    DeclaratorProc *func2 = SCM_DECLARATOR(d2)->func;

    SCM_RETURN(func1(func2(type_decl, SCM_DECLARATOR(d2)->data), SCM_DECLARATOR(d1)->data));
}

ScmObj Scm_ComposeDeclarator(ScmObj d1, ScmObj d2)
{
    ScmDeclarator *z;

    CHECK_ARG(d1);
    CHECK_ARG(d2);
    z = SCM_NEW(ScmDeclarator);
    SCM_SET_CLASS(z, SCM_CLASS_DECLARATOR);
    z->func = compose_declarator;
    z->data[0] = d1;
    z->data[1] = d2;
    SCM_RETURN(SCM_OBJ(z));
}
    
static ScmObj identifier_declarator(ScmObj type_decl, ScmObj *data)
{
    SCM_TYPE_DECL_NAME(type_decl) = data[0];
    SCM_RETURN(type_decl);
}

ScmObj Scm_IdentifierDeclarator(ScmObj name)
{
    ScmDeclarator *z = SCM_NEW(ScmDeclarator);
    SCM_SET_CLASS(z, SCM_CLASS_DECLARATOR);
    z->func = identifier_declarator;
    z->data[0] = name;
    z->data[1] = SCM_UNBOUND;
    SCM_RETURN(SCM_OBJ(z));
}

ScmObj Scm_ToInt(ScmObj v)
{
    if (SCM_REALP(v)) {
        SCM_RETURN(Scm_RoundToExact(v, SCM_ROUND_FLOOR));
    } else {
        SCM_RETURN(SCM_LIST3(SCM_LIST3(SYM(with_module), SYM(c_wrapper_c_ffi), SYM(cast)),
                             SYM(integer),
                             v));
    }
}

static ScmObj array_declarator(ScmObj type_decl, ScmObj *data)
{
    ScmObj type = SCM_TYPE_DECL_CTYPE(type_decl);
    ScmObj size = data[0];

    if (!SCM_FALSEP(size)) {
        size = Scm_ToInt(size);
    }
    
    SCM_TYPE_DECL_CTYPE(type_decl) = SCM_LIST3(SYM(c_array), type, size);
    SCM_RETURN(type_decl);
}

ScmObj Scm_ArrayDeclarator(ScmObj size)
{
    ScmDeclarator *z = SCM_NEW(ScmDeclarator);
    SCM_SET_CLASS(z, SCM_CLASS_DECLARATOR);
    z->func = array_declarator;
    z->data[0] = size;
    z->data[1] = SCM_UNBOUND;
    SCM_RETURN(SCM_OBJ(z));
}

static ScmObj func_declarator(ScmObj type_decl, ScmObj *data)
{
    ScmObj type = SCM_TYPE_DECL_CTYPE(type_decl);
    ScmObj name_type_list = SCM_NIL;
    ScmObj args = data[0];
    ScmObj pair;

    SCM_FOR_EACH(pair, args) {
        name_type_list = Scm_Cons(SCM_LIST3(SYM(list), 
                                            SCM_LIST2(SYM(quote), SCM_TYPE_DECL_NAME(SCM_CAR(pair))),
                                            SCM_TYPE_DECL_CTYPE(SCM_CAR(pair))),
                                  name_type_list);
    }
    name_type_list = Scm_Reverse(name_type_list);

    SCM_TYPE_DECL_CTYPE(type_decl) = SCM_LIST3(SYM(c_func),
                                               type,
                                               Scm_Cons(SYM(list), name_type_list));
    SCM_RETURN(type_decl);
}

ScmObj Scm_FuncDeclarator(ScmObj args)
{
    ScmDeclarator *z = SCM_NEW(ScmDeclarator);
    SCM_SET_CLASS(z, SCM_CLASS_DECLARATOR);
    z->func = func_declarator;
    z->data[0] = args;
    z->data[1] = SCM_UNBOUND;
    SCM_RETURN(SCM_OBJ(z));
}    

static ScmObj func_vaargs_declarator(ScmObj type_decl, ScmObj *data)
{
    ScmObj type = SCM_TYPE_DECL_CTYPE(type_decl);
    ScmObj name_type_list = SCM_NIL;
    ScmObj args = data[0];
    ScmObj pair;

    SCM_FOR_EACH(pair, args) {
        name_type_list = Scm_Cons(SCM_LIST3(SYM(list), 
                                            SCM_LIST2(SYM(quote), SCM_TYPE_DECL_NAME(SCM_CAR(pair))),
                                            SCM_TYPE_DECL_CTYPE(SCM_CAR(pair))),
                                  name_type_list);
    }
    name_type_list = Scm_Reverse(name_type_list);

    SCM_TYPE_DECL_CTYPE(type_decl) = SCM_LIST3(SYM(c_func_vaargs),
                                               type,
                                               Scm_Cons(SYM(list), name_type_list));
    SCM_RETURN(type_decl);
}

ScmObj Scm_FuncVaargsDeclarator(ScmObj args)
{
    ScmDeclarator *z = SCM_NEW(ScmDeclarator);
    SCM_SET_CLASS(z, SCM_CLASS_DECLARATOR);
    z->func = func_vaargs_declarator;
    z->data[0] = args;
    z->data[1] = SCM_UNBOUND;
    SCM_RETURN(SCM_OBJ(z));
}    

static ScmObj ptr_declarator(ScmObj type_decl, ScmObj *data)
{
    ScmObj type = SCM_TYPE_DECL_CTYPE(type_decl);

    if (SCM_PAIRP(type)) {
        if (SCM_EQ(SCM_CAR(type), SYM(c_func))) {
            SCM_SET_CAR(type, SYM(c_func_ptr));
            SCM_RETURN(type_decl);
        } else if (SCM_EQ(SCM_CAR(type), SYM(c_func_vaargs))) {
            SCM_SET_CAR(type, SYM(c_func_vaargs_ptr));
            SCM_RETURN(type_decl);
        }
    }
    SCM_TYPE_DECL_CTYPE(type_decl)
        = SCM_LIST2(SCM_LIST3(SYM(with_module),
                              SYM(c_wrapper_c_ffi),
                              SYM(ptr)),
                    type);
    SCM_RETURN(type_decl);
}

ScmObj Scm_PtrDeclarator()
{
    ScmDeclarator *z = SCM_NEW(ScmDeclarator);
    SCM_SET_CLASS(z, SCM_CLASS_DECLARATOR);
    z->func = ptr_declarator;
    z->data[0] = SCM_UNBOUND;
    z->data[1] = SCM_UNBOUND;
    SCM_RETURN(SCM_OBJ(z));
}

static ScmObj bit_field_declarator(ScmObj type_decl, ScmObj *data)
{
    static int counter = 0;
    char numbuf[50];
    ScmObj type = SCM_TYPE_DECL_CTYPE(type_decl);
    ScmObj n = data[0];
    
    SCM_TYPE_DECL_CTYPE(type_decl) = SCM_LIST3(SYM(c_bit_field), type, n);
    if (SCM_FALSEP(SCM_TYPE_DECL_NAME(type_decl))) {
        int nc = snprintf(numbuf, sizeof(numbuf), "%d", counter++);
        SCM_TYPE_DECL_NAME(type_decl)
            = Scm_Intern(SCM_STRING(Scm_StringAppendC(SCM_STRING(SCM_MAKE_STR_IMMUTABLE("%")),
                                                      numbuf,
                                                      nc,
                                                      nc)));
    }
    SCM_RETURN(type_decl);
}

ScmObj Scm_BitFieldDeclarator(ScmObj n)
{
    ScmDeclarator *z = SCM_NEW(ScmDeclarator);
    SCM_SET_CLASS(z, SCM_CLASS_DECLARATOR);
    z->func = bit_field_declarator;
    z->data[0] = n;
    z->data[1] = SCM_UNBOUND;
    SCM_RETURN(SCM_OBJ(z));
}    

static ScmObj init_value_declarator(ScmObj type_decl, ScmObj *data)
{
    SCM_TYPE_DECL_INIT_VALUE(type_decl) = data[0];
    SCM_RETURN(type_decl);
}

ScmObj Scm_InitValueDeclarator(ScmObj v)
{
    ScmDeclarator *z = SCM_NEW(ScmDeclarator);
    SCM_SET_CLASS(z, SCM_CLASS_DECLARATOR);
    z->func = init_value_declarator;
    z->data[0] = v;
    z->data[1] = SCM_UNBOUND;
    SCM_RETURN(SCM_OBJ(z));
}    

static ScmObj null_declarator(ScmObj type_decl, ScmObj *data)
{
    SCM_RETURN(type_decl);
}

ScmObj Scm_NullDeclarator()
{
    static ScmDeclarator *z = NULL;

    if (!z) {
        z = SCM_NEW(ScmDeclarator);
        SCM_SET_CLASS(z, SCM_CLASS_DECLARATOR);
        z->func = null_declarator;
        z->data[0] = SCM_UNBOUND;
        z->data[1] = SCM_UNBOUND;
    }
    SCM_RETURN(SCM_OBJ(z));
}
        
static ScmObj size2mode(int size)
{
    switch (size) {
    case 1:
        SCM_RETURN(SYM(QI));
    case 2:
        SCM_RETURN(SYM(HI));
    case 4:
        SCM_RETURN(SYM(SI));
    case 8:
        SCM_RETURN(SYM(DI));
    default:
        Scm_Error("invalid size %S", SCM_MAKE_INT(size));
    }

    /* NOTREACHED */
    SCM_RETURN(SCM_FALSE);
}

static ScmObj compose_variable_attribute(ScmObj type_decl, ScmObj *data)
{
    ScmObj attr_list = data[0];
    ScmObj declarator = data[1];
    ScmObj type = SCM_TYPE_DECL_CTYPE(type_decl);
    int unsigned_p = SCM_BOOL_VALUE(Scm_Memq(type, SCM_LIST5(SYM(c_uchar),
                                                             SYM(c_ushort),
                                                             SYM(c_uint),
                                                             SYM(c_ulong),
                                                             SYM(c_ulonglong))));
    ScmObj mode;

    mode = Scm_Assq(SYM(mode), attr_list);
    if (SCM_FALSEP(mode)) {
        mode = Scm_Assq(SYM(__mode__), attr_list);
    }
    if (!SCM_FALSEP(mode)) {
        mode = SCM_CADR(mode);
    }

    if (!SCM_FALSEP(Scm_Memq(mode, SCM_LIST2(SYM(word), SYM(__word__))))) {
        int dmy __attribute__((__mode__(__word__)));
        mode = size2mode(sizeof(dmy));
    } else if (!SCM_FALSEP(Scm_Memq(mode, SCM_LIST2(SYM(pointer), SYM(__pointer__))))) {
        int dmy __attribute__((__mode__(__pointer__)));
        mode = size2mode(sizeof(dmy));
    }

    if (!SCM_FALSEP(mode)) {
        if (!SCM_FALSEP(Scm_Memq(mode, SCM_LIST4(SYM(QI), SYM(__QI__), SYM(byte), SYM(__byte__))))) {
            if (unsigned_p) {
                SCM_TYPE_DECL_CTYPE(type_decl) = SYM(c_uchar);
            } else {
                SCM_TYPE_DECL_CTYPE(type_decl) = SYM(c_char);
            }
        } else if (!SCM_FALSEP(Scm_Memq(mode, SCM_LIST2(SYM(HI), SYM(__HI__))))) {
            if (unsigned_p) {
                SCM_TYPE_DECL_CTYPE(type_decl) = SYM(c_ushort);
            } else {
                SCM_TYPE_DECL_CTYPE(type_decl) = SYM(c_short);
            }
        } else if (!SCM_FALSEP(Scm_Memq(mode, SCM_LIST2(SYM(SI), SYM(__SI__))))) {
            if (unsigned_p) {
                SCM_TYPE_DECL_CTYPE(type_decl) = SYM(c_uint);
            } else {
                SCM_TYPE_DECL_CTYPE(type_decl) = SYM(c_int);
            }
        } else if (!SCM_FALSEP(Scm_Memq(mode, SCM_LIST2(SYM(DI), SYM(__DI__))))) {
            if (unsigned_p) {
                SCM_TYPE_DECL_CTYPE(type_decl) = SYM(c_ulonglong);
            } else {
                SCM_TYPE_DECL_CTYPE(type_decl) = SYM(c_longlong);
            }
        } else if (!SCM_FALSEP(Scm_Memq(mode, SCM_LIST2(SYM(SF), SYM(__SF__))))) {
            SCM_TYPE_DECL_CTYPE(type_decl) = SYM(c_float);
        } else if (!SCM_FALSEP(Scm_Memq(mode, SCM_LIST2(SYM(DF), SYM(__DF__))))) {
            SCM_TYPE_DECL_CTYPE(type_decl) = SYM(c_double);
        } 
    }
        
    SCM_RETURN(SCM_DECLARATOR(declarator)->func(type_decl, SCM_DECLARATOR(declarator)->data));
}
    
ScmObj Scm_ComposeVariableAttribute(ScmObj decl)
{
    ScmDeclarator *z = SCM_NEW(ScmDeclarator);
    SCM_SET_CLASS(z, SCM_CLASS_DECLARATOR);
    z->func = compose_variable_attribute;
    z->data[0] = Scm_ParserAttributeRef();
    z->data[1] = decl;
    Scm_ParserAttributeClear();
    SCM_RETURN(SCM_OBJ(z));
}    

ScmObj Scm_MakeTypeDeclList(ScmObj type_spec_list, ScmObj decls)
{
    ScmObj result = SCM_NIL;
    ScmObj pair;
    
    SCM_FOR_EACH(pair, decls) {
        result = Scm_Cons(Scm_MakeTypeDecl(type_spec_list, SCM_CAR(pair)), result);
    }
    SCM_RETURN(Scm_Reverse(result));
}

ScmObj Scm_ParameterDeclaration(ScmObj type_decl)
{
    ScmObj type;
    ScmObj name;

    CHECK_ARG(type_decl);

    type = SCM_TYPE_DECL_CTYPE(type_decl);
    if (SCM_PAIRP(type)) {
        /* ISO/IEC 9899:1999 6.7.5.3 */
        ScmObj car = SCM_CAR(type);
        if (SCM_EQ(SYM(c_func), car)) {
            SCM_SET_CAR(type, SYM(c_func_ptr));
        } else if (SCM_EQ(SYM(c_func_vaargs), car)) {
            SCM_SET_CAR(type, SYM(c_func_vaargs_ptr));
        }
    }

    name = SCM_TYPE_DECL_NAME(type_decl);
    if (!SCM_FALSEP(name)) {
        Scm_ArgPoolAdd(name);
    }

    SCM_RETURN(type_decl);
}

ScmObj Scm_Declaration(ScmObj type_spec_list, ScmObj declarator_list)
{
    ScmObj td_list;
    ScmObj pair;
    
    CHECK_ARG(type_spec_list);
    CHECK_ARG(declarator_list);

    Scm_ParserAttributeClear();
    td_list = Scm_MakeTypeDeclList(type_spec_list, declarator_list);
    SCM_FOR_EACH(pair, td_list) {
        Scm_ArgPoolAdd(SCM_TYPE_DECL_NAME(SCM_CAR(pair)));
    }

    SCM_RETURN(td_list);
}

ScmObj Scm_DefChunkDictInit()
{
    defchunk_dict.size = 0;
    defchunk_dict.chunk_vector = SCM_VECTOR(Scm_MakeVector(DEFCHUNK_VECTOR_INITIAL_SIZE, SCM_UNBOUND));
    defchunk_dict.identifier_table = SCM_HASH_TABLE(Scm_MakeHashTableSimple(SCM_HASH_EQ, 0));
    defchunk_dict.typename_table = SCM_HASH_TABLE(Scm_MakeHashTableSimple(SCM_HASH_EQUAL, 0));
}

static void defchunk_dict_add(ScmObj defchunk)
{
    int len = SCM_VECTOR_SIZE(defchunk_dict.chunk_vector);
    
    if (len <= defchunk_dict.size) {
        defchunk_dict.chunk_vector
            = SCM_VECTOR(Scm_VectorCopy(defchunk_dict.chunk_vector,
                                        0,
                                        defchunk_dict.size * DEFCHUNK_VECTOR_EXPAND_FACTOR,
                                        SCM_UNBOUND));
    }

    Scm_VectorSet(defchunk_dict.chunk_vector, defchunk_dict.size, defchunk);
    ++defchunk_dict.size;
}

    
ScmObj Scm_DefChunkDictSetIdentifier(ScmObj identifier, ScmObj defchunk)
{
    ScmObj holder;

    holder = Scm_HashTableRef(defchunk_dict.identifier_table, identifier, SCM_NIL);
    holder = Scm_Cons(defchunk, holder);
    Scm_HashTableSet(defchunk_dict.identifier_table, identifier, holder, 0);

    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_DefChunkDictSetTypename(ScmObj typename, ScmObj defchunk)
{
    ScmObj holder;

    holder = Scm_HashTableRef(defchunk_dict.typename_table, typename, SCM_NIL);
    holder = Scm_Cons(defchunk, holder);
    Scm_HashTableSet(defchunk_dict.typename_table, typename, holder, 0);

    SCM_RETURN(SCM_UNDEFINED);
}

static void defchunk_dict_set_mark(ScmObj defchunk)
{
    ScmObj typename_list = SCM_DEFCHUNK_REFERENCED_TYPENAME_LIST(defchunk);
    ScmObj identifier_list = SCM_DEFCHUNK_REFERENCED_IDENTIFIER_LIST(defchunk);
    ScmObj p1, p2;
    
    if (SCM_DEFCHUNK_IS_USED(defchunk)) {
        return;
    }

    SCM_DEFCHUNK_SET_USED(defchunk);

    SCM_FOR_EACH(p1, typename_list) {
        SCM_FOR_EACH(p2, Scm_HashTableRef(defchunk_dict.typename_table, SCM_CAR(p1), SCM_NIL)) {
            defchunk_dict_set_mark(SCM_CAR(p2));
        }
    }

    SCM_FOR_EACH(p1, identifier_list) {
        SCM_FOR_EACH(p2, Scm_HashTableRef(defchunk_dict.identifier_table, SCM_CAR(p1), SCM_NIL)) {
            defchunk_dict_set_mark(SCM_CAR(p2));
        }
    }
}

static ScmObj set_mark_cc(ScmObj result, void **data)
{
    int *pos_ptr = (int*) data[0];
    ScmObj proc = SCM_OBJ(data[1]);
    ScmObj defchunk = SCM_OBJ(data[2]);

    if (!SCM_FALSEP(result)) {
        defchunk_dict_set_mark(defchunk);
    }

    ++(*pos_ptr);
    if (*pos_ptr < defchunk_dict.size) {
        void *new_data[3];
        defchunk = Scm_VectorRef(defchunk_dict.chunk_vector, *pos_ptr, SCM_FALSE);
        new_data[0] = pos_ptr;
        new_data[1] = proc;
        new_data[2] = defchunk;
        Scm_VMPushCC(set_mark_cc, new_data, 3);
        SCM_RETURN(Scm_VMApply1(proc, defchunk));
    } else {
        SCM_RETURN(SCM_UNDEFINED);
    }
}

ScmObj Scm_DefChunkDictSetMark(ScmProcedure *proc)
{
    if (0 < defchunk_dict.size) {
        int *pos_ptr = SCM_NEW(int);
        void *data[3];
        ScmObj defchunk = Scm_VectorRef(defchunk_dict.chunk_vector, 0, SCM_FALSE);

        *pos_ptr = 0;
        data[0] = pos_ptr;
        data[1] = proc;
        data[2] = defchunk;
        Scm_VMPushCC(set_mark_cc, data, 3);
        SCM_RETURN(Scm_VMApply1(SCM_OBJ(proc), defchunk));
    } else {
        SCM_RETURN(SCM_UNDEFINED);
    }
}

static ScmObj defchunk2expr(ScmObj defchunk)
{
    ScmObj type = SCM_DEFCHUNK_TYPE(defchunk);
    ScmObj expr;

    if (SCM_EQ(type, SYM(S_alloc_struct))) {
        TYPE_COUNTUP(alloc_struct);
        SCM_RETURN(SCM_DEFCHUNK_OBJECT(defchunk));
    } else if (SCM_EQ(type, SYM(S_init_struct))) {
        TYPE_COUNTUP(init_struct);
        SCM_RETURN(SCM_DEFCHUNK_OBJECT(defchunk));
    } else if (SCM_EQ(type, SYM(S_alloc_union))) {
        TYPE_COUNTUP(alloc_union);
        SCM_RETURN(SCM_DEFCHUNK_OBJECT(defchunk));
    } else if (SCM_EQ(type, SYM(S_init_union))) {
        TYPE_COUNTUP(init_union);
        SCM_RETURN(SCM_DEFCHUNK_OBJECT(defchunk));
    } else if (SCM_EQ(type, SYM(S_define_enum))) {
        TYPE_COUNTUP(define_enum);
        SCM_RETURN(SCM_DEFCHUNK_OBJECT(defchunk));
    } else if (SCM_EQ(type, SYM(S_typedef))) {
        TYPE_COUNTUP(typedef);
        SCM_RETURN(SCM_DEFCHUNK_OBJECT(defchunk));
    } else if (SCM_EQ(type, SYM(S_define_inline))) {
        TYPE_COUNTUP(define_inline);
        SCM_RETURN(make_define_inline_expr(defchunk));
    } else if (SCM_EQ(type, SYM(S_define_extern))) {
        TYPE_COUNTUP(define_extern);
        SCM_RETURN(SCM_DEFCHUNK_OBJECT(defchunk));
    } else if (SCM_EQ(type, SYM(S_alloc_objc_class))) {
        TYPE_COUNTUP(alloc_objc_class);
        SCM_RETURN(SCM_DEFCHUNK_OBJECT(defchunk));
    } else if (SCM_EQ(type, SYM(S_init_objc_class))) {
        TYPE_COUNTUP(init_objc_class);
        SCM_RETURN(SCM_DEFCHUNK_OBJECT(defchunk));
    } else if (SCM_EQ(type, SYM(S_define_objc_method))) {
        TYPE_COUNTUP(define_objc_method);
        SCM_RETURN(SCM_DEFCHUNK_OBJECT(defchunk));
    } else if (SCM_EQ(type, SYM(S_define_cmacro))) {
        TYPE_COUNTUP(define_cmacro);
        SCM_RETURN(SCM_DEFCHUNK_OBJECT(defchunk));
    } else if (SCM_EQ(type, SYM(S_define_cfunclike_macro))) {
        TYPE_COUNTUP(define_cfunclike_macro);
        SCM_RETURN(SCM_DEFCHUNK_OBJECT(defchunk));
    }
}

static int defchunk_try_eval(ScmObj defchunk, ScmObj module)
{
    ScmObj type;

    if (SCM_FALSEP(defchunk)) {
        return FALSE;
    }

    type = SCM_DEFCHUNK_TYPE(defchunk);

    if (SCM_EQ(type, SYM(S_define_enum))) {
        ScmObj expr = defchunk2expr(defchunk);
        ScmObj sym = SCM_CADR(expr);
        ScmObj val = SCM_CAR(SCM_CDDR(expr));
        Scm_Define(SCM_MODULE(module), SCM_SYMBOL(sym), val);
        return TRUE;
    } else {
        ScmObj expr = defchunk2expr(defchunk);
        if (SCM_EQ(SCM_CAR(expr), SYM(S_define))) {
            ScmObj sym = SCM_CADR(expr);
            ScmObj val = SCM_CAR(SCM_CDDR(expr));
            if (SCM_SYMBOLP(val)) {
                Scm_Define(SCM_MODULE(module),
                           SCM_SYMBOL(sym),
                           Scm_GlobalVariableRef(SCM_MODULE(module), SCM_SYMBOL(val), FALSE));
                return TRUE;
            } else if (SCM_NUMBERP(val) || SCM_STRINGP(val)) {
                Scm_Define(SCM_MODULE(module), SCM_SYMBOL(sym), val);
                return TRUE;
            }
        }
    }

    return FALSE;
}

#define CONTINUE_IF_IMMEDIATE_EVAL(defchunk, module_or_proc)            \
    if (SCM_MODULEP(module_or_proc)) {                                  \
        if (defchunk_try_eval(defchunk, module_or_proc)) {              \
            continue;                                                   \
        } else {                                                        \
            break;                                                      \
        }                                                               \
    } else {                                                            \
        break;                                                          \
    }
    
static ScmObj defchunk_dict_for_each_cc(ScmObj result, void **data)
{
    int *pos_ptr = (int*) data[0];
    ScmObj module_or_proc = SCM_OBJ(data[1]);
    ScmObj all_flag = SCM_OBJ(data[2]);
    ScmObj defchunk;
    
    for (; (*pos_ptr < defchunk_dict.size); ++(*pos_ptr)) {
        defchunk = Scm_VectorRef(defchunk_dict.chunk_vector, *pos_ptr, SCM_FALSE);
        if (SCM_FALSEP(all_flag)) {
            if (SCM_DEFCHUNK_IS_USED(defchunk)) {
                CONTINUE_IF_IMMEDIATE_EVAL(defchunk, module_or_proc);
            } else {
                continue;
            }
        } else {
            CONTINUE_IF_IMMEDIATE_EVAL(defchunk, module_or_proc);
        }
    }
    
    if (*pos_ptr < defchunk_dict.size) {
        void *new_data[3];
        ScmObj expr;

        ++(*pos_ptr);
        new_data[0] = pos_ptr;
        new_data[1] = module_or_proc;
        new_data[2] = all_flag;
        Scm_VMPushCC(defchunk_dict_for_each_cc, new_data, 3);
        expr = defchunk2expr(defchunk);
        if (SCM_MODULEP(module_or_proc)) {
            SCM_RETURN(Scm_VMEval(expr, module_or_proc));
        } else {
            SCM_RETURN(Scm_VMApply1(module_or_proc, expr));
        }
    } else {
        SCM_RETURN(SCM_UNDEFINED);
    }
}

ScmObj Scm_DefChunkDictForEach(ScmObj proc, ScmObj all_flag)
{
    int *pos_ptr = SCM_NEW(int);
    ScmObj defchunk;
    ScmObj module_or_proc;

    if (SCM_FALSEP(proc)) {
        module_or_proc = ffi_sandbox_module();
    } else {
        module_or_proc = proc;
    }

    for (*pos_ptr = 0; (*pos_ptr < defchunk_dict.size); ++(*pos_ptr)) {
        defchunk = Scm_VectorRef(defchunk_dict.chunk_vector, *pos_ptr, SCM_FALSE);
        if (SCM_FALSEP(all_flag)) {
            if (SCM_DEFCHUNK_IS_USED(defchunk)) {
                CONTINUE_IF_IMMEDIATE_EVAL(defchunk, module_or_proc);
            } else {
                continue;
            }
        } else {
            CONTINUE_IF_IMMEDIATE_EVAL(defchunk, module_or_proc);
        }
    }
    
    if (*pos_ptr < defchunk_dict.size) {
        void *new_data[3];
        ScmObj expr;

        ++(*pos_ptr);
        
        new_data[0] = pos_ptr;
        new_data[1] = module_or_proc;
        new_data[2] = all_flag;
        Scm_VMPushCC(defchunk_dict_for_each_cc, new_data, 3);
        expr = defchunk2expr(defchunk);
        if (SCM_MODULEP(module_or_proc)) {
            SCM_RETURN(Scm_VMEval(expr, module_or_proc));
        } else {
            SCM_RETURN(Scm_VMApply1(module_or_proc, expr));
        }
    } else {
        SCM_RETURN(SCM_UNDEFINED);
    }
}

ScmObj Scm_DefChunkDictAllSymbols()
{
    ScmObj result = SCM_NIL;
    int i;

    for (i = 0; i < defchunk_dict.size; ++i) {
        ScmObj defchunk = Scm_VectorRef(defchunk_dict.chunk_vector, i, SCM_FALSE);
        ScmObj defchunk_syms = SCM_DEFCHUNK_SYMBOL_LIST(defchunk);
        ScmObj p;
        SCM_FOR_EACH(p, defchunk_syms) {
            ScmObj sym = SCM_CAR(p);
            result = Scm_Cons(sym, result);
        }
    }

    SCM_RETURN(result);
}

ScmObj Scm_MakeDefChunk(ScmObj type, ScmObj id, ScmObj sym_list, ScmObj obj)
{
    ScmObj vec = Scm_MakeVector(8, SCM_UNBOUND);

    SCM_DEFCHUNK_SET_TYPE(vec, type);
    SCM_DEFCHUNK_SET_UNUSED(vec);
    SCM_DEFCHUNK_SET_FILENAME(vec, Scm_FilenameRef());
    SCM_DEFCHUNK_SET_REFERENCED_TYPENAME_LIST(vec, Scm_ReferencedTypenameListRef());
    SCM_DEFCHUNK_SET_REFERENCED_IDENTIFIER_LIST(vec, Scm_ReferencedIdentifierListRef());
    SCM_DEFCHUNK_SET_IDENTIFIER(vec, id);
    SCM_DEFCHUNK_SET_SYMBOL_LIST(vec, sym_list);
    SCM_DEFCHUNK_SET_OBJECT(vec, obj);

    defchunk_dict_add(vec);

    SCM_RETURN(vec);
}

static ScmObj make_member_alist(ScmObj member_list)
{
    ScmObj p;
    ScmObj alist = SCM_LIST1(SYM(list));

    SCM_FOR_EACH(p, member_list) {
        ScmObj elem = SCM_CAR(p);
        alist = Scm_Cons(SCM_LIST3(SYM(cons),
                                   SCM_LIST2(SYM(quote), SCM_TYPE_DECL_NAME(elem)),
                                   SCM_TYPE_DECL_CTYPE(elem)),
                         alist);
    }
    SCM_RETURN(Scm_Reverse(alist));
}

ScmObj Scm_EmitAllocStruct(ScmObj tagname)
{
    if (is_struct_pool_exists(tagname)) {
        SCM_RETURN(SCM_UNDEFINED);
    }

    struct_pool_add(tagname);
    Scm_DefChunkDictSetTypename(tagname,
                                Scm_MakeDefChunk(SYM(S_alloc_struct),
                                                 tagname,
                                                 SCM_LIST1(Scm_CStructSymbol(tagname)),
                                                 SCM_LIST2(SYM(S_define_c_struct), tagname)));
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_EmitInitStruct(ScmObj tagname, ScmObj member_list)
{
    Scm_EmitAllocStruct(tagname);
    Scm_DefChunkDictSetTypename(tagname,
                                Scm_MakeDefChunk(SYM(S_init_struct),
                                                 tagname,
                                                 SCM_LIST1(Scm_CStructSymbol(tagname)),
                                                 SCM_LIST3(SYM(S_init_c_struct),
                                                           Scm_CStructSymbol(tagname),
                                                           make_member_alist(member_list))));
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_EmitAllocUnion(ScmObj tagname)
{
    if (is_union_pool_exists(tagname)) {
        SCM_RETURN(SCM_UNDEFINED);
    }

    union_pool_add(tagname);
    Scm_DefChunkDictSetTypename(tagname,
                                Scm_MakeDefChunk(SYM(S_alloc_union),
                                                 tagname,
                                                 SCM_LIST1(Scm_CUnionSymbol(tagname)),
                                                 SCM_LIST2(SYM(S_define_c_union), tagname)));
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_EmitInitUnion(ScmObj tagname, ScmObj member_list)
{
    Scm_EmitAllocUnion(tagname);
    Scm_DefChunkDictSetTypename(tagname,
                                Scm_MakeDefChunk(SYM(S_init_union),
                                                 tagname,
                                                 SCM_LIST1(Scm_CUnionSymbol(tagname)),
                                                 SCM_LIST3(SYM(S_init_c_union),
                                                           Scm_CUnionSymbol(tagname),
                                                           make_member_alist(member_list))));
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_EmitDefineEnum(ScmObj tagname, ScmObj enum_alist)
{
    ScmObj prev = SCM_MAKE_INT(-1);
    ScmObj p;

    SCM_FOR_EACH(p, enum_alist) {
        ScmObj identifier = SCM_CAAR(p);
        ScmObj v = SCM_CDAR(p);
        if (SCM_FALSEP(v)) {
            if (SCM_INTP(prev)) {
                v = SCM_MAKE_INT(SCM_INT_VALUE(prev) + 1);
            } else {
                v = SCM_LIST3(SYM(plus_op), SCM_LIST2(SYM(scm_cast), prev), SCM_MAKE_INT(1));
            }
        }
        Scm_RegisterIdentifier(identifier, v);
        Scm_DefChunkDictSetIdentifier(identifier,
                                      Scm_MakeDefChunk(SYM(S_define_enum),
                                                       identifier,
                                                       SCM_LIST1(identifier),
                                                       SCM_LIST3(SCM_LIST3(SYM(with_module),
                                                                           SYM(c_wrapper),
                                                                           SYM(S_define_enum)),
                                                                 identifier,
                                                                 v)));
        prev = v;
    }
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_EmitDefineInline(ScmObj declaration_specifiers, ScmObj declarator, ScmObj function_body)
{
    ScmObj declaration = Scm_MakeTypeDecl(declaration_specifiers, declarator);
    ScmObj ctype = SCM_TYPE_DECL_CTYPE(declaration);
    ScmObj identifier = SCM_TYPE_DECL_NAME(declaration);
    ScmObj vec = Scm_MakeVector(4, SCM_UNBOUND);

    Scm_VectorSet(SCM_VECTOR(vec), 0, declaration);
    Scm_VectorSet(SCM_VECTOR(vec), 1, ctype);
    Scm_VectorSet(SCM_VECTOR(vec), 2, identifier);
    Scm_VectorSet(SCM_VECTOR(vec), 3, function_body);
    
    Scm_DefChunkDictSetIdentifier(identifier,
                                  Scm_MakeDefChunk(SYM(S_define_inline),
                                                   identifier,
                                                   SCM_LIST1(identifier),
                                                   vec));
    Scm_RegisterIdentifier(identifier,
                           SCM_LIST3(SYM(lambda),
                                     SYM(args),
                                     SCM_LIST3(SYM(apply), identifier, SYM(args))));
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_EmitDefineObjcClass(ScmObj classname_list)
{
    ScmObj p;

    SCM_FOR_EACH(p, classname_list) {
        ScmObj classname = SCM_CAR(p);
        ScmObj sym;
        
        if (SCM_FALSEP(classname)) {
            continue;
        }

        Scm_InstallType(classname);
        sym = CParser_ctype2class_symbol(classname);
        Scm_DefChunkDictSetTypename(classname,
                                    Scm_MakeDefChunk(SYM(S_alloc_objc_class),
                                                     classname,
                                                     SCM_LIST1(sym),
                                                     SCM_LIST3(SYM(S_define),
                                                               sym,
                                                               Scm_CStructSymbol(SYM(objc_object)))));
        Scm_DefChunkDictSetTypename(classname,
                                    Scm_MakeDefChunk(SYM(S_init_objc_class),
                                                     classname,
                                                     SCM_LIST1(classname),
                                                     SCM_LIST3(SYM(S_define),
                                                               classname,
                                                               SCM_LIST2(SYM(objc_lookup_class),
                                                                         SCM_LIST2(SYM(quote), classname)))));
    }
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_EmitObjcMethod(ScmObj keywords, ScmObj type_list)
{
    ScmObj name = Scm_StringAppend(keywords);
    ScmObj lst = SCM_LIST1(SYM(list));
    ScmObj p;
    
    SCM_FOR_EACH(p, type_list) {
        lst = Scm_Cons(SCM_TYPE_DECL_CTYPE(SCM_CAR(p)), lst);
    }
    lst = Scm_Reverse(lst);
    
    Scm_MakeDefChunk(SYM(S_define_objc_method),
                     SCM_FALSE,
                     SCM_NIL,
                     SCM_LIST3(SYM(objc_register_method),
                               name,
                               lst));
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_EmitDefineCmacro(ScmObj name, ScmObj body)
{
    Scm_DefChunkDictSetIdentifier(name,
                                  Scm_MakeDefChunk(SYM(S_define_cmacro),
                                                   name,
                                                   SCM_LIST1(name),
                                                   SCM_LIST3(SYM(S_define), name, body)));
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_EmitDefineCfunclikeMacro(ScmObj name, ScmObj args, ScmObj body)
{
    Scm_DefChunkDictSetIdentifier(name,
                                  Scm_MakeDefChunk(SYM(S_define_cfunclike_macro),
                                                   name,
                                                   SCM_LIST1(name),
                                                   SCM_LIST4(SCM_LIST3(SYM(with_module),
                                                                       SYM(c_wrapper),
                                                                       SYM(S_define_cfunclike_macro)),
                                                             name,
                                                             args,
                                                             body)));
    SCM_RETURN(SCM_UNDEFINED);
}
                                                             
static void emit_typedef(ScmObj type_decl_list)
{
    ScmObj p;

    SCM_FOR_EACH(p, type_decl_list) {
        ScmObj v = SCM_CAR(p);
        ScmObj ctype = SCM_TYPE_DECL_CTYPE(v);
        ScmObj new_ctype = SCM_TYPE_DECL_NAME(v);
        ScmObj sym = CParser_ctype2class_symbol(new_ctype);

        Scm_DefChunkDictSetTypename(new_ctype,
                                    Scm_MakeDefChunk(SYM(S_typedef),
                                                     new_ctype,
                                                     SCM_LIST1(sym),
                                                     SCM_LIST3(SYM(S_define), sym, ctype)));
        Scm_InstallType(new_ctype);
    }
}

static void emit_define_extern(ScmObj declaration)
{
    ScmObj ctype = SCM_TYPE_DECL_CTYPE(declaration);
    ScmObj identifier = SCM_TYPE_DECL_NAME(declaration);
    ScmObj fnsym;
    ScmObj obj;
    ScmObj defchunk;
    
    if (SCM_FALSEP(ctype) || SCM_FALSEP(identifier)) {
        return;
    }

    fnsym = SCM_CAR(ctype);
    if (SCM_EQ(fnsym, SYM(c_func)) || SCM_EQ(fnsym, SYM(c_func_vaargs))) {
        ScmObj ret_type = SCM_CADR(ctype);
        ScmObj arg_types = SCM_LIST1(SYM(list));
        ScmObj p;
        SCM_FOR_EACH(p, SCM_CDR(SCM_CAR(SCM_CDDR(ctype)))) {
            arg_types = Scm_Cons(SCM_CAR(SCM_CDDR(SCM_CAR(p))), arg_types);
        }
        arg_types = Scm_Reverse(arg_types);
        obj = SCM_LIST4(SCM_EQ(fnsym, SYM(c_func)) ? SYM(make_c_func) : SYM(make_c_func_vaargs),
                        SCM_LIST2(SYM(quote), identifier),
                        ret_type,
                        arg_types);
    } else {
        obj = SCM_LIST3(SYM(make_c_var), SCM_LIST2(SYM(quote), identifier), ctype);
    }

    defchunk = Scm_MakeDefChunk(SYM(S_define_extern),
                                identifier,
                                SCM_LIST1(identifier),
                                SCM_LIST3(SYM(S_define), identifier, obj));
    Scm_DefChunkDictSetIdentifier(identifier, defchunk);
    Scm_RegisterIdentifier(identifier, obj);
}

ScmObj Scm_ExternalDeclaration(ScmObj declaration_specifiers, ScmObj init_declarator_list)
{
    ScmObj p;
    
    Scm_ParserAttributeClear();

    if (SCM_EQ(SCM_CAR(declaration_specifiers), SYM(U_typedef))) {
        emit_typedef(Scm_MakeTypeDeclList(SCM_CDR(declaration_specifiers), init_declarator_list));
    } else {
        SCM_FOR_EACH(p, init_declarator_list) {
            ScmObj init_declarator = SCM_CAR(p);
            ScmObj declaration = Scm_MakeTypeDecl(declaration_specifiers, init_declarator);
            emit_define_extern(declaration);
        }
    }
    SCM_RETURN(SCM_UNDEFINED);
}

static void parse_macro_body(ScmObj name, ScmObj args, ScmObj body_str)
{
    static ScmObj terminator = SCM_FALSE;
    ScmObj body;

    Scm_InitMacroParserState();

    if (SCM_FALSEP(body_str)) {
        return;
    }

    Scm_AllReferencedInfoClear();
    if (SCM_FALSEP(args)) {
        Scm_ArgPoolSet(SCM_NIL);
    } else {
        Scm_ArgPoolSet(args);
    }
    Scm_StartMacroSet();
    Scm_LastTokenSet(SCM_FALSE);
    if (SCM_FALSEP(terminator)) {
        terminator = SCM_MAKE_STR_IMMUTABLE(";\n");
    }
    Scm_SetInputString(SCM_STRING(Scm_StringAppend2(SCM_STRING(body_str), SCM_STRING(terminator))));
    CGrammar(SCM_FALSE);
    body = Scm_MacroBodyRef();

    if (SCM_FALSEP(body)) {
        /* DO NOTHING */
    } else if ((SCM_FALSEP(Scm_UseIteratorP()) && (!SCM_FALSEP(Scm_UseJumpP())))
        || (!SCM_FALSEP(Scm_UseReturnP()))) {
        /* DO NOTHING */
    } else if (SCM_FALSEP(args)) {
        if (SCM_PAIRP(body) && SCM_PAIRP(SCM_CDR(body))
            && SCM_EQ(SYM(scm_cast), SCM_CAR(body)) && SCM_EQ(SCM_CDDR(body), SCM_NIL)) {
            /* matched ('scm-cast v) */
            ScmObj v = SCM_CADR(body);
            if (!SCM_EQ(name, v)) {
                /* new_body = `(c-delay (lambda () (c-cast ,v)) ',v)) */
                ScmObj new_body = SCM_LIST3(SYM(c_delay),
                                            SCM_LIST3(SYM(lambda), SCM_NIL, SCM_LIST2(SYM(c_cast), v)),
                                            SCM_LIST2(SYM(quote), v));
                Scm_EmitDefineCmacro(name, new_body);
            }
        } else if (!SCM_EQ(name, body)) {
            Scm_EmitDefineCmacro(name, body);
        }
    } else {
        Scm_EmitDefineCfunclikeMacro(name, args, body);
    }
}

ScmObj Scm_ParseMacroCode(ScmObj in, ScmObj macro_list)
{
    static ScmObj trigger_line = SCM_FALSE;
    ScmObj line_str;
    ScmObj next_line_str; /* one line look-ahead */
    ScmObj skip_regex;

    /* skip the first line '# 1 "<stdin>"' */
    Scm_ReadLineUnsafe(SCM_PORT(in));

    if (SCM_FALSEP(trigger_line)) {
        trigger_line = SCM_MAKE_STR_IMMUTABLE("# 1 \"<stdin>\"");
    }
    
    while (!SCM_EOFP(line_str = Scm_ReadLineUnsafe(SCM_PORT(in)))) {
        if (Scm_StringEqual(SCM_STRING(trigger_line), SCM_STRING(line_str))) {
            break;
        }
    }

    // while (!SCM_EOFP(line_str = Scm_ReadLineUnsafe(SCM_PORT(in)))) {
    skip_regex = Scm_RegComp(SCM_STRING(SCM_MAKE_STR_IMMUTABLE("^# [0-9]+ \"<stdin>\"")), 0);
    line_str = Scm_ReadLineUnsafe(SCM_PORT(in));
    next_line_str = Scm_ReadLineUnsafe(SCM_PORT(in));
    while (!SCM_EOFP(line_str)) {
        /* skip lines starting with "# " and matching regexp and join with following line */
        while (!SCM_EOFP(next_line_str)
               && (SCM_STRING_LENGTH(next_line_str) > 2)
               && (Scm_StringRef(SCM_STRING(next_line_str), 0, 0) == 35)
               && (Scm_StringRef(SCM_STRING(next_line_str), 1, 0) == 32)
#if defined(SCM_REGEXP_MULTI_LINE)
               // for Gauche 0.9.9 or later
               && SCM_REGMATCHP(Scm_RegExec(SCM_REGEXP(skip_regex), SCM_STRING(next_line_str), SCM_UNDEFINED, SCM_UNDEFINED))) {
#else
               // for Gauche 0.9.8 or earlier
               && SCM_REGMATCHP(Scm_RegExec(SCM_REGEXP(skip_regex), SCM_STRING(next_line_str)))) {
#endif
            next_line_str = Scm_ReadLineUnsafe(SCM_PORT(in));
            if (!SCM_EOFP(next_line_str)) {
                line_str = Scm_StringAppend2(SCM_STRING(line_str), SCM_STRING(next_line_str));
                next_line_str = Scm_ReadLineUnsafe(SCM_PORT(in));
            }
        }
        // Scm_Printf(SCM_CURERR, "line_str = %S\n", line_str);
        if (SCM_NULLP(macro_list)) {
            // Scm_Error("[bug] lost macro body");
            Scm_Error("[bug] more cpp output than expected");
        } else {
            ScmObj pos_name_args = SCM_CDAR(macro_list);
            macro_list = SCM_CDR(macro_list);
            Scm_FilenameSet(SCM_CAAR(pos_name_args));
            Scm_LineNumberSet(SCM_INT_VALUE(SCM_CDAR(pos_name_args)));
            parse_macro_body(SCM_CADR(pos_name_args), SCM_CDDR(pos_name_args), line_str);
            line_str = next_line_str;
            next_line_str = Scm_ReadLineUnsafe(SCM_PORT(in));
        }
    }
    if (!(SCM_NULLP(macro_list))) {
        Scm_Error("[bug] less cpp output than expected");
    }

    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_BridgeSymbols(ScmObj module, ScmObj syms, ScmObj hides)
{
    ScmObj ffi_sandbox = ffi_sandbox_module();
    
    if (SCM_FALSEP(syms)) {
        int i;
        for (i = 0; i < defchunk_dict.size; ++i) {
            ScmObj defchunk = Scm_VectorRef(defchunk_dict.chunk_vector, i, SCM_FALSE);
            ScmObj defchunk_syms = SCM_DEFCHUNK_SYMBOL_LIST(defchunk);
            ScmObj p;
            SCM_FOR_EACH(p, defchunk_syms) {
                ScmObj sym = SCM_CAR(p);
                if (SCM_FALSEP(Scm_Memq(sym, hides))) {
                    Scm_Define(SCM_MODULE(module), SCM_SYMBOL(sym),
                               Scm_GlobalVariableRef(SCM_MODULE(ffi_sandbox),
                                                     SCM_SYMBOL(sym),
                                                     0));
                }
            }
        }
    } else {
        ScmObj p;
        SCM_FOR_EACH(p, syms) {
            ScmObj sym = SCM_CAR(p);
            if (SCM_FALSEP(Scm_Memq(sym, hides))) {
                Scm_Define(SCM_MODULE(module), SCM_SYMBOL(sym),
                           Scm_GlobalVariableRef(SCM_MODULE(ffi_sandbox),
                                                 SCM_SYMBOL(sym),
                                                 0));
            }
        }
    }

    SCM_RETURN(SCM_UNDEFINED);
}

/* a workaround for ansidecl.h */
#if defined(CONST)
#undef CONST
#endif
#if defined(SIGNED)
#undef SIGNED
#endif
#if defined(UNSIGNED)
#undef UNSIGNED
#endif

#include "y.tab.c"

static ScmObj error_proc = SCM_UNBOUND;

int yylex()
{
    ScmObj result;
    ScmObj token;
    ScmObj token_value;

    START_PROFILE(yylex);

    {
        START_PROFILE(c_scan);
        result = Scm_CScan();
        END_PROFILE(c_scan);
    }
    if (SCM_PAIRP(result)) {
        token = SCM_CAR(result);
        yylval = SCM_CDR(result);
    } else {
        token = result;
        yylval = SCM_UNBOUND;
    }
    token_value = Scm_HashTableRef(SCM_HASH_TABLE(token_table), token, SCM_UNBOUND);
    if (SCM_UNBOUNDP(token_value)) {
        Scm_Error("Invalid token %S", token);
    }

    END_PROFILE(yylex);

    return SCM_INT_VALUE(token_value);
}

int yyerror(const char *str)
{
    macro_body = SCM_FALSE;
    if (!SCM_FALSEP(error_proc)) {
        Scm_ApplyRec(error_proc, SCM_LIST1(SCM_MAKE_STR_IMMUTABLE(str)));
    }
    return 0;
}

ScmObj CGrammar(ScmObj error_reporter)
{
    int result;

    if (!SCM_PROCEDUREP(error_reporter) && !SCM_FALSEP(error_reporter)) {
        Scm_Error("<procedure> or #f required, but got %S", error_reporter);
    }

    error_proc = error_reporter;

    init_parser();

    result = yyparse();

    SCM_RETURN(SCM_MAKE_INT(result));
}
    
/*
 * Module initialization function.
 */
extern void Scm_Init_c_parserlib(ScmModule*);

ScmObj Scm_Init_c_parser(void)
{
    ScmModule *mod;

    /* Register this DSO to Gauche */
    SCM_INIT_EXTENSION(c_parser);

    /* Create the module if it doesn't exist yet. */
    mod = SCM_MODULE(SCM_FIND_MODULE(CPARSER_MODULE_NAME, TRUE));

    /* Register stub-generated procedures */
    Scm_Init_c_parserlib(mod);

    INIT_SYM(plus_op, "+");
    INIT_SYM(with_module, "with-module");
    INIT_SYM(c_wrapper, "c-wrapper");
    INIT_SYM(c_wrapper_c_ffi, "c-wrapper.c-ffi");
    INIT_SYM(c_wrapper_objc_ffi, "c-wrapper.objc-ffi");
    INIT_SYM(ptr, "ptr");
    INIT_SYM(quote, "quote");
    INIT_SYM(char, "char");
    INIT_SYM(U_signed, "SIGNED");
    INIT_SYM(U_unsigned, "UNSIGNED");
    INIT_SYM(short, "short");
    INIT_SYM(int, "int");
    INIT_SYM(long, "long");
    INIT_SYM(float, "float");
    INIT_SYM(double, "double");
    INIT_SYM(void, "void");
    INIT_SYM(_Bool, "_Bool");
    INIT_SYM(__builtin_va_list, "__builtin_va_list");
    INIT_SYM(U_struct, "STRUCT");
    INIT_SYM(U_union, "UNION");
    INIT_SYM(U_enum, "ENUM");
    INIT_SYM(c_char, "<c-char>");
    INIT_SYM(c_uchar, "<c-uchar>");
    INIT_SYM(c_short, "<c-short>");
    INIT_SYM(c_ushort, "<c-ushort>");
    INIT_SYM(c_int, "<c-int>");
    INIT_SYM(c_uint, "<c-uint>");
    INIT_SYM(c_long, "<c-long>");
    INIT_SYM(c_ulong, "<c-ulong>");
    INIT_SYM(c_longlong, "<c-longlong>");
    INIT_SYM(c_ulonglong, "<c-ulonglong>");
    INIT_SYM(c_float, "<c-float>");
    INIT_SYM(c_double, "<c-double>");
    INIT_SYM(c_longdouble, "<c-longdouble>");
    INIT_SYM(c_void, "<c-void>");
    INIT_SYM(c_struct, "c-struct");
    INIT_SYM(c_union, "c-union");
    INIT_SYM(c_enum, "c-enum");
    INIT_SYM(c_array, "c-array");
    INIT_SYM(c_func, "c-func");
    INIT_SYM(c_func_vaargs, "c-func-vaargs");
    INIT_SYM(c_func_ptr, "c-func-ptr");
    INIT_SYM(c_func_vaargs_ptr, "c-func-vaargs-ptr");
    INIT_SYM(c_bit_field, "c-bit-field");
    INIT_SYM(U_typedef, "TYPEDEF");
    INIT_SYM(cast, "cast");
    INIT_SYM(scm_cast, "scm-cast");
    INIT_SYM(integer, "<integer>");
    INIT_SYM(list, "list");
    INIT_SYM(cons, "cons");
    INIT_SYM(lambda, "lambda");
    INIT_SYM(args, "args");
    INIT_SYM(apply, "apply");
    INIT_SYM(mode, "mode");
    INIT_SYM(__mode__, "__mode__");
    INIT_SYM(QI, "QI");
    INIT_SYM(__QI__, "__QI__");
    INIT_SYM(HI, "HI");
    INIT_SYM(__HI__, "__HI__");
    INIT_SYM(SI, "SI");
    INIT_SYM(__SI__, "__SI__");
    INIT_SYM(DI, "DI");
    INIT_SYM(__DI__, "__DI__");
    INIT_SYM(SF, "SF");
    INIT_SYM(__SF__, "__SF__");
    INIT_SYM(DF, "DF");
    INIT_SYM(__DF__, "__DF__");
    INIT_SYM(byte, "byte");
    INIT_SYM(__byte__, "__byte__");
    INIT_SYM(word, "word");
    INIT_SYM(__word__, "__word__");
    INIT_SYM(pointer, "pointer");
    INIT_SYM(__pointer__, "__pointer__");
    INIT_SYM(S_alloc_struct, "alloc-struct");
    INIT_SYM(S_init_struct, "init-struct");
    INIT_SYM(S_alloc_union, "alloc-union");
    INIT_SYM(S_init_union, "init-union");
    INIT_SYM(S_define_enum, "define-enum");
    INIT_SYM(S_typedef, "typedef");
    INIT_SYM(S_define_inline, "define-inline");
    INIT_SYM(S_define_extern, "define-extern");
    INIT_SYM(S_alloc_objc_class, "alloc-objc-class");
    INIT_SYM(S_init_objc_class, "init-objc-class");
    INIT_SYM(S_define_objc_method, "define-objc-method");
    INIT_SYM(S_define_cmacro, "define-cmacro");
    INIT_SYM(S_define_cfunclike_macro, "define-cfunclike-macro");
    INIT_SYM(S_define, "define");
    INIT_SYM(c_func, "c-func");
    INIT_SYM(make_c_func, "make-c-func");
    INIT_SYM(c_func_vaargs, "c-func-vaargs");
    INIT_SYM(make_c_func_vaargs, "make-c-func-vaargs");
    INIT_SYM(make_c_var, "make-c-var");
    INIT_SYM(S_identity, "identity");
    INIT_SYM(S_define_c_struct, "define-c-struct");
    INIT_SYM(S_define_c_union, "define-c-union");
    INIT_SYM(S_init_c_struct, "init-c-struct!");
    INIT_SYM(S_init_c_union, "init-c-union!");
    INIT_SYM(objc_object, "objc_object");
    INIT_SYM(objc_lookup_class, "objc-lookup-class");
    INIT_SYM(objc_register_method, "objc-register-method");
    INIT_SYM(c_delay, "c-delay");
    INIT_SYM(c_cast, "c-cast");

    arg_pool = SCM_NIL;
    value_pool = SCM_FALSE;
    referenced_identifier_list = SCM_NIL;
    referenced_typename_list = SCM_NIL;

#ifdef USE_PROFILER
    atexit(show_profile_result);
#endif
#ifdef USE_EVAL_COUNTER
    atexit(show_eval_counter);
#endif
}

/* end of file */
