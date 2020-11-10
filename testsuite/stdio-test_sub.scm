(use c-wrapper)

;; On MSYS2/MinGW-w64, stdio_patch.h is required.
;; On MSYS2/MinGW-w64, "-D_MSVCRT_" option is required.
;; On MSYS2/MinGW-w64, "-D__USE_MINGW_ANSI_STDIO=0" option is required.
;(c-include '("stdio.h" "unistd.h"))
(c-include '("stdio.h" "./stdio_patch.h") :option "-D_MSVCRT_ -D__USE_MINGW_ANSI_STDIO=0")

(printf "Hello, world\n")
(fprintf stderr "error!\n")
(fflush stdout)
(fflush stderr)
(fclose stdout)
(fclose stderr)

;; ***** for debug *****
;(display "stdout output test\n" (current-output-port))
;(display "stderr output test\n" (current-error-port))

