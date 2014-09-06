/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SEMICOLON = 258,
     COMMA = 259,
     LCBRA = 260,
     RCBRA = 261,
     LSBRA = 262,
     RSBRA = 263,
     LPAREN = 264,
     RPAREN = 265,
     OR = 266,
     DOT = 267,
     COLON = 268,
     _7e = 269,
     X = 270,
     _2b = 271,
     _ = 272,
     _2a = 273,
     _2f = 274,
     _5e = 275,
     _26 = 276,
     _25 = 277,
     _3d = 278,
     P = 279,
     _LT = 280,
     _GT = 281,
     IDENTIFIER = 282,
     CONSTANT = 283,
     STRING = 284,
     SIZEOF = 285,
     PTR_OP = 286,
     INC_OP = 287,
     DEC_OP = 288,
     LEFT_OP = 289,
     RIGHT_OP = 290,
     LE_OP = 291,
     GE_OP = 292,
     EQ_OP = 293,
     NE_OP = 294,
     AND_OP = 295,
     OR_OP = 296,
     MUL_ASSIGN = 297,
     DIV_ASSIGN = 298,
     MOD_ASSIGN = 299,
     ADD_ASSIGN = 300,
     SUB_ASSIGN = 301,
     LEFT_ASSIGN = 302,
     RIGHT_ASSIGN = 303,
     AND_ASSIGN = 304,
     XOR_ASSIGN = 305,
     OR_ASSIGN = 306,
     TYPENAME = 307,
     TYPEDEF = 308,
     EXTERN = 309,
     STATIC = 310,
     AUTO = 311,
     REGISTER = 312,
     INLINE = 313,
     RESTRICT = 314,
     SIGNED = 315,
     UNSIGNED = 316,
     CONST = 317,
     VOLATILE = 318,
     STRUCT = 319,
     UNION = 320,
     ENUM = 321,
     ELLIPSIS = 322,
     RANGE = 323,
     CASE = 324,
     DEFAULT = 325,
     IF = 326,
     ELSE = 327,
     SWITCH = 328,
     WHILE = 329,
     DO = 330,
     FOR = 331,
     GOTO = 332,
     CONTINUE = 333,
     BREAK = 334,
     RETURN = 335,
     ASM = 336,
     UNKNOWN = 337,
     EXTENSION = 338,
     AT_INTERFACE = 339,
     AT_IMPLEMENTATION = 340,
     AT_END = 341,
     AT_SELECTOR = 342,
     AT_DEFS = 343,
     AT_ENCODE = 344,
     AT_PUBLIC = 345,
     AT_PRIVATE = 346,
     AT_PROTECTED = 347,
     AT_PACKAGE = 348,
     AT_PROTOCOL = 349,
     AT_CLASS = 350,
     AT_ALIAS = 351,
     AT_THROW = 352,
     AT_TRY = 353,
     AT_CATCH = 354,
     AT_FINALLY = 355,
     AT_SYNCHRONIZED = 356,
     AT_PROPERTY = 357,
     AT_SYNTHESIZE = 358,
     AT_DYNAMIC = 359,
     AT_OPTIONAL = 360,
     AT_REQUIRED = 361,
     OBJC_STRING = 362,
     START_MACRO = 363
   };
#endif
/* Tokens.  */
#define SEMICOLON 258
#define COMMA 259
#define LCBRA 260
#define RCBRA 261
#define LSBRA 262
#define RSBRA 263
#define LPAREN 264
#define RPAREN 265
#define OR 266
#define DOT 267
#define COLON 268
#define _7e 269
#define X 270
#define _2b 271
#define _ 272
#define _2a 273
#define _2f 274
#define _5e 275
#define _26 276
#define _25 277
#define _3d 278
#define P 279
#define _LT 280
#define _GT 281
#define IDENTIFIER 282
#define CONSTANT 283
#define STRING 284
#define SIZEOF 285
#define PTR_OP 286
#define INC_OP 287
#define DEC_OP 288
#define LEFT_OP 289
#define RIGHT_OP 290
#define LE_OP 291
#define GE_OP 292
#define EQ_OP 293
#define NE_OP 294
#define AND_OP 295
#define OR_OP 296
#define MUL_ASSIGN 297
#define DIV_ASSIGN 298
#define MOD_ASSIGN 299
#define ADD_ASSIGN 300
#define SUB_ASSIGN 301
#define LEFT_ASSIGN 302
#define RIGHT_ASSIGN 303
#define AND_ASSIGN 304
#define XOR_ASSIGN 305
#define OR_ASSIGN 306
#define TYPENAME 307
#define TYPEDEF 308
#define EXTERN 309
#define STATIC 310
#define AUTO 311
#define REGISTER 312
#define INLINE 313
#define RESTRICT 314
#define SIGNED 315
#define UNSIGNED 316
#define CONST 317
#define VOLATILE 318
#define STRUCT 319
#define UNION 320
#define ENUM 321
#define ELLIPSIS 322
#define RANGE 323
#define CASE 324
#define DEFAULT 325
#define IF 326
#define ELSE 327
#define SWITCH 328
#define WHILE 329
#define DO 330
#define FOR 331
#define GOTO 332
#define CONTINUE 333
#define BREAK 334
#define RETURN 335
#define ASM 336
#define UNKNOWN 337
#define EXTENSION 338
#define AT_INTERFACE 339
#define AT_IMPLEMENTATION 340
#define AT_END 341
#define AT_SELECTOR 342
#define AT_DEFS 343
#define AT_ENCODE 344
#define AT_PUBLIC 345
#define AT_PRIVATE 346
#define AT_PROTECTED 347
#define AT_PACKAGE 348
#define AT_PROTOCOL 349
#define AT_CLASS 350
#define AT_ALIAS 351
#define AT_THROW 352
#define AT_TRY 353
#define AT_CATCH 354
#define AT_FINALLY 355
#define AT_SYNCHRONIZED 356
#define AT_PROPERTY 357
#define AT_SYNTHESIZE 358
#define AT_DYNAMIC 359
#define AT_OPTIONAL 360
#define AT_REQUIRED 361
#define OBJC_STRING 362
#define START_MACRO 363




/* Copy the first part of user declarations.  */
#line 1 "c-grammar.y"

#define YYSTYPE ScmObj
static ScmObj token_table = SCM_UNBOUND;
static ScmObj name_348 = SCM_UNBOUND;
static ScmObj name_346 = SCM_UNBOUND;
static ScmObj name_341 = SCM_UNBOUND;
static ScmObj name_340 = SCM_UNBOUND;
static ScmObj name_339 = SCM_UNBOUND;
static ScmObj name_337 = SCM_UNBOUND;
static ScmObj name_335 = SCM_UNBOUND;
static ScmObj name_331 = SCM_UNBOUND;
static ScmObj name_329 = SCM_UNBOUND;
static ScmObj name_324 = SCM_UNBOUND;
static ScmObj name_321 = SCM_UNBOUND;
static ScmObj name_313 = SCM_UNBOUND;
static ScmObj name_311 = SCM_UNBOUND;
static ScmObj name_306 = SCM_UNBOUND;
static ScmObj name_304 = SCM_UNBOUND;
static ScmObj name_302 = SCM_UNBOUND;
static ScmObj name_301 = SCM_UNBOUND;
static ScmObj name_288 = SCM_UNBOUND;
static ScmObj name_286 = SCM_UNBOUND;
static ScmObj name_284 = SCM_UNBOUND;
static ScmObj name_274 = SCM_UNBOUND;
static ScmObj name_272 = SCM_UNBOUND;
static ScmObj name_270 = SCM_UNBOUND;
static ScmObj name_257 = SCM_UNBOUND;
static ScmObj name_253 = SCM_UNBOUND;
static ScmObj name_196 = SCM_UNBOUND;
static ScmObj name_188 = SCM_UNBOUND;
static ScmObj name_179 = SCM_UNBOUND;
static ScmObj name_178 = SCM_UNBOUND;
static ScmObj name_175 = SCM_UNBOUND;
static ScmObj name_167 = SCM_UNBOUND;
static ScmObj name_164 = SCM_UNBOUND;
static ScmObj name_151 = SCM_UNBOUND;
static ScmObj name_148 = SCM_UNBOUND;
static ScmObj name_145 = SCM_UNBOUND;
static ScmObj name_142 = SCM_UNBOUND;
static ScmObj name_139 = SCM_UNBOUND;
static ScmObj name_136 = SCM_UNBOUND;
static ScmObj name_133 = SCM_UNBOUND;
static ScmObj name_130 = SCM_UNBOUND;
static ScmObj name_128 = SCM_UNBOUND;
static ScmObj name_125 = SCM_UNBOUND;
static ScmObj name_123 = SCM_UNBOUND;
static ScmObj name_121 = SCM_UNBOUND;
static ScmObj name_119 = SCM_UNBOUND;
static ScmObj name_116 = SCM_UNBOUND;
static ScmObj name_114 = SCM_UNBOUND;
static ScmObj name_111 = SCM_UNBOUND;
static ScmObj name_109 = SCM_UNBOUND;
static ScmObj name_106 = SCM_UNBOUND;
static ScmObj name_104 = SCM_UNBOUND;
static ScmObj name_102 = SCM_UNBOUND;
static ScmObj name_99 = SCM_UNBOUND;
static ScmObj name_89 = SCM_UNBOUND;
static ScmObj name_87 = SCM_UNBOUND;
static ScmObj name_85 = SCM_UNBOUND;
static ScmObj name_83 = SCM_UNBOUND;
static ScmObj name_81 = SCM_UNBOUND;
static ScmObj name_76 = SCM_UNBOUND;
static ScmObj name_74 = SCM_UNBOUND;
static ScmObj name_72 = SCM_UNBOUND;
static ScmObj name_70 = SCM_UNBOUND;
static ScmObj name_67 = SCM_UNBOUND;
static ScmObj name_65 = SCM_UNBOUND;
static ScmObj name_57 = SCM_UNBOUND;
static ScmObj name_55 = SCM_UNBOUND;
static ScmObj name_53 = SCM_UNBOUND;
static ScmObj name_49 = SCM_UNBOUND;
static ScmObj name_47 = SCM_UNBOUND;
static ScmObj name_43 = SCM_UNBOUND;
static ScmObj name_41 = SCM_UNBOUND;
static ScmObj name_36 = SCM_UNBOUND;
static ScmObj name_34 = SCM_UNBOUND;
static ScmObj name_27 = SCM_UNBOUND;
static ScmObj name_16 = SCM_UNBOUND;
static ScmObj name_11 = SCM_UNBOUND;
static ScmObj name_8 = SCM_UNBOUND;
static ScmObj name_1 = SCM_UNBOUND;
static ScmObj token_sym_START_MACRO = SCM_UNBOUND;
static ScmObj token_sym_OBJC_STRING = SCM_UNBOUND;
static ScmObj token_sym_AT_REQUIRED = SCM_UNBOUND;
static ScmObj token_sym_AT_OPTIONAL = SCM_UNBOUND;
static ScmObj token_sym_AT_DYNAMIC = SCM_UNBOUND;
static ScmObj token_sym_AT_SYNTHESIZE = SCM_UNBOUND;
static ScmObj token_sym_AT_PROPERTY = SCM_UNBOUND;
static ScmObj token_sym_AT_SYNCHRONIZED = SCM_UNBOUND;
static ScmObj token_sym_AT_FINALLY = SCM_UNBOUND;
static ScmObj token_sym_AT_CATCH = SCM_UNBOUND;
static ScmObj token_sym_AT_TRY = SCM_UNBOUND;
static ScmObj token_sym_AT_THROW = SCM_UNBOUND;
static ScmObj token_sym_AT_ALIAS = SCM_UNBOUND;
static ScmObj token_sym_AT_CLASS = SCM_UNBOUND;
static ScmObj token_sym_AT_PROTOCOL = SCM_UNBOUND;
static ScmObj token_sym_AT_PACKAGE = SCM_UNBOUND;
static ScmObj token_sym_AT_PROTECTED = SCM_UNBOUND;
static ScmObj token_sym_AT_PRIVATE = SCM_UNBOUND;
static ScmObj token_sym_AT_PUBLIC = SCM_UNBOUND;
static ScmObj token_sym_AT_ENCODE = SCM_UNBOUND;
static ScmObj token_sym_AT_DEFS = SCM_UNBOUND;
static ScmObj token_sym_AT_SELECTOR = SCM_UNBOUND;
static ScmObj token_sym_AT_END = SCM_UNBOUND;
static ScmObj token_sym_AT_IMPLEMENTATION = SCM_UNBOUND;
static ScmObj token_sym_AT_INTERFACE = SCM_UNBOUND;
static ScmObj token_sym_EXTENSION = SCM_UNBOUND;
static ScmObj token_sym_UNKNOWN = SCM_UNBOUND;
static ScmObj token_sym_ASM = SCM_UNBOUND;
static ScmObj token_sym_RETURN = SCM_UNBOUND;
static ScmObj token_sym_BREAK = SCM_UNBOUND;
static ScmObj token_sym_CONTINUE = SCM_UNBOUND;
static ScmObj token_sym_GOTO = SCM_UNBOUND;
static ScmObj token_sym_FOR = SCM_UNBOUND;
static ScmObj token_sym_DO = SCM_UNBOUND;
static ScmObj token_sym_WHILE = SCM_UNBOUND;
static ScmObj token_sym_SWITCH = SCM_UNBOUND;
static ScmObj token_sym_ELSE = SCM_UNBOUND;
static ScmObj token_sym_IF = SCM_UNBOUND;
static ScmObj token_sym_DEFAULT = SCM_UNBOUND;
static ScmObj token_sym_CASE = SCM_UNBOUND;
static ScmObj token_sym_RANGE = SCM_UNBOUND;
static ScmObj token_sym_ELLIPSIS = SCM_UNBOUND;
static ScmObj token_sym_ENUM = SCM_UNBOUND;
static ScmObj token_sym_UNION = SCM_UNBOUND;
static ScmObj token_sym_STRUCT = SCM_UNBOUND;
static ScmObj token_sym_VOLATILE = SCM_UNBOUND;
static ScmObj token_sym_CONST = SCM_UNBOUND;
static ScmObj token_sym_UNSIGNED = SCM_UNBOUND;
static ScmObj token_sym_SIGNED = SCM_UNBOUND;
static ScmObj token_sym_RESTRICT = SCM_UNBOUND;
static ScmObj token_sym_INLINE = SCM_UNBOUND;
static ScmObj token_sym_REGISTER = SCM_UNBOUND;
static ScmObj token_sym_AUTO = SCM_UNBOUND;
static ScmObj token_sym_STATIC = SCM_UNBOUND;
static ScmObj token_sym_EXTERN = SCM_UNBOUND;
static ScmObj token_sym_TYPEDEF = SCM_UNBOUND;
static ScmObj token_sym_TYPENAME = SCM_UNBOUND;
static ScmObj token_sym_OR_ASSIGN = SCM_UNBOUND;
static ScmObj token_sym_XOR_ASSIGN = SCM_UNBOUND;
static ScmObj token_sym_AND_ASSIGN = SCM_UNBOUND;
static ScmObj token_sym_RIGHT_ASSIGN = SCM_UNBOUND;
static ScmObj token_sym_LEFT_ASSIGN = SCM_UNBOUND;
static ScmObj token_sym_SUB_ASSIGN = SCM_UNBOUND;
static ScmObj token_sym_ADD_ASSIGN = SCM_UNBOUND;
static ScmObj token_sym_MOD_ASSIGN = SCM_UNBOUND;
static ScmObj token_sym_DIV_ASSIGN = SCM_UNBOUND;
static ScmObj token_sym_MUL_ASSIGN = SCM_UNBOUND;
static ScmObj token_sym_OR_OP = SCM_UNBOUND;
static ScmObj token_sym_AND_OP = SCM_UNBOUND;
static ScmObj token_sym_NE_OP = SCM_UNBOUND;
static ScmObj token_sym_EQ_OP = SCM_UNBOUND;
static ScmObj token_sym_GE_OP = SCM_UNBOUND;
static ScmObj token_sym_LE_OP = SCM_UNBOUND;
static ScmObj token_sym_RIGHT_OP = SCM_UNBOUND;
static ScmObj token_sym_LEFT_OP = SCM_UNBOUND;
static ScmObj token_sym_DEC_OP = SCM_UNBOUND;
static ScmObj token_sym_INC_OP = SCM_UNBOUND;
static ScmObj token_sym_PTR_OP = SCM_UNBOUND;
static ScmObj token_sym_SIZEOF = SCM_UNBOUND;
static ScmObj token_sym_STRING = SCM_UNBOUND;
static ScmObj token_sym_CONSTANT = SCM_UNBOUND;
static ScmObj token_sym_IDENTIFIER = SCM_UNBOUND;
static ScmObj token_sym__GT = SCM_UNBOUND;
static ScmObj token_sym__LT = SCM_UNBOUND;
static ScmObj token_sym_P = SCM_UNBOUND;
static ScmObj token_sym__3d = SCM_UNBOUND;
static ScmObj token_sym__25 = SCM_UNBOUND;
static ScmObj token_sym__26 = SCM_UNBOUND;
static ScmObj token_sym__5e = SCM_UNBOUND;
static ScmObj token_sym__2f = SCM_UNBOUND;
static ScmObj token_sym__2a = SCM_UNBOUND;
static ScmObj token_sym__ = SCM_UNBOUND;
static ScmObj token_sym__2b = SCM_UNBOUND;
static ScmObj token_sym_X = SCM_UNBOUND;
static ScmObj token_sym__7e = SCM_UNBOUND;
static ScmObj token_sym_COLON = SCM_UNBOUND;
static ScmObj token_sym_DOT = SCM_UNBOUND;
static ScmObj token_sym_OR = SCM_UNBOUND;
static ScmObj token_sym_RPAREN = SCM_UNBOUND;
static ScmObj token_sym_LPAREN = SCM_UNBOUND;
static ScmObj token_sym_RSBRA = SCM_UNBOUND;
static ScmObj token_sym_LSBRA = SCM_UNBOUND;
static ScmObj token_sym_RCBRA = SCM_UNBOUND;
static ScmObj token_sym_LCBRA = SCM_UNBOUND;
static ScmObj token_sym_COMMA = SCM_UNBOUND;
static ScmObj token_sym_SEMICOLON = SCM_UNBOUND;
#ifdef USE_PROFILER
static long long _profile_name_39_count = 0;
static long long _profile_name_39_time = 0;
static long long _profile_yylex_count = 0;
static long long _profile_yylex_time = 0;
static long long _profile_name_250_count = 0;
static long long _profile_name_250_time = 0;
static long long _profile_name_251_count = 0;
static long long _profile_name_251_time = 0;
static long long _profile_name_252_count = 0;
static long long _profile_name_252_time = 0;
static long long _profile_name_131_count = 0;
static long long _profile_name_131_time = 0;
static long long _profile_name_132_count = 0;
static long long _profile_name_132_time = 0;
static long long _profile_name_254_count = 0;
static long long _profile_name_254_time = 0;
static long long _profile_name_255_count = 0;
static long long _profile_name_255_time = 0;
static long long _profile_name_134_count = 0;
static long long _profile_name_134_time = 0;
static long long _profile_name_256_count = 0;
static long long _profile_name_256_time = 0;
static long long _profile_name_135_count = 0;
static long long _profile_name_135_time = 0;
static long long _profile_name_258_count = 0;
static long long _profile_name_258_time = 0;
static long long _profile_name_137_count = 0;
static long long _profile_name_137_time = 0;
static long long _profile_name_259_count = 0;
static long long _profile_name_259_time = 0;
static long long _profile_name_138_count = 0;
static long long _profile_name_138_time = 0;
static long long _profile_name_40_count = 0;
static long long _profile_name_40_time = 0;
static long long _profile_name_42_count = 0;
static long long _profile_name_42_time = 0;
static long long _profile_name_44_count = 0;
static long long _profile_name_44_time = 0;
static long long _profile_name_45_count = 0;
static long long _profile_name_45_time = 0;
static long long _profile_name_46_count = 0;
static long long _profile_name_46_time = 0;
static long long _profile_name_48_count = 0;
static long long _profile_name_48_time = 0;
static long long _profile_name_260_count = 0;
static long long _profile_name_260_time = 0;
static long long _profile_name_261_count = 0;
static long long _profile_name_261_time = 0;
static long long _profile_name_140_count = 0;
static long long _profile_name_140_time = 0;
static long long _profile_name_262_count = 0;
static long long _profile_name_262_time = 0;
static long long _profile_name_141_count = 0;
static long long _profile_name_141_time = 0;
static long long _profile_name_263_count = 0;
static long long _profile_name_263_time = 0;
static long long _profile_name_264_count = 0;
static long long _profile_name_264_time = 0;
static long long _profile_name_143_count = 0;
static long long _profile_name_143_time = 0;
static long long _profile_name_265_count = 0;
static long long _profile_name_265_time = 0;
static long long _profile_name_144_count = 0;
static long long _profile_name_144_time = 0;
static long long _profile_name_266_count = 0;
static long long _profile_name_266_time = 0;
static long long _profile_name_300_count = 0;
static long long _profile_name_300_time = 0;
static long long _profile_name_267_count = 0;
static long long _profile_name_267_time = 0;
static long long _profile_name_146_count = 0;
static long long _profile_name_146_time = 0;
static long long _profile_name_268_count = 0;
static long long _profile_name_268_time = 0;
static long long _profile_name_147_count = 0;
static long long _profile_name_147_time = 0;
static long long _profile_name_269_count = 0;
static long long _profile_name_269_time = 0;
static long long _profile_name_303_count = 0;
static long long _profile_name_303_time = 0;
static long long _profile_name_149_count = 0;
static long long _profile_name_149_time = 0;
static long long _profile_name_305_count = 0;
static long long _profile_name_305_time = 0;
static long long _profile_name_307_count = 0;
static long long _profile_name_307_time = 0;
static long long _profile_name_308_count = 0;
static long long _profile_name_308_time = 0;
static long long _profile_name_309_count = 0;
static long long _profile_name_309_time = 0;
static long long _profile_name_50_count = 0;
static long long _profile_name_50_time = 0;
static long long _profile_name_51_count = 0;
static long long _profile_name_51_time = 0;
static long long _profile_name_52_count = 0;
static long long _profile_name_52_time = 0;
static long long _profile_name_54_count = 0;
static long long _profile_name_54_time = 0;
static long long _profile_name_56_count = 0;
static long long _profile_name_56_time = 0;
static long long _profile_name_58_count = 0;
static long long _profile_name_58_time = 0;
static long long _profile_name_59_count = 0;
static long long _profile_name_59_time = 0;
static long long _profile_name_2_count = 0;
static long long _profile_name_2_time = 0;
static long long _profile_name_3_count = 0;
static long long _profile_name_3_time = 0;
static long long _profile_name_4_count = 0;
static long long _profile_name_4_time = 0;
static long long _profile_name_5_count = 0;
static long long _profile_name_5_time = 0;
static long long _profile_name_6_count = 0;
static long long _profile_name_6_time = 0;
static long long _profile_name_7_count = 0;
static long long _profile_name_7_time = 0;
static long long _profile_name_271_count = 0;
static long long _profile_name_271_time = 0;
static long long _profile_name_150_count = 0;
static long long _profile_name_150_time = 0;
static long long _profile_name_9_count = 0;
static long long _profile_name_9_time = 0;
static long long _profile_name_273_count = 0;
static long long _profile_name_273_time = 0;
static long long _profile_name_152_count = 0;
static long long _profile_name_152_time = 0;
static long long _profile_name_153_count = 0;
static long long _profile_name_153_time = 0;
static long long _profile_name_275_count = 0;
static long long _profile_name_275_time = 0;
static long long _profile_name_154_count = 0;
static long long _profile_name_154_time = 0;
static long long _profile_name_276_count = 0;
static long long _profile_name_276_time = 0;
static long long _profile_name_155_count = 0;
static long long _profile_name_155_time = 0;
static long long _profile_name_310_count = 0;
static long long _profile_name_310_time = 0;
static long long _profile_name_277_count = 0;
static long long _profile_name_277_time = 0;
static long long _profile_name_156_count = 0;
static long long _profile_name_156_time = 0;
static long long _profile_name_278_count = 0;
static long long _profile_name_278_time = 0;
static long long _profile_name_157_count = 0;
static long long _profile_name_157_time = 0;
static long long _profile_name_312_count = 0;
static long long _profile_name_312_time = 0;
static long long _profile_name_279_count = 0;
static long long _profile_name_279_time = 0;
static long long _profile_name_158_count = 0;
static long long _profile_name_158_time = 0;
static long long _profile_name_159_count = 0;
static long long _profile_name_159_time = 0;
static long long _profile_name_314_count = 0;
static long long _profile_name_314_time = 0;
static long long _profile_name_315_count = 0;
static long long _profile_name_315_time = 0;
static long long _profile_name_316_count = 0;
static long long _profile_name_316_time = 0;
static long long _profile_name_317_count = 0;
static long long _profile_name_317_time = 0;
static long long _profile_name_318_count = 0;
static long long _profile_name_318_time = 0;
static long long _profile_name_319_count = 0;
static long long _profile_name_319_time = 0;
static long long _profile_name_60_count = 0;
static long long _profile_name_60_time = 0;
static long long _profile_name_61_count = 0;
static long long _profile_name_61_time = 0;
static long long _profile_name_62_count = 0;
static long long _profile_name_62_time = 0;
static long long _profile_name_63_count = 0;
static long long _profile_name_63_time = 0;
static long long _profile_name_64_count = 0;
static long long _profile_name_64_time = 0;
static long long _profile_name_66_count = 0;
static long long _profile_name_66_time = 0;
static long long _profile_name_68_count = 0;
static long long _profile_name_68_time = 0;
static long long _profile_name_69_count = 0;
static long long _profile_name_69_time = 0;
static long long _profile_name_280_count = 0;
static long long _profile_name_280_time = 0;
static long long _profile_name_281_count = 0;
static long long _profile_name_281_time = 0;
static long long _profile_name_160_count = 0;
static long long _profile_name_160_time = 0;
static long long _profile_name_282_count = 0;
static long long _profile_name_282_time = 0;
static long long _profile_name_161_count = 0;
static long long _profile_name_161_time = 0;
static long long _profile_name_283_count = 0;
static long long _profile_name_283_time = 0;
static long long _profile_name_162_count = 0;
static long long _profile_name_162_time = 0;
static long long _profile_name_163_count = 0;
static long long _profile_name_163_time = 0;
static long long _profile_name_285_count = 0;
static long long _profile_name_285_time = 0;
static long long _profile_name_165_count = 0;
static long long _profile_name_165_time = 0;
static long long _profile_name_320_count = 0;
static long long _profile_name_320_time = 0;
static long long _profile_name_287_count = 0;
static long long _profile_name_287_time = 0;
static long long _profile_name_166_count = 0;
static long long _profile_name_166_time = 0;
static long long _profile_name_200_count = 0;
static long long _profile_name_200_time = 0;
static long long _profile_name_322_count = 0;
static long long _profile_name_322_time = 0;
static long long _profile_name_289_count = 0;
static long long _profile_name_289_time = 0;
static long long _profile_name_168_count = 0;
static long long _profile_name_168_time = 0;
static long long _profile_name_201_count = 0;
static long long _profile_name_201_time = 0;
static long long _profile_name_323_count = 0;
static long long _profile_name_323_time = 0;
static long long _profile_name_169_count = 0;
static long long _profile_name_169_time = 0;
static long long _profile_name_202_count = 0;
static long long _profile_name_202_time = 0;
static long long _profile_name_203_count = 0;
static long long _profile_name_203_time = 0;
static long long _profile_name_325_count = 0;
static long long _profile_name_325_time = 0;
static long long _profile_name_204_count = 0;
static long long _profile_name_204_time = 0;
static long long _profile_name_326_count = 0;
static long long _profile_name_326_time = 0;
static long long _profile_name_205_count = 0;
static long long _profile_name_205_time = 0;
static long long _profile_name_327_count = 0;
static long long _profile_name_327_time = 0;
static long long _profile_name_206_count = 0;
static long long _profile_name_206_time = 0;
static long long _profile_name_328_count = 0;
static long long _profile_name_328_time = 0;
static long long _profile_name_207_count = 0;
static long long _profile_name_207_time = 0;
static long long _profile_name_208_count = 0;
static long long _profile_name_208_time = 0;
static long long _profile_name_71_count = 0;
static long long _profile_name_71_time = 0;
static long long _profile_name_209_count = 0;
static long long _profile_name_209_time = 0;
static long long _profile_name_73_count = 0;
static long long _profile_name_73_time = 0;
static long long _profile_name_75_count = 0;
static long long _profile_name_75_time = 0;
static long long _profile_name_77_count = 0;
static long long _profile_name_77_time = 0;
static long long _profile_name_78_count = 0;
static long long _profile_name_78_time = 0;
static long long _profile_name_79_count = 0;
static long long _profile_name_79_time = 0;
static long long _profile_name_290_count = 0;
static long long _profile_name_290_time = 0;
static long long _profile_name_291_count = 0;
static long long _profile_name_291_time = 0;
static long long _profile_name_170_count = 0;
static long long _profile_name_170_time = 0;
static long long _profile_name_292_count = 0;
static long long _profile_name_292_time = 0;
static long long _profile_name_171_count = 0;
static long long _profile_name_171_time = 0;
static long long _profile_name_293_count = 0;
static long long _profile_name_293_time = 0;
static long long _profile_name_172_count = 0;
static long long _profile_name_172_time = 0;
static long long _profile_name_294_count = 0;
static long long _profile_name_294_time = 0;
static long long _profile_name_173_count = 0;
static long long _profile_name_173_time = 0;
static long long _profile_name_295_count = 0;
static long long _profile_name_295_time = 0;
static long long _profile_name_174_count = 0;
static long long _profile_name_174_time = 0;
static long long _profile_c_scan_count = 0;
static long long _profile_c_scan_time = 0;
static long long _profile_name_296_count = 0;
static long long _profile_name_296_time = 0;
static long long _profile_name_330_count = 0;
static long long _profile_name_330_time = 0;
static long long _profile_name_297_count = 0;
static long long _profile_name_297_time = 0;
static long long _profile_name_176_count = 0;
static long long _profile_name_176_time = 0;
static long long _profile_name_298_count = 0;
static long long _profile_name_298_time = 0;
static long long _profile_name_177_count = 0;
static long long _profile_name_177_time = 0;
static long long _profile_name_210_count = 0;
static long long _profile_name_210_time = 0;
static long long _profile_name_332_count = 0;
static long long _profile_name_332_time = 0;
static long long _profile_name_299_count = 0;
static long long _profile_name_299_time = 0;
static long long _profile_name_211_count = 0;
static long long _profile_name_211_time = 0;
static long long _profile_name_333_count = 0;
static long long _profile_name_333_time = 0;
static long long _profile_name_212_count = 0;
static long long _profile_name_212_time = 0;
static long long _profile_name_334_count = 0;
static long long _profile_name_334_time = 0;
static long long _profile_name_213_count = 0;
static long long _profile_name_213_time = 0;
static long long _profile_name_214_count = 0;
static long long _profile_name_214_time = 0;
static long long _profile_name_336_count = 0;
static long long _profile_name_336_time = 0;
static long long _profile_name_215_count = 0;
static long long _profile_name_215_time = 0;
static long long _profile_name_216_count = 0;
static long long _profile_name_216_time = 0;
static long long _profile_name_338_count = 0;
static long long _profile_name_338_time = 0;
static long long _profile_name_217_count = 0;
static long long _profile_name_217_time = 0;
static long long _profile_name_80_count = 0;
static long long _profile_name_80_time = 0;
static long long _profile_name_218_count = 0;
static long long _profile_name_218_time = 0;
static long long _profile_name_219_count = 0;
static long long _profile_name_219_time = 0;
static long long _profile_name_82_count = 0;
static long long _profile_name_82_time = 0;
static long long _profile_name_84_count = 0;
static long long _profile_name_84_time = 0;
static long long _profile_name_86_count = 0;
static long long _profile_name_86_time = 0;
static long long _profile_name_88_count = 0;
static long long _profile_name_88_time = 0;
static long long _profile_name_180_count = 0;
static long long _profile_name_180_time = 0;
static long long _profile_name_181_count = 0;
static long long _profile_name_181_time = 0;
static long long _profile_name_182_count = 0;
static long long _profile_name_182_time = 0;
static long long _profile_name_183_count = 0;
static long long _profile_name_183_time = 0;
static long long _profile_name_184_count = 0;
static long long _profile_name_184_time = 0;
static long long _profile_name_185_count = 0;
static long long _profile_name_185_time = 0;
static long long _profile_name_186_count = 0;
static long long _profile_name_186_time = 0;
static long long _profile_name_187_count = 0;
static long long _profile_name_187_time = 0;
static long long _profile_name_220_count = 0;
static long long _profile_name_220_time = 0;
static long long _profile_name_342_count = 0;
static long long _profile_name_342_time = 0;
static long long _profile_name_100_count = 0;
static long long _profile_name_100_time = 0;
static long long _profile_name_221_count = 0;
static long long _profile_name_221_time = 0;
static long long _profile_name_343_count = 0;
static long long _profile_name_343_time = 0;
static long long _profile_name_101_count = 0;
static long long _profile_name_101_time = 0;
static long long _profile_name_189_count = 0;
static long long _profile_name_189_time = 0;
static long long _profile_name_222_count = 0;
static long long _profile_name_222_time = 0;
static long long _profile_name_344_count = 0;
static long long _profile_name_344_time = 0;
static long long _profile_name_223_count = 0;
static long long _profile_name_223_time = 0;
static long long _profile_name_345_count = 0;
static long long _profile_name_345_time = 0;
static long long _profile_name_103_count = 0;
static long long _profile_name_103_time = 0;
static long long _profile_name_224_count = 0;
static long long _profile_name_224_time = 0;
static long long _profile_name_225_count = 0;
static long long _profile_name_225_time = 0;
static long long _profile_name_347_count = 0;
static long long _profile_name_347_time = 0;
static long long _profile_name_105_count = 0;
static long long _profile_name_105_time = 0;
static long long _profile_name_226_count = 0;
static long long _profile_name_226_time = 0;
static long long _profile_name_227_count = 0;
static long long _profile_name_227_time = 0;
static long long _profile_name_349_count = 0;
static long long _profile_name_349_time = 0;
static long long _profile_name_90_count = 0;
static long long _profile_name_90_time = 0;
static long long _profile_name_107_count = 0;
static long long _profile_name_107_time = 0;
static long long _profile_name_228_count = 0;
static long long _profile_name_228_time = 0;
static long long _profile_name_91_count = 0;
static long long _profile_name_91_time = 0;
static long long _profile_name_108_count = 0;
static long long _profile_name_108_time = 0;
static long long _profile_name_229_count = 0;
static long long _profile_name_229_time = 0;
static long long _profile_name_92_count = 0;
static long long _profile_name_92_time = 0;
static long long _profile_name_93_count = 0;
static long long _profile_name_93_time = 0;
static long long _profile_name_94_count = 0;
static long long _profile_name_94_time = 0;
static long long _profile_name_95_count = 0;
static long long _profile_name_95_time = 0;
static long long _profile_name_96_count = 0;
static long long _profile_name_96_time = 0;
static long long _profile_name_97_count = 0;
static long long _profile_name_97_time = 0;
static long long _profile_name_10_count = 0;
static long long _profile_name_10_time = 0;
static long long _profile_name_98_count = 0;
static long long _profile_name_98_time = 0;
static long long _profile_name_12_count = 0;
static long long _profile_name_12_time = 0;
static long long _profile_name_13_count = 0;
static long long _profile_name_13_time = 0;
static long long _profile_name_14_count = 0;
static long long _profile_name_14_time = 0;
static long long _profile_name_15_count = 0;
static long long _profile_name_15_time = 0;
static long long _profile_name_17_count = 0;
static long long _profile_name_17_time = 0;
static long long _profile_name_18_count = 0;
static long long _profile_name_18_time = 0;
static long long _profile_name_190_count = 0;
static long long _profile_name_190_time = 0;
static long long _profile_name_19_count = 0;
static long long _profile_name_19_time = 0;
static long long _profile_name_191_count = 0;
static long long _profile_name_191_time = 0;
static long long _profile_name_192_count = 0;
static long long _profile_name_192_time = 0;
static long long _profile_name_193_count = 0;
static long long _profile_name_193_time = 0;
static long long _profile_name_194_count = 0;
static long long _profile_name_194_time = 0;
static long long _profile_name_195_count = 0;
static long long _profile_name_195_time = 0;
static long long _profile_name_197_count = 0;
static long long _profile_name_197_time = 0;
static long long _profile_name_230_count = 0;
static long long _profile_name_230_time = 0;
static long long _profile_name_110_count = 0;
static long long _profile_name_110_time = 0;
static long long _profile_name_198_count = 0;
static long long _profile_name_198_time = 0;
static long long _profile_name_231_count = 0;
static long long _profile_name_231_time = 0;
static long long _profile_name_199_count = 0;
static long long _profile_name_199_time = 0;
static long long _profile_name_232_count = 0;
static long long _profile_name_232_time = 0;
static long long _profile_name_112_count = 0;
static long long _profile_name_112_time = 0;
static long long _profile_name_233_count = 0;
static long long _profile_name_233_time = 0;
static long long _profile_name_113_count = 0;
static long long _profile_name_113_time = 0;
static long long _profile_name_234_count = 0;
static long long _profile_name_234_time = 0;
static long long _profile_name_235_count = 0;
static long long _profile_name_235_time = 0;
static long long _profile_name_115_count = 0;
static long long _profile_name_115_time = 0;
static long long _profile_name_236_count = 0;
static long long _profile_name_236_time = 0;
static long long _profile_name_237_count = 0;
static long long _profile_name_237_time = 0;
static long long _profile_name_117_count = 0;
static long long _profile_name_117_time = 0;
static long long _profile_name_238_count = 0;
static long long _profile_name_238_time = 0;
static long long _profile_name_118_count = 0;
static long long _profile_name_118_time = 0;
static long long _profile_name_239_count = 0;
static long long _profile_name_239_time = 0;
static long long _profile_name_20_count = 0;
static long long _profile_name_20_time = 0;
static long long _profile_name_21_count = 0;
static long long _profile_name_21_time = 0;
static long long _profile_name_22_count = 0;
static long long _profile_name_22_time = 0;
static long long _profile_name_23_count = 0;
static long long _profile_name_23_time = 0;
static long long _profile_name_24_count = 0;
static long long _profile_name_24_time = 0;
static long long _profile_name_25_count = 0;
static long long _profile_name_25_time = 0;
static long long _profile_name_26_count = 0;
static long long _profile_name_26_time = 0;
static long long _profile_name_28_count = 0;
static long long _profile_name_28_time = 0;
static long long _profile_name_29_count = 0;
static long long _profile_name_29_time = 0;
static long long _profile_name_240_count = 0;
static long long _profile_name_240_time = 0;
static long long _profile_name_120_count = 0;
static long long _profile_name_120_time = 0;
static long long _profile_name_241_count = 0;
static long long _profile_name_241_time = 0;
static long long _profile_name_242_count = 0;
static long long _profile_name_242_time = 0;
static long long _profile_name_122_count = 0;
static long long _profile_name_122_time = 0;
static long long _profile_name_243_count = 0;
static long long _profile_name_243_time = 0;
static long long _profile_name_244_count = 0;
static long long _profile_name_244_time = 0;
static long long _profile_name_245_count = 0;
static long long _profile_name_245_time = 0;
static long long _profile_name_124_count = 0;
static long long _profile_name_124_time = 0;
static long long _profile_name_246_count = 0;
static long long _profile_name_246_time = 0;
static long long _profile_name_247_count = 0;
static long long _profile_name_247_time = 0;
static long long _profile_name_126_count = 0;
static long long _profile_name_126_time = 0;
static long long _profile_name_248_count = 0;
static long long _profile_name_248_time = 0;
static long long _profile_name_127_count = 0;
static long long _profile_name_127_time = 0;
static long long _profile_name_249_count = 0;
static long long _profile_name_249_time = 0;
static long long _profile_name_129_count = 0;
static long long _profile_name_129_time = 0;
static long long _profile_name_30_count = 0;
static long long _profile_name_30_time = 0;
static long long _profile_name_31_count = 0;
static long long _profile_name_31_time = 0;
static long long _profile_name_32_count = 0;
static long long _profile_name_32_time = 0;
static long long _profile_name_33_count = 0;
static long long _profile_name_33_time = 0;
static long long _profile_name_35_count = 0;
static long long _profile_name_35_time = 0;
static long long _profile_name_37_count = 0;
static long long _profile_name_37_time = 0;
static long long _profile_name_38_count = 0;
static long long _profile_name_38_time = 0;
#endif


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 1059 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  105
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3223

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  109
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  137
/* YYNRULES -- Number of rules.  */
#define YYNRULES  412
/* YYNRULES -- Number of states.  */
#define YYNSTATES  722

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   363

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     9,    11,    14,    17,    20,
      23,    25,    27,    30,    34,    36,    39,    42,    46,    49,
      53,    56,    58,    61,    63,    66,    68,    72,    77,    80,
      82,    84,    86,    88,    90,    92,    94,    96,    98,   100,
     102,   104,   106,   108,   111,   113,   115,   117,   119,   121,
     125,   129,   136,   138,   140,   142,   144,   146,   151,   155,
     160,   164,   168,   171,   174,   176,   180,   182,   185,   188,
     191,   194,   199,   202,   204,   206,   208,   210,   212,   214,
     216,   221,   223,   227,   231,   235,   237,   241,   245,   247,
     251,   255,   257,   261,   265,   269,   273,   275,   279,   283,
     285,   289,   291,   295,   297,   301,   303,   307,   309,   313,
     315,   321,   323,   327,   331,   335,   339,   343,   347,   351,
     355,   359,   363,   367,   369,   373,   375,   381,   386,   389,
     391,   393,   395,   398,   402,   407,   410,   414,   419,   421,
     425,   427,   430,   434,   439,   445,   451,   458,   461,   463,
     467,   469,   473,   475,   478,   480,   484,   488,   493,   498,
     504,   508,   513,   518,   520,   523,   526,   530,   532,   535,
     537,   541,   543,   547,   549,   553,   555,   559,   562,   564,
     566,   569,   571,   573,   576,   580,   583,   587,   591,   596,
     600,   605,   610,   616,   619,   623,   627,   632,   634,   638,
     643,   645,   649,   651,   653,   655,   657,   659,   661,   663,
     665,   669,   672,   674,   680,   685,   688,   689,   692,   696,
     699,   701,   704,   708,   713,   717,   720,   724,   728,   733,
     736,   738,   741,   743,   746,   748,   751,   754,   760,   768,
     774,   780,   788,   795,   803,   811,   820,   828,   837,   846,
     856,   860,   863,   866,   869,   873,   875,   876,   878,   883,
     889,   896,   898,   900,   902,   904,   906,   908,   910,   912,
     915,   917,   919,   921,   925,   931,   939,   941,   944,   945,
     947,   949,   953,   958,   966,   968,   972,   975,   976,   978,
     980,   982,   984,   986,   988,   990,   992,   994,   996,  1000,
    1004,  1009,  1012,  1013,  1017,  1018,  1025,  1030,  1038,  1044,
    1047,  1053,  1057,  1058,  1060,  1064,  1068,  1070,  1072,  1074,
    1076,  1078,  1079,  1083,  1086,  1089,  1090,  1092,  1096,  1098,
    1102,  1105,  1107,  1109,  1114,  1115,  1118,  1121,  1124,  1127,
    1130,  1134,  1140,  1143,  1147,  1151,  1152,  1154,  1158,  1159,
    1161,  1167,  1169,  1176,  1179,  1180,  1183,  1184,  1186,  1189,
    1191,  1193,  1196,  1199,  1203,  1206,  1207,  1210,  1213,  1215,
    1217,  1220,  1222,  1224,  1226,  1228,  1230,  1232,  1234,  1236,
    1238,  1240,  1242,  1244,  1246,  1248,  1250,  1252,  1254,  1256,
    1258,  1260,  1268,  1272,  1279,  1282,  1284,  1286,  1288,  1291,
    1295,  1298,  1300,  1302,  1307,  1309,  1311,  1313,  1316,  1319,
    1321,  1326,  1331
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     110,     0,    -1,    -1,   111,    -1,   108,   176,    -1,   112,
      -1,   111,   112,    -1,   196,   113,    -1,   196,   195,    -1,
     196,   115,    -1,   198,    -1,     3,    -1,   151,   114,    -1,
     117,   151,   114,    -1,   174,    -1,   175,   174,    -1,   117,
       3,    -1,   117,   118,     3,    -1,   117,     3,    -1,   117,
     118,     3,    -1,   197,   116,    -1,   120,    -1,   120,   117,
      -1,   121,    -1,   121,   117,    -1,   119,    -1,   118,     4,
     119,    -1,   151,   182,    23,   163,    -1,   151,   182,    -1,
      53,    -1,    54,    -1,    55,    -1,    56,    -1,    58,    -1,
      52,    -1,    60,    -1,    61,    -1,    62,    -1,    57,    -1,
      63,    -1,   142,    -1,   148,    -1,    59,    -1,    52,   209,
      -1,   209,    -1,   181,    -1,    28,    -1,    29,    -1,   107,
      -1,     9,   140,    10,    -1,     9,   174,    10,    -1,     9,
     160,    10,     5,   164,     6,    -1,   239,    -1,   243,    -1,
     244,    -1,   245,    -1,   122,    -1,   123,     7,   140,     8,
      -1,   123,     9,    10,    -1,   123,     9,   124,    10,    -1,
     123,    12,   181,    -1,   123,    31,   181,    -1,   123,    32,
      -1,   123,    33,    -1,   139,    -1,   124,     4,   139,    -1,
     123,    -1,    32,   125,    -1,    33,   125,    -1,   126,   127,
      -1,    30,   125,    -1,    30,     9,   160,    10,    -1,   197,
     127,    -1,    21,    -1,    18,    -1,    16,    -1,    17,    -1,
      14,    -1,    15,    -1,   125,    -1,     9,   160,    10,   127,
      -1,   127,    -1,   128,    18,   127,    -1,   128,    19,   127,
      -1,   128,    22,   127,    -1,   128,    -1,   129,    16,   128,
      -1,   129,    17,   128,    -1,   129,    -1,   130,    34,   129,
      -1,   130,    35,   129,    -1,   130,    -1,   131,    25,   130,
      -1,   131,    26,   130,    -1,   131,    36,   130,    -1,   131,
      37,   130,    -1,   131,    -1,   132,    38,   131,    -1,   132,
      39,   131,    -1,   132,    -1,   133,    21,   132,    -1,   133,
      -1,   134,    20,   133,    -1,   134,    -1,   135,    11,   134,
      -1,   135,    -1,   136,    40,   135,    -1,   136,    -1,   137,
      41,   136,    -1,   137,    -1,   137,    24,   137,    13,   138,
      -1,   138,    -1,   125,    23,   139,    -1,   125,    42,   139,
      -1,   125,    43,   139,    -1,   125,    44,   139,    -1,   125,
      45,   139,    -1,   125,    46,   139,    -1,   125,    47,   139,
      -1,   125,    48,   139,    -1,   125,    49,   139,    -1,   125,
      50,   139,    -1,   125,    51,   139,    -1,   139,    -1,   140,
       4,   139,    -1,   138,    -1,   143,   181,     5,   144,     6,
      -1,   143,     5,   144,     6,    -1,   143,   181,    -1,    64,
      -1,    65,    -1,   145,    -1,   144,   145,    -1,   154,   146,
       3,    -1,   197,   154,   146,     3,    -1,   142,     3,    -1,
     197,   142,     3,    -1,    88,     9,    52,    10,    -1,   147,
      -1,   146,     4,   147,    -1,   151,    -1,    13,   141,    -1,
     151,    13,   141,    -1,    66,     5,   149,     6,    -1,    66,
       5,   149,     4,     6,    -1,    66,   181,     5,   149,     6,
      -1,    66,   181,     5,   149,     4,     6,    -1,    66,   181,
      -1,   150,    -1,   149,     4,   150,    -1,   181,    -1,   181,
      23,   141,    -1,   152,    -1,   153,   152,    -1,   181,    -1,
       9,   151,    10,    -1,   152,     7,     8,    -1,   152,     7,
     187,     8,    -1,   152,     7,   188,     8,    -1,   152,     7,
     187,   188,     8,    -1,   152,     9,    10,    -1,   152,     9,
     157,    10,    -1,   152,     9,   155,    10,    -1,    18,    -1,
      18,   154,    -1,    18,   153,    -1,    18,   154,   153,    -1,
     121,    -1,   154,   121,    -1,   156,    -1,   156,     4,    67,
      -1,   181,    -1,   156,     4,   181,    -1,   158,    -1,   158,
       4,    67,    -1,   159,    -1,   158,     4,   159,    -1,   154,
     151,    -1,   160,    -1,   154,    -1,   154,   161,    -1,   153,
      -1,   162,    -1,   153,   162,    -1,     9,   161,    10,    -1,
       7,     8,    -1,     7,   187,     8,    -1,     7,   188,     8,
      -1,     7,   187,   188,     8,    -1,   162,     7,     8,    -1,
     162,     7,   187,     8,    -1,   162,     7,   188,     8,    -1,
     162,     7,   187,   188,     8,    -1,     9,    10,    -1,     9,
     157,    10,    -1,   162,     9,    10,    -1,   162,     9,   157,
      10,    -1,   139,    -1,     5,   164,     6,    -1,     5,   164,
       4,     6,    -1,   163,    -1,   164,     4,   163,    -1,   173,
      -1,   174,    -1,   177,    -1,   178,    -1,   179,    -1,   180,
      -1,   184,    -1,   166,    -1,    97,   140,     3,    -1,    97,
       3,    -1,   172,    -1,   101,     9,   140,    10,   174,    -1,
      99,     9,   181,    10,    -1,   167,   174,    -1,    -1,   169,
     168,    -1,    98,   174,   169,    -1,   100,   174,    -1,   170,
      -1,   170,   171,    -1,   181,    13,   165,    -1,    69,   141,
      13,   165,    -1,    70,    13,   165,    -1,     5,     6,    -1,
       5,   176,     6,    -1,     5,   175,     6,    -1,     5,   175,
     176,     6,    -1,     1,     6,    -1,   116,    -1,   175,   116,
      -1,   165,    -1,   176,   165,    -1,     3,    -1,   140,     3,
      -1,     1,     3,    -1,    71,     9,   140,    10,   165,    -1,
      71,     9,   140,    10,   165,    72,   165,    -1,    73,     9,
     140,    10,   165,    -1,    74,     9,   140,    10,   165,    -1,
      75,   165,    74,     9,   140,    10,     3,    -1,    76,     9,
       3,     3,    10,   165,    -1,    76,     9,     3,     3,   140,
      10,   165,    -1,    76,     9,     3,   140,     3,    10,   165,
      -1,    76,     9,     3,   140,     3,   140,    10,   165,    -1,
      76,     9,   140,     3,     3,    10,   165,    -1,    76,     9,
     140,     3,     3,   140,    10,   165,    -1,    76,     9,   140,
       3,   140,     3,    10,   165,    -1,    76,     9,   140,     3,
     140,     3,   140,    10,   165,    -1,    77,   181,     3,    -1,
      78,     3,    -1,    79,     3,    -1,    80,     3,    -1,    80,
     140,     3,    -1,    27,    -1,    -1,   183,    -1,    81,     9,
     190,    10,    -1,    81,     9,   189,    10,     3,    -1,    81,
     185,     9,   189,    10,     3,    -1,    62,    -1,    63,    -1,
      59,    -1,    55,    -1,    59,    -1,    62,    -1,    63,    -1,
     186,    -1,   187,   186,    -1,   139,    -1,    18,    -1,   190,
      -1,   190,    13,   191,    -1,   190,    13,   191,    13,   191,
      -1,   190,    13,   191,    13,   191,    13,   194,    -1,    29,
      -1,   190,    29,    -1,    -1,   192,    -1,   193,    -1,   192,
       4,   193,    -1,    29,     9,   140,    10,    -1,     7,   181,
       8,    29,     9,   140,    10,    -1,    29,    -1,   194,     4,
      29,    -1,   183,     3,    -1,    -1,   197,    -1,    83,    -1,
     205,    -1,   201,    -1,   202,    -1,   207,    -1,   217,    -1,
     181,    -1,    52,    -1,   199,    -1,   200,     4,   199,    -1,
      95,   200,     3,    -1,    96,   181,   181,     3,    -1,    13,
     199,    -1,    -1,     5,   210,     6,    -1,    -1,   206,   203,
     208,   204,   218,    86,    -1,    85,   199,   203,   204,    -1,
     206,     9,   199,    10,   208,   218,    86,    -1,    85,   199,
       9,   181,    10,    -1,    84,   199,    -1,    94,   181,   208,
     218,    86,    -1,    94,   156,     3,    -1,    -1,   209,    -1,
      25,   200,    26,    -1,   210,   211,   212,    -1,   212,    -1,
      91,    -1,    92,    -1,    90,    -1,    93,    -1,    -1,   212,
     213,     3,    -1,   212,     3,    -1,   117,   214,    -1,    -1,
     215,    -1,   214,     4,   215,    -1,   151,    -1,   151,    13,
     139,    -1,    13,   139,    -1,    16,    -1,    17,    -1,   216,
     223,   224,   174,    -1,    -1,   218,   219,    -1,   218,   115,
      -1,   218,   220,    -1,   218,   105,    -1,   218,   106,    -1,
     216,   223,     3,    -1,   102,     9,   221,    10,   116,    -1,
     102,   116,    -1,   103,   118,     3,    -1,   104,   118,     3,
      -1,    -1,   181,    -1,   221,     4,   181,    -1,    -1,   181,
      -1,     9,   222,   160,    10,   230,    -1,   230,    -1,     9,
     222,   160,    10,   231,   229,    -1,   231,   229,    -1,    -1,
       3,   225,    -1,    -1,   227,    -1,     1,     3,    -1,   228,
      -1,   226,    -1,   227,   228,    -1,   228,   226,    -1,   117,
     158,     3,    -1,   117,     3,    -1,    -1,     4,    67,    -1,
       4,   158,    -1,   232,    -1,   234,    -1,   231,   234,    -1,
     181,    -1,    52,    -1,   233,    -1,    66,    -1,    64,    -1,
      65,    -1,    71,    -1,    72,    -1,    74,    -1,    75,    -1,
      76,    -1,    73,    -1,    69,    -1,    70,    -1,    79,    -1,
      78,    -1,    80,    -1,    77,    -1,    81,    -1,    30,    -1,
     232,    13,     9,   222,   160,    10,   181,    -1,   232,    13,
     181,    -1,    13,     9,   222,   160,    10,   181,    -1,    13,
     181,    -1,   232,    -1,   236,    -1,   237,    -1,   236,   237,
      -1,   232,    13,   140,    -1,    13,   140,    -1,   140,    -1,
      52,    -1,     7,   238,   235,     8,    -1,   232,    -1,   241,
      -1,   242,    -1,   241,   242,    -1,   232,    13,    -1,    13,
      -1,    87,     9,   240,    10,    -1,    94,     9,   181,    10,
      -1,    89,     9,    52,    10,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   844,   844,   846,   847,   851,   852,   856,   857,   858,
     859,   860,   864,   865,   869,   870,   874,   875,   879,   880,
     881,   885,   886,   887,   888,   892,   893,   897,   898,   902,
     903,   904,   905,   906,   910,   911,   912,   913,   914,   915,
     916,   917,   918,   919,   920,   924,   925,   926,   927,   928,
     929,   930,   931,   932,   933,   934,   938,   939,   940,   941,
     942,   943,   944,   945,   949,   950,   954,   955,   956,   957,
     958,   959,   960,   964,   965,   966,   967,   968,   969,   973,
     974,   978,   979,   980,   981,   985,   986,   987,   991,   992,
     993,   997,   998,   999,  1000,  1001,  1005,  1006,  1007,  1011,
    1012,  1016,  1017,  1021,  1022,  1026,  1027,  1031,  1032,  1036,
    1037,  1041,  1042,  1043,  1044,  1045,  1046,  1047,  1048,  1049,
    1050,  1051,  1052,  1056,  1057,  1061,  1065,  1066,  1067,  1071,
    1072,  1076,  1077,  1081,  1082,  1083,  1084,  1085,  1089,  1090,
    1094,  1095,  1096,  1100,  1101,  1102,  1103,  1104,  1108,  1109,
    1113,  1114,  1118,  1119,  1123,  1124,  1125,  1126,  1127,  1128,
    1129,  1130,  1131,  1135,  1136,  1137,  1138,  1142,  1143,  1147,
    1148,  1152,  1153,  1157,  1158,  1162,  1163,  1167,  1168,  1172,
    1173,  1177,  1178,  1179,  1183,  1184,  1185,  1186,  1187,  1188,
    1189,  1190,  1191,  1192,  1193,  1194,  1195,  1199,  1200,  1201,
    1205,  1206,  1210,  1211,  1212,  1213,  1214,  1215,  1216,  1217,
    1221,  1222,  1223,  1224,  1228,  1232,  1235,  1237,  1241,  1245,
    1249,  1250,  1254,  1255,  1256,  1260,  1261,  1262,  1263,  1264,
    1268,  1269,  1273,  1274,  1278,  1279,  1280,  1284,  1285,  1286,
    1290,  1291,  1292,  1293,  1294,  1295,  1296,  1297,  1298,  1299,
    1303,  1304,  1305,  1306,  1307,  1311,  1314,  1316,  1320,  1324,
    1325,  1329,  1330,  1331,  1335,  1336,  1337,  1338,  1342,  1343,
    1347,  1348,  1352,  1353,  1354,  1355,  1359,  1360,  1363,  1365,
    1369,  1370,  1374,  1375,  1379,  1380,  1384,  1387,  1389,  1393,
    1397,  1398,  1399,  1400,  1401,  1405,  1406,  1410,  1411,  1415,
    1419,  1423,  1424,  1428,  1429,  1433,  1434,  1435,  1436,  1440,
    1444,  1445,  1448,  1450,  1454,  1458,  1459,  1463,  1464,  1465,
    1466,  1469,  1471,  1472,  1476,  1479,  1481,  1482,  1486,  1487,
    1488,  1492,  1493,  1497,  1500,  1502,  1503,  1504,  1505,  1506,
    1510,  1514,  1515,  1516,  1517,  1520,  1522,  1523,  1526,  1528,
    1532,  1533,  1534,  1535,  1538,  1540,  1543,  1545,  1549,  1553,
    1554,  1555,  1556,  1560,  1561,  1564,  1566,  1567,  1571,  1575,
    1576,  1580,  1581,  1582,  1586,  1587,  1588,  1589,  1590,  1591,
    1592,  1593,  1594,  1595,  1596,  1597,  1598,  1599,  1600,  1601,
    1602,  1606,  1607,  1608,  1609,  1613,  1614,  1618,  1619,  1623,
    1624,  1628,  1629,  1633,  1637,  1638,  1642,  1643,  1647,  1648,
    1652,  1656,  1660
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "COMMA", "LCBRA", "RCBRA",
  "LSBRA", "RSBRA", "LPAREN", "RPAREN", "OR", "DOT", "COLON", "_7e", "X",
  "_2b", "_", "_2a", "_2f", "_5e", "_26", "_25", "_3d", "P", "_LT", "_GT",
  "IDENTIFIER", "CONSTANT", "STRING", "SIZEOF", "PTR_OP", "INC_OP",
  "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP",
  "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "TYPENAME", "TYPEDEF", "EXTERN", "STATIC",
  "AUTO", "REGISTER", "INLINE", "RESTRICT", "SIGNED", "UNSIGNED", "CONST",
  "VOLATILE", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "RANGE", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "ASM", "UNKNOWN", "EXTENSION",
  "AT_INTERFACE", "AT_IMPLEMENTATION", "AT_END", "AT_SELECTOR", "AT_DEFS",
  "AT_ENCODE", "AT_PUBLIC", "AT_PRIVATE", "AT_PROTECTED", "AT_PACKAGE",
  "AT_PROTOCOL", "AT_CLASS", "AT_ALIAS", "AT_THROW", "AT_TRY", "AT_CATCH",
  "AT_FINALLY", "AT_SYNCHRONIZED", "AT_PROPERTY", "AT_SYNTHESIZE",
  "AT_DYNAMIC", "AT_OPTIONAL", "AT_REQUIRED", "OBJC_STRING", "START_MACRO",
  "$accept", "program", "file", "external_definition",
  "function_definition", "function_body", "external_declaration",
  "declaration", "declaration_specifiers", "init_declarator_list",
  "init_declarator", "storage_class_specifier", "type_specifier",
  "primary_expr", "postfix_expr", "argument_expr_list", "unary_expr",
  "unary_operator", "cast_expr", "multiplicative_expr", "additive_expr",
  "shift_expr", "relational_expr", "equality_expr", "and_expr",
  "exclusive_or_expr", "inclusive_or_expr", "logical_and_expr",
  "logical_or_expr", "conditional_expr", "assignment_expr", "expr",
  "constant_expr", "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "struct_declarator_list", "struct_declarator", "enum_specifier",
  "enumerator_list", "enumerator", "declarator", "declarator2", "pointer",
  "type_specifier_list", "parameter_identifier_list", "identifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "type_name", "abstract_declarator", "abstract_declarator2",
  "initializer", "initializer_list", "statement", "objc_statement",
  "objc_catch_prefix", "objc_catch_clause", "objc_opt_catch_list",
  "objc_try_catch_clause", "objc_finally_clause",
  "objc_try_catch_statement", "labeled_statement", "compound_statement",
  "declaration_list", "statement_list", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "identifier", "maybe_asm", "asm_expr", "asm_statement", "type_qualifier",
  "array_qualifier", "array_qualifier_list", "array_size_expr",
  "asm_argument", "string_list", "asm_operands", "asm_operands2",
  "asm_operand", "asm_clobbers", "asm_definition", "maybe_extension",
  "extension", "objc_definition", "classname", "classname_list",
  "objc_class_declaration", "objc_alias_declaration", "objc_superclass",
  "objc_class_ivars", "objc_class_definition", "objc_interface_head",
  "objc_protocol_definition", "objc_protocol_references",
  "objc_non_empty_protocol_references", "objc_ivar_declaration_list",
  "objc_visibility_spec", "objc_ivar_declarations",
  "objc_ivar_declaration", "objc_ivars", "objc_ivar_declarator",
  "objc_method_type", "objc_method_definition",
  "objc_method_prototype_list", "objc_method_prototype", "objc_property",
  "property_attribute_list", "objc_protocol_qualifier",
  "objc_method_declaration", "optarglist", "myxdecls", "error_statement",
  "mydecls", "mydecl", "optparmlist", "unary_selector", "keyword_selector",
  "selector", "reserved_words", "keyword_declarator", "message_args",
  "keyword_arg_list", "keyword_arg", "receiver", "objc_message_expr",
  "selector_arg", "keyword_name_list", "keyword_name",
  "objc_selector_expr", "objc_protocol_expr", "objc_encode_expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   109,   110,   110,   110,   111,   111,   112,   112,   112,
     112,   112,   113,   113,   114,   114,   115,   115,   116,   116,
     116,   117,   117,   117,   117,   118,   118,   119,   119,   120,
     120,   120,   120,   120,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   123,   123,   123,   123,
     123,   123,   123,   123,   124,   124,   125,   125,   125,   125,
     125,   125,   125,   126,   126,   126,   126,   126,   126,   127,
     127,   128,   128,   128,   128,   129,   129,   129,   130,   130,
     130,   131,   131,   131,   131,   131,   132,   132,   132,   133,
     133,   134,   134,   135,   135,   136,   136,   137,   137,   138,
     138,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   140,   140,   141,   142,   142,   142,   143,
     143,   144,   144,   145,   145,   145,   145,   145,   146,   146,
     147,   147,   147,   148,   148,   148,   148,   148,   149,   149,
     150,   150,   151,   151,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   153,   153,   153,   153,   154,   154,   155,
     155,   156,   156,   157,   157,   158,   158,   159,   159,   160,
     160,   161,   161,   161,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   163,   163,   163,
     164,   164,   165,   165,   165,   165,   165,   165,   165,   165,
     166,   166,   166,   166,   167,   168,   169,   169,   170,   171,
     172,   172,   173,   173,   173,   174,   174,   174,   174,   174,
     175,   175,   176,   176,   177,   177,   177,   178,   178,   178,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     180,   180,   180,   180,   180,   181,   182,   182,   183,   184,
     184,   185,   185,   185,   186,   186,   186,   186,   187,   187,
     188,   188,   189,   189,   189,   189,   190,   190,   191,   191,
     192,   192,   193,   193,   194,   194,   195,   196,   196,   197,
     198,   198,   198,   198,   198,   199,   199,   200,   200,   201,
     202,   203,   203,   204,   204,   205,   205,   205,   205,   206,
     207,   207,   208,   208,   209,   210,   210,   211,   211,   211,
     211,   212,   212,   212,   213,   214,   214,   214,   215,   215,
     215,   216,   216,   217,   218,   218,   218,   218,   218,   218,
     219,   220,   220,   220,   220,   221,   221,   221,   222,   222,
     223,   223,   223,   223,   224,   224,   225,   225,   226,   227,
     227,   227,   227,   228,   228,   229,   229,   229,   230,   231,
     231,   232,   232,   232,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   234,   234,   234,   234,   235,   235,   236,   236,   237,
     237,   238,   238,   239,   240,   240,   241,   241,   242,   242,
     243,   244,   245
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     2,     1,     2,     2,     2,     2,
       1,     1,     2,     3,     1,     2,     2,     3,     2,     3,
       2,     1,     2,     1,     2,     1,     3,     4,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     3,
       3,     6,     1,     1,     1,     1,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     2,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     1,     5,     4,     2,     1,
       1,     1,     2,     3,     4,     2,     3,     4,     1,     3,
       1,     2,     3,     4,     5,     5,     6,     2,     1,     3,
       1,     3,     1,     2,     1,     3,     3,     4,     4,     5,
       3,     4,     4,     1,     2,     2,     3,     1,     2,     1,
       3,     1,     3,     1,     3,     1,     3,     2,     1,     1,
       2,     1,     1,     2,     3,     2,     3,     3,     4,     3,
       4,     4,     5,     2,     3,     3,     4,     1,     3,     4,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     1,     5,     4,     2,     0,     2,     3,     2,
       1,     2,     3,     4,     3,     2,     3,     3,     4,     2,
       1,     2,     1,     2,     1,     2,     2,     5,     7,     5,
       5,     7,     6,     7,     7,     8,     7,     8,     8,     9,
       3,     2,     2,     2,     3,     1,     0,     1,     4,     5,
       6,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     3,     5,     7,     1,     2,     0,     1,
       1,     3,     4,     7,     1,     3,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       4,     2,     0,     3,     0,     6,     4,     7,     5,     2,
       5,     3,     0,     1,     3,     3,     1,     1,     1,     1,
       1,     0,     3,     2,     2,     0,     1,     3,     1,     3,
       2,     1,     1,     4,     0,     2,     2,     2,     2,     2,
       3,     5,     2,     3,     3,     0,     1,     3,     0,     1,
       5,     1,     6,     2,     0,     2,     0,     1,     2,     1,
       1,     2,     2,     3,     2,     0,     2,     2,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     7,     3,     6,     2,     1,     1,     1,     2,     3,
       2,     1,     1,     4,     1,     1,     1,     2,     2,     1,
       4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     287,    11,   331,   332,   289,     0,     0,     0,     0,     0,
       0,     0,   287,     5,     0,   288,    10,   291,   292,   290,
     302,   293,     0,   294,   255,   296,   295,   309,   302,     0,
     312,   297,     0,     0,     0,   234,     0,     0,     0,    77,
      78,    75,    76,    74,    73,    46,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,    56,
      66,    79,     0,    81,    85,    88,    91,    96,    99,   101,
     103,   105,   107,   109,   111,   123,     0,   232,   209,   220,
     212,   202,   203,     0,   204,   205,   206,   207,    45,   208,
       0,    52,    53,    54,    55,     1,     6,     0,   163,     0,
      34,    29,    30,    31,    32,    38,    33,    42,    35,    36,
      37,    39,   129,   130,     0,     0,     7,     9,     0,    21,
      23,    40,     0,    41,     0,   152,     0,   154,     0,     8,
      44,     0,     0,   312,   348,     0,   390,   372,   375,   376,
     374,   383,   384,   377,   378,   382,   379,   380,   381,   388,
     386,   385,   387,   389,   371,   354,   351,   365,   368,   373,
     369,     0,   304,   311,     0,   334,   313,   299,     0,     0,
     236,   229,   225,   230,     0,     0,     0,     0,   402,   401,
      45,     0,     0,   167,     0,   179,     0,     0,     0,    70,
       0,    67,    68,    79,   125,     0,     0,     0,     0,     0,
       0,     0,     0,   251,   252,   253,     0,     0,   263,   261,
     262,     0,     0,     0,     0,   211,     0,   216,     0,     0,
       0,     0,     0,    62,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   235,     0,     0,   221,
     233,     0,    72,     0,   165,   164,     0,    43,     0,   147,
       0,    16,     0,    25,     0,    22,    24,     0,   128,    12,
      14,     0,     0,     0,     0,   153,   286,     0,   301,   304,
     349,     0,   348,   394,     0,     0,     0,   353,     0,   370,
       0,     0,   321,   306,   172,     0,   298,   300,    18,     0,
     256,   227,   231,     0,   226,    20,     0,   395,     0,   396,
     397,    49,     0,     0,   168,   181,   180,   182,     0,    50,
       0,     0,     0,   224,     0,     0,     0,     0,     0,     0,
     250,   254,   276,     0,   272,     0,   409,   404,     0,   405,
     406,     0,     0,   210,   218,     0,     0,    58,     0,    64,
      60,    61,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    82,    83,    84,    86,    87,    89,    90,
      92,    93,    94,    95,    97,    98,   100,   102,   104,   106,
       0,   108,   124,   219,   222,   155,   166,   314,     0,   148,
     150,     0,     0,    17,     0,    13,    28,   257,     0,    40,
       0,   131,     0,     0,     0,    15,   156,    74,   264,   265,
     266,   267,   270,   268,     0,     0,   160,   179,     0,   169,
       0,   173,   175,   178,   171,   312,   334,     0,     0,     0,
       0,   355,   360,   357,     0,   333,   366,   367,   348,   392,
     308,     0,   316,   310,     0,     0,     0,   338,   339,   336,
       0,     0,   335,   337,    19,   228,   400,     0,   403,     0,
     398,   185,     0,     0,   193,     0,     0,   183,     0,     0,
       0,    80,    71,     0,   223,     0,     0,     0,     0,     0,
       0,     0,     0,   278,   277,     0,   408,   410,     0,   407,
     412,   411,     0,     0,   217,     0,    57,     0,    59,     0,
       0,   143,     0,     0,   258,    26,     0,     0,   135,   127,
     132,     0,     0,   138,   140,    40,     0,     0,   157,   269,
       0,   158,     0,   177,   181,   162,     0,   161,     0,   334,
       0,     0,     0,   358,   364,     0,   361,   362,     0,     0,
     303,   319,   317,   318,   320,   321,   323,   325,     0,   345,
     342,     0,     0,     0,   399,   186,     0,   187,   194,   184,
     189,     0,     0,   195,     0,     0,   197,   200,     0,   237,
     239,   240,     0,     0,     0,     0,     0,     0,   259,     0,
       0,   273,   279,   280,     0,     0,   215,   213,    65,   110,
     144,   149,   151,     0,   145,    27,     0,   141,   133,     0,
       0,   136,     0,   126,   159,   170,   174,   176,     0,   305,
     350,   365,     0,   363,     0,   315,     0,   328,   324,   326,
     322,   346,     0,   343,   344,   340,   188,   190,     0,   191,
     196,     0,     0,    51,     0,     0,   242,     0,     0,     0,
       0,     0,     0,     0,     0,   278,     0,   260,     0,   146,
     137,   139,   142,   134,   307,   352,   393,     0,   330,     0,
       0,     0,     0,   192,     0,   198,   201,   238,   241,   243,
     244,     0,   246,     0,     0,     0,     0,     0,   274,   281,
     214,   391,   329,   327,   347,   341,   199,   245,   247,   248,
       0,     0,   282,     0,   249,     0,   284,   275,     0,     0,
     283,   285
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,   126,   289,   469,   183,   184,   282,
     283,   129,   193,    69,    70,   368,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,   205,   131,   132,   420,   421,   532,   533,   133,
     408,   409,   320,   135,   136,   437,   438,    29,   485,   441,
     442,   443,   336,   337,   587,   588,    87,    88,   513,   514,
     364,    89,   269,    90,    91,    92,   291,    93,    94,    95,
      96,    97,   190,   416,   417,    99,   221,   433,   434,   435,
     353,   354,   601,   602,   603,   717,   139,    14,   100,    16,
      31,    32,    17,    18,   143,   313,    19,    20,    21,   175,
     140,   461,   565,   462,   568,   638,   639,   471,    23,   315,
     472,   473,   642,   301,   165,   305,   451,   452,   453,   454,
     307,   166,   167,   168,   169,   170,   328,   329,   330,   191,
     101,   358,   359,   360,   102,   103,   104
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -509
static const yytype_int16 yypact[] =
{
     268,  -509,  -509,  -509,  -509,    26,    26,    38,    26,    38,
    1312,   105,   388,  -509,  2847,  -509,  -509,  -509,  -509,  -509,
     147,  -509,  2817,  -509,  -509,  -509,  -509,  -509,   242,   250,
      69,  -509,   275,    38,   184,  -509,   885,  2263,  1407,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  2452,  2484,  2484,
    2515,   109,   124,   149,   183,  1312,   196,    38,   212,   222,
    1488,    24,   225,   228,   233,  1516,   271,   290,  -509,  -509,
      49,   676,  2515,  -509,   307,   339,   324,   224,   344,   285,
     293,   305,   292,    18,  -509,  -509,   374,  -509,  -509,   243,
    -509,  -509,  -509,   786,  -509,  -509,  -509,  -509,   317,  -509,
    2515,  -509,  -509,  -509,  -509,  -509,  -509,   230,   460,    26,
     332,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,    58,   356,  -509,  -509,    57,  3155,
    3155,  -509,    63,  -509,  1177,   158,    62,  -509,   364,  -509,
    -509,    26,    26,   332,    38,   119,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,   386,  -509,  2744,   390,  -509,
    -509,    38,   411,  -509,    38,  -509,  -509,  -509,    26,   393,
    -509,  -509,  -509,  -509,    88,  1073,  1178,  1822,  -509,   397,
    -509,  2902,   414,  -509,   114,  1997,   436,   447,  1407,  -509,
    1407,  -509,  -509,  -509,  -509,   420,  1312,  2515,  2515,  2515,
     385,  1551,   461,  -509,  -509,  -509,   381,   439,  -509,  -509,
    -509,   465,  2932,   417,    38,  -509,   383,  -509,  2515,  2515,
    2295,    38,    38,  -509,  -509,  2515,  2515,  2515,  2515,  2515,
    2515,  2515,  2515,  2515,  2515,  2515,  -509,  2515,  2515,  2515,
    2515,  2515,  2515,  2515,  2515,  2515,  2515,  2515,  2515,  2515,
    2515,  2515,  2515,  2515,  2515,  2515,  -509,  2515,   271,  -509,
    -509,  1312,  -509,   466,  -509,   460,    75,  -509,    38,   476,
     439,  -509,   389,  -509,   986,  -509,  -509,   558,   482,  -509,
    -509,  1177,  3140,  1885,   942,   158,  -509,   478,  -509,   411,
    -509,  1611,    38,  -509,  3017,   271,   649,  -509,   390,  -509,
     148,   483,  -509,  -509,  -509,  2571,  -509,  -509,  -509,   391,
     413,  -509,  -509,  1277,  -509,  -509,  2515,   484,   487,  2902,
    -509,  -509,  1948,  1052,  -509,   283,  -509,   326,  1678,  -509,
     486,   488,  1312,  -509,   214,   218,   234,   490,  1597,   396,
    -509,  -509,  -509,   492,   165,   439,  -509,   494,   495,  2932,
    -509,   498,   499,  -509,   412,   248,   323,  -509,   252,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,   307,   307,   339,   339,
     324,   324,   324,   324,   224,   224,   344,   285,   293,   305,
      28,   292,  -509,  -509,  -509,  -509,  -509,  -509,   263,  -509,
     491,    38,    66,  -509,   230,  -509,   493,  -509,   501,   510,
     765,  -509,  2741,  1611,   558,  -509,  -509,   519,  -509,  -509,
    -509,  -509,  -509,  -509,  2011,   522,  -509,  1934,   508,   534,
     532,   540,  -509,  -509,  -509,   332,  -509,   535,  1611,   544,
     377,  -509,  -509,  3155,  3083,  -509,  -509,   545,    38,  -509,
    -509,    21,  3098,  -509,   870,   230,   230,  -509,  -509,  -509,
      57,  2817,  -509,  -509,  -509,  -509,   397,  2515,  -509,   484,
    -509,  -509,  2074,   546,  -509,   547,   551,   326,  2137,   309,
    1759,  -509,   561,   561,  -509,  1312,  1312,  1312,  2515,  2326,
     404,  1632,   553,   103,  -509,   557,  -509,  -509,   494,  -509,
    -509,  -509,   554,   271,  -509,   271,  -509,  2515,  -509,  2515,
     102,  -509,  2515,   338,  -509,  -509,  1759,   517,  -509,  -509,
    -509,  2515,   408,  -509,   559,   568,  2741,  1392,  -509,  -509,
     565,  -509,  2554,  -509,   134,  -509,     7,  -509,  1422,  -509,
    2626,  2987,   564,  -509,  -509,   410,  -509,  -509,  1611,  1611,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,   150,   573,    38,
    -509,   421,   423,   574,   397,  -509,   571,  -509,  -509,  -509,
    -509,  2200,   572,  -509,   575,  1759,  -509,  -509,   342,   509,
    -509,  -509,   260,  1312,   270,  2358,  2389,   441,  -509,    38,
     577,   569,   580,  -509,   584,    38,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,   111,  -509,  -509,   579,  -509,  -509,   194,
    2515,  -509,   445,  -509,  -509,  -509,  -509,  -509,  2681,  -509,
    -509,  2744,    38,  -509,   581,  3098,  2515,   582,   586,  -509,
    -509,  -509,   273,  -509,  -509,  -509,  -509,  -509,   585,  -509,
    -509,   343,  1759,  -509,  1312,   589,  -509,  1312,  1312,   277,
    1312,   284,  2421,   588,  2515,   103,   103,  -509,   591,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,    38,  -509,  2515,
     150,    38,  3140,  -509,  1726,  -509,  -509,  -509,  -509,  -509,
    -509,  1312,  -509,  1312,  1312,   300,   570,   311,   592,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    1312,   593,  -509,   578,  -509,  2515,  -509,   600,   313,   587,
    -509,  -509
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -509,  -509,  -509,   594,  -509,   325,   597,  -142,     5,  -154,
     199,  -509,   106,  -509,  -509,  -509,   503,  -509,    -2,   201,
     203,    84,   204,   365,   367,   369,   366,   370,   368,   -42,
     539,     2,  -467,  -272,  -509,   210,  -382,   100,    19,  -509,
     226,  -466,    -7,  -126,   -92,    -1,  -509,   345,  -273,  -257,
    -449,     6,  -313,  -311,  -508,    59,    37,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,    -9,   607,   -11,  -509,  -509,
    -509,  -509,    -5,  -509,   631,  -509,  -509,  -386,  -306,  -318,
     295,   371,   -18,  -509,   -12,  -509,  -509,  -509,    11,  -509,
      30,   548,  -509,  -509,   620,   359,  -509,  -509,  -509,  -131,
     -17,  -509,  -509,    94,  -509,  -509,   -20,   220,  -509,  -395,
    -509,  -509,  -509,  -270,   190,  -509,  -509,   208,  -509,   215,
      32,   116,   118,  -145,  -509,  -161,  -509,  -509,   336,  -509,
    -509,  -509,  -509,   312,  -509,  -509,  -509
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -360
static const yytype_int16 yytable[] =
{
      26,    26,    30,    26,    33,    98,   309,   134,   204,   137,
     295,    15,   299,   176,   483,   419,   274,   164,   615,   128,
     486,   440,   308,    15,   487,   186,   482,   560,   179,   197,
     319,    98,   448,   217,    24,    27,    28,   195,   530,   189,
     194,   519,   264,   322,   196,   325,   327,   187,   539,   457,
      98,   550,   212,    24,   611,   612,   229,   227,   230,   265,
     281,   231,   216,   278,   617,    24,   107,   226,   287,   265,
     246,   107,  -171,  -171,   625,   108,   524,   357,    25,   178,
     232,   233,   234,   218,    24,    24,   219,   220,    98,    24,
      24,   318,   210,   277,   109,   504,   539,   107,   272,   627,
     273,   407,   137,   335,    26,   105,   108,   275,   610,   627,
     599,   561,   562,   563,   564,    24,   540,   669,   267,   279,
     130,   284,   206,   137,   331,   290,   176,   288,   302,    24,
     270,   137,   600,   207,   285,   286,    26,    26,    24,   300,
     303,   332,   130,   542,   686,   292,    24,   611,   419,   322,
     325,   535,   419,   672,   628,   530,   141,   458,   208,   107,
     142,    24,   164,   636,   576,   293,   311,   294,   108,   314,
     582,   297,   298,    26,   323,    24,   686,    24,   503,   137,
      98,    98,   581,   406,   479,   272,   164,   180,   559,   197,
     181,   197,   209,   555,   504,   539,   187,   195,   187,   195,
     194,    98,   194,   107,   340,   211,   341,   531,   316,   344,
     345,   346,   108,   349,   508,   213,   584,   164,   267,   362,
      22,    24,   267,   270,   495,   214,   370,   371,   496,   486,
     365,   366,    22,   487,   222,   130,   130,   223,   267,   107,
     130,   335,   224,   343,   497,   383,   384,   385,   108,   254,
     255,   171,   267,   173,   174,   142,   517,    24,   515,   403,
     256,   257,   518,   648,   267,   419,    98,   520,    -2,   521,
     655,     1,   192,   410,   267,   290,    36,   681,   177,   178,
     657,   267,   425,   682,     2,     3,   422,   691,   267,   444,
     332,   130,   333,   130,   693,   292,   455,   300,   423,   228,
     195,   334,   292,   292,   267,   459,   260,   447,   404,   450,
     710,   571,   572,   261,   549,   267,   262,   267,    98,   583,
     470,   712,   570,   720,   164,   247,   248,   267,   476,   249,
     271,   516,   263,   488,   109,   489,   491,    98,   390,   391,
     392,   393,   613,   268,   614,   544,   652,   684,   653,   685,
     500,     4,     5,     6,   164,   250,   251,   109,   252,   253,
     270,   110,     7,     8,     9,   280,   115,   296,   117,   118,
     119,   120,   121,   122,   123,   124,    10,   266,   267,   494,
     554,   334,   258,   259,   351,   267,   363,   267,    -3,   304,
     130,     1,   413,   414,   474,   414,   317,   130,   130,   501,
     267,   267,   109,   310,     2,     3,   410,   595,   267,   137,
     130,   618,   619,   633,   558,   534,   312,   137,   295,   422,
     181,   130,   536,   422,   643,   414,   644,   414,   176,   110,
     543,   423,   137,   342,   115,   423,   117,   118,   119,   120,
     121,   122,   123,   124,   662,   267,   338,   195,   673,   619,
     544,   386,   387,   300,   552,   388,   389,   339,   450,   347,
     137,   137,   394,   395,   350,   137,   164,   567,   352,   361,
     309,     4,     5,     6,   355,   292,   405,   609,   108,   574,
     204,   411,     7,     8,     9,   109,   308,   424,   445,   204,
      98,    98,    98,   460,   125,   478,   492,   477,   493,   498,
     592,   594,   502,   597,   606,   507,   607,   506,   510,   511,
     527,   512,   110,   528,   522,   410,   526,   115,   545,   117,
     118,   119,   120,   121,   122,   123,   124,  -271,   334,   534,
     541,   137,   589,   590,   591,   273,   422,   137,   546,   137,
     705,   314,   547,   334,   548,   551,   164,   553,   423,   558,
     199,   201,   202,   203,   577,   470,   598,   578,   195,   130,
     637,   579,   137,   605,   641,   634,   490,   604,   130,   616,
     130,   621,   620,   624,   632,   203,   640,   645,   204,   646,
     649,   654,   665,   109,   666,   650,   664,   667,    98,   670,
     680,   677,   688,   683,   663,   679,   696,   659,   661,   711,
     668,   700,   715,   203,   719,   713,   106,   716,   410,   415,
     110,   127,   534,   525,   137,   115,   721,   117,   118,   119,
     120,   121,   122,   123,   124,   396,   164,   676,   397,   399,
     656,   398,   400,   470,   537,   401,   622,   523,   671,   439,
     567,     4,   334,   185,   651,   138,   418,   698,   172,    98,
     505,   412,    98,    98,   699,    98,   130,   276,   446,   635,
     703,   573,   557,   675,   695,   480,   697,   630,   556,   631,
       0,   509,   701,   637,   109,   137,   704,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    98,     0,    98,    98,
     203,   687,     0,   292,   689,   690,     0,   692,     0,   235,
       0,   110,     0,     0,     0,    98,   115,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   456,   718,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   707,     0,
     708,   709,     0,     0,   130,     0,     0,     0,     0,     0,
       0,   130,     0,     0,     0,     0,     0,   714,     0,     0,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   369,
       0,   529,     0,     0,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,     0,    -4,    34,   130,    35,
     109,    36,     0,    37,     0,    38,     0,     0,     0,     0,
      39,    40,    41,    42,    43,     0,   402,    44,     0,     0,
       0,     0,     0,    24,    45,    46,    47,   110,    48,    49,
       0,     0,   115,     0,   117,   118,   119,   120,   121,   122,
     123,   124,   432,     0,     0,     0,     0,     0,     0,     0,
       0,   203,     0,     0,     0,     0,     0,     0,     4,     0,
       0,     0,     0,   418,     0,    50,    51,    52,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,     0,     4,
       0,   432,     0,    62,     0,    63,     0,     0,     0,   569,
      64,     0,     0,    65,    66,     0,    34,    67,    35,     0,
      36,   182,    37,    68,    38,   109,     0,     0,     0,    39,
      40,    41,    42,    43,     0,     0,    44,     0,     0,     0,
     109,     0,    24,    45,    46,    47,     0,    48,    49,     0,
       0,     0,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   436,     4,    50,    51,    52,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,   109,     4,    24,
       0,     0,    62,   432,    63,     0,     0,     0,     0,    64,
       0,     0,    65,    66,     0,     0,    67,   192,     0,  -256,
    -256,    36,    68,     0,   110,     0,     0,     0,     0,   115,
       0,   117,   118,   119,   120,   121,   122,   123,   124,  -256,
       0,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   432,   203,     0,     0,   203,     0,   432,     0,   586,
       0,     0,     0,     0,   203,     0,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,     0,     0,   608,     0,     0,   332,
       0,   333,   484,     0,     0,   586,     0,   125,     0,     4,
     108,     0,     0,     0,    34,     0,    35,   109,    36,   321,
      37,     0,    38,     0,     0,     0,     0,    39,    40,    41,
      42,    43,     0,     0,    44,     0,     0,     0,   109,     0,
      24,    45,    46,    47,   110,    48,    49,     0,     0,   115,
       0,   117,   118,   119,   120,   121,   122,   123,   124,     0,
     432,     0,     0,   203,   586,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
       0,     0,    50,    51,    52,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,     0,     4,     0,     0,     0,
      62,     0,    63,     0,     0,     0,     0,    64,     0,     0,
      65,    66,     0,     0,    67,   678,     0,     0,   192,    34,
      68,    35,    36,    36,   324,    37,     0,    38,     0,     0,
       0,   586,    39,    40,    41,    42,    43,     0,     0,    44,
       0,     0,   109,     0,     0,    24,    45,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,     0,   702,     0,
       0,     0,     0,   586,     0,     0,     0,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,     0,     0,     0,    50,    51,    52,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
       4,     4,     0,     0,     0,    62,     0,    63,     0,     0,
       0,     0,    64,     0,     0,    65,    66,     0,    34,    67,
      35,     0,    36,   475,    37,    68,    38,     0,     0,     0,
       0,    39,    40,    41,    42,    43,     0,     0,    44,     0,
       0,     0,     0,     0,    24,    45,    46,    47,     0,    48,
      49,     0,     0,    34,     0,    35,     0,    36,     0,    37,
       0,    38,     0,     0,     0,     0,    39,    40,    41,    42,
      43,     0,     0,    44,     0,     0,     0,     0,     0,    24,
      45,    46,    47,     0,    48,    49,    50,    51,    52,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,     0,
       4,     0,     0,     0,    62,     0,    63,     0,     0,     0,
       0,    64,     0,     0,    65,    66,     0,     0,    67,     0,
       0,    50,    51,    52,    68,    53,    54,    55,    56,    57,
      58,    59,    60,    61,     0,     4,     0,     0,   623,    62,
       0,    63,     0,     0,     0,     0,    64,     0,   192,    65,
      66,     0,    36,    67,    37,     0,    38,   109,     0,    68,
       0,    39,    40,    41,    42,    43,     0,     0,    44,     0,
       0,     0,   109,     0,    24,    45,    46,    47,     0,    48,
      49,     0,     0,     0,   110,     0,     0,   109,     0,   115,
       0,   117,   118,   119,   120,   121,   122,   123,   124,   110,
       0,     0,     0,     0,   115,     0,   117,   118,   119,   120,
     121,   122,   123,   124,   110,     4,     0,     0,     0,   115,
     418,   117,   118,   119,   120,   121,   122,   123,   124,   626,
       4,   215,     0,     0,    62,    37,    63,    38,     0,     0,
       0,    64,    39,    40,    41,    42,    43,     0,     0,    44,
       0,     0,     0,     0,    68,    24,    45,    46,    47,   225,
      48,    49,     0,    37,     0,    38,     0,     0,     0,     0,
      39,    40,    41,    42,    43,     0,     0,    44,     0,     0,
       0,     0,     0,    24,    45,    46,    47,     0,    48,    49,
       0,     0,     0,     0,   348,     0,     0,     0,    37,     0,
      38,     0,     0,     0,     0,    39,    40,    41,    42,    43,
       0,     4,    44,     0,     0,    62,     0,    63,    24,    45,
      46,    47,    64,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,     0,     0,     0,     4,
     499,     0,     0,    62,    37,    63,    38,     0,     0,     0,
      64,    39,    40,    41,    42,    43,     0,     0,    44,     0,
       0,     0,     0,    68,    24,    45,    46,    47,     0,    48,
      49,     0,     0,     0,     4,   596,   109,     0,    62,    37,
      63,    38,     0,     0,     0,    64,    39,    40,    41,    42,
      43,     0,     0,    44,     0,     0,     0,     0,    68,    24,
      45,    46,    47,   110,    48,    49,     0,     0,   115,     0,
     117,   118,   119,   120,   121,   122,   123,   124,     0,     0,
       4,     0,     0,   490,    62,    37,    63,    38,     0,     0,
       0,    64,    39,    40,    41,    42,    43,     0,     0,    44,
       0,     0,     0,     0,    68,    24,    45,    46,    47,     0,
      48,    49,     0,     0,     0,     4,     0,     0,     0,    62,
       0,    63,     0,     0,     0,     0,    64,     0,     0,     0,
       0,   585,   706,    37,     0,    38,     0,     0,     0,    68,
      39,    40,    41,    42,    43,     0,     0,    44,     0,     0,
       0,     0,     0,    24,    45,    46,    47,     0,    48,    49,
       0,     4,     0,     0,   585,    62,    37,    63,    38,     0,
       0,     0,    64,    39,    40,    41,    42,    43,     0,     0,
      44,     0,     0,     0,     0,    68,    24,    45,    46,    47,
       0,    48,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       0,     0,     0,    62,     0,    63,     0,     0,     0,     0,
      64,     0,     0,     0,     0,     0,     0,     0,     0,    37,
       0,    38,     0,    68,     0,     0,    39,    40,    41,    42,
      43,     0,     4,    44,     0,     0,    62,   109,    63,    24,
      45,    46,    47,    64,    48,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    68,     0,     0,     0,
       0,     0,     0,     0,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
       0,     0,    37,   426,    38,     0,     0,     0,     0,    39,
      40,    41,    42,   427,     0,     4,    44,     0,     0,    62,
       0,    63,    24,    45,    46,    47,    64,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    68,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     428,   332,     0,   542,   429,     0,     0,   430,   431,     0,
       0,     0,   108,     0,     0,    37,   481,    38,     0,   109,
       0,    24,    39,    40,    41,    42,   427,     0,     4,    44,
       0,     0,    62,     0,    63,    24,    45,    46,    47,    64,
      48,    49,     0,     0,     0,     0,   110,     0,     0,     0,
       0,   115,    68,   117,   118,   119,   120,   121,   122,   123,
     124,     0,     0,   428,   332,     0,   333,   429,     0,     0,
     430,   431,     0,     0,     0,   108,     0,     0,    37,   538,
      38,     0,   109,     0,     0,    39,    40,    41,    42,   427,
       0,     4,    44,     0,     0,    62,     0,    63,    24,    45,
      46,    47,    64,    48,    49,     0,     0,     0,     0,   110,
       0,     0,     0,     0,   115,    68,   117,   118,   119,   120,
     121,   122,   123,   124,     0,     0,   428,     0,     0,     0,
     429,     0,     0,   430,   431,     0,     0,     0,     0,     0,
       0,    37,   575,    38,     0,     0,     0,     0,    39,    40,
      41,    42,   427,     0,     4,    44,     0,     0,    62,     0,
      63,    24,    45,    46,    47,    64,    48,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   428,
       0,     0,     0,   429,     0,     0,   430,   431,     0,     0,
       0,     0,     0,     0,    37,   580,    38,     0,     0,     0,
       0,    39,    40,    41,    42,   427,     0,     4,    44,     0,
       0,    62,     0,    63,    24,    45,    46,    47,    64,    48,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   428,     0,     0,     0,   429,     0,     0,   430,
     431,     0,     0,     0,     0,     0,     0,    37,   647,    38,
       0,     0,     0,     0,    39,    40,    41,    42,   427,     0,
       4,    44,     0,     0,    62,     0,    63,    24,    45,    46,
      47,    64,    48,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    68,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   428,     0,     0,     0,   429,
       0,     0,   430,   431,     0,     0,     0,     0,     0,     0,
      37,     0,    38,     0,     0,     0,     0,    39,    40,    41,
      42,    43,     0,     4,    44,     0,     0,    62,     0,    63,
      24,    45,    46,    47,    64,    48,    49,     0,     0,     0,
       0,     0,    37,     0,    38,   367,     0,    68,     0,    39,
      40,    41,    42,    43,     0,   188,    44,     0,     0,     0,
       0,     0,    24,    45,    46,    47,     0,    48,    49,     0,
       0,     0,     0,    37,     0,    38,   593,     0,     0,     0,
      39,    40,    41,    42,    43,     0,     4,    44,     0,     0,
      62,     0,    63,    24,    45,    46,    47,    64,    48,    49,
       0,     0,     0,     0,     0,    37,     0,    38,   658,     0,
      68,     0,    39,    40,    41,    42,    43,     0,     4,    44,
       0,     0,    62,     0,    63,    24,    45,    46,    47,    64,
      48,    49,     0,     0,     0,     0,    37,     0,    38,   660,
       0,     0,    68,    39,    40,    41,    42,    43,     0,     4,
      44,     0,     0,    62,     0,    63,    24,    45,    46,    47,
      64,    48,    49,     0,     0,     0,     0,     0,    37,     0,
      38,   694,     0,    68,     0,    39,    40,    41,    42,    43,
       0,     4,    44,     0,     0,    62,     0,    63,    24,    45,
      46,    47,    64,    48,    49,     0,     0,     0,     0,    37,
       0,   198,     0,     0,     0,    68,    39,    40,    41,    42,
      43,     0,     4,    44,     0,     0,    62,     0,    63,    24,
      45,    46,    47,    64,    48,    49,     0,     0,     0,     0,
       0,    37,     0,   200,     0,     0,    68,     0,    39,    40,
      41,    42,    43,     0,     4,    44,     0,     0,    62,     0,
      63,    24,    45,    46,    47,    64,    48,    49,     0,     0,
       0,     0,    37,     0,    38,     0,     0,     0,    68,    39,
      40,    41,    42,    43,     0,     4,    44,     0,     0,    62,
       0,    63,    24,    45,    46,    47,    64,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    68,
       0,   332,     0,   542,   484,     0,     0,     4,     0,     0,
       0,    62,   108,    63,     0,     0,     0,     0,    64,   109,
       0,    24,     0,     0,     0,     0,     0,     2,     3,     0,
       0,    68,     0,     0,     0,     0,   109,     0,     4,     0,
       0,     0,    62,     0,    63,     0,   110,     0,     0,    64,
       0,   115,     0,   117,   118,   119,   120,   121,   122,   123,
     124,     0,    68,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,     0,     0,
       0,     0,     2,     3,     0,     0,     0,     0,     0,     0,
       0,   109,     0,     0,     0,     0,     0,   463,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   464,   465,   466,   467,   468,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,     0,     0,     0,     2,     3,     0,
       0,     0,     0,     0,     0,     0,   109,     0,     0,     0,
       0,     0,   629,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   464,   465,
     466,   467,   468,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   306,     0,
     107,     0,     0,     0,   531,     0,     0,   145,     0,   108,
       0,     0,     0,     0,     0,     0,   109,   674,    24,     0,
       0,    24,     0,     0,   146,     0,     0,     0,     0,     0,
       0,     0,     0,   464,   465,   466,   467,   468,     0,     0,
       0,     0,     0,   110,     0,     0,   147,     0,   115,     0,
     117,   118,   119,   120,   121,   122,   123,   124,   148,   149,
     150,     0,     0,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   144,     0,     0,     0,
     145,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,     0,     0,   146,     0,     0,
       0,     0,     0,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,   108,     0,     0,     0,   147,
       0,     0,   109,     0,    24,     0,     0,     0,     0,     0,
       0,   148,   149,   150,     0,     0,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   326,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   125,    24,
       0,     0,   146,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   356,     0,     0,     0,     0,
       0,     0,     0,     0,   147,     0,     0,     0,     0,    24,
       0,     0,   146,     0,     0,     0,   148,   149,   150,     0,
       0,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   147,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,   149,   150,     0,
     145,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,    24,     0,     0,   146,   449,     0,
       0,     0,  -356,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   147,
       0,     0,   109,     0,     0,     0,     0,     0,     0,     0,
       0,   148,   149,   150,     0,     0,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   449,     0,     0,     0,  -359,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   566,     0,     0,     0,     0,     0,     0,  -359,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,     0,     4
};

static const yytype_int16 yycheck[] =
{
       5,     6,     7,     8,     9,    10,   167,    14,    50,    14,
     136,     0,   143,    30,   332,   287,   108,    22,   526,    14,
     333,   294,   167,    12,   335,    36,   332,     6,    33,    38,
     184,    36,   302,     9,    27,     5,     6,    38,   420,    37,
      38,    13,    24,   185,    38,   187,   191,    36,   434,   306,
      55,   446,    57,    27,   520,   522,     7,    66,     9,    41,
       3,    12,    60,     5,   531,    27,     9,    65,     5,    41,
      72,     9,     3,     4,    67,    18,    10,   222,    52,     4,
      31,    32,    33,    59,    27,    27,    62,    63,    93,    27,
      27,     3,    55,   110,    25,    29,   482,     9,   100,   548,
     107,    26,   107,   195,   109,     0,    18,   108,     6,   558,
       7,    90,    91,    92,    93,    27,   434,     6,     4,   124,
      14,   128,    13,   128,    10,   134,   143,   132,     9,    27,
      93,   136,    29,     9,   129,   130,   141,   142,    27,   144,
     145,     7,    36,     9,   652,   134,    27,   613,   420,   291,
     292,   423,   424,   620,   549,   537,     9,     9,     9,     9,
      13,    27,   167,    13,   482,     7,   171,     9,    18,   174,
     488,   141,   142,   178,   185,    27,   684,    27,    13,   184,
     185,   186,   488,   275,   329,   187,   191,     3,   458,   198,
       6,   200,     9,   450,    29,   581,   185,   198,   187,   200,
     198,   206,   200,     9,   198,     9,   200,    13,   178,   207,
     208,   209,    18,   211,   359,     3,   489,   222,     4,   224,
       0,    27,     4,   186,    10,     3,   231,   232,    10,   542,
     228,   229,    12,   544,     9,   129,   130,     9,     4,     9,
     134,   333,     9,   206,    10,   247,   248,   249,    18,    25,
      26,     9,     4,     3,     4,    13,     4,    27,    10,   268,
      36,    37,    10,   581,     4,   537,   271,     4,     0,     6,
      10,     3,     1,   278,     4,   284,     5,     4,     3,     4,
      10,     4,   291,    10,    16,    17,   287,    10,     4,   294,
       7,   185,     9,   187,    10,   284,   305,   302,   287,     9,
     301,   195,   291,   292,     4,   310,    21,   301,   271,   304,
      10,   465,   466,    20,   445,     4,    11,     4,   323,    10,
     315,    10,   464,    10,   329,    18,    19,     4,   326,    22,
      13,     8,    40,     7,    25,     9,   338,   342,   254,   255,
     256,   257,     4,   100,     6,   437,     4,     4,     6,     6,
     348,    83,    84,    85,   359,    16,    17,    25,    34,    35,
     323,    52,    94,    95,    96,     9,    57,     3,    59,    60,
      61,    62,    63,    64,    65,    66,   108,     3,     4,   342,
       3,   275,    38,    39,     3,     4,     3,     4,     0,     3,
     284,     3,     3,     4,     3,     4,     3,   291,   292,     3,
       4,     4,    25,    13,    16,    17,   411,     3,     4,   414,
     304,     3,     4,     3,     4,   422,     5,   422,   544,   420,
       6,   315,   423,   424,     3,     4,     3,     4,   445,    52,
     437,   420,   437,    13,    57,   424,    59,    60,    61,    62,
      63,    64,    65,    66,     3,     4,    10,   448,     3,     4,
     542,   250,   251,   458,   448,   252,   253,    10,   453,    74,
     465,   466,   258,   259,     3,   470,   471,   462,    29,    52,
     631,    83,    84,    85,     9,   464,    10,   519,    18,   477,
     522,     5,    94,    95,    96,    25,   631,     5,    10,   531,
     495,   496,   497,    10,    81,     8,    10,    13,    10,     9,
     498,   499,    10,   501,   513,    10,   515,    13,    10,    10,
       9,    99,    52,     3,    23,   520,    23,    57,    10,    59,
      60,    61,    62,    63,    64,    65,    66,     8,   422,   536,
       8,   536,   495,   496,   497,   542,   537,   542,     4,   544,
     682,   546,    10,   437,     4,    10,   551,     3,   537,     4,
      47,    48,    49,    50,     8,   550,     3,    10,   559,   453,
     567,    10,   567,     9,   569,   559,     5,    10,   462,    52,
     464,     3,    13,     8,    10,    72,     3,     3,   620,     8,
       8,    72,    13,    25,     4,    10,     9,     3,   593,    10,
       4,    10,     3,     8,   599,    13,     8,   595,   596,    29,
     605,    10,     9,   100,     4,    13,    12,    29,   613,   284,
      52,    14,   619,   414,   619,    57,    29,    59,    60,    61,
      62,    63,    64,    65,    66,   260,   631,   632,   261,   263,
     593,   262,   264,   628,   424,   265,   536,   411,   619,   294,
     635,    83,   536,    36,   585,    14,    88,   665,    28,   654,
     355,   280,   657,   658,   666,   660,   550,   109,   299,   565,
     680,   471,   454,   631,   662,   329,   664,   551,   453,   551,
      -1,   359,   677,   680,    25,   680,   681,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   691,    -1,   693,   694,
     187,   654,    -1,   682,   657,   658,    -1,   660,    -1,    23,
      -1,    52,    -1,    -1,    -1,   710,    57,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    67,   715,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,   691,    -1,
     693,   694,    -1,    -1,   628,    -1,    -1,    -1,    -1,    -1,
      -1,   635,    -1,    -1,    -1,    -1,    -1,   710,    -1,    -1,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   230,
      -1,     6,    -1,    -1,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,    -1,     0,     1,   682,     3,
      25,     5,    -1,     7,    -1,     9,    -1,    -1,    -1,    -1,
      14,    15,    16,    17,    18,    -1,   267,    21,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    52,    32,    33,
      -1,    -1,    57,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,   293,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   338,    -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,
      -1,    -1,    -1,    88,    -1,    69,    70,    71,    -1,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    83,
      -1,   332,    -1,    87,    -1,    89,    -1,    -1,    -1,     9,
      94,    -1,    -1,    97,    98,    -1,     1,   101,     3,    -1,
       5,     6,     7,   107,     9,    25,    -1,    -1,    -1,    14,
      15,    16,    17,    18,    -1,    -1,    21,    -1,    -1,    -1,
      25,    -1,    27,    28,    29,    30,    -1,    32,    33,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    10,    83,    69,    70,    71,    -1,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    25,    83,    27,
      -1,    -1,    87,   434,    89,    -1,    -1,    -1,    -1,    94,
      -1,    -1,    97,    98,    -1,    -1,   101,     1,    -1,     3,
       4,     5,   107,    -1,    52,    -1,    -1,    -1,    -1,    57,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    23,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   482,   519,    -1,    -1,   522,    -1,   488,    -1,   490,
      -1,    -1,    -1,    -1,   531,    -1,    -1,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    -1,    -1,   517,    -1,    -1,     7,
      -1,     9,    10,    -1,    -1,   526,    -1,    81,    -1,    83,
      18,    -1,    -1,    -1,     1,    -1,     3,    25,     5,     6,
       7,    -1,     9,    -1,    -1,    -1,    -1,    14,    15,    16,
      17,    18,    -1,    -1,    21,    -1,    -1,    -1,    25,    -1,
      27,    28,    29,    30,    52,    32,    33,    -1,    -1,    57,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
     581,    -1,    -1,   620,   585,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    69,    70,    71,    -1,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    83,    -1,    -1,    -1,
      87,    -1,    89,    -1,    -1,    -1,    -1,    94,    -1,    -1,
      97,    98,    -1,    -1,   101,   636,    -1,    -1,     1,     1,
     107,     3,     5,     5,     6,     7,    -1,     9,    -1,    -1,
      -1,   652,    14,    15,    16,    17,    18,    -1,    -1,    21,
      -1,    -1,    25,    -1,    -1,    27,    28,    29,    30,    -1,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,   679,    -1,
      -1,    -1,    -1,   684,    -1,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    -1,    -1,    69,    70,    71,
      -1,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      83,    83,    -1,    -1,    -1,    87,    -1,    89,    -1,    -1,
      -1,    -1,    94,    -1,    -1,    97,    98,    -1,     1,   101,
       3,    -1,     5,     6,     7,   107,     9,    -1,    -1,    -1,
      -1,    14,    15,    16,    17,    18,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    -1,    32,
      33,    -1,    -1,     1,    -1,     3,    -1,     5,    -1,     7,
      -1,     9,    -1,    -1,    -1,    -1,    14,    15,    16,    17,
      18,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    -1,    32,    33,    69,    70,    71,    -1,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      83,    -1,    -1,    -1,    87,    -1,    89,    -1,    -1,    -1,
      -1,    94,    -1,    -1,    97,    98,    -1,    -1,   101,    -1,
      -1,    69,    70,    71,   107,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    83,    -1,    -1,     6,    87,
      -1,    89,    -1,    -1,    -1,    -1,    94,    -1,     1,    97,
      98,    -1,     5,   101,     7,    -1,     9,    25,    -1,   107,
      -1,    14,    15,    16,    17,    18,    -1,    -1,    21,    -1,
      -1,    -1,    25,    -1,    27,    28,    29,    30,    -1,    32,
      33,    -1,    -1,    -1,    52,    -1,    -1,    25,    -1,    57,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    52,
      -1,    -1,    -1,    -1,    57,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    52,    83,    -1,    -1,    -1,    57,
      88,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      83,     3,    -1,    -1,    87,     7,    89,     9,    -1,    -1,
      -1,    94,    14,    15,    16,    17,    18,    -1,    -1,    21,
      -1,    -1,    -1,    -1,   107,    27,    28,    29,    30,     3,
      32,    33,    -1,     7,    -1,     9,    -1,    -1,    -1,    -1,
      14,    15,    16,    17,    18,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    -1,    32,    33,
      -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,     7,    -1,
       9,    -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,
      -1,    83,    21,    -1,    -1,    87,    -1,    89,    27,    28,
      29,    30,    94,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,    -1,    -1,    -1,    83,
       3,    -1,    -1,    87,     7,    89,     9,    -1,    -1,    -1,
      94,    14,    15,    16,    17,    18,    -1,    -1,    21,    -1,
      -1,    -1,    -1,   107,    27,    28,    29,    30,    -1,    32,
      33,    -1,    -1,    -1,    83,     3,    25,    -1,    87,     7,
      89,     9,    -1,    -1,    -1,    94,    14,    15,    16,    17,
      18,    -1,    -1,    21,    -1,    -1,    -1,    -1,   107,    27,
      28,    29,    30,    52,    32,    33,    -1,    -1,    57,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      83,    -1,    -1,     5,    87,     7,    89,     9,    -1,    -1,
      -1,    94,    14,    15,    16,    17,    18,    -1,    -1,    21,
      -1,    -1,    -1,    -1,   107,    27,    28,    29,    30,    -1,
      32,    33,    -1,    -1,    -1,    83,    -1,    -1,    -1,    87,
      -1,    89,    -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,
      -1,     5,     6,     7,    -1,     9,    -1,    -1,    -1,   107,
      14,    15,    16,    17,    18,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    -1,    32,    33,
      -1,    83,    -1,    -1,     5,    87,     7,    89,     9,    -1,
      -1,    -1,    94,    14,    15,    16,    17,    18,    -1,    -1,
      21,    -1,    -1,    -1,    -1,   107,    27,    28,    29,    30,
      -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      -1,    -1,    -1,    87,    -1,    89,    -1,    -1,    -1,    -1,
      94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      -1,     9,    -1,   107,    -1,    -1,    14,    15,    16,    17,
      18,    -1,    83,    21,    -1,    -1,    87,    25,    89,    27,
      28,    29,    30,    94,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      -1,    -1,     7,     8,     9,    -1,    -1,    -1,    -1,    14,
      15,    16,    17,    18,    -1,    83,    21,    -1,    -1,    87,
      -1,    89,    27,    28,    29,    30,    94,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,     7,    -1,     9,    59,    -1,    -1,    62,    63,    -1,
      -1,    -1,    18,    -1,    -1,     7,     8,     9,    -1,    25,
      -1,    27,    14,    15,    16,    17,    18,    -1,    83,    21,
      -1,    -1,    87,    -1,    89,    27,    28,    29,    30,    94,
      32,    33,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    57,   107,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    -1,    55,     7,    -1,     9,    59,    -1,    -1,
      62,    63,    -1,    -1,    -1,    18,    -1,    -1,     7,     8,
       9,    -1,    25,    -1,    -1,    14,    15,    16,    17,    18,
      -1,    83,    21,    -1,    -1,    87,    -1,    89,    27,    28,
      29,    30,    94,    32,    33,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    57,   107,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    -1,    55,    -1,    -1,    -1,
      59,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,     7,     8,     9,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    -1,    83,    21,    -1,    -1,    87,    -1,
      89,    27,    28,    29,    30,    94,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    59,    -1,    -1,    62,    63,    -1,    -1,
      -1,    -1,    -1,    -1,     7,     8,     9,    -1,    -1,    -1,
      -1,    14,    15,    16,    17,    18,    -1,    83,    21,    -1,
      -1,    87,    -1,    89,    27,    28,    29,    30,    94,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    59,    -1,    -1,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,     7,     8,     9,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    -1,
      83,    21,    -1,    -1,    87,    -1,    89,    27,    28,    29,
      30,    94,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    59,
      -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,     9,    -1,    -1,    -1,    -1,    14,    15,    16,
      17,    18,    -1,    83,    21,    -1,    -1,    87,    -1,    89,
      27,    28,    29,    30,    94,    32,    33,    -1,    -1,    -1,
      -1,    -1,     7,    -1,     9,    10,    -1,   107,    -1,    14,
      15,    16,    17,    18,    -1,    52,    21,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    -1,    32,    33,    -1,
      -1,    -1,    -1,     7,    -1,     9,    10,    -1,    -1,    -1,
      14,    15,    16,    17,    18,    -1,    83,    21,    -1,    -1,
      87,    -1,    89,    27,    28,    29,    30,    94,    32,    33,
      -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,    -1,
     107,    -1,    14,    15,    16,    17,    18,    -1,    83,    21,
      -1,    -1,    87,    -1,    89,    27,    28,    29,    30,    94,
      32,    33,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,
      -1,    -1,   107,    14,    15,    16,    17,    18,    -1,    83,
      21,    -1,    -1,    87,    -1,    89,    27,    28,    29,    30,
      94,    32,    33,    -1,    -1,    -1,    -1,    -1,     7,    -1,
       9,    10,    -1,   107,    -1,    14,    15,    16,    17,    18,
      -1,    83,    21,    -1,    -1,    87,    -1,    89,    27,    28,
      29,    30,    94,    32,    33,    -1,    -1,    -1,    -1,     7,
      -1,     9,    -1,    -1,    -1,   107,    14,    15,    16,    17,
      18,    -1,    83,    21,    -1,    -1,    87,    -1,    89,    27,
      28,    29,    30,    94,    32,    33,    -1,    -1,    -1,    -1,
      -1,     7,    -1,     9,    -1,    -1,   107,    -1,    14,    15,
      16,    17,    18,    -1,    83,    21,    -1,    -1,    87,    -1,
      89,    27,    28,    29,    30,    94,    32,    33,    -1,    -1,
      -1,    -1,     7,    -1,     9,    -1,    -1,    -1,   107,    14,
      15,    16,    17,    18,    -1,    83,    21,    -1,    -1,    87,
      -1,    89,    27,    28,    29,    30,    94,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
      -1,     7,    -1,     9,    10,    -1,    -1,    83,    -1,    -1,
      -1,    87,    18,    89,    -1,    -1,    -1,    -1,    94,    25,
      -1,    27,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,
      -1,   107,    -1,    -1,    -1,    -1,    25,    -1,    83,    -1,
      -1,    -1,    87,    -1,    89,    -1,    52,    -1,    -1,    94,
      -1,    57,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,   107,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   103,   104,   105,   106,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    -1,    -1,    -1,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,
     104,   105,   106,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     4,    -1,
       9,    -1,    -1,    -1,    13,    -1,    -1,    13,    -1,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    86,    27,    -1,
      -1,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   103,   104,   105,   106,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    52,    -1,    57,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    64,    65,
      66,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,     9,    -1,    -1,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    52,
      -1,    -1,    25,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    66,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    27,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    30,    -1,    -1,    -1,    64,    65,    66,    -1,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,
      13,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    27,    -1,    -1,    30,     1,    -1,
      -1,    -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    66,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,     1,    -1,    -1,    -1,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    83
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    16,    17,    83,    84,    85,    94,    95,    96,
     108,   110,   111,   112,   196,   197,   198,   201,   202,   205,
     206,   207,   216,   217,    27,    52,   181,   199,   199,   156,
     181,   199,   200,   181,     1,     3,     5,     7,     9,    14,
      15,    16,    17,    18,    21,    28,    29,    30,    32,    33,
      69,    70,    71,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    87,    89,    94,    97,    98,   101,   107,   122,
     123,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   165,   166,   170,
     172,   173,   174,   176,   177,   178,   179,   180,   181,   184,
     197,   239,   243,   244,   245,     0,   112,     9,    18,    25,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    81,   113,   115,   117,   120,
     121,   142,   143,   148,   151,   152,   153,   181,   183,   195,
     209,     9,    13,   203,     9,    13,    30,    52,    64,    65,
      66,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,   181,   223,   230,   231,   232,   233,
     234,     9,   203,     3,     4,   208,   209,     3,     4,   181,
       3,     6,     6,   116,   117,   175,   176,   197,    52,   140,
     181,   238,     1,   121,   140,   154,   160,   174,     9,   125,
       9,   125,   125,   125,   138,   141,    13,     9,     9,     9,
     165,     9,   181,     3,     3,     3,   140,     9,    59,    62,
      63,   185,     9,     9,     9,     3,   140,   174,     9,     7,
       9,    12,    31,    32,    33,    23,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,   127,    18,    19,    22,
      16,    17,    34,    35,    25,    26,    36,    37,    38,    39,
      21,    20,    11,    40,    24,    41,     3,     4,   100,   171,
     165,    13,   127,   151,   153,   154,   200,   209,     5,   181,
       9,     3,   118,   119,   151,   117,   117,     5,   181,   114,
     174,   175,   197,     7,     9,   152,     3,   199,   199,   208,
     181,   222,     9,   181,     3,   224,     4,   229,   232,   234,
      13,   181,     5,   204,   181,   218,   199,     3,     3,   118,
     151,     6,   116,   176,     6,   116,    13,   232,   235,   236,
     237,    10,     7,     9,   121,   153,   161,   162,    10,    10,
     160,   160,    13,   165,   140,   140,   140,    74,     3,   140,
       3,     3,    29,   189,   190,     9,    13,   232,   240,   241,
     242,    52,   181,     3,   169,   140,   140,    10,   124,   139,
     181,   181,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   127,   127,   127,   128,   128,   129,   129,
     130,   130,   130,   130,   131,   131,   132,   133,   134,   135,
     137,   136,   139,   174,   165,    10,   153,    26,   149,   150,
     181,     5,   190,     3,     4,   114,   182,   183,    88,   142,
     144,   145,   154,   197,     5,   174,     8,    18,    55,    59,
      62,    63,   139,   186,   187,   188,    10,   154,   155,   156,
     157,   158,   159,   160,   181,    10,   204,   160,   222,     1,
     117,   225,   226,   227,   228,   174,    67,   158,     9,   181,
      10,   210,   212,    86,   102,   103,   104,   105,   106,   115,
     117,   216,   219,   220,     3,     6,   140,    13,     8,   232,
     237,     8,   187,   188,    10,   157,   161,   162,     7,     9,
       5,   127,    10,    10,   165,    10,    10,    10,     9,     3,
     140,     3,    10,    13,    29,   189,    13,    10,   232,   242,
      10,    10,    99,   167,   168,    10,     8,     4,    10,    13,
       4,     6,    23,   149,    10,   119,    23,     9,     3,     6,
     145,    13,   146,   147,   151,   142,   154,   144,     8,   186,
     188,     8,     9,   151,   153,    10,     4,    10,     4,   208,
     218,    10,   160,     3,     3,   158,   228,   226,     4,   222,
       6,    90,    91,    92,    93,   211,     3,   117,   213,     9,
     116,   118,   118,   223,   140,     8,   188,     8,    10,    10,
       8,   187,   188,    10,   157,     5,   139,   163,   164,   165,
     165,   165,   140,    10,   140,     3,     3,   140,     3,     7,
      29,   191,   192,   193,    10,     9,   174,   174,   139,   138,
       6,   150,   141,     4,     6,   163,    52,   141,     3,     4,
      13,     3,   146,     6,     8,    67,    67,   159,   218,    86,
     230,   231,    10,     3,   160,   212,    13,   151,   214,   215,
       3,   181,   221,     3,     3,     3,     8,     8,   188,     8,
      10,   164,     4,     6,    72,    10,   165,    10,    10,   140,
      10,   140,     3,   181,     9,    13,     4,     3,   181,     6,
      10,   147,   141,     3,    86,   229,   181,    10,   139,    13,
       4,     4,    10,     8,     4,     6,   163,   165,     3,   165,
     165,    10,   165,    10,    10,   140,     8,   140,   191,   193,
      10,   181,   139,   215,   181,   116,     6,   165,   165,   165,
      10,    29,    10,    13,   165,     9,    29,   194,   140,     4,
      10,    29
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
#line 847 "c-grammar.y"
    { START_PROFILE(name_2) (yyval) = Scm_ApplyRec1(name_1, (yyvsp[(2) - (2)])); END_PROFILE(name_2) }
    break;

  case 7:
#line 856 "c-grammar.y"
    { START_PROFILE(name_3) (yyval) = Scm_AllReferencedInfoClear(); END_PROFILE(name_3) }
    break;

  case 8:
#line 857 "c-grammar.y"
    { START_PROFILE(name_4) (yyval) = Scm_AllReferencedInfoClear(); END_PROFILE(name_4) }
    break;

  case 9:
#line 858 "c-grammar.y"
    { START_PROFILE(name_5) (yyval) = Scm_AllReferencedInfoClear(); END_PROFILE(name_5) }
    break;

  case 10:
#line 859 "c-grammar.y"
    { START_PROFILE(name_6) (yyval) = Scm_AllReferencedInfoClear(); END_PROFILE(name_6) }
    break;

  case 11:
#line 860 "c-grammar.y"
    { START_PROFILE(name_7) (yyval) = Scm_AllReferencedInfoClear(); END_PROFILE(name_7) }
    break;

  case 12:
#line 864 "c-grammar.y"
    { START_PROFILE(name_9) (yyval) = Scm_EmitDefineInline(name_8,(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); END_PROFILE(name_9) }
    break;

  case 13:
#line 865 "c-grammar.y"
    { START_PROFILE(name_10) (yyval) = Scm_EmitDefineInline((yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)])); END_PROFILE(name_10) }
    break;

  case 14:
#line 869 "c-grammar.y"
    { START_PROFILE(name_12) (yyval) = Scm_ApplyRec1(name_11, (yyvsp[(1) - (1)])); END_PROFILE(name_12) }
    break;

  case 15:
#line 870 "c-grammar.y"
    { START_PROFILE(name_13) (yyval) = SCM_FALSE; END_PROFILE(name_13) }
    break;

  case 16:
#line 874 "c-grammar.y"
    { START_PROFILE(name_14) (yyval) = Scm_ExternalDeclaration((yyvsp[(1) - (2)]),SCM_LIST1(Scm_NullDeclarator())); END_PROFILE(name_14) }
    break;

  case 17:
#line 875 "c-grammar.y"
    { START_PROFILE(name_15) (yyval) = Scm_ExternalDeclaration((yyvsp[(1) - (3)]),(yyvsp[(2) - (3)])); END_PROFILE(name_15) }
    break;

  case 18:
#line 879 "c-grammar.y"
    { START_PROFILE(name_17) (yyval) = Scm_Declaration((yyvsp[(1) - (2)]),name_16); END_PROFILE(name_17) }
    break;

  case 19:
#line 880 "c-grammar.y"
    { START_PROFILE(name_18) (yyval) = Scm_Declaration((yyvsp[(1) - (3)]),(yyvsp[(2) - (3)])); END_PROFILE(name_18) }
    break;

  case 20:
#line 881 "c-grammar.y"
    { START_PROFILE(name_19) (yyval) = (yyvsp[(2) - (2)]); END_PROFILE(name_19) }
    break;

  case 22:
#line 886 "c-grammar.y"
    { START_PROFILE(name_20) (yyval) = CParser_Append((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); END_PROFILE(name_20) }
    break;

  case 23:
#line 887 "c-grammar.y"
    { START_PROFILE(name_21) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_21) }
    break;

  case 24:
#line 888 "c-grammar.y"
    { START_PROFILE(name_22) (yyval) = CParser_Append((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); END_PROFILE(name_22) }
    break;

  case 25:
#line 892 "c-grammar.y"
    { START_PROFILE(name_23) (yyval) = CParser_List(Scm_ComposeVariableAttribute((yyvsp[(1) - (1)]))); END_PROFILE(name_23) }
    break;

  case 26:
#line 893 "c-grammar.y"
    { START_PROFILE(name_24) (yyval) = CParser_AddList((yyvsp[(1) - (3)]),Scm_ComposeVariableAttribute((yyvsp[(3) - (3)]))); END_PROFILE(name_24) }
    break;

  case 27:
#line 897 "c-grammar.y"
    { START_PROFILE(name_25) (yyval) = Scm_ComposeDeclarator((yyvsp[(1) - (4)]),Scm_InitValueDeclarator((yyvsp[(4) - (4)]))); END_PROFILE(name_25) }
    break;

  case 28:
#line 898 "c-grammar.y"
    { START_PROFILE(name_26) (yyval) = (yyvsp[(1) - (2)]); END_PROFILE(name_26) }
    break;

  case 29:
#line 902 "c-grammar.y"
    { START_PROFILE(name_28) (yyval) = name_27; END_PROFILE(name_28) }
    break;

  case 30:
#line 903 "c-grammar.y"
    { START_PROFILE(name_29) (yyval) = name_16; END_PROFILE(name_29) }
    break;

  case 31:
#line 904 "c-grammar.y"
    { START_PROFILE(name_30) (yyval) = name_16; END_PROFILE(name_30) }
    break;

  case 32:
#line 905 "c-grammar.y"
    { START_PROFILE(name_31) (yyval) = name_16; END_PROFILE(name_31) }
    break;

  case 33:
#line 906 "c-grammar.y"
    { START_PROFILE(name_32) (yyval) = name_16; END_PROFILE(name_32) }
    break;

  case 34:
#line 910 "c-grammar.y"
    { START_PROFILE(name_33) (yyval) = CParser_Typename((yyvsp[(1) - (1)])); END_PROFILE(name_33) }
    break;

  case 35:
#line 911 "c-grammar.y"
    { START_PROFILE(name_35) (yyval) = name_34; END_PROFILE(name_35) }
    break;

  case 36:
#line 912 "c-grammar.y"
    { START_PROFILE(name_37) (yyval) = name_36; END_PROFILE(name_37) }
    break;

  case 37:
#line 913 "c-grammar.y"
    { START_PROFILE(name_38) (yyval) = name_16; END_PROFILE(name_38) }
    break;

  case 38:
#line 914 "c-grammar.y"
    { START_PROFILE(name_39) (yyval) = name_16; END_PROFILE(name_39) }
    break;

  case 39:
#line 915 "c-grammar.y"
    { START_PROFILE(name_40) (yyval) = name_16; END_PROFILE(name_40) }
    break;

  case 40:
#line 916 "c-grammar.y"
    { START_PROFILE(name_42) (yyval) = Scm_ApplyRec1(name_41, (yyvsp[(1) - (1)])); END_PROFILE(name_42) }
    break;

  case 41:
#line 917 "c-grammar.y"
    { START_PROFILE(name_44) (yyval) = Scm_ApplyRec1(name_43, (yyvsp[(1) - (1)])); END_PROFILE(name_44) }
    break;

  case 42:
#line 918 "c-grammar.y"
    { START_PROFILE(name_45) (yyval) = name_16; END_PROFILE(name_45) }
    break;

  case 43:
#line 919 "c-grammar.y"
    { START_PROFILE(name_46) (yyval) = CParser_Typename((yyvsp[(1) - (2)])); END_PROFILE(name_46) }
    break;

  case 44:
#line 920 "c-grammar.y"
    { START_PROFILE(name_48) (yyval) = name_47; END_PROFILE(name_48) }
    break;

  case 45:
#line 924 "c-grammar.y"
    { START_PROFILE(name_50) (yyval) = Scm_ApplyRec1(name_49, (yyvsp[(1) - (1)])); END_PROFILE(name_50) }
    break;

  case 46:
#line 925 "c-grammar.y"
    { START_PROFILE(name_51) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_51) }
    break;

  case 47:
#line 926 "c-grammar.y"
    { START_PROFILE(name_52) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_52) }
    break;

  case 48:
#line 927 "c-grammar.y"
    { START_PROFILE(name_54) (yyval) = Scm_ApplyRec1(name_53, (yyvsp[(1) - (1)])); END_PROFILE(name_54) }
    break;

  case 49:
#line 928 "c-grammar.y"
    { START_PROFILE(name_56) (yyval) = Scm_ApplyRec1(name_55, (yyvsp[(2) - (3)])); END_PROFILE(name_56) }
    break;

  case 50:
#line 929 "c-grammar.y"
    { START_PROFILE(name_58) (yyval) = Scm_ApplyRec1(name_57, (yyvsp[(2) - (3)])); END_PROFILE(name_58) }
    break;

  case 51:
#line 930 "c-grammar.y"
    { START_PROFILE(name_59) (yyval) = SCM_FALSE; END_PROFILE(name_59) }
    break;

  case 52:
#line 931 "c-grammar.y"
    { START_PROFILE(name_60) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_60) }
    break;

  case 53:
#line 932 "c-grammar.y"
    { START_PROFILE(name_61) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_61) }
    break;

  case 54:
#line 933 "c-grammar.y"
    { START_PROFILE(name_62) (yyval) = SCM_FALSE; END_PROFILE(name_62) }
    break;

  case 55:
#line 934 "c-grammar.y"
    { START_PROFILE(name_63) (yyval) = SCM_FALSE; END_PROFILE(name_63) }
    break;

  case 56:
#line 938 "c-grammar.y"
    { START_PROFILE(name_64) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_64) }
    break;

  case 57:
#line 939 "c-grammar.y"
    { START_PROFILE(name_66) (yyval) = Scm_ApplyRec2(name_65, (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); END_PROFILE(name_66) }
    break;

  case 58:
#line 940 "c-grammar.y"
    { START_PROFILE(name_68) (yyval) = Scm_ApplyRec2(name_67, (yyvsp[(1) - (3)]), name_16); END_PROFILE(name_68) }
    break;

  case 59:
#line 941 "c-grammar.y"
    { START_PROFILE(name_69) (yyval) = Scm_ApplyRec2(name_67, (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); END_PROFILE(name_69) }
    break;

  case 60:
#line 942 "c-grammar.y"
    { START_PROFILE(name_71) (yyval) = Scm_ApplyRec2(name_70, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); END_PROFILE(name_71) }
    break;

  case 61:
#line 943 "c-grammar.y"
    { START_PROFILE(name_73) (yyval) = Scm_ApplyRec2(name_72, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); END_PROFILE(name_73) }
    break;

  case 62:
#line 944 "c-grammar.y"
    { START_PROFILE(name_75) (yyval) = Scm_ApplyRec1(name_74, (yyvsp[(1) - (2)])); END_PROFILE(name_75) }
    break;

  case 63:
#line 945 "c-grammar.y"
    { START_PROFILE(name_77) (yyval) = Scm_ApplyRec1(name_76, (yyvsp[(1) - (2)])); END_PROFILE(name_77) }
    break;

  case 64:
#line 949 "c-grammar.y"
    { START_PROFILE(name_78) (yyval) = CParser_List((yyvsp[(1) - (1)])); END_PROFILE(name_78) }
    break;

  case 65:
#line 950 "c-grammar.y"
    { START_PROFILE(name_79) (yyval) = CParser_AddList((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); END_PROFILE(name_79) }
    break;

  case 66:
#line 954 "c-grammar.y"
    { START_PROFILE(name_80) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_80) }
    break;

  case 67:
#line 955 "c-grammar.y"
    { START_PROFILE(name_82) (yyval) = Scm_ApplyRec1(name_81, (yyvsp[(2) - (2)])); END_PROFILE(name_82) }
    break;

  case 68:
#line 956 "c-grammar.y"
    { START_PROFILE(name_84) (yyval) = Scm_ApplyRec1(name_83, (yyvsp[(2) - (2)])); END_PROFILE(name_84) }
    break;

  case 69:
#line 957 "c-grammar.y"
    { START_PROFILE(name_86) (yyval) = Scm_ApplyRec2(name_85, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); END_PROFILE(name_86) }
    break;

  case 70:
#line 958 "c-grammar.y"
    { START_PROFILE(name_88) (yyval) = Scm_ApplyRec1(name_87, (yyvsp[(2) - (2)])); END_PROFILE(name_88) }
    break;

  case 71:
#line 959 "c-grammar.y"
    { START_PROFILE(name_90) (yyval) = Scm_ApplyRec1(name_89, (yyvsp[(3) - (4)])); END_PROFILE(name_90) }
    break;

  case 72:
#line 960 "c-grammar.y"
    { START_PROFILE(name_91) (yyval) = (yyvsp[(2) - (2)]); END_PROFILE(name_91) }
    break;

  case 73:
#line 964 "c-grammar.y"
    { START_PROFILE(name_92) (yyval) = token_sym__26; END_PROFILE(name_92) }
    break;

  case 74:
#line 965 "c-grammar.y"
    { START_PROFILE(name_93) (yyval) = token_sym__2a; END_PROFILE(name_93) }
    break;

  case 75:
#line 966 "c-grammar.y"
    { START_PROFILE(name_94) (yyval) = token_sym__2b; END_PROFILE(name_94) }
    break;

  case 76:
#line 967 "c-grammar.y"
    { START_PROFILE(name_95) (yyval) = token_sym__; END_PROFILE(name_95) }
    break;

  case 77:
#line 968 "c-grammar.y"
    { START_PROFILE(name_96) (yyval) = token_sym__7e; END_PROFILE(name_96) }
    break;

  case 78:
#line 969 "c-grammar.y"
    { START_PROFILE(name_97) (yyval) = token_sym_X; END_PROFILE(name_97) }
    break;

  case 79:
#line 973 "c-grammar.y"
    { START_PROFILE(name_98) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_98) }
    break;

  case 80:
#line 974 "c-grammar.y"
    { START_PROFILE(name_100) (yyval) = Scm_ApplyRec2(name_99, (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)])); END_PROFILE(name_100) }
    break;

  case 81:
#line 978 "c-grammar.y"
    { START_PROFILE(name_101) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_101) }
    break;

  case 82:
#line 979 "c-grammar.y"
    { START_PROFILE(name_103) (yyval) = Scm_ApplyRec2(name_102, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); END_PROFILE(name_103) }
    break;

  case 83:
#line 980 "c-grammar.y"
    { START_PROFILE(name_105) (yyval) = Scm_ApplyRec2(name_104, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); END_PROFILE(name_105) }
    break;

  case 84:
#line 981 "c-grammar.y"
    { START_PROFILE(name_107) (yyval) = Scm_ApplyRec2(name_106, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); END_PROFILE(name_107) }
    break;

  case 85:
#line 985 "c-grammar.y"
    { START_PROFILE(name_108) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_108) }
    break;

  case 86:
#line 986 "c-grammar.y"
    { START_PROFILE(name_110) (yyval) = Scm_ApplyRec2(name_109, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); END_PROFILE(name_110) }
    break;

  case 87:
#line 987 "c-grammar.y"
    { START_PROFILE(name_112) (yyval) = Scm_ApplyRec2(name_111, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); END_PROFILE(name_112) }
    break;

  case 88:
#line 991 "c-grammar.y"
    { START_PROFILE(name_113) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_113) }
    break;

  case 89:
#line 992 "c-grammar.y"
    { START_PROFILE(name_115) (yyval) = Scm_ApplyRec2(name_114, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); END_PROFILE(name_115) }
    break;

  case 90:
#line 993 "c-grammar.y"
    { START_PROFILE(name_117) (yyval) = Scm_ApplyRec2(name_116, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); END_PROFILE(name_117) }
    break;

  case 91:
#line 997 "c-grammar.y"
    { START_PROFILE(name_118) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_118) }
    break;

  case 92:
#line 998 "c-grammar.y"
    { START_PROFILE(name_120) (yyval) = Scm_ApplyRec2(name_119, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); END_PROFILE(name_120) }
    break;

  case 93:
#line 999 "c-grammar.y"
    { START_PROFILE(name_122) (yyval) = Scm_ApplyRec2(name_121, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); END_PROFILE(name_122) }
    break;

  case 94:
#line 1000 "c-grammar.y"
    { START_PROFILE(name_124) (yyval) = Scm_ApplyRec2(name_123, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); END_PROFILE(name_124) }
    break;

  case 95:
#line 1001 "c-grammar.y"
    { START_PROFILE(name_126) (yyval) = Scm_ApplyRec2(name_125, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); END_PROFILE(name_126) }
    break;

  case 96:
#line 1005 "c-grammar.y"
    { START_PROFILE(name_127) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_127) }
    break;

  case 97:
#line 1006 "c-grammar.y"
    { START_PROFILE(name_129) (yyval) = Scm_ApplyRec2(name_128, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); END_PROFILE(name_129) }
    break;

  case 98:
#line 1007 "c-grammar.y"
    { START_PROFILE(name_131) (yyval) = Scm_ApplyRec2(name_130, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); END_PROFILE(name_131) }
    break;

  case 99:
#line 1011 "c-grammar.y"
    { START_PROFILE(name_132) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_132) }
    break;

  case 100:
#line 1012 "c-grammar.y"
    { START_PROFILE(name_134) (yyval) = Scm_ApplyRec2(name_133, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); END_PROFILE(name_134) }
    break;

  case 101:
#line 1016 "c-grammar.y"
    { START_PROFILE(name_135) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_135) }
    break;

  case 102:
#line 1017 "c-grammar.y"
    { START_PROFILE(name_137) (yyval) = Scm_ApplyRec2(name_136, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); END_PROFILE(name_137) }
    break;

  case 103:
#line 1021 "c-grammar.y"
    { START_PROFILE(name_138) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_138) }
    break;

  case 104:
#line 1022 "c-grammar.y"
    { START_PROFILE(name_140) (yyval) = Scm_ApplyRec2(name_139, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); END_PROFILE(name_140) }
    break;

  case 105:
#line 1026 "c-grammar.y"
    { START_PROFILE(name_141) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_141) }
    break;

  case 106:
#line 1027 "c-grammar.y"
    { START_PROFILE(name_143) (yyval) = Scm_ApplyRec2(name_142, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); END_PROFILE(name_143) }
    break;

  case 107:
#line 1031 "c-grammar.y"
    { START_PROFILE(name_144) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_144) }
    break;

  case 108:
#line 1032 "c-grammar.y"
    { START_PROFILE(name_146) (yyval) = Scm_ApplyRec2(name_145, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); END_PROFILE(name_146) }
    break;

  case 109:
#line 1036 "c-grammar.y"
    { START_PROFILE(name_147) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_147) }
    break;

  case 110:
#line 1037 "c-grammar.y"
    { START_PROFILE(name_149) (yyval) = Scm_ApplyRec3(name_148, (yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)])); END_PROFILE(name_149) }
    break;

  case 111:
#line 1041 "c-grammar.y"
    { START_PROFILE(name_150) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_150) }
    break;

  case 112:
#line 1042 "c-grammar.y"
    { START_PROFILE(name_152) (yyval) = Scm_ApplyRec2(name_151, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); END_PROFILE(name_152) }
    break;

  case 113:
#line 1043 "c-grammar.y"
    { START_PROFILE(name_153) (yyval) = Scm_ApplyRec2(name_151, (yyvsp[(1) - (3)]), Scm_ApplyRec2(name_102, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]))); END_PROFILE(name_153) }
    break;

  case 114:
#line 1044 "c-grammar.y"
    { START_PROFILE(name_154) (yyval) = Scm_ApplyRec2(name_151, (yyvsp[(1) - (3)]), Scm_ApplyRec2(name_104, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]))); END_PROFILE(name_154) }
    break;

  case 115:
#line 1045 "c-grammar.y"
    { START_PROFILE(name_155) (yyval) = Scm_ApplyRec2(name_151, (yyvsp[(1) - (3)]), Scm_ApplyRec2(name_106, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]))); END_PROFILE(name_155) }
    break;

  case 116:
#line 1046 "c-grammar.y"
    { START_PROFILE(name_156) (yyval) = Scm_ApplyRec2(name_151, (yyvsp[(1) - (3)]), Scm_ApplyRec2(name_109, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]))); END_PROFILE(name_156) }
    break;

  case 117:
#line 1047 "c-grammar.y"
    { START_PROFILE(name_157) (yyval) = Scm_ApplyRec2(name_151, (yyvsp[(1) - (3)]), Scm_ApplyRec2(name_111, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]))); END_PROFILE(name_157) }
    break;

  case 118:
#line 1048 "c-grammar.y"
    { START_PROFILE(name_158) (yyval) = Scm_ApplyRec2(name_151, (yyvsp[(1) - (3)]), Scm_ApplyRec2(name_114, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]))); END_PROFILE(name_158) }
    break;

  case 119:
#line 1049 "c-grammar.y"
    { START_PROFILE(name_159) (yyval) = Scm_ApplyRec2(name_151, (yyvsp[(1) - (3)]), Scm_ApplyRec2(name_116, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]))); END_PROFILE(name_159) }
    break;

  case 120:
#line 1050 "c-grammar.y"
    { START_PROFILE(name_160) (yyval) = Scm_ApplyRec2(name_151, (yyvsp[(1) - (3)]), Scm_ApplyRec2(name_133, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]))); END_PROFILE(name_160) }
    break;

  case 121:
#line 1051 "c-grammar.y"
    { START_PROFILE(name_161) (yyval) = Scm_ApplyRec2(name_151, (yyvsp[(1) - (3)]), Scm_ApplyRec2(name_136, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]))); END_PROFILE(name_161) }
    break;

  case 122:
#line 1052 "c-grammar.y"
    { START_PROFILE(name_162) (yyval) = Scm_ApplyRec2(name_151, (yyvsp[(1) - (3)]), Scm_ApplyRec2(name_139, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]))); END_PROFILE(name_162) }
    break;

  case 123:
#line 1056 "c-grammar.y"
    { START_PROFILE(name_163) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_163) }
    break;

  case 124:
#line 1057 "c-grammar.y"
    { START_PROFILE(name_165) (yyval) = Scm_ApplyRec2(name_164, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); END_PROFILE(name_165) }
    break;

  case 125:
#line 1061 "c-grammar.y"
    { START_PROFILE(name_166) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_166) }
    break;

  case 126:
#line 1065 "c-grammar.y"
    { START_PROFILE(name_168) (yyval) = Scm_ApplyRec3(name_167, (yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(4) - (5)])); END_PROFILE(name_168) }
    break;

  case 127:
#line 1066 "c-grammar.y"
    { START_PROFILE(name_169) (yyval) = Scm_ApplyRec3(name_167, (yyvsp[(1) - (4)]), SCM_FALSE, (yyvsp[(3) - (4)])); END_PROFILE(name_169) }
    break;

  case 128:
#line 1067 "c-grammar.y"
    { START_PROFILE(name_170) (yyval) = Scm_ApplyRec3(name_167, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), SCM_FALSE); END_PROFILE(name_170) }
    break;

  case 129:
#line 1071 "c-grammar.y"
    { START_PROFILE(name_171) (yyval) = token_sym_STRUCT; END_PROFILE(name_171) }
    break;

  case 130:
#line 1072 "c-grammar.y"
    { START_PROFILE(name_172) (yyval) = token_sym_UNION; END_PROFILE(name_172) }
    break;

  case 131:
#line 1076 "c-grammar.y"
    { START_PROFILE(name_173) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_173) }
    break;

  case 132:
#line 1077 "c-grammar.y"
    { START_PROFILE(name_174) (yyval) = CParser_Append((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); END_PROFILE(name_174) }
    break;

  case 133:
#line 1081 "c-grammar.y"
    { START_PROFILE(name_176) Scm_ApplyRec0(name_175); (yyval) = Scm_MakeTypeDeclList((yyvsp[(1) - (3)]),(yyvsp[(2) - (3)])); END_PROFILE(name_176) }
    break;

  case 134:
#line 1082 "c-grammar.y"
    { START_PROFILE(name_177) Scm_ApplyRec0(name_175); (yyval) = Scm_MakeTypeDeclList((yyvsp[(2) - (4)]),(yyvsp[(3) - (4)])); END_PROFILE(name_177) }
    break;

  case 135:
#line 1083 "c-grammar.y"
    { START_PROFILE(name_180) Scm_ApplyRec0(name_175); (yyval) = Scm_MakeTypeDeclList(CParser_List((yyvsp[(1) - (2)])),SCM_LIST1(Scm_IdentifierDeclarator(Scm_ApplyRec1(name_178, name_179)))); END_PROFILE(name_180) }
    break;

  case 136:
#line 1084 "c-grammar.y"
    { START_PROFILE(name_181) Scm_ApplyRec0(name_175); (yyval) = Scm_MakeTypeDeclList(CParser_List((yyvsp[(2) - (3)])),SCM_LIST1(Scm_IdentifierDeclarator(Scm_ApplyRec1(name_178, name_179)))); END_PROFILE(name_181) }
    break;

  case 137:
#line 1085 "c-grammar.y"
    { START_PROFILE(name_182) (yyval) = name_16; END_PROFILE(name_182) }
    break;

  case 138:
#line 1089 "c-grammar.y"
    { START_PROFILE(name_183) (yyval) = CParser_List(Scm_ComposeVariableAttribute((yyvsp[(1) - (1)]))); END_PROFILE(name_183) }
    break;

  case 139:
#line 1090 "c-grammar.y"
    { START_PROFILE(name_184) (yyval) = CParser_AddList((yyvsp[(1) - (3)]),Scm_ComposeVariableAttribute((yyvsp[(3) - (3)]))); END_PROFILE(name_184) }
    break;

  case 140:
#line 1094 "c-grammar.y"
    { START_PROFILE(name_185) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_185) }
    break;

  case 141:
#line 1095 "c-grammar.y"
    { START_PROFILE(name_186) (yyval) = Scm_BitFieldDeclarator((yyvsp[(2) - (2)])); END_PROFILE(name_186) }
    break;

  case 142:
#line 1096 "c-grammar.y"
    { START_PROFILE(name_187) (yyval) = Scm_ComposeDeclarator(Scm_BitFieldDeclarator((yyvsp[(3) - (3)])),(yyvsp[(1) - (3)])); END_PROFILE(name_187) }
    break;

  case 143:
#line 1100 "c-grammar.y"
    { START_PROFILE(name_189) (yyval) = Scm_ApplyRec2(name_188, SCM_FALSE, (yyvsp[(3) - (4)])); END_PROFILE(name_189) }
    break;

  case 144:
#line 1101 "c-grammar.y"
    { START_PROFILE(name_190) (yyval) = Scm_ApplyRec2(name_188, SCM_FALSE, (yyvsp[(3) - (5)])); END_PROFILE(name_190) }
    break;

  case 145:
#line 1102 "c-grammar.y"
    { START_PROFILE(name_191) (yyval) = Scm_ApplyRec2(name_188, (yyvsp[(2) - (5)]), (yyvsp[(4) - (5)])); END_PROFILE(name_191) }
    break;

  case 146:
#line 1103 "c-grammar.y"
    { START_PROFILE(name_192) (yyval) = Scm_ApplyRec2(name_188, (yyvsp[(2) - (6)]), (yyvsp[(4) - (6)])); END_PROFILE(name_192) }
    break;

  case 147:
#line 1104 "c-grammar.y"
    { START_PROFILE(name_193) (yyval) = Scm_ApplyRec2(name_188, (yyvsp[(2) - (2)]), name_16); END_PROFILE(name_193) }
    break;

  case 148:
#line 1108 "c-grammar.y"
    { START_PROFILE(name_194) (yyval) = CParser_List((yyvsp[(1) - (1)])); END_PROFILE(name_194) }
    break;

  case 149:
#line 1109 "c-grammar.y"
    { START_PROFILE(name_195) (yyval) = CParser_AddList((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); END_PROFILE(name_195) }
    break;

  case 150:
#line 1113 "c-grammar.y"
    { START_PROFILE(name_197) (yyval) = Scm_ApplyRec2(name_196, (yyvsp[(1) - (1)]), SCM_FALSE); END_PROFILE(name_197) }
    break;

  case 151:
#line 1114 "c-grammar.y"
    { START_PROFILE(name_198) (yyval) = Scm_ApplyRec2(name_196, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); END_PROFILE(name_198) }
    break;

  case 152:
#line 1118 "c-grammar.y"
    { START_PROFILE(name_199) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_199) }
    break;

  case 153:
#line 1119 "c-grammar.y"
    { START_PROFILE(name_200) (yyval) = Scm_ComposeDeclarator((yyvsp[(2) - (2)]),(yyvsp[(1) - (2)])); END_PROFILE(name_200) }
    break;

  case 154:
#line 1123 "c-grammar.y"
    { START_PROFILE(name_201) (yyval) = Scm_IdentifierDeclarator((yyvsp[(1) - (1)])); END_PROFILE(name_201) }
    break;

  case 155:
#line 1124 "c-grammar.y"
    { START_PROFILE(name_202) (yyval) = (yyvsp[(2) - (3)]); END_PROFILE(name_202) }
    break;

  case 156:
#line 1125 "c-grammar.y"
    { START_PROFILE(name_203) (yyval) = Scm_ComposeDeclarator(Scm_ArrayDeclarator(SCM_FALSE),(yyvsp[(1) - (3)])); END_PROFILE(name_203) }
    break;

  case 157:
#line 1126 "c-grammar.y"
    { START_PROFILE(name_204) (yyval) = Scm_ComposeDeclarator(Scm_ArrayDeclarator(SCM_FALSE),(yyvsp[(1) - (4)])); END_PROFILE(name_204) }
    break;

  case 158:
#line 1127 "c-grammar.y"
    { START_PROFILE(name_205) (yyval) = Scm_ComposeDeclarator(Scm_ArrayDeclarator((yyvsp[(3) - (4)])),(yyvsp[(1) - (4)])); END_PROFILE(name_205) }
    break;

  case 159:
#line 1128 "c-grammar.y"
    { START_PROFILE(name_206) (yyval) = Scm_ComposeDeclarator(Scm_ArrayDeclarator((yyvsp[(4) - (5)])),(yyvsp[(1) - (5)])); END_PROFILE(name_206) }
    break;

  case 160:
#line 1129 "c-grammar.y"
    { START_PROFILE(name_207) (yyval) = Scm_ComposeDeclarator((yyvsp[(1) - (3)]),Scm_FuncDeclarator(name_16)); END_PROFILE(name_207) }
    break;

  case 161:
#line 1130 "c-grammar.y"
    { START_PROFILE(name_208) (yyval) = Scm_ComposeDeclarator((yyvsp[(1) - (4)]),(yyvsp[(3) - (4)])); END_PROFILE(name_208) }
    break;

  case 162:
#line 1131 "c-grammar.y"
    { START_PROFILE(name_209) (yyval) = (yyvsp[(1) - (4)]); END_PROFILE(name_209) }
    break;

  case 163:
#line 1135 "c-grammar.y"
    { START_PROFILE(name_210) (yyval) = Scm_PtrDeclarator(); END_PROFILE(name_210) }
    break;

  case 164:
#line 1136 "c-grammar.y"
    { START_PROFILE(name_211) (yyval) = Scm_PtrDeclarator(); END_PROFILE(name_211) }
    break;

  case 165:
#line 1137 "c-grammar.y"
    { START_PROFILE(name_212) (yyval) = Scm_ComposeDeclarator(Scm_PtrDeclarator(),(yyvsp[(2) - (2)])); END_PROFILE(name_212) }
    break;

  case 166:
#line 1138 "c-grammar.y"
    { START_PROFILE(name_213) (yyval) = Scm_ComposeDeclarator(Scm_PtrDeclarator(),(yyvsp[(3) - (3)])); END_PROFILE(name_213) }
    break;

  case 167:
#line 1142 "c-grammar.y"
    { START_PROFILE(name_214) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_214) }
    break;

  case 168:
#line 1143 "c-grammar.y"
    { START_PROFILE(name_215) (yyval) = CParser_Append((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); END_PROFILE(name_215) }
    break;

  case 171:
#line 1152 "c-grammar.y"
    { START_PROFILE(name_216) (yyval) = CParser_List((yyvsp[(1) - (1)])); END_PROFILE(name_216) }
    break;

  case 172:
#line 1153 "c-grammar.y"
    { START_PROFILE(name_217) (yyval) = CParser_AddList((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); END_PROFILE(name_217) }
    break;

  case 173:
#line 1157 "c-grammar.y"
    { START_PROFILE(name_218) (yyval) = Scm_FuncDeclarator((yyvsp[(1) - (1)])); END_PROFILE(name_218) }
    break;

  case 174:
#line 1158 "c-grammar.y"
    { START_PROFILE(name_219) (yyval) = Scm_FuncVaargsDeclarator((yyvsp[(1) - (3)])); END_PROFILE(name_219) }
    break;

  case 175:
#line 1162 "c-grammar.y"
    { START_PROFILE(name_220) (yyval) = CParser_List((yyvsp[(1) - (1)])); END_PROFILE(name_220) }
    break;

  case 176:
#line 1163 "c-grammar.y"
    { START_PROFILE(name_221) (yyval) = CParser_AddList((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); END_PROFILE(name_221) }
    break;

  case 177:
#line 1167 "c-grammar.y"
    { START_PROFILE(name_222) (yyval) = Scm_ParameterDeclaration(Scm_MakeTypeDecl((yyvsp[(1) - (2)]),Scm_ComposeVariableAttribute((yyvsp[(2) - (2)])))); END_PROFILE(name_222) }
    break;

  case 178:
#line 1168 "c-grammar.y"
    { START_PROFILE(name_223) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_223) }
    break;

  case 179:
#line 1172 "c-grammar.y"
    { START_PROFILE(name_224) (yyval) = Scm_MakeTypeDecl((yyvsp[(1) - (1)]),Scm_NullDeclarator()); END_PROFILE(name_224) }
    break;

  case 180:
#line 1173 "c-grammar.y"
    { START_PROFILE(name_225) (yyval) = Scm_MakeTypeDecl((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); END_PROFILE(name_225) }
    break;

  case 181:
#line 1177 "c-grammar.y"
    { START_PROFILE(name_226) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_226) }
    break;

  case 182:
#line 1178 "c-grammar.y"
    { START_PROFILE(name_227) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_227) }
    break;

  case 183:
#line 1179 "c-grammar.y"
    { START_PROFILE(name_228) (yyval) = Scm_ComposeDeclarator((yyvsp[(2) - (2)]),(yyvsp[(1) - (2)])); END_PROFILE(name_228) }
    break;

  case 184:
#line 1183 "c-grammar.y"
    { START_PROFILE(name_229) (yyval) = (yyvsp[(2) - (3)]); END_PROFILE(name_229) }
    break;

  case 185:
#line 1184 "c-grammar.y"
    { START_PROFILE(name_230) (yyval) = Scm_PtrDeclarator(); END_PROFILE(name_230) }
    break;

  case 186:
#line 1185 "c-grammar.y"
    { START_PROFILE(name_231) (yyval) = Scm_PtrDeclarator(); END_PROFILE(name_231) }
    break;

  case 187:
#line 1186 "c-grammar.y"
    { START_PROFILE(name_232) (yyval) = Scm_ArrayDeclarator((yyvsp[(2) - (3)])); END_PROFILE(name_232) }
    break;

  case 188:
#line 1187 "c-grammar.y"
    { START_PROFILE(name_233) (yyval) = Scm_ArrayDeclarator((yyvsp[(3) - (4)])); END_PROFILE(name_233) }
    break;

  case 189:
#line 1188 "c-grammar.y"
    { START_PROFILE(name_234) (yyval) = Scm_ComposeDeclarator(Scm_PtrDeclarator(),(yyvsp[(1) - (3)])); END_PROFILE(name_234) }
    break;

  case 190:
#line 1189 "c-grammar.y"
    { START_PROFILE(name_235) (yyval) = Scm_ComposeDeclarator(Scm_PtrDeclarator(),(yyvsp[(1) - (4)])); END_PROFILE(name_235) }
    break;

  case 191:
#line 1190 "c-grammar.y"
    { START_PROFILE(name_236) (yyval) = Scm_ComposeDeclarator(Scm_ArrayDeclarator((yyvsp[(3) - (4)])),(yyvsp[(1) - (4)])); END_PROFILE(name_236) }
    break;

  case 192:
#line 1191 "c-grammar.y"
    { START_PROFILE(name_237) (yyval) = Scm_ComposeDeclarator(Scm_ArrayDeclarator((yyvsp[(4) - (5)])),(yyvsp[(1) - (5)])); END_PROFILE(name_237) }
    break;

  case 193:
#line 1192 "c-grammar.y"
    { START_PROFILE(name_238) (yyval) = Scm_FuncDeclarator(name_16); END_PROFILE(name_238) }
    break;

  case 194:
#line 1193 "c-grammar.y"
    { START_PROFILE(name_239) (yyval) = (yyvsp[(2) - (3)]); END_PROFILE(name_239) }
    break;

  case 195:
#line 1194 "c-grammar.y"
    { START_PROFILE(name_240) (yyval) = Scm_ComposeDeclarator((yyvsp[(1) - (3)]),Scm_FuncDeclarator(name_16)); END_PROFILE(name_240) }
    break;

  case 196:
#line 1195 "c-grammar.y"
    { START_PROFILE(name_241) (yyval) = Scm_ComposeDeclarator((yyvsp[(1) - (4)]),(yyvsp[(3) - (4)])); END_PROFILE(name_241) }
    break;

  case 197:
#line 1199 "c-grammar.y"
    { START_PROFILE(name_242) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_242) }
    break;

  case 198:
#line 1200 "c-grammar.y"
    { START_PROFILE(name_243) (yyval) = SCM_FALSE; END_PROFILE(name_243) }
    break;

  case 199:
#line 1201 "c-grammar.y"
    { START_PROFILE(name_244) (yyval) = SCM_FALSE; END_PROFILE(name_244) }
    break;

  case 202:
#line 1210 "c-grammar.y"
    { START_PROFILE(name_245) (yyval) = SCM_FALSE; END_PROFILE(name_245) }
    break;

  case 203:
#line 1211 "c-grammar.y"
    { START_PROFILE(name_246) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_246) }
    break;

  case 204:
#line 1212 "c-grammar.y"
    { START_PROFILE(name_247) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_247) }
    break;

  case 205:
#line 1213 "c-grammar.y"
    { START_PROFILE(name_248) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_248) }
    break;

  case 206:
#line 1214 "c-grammar.y"
    { START_PROFILE(name_249) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_249) }
    break;

  case 207:
#line 1215 "c-grammar.y"
    { START_PROFILE(name_250) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_250) }
    break;

  case 208:
#line 1216 "c-grammar.y"
    { START_PROFILE(name_251) (yyval) = SCM_FALSE; END_PROFILE(name_251) }
    break;

  case 209:
#line 1217 "c-grammar.y"
    { START_PROFILE(name_252) (yyval) = SCM_FALSE; END_PROFILE(name_252) }
    break;

  case 225:
#line 1260 "c-grammar.y"
    { START_PROFILE(name_254) (yyval) = Scm_ApplyRec1(name_57, name_253); END_PROFILE(name_254) }
    break;

  case 226:
#line 1261 "c-grammar.y"
    { START_PROFILE(name_255) (yyval) = Scm_ApplyRec1(name_57, (yyvsp[(2) - (3)])); END_PROFILE(name_255) }
    break;

  case 227:
#line 1262 "c-grammar.y"
    { START_PROFILE(name_256) (yyval) = Scm_ApplyRec1(name_57, name_253); END_PROFILE(name_256) }
    break;

  case 228:
#line 1263 "c-grammar.y"
    { START_PROFILE(name_258) (yyval) = Scm_ApplyRec2(name_257, (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)])); END_PROFILE(name_258) }
    break;

  case 229:
#line 1264 "c-grammar.y"
    { START_PROFILE(name_259) (yyval) = SCM_FALSE; END_PROFILE(name_259) }
    break;

  case 230:
#line 1268 "c-grammar.y"
    { START_PROFILE(name_260) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_260) }
    break;

  case 231:
#line 1269 "c-grammar.y"
    { START_PROFILE(name_261) (yyval) = CParser_Append((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); END_PROFILE(name_261) }
    break;

  case 232:
#line 1273 "c-grammar.y"
    { START_PROFILE(name_262) (yyval) = CParser_List((yyvsp[(1) - (1)])); END_PROFILE(name_262) }
    break;

  case 233:
#line 1274 "c-grammar.y"
    { START_PROFILE(name_263) (yyval) = CParser_AddList((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); END_PROFILE(name_263) }
    break;

  case 234:
#line 1278 "c-grammar.y"
    { START_PROFILE(name_264) (yyval) = SCM_MAKE_INT(0); END_PROFILE(name_264) }
    break;

  case 235:
#line 1279 "c-grammar.y"
    { START_PROFILE(name_265) (yyval) = (yyvsp[(1) - (2)]); END_PROFILE(name_265) }
    break;

  case 236:
#line 1280 "c-grammar.y"
    { START_PROFILE(name_266) (yyval) = SCM_FALSE; END_PROFILE(name_266) }
    break;

  case 237:
#line 1284 "c-grammar.y"
    { START_PROFILE(name_267) (yyval) = Scm_ApplyRec3(name_148, (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), SCM_MAKE_INT(0)); END_PROFILE(name_267) }
    break;

  case 238:
#line 1285 "c-grammar.y"
    { START_PROFILE(name_268) (yyval) = Scm_ApplyRec3(name_148, (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)])); END_PROFILE(name_268) }
    break;

  case 239:
#line 1286 "c-grammar.y"
    { START_PROFILE(name_269) (yyval) = SCM_FALSE; END_PROFILE(name_269) }
    break;

  case 240:
#line 1290 "c-grammar.y"
    { START_PROFILE(name_271) (yyval) = Scm_ApplyRec2(name_270, (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)])); END_PROFILE(name_271) }
    break;

  case 241:
#line 1291 "c-grammar.y"
    { START_PROFILE(name_273) (yyval) = Scm_ApplyRec2(name_272, (yyvsp[(5) - (7)]), (yyvsp[(2) - (7)])); END_PROFILE(name_273) }
    break;

  case 242:
#line 1292 "c-grammar.y"
    { START_PROFILE(name_275) (yyval) = Scm_ApplyRec4(name_274, SCM_MAKE_INT(0), SCM_MAKE_INT(1), SCM_MAKE_INT(0), (yyvsp[(6) - (6)])); END_PROFILE(name_275) }
    break;

  case 243:
#line 1293 "c-grammar.y"
    { START_PROFILE(name_276) (yyval) = Scm_ApplyRec4(name_274, SCM_MAKE_INT(0), SCM_MAKE_INT(1), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)])); END_PROFILE(name_276) }
    break;

  case 244:
#line 1294 "c-grammar.y"
    { START_PROFILE(name_277) (yyval) = Scm_ApplyRec4(name_274, SCM_MAKE_INT(0), (yyvsp[(4) - (7)]), SCM_MAKE_INT(0), (yyvsp[(7) - (7)])); END_PROFILE(name_277) }
    break;

  case 245:
#line 1295 "c-grammar.y"
    { START_PROFILE(name_278) (yyval) = Scm_ApplyRec4(name_274, SCM_MAKE_INT(0), (yyvsp[(4) - (8)]), (yyvsp[(6) - (8)]), (yyvsp[(8) - (8)])); END_PROFILE(name_278) }
    break;

  case 246:
#line 1296 "c-grammar.y"
    { START_PROFILE(name_279) (yyval) = Scm_ApplyRec4(name_274, (yyvsp[(3) - (7)]), SCM_MAKE_INT(1), SCM_MAKE_INT(0), (yyvsp[(7) - (7)])); END_PROFILE(name_279) }
    break;

  case 247:
#line 1297 "c-grammar.y"
    { START_PROFILE(name_280) (yyval) = Scm_ApplyRec4(name_274, (yyvsp[(3) - (8)]), SCM_MAKE_INT(1), (yyvsp[(6) - (8)]), (yyvsp[(8) - (8)])); END_PROFILE(name_280) }
    break;

  case 248:
#line 1298 "c-grammar.y"
    { START_PROFILE(name_281) (yyval) = Scm_ApplyRec4(name_274, (yyvsp[(3) - (8)]), (yyvsp[(5) - (8)]), SCM_MAKE_INT(0), (yyvsp[(8) - (8)])); END_PROFILE(name_281) }
    break;

  case 249:
#line 1299 "c-grammar.y"
    { START_PROFILE(name_282) (yyval) = Scm_ApplyRec4(name_274, (yyvsp[(3) - (9)]), (yyvsp[(5) - (9)]), (yyvsp[(7) - (9)]), (yyvsp[(9) - (9)])); END_PROFILE(name_282) }
    break;

  case 250:
#line 1303 "c-grammar.y"
    { START_PROFILE(name_283) (yyval) = SCM_FALSE; END_PROFILE(name_283) }
    break;

  case 251:
#line 1304 "c-grammar.y"
    { START_PROFILE(name_285) (yyval) = Scm_ApplyRec0(name_284); END_PROFILE(name_285) }
    break;

  case 252:
#line 1305 "c-grammar.y"
    { START_PROFILE(name_287) (yyval) = Scm_ApplyRec0(name_286); END_PROFILE(name_287) }
    break;

  case 253:
#line 1306 "c-grammar.y"
    { START_PROFILE(name_289) (yyval) = Scm_ApplyRec1(name_288, SCM_MAKE_INT(0)); END_PROFILE(name_289) }
    break;

  case 254:
#line 1307 "c-grammar.y"
    { START_PROFILE(name_290) (yyval) = Scm_ApplyRec1(name_288, (yyvsp[(2) - (3)])); END_PROFILE(name_290) }
    break;

  case 255:
#line 1311 "c-grammar.y"
    { START_PROFILE(name_291) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_291) }
    break;

  case 270:
#line 1347 "c-grammar.y"
    { START_PROFILE(name_292) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_292) }
    break;

  case 271:
#line 1348 "c-grammar.y"
    { START_PROFILE(name_293) (yyval) = SCM_FALSE; END_PROFILE(name_293) }
    break;

  case 295:
#line 1405 "c-grammar.y"
    { START_PROFILE(name_294) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_294) }
    break;

  case 296:
#line 1406 "c-grammar.y"
    { START_PROFILE(name_295) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_295) }
    break;

  case 297:
#line 1410 "c-grammar.y"
    { START_PROFILE(name_296) (yyval) = CParser_List((yyvsp[(1) - (1)])); END_PROFILE(name_296) }
    break;

  case 298:
#line 1411 "c-grammar.y"
    { START_PROFILE(name_297) (yyval) = CParser_AddList((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); END_PROFILE(name_297) }
    break;

  case 299:
#line 1415 "c-grammar.y"
    { START_PROFILE(name_298) (yyval) = Scm_EmitDefineObjcClass((yyvsp[(2) - (3)])); END_PROFILE(name_298) }
    break;

  case 300:
#line 1419 "c-grammar.y"
    { START_PROFILE(name_299) (yyval) = SCM_FALSE; END_PROFILE(name_299) }
    break;

  case 309:
#line 1440 "c-grammar.y"
    { START_PROFILE(name_300) (yyval) = Scm_EmitDefineObjcClass(CParser_List((yyvsp[(2) - (2)]))); END_PROFILE(name_300) }
    break;

  case 340:
#line 1510 "c-grammar.y"
    { START_PROFILE(name_303) Scm_ApplyRec0(name_175); (yyval) = Scm_ApplyRec2(name_301, name_302, (yyvsp[(2) - (3)])); END_PROFILE(name_303) }
    break;

  case 350:
#line 1532 "c-grammar.y"
    { START_PROFILE(name_305) (yyval) = Scm_ApplyRec2(name_304, (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)])); END_PROFILE(name_305) }
    break;

  case 351:
#line 1533 "c-grammar.y"
    { START_PROFILE(name_307) (yyval) = Scm_ApplyRec2(name_304, Scm_ApplyRec0(name_306), (yyvsp[(1) - (1)])); END_PROFILE(name_307) }
    break;

  case 352:
#line 1534 "c-grammar.y"
    { START_PROFILE(name_308) (yyval) = Scm_ApplyRec2(name_304, (yyvsp[(3) - (6)]), (yyvsp[(5) - (6)])); END_PROFILE(name_308) }
    break;

  case 353:
#line 1535 "c-grammar.y"
    { START_PROFILE(name_309) (yyval) = Scm_ApplyRec2(name_304, Scm_ApplyRec0(name_306), (yyvsp[(1) - (2)])); END_PROFILE(name_309) }
    break;

  case 358:
#line 1549 "c-grammar.y"
    { START_PROFILE(name_310) (yyval) = SCM_FALSE; END_PROFILE(name_310) }
    break;

  case 368:
#line 1571 "c-grammar.y"
    { START_PROFILE(name_312) (yyval) = Scm_ApplyRec1(name_311, (yyvsp[(1) - (1)])); END_PROFILE(name_312) }
    break;

  case 369:
#line 1575 "c-grammar.y"
    { START_PROFILE(name_314) (yyval) = Scm_ApplyRec1(name_313, (yyvsp[(1) - (1)])); END_PROFILE(name_314) }
    break;

  case 370:
#line 1576 "c-grammar.y"
    { START_PROFILE(name_315) (yyval) = Scm_ApplyRec2(name_313, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); END_PROFILE(name_315) }
    break;

  case 371:
#line 1580 "c-grammar.y"
    { START_PROFILE(name_316) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_316) }
    break;

  case 372:
#line 1581 "c-grammar.y"
    { START_PROFILE(name_317) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_317) }
    break;

  case 373:
#line 1582 "c-grammar.y"
    { START_PROFILE(name_318) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_318) }
    break;

  case 391:
#line 1606 "c-grammar.y"
    { START_PROFILE(name_319) Scm_ApplyRec0(name_175); (yyval) = Scm_ApplyRec2(name_311, (yyvsp[(1) - (7)]), (yyvsp[(5) - (7)])); END_PROFILE(name_319) }
    break;

  case 392:
#line 1607 "c-grammar.y"
    { START_PROFILE(name_320) Scm_ApplyRec0(name_175); (yyval) = Scm_ApplyRec2(name_311, (yyvsp[(1) - (3)]), Scm_ApplyRec0(name_306)); END_PROFILE(name_320) }
    break;

  case 393:
#line 1608 "c-grammar.y"
    { START_PROFILE(name_322) Scm_ApplyRec0(name_175); (yyval) = Scm_ApplyRec2(name_311, name_321, (yyvsp[(4) - (6)])); END_PROFILE(name_322) }
    break;

  case 394:
#line 1609 "c-grammar.y"
    { START_PROFILE(name_323) Scm_ApplyRec0(name_175); (yyval) = Scm_ApplyRec2(name_311, name_321, Scm_ApplyRec0(name_306)); END_PROFILE(name_323) }
    break;

  case 395:
#line 1613 "c-grammar.y"
    { START_PROFILE(name_325) (yyval) = Scm_ApplyRec1(name_324, (yyvsp[(1) - (1)])); END_PROFILE(name_325) }
    break;

  case 396:
#line 1614 "c-grammar.y"
    { START_PROFILE(name_326) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_326) }
    break;

  case 397:
#line 1618 "c-grammar.y"
    { START_PROFILE(name_327) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_327) }
    break;

  case 398:
#line 1619 "c-grammar.y"
    { START_PROFILE(name_328) (yyval) = CParser_Append((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); END_PROFILE(name_328) }
    break;

  case 399:
#line 1623 "c-grammar.y"
    { START_PROFILE(name_330) (yyval) = Scm_ApplyRec2(name_329, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); END_PROFILE(name_330) }
    break;

  case 400:
#line 1624 "c-grammar.y"
    { START_PROFILE(name_332) (yyval) = Scm_ApplyRec1(name_331, (yyvsp[(2) - (2)])); END_PROFILE(name_332) }
    break;

  case 401:
#line 1628 "c-grammar.y"
    { START_PROFILE(name_333) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_333) }
    break;

  case 402:
#line 1629 "c-grammar.y"
    { START_PROFILE(name_334) (yyval) = (yyvsp[(1) - (1)]); END_PROFILE(name_334) }
    break;

  case 403:
#line 1633 "c-grammar.y"
    { START_PROFILE(name_336) (yyval) = Scm_ApplyRec2(name_335, (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)])); END_PROFILE(name_336) }
    break;

  case 404:
#line 1637 "c-grammar.y"
    { START_PROFILE(name_338) (yyval) = Scm_ApplyRec1(name_337, (yyvsp[(1) - (1)])); END_PROFILE(name_338) }
    break;

  case 405:
#line 1638 "c-grammar.y"
    { START_PROFILE(name_342) (yyval) = Scm_ApplyRec2(name_339, Scm_ApplyRec2(name_340, name_337, (yyvsp[(1) - (1)])), name_341); END_PROFILE(name_342) }
    break;

  case 406:
#line 1642 "c-grammar.y"
    { START_PROFILE(name_343) (yyval) = CParser_List((yyvsp[(1) - (1)])); END_PROFILE(name_343) }
    break;

  case 407:
#line 1643 "c-grammar.y"
    { START_PROFILE(name_344) (yyval) = CParser_AddList((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); END_PROFILE(name_344) }
    break;

  case 408:
#line 1647 "c-grammar.y"
    { START_PROFILE(name_345) (yyval) = (yyvsp[(1) - (2)]); END_PROFILE(name_345) }
    break;

  case 409:
#line 1648 "c-grammar.y"
    { START_PROFILE(name_347) (yyval) = name_346; END_PROFILE(name_347) }
    break;

  case 410:
#line 1652 "c-grammar.y"
    { START_PROFILE(name_349) (yyval) = Scm_ApplyRec1(name_348, (yyvsp[(3) - (4)])); END_PROFILE(name_349) }
    break;


/* Line 1267 of yacc.c.  */
#line 4854 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1663 "c-grammar.y"

#ifdef USE_PROFILER
static void show_profile_result()
{
    fprintf(stderr, "---\n");
    fprintf(stderr, "%s\t%lld\t%lld\n", "'()", _profile_name_39_count, _profile_name_39_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(yylex)", _profile_yylex_count, _profile_yylex_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_250_count, _profile_name_250_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_251_count, _profile_name_251_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_252_count, _profile_name_252_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%NE $1 $3)", _profile_name_131_count, _profile_name_131_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_132_count, _profile_name_132_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOUND-STATEMENT '(0))", _profile_name_254_count, _profile_name_254_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOUND-STATEMENT $2)", _profile_name_255_count, _profile_name_255_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%BIT-AND $1 $3)", _profile_name_134_count, _profile_name_134_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOUND-STATEMENT '(0))", _profile_name_256_count, _profile_name_256_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_135_count, _profile_name_135_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOUND-STATEMENT-WITH-DECLARATION $2 $3)", _profile_name_258_count, _profile_name_258_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%BIT-XOR $1 $3)", _profile_name_137_count, _profile_name_137_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_259_count, _profile_name_259_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_138_count, _profile_name_138_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'()", _profile_name_40_count, _profile_name_40_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%STRUCT-OR-UNION-SPECIFIER $1)", _profile_name_42_count, _profile_name_42_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ENUM-SPECIFIER $1)", _profile_name_44_count, _profile_name_44_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'()", _profile_name_45_count, _profile_name_45_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%TYPENAME $1)", _profile_name_46_count, _profile_name_46_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'(id)", _profile_name_48_count, _profile_name_48_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_260_count, _profile_name_260_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%APPEND $1 $2)", _profile_name_261_count, _profile_name_261_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%BIT-OR $1 $3)", _profile_name_140_count, _profile_name_140_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LIST $1)", _profile_name_262_count, _profile_name_262_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_141_count, _profile_name_141_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ADD-LIST $1 $2)", _profile_name_263_count, _profile_name_263_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "0", _profile_name_264_count, _profile_name_264_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LOG-AND $1 $3)", _profile_name_143_count, _profile_name_143_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_265_count, _profile_name_265_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_144_count, _profile_name_144_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_266_count, _profile_name_266_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(emit-define-objc-class (%LIST $2))", _profile_name_300_count, _profile_name_300_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%IF $3 $5 0)", _profile_name_267_count, _profile_name_267_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LOG-OR $1 $3)", _profile_name_146_count, _profile_name_146_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%IF $3 $5 $7)", _profile_name_268_count, _profile_name_268_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_147_count, _profile_name_147_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_269_count, _profile_name_269_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(begin (parser-attribute-clear!) (apply emit-objc-method $2))", _profile_name_303_count, _profile_name_303_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%IF $1 $3 $5)", _profile_name_149_count, _profile_name_149_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-objc-method $3 $5)", _profile_name_305_count, _profile_name_305_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-objc-method (var-id) $1)", _profile_name_307_count, _profile_name_307_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-objc-method $3 $5)", _profile_name_308_count, _profile_name_308_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-objc-method (var-id) $1)", _profile_name_309_count, _profile_name_309_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%IDENTIFIER $1)", _profile_name_50_count, _profile_name_50_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_51_count, _profile_name_51_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_52_count, _profile_name_52_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%OBJC-STRING $1)", _profile_name_54_count, _profile_name_54_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%EXPR-IN-PARENS $2)", _profile_name_56_count, _profile_name_56_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOUND-STATEMENT $2)", _profile_name_58_count, _profile_name_58_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_59_count, _profile_name_59_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%MACRO-BODY $2)", _profile_name_2_count, _profile_name_2_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(all-referenced-info-clear!)", _profile_name_3_count, _profile_name_3_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(all-referenced-info-clear!)", _profile_name_4_count, _profile_name_4_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(all-referenced-info-clear!)", _profile_name_5_count, _profile_name_5_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(all-referenced-info-clear!)", _profile_name_6_count, _profile_name_6_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(all-referenced-info-clear!)", _profile_name_7_count, _profile_name_7_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%WHILE $3 $5)", _profile_name_271_count, _profile_name_271_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_150_count, _profile_name_150_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(emit-define-inline '(int) $1 $2)", _profile_name_9_count, _profile_name_9_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%DO-WHILE $5 $2)", _profile_name_273_count, _profile_name_273_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ASSIGN $1 $3)", _profile_name_152_count, _profile_name_152_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ASSIGN $1 (%MUL $1 $3))", _profile_name_153_count, _profile_name_153_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%FOR 0 1 0 $6)", _profile_name_275_count, _profile_name_275_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ASSIGN $1 (%DIV $1 $3))", _profile_name_154_count, _profile_name_154_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%FOR 0 1 $5 $7)", _profile_name_276_count, _profile_name_276_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ASSIGN $1 (%MOD $1 $3))", _profile_name_155_count, _profile_name_155_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_310_count, _profile_name_310_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%FOR 0 $4 0 $7)", _profile_name_277_count, _profile_name_277_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ASSIGN $1 (%ADD $1 $3))", _profile_name_156_count, _profile_name_156_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%FOR 0 $4 $6 $8)", _profile_name_278_count, _profile_name_278_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ASSIGN $1 (%SUB $1 $3))", _profile_name_157_count, _profile_name_157_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-keyword $1)", _profile_name_312_count, _profile_name_312_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%FOR $3 1 0 $7)", _profile_name_279_count, _profile_name_279_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ASSIGN $1 (%SHIFT-LEFT $1 $3))", _profile_name_158_count, _profile_name_158_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ASSIGN $1 (%SHIFT-RIGHT $1 $3))", _profile_name_159_count, _profile_name_159_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(combine-decl-keyword $1)", _profile_name_314_count, _profile_name_314_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(combine-decl-keyword $1 $2)", _profile_name_315_count, _profile_name_315_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_316_count, _profile_name_316_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_317_count, _profile_name_317_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_318_count, _profile_name_318_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(begin (parser-attribute-clear!) (decl-keyword $1 $5))", _profile_name_319_count, _profile_name_319_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_60_count, _profile_name_60_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_61_count, _profile_name_61_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_62_count, _profile_name_62_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_63_count, _profile_name_63_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_64_count, _profile_name_64_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%REF-ARRAY $1 $3)", _profile_name_66_count, _profile_name_66_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%FUNCALL $1 '())", _profile_name_68_count, _profile_name_68_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%FUNCALL $1 $3)", _profile_name_69_count, _profile_name_69_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%FOR $3 1 $6 $8)", _profile_name_280_count, _profile_name_280_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%FOR $3 $5 0 $8)", _profile_name_281_count, _profile_name_281_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ASSIGN $1 (%BIT-AND $1 $3))", _profile_name_160_count, _profile_name_160_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%FOR $3 $5 $7 $9)", _profile_name_282_count, _profile_name_282_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ASSIGN $1 (%BIT-XOR $1 $3))", _profile_name_161_count, _profile_name_161_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_283_count, _profile_name_283_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ASSIGN $1 (%BIT-OR $1 $3))", _profile_name_162_count, _profile_name_162_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_163_count, _profile_name_163_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%CONTINUE)", _profile_name_285_count, _profile_name_285_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%CONCAT-EXPR $1 $3)", _profile_name_165_count, _profile_name_165_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(begin (parser-attribute-clear!) (decl-keyword $1 (var-id)))", _profile_name_320_count, _profile_name_320_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%BREAK)", _profile_name_287_count, _profile_name_287_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_166_count, _profile_name_166_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR $2 $1)", _profile_name_200_count, _profile_name_200_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(begin (parser-attribute-clear!) (decl-keyword  $4))", _profile_name_322_count, _profile_name_322_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%RETURN 0)", _profile_name_289_count, _profile_name_289_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-struct-or-union $1 $2 $4)", _profile_name_168_count, _profile_name_168_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(identifier-declarator $1)", _profile_name_201_count, _profile_name_201_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(begin (parser-attribute-clear!) (decl-keyword  (var-id)))", _profile_name_323_count, _profile_name_323_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-struct-or-union $1 #f $3)", _profile_name_169_count, _profile_name_169_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$2", _profile_name_202_count, _profile_name_202_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR (array-declarator #f) $1)", _profile_name_203_count, _profile_name_203_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%QUOTE $1)", _profile_name_325_count, _profile_name_325_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR (array-declarator #f) $1)", _profile_name_204_count, _profile_name_204_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_326_count, _profile_name_326_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR (array-declarator $3) $1)", _profile_name_205_count, _profile_name_205_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_327_count, _profile_name_327_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR (array-declarator $4) $1)", _profile_name_206_count, _profile_name_206_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%APPEND $1 $2)", _profile_name_328_count, _profile_name_328_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR $1 (func-declarator '()))", _profile_name_207_count, _profile_name_207_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR $1 $3)", _profile_name_208_count, _profile_name_208_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%DOT-REF $1 $3)", _profile_name_71_count, _profile_name_71_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_209_count, _profile_name_209_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%PTR-REF $1 $3)", _profile_name_73_count, _profile_name_73_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%POST-INC $1)", _profile_name_75_count, _profile_name_75_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%POST-DEC $1)", _profile_name_77_count, _profile_name_77_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LIST $1)", _profile_name_78_count, _profile_name_78_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ADD-LIST $1 $3)", _profile_name_79_count, _profile_name_79_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%RETURN $2)", _profile_name_290_count, _profile_name_290_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_291_count, _profile_name_291_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-struct-or-union $1 $2 #f)", _profile_name_170_count, _profile_name_170_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_292_count, _profile_name_292_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'STRUCT", _profile_name_171_count, _profile_name_171_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_293_count, _profile_name_293_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'UNION", _profile_name_172_count, _profile_name_172_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_294_count, _profile_name_294_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_173_count, _profile_name_173_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_295_count, _profile_name_295_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%APPEND $1 $2)", _profile_name_174_count, _profile_name_174_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(c_scan)", _profile_c_scan_count, _profile_c_scan_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LIST $1)", _profile_name_296_count, _profile_name_296_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%KEYWORD-ARG $1 $3)", _profile_name_330_count, _profile_name_330_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ADD-LIST $1 $3)", _profile_name_297_count, _profile_name_297_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(begin (parser-attribute-clear!) (make-type-decl-list $1 $2))", _profile_name_176_count, _profile_name_176_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(emit-define-objc-class $2)", _profile_name_298_count, _profile_name_298_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(begin (parser-attribute-clear!) (make-type-decl-list $2 $3))", _profile_name_177_count, _profile_name_177_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(ptr-declarator)", _profile_name_210_count, _profile_name_210_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%KEYWORD-ARG-WITHOUT-SELECTOR $2)", _profile_name_332_count, _profile_name_332_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_299_count, _profile_name_299_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(ptr-declarator)", _profile_name_211_count, _profile_name_211_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_333_count, _profile_name_333_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR (ptr-declarator) $2)", _profile_name_212_count, _profile_name_212_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_334_count, _profile_name_334_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR (ptr-declarator) $3)", _profile_name_213_count, _profile_name_213_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_214_count, _profile_name_214_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%OBJC-MESSAGE-EXPR $2 $3)", _profile_name_336_count, _profile_name_336_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%APPEND $1 $2)", _profile_name_215_count, _profile_name_215_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LIST $1)", _profile_name_216_count, _profile_name_216_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(x->string $1)", _profile_name_338_count, _profile_name_338_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ADD-LIST $1 $3)", _profile_name_217_count, _profile_name_217_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_80_count, _profile_name_80_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(func-declarator $1)", _profile_name_218_count, _profile_name_218_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(func-vaargs-declarator $1)", _profile_name_219_count, _profile_name_219_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%PRE-INC $2)", _profile_name_82_count, _profile_name_82_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%PRE-DEC $2)", _profile_name_84_count, _profile_name_84_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%UNARY $1 $2)", _profile_name_86_count, _profile_name_86_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%SIZEOF-EXPR $2)", _profile_name_88_count, _profile_name_88_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(begin (parser-attribute-clear!) (make-type-decl-list (%LIST $1) (list (identifier-declarator (gensym %unnamed)))))", _profile_name_180_count, _profile_name_180_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(begin (parser-attribute-clear!) (make-type-decl-list (%LIST $2) (list (identifier-declarator (gensym %unnamed)))))", _profile_name_181_count, _profile_name_181_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'()", _profile_name_182_count, _profile_name_182_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LIST (compose-variable-attribute $1))", _profile_name_183_count, _profile_name_183_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ADD-LIST $1 (compose-variable-attribute $3))", _profile_name_184_count, _profile_name_184_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_185_count, _profile_name_185_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(bit-field-declarator $2)", _profile_name_186_count, _profile_name_186_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR (bit-field-declarator $3) $1)", _profile_name_187_count, _profile_name_187_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LIST $1)", _profile_name_220_count, _profile_name_220_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(string-join (map x->string $1) :)", _profile_name_342_count, _profile_name_342_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%CAST $2 $4)", _profile_name_100_count, _profile_name_100_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ADD-LIST $1 $3)", _profile_name_221_count, _profile_name_221_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LIST $1)", _profile_name_343_count, _profile_name_343_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_101_count, _profile_name_101_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-enum #f $3)", _profile_name_189_count, _profile_name_189_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(parameter-declaration (make-type-decl $1 (compose-variable-attribute $2)))", _profile_name_222_count, _profile_name_222_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ADD-LIST $1 $2)", _profile_name_344_count, _profile_name_344_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_223_count, _profile_name_223_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_345_count, _profile_name_345_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%MUL $1 $3)", _profile_name_103_count, _profile_name_103_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(make-type-decl $1 (null-declarator))", _profile_name_224_count, _profile_name_224_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(make-type-decl $1 $2)", _profile_name_225_count, _profile_name_225_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "", _profile_name_347_count, _profile_name_347_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%DIV $1 $3)", _profile_name_105_count, _profile_name_105_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_226_count, _profile_name_226_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_227_count, _profile_name_227_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%SELECTOR $3)", _profile_name_349_count, _profile_name_349_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%SIZEOF-TYPE $3)", _profile_name_90_count, _profile_name_90_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%MOD $1 $3)", _profile_name_107_count, _profile_name_107_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR $2 $1)", _profile_name_228_count, _profile_name_228_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$2", _profile_name_91_count, _profile_name_91_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_108_count, _profile_name_108_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$2", _profile_name_229_count, _profile_name_229_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'&", _profile_name_92_count, _profile_name_92_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'*", _profile_name_93_count, _profile_name_93_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'+", _profile_name_94_count, _profile_name_94_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'-", _profile_name_95_count, _profile_name_95_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'~", _profile_name_96_count, _profile_name_96_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'!", _profile_name_97_count, _profile_name_97_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(emit-define-inline $1 $2 $3)", _profile_name_10_count, _profile_name_10_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_98_count, _profile_name_98_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%FUNCTION-BODY $1)", _profile_name_12_count, _profile_name_12_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_13_count, _profile_name_13_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(external-declaration $1 (list (null-declarator)))", _profile_name_14_count, _profile_name_14_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(external-declaration $1 $2)", _profile_name_15_count, _profile_name_15_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(declaration $1 '())", _profile_name_17_count, _profile_name_17_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(declaration $1 $2)", _profile_name_18_count, _profile_name_18_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-enum #f $3)", _profile_name_190_count, _profile_name_190_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$2", _profile_name_19_count, _profile_name_19_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-enum $2 $4)", _profile_name_191_count, _profile_name_191_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-enum $2 $4)", _profile_name_192_count, _profile_name_192_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-enum $2 '())", _profile_name_193_count, _profile_name_193_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LIST $1)", _profile_name_194_count, _profile_name_194_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ADD-LIST $1 $3)", _profile_name_195_count, _profile_name_195_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-enumerator $1 #f)", _profile_name_197_count, _profile_name_197_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(ptr-declarator)", _profile_name_230_count, _profile_name_230_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ADD $1 $3)", _profile_name_110_count, _profile_name_110_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-enumerator $1 $3)", _profile_name_198_count, _profile_name_198_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(ptr-declarator)", _profile_name_231_count, _profile_name_231_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_199_count, _profile_name_199_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(array-declarator $2)", _profile_name_232_count, _profile_name_232_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%SUB $1 $3)", _profile_name_112_count, _profile_name_112_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(array-declarator $3)", _profile_name_233_count, _profile_name_233_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_113_count, _profile_name_113_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR (ptr-declarator) $1)", _profile_name_234_count, _profile_name_234_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR (ptr-declarator) $1)", _profile_name_235_count, _profile_name_235_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%SHIFT-LEFT $1 $3)", _profile_name_115_count, _profile_name_115_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR (array-declarator $3) $1)", _profile_name_236_count, _profile_name_236_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR (array-declarator $4) $1)", _profile_name_237_count, _profile_name_237_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%SHIFT-RIGHT $1 $3)", _profile_name_117_count, _profile_name_117_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(func-declarator '())", _profile_name_238_count, _profile_name_238_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_118_count, _profile_name_118_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$2", _profile_name_239_count, _profile_name_239_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%APPEND $1 $2)", _profile_name_20_count, _profile_name_20_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_21_count, _profile_name_21_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%APPEND $1 $2)", _profile_name_22_count, _profile_name_22_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LIST (compose-variable-attribute $1))", _profile_name_23_count, _profile_name_23_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ADD-LIST $1 (compose-variable-attribute $3))", _profile_name_24_count, _profile_name_24_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR $1 (init-value-declarator $4))", _profile_name_25_count, _profile_name_25_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_26_count, _profile_name_26_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'(TYPEDEF)", _profile_name_28_count, _profile_name_28_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'()", _profile_name_29_count, _profile_name_29_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR $1 (func-declarator '()))", _profile_name_240_count, _profile_name_240_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LT $1 $3)", _profile_name_120_count, _profile_name_120_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR $1 $3)", _profile_name_241_count, _profile_name_241_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_242_count, _profile_name_242_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%GT $1 $3)", _profile_name_122_count, _profile_name_122_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_243_count, _profile_name_243_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_244_count, _profile_name_244_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_245_count, _profile_name_245_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LE $1 $3)", _profile_name_124_count, _profile_name_124_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_246_count, _profile_name_246_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_247_count, _profile_name_247_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%GE $1 $3)", _profile_name_126_count, _profile_name_126_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_248_count, _profile_name_248_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_127_count, _profile_name_127_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_249_count, _profile_name_249_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%EQ $1 $3)", _profile_name_129_count, _profile_name_129_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'()", _profile_name_30_count, _profile_name_30_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'()", _profile_name_31_count, _profile_name_31_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'()", _profile_name_32_count, _profile_name_32_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%TYPENAME $1)", _profile_name_33_count, _profile_name_33_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'(SIGNED)", _profile_name_35_count, _profile_name_35_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'(UNSIGNED)", _profile_name_37_count, _profile_name_37_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'()", _profile_name_38_count, _profile_name_38_time);
}
#endif
void init_parser()
{
    if (!SCM_UNBOUNDP(token_table)) {
        /* already initialized */
        return;
    }
    name_348 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%SELECTOR");
    name_346 = SCM_MAKE_KEYWORD("");
    name_341 = SCM_MAKE_STR_IMMUTABLE(":");
    name_340 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "map");
    name_339 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "string-join");
    name_337 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "x->string");
    name_335 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%OBJC-MESSAGE-EXPR");
    name_331 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%KEYWORD-ARG-WITHOUT-SELECTOR");
    name_329 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%KEYWORD-ARG");
    name_324 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%QUOTE");
    name_321 = SCM_MAKE_STR_IMMUTABLE("");
    name_313 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "combine-decl-keyword");
    name_311 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "decl-keyword");
    name_306 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "var-id");
    name_304 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "decl-objc-method");
    name_302 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "emit-objc-method");
    name_301 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "apply");
    name_288 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%RETURN");
    name_286 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%BREAK");
    name_284 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%CONTINUE");
    name_274 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%FOR");
    name_272 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%DO-WHILE");
    name_270 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%WHILE");
    name_257 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%COMPOUND-STATEMENT-WITH-DECLARATION");
    name_253 = SCM_LIST1(SCM_MAKE_INT(0));
    name_196 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "decl-enumerator");
    name_188 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "decl-enum");
    name_179 = SCM_MAKE_STR_IMMUTABLE("%unnamed");
    name_178 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "gensym");
    name_175 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "parser-attribute-clear!");
    name_167 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "decl-struct-or-union");
    name_164 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%CONCAT-EXPR");
    name_151 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%ASSIGN");
    name_148 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%IF");
    name_145 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%LOG-OR");
    name_142 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%LOG-AND");
    name_139 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%BIT-OR");
    name_136 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%BIT-XOR");
    name_133 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%BIT-AND");
    name_130 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%NE");
    name_128 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%EQ");
    name_125 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%GE");
    name_123 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%LE");
    name_121 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%GT");
    name_119 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%LT");
    name_116 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%SHIFT-RIGHT");
    name_114 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%SHIFT-LEFT");
    name_111 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%SUB");
    name_109 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%ADD");
    name_106 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%MOD");
    name_104 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%DIV");
    name_102 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%MUL");
    name_99 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%CAST");
    name_89 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%SIZEOF-TYPE");
    name_87 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%SIZEOF-EXPR");
    name_85 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%UNARY");
    name_83 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%PRE-DEC");
    name_81 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%PRE-INC");
    name_76 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%POST-DEC");
    name_74 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%POST-INC");
    name_72 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%PTR-REF");
    name_70 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%DOT-REF");
    name_67 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%FUNCALL");
    name_65 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%REF-ARRAY");
    name_57 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%COMPOUND-STATEMENT");
    name_55 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%EXPR-IN-PARENS");
    name_53 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%OBJC-STRING");
    name_49 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%IDENTIFIER");
    name_47 = SCM_LIST1(SCM_INTERN("id"));
    name_43 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%ENUM-SPECIFIER");
    name_41 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%STRUCT-OR-UNION-SPECIFIER");
    name_36 = SCM_LIST1(SCM_INTERN("UNSIGNED"));
    name_34 = SCM_LIST1(SCM_INTERN("SIGNED"));
    name_27 = SCM_LIST1(SCM_INTERN("TYPEDEF"));
    name_16 = SCM_NIL;
    name_11 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%FUNCTION-BODY");
    name_8 = SCM_LIST1(SCM_INTERN("int"));
    name_1 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%MACRO-BODY");
    token_sym_START_MACRO = SCM_INTERN("START_MACRO");
    token_sym_OBJC_STRING = SCM_INTERN("OBJC_STRING");
    token_sym_AT_REQUIRED = SCM_INTERN("AT_REQUIRED");
    token_sym_AT_OPTIONAL = SCM_INTERN("AT_OPTIONAL");
    token_sym_AT_DYNAMIC = SCM_INTERN("AT_DYNAMIC");
    token_sym_AT_SYNTHESIZE = SCM_INTERN("AT_SYNTHESIZE");
    token_sym_AT_PROPERTY = SCM_INTERN("AT_PROPERTY");
    token_sym_AT_SYNCHRONIZED = SCM_INTERN("AT_SYNCHRONIZED");
    token_sym_AT_FINALLY = SCM_INTERN("AT_FINALLY");
    token_sym_AT_CATCH = SCM_INTERN("AT_CATCH");
    token_sym_AT_TRY = SCM_INTERN("AT_TRY");
    token_sym_AT_THROW = SCM_INTERN("AT_THROW");
    token_sym_AT_ALIAS = SCM_INTERN("AT_ALIAS");
    token_sym_AT_CLASS = SCM_INTERN("AT_CLASS");
    token_sym_AT_PROTOCOL = SCM_INTERN("AT_PROTOCOL");
    token_sym_AT_PACKAGE = SCM_INTERN("AT_PACKAGE");
    token_sym_AT_PROTECTED = SCM_INTERN("AT_PROTECTED");
    token_sym_AT_PRIVATE = SCM_INTERN("AT_PRIVATE");
    token_sym_AT_PUBLIC = SCM_INTERN("AT_PUBLIC");
    token_sym_AT_ENCODE = SCM_INTERN("AT_ENCODE");
    token_sym_AT_DEFS = SCM_INTERN("AT_DEFS");
    token_sym_AT_SELECTOR = SCM_INTERN("AT_SELECTOR");
    token_sym_AT_END = SCM_INTERN("AT_END");
    token_sym_AT_IMPLEMENTATION = SCM_INTERN("AT_IMPLEMENTATION");
    token_sym_AT_INTERFACE = SCM_INTERN("AT_INTERFACE");
    token_sym_EXTENSION = SCM_INTERN("EXTENSION");
    token_sym_UNKNOWN = SCM_INTERN("UNKNOWN");
    token_sym_ASM = SCM_INTERN("ASM");
    token_sym_RETURN = SCM_INTERN("RETURN");
    token_sym_BREAK = SCM_INTERN("BREAK");
    token_sym_CONTINUE = SCM_INTERN("CONTINUE");
    token_sym_GOTO = SCM_INTERN("GOTO");
    token_sym_FOR = SCM_INTERN("FOR");
    token_sym_DO = SCM_INTERN("DO");
    token_sym_WHILE = SCM_INTERN("WHILE");
    token_sym_SWITCH = SCM_INTERN("SWITCH");
    token_sym_ELSE = SCM_INTERN("ELSE");
    token_sym_IF = SCM_INTERN("IF");
    token_sym_DEFAULT = SCM_INTERN("DEFAULT");
    token_sym_CASE = SCM_INTERN("CASE");
    token_sym_RANGE = SCM_INTERN("RANGE");
    token_sym_ELLIPSIS = SCM_INTERN("ELLIPSIS");
    token_sym_ENUM = SCM_INTERN("ENUM");
    token_sym_UNION = SCM_INTERN("UNION");
    token_sym_STRUCT = SCM_INTERN("STRUCT");
    token_sym_VOLATILE = SCM_INTERN("VOLATILE");
    token_sym_CONST = SCM_INTERN("CONST");
    token_sym_UNSIGNED = SCM_INTERN("UNSIGNED");
    token_sym_SIGNED = SCM_INTERN("SIGNED");
    token_sym_RESTRICT = SCM_INTERN("RESTRICT");
    token_sym_INLINE = SCM_INTERN("INLINE");
    token_sym_REGISTER = SCM_INTERN("REGISTER");
    token_sym_AUTO = SCM_INTERN("AUTO");
    token_sym_STATIC = SCM_INTERN("STATIC");
    token_sym_EXTERN = SCM_INTERN("EXTERN");
    token_sym_TYPEDEF = SCM_INTERN("TYPEDEF");
    token_sym_TYPENAME = SCM_INTERN("TYPENAME");
    token_sym_OR_ASSIGN = SCM_INTERN("OR_ASSIGN");
    token_sym_XOR_ASSIGN = SCM_INTERN("XOR_ASSIGN");
    token_sym_AND_ASSIGN = SCM_INTERN("AND_ASSIGN");
    token_sym_RIGHT_ASSIGN = SCM_INTERN("RIGHT_ASSIGN");
    token_sym_LEFT_ASSIGN = SCM_INTERN("LEFT_ASSIGN");
    token_sym_SUB_ASSIGN = SCM_INTERN("SUB_ASSIGN");
    token_sym_ADD_ASSIGN = SCM_INTERN("ADD_ASSIGN");
    token_sym_MOD_ASSIGN = SCM_INTERN("MOD_ASSIGN");
    token_sym_DIV_ASSIGN = SCM_INTERN("DIV_ASSIGN");
    token_sym_MUL_ASSIGN = SCM_INTERN("MUL_ASSIGN");
    token_sym_OR_OP = SCM_INTERN("OR_OP");
    token_sym_AND_OP = SCM_INTERN("AND_OP");
    token_sym_NE_OP = SCM_INTERN("NE_OP");
    token_sym_EQ_OP = SCM_INTERN("EQ_OP");
    token_sym_GE_OP = SCM_INTERN("GE_OP");
    token_sym_LE_OP = SCM_INTERN("LE_OP");
    token_sym_RIGHT_OP = SCM_INTERN("RIGHT_OP");
    token_sym_LEFT_OP = SCM_INTERN("LEFT_OP");
    token_sym_DEC_OP = SCM_INTERN("DEC_OP");
    token_sym_INC_OP = SCM_INTERN("INC_OP");
    token_sym_PTR_OP = SCM_INTERN("PTR_OP");
    token_sym_SIZEOF = SCM_INTERN("SIZEOF");
    token_sym_STRING = SCM_INTERN("STRING");
    token_sym_CONSTANT = SCM_INTERN("CONSTANT");
    token_sym_IDENTIFIER = SCM_INTERN("IDENTIFIER");
    token_sym__GT = SCM_INTERN(">");
    token_sym__LT = SCM_INTERN("<");
    token_sym_P = SCM_INTERN("?");
    token_sym__3d = SCM_INTERN("=");
    token_sym__25 = SCM_INTERN("%");
    token_sym__26 = SCM_INTERN("&");
    token_sym__5e = SCM_INTERN("^");
    token_sym__2f = SCM_INTERN("/");
    token_sym__2a = SCM_INTERN("*");
    token_sym__ = SCM_INTERN("-");
    token_sym__2b = SCM_INTERN("+");
    token_sym_X = SCM_INTERN("!");
    token_sym__7e = SCM_INTERN("~");
    token_sym_COLON = SCM_INTERN("COLON");
    token_sym_DOT = SCM_INTERN("DOT");
    token_sym_OR = SCM_INTERN("OR");
    token_sym_RPAREN = SCM_INTERN("RPAREN");
    token_sym_LPAREN = SCM_INTERN("LPAREN");
    token_sym_RSBRA = SCM_INTERN("RSBRA");
    token_sym_LSBRA = SCM_INTERN("LSBRA");
    token_sym_RCBRA = SCM_INTERN("RCBRA");
    token_sym_LCBRA = SCM_INTERN("LCBRA");
    token_sym_COMMA = SCM_INTERN("COMMA");
    token_sym_SEMICOLON = SCM_INTERN("SEMICOLON");
    token_table = Scm_MakeHashTableSimple(SCM_HASH_EQ, 106);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_START_MACRO, SCM_MAKE_INT(START_MACRO), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_OBJC_STRING, SCM_MAKE_INT(OBJC_STRING), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_REQUIRED, SCM_MAKE_INT(AT_REQUIRED), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_OPTIONAL, SCM_MAKE_INT(AT_OPTIONAL), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_DYNAMIC, SCM_MAKE_INT(AT_DYNAMIC), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_SYNTHESIZE, SCM_MAKE_INT(AT_SYNTHESIZE), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_PROPERTY, SCM_MAKE_INT(AT_PROPERTY), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_SYNCHRONIZED, SCM_MAKE_INT(AT_SYNCHRONIZED), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_FINALLY, SCM_MAKE_INT(AT_FINALLY), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_CATCH, SCM_MAKE_INT(AT_CATCH), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_TRY, SCM_MAKE_INT(AT_TRY), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_THROW, SCM_MAKE_INT(AT_THROW), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_ALIAS, SCM_MAKE_INT(AT_ALIAS), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_CLASS, SCM_MAKE_INT(AT_CLASS), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_PROTOCOL, SCM_MAKE_INT(AT_PROTOCOL), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_PACKAGE, SCM_MAKE_INT(AT_PACKAGE), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_PROTECTED, SCM_MAKE_INT(AT_PROTECTED), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_PRIVATE, SCM_MAKE_INT(AT_PRIVATE), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_PUBLIC, SCM_MAKE_INT(AT_PUBLIC), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_ENCODE, SCM_MAKE_INT(AT_ENCODE), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_DEFS, SCM_MAKE_INT(AT_DEFS), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_SELECTOR, SCM_MAKE_INT(AT_SELECTOR), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_END, SCM_MAKE_INT(AT_END), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_IMPLEMENTATION, SCM_MAKE_INT(AT_IMPLEMENTATION), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_INTERFACE, SCM_MAKE_INT(AT_INTERFACE), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_EXTENSION, SCM_MAKE_INT(EXTENSION), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_UNKNOWN, SCM_MAKE_INT(UNKNOWN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_ASM, SCM_MAKE_INT(ASM), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_RETURN, SCM_MAKE_INT(RETURN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_BREAK, SCM_MAKE_INT(BREAK), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_CONTINUE, SCM_MAKE_INT(CONTINUE), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_GOTO, SCM_MAKE_INT(GOTO), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_FOR, SCM_MAKE_INT(FOR), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_DO, SCM_MAKE_INT(DO), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_WHILE, SCM_MAKE_INT(WHILE), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_SWITCH, SCM_MAKE_INT(SWITCH), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_ELSE, SCM_MAKE_INT(ELSE), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_IF, SCM_MAKE_INT(IF), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_DEFAULT, SCM_MAKE_INT(DEFAULT), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_CASE, SCM_MAKE_INT(CASE), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_RANGE, SCM_MAKE_INT(RANGE), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_ELLIPSIS, SCM_MAKE_INT(ELLIPSIS), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_ENUM, SCM_MAKE_INT(ENUM), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_UNION, SCM_MAKE_INT(UNION), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_STRUCT, SCM_MAKE_INT(STRUCT), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_VOLATILE, SCM_MAKE_INT(VOLATILE), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_CONST, SCM_MAKE_INT(CONST), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_UNSIGNED, SCM_MAKE_INT(UNSIGNED), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_SIGNED, SCM_MAKE_INT(SIGNED), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_RESTRICT, SCM_MAKE_INT(RESTRICT), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_INLINE, SCM_MAKE_INT(INLINE), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_REGISTER, SCM_MAKE_INT(REGISTER), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AUTO, SCM_MAKE_INT(AUTO), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_STATIC, SCM_MAKE_INT(STATIC), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_EXTERN, SCM_MAKE_INT(EXTERN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_TYPEDEF, SCM_MAKE_INT(TYPEDEF), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_TYPENAME, SCM_MAKE_INT(TYPENAME), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_OR_ASSIGN, SCM_MAKE_INT(OR_ASSIGN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_XOR_ASSIGN, SCM_MAKE_INT(XOR_ASSIGN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AND_ASSIGN, SCM_MAKE_INT(AND_ASSIGN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_RIGHT_ASSIGN, SCM_MAKE_INT(RIGHT_ASSIGN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_LEFT_ASSIGN, SCM_MAKE_INT(LEFT_ASSIGN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_SUB_ASSIGN, SCM_MAKE_INT(SUB_ASSIGN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_ADD_ASSIGN, SCM_MAKE_INT(ADD_ASSIGN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_MOD_ASSIGN, SCM_MAKE_INT(MOD_ASSIGN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_DIV_ASSIGN, SCM_MAKE_INT(DIV_ASSIGN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_MUL_ASSIGN, SCM_MAKE_INT(MUL_ASSIGN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_OR_OP, SCM_MAKE_INT(OR_OP), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AND_OP, SCM_MAKE_INT(AND_OP), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_NE_OP, SCM_MAKE_INT(NE_OP), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_EQ_OP, SCM_MAKE_INT(EQ_OP), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_GE_OP, SCM_MAKE_INT(GE_OP), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_LE_OP, SCM_MAKE_INT(LE_OP), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_RIGHT_OP, SCM_MAKE_INT(RIGHT_OP), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_LEFT_OP, SCM_MAKE_INT(LEFT_OP), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_DEC_OP, SCM_MAKE_INT(DEC_OP), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_INC_OP, SCM_MAKE_INT(INC_OP), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_PTR_OP, SCM_MAKE_INT(PTR_OP), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_SIZEOF, SCM_MAKE_INT(SIZEOF), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_STRING, SCM_MAKE_INT(STRING), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_CONSTANT, SCM_MAKE_INT(CONSTANT), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_IDENTIFIER, SCM_MAKE_INT(IDENTIFIER), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym__GT, SCM_MAKE_INT(_GT), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym__LT, SCM_MAKE_INT(_LT), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_P, SCM_MAKE_INT(P), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym__3d, SCM_MAKE_INT(_3d), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym__25, SCM_MAKE_INT(_25), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym__26, SCM_MAKE_INT(_26), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym__5e, SCM_MAKE_INT(_5e), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym__2f, SCM_MAKE_INT(_2f), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym__2a, SCM_MAKE_INT(_2a), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym__, SCM_MAKE_INT(_), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym__2b, SCM_MAKE_INT(_2b), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_X, SCM_MAKE_INT(X), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym__7e, SCM_MAKE_INT(_7e), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_COLON, SCM_MAKE_INT(COLON), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_DOT, SCM_MAKE_INT(DOT), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_OR, SCM_MAKE_INT(OR), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_RPAREN, SCM_MAKE_INT(RPAREN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_LPAREN, SCM_MAKE_INT(LPAREN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_RSBRA, SCM_MAKE_INT(RSBRA), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_LSBRA, SCM_MAKE_INT(LSBRA), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_RCBRA, SCM_MAKE_INT(RCBRA), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_LCBRA, SCM_MAKE_INT(LCBRA), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_COMMA, SCM_MAKE_INT(COMMA), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_SEMICOLON, SCM_MAKE_INT(SEMICOLON), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), SCM_INTERN("*eoi*"), SCM_MAKE_INT(0), 0);
}


