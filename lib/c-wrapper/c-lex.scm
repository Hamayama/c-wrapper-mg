;;;
;;; C-LEX for C-PARSE
;;;

(define-module c-wrapper.c-lex
  (use c-wrapper.context)
  (use srfi-1)
  (use util.queue)

  (export c-scan
          make-error-message
          print-current-line
          lineno
          lineno-set!
          filename
          filename-set!
          set-input-port!
          free-input-port!
          set-input-string!
          last-token-set!
          init-type-table
          install-type
          start-macro-set!
          start-macro-reset!
          parser-attribute-clear!
          parser-attribute
          parser-attribute-add!)
  (dynamic-load "c-lex")
  )

(select-module c-wrapper.c-lex)

(define (make-error-message msg)
  (format "~a:~a: ~a (at token: ~s)" (filename) (lineno) msg (last-token)))

(define (print-current-line)
  (let ((str (current-line)))
    (format (current-error-port) "~a:~a: ~a" (filename) (lineno) str)
    (unless (and (string? str) (#/\n$/ str))
      (newline (current-error-port)))))

;; (define-inline (buf-read-line)
;;   (let ((line (read-line (input-port) #t)))
;;     (current-line line)
;;     (cond
;;      ((eof-object? line)
;;       (let ((chars (circular-list line)))
;;         (rest-chars chars)
;;         chars))
;;      ((eq? (string-size line) 0)
;;       (lineno (+ (lineno) 1))
;;       (buf-read-line))
;;      ((string-incomplete? line)
;;       (lineno (+ (lineno) 1))
;;       (buf-read-line))
;;      (else
;;       (lineno (+ (lineno) 1))
;;       (let ((chars (string->list (string-append line "\n"))))
;;         (rest-chars chars)
;;         chars)))))

;; (define-inline (buf-read-char)
;;   (let ((rest (rest-chars)))
;;     (when (null? rest)
;;       (set! rest (buf-read-line)))
;;     (rest-chars (cdr rest))
;;     (car rest)))

;; (define-inline (buf-peek-char)
;;   (let ((rest (rest-chars)))
;;     (when (null? rest)
;;       (set! rest (buf-read-line)))
;;     (car rest)))

;; (define-inline (buf-next-char)
;;   (rest-chars (cdr (rest-chars))))

;;
;; (define c-keywords
;;   '((auto        AUTO)
;;     (break       BREAK)		
;;     (case        CASE)		
;;     (const	 CONST)		
;;     (__const	 CONST)		
;;     (continue	 CONTINUE)	
;;     (default	 DEFAULT)	
;;     (do		 DO)		
;;     (else	 ELSE)		
;;     (enum	 ENUM)		
;;     (extern	 EXTERN)	
;;     (for	 FOR)		
;;     (goto	 GOTO)		
;;     (if		 IF)		
;;     (register	 REGISTER)	
;;     (return	 RETURN)	
;;     (signed	 SIGNED)
;;     (__signed    SIGNED)
;;     (sizeof	 SIZEOF)	
;;     (static	 STATIC)	
;;     (struct	 STRUCT)	
;;     (switch	 SWITCH)	
;;     (typedef	 TYPEDEF)	
;;     (union	 UNION)		
;;     (unsigned	 UNSIGNED)
;;     (__unsigned  UNSIGNED)
;;     (volatile	 VOLATILE)	
;;     (__volatile	 VOLATILE)
;;     (__volatile__ VOLATILE)
;;     (while	 WHILE)
;;     (inline  INLINE)
;;     (__inline    INLINE)
;;     (__inline__  INLINE)
;;     (asm         ASM)
;;     (__asm       ASM)
;;     (__asm__     ASM)
;;     (__restrict  RESTRICT)
;;     (__restrict__  RESTRICT)
;;     (__extension__ EXTENSION)
;;     (__attribute__ ATTRIBUTE) ; ignore
;;     (@interface AT_INTERFACE)
;;     (@implementation AT_IMPLEMENTATION)
;;     (@end AT_END)
;;     (@selector AT_SELECTOR)
;;     (@defs AT_DEFS)
;;     (@encode AT_ENCODE)
;;     (@public AT_PUBLIC)
;;     (@private AT_PRIVATE)
;;     (@protected AT_PROTECTED)
;;     (@protocol AT_PROTOCOL)
;;     (@class AT_CLASS)
;;     (@compatibility_alias AT_ALIAS)
;;     (@throw AT_THROW)
;;     (@try AT_TRY)
;;     (@catch AT_CATCH)
;;     (@finally AT_FINALLY)
;;     (@synchronized AT_SYNCHRONIZED)
;;     (@property AT_PROPERTY)
;;     (@synthesize AT_SYNTHESIZE)
;;     (@dynamic AT_DYNAMIC)
;;     (@optional AT_OPTIONAL)
;;     (@required AT_REQUIRED)
;;     ))

;; (define c-operators
;;   '((>>=         RIGHT_ASSIGN)
;;     (<<=         LEFT_ASSIGN)
;;     (+=          ADD_ASSIGN)
;;     (-=          SUB_ASSIGN)
;;     (*=          MUL_ASSIGN)
;;     (/=          DIV_ASSIGN)
;;     (%=          MOD_ASSIGN)
;;     (&=          AND_ASSIGN)
;;     (^=          XOR_ASSIGN)
;;     ;;(|=          OR_ASSIGN)
;;     (>>          RIGHT_OP)
;;     (<<          LEFT_OP)
;;     (>           >)
;;     (<           <)
;;     (++          INC_OP)
;;     (--          DEC_OP)
;;     (->          PTR_OP)
;;     (&&          AND_OP)
;;     ;;(||          OR_OP)
;;     (<=          LE_OP)
;;     (>=          GE_OP)
;;     (==          EQ_OP)
;;     (!=          NE_OP)
;;     (*           *)
;;     (/           /)
;;     (+           +)
;;     (-           -)
;;     (%           %)
;;     (&           &)
;;     (^           ^)
;;     (=           =)
;;     (?           ?)
;;     (!           !)
;;     (~           ~)
;;     ))

;;;
;;;
;;;
;; (define %keyword-tbl (let ((tbl (make-hash-table)))
;;                        (for-each (lambda (lst)
;;                                    (hash-table-put! tbl (car lst) lst))
;;                                  c-keywords)
;;                        tbl))

;; (define %operator-tbl (let ((tbl (make-hash-table)))
;;                         (for-each (lambda (lst)
;;                                     (hash-table-put! tbl (car lst) lst))
;;                                   c-operators)
;;                         tbl))

;; (define (get-keyword-val symbol) (hash-table-get %keyword-tbl symbol #f))

;; (define (get-operator-val symbol) (hash-table-get %operator-tbl symbol #f))

;;;
;;;
;;;
;; gcc of GCC allows dollar sign
;;(define initial-identifier-charset #[A-Za-z_])
;;(define identifier-charset         #[A-Za-z_0-9])  
;; (define initial-identifier-charset #[A-Za-z_$@])
;; (define identifier-charset #[A-Za-z_$0-9])  

;; (define operator-charset #[*~!+\-/\^&%=?<>])
;; (define special-operator-charset #[|.]) ; cant be in scheme symbol

;; (define scheme-token-charset 
;;   (char-set    #\.			; DOT
;; 	       #\:			; COLON
;; 	       #\(			; LPAREN
;; 	       #\)			; RPAREN
;; 	       #\{			; LCBRA
;; 	       #\}			; RCBRA
;; 	       #\[			; LSBRA
;; 	       #\]			; RSBRA
;; 	       #\|			; OR
;; 	       ))

;; (define (char-digit? c)         (char-set-contains? #[0-9] c))
;; (define (char-nonzero-digit? c) (char-set-contains? #[1-9] c))
;; (define (char-hex-digit? c)     (char-set-contains? #[0-9A-Fa-f] c))
;; (define (char-octal-digit? c)   (char-set-contains? #[0-7] c))
 
;; (define skip-spaces
;;   (let ((space-char-list '(#\space #\tab #\x0b #\page)))
;;     (lambda ()
;;       (let loop ((c (buf-peek-char)))
;;         (when (memq c space-char-list)
;;           (buf-next-char)
;;           (loop (buf-peek-char)))))))

;; (define (skip-line)
;;   (let loop ((c (buf-peek-char)))
;;     (if (and (not (eof-object? c))
;;              (not (char=? c #\newline)))
;;         (begin
;;           (buf-next-char)
;;           (loop (buf-peek-char))))))

;; (define (l->symbol l)
;;   (string->symbol (list->string (reverse l))))

;; (define (read-identifier l)
;;   (let ((c (buf-peek-char)))
;;     (if (char-set-contains? identifier-charset c)
;;         (begin
;;           (buf-next-char)
;;           (read-identifier (cons c l)))
;;         (let ((s (l->symbol l)))
;;           (cond
;;            ((force-identifier?)
;;             (cons 'IDENTIFIER s))
;;            ((get-keyword-val s) => (lambda (k)
;;                                      ;; parse __attribute__
;;                                      (if (eq? k 'ATTRIBUTE)
;;                                          (parse-attribute)
;;                                          k)))
;;            ((memq s '(int long double char short float))
;;             (cons 'TYPENAME s))
;;            ((and (pair? (last-token)) (eq? (car (last-token)) 'TYPENAME))
;;             (cons 'IDENTIFIER s))
;;            ((or (eq? (last-token) 'STRUCT) (eq? (last-token) 'UNION))
;;             (cons 'IDENTIFIER s))
;;            ((eq? (last-token) 'AT_INTERFACE)
;;             (install-type s)
;;             (cons 'IDENTIFIER s))
;;            ((typedefed? s)
;;             (cons 'TYPENAME s))
;;            (else
;;             (cons 'IDENTIFIER s)))))))

;; (define (read-operator c)
;;   (define (l->opval l)
;;     (get-operator-val (l->symbol l)))
;;   (let lp ((cand (l->opval (list c)))
;; 	   (l (list c)))
;;     (let* ((c (buf-peek-char))
;; 	   (k (l->opval (cons c l))))
;;       (if k
;; 	  (begin
;; 	    (buf-next-char)
;; 	    (lp k (cons c l)))
;; 	  cand))))


;;;
;;;
;;;
;; (define (hexchar->integer c)
;;   (cond ((char=? c #\0) 0)
;;         ((char=? c #\1) 1)
;;         ((char=? c #\2) 2)
;;         ((char=? c #\3) 3)
;;         ((char=? c #\4) 4)
;;         ((char=? c #\5) 5)
;;         ((char=? c #\6) 6)
;;         ((char=? c #\7) 7)
;;         ((char=? c #\8) 8)
;;         ((char=? c #\9) 9)
;;         ((char-ci=? c #\a) 10)
;;         ((char-ci=? c #\b) 11)
;;         ((char-ci=? c #\c) 12)
;;         ((char-ci=? c #\d) 13)
;;         ((char-ci=? c #\e) 14)
;;         ((char-ci=? c #\f) 15)
;;         (else
;;          (error "can not be, there must be a bug in lexer"))))

;; (define (backslash c)
;;   (define (readn c n v)
;;     (if (and (> n 0) (char-octal-digit? c))
;;         (begin
;;           (buf-next-char)
;;           (readn (buf-peek-char) 
;;                  (- n 1) 
;;                  (+ (* v 8) (hexchar->integer c))))
;;         (integer->char v)))
;;   (define (readx c)
;;     (let lp ((c c) 
;;              (v 0))
;;       (if  (char-hex-digit? c)
;;            (begin
;;              (buf-next-char)
;;              (lp (buf-peek-char)
;;                  (+ (* v 16) (hexchar->integer c))))
;;            (integer->char v))))
;;   (define (readu c)
;;     (define (range-check v) 
;;       ;; CARM: Sec 2.9, p41
;;       (or (= v #x24)
;;           (= v #x40)
;;           (= v #x60)
;;           (not (or (< v #xa0)
;;                    (and (<= #xd800 v) (<= v #xdfff))))))
;;     (receive (n v)
;;         (let lp ((c c) 
;;                  (n 0) 
;;                  (v 0))
;;           (if (char-hex-digit? c)
;;               (begin
;;                 (buf-read-char)
;;                 (lp (buf-peek-char) 
;;                     (+ n 1)
;;                     (+ (* v 16) (hexchar->integer c))))
;;               (values n v)))
;;       (cond
;;        ((not (or (= n 4) (= n 8)))
;;         (error "Universal character name must be 4 or 8 hex-digit"))
;;        ((not (range-check v))
;;         (errorf "\\u~4,'0x is not a valid universal character" v))
;;        (else
;;         (ucs->char v)))))

;;   (if (char=? c #\\)
;;       (let ((c (buf-read-char)))
;;         (cond                
;; 	 ((char=? c #\n) #\newline)	; NL   0A  ^J
;; 	 ((char=? c #\x)		; not char-ci=?,  cf. CARM p. 35
;;           (if (char-hex-digit? (buf-peek-char))
;;               (readx (buf-peek-char))
;;               (error "\\x must be followed by hex-digit" (buf-peek-char))))
;; 	 ((char=? c #\t) #\tab)		; HT   09  ^I
;;          ((char-ci=? c #\u)
;;           (if (char-hex-digit? (buf-peek-char))
;;               (readu (buf-peek-char))
;;               (error "\\u must be followed by hex-digit" (buf-peek-char))))
;;          ((char-octal-digit? c)
;;           (readn (buf-peek-char) 3 (hexchar->integer c)))
;;          ((char-set-contains? #[?\'\"\\] c) c) ; first two backslash 
;;                                                ; are placed to fool emacs
;;          ((char=? c #\p)
;;           ;; TODO: pascal string
;;           c)
;; 	 ((char=? c #\a) #\x07)		; BEL  07  ^G
;; 	 ((char=? c #\b) #\x08)		; BS   08  ^H
;; 	 ((char=? c #\v) #\x0b)		; VT   0B  ^K
;; 	 ((char=? c #\f) #\page)	; NP   0C  ^L
;; 	 ((char=? c #\r) #\return)	; CR   0D  ^M
;;          ((char-set-contains? #[a-z] c)
;;           (warning "Unknown lower case escape character is used: ~a" c)
;;           c)
;;          ((char-set-contains? #[A-Z] c)
;;           (warning "No upper case espace character is defined: ~a" c)
;;           c)
;;          (else
;;           (buf-read-char))))
;;       c))

;; (define (read-string-literal)
;;   (let lp ((c (buf-read-char))
;;            (s '()))
;;     (if (eof-object? c)
;;         (error "missing double quote")
;;         (if (char=? c #\")
;;             (apply string (reverse s))
;;             (let ((cc (backslash c)))
;;               (lp (buf-read-char) (cons cc s)))))))

;; (define (read-character-constant)
;;   (let lp ((c (buf-read-char))
;;            (s 0))
;;     (if (eof-object? c)
;;         (error "missing quote")
;;         (if (char=? c  #\')
;;             s
;;             (let ((cc (backslash c)))
;;               ;; Meaning of Multicharacter constant is implementation
;;               ;; dependent.  Here we implement a convention with left-to-right
;;               ;; packing, which is  described in CARM pp. 31--32.
;;               (lp (buf-read-char) 
;;                   (+ (* 256 s) 
;;                      (char->integer cc))))))))
;;;
;;; read-hexadecimal, octal.
;;;
;; (define (read-octal-or-flonum l)
;;   (define (rl->n l)
;;     (for-each (lambda (c) 
;;                 (if (not (char-set-contains? #[0-7] c))
;;                     (error "invalid char in octal" c)))
;;               l)
;;     (strtoll (apply string (reverse l))))

;;   (let ((c (buf-peek-char)))
;;     (cond 
;;      ((char-set-contains? #[0-9] c)
;;       (buf-next-char)
;;       (read-octal-or-flonum (cons c l)))
;;      ((char=? #\. c)
;;       (buf-next-char)
;;       (read-flonum (cons c l) #[0-9] 10 #[Ee]))
;;      ((char-set-contains? #[Ee] c) 
;;       (buf-next-char)
;;       (read-expnum (cons c l) 10))
;;      ((char-set-contains? #[ULul] c)
;;       (buf-next-char)
;;       (list (integer-suffix c)
;;             (rl->n l)))
;;      (else
;;       (list 'int (rl->n l))))))
  
;;;
;;; read decimal integer or floating point
;;;
;; (define (read-number-constant l ics radix ecs)

;;   (define (rl->n l)
;;     (strtoll (apply string (reverse l))))

;;   (let ((c (buf-peek-char)))
;;     (cond 
;;      ((char-set-contains? ics c)
;;       (buf-next-char)
;;       (read-number-constant (cons c l) ics radix ecs))
;;      ((char=? c #\.)
;;       (buf-next-char)
;;       (read-flonum (cons c l) ics radix ecs))
;;      ((char-set-contains? ecs c) 
;;       (buf-next-char)
;;       (read-expnum (cons c l) radix))
;;      ((char-set-contains? #[ULul] c)
;;       (buf-next-char)
;;       (list (integer-suffix c)
;;             (rl->n l)))
;;      (else
;;       (list 'int (rl->n l))))))

;; (define (read-decimal l)
;;   (read-number-constant l #[0-9] 10 #[Ee]))
;; (define (read-hexadecimal l) 
;;   (read-number-constant l #[0-9A-Fa-f] 16 #[Pp]))

;; (define (integer-suffix c)
;;   ;; ugly...
;;   (cond 
;;    ((char-ci=? c #\u)
;;     (let ((c (buf-peek-char)))
;;       (cond ((char=? c #\l)
;;              (buf-next-char)
;;              (let ((c (buf-peek-char)))
;;                (if (char=? c #\l)
;;                    (begin
;;                      (buf-next-char)
;;                      'unsigned-long-long)
;;                    'unsigned-long)))
;;             ((char=? c #\L)
;;              (buf-next-char)
;;              (let ((c (buf-peek-char)))
;;                (if (char=? c #\L)
;;                    (begin
;;                      (buf-next-char)
;;                      'unsigned-long-long)
;;                    'unsigned-long)))
;;             (else
;;              'unsigned-int))))

;;    ((char=? c #\l)
;;     (let ((c (buf-peek-char)))
;;       (cond ((char=? c #\l)
;;              (begin
;;                (buf-next-char)
;;                (let ((c (buf-peek-char)))
;;                  (if (char-ci=? c #\u)
;;                      (begin (buf-next-char)
;;                             'unsigned-long-long)
;;                      'long-long))))
;;             ((char-ci=? c #\u)
;;              (buf-next-char)
;;              'unsinged-long)
;;             (else  'long))))

;;    ((char=? c #\L)
;;     (let ((c (buf-peek-char)))
;;       (cond ((char=? c #\L)
;;              (begin
;;                (buf-next-char)
;;                (let ((c (buf-peek-char)))
;;                  (if (char-ci=? c #\u)
;;                      (begin (buf-next-char)
;;                             'unsigned-long-long)
;;                      'long-long))))
;;             ((char-ci=? c #\u)
;;              (buf-next-char)
;;              'unsinged-long)
;;             (else  'long))))
;;    (else
;;     (error "there is a bug in lexer"))))

;; (define (read-flonum l ics radix ecs)
;;   (define (rl->n l)
;;     (strtod (apply string (reverse l))))

;;   (define (error-if-hex)
;;     (if (= radix 16)
;;         (error "hexadecimal floating constants require an exponent")))

;;   (let ((c (buf-peek-char)))
;;     (cond
;;      ((char-set-contains? ics c)
;;       (buf-next-char)
;;       (read-flonum (cons c l) ics radix ecs))
;;      ((char-set-contains? ecs c) 
;;       (buf-next-char)
;;       (read-expnum (cons c l) radix))
;;      ((char-ci=? c #\f)
;;       (buf-next-char)
;;       (error-if-hex)
;;       (list 'float (rl->n l)))
;;      ((char-ci=? c #\l)
;;       (buf-next-char)
;;       (error-if-hex)
;;       (list 'long-double (rl->n l)))
;;      (else
;;       (error-if-hex)
;;       (list 'double (rl->n l))))))

;;;
;;;
;;;
;; (define (read-expnum l radix)

;;   (define (rl->n l) (strtod (apply string (reverse l))))

;;   (define (exp1 c l)
;;     (cond
;;      ((char-numeric? c)
;;       (buf-next-char)
;;       (exp1 (buf-peek-char) (cons c l)))
;;      ((char-ci=? c #\f)
;;       (buf-next-char)
;;       (list 'float (rl->n l)))
;;      ((char-ci=? c #\l)
;;       (buf-next-char)
;;       (list 'long-double (rl->n l)))
;;      (else
;;       (list 'double (rl->n l)))))

;;   (if (char-set-contains? #[0-9\-\+] (buf-peek-char))
;;       (let ((c (buf-read-char)))
;;         (exp1 (buf-peek-char) (cons c l)))
;;       (error "malformed floating point expression")))

;;;
;;;
;;;
(define (follow expect ifyes ifno)
  (let ((c (buf-peek-char)))
    (if (char=? c expect)
        (begin (buf-next-char)
               ifyes)
        ifno)))

;;;
;;;
;;;

(define (enqueue-macro! name args)
  (enqueue! (macro-queue)
            (list* (if args
                       (string-append (symbol->string name)
                                      "("
                                      (string-join (map symbol->string args) ",")
                                      ")")
                       (symbol->string name))
                   (cons (filename) (lineno))
                   name
                   args)))

;; (define sc-ignore         skip-line)
;; (define sc-do-define      skip-line)

;; (define (sc-do-sharp-space)
;;   (skip-spaces)
;;   (let ((c (buf-read-char)))
;;     (when (char-numeric? c)
;;       (let ((num (read-decimal (list c))))
;;         (skip-spaces)
;;         (let ((c (buf-read-char)))
;;           (when (char=? c #\")
;;             (let ((str (read-string-literal)))
;;               (lineno-set! (- num 1))
;;               (filename-set! str))))))
;;     (skip-line)))

;; (define (sc-do-define)
;;   (skip-spaces)
;;   (let ((c (buf-read-char)))
;;     (when (char-set-contains? initial-identifier-charset c)
;;       (force-identifier-set! #t)
;;       (call/cc (lambda (break)
;;                  (let ((name (cdr (read-identifier (list c))))
;;                        (args #f))
;;                    (when (char=? (buf-peek-char) #\()
;;                      (buf-next-char)
;;                      (set! args '())
;;                      (skip-spaces)
;;                      (let loop ((c (buf-read-char)))
;;                        (cond
;;                         ((char=? c #\))
;;                          (set! args (reverse args)))
;;                         ((char-set-contains? initial-identifier-charset c)
;;                          (push! args (cdr (read-identifier (list c))))
;;                          (skip-spaces)
;;                          (loop (buf-read-char)))
;;                         ((char=? c #\,)
;;                          (skip-spaces)
;;                          (loop (buf-read-char)))
;;                         (else
;;                          (break #f)))))
;;                    (enqueue-macro! name args))))
;;       (force-identifier-set! #f))
;;     (skip-line)))

;; (define sharp-commands
;;   `((pragma  ,sc-ignore)
;;     (define  ,sc-do-define))
;;   )

;; (define (do-sharp-command)
;;   (if (char=? (buf-peek-char) #\space)
;;       (begin
;; 	(buf-next-char)
;; 	(sc-do-sharp-space))
;;       (let lp ((c (buf-peek-char))
;; 	       (l '()))
;; 	(cond ((char-alphabetic? c)
;; 	       (buf-next-char)
;; 	       (lp (buf-peek-char) (cons c l)))
;; 	      (else
;; 	       (let ((cmd (assq (l->symbol l) sharp-commands)))
;; 		 (if cmd 
;; 		     ((cadr cmd))
;; 		     (sc-ignore))))))))

;;;
;;; Changes from c-lex.scm:
;;;
;;;   STRING        -> STRING_LITERAL
;;;   OROR          -> OR_OP
;;;   (ASSIGN . OR) -> OR_ASSIGN
;;;
;; (define (c-scan)
;;   (let ((token (%c-scan)))
;;     (last-token-set! token)
;;     token))

;; (define (%c-scan)
;;   (skip-spaces)
;;   (let loop ((c (buf-read-char)))
;;     (cond
;;      ((eof-object? c)  '*eoi*)
;;      ((char=? c #\newline) 
;;       (skip-spaces)
;;       (loop (buf-read-char)))
;;      ((char=? c #\#)
;;       (do-sharp-command)
;;       (skip-spaces)
;;       (loop (buf-read-char)))
;;      ((char=? c #\0)
;;       (cond
;;        ((char-ci=? (buf-peek-char) #\x)
;;         (begin (buf-next-char)
;;                (cons 'CONSTANT (read-hexadecimal '(#\x #\0)))))
;;        (else
;;         (cons 'CONSTANT (read-octal-or-flonum (list c))))))

;;      ((char-numeric? c)
;;       (cons 'CONSTANT (read-decimal (list c))))

;;      ((and (char=? c #\.) (char-numeric? (buf-peek-char)))
;;       (cons 'CONSTANT (read-flonum (list c) #[0-9] 10 #[Ee])))

;;      ((char=? c #\.)  
;;       (if (char=? (buf-peek-char) #\.)
;;           (begin
;;             (buf-next-char)
;;             (if (char=? (buf-peek-char) #\.)
;;                 (begin
;;                   (buf-next-char)
;;                   'ELLIPSIS)
;;                 'UNKNOWN))
;;           'DOT))

;;      ((and (char=? c #\L) (char=? (buf-peek-char) #\"))
;;       (buf-next-char)                       ; L
;;       (cons 'STRING   (read-string-literal)))
;;      ((and (char=? c #\L) (char=? (buf-peek-char) #\'))
;;       (buf-next-char)                       ; L
;;       (cons 'CONSTANT (read-character-constant)))
;;      ((and (char=? c #\@) (char=? (buf-peek-char) #\"))
;;       (buf-next-char)                       ; @
;;       (cons 'OBJC_STRING (read-string-literal)))
;;      ((char=? c #\")
;;       (cons 'STRING (read-string-literal)))
;;      ((char=? c #\')
;;       (cons 'CONSTANT (read-character-constant)))

;;      ((char-set-contains? initial-identifier-charset c)
;;       (read-identifier (list c)))

;;      ((char-set-contains? operator-charset c)
;;       (read-operator c))

;;      ((char=? c #\,)   'COMMA)
;;      ((char=? c #\:)   'COLON)
;;      ((char=? c #\;)   'SEMICOLON)
;;      ((char=? c #\()   'LPAREN)
;;      ((char=? c #\))   'RPAREN)
;;      ((char=? c #\{)   'LCBRA)
;;      ((char=? c #\})   'RCBRA)
;;      ((char=? c #\[)   'LSBRA)
;;      ((char=? c #\])   'RSBRA)

;;      ;; special case for c-operator due to Scheme
;;      ((char=? c #\|)   (or (follow #\| 'OR_OP     #f)   ; ||
;;                            (follow #\= 'OR_ASSIGN #f)   ; |=
;;                            'OR))                        ; |
;;      (else
;;       (error "warning: illegal character: " c)
;;       (skip-spaces)
;;       (loop (buf-read-char))))))
;;;;;;

;; attribute-specifier := __attribute__ ( ( attribute-list )
;; attribute-list      := )
;;                      | attribute attribute-list-rest
;; attribute-list-rest := ) 
;;                      | , ) 
;;                      | , attribute attribute-list-rest
;; attribute           := word
;;                      | word ( param-list
;; param-list          := ) | word param-list-rest
;; param-list-rest     := ) 
;;                      | , ) 
;;                      | , word param-list-rest
;; word                := IDENTIFIER
;;                      | ( word )

(define (parse-attribute)
  (define (token-collector seed)
    (do ((lst (cons (c-scan) seed) (cons (c-scan) lst)))
        ((memq (car lst) '(RPAREN *eoi*))
         (if (eq? (car lst) 'RPAREN)
             lst
             (cdr lst)))
      (when (eq? (car lst) 'LPAREN)
        (set! lst (token-collector lst)))))
  (define (%parse-attribute token-list)
    (call/cc (lambda (break)
               (define (accept t)
                 (and-let* ((result (if (and (pair? (car token-list))
                                             (eq? (caar token-list) t))
                                        (cdar token-list)
                                        (equal? t (car token-list)))))
                   (next)
                   result))
               (define (next)
                 (if (null? (cdr token-list))
                     (break #f)
                     (set! token-list (cdr token-list))))                 
               (define (skip t)
                 (while (accept t)
                   #t))
               (define (word)
                 (cond
                  ((accept 'IDENTIFIER) => values)
                  ((accept 'STRING) => values)
                  ((accept 'CONSTANT) => values)
                  ((accept 'LPAREN)
                   (begin0
                     (word)
                     (skip 'RPAREN)))
                  (else
                   #f)))
               (define (param-list-rest p-lst)
                 (cond
                  ((accept 'RPAREN)
                   (reverse p-lst))
                  ((accept 'COMMA)
                   (cond
                    ((accept 'RPAREN)
                     (reverse p-lst))
                    (else
                     (param-list-rest (cons (word) p-lst)))))
                  (else
                   (next)
                   (param-list-rest p-lst))))
               (define (param-list)
                 (cond
                  ((accept 'RPAREN)
                   '())
                  (else
                   (param-list-rest (list (word))))))
               (define (attribute)
                 (let ((w (word)))
                   (cond
                    ((accept 'LPAREN)
                     (cons w (param-list)))
                    (else
                     (list w)))))
               (define (attribute-list-rest attr-list)
                 (cond
                  ((accept 'RPAREN)
                   (reverse attr-list))
                  ((accept 'COMMA)
                   (cond
                    ((accept 'RPAREN)
                     (reverse attr-list))
                    (else
                     (attribute-list-rest (cons (attribute) attr-list)))))
                  (else
                   (next)
                   (attribute-list-rest attr-list))))
               (define (attribute-list)
                 (cond
                  ((accept 'RPAREN)
                   '())
                  (else
                   (attribute-list-rest (list (attribute))))))
               (define (attribute-specifier)
                 (cond
                  ((accept 'LPAREN)
                   (skip 'LPAREN)
                   (begin0
                     (parser-attribute-add! (attribute-list))
                     (skip 'RPAREN)))
                  (else
                   #t)))
               (attribute-specifier))))
  (let ((t (c-scan)))
    (if (eq? t 'LPAREN)
        (begin
          (%parse-attribute (unwind-protect
                             (begin
                               (force-identifier-set! #t)
                               (reverse (token-collector (list t))))
                             (force-identifier-set! #f)))
          (c-scan))
        t)))

(provide "c-wrapper/c-lex")

;;;;;;
;;;;;; END OF LEXER PART

