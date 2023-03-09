;;; 3. Factorial

(princ "Enter a number please?")
(terpri)
(setq n (read))
(format t "The factorial of ~a is" n)
(defun factorial (n)
	(cond
	((= n 1) 1)
	(t (* n (factorial (- n 1))))))
(print (factorial n))

