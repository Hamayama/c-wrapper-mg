;;;
;;; Test include stdio.h
;;;

(use srfi-11)
(use gauche.test)
(use gauche.process)

(test-start "c-wrapper (include stdio.h)")
(use c-wrapper)

(c-include '("stdio.h" "unistd.h"))

(test "printf & fprintf"
      '("Hello, world" "error!")
      (lambda ()
        (let-values (((stdout-in stdout-out) (sys-pipe))
                     ((stderr-in stderr-out) (sys-pipe)))
          (let ((pid (sys-fork)))
            (if (= pid 0)
                (begin
                  (close-input-port stdout-in)
                  (close-input-port stderr-in)
                  (close 1)
                  (close 2)
                  (dup (port-file-number stdout-out))
                  (dup (port-file-number stderr-out))
                  (printf "Hello, world")
                  (fprintf stderr "error!")
                  (fflush stdout)
                  (fflush stderr)
                  (fclose stdout)
                  (fclose stderr)
                  (sys-exit 0))
                (begin
                  (close-output-port stdout-out)
                  (close-output-port stderr-out)
                  (let ((outstr (read-line stdout-in))
                        (errstr (read-line stderr-in)))
                    (sys-wait)
                    (list outstr errstr))))))))

(test "sscanf"
      5
      (lambda ()
        (let ((v (make <c-int>)))
          (sscanf "5" "%d" (ptr v))
          (v))))

;; epilogue
(test-end)

