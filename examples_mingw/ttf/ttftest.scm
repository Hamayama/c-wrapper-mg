;; -*- coding: utf-8 -*-
;;
;; SDL2_ttfによるフォント表示のテスト
;; 2016-10-14
;;
(add-load-path "." :relative)
(use c-wrapper)
(use c-wrapper.config)

;; SDLのロード
(cond-expand
 (gauche.os.windows
  (print "loading...") ; コンソールを割り当てる
  (let1 msystem (sys-getenv "MSYSTEM")
    (cond
     ((equal? msystem "MINGW64")
      (load "ttftest_sub_mingw64_64.scm"))
     ((equal? msystem "MINGW32")
      (load "ttftest_sub_mingw64_32.scm"))
     (else
      (load "ttftest_sub_mingw32.scm")))))
 (else
  (load "ttftest_sub_other.scm")))

(cond-expand
 (gauche.os.windows
  (print "complete."))
 (else))

;; 変数/定数
(define *window*    #f)
(define *screen*    #f)
(define *width*     640)
(define *height*    480)
(define *font-file* "C:\\WINDOWS\\Fonts\\MSGOTHIC.TTC")
(define *font*      #f)
(define *font2*     #f)
(define *surface*   #f)
(define *surface2*  #f)
(define *wait*      100)

;; 色情報作成
(define (make-color r g b)
  (rlet1 col (make <SDL_Color>)
    (set! (~ col 'r) r)
    (set! (~ col 'g) g)
    (set! (~ col 'b) b)))

;; 範囲情報作成
(define (make-rect x y w h)
  (rlet1 rct (make <SDL_Rect>)
    (set! (~ rct 'x) x)
    (set! (~ rct 'y) y)
    (set! (~ rct 'w) w)
    (set! (~ rct 'h) h)))


;; 初期化
(SDL_Init SDL_INIT_VIDEO)
(TTF_Init)

;; フォントの読み込み
(set! *font*  (TTF_OpenFont *font-file* 36))
(set! *font2* (TTF_OpenFont *font-file* 24))
(if (or (null-ptr? *font*) (null-ptr? *font2*)) (error "font load error"))
(set! *surface*  (TTF_RenderUTF8_Solid *font*  "文字表示のテスト"      (make-color 255 255 255)))
(set! *surface2* (TTF_RenderUTF8_Solid *font2* "(ESCキーで終了します)" (make-color 255 255 0)))

;; 画面作成
(set! *window* (SDL_CreateWindow "ttftest" 100 100 *width* *height* 0))
(set! *screen* (SDL_GetWindowSurface *window*))

;; フォントの表示
(SDL_BlitSurface *surface*  NULL *screen* (ptr (make-rect 100 100 0 0)))
(SDL_BlitSurface *surface2* NULL *screen* (ptr (make-rect 100 200 0 0)))

;; イベントループ
(let ((evt  (make <SDL_Event>))
      (keys (cast (c-array <c-uchar> 256) (SDL_GetKeyboardState NULL)))
      (done #f))
  (while (not done)
    ;; イベントチェック
    (when (> (SDL_PollEvent (ptr evt)) 0)
      (cond
       ((= (~ evt 'type) SDL_QUIT)
        (set! done #t))))
    ;; キー入力チェック
    (cond
     ((= (~ keys SDL_SCANCODE_ESCAPE) 1)
      (set! done #t)))
    ;; 画面更新
    (SDL_UpdateWindowSurface *window*)
    ;; ウェイト
    (SDL_Delay *wait*)))

;; 終了
(SDL_FreeSurface *surface*)
(SDL_FreeSurface *surface2*)
(TTF_CloseFont *font*)
(TTF_CloseFont *font2*)
(TTF_Quit)
(SDL_Quit)

