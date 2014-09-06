;;;
;;; Test ctypes
;;;

(use gauche.test)

(test-start "c-types")
(use c-wrapper)
(use gauche.sequence)
(use gauche.config)
(test-module 'c-wrapper)

(define DYLIB (string-append "./ffitest." (gauche-config "--dylib-suffix")))
(c-load-library DYLIB)

(define (make-c-struct tagname decl-alist)
  (eval `(define-c-struct ,tagname) (current-module))
  (init-c-struct! (c-struct tagname) decl-alist)
  (c-struct tagname))

(define (make-c-union tagname decl-alist)
  (eval `(define-c-union ,tagname) (current-module))
  (init-c-union! (c-union tagname) decl-alist)
  (c-union tagname))

(define-syntax test-cfunc
  (syntax-rules ()
    ((_ expected func-name c-type v1 v2)
     (test func-name
           expected
           (lambda ()
             (let ((func (make-c-func (string->symbol func-name)
                                      c-type
                                      (list c-type c-type))))
               (func v1 v2)))))))

(test-cfunc 3 "add_uchar" <c-uchar> 2 1)
(test-cfunc 3 "add_ushort" <c-ushort> 2 1)
(test-cfunc 3 "add_uint" <c-uint> 2 1)
(test-cfunc 3 "add_ulong" <c-ulong> 2 1)
(test-cfunc 3 "add_ulonglong" <c-ulonglong> 2 1)
(test-cfunc -1 "add_schar" <c-char> -2 1)
(test-cfunc -1 "add_sshort" <c-short> -2 1)
(test-cfunc -1 "add_sint" <c-int> -2 1)
(test-cfunc -1 "add_slong" <c-long> -2 1)
(test-cfunc -1 "add_slonglong" <c-longlong> -2 1)
(test-cfunc 2.5 "add_float" <c-float> 5 -2.5)
(test-cfunc 2.5 "add_double" <c-double> 5 -2.5)
(test "add_string"
      "Hello, world"
      (lambda ()
        (let ((func (make-c-func 'add_string
                                 (ptr <c-uchar>)
                                 (list (ptr <c-uchar>) (ptr <c-uchar>)))))
          (cast <string> (func "Hello, " "world")))))

(define-syntax test-carray
  (syntax-rules ()
    ((_ expected func-name c-type class v1 v2)
     (test func-name
           expected
           (lambda ()
             (let* ((array-class (c-type (length v1)))
                    (func (make-c-func (string->symbol func-name)
                                       (ptr c-type)
                                       (list <c-int> (ptr c-type) (ptr c-type)))))
               (map (cut cast class <>)
                    (cast array-class
                          (func (length v1) v1 v2)))))))))

(test-carray '(5 7 9) "add_array_uchar" <c-uchar> <real> '(1 2 3) '(4 5 6))
(test-carray '(5 7 9) "add_array_ushort" <c-ushort> <real> '(1 2 3) '(4 5 6))
(test-carray '(5 7 9) "add_array_uint" <c-uint> <real> '(1 2 3) '(4 5 6))
(test-carray '(5 7 9) "add_array_ulong" <c-ulong> <real> '(1 2 3) '(4 5 6))
(test-carray '(5 7 9) "add_array_ulonglong" <c-ulonglong> <real>
             '(1 2 3) '(4 5 6))
(test-carray '(5 -7 9) "add_array_schar" <c-char> <real> '(1 2 3) '(4 -9 6))
(test-carray '(5 -7 9) "add_array_sshort" <c-short> <real> '(1 2 3) '(4 -9 6))
(test-carray '(5 -7 9) "add_array_sint" <c-int> <real> '(1 2 3) '(4 -9 6))
(test-carray '(5 -7 9) "add_array_slong" <c-long> <real> '(1 2 3) '(4 -9 6))
(test-carray '(5 -7 9) "add_array_slonglong" <c-longlong> <real>
             '(1 2 3) '(4 -9 6))
(test-carray '(-0.5 0.0 0.5) "add_array_float" <c-float> <real>
             '(-1 1.5 1.75) '(0.5 -1.5 -1.25))
(test-carray '(-0.5 0.0 0.5) "add_array_double" <c-double> <real>
             '(-1 1.5 1.75) '(0.5 -1.5 -1.25))
(test-carray '("foo1" "bar2" "baz3") "add_array_string" (ptr <c-uchar>) <string>
             '("foo" "bar" "baz") '("1" "2" "3"))

(define-syntax test-cstruct
  (syntax-rules ()
    ((_ expected func-name c-type class v1 v2)
     (test func-name
           expected
           (lambda ()
             (let* ((struct-class (make-c-struct (gensym)
                                                 (list (cons 'dummy <c-char>)
                                                       (cons 'value c-type))))
                    (func (make-c-func (string->symbol func-name)
                                       struct-class
                                       (list struct-class struct-class)))
                    (s1 (make struct-class))
                    (s2 (make struct-class)))
               (set! (ref s1 'value) v1)
               (set! (ref s2 'value) v2)
               (cast class (ref (func s1 s2) 'value))))))))

(test-cstruct 3 "add_struct_uchar" <c-uchar> <real> 2 1)
(test-cstruct 3 "add_struct_ushort" <c-ushort> <real> 2 1)
(test-cstruct 3 "add_struct_uint" <c-uint> <real> 2 1)
(test-cstruct 3 "add_struct_ulong" <c-ulong> <real> 2 1)
(test-cstruct 3 "add_struct_ulonglong" <c-ulonglong> <real> 2 1)
(test-cstruct -1 "add_struct_schar" <c-char> <real> -2 1)
(test-cstruct -1 "add_struct_sshort" <c-short> <real> -2 1)
(test-cstruct -1 "add_struct_sint" <c-int> <real> -2 1)
(test-cstruct -1 "add_struct_slong" <c-long> <real> -2 1)
(test-cstruct -1 "add_struct_slonglong" <c-longlong> <real> -2 1)
(test-cstruct 1.5 "add_struct_float" <c-float> <real> 1.75 -0.25)
(test-cstruct 1.5 "add_struct_double" <c-double> <real> 1.75 -0.25)
(test-cstruct "Hello, world" "add_struct_string" (ptr <c-uchar>) <string>
              "Hello, " "world")

(define-syntax test-cstruct-array
  (syntax-rules ()
    ((_ expected func-name c-type class v1 v2)
     (test func-name
           expected
           (lambda ()
             (let* ((array-class (c-type (length v1)))
                    (struct-class (make-c-struct (gensym)
                                                 (list (cons 'dummy <c-char>)
                                                       (cons 'value array-class))))
                    (func (make-c-func (string->symbol func-name)
                                       struct-class
                                       (list struct-class struct-class)))
                    (s1 (make struct-class))
                    (s2 (make struct-class)))
               (set! (ref s1 'value) v1)
               (set! (ref s2 'value) v2)
               (map (cut cast class <>)
                    (ref (func s1 s2) 'value))))))))

(test-cstruct-array '(5 7 9) "add_struct_array_uchar" <c-uchar> <real>
                    '(1 2 3) '(4 5 6))
(test-cstruct-array '(5 7 9) "add_struct_array_ushort" <c-ushort> <real>
                    '(1 2 3) '(4 5 6))
(test-cstruct-array '(5 7 9) "add_struct_array_uint" <c-uint> <real>
                    '(1 2 3) '(4 5 6))
(test-cstruct-array '(5 7 9) "add_struct_array_ulong" <c-ulong> <real>
                    '(1 2 3) '(4 5 6))
(test-cstruct-array '(5 7 9) "add_struct_array_ulonglong" <c-ulonglong> <real>
                    '(1 2 3) '(4 5 6))
(test-cstruct-array '(5 -7 9) "add_struct_array_schar" <c-char> <real>
                    '(1 2 3) '(4 -9 6))
(test-cstruct-array '(5 -7 9) "add_struct_array_sshort" <c-short> <real>
                    '(1 2 3) '(4 -9 6))
(test-cstruct-array '(5 -7 9) "add_struct_array_sint" <c-int> <real>
                    '(1 2 3) '(4 -9 6))
(test-cstruct-array '(5 -7 9) "add_struct_array_slong" <c-long> <real>
                    '(1 2 3) '(4 -9 6))
(test-cstruct-array '(5 -7 9) "add_struct_array_slonglong" <c-longlong> <real>
                    '(1 2 3) '(4 -9 6))
(test-cstruct-array '(-0.5 0.0 0.5) "add_struct_array_float" <c-float> <real>
                    '(-1 1.5 1.75) '(0.5 -1.5 -1.25))
(test-cstruct-array '(-0.5 0.0 0.5) "add_struct_array_double" <c-double> <real>
                    '(-1 1.5 1.75) '(0.5 -1.5 -1.25))
(test-cstruct-array '("foo1" "bar2" "baz3") "add_struct_array_string"
                    (ptr <c-uchar>) <string>
                    '("foo" "bar" "baz") '("1" "2" "3"))

(define-syntax test-cclosure
  (syntax-rules ()
    ((_ expected func-name c-type v1 v2)
     (test func-name
           expected
           (lambda ()
             (let* ((fp-class (c-func-ptr
                               c-type
                               (list c-type c-type)))
                    (func (make-c-func (string->symbol func-name)
                                       c-type
                                       (list fp-class c-type c-type))))
               (func + v1 v2)))))))

(test-cclosure 3 "callback_uchar" <c-uchar> 2 1)
(test-cclosure 3 "callback_ushort" <c-ushort> 2 1)
(test-cclosure 3 "callback_uint" <c-uint> 2 1)
(test-cclosure 3 "callback_ulong" <c-ulong> 2 1)
(test-cclosure 3 "callback_ulonglong" <c-ulonglong> 2 1)
(test-cclosure -1 "callback_schar" <c-char> -2 1)
(test-cclosure -1 "callback_sshort" <c-short> -2 1)
(test-cclosure -1 "callback_sint" <c-int> -2 1)
(test-cclosure -1 "callback_slong" <c-long> -2 1)
(test-cclosure -1 "callback_slonglong" <c-longlong> -2 1)
(test-cclosure 2.5 "callback_float" <c-float> 5 -2.5)
(test-cclosure 2.5 "callback_double" <c-double> 5 -2.5)
(test "callback_string"
      "Hello, world"
      (lambda ()
        (let* ((fp-class (c-func-ptr
                          (ptr <c-uchar>)
                          (list (ptr <c-uchar>) (ptr <c-uchar>))))
               (func (make-c-func 'callback_string
                                  (ptr <c-uchar>)
                                  (list fp-class (ptr <c-uchar>) (ptr <c-uchar>)))))
          (cast <string> (func (lambda (a1 a2)
                                 (string-append (cast <string> a1)
                                                (cast <string> a2)))
                               "Hello, " "world")))))

(define-syntax test-vaarg
  (syntax-rules ()
    ((_ expected func-name in-c-type out-c-type class)
     (test (format "~a (~a)" func-name (class-name in-c-type))
           expected
           (lambda ()
             (let* ((array-class (out-c-type (length expected)))
                    (func (make-c-func-vaargs (string->symbol func-name)
                                              (ptr out-c-type)
                                              (list <c-int>))))
               (map (cut cast class <>)
                    (cast array-class
                          (apply func (length expected)
                                 (map (cut cast in-c-type <>)
                                      expected))))))))))

(test-vaarg '(1 2 3) "vaarg_uint" <c-uint> <c-uint> <real>)
(test-vaarg '(1 2 3) "vaarg_ulong" <c-ulong> <c-ulong> <real>)
(test-vaarg '(1 2 3) "vaarg_ulonglong" <c-ulonglong> <c-ulonglong> <real>)
(test-vaarg '(1 -2 3) "vaarg_sint" <c-int> <c-int> <real>)
(test-vaarg '(1 -2 3) "vaarg_slong" <c-long> <c-long> <real>)
(test-vaarg '(1 -2 3) "vaarg_slonglong" <c-longlong> <c-longlong> <real>)
(test-vaarg '(-0.5 0.0 0.5) "vaarg_double" <c-double> <c-double> <real>)
(test-vaarg '("foo" "bar" "baz") "vaarg_string" (ptr <c-uchar>) (ptr <c-uchar>) <string>)

;; promote type
(test-vaarg '(1 2 3) "vaarg_uint" <c-uchar> <c-uint> <real>)
(test-vaarg '(1 2 3) "vaarg_uint" <c-ushort> <c-uint> <real>)
(test-vaarg '(1 -2 3) "vaarg_sint" <c-char> <c-int> <real>)
(test-vaarg '(1 -2 3) "vaarg_sint" <c-short> <c-int> <real>)
(test-vaarg '(-0.5 0.0 0.5) "vaarg_double" <c-float> <c-double> <real>)

(define-syntax test-union
  (syntax-rules ()
    ((_ expected func-name class name v1 v2)
     (test func-name
           expected
           (lambda ()
             (let* ((union-class (make-c-union
                                  (gensym)
                                  `((c . ,<c-char>)
                                    (s . ,<c-short>)
                                    (i . ,<c-int>)
                                    (l . ,<c-long>)
                                    (ll . ,<c-longlong>)
                                    (f . ,<c-float>)
                                    (d . ,<c-double>)
                                    (str . ,(ptr <c-uchar>)))))
                    (func (make-c-func (string->symbol func-name)
                                       union-class
                                       (list union-class union-class)))
                    (u1 (make union-class))
                    (u2 (make union-class)))
               (set! (ref u1 name) v1)
               (set! (ref u2 name) v2)
               (cast class (ref (func u1 u2) name))))))))

(test-union -10 "test_union_c" <real> 'c -15 5)
(test-union -10 "test_union_s" <real> 's -9 -1)
(test-union -10 "test_union_i" <real> 'i 20 -30)
(test-union -10 "test_union_l" <real> 'l 10000000 -10000010)
(test-union -10 "test_union_ll" <real> 'll 0 -10)
(test-union -1.75 "test_union_f" <real> 'f -1 -0.75)
(test-union 0.5 "test_union_d" <real> 'd 3.75 -3.25)
(test-union "foobar" "test_union_str" <string> 'str "foo" "bar")

(test "test_modify" 
      2
      (lambda ()
        (let ((test_modify (make-c-func 'test_modify <c-void> (list (ptr <c-int>))))
              (v (make <c-int>)))
          (set! (ref v) 1)
          (test_modify (ptr v))
          (ref v))))

(test "null-ptr?"
      #t
      (lambda ()
        (null-ptr? (make-null-ptr))))

;; epilogue
(test-end)

