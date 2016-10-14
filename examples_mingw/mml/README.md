# MML音楽演奏サンプル

## 概要
- MinGW 環境で Gauche, c-wrapper, SDL2, SDL2_mixer を用いて、  
  MML (Music Macro Language) による音楽演奏を行うサンプルです。


## 環境のインストール方法
- Gauche, MinGW, c-wrapper, SDL2, SDL2_mixer が適切にインストールされている必要があります。

- Gauche, MinGW, c-wrapper については、  
  以下のページの「インストール方法」を参考にインストールを実施ください。  
  https://github.com/Hamayama/c-wrapper-mg

- SDL2, SDL2_mixer については、  
  以下のページを参考にインストールを実施ください。  
  https://gist.github.com/Hamayama/155b5557db31334ce492


## 実行方法
- ＜MinGW (32bit) 環境の場合＞  
  test1001.bat をダブルクリック等で起動します。  
  ＜MSYS2/MinGW-w64 (64bit) 環境の場合＞  
  test1001_mingw64_64.bat をダブルクリック等で起動します。  
  ＜MSYS2/MinGW-w64 (32bit) 環境の場合＞  
  test1001_mingw64_32.bat をダブルクリック等で起動します。  
  
  しばらくすると音楽が鳴ります。演奏が終わると終了します。


## ファイルについて
- test1001.scm の33行目の「 ($ set! a1 $ pcm->aud $ mml->pcm $ string-append 」の下が、  
  MML の文字列になっています。  
  ここを書き換えることで、いろいろな音楽を演奏できます。

- 音楽の演奏は audplaymod.scm というモジュールで行っています。  
  (c-wrapper 経由で SDL を制御しています)

- また、MML の解釈は mmlproc.scm というモジュールで行っています。  
  mmlproc の詳細については、以下のページを参照ください。  
  https://github.com/Hamayama/mmlproc


## 環境等
- OS
  - Windows 8.1 (64bit)
  - Windows XP Home SP3
- 環境
  - MSYS2/MinGW-w64 (64bit) (gcc version 6.2.0 (Rev2, Built by MSYS2 project))
  - MSYS2/MinGW-w64 (32bit) (gcc version 6.2.0 (Rev2, Built by MSYS2 project))
  - MinGW (32bit) (gcc v4.8.1)
- 言語
  - Gauche v0.9.5
  - Gauche v0.9.4

## 履歴
- 2014-11-1  v1.00 初版
- 2014-11-3  v1.01 mmlproc.scmをv1.02に更新
- 2014-11-3  v1.02 mmlproc.scmをv1.03に更新
- 2014-11-3  v1.03 mmlproc.scmをv1.04に更新
- 2014-11-5  v1.04 mmlproc.scmをv1.05に更新
- 2014-11-6  v1.05 mmlproc.scmをv1.06に更新
- 2014-11-7  v1.06 mmlproc.scmをv1.07に更新
- 2014-11-8  v1.07 mmlproc.scmをv1.10に更新
- 2014-11-8  v1.08 mmlproc.scmをv1.11に更新
- 2014-11-11 v1.09 mmlproc.scmをv1.12に更新
- 2014-11-13 v1.10 audplaymod.scmを作成
- 2014-11-14 v1.11 audplaymod.scmをv1.01に更新
- 2014-11-18 v1.12 audplaymod.scmをv1.02に更新(全面見直し)
- 2014-11-18 v1.13 audplaymod.scmをv1.03に更新(一部処理見直し)
- 2014-11-19 v1.14 audplaymod.scmをv1.04に更新(一部処理見直し)
- 2014-11-20 v1.15 audplaymod.scmをv1.05に更新(SDLロード処理見直し)
- 2014-11-24 v1.16 audplaymod.scmをv1.06に更新(SDLロード処理修正)
- 2014-11-26 v1.17 mmlproc.scmをv1.13に更新(コメント修正のみ)
- 2014-11-28 v1.18 audplaymod.scmをv1.07に更新(gosh-noconsoleでも動くようにコンソールの割り当てを追加)
- 2015-1-18  v1.19 mmlproc.scmをv1.14に更新(エラーチェック追加)
- 2015-8-25  v1.20 audplaymod.scmをv1.08に更新(cond-expandにelse節を追加)
- 2016-1-6   v1.21 MSYS2/MinGW-w64 (64bit) 環境に暫定対応(実験中)
- 2016-1-10  v1.22 MSYS2/MinGW-w64 (32bit) 環境に暫定対応(実験中)
- 2016-3-31  v1.23 mmlproc.scmをv1.15に更新(get-wav-size手続きを追加)
- 2016-4-17  v1.24 mmlproc.scmをv1.16に更新
- 2016-10-14 v1.25 README修正等(Gauche v0.9.5 対応)
- 2016-10-14 v1.26 mmlproc.scmをv1.17に更新
- 2016-10-14 v1.27 audplaymod.scmをv1.11に更新(コメント修正のみ)


(2016-10-14)
