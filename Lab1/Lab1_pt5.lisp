;;; 5. Loop for, and car and cdr

(princ "This is the list:")
(terpri)
(setq DC_char '(superman batman aquaman flash joker))
(setq fourth (cadddr DC_char))

(loop for y from 1 to (length DC_char) 
	do (format t "~a ~%" (car DC_char))
	(setq DC_char (cdr DC_char))
)

(format t "4th Item = ~a ~%" fourth)







