# MML音楽演奏サンプル

## 概要
- MinGW(32bit)環境で Gauche, c-wrapper, SDL2, SDL2_mixer を用いて、  
  MML(Music Macro Language)による音楽演奏を行うサンプルです。


## インストール方法
- SDL2サンプルのページ  
  https://github.com/Hamayama/c-wrapper-mg/tree/master/examples_mingw/sdl2  
  の「インストール方法」を参照ください。  
  Gauche, MinGW(32bit), c-wrapper, SDL2, SDL2_mixerが適切にインストール  
  されている必要があります。


## 実行方法
- audtest1001.bat をダブルクリック等で起動します。  
  (audtest1001.bat, audtest1001.scm, mmlproc.scm が同一フォルダに存在する必要があります)  
  しばらくすると音楽が鳴ります。演奏が終わると終了します。


## ファイルについて
- audtest1001.scm の61行目の「 (define a1 (audmake 」の下がMMLの文字列になっています。  
  ここを書き換えることで、いろいろな音楽を演奏できます。

- MMLの解釈は mmlproc.scm というモジュールで行っています。  
  MMLは方言が多く 本モジュールも独自文法になっています。  
  本モジュールのMML文法については、  
  https://github.com/Hamayama/mmlproc  
  の「MML(Music Macro Language)について」を参照ください。


## 環境等
- 以下の環境で動作を確認しました。
  - OS
    - Windows XP Home SP3
    - Windows 8 (64bit)
  - 環境
    - MinGW (32bit) v4.8.1
  - 言語
    - Gauche v0.9.4

## 履歴
- 2014-11-1  v1.00 初版
- 2014-11-3  v1.01 mmlproc.scmをv1.02に更新
- 2014-11-3  v1.02 mmlproc.scmをv1.03に更新
- 2014-11-3  v1.03 mmlproc.scmをv1.04に更新


(2014-11-3)
