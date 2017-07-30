cidades :- repeat, nl, write(' cidade (ultima = fim) >'), read(X), assertz(cidade(X)), X= fim, !.
vizinhos :- repeat, cidade(X), 
     ( X = fim, !; 
        nl, write('Informe os vizinhos  de '),
        write(X), read(Ys), assertz(vizinhos(X,Ys))), fail.