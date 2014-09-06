;;;
;;; inline function test
;;;

(use gauche.test)

(test-start "c-wrapper (inline)")
(use c-wrapper)

(c-load-library "libc")
(c-load-library "./ffitest")
(c-include '("stdio.h" "stdlib.h" "./ffitest.h"))

(test "constant"
      1
      (lambda ()
        (return_const)))

(test "string"
      "foo"
      (lambda ()
        (x->string (return_string))))

(test "ref array"
      10
      (lambda ()
        (let ((a (make (c-array <c-int> 3))))
          (set! (ref a 0) 0)
          (set! (ref a 1) 10)
          (set! (ref a 2) 20)
          (ref_array a))))

(test "func call without argument"
      '(-2 -1 0 1 2)
      (lambda ()
        (funccall1)
        (list (ref test_array 0)
              (ref test_array 1)
              (ref test_array 2)
              (ref test_array 3)
              (ref test_array 4))))

(test "func call with arguments"
      3
      (lambda ()
        (funcall2 1 2)))

(test "ref struct (. operator)"
      1
      (lambda ()
        (ref_struct1)))

(test "ref struct (-> operator)"
      1
      (lambda ()
        (let ((a (make (c-struct 'test_sint))))
          (set! (ref a 'value) 1)
          (ref_struct2 (ptr a)))))


(test "post increment"
      2
      (lambda ()
        (post_inc)))

(test "post decrement"
      1
      (lambda ()
        (post_dec)))

(test "pre increment"
      2
      (lambda ()
        (pre_inc)))

(test "pre decrement"
      1
      (lambda ()
        (pre_dec)))

(test "unary plus"
      1
      (lambda ()
        (unary_plus)))

(test "unary minus"
      -1
      (lambda ()
        (unary_minus)))

(test "unary logical negation"
      '(0 1)
      (lambda ()
        (list (unary_logneg 1) (unary_logneg 0))))

(test "unary bitwise negation"
      -2
      (lambda ()
        (unary_bitneg 1)))

(test "unary reference"
      123
      (lambda ()
        (unary_ref)))

(test "unary dereference"
      456
      (lambda ()
        (ref (deref (unary_deref)))))

(test "sizeof"
      #t
      (lambda ()
        (eq? (c-sizeof <c-int>) (op_sizeof))))

(test "mul"
      6
      (lambda ()
        (mul 2 3)))

(test "divi"
      3
      (lambda ()
        (divi 18 6)))

(test "mod"
      1
      (lambda ()
        (mod 5 2)))

(test "add"
      3
      (lambda ()
        (add 1 2)))

(test "sub"
      -1
      (lambda ()
        (sub 1 2)))

(test "left shift"
      4
      (lambda ()
        (left_shift 1 2)))

(test "right shift"
      2
      (lambda ()
        (right_shift 8 2)))

(test "lesser than"
      '(1 0 0)
      (lambda  ()
        (list (op_lt 1 2) (op_lt 2 2) (op_lt 2 1))))

(test "greater than"
      '(0 0 1)
      (lambda  ()
        (list (op_gt 1 2) (op_gt 2 2) (op_gt 2 1))))

(test "lesser than or equal" 
      '(1 1 0)
      (lambda  ()
        (list (op_lteq 1 2) (op_lteq 2 2) (op_lteq 2 1))))

(test "greater than or equal"
      '(0 1 1)
      (lambda  ()
        (list (op_gteq 1 2) (op_gteq 2 2) (op_gteq 2 1))))

(test "equal"
      '(0 1 0)
      (lambda  ()
        (list (op_eq 1 2) (op_eq 2 2) (op_eq 2 1))))

(test "not equal"
      '(1 0 1)
      (lambda  ()
        (list (op_noteq 1 2) (op_noteq 2 2) (op_noteq 2 1))))

(test "bitwise and"
      1
      (lambda ()
        (bitand 11 5)))

(test "bitwise or"
      15
      (lambda ()
        (bitor 11 5)))

(test "bitwise xor"
      14
      (lambda ()
        (bitxor 11 5)))

(test "logical and"
      '(1 0 0 0)
      (lambda ()
        (list (op_logand 1 1 1)
              (op_logand 1 1 0)
              (op_logand 0 1 1)
              (op_logand 0 1 0))))

(test "logical or"
      '(1 1 1 0)
      (lambda ()
        (list (op_logor 1 1 1)
              (op_logor 1 1 0)
              (op_logor 0 1 1)
              (op_logor 0 1 0))))

(test "assign mul"
      6
      (lambda ()
        (assign_mul 2 3)))

(test "assign div"
      3
      (lambda ()
        (assign_div 18 6)))

(test "assign mod"
      1
      (lambda ()
        (assign_mod 5 2)))

(test "assign_add"
      3
      (lambda ()
        (assign_add 1 2)))

(test "assign_sub"
      -1
      (lambda ()
        (assign_sub 1 2)))

(test "assign left shift"
      4
      (lambda ()
        (assign_left_shift 1 2)))

(test "assign right shift"
      2
      (lambda ()
        (assign_right_shift 8 2)))

(test "assign bitwise and"
      1
      (lambda ()
        (assign_bitand 11 5)))

(test "assign bitwise or"
      15
      (lambda ()
        (assign_bitor 11 5)))

(test "assign bitwise xor"
      14
      (lambda ()
        (assign_bitxor 11 5)))

(test "multi expr"
      10
      (lambda ()
        (multi_expr 2 5)))

(test "while"
      55
      (lambda ()
        (test_while)))
               
(test "while break"
      55
      (lambda ()
        (test_while_break)))
               
(test "while continue"
      55
      (lambda ()
        (test_while_continue)))
               
(test "do while"
      55
      (lambda ()
        (test_dowhile)))
               
(test "do while break"
      55
      (lambda ()
        (test_dowhile_break)))
               
(test "do while continue"
      0
      (lambda ()
        (test_dowhile_continue)))
               
(test "for"
      55
      (lambda ()
        (test_for)))
               
(test "for noinit, notest, noupdate"
      55
      (lambda ()
        (test_for_noinit_notest_noupdate)))
               
(test "for noinit, notest"
      55
      (lambda ()
        (test_for_noinit_notest)))
               
(test "for noinit, noupdate"
      55
      (lambda ()
        (test_for_noinit_noupdate)))
               
(test "for noinit"
      55
      (lambda ()
        (test_for_noinit_noupdate)))

(test "for notest, noupdate"
      55
      (lambda ()
        (test_for_notest_noupdate)))
               
(test "for notest"
      55
      (lambda ()
        (test_for_notest)))
               
(test "for noupdate"
      55
      (lambda ()
        (test_for_noupdate)))

(test "offset"
      #t
      (lambda ()
        (eq? (offset_calc) (c-offsetof (c-struct 'test_uchar) 'value))))

(test "not_supported"
      #t
      (lambda ()
        (procedure? not_supported)))

;; epilogue
(test-end)

