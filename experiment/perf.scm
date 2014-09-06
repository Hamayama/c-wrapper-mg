(use c-wrapper)

(select-module c-wrapper)
(export c-parse)

(define (c-parse)
  (let* ((in (standard-input-port)))
    (guard (e (else
               (raise e)))
           (parameterize ((value-pool (make-hash-table))
                          (struct-pool (make-hash-table))
                          (union-pool (make-hash-table))
                          (typedefed-identifiers (make-initial-install-types))
                          (last-token #f)
                          (macro-queue (make-queue)))
             (with-input-from-port in
               (lambda ()
                 (with-output-to-file "/dev/null"
                   (lambda ()
                     (c-grammar c-scan (lambda (msg . args)
                                         (errorf "~a:~a: ~a ~a (last token: ~s)"
                                                 (filename-of in)
                                                 (lineno-of in)
                                                 msg
                                                 (if (null? args) "" args)
                                                 (last-token))))))))))))


(select-module user)

(define (main args)
  (c-load-library "/System/Library/Frameworks/QuickTime.framework/QuickTime")
  (c-parse)
  0)

