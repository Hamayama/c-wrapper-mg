(c-load '("stdio.h" "stdlib.h" "SDL.h" "SDL_mixer.h")
        :cppflags "-Ic:/msys64/mingw32/include/SDL2 -D_SDL_cpuinfo_h -DSDL_cpuinfo_h_"
        :libs     "-Lc:/msys64/mingw32/bin -lSDL2 -lSDL2_mixer"
        :import (list (lambda (header sym)
                        ;(print header " " sym)
                        (#/\/SDL2\/.*\.h$/ header))
                      'NULL)
        :compiled-lib "sdl2audlib64_32")
