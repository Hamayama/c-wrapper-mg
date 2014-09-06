(use c-wrapper)
(use gauche.time)
(use benchmark-helpers)

(let ((counter (make <real-time-counter>)))
  (with-time-counter counter
    (c-load "gtk/gtk.h"
            :cppflags-cmd "pkg-config gtk+-2.0 --cflags-only-I"
            :cflags-cmd   "pkg-config gtk+-2.0 --cflags-only-other"
            :libs-cmd     "pkg-config gtk+-2.0 --libs"
;            :import '(#/^gtk_/i NULL)
            :compiled-lib "gtklib"))
  (format #t "[gtk parse] Time: ~s sec~%" (round* (time-counter-value counter) 1)))

