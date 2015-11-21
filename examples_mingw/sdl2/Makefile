SOEXT = $(shell gauche-config --so-suffix)

sdllib.$(SOEXT): breakout-mg.scm
	cwcompile --verbose breakout-mg.scm

run: sdllib.$(SOEXT)
	gosh -I. breakout-mg.scm

clean:
	cwcompile --verbose --clean breakout-mg.scm

