;;;; 1. Hello Your Name 

(print "What is your name?")
(terpri)
(setq *name* (read-line))
(format t"Hello ~a, Welcome to CS3342!" *name*)


