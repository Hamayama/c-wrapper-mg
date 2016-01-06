(c-load '("stdio.h" "stdlib.h" "SDL.h" "SDL_mixer.h")
        :cppflags "-Ic:/mingw/include/SDL2"
        :libs     "-Lc:/mingw/bin -lSDL2 -lSDL2_mixer"
        :import (list (lambda (header sym)
                        ;(print header " " sym)
                        (#/\/SDL2\/.*\.h$/ header))
                      'NULL)
        :compiled-lib "sdl2audlib32")
