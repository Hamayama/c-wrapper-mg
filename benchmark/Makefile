#
# $Id: Makefile.in 568 2009-02-11 07:41:38Z naoki $
#

# These may be overridden by make invocators
DESTDIR        =
GAUCHE_PACKAGE = gauche-package

CPPFLAGS       = -I. -DGAUCHE_API_0_8_8
LDFLAGS        = 
LIBS           = 

# Other parameters
SOEXT  = $(shell gauche-config --so-suffix)
DYLIBEXT = $(shell gauche-config --dylib-suffix)
OBJEXT = o
EXEEXT = 

TARGET    = test_func.$(SOEXT) test_func2.$(DYLIBEXT)
GENERATED = 

test_func_SRCS = test_func.c test_funclib.stub

all : benchmark

benchmark: $(TARGET)
	gosh -I. -I../src -I../lib test_func.scm
	gosh -I. -I../src -I../lib lexer.scm "`pkg-config gtk+-2.0 --cflags-only-I`" gtk/gtk.h
	gosh -I. -I../src -I../lib parser-only.scm "`pkg-config gtk+-2.0 --cflags-only-I`" gtk/gtk.h
	gosh -I. -I../src -I../lib parser-bench.scm

funccall: $(TARGET)
	gosh -ptime -I. -I../src -I../lib test_func.scm

c-load: $(TARGET)
	gosh -ptime -I. -I../src -I../lib parser-bench.scm

c-scan: $(TARGET)
	gosh -ptime -I. -I../src -I../lib lexer.scm "`pkg-config gtk+-2.0 --cflags-only-I`" gtk/gtk.h

c-parse: $(TARGET)
	gosh -ptime -I. -I../src -I../lib parser-only.scm "`pkg-config gtk+-2.0 --cflags-only-I`" gtk/gtk.h

test_func.$(SOEXT): $(test_func_SRCS)
	$(GAUCHE_PACKAGE) compile --cppflags="-DUSE_STUB $(CPPFLAGS)" --ldflags="$(LDFLAGS)" --libs="$(LIBS)" --verbose test_func $(test_func_SRCS)

test_func2.$(DYLIBEXT): test_func.c
	gcc -c -fPIC -o test_func2.$(OBJEXT) $<
	gcc `gauche-config --dylib-ldflags` $@ test_func2.$(OBJEXT)

clean :
	$(GAUCHE_PACKAGE) compile --clean test_func $(test_func_SRCS)
	rm -rf core $(TARGET) $(GENERATED) *.o *~ so_locations

distclean : clean

maintainer-clean : clean

