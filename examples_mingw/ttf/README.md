# TTF表示サンプル

## 概要
- MinGW 環境で Gauche, c-wrapper, SDL2, SDL2_ttf を用いて、  
  TrueTypeフォントの表示を行うサンプルです。


## 環境のインストール方法
- Gauche, MinGW, c-wrapper, SDL2, SDL2_ttf が適切にインストールされている必要があります。

- Gauche, MinGW, c-wrapper については、  
  以下のページの「インストール方法」を参考にインストールを実施ください。  
  https://github.com/Hamayama/c-wrapper-mg

- SDL2, SDL2_ttf については、  
  以下のページを参考にインストールを実施ください。  
  https://gist.github.com/Hamayama/155b5557db31334ce492


## 実行方法
  ＜MinGW (32bit) 環境の場合＞  
  ttftest.bat をダブルクリック等で起動します。  
  ＜MSYS2/MinGW-w64 (64bit) 環境の場合＞  
  ttftest_mingw64_64.bat をダブルクリック等で起動します。  
  ＜MSYS2/MinGW-w64 (32bit) 環境の場合＞  
  ttftest_mingw64_32.bat をダブルクリック等で起動します。  
  
  しばらくするとウィンドウが表示され、文字が表示されます。  
  ESCキーを押すと終了します。


## ファイルについて
- ttftest.scm の35行目の「 (define *font-file* ... 」  
  のところで、フォントファイルを指定しています。  
  ここを書き換えることで、他の TrueType フォントを表示できます。


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
- 2014-11-24 v1.00 初版
- 2014-11-28 v1.01 gosh-noconsoleでも動くようにコンソールの割り当てを追加
- 2015-8-25  v1.02 cond-expandにelse節を追加
- 2016-1-6   v1.03 MSYS2/MinGW-w64 (64bit) 環境に暫定対応(実験中)
- 2016-1-10  v1.04 MSYS2/MinGW-w64 (32bit) 環境に暫定対応(実験中)
- 2016-10-14 v1.05 README修正等(Gauche v0.9.5 対応)


(2016-10-14)
