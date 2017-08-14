telephone networks are connection-oriented (circuit switching) - precisa mexer pra onde vai nas centrais
ATM usa circuito virtual
IP is trying for QoS

3. Comunicação de dados e Representação de Sinais analógicos e digitais

qto+ bits -> +conteudo representado

Bloco = mensagem de texto, imagem jpeg (1GB = 2^30 bytes)
Stream = voz tempo real, streaming video (1kbps = 10^3 bps)

Propriedades do canal
	- largura de banda
	- atraso
	- jitter
	- perdas 
	- buffering

Atraso de transmissão - form1

Compressão = menos bits sem ruído ou ruidoso
Taxa = bits_original/bits_comprimido

CD 
	largura de banda = 22KHz
	amostra = 16b
	amostragem = 44kamostras/s

transmissor - telefone converte voz em corrente elétrica
receptor - telefone converte corrente em voz

transmissão
	Canal - cobre em par trançado, cabo coaxial, radio, luz em fibra optica, luz no ar, infravermelho
	Problemas - atenuação, distorção, ruido, interferência

Longa distância analógica (Repetidor)
	- Repetidor = amplificador + equalizador
	- Fonte - Repetidor - Repetidor - Destinatário
	- Repetidor = restaura sinal analógico à forma original, imperfeita
			  	= distorção não completamente eliminada
		  		= qualidade diminuida, pequena distância, antigo

Longa distância digital (Regenerador)
	- Repetidor digital = amplificador + equalizador + circuito de decisão e Regenerador
	- Recupera sequencia original dos dados e transmite no segmento seguinte
	- Prob. de erro pequena
	- Em relação ao analógico: menos potência, maiores distâncias, menor custo

Digitalização de um sinal analógico
	- amostrar em tempo e amplitude
	- largura de banda = velocidade de variação do sinal
		- largura alta - maior amostragem
		- taxa mínima de amostragem - 2*Ws
	- Voz: 4kHz, 8000 amostras/segundo
	- Audio: 22kHz, 44000 amostras/segundo
	- Amostragem- amostras em x(t)
	- Quantização - mapeamento das amostras
	- Compressão
	- COMO SE RELACIONA LARGURA DE BANDA COM TAXA DE AMOSTRAGEM 
	- CANAL = sistema (entra impulso sai resposta ao impulso)

Transmissão de stream
	- taxa constante(voz) ou taxa variável(vídeo)
	- atraso (entregue no tempo?), jitter (entregue suavizada?), perda (sem perda?)

Séries de Fourier
	- periódica :: f(t) = f(t + T), com isso, f(t) = f(t + nT), onde n = 0, +-1, +-2, ...
	- pra somar de frequencias diferentes ser periódica, uma sobre a outra deve ser racional

Componentes e harmônicos
	- C0 = componente de corrente direta
	- Cn = amplitude do harmônico n
	- Thetan = fase do harmônico n 

Paridade de funções
	- função par = simetria eixo vertical = f(t) = f(-t)
	- função ímpar = simetria origem = -f(t) = f(-t)
	- Se f(t) é par, não terá termos seno (ímpar), logo só terá an
	- Se f(t) é ímpar, não terá termos cosseno (par), logo só terá bn

Simetria
	- de meia onda = senos e cossenos ímpares
	- de quarto de onda
		- par = cossenos ímpares
		- ímpar = senos ímpares

Fenômeno de Gibbs
	- temos que truncar. À medida que agregamos mais harmônicos, a somatória se aproxima mais de f(t)

Espectros de frequência discreta
	- de amplitude = Cn x ômega
	- de fase = Fasen x ômega
	- uma f(t) só tem uma série de fourier
	- o eixo horizontal é um eixo de frequência (n=número de harmônico=múltiplo de ômega0)

Potência e teorema de Parseval
	- valor médio = altura do retângulo de mesma área da curva
	- faz-se pela potência média



4. Teoremas de Nyquist e Shannon

Largura de banda
	- P/ transmitir dados mais rápido, o sinal deve variar mais rápido.

Largura de banda do canal
	- Um canal tem um limite próprio da velocidade da variação dos sinais que transmite
	- É um limite do aperto que os pulsos de entrada podem ter

Problemas na transmissão
	- Atenuação do sinal, distorção, ruido Spuriols, interferência de outros sinais => limita medição 
	  do sinal recebido

Domínio da frequência
	- A saída de uma entrada sinusoidal é uma senoide de mesma frequência, com com amplitude e fase diferentes.
	- Para não ser barrado, a relação entre sinal de saida e de entrada deve ser próxima de 1.
	- Largura de banda Wc do canal é o intervalo de frequências que o canal não rejeita.

	Passa-baixas ideal
		- Apenas sinais de frequência f<Wc passam
		- Não há atenuação na amplitude, apenas um atraso
		- ex: circuito simples não ideal:
			- diferentes frequencias de entrada tem amplitude atenuadas em diferentes quantidades
			  e fases atrasadas por diferentes quantidades.

	Passa faixa
		- modems, sistemas de radio
		- largura de banda do canal é a largura da banda de frequências que passa valores de sinais de potência
		  relevantes

	Distorção do canal
		- Se resposta à amplitude não é plena, diferentes componentes de x(t) serão transferidos em quantidades
		  diferentes
		- Se resposta à fase não é plena plena, diferentes componentes de frequências de x(t) serão atrasados em 
		  diferentes quantidades
		- x(t) sempre é alterado

	Conforme se aumenta a largura de banda do canal, a saída do canal se aproxima mais ao sinal de entrada

Domínio do tempo
	- Precisa-se da resposta ao impulso h(t)
	
Conversão AD 
	- conversão analógico-digital
	- inverso é DA
	- No tempo: amostragem (período de amostragem - Ta - fa)
	- fa nos dá quantidade de amostras por segundo

Teorema de Nyquist
	- Sinais analógicos com largura de banda limitada - que contém certa gama de frequências - 
	  podem ser reconstruídos exatamente do sinal amostrado desde que a frequência de amostragem 
	  seja o dobro da maior frequência contida no sinal.
	- Aliasing: amostragem com fa menor que duas vezes a maior frequência

	Pulsos de Nyquist
		- p(t) é o pulso no receptor em resposta ao pulso de entrada
		- r(t) é a onda que aparece em resposta à sequência de pulsos
		- se s(t) é o pulso de Nyquist, então r(t) tem interferência intersimbólica (ISI)=0 
		  qdo amostrado em múltiplos T

	Sinalização Multinível
		- amostragem de nyquist: 2Wc
		- recuperação por interpolação das amostras
		- precisão do sinal amostrado depende da quantidade de níveis N=2^m que se divide a amplitude,
		  representada por m bits.

	Quantização
		- na amplitude: divisão para ser representado no computador, dada por m bits
		- delta = V/2^(m-1)
		- erro de quantização: e(t) = y(t) - x(t)
		- erro sempre entre -delta/2 e +delta/2
		- problema de m grade = pequenos erros podem ser vistos pelo quantizador como ruído
		- quanto maior o SNR, melhor a qualidade do sinal e maior a taxa de bits

	Precisão e erro de quantização
		- Escolher V como amplitude maxima do sinal não é eficiente pois poucos pulsos vão usar 
		  esse valor
		- Logo, estima-se um V cuja probabilidade de x(t) excedê-lo seja desprezível
		- SNR: taxa de sinal-ruído da quantização
		- Assim, para uma quantização uniforme o SNR aumenta 6dB por bit usado na definição dos níveis
		- A formula mostra que SNR aumenta com m

	Transmissão digital de informação analógica
		- x(t) -> amostrador AD -> Quantização -> transmissão ou armazenamento ->
		  -> gerador de pulso -> filtro de interpolação -> display playout

PCM - pulso code modulation
	- padrão de representação digital utilizado nas redes telefônicas
	- No PCM, a divisão da amplitude não é uniforme e sim logarítmica com maior espaçamento quanto 
	  maior a amplitude. 
	- Voz filtrada com passa-baixas de Wcorte = 4KHz
	- Por Nyquist, é necessário 2W = 8000 amostras/segundo e o sistema usa 8 bits
	- Assim, SNR = 6*8 - 10dB = 38dB

Limites do ruído
	- Receptor toma decisões baseado no pulso + ruido
	- taxa de erro: depende do valor relativo da amplitude do ruido e espaçamento entre níveis do sinal
	- O ruído afeta mais quanto mais níveis m usamos no sinal..

Distribuição do ruído
	- ruido termico é inevitável
	- gaussiana de probabilidade, dc=0

Probabilidade do erro
	- erro ocorre quando ruido excede certo limite
	- diminui: niveis do sinal relativo à potencia media do ruido

Capacidade do Canal de Shannon
	- se a potência de transmissão é limitada, quando M aumenta, o espaçamento entre os niveis diminui
	- a presença de ruido no receptor causa erros mais frequentes conforme M é aumentado

*M = qtd de bits para representar níveis



5. Meios de transmissão
	
Questões na transmissão de dados
	- limite da capacidade: amplitude de saída e largura dependente da distância 
							taxas de erro e sinal-ruído
	- velocidade na propagação do sinal

Meios
	Guiados (com fio): maior largura de banda, 
					   infraestrutura complexa com ductos e condutores
					   imunidade à ruído, à diafonia, são robustos fisicamente, preço
					   metálicos: par trançado ou coaxial
					   ópticos: fibra óptica
					   
					   par trançado: 
					   		gama(0-3.5 KHz), atenuação(0.2 dB/Km), atraso(50 us/km)
					   		estende-se vários Kms sem amplificação
					   		aplicação: sistema telefônico
					   		transmissões analógicas ou digitais
					   		taxas de vários Mpbs, alguns quilômetros
					   		suscetíveis à interferências e ruído
					   		no analógico: amplificadores a cada 5 ou 6 Km
					   		no digital: repetidores a cada 2 ou 3 km
					   		distância limitada
					   		banda limitada 1 MHz (ou 100 Mhz qdo 4 pares)
					   		alguns cabos:
					   			- UTP (Unshielded Twisted Pair) - conector RJ45
					   			- STP (Shielded Twisted Pair)
					   			- topologia ponto-a-ponto (máximo 100 metros)
						
					   cabo coaxial: 
					   		gama(0-500 MHz), atenuação(7 dB/Km), atraso(4 us/km)
					   		conector externa: malha de blindagem
					   		conector interno: metal sólido
					   		aplicação: sistemas telefônicos, TV a cabo e RLs
					   				   velocidades e distâncias maiores que no par trançado
					   		transmissões analógicas ou digitais
					   		no analógico: amplificadores a cada poucos Km, mais perto para frequências maiores 
					   		no digital: repetidores a cada 1 Km, mais perto para taxas maiores
					   		pode-se transmitir a até 300 Mhz por 100 Km
					   		canais usados para transmissões independentes de TV, áudio e fluxos de bits
					   		sinal só é transmitido em uma direção
					   		alguns cabos: 
					   			- 10 base 2 - conector BNC - boa blindagem à ruído - máximo de 500 metros
					   			- 10 base 5 
					   
					   fibra óptica: 
					   		gama(180-370 THz), atenuação(0.2-0.5 dB/Km), atraso(5 us/km)
					   		núcleo de vidro, diodo emissor de laser ou luz
					   		casca e núcleo de sílica
					   		pulsos convertidos em sinais elétricos (half-duplex full-duplex)
					   		taxa de 10 Mbps a 1 Gbps
					   		multimodo e monomodo
					   		distância máxima de 1 a 2 Km
					   		imune a interferências eletromagnéticas e eltromecânicas
					   		conectores: SMA, ST, SC, MIC ou FSD
					   		tecnologia atual deve permitir bandas de até 50 Tbps
					   			- a limitação prática atual é devido à conversão de sinais óticos em elétricos 
					   		baseado na refração da luz, cada raio tem um modo (multimodais)
					   		propagam luz em linha reta
					   			- monomodal: mais cara, distâncias maiores
					   		comunicação:
					   			- transmissor elétrico -> 
					   			  fonte de luz -> fibra óptica -> detector óptico -> 
					   			  receptor elétrico
					   			- Trasmissor:
					   				- interface elétrica: recebe info do usuário (vídeo, áudio, dados)
					   				- modulador (modulação): entrada do usuário -> sinal elétrico 
					   				- emissor de luz: saída elétrica -> sinal de luz
					   			- Fibra óptica
					   				- fonte de luz: diodos foto-emissores (LEDs), ammplificação da luz por radição (LASER)
					   			- Receptor
					   				- detector de luz: 
					   				- demodulador: 
					   				- interface elétrica: 
					   		permite 30 milhões de canais de TV, 50 bilhões de canais de voz
					   		multimodo: 
					   			- luz se propaga em diferentes modos ao longo do núcleo
					   			- fonte: LED
					   			- aplicação: redes locais 
					   		monomodo: 
					   			- luz se propaga em um único caminho pelo núcleo
					   			- aplicações: telefonia e CATV
					   			- sem refrações, vai praticamente em linha reta
					   		vantagens da fibra:
					   			- informação a distâncias bem maiores
					   			- imune a interfências
					   			- não sofre corrosão
					   			- mais leve
					   			- info. segura
					   			- transmissão de luz em frequências altíssimas
					   			- transmite dados a altas taxas
					   			- diâmetro, peso e perdas são menores 
					   		aplicações:
					   			- comunicação de longa distância na terra ou mar 
					   			  (dá conta de diversas chamadas telefônicas simultâneas)


	Não-guiados (sem fio): energia propagada no espaço (limitação direcional), 
						   banda limitada, 
						   infraestrutura simples com antenas e transmissores
						   usuários podem se mover
						   rádio, micro-ondas, infravermelho

					   satélites:
					   		tipos: GEO, MEO, LEO, HEO
					   		uplink: feixe da terra para satélite (alta banda)
					   		downlink: feixe do satélite para a terra (baixa banda)
					   		entre satélites

	Outros: suportes magnéticos (fitas)
			suportes ópticos: cd/dvd

Atenuação
	- varia no meio (depende da distância)
	- meio cabeado: dependência exponencial
	- meio não-cabeado: dependência logarítmica

interferência
	- eletromagnética (EMI): campos magnéticos
	- radiofrequência (RFI): transmissores de rádio, relés e comutadores, termostatos, lâmpadas fluorescentes
	- Blindagem
	- Cancelamento

Ruído
	- ??


6/7 - Codificação de Linha e controle de erro

Sinal digital
	- discreto, pulsos de voltagem descontínua
	- cada pulso: elemento do sinal

Termos:
	- unipolar: elementos so sinal com mesmo sinal (positivo=5 V; negativo=0 V)
	- polar: um estado tem sinal positivo e o outro negativo (positivo= 5 V; negativo= -5 V)
	- taxa de transmissão (R) - bps
	- duração de 1 bit = 1/R
	- taxa de modulação: taxa com que sinal muda de nível
		- medida em baud = símbolos por segundo
		- baud: elementos do sinal/ segundo
		- taxa de bits por segundo: baud x bits/símbolo
	- marca/mark (binário 1) ; espaço/space (binário 0)
	
	- taxa de dados: taxa de transmissão em bps
	- duração/ comprimento do bit: tempo gasto para transmissão de um bit
	- 

Codificação de linha
	- É o mapeamento de sequencias de informação binária no sinal digital que entra no canal
		(ex. "1" mapeia pulso +A, "0" mapeia pulso -A)
	- código é escolhido em função dos requerimentos do sistema
		- potência transmitida: consumo máximo de potência
		- temporização dos bits: transições no sinal ajudam na recuperação da temporização
		- eficência da largura de banda: transições excessivas desperdiçam largura de banda
		- conteúdo de baixas frequências: alguns canais bloqueiam baixas frequências
			- períodos longos causam quedas de sinal
			- onda não deve ter conteúdo de baixas frequências
		- detecção de erros: possui?
		- complexidade/custo: implementação vale a pena?

		Interpretação dos sinais
			- receptor: precisa saber timing (quando bit começa e quando termina)
			- fatores que atrapalham: relação sinal-ruído, taxa de transmissão, largura de banda, esquema de codificação

		Comparando esquemas de codificação
			- espectro do sinal
			- clocking
			- detecção de erros
			- interferência do sinal e imunidade ao ruído
			- custo e complexidade

		Exemplos de código de linha
			* NRZ: Non-return-to-zero (= que não sai de -5 até 0 V)
			* RZ: (= que sai de -5 à 0 V)
			- Unipolar NRZ: positivo=5 V, negativo=0 V
			- Polar NRZ: positivo= 5 V; negativo= -5 V
			- NRZ diferencial invertido: +5 ou -5V, só muda a polaridade se o sinal se repete
			- Bipolar: +5, -5 ou 0V, 0 fica em 0V sempre, 1 fica alternando entre +5 e -5V
			- Manchester NRZ: +5 ou -5V, 0 transita no meio de baixo para cima, 1 transita no meio de cima para baixo
			- Manchester diferencial NRZ: +5 ou -5, fica alternando as transições no meio entre cima-baixo e
										  baixo-cima pros dois

		Densidade espectral de potência (através da PSD)
			- suporte = potência sendo usada (= largura de banda)
			
			- Unipolar NRZ: bom suporte à baixas frequências, ruim pra altas, fecha no meio
					- alta potência média
					- strings longos de A ou 0 (conteúdo de baixas frequências)
					- simples
			- Polar NRZ: como anterior, mas com maior suporte às baixas 
					- melhor potência média (menor)
					- strings longos de A/2 ou -A/2 (conteúdo de baixas frequências)
					- simples
			- Unipolar RZ: grande range de faixa, mas pouco suporte
			- Bipolar RZ: nenhum suporte à baixas, alta nas médias mas fecha no meio
					- três nível (-A, 0, +A)
					- poucos conteúdo nas baixas frequências
					- strings longos causam perda de sincronismo pelo receptor
			- Manchester NRZ: alto range, suporte bom nas médias
					- fácil recuperação de temporização
					- usa o dobro da banda mínima
					- simples para implementar
					- usado em 10-Mbps e outros Lan

			- Diferencial (evitam erros de transposição na polaridade (tudo a partir dai fica errado!))

			-> NRZ tem alto conteúdo nas baixas frequências 
			-> Manchester tende a desperdiçar largura de banda
			-> Na PSD - máxima frequência do sinal diferente de 0 é sua largura de banda

		Taxa de modulação (baud)
			- NRZI => 1 bit = 1 usec = 1 elemento de sinal (1 elemento de sinal = 1 usec = duração do bit)
			- Manchester => 1 bit = 1 usec = 2 elementos de sinal (1 elemento de sinal = 0.5 usec = duração do bit) 
			- Baud rate = taxa com que o sinal muda

		Baud vs bit rate
			- a banda restringe os bauds (banda restringe o número de símbolos por segundo)
				(ex. canal telefônico tem 3100 Hz de banda e permite 2400 baud)
			- para aumentar taxa de bits: aumentar número de bits/símbolo
				(ex. modem usa 2400 baud com 4 bits/símbolo)

		Interpretando sinais
			- temporização dos bits
			- níveis dos símbolos

			- Fatores que afetam interpretação dos sinais:
				- razão sinal/ruído
				- taxa dados
				- largura de faixa

		Comparando esquemas
			- espectro do sinal
				- ausência de frequências altas reduz a largura de faixa
				- ausência de componente DC permite isolamento
				- potência concentrada no meio da largura de faixa
			- clocking
				- sincronismo do receptor e transmissor 
				- clock externo
				- mecanismo de sync baseado no próprio sinal
			- detecção de erro
				- pode ser incorporada ao próprio sinal codificado
			- imunidade à interferência e ruído
				- alguns códigos são melhores que os outros
			- custo e complexidade
				- taxa de bits alta = auto custo
				- alguns códigos requerem taxa de sinal mais alta que a de bits

		Controle de erro
			- transmissão digital introduz erro
			- cada aplicação depende de certo nível de confiabilidade
				- dados precisam de transferências sem erros
				- voz e vídeo toleram alguns erros
			- controle de erro é usado quando sistema de transmissão não alcança requerimentos 	da aplicação
			- o controle garante que fluxo seja transmitido com certo nível de precisão
			- 2 enfoques: error detection and retransmission (ARQ)
						  forward error corretion (FEC)

		Dado digital x sinal analógico
			- sistema de telefonia
				- largura de faixa: 300 a 3400 Hz
				- usa modem (modulador-demodulador)
			- MODULAÇÕES:
				- amplitude shift keying (ASK)
					- ASK: reto em '0', variando em '1' 
					- info representada por diferentes amplitudes
					- susceptível a mudanças bruscas no ganho ineficiente
					- até 1.2 kbps em linhas telefônicas
					- usado em fibra ótica
				- frequency shift keying (FSK)
					- BFSK: varia pouco em '0', varia muito em '1'
					- forma mais comum é o binary FSK (BFSK)
					- dois valores binários representados por 2 frequências diferentes
					- mais robusto a erros do que ASL
					- até 1.2 kbps em linhas telefônicas
					- radio de alta frequência
					- usado em LANs com cabo coaxial
					- multiple FSK: - usa mais do que duas frequências 
									- mais eficiente em termos de largura de faixa
									- menos robusto a erros
									- cada símbolo representa mais de 1 bit
				- phase shift keying (PSK)
					- BPSK: m alternando quando muda o sinal (m em cima= 1, m em baixo= 0)
					- informação é representada pela fase do sinal
					- mais comum: binary PSK (BPSK) - duas fases representam dois dígitos binários
					- differential PSK: fase é deslocada em relação a um valor anterior, e não em relação 
					  a algum sinal de referência
					- quadrature PSK (QPSK): - cada simbolo representa mais de 1 bit
									  		 - informações codificadas em em deslocamento de fases de 90 graus  
									  		 - modem 9600 bps usa 12 ângulos
					- offset QPSK: - ortogonal
								   - esquema moderno

				- performance
					- largura: ASK e PSK são diretamente relacionadas à taxa de bits, FSK é mais complicada
					- a razão de ruído (ou de erro de bits - BER) na PSK e QPSK é 3db maior que na ASM e FSK

				- Modem vs driver de linha
					- driver: apenas aplica "código de linha", como o HDB3
					- modem: faz modulação de amplitude, de frequência e de fase

				- quadrature amplitude modulation (QAM)
					- usada em modems asymmetric digital subscriber line (ADSL)
					- combina ASK com PSK
					- envia dois sinais digitais usando mesma portadora
						- uma cópia da portadora é deslocada de 90 graus
						- cada portadora é modulada com ASk

			- Cable Modem
				- downstream (8MHs), upstream (2MHs)

		Dado analógico x sinal digital
			- Conversão A/D
				- pulse code modulation (PCM)
				- delta modulation (DM)
				- ADPCM

			- digitalizando sinal analógico
				- analog data(voice) -> DIGITALIZER -> digital data -> MODULATOR -> analog data(ASK)

		Dado analógico x sinal analógico
			- por que modular sinais analógicos? 
				- maior frequência pode tornar atenuação menor 
				- permite multiplexar sinais sinais
			- tipos de modulação 
				- amplitude 
				- frequência
				- fase

			- ideias principais
				- todos os blocos de dados (codewords) satisfazem um padrão
				- se bloco não satisfaz padrão, é um erro
				- redundância: somente um cojunto de blocos possíveis podem ser codewords
				- mancha cega: quando o canal transforma um codeword em outro codeword

			- Checagem de paridade única 
				- adicionar ao final 1 bit de checagem de paridade para k bits
				- todos os codewords tem um número par de 1's (logo a paridade é sempre ímpar- porque codeword adiciona paridade)
				- o receptor checa para ver se o número de 1's é par (incluido o paridade)
					- padrões que mudam número ímpar de bits são detectados, se par não
				- bit de paridade é usado no código ASCII
				- eficiência:
					- 1 bit redundante
					- 50% de erros podem ser detectados
					- é possível identificar mais erros se adicionados mais check bits
					- na realidade, a aleatoriedade do canal implica em adicionar 1 erro em vez de 2,
					  assim a probabilidade sobe para detecção de 99.995% dos casos

					- que é um bom código? : bons códigos devem maximizar a separação entre codewords e não-codewords

			- Checagem de paridade bidimensional
				- mais bits de paridade para melhorar a abrangência
				- acomodar info como coluna
				- paridade simples a cada coluna
				- coluna final de paridade
				- 1,2 ou 3 erros são sempre detectados 
				- nem todos os com mais de 4 podem ser detectados

				- Outros detectores
					- paridade simples não detecta todos
					- bidimensionais requerem muitos bits de checagem
					- na prática são usados: Internet Check Sums, CRC Polynomial Codes
				
			- Internet Check Sum (difícil)
				- bits de checagem no cabeçalho IP
				- checksum recalculado em cada roteador
				- cada palavra de 16 bits é um inteiro:
					- x = b0 + b1 + .. + bL-1 mod 2¹⁶-1
					- bL = -x mod  2¹⁶-1
				- aritmética de complemento de 1

			- Códigos polinômicos
				- polinômios em vez de codewords
				- aritmética polinômica em vez de check sum
				- implementada com 	circuitos shift-register
				- centro dividido pelo esquerdo, dá cima e sobra baixo

				- polinômio gerador de grau = n - k, sendo k bits de informação e n o grau do código
				- residuo tem grau n -k -1
				- todos os codewords são múltiplos de g(x)! Receptor deve fazer a divisão para checar se teve erro
				- padrões não detectáveis:
					- mancha cega: se o erro ainda torna b(x) divisível por g(x)
					- deve-se escolher um bom gerador polinômico, sempre com +1 no final
					


				pol. gerador g(x)
				info i(x)
				resíduo r(x)
				código final b(x)
				quociente q(x)

				xi(x) = q(x)g(x) + r(x)
				b(x) = xi(x) + r(x) -> bits(n = k + n-k)

				








