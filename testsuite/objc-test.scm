;;;
;;; Test objc-wrapper
;;;

(use gauche.test)

(test-start "objc-wrapper")
(use objc-wrapper)
(use gauche.sequence)
(test-module 'objc-wrapper)

(c-load-framework "Foundation")
(c-load-library "./objc-test")
(c-include "./objc-test.h")

[[NSAutoreleasePool 'alloc] 'init]
(define obj [[OBJCTest 'alloc] 'init])

(test "staticMethod"
      5
      (lambda ()
        [OBJCTest 'staticMethod]))

(test "incrementUnsignedChar:"
      3
      (lambda ()
        [obj :incrementUnsignedChar 2]))

(test "incrementSignedChar:"
      -3
      (lambda ()
        [obj :incrementSignedChar -4]))

(test "incrementUnsignedShort:"
      4
      (lambda ()
        [obj :incrementUnsignedShort 3]))

(test "incrementSignedShort:"
      -4
      (lambda ()
        [obj :incrementSignedShort -5]))

(test "incrementUnsignedInt:"
      5
      (lambda ()
        [obj :incrementUnsignedInt 4]))

(test "incrementSignedInt:"
      -5
      (lambda ()
        [obj :incrementSignedInt -6]))

(test "incrementUnsignedLong:"
      6
      (lambda ()
        [obj :incrementUnsignedLong 5]))

(test "incrementSignedLong:"
      -6
      (lambda ()
        [obj :incrementSignedLong -7]))

(test "incrementUnsignedLongLong:"
      7
      (lambda ()
        [obj :incrementUnsignedLongLong 6]))

(test "incrementSignedLongLong:"
      -7
      (lambda ()
        [obj :incrementSignedLongLong -8]))

(test "addFloat:and:"
      1.5
      (lambda ()
        [obj :addFloat 1.0 :and 0.5]))

(test "addDouble:and:"
      -1.5
      (lambda ()
        [obj :addDouble -1.0 :and -0.5]))

(test "appendString:and:"
      YES
      (lambda ()
        (let ((str [obj :appendString (@ "foo") :and (@ "bar")]))
          [str :isEqualToString (@ "foobar")])))

(test "addLargeStruct:valA:valB:"
      '(2 3)
      (lambda ()
        (let ((data (make <TestLarge>)))
          (set! (ref data 'a) 3)
          (set! (ref data 'b) 2)
          (let ((ret [obj :addLargeStruct data :valA -1 :valB 1]))
            (list (ref ret 'a) (ref ret 'b))))))

(test "addSmallStruct:valA:valB:"
      '(2 3)
      (lambda ()
        (let ((data (make <TestSmall>)))
          (set! (ref data 'a) 3)
          (set! (ref data 'b) 2)
          (let ((ret [obj :addSmallStruct data :valA -1 :valB 1]))
            (list (ref ret 'a) (ref ret 'b))))))

(test "addLargeUnion:valA:"
      2
      (lambda ()
        (let ((data (make <TestLargeUnion>)))
          (set! (ref data 'a) 3)
          (let ((ret [obj :addLargeUnion data :valA -1]))
            (ref ret 'a)))))

(test "addSmallUnion:valA:"
      2
      (lambda ()
        (let ((data (make <TestSmallUnion>)))
          (set! (ref data 'a) 3)
          (let ((ret [obj :addSmallUnion data :valA -1]))
            (ref ret 'a)))))

(test "overwriteData:"
      '(1 2)
      (lambda ()
        (let ((data (make <TestLarge>)))
          (set! (ref data 'a) 3)
          (set! (ref data 'b) 2)
          [obj :overwriteData (ptr data)]
          (list (ref data 'a) (ref data 'b)))))

(test "inline function (return NSString)"
      YES
      (lambda ()
        [(returnString) :isEqualToString (@ "foo")]))

(test "inline function (invoke method)"
      YES
      (lambda ()
        [(inlineAppendString (@ "foo") (@ "bar")) :isEqualToString (@ "foobar")]))

(test "inline function (selector)"
      #t
      (lambda ()
        (equal? (@selector "init") (inlineSelector))))


(define-objc-class MyTest NSObject)

(define-objc-method MyTest <c-int> (:addA (v1 <c-int>) :addB (v2 <c-int>))
  (+ v1 v2))

(define *cnt* 0)

(define-objc-class MyTest2 NSObject)

(define-objc-method MyTest2 <id> (:init)
  [super :init]
  (set! *cnt* (+ *cnt* 2))
  self)

(define-objc-method MyTest2 <id> (:myString)
  (@ "foo"))

(define-objc-class MyTest3 MyTest2)

(define-objc-method MyTest3 <id> (:init)
  [super :init]
  (set! *cnt* (* *cnt* 3))
  self)

(define-objc-method MyTest3 <id> (:myString)
  [[super :myString] :stringByAppendingString (@ "bar")])
          

(test "define objc-class and method(1)"
      5
      (lambda ()
        (let ((obj [[MyTest :alloc] :init]))
          [obj :addA 2 :addB 3])))

(test "define objc-class and method(2)"
      (list 6 YES)
      (lambda ()
        (let ((obj [[MyTest3 :alloc] :init]))
          (list *cnt*
                [[obj :myString] :isEqualToString (@ "foobar")]))))

;; epilogue
(test-end)

