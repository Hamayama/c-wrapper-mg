/*
   stdio_patch.h
   2018-2-3

   This is a patch for stdio.h in MSYS2/MinGW-w64 (64bit/32bit).
*/

#if defined(__MINGW32__) && defined(__MINGW64_VERSION_MAJOR) && \
    defined(_MSVCRT_) && (__MSVCRT_VERSION__ < 1900)
#undef stdin
#undef stdout
#undef stderr
#define stdin  (&__iob_func()[0])
#define stdout (&__iob_func()[1])
#define stderr (&__iob_func()[2])
#endif

