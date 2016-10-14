;; -*- coding: utf-8 -*-
;;
;; audplaymod.scm
;; 2016-10-14 v1.11
;;
;; ＜内容＞
;;   Gauche で 音楽データを演奏するためのモジュールです。
;;   wavファイルを読み込んで演奏することができます。
;;
;;   実行するには、Gauche, c-wrapper, SDL2, SDL2_mixer が、
;;   適切にインストールされている必要があります。
;;   (Windowsの場合はMSYS2/MinGW-w64(64bit/32bit)環境のインストールも必要です)
;;
;; ＜インストール方法＞
;;   audplaymod.scm, audplaymod_sub_mingw32.scm,
;;   audplaymod_sub_mingw64_32.scm, audplaymod_sub_mingw64_64.scm,
;;   audplaymod_sub_other.scm
;;   を Gauche でロード可能なフォルダにコピーします。
;;   (例えば (gauche-site-library-directory) で表示されるフォルダ等)
;;
;; ＜使い方＞
;;   (use audplaymod)                ; モジュールをロードします
;;   (sdl-init SDL_INIT_AUDIO)       ; SDLの初期化
;;   (aud-init 22050)                ; SDL_mixerの初期化(引数はサンプリングレート(Hz))
;;   (define a1 (loadwav "test.wav") ; wavファイルを読み込んで音声チャンクに変換します
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
;;   (define st (audstat ch))        ; 指定したチャンネルの再生状態を取得します
;;                                   ;   戻り値は、停止中が0で再生中が1になります。
;;   (aud-end)                       ; SDL_mixerの終了
;;   (sdl-end)                       ; SDLの終了
;;
(define-module audplaymod
  (use c-wrapper)
  (use c-wrapper.config)
  (use gauche.uvector)
  (export
    sdl-init  sdl-end  sdl-sleep
    aud-init  aud-end  loadwav    pcm->aud
    audplay   audstop  audstat    ;audcallback
    SDL_INIT_TIMER    SDL_INIT_AUDIO       SDL_INIT_VIDEO
    SDL_INIT_JOYSTICK SDL_INIT_HAPTIC      SDL_INIT_GAMECONTROLLER
    SDL_INIT_EVENTS   SDL_INIT_NOPARACHUTE SDL_INIT_EVERYTHING))
(select-module audplaymod)


;; SDLのロード
(cond-expand
 (gauche.os.windows
  (display #\cr)(flush) ; コンソールを割り当てる
  (let1 msystem (sys-getenv "MSYSTEM")
    (cond
     ((equal? msystem "MINGW64")
      (load "audplaymod_sub_mingw64_64.scm"))
     ((equal? msystem "MINGW32")
      (load "audplaymod_sub_mingw64_32.scm"))
     (else
      (load "audplaymod_sub_mingw32.scm")))))
 (else
  (load "audplaymod_sub_other.scm")))


;; SDLの初期化
(define (sdl-init sysflag)
  (SDL_Init sysflag))

;; SDLの終了
(define (sdl-end)
  (SDL_Quit))

;; スリープ(msec)
(define (sdl-sleep wait)
  (SDL_Delay wait))


;; SDL_mixerの初期化
(define (aud-init sample-rate)
  (Mix_OpenAudio sample-rate AUDIO_S16SYS 1 4096))

;; SDL_mixerの終了
(define (aud-end)
  (Mix_CloseAudio))

;; wavファイルを読み込んで音声チャンクに変換
(define (loadwav wavfile)
  ;; wavファイルから音声チャンクを生成
  (Mix_LoadWAV wavfile))

;; PCMデータ(s16vector)を読み込んで音声チャンクに変換
(define (pcm->aud pcmdata)
  ;; PCMデータから音声チャンクを生成
  (Mix_QuickLoad_RAW (cast (ptr <c-uchar>) pcmdata) (* 2 (s16vector-length pcmdata))))

;; 音声チャンクの再生
;; (戻り値は再生チャンネルの番号)
(define (audplay audchunk :optional (ch -1) (waitflag #f))
  ;; 音声チャンクを再生
  (rlet1 pch (Mix_PlayChannel ch audchunk 0)
    ;; 終了待ちありのとき
    (when waitflag
      ;; 再生状態を監視
      (while (not (= (Mix_Playing pch) 0))
        (SDL_Delay 100)))))

;; 再生停止
(define (audstop ch)
  (Mix_HaltChannel ch))

;; 再生状態取得
;; (戻り値は、停止中が0で再生中が1になる)
(define (audstat ch)
  (Mix_Playing ch))

;; 再生終了コールバックの登録
;; (これは別スレッドのためエラーになる。使用不可)
(define (audcallback proc)
  ;(Mix_ChannelFinished (lambda (ch) (print "finished ch=" ch)))
  (Mix_ChannelFinished proc)
  )

