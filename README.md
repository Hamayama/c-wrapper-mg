# c-wrapper-mg

![image](image.png)

## 概要
- Gauche 用の c-wrapper を MinGW 上で動くように改造したものです。  
  c-wrapper は、Gauche から C言語のライブラリを呼び出せるようにするモジュールです。  
  正直中身は難しくてあまり理解できていませんが、  
  どうにかテストは (stdio の sys-fork 以外は) 通るようになりました。

- オリジナルの情報は、以下にあります。  
  http://www.koguro.net/prog/c-wrapper/index-j.html  
  ただし、ソースコードは、  
  https://bitbucket.org/nkoguro/c-wrapper  
  で最新と思われる c-wrapper v0.6.1 (ChangeLog 2012-07-19) (コミット 608d0bf) を、  
  ダウンロードしてベースとしました。

- もともと付属していた libffi は削除して、  
  https://sourceware.org/libffi/  
  にある libffi-3.3 を使うようにしました。  
  (libffi-3.3 は同梱していないため別途入手が必要です。  
  そして、元の libffi と同様に一部修正を行う必要があります)  
  (libffi のバージョンが上がって上記のページに存在しない場合は、  
   ftp://sourceware.org/pub/libffi/ から旧バージョンを取得可能です)

- また MinGW に存在しない mmap 関数については、  
  https://code.google.com/p/mman-win32/  
  にある mman.h と mman.c をソースに取り込みました。  
  (1箇所 MinGW とバッティングする関数名 (mprotect) はリネームしました)


## 変更点
- オリジナルからの変更点を、以下に示します。

1. configure.ac の変更  
   `*-mingw*` という場合分けのセクションを追加。

2. Gaucheの インストール先パスの空白対応  
   configure.ac や Makefile.in の該当箇所をダブルクォートでくくることで対応。  
   (Gauche のインストール先パスについてのみ対応)

3. libffi の変更  
   元の libffi は削除して、  
   https://sourceware.org/libffi/  
   から libffi を別途入手。  
   不具合があるので src/x86 フォルダ内の ffi.c を以下のように修正した。  
   
   - ffi.c の ffi_prep_cif_machdep 関数で、戻り値のスタック確保の条件を変更  
     X86_WIN32 のときに is_result_on_stack 関数で戻り値がスタックを使うかどうか  
     判定するようにした。  
     is_result_on_stack 関数は、元の libffi の src/prep_cif.c からコピーした。  
     この判定がないと Segmentation Fault エラーで落ちるので必須と思われる。  
     (その後、判定条件を一部変更しました。問題点の 5. 参照)  
   
   - ffi.c の ffi_prep_cif_machdep 関数で、スタック確保のサイズにスペースを追加  
     X86_WIN32 のときに 以下のようにスペースを追加するようにした。  
     `cif->bytes = ((cif->bytes + 15) & ~0xF) + 8;`  
     これは元の libffi の src/prep_cif.c の ffi_prep_cif 関数で追加していたため  
     同じようにした。ただし、これが必須なのかどうかはよく分からない。  
     (その後、このスペースの追加はやめてみました (実験中) (2016-1-8))  
   
   上記修正後、libffi の ./configure → make を実行し、  
   生成された i686-w64-mingw32 フォルダ内の .libs フォルダと include フォルダを、  
   c-wrapper の src/libffi フォルダの下にコピーした。

4. dlopen の対応  
   dlopen, dlsym, dlerror 等の関数が、MinGW には存在しない。  
   ただし c-wrapper は、すでに Cygwin 対応で Win32 API に切り換え可能になっていたので、  
   ほぼそのまま利用できた。  
   1箇所、c-ffi.c で EnumProcessModules で取得したモジュールハンドルを、  
   CloseHandle しているが、これがあると gdb で unknown signal と出てデバッグができなかった。  
   MSDN によれば、CloseHandle してはいけないようなので、  
   コメントアウトしたところ gdb でデバッグできるようになった。  
   また、インクルードでエラーになったので、  
   `__MINGW32__` が定義済みのときは c-ffi.h で dlfcn.h を インクルードしないようにした。

5. mmap の対応  
   mmap 関数が、MinGW には存在しない。  
   https://code.google.com/p/mman-win32/  
   から mman.h と mman.c を入手。  
   c-wrapper の src フォルダにコピーして取り込むようにした。  
   そして、`__MINGW32__` が定義済みのときは closure_alloc.h で src フォルダの下の mman.h を  
   インクルードするようにした。  
   あと、1箇所 MinGW とバッティングする関数名(mprotect)をリネームした(mman.hとmman.cを変更)。  
   また、configure.ac に FFI_SRC_ADD という定義を追加した。

6. cwcompile で c-load-library の処理に失敗する
   ```
   stubgen.scm
     compile-wrapper
       c-load-library
         変数名 libs がバッティングしていたのを修正。
         また、regexp-replace の引数不足を修正。
         しかしまだ直らない?
         ライブラリ名の取得に失敗している?
         以下のようにオプションをちゃんと指定したらいけた。
           (c-load-library "./ffitest2" :option "-L.")
           (c-include "./ffitest2.h" :compiled-lib "ffitelib2")
       c-include
         キーワード hide の定義もれ修正。
   ```

7. テストの test_bitfield2 で Segmentation Fault エラー
   ```
   c-ffi.scm
     init-decl-alist!
       構造体にビットフィールドの先頭があらわれたら、シフト値を 0 にするように変更した。
       本当にこれでよいのかは、よく分からない。
       (その後、さらに一部変更しました。問題点の 6. 参照)
   ```

8. config.scm.in に MinGW 用の場合分けを追加
   - lib/c-wrapper/config.scm.in に `(when @MINGW_FLAG@` という場合分けを追加した。  
     configure.ac に MINGW_FLAG の定義を追加した。

9. cwcompile の先頭行の変更 (空白のパスが入るので対策)
   - src/cwcompile.in の先頭行の記述を変更。  
     configure.ac に CWCOMPILE_SHEBANG の定義を追加した。

10. Gauche v0.9.5_pre1 で uvector のライブラリファイル名が変わったので対応
    - configure.ac に GAUCHE_UVECTOR_LIBS の定義を追加して、  
      ファイルの存在有無によってライブラリファイル名を切り換えるようにした。  
      (Cygwin は動作未確認)

11. ドキュメントファイル修正等
    - texi2html が MinGW になかったので、`makeinfo --html` に変更
      - doc/Makefile.in
    - ドキュメントファイルのインデックス追加
      - doc/c-wrapper-ref.texi

12. Makefile 修正
    - コンパイル時に CFLAGS の内容を反映するようにした。
      - src/Makefile.in

13. MSYS2/MinGW-w64 (64bit/32bit) 環境でのビルドに対応
    - automake v1.15 の使用
      - config.guess
      - config.sub
      - install-sh
    - ヘッダファイルのマクロ展開処理の修正
      - src/c-parser.c ( Scm_ParseMacroCode )  
        GCC のバージョンアップで出力が変わった件に対応した。  
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
        SDL.h 内の SDL_cpuinfo.h の読み込みでエラーが出ていたため対策した。  
        (c-wrapper が `__int128` 型や GCC の拡張書式の一部に対応していないため、  
        このファイルを読み込めないもよう。  
        このため、c-load の :cppflags に -D_SDL_cpuinfo_h オプションを追加して、  
        このファイルの処理をスキップするようにした)  
        SDL2 v2.0.7 で、マクロ名が `_SDL_cpuinfo_h` から `SDL_cpuinfo_h_` に変わったので対応。  
        SDL2 v2.0.7, SDL2_mixer v2.0.2 の音声不具合対策を追加。  
        (SDL2 v2.0.6 から音声再生に WASAPI を使うようになったが、うまく再生できなかった。  
        このため、環境変数 SDL_AUDIODRIVER に directsound をセットすることで、  
        元の動作に戻した)
    - テストの修正
      - testsuite/stdio-test_sub.scm  
        c-include のオプションを追加した。
      - testsuite/stdio-test_sub.scm, testsuite/stdio_patch.h  
        MSYS2/MinGW-w64 (64bit/32bit) (gcc v7.2.0) の stdio.h の更新により、  
        stdin,stdout,stderr の定義が変わってエラーが出ていたため対策した。  
        (`__acrt_iob_func` を使うように変更されていたが `__iob_func` を使うように戻した)
      - testsuite/cwrappertest.scm, testsuite/inline-test.scm  
        MSYS2/MinGW-w64 (32bit) (gcc v7.2.0) の stddef.h の更新により、  
        `__float128` 関連のエラーが出ていたため対策した。  
        (c-wrapper が `__float128` 型に対応していないため、  
        -D_GCC_MAX_ALIGN_T オプションを追加して、該当箇所をスキップするようにした)  
        (その後、cwrappertest.scm については、  
        ダミーの float128 構造体を定義する方式に変更した)
      - testsuite/stdio-test.scm, testsuite/stdio-test-sub.scm, testsuite/inline-test.scm  
        MSYS2/MinGW-w64 (gcc v10.2.0) の stdio.h の更新により、  
        printf 関数等が使用できなくなっていたため対策した。  
        (関数の inline 化が原因?)  
        とりあえず、-D__USE_MINGW_ANSI_STDIO=0 オプションを追加して、  
        MSVCRT の printf 関数等を使用するようにした。
      - testsuite/ffitest.h  
        MSYS2/MinGW-w64 (gcc v10.2.0) の stdio.h の更新により、  
        sscanf 関数が static 関数になっており、  
        ffitest.h の inline 関数内で使用できなくなっていたため対策した。  
        ffitest.h の inline 関数を static inline 関数に変更した。

14. Gauche v0.9.9 対応
    - src/c-parser.c で使っていた Scm_RegExec 関数の引数の数が、  
      Gauche v0.9.9 で 2 個増えていたため対応。

15. libffi-3.3 対応
    - c-wrapper の src/c-ffi.c で使っていた ffi_prep_closure 関数が非推奨になったため、  
      ffi_prep_closure_loc 関数に変更。
    - libffi の X86_WIN64 の対策は不要になったため、libffi の ffi.c の修正から外した。  
      (X86_WIN32 の対策はまだ必要)


## インストール方法
- MSYS2/MinGW-w64 (64bit/32bit) 環境でのインストール手順を、以下に示します。

1. Gauche のインストール  
   事前に Gauche がインストールされている必要があります。  
   以下のページに Windows用バイナリインストーラ があるので、インストールを実施ください。  
   http://practical-scheme.net/gauche/download-j.html  
   (すでにインストール済みであれば本手順は不要です)

2. MSYS2/MinGW-w64 (64bit/32bit) のインストール  
   事前に MSYS2/MinGW-w64 (64bit/32bit) がインストールされている必要があります。  
   以下のページを参考に、開発環境のインストールを実施ください。  
   https://gist.github.com/Hamayama/eb4b4824ada3ac71beee0c9bb5fa546d  
   (すでにインストール済みであれば本手順は不要です)

3. c-wrapper のソースの展開  
   本サイト ( https://github.com/Hamayama/c-wrapper-mg ) のソースを、  
   (Download Zip ボタン等で) ダウンロードして、作業用のフォルダに展開してください。  
   例えば、作業用のフォルダを c:\work とすると、  
   c:\work\c-wrapper の下にファイル一式が配置されるように展開してください。  
   (注意) 作業用フォルダのパスには、空白を入れないようにしてください。

4. libffi-3.3 のダウンロード  
   https://sourceware.org/libffi/  
   から libffi-3.3.tar.gz をダウンロードして展開します。  
   (libffi のバージョンが上がって上記のページに存在しない場合は、  
    ftp://sourceware.org/pub/libffi/ から旧バージョンを取得可能です)  
   例えば作業用のフォルダを c:\work とすると、  
   c:\work\libffi-3.3 の下にファイル一式が配置されるように展開してください。  
   (注意) 作業用フォルダのパスには、空白を入れないようにしてください。

5. libffi-3.3 のファイルの修正  
   c-wrapper の libffi_patch フォルダにある ffi.c を、  
   libffi-3.3 の src/x86 フォルダ内の ffi.c に上書きコピーしてください。

6. libffi-3.3 のコンパイル  
   ＜MSYS2/MinGW-w64 (64bit) 環境の場合＞  
   プログラムメニューから MSYS2 の MinGW 64bit Shell を起動して、以下のコマンドを実行してください。  
   ＜MSYS2/MinGW-w64 (32bit) 環境の場合＞  
   プログラムメニューから MSYS2 の MinGW 32bit Shell を起動して、以下のコマンドを実行してください。  
   ( c:\work にソースを展開した場合)
   ```
     cd /c/work/libffi-3.3
     ./configure
     make
   ```

7. 生成したライブラリとヘッダを c-wrapper のフォルダにコピー  
   コンパイルが完了すると libffi-3.3 の下に x86_64-w64-mingw32 というフォルダができます。  
   (32bit環境の場合には、i686-w64-mingw32 というフォルダができます)  
   この中の .libs フォルダと include フォルダ を、  
   c-wrapper の src/libffi フォルダの下にコピーしてください。
   ```
     c-wrapper
         |-- src
              |-- libffi
                     |-- .libs
                     |-- include
   ```

8. c-wrapper のコンパイル  
   ＜MSYS2/MinGW-w64 (64bit) 環境の場合＞  
   プログラムメニューから MSYS2 の MinGW 64bit Shell を起動して、以下のコマンドを実行してください。  
   ＜MSYS2/MinGW-w64 (32bit) 環境の場合＞  
   プログラムメニューから MSYS2 の MinGW 32bit Shell を起動して、以下のコマンドを実行してください。  
   ( c:\work にソースを展開した場合)
   ```
     cd /c/work/c-wrapper
     ./DIST gen
     ./configure
     make
   ```
   (注意) MinGW のバージョンが古くて、C99モードではないというエラーが発生する場合には、  
   make clean で一度生成ファイルをクリアしてから、上記手順の  
   ./configure のオプションに CFLAGS="-g -O2 -std=gnu99" を追加してみてください。

9. c-wrapper のインストール  
   ＜MSYS2/MinGW-w64 (64bit) 環境の場合＞  
   プログラムメニューから MSYS2 の MinGW 64bit Shell を起動して、以下のコマンドを実行してください。  
   ＜MSYS2/MinGW-w64 (32bit) 環境の場合＞  
   プログラムメニューから MSYS2 の MinGW 32bit Shell を起動して、以下のコマンドを実行してください。  
   ( c:\work にソースを展開した場合)
   ```
     cd /c/work/c-wrapper
     make install
   ```
   Gauche のライブラリフォルダに生成したファイルがコピーされます。  
   
   (注意) 環境によっては、make install を実行すると  
   「gauche-install: no write permission of ...」もしくは  
   「*** ERROR: mkstemp failed」というエラーが発生します。  
   このエラーは、インストール先のフォルダに書き込み権限がないとき等に発生します。  
   その場合には、プログラムメニューからの開発環境の起動時に右クリックして、  
   「管理者として実行」を選択してください。  
   そして再度上記のコマンドを実行してください。

10. c-wrapper のテスト  
    ＜MSYS2/MinGW-w64 (64bit) 環境の場合＞  
    プログラムメニューから MSYS2 の MinGW 64bit Shell を起動して、以下のコマンドを実行してください。  
    ＜MSYS2/MinGW-w64 (32bit) 環境の場合＞  
    プログラムメニューから MSYS2 の MinGW 32bit Shell を起動して、以下のコマンドを実行してください。  
    ( c:\work にソースを展開した場合)
    ```
      cd /c/work/c-wrapper
      make check
    ```
    テスト結果は c-wrapper の testsuite フォルダ内の test.log に記録されます。

- 以上です。


## 使い方
- MinGW 用の実行サンプルをいくつか examples_mingw フォルダに格納しました。  
  (benchmark, examples, experiment フォルダのサンプルは動作未確認です)

1. SDL2サンプル  
   https://github.com/Hamayama/c-wrapper-mg/tree/master/examples_mingw/sdl2

2. MML音楽演奏サンプル  
   https://github.com/Hamayama/c-wrapper-mg/tree/master/examples_mingw/mml

3. TTF表示サンプル  
   https://github.com/Hamayama/c-wrapper-mg/tree/master/examples_mingw/ttf


## その他 問題点等
1. テストの stdio-test.scm で fork failed エラー  
   → Windows に sys-fork がないので仕方ない。  
   → Windows のときは sys-fork-and-exec を使うようにテストの方を変更した。

2. ヘッダファイル (.h) だけを変更した場合に make で再コンパイルされない  
   → make clean してから make すればコンパイルできる。  
      (ヘッダファイルだけを変更することはあまりないと思うが、はまったので一応メモ)

3. テストの ffitest.h, ffitest.c でマクロの部分が gdb でデバッグ (ステップ実行) しにくい  
   → いくつかマクロを展開したものを、べたに書いてデバッグした。

4. c-wapper を利用した scm ファイルを、gosh-noconsole.exe で実行すると動作しない (途中で止まる)  
   (Gauche の Windows用インストーラ は、デフォルトで scm ファイルを  
    gosh-noconsole.exe に関連付けするので、scm ファイルをダブルクリックで実行すると  
    この現象が出る)  
   → よく分かっていないが、c-wrapper の仕組み上コンソールが必要なもよう。  
   → 基本的には gosh.exe で実行する必要がある。  
      (例えばバッチファイルを作成して gosh xxx.scm を実行する等)  
   → 回避策として c-include や c-load を実行する前に  
      `(display #\cr)(flush)` や `(print "XXX")` を実行してコンソールを割り当てるようにすれば、  
      gosh-noconsole.exe でも動かすことができた。  
      ただし、コマンドプロンプトの画面が出る。  
      どうしてもコマンドプロンプトの画面を出したくない場合には、以下のページを参照のこと。  
      https://github.com/Hamayama/msconalloc

5. 構造体を戻り値とする C の関数を呼び出すと、正常に動作しないケースがある  
   → 構造体の中の要素数やサイズによって、戻り値の返し方が変わるもよう。  
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
   → libffi-3.2.1 の ffi.c に判定条件を追加した。(2015-7-8)(2016-1-6)(2016-1-7)  
   → libffi-3.3 で、X86_WIN64 の対策は不要になった(X86_WIN32 の対策はまだ必要)。(2019-12-20)

6. 構造体のビットフィールドにサイズ 0 のものがあると、正常にアクセスできない  
   → ビットフィールドにサイズ 0 のものがあった場合は、アライメントするように  
      c-ffi.scm に処理を追加した。(2015-7-10)


## その他 ノウハウ等
1. デバッグ用のコンパイル  
   以下のように Makefile を書き換えると、gdb でデバッグしやすくなります。  
   (コンパイルオプションに -g をつける。また必要に応じて最適化オプションを外す)
   ```
     c-wrapper
       src フォルダ内 の Makefile (すでに -g がついていれば書き換え不要)
         CFLAGS         = -O2
           ↓
         CFLAGS         = -g -O2

       testsuite フォルダ内の Makefile (すでに -g がついていれば書き換え不要)
         CFLAGS         = -c -o
           ↓
         CFLAGS         = -g -c -o

     libffi-3.3
       i686-w64-mingw32 フォルダ内の Makefile
         CFLAGS = -O3 -fomit-frame-pointer -fstrict-aliasing -ffast-math -march=core2  -Wall -fexceptions
           ↓
         CFLAGS = -g -O3 -fomit-frame-pointer -fstrict-aliasing -ffast-math -march=core2  -Wall -fexceptions
   ```
   変更したら make clean してから再度 make が必要です。  
   (./configure を実行すると Makefile が元に戻ってしまうので注意してください)

2. デバッグのしかた  
   Segmentation Fault 等のエラーが発生した場合は、gdb を使ってデバッグを行います。  
   例えば、c:\work フォルダにある test.scm を実行してエラーとなった場合には、  
   以下のようにコマンドを実行します。
   ```
     cd /c/work
     gdb --args gosh test.scm
   ```
   以後は gdb の各コマンドを使ってデバッグを行います。
   ```
     r                    実行
     bt                   バックトレースの表示
                           (エラー発生時に実行すると、スタックフレームにある
                            C言語の関数の呼び出し履歴が表示されます。
                            前述の Makefile の設定を行っていれば、
                            行番号も表示されます。
                            かなり有力なデバッグの手がかりになります)
     b 関数名             ブレークポイントの設定
     b ファイル名:行番号  ブレークポイントの設定
     p 変数名             変数の内容の表示
     s                    ステップ実行(関数の中まで追いかけるとき)
     n                    ステップ実行(関数の中までは追いかけないとき)
     c                    実行再開
     q                    終了
   ```
   他にもいろいろなコマンドがあります。gdb のコマンドの詳細については、  
   gdb の使い方を説明したネット上のページ等を参照ください。


## 環境等
- OS
  - Windows 10 (version 1909) (64bit)
  - Windows 8.1 (64bit)
  - Windows XP Home SP3
- 環境
  - MSYS2/MinGW-w64 (64bit/32bit) (gcc version 10.2.0 (Rev5, Built by MSYS2 project)) (Windows 10)
  - MSYS2/MinGW-w64 (64bit/32bit) (gcc version 9.2.0 (Rev2, Built by MSYS2 project)) (Windows 8.1)
  - MinGW (32bit) (gcc version 6.3.0 (MinGW.org GCC-6.3.0-1))
- 言語
  - Gauche v0.9.10_rc1
  - Gauche v0.9.9
  - Gauche v0.9.8
  - Gauche v0.9.7
  - Gauche v0.9.6
  - Gauche v0.9.5
  - Gauche v0.9.4
- ライセンス
  - オリジナルと同様とします
  - 追加した mman.h と mman.c は MIT ライセンスです

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
- 2015-11-21 v0.6.1-mg0015 SDL2サンプル更新
- 2015-12-17 v0.6.1-mg0016 ドキュメントファイル修正等  
  (doc/Makefile.in を変更したため make clean → ./configure  → make install が必要)
- 2015-12-20 v0.6.1-mg0017 Makefile修正  
  (src/Makefile.in を変更したため make clean → ./configure  → make install が必要)
- 2016-1-6   v0.6.1-mg0018 変更点 13. 対応
- 2016-1-6   v0.6.1-mg0019 ドキュメントファイル修正
- 2016-1-7   v0.6.1-mg0020 libffi-3.2.1 の ffi.c を修正
- 2016-1-8   v0.6.1-mg0021 libffi-3.2.1 の ffi.c を修正
- 2016-1-10  v0.6.1-mg0022 MSYS2/MinGW-w64(32bit)環境に暫定対応
- 2016-1-16  v0.6.1-mg0023 コメント修正のみ
- 2016-10-14 v0.6.1-mg0024 README修正のみ(Gauche v0.9.5 で動作確認)
- 2017-5-17  v0.6.1-mg0025 configure.ac 修正
- 2017-5-26  v0.6.1-mg0026 コメント修正のみ
- 2017-6-3   v0.6.1-mg0027 configure.ac 修正
- 2018-2-3   v0.6.1-mg0028 バージョン表示ミス修正(v0.6.0→v0.6.1)  
  (mg0015からmg0027まで間違えていた)
- 2018-2-3   v0.6.1-mg0029 テストの修正
- 2018-2-4   v0.6.1-mg0030 examples_mingwを更新  
  (SDL2 v2.0.7, SDL2_mixer v2.0.2 の音声不具合対策等)
- 2018-2-4   v0.6.1-mg0031 examples_mingwを更新(cond-expand追加)
- 2018-7-9   v0.6.1-mg0031 README修正のみ(Gauche v0.9.6 で動作確認)
- 2019-12-20 v0.6.1-mg0032 Gauche v0.9.9 対応。libffi-3.2.1 を libffi-3.3 に更新
- 2020-1-3   v0.6.1-mg0033 テストの変更(testsuite/cwrappertest.scm)
- 2020-11-10 v0.6.1-mg0034 Gauche v0.9.10_rc1 対応 (gcc v10.2.0)


(2020-11-10)
