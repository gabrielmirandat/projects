 %Questao2
 
 
 /**#perguntas e respostas
 * ?- voa(piupiu). 				true.
 * ?- cor(piupiu).				amarelo
 * ?- voa(giserda).				false.
 * ?- asa(giserda).				true.
 * ?- voa(vampe).				true.
 * ?- asa(vampe).				true.
 * ?- oviparo(vampe).				false.
 * ?- mamifero(X), (nada(X); voa(X)). 		X = vampe ;X = orca ;false.
 * ?- animal(X), oviparo(X).			X = piupiu ;X = nemo ;X = giserda ;X = vermelho ;false.
 * ?- animal(X), comestivel(X).			X = malhada ;X = vermelho ;false.
 * ?- animal(X), anda(X).			X = malhada ;X = giserda ;false.
 * ?- animal(X), nada(X), viviparo(X).		X = pinoqio ;X = orca.
*/

/*****************************************/

/*#premissas 
 * animais -> peixe, passaro, mamifero
 * peixe -> nadadeira, nada
 * passaro -> asa, voa
 * oviparo -> passaro, peixe
 * viviparo -> mamifero
 * espada -> peixe, viviparo
 * salmão -> peixe, comestivel
 * canario -> passaro, amarelo
 * seriema -> passaro, anda
 * vaca -> mamifero, anda, comestivel, leite
 * morcego -> mamifero, voa
 * baleira -> mamifero, nada
 * 
 *#perguntas
 * voa(piupiu). 
 * cor(piupiu).
 * voa(giserda).
 * asa(giserda).
 * voa(vampe).
 * asa(vampe).
 * oviparo(vampe).
 * mamifero(X), (nada(X); voa(X)). 
 * animal(X), oviparo(X).
 * animal(X), comestivel(X).
 * animal(X), anda(X).
 * animal(X), nada(X), viviparo(X).
 * 
 *#fatos 
 * piupiu é um canario 
 * canario é um passaro 
 *  
 * nemo é um peixe 
 * 
 * pinoqio é um espada 
 * espada é um peixe
 * 
 * malhada é uma vaca
 * 
 * vampe é um morcego
 * morcego é um mamifero
 *
 * giserda é uma seriema
 * seriema é um passaro 
 * 
 * vermelho é um salmão
 * salmão é um peixe
 *
 * orca é uma baleia
 * baleia é um mamífero
*/

/*****************************************/
%#piupui
%#nemo
%#pinoqio
%#malhada
%#vampe
%#giserda
%#vermelho
%#orca

animal(piupiu).
animal(nemo).
animal(pinoqio).
animal(malhada).
animal(vampe).
animal(giserda).
animal(vermelho).
animal(orca).

voa(piupiu).
voa(vampe).
nada(nemo).
nada(pinoqio).
nada(vermelho).
nada(orca).
anda(malhada).
anda(giserda).

asa(piupiu).
asa(vampe).
asa(giserda).

oviparo(piupiu).
oviparo(nemo).
oviparo(giserda).
oviparo(vermelho).
viviparo(pinoqio).
viviparo(malhada).
viviparo(vampe).
viviparo(orca).

mamifero(malhada).
mamifero(vampe).
mamifero(orca).

comestivel(malhada).
comestivel(vermelho).

cor(piupiu) :- write(amarelo).

passaro(piupiu).
canario(piupiu).
peixe(nemo).
peixe(pinoqio).
nadadeira(nemo).
nadadeira(pinoqio).
espada(pinoqio).
vaca(malhada).

/*****************************************/

%Questao3


mae(X,Y) :- mulher(X), genitor(X,Y).
pai(X,Y) :- homem(X), genitor(X,Y).
irma(X,Y) :- mulher(X), mae(Z,X), mae(Z,Y).
irmao(X,Y) :- homem(X), mae(Z,X), mae(Z,Y).
grandfa(X,Y) :- homem(X), genitor(X,Z) , genitor(Z,Y).
grandma(X,Y) :- mulher(X), genitor(X,Z) , genitor(Z,Y).
filho(X,Y) :- homem(X), genitor(Y,X).
filha(X,Y) :- mulher(X), genitor(Y,X).

genitor(a1,a3).
genitor(a1,a5).
genitor(a1,a6).
genitor(a1,a8).
genitor(a1,a9).
genitor(a1,b2).
genitor(a1,b3).
genitor(a2,a3).
genitor(a2,a5).
genitor(a2,a6).
genitor(a2,a8).
genitor(a2,a9).
genitor(a2,b2).
genitor(a2,b3).


genitor(a3,z1).
genitor(a3,b5).
genitor(a4,z1).
genitor(a4,b5).
genitor(a6,b7).
genitor(a6,b8).
genitor(a7,b7).
genitor(a7,b8).
genitor(a9,c1).
genitor(a9,c2).
genitor(b1,c1).
genitor(b1,c2).
genitor(b3,c4).
genitor(b4,c4).

genitor(b5,c6).
genitor(b5,c7).
genitor(b5,c8).
genitor(b6,c6).
genitor(b6,c7).
genitor(b6,c8).
genitor(b8,c9).
genitor(b8,d1).
genitor(b8,d2).
genitor(b9,c9).
genitor(b9,d1).
genitor(b9,d2).
genitor(c2,d3).
genitor(c2,d4).
genitor(c2,d5).
genitor(c3,d3).
genitor(c3,d4).
genitor(c3,d5).
genitor(c4,d6).
genitor(c4,d7).
genitor(c4,d8).
genitor(c5,d6).
genitor(c5,d7).
genitor(c5,d8).

genitor(d9,e8).
genitor(e1,e8).
genitor(e2,f1).
genitor(e3,f1).
genitor(e4,f2).
genitor(e5,f2).
genitor(e6,f3).
genitor(e7,f3).

homem(a1).
homem(a3).
homem(a5).
homem(a6).
homem(a8).
homem(a9).
homem(b2).
homem(b3).

homem(z1).
homem(b5).
homem(b7).
homem(b8).
homem(c1).
homem(c2).
homem(c4).

homem(c6).
homem(c7).
homem(c8).
homem(c9).
homem(d1).
homem(d2).
homem(d3).
homem(d4).
homem(d5).
homem(d6).
homem(d7).
homem(d8).

homem(d9).
homem(e2).
homem(e4).
homem(e6).

homem(e8).
homem(f1).
homem(f2).
homem(f3).
homem(f4).

mulher(a2).
mulher(b6).
mulher(b9).
mulher(c3).
mulher(c5).
mulher(e1).
mulher(e3).
mulher(e5).
mulher(e7).
mulher(e9).

























