(use c-wrapper)

;; On MSYS2/MinGW-w64 (32bit), "-D_MSVCRT_" option is required.
;(c-include '("stdio.h" "unistd.h"))
(c-include '("stdio.h") :option "-D_MSVCRT_")

(printf "Hello, world\n")
(fprintf stderr "error!\n")
(fflush stdout)
(fflush stderr)
(fclose stdout)
(fclose stderr)
