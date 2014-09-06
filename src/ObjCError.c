/**
 *  ObjCError.m
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
 *   $Id: ffi.c 233 2006-05-03 15:58:37Z naoki $
 */

#include <gauche.h>
#include <gauche/class.h>
#include <gauche/exception.h>

#import "ObjCError.h"

static ScmObj objc_error_allocate(ScmClass *klass, ScmObj initargs);
static void objc_error_print(ScmObj objc_error, ScmPort *port, ScmWriteContext *ctx);

static ScmClass *default_cpl[] = {
    SCM_CLASS_STATIC_PTR(Scm_TopClass), NULL
};

SCM_DEFINE_BASE_CLASS(Scm_ObjCErrorClass, ScmObjCError,
                      objc_error_print, NULL, NULL, objc_error_allocate,
                      default_cpl);

static ScmObj objc_error_allocate(ScmClass *klass, ScmObj initargs)
{
    ScmObjCError *err = SCM_ALLOCATE(ScmObjCError, klass);
    SCM_SET_CLASS(err, klass);
    err->name = SCM_FALSE;
    err->reason = SCM_FALSE;

    SCM_RETURN(SCM_OBJ(err));
}

static void objc_error_print(ScmObj obj, ScmPort *port, ScmWriteContext *ctx)
{
    Scm_Printf(port, "#<objc-error %A (%A)>"
               , SCM_OBJC_ERROR(obj)->name, SCM_OBJC_ERROR(obj)->reason);
}

static ScmObj objc_error_name_get(ScmObjCError *err)
{
    SCM_RETURN(err->name);
}

static ScmObj objc_error_reason_get(ScmObjCError *err)
{
    SCM_RETURN(err->reason);
}

static ScmClassStaticSlotSpec objc_error_slots[] = {
    SCM_CLASS_SLOT_SPEC("name", objc_error_name_get, NULL),
    SCM_CLASS_SLOT_SPEC("reason", objc_error_reason_get, NULL),
    { NULL }
};

ScmObj Scm_MakeObjCError(ScmObj name, ScmObj reason)
{
    ScmObj e = objc_error_allocate(SCM_CLASS_OBJC_ERROR, SCM_NIL);
    SCM_OBJC_ERROR(e)->name = name;
    SCM_OBJC_ERROR(e)->reason = reason;

    SCM_RETURN(e);
}

void Scm_Init_ObjCError(ScmModule *mod)
{
    Scm_InitStaticClass(&Scm_ObjCErrorClass, "<objc-error>", mod, objc_error_slots, 0);
}
               
