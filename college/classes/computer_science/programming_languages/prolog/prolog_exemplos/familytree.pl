parent(pam,bob).
parent(tom,bob).
parent(tom,liz).
parent(bob,ann).
parent(bob,patty).
parent(patty,jim).
man(bob).
man(tom).
man(jim).
man(patty).
female(pam).
female(liz).
female(ann).
offspring(Y,X) :- parent(X,Y).
predecessor(X,Z) :- parent(X,Z).
predecessor(X,Z) :- parent(X,Y), predecessor(Y,Z).
first_son(X,Y):-man(X),parent(Y,X),!.
first_lady(X,Y):-female(X),parent(Y,X),!.