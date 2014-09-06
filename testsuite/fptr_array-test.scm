;;;
;;; Test for an array of function pointers
;;; 

(use gauche.test)

(test-start "fptr_array-test")
(use gauche.sequence)
(use c-wrapper)
(test-module 'c-wrapper)

(c-load-library "./fptr_array")
(c-include "./fptr_array.h")

(test "fptr_array"
      (list 3 55)
      (lambda ()
        (let ((foo (make (c-struct 'foo)))
              (v (make <c-int>))
              (results #f))
          (set! (ref v) 55)
          (fptr_array_set (ptr foo))
          (set! results (fptr_array_test (ptr foo) (ptr v)))
          (map identity (cast (c-array <c-int> 2) results)))))

;; epilogue
(test-end)

