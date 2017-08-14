@'MIPS � Uniciclo
Unidade Operativa'

'Introdu��o'
-> O desempenho de uma m�quina pode ser determinado por tr�s fatores:
 - n�mero de instru��es executadas
 - per�odo do clock (ou frequ�ncia)
 - N�mero de ciclos por instru��o (CPI)

-> Para um determinado algoritmo, o compilador e a ISA (Instruction Set Architecture) determinam o n�mero de instru��es a serem executadas.
-> A implementa��o do processador determina o per�odo de clock e o CPI.

-> Este cap�tulo aborda a implementa��o de apenas um subconjunto das instru��es do MIPS
-> O interrelacionamento entre ISA e a implementa��o � exemplificado em tr�s projetos alternativos do processador
 - Processador uniciclo
 - Processador multiciclo
 - Processador pipeline
 
'Unidade Operativa'
-> Tamb�m chamada �Parte Operativa�, �Caminho de Dados� ou, em ingl�s, �Datapath�
-> � constru�da a partir dos seguintes componentes:
 - elementos de armazenamento (registradores, flip-flops)
 - operadores l�gico-aritm�ticos
 - recursos de interconex�o (barramentos, mux)
 
'Unidade Operativa MIPS'
-> Ser� projetada para implementar o seguinte subconjunto de instru��es do MIPS:
 - Instru��es de refer�ncia a mem�ria: lw e sw
 - Instru��es l�gicas e aritm�ticas: add, sub, and, or e slt
 - Instru��es de fluxo de controle: beq e j
Conjunto incompleto, mas demonstra os princ�pios b�sicos de projeto.

'Sinopse da Implementa��o'
-> Implementa��o gen�rica:
 - use o contador de programa (PC) para fornecer endere�o da instru��o
 - obtenha a instru��o da mem�ria
 - leia os registradores
 - use a instru��o para decidir exatamente o que fazer
-> Todas as instru��es usam a ALU ap�s lerem os registradores (exceto jump)
Por qu�? Refer�ncia � mem�ria? Aritm�tica? Fluxo de controle?

'Vis�o de alto n�vel da implementa��o'
-> Obs.: - Em v�rios pontos temos dados vindo de duas origens diferentes
 - As unidades precisam ser controladas.
 
'Implementa��o b�sica do subconjunto MIPS'
-> Unidades de controle
 - 1 �nico ciclo de clock
 - multiciclo
-> Elementos combinacionais e sequenciais

'Componentes Combinacionais'
-> Componentes combinacionais definem o valor de suas sa�das apenas em fun��o dos valores presentes nas suas entradas.

'Componentes Sequenciais'
-> Componentes sequenciais t�m um estado, que define seu valor em um dado instante de tempo.
 - Registrador :
  - Um conjunto de flip-flops tipo D (Registrador)
    - Com n bits de entrada e sa�da
    - entrada de habilita��o de escrita
  - Habilita��o de escrita (Write Enable - WE):
    - 0: o dado de sa�da n�o muda
    - 1: o dado de entrada ser� carregado (sa�da = entrada) na transi��o do clock
 - Mem�ria
  - Mem�ria (One/Two/Three... Ports)
    - Um barramento de entrada: Data in
    - Um barramento de sa�da: Data out
  - Uma palavra � selecionada por:
    - Um endere�o seleciona a palavra para ser colocada na sa�da (Data out)
    - Write Enable = 1: Permite que a palavra selecionada seja escrita com a informa��o na entrada (Data in)
  - Entrada de Clock (CLK)
    - Sincroniza os processos de acesso � mem�ria
    
'Estrat�gia de Temporiza��o'
-> Uma metodologia de temporiza��o define quando os sinais podem ser lidos e quando eles podem ser escritos
-> � necess�rio evitar situa��es de conflito, por exemplo, querer ler uma palavra e escrev�-la simultaneamente
-> Ser� adotada uma metodologia de temporiza��o sens�vel �s transi��es do sinal do clock
-> Nesta metodologia, qualquer valor armazenado nos elementos de estado s� pode ser atualizado durante a transi��o do sinal de rel�gio (clock)

@'ELEMENTO DE ESTADO = que participam da l�gica sequencial: registradores e mem�ria.'
-> L�gica combinacional usualmente tem entradas e sa�das conectadas a elementos de estado (sequenciais)
-> O elemento de estado 2 s� pode ser escrito depois de os dados em sua entrada estarem est�veis
 - atraso de propaga��o no elemento de estado 1
 - atraso da l�gica combinacional
 - tempo de pr�-carga (setup time) no elemento de estado 2
Sinais de escrita na subida do clock

'Criando a Unidade Operativa'
-> Uma maneira de se come�ar o projeto de uma unidade operativa (data path) � examinar cada um dos componentes necess�rios para a execu��o
de cada uma das classes de instru��es do MIPS
-> Elementos necess�rios:
 - um lugar para armazenar as instru��es (mem�ria de instru��es)
 - Um registrador para armazenar o endere�o de instru��o (Program Counter � PC)
 - Um contador para incrementar o PC, para compor o endere�o da pr�xima instru��o (soma 4 para endere�ar pr�xima instru��o)
 
'Instru��es L�gico-Aritm�ticas'
-> Formato de uma instru��o tipo R no MIPS:
  $rd ? op($rs, $rt)
Estrutura de suporte: banco de registradores

'Banco de Registradores'
-> Dupla porta: leitura de dois registradores ao mesmo tempo
-> Sinal de controle para escrita - leitura n�o necessita controle

'Projeto da ULA'
-> A ULA foi desenvolvida no cap�tulo anterior
-> 4 bits de controle indicam a opera��o a ser realizada

AND			0000
OR			0001
ADD			0010
SUBTRACT		0110
SET ON LESS THAN	0111
NOR			1100

Instru��es Tipo-I LW e SW (e desvio condicional) (Imm 16 bits)

'Mem�ria' de dados
-> Mem�ria com um barramento de entrada independente do de sa�da
-> Controle de escrita (write) e leitura (read)
-> Barramento de endere�os
-> Um acesso de cada vez

'Extens�o de Sinal do Imediato'
-> Imediato deve ser extendido de 16 para 32 bits, mantendo-se o sinal
 - se for negativo, 16 bits superiores = 1
 - se for positivo, 16 bits superiores = 0
 
'Acesso a Mem�ria de dados'
-> lw l� um dado da mem�ria e escreve em um registrador
 - conex�o entre a sa�da da mem�ria e a entrada do banco de registradores
-> sw l� um dado de um registrador e escreve na mem�ria
 - liga��o entre sa�da do banco de registradores e entrada de dados da mem�ria 
-> endere�o calculado atrav�s da ULA
 - sa�da da ULA ligada ao barramento de endere�os da mem�ria

'Unidade Operativa: Instru��es Tipo-I' - acesso mem�ria

'Instru��es de Desvio'
beq $t1, $t2, desloc
-> compara dois registradores
-> soma desloc palavras ao endere�o PC+4 se $t1 = $t2	
 - PC + 4 � o endere�o da pr�xima instru��o
-> no Assembly utiliza-se uma vers�o simplificada, com o r�tulo do destino
 - beq $t1, $t2, LABEL
 - neste caso, o montador calcula o deslocamento a ser usado
-> desloc � um deslocamento de palavras, ou seja, cada unidade de desloc corresponde a 4 bytes

'Instru��es de Desvio'
-> A compara��o entre os registradores � feita subtraindo-os na ULA e verificando se o resultado � zero
-> O PC deve ser carregado com PC + 4 ou PC + 4 + desloc*4, de acordo com o resultado do teste
-> A multiplica��o de desloc por 4 � feita deslocando-se 2 bits a esquerda o seu valor

-> Para realizar a compara��o dos dois operandos precisamos usar o 	banco de registradores
-> O c�lculo do endere�o de desvio foi inclu�do no circuito
-> Na instru��o n�o � preciso escrever no banco de registradores
-> A compara��o ser� feita pela ULA, subtraindo-se os registradores e utilizando a sa�da zero para verificar a igualdade

@'MIPS � Uniciclo
Unidade de Controle'

'MIPS Uniciclo'
-> Foram desenvolvidas, na verdade, tr�s tipos de unidades operativas:
	- uma para instru��es no formato R (add, sub, etc.)
	- uma para instru��es de acesso a mem�ria lw e sw - formato I
	- uma para instru��es condicionais (beq ) � formato I
-> Na fase de projeto as vezes precisamos replicar recursos.
-> Na via de dados mais simples deve-se propor executar as instru��es em um �nico per�odo do clock.
-> Isto quer dizer que nenhum dos recursos pode ser usado mais de uma vez por instru��o.

'Controle do MIPS'
-> Cada opera��o requer a utiliza��o adequada dos recursos do MIPS
-> Ex: add $t0, $s1, $s2
	- � necess�rio que os endere�os dos operandos $s1  e $s2 sejam enviados ao banco de registradores
	- Da mesma maneira, o endere�o do registrador destino ($t0) dever� ser informando ao banco de registradores
	- Uma vez que o banco de registradores disponibilize os valores de $s1  e $s2, estes dever�o ser encaminhados � ULA
	- Posteriormente, o resultado dever� ser escrito no banco de registradores (registrador $t0)
	
'Controle da ULA'
-> As opera��es da ULA s�o controladas por um c�digo de 4 bits:
-> As instru��es lw e sw utilizam a opera��o de soma da ULA
-> As instru��es do tipo R utilizam uma das 5 opera��es
-> A instru��o beq utiliza a subtra��o da ULA
-> Nor n�o � usada nesta implementa��o

'Identifica��o da Opera��o' @'ULA'
-> O campo funct, de 6 bits (no formato R) indica que tipo de opera��o aritm�tica/l�gica ser� executada:
-> Vamos definir 2 bits para identificar cada uma das categorias de instru��es (opALU):
	- 00 acesso � mem�ria (lw, sw) [add]
	- 01 desvio (beq, bne) [sub]
	- 10 l�gico-aritm�ticas ([add, sub, and, or, slt])
	
@'Logo, dadas as entrada funt(6 bits) + opALU(2 bits) geramos o c�digo de opera��o da ULA(4 bits)'

'Unidade de Controle Uniciclo'
-> A unidade de controle deve, a partir do c�digo da instru��o, fornecer os sinais que realizam as instru��es na unidade operativa.

'Sinais de Controle'
-> A unidade de controle de prover:
	- sinais para os multiplexadores
	- sinais de leitura e escrita para as mem�rias
	- sele��o da opera��o da ULA
	- controle do novo endere�o a ser carregado no PC, para instru��es de salto
	
'Implementa��es'
-> L�gica Combinacional Cl�ssica � Tabela verdade grande!
-> ROM (Read Only Memory) � Qual o tamanho?
-> PLA (Programable Logic Array) � Ferramenta autom�tica

'Temporiza��o'
-> Todas as tarefas executadas em 1 per�odo do clock
-> Elementos de estado alteram seu valor apenas na borda de subida do clock

'Problemas com MIPS Uniciclo'
-> Per�odo do rel�gio determinado pelo caminho mais longo
	- instru��o lw: (imagina se tivesse opera��es em Float Point!)
		- leitura da instru��o
		- leitura do registrador de base, extens�o de sinal
 		- c�lculo do endere�o
		- leitura do dado da mem�ria
		- escrita em registrador
-> TODAS as instru��es levam o mesmo tempo para executar: @'CPI=1'
E ainda!
-> Viola o princ�pio de tornar o caso comum r�pido!
-> Unidades funcionais duplicadas

'An�lise de Desempenho Uniciclo'
-> Supondo os seguintes tempos de execu��o das unidades operativas:
	- Acesso a mem�ria: 200ps
	- ULA e somadores: 100ps
	- Acesso ao banco de registradores (leitura ou escrita): 50ps
	- Multiplexadores, Unidade de Controle, acesso ao PC, Unidade de Extens�o de Sinal e fios considerados sem atraso (!!!!)
-> Qual das seguintes implementa��es seria mais r�pida e quanto?
	1) Implementa��o onde toda instru��o � feita em 1 ciclo de clock de dura��o fixa.
	2) Implementa��o onde toda instru��o � feita em 1 ciclo de clock de dura��o somente o necess�rio (!!exemplo ideal - did�tico!!)
Para compara��o consideremos um workload composto de:
25% loads, 10% stores, 45% ALU, 15% desvios condicionais, 5% jumps

#exercicio - ok

@'MIPS Multiciclo Unidade Operativa'

'MIPS Multiciclo'
-> Ideia: cada fase de execu��o de uma instru��o dura um ciclo de rel�gio
-> Instru��es podem ser executadas em um n�mero diferente de ciclos
-> Ex.:
 	- lw demora 5 ciclos
	- jump demora 3 ciclos
	- add demora 4 ciclos
-> Ciclo dimensionado de acordo com a etapa mais demorada
-> Vamos reutilizar unidades funcionais
	� ULA usada tamb�m para calcular endere�o e incrementar o PC
	� Mem�ria usada para armazenar instru��o E dados
-> A organiza��o da parte operativa pode ser re-estruturada em fun��o destas caracter�sticas
-> Sinais de controle n�o ser�o determinados diretamente pela instru��o, e sim pela instru��o+etapa
-> Usaremos uma m�quina de estado finito para controle

'Unidade Operativa Multiciclo'
-> Dividir as instru��es em etapas, cada uma durando um ciclo
 � equilibrar a quantidade de trabalho a ser feito
 � restringir cada ciclo para usar apenas uma vez cada unidade funcional
->  No final de um ciclo
 � armazenar os valores para uso em ciclos posteriores
 � Logo, necessita introduzir registradores auxiliares �internos� adicionais
 
-> Vis�o Abstrata:
	- Uma �nica ULA
	- Uma �nica Unidade de Mem�ria
	- Registradores Auxiliares ap�s unidades funcionais
		- onde coloc�-los? Unidade combinacional de 1 ciclo e onde necessitar ser salvo. No nosso caso:
Obs.:
Dados utilizados pelas etapas subsequentes armazenados em registradores (elemento de estado invis�vel ao programador)
Dados utilizados pelas instru��es subsequentes armazenados na Mem�ria, Banco de Registradores (vis�vel ao programador)

-> Detalhamento:
	- Todos os registradores auxiliares precisam manter o dado por 1 ciclo apenas (EXCE��O IR)
	Logo n�o necessitam de pino de controle de escrita
-> Incluir e expandir Multiplexadores para poder reusar Unidades Funcionais

'Controle Multiciclo'
-> Exemplo: Instru��o Tipo-R poderia ser pensada na seguinte instru��o em linguagem de descri��o de hardware (HDL) Verilog:
	Reg[Memory[PC][15:11]] <= Reg[Memory[PC][25:21]] op
	Reg[Memory[PC][20:16]] ;
-> Decomposta nas seguintes etapas usando �vari�veis locais�:
	IR <= Memory[PC];
	A <= Reg[IR[25:21]];
	B <= Reg[IR[20:16]];
	saidaALU <= A op B;
	Reg[IR[15:11]] = saidaALU;
	PC <= PC+4;

'Controle Multiciclo: 5 etapas'
Considerando:
� 1 acesso � mem�ria, 1 acesso ao banco de registradores ou 1 opera��o da ULA por ciclo. (determina o ciclo de clock)
� Projeto acionado por transi��o (valores dos regs n�o muda at� ent�o)
	1. Etapa de Busca da Instru��o
		IR <= Memoria[PC];
		PC <= PC + 4;
		Execu��o: Ler a Instru��o da mem�ria e incrementar PC
			� Ativar os sinais de controle LeMem e Escreve IR
			� Definir PC como origem do endere�o: Colocar IouD em 0
			� Incrementar PC+4: OrigAALU em 0 (PC para ALU), OrigBALU 01 (4 para ALU) e opALU 00 (soma).
			� Armazenar o endere�o de instru��o incrementado em PC: origPC 00 e ativar EscrevePC	
	2. Etapa de Decodifica��o da Instru��o e busca de operandos
		A <= Reg[IR[25:21]];
		B <= Reg[IR[20:16]];
		SaidaALU <= PC + (extens�o-sinal(IR[15:0]) << 2);
		Execu��o: Como n�o sabemos qual a instru��o ainda, podemos fazer a��es gerais que n�o causem problemas depois!
			� Acessar o banco de registradores e ler rs e rt e armazenar em A e B.
			� C�lculo pr�vio do endere�o de desvio e coloca em SaidaALU: OrigAALU em 0 ( PC para ALU), OrigBALU em 11 
			  (offset extendido em ALU) e opALU 00 (soma).
	3. Etapa de Execu��o, c�lculo do endere�o de mem�ria ou conclus�o de desvio
		-> Refer�ncia � mem�ria (lw,sw):
		 - SaidaULA = A + extens�o-sinal(IR[15-0])
		 Execu��o: Calcular o endere�o
			� OrigAALU em 1 (A na ALU), OrigBALU em 10 (sa�da ext-sinal na ALU), opALU 00 (soma)

		-> Instru��o Tipo-R:
		 - SaidaULA <= A op B
		 Execu��o: os valores de A e B est�o prontos!
			� OrigAALU em 1 (A na ALU), OrigBALU em 00 (B na ALU), opALU 10 (l�gico-aritm�tica pelo campo funct)

		-> beq:
		 - if (A==B) PC <= SaidaALU
		 Execu��o: o endere�o de desvio j� est� pronto.
			� OrigAALU em 1 (A na ALU), OrigBALU em 00 (B na ALU), opALU 01 (subtrai)
			� Ativar sinal EscrevePCCond
			� Colocar OrigPCem 01 (valor do PC vem da ULA)
			
		-> Jump:
		- PC <= {PC[31:28],(IR[25:0]],2�b00)}
		Execu��o: PC � substitu�do pelo endere�o de Jump
			� Colocar OriPC em 10
			� Ativar EscrevePC
			
	4. Etapa de acesso � mem�ria ou conclus�o de instruc�o Tipo-R
	    -> Refer�ncia � mem�ria (lw, sw):
		 - MDR <= Memoria[SaidaALU]; #para load
		 ou
		 - Mem�ria[saidaALU] <= B # para store
		 Execu��o: Em qualquer dos casos o endere�o j� est� na SaidaALU
			� IouD colocado em 1 (Endere�o da ALU)
			� LeMem ou EscreveMem deve ser ativado
		
		-> Instru��o Tipo-R:
		 - Reg[IR[15:11]] <= SaidaALU
		 Execu��o: Colocar o resultado no reg destino
			� Colocar RegDST em 1 (usar rd como destino)
			� Ativar EscreveReg
			� Colocar MemparaReg em 0 (sa�da da ALU na entrada do banco de reg)
			
	5. Conclus�o da Leitura da Mem�ria (lw)
		-> Reg[IR[20:16]] <= MDR;
		Execu��o: Escrever o dado do MDR no banco de reg
			� Colocar MemparaReg em 1 (resultado da mem�ria)
			� Ativar o EscreveReg
			� Colocar RegDst em 0 (campo rt � o reg destino)
			
@'Mips Multiciclo: Unidade de Controle'

'MIPS Multiciclo Unidade de Controle'
->: Controle feito em uma s�rie de etapas
-> T�cnicas de Implementa��o:
	- M�quinas de Estado Finito
	- Microprograma��o

Representa��o Inicial							Diagrama de estados finitos 		Microprograma
Controle de Sequencia��o						Fun��o de pr�ximo estado expl�cita	Contador de programa + ROM
Representa��o L�gica 							Equa��es L�gicas 					Tabelas Verdade
T�cnica de Implementa��o						PLA									ROM

'Controle com MEF'
'Implementa��o com ROM'
	- Simples!
-> Tamanho da mem�ria
	- 10 bits endere�o: 1024 posi��es de mem�ria
	- 20 bits de dados
Logo ROM de 20kbits
Quantas posi��es de mem�ria s�o realmente utilizadas?
-> Por�m, ineficiente

'Implementa��o com PLA (Programable Gate Array)'
-> Mais eficiente:
	- Pode compartilhar termos de produtos
	- Apenas entradas que possuem sa�das ativas
	- Pode considerar don�t cares

Tamanho: (EntradasxN.Prod.)+(Saidas xN.Prod)
Tamanho: (10x17)+(20x17)=510 c�lulas

'Microprograma��o'
'Problemas da MEF:'
-> O projeto da parte de controle atrav�s de diagramas de transi��o de estados pode rapidamente se tornar invi�vel se o n�mero de estados for muito grande
-> MEF's de processadores complexos podem ter milhares de estados
Uma alternativa para projeto � seguir um processo semelhante a programa��o

-> Uma microinstru��o � definida pelos valores dos sinais de controle que atuam na unidade operativa durante um estado da MEF (ESTADO)
-> A execu��o de uma instru��o do processador pode ent�o ser realizada atrav�s de uma sequ�ncia de microinstru��es (TRANSI��ES)
-> O conjunto de microinstru��es que implementa o controle de um processador � chamado de microprograma (DIAGRAMA DE ESTADOS)

-> O sequenciamento das microinstru��es � realizado de forma similar a de um programa normal
	- microinstru��es s�o usualmente executadas em sequ�ncia -> correspondem aos caminhos no diagrama de estados.
	- em alguns casos, a sequ�ncia a ser seguida depende de informa��es externas (c�digo da instru��o, por exemplo). 
	Nestes casos, s�o necess�rios mecanismos de desvio.
	
'Formato da Microinstru��o'
-> A microinstru��o � dividida em campos que atuam sobre conjuntos de elementos da unidade operativa
->  Os campos s�o escolhidos de acordo com sua finalidade. O controle da ULA, por exemplo, � associado a um campo 
-> O microprograma � usualmente implementado em ROM ou PLA, onde cada microinstru��o tem seu pr�prio endere�o

@'MIPS Pipeline - Conceitos'

'Objetivo'
-> Apresentar t�cnicas para aumento de desempenho de uma �nica tarefa em �nico processador usando ILP (Instruction Level Parallelism):
	- Pipelining : T�cnica de projeto onde o hardware processa mais de uma instru��o de cada vez, sem esperar que uma instru��o termine antes de
				   come�ar a pr�xima.
	- Superpipeline : T�cnicas para aumento da efici�ncia do pipeline.
	- Superescalar: Uso eficiente de m�ltiplas unidades funcionais.
-> Outros n�veis de paralelismo: Aumenta a efici�ncia em m�quinas multi task.
	- Multithread : V�rias tarefas independentes simultaneamente, aproveitando-se das �falhas� do pipeline e/ou de estrutura superescalar.
	- Multicore: V�rios n�cleos em 1 chip, compartilhando mem�rias caches.
	- Multiprocessor: Sistema multiprocessado/distribu�do. Diferentes computadores.
	
'Pipelining: Conceito B�sico'
-> uma pessoa leva 5 unidades de tempo para montar uma bicicleta

'Linha de Montagem (pipeline)'
-> uma pessoa diferente para cada tarefa

'An�lise'
-> Lat�ncia:
	- tempo que uma instru��o leva para ser executada
	- MIPS: 5 ciclos
->  Vaz�o:
	- n�mero de instru��es por unidade de tempo
	- 1 instru��o/ciclo
-> Qual a acelera��o ideal?
	- Para est�gios balanceados, condi��es ideais e grande n�mero de instru��es:
						tempo_entre_instru��es_com_pipe =  tempo_entre_instru��es_sem_pipe/numero)est�gios_pipe
						
-> O pipeline s� come�a a produzir nessa taxa uma vez que linha esteja cheia
-> Primeira bicicleta produzida em 5 UT
-> Ap�s a primeira, o pipe produz uma bicicleta por UT
-> Balanceamento
	- Suponha que a opera��o Montagem da Roda Trazeira requeira duas unidades de tempo
		- Uma unidade para montar a correia
		- Uma unidade para montar a roda
	- O que ocorre com a lat�ncia do pipeline ?
	- O que ocorre com a vaz�o ?
	- Como otimizar o pipeline neste caso ?

'Pipeline'
-> O que facilita o pipeline:
	- Todas instru��es t�m o mesmo comprimento.
		- Obs.: IA-32 instru��es de 1 a 17 bytes
	- Poucos formatos de instru��es.
		- Obs: Tipo-R, I , J operandos �quase� nas mesmas posi��es
	- Operandos em mem�ria s� aparecem em loads e stores.
		- Obs.: Pode-se usar a ULA para c�lculo de endere�o.
	O mesmo n�o vale para busca de operandos da ULA da mem�ria (IA-32)

-> O que complica (hazards):
	- Riscos Estruturais	
	- Riscos de Controle
	- Riscos de Dados
	
'Hazard Estruturais'
-> Hardware pode n�o admitir a combina��o de instru��es e um mesmo ciclo de clock.
	- uma pessoa apenas para montar as bicicletas
	- Considerando apenas 1 mem�ria para dados e instru��es, como ficaria uma quarta instru��o no exemplo dado?

'Hazard de Dados'
-> Pipeline precisa ser interrompido por que uma etapa precisa esperar at� que outra seja conclu�da (depend�ncia de dados).
	- Exemplo:
		- add $s0,$t0,$t1
		- sub $t2,$s0,$t3
-> Solu��es:
	-  Inser��o de Bolhas
	-  Execu��o fora de ordem (compilador e processador)
	-  Forwarding ou bypassing
	
	'Execu��o Fora de Ordem'
	-> Aproveitar os espa�os das bolhas para tarefas �teis que sejam independentes.
	-> Alterar o algoritmo sem alterar o resultado!

	'Forwarding'
	-> Observa��o: n�o � necess�rio esperar que a instru��o termine antes de tentar resolver o hazard de dados.
	
'Hazard de Controle'
'Hazard de Controle'
-> Necessidade de tomar uma decis�o com base nos resultados de uma instru��o enquanto outras est�o sendo executadas
BEQ � avaliado pela ULA no 3� est�gio => Necessita 2 bolhas!!!
-> Alterando o caminho de dados para que o BEQ seja avaliado no 2� Est�gio => Economiza 1 Bolha!!
-> Delayed Branch: ocupar a bolha com uma instru��o �til, equivalente a atrasar a execu��o do Branch
 No exemplo: add $4,$5,$6 no lugar da bolha
 
 -> Prevendo estaticamente o desvio como n�o tomado
	- Formas Din�micas de Previs�o:
		�Endere�o � anterior? Prev� tomar o desvio
		�Armazenamento do hist�rico

'Acelerando m�quinas com pipeline'
-> A velocidade m�xima de uma m�quina com pipeline � de uma instru��o por ciclo de clock. Correto?
-> T�cnicas para iniciar m�ltiplas instru��es em 1 ciclo de clock:
	o Estruturas superpipeline
	o Estruturas superescalares.
	
'Acelerando m�quinas: Superpipeline'
-> A estrutura Superpipeline subdivide cada est�gio do pipeline em subest�gios, e multiplica internamente a frequ�ncia de clock.
-> Cada (sub)est�gio continua executando uma instru��o por clock. Mas como o clock interno � multiplicado, o pipeline pode aceitar duas ou mais instru��es 
para cada clock externo.

'Acelerando m�quinas: Superescalar'
	-> A estrutura superescalar cont�m m�ltiplas unidades funcionais que s�o capazes de fazer a mesma tarefa.
	-> Isto permite ao processador executar v�rias instru��es similares concorrentemente, pelo roteamento das instru��es �s unidades de execu��o dispon�veis.
	
@'MIPS Pipeline � Unidade Operativa e Controle'

'Controle do pipeline'
-> Temos 5 est�gios. O que deve ser controlado em cada est�gio?
	IF: Instruction Fetch e PC Increment
	ID: Instruction Decode / Register Fetch
	EX: Execution
	MEM: Memory Stage
	WB: Write Back
	
-> Busca da instru��o:
	- Nenhum sinal de controle
->  Decodifica��o da instru��o / leitura do banco de regs.:
	- Nenhum sinal de controle
->  Execu��o / c�lculo de endere�o:
	- RegDest, OpALU, OrigALU
->  Acesso a mem�ria:
	- Branch, LeMem, EscreveMem
->  Escrita do resultado
	- MemparaReg, EscreveReg

	
