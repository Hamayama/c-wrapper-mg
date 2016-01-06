(c-load '("stdio.h" "stdlib.h" "SDL.h" "SDL_ttf.h")
        :cppflags "-Ic:/mingw/include/SDL2"
        :libs     "-Lc:/mingw/bin -lSDL2 -lSDL2_ttf"
        :import (list (lambda (header sym)
                        ;(print header " " sym)
                        (#/\/SDL2\/.*\.h$/ header))
                      'NULL)
        :compiled-lib "sdl2ttflib32")
