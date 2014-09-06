;; -*- coding: utf-8; mode: scheme -*-
;;
;; genyacc.scm - Generate YACC source.
;;
;;   Copyright (c) 2009 KOGURO, Naoki (naoki@koguro.net)
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

(use gauche.parseopt)
(use util.match)
(use srfi-11)
(use srfi-1)
(use gauche.cgen.unit)

(define cfunc-table (make-hash-table))

(define (register-cfunc! scm-name c-name)
  (hash-table-put! cfunc-table scm-name c-name))

(define (has-cfunc? scm-name)
  (hash-table-exists? cfunc-table scm-name))
  
(define (cfunc-name scm-name)
  (hash-table-get cfunc-table scm-name #f))

(define (use-stub filename)
  (call-with-input-file filename
      (lambda (in)
        (port-for-each (lambda (expr)
                         (match expr
                           (('define-cproc scm-name args
                              ('call c-name))
                            (register-cfunc! scm-name c-name))
                           (else
                            #f)))
                       (cut read in)))))

(define-class <yacc-context> ()
  ((decl-part :init-value '())
   (rule-part :init-value '())
   (profiler-table :init-value (make-hash-table 'equal?))
   (token-list :init-value '())
   (object-alist :init-value '())))

(define make-name
  (let ((counter 0))
    (lambda ()
      (inc! counter)
      #`"name_,counter")))

(define (ccode-list context args)
  (let ((len (length args)))
    (case len
      ((0) "SCM_NIL")
      ((1) #`"SCM_LIST1(,(scm->c context (ref args 0)))")
      ((2) #`"SCM_LIST2(,(scm->c context (ref args 0)),, ,(scm->c context (ref args 1)))")
      ((3) #`"SCM_LIST3(,(scm->c context (ref args 0)),, ,(scm->c context (ref args 1)),, ,(scm->c context (ref args 2)))")
      ((4) #`"SCM_LIST4(,(scm->c context (ref args 0)),, ,(scm->c context (ref args 1)),, ,(scm->c context (ref args 2)),, ,(scm->c context (ref args 3)))")
      ((5) #`"SCM_LIST5(,(scm->c context (ref args 0)),, ,(scm->c context (ref args 1)),, ,(scm->c context (ref args 2)),, ,(scm->c context (ref args 3)),, ,(scm->c context (ref args 4)))")
      (else
       #`"Scm_Cons(,(scm->c context (car args)),, ,(ccode-list context (cdr args)))"))))
    
(define (ccode-eval context expr)
  (let ((func-name (car expr))
        (args (cdr expr)))
    (case (length args)
      ((0)  #`"Scm_ApplyRec0(,func-name)")
      ((1)  #`"Scm_ApplyRec1(,func-name,, ,(scm->c context (ref args 0)))")
      ((2)  #`"Scm_ApplyRec2(,func-name,, ,(scm->c context (ref args 0)),, ,(scm->c context (ref args 1)))")
      ((3)  #`"Scm_ApplyRec3(,func-name,, ,(scm->c context (ref args 0)),, ,(scm->c context (ref args 1)),, ,(scm->c context (ref args 2)))")
      ((4)  #`"Scm_ApplyRec4(,func-name,, ,(scm->c context (ref args 0)),, ,(scm->c context (ref args 1)),, ,(scm->c context (ref args 2)),, ,(scm->c context (ref args 3)))")
      ((5)  #`"Scm_ApplyRec5(,func-name,, ,(scm->c context (ref args 0)),, ,(scm->c context (ref args 1)),, ,(scm->c context (ref args 2)),, ,(scm->c context (ref args 3)),, ,(scm->c context (ref args 4)))")
      (else #`"Scm_ApplyRec (,func-name,, ,(ccode-list context args))"))))

(define (analyze-args scm-code)
  (define (traverse args code cont)
    (cond
     ((null? code)
      (cont args))
     ((pair? code)
      (let-values (((head rest) (car+cdr code)))
        (cond
         ((pair? head)
          (traverse args head (cut traverse <> rest cont)))
         ((#/^\$\d+$/ (x->string head))
          (traverse (if (memq head args)
                        args
                        (cons head args))
                    rest cont))
         (else
          (traverse args rest cont)))))
     (else
      (traverse args (list code) cont))))
  (traverse '() scm-code reverse))

(define (ccode-value-list vals)
  (define (cconst v)
    (match v
      ((? symbol? v)
       #`"SCM_INTERN(\",v\")")
      ((? fixnum? v)
       #`"SCM_MAKE_INT(,v)")))
  (let ((len (length vals)))
    (case len
      ((0) "SCM_NIL")
      ((1) #`"SCM_LIST1(,(cconst (ref vals 0)))")
      ((2) #`"SCM_LIST2(,(cconst (ref vals 0)),, ,(cconst (ref vals 1)))")
      ((3) #`"SCM_LIST3(,(cconst (ref vals 0)),, ,(cconst (ref vals 1)),, ,(cconst (ref vals 2)))")
      ((4) #`"SCM_LIST4(,(cconst (ref vals 0)),, ,(cconst (ref vals 1)),, ,(cconst (ref vals 2)),, ,(cconst (ref vals 3)))")
      ((5) #`"SCM_LIST5(,(cconst (ref vals 0)),, ,(cconst (ref vals 1)),, ,(cconst (ref vals 2)),, ,(cconst (ref vals 3)),, ,(cconst (ref vals 4)))")
      (else
       #`"Scm_Cons(,(cconst (car vals)),, ,(ccode-value-list (cdr vals)))"))))

(define (yacc-arg? x)
  (#/^\$\d+$/ (x->string x)))

(define (cobj context v)
  (or (and-let* ((pair (find (lambda (pair)
                               (equal? (cdr pair) v))
                             (ref context 'object-alist))))
        (car pair))
      (let ((name (make-name)))
        (register-object! context name v)
        name)))

(define (register-object! context name v)
  (push! (ref context 'object-alist) (cons name v)))
  
(define (scm->c context expr)
  (match expr
    (()
     "SCM_NIL")
    ((? yacc-arg? v)
     #`",v")
    (('quote (vals ...))
     (cobj context `(quote ,vals)))
    (('quote sym)
     (cobj context `(quote ,sym)))
    (#f
     "SCM_FALSE")
    ((? fixnum? x)
     #`"SCM_MAKE_INT(,x)")
    (('car v)
     #`"SCM_CAR(,(scm->c context v))")
    (('cdr v)
     #`"SCM_CDR(,(scm->c context v))")
    (('caar v)
     #`"SCM_CAAR(,(scm->c context v))")
    (('cadr v)
     #`"SCM_CADR(,(scm->c context v))")
    (('cdar v)
     #`"SCM_CDAR(,(scm->c context v))")
    (('cddr v)
     #`"SCM_CDDR(,(scm->c context v))")
    (('list vals ...)
     (ccode-list context vals))
    ((? symbol? v)
     (cobj context v))
    ((? keyword? v)
     (cobj context v))
    ((? string? v)
     (cobj context v))
    ((func-name args ...)
     (if (has-cfunc? func-name)
         (format "~a(~a)"
                 (cfunc-name func-name)
                 (string-join (map (lambda (arg)
                                     (scm->c context arg))
                                   args)
                              ","))
         (let ((c-name (cobj context func-name)))
           (ccode-eval context (cons c-name args)))))))
    
(define (generate-action context action)
  (define (%generate-ccode expr tail?)
    (format "~a~a;"
            (if tail?
                "$$ = "
                "")
            (scm->c context expr)))
  (let ((ccode (match action
                 (('begin expr ...)
                  (let loop ((rest expr)
                             (body '()))
                    (if (null? rest)
                        (string-join (reverse body) " ")
                        (loop (cdr rest)
                              (cons (%generate-ccode (car rest)
                                                     (null? (cdr rest)))
                                    body)))))
                 (else
                  (%generate-ccode action #t))))
        (name (make-name)))
    (hash-table-put! (ref context 'profiler-table) name action)
    #`"{ START_PROFILE(,name) ,ccode END_PROFILE(,name) }"))
  
(define (rule-parser context lst)
  (let loop ((result '())
             (rest lst))
    (match rest
      (((elements ...) ': action rest ...)
       (loop (cons (cons elements (generate-action context action)) result) rest))
      (((elements ...) rest ...)
       (loop (cons (cons elements #f) result) rest))
      (()
       (reverse result)))))

(define (token-symbol-cname identifier)
  (string->symbol #`"token_sym_,(cgen-safe-name-friendly (x->string identifier))"))

(define (lalr-parser context lst)
  (for-each (lambda (sexp)
              (match sexp
                (('expect: n)
                 #f)
                (('output: func filename)
                 #f)
                (('ID identifiers ...)
                 (for-each (lambda (identifier)
                             (push! (ref context 'decl-part)
                                    (format "%token ~a" (cgen-safe-name-friendly (x->string identifier))))
                             (register-object! context (token-symbol-cname identifier) `(quote ,identifier))
                             (push! (ref context 'token-list) identifier))
                           identifiers))
                ((rule-name rest ...)
                 (push! (ref context 'rule-part)
                        (with-output-to-string
                          (lambda ()
                            (let ((rules (rule-parser context rest)))
                              (format #t "~a~%" (cgen-safe-name-friendly (x->string rule-name)))
                              (fold (lambda (rule separator)
                                      (format #t "\t~a ~a ~a~%"
                                              separator
                                              (string-join (map (lambda (sym)
                                                                  (cgen-safe-name-friendly (x->string sym)))
                                                                (car rule)) " ")
                                              (or (cdr rule)
                                                  ""))
                                      "|")
                                    ":"
                                    rules)
                              (print ";"))))))))
            lst))

(define (write-code context ofile)
  (with-output-to-file ofile
    (lambda ()
      (print "%{")
      (print "#define YYSTYPE ScmObj")
      (print "static ScmObj token_table = SCM_UNBOUND;")
      (for-each (lambda (name)
                  (print #`"static ScmObj ,name = SCM_UNBOUND;"))
                (map car (slot-ref context 'object-alist)))
      (print "#ifdef USE_PROFILER")
      (for-each (lambda (name)
                  (print #`"static long long _profile_,|name|_count = 0;")
                  (print #`"static long long _profile_,|name|_time = 0;"))
                (hash-table-keys (slot-ref context 'profiler-table)))
      (print "#endif")
      (print "%}")
      (for-each (lambda (decl)
                  (print decl))
                (reverse (slot-ref context 'decl-part)))
      (print "%%")
      (for-each (lambda (rule)
                  (print rule))
                (reverse (slot-ref context 'rule-part)))
      (print "%%")
      (print "#ifdef USE_PROFILER")
      (print "static void show_profile_result()")
      (print "{")
      (print "    fprintf(stderr, \"---\\n\");")
      (hash-table-for-each (slot-ref context 'profiler-table)
                           (lambda (name action)
                             (print #`"    fprintf(stderr, \"%s\\t%lld\\t%lld\\n\",, \",|action|\",, _profile_,|name|_count,, _profile_,|name|_time);")))
      (print "}")
      (print "#endif")
      (print "void init_parser()")
      (print "{")
      (print "    if (!SCM_UNBOUNDP(token_table)) {")
      (print "        /* already initialized */")
      (print "        return;")
      (print "    }")
      (for-each (lambda (pair)
                  (let ((init (match (cdr pair)
                                (('quote (vals ...))
                                 (ccode-value-list vals))
                                (('quote (? symbol? sym))
                                 #`"SCM_INTERN(\",sym\")")
                                ((? keyword? v)
                                 #`"SCM_MAKE_KEYWORD(\",v\")")
                                ((? string? str)
                                 #`"SCM_MAKE_STR_IMMUTABLE(\",str\")")
                                ((? symbol? sym)
                                 #`"SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME,, \",sym\")"))))
                    (print #`"    ,(car pair) = ,init;")))
                (slot-ref context 'object-alist))
      (print #`"    token_table = Scm_MakeHashTableSimple(SCM_HASH_EQ, ,(length (slot-ref context 'token-list)));")
      (for-each (lambda (token)
                  (print #`"    Scm_HashTableSet(SCM_HASH_TABLE(token_table),, ,(token-symbol-cname token),, SCM_MAKE_INT(,(cgen-safe-name-friendly (x->string token))),, 0);"))
                (slot-ref context 'token-list))
      (print "    Scm_HashTableSet(SCM_HASH_TABLE(token_table), SCM_INTERN(\"*eoi*\"), SCM_MAKE_INT(0), 0);")
      (print "}")
      (print ""))))

(define (scm->y ifile ofile)
  (let ((context (make <yacc-context>)))
    (hash-table-put! (ref context 'profiler-table) "yylex" '(yylex))    
    (hash-table-put! (ref context 'profiler-table) "c_scan" '(c_scan))    
    (with-input-from-file ifile
      (lambda ()
        (port-for-each (lambda (sexp)
                         (match sexp
                           (('lalr-parser rest ...)
                            (lalr-parser context rest))))
                       read)))
    (write-code context ofile)))

(define (main args)
  (let-args (cdr args) ((outfile "o|outfile=s")
                        . args)
    (let* ((ifile (car args))
           (ofile (or outfile
                      (if (#/\.scm$/ ifile)
                          (regexp-replace #/\.scm$/ ifile ".y")
                          #`",|ifile|.y"))))
      (use-stub "./c-parserlib.stub")
      (use-stub "./c-ffilib.stub")
      (scm->y ifile ofile)))
  0)
    
;; end of file
