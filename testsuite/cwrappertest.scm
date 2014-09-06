;;;
;;; Test c-wrapper
;;;

(use gauche.test)

(test-start "c-wrapper")
(use c-wrapper)
(use gauche.sequence)
(test-module 'c-wrapper)

(c-load-library "./ffitest")
(c-include "./ffitest.h")

(define-syntax test-cfunc
  (syntax-rules ()
    ((_ expected func v1 v2)
     (test (symbol->string 'func)
           expected
           (lambda ()
               (func v1 v2))))))

(test-cfunc 3 add_uchar 2 1)
(test-cfunc 3 add_ushort 2 1)
(test-cfunc 3 add_uint 2 1)
(test-cfunc 3 add_ulong 2 1)
(test-cfunc 3 add_ulonglong 2 1)
(test-cfunc -1 add_schar -2 1)
(test-cfunc -1 add_sshort -2 1)
(test-cfunc -1 add_sint -2 1)
(test-cfunc -1 add_slong -2 1)
(test-cfunc -1 add_slonglong -2 1)
(test-cfunc 2.5 add_float 5 -2.5)
(test-cfunc 2.5 add_double 5 -2.5)
(test "add_string"
      "Hello, world"
      (lambda ()
        (x->string (add_string "Hello, " "world"))))

(define-syntax test-carray
  (syntax-rules ()
    ((_ expected func c-type class v1 v2)
     (test (symbol->string 'func)
           expected
           (lambda ()
             (map (cut cast class <>)
                  (cast (c-type (length v1))
                        (func (length v1) v1 v2))))))))

(test-carray '(5 7 9) add_array_uchar <c-uchar> <real> '(1 2 3) '(4 5 6))
(test-carray '(5 7 9) add_array_ushort <c-ushort> <real> '(1 2 3) '(4 5 6))
(test-carray '(5 7 9) add_array_uint <c-uint> <real> '(1 2 3) '(4 5 6))
(test-carray '(5 7 9) add_array_ulong <c-ulong> <real> '(1 2 3) '(4 5 6))
(test-carray '(5 7 9) add_array_ulonglong <c-ulonglong> <real>
             '(1 2 3) '(4 5 6))

(test-carray '(5 -7 9) add_array_schar <c-char> <real> '(1 2 3) '(4 -9 6))
(test-carray '(5 -7 9) add_array_sshort <c-short> <real> '(1 2 3) '(4 -9 6))
(test-carray '(5 -7 9) add_array_sint <c-int> <real> '(1 2 3) '(4 -9 6))
(test-carray '(5 -7 9) add_array_slong <c-long> <real> '(1 2 3) '(4 -9 6))
(test-carray '(5 -7 9) add_array_slonglong <c-longlong> <real>
             '(1 2 3) '(4 -9 6))
(test-carray '(-0.5 0.0 0.5) add_array_float <c-float> <real>
             '(-1 1.5 1.75) '(0.5 -1.5 -1.25))
(test-carray '(-0.5 0.0 0.5) add_array_double <c-double> <real>
             '(-1 1.5 1.75) '(0.5 -1.5 -1.25))
(test-carray '("foo1" "bar2" "baz3") add_array_string (ptr <c-uchar>) <string>
             '("foo" "bar" "baz") '("1" "2" "3"))

(define-syntax test-cstruct
  (syntax-rules ()
    ((_ expected func tagname class v1 v2)
     (test (symbol->string 'func)
           expected
           (lambda ()
             (let ((s1 (make tagname))
                   (s2 (make tagname)))
               (set! (ref s1 'value) v1)
               (set! (ref s2 'value) v2)
               (cast class (ref (func s1 s2) 'value))))))))

(test-cstruct 3 add_struct_uchar (c-struct 'test_uchar) <real> 2 1)
(test-cstruct 3 add_struct_ushort (c-struct 'test_ushort) <real> 2 1)
(test-cstruct 3 add_struct_uint (c-struct 'test_uint) <real> 2 1)
(test-cstruct 3 add_struct_ulong (c-struct 'test_ulong) <real> 2 1)
(test-cstruct 3 add_struct_ulonglong (c-struct 'test_ulonglong) <real> 2 1)
(test-cstruct -1 add_struct_schar (c-struct 'test_schar) <real> -2 1)
(test-cstruct -1 add_struct_sshort (c-struct 'test_sshort) <real> -2 1)
(test-cstruct -1 add_struct_sint (c-struct 'test_sint) <real> -2 1)
(test-cstruct -1 add_struct_slong (c-struct 'test_slong) <real> -2 1)
(test-cstruct -1 add_struct_slonglong (c-struct 'test_slonglong) <real> -2 1)
(test-cstruct 1.5 add_struct_float (c-struct 'test_float) <real> 1.75 -0.25)
(test-cstruct 1.5 add_struct_double (c-struct 'test_double) <real> 1.75 -0.25)
(test-cstruct "Hello, world" add_struct_string (c-struct 'test_string) <string>
              "Hello, " "world")

(define-syntax test-cstruct-array
  (syntax-rules ()
    ((_ expected func tagname class v1 v2)
     (test (symbol->string 'func)
           expected
           (lambda ()
             (let* ((s1 (make tagname))
                    (s2 (make tagname)))
               (set! (ref s1 'value) v1)
               (set! (ref s2 'value) v2)
               (map (cut cast class <>)
                    (ref (func s1 s2) 'value))))))))

(test-cstruct-array '(5 7 9) add_struct_array_ushort
                    (c-struct 'test_array_ushort)
                    <real>
                    '(1 2 3) '(4 5 6))
(test-cstruct-array '(5 7 9) add_struct_array_uint
                    (c-struct 'test_array_uint)
                    <real>
                    '(1 2 3) '(4 5 6))
(test-cstruct-array '(5 7 9) add_struct_array_ulong
                    (c-struct 'test_array_ulong)
                    <real>
                    '(1 2 3) '(4 5 6))
(test-cstruct-array '(5 7 9) add_struct_array_ulonglong
                    (c-struct 'test_array_ulonglong)
                    <real>
                    '(1 2 3) '(4 5 6))
(test-cstruct-array '(5 -7 9) add_struct_array_schar
                    (c-struct 'test_array_schar)
                    <real>
                    '(1 2 3) '(4 -9 6))
(test-cstruct-array '(5 -7 9) add_struct_array_sshort
                    (c-struct 'test_array_sshort)
                    <real>
                    '(1 2 3) '(4 -9 6))
(test-cstruct-array '(5 -7 9) add_struct_array_sint
                    (c-struct 'test_array_sint)
                    <real>
                    '(1 2 3) '(4 -9 6))
(test-cstruct-array '(5 -7 9) add_struct_array_slong
                    (c-struct 'test_array_slong)
                    <real>
                    '(1 2 3) '(4 -9 6))
(test-cstruct-array '(5 -7 9) add_struct_array_slonglong
                    (c-struct 'test_array_slonglong)
                    <real>
                    '(1 2 3) '(4 -9 6))
(test-cstruct-array '(-0.5 0.0 0.5) add_struct_array_float
                    (c-struct 'test_array_float)
                    <real>
                    '(-1 1.5 1.75) '(0.5 -1.5 -1.25))
(test-cstruct-array '(-0.5 0.0 0.5) add_struct_array_double
                    (c-struct 'test_array_double)
                    <real>
                    '(-1 1.5 1.75) '(0.5 -1.5 -1.25))
(test-cstruct-array '("foo1" "bar2" "baz3") add_struct_array_string
                    (c-struct 'test_array_string)
                    <string>
                    '("foo" "bar" "baz") '("1" "2" "3"))

(define-syntax test-cclosure
  (syntax-rules ()
    ((_ expected func v1 v2)
     (test (symbol->string 'func)
           expected
           (lambda ()
               (func + v1 v2))))))

(test-cclosure 3 callback_uchar 2 1)
(test-cclosure 3 callback_ushort 2 1)
(test-cclosure 3 callback_uint 2 1)
(test-cclosure 3 callback_ulong 2 1)
(test-cclosure 3 callback_ulonglong 2 1)
(test-cclosure -1 callback_schar -2 1)
(test-cclosure -1 callback_sshort -2 1)
(test-cclosure -1 callback_sint -2 1)
(test-cclosure -1 callback_slong -2 1)
(test-cclosure -1 callback_slonglong -2 1)
(test-cclosure 2.5 callback_float 5 -2.5)
(test-cclosure 2.5 callback_double 5 -2.5)
(test "callback_string"
      "Hello, world"
      (lambda ()
        (x->string (callback_string (lambda (a1 a2)
                                      (string-append (x->string a1)
                                                     (x->string a2)))
                                    "Hello, " "world"))))

(define-syntax test-vaarg
  (syntax-rules ()
    ((_ expected func in-c-type out-c-type class)
     (test (symbol->string 'func)
           expected
           (lambda ()
             (let* ((array-class (out-c-type (length expected))))
               (map (cut cast class <>)
                    (cast array-class
                          (apply func (length expected)
                                 (map (cut cast in-c-type <>)
                                      expected))))))))))

(test-vaarg '(1 2 3) vaarg_uint <c-uint> <c-uint> <real>)
(test-vaarg '(1 2 3) vaarg_ulong <c-ulong> <c-ulong> <real>)
(test-vaarg '(1 2 3) vaarg_ulonglong <c-ulonglong> <c-ulonglong> <real>)
(test-vaarg '(1 -2 3) vaarg_sint <c-int> <c-int> <real>)
(test-vaarg '(1 -2 3) vaarg_slong <c-long> <c-long> <real>)
(test-vaarg '(1 -2 3) vaarg_slonglong <c-longlong> <c-longlong> <real>)
(test-vaarg '(-0.5 0.0 0.5) vaarg_double <c-double> <c-double> <real>)
(test-vaarg '("foo" "bar" "baz") vaarg_string
            (ptr <c-uchar>) (ptr <c-uchar>) <string>)

(define-syntax test-union
  (syntax-rules ()
    ((_ expected func class name v1 v2)
     (test (symbol->string 'func)
           expected
           (lambda ()
             (let ((u1 (make (c-union 'test)))
                   (u2 (make (c-union 'test))))
               (set! (ref u1 name) v1)
               (set! (ref u2 name) v2)
               (cast class (ref (func u1 u2) name))))))))

(test-union -10 test_union_c <real> 'c -15 5)
(test-union -10 test_union_s <real> 's -9 -1)
(test-union -10 test_union_i <real> 'i 20 -30)
(test-union -10 test_union_l <real> 'l 10000000 -10000010)
(test-union -10 test_union_ll <real> 'll 0 -10)
(test-union -1.75 test_union_f <real> 'f -1 -0.75)
(test-union 0.5 test_union_d <real> 'd 3.75 -3.25)
(test-union "foobar" test_union_str <string> 'str "foo" "bar")

(test "test_var"
      '(-1 -2 -3 -4 -5 5 4 3 2 1 -0.5 0.5 "foobar")
      (lambda ()
        (set! (ref var_char) -2)
        (set! (ref var_short) -3)
        (set! (ref var_int) -4)
        (set! (ref var_long) -5)
        (set! (ref var_longlong) -6)
        (set! (ref var_uchar) 4)
        (set! (ref var_ushort) 3)
        (set! (ref var_uint) 2)
        (set! (ref var_ulong) 1)
        (set! (ref var_ulonglong) 0)
        (set! (ref var_float) -1.75)
        (set! (ref var_double) -0.75)
        (set! (ref var_string) "foo")
        (test_var)
        (list (ref var_char)
              (ref var_short)
              (ref var_int)
              (ref var_long)
              (ref var_longlong)
              (ref var_uchar)
              (ref var_ushort)
              (ref var_uint)
              (ref var_ulong)
              (ref var_ulonglong)
              (ref var_float)
              (ref var_double)
              (x->string var_string))))

(test "incomplete_array(ref)"
      '(1 -2 123)
      (lambda ()
        (list (ref incomplete_array 0)
              (ref incomplete_array 1)
              (ref incomplete_array 2))))

(test "incomplete_array(set!)"
      '(5 -2 -321)
      (lambda ()
        (set! (ref incomplete_array 0) 5)
        (set! (ref incomplete_array 2) -321)
        (list (ref incomplete_array 0)
              (ref incomplete_array 1)
              (ref incomplete_array 2))))

(test "test_null_ptr (make-null-ptr)"
      #t
      (lambda ()
        (not (= 0 (test_null_ptr (make-null-ptr))))))

(test "test_null_ptr (0)"
      #t
      (lambda ()
        (not (= 0 (test_null_ptr 0)))))

(test "test_null_func_ptr (make-null-ptr)"
      #t
      (lambda ()
        (not (= 0 (test_null_func_ptr (make-null-ptr))))))

(test "test_null_func_ptr (0)"
      #t
      (lambda ()
        (not (= 0 (test_null_func_ptr 0)))))

(test "test post++"
      '(3 4)
      (lambda ()
        (c-value-set! test_val 3)
        (let ((x (post_pp test_val)))
          (list x (test_val)))))

(test "test post--"
      '(3 2)
      (lambda ()
        (c-value-set! test_val 3)
        (let ((x (post_mm test_val)))
          (list x (test_val)))))

(test "test pre++"
      '(4 4)
      (lambda ()
        (c-value-set! test_val 3)
        (let ((x (pre_pp test_val)))
          (list x (test_val)))))

(test "test pre--"
      '(2 2)
      (lambda ()
        (c-value-set! test_val 3)
        (let ((x (pre_mm test_val)))
          (list x (test_val)))))

(test "test post++ (pointer)"
      '(-2 -1)
      (lambda ()
        (init_test_ptr)
        (let ((x (post_pp test_ptr)))
          (list ((deref x)) ((deref test_ptr))))))

(test "test post-- (pointer)"
      '(-1 -2)
      (lambda ()
        (init_test_ptr)
        (post++ test_ptr)
        (let ((x (post_mm test_ptr)))
          (list ((deref x)) ((deref test_ptr))))))

(test "test pre++ (pointer)"
      '(-1 -1)
      (lambda ()
        (init_test_ptr)
        (let ((x (pre_pp test_ptr)))
          (list ((deref x)) ((deref test_ptr))))))

(test "test pre-- (pointer)"
      '(-2 -2)
      (lambda ()
        (init_test_ptr)
        (pre++ test_ptr)
        (let ((x (pre_mm test_ptr)))
          (list ((deref x)) ((deref test_ptr))))))

(test "test plus (value)"
      5
      (lambda ()
        (plus 2 3)))

(test "test minus (value)"
      3
      (lambda ()
        (let ((v1 (make <c-int>))
              (v2 (make <c-int>)))
          (v1 5)
          (v2 2)
        (minus v1 v2))))

(test "test plus (pointer)"
      1
      (lambda ()
        (init_test_ptr)
        ((deref (plus test_ptr 3)))))

(test "test minus (pointer)"
      -1
      (lambda ()
        (init_test_ptr)
        ((deref (minus (plus test_ptr 3) 2)))))

(test "test bitfield"
      '(-2 2 2 -30001 3)
      (lambda ()
        (let ((dat (make (c-struct 'bitfield_rec))))
          (c-struct-set! dat 'v1 -1)
          (c-struct-set! dat 'v2 1)
          (c-struct-set! dat 'v3 1)
          (c-struct-set! dat 'v4 -30000)
          (c-struct-set! dat 'v5 2)
          (let ((newdat (test_bitfield dat)))
            (list (c-struct-ref newdat 'v1)
                  (c-struct-ref newdat 'v2)
                  (c-struct-ref newdat 'v3)
                  (c-struct-ref newdat 'v4)
                  (c-struct-ref newdat 'v5))))))

(test "test sizeof struct which has bitfields"
      (expected_sizeof_bitfield_rec2)
      (lambda ()
        (c-sizeof (c-struct 'bitfield_rec2))))

(test "test bitfield2"
      '(8191 2)
      (lambda ()
        (let ((dat (make (c-struct 'bitfield_rec2))))
          (c-struct-set! dat 'v1 8190)
          (c-struct-set! dat 'v2 1)
          (let ((newdat (test_bitfield2 dat)))
            (list (c-struct-ref newdat 'v1)
                  (c-struct-ref newdat 'v2))))))
               
(test "test macro function #1"
      '(1 0)
      (lambda ()
        (let ((v1 (make <c-int>))
              (v2 (make <c-int>)))
          (v1 0)
          (v2 0)
          (IFMAC 1 (post++ v1) (post++ v2))
          (list (v1) (v2)))))

(test "test macro function #2"
      '(0 1)
      (lambda ()
        (let ((v1 (make <c-int>))
              (v2 (make <c-int>)))
          (v1 0)
          (v2 0)
          (IFMAC 0 (post++ v1) (post++ v2))
          (list (v1) (v2)))))

(test "ignore function-like macro when an argument is used as a type."
      #f
      (lambda ()
        (global-variable-bound? (current-module) 'FUNCLIKE_MACRO_USING_TYPE_PARAM)))

(test "test function parameter"
      "foobar"
      (lambda ()
        (x->string (param_func_test malloc))))

(test "test dereference of a function pointer"
      3
      (lambda ()
        ((deref (get_fptr)) 1 2)))

(test "object-apply of a function pointer"
      3
      (lambda ()
        ((get_fptr) 1 2)))

(test "test (setter ref) for a pointer"
      3
      (lambda ()
        (let* ((v1 (make (c-array <c-int> 10)))
               (v2 (cast (ptr <c-int>) v1)))
          (set! (ref v2 5) 3)
          (ref v1 5))))

(test "test variable attribute 'mode' QI"
      <c-char>
      (lambda ()
        (class-of test_qi)))

(test "test variable attribute 'mode' HI"
      <c-short>
      (lambda ()
        (class-of test_hi)))

(test "test variable attribute 'mode' SI"
      <c-int>
      (lambda ()
        (class-of test_si)))

(test "test variable attribute 'mode' DI"
      <c-longlong>
      (lambda ()
        (class-of test_di)))

(test "test variable attribute 'mode' QI (unsigned)"
      <c-uchar>
      (lambda ()
        (class-of test_uqi)))

(test "test variable attribute 'mode' HI (unsigned)"
      <c-ushort>
      (lambda ()
        (class-of test_uhi)))

(test "test variable attribute 'mode' SI (unsigned)"
      <c-uint>
      (lambda ()
        (class-of test_usi)))

(test "test variable attribute 'mode' DI (unsigned)"
      <c-ulonglong>
      (lambda ()
        (class-of test_udi)))

(test "test variable attribute 'mode' SF"
      <c-float>
      (lambda ()
        (class-of test_sf)))

(test "test variable attribute 'mode' DF"
      <c-double>
      (lambda ()
        (class-of test_df)))

(test "test variable attribute 'mode' for struct"
      (list <c-char> <c-short> <c-int> <c-longlong>
            <c-uchar> <c-ushort> <c-uint> <c-ulonglong>
            <c-float> <c-double>)
      (lambda ()
        (let ((s (make (c-struct 'test_attr_mode_rec))))
          (map (lambda (name)
                 (class-of (raw-ref s name)))
               '(test_qi test_hi test_si test_di test_uqi test_uhi test_usi test_udi
                         test_sf test_df)))))

(test "test variable attribute 'mode' for function argument"
      '(127                  ; 2^7  - 1
        32767                ; 2^15 - 1
        2147483647           ; 2^31 - 1
        9223372036854775807  ; 2^63 - 1
        255                  ; 2^8  - 1
        65535                ; 2^16 - 1
        4294967295           ; 2^32 - 1
        18446744073709551615 ; 2^64 - 1
        0.5
        1.0e300
        )
      (lambda ()
        (test_attr_mode 127 32767 2147483647 9223372036854775807
                        255 65535 4294967295 18446744073709551615
                        0.5 1.0e300)
        (map scm-cast (list test_qi test_hi test_si test_di
                            test_uqi test_uhi test_usi test_udi
                            test_sf test_df))))

(test "test variable-like macro"
      '(1 2 3)
      (lambda ()
        (reset_counter)
        (do ((lst '() (cons (COUNTER) lst))
             (i 0 (+ i 1)))
            ((<= 3 i) (reverse lst)))))

(test "test suppress using function-like macro"
      3
      (lambda ()
        (confusing_func2 1 2)))

;; epilogue
(test-end)

