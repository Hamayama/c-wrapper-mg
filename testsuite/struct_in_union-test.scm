;;;
;;; Test struct_in_union 
;;; 

(use gauche.test)

(test-start "struct_in_union")
(use c-wrapper)
(test-module 'c-wrapper)

(c-include "./struct_in_union.h")

(test "reference"
      0
      (lambda ()
        (ref (ref (ref (make <c-struct:struct_in_union>) 'u) 's1) 'v1)))

(test "set"
      1
      (lambda ()
        (let ((struct (make <c-struct:struct_in_union>)))
          (set! (ref (ref (ref struct 'u) 's1) 'v1) 1)
          (ref (ref (ref struct 'u) 's1) 'v1))))

(test "a union in an array"
      2
      (lambda ()
        (let ((array (make (<c-struct:struct_in_union> 3))))
          (set! (ref (ref (ref (ref array 1) 'u) 's1) 'v1) 2)
          (ref (ref (ref (ref array 1) 'u) 's1) 'v1))))

;; epilogue
(test-end)

