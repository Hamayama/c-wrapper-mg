(c-load '("stdio.h" "stdlib.h" "SDL.h" "SDL_ttf.h")
        :cppflags "-Ic:/msys64/mingw32/include/SDL2 -D_SDL_cpuinfo_h"
        :libs     "-Lc:/msys64/mingw32/bin -lSDL2 -lSDL2_ttf"
        :import (list (lambda (header sym)
                        ;(print header " " sym)
                        (#/\/SDL2\/.*\.h$/ header))
                      'NULL)
        :compiled-lib "sdl2ttflib64_32")
