Communicators and Topologies

Comunicadores - definem escopo dos processos que podem se comunicar
Topologia - forma de indexar estes processos

Multiplação de matrizes de fox
Em vez de armazenar linhas ou colunas de matrizes nos processos, armazenamos
submatrizes.

Algoritmo de fox
n = ordem da matriz
p = n de processos = n^2

Mapeia aij, bij e cij para o processo i*n  + j
n estágios: um estágio pra cada aikbkj
subscritos mod n

Mas usar n^2 processos é muita coisa, imagina se n=100 por exemplo

n´= n/sqrt(p)

"Comunicadores"
Para facilitar o código, podemos fazer que um subset de processos é um comunicador

"Intra-communicator"
Comunica processos do mesmo comunicador

'Group' - coleçao ordenada de processos, cada processo tem um rank.
'Context' - objeto definido pelo sistema que unicamente identifica um comunicador

"Inter-communicator"
Comunica processos de comunicadores diferentes
Tem 'context diferentes'




