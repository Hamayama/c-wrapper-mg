;; run 'esd -tcp -port 16001'

(use c-wrapper)

(c-load '("stdlib.h" "stdio.h" "signal.h" "unistd.h" "esd.h")
        :cppflags-cmd "pkg-config esound --cflags-only-I"
        :cflags-cmd "pkg-config esound --cflags-only-other"
        :libs-cmd "pkg-config esound --libs"
        :compiled-lib "esoundlib")

(define BUFFER 4096)
(define HOST (make-null-ptr))
(define tmp (make (<c-char> BUFFER)))

(define (main args)
  (let* ((wavfile "sunday.wav")
         (fp (fopen wavfile "r"))
         (sock (esd_play_stream_fallback
		(logior ESD_BITS8 ESD_MONO ESD_STREAM ESD_PLAY)
		22050 "localhost:16001" wavfile)))
    (let loop ((len (fread tmp 1 BUFFER fp)))
      (if (< 0 len)
          (begin
            (write sock tmp len)
            (loop (fread tmp 1 BUFFER fp)))
          #f))
    (fclose fp)
    (close sock)
   )
  0)

