# SDL2サンプル

![image](image.png)

## 概要
- c-wrapperのSDLサンプルのブロック崩しを、SDL2 + MinGW(32bit)用に改造したものです。


## インストール方法
- インストールの方法を以下に示します。

1. 事前準備  
   事前にGauche, MinGW(32bit), c-wrapperがインストールされている必要があります。  
   ( https://github.com/Hamayama/c-wrapper-mg の「インストール方法」を参照)

2. SDL2のダウンロード  
   http://www.libsdl.org/  
   から SDL 2.0 のダウンロードページへ行き、Development LibrariesのMinGW用のファイル  
   SDL2-devel-2.0.3-mingw.tar.gz  
   をダウンロードします。  
   そして、このファイルの中身を作業用のフォルダに展開します。  
   例えば作業用のフォルダを c:\work とした場合、このフォルダにファイルを置いて、  
   コマンドプロンプトを開いて以下を実行すると展開できます。
   ```
     bash
     cd /c/work
     tar zxvf SDL2-devel-2.0.3-mingw.tar.gz
   ```

3. SDL2のインクルードファイルの修正  
   そのままだとコンパイル時に  
   「winapifamily.h: No such file or directory」  
   というエラーが発生します。  
   以下のページに説明があります。  
   http://stackoverflow.com/questions/22446008/winapifamily-h-no-such-file-or-directory-when-compiling-sdl-in-codeblocks  
   記述通りに、  
   https://hg.libsdl.org/SDL/raw-file/e217ed463f25/include/SDL_platform.h  
   にアクセスして、SDL_platform.h をダウンロードし、  
   SDL2-2.0.3 の i686-w64-mingw32/include/SDL2 フォルダ内の SDL_platform.h に  
   上書きコピーします。

4. SDL2のインストール  
   コマンドプロンプトを開いて以下を実行して、MinGWのフォルダにインストールします。
   ```
     bash
     cd /c/work/SDL2-2.0.3
     make install-package arch=i686-w64-mingw32 prefix=/mingw
   ```

5. SDL2_mixerのダウンロード  
   http://www.libsdl.org/projects/SDL_mixer/  
   のページから、Development LibrariesのMinGW用のファイル  
   SDL2_mixer-devel-2.0.0-mingw.tar.gz  
   をダウンロードします。  
   そして、このファイルの中身を作業用のフォルダに展開します。  
   例えば作業用のフォルダを c:\work とした場合、このフォルダにファイルを置いて、  
   コマンドプロンプトを開いて以下を実行すると展開できます。
   ```
     bash
     cd /c/work
     tar zxvf SDL2_mixer-devel-2.0.0-mingw.tar.gz
   ```

6. SDL2_mixerのインストール  
   コマンドプロンプトを開いて以下を実行して、MinGWのフォルダにインストールします。
   ```
     bash
     cd /c/work/SDL2_mixer-2.0.0
     make install-package arch=i686-w64-mingw32 prefix=/mingw
   ```

- 以上です。


## 実行方法
- breakout.bat をダブルクリック等で起動します。  
  (breakout.bat, breakout.scm, cursor5.wav, cursor6.wav が同一フォルダに存在する必要があります)  
  スペースキーでボールを発射します。  
  カーソルキーの左右でパドルを動かします。  
  すべてのブロックを消すか、ボールを3個うしろにそらすと、  
  ゲームオーバーになり最初に戻ります。  
  [ESC]キーで終了します。


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
- 2014-10-16 v1.00 初版
- 2014-10-17 v1.01 一部パラメータ調整


(2014-11-1)
