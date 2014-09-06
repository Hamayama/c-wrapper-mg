;; -*- coding: utf-8; mode: scheme -*-
;;
;; c-wrapper.scm - A generic wrapper for C libraries
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

(define-module c-wrapper
  (use srfi-1)
  (use srfi-13)
  (use gauche.process)
  (use gauche.parameter)
  (use gauche.sequence)
  (use file.util)
  (use util.match)
  (use gauche.vport)
  (use gauche.uvector)
  (use gauche.regexp)
  (use gauche.config)
  (use util.queue)
  (use c-wrapper.config)
  (use c-wrapper.c-parser)

  (extend c-wrapper.c-ffi)

  (export c-include
          c-load)

  )

(select-module c-wrapper)

(define-syntax c-include
  (syntax-rules ()
    ((_ headers . args)
     (%c-include (current-module) headers . args))))

(define (compiled-lib-exist? compiled-lib)
  (and compiled-lib
       (find-file-in-paths (path-swap-extension compiled-lib
                                                (gauche-config "--so-suffix"))
                           :paths *dynamic-load-path*
                           :pred file-is-readable?)))

(define make-sandbox
  (let ((cnt 0))
    (lambda (curmod module)
      (cond
       ((module? module)
        module)
       ((eq? module #t)
        (inc! cnt)
        (let ((m (make-module (string->symbol (format "c-wrapper.sandbox.~a" cnt)))))
          (eval '(export-all) m)
          m))
       ((eq? module #f)
        curmod)
       (else
        (errorf "<module>, #t or #f required, but got ~s" module))))))

(define sandbox-module (make-parameter #f))

(define (%c-include curmod headers . args)
  (let-keywords* args ((include-dirs '())
                       (option #f)
                       (import-arg :import #f)
                       (compiled-lib #f)
                       (module #t)
                       (export? #f)
                       (output #f)
                       (hide-symbols '()))
    (when (eq? module #t)
      (set! export? #t))
    (parameterize ((sandbox-module (make-sandbox curmod module)))
      (cond
       ((compiled-lib-exist? compiled-lib)
        (dynamic-load compiled-lib)
        (when module
          (eval `(import ,(module-name (sandbox-module))) curmod)))
       (else
        (let ((output-list '()))
          (c-parse (if (list? include-dirs)
                       include-dirs
                       (list include-dirs))
                   (if (list? headers)
                       headers
                       (list headers))
                   (if option
                       (string-split option #[\s])
                       '())
                   import-arg
                   export?
                   (if output
                       (lambda (expr)
                         (push! output-list expr))
                       (sandbox-module))
                   hide-symbols)
          (if output
              (call-with-output-file output
                (lambda (out)
                  (for-each (lambda (expr)
                              (write expr out)
                              (newline out))
                            (reverse output-list))))
              (when module
                (eval `(import ,(module-name (sandbox-module))) curmod)))))))))

(define (append-cmd str cmd)
  (string-join (append (list str)
                       (list (cond
                              ((list? cmd)
                               (apply string-append
                                      (map process-output->string
                                           cmd)))
                              (cmd
                               => process-output->string)
                              (else ""))))
               " "))

(define-macro (c-load headers . keywords)
  (let-keywords* keywords ((cflags "")
                           (cflags-cmd #f)
                           (cppflags "")
                           (cppflags-cmd #f)
                           (ldflags "")
                           (ldflags-cmd #f)
                           (libs "")
                           (libs-cmd #f)
                           (compiled-lib #f)
                           (import-arg :import #f)
                           (module #t)
                           (export? #f)
                           (output #f)
                           (hide-symbols '()))
    (cond
     ((compiled-lib-exist? compiled-lib)
      `(begin
         ,(if force-load-library-when-compiledlib-exists?
              `(c-ld ,(string-join (list (append-cmd ldflags ldflags-cmd)
                                         (append-cmd libs libs-cmd))
                                   " "))
              #f)
         ((with-module c-wrapper %c-include) (current-module) '() :compiled-lib ,compiled-lib :module ,module)))
     (else
      (let* ((cpp-option (append-cmd cppflags cppflags-cmd))
             (ld-option (string-join (list (append-cmd ldflags ldflags-cmd)
                                           (append-cmd libs libs-cmd))
                                     " ")))
        `(begin
           (c-ld ,ld-option)
           (c-include ,headers :option ,cpp-option :import ,import-arg :output ,output :module ,module :export? ,export? :hide-symbols ,hide-symbols)))))))

(define-syntax define-enum
  (syntax-rules ()
    ((_ name value)
     (define name value))))

(define-macro (define-inline-cfunc name ret-type arg-names arg-types body)
  (define (make-bindings name-list type-list)
    (let loop ((bindings '())
               (i 0)
               (name-rest name-list)
               (type-rest type-list))
      (if (null? name-rest)
          (reverse bindings)
          (loop (cons `(,(car name-rest) (cast ,(car type-rest)
                                               (list-ref %args ,i)))
                      bindings)
                (+ i 1)
                (cdr name-rest)
                (cdr type-rest)))))
  `(define (,name . %args)
     (scm-cast (cast ,ret-type
                     (let ,(make-bindings arg-names arg-types)
                       ,body)))))

(define-syntax define-cfunclike-macro
  (syntax-rules ()
    ((_ name args body)
     (define-syntax name
       (syntax-rules ()
         ((_ . args) body))))))

(provide "c-wrapper")


