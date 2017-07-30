module(if, [se/1,entao/2,senao/2]).
:- op(750,fx,se).
:- op(800,xfx,entao).
:- op(810,xfx,senao).
se X :- X.
X entao Y :- X, Y.
X senao _ :- X,!.
_ senao Z :- Z.
