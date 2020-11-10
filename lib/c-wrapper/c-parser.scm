;; -*- coding: utf-8; mode: scheme -*-
;;
;; parser.scm
;; 
;;  Copyright (c) 2006 KOGURO, Naoki (naoki@koguro.net)
;; 
;;  Permission is hereby granted, free of charge, to any person 
;;  obtaining a copy of this software and associated 
;;  documentation files (the "Software"), to deal in the 
;;  Software without restriction, including without limitation 
;;  the rights to use, copy, modify, merge, publish, distribute, 
;;  sublicense, and/or sell copies of the Software, and to 
;;  permit persons to whom the Software is furnished to do so, 
;;  subject to the following conditions:
;; 
;;  The above copyright notice and this permission notice shall 
;;  be included in all copies or substantial portions of the 
;;  Software.
;; 
;;  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY 
;;  KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE 
;;  WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR 
;;  PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS 
;;  OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR 
;;  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR 
;;  OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
;;  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
;; 
;;  $Id: $

(define-module c-wrapper.c-parser
  (use srfi-1)
  (use srfi-13)
  (use srfi-11)
  (use gauche.process)
  (use gauche.sequence)
  (use file.util)
  (use util.match)
  (use gauche.vport)
  (use gauche.uvector)
  (use gauche.regexp)
  (use gauche.config)
  (use util.queue)
  (use c-wrapper.config)
  (use c-wrapper.c-ffi)
  (use c-wrapper.context)
  (use c-wrapper.c-lex)
  (use util.list)

  (export c-parse)
  (dynamic-load "c-parser")
  )

(select-module c-wrapper.c-parser)

(define (with-parse-context trunk)
  (unwind-protect
   (begin
     (set! context (make <parse-context>))
     (init-type-table)
     (init-value-pool)
     (init-struct-pool)
     (init-union-pool)
     (parser-attribute-clear!)
     (all-referenced-info-clear!)
     (defchunk-dict-init)
     (trunk))
   (set! context #f)))

;; (define (register-identifier name value)
;;   (hash-table-put! (value-pool) name value)
;;   value)

;; (define (registered-identifier? name)
;;   (or (hash-table-exists? (value-pool) name)
;;       (memq name (arg-pool))))

;; (define (c-lookup-value v)
;;   (match v
;;     (('identity (? symbol? name))
;;      (hash-table-get (value-pool) name #f))
;;     (else
;;      v)))

(debug-print-width #f)

;; moved to c-parserlib.stub
;; (define (c-type->class-symbol type)
;;   (string->symbol (string-append "<" (symbol->string type) ">")))

;;
;;
;;

;; (define (%INT v)
;;   (if (real? v)
;;       (x->integer v)
;;       `((with-module c-wrapper.c-ffi cast) <integer> ,v)))

(define (%REAL v)
  (if (real? v)
      v
      `((with-module c-wrapper.c-ffi cast) <real> ,v)))

(define (%SCM-CAST expr)
  (match expr
    ((? number? v)
     v)
    ((? string? v)
     v)
    (('begin (or (? number? v) (? string? v)))
     v)
    ((('with-module 'c-wrapper.c-ffi 'cast) _ (? number? v))
     v)
    (else
     `(scm-cast ,expr))))

(define (%IDENTIFIER v)
  (if (registered-identifier? v)
      (begin
        (referenced-identifier-list-add! v)
        v)
      #f))

(define-syntax define-maybe
  (syntax-rules ()
    ((_ (name . args) . body)
     (define (name . args)
       (if (and . args)
           (begin . body)
           #f)))))

;; (define-maybe (%TYPENAME v)
;;   (referenced-typename-list-add! v)
;;   (list v))

(define-maybe (%STRUCT-OR-UNION-SPECIFIER v)
  (referenced-typename-list-add! (list-ref v 1))
  (list v))

(define-maybe (%ENUM-SPECIFIER v)
  (referenced-typename-list-add! (list-ref v 1))
  (list v))
  
(define-maybe (%MACRO-BODY body)
  (let ((new-body (if (null? (cdr body))
                      (%SCM-CAST (car body))
                      (%SCM-CAST `(begin ,@body)))))
    (macro-body-set! new-body)
    new-body))

(define-maybe (%FUNCTION-BODY body)
  `(call/cc (lambda (%return) ,body)))

(define-maybe (%OBJC-STRING v)
  `(@ ,v))

(define-maybe (%EXPR-IN-PARENS expr)
  (if (symbol? expr)
      `(identity ,expr)
      expr))

(define-maybe (%COMPOUND-STATEMENT statements)
  `(begin ,@statements))

(define-maybe (%COMPOUND-STATEMENT-WITH-DECLARATION declaration-list statements)
  (let ((var-list '())
        (init-list '()))
    (for-each (lambda (declaration)
                (let* ((type (type-of declaration))
                       (identifier (name-of declaration))
                       (init-val (value-of declaration)))
                  ;; TODO: typedef in compound_statement is not supported
                  (push! var-list `(,identifier (make ,type)))
                  (when init-val
                    (push! init-list
                           `(set! ((with-module c-wrapper.c-ffi ref) ,identifier)
                                  ,init-val)))))
              declaration-list)
    `(let* ,(reverse var-list)
       ,@(reverse init-list)
       ,@statements)))

(define-maybe (%REF-ARRAY v index)
  `((with-module c-wrapper.c-ffi ref) ,v ,(%INT index)))

(define-maybe (%FUNCALL func names)
  (cons (c-lookup-value func) names))

(define-maybe (%DOT-REF v name)
  `(raw-ref ,v ',name))

(define-maybe (%PTR-REF p name)
  `(raw-ref ((with-module c-wrapper.c-ffi deref) ,p) ',name))

(define-maybe (%POST-INC v)
  `(post++ ,v))

(define-maybe (%POST-DEC v)
  `(post-- ,v))

;; (define-maybe (%LIST v)
;;   (list v))

;; (define-maybe (%ADD-LIST lst v)
;;   (append lst (list v)))

(define-maybe (%PRE-INC v)
  `(pre++ ,v))

(define-maybe (%PRE-DEC v)
  `(pre-- ,v))

(define-maybe (%UNARY op v)
  (case op
    ((+) v)
    ((-) (%SUB 0 v))
    ((!) (%IF v 0 1))
    ((~) (%BIT-NOT v))
    ((&) `((with-module c-wrapper.c-ffi ptr) ,v))
    ((*) `((with-module c-wrapper.c-ffi deref) ,v))
    (else #f)))

(define-maybe (%BIT-NOT v)
  (if (integer? v)
      (lognot v)
      `(lognot ,(%INT v))))

(define-maybe (%SIZEOF-EXPR v)
  `(c-sizeof ,v))

(define-maybe (%SIZEOF-TYPE v)
  `(c-sizeof ,(type-of v)))

(define-maybe (%CAST type-name expr)
  `((with-module c-wrapper.c-ffi cast) ,(type-of type-name) ,expr))

(define-maybe (%MUL expr1 expr2)
  (if (and (real? expr1) (real? expr2))
      (* expr1 expr2)
      `(* ,expr1 ,expr2)))

(define-maybe (%DIV expr1 expr2)
  (if (and (real? expr1) (real? expr2))
      (/ expr1 expr2)
      `(/ ,expr1 ,expr2)))

(define-maybe (%MOD expr1 expr2)
  (if (and (integer? expr1) (integer? expr2))
      (modulo expr1 expr2)
      `(modulo ,(%INT expr1) ,(%INT expr2))))

(define-maybe (%ADD expr1 expr2)
  (if (and (real? expr1) (real? expr2))
      (+ expr1 expr2)
      `(if (is-a? ,expr1 <c-ptr>)
           (c-ptr+ ,expr1 ,expr2)
           (+ ,expr1 ,expr2))))

(define-maybe (%SUB expr1 expr2)
  (if (and (real? expr1) (real? expr2))
      (- expr1 expr2)
      `(if (is-a? ,expr1 <c-ptr>)
           (c-ptr- ,expr1 ,expr2)
           (- ,expr1 ,expr2))))

(define-maybe (%SHIFT-LEFT expr1 expr2)
  (if (and (integer? expr1) (integer? expr2))
      (ash expr1 expr2)
      `(ash ,(%INT expr1) ,(%INT expr2))))

(define-maybe (%SHIFT-RIGHT expr1 expr2)
  (if (and (integer? expr1) (integer? expr2))
      (ash expr1 (- expr2))
      `(ash ,(%INT expr1) (- ,expr2))))

(define-maybe (%LT expr1 expr2)
  (if (and (real? expr1) (real? expr2))
      (if (< expr1 expr2) 1 0)
      `(if (< ,(%REAL expr1) ,(%REAL expr2)) 1 0)))

(define-maybe (%GT expr1 expr2)
  (if (and (real? expr1) (real? expr2))
      (if (> expr1 expr2) 1 0)
      `(if (> ,(%REAL expr1) ,(%REAL expr2)) 1 0)))

(define-maybe (%LE expr1 expr2)
  (if (and (real? expr1) (real? expr2))
      (if (<= expr1 expr2) 1 0)
      `(if (<= ,(%REAL expr1) ,(%REAL expr2)) 1 0)))

(define-maybe (%GE expr1 expr2)
  (if (and (real? expr1) (real? expr2))
      (if (>= expr1 expr2) 1 0)
      `(if (>= ,(%REAL expr1) ,(%REAL expr2)) 1 0)))

(define-maybe (%EQ expr1 expr2)
  (if (and (real? expr1) (real? expr2))
      (if (eq? expr1 expr2) 1 0)
      `(if (equal? ,(%REAL expr1) ,(%REAL expr2)) 1 0)))

(define-maybe (%NE expr1 expr2)
  (if (and (real? expr1) (real? expr2))
      (if (eq? expr1 expr2) 0 1)
      `(if (equal? ,(%REAL expr1) ,(%REAL expr2)) 0 1)))

(define-maybe (%BIT-AND expr1 expr2)
  (if (and (integer? expr1) (integer? expr2))
      (logand expr1 expr2)
      `(logand ,(%INT expr1) ,(%INT expr2))))

(define-maybe (%BIT-XOR expr1 expr2)
  (if (and (integer? expr1) (integer? expr2))
      (logxor expr1 expr2)
      `(logxor ,(%INT expr1) ,(%INT expr2))))

(define-maybe (%BIT-OR expr1 expr2)
  (if (and (integer? expr1) (integer? expr2))
      (logior expr1 expr2)
      `(logior ,(%INT expr1) ,(%INT expr2))))

(define-maybe (%LOG-AND expr1 expr2)
  (let ((v (gensym "%")))
    `(let ((,v ,(%REAL expr1)))
       (if (eq? ,v 0) ,v ,expr2))))

(define-maybe (%LOG-OR expr1 expr2)
  (let ((v (gensym "%")))
    `(let ((,v ,(%REAL expr1)))
       (if (eq? ,v 0) ,expr2 ,v))))

(define-maybe (%IF test then else)
  `(if (eq? ,(%REAL test) 0) ,else ,then))

(define-maybe (%ASSIGN lhs rhs)
  (match lhs
    ((? symbol? x)
     `(let ((%v ,rhs))
        (set! ((with-module c-wrapper.c-ffi ref) ,x) %v)
        %v))
    (((or ('with-module 'c-wrapper.c-ffi 'ref) 'raw-ref) x ...)
     `(let ((%v ,rhs))
        (set! ((with-module c-wrapper.c-ffi ref) ,@x) %v)
        %v))
    ((('with-module 'c-wrapper.c-ffi 'deref) x)
     `(let ((%v ,rhs))
        (set! ((with-module c-wrapper.c-ffi deref) ,x) %v)
        %v))
    (else
     #f)))

(define-maybe (%CONCAT-EXPR expr1 expr2)
  `(begin ,expr1 ,expr2))

(define-maybe (%FOR init test update body)
  (use-iterator-set! #t)
  `(call/cc (lambda (%break)
              ,init
              (let %continue ()
                ,(%IF test
                      `(begin
                         ,body
                         ,update
                         (%continue))
                      '(%break 0))))))

(define-maybe (%WHILE test statement)
  (use-iterator-set! #t)
  `(call/cc (lambda (%break)
              (let %continue ()
                ,(%IF test `(begin ,statement (%continue)) '(%break 0))))))

(define-maybe (%DO-WHILE test statement)
  (use-iterator-set! #t)
  `(call/cc (lambda (%break)
              (letrec ((%body (lambda () ,statement (%continue)))
                       (%continue (lambda ()
                                    ,(%IF test
                                          '(%body)
                                          '(%break 0)))))
                (%body)))))

(define (%CONTINUE)
  (use-jump-set! #t)
  '(%continue))

(define (%BREAK)
  (use-jump-set! #t)
  '(%break 0))

(define-maybe (%RETURN v)
  (use-return-set! #t)
  `(%return ,v))

(define-maybe (%QUOTE v)
  `(',v))

;; (define-maybe (%APPEND v1 v2)
;;   (append v1 v2))

;; (define-maybe (%COMPOSE-DECLARATOR d1 d2)
;;   (lambda (var)
;;     (d1 (d2 var))))

(define-maybe (%KEYWORD-ARG selector expr)
  `(',selector ,expr))

(define-maybe (%KEYWORD-ARG-WITHOUT-SELECTOR expr)
  (list : expr))

(define-maybe (%OBJC-MESSAGE-EXPR receiver args)
  `(,receiver ,@args))

(define-maybe (%SELECTOR selector)
  `(@selector ,selector))

;;
;; (define (external-declaration declaration-specifiers init-declarator-list)
;;   (parser-attribute-clear!)
;;   (if (eq? (car declaration-specifiers) 'TYPEDEF)
;;       (emit-typedef (make-type-decl-list (cdr declaration-specifiers) init-declarator-list))
;;       (for-each (lambda (init-declarator)
;;                   (let ((declaration (make-type-decl declaration-specifiers init-declarator)))
;;                     (emit-define-extern declaration)))
;;                 init-declarator-list)))

;; (define-maybe (parameter-declaration v)
;;   (parser-attribute-clear!)
;;   (let ((type (type-of v)))
;;     ;; ISO/IEC 9899:1999 6.7.5.3
;;     (when (pair? type)
;;       (case (car type)
;;         ((c-func) (set-car! type 'c-func-ptr))
;;         ((c-func-vaargs) (set-car! type 'c-func-vaargs-ptr))
;;         (else #f)))
;;     (and-let* ((name (name-of v)))
;;       (arg-pool-add! name))
;;     v))

;; (define (declaration specifiers declarator-list)
;;   (parser-attribute-clear!)
;;   (let ((var-list (make-type-decl-list specifiers declarator-list)))
;;     (for-each (lambda (var)
;;                 (arg-pool-add! (name-of var)))
;;               var-list)
;;     var-list))

(define (decl-keyword selector . typename-list)
  (cons (list (string-append (x->string selector)
                             (if (null? typename-list) "" ":")))
        typename-list))

(define (decl-enum identifier lst)
  (list 'ENUM (or identifier (gensym "%")) lst))

(define (decl-enumerator identifier expr)
  (cons identifier expr))

(define (combine-decl-keyword decl1 . rest)
  (let-optionals* rest ((decl2 #f))
    (if decl2
        (cons (append (car decl1) (car decl2))
              (append (cdr decl1) (cdr decl2)))
        decl1)))

(define (decl-objc-method ret-type decl-arg)
  (list (car decl-arg) (cons ret-type (cdr decl-arg))))

(define (decl-struct-or-union struct-or-union identifier decl-list)
  (list struct-or-union (or identifier (gensym "%")) decl-list))

(define (var-id)
  (make-type-decl '(id) (null-declarator)))

;;
;; moved to c-parser.c and c-parserlib.stub
;; (define-maybe (make-type-decl type-spec-list qualifier)
;;   (and-let* ((c-type (typespec->c-type ((with-module srfi-1 remove)
;;                                         (cut eq? 'TYPEDEF <>)
;;                                         type-spec-list))))
;;     (qualifier (vector c-type #f #f))))
                     
;; (define-inline (name-of v)
;;   (vector-ref v 1))

;; (define-inline (set-name! v name)
;;   (vector-set! v 1 name))

;; (define-inline (type-of v)
;;   (vector-ref v 0))

;; (define-inline (set-type! v type)
;;   (vector-set! v 0 type))

;; (define-inline (value-of v)
;;   (vector-ref v 2))

;; (define-inline (set-value! v val)
;;   (vector-set! v 2 val))

;; (define (identifier-declarator name)
;;   (lambda (var)
;;     (set-name! var name)
;;     var))

;; (define (array-declarator n)
;;   (lambda (var)
;;     (set-type! var `(c-array ,(type-of var) ,(and n (%INT n))))
;;     var))

;; (define (func-declarator args)
;;   (lambda (var)
;;     (set-type! var `(c-func ,(type-of var) (list ,@(map (lambda (arg)
;;                                                           `(list ',(name-of arg)
;;                                                                  ,(type-of arg)))
;;                                                         args))))
;;     var))

;; (define (func-vaargs-declarator args)
;;   (lambda (var)
;;     (set-type! var `(c-func-vaargs ,(type-of var) (list ,@(map (lambda (arg)
;;                                                                  `(list ',(name-of arg)
;;                                                                         ,(type-of arg)))
;;                                                                args))))
;;     var))

;; (define (ptr-declarator)
;;   (lambda (var)
;;     (let ((type (type-of var)))
;;       (define (%ptr-qualifier)
;;         (set-type! var `((with-module c-wrapper.c-ffi ptr) ,type)))
;;       (if (pair? type)
;;           (case (car type)
;;             ((c-func) (set-car! type 'c-func-ptr))
;;             ((c-func-vaargs) (set-car! type 'c-func-vaargs-ptr))
;;             (else
;;              (%ptr-qualifier)))
;;           (%ptr-qualifier))
;;       var)))

;; (define (bit-field-declarator n)
;;   (lambda (var)
;;     (set-type! var `(c-bit-field ,(type-of var) ,n))
;;     (unless (name-of var)
;;       (set-name! var (gensym "%")))
;;     var))

;; (define (init-value-declarator v)
;;   (lambda (var)
;;     (set-value! var v)
;;     var))

;; (define (compose-variable-attribute declarator)
;;   (let ((attr-list (parser-attribute)))
;;     (parser-attribute-clear!)
;;     (lambda (var)
;;       (let ((type (type-of var)))
;;         (set-type! var (let ((unsigned? (memq type '(<c-uchar> <c-ushort> <c-uint> <c-ulong> <c-ulonglong>)))
;;                              (size->mode (cut assoc-ref '((1 . QI) (2 . HI) (4 . SI) (8 . DI)) <>)))
;;                          (let %attribute-mode->c-type ((mode (cadr (or (assq 'mode attr-list)
;;                                                                        (assq '__mode__ attr-list)
;;                                                                        (list #f #f)))))
;;                            (case mode
;;                              ((QI __QI__ byte __byte__) (if unsigned?
;;                                                             '<c-uchar>
;;                                                             '<c-char>))
;;                              ((HI __HI__) (if unsigned?
;;                                               '<c-ushort>
;;                                               '<c-short>))
;;                              ((SI __SI__) (if unsigned?
;;                                               '<c-uint>
;;                                               '<c-int>))
;;                              ((DI __DI__) (if unsigned?
;;                                               '<c-ulonglong>
;;                                               '<c-longlong>))
;;                              ((SF __SF__) '<c-float>)
;;                              ((DF __DF__) '<c-double>)
;;                              ((word __word__)
;;                               (%attribute-mode->c-type (size->mode (word-size))))
;;                              ((pointer __pointer__)
;;                               (%attribute-mode->c-type (size->mode (pointer-size))))
;;                              (else
;;                               type)))))
;;         (declarator var)))))
    
;; (define (make-type-decl-list type-spec-list qualifiers)
;;   (map (cut make-type-decl type-spec-list <>) qualifiers))

;; (define (typespec->c-type type)
;;   (match type
;;     (('char) '<c-char>)
;;     (('SIGNED 'char) '<c-char>)
;;     (('UNSIGNED 'char) '<c-uchar>)
;;     (('short) '<c-short>)
;;     (('short 'int) '<c-short>)
;;     (('short 'UNSIGNED 'int) '<c-ushort>)
;;     (('SIGNED 'short) '<c-short>)
;;     (('SIGNED 'short 'int) '<c-short>)
;;     (('UNSIGNED 'short) '<c-ushort>)
;;     (('UNSIGNED 'short 'int) '<c-ushort>)
;;     (('int) '<c-int>)
;;     (('SIGNED 'int) '<c-int>)
;;     (('SIGNED) '<c-int>)
;;     (('UNSIGNED 'int) '<c-uint>)
;;     (('UNSIGNED) '<c-uint>)
;;     (('long) '<c-long>)
;;     (('long 'int) '<c-long>)
;;     (('SIGNED 'long) '<c-long>)
;;     (('SIGNED 'long 'int) '<c-long>)
;;     (('long 'SIGNED 'int) '<c-long>)
;;     (('UNSIGNED 'long) '<c-ulong>)
;;     (('UNSIGNED 'long 'int) '<c-ulong>)
;;     (('long 'UNSIGNED 'int) '<c-ulong>)
;;     (('long 'long) '<c-longlong>)
;;     (('long 'long 'int) '<c-longlong>)
;;     (('SIGNED 'long 'long) '<c-longlong>)
;;     (('SIGNED 'long 'long 'int) '<c-longlong>)
;;     (('long 'long 'SIGNED 'int) '<c-longlong>)
;;     (('UNSIGNED 'long 'long) '<c-ulonglong>)
;;     (('UNSIGNED 'long 'long 'int) '<c-ulonglong>)
;;     (('long 'long 'UNSIGNED 'int) '<c-ulonglong>)
;;     (('float) '<c-float>)
;;     (('double) '<c-double>)
;;     (('long 'double) '<c-longdouble>)
;;     (('void) '<c-void>)
;;     (('_Bool) '<c-int>)
;;     (('__builtin_va_list) '((with-module c-wrapper.c-ffi ptr) <c-void>))
;;     ((('STRUCT tagname (elem-alist ...)))
;;      (emit-init-struct tagname elem-alist)
;;      `(c-struct ',tagname))
;;     ((('STRUCT tagname #f))
;;      (emit-alloc-struct tagname)
;;      `(c-struct ',tagname))
;;     ((('UNION tagname (elem-alist ...)))
;;      (emit-init-union tagname elem-alist)
;;      `(c-union ',tagname))
;;     ((('UNION tagname #f))
;;      (emit-alloc-union tagname)
;;      `(c-union ',tagname))
;;     ((('ENUM tagname (enum-alist ...)))
;;      (emit-define-enum tagname enum-alist)
;;      `(c-enum ',tagname))
;;     (((? symbol? x))
;;      (c-type->class-symbol x))
;;     (else
;;      #f)))

;;;
;; (define (emit-definition name define-list . rest)
;;   (let-optionals* rest ((dependent-symbols define-list))
;;     (if (import-cond)
;;         (let ((pair (enqueue-code define-list #f)))
;;           (enqueue-import-pool name (cons pair dependent-symbols))
;;           (when (or (hash-table-exists? (imported-pool) name)
;;                     (need-import? name))
;;             (imp-sym name)))
;;         (begin
;;           (enqueue-code define-list #t)
;;           (when (and (export?) name)
;;             (enqueue-code `(export ,name) #t))))))

;; (define (make-member-alist elem-list)
;;   (map (lambda (elem)
;;          `(cons ',(name-of elem) ,(type-of elem)))
;;        elem-list))

;; (define (emit-alloc-struct tagname)
;;   (unless (hash-table-exists? (struct-pool) tagname)
;;     (hash-table-put! (struct-pool) tagname #t)
;;     (emit-definition `(c-struct ',tagname) `(define-c-struct ,tagname))))

;; (define (emit-alloc-struct tagname)
;;   (unless (hash-table-exists? (struct-pool) tagname)
;;     (hash-table-put! (struct-pool) tagname #t)
;;     (defchunk-dict-set-typename! tagname
;;       (make-defchunk 'alloc-struct
;;                      tagname
;;                      (list (c-struct-symbol tagname))
;;                      `(define-c-struct ,tagname)))))

;; (define (emit-init-struct tagname member-list)
;;   (emit-alloc-struct tagname)
;;   (emit-definition `(c-struct ',tagname)
;;                    `(init-c-struct! (c-struct ',tagname)
;;                                     (list ,@(make-member-alist member-list)))))

;; (define (emit-init-struct tagname member-list)
;;   (emit-alloc-struct tagname)
;;   (defchunk-dict-set-typename! tagname
;;     (make-defchunk 'init-struct
;;                    tagname
;;                    (list (c-struct-symbol tagname))
;;                    `(init-c-struct! (c-struct ',tagname) (list ,@(make-member-alist member-list))))))

;; (define (emit-alloc-union tagname)
;;   (unless (hash-table-exists? (union-pool) tagname)
;;     (hash-table-put! (union-pool) tagname #t)
;;     (emit-definition `(c-union ',tagname) `(define-c-union ,tagname))))

;; (define (emit-alloc-union tagname)
;;   (unless (hash-table-exists? (union-pool) tagname)
;;     (hash-table-put! (union-pool) tagname #t)
;;     (defchunk-dict-set-typename! tagname
;;       (make-defchunk 'alloc-union
;;                      tagname
;;                      (list (c-union-symbol tagname))
;;                      `(define-c-union ,tagname)))))

;; (define (emit-init-union tagname member-list)
;;   (emit-alloc-union tagname)
;;   (emit-definition `(c-union ',tagname)
;;                  `(init-c-union! (c-union ',tagname)
;;                                  (list ,@(make-member-alist member-list)))))

;; (define (emit-init-union tagname member-list)
;;   (emit-alloc-union tagname)
;;   (defchunk-dict-set-typename! tagname
;;     (make-defchunk 'init-union tagname
;;                    (list (c-union-symbol tagname))
;;                    `(init-c-union! (c-union ',tagname) (list ,@(make-member-alist member-list))))))

;; (define (emit-define-enum tagname enum-alist)
;;   (fold (lambda (p prev)
;;           (let ((v (or (cdr p)
;;                        (if (number? prev)
;;                            (+ prev 1)
;;                            `(+ (scm-cast ,prev) 1)))))
;;             (register-identifier (car p) v)
;;             (emit-definition (car p) `((with-module c-wrapper define-enum) ,(car p) ,v))
;;             v))
;;         -1
;;         enum-alist)
;;   (emit-definition `(c-enum ',tagname)
;;                  `(init-c-enum! (c-enum ',tagname)
;;                                 (list ,@(map car enum-alist)))))

;; (define (emit-define-enum tagname enum-alist)
;;   (let ((prev -1))
;;     (for-each (lambda (p)
;;                 (let ((v (or (cdr p)
;;                              (if (number? prev)
;;                                  (+ prev 1)
;;                                  `(+ (scm-cast ,prev) 1)))))
;;                   (register-identifier (car p) v)
;;                   (defchunk-dict-set-identifier! (car p)
;;                     (make-defchunk 'define-enum (car p) (list (car p)) `((with-module c-wrapper define-enum) ,(car p) ,v)))
;;                   (set! prev v)))
;;               enum-alist)))

;; (define (emit-typedef var-list)
;;   (for-each (lambda (v)
;;               (let ((obj (type-of v))
;;                     (sym (c-type->class-symbol (name-of v))))
;;                 (emit-definition sym `(define ,sym ,obj)))
;;               (install-type (name-of v)))
;;             var-list))

;; (define (emit-typedef var-list)
;;   (for-each (lambda (v)
;;               (let* ((obj (type-of v))
;;                      (c-type (name-of v))
;;                      (sym (c-type->class-symbol c-type)))
;;                 (defchunk-dict-set-typename! c-type
;;                   (make-defchunk 'typedef
;;                                  c-type
;;                                  (list sym)
;;                                  `(define ,sym ,obj)))
;;                 (install-type c-type)))
;;             var-list))

;; (define (emit-define-inline declaration-specifiers declarator function-body)
;;   (define (make-bindings name-list type-list)
;;     (let loop ((bindings '())
;;                (i 0)
;;                (name-rest name-list)
;;                (type-rest type-list))
;;       (if (null? name-rest)
;;           (reverse bindings)
;;           (loop (cons `(,(car name-rest) ((with-module c-wrapper.c-ffi cast) ,(car type-rest)
;;                                           (list-ref %args ,i)))
;;                       bindings)
;;                 (+ i 1)
;;                 (cdr name-rest)
;;                 (cdr type-rest)))))
;;   (let* ((declaration (make-type-decl declaration-specifiers declarator))
;;          (c-type (type-of declaration))
;;          (identifier (name-of declaration)))
;;     (match c-type
;;       (('c-func ret-type ('list ('list ('quote names) types) ...))
;;        (register-identifier identifier
;;                             `(lambda args
;;                                (apply ,identifier args)))
;;        (emit-definition identifier
;;                         `((with-module c-wrapper define-inline-cfunc)
;;                           ,identifier ,ret-type ,names ,types
;;                           ,(or function-body
;;                                `(errorf "~a is not supported. Try cwcompile if you want to use." ,identifier)))))
;;       (('c-func-ptr ret-type ('list ('list ('quote names) types) ...))
;;        (warning "'~a' is ignored. It appears in a function definition, but it is a pointer of a function in reality." identifier))
;;       (((? (lambda (v) (memq v '(c-func-vaargs-ptr func-vaargs))) v)
;;         ret-type ('list ('list ('quote names) types) ...))
;;        (warning "The inline function '~a' is ignored, because it gets variable arguments" identifier))
;;       (else
;;        (warning "'~a' is ignored, it is not a function." identifier)))))

;; (define (emit-define-inline declaration-specifiers declarator function-body)
;;   (let* ((declaration (make-type-decl declaration-specifiers declarator))
;;          (c-type (type-of declaration))
;;          (identifier (name-of declaration)))
;;     (defchunk-dict-set-identifier! identifier
;;       (make-defchunk 'define-inline
;;                      identifier
;;                      (list identifier)
;;                      (vector declaration c-type identifier function-body)))
;;     (register-identifier identifier
;;                          `(lambda args
;;                             (apply ,identifier args)))))

;; (define (emit-define-extern declaration)
;;   (and-let* ((c-type (type-of declaration))
;;              (identifier (name-of declaration)))
;;     (when (or (ignore-dlsym-check?)
;;               (c-lookup-symbol identifier))
;;       (and-let* ((obj (match c-type
;;                         (('c-func ret-type ('list ('list _ arg-type) ...))
;;                          `(make-c-func ',identifier
;;                                        ,ret-type
;;                                        (list ,@arg-type)))
;;                         (('c-func-vaargs ret-type ('list ('list _ arg-type) ...))
;;                          `(make-c-func-vaargs ',identifier
;;                                               ,ret-type
;;                                               (list ,@arg-type)))
;;                         (else
;;                          `(make-c-var ',identifier ,c-type)))))
;;         (register-identifier identifier obj)
;;         (emit-definition identifier `(define ,identifier ,obj))))))

;; (define (emit-define-extern declaration)
;;   (and-let* ((c-type (type-of declaration))
;;              (identifier (name-of declaration)))
;;     (when (or (ignore-dlsym-check?)
;;               (c-lookup-symbol identifier))
;;       (let ((obj (match c-type
;;                    (('c-func ret-type ('list ('list _ arg-type) ...))
;;                     `(make-c-func ',identifier
;;                                   ,ret-type
;;                                   (list ,@arg-type)))
;;                    (('c-func-vaargs ret-type ('list ('list _ arg-type) ...))
;;                     `(make-c-func-vaargs ',identifier
;;                                          ,ret-type
;;                                          (list ,@arg-type)))
;;                    (else
;;                     `(make-c-var ',identifier ,c-type)))))
;;         (defchunk-dict-set-identifier! identifier
;;           (make-defchunk 'define-extern
;;                          identifier
;;                          (list identifier)
;;                          `(define ,identifier ,obj)))
;;         (register-identifier identifier obj)))))

;; (define (emit-define-objc-class classname-list)
;;   (for-each (lambda (classname)
;;               (when classname
;;                 (install-type classname)
;;                 (let ((sym (c-type->class-symbol classname)))
;;                   (emit-definition sym `(define ,sym (c-struct 'objc_object))))
;;                 (emit-definition classname
;;                                `(define ,classname
;;                                   (objc-lookup-class ',classname)))))
;;             classname-list))

;; (define (emit-define-objc-class classname-list)
;;   (for-each (lambda (classname)
;;               (when classname
;;                 (install-type classname)
;;                 (let ((sym (c-type->class-symbol classname)))
;;                   (defchunk-dict-set-typename! classname
;;                     (make-defchunk 'alloc-objc-class
;;                                    classname
;;                                    (list sym)
;;                                    `(define ,sym (c-struct 'objc_object)))))
;;                 (defchunk-dict-set-typename! classname
;;                   (make-defchunk 'init-objc-class
;;                                  classname
;;                                  (list classname)
;;                                  `(define ,classname
;;                                     (objc-lookup-class ',classname))))))
;;             classname-list))

;; (define (emit-objc-method keywords type-list)
;;   (let ((name (apply string-append keywords)))
;;     (emit-definition #f
;;                    `(objc-register-method ,name
;;                                           (list ,@(map type-of type-list))))))

;; (define (emit-objc-method keywords type-list)
;;   (let ((name (apply string-append keywords)))
;;     (make-defchunk 'define-objc-method
;;                    #f
;;                    '()
;;                    `(objc-register-method ,name (list ,@(map type-of type-list))))))

;; (define (emit-define-cmacro name body)
;;   (emit-definition name `(define ,name ,body)))

;; (define (emit-define-cmacro name body)
;;   (defchunk-dict-set-identifier! name
;;     (make-defchunk 'define-cmacro
;;                    name
;;                    (list name)
;;                    `(define ,name ,body))))

;; (define (emit-define-cfunclike-macro name args body)
;;   (emit-definition name
;;                    `((with-module c-wrapper define-cfunclike-macro)
;;                      ,name ,args ,body)))

;; (define (emit-define-cfunclike-macro name args body)
;;   (defchunk-dict-set-identifier! name
;;     (make-defchunk 'define-cfunclike-macro
;;                    name
;;                    (list name)
;;                    `((with-module c-wrapper define-cfunclike-macro)
;;                      ,name ,args ,body))))


(define (make-define-inline-expr defchunk)
  (let* ((vec (defchunk-object defchunk))
         (declaration (vector-ref vec 0))
         (c-type (vector-ref vec 1))
         (identifier (vector-ref vec 2))
         (function-body (vector-ref vec 3)))
    ;(display identifier (current-error-port))
    ;(display c-type (current-error-port))
    ;(newline (current-error-port))
    (match c-type
      (('c-func ret-type ('list ('list ('quote names) types) ...))
       `((with-module c-wrapper define-inline-cfunc)
         ,identifier ,ret-type ,names ,types
         ,(or function-body
              `(errorf "~a is not supported. Try cwcompile if you want to use." ,identifier))))
      (('c-func-vaargs ret-type ('list ('list ('quote names) types) ...))
       `((with-module c-wrapper define-inline-cfunc)
         ,identifier ,ret-type ,names ,types
         ,(or function-body
              `(errorf "~a is not supported. Try cwcompile if you want to use." ,identifier))))
      (('c-func-ptr ret-type ('list ('list ('quote names) types) ...))
       (warning "'~a' is ignored. It appears in a function definition, but it is a pointer of a function in reality." identifier)
       (lambda ())
       )
      (((? (lambda (v) (memq v '(c-func-vaargs-ptr func-vaargs))) v)
        ret-type ('list ('list ('quote names) types) ...))
       (warning "The inline function '~a' is ignored, because it gets variable arguments" identifier)
       (lambda ())
       )
      (else
       (warning "'~a' is ignored, it is not a function." identifier)
       (lambda ())
       ))))
  
;; (define (defchunk->sexpr defchunk)
;;   (case (defchunk-type defchunk)
;;     ((define-inline)
;;      (make-define-inline-expr defchunk))
;;     (else
;;      (defchunk-object defchunk))))
     
;;;
(define (call-with-gcc-io include-dirs headers options proc . rest)
  (let ((gcc-error #f))
    (let-keywords* rest ((show-define? #t))
      (call-with-process-io (cpp-command include-dirs headers options show-define?)
        proc
        :on-abnormal-exit (lambda (process)
                            (format (current-error-port) (make-error-message "GCC exitted abnormally"))
                            (newline (current-error-port))
                            (set! gcc-error (format "process ~a exitted abnormally with exit code ~a"
                                                    (process-pid process)
                                                    (process-exit-status process))))))
    (when gcc-error
      (error gcc-error))))
    

(define (cpp-command include-dirs headers options . rest)
  (let-optionals* rest ((show-define? #t))
    (string-join (append (list GCC "-E -U__BLOCKS__")
                         (if show-define? 
                             '("-dD")
                             '())
                         options
                         (map (cut format "-I~a" <>) include-dirs)
                         (map (cut format "-include ~a" <>) headers)
                         (list "-"))
                 " ")))

(define (report-parse-error msg . args)
  (errorf msg))

(define (do-parse initializer finalizer error-reporter)
  (last-token-set! #f)
  (unwind-protect
   (begin
     (initializer)
     (guard (e ((<message-condition> e)
                (let ((errmsg (make-error-message (condition-ref e 'message))))
                  (print-current-line)
                  (display errmsg (current-error-port))
                  (newline (current-error-port))
                  (raise e)))
               (else
                (let ((errmsg (make-error-message e)))
                  (print-current-line)
                  (display errmsg (current-error-port))
                  (newline (current-error-port))
                  (raise e))))
       (c-grammar error-reporter)))
   (finalizer)))
  
(define (parse-from-port port error-reporter)
  (do-parse (lambda ()
              (set-input-port! port)
              (start-macro-reset!))
            free-input-port!
            error-reporter))

;;;
;; (define (parse-macro-body name args body-str)
;;   (init-macro-parser-state)
;;   (and-let* ((body (and body-str
;;                         (begin
;;                           (all-referenced-info-clear!)
;;                           (arg-pool-set! (or args '()))
;;                           (start-macro-set!)
;;                           (last-token-set! #f)
;;                           (set-input-string! (string-append body-str ";\n"))
;;                           (c-grammar #f)
;;                           (macro-body)))))
;;     (cond
;;      ((or (and (not (use-iterator?)) (use-jump?))
;;           (use-return?))
;;       #f)
;;      ((not args)
;;       (match body
;;         (('scm-cast v)
;;          (unless (eq? name v)
;;            (let ((new-body `(c-delay (lambda () (c-cast ,v)) ',v)))
;;              (emit-define-cmacro name new-body))))
;;         (else
;;          (unless (eq? name body)
;;            (emit-define-cmacro name body)))))
;;      (args
;;       (emit-define-cfunclike-macro name args body))
;;      (else
;;       #f))))

;; (define (parse-macro-code in macro-list)
;;   (define (skip line)
;;     (cond
;;      ((eof-object? line)
;;       #f)
;;      ((eq? (string-size line) 0)
;;       (skip (read-line in #t)))
;;      ((not (eq? (string-byte-ref line 0) 35)) ;; '#' != 35 (ASCII)
;;       (skip (read-line in #t)))
;;      ((string-incomplete? line)
;;       (skip (read-line in #t)))
;;      ((string=? line "# 1 \"<stdin>\"")
;;       (parse (read-line in #t)))
;;      (else
;;       (skip (read-line in #t)))))
;;   (define (parse line)
;;     (cond
;;      ((eof-object? line)
;;       #f)
;;      ((null? macro-list)
;;       (error "[bug] lost macro body"))
;;      (else
;;       (let ((pos&name&args (cdr (pop! macro-list))))
;;         (filename-set! (caar pos&name&args))
;;         (lineno-set! (cdar pos&name&args))
;;         (parse-macro-body (cadr pos&name&args)
;;                           (cddr pos&name&args)
;;                           line))
;;       (parse (read-line in #t)))))
;;   ;; skip the first line '# 1 "<stdin>"'
;;   (read-line in #t)
;;   (skip (read-line in #t)))
  
;; (define (parse-macro include-dirs headers options)
;;   (unwind-protect
;;    (guard (e ((<message-condition> e)
;;               (let ((errmsg (make-error-message (condition-ref e 'message))))
;;                 (print-current-line)
;;                 (display errmsg (current-error-port))
;;                 (newline (current-error-port))
;;                 (raise e)))
;;              (else
;;               (let ((errmsg (make-error-message e)))
;;                 (print-current-line)
;;                 (display errmsg (current-error-port))
;;                 (newline (current-error-port))
;;                 (raise e))))
;;      (call-with-gcc-io include-dirs headers options
;;                        (lambda (in out)
;;                          (let ((identifier-queue (make-queue)))
;;                            (for-each (lambda (macro-def)
;;                                        (display (car macro-def) out)
;;                                        (newline out)
;;                                        (enqueue! identifier-queue (cdr macro-def)))
;;                                      (queue->list (macro-queue)))
;;                            (close-output-port out)
;;                            (parse-macro-code in identifier-queue)))
;;                        :show-define? #f))
;;    (start-macro-reset!)))

(define (parse-macro include-dirs headers options)
  (unwind-protect
   (guard (e ((<message-condition> e)
              (let ((errmsg (make-error-message (condition-ref e 'message))))
                (print-current-line)
                (display errmsg (current-error-port))
                (newline (current-error-port))
                (raise e)))
             (else
              (let ((errmsg (make-error-message e)))
                (print-current-line)
                (display errmsg (current-error-port))
                (newline (current-error-port))
                (raise e))))
     (call-with-gcc-io include-dirs headers options
                       (lambda (in out)
                         (let ((macro-list (queue->list (macro-queue))))
                           (for-each (lambda (macro-def)
                                       (display (car macro-def) out)
                                       (newline out))
                                     macro-list)
                           (close-output-port out)
                           (parse-macro-code in macro-list)))
                       :show-define? #f))
   (start-macro-reset!)))

(define (parse-source-code)
  (parse-from-port (current-input-port)
                   report-parse-error))

(define (parse-source include-dirs headers options)

  ;; ***** for debug *****
  ;(call-with-gcc-io include-dirs headers options
  ;                  (lambda (in out)
  ;                    (close-output-port out)
  ;                    (call-with-output-file
  ;                        (string-append "c:\\work\\c-wrapper-log\\cpp_output_"
  ;                                       (number->string (sys-time))
  ;                                       ".txt")
  ;                      (lambda (out) (copy-port in out)))))

  (call-with-gcc-io include-dirs headers options
                    (lambda (in out)
                      (close-output-port out)
                      (with-input-from-port in
                        parse-source-code))))

(define (need-import? defchunk import-cond)
  (let ((id (defchunk-identifier defchunk)))
    (cond
     ((regexp? import-cond)
      (rxmatch import-cond (symbol->string id)))
     ((is-a? import-cond <collection>)
      (find (cut need-import? defchunk <>) import-cond))
     ((symbol? import-cond)
      (eq? id import-cond))
     ((string? import-cond)
      (string=? (symbol->string id) import-cond))
     ((procedure? import-cond)
      (apply import-cond (list (defchunk-filename defchunk) id)))
     (else
      (errorf "~s can't be used for :import argument." import-cond)))))

(define (c-parse include-dirs headers options import-arg export? sandbox hides)
  (with-parse-context
   (lambda ()
     (parse-source include-dirs headers options)
     (parse-macro include-dirs headers options)

     (let ((export-syms
            (if import-arg
                (let ((syms '()))
                  (defchunk-dict-set-mark!
                    (lambda (defchunk)
                      (let ((result (need-import? defchunk import-arg)))
                        (when result
                          (for-each (lambda (sym)
                                      (push! syms sym))
                                    (defchunk-symbol-list defchunk)))
                        result)))
                  syms)
                #f)))
       (defchunk-dict-for-each (if (module? sandbox)
                                   #f
                                   sandbox)
         (not import-arg))
       (if (module? sandbox)
           (bridge-symbols sandbox export-syms hides)
           (sandbox (cons 'export
                          ((with-module srfi-1 remove) (cut memq <> hides) (or export-syms
                                                                               (defchunk-dict-all-symbols))))))))))

(provide "c-wrapper/c-parser")

