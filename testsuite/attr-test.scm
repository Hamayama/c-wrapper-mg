;;;
;;; Test parse-attribute
;;;

(use gauche.test)

(test-start "parse-attribute")
(use c-wrapper)
(test-module 'c-wrapper.c-lex)

(define-macro (test-attribute desc expected source)
  `(test ,desc ,expected
         (lambda ()
           (with-module c-wrapper.c-parser
             (with-parse-context
              (lambda ()
                (set-input-string! ,source)
                ((with-module c-wrapper.c-lex parse-attribute))
                (parser-attribute)))))))

(test-attribute "an attribute without args" '((always_inline)) "((always_inline))")
(test-attribute "an attribute is equals to C keyword" '((const)) "((const))")
(test-attribute "an attribute with a string arg" '((alias "__f")) "((alias(\"__f\")))")
(test-attribute "an attribute with numerical args" '((format printf 2 3)) "((format(printf, 2, 3)))")
(test-attribute "attribute list" '((weak) (alias "__f")) "((weak, alias(\"__f\")))")
(test-attribute "multiple attributes" '((weak) (alias "__f") (format printf 2 3)) "((weak, alias(\"__f\"))) __attribute__((format(printf, 2, 3)))")

(test "check token list"
      '((UNION LCBRA UNSIGNED (IDENTIFIER . __l) SEMICOLON (TYPENAME . double) (IDENTIFIER . __d) SEMICOLON RCBRA *eoi*)
        ((__mode__ __DI__)))
      (lambda ()
        (with-module c-wrapper.c-parser
          (with-parse-context
           (lambda ()
             (set-input-string! "union { unsigned __l __attribute__((__mode__(__DI__))); double __d; }")
             (let ((token-list (do ((lst (list (c-scan)) (cons (c-scan) lst)))
                                   ((eq? (car lst) '*eoi*)
                                    (reverse lst)))))
               (list token-list (parser-attribute))))))))

;; epilogue
(test-end)

