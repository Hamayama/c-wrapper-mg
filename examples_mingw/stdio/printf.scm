(use c-wrapper)

;; On MSYS2/MinGW-w64, "-D__USE_MINGW_ANSI_STDIO=0" option is required.
(c-include "stdio.h" :compiled-lib "stdiolib" :option "-D__USE_MINGW_ANSI_STDIO=0")

(print  "--- Scheme start ---")
(printf "--- C Language exec ---\n")
(print  "--- Scheme end ---")
