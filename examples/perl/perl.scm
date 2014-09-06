#!/usr/bin/env gosh

(use c-wrapper)

(c-load-library "/System/Library/Perl/5.8.6/darwin-thread-multi-2level/CORE/libperl")
(c-include '("EXTERN.h" "perl.h") :include-dirs "/System/Library/Perl/5.8.6/darwin-thread-multi-2level/CORE")

(define perl (perl_alloc))
(perl_construct perl)
(perl_parse perl NULL 3 '("" "-e" "0") NULL)
(perl_run perl)

(Perl_eval_pv perl "$var = 3; $var **=2;" TRUE)
(print (SvIVX (Perl_get_sv perl "var" FALSE)))

(perl_destruct perl)
(perl_free perl)


