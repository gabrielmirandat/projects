Capítulo 22 A linguagem SOM-A

22.8  Cartas espectrais, instrumentos e notas 
Os seguintes termos refletem os conceitos básicos da linguagem SOM-A que se empregam na codificação de uma estrutura espectral -- música, fala, ou efeito -- a 
ser interpretadas em amostras digitais de som.

	*Cartas espectrais: São programas partiturais a serem interpretados pela máquina espectral do SOM-A, isto é, são estruturas de dados que contêm partituras e
	orquestras matemáticas. 

	*Instrumentos: Um instrumento se define numa carta espectral a partir de um número qualquer de componentes, todas elas possuindo um comportamento espectral 
	bem definido e individualizado. 

	*Notas: Para se executar uma nota, que contém uma lista de parâmetros, sendo o primeiro deles justamente o nome do instrumento que deverá executar a nota, 
	utilizam-se comandos que fazem referência a todas as unidades-H do instrumento. 

	*Subinstrumento: Quando escrito de uma forma mais específica, o comando de execução pode solicitar a um determinado instrumento que acione apenas um 
	subconjunto de unidades-H. Esta capacidade singular de fracionar o instrumento em grupos menores concede à linguagem a noção de subinstrumento. 
	
22.9  Os 5 operadores de SOM-A 
		
	* Operador VAL
	É o primeiro comando de uma carta espectral, devendo ser aplicado sob a forma:
											(VAL t1 t2 Fa   A T N L)
	-Sua função é atribuir valores (a) ao lapso de tempo [t1 ,t2] em segundos, (b) à taxa de amostragem Fa em Hz, (c) aos três modificadores A T N de 
	interpretação de notas, e (d) ao número máximo de pontos L para as envoltórias. 

	-Parâmetros modificadores de VAL:
		*A: Andamento. Valor que multiplica todos os tempos e durações.
		*T: Transposição. Valor que multiplica as frequências (nas notas).
		*N: Norma. Valor que multiplica as amplitudes das notas.
		*L: Limite de envoltória. Valor limite das abscissas na envoltória.
		
	*Operador INS 
	Define um instrumento aditivo na íntegra por intermédio da sintaxe:
									(INS <vigência> <nome-ins> <unidades-H>)	em que:
		-<vigência> = instante a partir do qual o instrumento deixa de existir;
		-<nome-ins> = cadeia de caracteres;
		-<unidades-H> é a lista ( (h1 phi1 e1 lambda1) (h2 phi2 e2 lambda2) ... (hk phik ek lambdak) );
			*hi: ordem de freqüência da i-ésima unidade: número real positivo.
			*phi_i: ângulo de fase: valor em graus.
			*ei: envoltória. Lista de pares ordenados sendo a ordenada um valor real e a abscissa um número inteiro compreendido entre zero e L.
			*lambda_i: grau de estereofonia. Valor entre 0 e 1 que corresponde ao balanço de saída da componente com relação aos canais estereofônicos x, y.
			Se for 0, a saída estará totalmente em x.
			
	*Operador EXE 
	A aplicação deste operador na forma mostrada abaixo submete uma sequência de eventos espectrais compreendidos entre (dois instantes de nota) ta e tb aos 
	respectivos instrumentos da orquestra: 
			(EXE ta tb)
				(nota_1 -----------------)
				(nota_2 -----------------)
				...
				(nota_n -----------------)
			(STP)

		-O comando (STP) é o delimitador de atuação de EXE. Diversas seções (EXE ta tb) {notas} (STP) podem compor uma carta. 
		-Sintaxe de uma nota:
				nota = ( <instrumento> 
							<instante inicial> 
								<duração> 
									<frequência em Hz>
										<amplitude> 
						)
	
		-As notas devem estar ordenadas cronologicamente, isto é, segundo o instante inicial. A escala de tempo usada nas notas -- especificamente no instante
		inicial e na duração, como também no lapso [ta, tb] do comando EXE -- não é necessariamente uma escala em segundos. O valor em segundos para os tempos
		t0 e dur da nota é obtido com o produto desses tempos pelo parâmetro A de andamento que se define com o comando VAL. 
		
		-22.9.3.1  Instrumento requisitado 
		O instrumento requisitado pela nota pode ser escrito como um único nome, que é o mais comum, ou como uma lista -- denominada subinstrumento, isto é, 
		um instrumento requisitado é assim definido:
						<instrumento> = <instrumento> | <subinstrumento>
		No caso de ser um nome, a nota estará exigindo a ação plena do instrumento. De outro modo, isto é, se o instrumento for representado por uma lista, a
		nota estará solicitando um subconjunto das unidades-H de um determinado instrumento, o qual passará a ser considerado como um macro-instrumento. 

		-22.9.3.2  Subinstrumento 
						<subinstrumento> = ( <macro-instrumento> (n1 n2 ... nk ) )
		O primeiro elemento da lista é o nome de um instrumento previamente definido representando um macro- instrumento, e o segundo uma lista de númerospode
		ser representando unidades-H selecionadas desse macro- instrumento. Cada número representa a posição da unidade-H na sequência (lista-unidades-H). 
		
	*Operador STP 
	Este operador encerra um bloco de notas definido por um comando EXE.
	
	* Operador FIM 
	Este quinto e último operador encerra a carta espectral. 

     Capítulo 12 Fundamentos do som digital 
     
      12.3 Elementos do som digital
	1.Sinais amostrados
	2.Taxa de amostragem
	3.Teoria espectral
	4.Aliasing
	5.Critério de Nyquist
	6.Níveis de quantização
	7.Multiplexação
	8.Esquema de produção de som por computador
	
	12.3.1  Sinais amostrados
	  -Um som puro (senoidal) quando representado por números é feito de amostras discretas.
	12.3.2  Taxa de amostragem
	  -Fa = quantidade de amostrar por segundo. = (1/Ta) "taxa de amostragem"
	  -Ta = tempo que separa duas amostras consecutivas. "período de amostragem"
	  -44100 Hz = 44100 amostras por segundo. = taxa de amostragem
	12.3.3  Teoria espectral 
	  -A transformação de Fourier é o método matemático com o qual é possível passar-se do domínio do tempo para o da frequência. Trata-se,
	   portanto, da principal ferramenta usada em análise espectral. 
	      12.3.3.1  Função contínua e aperiódica -- Transformada cheia
		-Neste caso, quando o sinal (o som) é contínuo porém aperiódico -- como, por exemplo, um estrondo (solitário), que pode ser 
		 representado por um único pulso -- a sua transformada de Fourier é também uma função contínua e aperiódica. Vale dizer, o 
		 espectro de um estrondo é uma banda contínua de frequências. 
	      12.3.3.2  Função contínua e periódica -- Série de Fourier
		-Neste caso, quando o sinal (o som) é contínuo e periódico -- como, por exemplo, uma nota musical lá4 (440 Hz), quando tocada 
		 por um instrumento musical -- corresponde a uma função discreta (e aperiódica) no domínio da frequência. Em outras palavras, o 
		 conteúdo espectral de um som complexo é um conjunto de funções senoidais separadas umas das outras de tal modo que suas 
		 frequências têm valores que são múltiplos da frequência mais baixa, a chamada fundamental.
	      12.3.3.3  Função discreta e aperiódica 
	        -Quando o sinal é discreto e aperiódico -- como, por exemplo, o conteúdo numérico (obtido por digitalização) de um estrondo, 
	         quando representado em um arquivo de dados -- a transformada corresponde a uma função contínua e periódica no domínio da 
	         frequência. Desta maneira, o conteúdo espectral de uma representação digital de um pulso é uma sequência periódica de espectros 
	         individuais (separados por uma distância de frequência dada por Fa/2).
	      12.3.3.4  Função discreta e periódica 
		-Quando o sinal é discreto e periódico -- como, por exemplo, o conteúdo numérico (obtido por digitalização) de uma nota musical,
		 quando tocada por um instrumento representada em um arquivo de dados -- a transformada corresponde a uma função discreta e 
		 periódica no domínio da frequência. Desta maneira, o conteúdo espectral de uma representação digital de uma função periódica
		 discreta é uma sequência periódica de espectros individuais discretos (separados por uma distância de frequência dada por Fa/2).
	12.3.4  Aliasing
	  -É o surgimento de frequências espúrias quando o sinal não está corretamente amostrado. As duas figuras abaixo ilustram a dinâmica 
	   desse fenômeno inerente aos sistemas amostrados. 
	12.3.5  Critério de Nyquist
	  -Para que um sinal seja corretamente amostrado, a sua maior frequência (fmax) deverá ser menor do que a metade da taxa de amostragem
	   (Fa). Isto é, 
				    2*fmax(do sinal) < Fa(qtd de amostras por segundo) 
	  -Caso contrário, ocorre aliasing.
	12.3.6  Níveis de quantização
	  -Numero de bits necessário para representar o eixo y das amostras.
	  -Quanto maior, melhor a resolução do sinal.(menor sua distorção). -- mas também maior será a massa de dados necessária para o sinal. 
	12.3.7  Multiplexação
	  -É a técnica segundo a qual vários sinais compartilham a mesma sequência de amostras.
	12.3.8  Esquema de produção de som por computador
	  -É preciso um dispositivo contendo um ou mais conversores D/A e filtro passa-baixa a fim de se obter um sinal de áudio contínuo -- e 
	   não digital -- para que se possa utilizá-lo auditivamente. Note-se que é tecnicamente errado e imprudente lançar-se diretamente o 
	   sinal digital sobre o sistema de altofalantes. Antes, deve-se "analogizá-lo" com um filtro passa baixa com uma frequência de corte 
	   apropriada e uma atenuação (dB/oitava) elevada. 
	12.3.9  Conversor D/A
	  -Digital analógico.
	"Tipos de Formato"
	  -Há uma diferença básica entre o formato de arquivo de áudio e o que se denomina codec de áudio. Um codec responde pela codificação e 
	  decodificação dos dados (brutos) de áudio. Já os dados, depois de codificados pelo codec são guardados em um arquivo de formato
	  específico, correspondente ao tipo de codificação levada a cabo pelo codec.   
	
     Capítulo 13 Métodos de síntese 
     
	-3 linguagens sônicas: fala, música e ruídos ambientais.
	-Técnicas empregadas para a produção destes sons:
	    *Síntese subtrativa
	    *Síntese por modulação FM
	    *Síntese por distorção não linear
	    *Síntese granular
	    *Síntese aditiva (*)
	13.2 Espectros dinâmicos
	  -É o fato de as componentes espectrais terem amplitudes variáveis, isto é, todas elas são moduladas em amplitude por curvas 
	   denominadas envoltórias. Um sinal musical ou de voz em geral possui um espectro dinâmico.
	13.3 Síntese subtrativa
	  - Filtragem de sinais -- sinais esses cujo espectro contém, em princípio, uma densidade de componentes elevada -- por meio de 
	    dispositivos de múltipla ressonância. 
	  - No caso da fala,o esquema da construção da voz é de certo modo uma síntese subtrativa, o mesmo vale para instrumentos musicais.
	  
	Instrumentos: divididos em três partes: (1) fonte sonora, (2) ressonador, e (3) radiador.
	  - A fonte sonora gera um sinal acústico (uma onda estacionária) com uma boa densidade espectral, sinal este que é entregue por 
	    acoplamento acústico ao sistema ressonador, que então "esculpirá" um espectro final a partir da matéria-prima espectral bruta que 
	    provém da unidade vibratória primal (a fonte sonora). 
 	  - (2) oscila em determinadas frequências.
		-Poder de subtrair harmônicos do som digital.
 	  - (3) troca calor.
 	  
 	13.4 Síntese por modulação FM
	  - x(t) = A sen(ct + I sen mt)
	em que
	
		c: frequência da portadora
		m: frequência da modulante
		I: (= d/m ) índice de modulação
		d: desvio de pico

        13.5 Síntese por distorção não-linear
	  -polinômios de Cheychev = defini-los como uma sequência de polinômios ortogonais, relacionados com a fórmula de Moivre e facilmente 
	   obtíveis de forma recursiva.
	13.6 Síntese granular
	  -Conceito central: quantum sônico.
	13.7 Síntese aditiva
	  -É o sinal resultante de um grupo aditivo de k unidades harmônicas.
	  
	   13.7.1 Oscilador 
	    -Gera amostras correspondentes a um certo número de ciclos de uma senoide numa dada frequência e com uma dada amplitude. 
	   13.7.2 Gerador de envoltória
	    -Gera amostras de uma função modulante para atuar na amplitude da senoide produzida pelo oscilador. 
	   13.7.3 Dispositivo de saída
	    -Direciona as amostras para o canal x ou para o canal y , ou para ambos.
	   13.7.4 Unidade-H
	    -É o menor instrumento possível. Reúne em único algoritmo as unidades definidas acima. Compreende um Oscilador, um Gerador de 
	     envoltória e um Dispositivo de saída. 
	   13.7.5 Instrumento aditivo
	    -É o dispositivo básico da síntese aditiva que é formado por um agregado de unidades-H cujas saídas são adicionadas.
    
         Capítulo 14 Oscilador 
	   14.8 Oscilador digital
	    -É um dispositivo de seis partes que pode ser implementado por software ou pode ser construído como um hardware. 
		SEN
		Incr
		Inicio
		Acumulador
		Indexador
		Multiplicador
	    -É à tabela (se fosse pela série de Taylor iria demorar demais em termos de complexidade).
	    -O dispositivo tem 3 entradas: amplitude (a), frequência (f) e ângulo de fase inicial (phi). A saída é uma sequência de números 
	     inteiros Osc(nT) representando um sinal senoidal gerado a uma taxa de amostragem FA = 1/T, sendo T o período do relógio (clock,
	     isto é, o trem de pulsos P(nT) que aciona o dispositivo. 
	     
	      *SEN = Consta de um array de números reais -- contendo 1+No amostras igualmente espaçadas ao longo de um período de uma senóide 
		     de amplitude unitária -- e de um mecanismo de interpolação. Percorrida com saltos iguais.
		     
	      *Incr = campo (variável) que contém o salto de amostras correspondente a uma dada frequência. A partir da frequência calcula-se 
	      o incremento :					Incr = (f / Fa)* No
	      
	      *Início = É o valor inicial do indexador de array devido ao ângulo de fase inicial phi . Inicio = (phi /360 )*No. 
	      
	      *Acumulador (Ac) = É o acumulador do índice real sigma. Guarda o índice real da amostra n -1. Em n=0, a acumulador Ac contém o 
				 valor Inicio. 
				 
	      *Indexador sigma_zero = Calcula o índice real para a parte array SEN correspondente à n-ésima amostra. Depois de proceder com o 
	                              cálculo da amostra corrente, sigma-zero guarda no acumulador Ac o índice real da amostra. 
	                              
	      *Multiplicadora x = Para escalonar a saída de acordo com a entrada de amplitude a = Env(nT). 
	      
	    14.8.8 Interpolação da parte SEN
	        1)Truncamento
		2)Arredondamento
		3)Interpolação
		
	 Capítulo 15 Gerador de curvas
	  -Uma nota musical verdadeira, como se sabe, define-se com três parâmetros: altura, duração e intensidade. 
	  -Estas regiões (ou etapas) correspondem efetivamente ao surgimento, à existência e à extinção da nota. Molde na nota em sua duração.
	  -São justamente as "envoltórias" que dão um caráter musical mais convincente ao timbre do instrumento. 
	  
	   15.3  Tempo de ataque
	      -O tempo de ataque de uma nota musical é uma grandeza psicoacústica que corresponde ao tempo necessário para se ouvir a ênfase 
	       rítmica do som.
	   15.4  Sustentação
	      -A sustentação de um som musical é a fase de constância (ou quase constância) da amplitude do som. Em geral ela se estabelece logo
	       em seguida à fase de ataque, para formar o que denomina corpo da nota.
	   15.5  Declínio 
	      -O declínio de um som musical é a fase em que não mais se aplica (por parte do instrumentista) uma força de excitação ao instrumento. 
	   15.6  Densidade de ataque (Grau de percussão)
	      -Razão entre o tempo de ataque(ta) e o período."(ou tempo de ataque * frequência)"
 	      -Instrumentos de percussão tem grau de ataque menor que 5.
 	   15.8 Função das envoltórias na acentuação de notas musicais
	      -1. Staccato
	      A nota é tocada de modo a soar desconectada de sua sucessora. Para tal, encurta-se a duração e acrescenta-se uma pausa compensativa
	      a fim de se preservar a duração real.
	      -2. Tenuto
	      A nota é mantida a uma mesma intensidade ao longo de toda a sua duração.
	      -3. Marcato
	      A nota é iniciada em forte e logo em seguida é reduzida a piano.
	      -4. Legato
	      A nota é iniciada com a intensidade final de sua antecessora.

	      
 	    
	


      
	
	
	

	
	
	
	
	
	
	
	

