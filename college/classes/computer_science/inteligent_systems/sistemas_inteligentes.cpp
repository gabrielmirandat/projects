deep-face = 3d face modeling with a nine-layer deep neural network.
		  = 120 million parameters.
		  = dataset: four million facial images belonging to more than 4.000 identities.
		  = usado pelo facebook!

The imitation game = li introdução.

Notas = dado em sala. Lido.

IC = inteligencia computacional.


Aula 1-1 : Sistemas Inteligentes
	- IA clássica = simbólica = lógica
		- Sistemas especialistas
		- Sistemas especialistas são programas que têm como objetivo simular o raciocínio de um profissional
	  	“expert” em alguma área de conhecimento bem específica.

Aula 1-2 : Neurônios Artificiais e Redes
	- processadores numéricos (não-simbólicos)
	- interconexões maciças alteradas pelo algoritmo de treinamento
	- PA - potencial de ação (pulso?)
	- 	soma ponderada das entradas (b - bias - peso) - entra vários x e sai um y
		função de ativação - artificial - geralmente não linear
	- Modelos
		- computacional
			- funções sigmóides (logística ou tangente hiperbólica)
		- estocástico
			- y é binário (1 ou 0)
			- probabilidade de ativação depende da soma ponderada
	- Arquiteturas
		- FeedForward (1 ou 2 camadas)
			- camadas
			- conexão de cada um com todos da camada seguinte
		- Recorrente
			- dinâmico - saídas dos neurônios se interferem na mesma camada (há retorno)
		- Competitiva
			- camada única que recebe todas as entradas (até dos vizinhos na mesma camada)
	- Aplicações
		- Reconhecimento de padrões
			- por features (pesos em tds as classes)
			- por clusters (com rede competitiva - sai só a classe certa - classificação)
		- Modelagem
			- rede aprende a representar sistema de dinâmica
		- Predição
			- relacionar valores passados e futuros

Aula 3-1 : Redes de Funções Radiais de Base (RBFs) - começou com R é essa!
	- objetivo do perceptron: adaptar parâmetros minimizando erros
	- objetivo RBF: aproximar função conhecida apenas por exemplos
		- Isto não é só interpolação?? NÃO! Queremos que o sistema exiba generalização.

	- Aqui usaremos a teoria da regularização!

	Teoria da regularização
		- sejam x entradas, d valores desejados e F(x) aproximações obtidas
		- um problema de interpolação apenas procura minimizar o erro de aproximação
		- na regularização, é incluido um termo de penalização, que penaliza funções F desnecessariamente completas, 
		  melhorando a generalização
		- D chama-se funcional estabilizador
	
	- uma solução particular deste problema é dada por uma sobreposição de gaussianas centradas nos pontos xi	
		- esta solução define um novo tipo de rede, com uma gaussiana em cada ponto

	REDE RBF: - camada escondida tem funções radias (de simetria esférica) com M neurônios
			  - o espaço de entrada é repartido entre neurônios da camada escondida
			  - problema linearizado em cada sub-região
			  - a saída é uma simples transformação linear
			  - inclui bias
			  - M+1 parâmetros a determinar
			  - Com N>M exemplos, é um problema sobre-determinado
			  - solução via pseudo-inversa
			  - melhor solução: mínimos quadrados

	Comparando MLP com RBF
		- Camada escondida única, camada escondida tem modelo unico, função de ativação empregada a partir da norma
		  euclidiana, aproximações locais, representação localizada na entrada

	Determinação dos centros
		- centros fixos e aleatoriamente escolhidos a partir de exemplos
		- escolha do desvio da gaussiana dado por fórmula
		- em geral, exige muitos centros para bom desempenho
		- auto-organização dos centros: - a partir da distribuição dos exemplos, são definidos clusters onde devem estar os centros
										- algoritmo: mapa de kohonen
		- aprendizado dos centros: após a determinação inicial dos centros, todos os parâmetros da rede (centros, variâncias, pesos)
								   são ajustados por descida de gradiente
		- espaço de parâmetros é não convexo: problema de mínimos locais 

	- resultados mistos	na literatura: melhoria ou não em relação aos centros fixos

Aula 4-1 : Mapas auto-organizáveis (SOM)

	- ideia da auto-organização: - hipótese do professor é irreal (de que o aprendizado é supervisionado)
								 - sistema biológico organiza-se apenas de interações locais, em todos os níveis (celular, orgânico, "social")
								 - exposição à estimulos, por si só, deve gerar organização para processamento (cortex auditivo, visual, 
								 																				mapa somatotópico)

	- mapa somatotópico
		- veja a manutenção da vizianhança topológica
		- notável a importância da mão e dedos (principalmente polegar) e língua

	- características de um mapa de neurônios auto-organizado
		- cada neurônio se especializa em uma região específica do espaço de características (feature space)
			- pontos distantes no espaço de entrada com características semelhantes são tratados por um mesmo conjunto de neurônios
			- neurônios vizinhos espacialmente tratam de padrões vizinhos no feature space

	Rede de Kohonen ou SOM (MAPA AUTO-ORGANIZADO)
		- camada única
		- conexões laterais inibitórias
			- implementadas como "competição" entre neurônios
			- neurônio de maior saída "inibe" os vizinhos
		- rede "sem saída"
			- interessa-nos a distribuição de vetores de pesos
		- topologia e vizinhança arbitrárias 
			- projeção em um mapa de fácil leitura (2D)
		
		- treinamento
			- pesos iniciais aleatórios e de mesmo módulo
			- apresenta-se a entrada x 
			- neurônios computam suas saídas => y = w . x
			- neurônio de maior saída é o vencedor (v)
			- neurônio v e uma vizianhaça atualizam seus pesos de acordo com fórmula
			- pesos são re-normalizados
			- raio da vizinhança diminui ao longo do tempo
				- inicia-se com um valor que inclui quase toda a rede
				- constante de aprendizado diminui com o tempo
			- atualização inclina o peso sináptico vencedor (e vizinhos) na direção do vetor de entrada

			ex: - dados uniformemente distribuídos no plano 
				- 5 neurônios
				- vizinhança mono-dimensional
				- valores iniciais aleatórios
				- apresenta-se um dado: neurônio 2 é o vencedor
					- supomos que vizinhança inclui neurônios 1 e 3
					- neurônios 2,1 e 3 vão alterar pesos-
					- pesos do vencedor e vizinho tendem a se aproximar da entrada
				- com a continuidade do processo, os pesos tendem a se distribuir pelo espaço, 
				  respeitando a condição imposta de vizinhança

	Propriedades do SOM
		- ao final, os vetores sinápticos formam uma boa codificação do espaço de entrada (quantização vetorial)
		- a posição dos neurônios no mapa representa regiões do espaço de entrada (ordenamento  tolológico)
		- variações de densidade no posicionamento dos neurônios refletem variações de densidade no espaço de entrada (preservação de densidade)
		- o mapa representa a melhor projeção possível dos dados na dimensão disponível (seleção de características)

	Exemplos de mapas
		-> mapa de animais: nome do animal e seus atributos
			- representado por um vetor binários em que cada posição representa se tem ou não alguma característica, qual animal é, ..
			- atributos simples, é pequeno? Tem 2 patas? Tem pelo?
			- gerado mapa bidimensional - neurônio com maior resposta (para o bit de identificação apenas)
			- observada classificação natural, por proximidade, entere mamíferos e aves

		-> mapa semântico
			- vocabulário de 30 palavras, cada representada por vetor aleatório de 7 posições
			- pares de palavras apresentadas ao mapa, seguindo um dos padrões de sentenças
			- resultados: classes morfológicas separadas
			- proximidade intra-classes, run perto de walk, buys perto de sells, hates perto de likes, fast perto de slowly..

		-> sensor de posição
			- a rede aprende vizinhança, mas não sentido
			
		-> classificação
			- a auto-organização por si só pode resultar em grupos correspondentes às diferentes classes
			- faltaria apenas um trabalho de rotulação
			- para cada neurônio, qual a classe a cujos exemplos ele responde melhor
			
		-> Algoritmo LVQ (Learning Vector Quantization)
			- se a simples separação geométrica dos padrões não for suficiente, pode-se usar técnica de treinamento supervisionado
			  e aprender quais as melhores posições para os vetores sinápticos
			- algoritmo 
				- apresenta-se exemplo. Encontra-se o neurônio vencedor (c)
				- se c for rotulado com a classe correta do exemplo, aproxima-se exemplo e vetor, cc, afasta exemplo e vetor
				- a taxa de aprendizado deve diminuir com n
				- a taxa já começa menor do que a usada na formação do mapa 
					- queremos um ajuste fino no mapa, não redefiní-lo


Aula 5-1 : Construindo a rede convolucional profunda

	Entrada por campo receptivo
		- entrada organizada em disposição 2D de 28x28 pixels (imagem)
		- cada neurônio da camada escondida recebe um campo de 5x5 pixels. Há 26 pesos (25 + bias) conectando os pixels de entrada
		  ao neurônio da camada escondida

	Deslocamentos dos campos receptivos
		- No exemplo, neurônio escondido vizinho à direita recebe um campo 5x5 deslocado de um pixel à direita
		- se a imagem era 28x28, a camada escondida terá 24x24 (sliding window 1 em 1)
		- compartilhamento de pesos: estes pesos serão os mesmos para todos os neurônios da camada escondida!
			- cada campo receptivo aprenderá a identificar a mesma característica, em diferentes posições da imagem. 
			  Isto será chamado um "Mapa de características"

	Múltiplos mapas de características
		- No exemplo, há 3 mapas de características (3 x 24 x 24)
		- Cada mapa aprenderá uma característica diferente
			- Cada mapa tem mesmos pesos diferentes
			- pesos em escalas de cinza: branco(muito negativo), preto(muito positivo) 


	Camadas de pooling (aglutinação)
		- aglutinam informações dos mapas de características
		- no max-pooling: saída é o máximo da ativação dos quatro neurônios 
		- se a primeira escondida era 24x24, o mapa aglutinado é 12x12 (sliding window 4 em 4)
		- um mapa aglutinado para cada feature map
		- L2 POOLING: toma-se a raiz quadrada da soma dos quadrados das ativações na região aglutinada	
	
	Última camada
		- interconexão total entre mapas reduzidos e neurônios de saída (1 para cada classe)
	

	------------------------------------------------------------------------------------------------------------------------

	Redes de funções radias de Base (que usam regularização)
	-> objetivo: aproximar função conhecida apenas por exemplos, não apenas otimizar desempenho da rede como perceptron
	-> queremos sistema generalizado = teoria da regularização
	-> não é só um problema de interpolação (que procura apenas minimizar o erro de aproximação)
	-> a regularização penaliza aproximações obtidas muito complexas
	-> solução disso: sobrepor gaussianas centradas nos exemplos ('REDE RBF')
	('RBF')
		-> camada escondida têm funções de ativação radiais - gaussianas - (de simetria esférica) com M neurônios
		-> entrada repartidos entre neurônios da camada escondida
		-> problema linearizado em cada sub-região
		-> a saída é uma simples transformação linear, que inclui bias e M+1 parâmetros a determinar
		-> Com N>M exemplos, é um problema sobredeterminado, cuja solução é via pseudo-inversa
	('Solução')
		-> seja Y a matriz de saída da camada escondida para todos os exemplos
		-> Queremos Yw = d, sendo d = valores desejados de cada exemplo
		-> a melhor solução é por mínimos quadrados
	('Muito exemplo..deve cair na prova')
	('Em relação ao perceptron')
		-> camada escondida tem de ser única, com modelo único
		-> função de ativação a partir de norma euclidiana, enquanto que Perceptron é produto interno
		-> Aproximações locais
		-> entrada localizada
	('Centros')
		-> são fixos, escolhidos aleatoriamente das entradas
		-> função sigma sugerida para boa sobreposição dos centros
		-> quanto mais centros melhor o desempenho
		-> centros auto-organizáveis: a partir da distribuição dos exemplos, clusters são definidos onde devem estar os centros
			-> Através de Mapa de Kohonen
		-> após chute de centro inicial, todos os parâmetros da rede são ajustados por descida de gradiente (centros, variâncias, pesos)
		-> espaço para centros e variâncias não-convexo -> mínimos locais
		-> alguns reportam melhoria com centros fixos, outros não

	------------------------------------------------------------------------------------------------------------------------

	Mapas de neurônios auto-organizáveis (aprendizado não-supervisionado)
	-> aprendizado supervisionado é "irreal"
	-> sistema organiza-se apenas por interações locais
	-> estímulos são suficientes para gerar organização
	('O mapa')
		-> neurônios especializados no espaço de características
		-> mesmo conjunto de neurônios tratam entradas de características semelhantes relevantes (independe da ordem da entrada)
		-> neurônios vizinhos espacialmente tratam padrões semelhantes no espaço de características
	('Kohonen ou SOM')
		-> camada única
		-> conexões laterias se inibem
			-> neurônio mais forte inibe saída dos vizinhos
		-> interesse final: distribuição dos vetores pesos
		-> topologia inicial: vizinhança arbitrária em mapa 2D
		-> wi é a distribuição dos dados da entrada
	('Treinamento')
		-> wi inicias aleatórios e de mesmo módulo
		-> x é mostrado, neurônios computam saída, neurônio mais forte vence (v), neurônio v e vizinhança atualizam pesos, normalizados
		-> raio de vizinhança diminui com tempo (primeiro inclui quase toda a rede)
		-> constante de aprendizado diminui com tempo
		-> atualização inclina peso sináptico vencedor e dos vizinhos na direção do vetor de entrada
		-> ao final, vetores sinápticos codificam bem espaço de entrada
		-> posições dos neurônios no mapa representam regiões do espaço de entrada
		-> variações de densidade espacial dos neurônios refletem variações de densidade espacial da entrada
		-> melhor projeção possível dos dados na dimensão disponível
	('Uso em classificação')
		-> auto-organização gera por si só grupos de diferentes classes 
		-> falta apenas a rotulação: para qual classe o neurônio responde melhor?
	('LQV') - learning vector quantization
		-> se SOM não suficiente, treinamento supervisionado para melhorar posição dos vetores sinápticos
		-> modificar posição dos vetores para minimizar o erro nas fronteiras
		-> apresenta exemplo, encontra neurônio vencedor (c)
		-> se c rotulado na classe correta, aproxima exemplo e vetor, caso contrário, afasta exemplo e vetor
		-> taxa de aprendizado diminui com tempo deve começar menor que a a última usada no mapa
		-> objetivo: apenas fazer ajuste fino do mapa já criado com SOM

------------------------------------------------------------------------------------------------------------------------

	Rede Convolucional (ou profunda - deep learning)
	-> entradas 2d (28x28)
	('camada escondida')	
		-> cada neurônio da escondida recebe função de janela (5x5) da entrada, sendo 26 pesos (bias)
		-> deslocamento 1a1 
		-> pesos idênticos por janelas (diferentes por mapas)
		-> os neurônios de um mesmo mapa aprendem a mesma característica em diferentes posições da imagem
		-> mapas diferentes aprendem características diferentes
		-> camada escondida com (24x24) = mapa de características
	('camada pooling')	
		-> aglutinam informações do mapa de características
		-> max-pooling: máximo entre 4 neurônios (4x4)
		-> l2 pooling: raiz da soma dos quadrados (pitágoras)
		-> deslocamento de 4a4
		-> camada de pooling com (12x12)
		-> uma para cada mapa de características
	('camada final')
		-> interconexão total entre pooling e quantidade de classes (igual do perceptron)

------------------------------------------------------------------------------------------------------------------------

	Aprendizado por Reforço (Reinforcement Learning - RL)
	-> Agente(ações) x Ambiente(recompensa, estados)
	-> Navegação, Marcha, Exploração de ambiente, Desenvolvimento de estratégias
	-> Estado = conj. mínimo de variáveis com informações do histórico do agente
			  = propriedade markoviana - prob de transitar depende do estado e ação atuais
	// -> Markoviana = prob de chegar no estado s' e receber r de recompensa
	-> Policy = mapeamento enter estados e ações
			  = construída ou adapatado a partir do histórico de recompensas recebidas
			  = (BANDO DE SETAS)
	-> Reward function = recompensa de cada estado (ou estado-ação)
					   = agente não conhece, mas deve usar para mudar política
					   = o agente quer maximizar a função de retorno
					   = Em tarefas de horizonte longo (usual), temos retorno com DESCONTO
	-> Value function = média das recompensas futuras a partir do estado atual
					  = preocupa-se com longo prazo
					  = se determinada, RL está resolvido					   					   
					  = algoritmos RL tentarão estimar esta função
					  = depende da política
					  = valor esperado da reward function com desconto seguindo política em s
					  = valor de AÇÃO - valor esperado da reward function com desconto seguindo política tomando a em s
					  = MÉTODOS
					  	= Monte Carlo - agente guarda média dos retornos após cada estado e ação
					  	= Aproximação parametrizada - agente mantém estimativas de values functions e as adapta para concordarem 
					  								  com a experiência
					  = (BANDO DE VALORES)
    -> Eq. de Bellman = o valor do estado é media dos valores de outros estados ponderados pelas probabilidades de 
    				  = serem alcançados de com a política e somadas recompensas de transição 
    				  = política aleatória -> mapa de valor
    				  = política ótima - função de valor maior ou igual em todas as posições
    				  = política gulosa (só importa com recompensa atual) na função de valor ótima é ótima
    				  = Impraticabilidade de eq. de Bellman
    				  	- pressupõe cond. markoviana
    				  	- necessita alto poder computacional
    				  	- conhecimento perfeito das probabilidades de transição
    				  	- Os métodos que estudaremos tentam estimar o valor das ações a partir da experiência
    -> Programação dinâmica = tenta achar política ótima
    						= supõe conhecimento de todo o ambiente
    						= sem Bellman, métodos iterativos
    						= começa com valores zero
    						= iterações de Bellman até a convergência
    						= calculado value function da política atual, quando parar de mudar a política?
    							- quando a política gulosa parar de mudar
    -> Monte Carlo = aleatoriedade tem papel preponderante
    			   = estimar value function da experiência
    			   = aprendizado dividido em episódios
    			   = experiência do episódio usada para melhorar value function
    			   = método primeira vista - médio dos retornos obtidos no estado
    			   = mesma estratégia da programação dinâmica
    			   		- problema de inícios exploratórios
    			   		- on-policy: melhorar política da experiência de seguir esta mesma política
    			   		- off-policy: melhorar política gulosa com experiência de outra política (E-gulosa)
    			   = pode ter episódios muitos longos, aprendizado ruidoso..
    -> Diferença temporal = também em episódios
    					  = converge mais rápido que MC
    					  = método on-policy (SARSA) e off-policy (Q-Learning)
    					  = SARSA - tenta estimar Q da política atualmente seguida
    					  = Q-Learning - tenta achar Q de cada estado, estimando assim diretamente o Q da 
    					  			   - política ótima

------------------------------------------------------------------------------------------------------------------------

INTRO
agente: elemento que define ações
ações: maximizar RECOMPENSAS TOTAIS (longo prazo)
estado: variáveis de histórico do agente
política: mapeia ações em estados. Adaptada do histórico de recompensas
f. de recompensa: p/ cada estado (ou par estado-ação) o ambiente retorna um valor de recompensa
				: agente não controla, mas muda política através dela
f. de valor: média das recompensas futuras a partir do estado atual
		   : aspecto longo prazo
		   : ela que é tentada ser estimada pelos algoritmos de RL (tê-la resolve o problema)
		   DE ESTADO => v(s)
		   : definido sob política
		   : é a média de uma 'função de retorno' COM DESCONTO em uma dada política pi num dado estado s,
		     sendo a função de desconto por definição função de todas as recompensas futuras
		   DE AÇÃO => q(s,a) - defini-la resolve o problema por completo
		   : definido sob política
		   : é a média de uma função de retorno COM DESCONTO em uma dada política pi num dado estado s tomada uma dada 
		     ação a, sendo a função de desconto por definição função de todas as recompensas futuras
		   EQ. DE BELLMAN 
		   : nada mais é que outra forma de se escrever a f. de valor de estado ou de ação
		   : substitui o termo esperança pela definição com somatórias (mais viável na computação)
		   : é a somatória na ação a dada uma política definida em a para um estado s multiplicada pela somatória
		   	 no estado s futuro da probabilidade de transição markoviana multiplicada pela função recompensa média markoviana 
		   	 somada com a f. de valor do estado futuro definida na política pi descontada
		   : o valor de um estado é uma média dos valores de outros estados (ponderada pelas probabilidades de os alcançarmos 
		   	 seguindo a política pi) somada a recompensa da transição! BEM FÁCIL
		   : se r e p são completamente conhecidos (irrealista), achamos a f. de valor de estado. 
		   MÉTODOS: 
		   	- MONTE CARLO
		   	  : guarda média dos retornos obtidos após visitar cada estado e tomar cada ação. Com um longo histórico, 
		   	    a média deve tender às funções de valor
		   	  : é a própria fórmula da f. de valor de estado ná prática, só que com experiência. 
		   	  : só vai se aproximar bem se o agente alcançar muitos estados diferentes
		   	- APROXIMAÇÃO PARAMETRIZADA
		   	  : mantém parâmetros que definem estimativas de funções de valor, e os adapta para 
		   	  : concordarem com a experiência
		   	- PROGRAMAÇÂO DINÂMICA
		   	  : markoviana. 
		   	  : método para determinar política ótima, com modelo perfeito do ambiente.
		   	  : evitam solução explítica das equações de Bellman usando métodos iterativos.
		   	  : determina funções de valor sem resolver equações de Bellman
		   	  : calculando o valor v sob uma política, quando sabemos se devemos mudar a política?
		   	  	- calcular, a cada estado, a política gulosa de acordo com a função valor recém-calculada.
		   	  	  Se for diferente do prescrito pela política atual, modificá-la.
		   	  	- avalia v na política atual; verifica se v pode ser melhorada, em cada estado, por uma 
		   	  	  política gulosa; repete a operação até a convergência
		   	- MONTE CARLO
			  : aleatoriedade tem papel preponderante
			  : estimam função de valor a partir de experiência
			  	- aprendizado dividido em episódios: a cada período, experiência adquirida pelo agente é usada
			      no melhoramento de estimativas de valor
			    - computa média das f. de retorno obtidas cada vez que um estado é visitado, só contando a PRIMEIRA VISITA
  				  ao estado. A cada estado alcançado, o vetor de retorno aumenta em 1 unidade e a nova média é computada.
  			  : também serve para estimar q. O que muda é: fazer média dos retornos obtidos quando se visitou o estado s
  			    e tomou-se a ação a. O problema é garantir que todos os estados e ações relevantes sejam visitados.
  			    - mesma estratégia da Programação Dinâmica. Uma iteração de melhoramento de V alternada com uma melhoria de 
  			      política (mudar se existe ação melhor segundo o novo V).
  			    - inícios exploradores a cada episódio 
  			    - estratégia E-gulosa para melhoramento de política: é mais suave que a gulosa, atribui melhor estimativa 
  			      atual de valor ou uma ação aleatória com probabilidade E.
  			- TD
  			  : define nova função de valor
  			  : toma ação e observe f. de retorno. Atualiza f. de valor com nova equação
  			  : também com episódios. Converge mais rápido que MC.
  			  : é sem modelo do ambiente, precisa de Q(s,a) - controle - , não V(s) - predição.
  			  : atualiza política como MC.
  			  SARSA (ON-POLICY)
  			  	: fórmula louca para Q assim como a de V
  			  	: Para isso precisamos, a partir de um dado estado atual, tomar uma ação, verificar a recompensa e
  			  	  o novo estado, e escolher a ação no novo estado pela mesma política.
  			  	: O algoritmo então precisa dos valores S,A,R,S,A, de onde vem o seu nome.
  			  		- estado, ação, retorno, estado futuro, ação futura
  			  	: trabalho 3- SARSA é ótima, MC fica em loop infinito
			  Q-LEARNING (OFF-POLICY)
  			  	: A ideia do Q-Learning é estimar diretamente o melhor valor Q de cada estado, estimando assim
				  diretamente o Q da política ótima.

------------------------------------------------------------------------------------------------------------------------
-----------> Sistemas fuzzy

- Sistema Baseado em Regras
- Conjuntos Nebulosos
- Operadores
- Base de Regras Nebulosas

info - fatos - regras - motor de inferência - decisão

ORIGEM: dificuldade de inferir certas quantidades (homem alto se altura > ?; homem calvo se cabelo > ?)

CONJ. NEBULOSO: sistematizar termos vagos
LÓGICA FUZZY

A teoria dos conjuntos é isomórfica à álgebra booleana (e à lógica de proposicional).

CONJUNTO = LÓGICA
pertinência = valor-verdade
união = OU
interseção = E
complemento = NÃO

Nebulização -> desnebulização

REGRA: Se febre E fatos e dorDeCabeça E fatos então aumenteP(Gripe)
antecedente: febre E fatos e dorDeCabeça E fatos
consequente: aumenteP(Gripe)

MOTOR: procura regras aplicáveis a fatos conhecidos
	   infere novos fatos e toma decisões

----------->] Algorítmos genéticos

- Inspirado em seleção natural
- soluções geradas aleatoriamente, combinadas, modificadas e selecionadas por um critério de desempenho

Origem das espécies
- Observações não favorecem a idéia de um projeto com um objetivo.
-  Seres hoje vivos são descendentes de seres que viveram o bastante para gerar descendentes.
-  Características dos seres são passadas para a prole por um método de cópia sujeito a erros.
- Erros são aleatórios, mas a seleção não é!

SELEÇÃO NATURAL
+ Apesar de envolver elementos aleatórios, não é guiado por tentativa e erro.
+ Múltiplas “soluções” são testadas em paralelo.
+ Não é preciso especificar métodos, apenas avaliar o resultado final.

CROMOSSOMO
	- lista de parâmetros que codificam uma solução proposta
	- que descrevem a forma de um objeto 
	- instruções de um programa de computador
	- parâmetros de uma política em RL

ANALOGIA: CROMOSSOMO = INDIVÍDUO

FITNESS: 
	- função que avalia indivíduo e lhe atribui valor numérico
	- é subjetiva (qualquer uma serve)
	- sem treino, roda e vê resultado
SELEÇÃO: 
	- define como são escolhidos os cromossomos que participam da geração de novos cromossomos
	- primeiro método: prob. de seleção é proporcional à adequação(ou FITNESS) numa ("roleta") de probabilidades

NOVA GERAÇÃO: 
	- selecionado PAR de cromossomos pela seleção, ele gera novo par com possíveis alterações dadas por CROSS-OVER ou MUTAÇÃO
	- novos pares são selecionados novamente até a nova geração ficar completa
	- elitismo: as melhores soluções de uma geração são mantidas para a geração seguinte
		- impede perda de boas soluções pelos operadores cross-over e mutação
	- critério de parada: 1) solução atende especificações
						  2) número máximo de gerações 
						  3) adequação não melhorou bem nas duas últimas gerações

CROSS-OVER
	- prob. Pc de ocorrer cruzamento de material genético na produção da descendência (tipo 3 bloquinhos entre o par)
	- com 1 - Pc a descendência é idêntica aos pais

MUTAÇÃO
	- prob. Pm de um elemento do cromossomo sofrer uma modificação aleatória


VARIANTES SELEÇÃO:
	- ELITISMO: O melhor indivíduo sempre faz parte da geração seguinte.
	- ESTOCÁSTICA SEM REPOSIÇÃO (VALOR ESPERADO)
	- DETERMINISTICA
	- ESTOCÁSTICA DE RESTOS COM REPOSIÇÃO
	- ESTOCÁSTICA DE RESTOS SEM REPOSIÇÃO
	- TORNEIO ESTOCÁSTICO

OTIMIZAÇÃO MULTI-OBJETIVO:
	- para identificar boa solução
	- DOMINÂNCIA
	- Uma solução X domina uma solução Y se X é pelo menos tão boa quanto Y em qualquer critério, e é melhor que Y em pelo menos 1.
	










