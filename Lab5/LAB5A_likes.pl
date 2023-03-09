% Some simple test Prolog programs
% --------------------------------

% Knowledge bases

loves(vincent, mia).
loves(marcellus, mia).
loves(pumpkin, honey_bunny).
loves(honey_bunny, pumpkin).

likes(dan,sally).
likes(sally,dan).
likes(josh,brittney).

dating(X,Y) :-
    likes(X,Y),
    likes(Y,X).
    
friendship(X,Y) :-
    likes(X,Y);
    likes(Y,X).

jealous(X, Y) :-
    loves(X, Z),
    loves(Y, Z).


/** <examples>
?- loves(X, mia).
?- jealous(X, Y).
?- dating(sally,dan).
?- friendship(josh,brittney). */

