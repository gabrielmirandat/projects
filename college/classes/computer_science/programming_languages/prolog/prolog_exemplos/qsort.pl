separa(B,[X|Xs],[X|Ys],Zs) :- X @=< B, separa(B,Xs,Ys,Zs).
separa(B,[X|Xs],Ys,[X|Zs]) :- X @>  B, separa(B,Xs,Ys,Zs).
separa(_, [],[],[]).

qsort([X|Xs],Rs) :- separa(X,Xs,Ys, Zs), 
                    qsort(Ys,Ry),
                    qsort(Zs,Rz),
                    append(Ry,[X|Rz], Rs).
qsort([],[]).
