;; -*- coding: utf-8; mode: scheme -*-
;;
;; lexer.scm - lexer benchmark 
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
(use gauche.process)
(use gauche.time)
(use srfi-11)
(use benchmark-helpers)

(define lexer-only
  (lambda (include-dirs headers options)
    (with-module c-wrapper.c-parser
      (set! context (make <parse-context>))
      (call-with-output-string
        (lambda (wrapper-out)
          (let ((gcc-error #f))
            (call-with-process-io (cpp-command include-dirs headers options)
              (lambda (in out)
                (close-output-port out)
                (with-input-from-port in
                  (lambda ()
                    (init-type-table)
                    (last-token-set! #f)
                    (set-input-port! in)
                    (while (not (eq? (c-scan) '*eoi*))
                      #t)
                    (free-input-port!))))
              :on-abnormal-exit (lambda (process)
                                  (set! gcc-error (format "process ~a exitted abnormally with exit code ~a"
                                                          (process-pid process)
                                                          (process-exit-status process)))))
            (when gcc-error
              (error gcc-error)))
          (set! context #f))))))

(define (main args)
  (let-optionals* args (cmd option . headers)
    (let ((counter (make <real-time-counter>)))
      (with-time-counter counter
        (lexer-only '() headers (string-split option " ")))
      (format #t "[lexer only] Time: ~s sec~%" (round* (time-counter-value counter) 1))))
  0)

;; end of file
