MUMPS =  Massachusetts General Hospital Utility Multi-Programming System 
		 Sistema de multiprogramação do Hospital Geral de Massachusetts
-> LP procedural e interpretada (década de 1960) para área de saúde.
-> Aplicações multiusuário com orientação ao banco de dados.
-> Pré linguagens mais conhecidas e sintaxe incomum.
-> "build-in" de banco de dados = acesso alto-nível de armazenamento em disco.
-> Usada até hoje em sistemas de bancos de dados/sistemas clínico e financeiro, várias redes bancárias e comércio online.
-> Matrizes esparsas e o único tipo de dados são strings!
-> MUMPS deu origem ao banco de dados Caché.
-> Multitasking (multitarefa).
-> MUMPS V1 agora já foi portado até para o Raspberry Pi.
-> empresa  MEDITECH. A linguagem foi estendida melhorada, nomeando uma nova linguagem MIIS (e logo mais, uma outra chamada MAGIC).
->  A Agência Espacial Européia anunciou dia 13 de maio de 2010 que irá utilizar MUMPS para apoiar a Missão Espacial Gaia.
-> Memória reduzida a 2048 bytes. Comando QUIT (sair), podendo ser utilizado como Q, função $PIECE como $P, READ como R ou função $TRANSLATE como $TR.
-> variáveis GLOBAIS = nomes de variáveis com prefixo do caractere circunflexo ("^") são armazenados no banco de dados ao invés de ficarem na memória RAM.
   Mantendo seus valores após saídas de aplicações e sendo visível e modificável por outras aplicações em execução.
-> O modo de armazenamento do MUMPS (Globais armazenadas como arrays) dá ao banco de dados MUMPS as características de uma base de dados orientada a
   documentos.
-> variáveis LOCAIS = temporárias e privadas. Aquelas sem (^).
-> Tanto as globais como as locais podem ter nós filhas (chamados de "Subscripts" ou "índices" no MUMPS), em que não são limitadas apenas a números.
	
		Set ^Carro("Porta","Cor")="AZUL"
		S ^Carro("Porta","Motor")="2.0"		
		
-> MUMPS exige que todos os índices das variáveis sejam mantidos em ordem de classificação. Índices númericos, por exemplo, são armazenados do menor para o
   maior (mesmo utilizando números de ponto flutuante), já os índices não-numéricos são armazenados em ordem alfabética, após os números. Usando apenas 
   números inteiros não-negativos, o programador MUMPS pode emular os [[|array|arrays]] de dados de outras linguagens.
-> Os caracteres de espaço entre as declarações de MUMPS são bastante significantes.
-> As novas linhas também são bastante significantes: comandos como IF, ELSE ou FOR apenas processam comandos que estiverem até o fim da mesma linha.

'Tipos de Dados': Há apenas um tipo de dados universal, o qual funciona com uma conversão implícita para string, número inteiro e número de ponto flutuante,
realizando a conversão de acordo com o contexto do código.

'Valor Booleano': Nos comandos IF e outra sintaxe que expressa valores de condição, as strings são convertidas para valores numéricos e o único valor 
numérico que representa a condição FALSA é o zero (0), sendo que qualquer outro representa a condição VERDADEIRA.

'Declarações': Nenhuma declaração de variáveis é necessária. Todas elas são dinamicamente criadas no momento que lhe são atribuídas algum valor.

'Linhas': São entidades sintáticas importantes, diferentemente de linguagens como C ou Pascal. São permitidos múltiplos comandos em uma mesma linha e o 
escopo dos comandos IF, ELSE e FOR são limitados ao seu uso em apenas uma linha.

'Case Sensitive': Comandos e funções intrínsecas não possuem sensibilidade de letras maiúsculas ou minúsculas. Porém, os nomes de variáveis e labels a 
possuem.

'Pós-Condicionais': A execução de quase todos os comandos podem ser controlados quando seguidos do caractere "dois pontos" (":") seguido também de uma 
condição para a execução do comando. Por exemplo, no código SET:N<10 X="Foo", a variável X receberá a string "Foo" caso a condição N<10 seja verdadeira.

'Abreviação': É possível abreviar praticamente todos os comandos e funções nativas para até 3 caracteres.

'Palavras Reservadas': Não há nenhuma. O MUMPS interpreta o código fonte pelo contexto, logo não há necessidade para o uso de palavras reservadas.

'Arrays': São criadas dinamicamente, classificadas como Árvores B, podem ter qualquer número de níveis ou subscripts, sendo que os índices podem ser strings 
ou valores numéricos, números inteiros ou pontos flutuantes. Os arrays são automaticamente armazenados em ordem numérica seguida da ordem alfabética. 
A manipulação dos arrays podem ser dadas através de funções nativas como $DATA, $ORDER, $NEXT (obsoleta) e $QUERY.

'Arrays Locais': São todas as variáveis as quais o nome não começa com o caractere acento circunflexo ("^"). Elas são armazenadas na memória, são privadas a 
uma determinada aplicação e são excluídas automaticamente quando o processo da aplicação finaliza.

'Arrays Globais': São todas as variáveis as quais o nome começa com o caractere acento circunflexo ("^"). Elas são armazenadas no disco, estão disponíveis 
para todos os processos e aplicações e continuam existindo após o processo ser encerrado. Grandes globais (de até centenas de GBytes são práticas e bastante eficientes na maior parte das implementações.

'Indireção': A indireção é realizada através do caractere "arroba" ("@") posicionado no início do nome de uma variável. A indireção pode ser usada de forma 
a atribuir o conteúdo de uma variável com algum valor, de forma ao conteúdo dessa variável se tornar outra variável.

'Função 'Piece'': Esta função nativa serve para quebrar o conteúdo de uma variável em pedaços, utilizando uma string ou caractere separador específico 
(chamado também de "delimitador").

'Função 'Order'': Esta função nativa trata a entrada da estrutura, encontrando o próximo índice existente o qual possui a mesma estrutura exceto pelo último
subscript. A função retorna o próximo valor da classificação ordenada em relação ao valor de entrada.

'Multiusuário/Multiprocessamento': O MUMPS suporta processos e usuários múltiplos e simultâneos mesmo quando o sistema operacional não os suporta (como no 
caso do MS-DOS). Além disso, existe a possibilidade de especificar o ambiente para uma variável, especificando assim o nome da máquina em uma variável (como
em Set ^|"DENVER"|A(1000)="Foo"), permitindo o acesso aos dados de máquinas remotas.

