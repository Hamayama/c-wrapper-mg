/**
 *  util.h 
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
#ifndef GAUCHE_CWRAPPER_UTIL_H
#define GAUCHE_CWRAPPER_UTIL_H

#define SYM(x) sym_##x
#define DEFINE_SYM(x) static ScmObj SYM(x)
#define INIT_SYM(x, s) SYM(x)=SCM_INTERN(s)
#define DEFINE_PROC0(cname, module, name)           \
    static inline ScmObj cname()                    \
    {                                               \
        static ScmObj _proc = SCM_UNBOUND;          \
        if (SCM_UNBOUNDP(_proc)) {                  \
            _proc = SCM_SYMBOL_VALUE(module, name); \
        }                                           \
        SCM_RETURN(Scm_ApplyRec0(_proc));           \
    }
#define DEFINE_PROC1(cname, module, name)           \
    static inline ScmObj cname(ScmObj v0)           \
    {                                               \
        static ScmObj _proc = SCM_UNBOUND;          \
        if (SCM_UNBOUNDP(_proc)) {                  \
            _proc = SCM_SYMBOL_VALUE(module, name); \
        }                                           \
        SCM_RETURN(Scm_ApplyRec1(_proc, v0));       \
    }
#define DEFINE_PROC2(cname, module, name)               \
    static inline ScmObj cname(ScmObj v0, ScmObj v1)    \
    {                                                   \
        static ScmObj _proc = SCM_UNBOUND;              \
        if (SCM_UNBOUNDP(_proc)) {                      \
            _proc = SCM_SYMBOL_VALUE(module, name);     \
        }                                               \
        SCM_RETURN(Scm_ApplyRec2(_proc, v0, v1));       \
    }
#define DEFINE_PROC3(cname, module, name)                       \
    static inline ScmObj cname(ScmObj v0, ScmObj v1, ScmObj v2) \
    {                                                           \
        static ScmObj _proc = SCM_UNBOUND;                      \
        if (SCM_UNBOUNDP(_proc)) {                              \
            _proc = SCM_SYMBOL_VALUE(module, name);             \
        }                                                       \
        SCM_RETURN(Scm_ApplyRec3(_proc, v0, v1, v2);            \
    }
#define DEFINE_PROC4(cname, module, name)                               \
    static inline ScmObj cname(ScmObj v0, ScmObj v1, ScmObj v2, ScmObj v3) \
    {                                                                   \
        static ScmObj _proc = SCM_UNBOUND;                              \
        if (SCM_UNBOUNDP(_proc)) {                                      \
            _proc = SCM_SYMBOL_VALUE(module, name);                     \
        }                                                               \
        SCM_RETURN(Scm_ApplyRec4(_proc, v0, v1, v2, v3));               \
    }
#define DEFINE_PROC5(cname, module, name)                               \
    static inline ScmObj cname(ScmObj v0, ScmObj v1, ScmObj v2, ScmObj v3, ScmObj v4) \
    {                                                                   \
        static ScmObj _proc = SCM_UNBOUND;                              \
        if (SCM_UNBOUNDP(_proc)) {                                      \
            _proc = SCM_SYMBOL_VALUE(module, name);                     \
        }                                                               \
        SCM_RETURN(Scm_ApplyRec5(_proc, v0, v1, v2, v3, v4));           \
    }

#endif  /* GAUCHE_CWRAPPER_UTIL_H */

/* end of file */
