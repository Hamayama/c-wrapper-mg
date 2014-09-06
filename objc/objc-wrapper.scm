;; -*- coding: utf-8; mode: scheme -*-
;;
;; objc-wrapper.scm - A generic wrapper for Objective-C libraries
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

(define-module objc-wrapper
  (use util.match)
  
  (extend c-wrapper c-wrapper.objc-ffi)

  (export define-objc-class
          define-objc-method)
  )

(select-module objc-wrapper)

(define-syntax define-objc-class
  (syntax-rules ()
    ((_ class super-class)
     (define class
       (cast <id> (ptr (objc-make-class 'class (cast <Class> super-class))))))))

(define-macro (define-objc-method class ret-type lst . body)
  (receive (method-name arg-types arg-vars)
      (let loop ((rest lst)
                 (name-parts '())
                 (arg-types '())
                 (arg-vars '()))
        (match rest
         (()
          (values (string-append (string-join (reverse name-parts) ":")
                                 (if (< 1 (length name-parts)) ":" ""))
                  (reverse arg-types)
                  (reverse arg-vars)))
         ((('quote x) _ ...)
          (loop (cdr rest) (cons (x->string x) name-parts) arg-types arg-vars))
         (((? keyword? x) _ ...)
          (loop (cdr rest) (cons (x->string x) name-parts) arg-types arg-vars))
         (((? symbol? x) _ ...)
          (loop (cdr rest) name-parts (cons '<id> arg-types) (cons x arg-vars)))
         (((var type) _ ...)
          (loop (cdr rest) name-parts (cons type arg-types) (cons var arg-vars)))
         (else
          (errorf "Invalid arg spec ~s" lst))))
    (let ((sel (gensym)))
      `(begin
         (objc-add-method ,class ,method-name ,ret-type (list ,@arg-types)
                          (lambda (self ,sel ,@arg-vars)
                            (let ((super (make-super ,class self)))
                              ,@body)))
         (objc-register-method ,method-name (list ,ret-type ,@arg-types))))))

(provide "objc-wrapper")
