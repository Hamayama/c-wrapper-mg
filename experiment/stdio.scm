(define-module stdio
  (use c-wrapper)

  (c-include "stdio.h" :compiled-lib "stdiolib")

  (export-all)
  )

(provide "stdio")
