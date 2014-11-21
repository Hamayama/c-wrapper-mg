(use c-wrapper)

(c-include '("stdio.h" "unistd.h"))

(printf "Hello, world\n")
(fprintf stderr "error!\n")
(fflush stdout)
(fflush stderr)
(fclose stdout)
(fclose stderr)
