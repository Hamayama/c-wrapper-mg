#! /usr/local/bin/gosh

(use c-wrapper)
(c-load "curses.h" :libs "-lcurses")

(initscr)
(cbreak)
(noecho)

(let ((hello  " [Hello, Curses World!] ")
      (help " [h]:left [j]:down [k]:up [l]:right [c]:clear [q]: quit "))
  (let* ((line (x->number LINES))
         (maxy (- line 2))
         (cols (x->number COLS))
         (maxx (- cols 2))
         (win (newwin (- line 2) (- cols 2) 1 1)))
    (define (init)
      (wclear win)
      (box win (x->number #\|) (x->number #\-))
      (mvwprintw win 0 (x->integer (/ (- cols (string-length hello)) 2)) hello)
      (mvwprintw win (- line 3) (- cols (string-length help) 5) help)
      (wrefresh win))

    (init)

    ;; main loop
    (let lp ((y (x->integer (/ line 2)))
             (x (x->integer (/ cols 2))))

      (cond ((= y (- maxy 1)) (set! y 1))
            ((= 0 y) (set! y (- maxy 2))))
      (cond ((= x (- maxx 1)) (set! x 1))
            ((= 0 x) (set! x (- maxx 2))))

      (mvwaddch win y x (x->number #\*))
      (wmove win y x)
      (wrefresh win)
      (case (read-char)
        ((#\h) (lp y (- x 1)))
        ((#\j) (lp (+ y 1) x))
        ((#\k) (lp (- y 1) x))
        ((#\l) (lp y (+ x 1)))
        ((#\c) (init) (lp y x))
        ((#\q) (endwin) (exit 0))
        (else (lp y x)))

      )))

