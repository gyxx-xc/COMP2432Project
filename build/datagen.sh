:;exec emacs -batch -l   "$0" "$@" --no-site-file -q  # -*- Emacs-Lisp -*-
;     @emacs -batch -l "%~f0"  %*  --no-site-file -q  & goto :EOF
;
;; this is NOT a bash shell script

(random t)
(let ((x 0))
  (while (< x 100)
    (princ
     (format "addORDER P%04d %s %d00 Product_%c\n"
             (+ x 1)
             (format-time-string
              "%Y-%m-%d" (time-add
                          (date-to-time "2024-06-01")
                          (days-to-time (random 30))))
             (+ (random 50) 1)
             (+ 65 (random 9))))
    (setq x (+ x 1))))
;
;:EOF
