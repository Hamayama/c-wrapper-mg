;; -*- coding: utf-8 -*-
;;
;; audplaymod.scm
;; 2014-11-14 v1.01
;;
;; ＜内容＞
;;   Gauche で 音楽データを演奏するためのモジュールです。
;;   wavファイルを読み込んで演奏することができます。
;;   また、MML(Music Macro Language)の文字列を読み込んで演奏することもできます。
;;
;;   実行するには、Gauche, c-wrapper, SDL2, SDL2_mixer が、
;;   適切にインストールされている必要があります。
;;   (Windowsの場合はMinGW(32bit)環境のインストールも必要です)
;;   また、MMLの解釈には mmlproc モジュールを使用しているため、
;;   このモジュールも必要です。
;;
;; ＜インストール方法＞
;;   audplaymod.scm を Gauche でロード可能なフォルダにコピーします。
;;   (例えば (gauche-site-library-directory) で表示されるフォルダ等)
;;
;; ＜使い方＞
;;   (use audplaymod)                ; モジュールをロードします
;;   (sdl-init SDL_INIT_AUDIO)       ; SDLの初期化
;;   (aud-init 22050)                ; SDL_mixerの初期化(引数はサンプリングレート(Hz))
;;   (sdl-delay 100)                 ; 一定時間ウェイトします(msec)
;;   (define a1 (loadwav "test.wav") ; wavファイルを読み込んで音声チャンクに変換します
;;   (define a1 (mml->aud "cdefg"))  ; MML文字列を読み込んで音声チャンクに変換します
;;   (define ch (audplay a1 -1 #t))  ; 音声チャンクを再生します
;;                                   ;   第2引数はオプション引数で、
;;                                   ;   再生するチャンネルの番号を指定します。
;;                                   ;   省略もしくは-1を指定すると、空いているチャンネル
;;                                   ;   で再生します。
;;                                   ;   第3引数はオプション引数で、
;;                                   ;   #tを指定すると再生終了までウェイトします。
;;                                   ;   省略もしくは#fを指定するとウェイトしません。
;;                                   ;   戻り値は再生したチャンネルの番号になります。
;;   (audstop ch)                    ; 指定したチャンネルの再生を停止します
;;   (define st (getaudstat ch))     ; 指定したチャンネルの再生状態を取得します
;;                                   ;   戻り値は、停止中が0で再生中が1となります。
;;   (aud-end)                       ; SDL_mixerの終了
;;   (sdl-end)                       ; SDLの終了
;;
(define-module audplaymod
  (add-load-path "." :relative)
  (use c-wrapper)
  (use mmlproc)
  (use gauche.uvector)
  (export
    sdl-init sdl-end  sdl-delay
    aud-init aud-end
    loadwav  mml->aud
    audplay  audstop
    getaudstat
    ;setaudcallback
    SDL_INIT_TIMER    SDL_INIT_AUDIO       SDL_INIT_VIDEO
    SDL_INIT_JOYSTICK SDL_INIT_HAPTIC      SDL_INIT_GAMECONTROLLER
    SDL_INIT_EVENTS   SDL_INIT_NOPARACHUTE SDL_INIT_EVERYTHING))
(select-module audplaymod)


;; SDLのロード
(cond-expand
 ;; Windowsのとき
 (gauche.os.windows
  (c-load '("SDL.h" "SDL_mixer.h" "stdio.h" "stdlib.h")
          :cppflags "-I/mingw/include/SDL2"
          :libs "-L/mingw/lib -lSDL2 -lSDL2_mixer"
          :import (list (lambda (header sym)
                          ;(print header " " sym)
                          (#/\/SDL2\/.*\.h$/ header))
                        'NULL)
          :compiled-lib "sdl2audlib"))
 ;; その他のOSのとき(動作未確認)
 (else
  (c-load '("SDL.h" "SDL_mixer.h" "stdio.h" "stdlib.h")
          :cppflags-cmd "sdl2-config --cflags"
          :libs-cmd "sdl2-config --libs; echo '-lSDL2_mixer'"
          :import (list (lambda (header sym)
                          ;(print header " " sym)
                          (#/\/SDL2\/.*\.h$/ header))
                        'NULL)
          :compiled-lib "sdl2audlib")))


;; SDLの初期化
(define (sdl-init sysflag)
  (SDL_Init sysflag))

;; SDLの終了
(define (sdl-end)
  (SDL_Quit))

;; ウェイト(msec)
(define (sdl-delay wait)
  (SDL_Delay wait))

;; SDL_mixerの初期化
(define (aud-init sample-rate)
  (Mix_OpenAudio sample-rate AUDIO_S16SYS 1 4096)
  (set! mml-sample-rate sample-rate))

;; SDL_mixerの終了
(define (aud-end)
  (Mix_CloseAudio))

;; wavファイルを読み込んで音声チャンクに変換
(define (loadwav wavfile)
  (define audchunk #f) ; 音声チャンク
  ;; wavファイルから音声チャンクを生成
  (set! audchunk (Mix_LoadWAV wavfile))
  ;; 音声チャンクを返す
  audchunk)

;; MML文字列を読み込んで音声チャンクに変換
(define (mml->aud mmlstr)
  (define pcmdata  #f) ; PCMデータ(s16vector)
  (define audchunk #f) ; 音声チャンク
  ;; MML文字列をPCMデータに変換
  (set! pcmdata (mml->pcm mmlstr))
  ;; PCMデータから音声チャンクを生成
  (set! audchunk (Mix_QuickLoad_RAW (cast (ptr <c-uchar>) pcmdata) (* 2 (s16vector-length pcmdata))))
  ;; 音声チャンクを返す
  audchunk)

;; 音声チャンクの再生
(define (audplay audchunk :optional (ch -1) (waitflag #f))
  (define pch    0) ; 再生チャンネル
  (define pstate 0) ; 再生状態(=0:停止,=1:再生中)
  ;; 音声チャンクを再生
  (set! pch (Mix_PlayChannel ch audchunk 0))
  ;; 終了待ちありのとき
  (when waitflag
    ;; 再生状態を監視
    (set! pstate 1)
    (while (not (= pstate 0))
      (set! pstate (Mix_Playing pch))
      (SDL_Delay 100)))
  ;; 再生チャンネルを返す
  pch)

;; 再生停止
(define (audstop ch)
  (Mix_HaltChannel ch))

;; 再生状態取得(=0:停止,=1:再生中)
(define (getaudstat ch)
  (Mix_Playing ch))

;; 再生終了コールバックの登録
;; (これは別スレッドのためエラーになる。使用不可)
(define (setaudcallback proc)
  ;(Mix_ChannelFinished (lambda (ch) (print "finished ch=" ch)))
  (Mix_ChannelFinished proc)
  )

