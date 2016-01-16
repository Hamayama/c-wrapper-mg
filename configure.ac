dnl
dnl Configuring c-wrapper
dnl  process this file with autoconf to generate 'configure'.
dnl $Id$
dnl

AC_PREREQ(2.54)
AC_INIT(c-wrapper, 0.6.1, naoki@koguro.net)
dnl If you want to use the system name (OS, architecture, etc) in the
dnl configure, uncomment the following line.  In such a case, you need
dnl to copy config.guess and config.sub from automake distribution.
AC_CANONICAL_SYSTEM

dnl Set up gauche related commands.  The commands are set by scanning
dnl PATH.  You can override them by "GOSH=/my/gosh ./configure" etc.
AC_PATH_PROG([GOSH], gosh)
AC_PATH_PROG([GAUCHE_CONFIG], gauche-config)
AC_PATH_PROG([GAUCHE_PACKAGE], gauche-package)
AC_PATH_PROG([GAUCHE_INSTALL], gauche-install)
AC_PATH_PROG([GAUCHE_CESCONV], gauche-cesconv)

dnl Usually these parameters are set by AC_PROG_CC, but we'd rather use
dnl the same one as Gauche has been compiled with.
SOEXT=`"$GAUCHE_CONFIG" --so-suffix`
OBJEXT=`"$GAUCHE_CONFIG" --object-suffix`
EXEEXT=`"$GAUCHE_CONFIG" --executable-suffix`
DYLIBEXT=`"$GAUCHE_CONFIG" --dylib-suffix`
AC_SUBST(SOEXT)
AC_SUBST(OBJEXT)
AC_SUBST(EXEEXT)
AC_SUBST(DYLIBEXT)

ac_default_prefix=`"$GAUCHE_CONFIG" --prefix`

GAUCHE_PKGINCDIR=`"$GAUCHE_CONFIG" --pkgincdir`
GAUCHE_PKGLIBDIR=`"$GAUCHE_CONFIG" --pkglibdir`
GAUCHE_PKGARCHDIR=`"$GAUCHE_CONFIG" --pkgarchdir`
AC_SUBST(GAUCHE_PKGINCDIR)
AC_SUBST(GAUCHE_PKGLIBDIR)
AC_SUBST(GAUCHE_PKGARCHDIR)

dnl Check for headers.
dnl Add your macro calls to check required headers, if you have any.

dnl Check for other programs.
dnl Add your macro calls to check existence of programs, if you have any.
AC_PROG_CC
AC_PROG_YACC
AC_CHECK_PROGS(MAKEINFO, makeinfo)
AC_CHECK_PROGS(GZIP_PROGRAM, gzip)
AC_CHECK_PROGS(SED, sed)
AC_PATH_PROG([LDCONFIG], [ldconfig], [], [$PATH:/sbin:/usr/sbin])

dnl Check for libraries
dnl Add your macro calls to check required libraries, if you have any.

dnl Platform-dependent configuration.
AC_ARG_ENABLE(objc, [  --enable-objc           turn on Objective-C support])

try_rpath=yes
rpath=AC_ARG_WITH(rpath, AC_HELP_STRING([--with-rpath=PATH:PATH...], 
                                        [Use -rpath option while building dynamically loadable objects.]),
  [
    case $with_rpath in
        yes) ;;
        no)  try_rpath=no;;
        *)   rpath="`echo $with_rpath | sed -e 's/^/-Wl,-rpath /' -e 's/:/ -Wl,-rpath /g'`";;
    esac
  ])
                  
STUBGEN_FFI_MODULE=c-wrapper.c-ffi
LDCONFIG_CMD=""
LD_LIBRARY_PATH_ENVS='"LD_LIBRARY_PATH"'
LDFLAGS="$LDFLAGS $rpath"
TESTLIB_CFLAGS="-c -fPIC -o"
TESTLIB_LDFLAGS="$rpath -shared -o"
SYS_LIBRARY_PATHS="/usr/lib /lib"
CPARSER_LIBS=""
CYGWIN_FLAG="#f"
MINGW_FLAG="#f"
CWCOMPILE_DEFAULT_LIBS=""
CWCOMPILE_SHEBANG="$GOSH"
FFI_SRC_ADD=""
case "$target" in
    *darwin*)
        LD_LIBRARY_PATH_ENVS='"LD_LIBRARY_PATH" "DYLD_LIBRARY_PATH"'
        TESTLIB_LDFLAGS="-dynamiclib -o"
        ;;
    i?86-*-linux*|sparc*-*-linux*)
        CPPFLAGS="$CPPFLAGS -D_GNU_SOURCE"
        if test "X$LDCONFIG" != "X" -a "X$SED" != "X"; then
            LDCONFIG_CMD="$LDCONFIG -p | $SED -n -e '/lib64/n' -e '/^	/s/^.*=> //p'"
        fi
        ;;
    *linux*)
        CPPFLAGS="$CPPFLAGS -D_GNU_SOURCE"
        if test "X$LDCONFIG" != "X" -a "X$SED" != "X"; then
            LDCONFIG_CMD="$LDCONFIG -p | $SED -n '/^	/s/^.*=> //p'"
        fi
        ;;
    *-*-gnu*|*-*-kfreebsd*-gnu)
        CPPFLAGS="$CPPFLAGS -D_GNU_SOURCE"
        if test "X$LDCONFIG" != "X" -a "X$SED" != "X"; then
            LDCONFIG_CMD="$LDCONFIG -p | $SED -n '/^	/s/^.*=> //p'"
        fi
        ;;
    *freebsd*)
        if test "X$LDCONFIG" != "X" -a "X$SED" != "X"; then
            LDCONFIG_CMD="$LDCONFIG -r | $SED -n '/^	/s/^.*=> //p'"
        fi
        ;;
    *netbsd*)
        SYS_LIBRARY_PATHS="$SYS_LIBRARY_PATHS /usr/pkg/lib"
        if test "X$LDCONFIG" != "X" -a "X$SED" != "X"; then
            LDCONFIG_CMD="$LDCONFIG -r | $SED -n '/^	/s/^.*=> //p'"
        fi
        ;;
    *-cygwin*|*-mingw*)
        dnl Gauche's uvector library file name was changed in Gauche v0.9.5_pre1.
        GAUCHE_SYSDIR=`"$GAUCHE_CONFIG" --sysarchdir | sed 's/\\\\/\\//g'`
        GAUCHE_UVECTOR_DLL="$GAUCHE_SYSDIR/gauche--uvector.$SOEXT"
        if test -e "$GAUCHE_UVECTOR_DLL"; then
            GAUCHE_UVECTOR_LIBS="-lgauche--uvector"
        else
            GAUCHE_UVECTOR_LIBS="-lgauche-uvector"
        fi
        LIBS="$GAUCHE_UVECTOR_LIBS -lpsapi $LIBS"
        LDFLAGS="$LDFLAGS -L."
        TESTLIB_CFLAGS="-c -o"
        CPARSER_LIBS="-lc-ffi -lc-lex"
        SYS_LIBRARY_PATHS="$SYS_LIBRARY_PATHS /usr/bin"
        CWCOMPILE_DEFAULT_LIBS="$GAUCHE_UVECTOR_LIBS"
        CWCOMPILE_SHEBANG="/usr/bin/env gosh"
        case "$target" in
            *-cygwin*)
                CYGWIN_FLAG="#t"
                ;;
            *-mingw*)
                MINGW_FLAG="#t"
                FFI_SRC_ADD="mman.c"
                ;;
        esac
        ;;
esac

if test "$enable_objc" = "yes"; then
   CPPFLAGS="$CPPFLAGS -x objective-c -fobjc-exceptions"
   LDFLAGS="$LDFLAGS -framework Foundation"
   OBJC_ENABLE_TRUE=""
   STUBGEN_FFI_MODULE=c-wrapper.objc-ffi
else
   OBJC_ENABLE_TRUE="#"   
fi
AC_SUBST(LD_LIBRARY_PATH_ENVS)
AC_SUBST(TESTLIB_CFLAGS)
AC_SUBST(TESTLIB_LDFLAGS)
AC_SUBST(OBJC_ENABLE_TRUE)
AC_SUBST(STUBGEN_FFI_MODULE)
AC_SUBST(LDCONFIG_CMD)
AC_SUBST(SYS_LIBRARY_PATHS)
AC_SUBST(CPARSER_LIBS)
AC_SUBST(CYGWIN_FLAG)
AC_SUBST(MINGW_FLAG)
AC_SUBST(CWCOMPILE_DEFAULT_LIBS)
AC_SUBST(CWCOMPILE_SHEBANG)
AC_SUBST(FFI_SRC_ADD)

dnl Creating gpd (gauche package description) file
GAUCHE_PACKAGE_CONFIGURE_ARGS="`echo ""$ac_configure_args"" | sed 's/[\\""\`\$]/\\\&/g'`"
AC_MSG_NOTICE([creating ${PACKAGE_NAME}.gpd])
"$GAUCHE_PACKAGE" make-gpd "$PACKAGE_NAME" \
  -version "$PACKAGE_VERSION" \
  -configure "./configure $GAUCHE_PACKAGE_CONFIGURE_ARGS"

dnl Output
echo $PACKAGE_VERSION > VERSION
AC_OUTPUT(Makefile src/Makefile lib/Makefile objc/Makefile testsuite/Makefile src/cwcompile lib/c-wrapper/config.scm lib/c-wrapper/stubgen.scm doc/Makefile)

