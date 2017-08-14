@'MIPS – Uniciclo
Unidade Operativa'

'Introdução'
-> O desempenho de uma máquina pode ser determinado por três fatores:
 - número de instruções executadas
 - período do clock (ou frequência)
 - Número de ciclos por instrução (CPI)

-> Para um determinado algoritmo, o compilador e a ISA (Instruction Set Architecture) determinam o número de instruções a serem executadas.
-> A implementação do processador determina o período de clock e o CPI.

-> Este capítulo aborda a implementação de apenas um subconjunto das instruções do MIPS
-> O interrelacionamento entre ISA e a implementação é exemplificado em três projetos alternativos do processador
 - Processador uniciclo
 - Processador multiciclo
 - Processador pipeline
 
'Unidade Operativa'
-> Também chamada “Parte Operativa”, “Caminho de Dados” ou, em inglês, “Datapath”
-> É construída a partir dos seguintes componentes:
 - elementos de armazenamento (registradores, flip-flops)
 - operadores lógico-aritméticos
 - recursos de interconexão (barramentos, mux)
 
'Unidade Operativa MIPS'
-> Será projetada para implementar o seguinte subconjunto de instruções do MIPS:
 - Instruções de referência a memória: lw e sw
 - Instruções lógicas e aritméticas: add, sub, and, or e slt
 - Instruções de fluxo de controle: beq e j
Conjunto incompleto, mas demonstra os princípios básicos de projeto.

'Sinopse da Implementação'
-> Implementação genérica:
 - use o contador de programa (PC) para fornecer endereço da instrução
 - obtenha a instrução da memória
 - leia os registradores
 - use a instrução para decidir exatamente o que fazer
-> Todas as instruções usam a ALU após lerem os registradores (exceto jump)
Por quê? Referência à memória? Aritmética? Fluxo de controle?

'Visão de alto nível da implementação'
-> Obs.: - Em vários pontos temos dados vindo de duas origens diferentes
 - As unidades precisam ser controladas.
 
'Implementação básica do subconjunto MIPS'
-> Unidades de controle
 - 1 único ciclo de clock
 - multiciclo
-> Elementos combinacionais e sequenciais

'Componentes Combinacionais'
-> Componentes combinacionais definem o valor de suas saídas apenas em função dos valores presentes nas suas entradas.

'Componentes Sequenciais'
-> Componentes sequenciais têm um estado, que define seu valor em um dado instante de tempo.
 - Registrador :
  - Um conjunto de flip-flops tipo D (Registrador)
    - Com n bits de entrada e saída
    - entrada de habilitação de escrita
  - Habilitação de escrita (Write Enable - WE):
    - 0: o dado de saída não muda
    - 1: o dado de entrada será carregado (saída = entrada) na transição do clock
 - Memória
  - Memória (One/Two/Three... Ports)
    - Um barramento de entrada: Data in
    - Um barramento de saída: Data out
  - Uma palavra é selecionada por:
    - Um endereço seleciona a palavra para ser colocada na saída (Data out)
    - Write Enable = 1: Permite que a palavra selecionada seja escrita com a informação na entrada (Data in)
  - Entrada de Clock (CLK)
    - Sincroniza os processos de acesso à memória
    
'Estratégia de Temporização'
-> Uma metodologia de temporização define quando os sinais podem ser lidos e quando eles podem ser escritos
-> É necessário evitar situações de conflito, por exemplo, querer ler uma palavra e escrevê-la simultaneamente
-> Será adotada uma metodologia de temporização sensível às transições do sinal do clock
-> Nesta metodologia, qualquer valor armazenado nos elementos de estado só pode ser atualizado durante a transição do sinal de relógio (clock)

@'ELEMENTO DE ESTADO = que participam da lógica sequencial: registradores e memória.'
-> Lógica combinacional usualmente tem entradas e saídas conectadas a elementos de estado (sequenciais)
-> O elemento de estado 2 só pode ser escrito depois de os dados em sua entrada estarem estáveis
 - atraso de propagação no elemento de estado 1
 - atraso da lógica combinacional
 - tempo de pré-carga (setup time) no elemento de estado 2
Sinais de escrita na subida do clock

'Criando a Unidade Operativa'
-> Uma maneira de se começar o projeto de uma unidade operativa (data path) é examinar cada um dos componentes necessários para a execução
de cada uma das classes de instruções do MIPS
-> Elementos necessários:
 - um lugar para armazenar as instruções (memória de instruções)
 - Um registrador para armazenar o endereço de instrução (Program Counter – PC)
 - Um contador para incrementar o PC, para compor o endereço da próxima instrução (soma 4 para endereçar próxima instrução)
 
'Instruções Lógico-Aritméticas'
-> Formato de uma instrução tipo R no MIPS:
  $rd ? op($rs, $rt)
Estrutura de suporte: banco de registradores

'Banco de Registradores'
-> Dupla porta: leitura de dois registradores ao mesmo tempo
-> Sinal de controle para escrita - leitura não necessita controle

'Projeto da ULA'
-> A ULA foi desenvolvida no capítulo anterior
-> 4 bits de controle indicam a operação a ser realizada

AND			0000
OR			0001
ADD			0010
SUBTRACT		0110
SET ON LESS THAN	0111
NOR			1100

Instruções Tipo-I LW e SW (e desvio condicional) (Imm 16 bits)

'Memória' de dados
-> Memória com um barramento de entrada independente do de saída
-> Controle de escrita (write) e leitura (read)
-> Barramento de endereços
-> Um acesso de cada vez

'Extensão de Sinal do Imediato'
-> Imediato deve ser extendido de 16 para 32 bits, mantendo-se o sinal
 - se for negativo, 16 bits superiores = 1
 - se for positivo, 16 bits superiores = 0
 
'Acesso a Memória de dados'
-> lw lê um dado da memória e escreve em um registrador
 - conexão entre a saída da memória e a entrada do banco de registradores
-> sw lê um dado de um registrador e escreve na memória
 - ligação entre saída do banco de registradores e entrada de dados da memória 
-> endereço calculado através da ULA
 - saída da ULA ligada ao barramento de endereços da memória

'Unidade Operativa: Instruções Tipo-I' - acesso memória

'Instruções de Desvio'
beq $t1, $t2, desloc
-> compara dois registradores
-> soma desloc palavras ao endereço PC+4 se $t1 = $t2	
 - PC + 4 é o endereço da próxima instrução
-> no Assembly utiliza-se uma versão simplificada, com o rótulo do destino
 - beq $t1, $t2, LABEL
 - neste caso, o montador calcula o deslocamento a ser usado
-> desloc é um deslocamento de palavras, ou seja, cada unidade de desloc corresponde a 4 bytes

'Instruções de Desvio'
-> A comparação entre os registradores é feita subtraindo-os na ULA e verificando se o resultado é zero
-> O PC deve ser carregado com PC + 4 ou PC + 4 + desloc*4, de acordo com o resultado do teste
-> A multiplicação de desloc por 4 é feita deslocando-se 2 bits a esquerda o seu valor

-> Para realizar a comparação dos dois operandos precisamos usar o 	banco de registradores
-> O cálculo do endereço de desvio foi incluído no circuito
-> Na instrução não é preciso escrever no banco de registradores
-> A comparação será feita pela ULA, subtraindo-se os registradores e utilizando a saída zero para verificar a igualdade

@'MIPS – Uniciclo
Unidade de Controle'

'MIPS Uniciclo'
-> Foram desenvolvidas, na verdade, três tipos de unidades operativas:
	- uma para instruções no formato R (add, sub, etc.)
	- uma para instruções de acesso a memória lw e sw - formato I
	- uma para instruções condicionais (beq ) – formato I
-> Na fase de projeto as vezes precisamos replicar recursos.
-> Na via de dados mais simples deve-se propor executar as instruções em um único período do clock.
-> Isto quer dizer que nenhum dos recursos pode ser usado mais de uma vez por instrução.

'Controle do MIPS'
-> Cada operação requer a utilização adequada dos recursos do MIPS
-> Ex: add $t0, $s1, $s2
	- é necessário que os endereços dos operandos $s1  e $s2 sejam enviados ao banco de registradores
	- Da mesma maneira, o endereço do registrador destino ($t0) deverá ser informando ao banco de registradores
	- Uma vez que o banco de registradores disponibilize os valores de $s1  e $s2, estes deverão ser encaminhados à ULA
	- Posteriormente, o resultado deverá ser escrito no banco de registradores (registrador $t0)
	
'Controle da ULA'
-> As operações da ULA são controladas por um código de 4 bits:
-> As instruções lw e sw utilizam a operação de soma da ULA
-> As instruções do tipo R utilizam uma das 5 operações
-> A instrução beq utiliza a subtração da ULA
-> Nor não é usada nesta implementação

'Identificação da Operação' @'ULA'
-> O campo funct, de 6 bits (no formato R) indica que tipo de operação aritmética/lógica será executada:
-> Vamos definir 2 bits para identificar cada uma das categorias de instruções (opALU):
	- 00 acesso à memória (lw, sw) [add]
	- 01 desvio (beq, bne) [sub]
	- 10 lógico-aritméticas ([add, sub, and, or, slt])
	
@'Logo, dadas as entrada funt(6 bits) + opALU(2 bits) geramos o código de operação da ULA(4 bits)'

'Unidade de Controle Uniciclo'
-> A unidade de controle deve, a partir do código da instrução, fornecer os sinais que realizam as instruções na unidade operativa.

'Sinais de Controle'
-> A unidade de controle de prover:
	- sinais para os multiplexadores
	- sinais de leitura e escrita para as memórias
	- seleção da operação da ULA
	- controle do novo endereço a ser carregado no PC, para instruções de salto
	
'Implementações'
-> Lógica Combinacional Clássica – Tabela verdade grande!
-> ROM (Read Only Memory) – Qual o tamanho?
-> PLA (Programable Logic Array) – Ferramenta automática

'Temporização'
-> Todas as tarefas executadas em 1 período do clock
-> Elementos de estado alteram seu valor apenas na borda de subida do clock

'Problemas com MIPS Uniciclo'
-> Período do relógio determinado pelo caminho mais longo
	- instrução lw: (imagina se tivesse operações em Float Point!)
		- leitura da instrução
		- leitura do registrador de base, extensão de sinal
 		- cálculo do endereço
		- leitura do dado da memória
		- escrita em registrador
-> TODAS as instruções levam o mesmo tempo para executar: @'CPI=1'
E ainda!
-> Viola o princípio de tornar o caso comum rápido!
-> Unidades funcionais duplicadas

'Análise de Desempenho Uniciclo'
-> Supondo os seguintes tempos de execução das unidades operativas:
	- Acesso a memória: 200ps
	- ULA e somadores: 100ps
	- Acesso ao banco de registradores (leitura ou escrita): 50ps
	- Multiplexadores, Unidade de Controle, acesso ao PC, Unidade de Extensão de Sinal e fios considerados sem atraso (!!!!)
-> Qual das seguintes implementações seria mais rápida e quanto?
	1) Implementação onde toda instrução é feita em 1 ciclo de clock de duração fixa.
	2) Implementação onde toda instrução é feita em 1 ciclo de clock de duração somente o necessário (!!exemplo ideal - didático!!)
Para comparação consideremos um workload composto de:
25% loads, 10% stores, 45% ALU, 15% desvios condicionais, 5% jumps

#exercicio - ok

@'MIPS Multiciclo Unidade Operativa'

'MIPS Multiciclo'
-> Ideia: cada fase de execução de uma instrução dura um ciclo de relógio
-> Instruções podem ser executadas em um número diferente de ciclos
-> Ex.:
 	- lw demora 5 ciclos
	- jump demora 3 ciclos
	- add demora 4 ciclos
-> Ciclo dimensionado de acordo com a etapa mais demorada
-> Vamos reutilizar unidades funcionais
	– ULA usada também para calcular endereço e incrementar o PC
	– Memória usada para armazenar instrução E dados
-> A organização da parte operativa pode ser re-estruturada em função destas características
-> Sinais de controle não serão determinados diretamente pela instrução, e sim pela instrução+etapa
-> Usaremos uma máquina de estado finito para controle

'Unidade Operativa Multiciclo'
-> Dividir as instruções em etapas, cada uma durando um ciclo
 – equilibrar a quantidade de trabalho a ser feito
 – restringir cada ciclo para usar apenas uma vez cada unidade funcional
->  No final de um ciclo
 – armazenar os valores para uso em ciclos posteriores
 – Logo, necessita introduzir registradores auxiliares “internos” adicionais
 
-> Visão Abstrata:
	- Uma única ULA
	- Uma única Unidade de Memória
	- Registradores Auxiliares após unidades funcionais
		- onde colocá-los? Unidade combinacional de 1 ciclo e onde necessitar ser salvo. No nosso caso:
Obs.:
Dados utilizados pelas etapas subsequentes armazenados em registradores (elemento de estado invisível ao programador)
Dados utilizados pelas instruções subsequentes armazenados na Memória, Banco de Registradores (visível ao programador)

-> Detalhamento:
	- Todos os registradores auxiliares precisam manter o dado por 1 ciclo apenas (EXCEÇÃO IR)
	Logo não necessitam de pino de controle de escrita
-> Incluir e expandir Multiplexadores para poder reusar Unidades Funcionais

'Controle Multiciclo'
-> Exemplo: Instrução Tipo-R poderia ser pensada na seguinte instrução em linguagem de descrição de hardware (HDL) Verilog:
	Reg[Memory[PC][15:11]] <= Reg[Memory[PC][25:21]] op
	Reg[Memory[PC][20:16]] ;
-> Decomposta nas seguintes etapas usando “variáveis locais”:
	IR <= Memory[PC];
	A <= Reg[IR[25:21]];
	B <= Reg[IR[20:16]];
	saidaALU <= A op B;
	Reg[IR[15:11]] = saidaALU;
	PC <= PC+4;

'Controle Multiciclo: 5 etapas'
Considerando:
• 1 acesso à memória, 1 acesso ao banco de registradores ou 1 operação da ULA por ciclo. (determina o ciclo de clock)
• Projeto acionado por transição (valores dos regs não muda até então)
	1. Etapa de Busca da Instrução
		IR <= Memoria[PC];
		PC <= PC + 4;
		Execução: Ler a Instrução da memória e incrementar PC
			Ø Ativar os sinais de controle LeMem e Escreve IR
			Ø Definir PC como origem do endereço: Colocar IouD em 0
			Ø Incrementar PC+4: OrigAALU em 0 (PC para ALU), OrigBALU 01 (4 para ALU) e opALU 00 (soma).
			Ø Armazenar o endereço de instrução incrementado em PC: origPC 00 e ativar EscrevePC	
	2. Etapa de Decodificação da Instrução e busca de operandos
		A <= Reg[IR[25:21]];
		B <= Reg[IR[20:16]];
		SaidaALU <= PC + (extensão-sinal(IR[15:0]) << 2);
		Execução: Como não sabemos qual a instrução ainda, podemos fazer ações gerais que não causem problemas depois!
			Ø Acessar o banco de registradores e ler rs e rt e armazenar em A e B.
			Ø Cálculo prévio do endereço de desvio e coloca em SaidaALU: OrigAALU em 0 ( PC para ALU), OrigBALU em 11 
			  (offset extendido em ALU) e opALU 00 (soma).
	3. Etapa de Execução, cálculo do endereço de memória ou conclusão de desvio
		-> Referência à memória (lw,sw):
		 - SaidaULA = A + extensão-sinal(IR[15-0])
		 Execução: Calcular o endereço
			Ø OrigAALU em 1 (A na ALU), OrigBALU em 10 (saída ext-sinal na ALU), opALU 00 (soma)

		-> Instrução Tipo-R:
		 - SaidaULA <= A op B
		 Execução: os valores de A e B estão prontos!
			Ø OrigAALU em 1 (A na ALU), OrigBALU em 00 (B na ALU), opALU 10 (lógico-aritmética pelo campo funct)

		-> beq:
		 - if (A==B) PC <= SaidaALU
		 Execução: o endereço de desvio já está pronto.
			Ø OrigAALU em 1 (A na ALU), OrigBALU em 00 (B na ALU), opALU 01 (subtrai)
			Ø Ativar sinal EscrevePCCond
			Ø Colocar OrigPCem 01 (valor do PC vem da ULA)
			
		-> Jump:
		- PC <= {PC[31:28],(IR[25:0]],2’b00)}
		Execução: PC é substituído pelo endereço de Jump
			Ø Colocar OriPC em 10
			Ø Ativar EscrevePC
			
	4. Etapa de acesso à memória ou conclusão de instrucão Tipo-R
	    -> Referência à memória (lw, sw):
		 - MDR <= Memoria[SaidaALU]; #para load
		 ou
		 - Memória[saidaALU] <= B # para store
		 Execução: Em qualquer dos casos o endereço já está na SaidaALU
			Ø IouD colocado em 1 (Endereço da ALU)
			Ø LeMem ou EscreveMem deve ser ativado
		
		-> Instrução Tipo-R:
		 - Reg[IR[15:11]] <= SaidaALU
		 Execução: Colocar o resultado no reg destino
			Ø Colocar RegDST em 1 (usar rd como destino)
			Ø Ativar EscreveReg
			Ø Colocar MemparaReg em 0 (saída da ALU na entrada do banco de reg)
			
	5. Conclusão da Leitura da Memória (lw)
		-> Reg[IR[20:16]] <= MDR;
		Execução: Escrever o dado do MDR no banco de reg
			Ø Colocar MemparaReg em 1 (resultado da memória)
			Ø Ativar o EscreveReg
			Ø Colocar RegDst em 0 (campo rt é o reg destino)
			
@'Mips Multiciclo: Unidade de Controle'

'MIPS Multiciclo Unidade de Controle'
->: Controle feito em uma série de etapas
-> Técnicas de Implementação:
	- Máquinas de Estado Finito
	- Microprogramação

Representação Inicial							Diagrama de estados finitos 		Microprograma
Controle de Sequenciação						Função de próximo estado explícita	Contador de programa + ROM
Representação Lógica 							Equações Lógicas 					Tabelas Verdade
Técnica de Implementação						PLA									ROM

'Controle com MEF'
'Implementação com ROM'
	- Simples!
-> Tamanho da memória
	- 10 bits endereço: 1024 posições de memória
	- 20 bits de dados
Logo ROM de 20kbits
Quantas posições de memória são realmente utilizadas?
-> Porém, ineficiente

'Implementação com PLA (Programable Gate Array)'
-> Mais eficiente:
	- Pode compartilhar termos de produtos
	- Apenas entradas que possuem saídas ativas
	- Pode considerar don’t cares

Tamanho: (EntradasxN.Prod.)+(Saidas xN.Prod)
Tamanho: (10x17)+(20x17)=510 células

'Microprogramação'
'Problemas da MEF:'
-> O projeto da parte de controle através de diagramas de transição de estados pode rapidamente se tornar inviável se o número de estados for muito grande
-> MEF's de processadores complexos podem ter milhares de estados
Uma alternativa para projeto é seguir um processo semelhante a programação

-> Uma microinstrução é definida pelos valores dos sinais de controle que atuam na unidade operativa durante um estado da MEF (ESTADO)
-> A execução de uma instrução do processador pode então ser realizada através de uma sequência de microinstruções (TRANSIÇÕES)
-> O conjunto de microinstruções que implementa o controle de um processador é chamado de microprograma (DIAGRAMA DE ESTADOS)

-> O sequenciamento das microinstruções é realizado de forma similar a de um programa normal
	- microinstruções são usualmente executadas em sequência -> correspondem aos caminhos no diagrama de estados.
	- em alguns casos, a sequência a ser seguida depende de informações externas (código da instrução, por exemplo). 
	Nestes casos, são necessários mecanismos de desvio.
	
'Formato da Microinstrução'
-> A microinstrução é dividida em campos que atuam sobre conjuntos de elementos da unidade operativa
->  Os campos são escolhidos de acordo com sua finalidade. O controle da ULA, por exemplo, é associado a um campo 
-> O microprograma é usualmente implementado em ROM ou PLA, onde cada microinstrução tem seu próprio endereço

@'MIPS Pipeline - Conceitos'

'Objetivo'
-> Apresentar técnicas para aumento de desempenho de uma única tarefa em único processador usando ILP (Instruction Level Parallelism):
	- Pipelining : Técnica de projeto onde o hardware processa mais de uma instrução de cada vez, sem esperar que uma instrução termine antes de
				   começar a próxima.
	- Superpipeline : Técnicas para aumento da eficiência do pipeline.
	- Superescalar: Uso eficiente de múltiplas unidades funcionais.
-> Outros níveis de paralelismo: Aumenta a eficiência em máquinas multi task.
	- Multithread : Várias tarefas independentes simultaneamente, aproveitando-se das “falhas” do pipeline e/ou de estrutura superescalar.
	- Multicore: Vários núcleos em 1 chip, compartilhando memórias caches.
	- Multiprocessor: Sistema multiprocessado/distribuído. Diferentes computadores.
	
'Pipelining: Conceito Básico'
-> uma pessoa leva 5 unidades de tempo para montar uma bicicleta

'Linha de Montagem (pipeline)'
-> uma pessoa diferente para cada tarefa

'Análise'
-> Latência:
	- tempo que uma instrução leva para ser executada
	- MIPS: 5 ciclos
->  Vazão:
	- número de instruções por unidade de tempo
	- 1 instrução/ciclo
-> Qual a aceleração ideal?
	- Para estágios balanceados, condições ideais e grande número de instruções:
						tempo_entre_instruções_com_pipe =  tempo_entre_instruções_sem_pipe/numero)estágios_pipe
						
-> O pipeline só começa a produzir nessa taxa uma vez que linha esteja cheia
-> Primeira bicicleta produzida em 5 UT
-> Após a primeira, o pipe produz uma bicicleta por UT
-> Balanceamento
	- Suponha que a operação Montagem da Roda Trazeira requeira duas unidades de tempo
		- Uma unidade para montar a correia
		- Uma unidade para montar a roda
	- O que ocorre com a latência do pipeline ?
	- O que ocorre com a vazão ?
	- Como otimizar o pipeline neste caso ?

'Pipeline'
-> O que facilita o pipeline:
	- Todas instruções têm o mesmo comprimento.
		- Obs.: IA-32 instruções de 1 a 17 bytes
	- Poucos formatos de instruções.
		- Obs: Tipo-R, I , J operandos “quase” nas mesmas posições
	- Operandos em memória só aparecem em loads e stores.
		- Obs.: Pode-se usar a ULA para cálculo de endereço.
	O mesmo não vale para busca de operandos da ULA da memória (IA-32)

-> O que complica (hazards):
	- Riscos Estruturais	
	- Riscos de Controle
	- Riscos de Dados
	
'Hazard Estruturais'
-> Hardware pode não admitir a combinação de instruções e um mesmo ciclo de clock.
	- uma pessoa apenas para montar as bicicletas
	- Considerando apenas 1 memória para dados e instruções, como ficaria uma quarta instrução no exemplo dado?

'Hazard de Dados'
-> Pipeline precisa ser interrompido por que uma etapa precisa esperar até que outra seja concluída (dependência de dados).
	- Exemplo:
		- add $s0,$t0,$t1
		- sub $t2,$s0,$t3
-> Soluções:
	-  Inserção de Bolhas
	-  Execução fora de ordem (compilador e processador)
	-  Forwarding ou bypassing
	
	'Execução Fora de Ordem'
	-> Aproveitar os espaços das bolhas para tarefas úteis que sejam independentes.
	-> Alterar o algoritmo sem alterar o resultado!

	'Forwarding'
	-> Observação: não é necessário esperar que a instrução termine antes de tentar resolver o hazard de dados.
	
'Hazard de Controle'
'Hazard de Controle'
-> Necessidade de tomar uma decisão com base nos resultados de uma instrução enquanto outras estão sendo executadas
BEQ é avaliado pela ULA no 3º estágio => Necessita 2 bolhas!!!
-> Alterando o caminho de dados para que o BEQ seja avaliado no 2º Estágio => Economiza 1 Bolha!!
-> Delayed Branch: ocupar a bolha com uma instrução útil, equivalente a atrasar a execução do Branch
 No exemplo: add $4,$5,$6 no lugar da bolha
 
 -> Prevendo estaticamente o desvio como não tomado
	- Formas Dinâmicas de Previsão:
		•Endereço é anterior? Prevê tomar o desvio
		•Armazenamento do histórico

'Acelerando máquinas com pipeline'
-> A velocidade máxima de uma máquina com pipeline é de uma instrução por ciclo de clock. Correto?
-> Técnicas para iniciar múltiplas instruções em 1 ciclo de clock:
	o Estruturas superpipeline
	o Estruturas superescalares.
	
'Acelerando máquinas: Superpipeline'
-> A estrutura Superpipeline subdivide cada estágio do pipeline em subestágios, e multiplica internamente a frequência de clock.
-> Cada (sub)estágio continua executando uma instrução por clock. Mas como o clock interno é multiplicado, o pipeline pode aceitar duas ou mais instruções 
para cada clock externo.

'Acelerando máquinas: Superescalar'
	-> A estrutura superescalar contém múltiplas unidades funcionais que são capazes de fazer a mesma tarefa.
	-> Isto permite ao processador executar várias instruções similares concorrentemente, pelo roteamento das instruções às unidades de execução disponíveis.
	
@'MIPS Pipeline – Unidade Operativa e Controle'

'Controle do pipeline'
-> Temos 5 estágios. O que deve ser controlado em cada estágio?
	IF: Instruction Fetch e PC Increment
	ID: Instruction Decode / Register Fetch
	EX: Execution
	MEM: Memory Stage
	WB: Write Back
	
-> Busca da instrução:
	- Nenhum sinal de controle
->  Decodificação da instrução / leitura do banco de regs.:
	- Nenhum sinal de controle
->  Execução / cálculo de endereço:
	- RegDest, OpALU, OrigALU
->  Acesso a memória:
	- Branch, LeMem, EscreveMem
->  Escrita do resultado
	- MemparaReg, EscreveReg

	
