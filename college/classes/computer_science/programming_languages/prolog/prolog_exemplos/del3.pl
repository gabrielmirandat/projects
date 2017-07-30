del3(L,L1) :- append(L1,[_,_,_],L).
del_3_3(L,L2) :- del3(L,L1),[_,_,_|L2]=L1.
