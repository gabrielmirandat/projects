1. Medidas DC (14/09)
2. Medidas AC (21/09)
3. An�lise de circuitos resistivos (28/09)
4. Princ�pio da sup erp osi��o (05/10)
5. Teorema de Norton e de Th�venin (05/10)
6. Capacitor e Indutor (19/10)
7. Circuitos RC e RL (09/11 - 16/11)
8. Circuitos RLC (23/11)
9. An�lise fasorial de circuitos RLC (30/11)

Sugest�es de programas de simula��o de circuitos:
DoCircuits (homepage),
CircuitLab (homepage),
simulador Tektronix (simula o oscilosc�pio),
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
   Avalia��o Individual
-> Pr�-relat�rio(individual) e relat�rio(grupo)
-> Pontua��o:
		* Pr�-relat�rio completo e no prazo (1 ponto)
		* Apresenta��o e organiza��o (1 ponto)
		* Simula��es (2 pontos)
		* C�lculos te�ricos (2 pontos)
		* Procedimento experimental (2 pontos)
		* Resposta �s perguntas e an�lises (2 pontos)

-> Pr�-relat�rio
	- Todos os itens pedidos no roteiro do experimento que n�o sejam de car�ter pr�tico como, por exemplo, c�lculos te�ricos e simula��es computacionais.
	- Individual e feito a m�o (resultados de simula��o impressos e anexados ao documento).
	- Deve ser anexado ao relat�rio do grupo e entregue juntamente ao relat�rio. 
	- Pr�-relat�rios entregues sem a rubrica do professor n�o ser�o considerados.

-> Relat�rio
	- Os alunos completar�o seus relat�rios � m�o.
	- Dever� apresentar os resultados da parte pr�tica, uma an�lise comparativa com os resultados te�ricos e simulados, e respostas �s quest�es do roteiro.
	- O relat�rio (um por grupo) dever� ser 'feito em aula' e ser� aceito se e somente se for entregue at� o final do dia correspondente � realiza��o do 
	  experimento (juntamente com o pr�-relat�rio anexado de cada um dos integrantes do grupo).
	  
-> Registro na plataforma Piazza tamb�m poder� ser feito atrav�s do link (piazza.com/unb.br/fall2015/167011).
-> P�gina principal do curso pode ser acessada atrav�s do link (piazza.com/unb.br/fall2015/167011/home).

#MANUAL DOS EQUIPAMENTOS

- Equipamentos

#MULTIMETRO
-> 1.1.1 Medindo tens�o
	- DC (direct current) constante no tempo ou 
	  AC (alternate current), variante no tempo.
	
	- V~  = tens�o alternada		//multimetro mostra valor RMS
	  V== = tens�o cont�nua			//multimetro mostra valor m�dio
	  //APENAS PARA ONDAS SENOIDAIS COM FREQUENCIAS AT� 5 KHz e para ondas quadradas com frequ�ncia at� 200 KHz E MESMO ASSIM COM ERROS DE 6% A 8% 
	  //Quando o MULTIMETRO for usado como VOLTIMETRO, ele deve sempre ser ligado em paralelo com o componente sobre o qual se deseja medir a diferen�a de 
	  //potencial (tens�o).
1.1.2 Medindo corrente
	- A~  = corrente alternada		//multimetro mostra valor RMS
	  A== = corrente cont�nua		//multimetro mostra valor m�dio
1.1.3 Medindo resist�ncia
	- Com mult�metro. 
	- NUNCA UM COMPONENTE DEVE TER SUA RESIST�NCIA MEDIDA QUANDO ESTE ESTIVER CONECTADO A UMA FONTE DE TENS�O, A UM CIRCUITO OU A QUALQUER OUTRO ELEMENTO.
1.1.4 Medindo continuidade
	- P/ saber se componenete est� funcionando corretamente.
	-> RESISTENCIA
		- BIP do mult�metro = resist�ncia ZERO (curto).
		- Se resist�ncia infinita (circuito-aberto), n�o tem como saber.
	-> CAPACITOR
		- BIP do mult�metro = queimado ou curto-circuitado.
	- teste deve ser efetuado apenas se o componente estiver desconectado DE OUTROS COMPONENTES.
1.1.5 Medindo capacit�ncia
	- O multimetro pode ser usado para medir a capacit�ncia de um componente. 
	
#FONTE DE TENS�O
1.2.1 Ajustando a tens�o
	- Capaz de fornecer duas tens�es diferentes pois ela possui dois geradores de tens�o DC independentes com capacidade m�xima de 15V cada.
	- Utilizar as duas fontes ao mesmo tempo em um mesmo circuito cria-se um problema de referencia de tens�o e isso pode fazer o circuito n�o funcionar 
	  corretamente ou at� mesmo queimar os componentes e as fontes.
1.2.2 Liga��o entre as FONTES 1 e 2
	- Para esta fonte os terminais pretos est�o conectados. Isso significa que ambos possuem o mesmo potencial SEMPRE. Ela foi constru�da desta forma para 
	  permitir alcan�ar valores de tens�o maiores que 15V. A ideia � usar a FONTE 1 e a FONTE 2 em s�rie. Como cada uma delas � capaz de fornecer 15V ent�o
	  em s�rie elas podem fornecer 30V. 
	- S�RIE => interconectar os terminais pretos.
1.2.3 Refer�ncia de tens�o
	- Geralmente usa-se o valor de Zero Volts para esse fim. Portanto, TODO CIRCUITO DEVE TER UMA REFERENCIA DE TENS�O. As fontes de tens�o geralmente v�m com
      um terminal indicando o valor zero. Isso significa que essa � a sua referencia de Zero volts.
	- Lembrando que o gerador de sinal tamb�m � uma fonte e deve ter sua referencia unida � referencia das outras fontes do  circuito.

#GERADOR DE SINAL
1.3.1 As tr�s vari�veis de um sinal AC
	- Tipo de onda= senoidais, quadradas ou tri�ngulares.
					bot�o WAVE do gerador de sinais. Ele alterna entre os tr�s formatos.
	- Amplitude	  = medida de afastamento m�ximo com rela��o � posi��o de equil�brio de um sinal.
					medida VPP (valor pico a pico) -> Ele mede a dist�ncia entre o valor m�ximo e o valor m�nimo de um sinal oscilante. Para ondas sim�tricas
													  ele � justamente o dobro da amplitude conforme ilustra a figura 12
					alterado de 2 maneiras.
					o valor que aparece no mostrador � O DA AMPLITUDE E N�O O VALOR DE PICO A PICO.
	- Frequ�ncia  = alterado de 2 maneiras.
	-> Outros bot�es do gerador de sinal: 
			RUN: quando pressionado faz o gerador de sinal mostrar o valor da frequ�ncia e a amplitude da onda que esta sendo gerada. ELE DEVE SER	
				 PRESSIONADO TODA VEZ QUE FOR FEITA ALGUMA MODIFICA��O EM UMA DAS TR�S VARI�VEIS DA ONDA (tipo da onda � WAVE, frequ�ncia -RANGE ou FADJ 
				 ou amplitude � ATT ou	AADJ).
	
#OSCILOSC�PIO
1.4.1 Fun��o de um Oscilosc�pio
	- O oscilosc�pio � uma ferramenta de an�lise de tens�o. Ele permite visualizar o formato da onda de um determinado sinal.
1.4.3 Canais de entrada de sinais
	- Para se medir um sinal no oscilosc�pio primeiro � preciso fornecer tal sinal para o oscilosc�pio. Para tanto existem dois canais de entrada. � nesses 
	  canais que se deve introduzir o sinal de tens�o cujo comportamento deseja-se analisar. Portanto esse oscilosc�pio permite a visualiza��o simult�nea de
	  dois sinais. 
1.4.4 Ajuste da escala de tens�o
	- Se CH � 5.0 volts isso significa que a distancia entre cada linha pontilhada � de 5 volts.
	- fato de que o oscilosc�pio possui um erro em suas medidas. Para reduzir ao m�ximo esse erro de leitura a onda deve ocupar a �REA M�XIMA DO GR�FICO 
	  sem deixar nenhuma parte da onda cortada.  
	- Entrada MATH : Depois de pressionado deve-se escolher a opera��o (est�o dispon�veis apenas as opera��es de soma, subtra��o, multiplica��o e FFT das 
	  entradas 1 e 2), as origens dos operandos (em que ordem os canais devem ser operados) e a invers�o ou n�o da resposta.
1.4.5 Ajuste do disparo (Trigger)
	- A fim de evitar que a onda mostrada no oscilosc�pio fique se movimentando e sua visualiza��o fique prejudicada existe uma ferramenta nos oscilosc�pios
      que permite ajustar qual ponto da onda passar� �sempre� pelo ponto de refer�ncia de zero de tens�o.
	-> Bot�o menu = qual o ponto da onda deve passar pela refer�ncia deve-se definir qual dos canais ser� usado como FONTE para o disparo.
	-> Bot�o de n�vel (Level) = ponto da onda passar� pela refer�ncia de zero do tempo.
1.4.6 Cursores para medi��o precisa de valores
	- CURSORES = para precis�o das medidas.
1.4.7 Fun��o MEDI��O
	- permite escolher quais dos par�metros das ondas ser�o exibidos na tela.  
1.4.8 Salvando imagens
	- O oscilosc�pio permite salvar ou at� mesmo imprimir as imagens diretamente da tela. Para isso existe uma porta USB que pode ser diretamente conectada 
	em um computador.  

#RESISTORES
- Observe que h� algumas faixas de cores envolta dos resistores. O valor da resist�ncia do resistor � especificado por essas faixas de cores que seguem um 
  determinado c�digo. Os resistores existentes no mercado se dividem em quatro grupos: com 3, 4, 5 ou 6 faixas.
1.5.1 Resistores com quatro faixas:
	- Observando um resistor de 4 faixas, pode-se ver que uma das cores das extremidades � quase sempre da cor prata ou ouro. Essa � a quarta cor. A quarta 
	  cor indica a toler�ncia do resistor (1% para a cor marrom, 2% para a cor vermelha, 5% para a cor dourada e 10% para a cor prata). As outras tr�s indicam
	  o valor da resist�ncia. Segundo a conven��o, a primeira cor indica o valor do primeiro algarismo, a segunda cor indica o valor do segundo algarismo e a 
	  terceira indica o n�mero de zeros que seguem os dois primeiros algarismos.
	- COR 1 = 1� ALGARISMO
	- COR 2 = 2� ALGARISMO
	- COR 3 = QTD DE ZEROS
	- COR 4 = TOLER�NCIA
1.5.2 Resistores com 5 faixas:
	- A terceira faixa agora se refere ao terceiro algarismo significativo.
	
#INDUTORES
- Indutores s�o elementos armazenadores de energia.
- Diferentemente do resistor �hmico seus par�metros dependem do tempo. 

#CAPACITORES
- Um capacitor � um elemento armazenador de energia e seus par�metros dependem do tempo, assim como em um indutor. 
- Um capacitor � composto por duas placas feitas de material condutor separadas por um isolante. 
	- Capacitor Cer�mico
		- Esse capacitor n�o tem polaridade.
	- Capacitor Eletrol�tico
		- levados de capacit�ncia do que os capacitores cer�micos. Um aspecto importante dos capacitores eletrol�ticos � sua polaridade.

#PROTOBOARD
- A vantagem de se utilizar uma protoboard � a facilidade de inser��o de componentes, uma vez que a soldagem n�o � necess�ria.
- Linhas horizontais = n�s (mesmo potencial)
1.8.1 Circuito em s�rie
1.8.2 Circuito em paralelo
	
					
 