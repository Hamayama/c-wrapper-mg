;;;
;;; Test ffi
;;;

(use gauche.test)

(test-start "c-wrapper (ffi)")
(use c-wrapper)
(use gauche.uvector)
(use gauche.config)
(test-module 'c-wrapper)

(define DYLIB (string-append "./ffitest." (gauche-config "--dylib-suffix")))
(define dlopen (with-module c-wrapper dlopen))
(define dlclose (with-module c-wrapper dlclose))
(define dlsym (with-module c-wrapper dlsym))
(define ffi-type-uint (with-module c-wrapper ffi-type-uint))
(define ffi-type-sint (with-module c-wrapper ffi-type-sint))
(define ffi-type-pointer (with-module c-wrapper ffi-type-pointer))
(define ffi-prep-cif (with-module c-wrapper ffi-prep-cif))
(define ffi-call (with-module c-wrapper ffi-call))
(define ffi-prep-closure (with-module c-wrapper ffi-prep-closure))
(define ffi-closure (with-module c-wrapper ffi-closure))

(test "dlopen"
      #f
      (lambda ()
        (let ((handle (dlopen DYLIB)))
          (begin0
            (null-ptr? handle)
            (dlclose handle)))))
          

(test "dlsym"
      #f
      (lambda ()
        (let* ((handle (dlopen DYLIB))
               (ptr (dlsym "add_uint")))
          (begin0
            (null-ptr? ptr)
            (dlclose handle)))))

(test "ffi_prep_cif"
      (with-module c-wrapper FFI_OK)
      (lambda ()
        (let* ((handle (dlopen DYLIB))
               (fn (dlsym "add_uint")))
          (receive (status cif)
              (ffi-prep-cif (ffi-type-uint) (list (ffi-type-uint)
                                                  (ffi-type-uint)))
            (begin0
              status
              (dlclose handle))))))

(test "ffi_call"
      3
      (lambda ()
        (let* ((handle (dlopen DYLIB))
               (fn (dlsym "add_uint"))
               (rvalue (make <c-uint>))
               (v1 (make <c-uint>))
               (v2 (make <c-uint>)))
          (receive (status cif)
              (ffi-prep-cif (ffi-type-sint) (list (ffi-type-uint)
                                                  (ffi-type-uint)))
            (v1 1)
            (v2 2)
            (ffi-call cif fn (ptr rvalue)
                      (list (slot-ref v1 'buffer) (slot-ref v2 'buffer)))
            (begin0
              (rvalue)
              (dlclose handle))))))

(test "ffi_closure"
      #t
      (lambda ()
        (let* ((handle (dlopen DYLIB))
               (fn (dlsym "callback")))
          (receive (status cif)
              (ffi-prep-cif (ffi-type-sint) (list (ffi-type-sint)
                                                  (ffi-type-sint)))
            (receive (status closure)
                (ffi-prep-closure cif (lambda (v1 v2)
                                        (let ((result (make <c-int>)))
                                          (result
                                           (+ ((deref (cast (ptr <c-int>) v1)))
                                              ((deref (cast (ptr <c-int>) v2)))))

                                          (ptr result))))
              (begin0
                (and (= status (with-module c-wrapper FFI_OK)) (not (null-ptr? (ffi-closure closure))))
                (dlclose handle)))))))

(test "call callback"
      5
      (lambda ()
        (let* ((handle (dlopen DYLIB))
               (fn (dlsym "callback_sint"))
               (v1 (make <c-int>))
               (v2 (make <c-int>))
               (rvalue (make <c-int>)))
          (receive (status cif_closure)
              (ffi-prep-cif (ffi-type-sint) (list (ffi-type-sint)
                                                  (ffi-type-sint)))
            (receive (status closure)
                (ffi-prep-closure cif_closure
                                  (lambda (v1 v2)
                                    (let ((result (make <c-int>)))
                                      (result
                                       (+ ((deref (cast (ptr <c-int>) v1)))
                                          ((deref (cast (ptr <c-int>) v2)))))
                                      (ptr result))))
              (receive (status cif)
                  (ffi-prep-cif (ffi-type-sint) (list (ffi-type-pointer)
                                                      (ffi-type-sint)
                                                      (ffi-type-sint)))
                (v1 -3)
                (v2 8)
                (ffi-call cif fn (ptr rvalue) (list (slot-ref (ffi-closure closure) 'buffer)
                                                    (slot-ref v1 'buffer)
                                                    (slot-ref v2 'buffer)))
                (begin0
                  (rvalue)
                  (dlclose handle))))))))

;; epilogue
(test-end)

