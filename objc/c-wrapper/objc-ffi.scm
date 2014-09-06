;; -*- coding: utf-8; mode: scheme -*-
;;
;; objc-ffi.scm 
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

(define-module c-wrapper.objc-ffi
  (use c-wrapper)
  (use file.util)
  (use srfi-1)
  (extend c-wrapper.c-ffi)
  
  (c-load '("stdlib.h" "objc/objc-runtime.h" "objc/objc-class.h")
          :libs "-lobjc"
          :module #f
          :import '(id
                    SEL
                    objc_lookUpClass
                    objc_class
                    objc_addClass
                    objc_method
                    objc_method_list
                    objc_super
                    sel_registerName
                    Class
                    CLS_CLASS
                    CLS_META
                    class_addMethods
                    nil
                    malloc)
          :compiled-lib "objc-ffilib")

  (export @ 
          @selector
          c-load-framework
          objc-lookup-class
          objc-register-method
          objc-add-method
          make-super
          <id>
          <SEL>)
  )

(select-module c-wrapper.objc-ffi)

(with-module c-wrapper.c-ffi
  (set! %c-load-framework
        (lambda (name)
          (or (and-let* ((filename (find-file-in-paths
                                    name :paths (map (cut string-append 
                                                          <>
                                                          name
                                                          ".framework/")
                                                     (list (build-path 
                                                            (sys-getenv "HOME")
                                                            "Library/Frameworks/")
                                                           "/Library/Frameworks/"
                                                           "/System/Library/Frameworks/"))
                                    :pred file-is-readable?)))
                (c-load-library filename))
              (errorf "framework ~a is not found" name)))))

(define c-load-framework (with-module c-wrapper.objc-ffi %c-load-framework))

(define method-pool (make-hash-table 'string=?))
(define ivar-pool (make-hash-table 'equal?))

(define (@ str)
  (objc-string <id> str)  )

(define (@selector name)
  (sel_registerName (x->string name)))

(define (encode-objc-type c-type)
  (format "~a~a"
          (cond
           ((equal? c-type <c-char>)
            "c")
           ((equal? c-type <c-int>)
            "i")
           ((equal? c-type <c-short>)
            "s")
           ((equal? c-type <c-long>)
            "l")
           ((equal? c-type <c-longlong>)
            "q")
           ((equal? c-type <c-uchar>)
            "C")
           ((equal? c-type <c-uint>)
            "I")
           ((equal? c-type <c-ushort>)
            "S")
           ((equal? c-type <c-ulong>)
            "L")
           ((equal? c-type <c-ulonglong>)
            "Q")
           ((equal? c-type <c-float>)
            "f")
           ((equal? c-type <c-double>)
            "d")
           ((equal? c-type <c-void>)
            "v")
           ((equal? c-type <id>)
            "@")
           ((equal? c-type <Class>)
            "#")
           ((equal? c-type <SEL>)
            ":")
           ((is-a? c-type <c-array-meta>)
            (format "[~a]" (encode-objc-type (element-type-of c-type))))
           ((is-a? c-type <c-struct-meta>)
            (format "{~a}"
                    (string-append (map (lambda (alist)
                                          (format "~a=~a"
                                                  (car alist)
                                                  (encode-objc-type (cdr alist))))
                                        (decl-alist-of c-type)))))
           ((is-a? c-type <c-union-meta>)
            (format "(~a)"
                    (string-append (map (lambda (alist)
                                          (format "~a"
                                                  (encode-objc-type (cdr alist))))
                                        (decl-alist-of c-type)))))
           ((bit-field? c-type)
                   "b")
                  ((is-a? c-type <c-ptr-meta>)
                   (format "^~a" (encode-objc-type (orig-c-type-of c-type))))
                  (else
                   "?"))
          (cond
           ((bit-field? c-type)
            (bits-of c-type))
           (else
            (c-sizeof c-type)))))
            
                           
(define (objc-lookup-class name)
  (objc_lookUpClass (symbol->string name)))

(define (objc-register-method name type-list)
  (hash-table-put! method-pool name type-list))

(define (nil? x)
  (eq? (ref x) nil))

(define (objc-make-class name super-class-ptr)
  (unless (nil? (objc-lookup-class name))
    (errorf "Objective-C class '~a' is already exists." name))
  (let ((root-class-ptr (do ((class-ptr super-class-ptr
                                        (ref (deref class-ptr) 'super_class)))
                            ((nil? (ref (deref class-ptr) 'super_class))
                             class-ptr)))
        (new-class (deref (cast <Class>
                                (malloc (c-sizeof (c-struct 'objc_class))))))
        (meta-class (deref (cast <Class>
                                 (malloc (c-sizeof (c-struct 'objc_class)))))))
    (set! (ref new-class 'isa) (ptr meta-class))
    (set! (ref new-class 'info) CLS_CLASS)
    (set! (ref meta-class 'info) CLS_META)
    
    (set! (ref new-class 'name) (symbol->string name))
    (set! (ref meta-class 'name) (symbol->string name))
    
    (set! (ref new-class 'methodLists) (make-null-ptr))
    (set! (ref meta-class 'methodLists) (make-null-ptr))
    
    (set! (ref new-class 'super_class) super-class-ptr)
    (set! (ref meta-class 'super_class) (ref (deref super-class-ptr) 'isa))
    (set! (ref meta-class 'isa) (ref (deref root-class-ptr) 'isa))
    
    (set! (ref new-class 'instance_size) (ref (deref super-class-ptr)
                                              'instance_size))
    (set! (ref meta-class 'instance_size)
          (ref (deref (ref meta-class 'super_class)) 'instance_size))
    
    (objc_addClass (ptr new-class))
    new-class))

(define (objc-add-method class method-name ret-type arg-types proc)
  (let ((selector (@selector method-name))
        (method (make (c-struct 'objc_method)))
        (method-list (make (c-struct 'objc_method_list))))
    (set! (ref method 'method_name) selector)
    (set! (ref method 'method_types)
          (apply string-append (map encode-objc-type
                                    (list* ret-type <id> <SEL> arg-types))))
    (set! (ref method 'method_imp)
          (cast (c-func-ptr ret-type (list* <id> <SEL> arg-types)) proc))
    
    (set! (ref method-list 'method_count) 1)
    (set! (ref (ref method-list 'method_list) 0) method)
    
    (class_addMethods class (ptr method-list))))

(define (needs-objc_msgSend_stret? ret-type)
  (define (composite-type? ret-type)
    (or (is-a? ret-type <c-struct-meta>)
        (is-a? ret-type <c-union-meta>)))
  (if (big-endian?)
      ;; Mac on PPC
      (composite-type? ret-type)
      ;; Mac on Intel
      (cond
       ((not (composite-type? ret-type))
        #f)
       ((< 8 (c-sizeof ret-type))
        #t)
       (else
        (let loop ((composite-type ret-type))
          (find (lambda (type)
                  (cond
                   ((composite-type? type)
                    (loop type))
                   ((and (is-a? type <c-array-meta>)
                         (< 1 (size-of type)))
                    #t)
                   (else
                    #f)))
                (map cdr (decl-alist-of composite-type))))))))
        
(define (%objc-msg-send obj super? selector-name . args)
  (or (and-let* ((lst (hash-table-get method-pool selector-name)))
        (let* ((ret-type (car lst))
               (arg-types (cdr lst))
               (send (if (needs-objc_msgSend_stret? ret-type)
                         (lambda (obj selector . args)
                           (let ((retval (make ret-type)))
                             (apply (make-c-func-vaargs
                                     (if super?
                                         'objc_msgSendSuper_stret
                                         'objc_msgSend_stret)
                                     <c-void>
                                     (append (list (ptr <c-void>)
                                                   (if super?
                                                       (ptr (c-struct 'objc_super))
                                                       <id>)
                                                   <SEL>)
                                             arg-types))
                                    (ptr retval) obj selector args)
                             retval))
                         (make-c-func-vaargs (if super?
                                                 'objc_msgSendSuper
                                                 'objc_msgSend)
                                             ret-type
                                             (append (list (if super?
                                                               (ptr (c-struct 'objc_super))
                                                               <id>)
                                                           <SEL>)
                                                     arg-types))))
               (sel (@selector selector-name)))
          (if (null-ptr? sel)
              (errorf "selector ~a is not found." selector-name)
              (apply send obj sel args))))
      (errorf "selector ~a is not found." selector-name)))
                                       
(define (args->selector-name args)
  (string-append
   (string-join (map x->string
                     (filter (lambda (elem)
                               (or (symbol? elem) (keyword? elem)))
                             args))
                ":")
   (if (= (length args) 1)
       ""
       ":")))

(define (filter-args args)
  (remove (lambda (elem) (or (symbol? elem) (keyword? elem))) args))

(define-method object-apply ((obj <id>) . rest)
  (apply %objc-msg-send obj #f (args->selector-name rest) (filter-args rest)))

(define-method object-apply ((obj (ptr (c-struct 'objc_super))) . rest)
  (apply %objc-msg-send obj #t (args->selector-name rest) (filter-args rest)))

(define (make-super class obj)
  (let ((data (make (c-struct 'objc_super))))
    (set! (ref data 'receiver) obj)
    (set! (ref data 'class)
          (ref (deref (cast (ptr (c-struct 'objc_class)) class)) 'super_class))
    (ptr data)))

(provide "c-wrapper/objc-ffi")

;; end of file
