/**
 *  c-lex.h
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
 *   $Id: $
 */

/* Prologue */
#ifndef GAUCHE_CWRAPPER_LEX_H
#define GAUCHE_CWRAPPER_LEX_H

#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <gauche.h>
#include <gauche/extend.h>
#include "util.h"

SCM_DECL_BEGIN

#define CLEX_MODULE_NAME "c-wrapper.c-lex"

extern ScmObj Scm_ParserAttributeClear();
extern ScmObj Scm_ParserAttributeRef();
extern ScmObj Scm_ParserAttributeAdd(ScmObj attr);
extern ScmObj Scm_BufferReadChar();
extern ScmObj Scm_BufferPeekChar();
extern ScmObj Scm_BufferNextChar();
extern ScmObj Scm_SetInputPort(ScmObj port);
extern ScmObj Scm_FreeInputPort();
extern ScmObj Scm_SetInputString(ScmString *str);
extern ScmObj Scm_GetKeywordVal(ScmObj sym);
extern ScmObj Scm_GetOperatorVal(ScmObj sym);
extern ScmObj Scm_InitTypeTable();
extern ScmObj Scm_InstallType(ScmObj sym);
extern ScmObj Scm_LineNumberRef();
extern ScmObj Scm_LineNumberSet(int num);
extern ScmObj Scm_FilenameRef();
extern ScmObj Scm_FilenameSet(ScmObj filename);
extern ScmObj Scm_CurrentLineRef();
extern ScmObj Scm_CharHexDigit(ScmObj c);
extern ScmObj Scm_CharOctalDigit(ScmObj c);
extern ScmObj Scm_SkipSpaces();
extern ScmObj Scm_SkipLine();
extern ScmObj Scm_LastTokenRef();
extern ScmObj Scm_LastTokenSet(ScmObj token);
extern ScmObj Scm_IsForceIdentifierRef();
extern ScmObj Scm_IsForceIdentifierSet(ScmObj v);
extern ScmObj Scm_ReadIdentifier(ScmObj l);
extern ScmObj Scm_ReadOperator(ScmObj c);
extern ScmObj Scm_ReadStringLiteral();
extern ScmObj Scm_ReadCharacterConstant();
extern ScmObj Scm_ReadOctalOrFlonum(ScmObj l);
extern ScmObj Scm_ReadDecimal(ScmObj l);
extern ScmObj Scm_ReadHexadecimal(ScmObj l);
extern ScmObj Scm_ReadFlonum(ScmObj l, ScmObj ics, int radix, ScmObj ecs);
extern ScmObj Scm_DoSharpCommand();
extern ScmObj Scm_CScan();
extern ScmObj Scm_StartMacroSet();
extern ScmObj Scm_StartMacroReset();

/* Epilogue */
SCM_DECL_END

#endif  /* GAUCHE_CWRAPPER_LEX_H */

/* end of file */
