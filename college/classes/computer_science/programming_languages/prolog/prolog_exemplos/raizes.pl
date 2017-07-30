raizes:- simNao('quer achar as raizes de a*x*x+b*x+c ?'), 
    obtemcoef(A,B,C),
    D is B^2-4*A*C,
    ( D >= 0,  X1 is (-B + sqrt(D))/(2*A),
               X2 is ( B + sqrt(D))/(2*A), nl, 
               write('x1 = '), write(X1),  nl,
               write('x2 = '), write(X2);
      D < 0, nl, write('Nao tem raizes reais')),
    raizes.  

simNao(Msg) :- nl, write(Msg), repeat, 
    write(' (s/n): '),
    get_char(N), nl, member(N,['S','s','N','n']), 
    !, member(N,['S','s']).

obtemcoef(A,B,C) :- 
    obtem('Informe coef a > ', A),
    obtem('Informe coef b > ', B),
    obtem('Informe coef c > ', C).

obtem(Msg,X) :- nl, write(Msg), read(X).
