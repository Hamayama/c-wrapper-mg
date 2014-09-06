(use c-wrapper)

(c-load-library "libc")
(c-include "stdio.h")

(define (main args)
  (let ((fp (fopen "greeting.txt" "w")))
    (fprintf fp "Hello, %s\n" "world")
    (fclose fp))

  (printf "greeting.txt is created.\n")
  0)
