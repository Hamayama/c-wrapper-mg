;;;
;;; Test typename in declaration
;;; 

(use gauche.test)

(test-start "typename_in_declaration")
(use c-wrapper)
(test-module 'c-wrapper)

(c-include "./typename_in_declaration.h")

(test "has a member"
      (cons 'foo (c-func-ptr <c-void> (list (ptr <c-void>))))
      (lambda ()
        (assoc 'foo (slot-ref <bar> 'decl-alist))))

(test "typename after dot"
    (cast (ptr <c-void>) 1)
  (lambda ()
    (let ((bar (make <bar>)))
      (set! (ref bar 'foo) 1)
      (get_foo1 bar))))

(test "typename after ->"
    (cast (ptr <c-void>) 2)
  (lambda ()
    (let ((bar (make <bar>)))
      (set! (ref bar 'foo) 2)
      (get_foo2 (ptr bar)))))

;; epilogue
(test-end)

