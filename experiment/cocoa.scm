(use objc-wrapper)

(c-include "gauche.h" :include-dirs "/usr/local/lib/gauche/0.8.9/include")

;(GC_disable)

(define-module cocoa
  (use objc-wrapper)
  (c-load "Cocoa/Cocoa.h"
          :libs "-framework Foundation -framework Cocoa"
          :compiled-lib "cocoalib")
  (export-all))

(select-module cocoa)

(print (gc-stat))

(provide "cocoa")

