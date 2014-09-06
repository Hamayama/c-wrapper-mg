;; -*- coding: utf-8; mode: scheme -*-
;;
;; test_func.scm - 
;;
;;   Copyright (c) 2009 KOGURO, Naoki (naoki@koguro.net)
;;   All rights reserved.
;;
;;   Redistribution and use in source and binary forms, with or without 
;;   modification, are permitted provided that the following conditions 
;;   are met:
;;
;;   1. Redistributions of source code must retain the above copyright 
;;      notice, this list of conditions and the following disclaimer.
;;   2. Redistributions in binary form must reproduce the above copyright 
;;      notice, this list of conditions and the following disclaimer in the 
;;      documentation and/or other materials provided with the distribution.
;;   3. Neither the name of the authors nor the names of its contributors 
;;      may be used to endorse or promote products derived from this 
;;      software without specific prior written permission.
;;
;;   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
;;   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
;;   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
;;   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
;;   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
;;   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED 
;;   TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
;;   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
;;   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
;;   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
;;   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;;

(use c-wrapper)
(use gauche.time)

(define-module test_func
  (export-all))

(dynamic-load "test_func")

(import test_func)

(c-load-library "./test_func2")
(c-include "test_func.h")

(define (do-benchmark msg n trunk)
  (let ((counter (make <real-time-counter>)))
    (gc) (gc)
    (with-time-counter counter
      (dotimes (i n)
        (trunk)))
    (format #t "[~a] Time: ~s ns.\n" msg (round->exact (* (/ (time-counter-value counter) n) 1000000000)))))

(do-benchmark "func_void (stub version)" 1000000 (cut %func_void))
(do-benchmark "func_void (c-wrapper version)" 1000000 (cut func_void))

(do-benchmark "func_int_int (stub version)" 1000000 (cut %func_int_int 1))
(do-benchmark "func_int_int (c-wrapper version)" 1000000 (cut func_int_int 1))

(do-benchmark "func_double_int (stub version)" 1000000 (cut %func_double_int 1))
(do-benchmark "func_double_int (c-wrapper version)" 1000000 (cut func_double_int 1))

(do-benchmark "func_double_double (stub version)" 1000000 (cut %func_double_double 1.0))
(do-benchmark "func_double_double (c-wrapper version)" 1000000 (cut func_double_double 1.0))

(do-benchmark "func_intx32 (stub version)" 1000000 (cut %func_intx32
                                                       0  1  2  3  4  5  6  7  8  9 
                                                       10 11 12 13 14 15 16 17 18 19 
                                                       20 21 22 23 24 25 26 27 28 29 
                                                       30 31))
(do-benchmark "func_intx32 (c-wrapper version)" 1000000 (cut func_intx32
                                                            0  1  2  3  4  5  6  7  8  9 
                                                            10 11 12 13 14 15 16 17 18 19 
                                                            20 21 22 23 24 25 26 27 28 29 
                                                            30 31))
(do-benchmark "func_var 1 (c-wrapper version)" 100000 (cut func_var
                                                         0))
(do-benchmark "func_var 2 (c-wrapper version)" 100000 (cut func_var
                                                         0  1))
(do-benchmark "func_var 4 (c-wrapper version)" 100000 (cut func_var
                                                         0  1  2  3))
(do-benchmark "func_var 8 (c-wrapper version)" 100000 (cut func_var
                                                         0  1  2  3  4  5  6  7))
(do-benchmark "func_var 16 (c-wrapper version)" 100000 (cut func_var
                                                         0  1  2  3  4  5  6  7  8  9 
                                                         10 11 12 13 14 15))
(do-benchmark "func_var 32 (c-wrapper version)" 100000 (cut func_var
                                                         0  1  2  3  4  5  6  7  8  9 
                                                         10 11 12 13 14 15 16 17 18 19 
                                                         20 21 22 23 24 25 26 27 28 29 
                                                         30 31))
;; end of file


