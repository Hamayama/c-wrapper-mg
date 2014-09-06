(use c-wrapper)

(c-load "gtk/gtk.h"
        :cppflags-cmd "pkg-config gtk+-2.0 --cflags-only-I"
        :cflags-cmd   "pkg-config gtk+-2.0 --cflags-only-other"
        :libs-cmd     "pkg-config gtk+-2.0 --libs"
        :import '(gtk_init 
                  gtk_window_new
                  GTK_WINDOW_TOPLEVEL
                  gtk_signal_connect
                  gtk_main_quit
                  gtk_container_set_border_width
                  gtk_button_new_with_label
                  gtk_container_add
                  gtk_widget_show
                  gtk_main
                  NULL)
        ;;         :import '(#/^gtk_/i NULL)
        :compiled-lib "gtklib")

(define (main args)
  (let ((argc (make <c-int>)))
    (gtk_init (ptr argc) (make-null-ptr)))
  (let1 window (gtk_window_new GTK_WINDOW_TOPLEVEL)
    (gtk_signal_connect window
			"destroy"
			(lambda _
			  (format #t "Destroying\n")
			  (gtk_main_quit)
                          NULL)
			(make-null-ptr))
    (gtk_container_set_border_width window 10)
    (let1 button (gtk_button_new_with_label "Hello world")
      (gtk_signal_connect button
			  "clicked"
			  (lambda _
			      (format #t "Hello world\n")
                              NULL)
			  (make-null-ptr))
      (gtk_container_add window button)
      (gtk_widget_show button)
      (gtk_widget_show window)
      ))
  (gtk_main)
  0)
