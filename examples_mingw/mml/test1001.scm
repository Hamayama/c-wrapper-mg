;; -*- coding: utf-8 -*-
;;
;; audplaymodのテスト1
;; 2016-10-14
;;
(add-load-path "." :relative)
(use audplaymod)
(use mmlproc)

;; 変数
(define a1 #f) ; 音声チャンク
(define ch  0) ; チャンネル

;; 初期化
(set! mml-sample-rate 22050)
(sdl-init SDL_INIT_AUDIO)
(aud-init mml-sample-rate)

;;; wavファイルを読み込んで音声チャンクに変換
;(print "loadwav")
;(set! a1 (loadwav "test.wav"))
;
;;; 音声チャンクの再生
;(print "audplay")
;(set! ch (audplay a1 -1 #f))
;(sdl-sleep 1000)
;(audstop ch)
;(print "stopped.")
;(newline)

;; MML文字列を読み込んで音声チャンクに変換
(print "mml->aud")
($ set! a1 $ pcm->aud $ mml->pcm $ string-append
   "!c0 @501 o4 >cc gg aa g&r ff  ee   de32d32c32d16.e16 c2 "
   "!c1 @501 o3 c>c ec fc ec  d<b >c<a fg                c2 "
   )

;; 音声チャンクの再生
(print "audplay")
(set! ch (audplay a1))
(until (= (audstat ch) 0)
  (sdl-sleep 100))
(print "finished.")

;; 終了
(aud-end)
(sdl-end)

