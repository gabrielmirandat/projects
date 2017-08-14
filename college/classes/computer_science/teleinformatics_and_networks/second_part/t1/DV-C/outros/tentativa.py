#!/usr/bin/python

import re
import sys

def entrada():
    "funcao para ler do parametro de entrada"
	
    try:
        with open(str(sys.argv[1]), "r") as filestream:
            for line in filestream:
                number = re.findall(r'\d+', line)
                print line
                print number
                atribui_vizinhos_matriz(line)
    except IOError:
        print 'Nao conseguiu abrir arquivo', arg


def atribui_vizinhos_matriz(line)
    "funcao para construcao inicial da matriz de adjacencia"

    global dmat
    no_atual = line[0] - 1
    
    dmat[no_atual-1][vizinho-1] = custo


if __name__ == "__main__":
	entrada()

        

        