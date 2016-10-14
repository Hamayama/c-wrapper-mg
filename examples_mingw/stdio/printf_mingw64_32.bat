@echo off
set PATH=C:\msys64\mingw32\bin;C:\msys64\usr\local\bin;C:\msys64\usr\bin;C:\msys64\bin;%PATH%
set MSYSTEM=MINGW32
gosh printf.scm
pause
