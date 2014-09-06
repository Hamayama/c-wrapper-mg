(define-module magick
  (use c-wrapper)
  (c-load '("stdio.h" "wand/magick_wand.h")
          :cppflags-cmd "Wand-config --cppflags" 
          :ldflags-cmd "Wand-config --ldflags" 
          :libs-cmd "Wand-config --libs"
          :import (lambda (fn name) (#/.*\/wand\/.*\.h/ fn))
          :compiled-lib "magicklib"))

