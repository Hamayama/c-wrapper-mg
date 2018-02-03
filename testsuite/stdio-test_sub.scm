(use c-wrapper)

;; On MSYS2/MinGW-w64 (32bit), "-D_MSVCRT_" option is required.
;; On MSYS2/MinGW-w64 (64bit/32bit), stdio_patch.h is required.
;(c-include '("stdio.h" "unistd.h"))
(c-include '("stdio.h" "./stdio_patch.h") :option "-D_MSVCRT_")

(printf "Hello, world\n")
(fprintf stderr "error!\n")
(fflush stdout)
(fflush stderr)
(fclose stdout)
(fclose stderr)
