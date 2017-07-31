1. Medidas DC (14/09)
2. Medidas AC (21/09)
3. Análise de circuitos resistivos (28/09)
4. Princípio da sup erp osição (05/10)
5. Teorema de Norton e de Thévenin (05/10)
6. Capacitor e Indutor (19/10)
7. Circuitos RC e RL (09/11 - 16/11)
8. Circuitos RLC (23/11)
9. Análise fasorial de circuitos RLC (30/11)

Sugestões de programas de simulação de circuitos:
DoCircuits (homepage),
CircuitLab (homepage),
simulador Tektronix (simula o osciloscópio),
Circuit Maker,
Solve Elec,
EveryCircuit (Android/iOS),
Proteus,
Pspice,
Icircuit (Android/iOS),
Circuit Simulator,
NI MultiSim,
Electronic Workbench (EWB).


#PLANO DE ENSINO
-> Experimento em grupo
   Avaliação Individual
-> Pré-relatório(individual) e relatório(grupo)
-> Pontuação:
		* Pré-relatório completo e no prazo (1 ponto)
		* Apresentação e organização (1 ponto)
		* Simulações (2 pontos)
		* Cálculos teóricos (2 pontos)
		* Procedimento experimental (2 pontos)
		* Resposta às perguntas e análises (2 pontos)

-> Pré-relatório
	- Todos os itens pedidos no roteiro do experimento que não sejam de caráter prático como, por exemplo, cálculos teóricos e simulações computacionais.
	- Individual e feito a mão (resultados de simulação impressos e anexados ao documento).
	- Deve ser anexado ao relatório do grupo e entregue juntamente ao relatório. 
	- Pré-relatórios entregues sem a rubrica do professor não serão considerados.

-> Relatório
	- Os alunos completarão seus relatórios à mão.
	- Deverá apresentar os resultados da parte prática, uma análise comparativa com os resultados teóricos e simulados, e respostas às questões do roteiro.
	- O relatório (um por grupo) deverá ser 'feito em aula' e será aceito se e somente se for entregue até o final do dia correspondente à realização do 
	  experimento (juntamente com o pré-relatório anexado de cada um dos integrantes do grupo).
	  
-> Registro na plataforma Piazza também poderá ser feito através do link (piazza.com/unb.br/fall2015/167011).
-> Página principal do curso pode ser acessada através do link (piazza.com/unb.br/fall2015/167011/home).

#MANUAL DOS EQUIPAMENTOS

- Equipamentos

#MULTIMETRO
-> 1.1.1 Medindo tensão
	- DC (direct current) constante no tempo ou 
	  AC (alternate current), variante no tempo.
	
	- V~  = tensão alternada		//multimetro mostra valor RMS
	  V== = tensão contínua			//multimetro mostra valor médio
	  //APENAS PARA ONDAS SENOIDAIS COM FREQUENCIAS ATÉ 5 KHz e para ondas quadradas com frequência até 200 KHz E MESMO ASSIM COM ERROS DE 6% A 8% 
	  //Quando o MULTIMETRO for usado como VOLTIMETRO, ele deve sempre ser ligado em paralelo com o componente sobre o qual se deseja medir a diferença de 
	  //potencial (tensão).
1.1.2 Medindo corrente
	- A~  = corrente alternada		//multimetro mostra valor RMS
	  A== = corrente contínua		//multimetro mostra valor médio
1.1.3 Medindo resistência
	- Com multímetro. 
	- NUNCA UM COMPONENTE DEVE TER SUA RESISTÊNCIA MEDIDA QUANDO ESTE ESTIVER CONECTADO A UMA FONTE DE TENSÃO, A UM CIRCUITO OU A QUALQUER OUTRO ELEMENTO.
1.1.4 Medindo continuidade
	- P/ saber se componenete está funcionando corretamente.
	-> RESISTENCIA
		- BIP do multímetro = resistência ZERO (curto).
		- Se resistência infinita (circuito-aberto), não tem como saber.
	-> CAPACITOR
		- BIP do multímetro = queimado ou curto-circuitado.
	- teste deve ser efetuado apenas se o componente estiver desconectado DE OUTROS COMPONENTES.
1.1.5 Medindo capacitância
	- O multimetro pode ser usado para medir a capacitância de um componente. 
	
#FONTE DE TENSÃO
1.2.1 Ajustando a tensão
	- Capaz de fornecer duas tensões diferentes pois ela possui dois geradores de tensão DC independentes com capacidade máxima de 15V cada.
	- Utilizar as duas fontes ao mesmo tempo em um mesmo circuito cria-se um problema de referencia de tensão e isso pode fazer o circuito não funcionar 
	  corretamente ou até mesmo queimar os componentes e as fontes.
1.2.2 Ligação entre as FONTES 1 e 2
	- Para esta fonte os terminais pretos estão conectados. Isso significa que ambos possuem o mesmo potencial SEMPRE. Ela foi construída desta forma para 
	  permitir alcançar valores de tensão maiores que 15V. A ideia é usar a FONTE 1 e a FONTE 2 em série. Como cada uma delas é capaz de fornecer 15V então
	  em série elas podem fornecer 30V. 
	- SÉRIE => interconectar os terminais pretos.
1.2.3 Referência de tensão
	- Geralmente usa-se o valor de Zero Volts para esse fim. Portanto, TODO CIRCUITO DEVE TER UMA REFERENCIA DE TENSÃO. As fontes de tensão geralmente vêm com
      um terminal indicando o valor zero. Isso significa que essa é a sua referencia de Zero volts.
	- Lembrando que o gerador de sinal também é uma fonte e deve ter sua referencia unida à referencia das outras fontes do  circuito.

#GERADOR DE SINAL
1.3.1 As três variáveis de um sinal AC
	- Tipo de onda= senoidais, quadradas ou triângulares.
					botão WAVE do gerador de sinais. Ele alterna entre os três formatos.
	- Amplitude	  = medida de afastamento máximo com relação à posição de equilíbrio de um sinal.
					medida VPP (valor pico a pico) -> Ele mede a distância entre o valor máximo e o valor mínimo de um sinal oscilante. Para ondas simétricas
													  ele é justamente o dobro da amplitude conforme ilustra a figura 12
					alterado de 2 maneiras.
					o valor que aparece no mostrador É O DA AMPLITUDE E NÃO O VALOR DE PICO A PICO.
	- Frequência  = alterado de 2 maneiras.
	-> Outros botões do gerador de sinal: 
			RUN: quando pressionado faz o gerador de sinal mostrar o valor da frequência e a amplitude da onda que esta sendo gerada. ELE DEVE SER	
				 PRESSIONADO TODA VEZ QUE FOR FEITA ALGUMA MODIFICAÇÃO EM UMA DAS TRÊS VARIÁVEIS DA ONDA (tipo da onda – WAVE, frequência -RANGE ou FADJ 
				 ou amplitude – ATT ou	AADJ).
	
#OSCILOSCÓPIO
1.4.1 Função de um Osciloscópio
	- O osciloscópio é uma ferramenta de análise de tensão. Ele permite visualizar o formato da onda de um determinado sinal.
1.4.3 Canais de entrada de sinais
	- Para se medir um sinal no osciloscópio primeiro é preciso fornecer tal sinal para o osciloscópio. Para tanto existem dois canais de entrada. É nesses 
	  canais que se deve introduzir o sinal de tensão cujo comportamento deseja-se analisar. Portanto esse osciloscópio permite a visualização simultânea de
	  dois sinais. 
1.4.4 Ajuste da escala de tensão
	- Se CH é 5.0 volts isso significa que a distancia entre cada linha pontilhada é de 5 volts.
	- fato de que o osciloscópio possui um erro em suas medidas. Para reduzir ao máximo esse erro de leitura a onda deve ocupar a ÀREA MÁXIMA DO GRÁFICO 
	  sem deixar nenhuma parte da onda cortada.  
	- Entrada MATH : Depois de pressionado deve-se escolher a operação (estão disponíveis apenas as operações de soma, subtração, multiplicação e FFT das 
	  entradas 1 e 2), as origens dos operandos (em que ordem os canais devem ser operados) e a inversão ou não da resposta.
1.4.5 Ajuste do disparo (Trigger)
	- A fim de evitar que a onda mostrada no osciloscópio fique se movimentando e sua visualização fique prejudicada existe uma ferramenta nos osciloscópios
      que permite ajustar qual ponto da onda passará “sempre” pelo ponto de referência de zero de tensão.
	-> Botão menu = qual o ponto da onda deve passar pela referência deve-se definir qual dos canais será usado como FONTE para o disparo.
	-> Botão de nível (Level) = ponto da onda passará pela referência de zero do tempo.
1.4.6 Cursores para medição precisa de valores
	- CURSORES = para precisão das medidas.
1.4.7 Função MEDIÇÂO
	- permite escolher quais dos parâmetros das ondas serão exibidos na tela.  
1.4.8 Salvando imagens
	- O osciloscópio permite salvar ou até mesmo imprimir as imagens diretamente da tela. Para isso existe uma porta USB que pode ser diretamente conectada 
	em um computador.  

#RESISTORES
- Observe que há algumas faixas de cores envolta dos resistores. O valor da resistência do resistor é especificado por essas faixas de cores que seguem um 
  determinado código. Os resistores existentes no mercado se dividem em quatro grupos: com 3, 4, 5 ou 6 faixas.
1.5.1 Resistores com quatro faixas:
	- Observando um resistor de 4 faixas, pode-se ver que uma das cores das extremidades é quase sempre da cor prata ou ouro. Essa é a quarta cor. A quarta 
	  cor indica a tolerância do resistor (1% para a cor marrom, 2% para a cor vermelha, 5% para a cor dourada e 10% para a cor prata). As outras três indicam
	  o valor da resistência. Segundo a convenção, a primeira cor indica o valor do primeiro algarismo, a segunda cor indica o valor do segundo algarismo e a 
	  terceira indica o número de zeros que seguem os dois primeiros algarismos.
	- COR 1 = 1º ALGARISMO
	- COR 2 = 2º ALGARISMO
	- COR 3 = QTD DE ZEROS
	- COR 4 = TOLERÂNCIA
1.5.2 Resistores com 5 faixas:
	- A terceira faixa agora se refere ao terceiro algarismo significativo.
	
#INDUTORES
- Indutores são elementos armazenadores de energia.
- Diferentemente do resistor ôhmico seus parâmetros dependem do tempo. 

#CAPACITORES
- Um capacitor é um elemento armazenador de energia e seus parâmetros dependem do tempo, assim como em um indutor. 
- Um capacitor é composto por duas placas feitas de material condutor separadas por um isolante. 
	- Capacitor Cerâmico
		- Esse capacitor não tem polaridade.
	- Capacitor Eletrolítico
		- levados de capacitância do que os capacitores cerâmicos. Um aspecto importante dos capacitores eletrolíticos é sua polaridade.

#PROTOBOARD
- A vantagem de se utilizar uma protoboard é a facilidade de inserção de componentes, uma vez que a soldagem não é necessária.
- Linhas horizontais = nós (mesmo potencial)
1.8.1 Circuito em série
1.8.2 Circuito em paralelo
	
					
 