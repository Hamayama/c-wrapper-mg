# TTF表示サンプル

## 概要
- MinGW(32bit)環境で Gauche, c-wrapper, SDL2, SDL2_ttf を用いて、  
  TrueTypeフォントの表示を行うサンプルです。


## 環境のインストール方法
- Gauche, MinGW(32bit), c-wrapper, SDL2, SDL2_ttfが適切にインストールされている必要があります。

- Gauche, MinGW(32bit), c-wrapperについては、  
  以下のページの「インストール方法」を参考にインストールを実施ください。  
  https://github.com/Hamayama/c-wrapper-mg

- SDL2, SDL2_ttfについては、  
  以下のページを参考にインストールを実施ください。  
  https://gist.github.com/Hamayama/155b5557db31334ce492


## 実行方法
- ttftest.bat をダブルクリック等で起動します。  
  (サンプルのファイル一式が同一フォルダに存在する必要があります)  
  しばらくするとウィンドウが表示され、文字が表示されます。  
  ESCキーを押すと終了します。


## ファイルについて
- ttftest.scm の34行目の「 (define *font-file* ... 」  
  のところで、フォントファイルを指定しています。  
  ここを書き換えることで、他のTrueTypeフォントを表示できます。


## 環境等
- OS
  - Windows XP Home SP3
  - Windows 8.1 (64bit)
- 環境
  - MinGW (32bit) (gcc v4.8.1)
  - MSYS2/MinGW-w64 (64bit) (gcc version 5.3.0 (Rev1, Built by MSYS2 project)) (実験中)
  - MSYS2/MinGW-w64 (32bit) (gcc version 5.3.0 (Rev1, Built by MSYS2 project)) (実験中)
- 言語
  - Gauche v0.9.4
  - Gauche v0.9.5_pe1

## 履歴
- 2014-11-24 v1.00 初版
- 2014-11-28 v1.01 gosh-noconsoleでも動くようにコンソールの割り当てを追加
- 2015-8-25  v1.02 cond-expandにelse節を追加
- 2016-1-6   v1.03 MSYS2/MinGW-w64 (64bit) 環境に暫定対応(実験中)
- 2016-1-10  v1.04 MSYS2/MinGW-w64 (32bit) 環境に暫定対応(実験中)


(2016-1-10)
