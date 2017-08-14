irmas(A,B) :- pai(P,A), pai(P,B),  A\==B. 
avo(A,N) :- pai(P,N), pai(A,P).
tio(T,S) :- pai(P,S), irmas(P,T).