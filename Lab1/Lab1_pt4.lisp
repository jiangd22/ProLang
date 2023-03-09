;;; 4. Fibonacci Sequence

(princ "How many Fibonacci number do you like to have? ") 
(setq n (read))
(format t "The following are the ~a Fibonacci numbers." n)

(defun fib (n)
	(if (< n 2) n
	(+ (fib (- n 1)) (fib (- n 2)))))


(defun fibs (n)
(loop for I from 1 to n 
collect (fib I)
))

(print (fibs n))


;;; if n = 10
;;; output = (1 1 2 3 5 8 13 21 34 55)
