;; -*- coding: utf-8; mode: scheme -*-
;;
;; stubgen.scm - Stub generater
;;
;;   Copyright (c) 2006 KOGURO, Naoki (naoki@koguro.net)
;;   All rights reserved.
;;
;;   Redistribution and use in source and binary forms, with or without 
;;   modification, are permitted provided that the following conditions 
;;   are met:
;;
;;   1. Redistributions of source code must retain the above copyright 
;;      notice, this list of conditions and the following disclaimer.
;;   2. Redistributions in binary form must reproduce the above copyright 
;;      notice, this list of conditions and the following disclaimer in the 
;;      documentation and/or other materials provided with the distribution.
;;   3. Neither the name of the authors nor the names of its contributors 
;;      may be used to endorse or promote products derived from this 
;;      software without specific prior written permission.
;;
;;   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
;;   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
;;   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
;;   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
;;   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
;;   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED 
;;   TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
;;   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
;;   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
;;   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
;;   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;;
;;   $Id: $
;;

(use file.filter)
(use file.util)
(use text.tr)
(use srfi-13)
(use util.match)
(use c-wrapper.c-parser)
(use c-wrapper.c-ffi)
(use srfi-1)

(define-syntax set-append!
  (syntax-rules ()
    ((_ var v sep)
     (set! var (string-append var sep v)))))

(define *template-dir* "./template")
(define *module-name* #f)
(define *includes* "")
(define *parsed-code* #f)
(define *cppflags* "-DGAUCHE_API_0_8_8")
(define *libs* "")
(define *ldflags* "")

(define *enums* "")
(define *typedefs* "")
(define *global-vars* "")
(define *extern-vars* "")
(define *cevals* "")
(define *defines* "")
(define *define-type* "")
(define *cprocs* "")

(define *variable-table* (make-hash-table 'equal?))
(define *enum-table* (make-hash-table))

(define (type-symbol->type sym)
  (match sym
    (('c-struct ('quote nam))
     #`"struct ,nam")
    (('c-union ('quote nam))
     #`"union ,nam")
    (('ptr type)
     (type-symbol->ptr-type type))
    (('make-c-array type num)
     #`",(type-symbol->type type)*")
    (('make-c-func-ptr ret-type ('list ('list nam arg-type) ...))
     (let ((args (string-join (map type-symbol->type arg-type) ",")))
       #`",(type-symbol->type ret-type) (*)(,|args|)"))
    (('make-c-func-ptr ret-type ('list arg-type ...))
     (let ((args (string-join (map type-symbol->type arg-type) ",")))
       #`",(type-symbol->type ret-type) (*)(,|args|)"))
    (('make-c-func-type _ ...)
     #f)
    ('<c-char>
     "char")
    ('<c-uchar>
     "unsigned char")
    ('<c-short>
     "short")
    ('<c-ushort>
     "unsigned short")
    ('<c-int>
     "int")
    ('<c-uint>
     "unsigned int")
    ('<c-long>
     "long")
    ('<c-ulong>
     "unsigned long")
    ('<c-longlong>
     "long long")
    ('<c-ulonglong>
     "unsigned long long")
    ('<c-float>
     "float")
    ('<c-double>
     "double")
    ('<c-longdouble>
     "long double")
    ('<c-void>
     "void")
    (else
     (rxmatch-case (x->string sym)
       (#/^<(.*)>$/ (#f type)
        type)
       (else
        (errorf "Unknown type ~a" sym))))))

(define (type-symbol->ptr-type sym)
  (match sym
    (('make-c-func-ptr ret-type ('list ('list nam arg-type) ...))
     (let ((args (string-join (map type-symbol->type arg-type) ",")))
       #`",(type-symbol->type ret-type) (*(*))(,|args|)"))
    (('make-c-func-ptr ret-type ('list arg-type ...))
     (let ((args (string-join (map type-symbol->type arg-type) ",")))
       #`",(type-symbol->type ret-type) (*(*))(,|args|)"))
    (else
     (string-append (type-symbol->type sym) "*"))))

(define (type-symbol->stub-type sym)
  (if (equal? sym '<c-void>)
      "<void>"
      (let1 varnam (get-variable-name sym)
        #`"<,|varnam|>")))
  
(define (register-type type eval?)
  (let ((varnam (gensym)))
    (hash-table-put! *variable-table* type varnam)
    (set-append! *global-vars* #`"ScmObj ,varnam;" "\n")
    (set-append! *extern-vars* #`"extern ScmObj ,varnam;" "\n")
    (and-let* ((ctype (type-symbol->type type)))
      (set-append! *defines* #`"#define BOX_,varnam(x) box(,varnam,, &(x))" "\n")
      (set-append! *defines* #`"#define UNBOX_,varnam(x) (*(,(type-symbol->ptr-type type)) unbox(x))" "\n")
      (set-append! *defines* #`"#define ,|varnam|_P(x) SCM_XTYPEP(x,, ,varnam)" "\n")
      (set-append! *define-type* #`"(define-type ,(type-symbol->stub-type type) \",|ctype|\" #f \",|varnam|_P\" \"UNBOX_,varnam\" \"BOX_,varnam\")" "\n"))
    (when eval?
      (set-append! *cevals* #`"    ,varnam = cw_eval(\",type\");" "\n"))))

(define (get-variable-name type)
  (or (hash-table-get *variable-table* type #f)
      (begin
        (register-type type #t)
        (get-variable-name type))))

(for-each (cut register-type <> #t) '(<c-longdouble>
                                      <c-float>
                                      <c-double>
                                      <c-uchar>
                                      <c-char>
                                      <c-ushort>
                                      <c-short>
                                      <c-uint>
                                      <c-int>
                                      <c-ulong>
                                      <c-long>
                                      <c-ulonglong>
                                      <c-longlong>
                                      <c-void>))

(define (filter-copy src dst
                     package-name extension-name module-name executables)
  (let1 EXTENSION-NAME (string-upcase extension-name)
    (file-filter (lambda (in out)
                   (port-for-each
                    (lambda (line)
                      (let1 str (regexp-replace-all*
                                 line
                                 #/@@package@@/ package-name
                                 #/@@modname@@/ (x->string module-name)
                                 #/@@modpath@@/ (module-name->path module-name)
                                 #/@@extname@@/ extension-name
                                 #/@@EXTNAME@@/ EXTENSION-NAME
                                 #/@@INCLUDES@@/ *includes*
                                 #/@@enums@@/ *enums*
                                 #/@@cppflags@@/ (string-trim *cppflags*)
                                 #/@@libs@@/ (string-trim *libs*)
                                 #/@@ldflags@@/ (string-trim *ldflags*))
                        (and-let* ((prev (string-scan line "@@cevals@@" 'before)))
                          (set! str (string-append prev *cevals*)))
                        (and-let* ((prev (string-scan line "@@globalvars@@" 'before)))
                          (set! str (string-append prev *global-vars*)))
                        (and-let* ((prev (string-scan line "@@externvars@@" 'before)))
                          (set! str (string-append prev *extern-vars*)))
                        (and-let* ((prev (string-scan line "@@defines@@" 'before)))
                          (set! str (string-append prev *defines*)))
                        (and-let* ((prev (string-scan line "@@define-type@@" 'before)))
                          (set! str (string-append prev *define-type*)))
                        (and-let* ((prev (string-scan line "@@cprocs@@" 'before)))
                          (set! str (string-append prev *cprocs*)))
                        (display str out)
                        (newline out)))
                    (cut read-line in)))
                 :input src
                 :output dst)
    (when (member (sys-basename dst) executables)
      (sys-chmod dst #o755))
    ))

(define (make-files package-name)
  (let* ((extension-name (string-tr package-name "A-Za-z_-" "a-za-z__"))
         (module-name (string->symbol extension-name))
         (scm-subdir (sys-dirname (module-name->path module-name))))
    (make-directory* (simplify-path (build-path package-name scm-subdir)))
    (for-each
     (lambda (file)
       (let* ((src-path (build-path *template-dir* #`"template.,file"))
              (dst-name (regexp-replace* 
                         file
                         #/extension/ extension-name
                         #/module/ (sys-basename
                                    (module-name->path module-name))))
              (dst-path (if (equal? file "module.scm")
                            (build-path package-name scm-subdir dst-name)
                            (build-path package-name dst-name))))
         (filter-copy src-path dst-path
                      package-name extension-name module-name '("DIST"))))
     '("Makefile.in" "configure.ac" "extension.c" "extension.h"
       "extensionlib.stub" "module.scm" "test.scm" "DIST"))))

(define (->list x)
  (if (list? x)
      x
      (list x)))

(define (parse filename)
  (define (parse-expr expr)
    (match expr
      (('define-module module lst ...)
       (set! *module-name* (x->string module))
       (for-each parse-expr lst))
      (('use 'objc-wrapper)
       (set-append! *cppflags* "-ObjC" " "))
      (('c-load-framework frameworks)
       (set-append! *libs*
                    (string-join (map (lambda (framework)
                                        #`"-framework ,framework")
                                      (->list frameworks))
                                 " ")
                    " "))
      (('c-load-library libs keywords ...)
       (let-keywords* keywords ((library-dirs '())
                                (option ""))
         (set-append! *libs*
                      (string-join (map (lambda (lib)
                                          #`"-l,(regexp-replace #/(|.*)lib/ lib \"\")")
                                        (->list libs)))
                      " ")
         (set-append! *ldflags* 
                      (string-join (map (cut string-append "-L" <>)
                                        (append
                                         (remove (cut string=? <> ".")
                                                 (map sys-dirname (->list libs)))
                                         library-dirs))
                                   " ")
                      " ")
         (set-append! *ldflags* option " ")))
      (('c-include headers args ...)
       (unless *module-name*
         (error "You must specify a module with define-module."))
       (let-keywords* args ((include-dirs '())
                            (option "")
                            (import-arg :import #f))
         (set-append! *includes*
                      (string-join (map (lambda (header)
                                          #`"#include \",header\"")
                                        (->list headers))
                                   "\n")
                      "\n")
         (set-append! *cppflags*
                      (string-join (map (lambda (dir)
                                          #`"-I,dir")
                                        (->list include-dirs))
                                   " ")
                      " ")
         (set-append! *cppflags* option " ")
         (set! *parsed-code* (with-output-to-string
                               (lambda ()
                                 (c-parse (->list include-dirs)
                                          (->list headers)
                                          (string-split option " ")
                                          import-arg))))))
      (else
       expr)))
  (with-input-from-file filename
    (lambda ()
      (port-for-each parse-expr read))))

(define (parse-scm)
  (with-input-from-string *parsed-code*
    (lambda ()
      (port-for-each (lambda (expr)
                       (match expr
                         (('define-enum name val)
                          (set-append! *enums* #`"(define-enum ,name)" "\n")
                          (hash-table-put! *enum-table* name #t))
                         (('define-ctype new-type type)
                          (register-type new-type #f)
                          (let ((varnam (get-variable-name type)))
                            (set-append! *cevals*
                                         #`"    ,(get-variable-name new-type) = ,varnam;"
                                       "\n")
                            (set-append! *cevals*
                                         #`"    SCM_DEFINE(mod,, \",new-type\",, ,varnam);"
                                         "\n")))
                         (('define-c-union name)
                          (set-append! *cevals*
                                       #`"    cw_eval(\",expr\");"
                                       "\n")
                          (register-type `(c-union ',name) #t))
                         (('init-c-union! _)
                          (set-append! *cevals*
                                       #`"    cw_eval(\",expr\");"
                                       "\n"))
                         (('define-c-struct name)
                          (set-append! *cevals*
                                       #`"    cw_eval(\",expr\");"
                                       "\n")
                          (register-type `(c-struct ',name) #t))
                         (('init-c-struct! _ ...)
                          (set-append! *cevals*
                                       #`"    cw_eval(\",expr\");"
                                       "\n"))
                         (('define-objc-class _ ...)
                          (set-append! *cevals*
                                       #`"    cw_eval(\",expr\");"
                                       "\n"))
                         (('define-objc-method name param)
                          (let1 str (regexp-replace-all
                                     #/\"/
                                     (format "(define-objc-method \"~a\" ~s)" name param) 
                                     "\\\\\"")
                            (set-append! *cevals*
                                         (format "    cw_eval(\"~a\");" str)
                                       "\n")))
                         (('define-extern name ('make-c-func _ ret-type ('list arg-types ...)))
                          (let* ((narg-types (remove (cut equal? <> '<c-void>) arg-types))
                                 (args (string-join (map (lambda (n arg-type)
                                                          #`"v,|n|::,(type-symbol->stub-type arg-type)")
                                                        (iota (length narg-types))
                                                        narg-types)
                                                   " "))
                                (stub-ret-type (type-symbol->stub-type ret-type)))
                            (set-append! *cprocs*
                                         #`"(define-cproc ,name (,|args|) (call ,stub-ret-type \",name\"))"
                                         "\n")))
                         (('define-cmacro name val)
                          (if (hash-table-exists? *enum-table* name)
                              (format (standard-error-port)
                                      "redefing constant ~a, so ignored ~s~%"
                                      name expr)
                              (let1 str (regexp-replace-all
                                         #/\"/
                                         (format "~s" expr)
                                         "\\\\\"")
                                (set-append! *cevals*
                                             (format "    cw_eval(\"~a\");" str)
                                             "\n"))))
                         (('define-cfunclike-macro _ ...)
                          (let1 str (regexp-replace-all
                                     #/\"/
                                     (format "~s" expr)
                                     "\\\\\"")
                            (set-append! *cevals*
                                         (format "    cw_eval(\"~a\");" str)
                                       "\n")))
                         (else
                          (let1 str (regexp-replace-all
                                     #/\"/
                                     (format "~s" expr)
                                     "\\\\\"")
                            (set-append! *cevals*
                                         (format "    cw_eval(\"~a\");" str)
                                       "\n")))))
                     read))))

(define (main args)
  (parse (list-ref args 1))
  (parse-scm)
  (make-files *module-name*)
  0)

;; end of file
