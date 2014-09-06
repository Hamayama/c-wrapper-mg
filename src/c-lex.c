/**
 *  c-lex.c
 *
 *   Copyright (c) 2006 KOGURO, Naoki (naoki@koguro.net)
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

#include "c-lex.h"

static ScmObj attribute_list = SCM_NIL;
static ScmObj input_port = SCM_FALSE;
static int is_force_identifier;
static int is_start_macro;
static int line_number;
static int line_position;
static const char first_line_buffer[] = {'\0'};
static const char *line_buffer;
static ScmObj current_filename;
static ScmObj last_token;

static ScmObj c_keyword_table;
static ScmObj c_operator_table;
static ScmObj type_table;
static ScmObj typename_list;

typedef enum {
    RADIX_OCTAL,
    RADIX_DECIMAL,
    RADIX_HEXADECIMAL,
} RadixMode;

DEFINE_SYM(asterisk);
DEFINE_SYM(ptr_op);

DEFINE_SYM(U_identifier);
DEFINE_SYM(U_attribute);
DEFINE_SYM(int);
DEFINE_SYM(long);
DEFINE_SYM(double);
DEFINE_SYM(char);
DEFINE_SYM(short);
DEFINE_SYM(float);
DEFINE_SYM(U_typename);
DEFINE_SYM(U_struct);
DEFINE_SYM(U_union);
DEFINE_SYM(U_at_interface);
DEFINE_SYM(eoi);
DEFINE_SYM(U_constant);
DEFINE_SYM(U_ellipsis);
DEFINE_SYM(U_unknown);
DEFINE_SYM(U_dot);
DEFINE_SYM(U_string);
DEFINE_SYM(U_objc_string);
DEFINE_SYM(U_comma);
DEFINE_SYM(U_colon);
DEFINE_SYM(U_semicolon);
DEFINE_SYM(U_lparen);
DEFINE_SYM(U_rparen);
DEFINE_SYM(U_lcbra);
DEFINE_SYM(U_rcbra);
DEFINE_SYM(U_lsbra);
DEFINE_SYM(U_rsbra);
DEFINE_SYM(U_or_op);
DEFINE_SYM(U_or_assign);
DEFINE_SYM(U_or);
DEFINE_SYM(U_start_macro);

DEFINE_PROC0(parse_attribute, "c-wrapper.c-lex", "parse-attribute");
DEFINE_PROC2(enqueue_macro, "c-wrapper.c-lex", "enqueue-macro!");

static inline ScmObj warning(ScmObj fmt, ScmObj arg_list)
{                                               
    static ScmObj _warning = SCM_UNBOUND;
    
    if (SCM_UNBOUNDP(_warning)) {                  
        _warning = SCM_SYMBOL_VALUE("c-wrapper.c-lex", "warning"); 
    }                                           

    SCM_RETURN(Scm_ApplyRec(_warning, arg_list));           
}

ScmObj Scm_ParserAttributeClear()
{
    attribute_list = SCM_NIL;
}

ScmObj Scm_ParserAttributeRef()
{
    SCM_RETURN(attribute_list);
}

ScmObj Scm_ParserAttributeAdd(ScmObj attr)
{
    attribute_list = Scm_Append2(attribute_list, attr);
    SCM_RETURN(SCM_UNDEFINED);
}

static void init_c_keyword_table()
{
    const char *tbl[][2] = {
        {"auto", "AUTO"},
        {"break", "BREAK"},
        {"case", "CASE"},
        {"const", "CONST"},
        {"__const", "CONST"},
        {"continue", "CONTINUE"},
        {"default", "DEFAULT"},
        {"do", "DO"},
        {"else", "ELSE"},
        {"enum", "ENUM"},
        {"extern", "EXTERN"},
        {"for", "FOR"},
        {"goto", "GOTO"},
        {"if", "IF"},
        {"register", "REGISTER"},
        {"return", "RETURN"},
        {"signed", "SIGNED"},
        {"__signed", "SIGNED"},
        {"sizeof", "SIZEOF"},
        {"static", "STATIC"},
        {"struct", "STRUCT"},
        {"switch", "SWITCH"},
        {"typedef", "TYPEDEF"},
        {"union", "UNION"},
        {"unsigned", "UNSIGNED"},
        {"__unsigned", "UNSIGNED"},
        {"volatile", "VOLATILE"},
        {"__volatile", "VOLATILE"},
        {"__volatile__", "VOLATILE"},
        {"while", "WHILE"},
        {"inline", "INLINE"},
        {"__inline", "INLINE"},
        {"__inline__", "INLINE"},
        {"asm", "ASM"},
        {"__asm", "ASM"},
        {"__asm__", "ASM"},
        {"__restrict", "RESTRICT"},
        {"__restrict__", "RESTRICT"},
        {"__extension__", "EXTENSION"},
        {"__attribute__", "ATTRIBUTE"},
        {"@interface", "AT_INTERFACE"},
        {"@implementation", "AT_IMPLEMENTATION"},
        {"@end", "AT_END"},
        {"@selector", "AT_SELECTOR"},
        {"@defs", "AT_DEFS"},
        {"@encode", "AT_ENCODE"},
        {"@public", "AT_PUBLIC"},
        {"@private", "AT_PRIVATE"},
        {"@protected", "AT_PROTECTED"},
        {"@package", "AT_PACKAGE"},
        {"@protocol", "AT_PROTOCOL"},
        {"@class", "AT_CLASS"},
        {"@compatibility_alias", "AT_ALIAS"},
        {"@throw", "AT_THROW"},
        {"@try", "AT_TRY"},
        {"@catch", "AT_CATCH"},
        {"@finally", "AT_FINALLY"},
        {"@synchronized", "AT_SYNCHRONIZED"},
        {"@property", "AT_PROPERTY"},
        {"@synthesize", "AT_SYNTHESIZE"},
        {"@dynamic", "AT_DYNAMIC"},
        {"@optional", "AT_OPTIONAL"},
        {"@required", "AT_REQUIRED"},
        {NULL, NULL},
    };
    int i;
    
    c_keyword_table = Scm_MakeHashTableSimple(SCM_HASH_EQ, 0);

    for (i = 0; tbl[i][0] != NULL; ++i) {
        Scm_HashTableSet(SCM_HASH_TABLE(c_keyword_table),
                         SCM_INTERN(tbl[i][0]),
                         SCM_INTERN(tbl[i][1]),
                         0);
    }
}

static void init_c_operator_table()
{
    c_operator_table = Scm_MakeHashTableSimple(SCM_HASH_STRING, 0);

    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("auto"),
                     SCM_INTERN("AUTO"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE(">>="),
                     SCM_INTERN("RIGHT_ASSIGN"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("<<="),
                     SCM_INTERN("LEFT_ASSIGN"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("+="),
                     SCM_INTERN("ADD_ASSIGN"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("-="),
                     SCM_INTERN("SUB_ASSIGN"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("*="),
                     SCM_INTERN("MUL_ASSIGN"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("/="),
                     SCM_INTERN("DIV_ASSIGN"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("%="),
                     SCM_INTERN("MOD_ASSIGN"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("&="),
                     SCM_INTERN("AND_ASSIGN"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("^="),
                     SCM_INTERN("XOR_ASSIGN"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("|="),
                     SCM_INTERN("OR_ASSIGN"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE(">>"),
                     SCM_INTERN("RIGHT_OP"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("<<"),
                     SCM_INTERN("LEFT_OP"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE(">"),
                     SCM_INTERN(">"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("<"),
                     SCM_INTERN("<"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("++"),
                     SCM_INTERN("INC_OP"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("--"),
                     SCM_INTERN("DEC_OP"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("->"),
                     SYM(ptr_op),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("&&"),
                     SCM_INTERN("AND_OP"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("||"),
                     SCM_INTERN("OR_OP"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("<="),
                     SCM_INTERN("LE_OP"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE(">="),
                     SCM_INTERN("GE_OP"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("=="),
                     SCM_INTERN("EQ_OP"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("!="),
                     SCM_INTERN("NE_OP"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("*"),
                     SYM(asterisk),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("/"),
                     SCM_INTERN("/"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("+"),
                     SCM_INTERN("+"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("-"),
                     SCM_INTERN("-"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("%"),
                     SCM_INTERN("%"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("&"),
                     SCM_INTERN("&"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("|"),
                     SCM_INTERN("OR") ,
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("^"),
                     SCM_INTERN("^"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("="),
                     SCM_INTERN("="),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("?"),
                     SCM_INTERN("?"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("!"),
                     SCM_INTERN("!"),
                     0);
    Scm_HashTableSet(SCM_HASH_TABLE(c_operator_table),
                     SCM_MAKE_STR_IMMUTABLE("~"),
                     SCM_INTERN("~"),
                     0);
}

static void init_type_table()
{
    const char *types[] = {
        "__builtin_va_list",
        "char",
        "short",
        "int",
        "long",
        "float",
        "double",
        "void",
        "_Bool",
        NULL,
    };
    int i;
    
    type_table = Scm_MakeHashTableSimple(SCM_HASH_EQ, 0);

    for (i = 0; types[i] != NULL; ++i) {
        Scm_HashTableSet(SCM_HASH_TABLE(type_table),
                         SCM_INTERN(types[i]),
                         SCM_TRUE,
                         0);
    }
}

static int is_type(ScmObj sym)
{
    SCM_RETURN(SCM_BOOL_VALUE(Scm_HashTableRef(SCM_HASH_TABLE(type_table), sym, SCM_FALSE)));
}

static void install_type(ScmObj sym)
{
    Scm_HashTableSet(SCM_HASH_TABLE(type_table), sym, SCM_TRUE, 0);
}

ScmObj Scm_InitTypeTable() {
    init_type_table();
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_InstallType(ScmObj sym)
{
    install_type(sym);
    SCM_RETURN(SCM_UNDEFINED);
}
    
static void buffer_eof()
{
    line_buffer = NULL;
}

static inline int buffer_eof_p()
{
    return (line_buffer == NULL);
}

static void buffer_read_line()
{
    ScmObj line_str;
    
    if (SCM_FALSEP(input_port)) {
        buffer_eof();
        return;
    }

    line_str = Scm_ReadLineUnsafe(SCM_PORT(input_port));
    if (SCM_EOFP(line_str)) {
        input_port = SCM_FALSE;
        buffer_eof();
        return;
    }

    line_buffer = Scm_GetStringConst(SCM_STRING(line_str));
    line_position = 0;
    ++line_number;
}
    
static inline void buffer_next_char()
{
    if (line_buffer[line_position] == '\0') {
        buffer_read_line();
    } else {
        ++line_position;
    }
}

static inline int buffer_peek_char()
{
    int c;

    if (buffer_eof_p()) {
        return -1;
    }

    c = ((unsigned char) line_buffer[line_position]);
    if (c == '\0') {
        return '\n';
    } else {
        return c;
    }
}

static inline int buffer_read_char()
{
    int c = buffer_peek_char();

    if (c != -1) {
        buffer_next_char();
    }

    return c;
}

ScmObj Scm_BufferReadChar()
{
    int c = buffer_read_char();

    if (c == -1) {
        SCM_RETURN(SCM_EOF);
    } else {
        SCM_RETURN(SCM_MAKE_CHAR(c));
    }
}

ScmObj Scm_BufferPeekChar()
{
    int c = buffer_peek_char();

    if (c == -1) {
        SCM_RETURN(SCM_EOF);
    } else {
        SCM_RETURN(SCM_MAKE_CHAR(c));
    }
}

ScmObj Scm_BufferNextChar()
{
    buffer_next_char();
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_SetInputPort(ScmObj port)
{
    if ((!SCM_PORTP(port))) {
        Scm_Error("<port> required, but got %S", port);
    }

    input_port = port;

    line_buffer = first_line_buffer;
    line_number = 0;
    line_position = 0;

    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_FreeInputPort()
{
    if (SCM_PORTP(input_port)) {
        input_port = SCM_FALSE;
    }
    buffer_eof();

    SCM_RETURN(SCM_UNDEFINED);
}
    
ScmObj Scm_SetInputString(ScmString *str)
{
    input_port = SCM_FALSE;
    line_buffer = Scm_GetStringConst(str);
    line_position = 0;

    SCM_RETURN(SCM_UNDEFINED);
}

static inline ScmObj get_keyword_val(ScmObj sym)
{
    SCM_RETURN(Scm_HashTableRef(SCM_HASH_TABLE(c_keyword_table), sym, SCM_FALSE));
}

static inline ScmObj get_operator_val(ScmObj str)
{
    SCM_RETURN(Scm_HashTableRef(SCM_HASH_TABLE(c_operator_table), str, SCM_FALSE));
}

ScmObj Scm_GetKeywordVal(ScmObj sym)
{
    SCM_RETURN(get_keyword_val(sym));
}

ScmObj Scm_GetOperatorVal(ScmObj sym)
{
    SCM_RETURN(get_operator_val(SCM_OBJ(SCM_SYMBOL_NAME(sym))));
}

ScmObj Scm_LineNumberRef()
{
    SCM_RETURN(SCM_MAKE_INT(line_number));
}

ScmObj Scm_LineNumberSet(int num)
{
    line_number = num;
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_FilenameRef()
{
    SCM_RETURN(current_filename);
}

ScmObj Scm_FilenameSet(ScmObj filename)
{
    current_filename = filename;
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_CurrentLineRef()
{
    if (line_buffer == NULL) {
        SCM_RETURN(SCM_FALSE);
    } else {
        SCM_RETURN(SCM_MAKE_STR_COPYING((char*) line_buffer));
    }
}

ScmObj Scm_LastTokenRef()
{
    SCM_RETURN(last_token);
}

ScmObj Scm_LastTokenSet(ScmObj token)
{
    last_token = token;
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_IsForceIdentifierRef()
{
    SCM_RETURN(SCM_MAKE_BOOL(is_force_identifier));
}

ScmObj Scm_IsForceIdentifierSet(ScmObj v)
{
    is_force_identifier = SCM_BOOL_VALUE(v);
    SCM_RETURN(SCM_UNDEFINED);
}
    
/*
  bit 0: initial identifier char
  bit 1: identifier char
  bit 2: operator char
*/

static unsigned char ctypes[] = {
 /* nul soh stx etx eot enq ack bel bs  ht  nl  vt  np  cr  so  si */
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
 /* dle dc1 dc2 dc3 dc4 nak syn etb can em  sub esc fs  gs  rs  us */
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
 /*     !   "   #   $   %   &   '   (   )   *   +   ,   -   .   /  */
    0,  4,  0,  0,  3,  4,  4,  0,  0,  0,  4,  4,  0,  4,  0,  4,
 /* 0   1   2   3   4   5   6   7   8   9   :   ;   <   =   >   ?  */
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  0,  0,  4,  4,  4,  4,
 /* @   A   B   C   D   E   F   G   H   I   J   K   L   M   N   O  */
    1,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,
 /* P   Q   R   S   T   U   V   W   X   Y   Z   [   \   ]   ^   _  */
    3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  0,  0,  0,  4,  3,
 /* `   a   b   c   d   e   f   g   h   i   j   k   l   m   n   o  */
    0,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,
 /* p   q   r   s   t   u   v   w   x   y   z   {   |   }   ~   del*/
    3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  0,  0,  0,  4,  0,
};

static inline int is_initial_identifier_char(int c)
{
    return (0 <= c && c < 128 && (ctypes[(unsigned char)c]&1));
}

static inline int is_identifier_char(int c)
{
    return (0 <= c && c < 128 && (ctypes[(unsigned char)c]&2));
}

static inline int is_operator_char(int c)
{
    return (0 <= c && c < 128 && (ctypes[(unsigned char)c]&4));
}

static inline int is_hex_digit_char(int c)
{
    return isxdigit(c);
}

static inline int is_octal_digit_char(int c)
{
    return ('0' <= c && c <= '7');
}

ScmObj Scm_CharHexDigit(ScmObj c)
{
    if (!SCM_CHARP(c)) {
        Scm_Error("<char> required, but got %S", c);
    }

    SCM_RETURN(SCM_MAKE_BOOL(is_hex_digit_char(SCM_CHAR_VALUE(c))));
}


ScmObj Scm_CharOctalDigit(ScmObj c)
{
    if (!SCM_CHARP(c)) {
        Scm_Error("<char> required, but got %S", c);
    }

    SCM_RETURN(SCM_MAKE_BOOL(is_octal_digit_char(SCM_CHAR_VALUE(c))));
}

static void skip_spaces()
{
    int c = buffer_peek_char();

    while ((c != -1) && isspace(c)) {
        buffer_next_char();
        c = buffer_peek_char();
    }
}

static void skip_line()
{
    buffer_read_line();
}

ScmObj Scm_SkipSpaces()
{
    skip_spaces();
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_SkipLine()
{
    skip_line();
    SCM_RETURN(SCM_UNDEFINED);
}

static ScmObj read_identifier(ScmDString *dstr)
{
    int c;
    ScmObj sym;
    ScmObj k;
    
    c = buffer_peek_char();
    while (is_identifier_char(c)) {
        buffer_next_char();
        Scm_DStringPutb(dstr, (char) c);
        c = buffer_peek_char();
    }

    sym = SCM_INTERN(Scm_DStringGetz(dstr));

    if (is_force_identifier) {
        SCM_RETURN(Scm_Cons(SYM(U_identifier), sym));
    }
    k = get_keyword_val(sym);
    if (!SCM_FALSEP(k)) {
        if (SCM_EQ(SYM(U_attribute), k)) {
            SCM_RETURN(parse_attribute());
        } else {
            SCM_RETURN(k);
        }
    } else if (!SCM_FALSEP(Scm_Memq(sym, typename_list))) {
        SCM_RETURN(Scm_Cons(SYM(U_typename), sym));
    } else if ((SCM_PAIRP(last_token) && SCM_EQ(SCM_CAR(last_token), SYM(U_typename)))
               || SCM_EQ(last_token, SYM(U_struct))
               || SCM_EQ(last_token, SYM(U_union))
               || SCM_EQ(last_token, SYM(asterisk))
               || SCM_EQ(last_token, SYM(ptr_op))
               || SCM_EQ(last_token, SYM(U_dot))) {
        SCM_RETURN(Scm_Cons(SYM(U_identifier), sym));
    } else if (SCM_EQ(last_token, SYM(U_at_interface))) {
        install_type(sym);
        SCM_RETURN(Scm_Cons(SYM(U_identifier), sym));
    } else if (is_type(sym)) {
        SCM_RETURN(Scm_Cons(SYM(U_typename), sym));
    } else {
        SCM_RETURN(Scm_Cons(SYM(U_identifier), sym));
    }        
}

ScmObj Scm_ReadIdentifier(ScmObj l)
{
    ScmDString ds;

    if ((!SCM_LISTP(l)) || SCM_NULLP(l)) {
        Scm_Error("<list> required, but got %S", l);
    }

    Scm_DStringInit(&ds);
    Scm_DStringPutb(&ds, (char) SCM_CHAR_VALUE(SCM_CAR(l)));

    SCM_RETURN(read_identifier(&ds));
}

static ScmObj read_operator(ScmDString *dstr)
{
    int c;
    ScmObj candidate;
    ScmObj k;

    candidate = get_operator_val(Scm_DStringGet(dstr, 0));

    c = buffer_peek_char();
    Scm_DStringPutb(dstr, (char) c);
    k = get_operator_val(Scm_DStringGet(dstr, 0));
    while (!SCM_FALSEP(k)) {
        candidate = k;
        buffer_next_char();
        c = buffer_peek_char();
        Scm_DStringPutb(dstr, (char) c);
        k = get_operator_val(Scm_DStringGet(dstr, 0));
    }

    SCM_RETURN(candidate);
}

ScmObj Scm_ReadOperator(ScmObj c)
{
    ScmDString ds;
    
    if ((!SCM_CHARP(c))) {
        Scm_Error("<char> required, but got %S", c);
    }

    Scm_DStringInit(&ds);
    Scm_DStringPutb(&ds, (char) SCM_CHAR_VALUE(c));

    SCM_RETURN(read_operator(&ds));
}

static int hexchar2integer(int c)
{
    static int vals[] = {
        /* nul soh stx etx eot enq ack bel bs  ht  nl  vt  np  cr  so  si */
           -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        /* dle dc1 dc2 dc3 dc4 nak syn etb can em  sub esc fs  gs  rs  us */
           -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        /*     !   "   #   $   %   &   '   (   )   *   +   ,   -   .   /  */
           -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        /* 0   1   2   3   4   5   6   7   8   9   :   ;   <   =   >   ?  */
           0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  -1, -1, -1, -1, -1, -1,
        /* @   A   B   C   D   E   F   G   H   I   J   K   L   M   N   O  */
           -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        /* P   Q   R   S   T   U   V   W   X   Y   Z   [   \   ]   ^   _  */
           -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        /* `   a   b   c   d   e   f   g   h   i   j   k   l   m   n   o  */
           -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        /* p   q   r   s   t   u   v   w   x   y   z   {   |   }   ~   del*/
           -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    };
    int v = -1;

    if (0 <= c && c <= 0x7f) {
        v = vals[c];
    }
    if (0 <= v) {
        return v;
    } else {
        Scm_Error("%S can not be hexchar, there must be a bug in lexer", SCM_MAKE_CHAR(c));
    }
}

static inline int readn(int n, int v0)
{
    int c = buffer_peek_char();
    int v = v0;
    int i;

    for (i = 0; (i < n) && is_octal_digit_char(c); ++i) {
        buffer_next_char();
        v = v*8 + hexchar2integer(c);
        c = buffer_peek_char();
    }
    return v;
}

static inline int readx()
{
    int c = buffer_peek_char();
    int v = 0;

    while (is_hex_digit_char(c)) {
        buffer_next_char();
        v = v*16 + hexchar2integer(c);
        c = buffer_peek_char();
    }

    return v;
}

static inline int range_check(int v)
{
    /* CARM: Sec 2.9, p41 */
    return (v == 0x24) || (v == 0x40) || (v == 0x60)
        || !(v < 0xa0) || ((0xd800 <= v) && (v <= 0xdfff));
}

static inline int readu()
{
    int c = buffer_peek_char();
    int n = 0;
    int v = 0;

    while (is_hex_digit_char(c)) {
        buffer_next_char();
        ++n;
        v = v*16 + hexchar2integer(c);
        c = buffer_peek_char();
    }

    if ((n != 4) && (n != 8)) {
        Scm_Error("Universal character name must be 4 or 8 hex-digit");
    }
    if (!range_check(v)) {
        Scm_Error("\\u%04x is not a valid universal character", v);
    }
    return v;
}

static inline int backslash(int c)
{
    int c1;
    
    if (c == '\\') {
        c = buffer_read_char();
        switch (c) {
        case 'n':
            return '\n';
        case 'x':
            c1 = buffer_peek_char();
            if (is_hex_digit_char(c1)) {
                return readx(c1);
            } else {
                Scm_Error("\\x must be followed by hex-digit, but got '%c'", c1);
            }
        case 't':
            return '\t';
        case 'u':
        case 'U':
            c1 = buffer_peek_char();
            if (is_hex_digit_char(c1)) {
                return c1;
            } else {
                Scm_Error("\\u must be followed by hex-digit, but got '%c'", c1);
            }
        case '0':; case '1':; case '2':; case '3':;
        case '4':; case '5':; case '6':; case '7':
            return readn(3, hexchar2integer(c));
        case '\'':; case '"':; case '\\':
            return c;
        case 'p':
            /* TODO: pascal string */
            return c;
        case 'a':
            /* BEL */
            return 0x07;
        case 'b':
            /* BS */
            return 0x08;
        case 'v':
            /* VT */
            return 0x0b;
        case 'f':
            /* NP */
            return 0x0c;
        case 'r':
            /* CR */
            return 0x0d;
        default:
            if ('a' <= c && c <= 'z') {
                warning(SCM_MAKE_STR_IMMUTABLE("Unknown lower case escape character is used: ~a"),
                        SCM_LIST1(SCM_MAKE_CHAR(c)));
                return c;
            } else if ('A' <= c && c <= 'Z') {
                warning(SCM_MAKE_STR_IMMUTABLE("No upper case escape character is defined: ~a"),
                        SCM_LIST1(SCM_MAKE_CHAR(c)));
                return c;
            } else {
                return buffer_read_char(c);
            }
        }
    } else {
        return c;
    }        
}

static ScmObj read_string_literal()
{
    int c;
    ScmDString ds;

    Scm_DStringInit(&ds);
    c = buffer_read_char();
    while (c != '"') {
        int cc;
        if (c == -1) {
            Scm_Error("missing double quote");
        }
        cc = backslash(c);
        assert(cc >= 0);
        do {
            SCM_DSTRING_PUTB(&ds, cc % 256);
            cc >>= 8;
        } while (cc != 0);
        c = buffer_read_char();
    }
    SCM_RETURN(Scm_DStringGet(&ds, 0));
}

static ScmObj read_character_constant()
{
    int c;
    long v = 0;
    ScmDString ds;

    Scm_DStringInit(&ds);
    c = buffer_read_char();
    while (c != '\'') {
        int cc;
        if (c == -1) {
            Scm_Error("missing quote");
        }
        cc = backslash(c);
        assert(cc >= 0);
        /*
          Meaning of Multicharacter constant is implementation
          dependent.  Here we implement a convention with left-to-right
          packing, which is  described in CARM pp. 31--32.
         */
        do {
            v = v * 256 + (cc % 256);
            cc >>= 8;
        } while (cc != 0);
        c = buffer_read_char();
    }
    SCM_RETURN(Scm_MakeInteger(v));
}

ScmObj Scm_ReadStringLiteral()
{
    SCM_RETURN(read_string_literal());
}

ScmObj Scm_ReadCharacterConstant()
{
    SCM_RETURN(read_character_constant());
}

static inline ScmObj rl2n_octal(ScmDString *dstr)
{
    const char *str = Scm_DStringGetz(dstr);
    char *endptr = NULL;
    long long v;
    int i;

    for (i = 0; str[i] != '\0'; ++i) {
        if (! ('0' <= str[i] && str[i] <= '7')) {
            Scm_Error("invalid char '%c' in octal", str[i]);
        }
    }

    v = strtoll(str, &endptr, 0);
    SCM_RETURN(Scm_MakeInteger64(v));
}

static inline ScmObj rl2n_flonum(ScmDString *dstr)
{
    const char *str = Scm_DStringGetz(dstr);
    char *endptr = NULL;
    double v;

    v = strtod(str, &endptr);
    SCM_RETURN(Scm_MakeFlonum(v));
}

static inline ScmObj rl2n(ScmDString *dstr)
{
    const char *str = Scm_DStringGetz(dstr);
    char *endptr = NULL;
    long long v;

    v = strtoll(str, &endptr, 0);
    SCM_RETURN(Scm_MakeInteger64(v));
}

static void skip_integer_suffix_char()
{
    int c = buffer_peek_char();

    while (c == 'u' || c == 'U' || c == 'l' || c == 'L') {
        buffer_next_char();
        c = buffer_peek_char();
    }
}

static ScmObj read_expnum(ScmDString *dstr, RadixMode mode)
{
    int c = buffer_peek_char();

    if (! (isdigit(c) || (c == '+') || (c == '-'))) {
        Scm_Error("malformed floating point expression");
    }

    SCM_DSTRING_PUTB(dstr, (char) c);
    buffer_next_char();
    
    while (1) {
        c = buffer_peek_char();
        if (((mode == RADIX_DECIMAL) && isdigit(c))
            || ((mode == RADIX_HEXADECIMAL) && isxdigit(c))) {
            SCM_DSTRING_PUTB(dstr, (char) c);
            buffer_next_char();
            continue;
        }

        switch (c) {
        case 'f':
        case 'F':
            buffer_next_char();
            SCM_RETURN(rl2n_flonum(dstr));
        case 'l':
        case 'L':
            buffer_next_char();
            SCM_RETURN(rl2n_flonum(dstr));
        default:
            SCM_RETURN(rl2n_flonum(dstr));
        }
    }
}

static ScmObj read_flonum(ScmDString *dstr, RadixMode mode)
{
    int c;

    while (1) {
        c = buffer_peek_char();
        if (((mode == RADIX_DECIMAL) && isdigit(c))
            || ((mode == RADIX_HEXADECIMAL) && isxdigit(c))) {
            SCM_DSTRING_PUTB(dstr, (char) c);
            buffer_next_char();
            continue;
        }

        if (((mode == RADIX_DECIMAL) && (c == 'e' || c == 'E'))
            || ((mode == RADIX_HEXADECIMAL) && (c == 'p' || c == 'P'))) {
            SCM_DSTRING_PUTB(dstr, (char) c);
            buffer_next_char();
            SCM_RETURN(read_expnum(dstr, mode));
        }
            
        switch (c) {
        case 'f':
        case 'F':
            buffer_next_char();
            SCM_RETURN(rl2n_flonum(dstr));
        case 'l':
        case 'L':
            if (mode == RADIX_HEXADECIMAL) {
                Scm_Error("hexadecimal floating constants require an exponent");
            }
            buffer_next_char();
            SCM_RETURN(rl2n_flonum(dstr));
        default:
            if (mode == RADIX_HEXADECIMAL) {
                Scm_Error("hexadecimal floating constants require an exponent");
            }
            SCM_RETURN(rl2n_flonum(dstr));
        }
    }
}

static ScmObj read_octal_or_flonum(ScmDString *dstr)
{
    int c;

    while (1) {
        c = buffer_peek_char();
        if (isdigit(c)) {
            SCM_DSTRING_PUTB(dstr, (char) c);
            buffer_next_char();
            continue;
        }
            
        switch (c) {
        case '.':
            SCM_DSTRING_PUTB(dstr, (char) c);
            buffer_next_char();
            SCM_RETURN(read_flonum(dstr, RADIX_DECIMAL));
        case 'e':
        case 'E':
            SCM_DSTRING_PUTB(dstr, (char) c);
            buffer_next_char();
            SCM_RETURN(read_expnum(dstr, RADIX_DECIMAL));
        case 'U':; case 'u':;
        case 'L':; case 'l':;
            buffer_next_char();
            skip_integer_suffix_char();
            SCM_RETURN(rl2n_octal(dstr));
        default:
            SCM_RETURN(rl2n_octal(dstr));
        }
    }
}

static ScmObj read_number_constant(ScmDString *dstr, RadixMode mode)
{
    int c;

    while (1) {
        c = buffer_peek_char();
        if (((mode == RADIX_DECIMAL) && isdigit(c))
            || ((mode == RADIX_HEXADECIMAL) && isxdigit(c))) {
            SCM_DSTRING_PUTB(dstr, (char) c);
            buffer_next_char();
            continue;
        }

        if (((mode == RADIX_DECIMAL) && (c == 'e' || c == 'E'))
            || ((mode == RADIX_HEXADECIMAL) && (c == 'p' || c == 'P'))) {
            SCM_DSTRING_PUTB(dstr, (char) c);
            buffer_next_char();
            SCM_RETURN(read_expnum(dstr, mode));
        }
            
        switch (c) {
        case '.':
            SCM_DSTRING_PUTB(dstr, (char) c);
            buffer_next_char();
            SCM_RETURN(read_flonum(dstr, mode));
        case 'U':; case 'u':;
        case 'L':; case 'l':;
            buffer_next_char();
            skip_integer_suffix_char();
            SCM_RETURN(rl2n(dstr));
        default:
            SCM_RETURN(rl2n(dstr));
        }
    }
}

static ScmObj read_decimal(ScmDString *dstr)
{
    SCM_RETURN(read_number_constant(dstr, RADIX_DECIMAL));
}

static ScmObj read_hexadecimal(ScmDString *dstr)
{
    SCM_RETURN(read_number_constant(dstr, RADIX_HEXADECIMAL));
}

ScmObj Scm_ReadOctalOrFlonum(ScmObj l)
{
    ScmDString ds;

    if ((!SCM_LISTP(l)) || SCM_NULLP(l)) {
        Scm_Error("<list> required, but got %S", l);
    }

    Scm_DStringInit(&ds);
    Scm_DStringPutb(&ds, (char) SCM_CHAR_VALUE(SCM_CAR(l)));

    SCM_RETURN(read_octal_or_flonum(&ds));
}

ScmObj Scm_ReadDecimal(ScmObj l)
{
    ScmDString ds;

    if ((!SCM_LISTP(l)) || SCM_NULLP(l)) {
        Scm_Error("<list> required, but got %S", l);
    }

    Scm_DStringInit(&ds);
    Scm_DStringPutb(&ds, (char) SCM_CHAR_VALUE(SCM_CAR(l)));

    SCM_RETURN(read_decimal(&ds));
}

ScmObj Scm_ReadHexadecimal(ScmObj l)
{
    ScmDString ds;

    if ((!SCM_LISTP(l)) || SCM_NULLP(l)) {
        Scm_Error("<list> required, but got %S", l);
    }

    Scm_DStringInit(&ds);
    Scm_DStringPutb(&ds, (char) SCM_CHAR_VALUE(SCM_CAR(l)));

    SCM_RETURN(read_hexadecimal(&ds));
}

ScmObj Scm_ReadFlonum(ScmObj l, ScmObj ics, int radix, ScmObj ecs)
{
    ScmDString ds;
    RadixMode mode;
    
    if ((!SCM_LISTP(l)) || SCM_NULLP(l)) {
        Scm_Error("<list> required, but got %S", l);
    }

    if (radix == 10) {
        mode = RADIX_DECIMAL;
    } else if (radix == 16) {
        mode = RADIX_HEXADECIMAL;
    } else {
        Scm_Error("invalid radix: %d", radix);
    }
    
    Scm_DStringInit(&ds);
    SCM_DSTRING_PUTB(&ds, (char) SCM_CHAR_VALUE(SCM_CAR(l)));

    SCM_RETURN(read_flonum(&ds, mode));
}

static void sc_do_sharp_space()
{
    int c;
    
    skip_spaces();
    c = buffer_read_char();
    if (isdigit(c)) {
        ScmDString ds;
        ScmObj num;
        Scm_DStringInit(&ds);
        SCM_DSTRING_PUTB(&ds, (char) c);
        num = read_decimal(&ds);
        skip_spaces();
        c = buffer_read_char();
        if (c == '"') {
            Scm_FilenameSet(read_string_literal());
            Scm_LineNumberSet(Scm_GetInteger(num) - 1);
        }
    }
    skip_line();
}

static void sc_do_define()
{
    int c;
    
    skip_spaces();
    c = buffer_read_char();
    if (is_initial_identifier_char(c)) {
        ScmObj name;
        ScmObj args;
        ScmDString ds;
        is_force_identifier = TRUE;
        Scm_DStringInit(&ds);
        SCM_DSTRING_PUTB(&ds, (char) c);
        name = SCM_CDR(read_identifier(&ds));
        args = SCM_FALSE;
        if (buffer_peek_char() == '(') {
            buffer_next_char();
            args = SCM_NIL;
            skip_spaces();
            c = buffer_read_char();
            while (1) {
                if (c == ')') {
                    args = Scm_Reverse(args);
                    break;
                } else if (is_initial_identifier_char(c)) {
                    Scm_DStringInit(&ds);
                    SCM_DSTRING_PUTB(&ds, (char) c);
                    args = Scm_Cons(SCM_CDR(read_identifier(&ds)), args);
                    skip_spaces();
                    c = buffer_read_char();
                    continue;
                } else if (c == ',') {
                    skip_spaces();
                    c = buffer_read_char();
                    continue;
                } else {
                    goto finish;
                }
            }
        }
        enqueue_macro(name, args);
    }
finish:
    is_force_identifier = FALSE;
    skip_line();
}
    
static void do_sharp_command()
{
    if (buffer_peek_char() == ' ') {
        buffer_next_char();
        sc_do_sharp_space();
    } else {
        int c = buffer_peek_char();
        ScmDString ds;
        const char *str;
        Scm_DStringInit(&ds);
        while (isalpha(c)) {
            SCM_DSTRING_PUTB(&ds, (char) c);
            buffer_next_char();
            c = buffer_peek_char();
        }
        str = Scm_DStringGetz(&ds);
        if (strcmp("define", str) == 0) {
            sc_do_define();
        } else {
            skip_line();
        }
    }
}

ScmObj Scm_DoSharpCommand()
{
    do_sharp_command();
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_StartMacroSet()
{
    is_start_macro = TRUE;
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_StartMacroReset()
{
    is_start_macro = FALSE;
    SCM_RETURN(SCM_UNDEFINED);
}

ScmObj Scm_CScan()
{
    int c;
    ScmObj token = SCM_FALSE;

    if (is_start_macro) {
        is_start_macro = FALSE;
        token = SYM(U_start_macro);
    } else {
        skip_spaces();
        c = buffer_read_char();
    }
    while (SCM_FALSEP(token)) {
        if (is_initial_identifier_char(c)) {
            ScmDString ds;
            if (c == 'L') {
                int c0 = buffer_peek_char();
                if (c0 == '"') {
                    buffer_next_char();
                    token = Scm_Cons(SYM(U_string), read_string_literal());
                    break;
                } else if (c0 == '\'') {
                    buffer_next_char();
                    token = Scm_Cons(SYM(U_constant), read_character_constant());
                    break;
                }
            } else if (c == '@' && buffer_peek_char() == '"') {
                buffer_next_char();
                token = Scm_Cons(SYM(U_objc_string), read_string_literal());
                break;
            }
            Scm_DStringInit(&ds);
            SCM_DSTRING_PUTB(&ds, (char) c);
            token = read_identifier(&ds);
        } else if (c == '(') {
            token = SYM(U_lparen);
        } else if (c == ')') {
            token = SYM(U_rparen);
        } else if (is_operator_char(c)) {
            ScmDString ds;
            Scm_DStringInit(&ds);
            SCM_DSTRING_PUTB(&ds, (char) c);
            token = read_operator(&ds);
        } else if (c == ';') {
            token = SYM(U_semicolon);
        } else if (c == ',') {
            token = SYM(U_comma);
        } else if (c == '#') {
            do_sharp_command();
            skip_spaces();
            c = buffer_read_char();
        } else if (isdigit(c)) {
            ScmDString ds;
            if (c == '0') {
                int c0 = buffer_peek_char();
                ScmDString ds;
                Scm_DStringInit(&ds);
                SCM_DSTRING_PUTB(&ds, '0');
                if (c0 == 'x' || c0 == 'X') {
                    buffer_next_char();
                    SCM_DSTRING_PUTB(&ds, 'x');
                    token = Scm_Cons(SYM(U_constant), read_hexadecimal(&ds));
                } else {
                    token = Scm_Cons(SYM(U_constant), read_octal_or_flonum(&ds));
                }
            } else {
                Scm_DStringInit(&ds);
                SCM_DSTRING_PUTB(&ds, (char) c);
                token = Scm_Cons(SYM(U_constant), read_decimal(&ds));
            }
        } else if (c == '{') {
            token = SYM(U_lcbra);
        } else if (c == '}') {
            token = SYM(U_rcbra);
        } else if (c == ':') {
            token = SYM(U_colon);
        } else if (c == '"') {
            token = Scm_Cons(SYM(U_string), read_string_literal());
        } else if (c == '.') {
            int c0 = buffer_peek_char();
            if (c0 == '.') {
                buffer_next_char();
                if (buffer_peek_char() == '.') {
                    buffer_next_char();
                    token = SYM(U_ellipsis);
                } else {
                    token = SYM(U_unknown);
                }
            } else if (isdigit(c0)) {
                ScmDString ds;
                Scm_DStringInit(&ds);
                SCM_DSTRING_PUTB(&ds, (char) c);
                token = Scm_Cons(SYM(U_constant), read_flonum(&ds, RADIX_DECIMAL));
            } else {
                token = SYM(U_dot);
            }
        } else if (c == '[') {
            token = SYM(U_lsbra);
        } else if (c == ']') {
            token = SYM(U_rsbra);
        } else if (c == '|') {
            int c0 = buffer_peek_char();
            if (c0 == '|') {
                buffer_next_char();
                token = SYM(U_or_op);
            } else if (c0 == '=') {
                buffer_next_char();
                token = SYM(U_or_assign);
            } else {
                token = SYM(U_or);
            }
        } else if (c == '\'') {
            token = Scm_Cons(SYM(U_constant), read_character_constant());
        } else if (c == '\n') {
            skip_spaces();
            c = buffer_read_char();
        } else if (c == -1) {
            token = SYM(eoi);
        } else {
            warning(SCM_MAKE_STR_IMMUTABLE("illegal character: %S"), SCM_LIST1(SCM_MAKE_CHAR(c)));
            skip_spaces();
            c = buffer_read_char();
        }
    }

    last_token = token;
    SCM_RETURN(token);
}

/*
 * Module initialization function.
 */
extern void Scm_Init_c_lexlib(ScmModule*);

ScmObj Scm_Init_c_lex(void)
{
    ScmModule *mod;

    /* Register this DSO to Gauche */
    SCM_INIT_EXTENSION(c_lex);

    /* Create the module if it doesn't exist yet. */
    mod = SCM_MODULE(SCM_FIND_MODULE(CLEX_MODULE_NAME, TRUE));

    /* Register stub-generated procedures */
    Scm_Init_c_lexlib(mod);

    INIT_SYM(asterisk, "*");
    INIT_SYM(ptr_op, "PTR_OP");

    init_c_keyword_table();
    init_c_operator_table();

    INIT_SYM(U_identifier, "IDENTIFIER");
    INIT_SYM(U_attribute, "ATTRIBUTE");
    INIT_SYM(int, "int");
    INIT_SYM(long, "long");
    INIT_SYM(double, "double");
    INIT_SYM(char, "char");
    INIT_SYM(short, "short");
    INIT_SYM(float, "float");
    INIT_SYM(U_typename, "TYPENAME");
    INIT_SYM(U_struct, "STRUCT");
    INIT_SYM(U_union, "UNION");
    INIT_SYM(U_at_interface, "AT_INTERFACE");
    INIT_SYM(eoi, "*eoi*");
    INIT_SYM(U_constant, "CONSTANT");
    INIT_SYM(U_ellipsis, "ELLIPSIS");
    INIT_SYM(U_unknown, "UNKNOWN");
    INIT_SYM(U_dot, "DOT");
    INIT_SYM(U_string, "STRING");
    INIT_SYM(U_objc_string, "OBJC_STRING");
    INIT_SYM(U_comma, "COMMA");
    INIT_SYM(U_colon, "COLON");
    INIT_SYM(U_semicolon, "SEMICOLON");
    INIT_SYM(U_lparen, "LPAREN");
    INIT_SYM(U_rparen, "RPAREN");
    INIT_SYM(U_lcbra, "LCBRA");
    INIT_SYM(U_rcbra, "RCBRA");
    INIT_SYM(U_lsbra, "LSBRA");
    INIT_SYM(U_rsbra, "RSBRA");
    INIT_SYM(U_or_op, "OR_OP");
    INIT_SYM(U_or_assign, "OR_ASSIGN");
    INIT_SYM(U_or, "OR");
    INIT_SYM(U_start_macro, "START_MACRO");

    typename_list = Scm_Cons(SYM(int), SCM_LIST5(SYM(long), SYM(double), SYM(char), SYM(short), SYM(float)));
}

/* end of file */
