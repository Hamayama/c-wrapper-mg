# TTF表示サンプル

## 概要
- MinGW(32bit)環境で Gauche, c-wrapper, SDL2, SDL2_ttf を用いて、  
  TrueTypeフォントの表示を行うサンプルです。


## インストール方法
- インストールの方法を以下に示します。

1. 事前準備  
   SDL2サンプルのページ  
   https://github.com/Hamayama/c-wrapper-mg/tree/master/examples_mingw/sdl2  
   の「インストール方法」を参照ください。  
   ただし、SDL2_mixerのダウンロード/インストールは不要です。  
   Gauche, MinGW(32bit), c-wrapper, SDL2が適切にインストール  
   されている必要があります。

2. SDL2_ttfのダウンロード  
   https://www.libsdl.org/projects/SDL_ttf/  
   のページから、Development LibrariesのMinGW用のファイル  
     SDL2_ttf-devel-2.0.12-mingw.tar.gz  
   をダウンロードします。  
   そして、このファイルの中身を作業用のフォルダに展開します。  
   例えば作業用のフォルダを c:\work とした場合、このフォルダにファイルを置いて、  
   コマンドプロンプトを開いて以下を実行すると展開できます。
   ```
     bash
     cd /c/work
     tar zxvf SDL2_ttf-devel-2.0.12-mingw.tar.gz
   ```

3. SDL2_ttfのインストール  
   コマンドプロンプトを開いて以下を実行して、MinGWのフォルダにインストールします。
   ```
     bash
     cd /c/work/SDL2_ttf-2.0.12
     make install-package arch=i686-w64-mingw32 prefix=/mingw
   ```

- 以上です。


## 実行方法
- ttftest.bat をダブルクリック等で起動します。  
  (ttftest.bat と ttftest.scm が同一フォルダに存在する必要があります)  
  しばらくするとウィンドウが表示され、文字が表示されます。  
  ESCキーを押すと終了します。


## ファイルについて
- ttftest.scm の28行目の「 (define *font-file* ... 」  
  のところで、フォントファイルを指定しています。  
  ここを書き換えることで、他のTrueTypeフォントを表示できます。


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
- 2014-11-24 v1.00 初版


(2014-11-24)
