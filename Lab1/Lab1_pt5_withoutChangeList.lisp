
(princ "This is the list:")

(terpri)

(setq DC_char '(superman batman aquaman flash joker))

(loop for x from 0 to (- (length DC_char) 1)
	do (format t "~a~%" (nth x DC_char))
)

(format t "4th Item = ~a ~%" (cadddr DC_char))


