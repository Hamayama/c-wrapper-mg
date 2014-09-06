;;;
;;;   cairo-demo/X11/cairo-spline.c
;;;
(use math.const)
(use gauche.process)
(use c-wrapper)

(c-ld (string-append (process-output->string "pkg-config cairo --libs") " -L/usr/X11R6/lib -lX11"))

(c-include '("cairo.h" "cairo-xlib.h")
           :option (string-append "-I/usr/X11R6/include " (process-output->string "pkg-config cairo --cflags")))

;;;
;;;
;;;
(define-class <color> ()
  ((red :accessor red-of
        :init-keyword :red)
   (green :accessor green-of
          :init-keyword :green)
   (blue :accessor blue-of
         :init-keyword :blue)))

(define (make-color red green blue)
  (make <color> :red red :green green :blue blue))

(define-class <pt> ()
  ((x :accessor x-of
      :init-keyword :x)
   (y :accessor y-of
      :init-keyword :y)))

(define (make-pt x y) (make <pt> :x x :y y))

(define-class <window> ()
  ((dpy           :accessor dpy-of)
   (scr           :accessor scr-of)
   (win           :accessor win-of)
   (gc            :accessor gc-of)
   (pix           :accessor pix-of)
   (width         :accessor width-of)
   (height        :accessor height-of)
   (event-mask    :accessor event-mask-of)
   (needs-refresh :accessor needs-refresh?)
   (tolerance     :accessor tolerance-of)
   (line-width    :accessor line-width-of)
   (line-cap      :accessor line-cap-of)
   (spline        :accessor spline-of)
   (zoom          :accessor zoom-of)
   (xtrans        :accessor xtrans-of)
   (ytrans        :accessor ytrans-of)
   (click         :accessor click-of)
   (drag-pt       :accessor drag-pt-of)
   (active        :accessor active-of)))

(define-constant DEFAULT_XTRANS 0.0)
(define-constant DEFAULT_YTRANS 0.0)
(define-constant DEFAULT_TOLERANCE 0.1)
(define-constant DEFAULT_LINE_WIDTH 10)
(define-constant DEFAULT_ZOOM 1.0)
(define-constant DEFAULT_LINE_CAP CAIRO_LINE_CAP_ROUND)

(define *ribbon* (vector (make-pt 110 20)
                         (make-pt 310 300)
                         (make-pt 10 310)
                         (make-pt 210 20)))
;;;
;;;
;;;
(define (main args)
  (let ((dpy (XOpenDisplay 0)))
    (if (null-ptr? dpy)
        (error "Failed to open display")
        (let ((win (win-init dpy 400 400)))
          (win-print-help win)
          (win-handle-events win)))))

(define (draw-control-line cr a b width)
  (cairo_save cr)
  (cairo_set_source_rgb cr 0 0 1)
  (cairo_set_line_width cr width)
  (cairo_move_to cr (x-of a) (y-of a))
  (cairo_line_to cr (x-of b) (y-of b))
  (cairo_stroke cr)
  (cairo_restore cr))

(define (draw-spline cr win)
  (let ((spline (spline-of win))
        (drag-user-x (cast <c-double> (x-of (drag-pt-of win))))
        (drag-user-y (cast <c-double> (y-of (drag-pt-of win)))))

    (cairo_device_to_user cr (ptr drag-user-x) (ptr drag-user-y))

    ;;(format #t "drag-user(x,y)=(~d,~d)~%" drag-user-x drag-user-y)

    (cairo_save cr)

    (cairo_move_to cr 
                   (x-of (vector-ref (spline-of win) 0))
                   (y-of (vector-ref (spline-of win) 0)))
    (cairo_curve_to cr
                    (x-of (vector-ref (spline-of win) 1))
                    (y-of (vector-ref (spline-of win) 1))
                    (x-of (vector-ref (spline-of win) 2))
                    (y-of (vector-ref (spline-of win) 2))
                    (x-of (vector-ref (spline-of win) 3))
                    (y-of (vector-ref (spline-of win) 3)))

    (if (and (click-of win)
             (not (zero? (cairo_in_stroke cr drag-user-x drag-user-y))))
        (set! (active-of win) #xf))

    (cairo_stroke cr)

    (draw-control-line cr 
                       (vector-ref (spline-of win) 0)
                       (vector-ref (spline-of win) 1)
                       (/ 2.0 (zoom-of win)))
    (draw-control-line cr 
                       (vector-ref (spline-of win) 3)
                       (vector-ref (spline-of win) 2)
                       (/ 2.0 (zoom-of win)))

    (do ((i 0 (+ i 1)))
        ((= i 4) #t)
      (cairo_save cr)
      (cairo_set_source_rgba cr 1 0 0 0.5)
      (cairo_new_path cr)
      (cairo_arc cr
                 (x-of (vector-ref (spline-of win) i))
                 (y-of (vector-ref (spline-of win) i))
                 (/ (line-width-of win) 1.25)
                 0 (* 2 pi))
      (cond ((and (click-of win) 
                  (not (zero? (cairo_in_fill cr drag-user-x drag-user-y))))
             (set! (active-of win) (ash 1 i))
             (set! (click-of win) #f)))
      (cairo_fill cr)
      (cairo_restore cr))
    (cairo_restore cr)))

(define (win-refresh win)
  (XFillRectangle (dpy-of win) (pix-of win)  (gc-of win) 0 0
                  (width-of win) (height-of win))
  (let* ((surface (cairo_xlib_surface_create (dpy-of win)
                                             (pix-of win)
                                             (XDefaultVisual (dpy-of win) (scr-of win))
                                             (width-of win) (height-of win)))
         (cr (cairo_create surface)))

    (cairo_set_source_rgb cr 0 0 0)
    (cairo_set_line_width cr (line-width-of win))
    (cairo_set_line_cap cr (line-cap-of win))
    (cairo_translate cr (xtrans-of win) (ytrans-of win))
    (cairo_scale cr (zoom-of win) (zoom-of win))
    (cairo_set_tolerance cr (tolerance-of win))

    (draw-spline cr win)

    (if (not (zero? (cairo_status cr)))
        (format (current-error-port)
                "Cairo is unhappy: ~a~%"
                (cairo_status_to_string status)))

    (cairo_destroy cr)
    (cairo_surface_destroy surface)

    (XCopyArea (dpy-of win) (pix-of win) (win-of win) (gc-of win)
               0 0 (width-of win) (height-of win) 0 0)))

(define (win-init dpy width height)
  (let* ((gcv  (make <XGCValues>))
         (root (XDefaultRootWindow dpy))
         (scr  (XDefaultScreen dpy))
         (win  (XCreateSimpleWindow dpy root 0 0
                                    width
                                    height
                                    0
                                    (XWhitePixel dpy scr)
                                    (XWhitePixel dpy scr)))
         (pix  (XCreatePixmap dpy win width height (XDefaultDepth dpy scr)))
         (dum  (set! (ref gcv 'foreground) (XWhitePixel dpy scr)))
         (gc   (XCreateGC dpy pix GCForeground (ptr gcv)))
         (w    (make <window>)))

    (XFillRectangle dpy pix gc 0 0 width height)
    (set! (dpy-of w) dpy)
    (set! (win-of w) win)
    (set! (scr-of w) scr)
    (set! (gc-of w) gc)
    (set! (pix-of w) pix)
    (set! (width-of w) width)
    (set! (height-of w) height)
    (set! (active-of w) 0)
    (set! (spline-of w) *ribbon*)
    (set! (tolerance-of w) DEFAULT_TOLERANCE)
    (set! (line-width-of w) DEFAULT_LINE_WIDTH)
    (set! (line-cap-of w) DEFAULT_LINE_CAP)
    (set! (zoom-of w) DEFAULT_ZOOM)
    (set! (xtrans-of w) DEFAULT_XTRANS)
    (set! (ytrans-of w) DEFAULT_YTRANS)
    (set! (click-of w) #f)
    (set! (drag-pt-of w) (make-pt 0.0 0.0))
    (win-refresh w)
    (set! (needs-refresh? w) #f)
    (win-select-events w)
    (XMapWindow dpy win)
    (init-binding dpy)
    w))

(define (win-deinit win)
  (XFreeGC (dpy-of win) (gc-of win))
  (XFreePixmap (dpy-of win) (pix-of win))
  (XDestroyWindow (dpy-of win) (win-of win)))

(define (win-select-events win)
  (set! (event-mask-of win) (logior ButtonPressMask
                                    ButtonReleaseMask
                                    PointerMotionMask
                                    KeyPressMask
                                    StructureNotifyMask
                                    ExposureMask))
  (XSelectInput (dpy-of win) (win-of win) (event-mask-of win)))

(define (win-print-help win)
  (print "*******************************************************************")
  (print "A cairo spline demonstration (implemented in Gauche with c-wrapper)")
  (print "Click and drag to move the spline or adjust its controls. Or:\n\n")
  (hash-table-for-each *bindings* (lambda (key obj)
                                   (format #t "~a:\t ~a\n"
                                           (key-of obj) (doc-of obj)))))

(define (win-handle-events win)
  (let loop ((xev (make <XEvent>)))

    (cond ((and (zero? (XPending (dpy-of win)))
                (needs-refresh? win))
           (win-refresh win)
           (set! (needs-refresh? win) #f)))
    
    (XNextEvent (dpy-of win) (ptr xev))
    
    (let ((xxx (ref xev 'type)))
      (cond ((= xxx ButtonPress)
             (win-handle-button-press win (ref xev 'xbutton)))
            ((= xxx MotionNotify)
             (win-handle-motion win (ref xev 'xmotion)))
            ((= xxx ButtonRelease)
             (set! (click-of win) #f)
             (set! (active-of win) 0))
            ((= xxx KeyPress)
             (win-handle-key-press win (ref xev 'xkey)))
            ((= xxx ConfigureNotify)
             (win-handle-configure win (ref xev 'xconfigure)))
            ((= xxx Expose)
             (win-handle-expose win (ref xev 'xexpose)))
            (else
             ;;(format #t "Unknown Event (~d)~%" xxx)
             )))
    (loop xev)))

(define (win-handle-motion win mev)
  ;;(format #t "mev(x,y)=(~d,~d)~%" (ref mev 'x) (ref mev 'y))
  (if (not (zero? (active-of win)))
      (begin
        (do ((i 0 (+ i 1)))
            ((= i 4) #t)
          (cond ((logbit? i (active-of win))
                 (inc! (x-of (vector-ref (spline-of win) i))
                       (/ (- (ref mev 'x) (x-of (drag-pt-of win)))
                          (zoom-of win)))
                 (inc! (y-of (vector-ref (spline-of win) i))
                       (/ (- (ref mev 'y) (y-of (drag-pt-of win)))
                          (zoom-of win)))
                 (set! (needs-refresh? win) #t))))
        (set! (x-of (drag-pt-of win)) (ref mev 'x))
        (set! (y-of (drag-pt-of win)) (ref mev 'y)))))

(define (win-handle-key-press win kev)
  (let ((cmd (hash-table-get *bindings* (ref kev 'keycode) #f)))
    (if cmd
        ((proc-of cmd) win))))

(define (win-grow-pixmap win)
  (let ((new (XCreatePixmap (dpy-of win) (win-of win) (width-of win) (height-of win)
                            (XDefaultDepth (dpy-of win) (scr-of win)))))
    (XFillRectangle (dpy-of win) new (gc-of win) 0 0 (width-of win) (height-of win))
    (XCopyArea (dpy-of win) (pix-of win) new (gc-of win) 0 0 (width-of win) (height-of win) 0 0)
    (XFreePixmap (dpy-of win) (pix-of win))
    (set! (pix-of win) new)
    (set! (needs-refresh? win) #t)))

(define (win-handle-configure win cev)
  (let ((has-grown #f))
    (if (or (> (ref cev 'width) (width-of win))
            (> (ref cev 'height) (height-of win)))
        (set! has-grown #t))
    (set! (width-of win) (ref cev 'width))
    (set! (height-of win) (ref cev 'height))
    (if has-grown
        (win-grow-pixmap win))))

(define (win-handle-button-press win bev)
  ;;(format #t "bev(x,y)=(~d,~d)~%" (ref bev 'x) (ref bev 'y))
  (set! (click-of win) #t)
  (set! (x-of (drag-pt-of win)) (ref bev 'x))
  (set! (y-of (drag-pt-of win)) (ref bev 'y))
  (set! (needs-refresh? win) #t))

(define (win-handle-expose win eev)
  (XCopyArea (dpy-of win) (pix-of win) (win-of win) (gc-of win)
             (ref eev 'x) (ref eev 'y)
             (ref eev 'width) (ref eev 'height)
             (ref eev 'x) (ref eev 'y)))
;;;
;;;
;;;
(define (quit-cb win) 
  (win-deinit win)
  (XCloseDisplay (dpy-of win))
  (exit 0))

(define (print-spline win)
  (let ((s (spline-of win)))
    (format #t "((~a ~a) (~a ~a) (~a ~a) (~a ~a))~%"
            (x-of (vector-ref s 0)) (y-of (vector-ref s 0))
            (x-of (vector-ref s 1)) (y-of (vector-ref s 1))
            (x-of (vector-ref s 2)) (y-of (vector-ref s 2))
            (x-of (vector-ref s 3)) (y-of (vector-ref s 3)))))

(define (zoom-in win)
  (set! (zoom-of win) (* (zoom-of win) 1.1))
  (set! (needs-refresh? win) #t))

(define (zoom-out win)
  (set! (zoom-of win) (/ (zoom-of win) 1.1))
  (set! (needs-refresh? win) #t))

(define (trans-left win)
  (dec! (xtrans-of win) (/ (width-of win) 16))
  (set! (needs-refresh? win) #t))

(define (trans-right win)
  (inc! (xtrans-of win) (/ (width-of win) 16))
  (set! (needs-refresh? win) #t))

(define (trans-up win)
  (dec! (ytrans-of win) (/ (height-of win) 16))
  (set! (needs-refresh? win) #t))

(define (trans-down win)
  (inc! (ytrans-of win) (/ (height-of win) 16))
  (set! (needs-refresh? win) #t))

(define (flatten win)
  (set! (tolerance-of win) (* (tolerance-of win) 10))
  (set! (needs-refresh? win) #t))

(define (smooth win)
  (set! (tolerance-of win) (/ (tolerance-of win) 10))
  (set! (needs-refresh? win) #t))

(define (widen-line win)
  (set! (line-width-of win) (* (line-width-of win) 2))
  (set! (needs-refresh? win) #t))

(define (narrow-line win)
  (set! (line-width-of win) (/ (line-width-of win) 2))
  (set! (needs-refresh? win) #t))

(define-class <command> ()
  ((key     :accessor key-of
            :init-keyword :key)
   (keycode :accessor keycode-of
            :init-keyword :keycode)
   (proc    :accessor proc-of
            :init-keyword :proc)
   (doc     :accessor doc-of
            :init-keyword :doc)))

(define *bindings* (make-hash-table))

(define (bind-key dpy key proc doc)
  (let* ((keysym  (XStringToKeysym key))
         (keycode (XKeysymToKeycode dpy keysym)))
    (if (= keysym NoSymbol)
        (errorf "No keysym for ~s~%" key))
    (hash-table-put! *bindings* keycode
                     (make <command> :key key :keycode keycode
                           :proc proc :doc doc))))

(define (init-binding dpy)
  (bind-key dpy "Q"     quit-cb     "Exit the program")
  (bind-key dpy "Left"  trans-left  "Translate left")
  (bind-key dpy "Right" trans-right "Translate right")
  (bind-key dpy "Up"    trans-up    "Translate up")
  (bind-key dpy "Down"  trans-down  "Translate down")
  (bind-key dpy "plus"  zoom-in     "Zoom in")
  (bind-key dpy "minus" zoom-out    "Zoom out")
  (bind-key dpy "greater" smooth    "Increase rendering accuracy")
  (bind-key dpy "period"  smooth    "Increase rendering accuracy")
  (bind-key dpy "less"  flatten     "Decrease rendering accuracy")
  (bind-key dpy "comma" flatten     "Decrease rendering accuracy")
  (bind-key dpy "W"     widen-line  "Widen line width")
  (bind-key dpy "N"     narrow-line "Narrow line width")
)

;;; EOF
