SOEXT = $(shell gauche-config --so-suffix)

sdllib.$(SOEXT): breakout.scm
	cwcompile --verbose breakout.scm

run: sdllib.$(SOEXT)
	gosh -I. breakout.scm

clean:
	cwcompile --verbose --clean breakout.scm

