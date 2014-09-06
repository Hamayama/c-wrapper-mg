/**
 *  c-parser.h 
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

/* Prologue */
#ifndef GAUCHE_CWRAPPER_PARSER_H
#define GAUCHE_CWRAPPER_PARSER_H

#include <gauche.h>
#include <gauche/extend.h>
#include "c-lex.h"
#include "c-ffi.h"
#include "util.h"

SCM_DECL_BEGIN

#define CPARSER_MODULE_NAME "c-wrapper.c-parser"

/* declarator */
typedef ScmObj DeclaratorProc(ScmObj type_decl, ScmObj *data);

typedef struct ScmDeclaratorRec {
    SCM_HEADER;
    DeclaratorProc *func;
    ScmObj data[2];
} ScmDeclarator;

SCM_CLASS_DECL(Scm_DeclaratorClass);
#define SCM_CLASS_DECLARATOR (&Scm_DeclaratorClass)
#define SCM_DECLARATOR(obj) ((ScmDeclarator*)obj)
#define SCM_DECLARATORP(obj) SCM_XTYPEP(obj, SCM_CLASS_DECLARATOR)

/* type-decl */
typedef struct ScmTypeDeclRec {
    SCM_HEADER;
    ScmObj type;
    ScmObj name;
    ScmObj init_value;
} ScmTypeDecl;

SCM_CLASS_DECL(Scm_TypeDeclClass);
#define SCM_CLASS_TYPE_DECL (&Scm_TypeDeclClass)
#define SCM_TYPE_DECL(obj) ((ScmTypeDecl*)obj)
#define SCM_TYPE_DECL_P(obj) SCM_XTYPEP(obj, SCM_CLASS_TYPE_DECL)
#define SCM_TYPE_DECL_CTYPE(obj) (SCM_TYPE_DECL(obj)->type)
#define SCM_TYPE_DECL_NAME(obj) (SCM_TYPE_DECL(obj)->name)
#define SCM_TYPE_DECL_INIT_VALUE(obj) (SCM_TYPE_DECL(obj)->init_value)

/* DefChunk */

#define SCM_DEFCHUNK_TYPE(obj) Scm_VectorRef(SCM_VECTOR(obj), 0, SCM_FALSE)
#define SCM_DEFCHUNK_SET_TYPE(obj, type) Scm_VectorSet(SCM_VECTOR(obj), 0, type)
#define SCM_DEFCHUNK_IS_USED(obj) SCM_BOOL_VALUE(Scm_VectorRef(SCM_VECTOR(obj), 1, SCM_FALSE))
#define SCM_DEFCHUNK_SET_USED(obj) Scm_VectorSet(SCM_VECTOR(obj), 1, SCM_TRUE)
#define SCM_DEFCHUNK_SET_UNUSED(obj) Scm_VectorSet(SCM_VECTOR(obj), 1, SCM_FALSE)
#define SCM_DEFCHUNK_FILENAME(obj) Scm_VectorRef(SCM_VECTOR(obj), 2, SCM_FALSE)
#define SCM_DEFCHUNK_SET_FILENAME(obj, filename) Scm_VectorSet(SCM_VECTOR(obj), 2, filename)
#define SCM_DEFCHUNK_REFERENCED_TYPENAME_LIST(obj) Scm_VectorRef(SCM_VECTOR(obj), 3, SCM_NIL)
#define SCM_DEFCHUNK_SET_REFERENCED_TYPENAME_LIST(obj, list) Scm_VectorSet(SCM_VECTOR(obj), 3, list)
#define SCM_DEFCHUNK_REFERENCED_IDENTIFIER_LIST(obj) Scm_VectorRef(SCM_VECTOR(obj), 4, SCM_NIL)
#define SCM_DEFCHUNK_SET_REFERENCED_IDENTIFIER_LIST(obj, list) Scm_VectorSet(SCM_VECTOR(obj), 4, list)
#define SCM_DEFCHUNK_IDENTIFIER(obj) Scm_VectorRef(SCM_VECTOR(obj), 5, SCM_FALSE)
#define SCM_DEFCHUNK_SET_IDENTIFIER(obj, val) Scm_VectorSet(SCM_VECTOR(obj), 5, val)
#define SCM_DEFCHUNK_SYMBOL_LIST(obj) Scm_VectorRef(SCM_VECTOR(obj), 6, SCM_FALSE)
#define SCM_DEFCHUNK_SET_SYMBOL_LIST(obj, val) Scm_VectorSet(SCM_VECTOR(obj), 6, val)
#define SCM_DEFCHUNK_OBJECT(obj) Scm_VectorRef(SCM_VECTOR(obj), 7, SCM_FALSE)
#define SCM_DEFCHUNK_SET_OBJECT(obj, val) Scm_VectorSet(SCM_VECTOR(obj), 7, val)

extern ScmObj CParser_List(ScmObj v);
extern ScmObj CParser_Append(ScmObj v0, ScmObj v1);
extern ScmObj CParser_AddList(ScmObj v0, ScmObj v1);
extern ScmObj CParser_Typename(ScmObj v);
extern ScmObj CParser_ctype2class_symbol(ScmObj sym);
extern ScmObj Scm_ArgPoolRef();
extern ScmObj Scm_ArgPoolSet(ScmObj lst);
extern ScmObj Scm_ArgPoolAdd(ScmObj name);
extern ScmObj Scm_ArgPoolClear();
extern ScmObj Scm_InitValuePool();
extern ScmObj Scm_RegisterIdentifier(ScmObj name, ScmObj value);
extern ScmObj Scm_RegisteredIdentifierP(ScmObj name);
extern ScmObj Scm_LookupValue(ScmObj v);
extern ScmObj Scm_InitStructPool();
extern ScmObj Scm_InitUnionPool();
extern ScmObj Scm_InitMacroParserState();
extern ScmObj Scm_UseReturnP();
extern ScmObj Scm_UseReturnSet(ScmObj flag);
extern ScmObj Scm_UseJumpP();
extern ScmObj Scm_UseJumpSet(ScmObj flag);
extern ScmObj Scm_UseIteratorP();
extern ScmObj Scm_UseIteratorSet(ScmObj flag);
extern ScmObj Scm_MacroBodyRef();
extern ScmObj Scm_MacroBodySet(ScmObj body);
extern ScmObj Scm_ReferencedIdentifierListRef();
extern ScmObj Scm_ReferencedIdentifierListAdd(ScmObj identifier);
extern ScmObj Scm_ReferencedIdentifierListClear();
extern ScmObj Scm_ReferencedTypenameListRef();
extern ScmObj Scm_ReferencedTypenameListAdd(ScmObj typename);
extern ScmObj Scm_ReferencedTypenameListClear();
extern ScmObj Scm_AllReferencedInfoClear();
extern ScmObj Scm_ToInt(ScmObj v);
extern ScmObj Scm_MakeTypeDecl(ScmObj type_spec_list, ScmObj declarator);
extern ScmObj Scm_ComposeDeclarator(ScmObj d1, ScmObj d2);
extern ScmObj Scm_IdentifierDeclarator(ScmObj name);
extern ScmObj Scm_ArrayDeclarator(ScmObj size);
extern ScmObj Scm_FuncDeclarator(ScmObj args);
extern ScmObj Scm_FuncVaargsDeclarator(ScmObj args);
extern ScmObj Scm_PtrDeclarator();
extern ScmObj Scm_BitFieldDeclarator(ScmObj n);
extern ScmObj Scm_InitValueDeclarator(ScmObj v);
extern ScmObj Scm_NullDeclarator();
extern ScmObj Scm_ComposeVariableAttribute(ScmObj decl);
extern ScmObj Scm_MakeTypeDeclList(ScmObj type_spec_list, ScmObj decls);
extern ScmObj Scm_ParameterDeclaration(ScmObj type_decl);
extern ScmObj Scm_Declaration(ScmObj type_spec_list, ScmObj declarator_list);

extern ScmObj Scm_DefChunkDictInit();
extern ScmObj Scm_DefChunkDictSetIdentifier(ScmObj identifier, ScmObj defchunk);
extern ScmObj Scm_DefChunkDictSetTypename(ScmObj typename, ScmObj defchunk);
extern ScmObj Scm_DefChunkDictSetMark(ScmProcedure *proc);
extern ScmObj Scm_DefChunkDictForEach(ScmObj module_or_proc, ScmObj all_flag);
extern ScmObj Scm_DefChunkDictAllSymbols();

extern ScmObj Scm_MakeDefChunk(ScmObj type, ScmObj id, ScmObj sym, ScmObj obj);
extern ScmObj Scm_ExternalDeclaration(ScmObj declaration_specifiers, ScmObj init_declarator_list);
extern ScmObj Scm_EmitAllocStruct(ScmObj tagname);
extern ScmObj Scm_EmitInitStruct(ScmObj tagname, ScmObj member_list);
extern ScmObj Scm_EmitAllocUnion(ScmObj tagname);
extern ScmObj Scm_EmitInitUnion(ScmObj tagname, ScmObj member_list);
extern ScmObj Scm_EmitDefineEnum(ScmObj tagname, ScmObj enum_alist);
extern ScmObj Scm_EmitDefineInline(ScmObj declaration_specifiers, ScmObj declarator, ScmObj function_body);
extern ScmObj Scm_EmitDefineObjcClass(ScmObj classname_list);
extern ScmObj Scm_EmitObjcMethod(ScmObj keywords, ScmObj type_list);
extern ScmObj Scm_EmitDefineCmacro(ScmObj name, ScmObj body);
extern ScmObj Scm_EmitDefineCfunclikeMacro(ScmObj name, ScmObj args, ScmObj body);
extern ScmObj Scm_ParseMacroCode(ScmObj in, ScmObj macro_list);
extern ScmObj Scm_BridgeSymbols(ScmObj module, ScmObj syms, ScmObj hides);

extern ScmObj CGrammar(ScmObj error_reporter);

/* Epilogue */
SCM_DECL_END

#endif  /* GAUCHE_CWRAPPER_PARSER_H */

/* end of file */
