import matplotlib.pyplot as plt
import numpy as np
from decimal import *
from collections import defaultdict

# num_a_f = 10
# num_g = 4
# num_n = 13
num_a_f = 5
num_g = 4
num_n = 13

# a_g = np.zeros((num_g,num_a_f),dtype=object)
# c_n = np.zeros((num_n,num_a_f),dtype=object)
# d_n = np.zeros((num_n,num_a_f),dtype=object)

a_g = defaultdict(lambda  : defaultdict(list))
c_n = defaultdict(lambda  : defaultdict(list))
d_n = defaultdict(lambda  : defaultdict(list))

a_x = [50,100,200,400,800,1000,2000,4000,8000,16000,32000,64000,128000]
c_d_x = 0

# 10 casos a-f
arq_a_f = [None] * num_a_f
arq_a_f[0] = "graph/a1b2c0d0e1f0.txt"
arq_a_f[1] = "graph/a2b2c0d0e1f0.txt"
arq_a_f[2] = "graph/a4b2c0d0e1f0.txt"
arq_a_f[3] = "graph/a8b2c0d0e1f0.txt"
arq_a_f[4] = "graph/a16b4c0d0e1f0.txt"
# arq_a_f[5] = "graph/a2b1c1d0e1f0.txt"
# arq_a_f[6] = "graph/a1b1c1d0e1f0.txt"
# arq_a_f[7] = "graph/a1b1c1d1e1f2.txt"
# arq_a_f[8] = "graph/a1b4c0d1e2f0.txt"
# arq_a_f[9] = "graph/a8b4c0d8e2f0.txt"

# obtem todas as linhas dos arquivos arq_a_f
# 4 g's para 13 n's linhas por caso a-f
conteudo_arq_a_f = [None] * num_a_f
for id_arq in xrange(num_a_f):
    with open(arq_a_f[id_arq]) as f:
        conteudo_arq_a_f[id_arq] = [x.strip() for x in f.readlines()]

for id_arq in xrange(num_a_f):
    for id_linha in xrange(num_g*num_n):
        linha = [Decimal(i) for i in conteudo_arq_a_f[id_arq][id_linha].split()]
        altura_arvore, g, n, tempo_total_gasto = linha[:4]
        a_g[g][id_arq].append(tempo_total_gasto)
        if g == 2:
            c_n[a_x.index(n)][id_arq] = linha[4:]
        elif g == 1:
            d_n[a_x.index(n)][id_arq] = linha[4:]

# plota os graficos
# grafico a
for id_grafico in xrange(num_g):
    id_grafico_str = str(id_grafico)
    fig = plt.figure()

    for id_linha in xrange(num_a_f):
        id_linha_str = str(id_linha+1)
        y = a_g[id_grafico][id_linha]
        plt.plot(a_x, y, label = "af" + id_linha_str)

    plt.xlabel("n")
    plt.ylabel("tempo total")
    plt.title("Parte a - g" + id_grafico_str)
    plt.legend()
    fig_str = "graph/parte_a_g_" + id_grafico_str + ".png"
    fig.savefig(fig_str)
    plt.close(fig)
    print "#salvando " + fig_str

# grafico c
for id_grafico in xrange(num_n):
    id_grafico_str = str(a_x[id_grafico])

    fig = plt.figure()

    for id_linha in xrange(num_a_f):
        id_linha_str = str(id_linha+1)
        y = c_n[id_grafico][id_linha]
        plt.plot([x+1 for x in range(len(y))], y, label = "af" + id_linha_str)

    plt.xlabel("nivel")
    plt.ylabel("tempo no nivel")
    plt.title("Parte c - n" + id_grafico_str)
    plt.legend()
    fig_str = "graph/parte_c_n_" + id_grafico_str + ".png"
    fig.savefig(fig_str)
    plt.close(fig)
    print "#salvando " + fig_str

# grafico d
for id_grafico in xrange(num_n):
    id_grafico_str = str(a_x[id_grafico])

    fig = plt.figure()

    for id_linha in xrange(num_a_f):
        id_linha_str = str(id_linha+1)
        y = d_n[id_grafico][id_linha]
        plt.plot([x+1 for x in range(len(y))], y, label = "af" + id_linha_str)

    plt.xlabel("linha")
    plt.ylabel("chamadas na linha")
    plt.title("Parte d - n" + id_grafico_str)
    plt.legend()
    fig_str = "graph/parte_d_n_" + id_grafico_str + ".png"
    fig.savefig(fig_str)
    plt.close(fig)
    print "#salvando " + fig_str
