;; -*- coding: utf-8; mode: scheme -*-
;;
;; breakout-mg.scm
;;
;;   Modified for SDL2 + MinGW(32bit), by Hamayama (2014-2015).
;;   Licensed under the same license that the original breakout is.
;;
;; --
;;
;; breakout.scm - Breakout
;;
;;   Copyright (c) 2007 KOGURO, Naoki (naoki@koguro.net)
;;   All rights reserved.
;;
;;   Redistribution and use in source and binary forms, with or without 
;;   modification, are permitted provided that the following conditions 
;;   are met:
;;
;;   1. Redistributions of source code must retain the above copyright 
;;      notice, this list of conditions and the following disclaimer.
;;   2. Redistributions in binary form must reproduce the above copyright 
;;      notice, this list of conditions and the following disclaimer in the 
;;      documentation and/or other materials provided with the distribution.
;;   3. Neither the name of the authors nor the names of its contributors 
;;      may be used to endorse or promote products derived from this 
;;      software without specific prior written permission.
;;
;;   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
;;   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
;;   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
;;   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
;;   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
;;   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED 
;;   TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
;;   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
;;   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
;;   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
;;   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;;
;;   $Id: $
;;

(use c-wrapper)
(use srfi-1)
(use srfi-27)
(use math.const)

;; ***** SDL2対応 *****
;(c-load '("SDL.h" "SDL_mixer.h" "stdio.h" "stdlib.h")
;        :cppflags-cmd "sdl-config --cflags"
;        :libs "-L/usr/local/lib -lSDL -lSDL_mixer"
;        :import (list (lambda (header sym)
;                        (#/\/SDL\/.*\.h$/ header))
;                      'NULL))
(display #\cr)(flush) ; コンソールを割り当てる
(c-load '("SDL.h" "SDL_mixer.h" "stdio.h" "stdlib.h")
        :cppflags "-I/mingw/include/SDL2"
        :libs "-L/mingw/lib -lSDL2 -lSDL2_mixer"
        :import (list (lambda (header sym)
                        ;(print header " " sym)
                        (#/\/SDL2\/.*\.h$/ header))
                      'NULL)
        :compiled-lib "sdllib")

;; ***** SDL2対応 *****
(define *window* #f) ; ウィンドウ
(define *wait* 8)    ; ウェイト時間(msec)

(define *screen* #f)
(define-constant *screen-width* 640)
(define-constant *screen-height* 480)
(define-constant *screen-depth* 8)
(define *unit* 8)

(define *ball-rect* #f)
;; vx and vy must be a multiple of *unit*.
(define *ball-vx* 0)
(define *ball-vy* 0)
(define *ball-count* 0)
(define-constant *ball-size* *unit*)
(define *ball-speed* (* (sqrt 2) *unit*))

(define *paddle-rect* #f)
;(define *paddle-width* (* 8 *unit*))
(define *paddle-width* (* 10 *unit*))
(define *paddle-height* *ball-speed*)
(define *paddle-vx* 0)

(define *block-list* '())
(define *block-start-x* 0)
(define *block-start-y* 0)
(define *block-end-x* 0)
(define *block-end-y* 0)

(define-constant *block-width* (* 6 *unit*))
(define-constant *block-height* (* 3 *unit*))

(define *tick* 0)
(define *tick-threshold* 20)

(define *bounce-sound* #f)
(define *shoot-sound* #f)

(define (init)
  (SDL_Init (logior SDL_INIT_VIDEO SDL_INIT_AUDIO))

  ;; ***** SDL2対応 *****
  ;; (画面作成)
  ;(set! *screen* (SDL_SetVideoMode *screen-width* *screen-height*
  ;                                 *screen-depth*
  ;                                 (logior SDL_HWSURFACE
  ;                                         SDL_DOUBLEBUF)))
  ;(SDL_WM_SetCaption "Breakout" NULL)
  (set! *window* (SDL_CreateWindow "Breakout" 100 100 *screen-width* *screen-height* 0))
  (set! *screen* (SDL_GetWindowSurface *window*))
  (print "[SPACE]:START  [<-][->]:MOVE  [ESC]:EXIT")

  (set! *paddle-rect* (make <SDL_Rect>))
  (set! (ref *paddle-rect* 'w) *paddle-width*)
  ;(set! (ref *paddle-rect* 'h) *unit*)
  (set! (ref *paddle-rect* 'h) *paddle-height*)
  
  (Mix_OpenAudio 44100 AUDIO_S16SYS 2 1024)
  (set! *bounce-sound* (Mix_LoadWAV "cursor5.wav"))
  (set! *shoot-sound* (Mix_LoadWAV "cursor6.wav"))
  (init-game))

(define (init-game)
  (set! (ref *paddle-rect* 'x) (- (/ *screen-width* 2)
                                  (/ (ref *paddle-rect* 'w) 2)))
  (set! (ref *paddle-rect* 'y) (- *screen-height* (* 3 *unit*)))
  (set! *ball-count* 2)
  (make-blocks))
  
(define (make-block x y color)
  (let ((rect (make <SDL_Rect>)))
    (set! (ref rect 'x) (+ x 1))
    (set! (ref rect 'y) (+ y 1))
    (set! (ref rect 'w) (- *block-width* 2))
    (set! (ref rect 'h) (- *block-height* 2))
  (vector (list x y (+ x *block-width*) (+ y *block-height*))
          rect
          color)))

(define (block-vertical-reflect? block x y vx)
  (receive (sx sy ex ey) (apply values (vector-ref block 0))
    (and (<= sy y ey)
         ;(or (and (= x sx) (< 0 vx))
         ;    (and (= x ex) (< vx 0))))))
         (or (and (<= (abs (- x sx)) *ball-speed*) (< 0 vx))
             (and (<= (abs (- x ex)) *ball-speed*) (< vx 0))))))

(define (block-horizontal-reflect? block x y vy)
  (receive (sx sy ex ey) (apply values (vector-ref block 0))
    (and (<= sx x ex)
         ;(or (and (= y sy) (< 0 vy))
         ;    (and (= y ey) (< vy 0))))))
         (or (and (<= (abs (- y sy)) *ball-speed*) (< 0 vy))
             (and (<= (abs (- y ey)) *ball-speed*) (< vy 0))))))

(define (block-hit? block x y)
  (receive (sx sy ex ey) (apply values (vector-ref block 0))
    (and (<= sx x ex) (<= sy y ey))))
  
(define (make-blocks)
  (do ((block-list '())
       (level 0 (+ level 1))

       ;; ***** SDL2対応 *****
       ;; (32ビットカラーに変更)
       ;(colors '(#o700 #o770 #o373 #o077 #o007) (cdr colors))
       (colors '(#xFF0000 #xFFFF00 #x7FFF7F #x00FFFF #x0000FF) (cdr colors))

       (y (* 7 *unit*) (+ y *block-height*)))
      ((<= 5 level)
       (set! *block-list* block-list))
    (do ((x (* 1 *unit*) (+ x *block-width*)))
        ((<= *screen-width* (+ x *block-width*)))
      (push! block-list (make-block x y (car colors)))))
  (set! *block-start-x* *screen-width*)
  (set! *block-start-y* *screen-height*)
  (set! *block-end-x* 0)
  (set! *block-end-y* 0)
  (for-each (lambda (block)
              (receive (sx sy ex ey) (apply values (vector-ref block 0))
                (when (< sx *block-start-x*)
                  (set! *block-start-x* sx))
                (when (< sy *block-start-y*)
                  (set! *block-start-y* sy))
                (when (< *block-end-x* ex)
                  (set! *block-end-x* ex))
                (when (< *block-end-y* ey)
                  (set! *block-end-y* ey))))
            *block-list*))
                
(define (teardown)
  (Mix_CloseAudio)
  (SDL_Quit))

(define clear-screen
  (let ((rect (make <SDL_Rect>)))
    (set! (ref rect 'x) 0)
    (set! (ref rect 'y) 0)
    (set! (ref rect 'w) *screen-width*)
    (set! (ref rect 'h) *screen-height*)
    (lambda ()
      (SDL_FillRect *screen* (ptr rect) 0))))
  
(define (draw-paddle)
  ;; ***** SDL2対応 *****
  ;; (32ビットカラーに変更)
  ;(SDL_FillRect *screen* (ptr *paddle-rect* ) #o777))
  (SDL_FillRect *screen* (ptr *paddle-rect* ) #xFFFFFF))

(define (move-paddle-left)
  (set! *paddle-vx* (- *unit*)))

(define (move-paddle-right)
  (set! *paddle-vx* *unit*))

(define (move-paddle)
  (let ((new-x (+ (ref *paddle-rect* 'x) *paddle-vx*))
        (w (ref *paddle-rect* 'w)))
    (when (< new-x 0)
      (set! new-x 0))
    (when (< (- *screen-width* w) new-x)
      (set! new-x (- *screen-width* w)))
    (set! (ref *paddle-rect* 'x) new-x)))

(define (stop-paddle)
  (set! *paddle-vx* 0))

(define (draw-ball)
  (define rect (make <SDL_Rect>))
  (when *ball-rect*
    ;; ボールの半径分ずらして表示
    (set! (ref rect 'x) (- (ref *ball-rect* 'x) (/. (ref *ball-rect* 'w) 2)))
    (set! (ref rect 'y) (- (ref *ball-rect* 'y) (/. (ref *ball-rect* 'h) 2)))
    (set! (ref rect 'w) (ref *ball-rect* 'w))
    (set! (ref rect 'h) (ref *ball-rect* 'h))
    ;; ***** SDL2対応 *****
    ;; (32ビットカラーに変更)
    ;(SDL_FillRect *screen* (ptr *ball-rect*) #o777)))
    (SDL_FillRect *screen* (ptr rect) #xFFFFFF)))

(define (move-ball)
  (let ((reflect? #f))
    (define (reflect-x)
      (set! *ball-vx* (- *ball-vx*))
      (set! reflect? #t))
    (define (reflect-y)
      (set! *ball-vy* (- *ball-vy*))
      (set! reflect? #t))
    (when *ball-rect*
      (let ((new-x (+ (ref *ball-rect* 'x) *ball-vx*))
            (new-y (+ (ref *ball-rect* 'y) *ball-vy*))
            (paddle-x (ref *paddle-rect* 'x))
            (paddle-y (ref *paddle-rect* 'y))
            (paddle-w (ref *paddle-rect* 'w))
            (paddle-h (ref *paddle-rect* 'h))
            (x (ref *ball-rect* 'x))
            (w (ref *ball-rect* 'w))
            (h (ref *ball-rect* 'h)))
        (when (< new-x 0)
          (reflect-x)
          (set! new-x (- new-x)))
        ;(when (< (- *screen-width* w) new-x)
        ;  (reflect-x)
        ;  (set! new-x (- (* 2 (- *screen-width* w)) new-x)))
        (when (< (- *screen-width* 1) new-x)
          (reflect-x)
          (set! new-x (- (* 2 (- *screen-width* 1)) new-x)))
        (when (< new-y 0)
          (reflect-y)
          (set! new-y 0))
        (when (and (<= paddle-y new-y (+ paddle-y paddle-h))
                   (<= paddle-x new-x (+ paddle-x paddle-w)))
          ;(reflect-y)
          ;(when (or (and (= paddle-x new-x)
          ;               (< 0 *ball-vx*))
          ;          (and (= (+ paddle-x paddle-w (- *unit*)) new-x)
          ;               (< *ball-vx* 0)))
          ;  (reflect-x))
          ;(set! new-y (- paddle-y h)))
          (let ((rad 0)
                (hit-dir (if  (< x (+ paddle-x (/. paddle-w 2))) -1 1))
                (hit-pos (abs (- x (+ paddle-x (/. paddle-w 2))))))
            ;; 反射角を設定
            (set! rad (if (< *ball-vx* 0)
                        (* (/. pi 4) 3)
                        (/. pi 4)))
            ;; パドルの端にヒットしたときは反射角を変える
            (when (and (< (* *ball-vx* hit-dir) 0)
                       (> hit-pos (/. paddle-w 6)))
              (set! rad (- pi rad)))
            ;; パドルのヒット位置によって反射角を変える
            (set! rad (+ rad
                         (* (if (< rad (/. pi 2)) -1 1)
                            (- (/. (* hit-pos (/. pi 6)) (/. paddle-w 2))
                               (/. pi 12)))))
            ;; 反射させる
            (set! rad (- rad))
            (set! *ball-vx* (* *ball-speed* (cos rad)))
            (set! *ball-vy* (* *ball-speed* (sin rad)))
            (set! reflect? #t))
          (set! new-y (- paddle-y h)))

        ;(when (< (- *screen-height* h) new-y)
        (when (< (- *screen-height* 1) new-y)
          (dec! *ball-count*)
          (set! *ball-rect* #f))
        (when (and (<= *block-start-x* new-x *block-end-x*)
                   (<= *block-start-x* new-y *block-end-y*))
          (do ((block-list *block-list* (cdr block-list))
               (result '() (cons (car block-list) result)))
              ((or (null? block-list)
                   (block-hit? (car block-list) new-x new-y))
               (unless (null? block-list)
                 (when (block-vertical-reflect? (car block-list) new-x new-y
                                                *ball-vx*)
                   (reflect-x))
                 (when (block-horizontal-reflect? (car block-list) new-x new-y
                                                  *ball-vy*)
                   (reflect-y))
                 (set! *block-list* (append result (cdr block-list)))))))
        (when *ball-rect*
          (set! (ref *ball-rect* 'x) new-x)
          (set! (ref *ball-rect* 'y) new-y))
        (when reflect?
          (Mix_PlayChannel -1 *bounce-sound* 0))))))

(define (shoot-ball)
  (unless *ball-rect*
    (let ((paddle-x (ref *paddle-rect* 'x))
          (paddle-y (ref *paddle-rect* 'y))
          (paddle-w (ref *paddle-rect* 'w))
          (paddle-h (ref *paddle-rect* 'h)))
      (set! *ball-rect* (make <SDL_Rect>))
      (set! (ref *ball-rect* 'w) *ball-size*)
      (set! (ref *ball-rect* 'h) *ball-size*)
      (set! (ref *ball-rect* 'x) (+ paddle-x (/ paddle-w 2)))
      (set! (ref *ball-rect* 'y) paddle-y)
      ;(set! *ball-vx* (* (- (* 2 (random-integer 2)) 1) *unit*))
      ;(set! *ball-vy* (- *unit*))
      (let1 rad (if (= (random-integer 2) 0)
                  (* (/. pi 4) 3)
                  (/. pi 4))
        (set! rad (- rad))
        (set! *ball-vx* (* *ball-speed* (cos rad)))
        (set! *ball-vy* (* *ball-speed* (sin rad))))
      (format #t "ball: ~a~%" *ball-count*)
      (Mix_PlayChannel -1 *shoot-sound* 0))))

(define (draw-blocks)
  (for-each (lambda (block)
              (SDL_FillRect *screen*
                            (ptr (vector-ref block 1))
                            (vector-ref block 2)))
            *block-list*))

(define (poll-event event)

  ;; ***** SDL2対応 *****
  ;; (キー入力処理)
  ;(define keys (cast (ptr <c-uchar>) (SDL_GetKeyboardState 0))) ; これだと(ref keys xx)でメモリリークする
  (define keys (cast (c-array <c-uchar> 256) (SDL_GetKeyboardState 0)))

  (SDL_PollEvent (ptr event))
  (unless (< 0 (SDL_PollEvent (ptr event)))
    (let ((type (ref event 'type)))
      (cond
       ((eq? type SDL_QUIT)
        #f)

       ;; ***** SDL2対応 *****
       ;; (キー入力処理)
       ;((eq? type SDL_KEYDOWN)
       ;  (case (ref* event 'key 'keysym 'sym)
       ;   ((27)
       ;    #f)
       ;   ((32)
       ;    (shoot-ball)
       ;    #t)
       ;   ((122)
       ;    (move-paddle-left)
       ;    #t)
       ;   ((120)
       ;    (move-paddle-right)
       ;    #t)
       ;   (else
       ;    #t)))
       ;(else
       ; #t)))))
       (else
        (cond
         ((= (ref keys SDL_SCANCODE_ESCAPE) 1)
          #f)
         ((= (ref keys SDL_SCANCODE_SPACE)  1)
          (shoot-ball)
          #t)
         ((= (ref keys SDL_SCANCODE_LEFT)   1)
          (move-paddle-left)
          #t)
         ((= (ref keys SDL_SCANCODE_RIGHT)  1)
          (move-paddle-right)
          #t)
         (else
          #t)))))))

(define (sdl-main argc argv)
  (init)
  (let ((event (make <SDL_Event>)))
    (do ((continue? (poll-event event) (poll-event event)))
        ((not continue?) #f)
      (clear-screen)
      (move-paddle)
      (let ((delta (- (SDL_GetTicks) *tick*)))
        (when (< *tick-threshold* delta)
          (move-ball)
          (set! *tick* (SDL_GetTicks))))
      (draw-paddle)
      (draw-ball)
      (draw-blocks)
      (stop-paddle)

      ;; ***** SDL2対応 *****
      ;; (画面更新)
      ;(SDL_Flip *screen*)
      (SDL_UpdateWindowSurface *window*)
      ;; (ウェイト)
      (SDL_Delay *wait*)

      (cond
       ((< *ball-count* 0)
        (print "GAME OVER!!")
        (init-game))
       ((null? *block-list*)
        (set! *ball-rect* #f)
        (make-blocks)))))
  (teardown)
  0)
  
(define (main args)
  (sdl-main (length args) args))
  
;; end of file
