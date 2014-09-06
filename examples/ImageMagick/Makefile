SOEXT = $(shell gauche-config --so-suffix)

magicklib.$(SOEXT): magick.scm
	cwcompile --verbose magick.scm

run: magicklib.$(SOEXT)
	gosh -I. magick.scm

clean:
	cwcompile --verbose --clean magick.scm
	rm -f thumbnail.png

