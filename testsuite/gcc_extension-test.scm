;;;
;;; Test GCC extension
;;; 

(use gauche.test)

(test-start "gcc_extension")
(use c-wrapper)
(test-module 'c-wrapper)

(c-load-library "./gcc_extension")
(c-include "./gcc_extension.h")

(test "Unnamed struct/union fields within structs/unions 1"
      '(2 3.0 4 5 6.0)
      (lambda ()
        (let ((foo (make (c-struct 'foo))))
          (set! (ref foo 'a) 1)
          (set! (ref foo 'b) 2)
          (set! (ref foo 'e) 3)
          (set! (ref foo 'f) 4)
          (set! (ref foo 'g) 5)
          (inc_foo (ptr foo) FLOAT_MODE)
          (map (cut ref foo <>) '(a b e f g)))))

(test "Unnamed struct/union fields within structs/unions 2"
      '(2 3 4.0 5 6 7.0)
      (lambda ()
        (let ((foo (make (c-struct 'foo))))
          (set! (ref foo 'a) 1)
          (set! (ref foo 'c) 2)
          (set! (ref foo 'd) 3)
          (set! (ref foo 'e) 4)
          (set! (ref foo 'f) 5)
          (set! (ref foo 'g) 6)
          (inc_foo (ptr foo) STRUCT_MODE)
          (map (cut ref foo <>) '(a c d e f g)))))

;; epilogue
(test-end)
