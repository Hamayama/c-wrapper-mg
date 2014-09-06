(use c-wrapper)

(c-load '("stdio.h" "wand/magick_wand.h")
        :cppflags-cmd "Wand-config --cppflags"
        :ldflags-cmd "Wand-config --ldflags"
        :libs-cmd "Wand-config --libs"
        :compiled-lib "magicklib")

(define (main args)
  (MagickWandGenesis)
  (let ((magick-wand (NewMagickWand)))
    (MagickReadImage magick-wand "bear.jpg")
    (MagickResetIterator magick-wand)
    (MagickNextImage magick-wand)
    (MagickResizeImage magick-wand 100 75 LanczosFilter 1.0)
    (MagickWriteImages magick-wand "thumbnail.png" MagickTrue)
    (print "thumbnail.png is created.")
    (DestroyMagickWand magick-wand)
    (MagickWandTerminus))
  0)


