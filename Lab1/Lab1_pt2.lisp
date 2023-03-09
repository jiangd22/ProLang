;;; 2. Cond (condition) function

(print "What is the age?")
(terpri)
(setq *age* (read))
(defun college-ready (*age*)
	(cond ( (>= *age* 18) 
			(setf *college-ready* 'yes)
			(format t "Ready for College ~%")
		)
		( (< *age* 18)
			(setf *college-ready* 'no)
			(format t "Not Ready for College ~%")
		)
	)
)
(college-ready *age*)