# -*- coding: utf-8 -*-

import numpy

## Variaveis de Estado e Medida

# Distancia do obstaculo medida pelo sensor [muito perto, medio, longe]
# Independente
D = [0,1,2]

# Angulo medido do obstaculo em relacao ao robo [na esquerda, na frente, na direita]
# Independente
A = [-1,0,1]

# Motor [virar a esquerda, andar reto, virar a direita]
# Depende do Angulo
M = [-1,0,1]


## Distribuicao de Probabilidade das variaveis

# A distribuicao da Distancia eh uniforme
DD = [(1./2),(1./3),(1./3)]

# A distribuicao do Angulo eh uniforme
DA = [(1./3),(1./3),(1./3)]

# A distribuicao do Motor depende do Angulo (linha)
DM = numpy.matrix([[1., 100., 10000.],[1000., 1., 1000.],[10000., 100., 1.]])
DM = numpy.divide(DM, DM.sum())

if __name__ == "__main__":

	# entrada de dados
	d = int(raw_input('Distancia medida pelo obstaculo [0 (muito perto), 1 (medio), 2 (longe)] \n'))
	a = int(raw_input('Angulo medido do obstaculo em relacao ao robo [-1 (na esquerda), 0 (na frente), 1 (na direita)] \n'))
	m = int(raw_input('Açao do motor [-1 (virar pra esquerda), 0 (andar reto), 1 (virar pra direita)] \n'))

	# se fora de range seta a primeira possibilidade
	if d<0 or d>2: d = 0
	if a<-1 or a>1: a = -1
	if m<-1 or m>1: m = -1

	# shiftando para os valores no vetor
	a=a+1
	m=m+1

	# calculo
	P = DD[d] * DA[a] * DM[a,m]
	print P