Kurose cap 4
Medhi cap 2

Implementar algoritmos e protocolos de roteamento
linguagem: C/C++ ou Python
entrada: topologia
		 Grafo - G(V,E) = (nós,arestas)
		 Aresta - (u,v) = p, p>0, peso da aresta que conecta u a v
		 CADA NÓ RECEBE VIZINHOS CONECTADOS COM CUSTO
		 1; 2[4]; 3[1];
		 2; 1[4]; 3[2];
		 3; 1[1]; 2[3]

saida: lista de destinos e custos para cada no
	   mostrar convergência, programa deve ser distribuído
	   mostrar opção de troca de informações num nó

	   3 topologias de exemplo

	   Informar fontes e custos

OK
Ler Kurose
Ler Medhi
Entender codigo C - http://hubpages.com/art/Distance-Vector-Algorithm-in-C
Adaptar com threads e socket

	1-  2-  3-  4-  5-  6-
1-	0 	7 	4   2   999 999
2-	7 	0 	1   999 5   999
3-	4 	1 	0   1   4   1
4-	2 	999 1   0   999 3
5-	999 5 	4   999 0   2
6-	999 999 1   3   2   0

nodo; vizinho1[custo]; vizinho2[custo]; · · · , vizinhoN [custo]
1;2[4];3[1];
2;1[4];3[2];
3;1[1];2[3]

1;2[7];3[4];4[2];
2;1[7];3[1];5[5];
3;1[4];2[1];4[1];5[4];6[1];
4;1[2];3[1];6[3];
5;2[5];3[4];6[2];
6;3[1];4[3];5[2];

 


