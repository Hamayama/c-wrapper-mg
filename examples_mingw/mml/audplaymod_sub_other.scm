;(set! ignore-libname-list (append ignore-libname-list '("mingw32" "SDL2main")))
;(set! ignore-library-list (append ignore-library-list '("libmingw32" "libSDL2main"))))
(c-load '("stdio.h" "stdlib.h" "SDL.h" "SDL_mixer.h")
        :cppflags-cmd "bash -c 'sdl2-config --cflags'"
        :libs-cmd     "bash -c 'sdl2-config --libs; echo \"-lSDL2_mixer\"'"
        :import (list (lambda (header sym)
                        ;(print header " " sym)
                        (#/\/SDL2\/.*\.h$/ header))
                      'NULL)
        :compiled-lib "sdl2audlib")
