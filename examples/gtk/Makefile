SOEXT = $(shell gauche-config --so-suffix)

gtklib.$(SOEXT): gtk-hello.scm
	cwcompile --verbose gtk-hello.scm

run: gtklib.$(SOEXT)
	gosh -I. gtk-hello.scm

clean:
	cwcompile --verbose --clean gtk-hello.scm

