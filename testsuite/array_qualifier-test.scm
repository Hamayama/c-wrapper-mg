;;;
;;; Test array qualifier (C99)
;;; 

(use gauche.test)

(test-start "array_qualifier")
(use c-wrapper)
(test-module 'c-wrapper)

(c-include "./array_qualifier.h")

(test "static"
      (list (ptr <c-int>))
      (lambda ()
        (let ((a (make (c-struct 'foo))))
          (slot-ref (class-of (ref a 'f1)) 'arg-types))))

(test "restrict"
      (list (ptr <c-int>))
      (lambda ()
        (let ((a (make (c-struct 'foo))))
          (slot-ref (class-of (ref a 'f2)) 'arg-types))))

(test "const"
      (list (ptr <c-int>))
      (lambda ()
        (let ((a (make (c-struct 'foo))))
          (slot-ref (class-of (ref a 'f3)) 'arg-types))))

(test "volatile"
      (list (ptr <c-int>))
      (lambda ()
        (let ((a (make (c-struct 'foo))))
          (slot-ref (class-of (ref a 'f4)) 'arg-types))))

;; epilogue
(test-end)

