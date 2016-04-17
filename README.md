# c-wrapper-mg

![image](image.png)

## 概要
- Gauche 用 の c-wrapper を MinGW (32bit) 上で動くように改造したものです。  
  c-wrapperは、GacuheからC言語のライブラリを呼び出せるようにするモジュールです。  
  正直中身は難しくてあまり理解できていませんが、  
  どうにかテストは(stdioのsys-fork以外は)通るようになりました。

- オリジナルの情報は、以下にあります。  
  http://www.koguro.net/prog/c-wrapper/index-j.html  
  ただし、ソースコードは、  
  https://bitbucket.org/nkoguro/c-wrapper  
  で最新と思われる c-wrapper v0.6.1 (ChangeLog 2012-07-19) をダウンロードしてベースとしました。

- もともと付属していたlibffiは削除して、  
  https://sourceware.org/libffi/  
  にある libffi-3.2.1 を使うようにしました。  
  (libffi-3.2.1は同梱していないため別途入手が必要です。  
  そして、元のlibffiと同様に一部修正を行う必要があります)  
  (libffiのバージョンが上がって上記のページに存在しない場合は、  
   ftp://sourceware.org/pub/libffi/ から旧バージョンを取得可能です)

- またMinGWに存在しないmmap関数については、  
  https://code.google.com/p/mman-win32/  
  にある mman.h と mman.c をソースに取り込みました。  
  (1箇所MinGWとバッティングする関数名(mprotect)はリネームしました)


## 変更点
- オリジナルからの変更点を、以下に示します。

1. configure.ac の変更  
   `*-mingw*` という場合分けのセクションを追加。

2. Gaucheのインストール先パスの空白対応  
   configure.ac や Makefile.in の該当箇所をダブルクォートでくくることで対応。  
   (Gaucheのインストール先パスについてのみ対応)

3. libffiの変更  
   元のlibffiは削除して、  
   https://sourceware.org/libffi/  
   からlibffi-3.2.1を別途入手。  
   不具合があるので src/x86 フォルダ内の ffi.c を以下のように修正した。
   ```
   (1)ffi.c の ffi_prep_cif_machdep 関数で、戻り値のスタック確保の条件を変更
        X86_WIN32 のときに is_result_on_stack 関数で戻り値がスタックを使うかどうか
        判定するようにした。
        is_result_on_stack関数は、元のlibffiの src/prep_cif.c からコピーした。
        この判定がないと Segmentation Fault エラーで落ちるので必須と思われる。
        (その後、判定条件を一部変更しました。問題点の 5. 参照)

   (2)ffi.c の ffi_prep_cif_machdep 関数で、スタック確保のサイズにスペースを追加
        X86_WIN32 のときに 以下のようにスペースを追加するようにした。
          cif->bytes = ((cif->bytes + 15) & ~0xF) + 8;
        これは元のlibffiの src/prep_cif.c の ffi_prep_cif関数で追加していたため
        同じようにした。ただし、これが必須なのかどうかはよく分からない。
        (その後、このスペースの追加はやめてみました (実験中) (2016-1-8))
   ```
   上記修正後、libffi-3.2.1 の ./configure → make を実行し、  
   生成された i686-pc-mingw32 フォルダ内の .lib フォルダと include フォルダを、  
   c-wrapper の src/libffi フォルダの下にコピーした。

4. dlopenの対応  
   dlopen, dlsym, dlerror等の関数が、MinGWには存在しない。  
   ただし c-wrapper は、すでにCygwin対応でWin32 APIに切り換え可能になっていたので、  
   ほぼそのまま利用できた。  
   1箇所、c-ffi.c で EnumProcessModules で取得したモジュールハンドルを、  
   CloseHandleしているが、これがあると gdb で unknown signal と出てデバッグができなかった。  
   CloseHandleしてはいけないようなのでコメントアウトしたところ、gdbでデバッグできるようになった。  
   また、インクルードでエラーになったので、  
   `__MINGW32__` が定義済みのときは c-ffi.h で dlfcn.h を インクルードしないようにした。

5. mmapの対応  
   mmap関数が、MinGWには存在しない。  
   https://code.google.com/p/mman-win32/  
   から mman.h と mman.c を入手。  
   c-wrapper の src フォルダにコピーして取り込むようにした。  
   そして、`__MINGW32__` が定義済みのときは closure_alloc.h で src フォルダの下の mman.h を  
   インクルードするようにした。  
   あと、1箇所MinGWとバッティングする関数名(mprotect)をリネームした(mman.hとmman.cを変更)。  
   また、configure.ac に FFI_SRC_ADD という定義を追加した。

6. cwcompile で c-load-library の処理に失敗する
   ```
   stubgen.scm
     compile-wrapper
       c-load-library
         変数名libsがバッティングしていたのを修正
         また、regexp-replaceの引数不足を修正
         しかしまだ直らない?
         ライブラリ名の取得に失敗している?
         以下のようにオプションをちゃんと指定したらいけた。
           (c-load-library "./ffitest2" :option "-L.")
           (c-include "./ffitest2.h" :compiled-lib "ffitelib2")
       c-include
         キーワードhideの定義もれ修正
   ```

7. テストの test_bitfield2 でSegmentation Faultエラー
   ```
   c-ffi.scm
     init-decl-alist!
       構造体にビットフィールドの先頭があらわれたら、シフト値を0にするように変更した。
       本当にこれでよいのかは、よく分からない。
       (その後、さらに一部変更しました。問題点の 6. 参照)
   ```

8. config.scm.in に MinGW 用の場合分けを追加
   ```
     lib/c-wrapper/config.scm.in に (when @MINGW_FLAG@ という場合分けを追加した。
     configure.ac に MINGW_FLAG の定義を追加した。
   ```

9. cwcompileの先頭行の変更(空白のパスが入るので対策)
   ```
     src/cwcompile.in の先頭行の記述を変更。
     configure.ac に CWCOMPILE_SHEBANG の定義を追加した。
   ```

10. Gauche v0.9.5_pre1 で uvector のライブラリファイル名が変わったので対応
    ```
      configure.ac に GAUCHE_UVECTOR_LIBS の定義を追加して、
      ファイルの存在有無によってライブラリファイル名を切り換えるようにした。
      (Cygwinは動作未確認)
    ```

11. ドキュメントファイル修正等
    - texi2html が MinGW になかったので、makeinfo --html に変更
      - doc/Makefile.in
    - ドキュメントファイルのインデックス追加
      - doc/c-wrapper-ref.texi

12. Makefile修正  
    コンパイル時に CFLAGS の内容を反映するようにした。
    - src/Makefile.in

13. MSYS2/MinGW-w64(64bit/32bit)環境でのビルドに暫定対応(実験中)
    - automake v1.15 の使用
      - config.guess
      - config.sub
      - install-sh
    - ヘッダファイルのマクロ展開処理の修正
      - src/c-parser.c ( Scm_ParseMacroCode )  
        GCCのバージョンアップで出力が変わった件に対応した。  
        ( https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=777861 )
    - ヘッダファイルの関数取得処理の修正
      - lib/c-wrapper/c-parser.scm ( make-define-inline-expr )  
        c-func-vaargs の処理を追加した。  
        また warning 時は、空の手続き (lambda ()) を返すようにして、  
        Segmentation Fault エラーを回避した。
    - 配列変数の処理でエラー
      - src/c-ffi.c ( Scm_MakeFFIArrayType )  
        `__X86_64__` が定義されている場合に特別扱いしている処理をコメントアウトした。
    - libffi-3.2.1 の修正
      - src/x86/ffi.c  
        X86_WIN64 が定義されている場合でも、動作するように条件を修正した。
    - ドキュメント修正
      - doc/c-wrapper-ref.texi  
        文字コード変更 (EUC → UTF-8) とヘッダ情報の追加を行った。
      - doc/extract.scm  
        Gauche の doc からコピーした。
      - doc/Makefile.in
    - サンプルの修正
      - examples_mingw  
        c-load のディレクトリ指定をフルパスに修正した。  
        SDL.h 内の SDL_cpuinfo.h の読み込みでエラーになるので、  
        c-load の :cppflags に -D_SDL_cpuinfo_h を追加して読み込まないようにした。  
        (新しい型の `__int128` や GCC の拡張書式に対応しないと、このファイルは読み込めないもよう)
    - テストの修正
      - testsuite/stdio-test_sub.scm  
        c-include のオプションを追加した。
    - ビルド方法のメモ(実験中)
      ```
       ＜MSYS2/MinGW-w64(64bit/32bit)環境でのビルド方法のメモ(実験中)＞

      ・Gauche本体も、MSYS2/MinGW-w64(64bit/32bit)環境でコンパイルされている必要がある。
        https://gist.github.com/Hamayama/6666e5d2c8d5167d22f7

      ・MSYS2/MinGW-w64 (32bit) 環境では、libffi-3.2.1 のコンパイルでエラーになる。
        64bit 環境と間違えて src/x86/win64.S をコンパイルしてしまうため、
        ./configure --build=i386-pc-mingw32 --host=i386-pc-mingw32 --target=i386-pc-mingw32
        のようにオプションを指定する必要があった。
      ```


## インストール方法
- MinGW (32bit) 環境でのインストール手順を、以下に示します。

1. Gaucheのインストール  
   事前に Gauche がインストールされている必要があります。  
   以下のページに Windows用バイナリインストーラ があるので、インストールを実施ください。  
   http://practical-scheme.net/gauche/download-j.html  
   (すでにインストール済みであれば本手順は不要です)

2. MinGW (32bit) のインストール  
   事前に MinGW (32bit) がインストールされている必要があります。  
   以下のページを参考に、インストールを実施ください。  
   https://gist.github.com/Hamayama/362f2eb14ae26d971ca4  
   (すでにインストール済みであれば本手順は不要です)

3. c-wrapperのソースの展開  
   本サイト( https://github.com/Hamayama/c-wrapper-mg )のソースを、  
   (Download Zip ボタン等で)ダウンロードして、作業用のフォルダに展開してください。  
   例えば、作業用のフォルダを c:\work とすると、  
   c:\work\c-wrapper の下にファイルとフォルダ一式が配置されるように展開してください。  
   (注意) 作業用フォルダのパスには、空白を入れないようにしてください。

4. libffi-3.2.1のダウンロード  
   https://sourceware.org/libffi/  
   から libffi-3.2.1.tar.gz をダウンロードして展開します。  
   (libffiのバージョンが上がって上記のページに存在しない場合は、  
    ftp://sourceware.org/pub/libffi/ から旧バージョンを取得可能です)  
   例えば作業用のフォルダを c:\work とすると、このフォルダにファイルを置いて、  
   コマンドプロンプトを開いて以下を実行すると展開されます。
   ```
     bash
     cd /c/work
     tar zxvf libffi-3.2.1.tar.gz
   ```

5. libffi-3.2.1のファイルの修正  
   c-wrapper  の libffi_patch フォルダにある ffi.c を、  
   libffi-3.2.1 の src/x86 フォルダ内の ffi.c に上書きコピーしてください。

6. libffi-3.2.1のコンパイル  
   コマンドプロンプトを開いて以下を実行します。
   ```
     bash
     cd /c/work/libffi-3.2.1
     ./configure    # Makefile等を生成します
     make           # コンパイルを実行します
   ```

7. 生成したライブラリとヘッダをc-wrapperのフォルダにコピー  
   コンパイルが完了すると libffi-3.2.1 の下に i686-pc-mingw32 というフォルダができます。  
   この中の .libs フォルダと include フォルダ を、  
   c-wrapper の src/libffi フォルダの下にコピーしてください。
   ```
     c-wrapper
         |-- src
              |-- libffi
                     |-- .lib
                     |-- include
   ```

8. c-wrapperのコンパイル  
   コマンドプロンプトを開いて以下を実行します。  
   ```
     bash
     cd /c/work/c-wrapper
     ./DIST gen     # configureファイルを生成します
     ./configure    # Makefile等を生成します
     make           # コンパイルを実行します
   ```

9. c-wrapperのインストール  
   コマンドプロンプトを開いて以下を実行します。
   ```
     bash
     cd /c/work/c-wrapper
     make install
   ```
   Gaucheのライブラリフォルダに生成したファイルがコピーされます。  
   (注意) 環境によっては make install を実行すると、  
   「*** ERROR: mkstemp failed」というエラーが発生します。  
   このエラーは c:\Program Files (x86) のフォルダに 書き込み権限がないとき等に発生します。  
   その場合は、コマンドプロンプトを開くときに、  
   コマンドプロンプトのアイコンを右クリックして、「管理者として実行」を選択してください。  
   そして再度上記のコマンドを実行してください。

10. c-wrapperのテスト  
    コマンドプロンプトを開いて以下を実行します。
    ```
     bash
     cd /c/work/c-wrapper
     make check
    ```
    テスト結果はc-wrapperのtestsuiteフォルダ内のtest.logに記録されます。

- 以上です。


##使い方
- MinGW用の実行サンプルをいくつかexamples_mingwフォルダに格納しました。  
  (benchmark, examples, experimentフォルダのサンプルは動作未確認です)

1. SDL2サンプル  
   https://github.com/Hamayama/c-wrapper-mg/tree/master/examples_mingw/sdl2

2. MML音楽演奏サンプル  
   https://github.com/Hamayama/c-wrapper-mg/tree/master/examples_mingw/mml

3. TTF表示サンプル  
   https://github.com/Hamayama/c-wrapper-mg/tree/master/examples_mingw/ttf


## その他 問題点等
1. テストの stdio-test.scm で fork failed エラー  
   → Windows に sys-fork がないので仕方ない  
   → Windows のときは sys-fork-and-exec を使うようにテストの方を変更した

2. ヘッダファイル(.h)だけを変更した場合にmakeで再コンパイルされない  
   → make clean してから make すればコンパイルできる  
      (ヘッダファイルだけを変更することはまずないと思うが、はまったので一応メモ)

3. テストの ffitest.h, ffitest.c でマクロの部分がgdbでデバッグ(ステップ実行)しにくい  
   → いくつかマクロを展開したものを、べたに書いてデバッグした

4. c-wapperを利用したscmファイルを、gosh-noconsole.exe で実行すると動作しない(途中で止まる)  
   (GaucheのWindows用インストーラは、デフォルトでscmファイルを  
    gosh-noconsole.exe に関連付けするので、scmファイルをダブルクリックで実行すると  
    この現象が出る)  
   → よく分かっていないが、c-wrapperの仕組み上コンソールが必要なもよう  
   → 基本的には gosh.exe で実行する必要がある  
      (例えばバッチファイルを作成して gosh xxx.scm を実行する等)  
   → 回避策として c-include や c-load を実行する前に  
      (display #\cr)(flush) や (print "XXX") を実行してコンソールを割り当てるようにすれば、  
      gosh-noconsole.exe でも動かすことができた。  
      ただし、コマンドプロンプトの画面が出る。  
      どうしてもコマンドプロンプトの画面を出したくない場合には、以下のページを参照のこと。  
      https://github.com/Hamayama/msconalloc

5. 構造体を戻り値とするCの関数を呼び出すと、正常に動作しないケースがある  
   → 構造体の中の要素数やサイズによって、戻り値の返し方が変わるもよう  
   ```
      X86_WIN32 のとき
      ・構造体の中の要素数が3個以上のとき → 戻り値はポインタ渡し
      ・構造体の中の要素数が1個のとき → その要素が単独の戻り値のときと同様に返る
      ・構造体の中の要素数が2個で合計が8バイト以下のとき → 戻り値はレジスタ2個で値渡し
      ・その他のとき → 戻り値はポインタ渡し

      X86_WIN64 のとき
      ・構造体の中の要素数が1個のとき → その要素が単独の戻り値のときと同様に返る
      ・構造体の中の合計が8バイト以下のとき → 戻り値はレジスタ1個で値渡し
      ・その他のとき → 戻り値はポインタ渡し
   ```
   → libffi-3.2.1 の ffi.c に判定条件を追加した(2015-7-8)(2016-1-6)(2016-1-7)

6. 構造体のビットフィールドにサイズ0のものがあると、正常にアクセスできない  
   → ビットフィールドにサイズ0のものがあった場合は、アライメントするように  
      c-ffi.scm に処理を追加した(2015-7-10)


## その他 ノウハウ等
1. デバッグ用のコンパイル  
   以下のように Makefile を書き換えると、gdbでデバッグしやすくなります。  
   (コンパイルオプションに -g をつける。また必要に応じて最適化オプションを外す)
   ```
     c-wrapper
       srcフォルダ内のMakefile (すでに -g がついていれば書き換え不要)
         CFLAGS         = -O2
           ↓
         CFLAGS         = -g -O2

       testsuiteフォルダ内のMakefile (すでに -g がついていれば書き換え不要)
         CFLAGS         = -c -o
           ↓
         CFLAGS         = -g -c -o

     libffi-3.2.1
       i686-pc-mingw32フォルダ内のMakefile
         CFLAGS = -O3 -fomit-frame-pointer -fstrict-aliasing -ffast-math -march=core2  -Wall -fexceptions
           ↓
         CFLAGS = -g -O3 -fomit-frame-pointer -fstrict-aliasing -ffast-math -march=core2  -Wall -fexceptions
   ```
   変更したら make clean してから再度 make が必要です。  
   (./configureを実行するとMakefileが元に戻ってしまうので注意してください)

2. デバッグのしかた  
   Segmentation Fault 等のエラーが発生した場合は、gdbを使ってデバッグを行います。  
   例えば、c:\work フォルダにある test.scm を実行してエラーとなった場合は、  
   コマンドプロンプトを開いて以下を実行します。
   ```
     bash
     cd /c/work
     gdb --args gosh test.scm
   ```
   以後はgdbの各コマンドを使ってデバッグを行います。
   ```
     r                      実行
     info stack (またはbt)  スタックトレースの表示
                            (エラー発生時に実行すると、スタックフレームにある
                             C言語の関数の呼び出し履歴が表示されます。
                             前述のMakefileの設定を行っていれば、
                             行番号も表示されます。
                             かなり有力なデバッグの手がかりになります)
     b 関数名               ブレークポイントの設定
     b ファイル名:行番号    ブレークポイントの設定
     p 変数名               変数の内容の表示
     s                      ステップ実行(関数の中まで追いかけるとき)
     n                      ステップ実行(関数の中までは追いかけないとき)
     c                      実行再開
     q                      終了
   ```
   他にもいろいろなコマンドがあります。gdbのコマンドの詳細については、  
   gdbの使い方を説明したネット上のページ等を参照ください。


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
- ライセンス
  - オリジナルと同様とします
  - 追加した mman.h と mman.c は MITライセンスです

## 履歴
- 2014-9-6   v0.6.1-mg0001 MinGW対応
- 2014-9-8   v0.6.1-mg0002 configure.ac, config.scm.in, cwcompile.in を変更  
  (configure.ac を変更したため ./DIST gen → ./configure  → make install が必要)
- 2014-9-8   v0.6.1-mg0003 config.scm.in の変更ミス修正  
  ( ./configure → make install が必要)
- 2014-10-16 v0.6.1-mg0004 SDL2サンプル examples/sdl2 を追加
- 2014-10-17 v0.6.1-mg0005 MinGW用のサンプルは examples_mingw フォルダに移動  
  c-ffi.cのlookup_symbol関数にデバッグ用コード追加(今はコメントアウトしてある)
- 2014-11-1  v0.6.1-mg0006 MML音楽演奏サンプル examples_mingw/mml を追加
- 2014-11-20 v0.6.1-mg0007 configure.ac を変更  
  (MinGW時のCWCOMPILE_SHEBANGの定義を「/usr/bin/env gosh」にした)  
  (configure.ac を変更したため ./DIST gen → ./configure  → make install が必要)
- 2014-11-20 v0.6.1-mg0008 libffi-3.1 を libffi-3.2.1 に更新
- 2014-11-24 v0.6.1-mg0009 TTF表示サンプル examples_mingw/ttf を追加
- 2015-5-20  v0.6.1-mg0010 configure.ac を変更  
  (Gauche v0.9.5_pre1 で uvector のライブラリファイル名が変わったので対応)  
  (configure.ac を変更したため make clean → ./DIST gen → ./configure  → make install が必要)
- 2015-6-27  v0.6.1-mg0011 configure.ac を変更  
  (Cygwinと場合分けを共通化。ただしCygwinは動作未確認)  
  (configure.ac を変更したため make clean → ./DIST gen → ./configure  → make install が必要)
- 2015-7-8   v0.6.1-mg0012 libffi-3.2.1 の ffi.c を修正  
  (構造体を戻り値とするCの関数を呼び出すと、正常に動作しないケースがある件の対策)
- 2015-7-10  v0.6.1-mg0013 c-ffi.scm を修正  
  (構造体のビットフィールドにサイズ0のものがあると、正常にアクセスできない件の対策)
- 2015-8-25  v0.6.1-mg0014 MML音楽演奏サンプルとTTF表示サンプルを一部修正(cond-expandにelse節を追加)
- 2015-11-21 v0.6.0-mg0015 SDL2サンプル更新
- 2015-12-17 v0.6.0-mg0016 ドキュメントファイル修正等  
  (doc/Makefile.in を変更したため make clean → ./configure  → make install が必要)
- 2015-12-20 v0.6.0-mg0017 Makefile修正  
  (src/Makefile.in を変更したため make clean → ./configure  → make install が必要)
- 2016-1-6   v0.6.0-mg0018 変更点 13. 対応
- 2016-1-6   v0.6.0-mg0019 ドキュメントファイル修正
- 2016-1-7   v0.6.0-mg0020 libffi-3.2.1 の ffi.c を修正
- 2016-1-8   v0.6.0-mg0021 libffi-3.2.1 の ffi.c を修正
- 2016-1-10  v0.6.0-mg0022 MSYS2/MinGW-w64(32bit)環境に暫定対応
- 2016-1-16  v0.6.0-mg0023 コメント修正のみ


(2016-4-17)
