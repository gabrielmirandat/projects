romariz@unb.br

objetivo:
Circuitos Sequenciais.
Memória.
Microcontroladores.

sabemos:
Códigos Digitais.
Portas Lógicas.
Circuitos Combinacionais
Noções de VHDL

O que ainda vamos aprender?
  Como projetar sistemas que reagem a um histórico de entradas anteriores?
  Ex: Receber bits serialmente e apresentá-los em paralelo.
Como armazenar eletronicamente dados digitais?
Como são organizados os computadores digitais?
Como se programam microcontroladores?

#Ementa e Programa
  ->Latches e flip-flops.
    -Elementos bi-estáveis; tipos de latches; tipos de flip-flops.
  ->Circuitos sequenciais síncronos
    -Modelos de Mealey e Moore; Diagramas de Estados; Projetos de Máquinas síncronas.
  ->Circuitos sequenciais assíncronos
    -Atribuição de Estados; Projetos de Máquinas Assíncronas; Corridas e Riscos.
  ->Registradores e Contadores
    -Registradores; Contadores sincronos; contadores em anel
  ->Memória.
    -Histórico; Memória de Leitura Apenas ; Memória de Escrita e Leitura.
  ->Sequenciadores
    -Máquinas de estados com registradores e contadores; Máquinas programáveis; Máquinas com Instruções
  ->Microcontroladores
    -Arquitetura ; Conjunto de Instruções ; Microcontrolador 8051 ; Programação em Assembly
	
Módulo 1: Latches e Flip-Flops

	Aula 1-1: Circuitos bi-estáveis ; “Latches” e flip-flops
	
'Sistemas Sequenciais'
Definição
➔Dependem não apenas dos valores atuais das entradas.
➔Dependem da sequência passada de entradas.
➔São a grande maioria dos sistemas digitais de interesse.
Exemplos
➔Circuito que recebe bits de uma linha serial e informa a palavra de 8 bits em paralelo (Conversor série-paralelo)
➔Circuito que, a cada sinal de entrada, soma 1 à saída (contador)
➔Cadeado com segredo (entrada dos números em sequência, o que escolhe um pra cada número não é sequencial, é combinacional).

'Bi-estabilidade'
● Para que o sistema tenha memória, é preciso que se mantenha, por seus próprios meios, em pelo menos 2 estados possíveis (1 bit).	

'Retroalimentação (feedback)'
● É possível obter-se multi-estabilidade por meio de retroalimentação (conexão entre saída e entrada).

'Estado Estável I'
● Se Q =1 → Q_L = 0 → Mantém Q=1 (Estável)

'Estado Estável II'
● Se Q =0 → Q_L = 1 → Mantém Q=0 (Estável)

'Equilíbrio Instável'
● É teoricamente possível termos Q e Q_L em um estado entre 0 e 1 lógico.
● Instável (qualquer mínimo desvio do equilíbrio vai levar a um dos estados estáveis).

'Problema com o arranjo'
● Ao ligarmos o circuito, teremos Q=1 ou Q=0, mas não sabemos qual. Depende de detalhes e assimetrias entre as duas portas.
● Não há uma entrada para levar de um estado a outro.
	
'Latches e Flip-Flops'
● Latch (Ferrolho, Trinco)
	– Pode ser levado a um de seus estados estáveis a qualquer momento.
● Flip-flop (de flip: virada, mudança positiva,sucesso, flop: queda, fracasso, mudança para pior).
	– Só responde a tentativas de mudança em um instante específico.
	
'Latch SR'
● Entradas S e R
● Pode ser levado a um dos estados estáveis,e manter-se no estado sem auxílio das entradas.

'Latch SR – Comando “Set”'
● “Set” (armar, preparar) leva ao estado Q=1, QN=0.
● Só funciona corretamente se R=0.
● Se posteriormente fazemos S=0, o estado se mantém.

'Latch SR – Comando “Reset”'
● “Reset” (desarmar) leva ao estado Q=0, QN=1.
● Só funciona corretamente se S=0.
● Se posteriormente fazemos R=0, o estado se mantém

'Latch SR S=1, R=1'
● Não é “proibido” nem “indefinido”!
● Leva a um estado em que Q = QN (logicamente sem sentido).
● Se S e R voltarem a zero com pouca diferença de tempo, não se sabe o estado resultante!

'Latch S^R^'
● É um latch SR em “ativo baixo”.

'Latch SR com Enable'
● Latch só recebe comandos se C=1

'Latch D (ou Latch Transparente)'
● Observe que continuamos a chamar “Latch” porque a transição não ocorre em um “instante” apenas

'Importância da Temporização'
● Este é um modelo das máquinas de estado que vamos estudar.
● A Memória de Estado é constituída pelos Flip-Flops.

'Flip-Flops'
● Muitas vezes, é conveniente que o dispositivo bi-estável só seja sensível à entrada em um curto período de tempo.
● entre bordas iguais -> Tempo para calcular qual deve ser o novo estado. É importante que os elementos de memória não possam trocar de estado aqui.
● Soluções Possíveis
	– Par “mestre-escravo”.
		● Um par de Latches com relógios invertidos.
		● Solução antiga.
	– Detetor de borda.
	– Latch internamente sensível à borda apenas.
		● Estudaremos adiante (“Máquina Assíncrona”)
		
'Flip-Flop D “Mestre-Escravo”' -> dar olhada
● CLK=0
	– Mestre recebe entrada, mas não repassa à saída.
● CLK=1
	– Saída recebe o último valor do mestre antes da subida.
	
	subiu no 1 fica 1, subiu no 0 fica 0?
	
'Flip-Flop D “Mestre-Escravo” com PRESET e CLEAR'
● Entradas que levam ao estado Q=1 (Preset) ou Q=0 (Clear), de maneira independente do relógio ou da entrada D.
● Tipicamente definem os estados iniciais.

'Flip-Flop JK'
● A rigor, com o Flip-Flop D, podemos construir qualquer tipo de sistema sequencial.
● No entanto, Flip-flops com comportamento mais complexo podem tornar o sistema mais simples. Por exemplo, podemos ter um FF que aceite os comandos:
	– Armar.
	– Desarmar.
	– Trocar de estado.
● Multiplexador seleciona J, K ou o estado anterior reverso como entrada.

'Flip-Flop T'
● Em alguns casos, o elemento de memória deve apenas trocar de estado a cada mudança do relógio.

'Flip-Flop T com enable'
● Neste caso, o FF troca de estado na subida do clock, apenas se EN=1.

'Versões do FF T' - vide figura
● Atenção, diferentes autores se referem ao Flip-Flop tipo T de diferentes maneiras:	
● Na notação da esquerda, a entrada T substitui o relógio como usado nos outros FFs. Uma entrada habilitadora (EN) informa se o circuito deve ou não trocar
     de estado.
  Na notação da direita (que eu prefiro), o relógio continua sendo o relógio, e a entrada que habilita a mudança de estado chama-se T.
	
Porta C de Muller - Circuito
  ● Introduz uma bi-estabilidade controlada.
  ● Duas entradas
  ● Mesmo conceito do par de inversores. 
  ● Um inversor é "mais fraco"que o outro.
  ● Efeito de memória.
  
O que é a "força"de uma porta?
  ● Chave ideal em série com resistência.
  ● Se chave representa saída de porta lógica, R é a "Impedância de saída".
  
'Temporização'
● Em máquinas de estados tempos flip-flops para armazenamento.
● Se os FFs respondem a qualquer momento, uma transição temporária da Lógica de Próximo Estado pode levar a uma transição indevida de estado. 

'Parâmetros de Temporização'
● Tempo de atraso
  - Tempo típico entre 50% da transição da entrada e  50% da transição correspondente na saída.
  - Pode ser diferente para transições baixo-para-alto (LH) e alto-para-baixo(HL). 
  - Pode ser diferente para transições provocadas pelo relógio (C) ou por D. 

● Tempo de preparação (setup, ativação)
  - Janela de tempo anterior à transição de relógio (metade da rampa) em que as entradas devem permanecer constantes.
● Tempo de sustentação (hold)
  - Janela de tempo posterior à transição de relógio (metade da rampa) em que as entradas devem permanecer constantes.
● Violação dos tempos de Hold e Setup podem levar a estados indeterminados  

'Projeto de Flip-Flops'
● A partir de um Flip-Flop XY dado, construir um Flip-Flop com outra funcionalidade.

Método: 
  1. A partir da Tabela de transição do FF desejado, identificar os valores das variáveis X e Y.
  2. Simplificar a expressão. 
  
  1)Tabela de transição
  2)Tabela de transição e excitação

'Aplicação de Latch'
● Mendonça 6-17 - “Debouncer” (circuito para remover osilações de chave)
● Problema: A chave tradicional simples produz ruído elétrico nos contatos, porque no movimento da chave os contatos são abertos e fechados
múltiplas vezes até o equilíbrio. 

'Debouncer – Solução com Latch '
● Supor que começamos no estado ON, com Vs=1. A desconexão do contato ON ocasionará vários comandos Set, mas isto não afeta a saída. Quando
começa a conexão do contato OFF, haverá vários reset, mas o primeiro deles leva Vs a zero, e os demais não têm efeito.
● Pode-se também controlar o efeito por software. Espera-se o sinal estar estável por um certo nível de ciclos antes de tomar uma decisão.  

Módulo 2: Máquinas de Estados
			Aula 2-1: Introdução
			
'Máquina de Estados'
● Ou máquina de estados finitos ou ainda Autômato Finito.
● Modelo de dispositivo computacional com memória rudimentar
	− Entradas.
	− Memória de Estados
	− Regras de Transição entre Estados (fixas).
	− Saídas.
	
'Máquinas de estados - Exemplos'
• Sinal de trânsito.
	• Transita entre os estados {Vermelho, Amarelo,Verde} a partir dos sensores de presença, comandos locais e remotos, e temporizadores.
• Máquina de vendas
• Protocolo de comunicação.
• Tradutores e compiladores.

'Estado'
● Conjunto mínimo de variáveis que
	− Resume todo o histórico de interesse.
	− Permite definir sem ambiguidade a saída futura a partir das entradas atuais e futuras.
● Exemplos:
	− Em um contador: número da contagem atual.
	− Detetor serial de paridade: paridade dos bits entrados até agora (par / ímpar)
	
'Modelo de Mealey'
● Saída depende do estado atual e da entrada atual
● Saída não pode ser representada dentro do estado.

'Modelo de Moore'
● Saída depende do estado atual apenas.
● Com mudanças nas transições de estados, podemos transformar M. Mealey em M. Moore e vice-versa
● Saída representada dentro do estado.

'Diagrama de Estados'
● Representa os estados e as transições na máquina.
● Ex: Detetor serial de paridade – Modelo Moore.
● Entrada I e saída P.(I=0 ou I=1)
● Representação alternativa para transições. (I ou Ib)
● Em Mealy:
	- Significado dos estados é menos claro.
	- Atenção! Saída P não é produzida na transição de um estado para outro! − É apenas uma questão de representação.
	
'Limitações das Máquinas de Estado'
● Têm memória finita.
	− As transições são fixas.
	− Neste sentido, a Máquina de Turing é um modelo mais geral (aqui um programa pode se alterar - transições dinâmicas).
	
'Máquina de Turing'
● Modelo Teórico de Computação.
● Constituído por
	− Leitora / Gravadora de Símbolos.
	− Fita infinita.
	− Máquina de estados que determina qual símbolo gravar, para onde andar com a fita e qual o próximo estado.
● Todas as tentativas de definir computação resultaram em modelos equivalentes.
● Tese de Church-Turing
	− Tudo o que é efetivamente computável pode ser computado com a máquina de Turing.
● Usada para definir "efetivamente calculável" no contexto do Entscheidungproblem de Hilbert (problema da decisão).
● Há um procedimento bem definido (que possa ser seguido mecanicamente, sem intuição ou criatividade) que permita determinar a verdade 
de qualquer proposição lógica?
	- Turing (e Church independentemente) provam que a resposta é negativa.	

'Análise de Máquina de Estados'
- Equações de excitação
- Equações de Estado
- Tabela de Transição de Estados
- Diagrama de Estados

		Aula 2-2: Síntese de Máquina de Estados
		
'Etapas do Processo de Síntese'
- Traduzir a especificaç˜ao em um diagrama de estados
- Procurar minimizar estados
- Atribuir variáveis de estado e assinalar estados
- Tabela de transições e saídas
- Definir tipo de Flip-Flops
- Minimizar lógica de transição e de saída

'Diagrama de Estados'
● Minimização
	- Por inspeção, n˜ao há estados equivalentes.
		- Estados para os quais entradas iguais levam a estados e saídas iguais.

● Atribuição de Estados
	- Princípios
		- Atribuir o estado inicial que pode ser facilmente forçado(000.... ou 111....).
		- Tentar minimizar o número de mudanças de variáveis nas transições.
		- No exemplo em quest˜ao, 3 estados n˜ao s˜ao usados.
		
● Estados n˜ao-atribuídos		
	- Soluç˜ao de Mínimo Risco
		- Por algum erro transiente de hardware , a máquina pode chegar ao estado n˜ao-atribuído.
		- Estado n˜ao-atribuído deve transitar para estado definido (Ex:000) com qualquer entrada.
		- Saída nos estados n˜ao-atribuídos deve ser especificada (no caso, Z=0).
	- Soluç˜ao de Minimo Custo
		- Usar estados n˜ao-atribuídos como ”don’t cares” nas transiç˜oes e nas saídas. 
		
● Variação do Primeiro Problema - FFs JK
	- Motivaç˜ao
		- Maiores opç˜oes de controle podem levar a implementação mais simples.
		- Faremos aqui como exercício apenas.
		
	- Modificação do projeto
		- Até a etapa de atribuição de estados, o problema é o mesmo.
		- No caso do FF D, tínhamos D = Q*. Para o JK, é preciso uma Tabela de Aplicação
		
		Aula 2-2: Síntese de Máquinas Síncronas Exemplo; Máquina Fatorada
		
● Uso de Registrador (Flip-Flop tipo D) - de OAC!! - armazena variáveis

'Fatoramento de Máquinas'
● É interessante, em casos mais complexos, dividir o problema. As transições da máquina principal são 
função de variáveis calculadas por outras máquinas de estado.
● Exemplo: Incluir o modo “Parada” na máquina anterior. Se acionado (entrada P), uma vez que o sinal 
fique verde para Bravado, continua verde até um sinal R subir
● Modo (M) é determinado por uma outra máquina, a partir das entradas P e R

		Aula 2-3: Mapas de Karnaugh com Variáveis Introduzidas
● Se expressarmos o valor-verdade de uma função lógica em em termos de uma variável, eliminamos 
esta variável da Tabela-Verdade.

Exemplo: Funções f, g e h, de três variáveis
	- Se f é função de A,B e C, podemos introduzir C na sua tabela verdade e ai fica em função de A e B.
	- Se função g, tal que:
		C = 0 e g = d	então g = /C*d	
		C = 1 e g = 0

'Mapa de Karnaugh com V.I. (2)'
● Seja V a variável introduzida. A solução será feita em três etapas: agrupamentos com V, agrupamentos 
com /V e outros agrupamentos.
	- Primeira Parte: Agrupamentos com V. Exemplo.
		- Observe que também valeriam 1 as células contendo 1 e V+/Vd.
		- Estes termos devem ser incluídos nos grupos, para chegarmos à função mínima. No entanto, não se preocupe 
		com estes termos isoladamente!
		#Termos com Vd, /V+Vd e d podem ser incluídos no grupo, se facilitarem a criação de grupos maiores.
	- Segunda Parte: Agrupamentos com /V. Exemplo.
		- Observe que também valeriam 1 as células contendo 1 e /V+Vd.
		- Estes termos devem ser incluídos nos grupos, para chegarmos à função mínima. No entanto, não se preocupe 
		com estes termos isoladamente!
		#Termos com /V.d, V+/V.d e d podem ser incluídos no grupo, se facilitarem a  criação de grupos maiores.
	
	Resumo: Termos com a variável introduzida (V, /V)
		1. O objetivo desta etapa é cobrir os termos V e com /V apenas. Outros termos não devem ser combinados 
		isoladamente, mas podem ser combinados para formar grupos.
		2. Combinar todos as células que contém V. Para formar grupos, dar prioridade às células com 1 e com 
		V+ /V d. PODEM ser incluídos, para formar grupos maiores, células contendo V.d, /V + V.d e d.
		2. Combinar todos as células que contém /V. Para formar grupos, dar prioridade às células com 1 e com 
		/V+ V d. PODEM ser incluídos, para formar grupos maiores, células contendo /V.d, V + /V.d e d.
		
		● Ao final da etapa 1, precisamos inspecionar as células do mapa. Elas podem necessitar mudanças para a 
		etapa 2. Vejamos caso a caso.
			– Célula tem '0'. Obviamente não foi incluída em nenhum grupo.Permanece '0'.
			– Célula tem 'V'. Já está incluída no termo em V. Substituir por '0'.
			– Célula tem '/V'. Mesmo argumento. Substituir por '0'.
			– Célula tem 'd'. Mesmo que já tenha sido usada, continua sendo um “don't care”. Permanece 'd'.
			– Célula tem '1' e não foi incluída em nenhum grupo. Peramence '1'.
			– Célula tem '1' e foi incluída em grupo(s) contendo V (ou /V) apenas. Permanece em '1' porque é preciso 
			levar a 1 também no caso complementar (é verdadeiro para V=0 e para V=1).
			– Célula tem '1' e foi incluída em pelo menos 1 grupo com V e 1 grupo com /V. Substituir por  'd'. (ainda 
			pode ser útil para minimização).
			– Célula tem 'V+/V.d' e não foi incluida em grupo com V. Substituir por '1'.
			– Célula tem 'V+/V.d' e foi incluída em um grupo com V. Substituir por 'd'.
			– Célula tem '/V+V.d' e não foi incluída em grupo com /V. Substituir por '1'.
			– Célula tem '/V+V.d' e foi incluída em um grupo com /V. Substituir por 'd'.
			– Célula tem 'V.d'. Substituir por '0'
			– Célula tem '/V.d'. Substituir por '0'
			
- Em forma Produto de Somas...
	- Melhor minimizar /f e depois aplicar De Morgan.
	● Pares de inversas: Dd  ->  /D+Dd
						 /Dd ->  D+/Dd
						 
		Aula 2-4: Síntese de Máquina de Estados - Outro exemplo
'Designação de Estados'
● Designação decomposta (Cada variável indica algo específico).
● QC indica estado inicial.
● QB indica entradas iguais ou diferentes no último período.
● QA indica Z=1.

#Módulo 4: Registradores e Contadores
Aula 4-1: Registradores e Contadores – Topologias Básicas

'Registradores'
● Conjunto de Elementos de Memória.
● Armazenamento Temporário.

'Registrador – Topologia Básica'
#Se LOAD=0, Di = Qi (mantém estado). Se LOAD=1, Di=Xi (Carrega dados).

'Registrador de Deslocamento'
● Além de Armazenar, permite que os bits sejam deslocados à direita e à esquerda.
● Aplicações:
  – Conversão Serial / Paralela.
  – Operações Aritméticas.
  – Acionamento sequencial de saídas.
● Entrada serial por D0. Bits passam à esquerda a cada subida do relógio.

'RD Controlado'
#Se SHL=1, desloca-se à esquerda. Se SHL=0, mantém-se o estado.

'RD em VHDL'
- Descrição comportamental de um RD de 8 bits com as seguintes funções:

Função			Controle
		S2 	   S1 	      S0
Hold		0	   0	       0
Load		0	   0	       1
Shift R		0	   1	       0
Shift L		0	   1	       1
Shift CR	1	   0	       0
Shift CL	1	   0	       1
Shift AL	1	   1	       0
SHift AR	1	   1	       1

SCR = shift circular à direita.
SCL = shift circular à esquerda.
ASR = shift à direta aritmético (mantém sinal).		//Divisão por 2 em complemento de 2. Repete bit 7 à esquerda (sinal).
ASL = shift à direta aritmético (mantém sinal).

#Registrador em VHDL
• S: Entradas Paralelas 
• Q: Estado (Saída) 
• D: Vetor de comando 
• Rin: Entrada serial para deslocamento à direita 
• Lin: Entrada serial para deslocamento à esquerda. 

entity Vshftreg is
  port (
    CLK, CLR, RIN, LIN: in STD_LOGIC;
    S: in STD_LOGIC_VECTOR (2 downto 0); -- function select
    D: in STD_LOGIC_VECTOR (7 downto 0); -- data in
    Q: out STD_LOGIC_VECTOR (7 downto 0) -- data out
  );
end Vshftreg;

process (CLK,CLR,IQ)
  begin
    if (CLR='1') then IQ <= (others=>'0'); 
    elsif (CLK'event and CLK='1') then
    case S is 
      when "000" => null;
      when "001" => IQ <=D; 					-- Load
      when "010" => IQ <=RIN & IQ(7 downto 1); 			-- Shift Right
      when "011" => IQ <=IQ(6 downto 0) & LIN ;  		-- Shift Left
      when "100" => IQ <= IQ(0) & IQ(7 downto 1); 		-- SCR
      when "101" => IQ <= IQ(6 downto 0) & IQ(7); 		-- SCL
      when "110" => IQ <= IQ(7) & IQ(7 downto 1); 		-- Arithmetic SR
      when "111" => IQ <= IQ(6 downto 0) & '0'; 		-- ASL
      when others => null;
    end case;
  end if;
Q <=IQ;
end process;

#Contadores
● Circuito com uma sequencia pré-definida de estados a seguir. 
● Aplicações 
  – Contagem de Tempo.
  – Sequenciadores.
  
'Contador Assíncrono'
● “Ripple Counter”
● Q0 troca a cada ciclo. 
● Q1 troca a cada dois ciclos.  
● Sequencia de estados
    – 0000 , 0001 , 0010, ...
● Os atrasos nas transições se acumulam. 
● Exige uma frequencia relativamente baixa de operação. 

'Contador Síncrono'
● Todos os FF recebem o mesmo sinal de relógio.
● Transições garantidas por lógica.
● Pode operar em frequências maiores.

'Contador em Anel'
● Apenas um bit '1' circula pelo contador. 
● Fácil decodificação (código 1-de-N). 
● Acionamento sequencial de saida.

'Estados do Contador em Anel'
● 16 estados, 4 para contagem, 12 não-usados.
● Se o sistema chegar a um estado espúrio, não retorna.

'Contador em Anel com correção'
● Uma simples porta NOR implementa a solução
● Observe que o FF mais significativo pode ser dispensado (Q3 sai da própria NOR). 
● Outra solução (veja que Q0 está à direita). O sistema passa apenas transitoriamente por estados errados. 

#Contador Johnson
● Ou Contador em Anel Torcido ou Contador Möebius
● Sequência 0000 – 1000 – 1100 – 1110 – 1111 – 0111 – 0011 – 0001 -
● 2N estados na sequência de contagem. 
● Por que Möebius?

#RD com retroalimentação linear
● Um XOR de saídas selecionadas de um RD, com o  resultado introduzido como em um dos bits, produz uma sequência de 2N-1 estados (o estado 000... fica isolado). 
● Além de longa, esta sequência é difícil de prever, se não houver acesso ao circuito (Sequência Pseudo-Aleatória).
● Ex: Supor um RD de 3 bits, com X2 = (X1 XOR X0) E APÓS ISTO FAZ O DESLOCAMENTO PARA A DIREITA. 
● Partindo-se do 001, temos 
● 001, 100, 010, 101, 110, 111, 011
● (Sequência 1, 4, 2, 5, 6, 7, 3)

Módulo 4: Sequenciadores (mas na verdade é CONTADOR)
Aula 4-1: Motivação e Exemplo

● Implementamos a memória de estado a partir de FlipFlops.
● Mas podemos usar CONTADORES, REGISTRADORES ou uma ROM 

CONTADORES
● Se a transição de estados aproveitar as transições naturais nos contadores, a lógica de transição pode ser simplificada.  
● Pequenas alterações podem ser feitas na máquina com pouca mudança na lógica de estados. Esta ideia levará, mas adiante, à definição de sequenciadores 
(ou nanocontroladores) e microprocessadores, no qual um hardware fixo é programado para executar diversas funções.

Toca-CD: Diagrama de Estados
- Atribuição foi feita pensando no uso de um contador.

Contador 74161
● 4 bits
● Clear Assíncrono
● LOAD Síncrono
● LOAD tem prioridade.
● Para implementar a máquina, vamos usar 2 modos: 
	– Contagem (E=1) 
	– Carregamento (LOAD_L=0)

Uma última preocupação
● As saídas do contador podem ter transitórios quando mais de um bit muda.
– Usar Latches D na lógica de saída, acionados pela borda de descida.
● Borda de subida atualiza o estado da máquina, descida atualiza as saídas.

Módulo 4: Sequenciadores
Aula 4-2: Sequenciador a partir de contador

Objetivo
● Implementar um dispositivo (Sequenciador, ou Nanocontrolador) capaz de reconhecer e executar instruções pré-fixadas em sequência.
	– O projeto de máquinas de estado se resume a um PROGRAMA de instruções pré-fixadas.
● Na aula de hoje, vamos conceber tal dispositivo a partir do contador utilizado na aula passada no problema do Toca-CD, e aplicá-lo ao mesmo problema.

Elementos do Sequenciador
● Porta de Entrada
	– As entradas para o sistema. Mais de uma entrada pode ser ligada à mesma porta por um MUX. A seleção da entrada considerada em um instante depende 
	da instrução que está sendo executada.
● Instrução
	– O código de uma das instruções pré-definidas, que é carregado de uma memória ROM.
● Endereço de carga	
	– O endereço correspondente ao próximo estado, quando precisa ocorrer um salto.
● Saídas
	– Controlada por conjuntos de flip-flops para evitar problemas com transitórios.

Explicando Entradas e FLAG
● Tipicamente, as transições dependem de uma variável em cada caso.
● A solução é dizer que as instruções podem depender de uma condição (“Flag”, bandeira, indicação, sinal). Por exemplo, “conte adiante se Flag=1”.
● O MUX seleciona a qual variável se refere a condição. Esta seleção também vem do programa.

Conjunto de Instruções
● Contagem Incondicional (CI)
	– Siga para o próximo estado da contagem.
● Salto Incondicional (SI)
	– Siga para o estado especificado.
● Contagem Condicional (CC)
	– Se FLAG=1, siga para o próximo estado da contagem. Caso contrário, fique onde está.
● Salto Condicional (SC)
	– Se FLAG=1, siga para o estado especificado. Caso Contrário, fique onde está.
● Contagem ou Salto (CSC) 
	– Se FLAG=0, siga para o próximo estágio da contagem, caso contrário vá para o estado especificado.
● Salto ou Contagem (SCC)
	– Se FLAG=0, salto ; caso contrário, contagem.
● Parada (PR)
	– Fique onde está
● Salto para o zero (ZR)
	– Vá para o Estado Zero.
	
Implementação com contador
● Para cada instrução, especificar, os sinais E (habilita contagem), LD (carregar).
● Criado um sinal SZ que indica se o carregamento deve ser o zero ou outro valor.
● D,C,B,A vão vir da ROM, ou então serão 0,0,0,0 se SZ=1.

Problema no Diagrama de Estados
- Nanocontrolador só faz saltos condicionados a uma variável apenas.
- Solução: Primeiro, checa se OP+PL foi acionado. Depois, decide se foi OP + PL.

Implementando o Diagrama
● Com o sequenciador funcionando, o funcionamento da máquina depende apenas do conteúdo da memória ROM. Esta memória deve conter, para cada estado 
(ou seja, cada endereço):
	– O OpCode da instrução.
	– O endereço de carga
	– O Flag de entrada
	– Os valores de saída.
	
● Canais de entrada no MUX:
	– CD (000)
	– OP+PL (001)
	– OP (010)
	– MOK (011)
	– EJT (100)
	– CL (101)
	– RCD (110)
	– ST (111)
	
Módulo 3: Memória
Aula 3-1: ROM e PROMs

Memória
● A princípio, qualquer sistema sequencial tem “memória”. Mas em geral o termo é reservado para um dispositivo que armazena bits em uma estrutura bem definida. 
	– Recebe um endereço
	– Informa uma pal avra binária (conjunto de bits de extensão pré-definida)

Memória ROM
● “Read-only Memory”
	– Tem seu conteúdo determinado uma única vez, na fabricação.
	– Aplicações: Instruções iniciais para uma máquina (ciclo de boot) , Tabela-Verdade de uma função lógica
	
Estrutura de uma memória ROM
- Total 8 x 16 bits
- Bits 4 a 6 do endereço seleciona linha
- Bits 0 a 3 de endereço seleciona coluna

ROM - Bit zero
- Onde não há diodo, a saída do decoder não tem efeito aqui.
- Não há corrente nesta linha, então a tensão é alta aqui. A saída é ZERO se a célula for selecionada.

- Se esta linha é selecionada, a tensão é baixa.
- Por conta deste diodo, a tensão nesta coluna cai.

Em resumo
- A presença de um diodo marca um bit '1' na linha e coluna correspondente.
- A regularidade do projeto elétrico torna possível automatizar o design da ROM.

ROM com transistores
- `D' e `S' ligados se G = `1`

Memória PROM
● Programmable ROM
	– O usuário pode programar (1 única vez) o conteúdo da ROM.
	– Na fabricação, há diodos (ou transistores) em todas as posições.
	– Um pulso de alta tensão “queima” os diodos (ou transistores) na posição onde se deseja um bit zero.
● Aplicações comuns
	– Consoles de videogame, celulares, eletrônica automotiva.
	
Memória EPROM
● Erasable Programmable
● Unidade de conexão é o transistor com porta adicional isolada. 
- Pulso de alta tensão em G1 rompe momentaneamente o isolante, aprisiona carga em G2. Efeito é o mesmo que tensão aplicada em G2. Permanece, a princípio, 
  indefinidamente.
- Incidência de Luz Ultravioleta dá às cargas armazenadas em G2 energia suficiente para escapar do isolante (apagamento).
● Aplicações típicas: Protótipos, Alguns Microcontroladores,
● Facilmente reconhecida pela janela transparente.

Memória EEPROM (E2PROM)
● Electrically-erasable PROM
● Memória “Flash”
● Basicamente a mesma estrutura da EPROM. Camada isolante se tornou mais fina, permitindo o apagamento elétrico.
● Pen Drives, memória de massa de netbooks e tablets.

ROM - Temporização
- Atraso entre desseleção e desconexão (alta impedância).
- Atraso entre mudança de endereço e invalidade de dados.
- Atraso entre (CS e OE) e saída conectada.
- Atraso entre seleção do chip e saída válida.
- Atraso entre endereço estável e saída válida.

Módulo 3: Memória
Aula 3-2: RAMs

Memória RAM
● Em oposição de memórias de leitura apenas (ROM), existem estruturas de memória que permitem a leitura e escrita. Ficaram conhecidas como RAM 
(“Random Access Memory”), que é um nome bastante infeliz.
	– O nome diz apenas que posso acessar pontos da memória a qualquer instante. E nem isso faz direito (“aleatório” lembra “sem controle”). Seria melhor
	  “acesso livre”.
	– A questão de o acesso ser serial (como em uma fita magnética) ou livre (como em um disco) nada tem a ver com poder ler e escrever.
	– As memórias flash são ROMs programáveis mas, exceto pelo tempo de acesso, agem como RAMs.
	
Tipos de Memória RAM
● RAM Estática.
	– Mantêm o dado gravado indefinidamente enquanto houver energia.
● RAM Dinâmica.	
	– Mantêm o dado gravado por uma janela de tempo. Requerem regravação periódica (“refresh”).
	– Circuitos mais simples, permitem muito maior densidade (mais bits no mesmo espaço).

RAM Estática – Célula
● Basicamente, um latch tipo D. Observe que a saída é em três estados, controlada pelo sinal SEL_L.

RAM Dinâmica - Célula
● Endereço multiplexado. Linha informada, depois coluna.Sinais RAS e CAS (Row/Column Address Strobe) usados para informar a temporização.
● Decoder, mux, demux, ..

Operação de “Refresh”
- Há vários modos. Acima está mostrado o modo “RAS-only refresh cycle”. Refresca toda uma linha sem efetuar leitura ou escrita na memória. Observar que ambas 
as bordas do sinal RAS_L são usadas. Na queda, o conteúdo é armazenado em latches internos, e na subida é gravado de volta.

Temporização do Refresh
● DRAMs modernas estão organizadas em 4096 linhas, que devem ser refrescadas a cada 64 ms:
– 1 linha a cada 15,6 μs.
– Operação dura 100 ns.
– Memória está disponível para outras operações (15,5/15,6)*100 = 99,4% do tempo.



Módulo : Microcontroladores
Aula -1: mP e MC: Tipos, Histórico, Atualidades

Microcontroladores (8051)
x
Microprocessadores = +complexo, +poder, +caro

Arquitetura RISC

'INSTRUÇÕES'

1) Saltos incondicionais
– JMP K    = Próxima instrução será buscada na posiçao K.
– JMP R    = Próxima instrução será buscada na posição indicada pelo registrador R
– JMPREL K = Salto Relativo: Próxima posição será buscada em PC+K (salta K posições da memória)

2) Saltos condicionais
– JZ (Jump if Zero)          = Salta se o último resultado aritmético foi zero.
– JNZ (Jump if Not Zero)
– JS (Jump if Signal), JNS	 = Condicional ao Flag de Sinal.
– JC (Jump if Carry), JNC
– JP (Jump if Parity), JNP
– JO (Jump if Overflow), JNO

Usada para armazenamento temporário e armazenamento do endereço de retorno em sub-rotinas.
PUSH R1 = SP++	pilha = R1
POP R1 = R1 = dado SP--

Sub-rotinas
Trecho de código executado repetidamente.
	● Execução é desviada para o início da subrotina, mas, ao contrário do salto, o valor do PC é armazenado para que se retorne ao mesmo ponto ao 
	  final da execução.
	● Instruções CALL e RET

8051
● Memória de Programa (64Kbytes x 16 bits)
● Memória de Dados Externa (64Kbytes x 16 bits)
● Memória de Dados Interna (256 bytes x 8 bits)
● Área de bits (256 bits) (usa 32 bytes da RAM)

RAM Interna
● Nos 256 bytes da RAM interna estão os bancos de registradores, área para acesso bit-a-bit e área de RAM livre.
● A região entre 0H e 1FH (32 bytes) contém 4 bancos de 8 registradores (R0-R7).
● O banco em uso no momento é determinado por dois bits (RS1 e RS0) da palavra de estado do programa, como veremos a seguir.
● A região de 20H a 2FH (16 bytes) é usada para acesso de dados bit-a-bit (128 bits) – Instruções reconhecem bits desta área no formato byte.bit (Ex: 20H.0)
● 80 bytes entre 30H e 7FH são livres, mas não acessáveis bit-a-bit.

	.:acessados bit a bit
		- Acumulador (A), Registrador Auxiliar (B)
		- Registros para interrupção, Portas Paralelas
		
Tipos de Instruções
● Aritméticas (24) 				– Soma, subtração, etc. Utilizam o registrador A(Acumulador).
● Lógicas (25) 	   				– E, OU, Deslocamentos, etc. Operam bit-a-bit e geralmente utilizam o registrador A.
● Transferência ou Cópia (28)	– Movimento bytes entre registradores e RAM.
● Booleanas (17)				– Transferência, cópia, set, reset bit a bit.
● Salto (17)					– Desvio de execução ; chamada de subrotinas.

Tabelas
● Diretiva “DB” (Declare Byte) do montador copia sequência de valores diretamente para memória.
● Formato:				LABEL: DB b0 b1 b2 b3
● Na posição de memória “Label” teremos b0. Na posição LABEL+1 teremos b1, assim por diante.
● LABEL é opcional. Se não for usado, refere-se à posição atual de memória de programa.

Portas Paralelas
● O 8051 tem 4 portas paralelas (P0-P3).
● Mapeadas na área de memória (SFR).
● Acessíveis bit-a-bit.
● As portas são compartilhadas com funções próprias do 8051, da seguinte forma:
	– P0: Dados (D0 a D7) e parte baixa dos endereços (A0 a A7).
	– P1: Livre (não compartilhada).
	– P2: Parte alta dos endereços (A8 a A15).
	– P3: Sinais de controle de comunicação e interrupção
	
Contadores e Temporizadores
● Funcionalidade típica de microcontroladores.
	– Contato direto com eventos do mundo externo.
● Dois Registros de 16 bits
	– Contador / Temporizador 0
	– Contador / Temporizador 1
● Modo de contagem / temporização definido por software.
● Temporização: O sinal de entrada é 1/12 da frequência do sinal de relógio (resultando, tipicamente, em 1 Mhz. Ou seja ele conta a cada 1 microssegundo.
● Contagem: 
	- Eventos externos (Borda de descida dos pinos T0 (para contador 0) ou T1. Valores são amostrados a cada ciclo de máquina)
	










