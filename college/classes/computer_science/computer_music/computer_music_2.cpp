Cap�tulo 22 A linguagem SOM-A

22.8  Cartas espectrais, instrumentos e notas 
Os seguintes termos refletem os conceitos b�sicos da linguagem SOM-A que se empregam na codifica��o de uma estrutura espectral -- m�sica, fala, ou efeito -- a 
ser interpretadas em amostras digitais de som.

	*Cartas espectrais: S�o programas partiturais a serem interpretados pela m�quina espectral do SOM-A, isto �, s�o estruturas de dados que cont�m partituras e
	orquestras matem�ticas. 

	*Instrumentos: Um instrumento se define numa carta espectral a partir de um n�mero qualquer de componentes, todas elas possuindo um comportamento espectral 
	bem definido e individualizado. 

	*Notas: Para se executar uma nota, que cont�m uma lista de par�metros, sendo o primeiro deles justamente o nome do instrumento que dever� executar a nota, 
	utilizam-se comandos que fazem refer�ncia a todas as unidades-H do instrumento. 

	*Subinstrumento: Quando escrito de uma forma mais espec�fica, o comando de execu��o pode solicitar a um determinado instrumento que acione apenas um 
	subconjunto de unidades-H. Esta capacidade singular de fracionar o instrumento em grupos menores concede � linguagem a no��o de subinstrumento. 
	
22.9  Os 5 operadores de SOM-A 
		
	* Operador VAL
	� o primeiro comando de uma carta espectral, devendo ser aplicado sob a forma:
											(VAL t1 t2 Fa   A T N L)
	-Sua fun��o � atribuir valores (a) ao lapso de tempo [t1 ,t2] em segundos, (b) � taxa de amostragem Fa em Hz, (c) aos tr�s modificadores A T N de 
	interpreta��o de notas, e (d) ao n�mero m�ximo de pontos L para as envolt�rias. 

	-Par�metros modificadores de VAL:
		*A: Andamento. Valor que multiplica todos os tempos e dura��es.
		*T: Transposi��o. Valor que multiplica as frequ�ncias (nas notas).
		*N: Norma. Valor que multiplica as amplitudes das notas.
		*L: Limite de envolt�ria. Valor limite das abscissas na envolt�ria.
		
	*Operador INS 
	Define um instrumento aditivo na �ntegra por interm�dio da sintaxe:
									(INS <vig�ncia> <nome-ins> <unidades-H>)	em que:
		-<vig�ncia> = instante a partir do qual o instrumento deixa de existir;
		-<nome-ins> = cadeia de caracteres;
		-<unidades-H> � a lista ( (h1 phi1 e1 lambda1) (h2 phi2 e2 lambda2) ... (hk phik ek lambdak) );
			*hi: ordem de freq��ncia da i-�sima unidade: n�mero real positivo.
			*phi_i: �ngulo de fase: valor em graus.
			*ei: envolt�ria. Lista de pares ordenados sendo a ordenada um valor real e a abscissa um n�mero inteiro compreendido entre zero e L.
			*lambda_i: grau de estereofonia. Valor entre 0 e 1 que corresponde ao balan�o de sa�da da componente com rela��o aos canais estereof�nicos x, y.
			Se for 0, a sa�da estar� totalmente em x.
			
	*Operador EXE 
	A aplica��o deste operador na forma mostrada abaixo submete uma sequ�ncia de eventos espectrais compreendidos entre (dois instantes de nota) ta e tb aos 
	respectivos instrumentos da orquestra: 
			(EXE ta tb)
				(nota_1 -----------------)
				(nota_2 -----------------)
				...
				(nota_n -----------------)
			(STP)

		-O comando (STP) � o delimitador de atua��o de EXE. Diversas se��es (EXE ta tb) {notas} (STP) podem compor uma carta. 
		-Sintaxe de uma nota:
				nota = ( <instrumento> 
							<instante inicial> 
								<dura��o> 
									<frequ�ncia em Hz>
										<amplitude> 
						)
	
		-As notas devem estar ordenadas cronologicamente, isto �, segundo o instante inicial. A escala de tempo usada nas notas -- especificamente no instante
		inicial e na dura��o, como tamb�m no lapso [ta, tb] do comando EXE -- n�o � necessariamente uma escala em segundos. O valor em segundos para os tempos
		t0 e dur da nota � obtido com o produto desses tempos pelo par�metro A de andamento que se define com o comando VAL. 
		
		-22.9.3.1  Instrumento requisitado 
		O instrumento requisitado pela nota pode ser escrito como um �nico nome, que � o mais comum, ou como uma lista -- denominada subinstrumento, isto �, 
		um instrumento requisitado � assim definido:
						<instrumento> = <instrumento> | <subinstrumento>
		No caso de ser um nome, a nota estar� exigindo a a��o plena do instrumento. De outro modo, isto �, se o instrumento for representado por uma lista, a
		nota estar� solicitando um subconjunto das unidades-H de um determinado instrumento, o qual passar� a ser considerado como um macro-instrumento. 

		-22.9.3.2  Subinstrumento 
						<subinstrumento> = ( <macro-instrumento> (n1 n2 ... nk ) )
		O primeiro elemento da lista � o nome de um instrumento previamente definido representando um macro- instrumento, e o segundo uma lista de n�merospode
		ser representando unidades-H selecionadas desse macro- instrumento. Cada n�mero representa a posi��o da unidade-H na sequ�ncia (lista-unidades-H). 
		
	*Operador STP 
	Este operador encerra um bloco de notas definido por um comando EXE.
	
	* Operador FIM 
	Este quinto e �ltimo operador encerra a carta espectral. 

     Cap�tulo 12 Fundamentos do som digital 
     
      12.3 Elementos do som digital
	1.Sinais amostrados
	2.Taxa de amostragem
	3.Teoria espectral
	4.Aliasing
	5.Crit�rio de Nyquist
	6.N�veis de quantiza��o
	7.Multiplexa��o
	8.Esquema de produ��o de som por computador
	
	12.3.1  Sinais amostrados
	  -Um som puro (senoidal) quando representado por n�meros � feito de amostras discretas.
	12.3.2  Taxa de amostragem
	  -Fa = quantidade de amostrar por segundo. = (1/Ta) "taxa de amostragem"
	  -Ta = tempo que separa duas amostras consecutivas. "per�odo de amostragem"
	  -44100 Hz = 44100 amostras por segundo. = taxa de amostragem
	12.3.3  Teoria espectral 
	  -A transforma��o de Fourier � o m�todo matem�tico com o qual � poss�vel passar-se do dom�nio do tempo para o da frequ�ncia. Trata-se,
	   portanto, da principal ferramenta usada em an�lise espectral. 
	      12.3.3.1  Fun��o cont�nua e aperi�dica -- Transformada cheia
		-Neste caso, quando o sinal (o som) � cont�nuo por�m aperi�dico -- como, por exemplo, um estrondo (solit�rio), que pode ser 
		 representado por um �nico pulso -- a sua transformada de Fourier � tamb�m uma fun��o cont�nua e aperi�dica. Vale dizer, o 
		 espectro de um estrondo � uma banda cont�nua de frequ�ncias. 
	      12.3.3.2  Fun��o cont�nua e peri�dica -- S�rie de Fourier
		-Neste caso, quando o sinal (o som) � cont�nuo e peri�dico -- como, por exemplo, uma nota musical l�4 (440 Hz), quando tocada 
		 por um instrumento musical -- corresponde a uma fun��o discreta (e aperi�dica) no dom�nio da frequ�ncia. Em outras palavras, o 
		 conte�do espectral de um som complexo � um conjunto de fun��es senoidais separadas umas das outras de tal modo que suas 
		 frequ�ncias t�m valores que s�o m�ltiplos da frequ�ncia mais baixa, a chamada fundamental.
	      12.3.3.3  Fun��o discreta e aperi�dica 
	        -Quando o sinal � discreto e aperi�dico -- como, por exemplo, o conte�do num�rico (obtido por digitaliza��o) de um estrondo, 
	         quando representado em um arquivo de dados -- a transformada corresponde a uma fun��o cont�nua e peri�dica no dom�nio da 
	         frequ�ncia. Desta maneira, o conte�do espectral de uma representa��o digital de um pulso � uma sequ�ncia peri�dica de espectros 
	         individuais (separados por uma dist�ncia de frequ�ncia dada por Fa/2).
	      12.3.3.4  Fun��o discreta e peri�dica 
		-Quando o sinal � discreto e peri�dico -- como, por exemplo, o conte�do num�rico (obtido por digitaliza��o) de uma nota musical,
		 quando tocada por um instrumento representada em um arquivo de dados -- a transformada corresponde a uma fun��o discreta e 
		 peri�dica no dom�nio da frequ�ncia. Desta maneira, o conte�do espectral de uma representa��o digital de uma fun��o peri�dica
		 discreta � uma sequ�ncia peri�dica de espectros individuais discretos (separados por uma dist�ncia de frequ�ncia dada por Fa/2).
	12.3.4  Aliasing
	  -� o surgimento de frequ�ncias esp�rias quando o sinal n�o est� corretamente amostrado. As duas figuras abaixo ilustram a din�mica 
	   desse fen�meno inerente aos sistemas amostrados. 
	12.3.5  Crit�rio de Nyquist
	  -Para que um sinal seja corretamente amostrado, a sua maior frequ�ncia (fmax) dever� ser menor do que a metade da taxa de amostragem
	   (Fa). Isto �, 
				    2*fmax(do sinal) < Fa(qtd de amostras por segundo) 
	  -Caso contr�rio, ocorre aliasing.
	12.3.6  N�veis de quantiza��o
	  -Numero de bits necess�rio para representar o eixo y das amostras.
	  -Quanto maior, melhor a resolu��o do sinal.(menor sua distor��o). -- mas tamb�m maior ser� a massa de dados necess�ria para o sinal. 
	12.3.7  Multiplexa��o
	  -� a t�cnica segundo a qual v�rios sinais compartilham a mesma sequ�ncia de amostras.
	12.3.8  Esquema de produ��o de som por computador
	  -� preciso um dispositivo contendo um ou mais conversores D/A e filtro passa-baixa a fim de se obter um sinal de �udio cont�nuo -- e 
	   n�o digital -- para que se possa utiliz�-lo auditivamente. Note-se que � tecnicamente errado e imprudente lan�ar-se diretamente o 
	   sinal digital sobre o sistema de altofalantes. Antes, deve-se "analogiz�-lo" com um filtro passa baixa com uma frequ�ncia de corte 
	   apropriada e uma atenua��o (dB/oitava) elevada. 
	12.3.9  Conversor D/A
	  -Digital anal�gico.
	"Tipos de Formato"
	  -H� uma diferen�a b�sica entre o formato de arquivo de �udio e o que se denomina codec de �udio. Um codec responde pela codifica��o e 
	  decodifica��o dos dados (brutos) de �udio. J� os dados, depois de codificados pelo codec s�o guardados em um arquivo de formato
	  espec�fico, correspondente ao tipo de codifica��o levada a cabo pelo codec.   
	
     Cap�tulo 13 M�todos de s�ntese 
     
	-3 linguagens s�nicas: fala, m�sica e ru�dos ambientais.
	-T�cnicas empregadas para a produ��o destes sons:
	    *S�ntese subtrativa
	    *S�ntese por modula��o FM
	    *S�ntese por distor��o n�o linear
	    *S�ntese granular
	    *S�ntese aditiva (*)
	13.2 Espectros din�micos
	  -� o fato de as componentes espectrais terem amplitudes vari�veis, isto �, todas elas s�o moduladas em amplitude por curvas 
	   denominadas envolt�rias. Um sinal musical ou de voz em geral possui um espectro din�mico.
	13.3 S�ntese subtrativa
	  - Filtragem de sinais -- sinais esses cujo espectro cont�m, em princ�pio, uma densidade de componentes elevada -- por meio de 
	    dispositivos de m�ltipla resson�ncia. 
	  - No caso da fala,o esquema da constru��o da voz � de certo modo uma s�ntese subtrativa, o mesmo vale para instrumentos musicais.
	  
	Instrumentos: divididos em tr�s partes: (1) fonte sonora, (2) ressonador, e (3) radiador.
	  - A fonte sonora gera um sinal ac�stico (uma onda estacion�ria) com uma boa densidade espectral, sinal este que � entregue por 
	    acoplamento ac�stico ao sistema ressonador, que ent�o "esculpir�" um espectro final a partir da mat�ria-prima espectral bruta que 
	    prov�m da unidade vibrat�ria primal (a fonte sonora). 
 	  - (2) oscila em determinadas frequ�ncias.
		-Poder de subtrair harm�nicos do som digital.
 	  - (3) troca calor.
 	  
 	13.4 S�ntese por modula��o FM
	  - x(t) = A sen(ct + I sen mt)
	em que
	
		c: frequ�ncia da portadora
		m: frequ�ncia da modulante
		I: (= d/m ) �ndice de modula��o
		d: desvio de pico

        13.5 S�ntese por distor��o n�o-linear
	  -polin�mios de Cheychev = defini-los como uma sequ�ncia de polin�mios ortogonais, relacionados com a f�rmula de Moivre e facilmente 
	   obt�veis de forma recursiva.
	13.6 S�ntese granular
	  -Conceito central: quantum s�nico.
	13.7 S�ntese aditiva
	  -� o sinal resultante de um grupo aditivo de k unidades harm�nicas.
	  
	   13.7.1 Oscilador 
	    -Gera amostras correspondentes a um certo n�mero de ciclos de uma senoide numa dada frequ�ncia e com uma dada amplitude. 
	   13.7.2 Gerador de envolt�ria
	    -Gera amostras de uma fun��o modulante para atuar na amplitude da senoide produzida pelo oscilador. 
	   13.7.3 Dispositivo de sa�da
	    -Direciona as amostras para o canal x ou para o canal y , ou para ambos.
	   13.7.4 Unidade-H
	    -� o menor instrumento poss�vel. Re�ne em �nico algoritmo as unidades definidas acima. Compreende um Oscilador, um Gerador de 
	     envolt�ria e um Dispositivo de sa�da. 
	   13.7.5 Instrumento aditivo
	    -� o dispositivo b�sico da s�ntese aditiva que � formado por um agregado de unidades-H cujas sa�das s�o adicionadas.
    
         Cap�tulo 14 Oscilador 
	   14.8 Oscilador digital
	    -� um dispositivo de seis partes que pode ser implementado por software ou pode ser constru�do como um hardware. 
		SEN
		Incr
		Inicio
		Acumulador
		Indexador
		Multiplicador
	    -� � tabela (se fosse pela s�rie de Taylor iria demorar demais em termos de complexidade).
	    -O dispositivo tem 3 entradas: amplitude (a), frequ�ncia (f) e �ngulo de fase inicial (phi). A sa�da � uma sequ�ncia de n�meros 
	     inteiros Osc(nT) representando um sinal senoidal gerado a uma taxa de amostragem FA = 1/T, sendo T o per�odo do rel�gio (clock,
	     isto �, o trem de pulsos P(nT) que aciona o dispositivo. 
	     
	      *SEN = Consta de um array de n�meros reais -- contendo 1+No amostras igualmente espa�adas ao longo de um per�odo de uma sen�ide 
		     de amplitude unit�ria -- e de um mecanismo de interpola��o. Percorrida com saltos iguais.
		     
	      *Incr = campo (vari�vel) que cont�m o salto de amostras correspondente a uma dada frequ�ncia. A partir da frequ�ncia calcula-se 
	      o incremento :					Incr = (f / Fa)* No
	      
	      *In�cio = � o valor inicial do indexador de array devido ao �ngulo de fase inicial phi . Inicio = (phi /360 )*No. 
	      
	      *Acumulador (Ac) = � o acumulador do �ndice real sigma. Guarda o �ndice real da amostra n -1. Em n=0, a acumulador Ac cont�m o 
				 valor Inicio. 
				 
	      *Indexador sigma_zero = Calcula o �ndice real para a parte array SEN correspondente � n-�sima amostra. Depois de proceder com o 
	                              c�lculo da amostra corrente, sigma-zero guarda no acumulador Ac o �ndice real da amostra. 
	                              
	      *Multiplicadora x = Para escalonar a sa�da de acordo com a entrada de amplitude a = Env(nT). 
	      
	    14.8.8 Interpola��o da parte SEN
	        1)Truncamento
		2)Arredondamento
		3)Interpola��o
		
	 Cap�tulo 15 Gerador de curvas
	  -Uma nota musical verdadeira, como se sabe, define-se com tr�s par�metros: altura, dura��o e intensidade. 
	  -Estas regi�es (ou etapas) correspondem efetivamente ao surgimento, � exist�ncia e � extin��o da nota. Molde na nota em sua dura��o.
	  -S�o justamente as "envolt�rias" que d�o um car�ter musical mais convincente ao timbre do instrumento. 
	  
	   15.3  Tempo de ataque
	      -O tempo de ataque de uma nota musical � uma grandeza psicoac�stica que corresponde ao tempo necess�rio para se ouvir a �nfase 
	       r�tmica do som.
	   15.4  Sustenta��o
	      -A sustenta��o de um som musical � a fase de const�ncia (ou quase const�ncia) da amplitude do som. Em geral ela se estabelece logo
	       em seguida � fase de ataque, para formar o que denomina corpo da nota.
	   15.5  Decl�nio 
	      -O decl�nio de um som musical � a fase em que n�o mais se aplica (por parte do instrumentista) uma for�a de excita��o ao instrumento. 
	   15.6  Densidade de ataque (Grau de percuss�o)
	      -Raz�o entre o tempo de ataque(ta) e o per�odo."(ou tempo de ataque * frequ�ncia)"
 	      -Instrumentos de percuss�o tem grau de ataque menor que 5.
 	   15.8 Fun��o das envolt�rias na acentua��o de notas musicais
	      -1. Staccato
	      A nota � tocada de modo a soar desconectada de sua sucessora. Para tal, encurta-se a dura��o e acrescenta-se uma pausa compensativa
	      a fim de se preservar a dura��o real.
	      -2. Tenuto
	      A nota � mantida a uma mesma intensidade ao longo de toda a sua dura��o.
	      -3. Marcato
	      A nota � iniciada em forte e logo em seguida � reduzida a piano.
	      -4. Legato
	      A nota � iniciada com a intensidade final de sua antecessora.

	      
 	    
	


      
	
	
	

	
	
	
	
	
	
	
	

