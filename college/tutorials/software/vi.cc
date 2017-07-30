MODO EDIÇÃO - vi arquivo.x

i : insere texto a partir do cursor atual
a : insere texto depois do cursor atual
I : insere texto no início da linha
A : insere texto no final da linha
s : substitui texto no cursor atual
S : substitui texto depois do cursor atual
o : abre uma linha abaixo do cursor atual

MODO DE COMANDO - após apertar <ESC>

/Expressão : Procura Expressão (que pode ser qualquer palavra) no texto
n : Procura próxima ocorrência de Expressão no texto
N : Procura ocorrência anterior de Expressão no texto
yy : Copia linha atual do texto para memória
p : Cola conteúdo da memória no texto
dd : Apaga linha atual (e coloca na memória)
n comando : Um número n (1, 2, ...) seguido de qualquer comando executa o comando n vezes
u : Desfaz última ação executada
. : Refaz última ação executada
:n : Pula para linha de número n
:w : Salva o arquivo atual
:wq : Salva o arquivo atual e sai do Vi
:x : Salva o arquivo atual e sai do Vi (equivalente) a :wq
:q : Sai do Vi
:q! : Sai do Vi , independe de salvar o conteúdo atual
:w arquivo : Salva o arquivo atual com o nome arquivo
