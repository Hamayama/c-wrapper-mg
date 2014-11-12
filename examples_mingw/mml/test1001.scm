;; -*- coding: utf-8 -*-
;;
;; audplaymodのテスト1
;; 2014-11-13
;;
(add-load-path "." :relative)
(use audplaymod)

;; 変数
(define a1 #f) ; 音声チャンク
(define ch  0) ; チャンネル

;; 初期化
(sdl-init SDL_INIT_AUDIO)
(aud-init 22050)

;;; wavファイルを読み込んで音声チャンクに変換
;(print "loadwav")
;(set! a1 (loadwav "test.wav"))
;
;;; 音声チャンクの再生
;(print "audplay")
;(set! ch (audplay a1 -1 #f))
;(sdl-delay 1000)
;(audstop ch)
;(print "stopped.")
;(newline)

;; MML文字列を読み込んで音声チャンクに変換
(print "mml->aud")
(set! a1 (mml->aud
  "!c0 @501 o4 >cc gg aa g&r ff  ee   de32d32c32d16.e16 c2 \
   !c1 @501 o3 c>c ec fc ec  d<b >c<a fg                c2 "
  ))

;; 音声チャンクの再生
(print "audplay")
(set! ch (audplay a1))
(while (not (= (getaudstat ch) 0))
  (sdl-delay 100))
(print "finished.")

;; 終了
(aud-end)
(sdl-end)

