;; -*- coding: utf-8 -*-
;;
;; MML音楽演奏のサンプル
;;
(add-load-path "." :relative)
(use c-wrapper)
(use mmlproc)
(use gauche.uvector)
(use gauche.time)

;; SDL2のロード
(c-load '("SDL.h" "SDL_mixer.h" "stdio.h" "stdlib.h")
        :cppflags "-I/mingw/include/SDL2"
        :libs "-L/mingw/lib -lSDL2 -lSDL2_mixer"
        :import (list (lambda (header sym)
                        ;(print header " " sym)
                        (#/\/SDL2\/.*\.h$/ header))
                      'NULL)
        :compiled-lib "sdllib")

;; MML文字列から音声チャンクを生成
(define (audmake mmlstr)
  (define pcmdata  #f) ; PCMデータ(s16vector)
  (define audchunk #f) ; 音声チャンク
  ;; MML文字列をPCMデータに変換
  (print "mml->pcm")
  (time (set! pcmdata (mml->pcm mmlstr)))
  ;; PCMデータから音声チャンクを生成
  (set! audchunk (Mix_QuickLoad_RAW (cast (ptr <c-uchar>) pcmdata) (* 2 (s16vector-length pcmdata))))
  ;; 音声チャンクを返す
  audchunk)

;; 音声チャンクの再生と終了待ち
(define (audplay audchunk :optional (waitflag #f))
  (define audch        0)  ; 音声チャンネル
  (define audplaystate 0)  ; 音声再生状態(=0:停止,=1:再生中)
  ;; 音声チャンクを再生
  (set! audch (Mix_PlayChannel -1 audchunk 0))
  (print "play ch=" audch)
  ;; 終了待ちありのとき
  (when waitflag
    ;; 音声再生状態を監視
    (set! audplaystate 1)
    (while (not (= audplaystate 0))
      (set! audplaystate (Mix_Playing audch))
      (SDL_Delay 100))
    (print "finished."))
  ;; 音声チャンネルを返す
  audch)


;; SDLの初期化
(SDL_Init (logior SDL_INIT_VIDEO SDL_INIT_AUDIO))
;; SDL_mixerの初期化
(Mix_OpenAudio mml-sample-rate AUDIO_S16SYS 1 4096)

;; 再生終了コールバックの登録 (これは別スレッドのためエラーになる)
;(Mix_ChannelFinished (lambda (audch) (print "finished ch=" audch)))

;; 音声チャンクの生成
(define a1 (audmake
  "!c0 @500 o4 >cc gg aa g&r ff  ee   de32d32c32d16.e16 c2 \
   !c1 @500 o3 c>c ec fc ec  d<b >c<a fg                c2 "
  ))

;; 音声チャンクの再生
(audplay a1 #t)

;; SDL_mixerの終了
(Mix_CloseAudio)
;; SDLの終了
(SDL_Quit)

