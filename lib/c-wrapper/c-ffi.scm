;; -*- coding: utf-8; mode: scheme -*-
;;
;; c-ffi.scm
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

(define-module c-wrapper.c-ffi
  (use srfi-1)
  (use srfi-13)
  (use gauche.sequence)
  (use file.util)
  (use gauche.uvector)
  (use util.queue)
  (use c-wrapper.config)
  (use util.match)
  (use util.list)
  (use gauche.parameter)

  (export c-load-library
          c-ld
          c-lookup-symbol
          @
          @selector
          c-symbol
          <c-type-meta>
          <c-type>
          <c-promise-meta>
          <c-promise>
          c-delay
          c-force
          c-sizeof
          c-type?
          <c-value-meta>
          <c-value>
          c-value-ref
          c-value-set!
          <c-longdouble>
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
          post++
          post--
          pre++
          pre--
          <c-void-meta>
          <c-void>
          <c-basic-ptr-meta>
          <c-basic-ptr>
          <c-ptr-meta>
          <c-ptr>
          c-ptr-ref
          c-ptr-set!
          c-ptr+
          c-ptr-
          null-ptr?
          make-null-ptr
          register-finalizer!
          unregister-finalizer!
          finalize!
          make-c-var
          <c-func-ptr-meta>
          <c-func-ptr>
          <c-array-meta>
          <c-array>
          c-array-ref
          c-array-set!
          c-array-length
          c-array
          make-c-array ;deprecated
          c-array-length
          <c-struct-meta>
          <c-struct>
          define-c-struct
          init-c-struct!
          c-bit-field
          make-bit-field ;deprecated
          c-struct-symbol
          c-struct
          c-struct-ref
          c-struct-set!
          c-offsetof
          raw-ref
          <c-union-meta>
          <c-union>
          define-c-union
          init-c-union!
          c-union-symbol
          c-union
          c-union-ref
          c-union-set!
          c-enum
          define-c-enum
          init-c-enum! ;deprecated
          ptr
          deref
          c-func-ptr
          make-c-func-ptr ;deprecated
          c-func-vaargs-ptr
          make-c-func-vaargs-ptr ;deprecated
          c-func
          <c-func>
          make-c-func-type ;deprecated
          make-c-func
          make-c-func-vaargs
          c-closure-free
          cast
          c-cast
          scm-cast
          )

  (dynamic-load "c-ffi")
  )

(select-module c-wrapper.c-ffi)

(define (find-dylib-from-la lafile)
  (call-with-input-file lafile
    (lambda (in)
      (let loop ((dlname #f)
                 (libdir #f)
                 (installed? #f)
                 (str (read-line in)))
        (rxmatch-cond 
          (test (eof-object? str)
           (if (and dlname libdir installed?)
               (build-path libdir dlname)
               #f))
          ((#/dlname='(.+)'/ str) (#f dn)
           (loop dn libdir installed? (read-line in)))
          ((#/libdir='(.+)'/ str) (#f lb)
           (loop dlname lb installed? (read-line in)))
          ((#/installed=yes/ str) (#f)
           (loop dlname libdir #t (read-line in)))
          (else
           (loop dlname libdir installed? (read-line in))))))))

(define (find-library lib paths need-prefix?)
  (define (find-library-in-paths filename)
    (find-file-in-paths filename :paths paths :pred file-is-readable?))
  (define (find-library-add-extension basename)
    (let loop ((extensions `("" ".la" ,(string-append "." DYLIBEXT))))
      (cond
       ((null? extensions)
        #f)
       (else
        (or (and-let* ((filename (find-library-in-paths (string-append basename (car extensions)))))
              (if (equal? (path-extension filename) "la")
                  (find-dylib-from-la filename)
                  filename))
            (loop (cdr extensions)))))))
  (define (find-library-add-prefix libname)
    (any find-library-add-extension (map (cut string-append <> libname)
                                          libname-prefix-list)))
  ((if need-prefix?
       find-library-add-prefix
       find-library-add-extension)
   lib))

(define (%c-load-framework name)
  #f)

(define (c-load-library libraries . keywords)
  (define (try-ld-script dlfile)
    (guard (e (else #f))
           (call-with-input-file dlfile
             (lambda (in)
               (let loop ((str (read-line in)))
                 (rxmatch-cond
                   (test (eof-object? str)
                    #f)
                   ((#/GROUP\s*\((.*)\)/ str) (#f libs)
                    (or (and-let* ((dl (find (cut #/\.so/ <>)
                                             (string-split libs #[,\s]))))
                          (dlopen dl))
                        #f))
                   (else
                    (loop (read-line in)))))))))
  (define (lib-load lib search-paths need-prefix?)
    (or (and-let* ((dlfile (cond
                            ((string-scan lib "/")
                             (find-library lib '(".") need-prefix?))
                            (else
                             (or (find-library lib (ld-library-paths) need-prefix?)
                                 (search-library-with-ldconfig lib)
                                 (find-library lib
                                               (append search-paths
                                                       (sys-library-paths))
                                               need-prefix?)))))
                   (handle (or (dlopen dlfile)
                               (try-ld-script dlfile))))
          handle)
        (errorf "can't load ~a ~a" lib (or (and-let* ((errmsg (dlerror)))
                                             (string-append "(" errmsg ")"))
                                           ""))))
  (let-keywords* keywords ((library-dirs '())
                           (option ""))
    (let loop ((libs '())
               (paths (if (list? library-dirs)
                          (reverse library-dirs)
                          (list library-dirs)))
               (rest-opts (string-split option #[\s])))
      (define (opt) (car rest-opts))
      (cond
       ((null? rest-opts)
        (for-each (lambda (lib)
                    (unless (member lib ignore-library-list)
                      (lib-load lib (reverse paths) #f)))
                  (if (list? libraries)
                      (reverse libraries)
                      (list libraries)))
        (for-each (lambda (lib)
                    (lib-load lib (reverse paths) #t))
                  (reverse libs)))
       ((string-prefix? "-l" (opt))
        (let ((libname (substring (opt) 2 (string-length (opt)))))
          (loop (if (member libname ignore-libname-list)
                    libs
                    (cons libname libs))
                paths
                (cdr rest-opts))))
       ((string-prefix? "-L" (opt))
        (loop libs
              (cons (substring (opt) 2 (string-length (opt)))
                    paths)
              (cdr rest-opts)))
       ((string-prefix? "-Wl," (opt))
        (loop libs
              paths
              (append (string-split (substring (opt) 4 (string-length (opt)))
                                    ",")
                      (cdr rest-opts))))
       ((string=? (car rest-opts) "-framework")
        (%c-load-framework (cadr rest-opts))
        (loop libs paths (cddr rest-opts)))
       (else
        (loop libs paths (cdr rest-opts)))))))

(define (c-ld option)
  (c-load-library '() :option option))

(define (c-lookup-symbol sym)
  (let ([str (symbol->string sym)])
    (dlsym str)))

;; for Objective-C functions
(define (@ str)
  (error "Objective-C string is not supported."))

(define (@selector str)
  (error "@selector is not supported."))

;; FFI sandbox

(define ffi-sandbox-module
  (let ((mod #f))
    (lambda ()
      (or mod
          (let ((m (or (make-module 'c-wrapper.c-ffi.sandbox :if-exists #f)
                       (find-module 'c-wrapper.c-ffi.sandbox))))
            (eval `(extend ,(if (library-exists? 'c-wrapper.objc-ffi)
                                'c-wrapper.objc-ffi
                                'c-wrapper.c-ffi))
                  m)
            (set! mod m)
            m)))))

(define-macro (c-symbol sym)
  `(with-module c-wrapper.c-ffi.sandbox ,sym))

;;
;; basic class and functions for C type system
;;
(define-class <c-type-meta> (<class>)
  ((type-name :init-value #f
              :accessor type-name-of)
   (ptr-class :init-value #f)
   (array-class-alist :init-value '())
   (ffi-type :init-value #f
             :init-keyword :ffi-type
             :accessor ffi-type-of)))

(define-class <c-type> ()
  ((identifier :init-value #f
               :init-keyword :identifier)
   (buffer :init-value #f
           :init-keyword :buffer))
  :metaclass <c-type-meta>)

(define-class <c-promise-meta> (<c-type-meta>)
  ())

(define-class <c-promise> (<c-type>)
  ((trunk :init-value #f
          :init-keyword :trunk)
   (info :init-value #f
         :init-keyword :info))
  :metaclass <c-promise-meta>)

(define (c-delay trunk . rest)
  (let-optionals* rest ((info #f))
    (make <c-promise> :trunk trunk :info info)))

(define-method c-force ((obj <c-promise>))
  ((slot-ref obj 'trunk)))

(define-method c-force ((obj <c-type>))
  obj)

(define-method ref ((obj <c-promise>) . rest)
  (apply ref (c-force obj) rest))

(define-method (setter ref) ((obj <c-promise>) . rest)
  (apply (setter ref) (c-force obj) rest))

(define buffer-of
  (let ((alloc-buffer-if-needed (lambda (obj)
                                  (unless (slot-ref obj 'buffer)
                                    (slot-set! obj 'buffer
                                               (or (and-let* ((identifier (slot-ref obj 'identifier)))
                                                     (or (and-let* ((vptr (c-lookup-symbol identifier)))
                                                           (%deref-uvector vptr (c-sizeof obj)))
                                                         (errorf "variable ~a is not found." identifier)))
                                                   (make-u8vector-nonatomic (c-sizeof obj))))))))
    (getter-with-setter (lambda (obj)
                          (alloc-buffer-if-needed obj)
                          (slot-ref obj 'buffer))
                        (lambda (obj v)
                          (alloc-buffer-if-needed obj)
                          (slot-set! obj 'buffer v)))))

(define-method object-equal? ((obj1 <c-type-meta>) (obj2 <c-type-meta>))
  (eq? (type-name-of obj1) (type-name-of obj2)))

(define-method object-equal? ((obj1 <c-type>) (obj2 <c-type>))
  (and (eq? (class-of obj1) (class-of obj2))
       (equal? (buffer-of obj1) (buffer-of obj2))))

(define-method object-hash ((obj <c-type-meta>))
  (hash (type-name-of obj)))

(define-method write-object ((obj <c-type-meta>) port)
  (format port "#<~a>" (type-name-of obj)))

(define-method write-object ((obj <c-type>) port)
  (format port "#<~a ~a>" (type-name-of (class-of obj)) (buffer-of obj)))

(define-method write-object ((obj <c-promise>) port)
  (format port "#<c-promise ~s>" (slot-ref obj 'info)))

(define-method object-apply ((obj <c-promise> ) . args)
  (apply (c-force obj) args))

(define-method initialize ((obj <c-type>) initargs)
  (next-method))

(define (c-sizeof-type type)
  (cond
   ((slot-ref type 'ffi-type) => (cut slot-ref <> 'size))
   (else
    0)))
  
(define-method c-sizeof ((obj <c-type-meta>))
  (c-sizeof-type obj))

(define-method c-sizeof ((obj <c-promise>))
  (c-sizeof (c-force obj)))

(define-method c-sizeof ((obj <c-type>))
  (c-sizeof (class-of obj)))

(define (c-type? obj)
  (is-a? obj <c-type>))

;;
;; C value class (char, short, int, long, long long, float, double)
;;
(define-class <c-value-meta> (<c-type-meta>)
  ())

(define-class <c-value> (<c-type>)
  ()
  :metaclass <c-value-meta>)

(define (%signed-uvector-alias obj)
  (case (slot-ref (ffi-type-of (class-of obj)) 'size)
    ((1) (uvector-alias <s8vector> (buffer-of obj)))
    ((2) (uvector-alias <s16vector> (buffer-of obj)))
    ((4) (uvector-alias <s32vector> (buffer-of obj)))
    ((8) (uvector-alias <s64vector> (buffer-of obj)))
    (else
     (error "Unsupported size: "
            (slot-ref (ffi-type-of (class-of obj)) 'size)))))

(define (%unsigned-uvector-alias obj)
  (case (slot-ref (ffi-type-of (class-of obj)) 'size)
    ((1) (uvector-alias <u8vector> (buffer-of obj)))
    ((2) (uvector-alias <u16vector> (buffer-of obj)))
    ((4) (uvector-alias <u32vector> (buffer-of obj)))
    ((8) (uvector-alias <u64vector> (buffer-of obj)))
    (else
     (error "Unsupported size: "
            (slot-ref (ffi-type-of (class-of obj)) 'size)))))

(define-syntax define-c-value
  (syntax-rules (signed unsigned)
    ((_ name ffi-type)
     (begin
       (define-class name (<c-value>)
         ())
       (set! (ffi-type-of name) ffi-type)
       (set! (type-name-of name) (string->symbol
                                  (substring (symbol->string 'name)
                                             1
                                             (- (string-length
                                                 (symbol->string 'name))
                                                1))))))
    ((_ name ffi-type signed)
     (begin
       (define-c-value name ffi-type)
       (define-method c-value-ref ((obj name))
         (ref (%signed-uvector-alias obj) 0))
       (define-method c-value-set! ((obj name) v)
         (if (<= 0 v)
             (set! (ref (%unsigned-uvector-alias obj) 0) v)
             (set! (ref (%signed-uvector-alias obj) 0) v)))))
    ((_ name ffi-type unsigned)
     (begin
       (define-c-value name ffi-type)
       (define-method c-value-ref ((obj name))
         (ref (%unsigned-uvector-alias obj) 0))
       (define-method c-value-set! ((obj name) v)
         (if (<= 0 v)
             (set! (ref (%unsigned-uvector-alias obj) 0) v)
             (set! (ref (%signed-uvector-alias obj) 0) v)))))
    ((_ name ffi-type uvector-class)
     (begin
       (define-c-value name ffi-type)
       (define-method c-value-ref ((obj name))
         (ref (uvector-alias uvector-class (buffer-of obj)) 0))
       (define-method c-value-set! ((obj name) v)
         (set! (ref (uvector-alias uvector-class (buffer-of obj)) 0) v))))))

(define-method c-value-ref ((obj <c-promise>))
  (c-value-ref (c-force obj)))

(define-method c-value-set! ((obj <c-promise>) v)
  (c-value-set! (c-force obj) v))

(define-class <c-longdouble> (<c-type>)
  ()
  :metaclass <c-type-meta>)
(set! (ffi-type-of <c-longdouble>) (ffi-type-longdouble))
(set! (type-name-of <c-longdouble>) 'c-longdouble)

(define-c-value <c-float>  (ffi-type-float) <f32vector>)
(define-c-value <c-double>  (ffi-type-double) <f64vector>)
(define-c-value <c-uchar>  (ffi-type-uchar) unsigned)
(define-c-value <c-char>  (ffi-type-schar) signed)
(define-c-value <c-ushort>  (ffi-type-ushort) unsigned)
(define-c-value <c-short>  (ffi-type-sshort) signed)
(define-c-value <c-uint>  (ffi-type-uint) unsigned)
(define-c-value <c-int>  (ffi-type-sint) signed)
(define-c-value <c-ulong>  (ffi-type-ulong) unsigned)
(define-c-value <c-long>  (ffi-type-slong) signed)
(define-c-value <c-ulonglong> (ffi-type-ulonglong) unsigned)
(define-c-value <c-longlong> (ffi-type-slonglong) signed)

(define-method write-object ((obj <c-value>) port)
  (format port "#<~a ~a>" (type-name-of (class-of obj)) (c-value-ref obj)))

(define-method ref ((obj <c-value>))
  (c-value-ref obj))

(define-method (setter ref) ((obj <c-value>) (v <real>))
  (c-value-set! obj v))

(define-method object-apply ((obj <c-value>))
  (c-value-ref obj))

(define-method object-apply ((obj <c-promise>))
  (scm-cast (c-force obj)))

(define-method object-apply ((obj <c-value>) (v <real>))
  (c-value-set! obj v))

(define-method object-apply ((obj <c-promise>) (v <real>))
  ((c-force obj) v))

(define-method post++ ((obj <c-value>))
  (let ((v (make (class-of obj) :buffer (u8vector-copy (buffer-of obj)))))
    (c-value-set! obj (+ (c-value-ref obj) 1))
    v))

(define-method post++ ((obj <c-promise>))
  (post++ (c-force obj)))

(define-method post-- ((obj <c-value>))
  (let ((v (make (class-of obj) :buffer (u8vector-copy (buffer-of obj)))))
    (c-value-set! obj (- (c-value-ref obj) 1))
    v))

(define-method post-- ((obj <c-promise>))
  (post-- (c-force obj)))

(define-method pre++ ((obj <c-value>))
  (c-value-set! obj (+ (c-value-ref obj) 1))
  obj)

(define-method pre++ ((obj <c-promise>))
  (pre++ (c-force obj)))
                      
(define-method pre-- ((obj <c-value>))
  (c-value-set! obj (- (c-value-ref obj) 1))
  obj)

(define-method pre-- ((obj <c-promise>))
  (pre-- (c-force obj)))

(define-syntax define-object-op-for-c-value
  (syntax-rules ()
    ((_ object-op op)
     (begin
       (define-method object-op ((v0 <c-value>) v1)
         (op (c-value-ref v0) v1))
       (define-method object-op ((v0 <c-promise>) v1)
         (op (c-force v0) v1))
       (define-method object-op (v0 (v1 <c-value>))
         (op v0 (c-value-ref v1)))
       (define-method object-op (v0 (v1 <c-promise>))
         (op v0 (c-force v1)))))))

(define-object-op-for-c-value object-+ +)
(define-object-op-for-c-value object-- -)
(define-object-op-for-c-value object-* *)
(define-object-op-for-c-value object-/ /)

(define-method object-- ((v <c-value>))
  (- (c-value-ref v)))

(define-method object-- ((v <c-promise>))
  (- (c-force v)))

;;
;; void 
;;
(define-class <c-void-meta> (<c-type-meta>)
  ()
  )

(define-class <c-void> (<c-type>)
  ()
  :metaclass <c-void-meta>)

(set! (ffi-type-of <c-void>) (ffi-type-void))
(set! (type-name-of <c-void>) 'c-void)

(define-method write-object ((obj <c-void>) port)
  (format port "#<~a>" (type-name-of (class-of obj))))

;; 
;; basic-pointer
;;
(define-class <c-basic-ptr-meta> (<c-type-meta>)
  ()
  )

(define-class <c-basic-ptr> (<c-type>)
  ()
  )

(define-method write-object ((obj <c-basic-ptr>) port)
  (format port "#<~a 0x~x>" (type-name-of (class-of obj)) (c-ptr-ref obj)))

(define-method c-ptr-ref ((ptr <c-basic-ptr>))
  (ref (%unsigned-uvector-alias ptr) 0))

(define-method c-ptr-ref ((obj <c-promise>))
  (c-ptr-ref (c-force obj)))

(define-method c-ptr-set! ((obj <c-basic-ptr>) (v <integer>))
  (if (<= 0 v)
      (set! (ref (%unsigned-uvector-alias obj) 0) v)
      (set! (ref (%signed-uvector-alias obj) 0) v)))
  
(define-method c-ptr-set! ((obj <c-basic-ptr>) (v <c-basic-ptr>))
  (u8vector-copy! (buffer-of obj) 0 (buffer-of v)))

(define-method c-ptr-set! ((obj <c-promise>) v)
  (c-ptr-set! (c-force obj) v))

(define-method ref ((obj <c-basic-ptr>))
  (c-ptr-ref obj))

(define-method (setter ref) ((obj <c-basic-ptr>) v)
  (c-ptr-set! obj v))

;;
;; pointer
;;
(define-class <c-ptr-meta> (<c-basic-ptr-meta>)
  ((orig-c-type :accessor orig-c-type-of))
  )

(define-class <c-ptr> (<c-basic-ptr>)
  ((finalizer :init-value #f
              :accessor finalizer-of))
  :metaclass <c-ptr-meta>)

(define c-ptr
  (let* ((t-ptr (ffi-type-pointer)))
    (lambda (c-type)
      (or (slot-ref c-type 'ptr-class)
          (let* ((mod (ffi-sandbox-module))
                 (type-name-str (string-append "c-ptr:" (symbol->string (type-name-of c-type))))
                 (type-name (string->symbol type-name-str))
                 (class-name (string->symbol (string-append "<" type-name-str ">"))))
            (eval `(define-class ,class-name (<c-ptr>) () :metaclass <c-ptr-meta>) mod)
            (let ((class (global-variable-ref mod class-name #f)))
              (set! (ffi-type-of class) t-ptr)
              (set! (type-name-of class) type-name)
              (set! (orig-c-type-of class) c-type)
              (slot-set! c-type 'ptr-class class)
              class))))))

(define-method ptr ((c-type <c-type-meta>))
  (c-ptr c-type))

(define-method c-ptr-set! ((obj <c-ptr>) (v <string>))
  (c-ptr-set! obj (cast (ptr <c-char>) v)))

(define-method ref ((obj <c-ptr>) (n <integer>))
  (c-array-ref (cast (c-array (orig-c-type-of (class-of obj)) #f) obj) n))

(define-method (setter ref) ((obj <c-ptr>) (n <integer>) v)
  (c-array-set! (cast (c-array (orig-c-type-of (class-of obj)) #f) obj) n v))

(define-method post++ ((obj <c-ptr>))
  (let ((v (make (class-of obj) :buffer (u8vector-copy (buffer-of obj)))))
    (c-ptr-set! obj (+ (c-ptr-ref obj)
                       (c-sizeof-type (orig-c-type-of (class-of obj)))))
    v))

(define-method post-- ((obj <c-ptr>))
  (let ((v (make (class-of obj) :buffer (u8vector-copy (buffer-of obj)))))
    (c-ptr-set! obj (- (c-ptr-ref obj)
                       (c-sizeof-type (orig-c-type-of (class-of obj)))))
    v))

(define-method pre++ ((obj <c-ptr>))
  (c-ptr-set! obj (+ (c-ptr-ref obj)
                     (c-sizeof-type (orig-c-type-of (class-of obj)))))
  obj)

(define-method pre-- ((obj <c-ptr>))
  (c-ptr-set! obj (- (c-ptr-ref obj)
                     (c-sizeof-type (orig-c-type-of (class-of obj)))))
  obj)

(define-method c-ptr+ ((ptr <c-ptr>) (n <integer>))
  (let ((newptr (make (class-of ptr))))
    (c-ptr-set! newptr (+ (c-ptr-ref ptr)
                          (* (c-sizeof-type (orig-c-type-of (class-of ptr))) n)))
    newptr))

(define-method c-ptr+ ((ptr <c-ptr>) (obj <c-value>))
  (c-ptr+ ptr (c-value-ref obj)))

(define-method c-ptr+ ((ptr <c-ptr>) (obj <c-promise>))
  (c-ptr+ ptr (c-force obj)))

(define-method c-ptr+ ((obj <c-promise>) n)
  (c-ptr+ (c-force obj) n))

(define-method c-ptr- ((ptr <c-ptr>) (n <integer>))
  (c-ptr+ ptr (- n)))

(define-method c-ptr- ((ptr <c-ptr>) (obj <c-value>))
  (c-ptr- ptr (c-value-ref obj)))

(define-method c-ptr- ((ptr <c-ptr>) (obj <c-promise>))
  (c-ptr- ptr (c-force obj)))

(define-method c-ptr- ((obj <c-promise>) n)
  (c-ptr- (c-force obj) n))

(define-method register-finalizer! ((ptrobj <c-ptr>) proc)
  (set! (finalizer-of ptrobj) proc)
  (%register-finalizer! ptrobj))

(define-method register-finalizer! ((obj <c-promise>) proc)
  (register-finalizer! (c-force obj) proc))

(define-method unregister-finalizer! ((ptrobj <c-ptr>))
  (set! (finalizer-of ptrobj) #f)
  (%unregister-finalizer! ptrobj))

(define-method unregister-finalizer! ((obj <c-promise>))
  (unregister-finalizer! (c-force obj)))

(define-method finalize! ((ptrobj <c-ptr>))
  (and-let* ((proc (finalizer-of ptrobj)))
    (set! (finalizer-of ptrobj) #f)
    (proc ptrobj))
  (%unregister-finalizer! ptrobj))

(define-method finalize! ((obj <c-promise>))
  (finalize! (c-force obj)))

(define (make-c-var identifier type)
  (make type :identifier identifier))

;;
;; function pointer
;;
(define-class <c-func-ptr-meta> (<c-basic-ptr-meta>)
  ((ret-type :accessor ret-type-of)
   (arg-types :accessor arg-types-of)))

(define-method object-equal? ((obj1 <c-func-ptr-meta>) (obj2 <c-func-ptr-meta>))
  (and (equal? (ret-type-of obj1) (ret-type-of obj2))
       (equal? (arg-types-of obj1) (arg-types-of obj2))))

(define-method object-hash ((obj <c-func-ptr-meta>))
  (logxor (hash (ret-type-of obj)) (hash (arg-types-of obj))))

(define-class <c-func-ptr> (<c-basic-ptr>)
  ()
  :metaclass <c-func-ptr-meta>)

(define (normalize-arg-types arg-types)
  (match arg-types
    (((_ (? (cut eq? <c-void> <>) void)))
     '())
    (((? (cut eq? <c-void> <>) void))
     '())
    (else
     (map (lambda (atype)
            (let ((t (if (pair? atype) (cadr atype) atype)))
              (cond
               ((is-a? t <c-array-meta>)
                ;; array -> pointer
                (ptr (element-type-of t)))
               ((equal? t <c-void>)
                (error "can't use void as a parameter"))
               ((= (c-sizeof-type t) 0)
                (errorf "can't use the incomplete type ~a as a parameter" t))
               (else
                t))))
          arg-types))))

(define (normalize-ret-type ret-type)
  (cond
   ((is-a? ret-type <c-array-meta>)
    ;; array -> pointer
    (ptr (element-type-of ret-type)))
   ((= (c-sizeof-type ret-type) 0)
    (errorf "can't use the incomplete type ~a as a return type" ret-type))
   (else
    ret-type)))

(define (c-func-ptr ret-type arg-types . _)
  (let ((class (make <c-func-ptr-meta>
                 :name (gensym)
                 :supers (list <c-func-ptr>)
                 :slots ()
                 :defined-modules (list (ffi-sandbox-module)))))
    (set! (ffi-type-of class) (ffi-type-pointer))
    (set! (type-name-of class) 'c-func-ptr)
    (set! (ret-type-of class) (normalize-ret-type ret-type))
    (set! (arg-types-of class) (normalize-arg-types arg-types))
    class))

;; deprecated
(define make-c-func-ptr c-func-ptr)

(define (c-func-vaargs-ptr ret-type arg-types . _)
  (c-func-ptr ret-type arg-types))

;; deprecated
(define make-c-func-vaargs-ptr c-func-vaargs-ptr)

(define-class <c-func> ()
  ((ret-type :init-keyword :ret-type
             :accessor ret-type-of)
   (arg-types :init-keyword :arg-types
              :accessor arg-types-of)))

(define (c-func ret-type arg-types . _)
  (make <c-func> :ret-type ret-type :arg-types arg-types))

;; deprecated
(define make-c-func-type c-func)

(define-method ptr ((func-type <c-func>))
  (c-func-ptr (ret-type-of func-type)
              (arg-types-of func-type)))

(define-method deref ((fptr <c-func-ptr>))
  (let ((func-type (class-of fptr)))
    (%make-c-func-vaargs fptr (ret-type-of func-type) (arg-types-of func-type))))

(define-method object-apply ((fptr <c-func-ptr>) . args)
  (apply (deref fptr) args))

;;
;; array
;;
(define-class <c-array-meta> (<c-type-meta>)
  ((element-type :accessor element-type-of)
   (size :accessor size-of)))

(define-method object-equal? ((obj1 <c-array-meta>) (obj2 <c-array-meta>))
  (and (equal? (element-type-of obj1) (element-type-of obj2))
       (equal? (size-of obj1) (size-of obj2))))

(define-method object-hash ((obj <c-array-meta>))
  (logxor (hash (element-type-of obj)) (hash (size-of obj))))

(define-class <c-array> (<c-type> <sequence>)
  ())

(define (c-array element-type size)
  (or (and-let* ((pair (assq size (slot-ref element-type 'array-class-alist))))
        (cdr pair))
      (let ((class (make <c-array-meta>
                     :name (gensym)
                     :supers (list <c-array>)
                     :slots ()
                     :defined-modules (list (ffi-sandbox-module))))
            (size (if size size 0)))
        (set! (ffi-type-of class)
              (make-ffi-array-type (ffi-type-of element-type) size))
        (set! (type-name-of class)
              (string->symbol (format "c-array:~a[~a]"
                                      (type-name-of element-type)
                                      size)))
        (set! (element-type-of class) element-type)
        (set! (size-of class) size)
        (push! (slot-ref element-type 'array-class-alist) (cons size class))
        class)))

;; deprecated
(define (make-c-array element-type size)
  (c-array element-type size))

(define-method c-array-ref ((obj <c-array>) (index <integer>))
  (let* ((start (* index (c-sizeof-type (element-type-of (class-of obj)))))
         (end (+ start (c-sizeof-type (element-type-of (class-of obj))))))
    (scm-cast (make (element-type-of (class-of obj))
                :buffer (uvector-alias <u8vector> 
                                       (if (= (size-of (class-of obj)) 0)
                                           (%expand-u8vector (buffer-of obj) end)
                                           (buffer-of obj))
                                       start end)))))

(define-method c-array-ref ((obj <c-promise>) index)
  (c-array-ref (c-force obj) index))

(define-method c-array-set! ((obj <c-array>) (index <integer>) value)
  (let* ((tstart (* index (c-sizeof-type (element-type-of (class-of obj)))))
         (send (c-sizeof-type (element-type-of (class-of obj))))
         (casted-value (cast (element-type-of (class-of obj)) value)))
    (u8vector-copy!
     (if (= (size-of (class-of obj)) 0)
         (%expand-u8vector (buffer-of obj) (+ tstart send))
         (buffer-of obj))
     tstart (buffer-of casted-value) 0 send)))

(define-method c-array-set! ((obj <c-promise>) index value)
  (c-array-set! (c-force obj) index value))

(define-method c-array-length ((array <c-array>))
  (size-of (class-of array)))

(define-method c-array-length ((obj <c-promise>))
  (c-array-length (c-force obj)))

(define-method object-apply ((c-type <c-type-meta>) (size <integer>))
  (c-array c-type size))

;; gauche.sequence support
(define-method call-with-iterator ((array <c-array>) proc . args)
  (let-keywords* args ((start 0))
    (let ((i start))
      (proc (lambda ()
              (<= (size-of array) i))
            (lambda ()
              (begin0
                (c-array-ref array i)
                (inc! i)))))))

(define-method call-with-iterator ((obj <c-promise>) proc . args)
  (apply call-with-iterator (c-force obj) proc args))

(define-method size-of ((array <c-array>))
  (c-array-length array))

(define-method size-of ((obj <c-promise>))
  (size-of (c-force obj)))

(define-method referencer ((obj <c-array>)) c-array-ref)

(define-method referencer ((obj <c-promise>))
  (referencer (c-force obj)))

(define-method modifier ((obj <c-array>)) c-array-set!)

(define-method modifier ((obj <c-promise>))
  (modifier (c-force obj)))

;;
;; struct
;;
(define-class <c-struct-meta> (<c-type-meta>)
  ((decl-alist :accessor decl-alist-of)
   (unnamed-alist :accessor unnamed-alist-of)))

(define-class <c-struct> (<c-type>)
  ())

(define-syntax define-c-struct
  (syntax-rules ()
    ((_ tagname)
     (let ((classname (c-struct-symbol 'tagname)))
       (unless (global-variable-ref (ffi-sandbox-module) classname #f)
         (eval `(define-class ,classname (<c-struct>)
                  ()
                  :metaclass <c-struct-meta>)
               (ffi-sandbox-module))
         (set! (type-name-of (c-struct 'tagname))
               (string->symbol (string-append "c-struct:" (symbol->string 'tagname)))))))))

(define-class <bit-field> ()
  ((bits :init-keyword :bits
         :accessor bits-of)
   (signed? :init-keyword :signed?
            :accessor signed?)
   (shift :accessor shift-of)
   (leader? :accessor leader?)
   (bit-mask :allocation :virtual
             :getter bit-mask-of
             :slot-ref (lambda (obj)
                         (- (expt 2 (bits-of obj)) 1)))))

(define (bit-field? obj)
  (is-a? obj <bit-field>))

(define (follower? obj)
  (not (leader? obj)))

(define-method ffi-type-of ((obj <bit-field>))
  (ffi-type-of <c-uint>))

(define-method c-sizeof ((obj <bit-field>))
  (c-sizeof-type <c-uint>))

(define-method leader? ((obj <c-type-meta>))
  #t)

(define (c-bit-field c-type num)
  (make <bit-field> :bits num :signed? (eq? c-type <c-int>)))

;; deprecated
(define make-bit-field c-bit-field)

(define (init-decl-alist! alist)
  (define (dispatch rest accum)
    (cond
     ((null? rest)
      alist)
     ((bit-field? (cdar rest))
      (do-bit-field (cdar rest) (cdr rest) accum))
     (else
      ;; ***** fix bit-field offset *****
      ;(dispatch (cdr rest) (max (* (- (c-sizeof-type <c-uint>) (c-sizeof-type (cdar rest))) 8)
      ;                          0)))))
      (dispatch (cdr rest) 0))))
  (define (do-bit-field bit-field rest accum)
    (if (< (* (c-sizeof-type <c-uint>) 8) (+ accum (bits-of bit-field)))
        (do-bit-field bit-field rest 0)
        (begin
          ;; ***** fix bit-field offset *****
          (if (= (bits-of bit-field) 0) (set! accum 0))
          (set! (shift-of bit-field) (if (big-endian?)
                                         (- (* (c-sizeof-type <c-uint>) 8)
                                            accum
                                            (bits-of bit-field))
                                         accum))
          ;; ***** fix bit-field offset *****
          ;(set! (leader? bit-field) (= accum 0))
          (set! (leader? bit-field) (and (= accum 0)
                                         (not (= (bits-of bit-field) 0))))
          (dispatch rest (+ accum (bits-of bit-field))))))
  (dispatch alist 0))

(define (unnamed-symbol? sym)
  (#/^%unnamed/ (symbol->string sym)))

(define (make-unnamed-alist decl-alist)
  (define (%member-unnamed-alist type unnamed-name knil)
    (fold (lambda (pair result)
            (match-let (((sym . mem-type) pair))
                (if (unnamed-symbol? sym)
                    (%member-unnamed-alist mem-type unnamed-name result)
                    (cons (cons sym unnamed-name) result))))
          knil
          (decl-alist-of type)))
  (fold (lambda (pair result)
          (match-let (((sym . mem-type) pair))
              (if (unnamed-symbol? sym)
                  (%member-unnamed-alist mem-type sym result)
                  result)))
        '()
        decl-alist))

(define (unnamed-member class name)
  (assoc-ref (unnamed-alist-of class) name #f))

(define (init-c-struct! class alist)
  (let ((decl-alist (init-decl-alist! alist)))
    (set! (ffi-type-of class)
          (make-ffi-struct-type (map (lambda (pair)
                                       (ffi-type-of (cdr pair)))
                                     (remove (lambda (pair)
                                               (or (follower? (cdr pair))
                                                   ;; remove zero-sized array
                                                   (= (c-sizeof (cdr pair)) 0)))
                                             decl-alist))))
    (set! (decl-alist-of class) decl-alist)
    (set! (unnamed-alist-of class) (make-unnamed-alist decl-alist)))
  class)

(define-method align (offset (alignment <integer>))
  (+ (logior (- offset 1) (- alignment 1)) 1))

(define-method align (offset (c-type <c-type-meta>))
  (align offset (slot-ref (ffi-type-of c-type) 'alignment)))

(define-method align (offset (bit-field <bit-field>))
  (if (leader? bit-field)
      (align offset <c-uint>)
      offset))

(define-method c-struct-get-value (obj offset (c-type <c-type-meta>))
  (make c-type :buffer (uvector-alias <u8vector>
                                      (buffer-of obj)
                                      offset
                                      (+ offset (c-sizeof c-type)))))

(define-method c-struct-get-value (obj offset (bit-field <bit-field>))
  (let* ((v (make <c-uint> 
              :buffer (uvector-alias <u8vector>
                                     (buffer-of obj)
                                     offset
                                     (+ offset (c-sizeof-type <c-uint>)))))
         (n (logand (ash (c-value-ref v) (- (shift-of bit-field)))
                    (bit-mask-of bit-field))))
    (if (and (signed? bit-field) (< (ash (bit-mask-of bit-field) -1) n))
        (- -1 (logand (lognot n) (bit-mask-of bit-field)))
        n)))
  
(define-method c-struct-set-value! (obj offset (c-type <c-type-meta>) value)
  (u8vector-copy! (buffer-of obj) offset
                  (buffer-of (cast c-type value))
                  0
                  (c-sizeof c-type)))

(define-method c-struct-set-value! (obj offset (bit-field <bit-field>) value)
  (let1 intval (make <c-uint>
                 :buffer (u8vector-copy (buffer-of obj)
                                        offset (+ offset (c-sizeof-type <c-uint>))))
    (c-value-set! intval (logior (logand (c-value-ref intval)
                                         (lognot (ash (bit-mask-of bit-field)
                                                      (shift-of bit-field))))
                                 (ash (logand (cast <integer> value)
                                              (bit-mask-of bit-field))
                                      (shift-of bit-field))))
    (u8vector-copy! (buffer-of obj) offset
                    (buffer-of intval) 0 (c-sizeof intval))))

(define (next-offset offset type rest)
  (cond
   ((null? rest)
    offset)
   ((follower? (cdar rest))
    offset)
   (else
    (+ offset (c-sizeof type)))))

(define-syntax c-struct
  (syntax-rules ()
    ((_ tagname)
     (global-variable-ref (ffi-sandbox-module) (c-struct-symbol tagname)))))

(define (offset&type struct-class name)
  (let loop ((rest (decl-alist-of struct-class))
             (offset 0))
    (when (null? rest)
      (errorf "~a doesn't have such element: ~a" struct-class name))
    (let ((elem-name (caar rest))
          (elem-type (cdar rest)))
      (set! offset (align offset elem-type))
      (if (eq? elem-name name)
          (values offset elem-type)
          (loop (cdr rest) (next-offset offset elem-type (cdr rest)))))))

(define (c-offsetof struct-class name)
  (receive (offset elem-type) (offset&type struct-class name)
    offset))

(define-method c-struct-ref ((obj <c-struct>) (name <symbol>) . args)
  (let-optionals* args ((auto-cast? #t))
    (or (and-let* ((unnamed-name (unnamed-member (class-of obj) name)))
          (ref (c-struct-ref obj unnamed-name) name auto-cast?))
        (receive (offset elem-type) (offset&type (class-of obj) name)
          (let ((result (c-struct-get-value obj offset elem-type)))
            (if auto-cast?
                (scm-cast result)
                result))))))

(define-method c-struct-ref ((obj <c-promise>) name . args)
  (apply c-struct-ref (c-force obj) name args))

(define-method c-struct-set! ((obj <c-struct>) (name <symbol>) value)
  (or (and-let* ((unnamed-name (unnamed-member (class-of obj) name)))
        (set! (ref (c-struct-ref obj unnamed-name) name) value))
      (receive (offset elem-type) (offset&type (class-of obj) name)
        (c-struct-set-value! obj offset elem-type value))))

(define-method c-struct-set! ((obj <c-promise>) name value)
  (c-struct-set! (c-force obj) name value))

(define-method ref ((obj <c-struct>) (name <symbol>) . rest)
  (apply c-struct-ref obj name rest))

(define-method (setter ref) ((obj <c-struct>) (name <symbol>) value)
  (c-struct-set! obj name value))

(define-method raw-ref ((obj <c-struct>) (name <symbol>))
  (c-struct-ref obj name #f))

(define-method raw-ref ((obj <c-promise>) name)
  (raw-ref (c-force obj) name))

(define-method ref ((obj <c-ptr>) (name <symbol>))
  (ref (deref obj) name))

(define-method (setter ref) ((obj <c-ptr>) (name <symbol>) value)
  (set! (ref (deref obj) name) value))
  
;;
;; union
;;
(define-class <c-union-meta> (<c-type-meta>)
  ((decl-alist :accessor decl-alist-of)
   (unnamed-alist :accessor unnamed-alist-of)))

(define-class <c-union> (<c-type>)
  ())

(define-syntax define-c-union
  (syntax-rules ()
    ((_ tagname)
     (let ((classname (c-union-symbol 'tagname)))
       (unless (global-variable-ref (ffi-sandbox-module) classname #f)
         (eval `(define-class ,classname (<c-union>)
                  ()
                  :metaclass <c-union-meta>)
               (ffi-sandbox-module))
         (set! (type-name-of (c-union 'tagname))
               (string->symbol (string-append "c-union:" (symbol->string 'tagname)))))))))

(define (init-c-union! class decl-alist)
  (set! (ffi-type-of class)
        (make-ffi-struct-type
         (list (ffi-type-of (fold (lambda (p c-type)
                                    (if (or (not c-type)
                                            (< (c-sizeof c-type)
                                               (c-sizeof (cdr p))))
                                        (cdr p)
                                        c-type))
                                  #f
                                  decl-alist)))))
  (set! (decl-alist-of class) decl-alist)
  (set! (unnamed-alist-of class) (make-unnamed-alist decl-alist))
  class)

(define-syntax c-union
  (syntax-rules ()
    ((_ tagname)
     (global-variable-ref (ffi-sandbox-module) (c-union-symbol tagname)))))

(define-method c-union-ref ((obj <c-union>) (name <symbol>) . args)
  (let-optionals* args ((auto-cast? #t))
    (or (and-let* ((unnamed-name (unnamed-member (class-of obj) name)))
          (ref (c-union-ref obj unnamed-name) name auto-cast?))
        (or (and-let* ((pair (assq name (decl-alist-of (class-of obj)))))
              (let* ((elem-type (cdr pair))
                     (v (make elem-type
                          :buffer (uvector-alias <u8vector> (buffer-of obj)
                                                 0 (c-sizeof elem-type)))))
                (if auto-cast?
                    (scm-cast v)
                    v)))
            (errorf "~a doesn't have such element: ~a" (class-of obj) name)))))

(define-method c-union-ref ((obj <c-promise>) name . args)
  (apply c-union-ref (c-force obj) name args))

(define-method c-union-set! ((obj <c-union>) (name <symbol>) value)
  (or (and-let* ((unnamed-name (unnamed-member (class-of obj) name)))
        (set! (ref (c-union-ref obj unnamed-name) name) value))
      (or (and-let* ((pair (assq name (decl-alist-of (class-of obj)))))
            (let1 elem-type (cdr pair)
              (u8vector-copy! (buffer-of obj) 0
                              (buffer-of (cast elem-type value))
                              0 (c-sizeof elem-type))))
          (errorf "~a doesn't have such element: ~a" (class-of obj) name))))

(define-method c-union-set! ((obj <c-promise>) name value)
  (c-union-set! (c-force obj) name value))

(define-method ref ((obj <c-union>) (name <symbol>) . rest)
  (apply c-union-ref obj name rest))

(define-method (setter ref) ((obj <c-union>) (name <symbol>) value)
  (c-union-set! obj name value))

(define-method raw-ref ((obj <c-union>) (name <symbol>))
  (c-union-ref obj name #f))

;;
;; enum
;;
(define-syntax c-enum
  (syntax-rules ()
    ((_ tagname)
     <c-int>)))

(define (init-c-enum! class enum-symbols)
  class)

(define-syntax define-c-enum
  (syntax-rules ()
    ((_ tagname ())
     ())
    ((_ tagname ((sym val) rest ...))
     (begin
       (define sym val)
       (define-c-enum tagname (rest ...))))))
     
;;
;; functions to make pointer and dereference
;;
(define-method ptr ((obj <c-type>))
  (%ptr obj))

(define-method ptr ((obj <c-promise>))
  (ptr (c-force obj)))

(define-method deref ((obj <c-ptr>))
  (%deref obj))

(define-method deref ((obj <c-promise>))
  (deref (c-force obj)))

(define-method (setter deref) ((obj <c-ptr>) value)
  (let ((deref-obj (deref obj))
        (casted-value (cast (orig-c-type-of (class-of obj)) value)))
    (u8vector-copy! (buffer-of deref-obj) 0 (buffer-of casted-value))))

(define-method (setter deref) ((obj <c-promise>) value)
  ((setter deref) (c-force obj) value))

;;
;; functions and macro to define C function and closure
;;
(define (errchk func . args)
  (receive (status result) (apply func args)
    (cond 
     ((eq? status FFI_OK) result)
     ((eq? status FFI_BAD_TYPEDEF)
      (error "One of the ffi_type objects that ffi_prep_cif came across is bad."))
     ((eq? status FFI_BAD_ABI)
      (error "FFI_BAD_ABI"))
     (else
      (error "Unknown error: " status)))))

(define (c++-type->str type)
  (cond
   ((is-a? type <c-ptr-meta>)
    (string-append "P" (type->str (orig-c-type-of type))))
   ((is-a? type <c-struct-meta>)
    (let ((name ((#/<c-struct:(.*)>/ (symbol->string (class-name type))) 1)))
      (format "~a~a" (string-length name) name)))
   ((is-a? type <c-union-meta>)
    (let ((name ((#/<c-union:(.*)>/ (symbol->string (class-name type))) 1)))
      (format "~a~a" (string-length name) name)))
   ((is-a? type <c-array-meta>)
    (format "P~a" (type->str (element-type-of type))))
   ((eq? type <c-void>) "v")
   ((eq? type <c-uchar>) "h")
   ((eq? type <c-char>) "c")
   ((eq? type <c-short>) "s")
   ((eq? type <c-ushort>) "t")
   ((eq? type <c-int>) "i")
   ((eq? type <c-uint>) "j")
   ((eq? type <c-long>) "l")
   ((eq? type <c-ulong>) "m")
   ((eq? type <c-longlong>) "x")
   ((eq? type <c-ulonglong>) "y")
   ((eq? type <c-float>) "f")
   ((eq? type <c-double>) "d")
   ((eq? type <c-longdouble>) "e")
   ((eq? type 'ellipsis) "z")))

(define (c++-mangle name arg-types)
  (string->symbol (format "_Z~a~a~a" (string-length (symbol->string name)) name
                          (apply string-append
                                 (map type->str
                                      (if (null? arg-types)
                                          (list <c-void>)
                                          arg-types))))))

(define (make-c-func identifier ret-type arg-types . opts)
  (let-keywords* opts ((c++? #f))
    ;; ***** for debug *****
    ;(print ret-type)
    ;(print arg-types)
    ;(print (normalize-ret-type ret-type))
    ;(print (normalize-arg-types arg-types))
    ;(if (not (null? arg-types)) (read-eval-print-loop))
    (make-c-subr #f
                 (normalize-ret-type ret-type)
                 (normalize-arg-types arg-types)
                 #f
                 (if c++?
                     (c++-mangle identifier arg-types)
                     identifier))))

(define (%make-c-func-vaargs fptr ret-type arg-types . rest)
  (let-optionals* rest ((identifier #f))
    (let ((nret-type (normalize-ret-type ret-type))
          (narg-types (normalize-arg-types arg-types)))
      (make-c-subr fptr nret-type narg-types #t identifier))))

(define (make-c-func-vaargs identifier ret-type arg-types . opts)
  (let-keywords* opts ((c++? #f))
    (%make-c-func-vaargs #f ret-type arg-types
                         (if c++?
                             (c++-mangle identifier (append arg-types '(ellipsis)))
                             identifier))))

(define-class <c-closure-key> ()
  ((fp-class :init-keyword :fp-class
             :accessor fp-class-of)
   (proc :init-keyword :proc
         :accessor proc-of)))

(define-method object-equal? ((obj1 <c-closure-key>) (obj2 <c-closure-key>))
  (and (equal? (fp-class-of obj1) (fp-class-of obj2))
       (eq? (proc-of obj1) (proc-of obj2))))

(define-method object-hash ((obj <c-closure-key>))
  (hash (fp-class-of obj)))

(define *closure-table* (make-hash-table 'equal?))

(define (make-c-closure fp-class proc)
  (let ((key (make <c-closure-key> :fp-class fp-class :proc proc)))
    (unless (hash-table-exists? *closure-table* key)
      (let* ((cif (errchk ffi-prep-cif
                          (ffi-type-of (ret-type-of fp-class))
                          (map ffi-type-of (arg-types-of fp-class))))
             (closure-obj 
              (errchk ffi-prep-closure cif
                      (lambda args
                        (let ((rvalue (cast (ret-type-of fp-class)
                                            (apply proc (map (lambda (c-type pointer)
                                                               (scm-cast (deref (cast (ptr c-type) pointer))))
                                                             (arg-types-of fp-class)
                                                             args)))))
                          (ptr rvalue))))))
        (hash-table-put! *closure-table* key closure-obj)))
    (cast fp-class (ffi-closure (hash-table-get *closure-table* key)))))

(define (c-closure-free func-ptr)
  (for-each (cut hash-table-delete! *closure-table* <>)
            (hash-table-fold *closure-table*
                             (lambda (key val kons)
                               (if (equal? (buffer-of func-ptr) (ffi-closure val))
                                   (cons key kons)
                                   kons))
                             '())))

;;
;; cast
;;
(define-method cast (class value)
  (if (is-a? value class)
      value
      (errorf "cast ~a to ~a is not allowed." value class)))

(define-method cast (class (obj <c-promise>))
  (cast class (c-force obj)))

(define-method cast ((c-type <c-type-meta>) (value <c-value>))
  (cast c-type (c-value-ref value)))

(define-method cast ((c-type <c-value-meta>) (value <real>))
  (let ((new-value (make c-type)))
    (c-value-set! new-value value)
    new-value))

(define-method cast ((c-type <c-value-meta>) (value <c-basic-ptr>))
  (let ((v (c-ptr-ref value))
        (new-value (make c-type)))
    (c-value-set! new-value v)
    new-value))
    
(define-method cast ((c-type <c-value-meta>) (value <boolean>))
  (let ((new-value (make c-type)))
    (c-value-set! new-value (if value 1 0))
    new-value))
                   
(define-method cast ((c-type <c-basic-ptr-meta>) (num <integer>))
  (if (= num 0)
      (cast c-type (make-null-ptr))
      (let ((new-ptr (make c-type)))
        (c-ptr-set! new-ptr num)
        new-ptr)))

(define-method cast ((c-type <c-basic-ptr-meta>) (p <c-basic-ptr>))
  (make c-type :buffer (buffer-of p)))

(define-method cast ((c-type <c-ptr-meta>) (str <string>))
  (let ((vec (make-u8vector (+ (string-size str) 1) 0)))
    (%ptr-uvector c-type (string->u8vector! vec 0 str))))

(define-method cast ((c-type <c-ptr-meta>) (array <c-array>))
  (%ptr-uvector c-type (buffer-of array)))

(define-method cast ((c-type <c-ptr-meta>) (array <uvector>))
  (%ptr-uvector c-type (uvector-alias <u8vector> array)))

(define-method cast ((c-type <c-ptr-meta>) (seq <sequence>))
  (cast c-type (cast (c-array (orig-c-type-of c-type) (size-of seq)) seq)))

(define-method cast ((c-type <c-ptr-meta>) (fptr <foreign-pointer>))
  (foreign-pointer->c-ptr c-type fptr))

(define-method cast ((c-type <c-array-meta>) (seq <sequence>))
  (let ((array (make c-type)))
    (dotimes (i (size-of seq) array)
      (c-array-set! array i (ref seq i)))))

(define-method cast ((c-type <c-array-meta>) (p <c-ptr>))
  (deref (cast (ptr c-type) p)))

(define-method cast ((c-type <c-func-ptr-meta>) (proc <procedure>))
  (make-c-closure c-type proc))

;; There is no conversion if you change a function-pointer's type to
;; other function-pointer type.
;; Some function pointers which allow any arguments are defined
;; as "ret_type (*fn)()" in header files. This cast rule is for the case.
(define-method cast ((c-type <c-func-ptr-meta>) (func-ptr <c-func-ptr>))
  func-ptr)

;; This cast will be called when c-closure's return is void. 
(define-method cast ((c-type <c-void-meta>) value)
  (make <c-int>))

(define-method cast (class (value <c-value>))
  (cond
   ((eq? class <integer>)
    (x->integer (c-value-ref value)))
   ((memq class (class-precedence-list <real>))
    (c-value-ref value))
   ((eq? class <boolean>)
    (if (= (c-value-ref value) 0) #f #t))
   (else
    (next-method))))

(define-method cast (class (value <real>))
  (cond
   ((eq? class <integer>)
    (x->integer value))
   ((memq class (class-precedence-list <real>))
    value)
   ((eq? class <boolean>)
    (if (= value 0) #f #t))
   (else
    (next-method))))

(define-method cast (class (value <c-basic-ptr>))
  (cond
   ((memq class (class-precedence-list <integer>))
    (c-ptr-ref value))
   ((eq? class <string>)
      (ptr->string value))
   (else
    (next-method))))

(define-method cast (class (value <c-array>))
  (cast class (ptr value)))

(define-method cast ((coll-class <class>) (array <c-array>))
  (if (memq <collection> (class-precedence-list coll-class))
      (map-to coll-class scm-cast array)
      (next-method)))

(define-method scm-cast ((obj <c-promise>))
  (scm-cast (c-force obj)))

(define-method scm-cast ((value <c-value>))
  (c-value-ref value))

(define-method scm-cast ((value <c-void>))
  (undefined))

(define-method scm-cast (obj)
  obj)

(define-method c-cast ((v <integer>))
  (define (containable? type v signed?)
    (let ((size (* (c-sizeof-type type) 8)))
      ((case (- size (if signed? 1 0))
         ((7)  (cut <=                 -128 <>                  127))
         ((8)  (cut <=                    0 <>                  255))
         ((15) (cut <=               -32768 <>                32767))
         ((16) (cut <=                    0 <>                65535))
         ((31) (cut <=          -2147483648 <>           2147483647))
         ((32) (cut <=                    0 <>           4294967295))
         ((63) (cut <= -9223372036854775808 <>  9223372036854775807))
         ((64) (cut <=                    0 <> 18446744073709551616))
         (else (lambda (x) #f))) v)))
  (cond
   ((containable?       <c-int> v #t) (cast       <c-int> v))
   ((containable?      <c-uint> v #f) (cast      <c-uint> v))
   ((containable?      <c-long> v #t) (cast      <c-long> v))
   ((containable?     <c-ulong> v #f) (cast     <c-ulong> v))
   ((containable?  <c-longlong> v #t) (cast  <c-longlong> v))
   ((containable? <c-ulonglong> v #f) (cast <c-ulonglong> v))
   (else
    (next-method))))

(define-method c-cast ((v <real>))
  (cast <c-double> v))

(define-method c-cast ((v <foreign-pointer>))
  (cast (ptr <c-void>) v))

(define-method c-cast ((v <c-promise>))
  (c-cast (c-force v)))

(define-method c-cast ((v <c-type>))
  v)

(define-method c-cast (v)
  v)

(define-method x->string ((obj <c-ptr>))
  (cast <string> obj))

(define-method x->string ((obj <c-array>))
  (cast <string> (ptr obj)))

(define-method x->number ((obj <c-value>))
  (cast <real> obj))

(provide "c-wrapper/c-ffi")
