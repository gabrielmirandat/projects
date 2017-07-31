  1. Apresentação do Curso: A Revolu̧cão Digital.
  2. Álgebra de Boole; Portas Lógicas, Famílias Lógicas, Funções Lógica;
    Mapas de Karnaugh, Mapas de Karnaugh com Variáveis Introduzidas.
  3. A Linguagem VHDL
  4. Representação de Números em Ponto Fixo, Ponto Flutuante.
  5. Circuitos Combinacionais: Multiplexadores, Somadores, Comparado-
     res, Codificadores, Decodificadores, Multiplicadores, Unidade Lógica
     Aritmética, Buffers.
  6. Circuitos Sequenciais: Latches, Flip-Flops, Contadores e Registradores.
  7. Máquinas de Estado Síncronas.


  'Projeto 1 -  especificação'
    código detector de erro - 00 e 11 inves de 0 e 1. Número par de bits mandados e se qtd ímpar der problema.
    código detector e corretor de erro - 00000 e 11111 inves de 0 e 1.		-> o que queremos.

    Hamming
      mensagem (4 bits) -> encoder (7 bits) -> canal (7 bits) -> decoder (4 bits)
	  m			x			y		m''

      distância de hamming = nº de bits diferentes entre as duas palavras.
	  d(x,y) = 3; e o código garante que m''= m, se d(x,y)<= 1
	  ou seja, a mensagem recebida será igual a mensagem enviada se houver no máximo um erro.

	  A.codificador (para gerar x, multiplicamos pela matriz geradora G(4x7))
	    x = mG
	    'lembrando que a matemática é feita em módulo de 2 (1 + 1 = 0)'

	  B.decodificador (para gerar m'', multiplica-se pela matriz de paridade H)
	    ou seja, a mensagem recebida será igual a mensagem enviada se houver no máximo um erro.
	    A matriz de paridade H pode ser encontrada a partir de G resolvendo a equação GH^T = 0.
	    O algorítmo para decodificar a palavra recebida y consiste em encontrar a síndrome
	      s = Hy^T
	      'lembrando que a matemática é feita em módulo de 2 (1 + 1 = 0)'
	      Além disso, a síndrome calculada pela Eq. 5 diz exatamente qual dos bits de y deve ser invertido para transformar y em uma
	      palavra código correta!
	      'se s = [0 0 1], o primeiro bit foi invertido, então inverta-o'
	      'se s = [0 1 1], o terceiro bit foi convertido, então inverta-o'







  'n' - qtd de bits
  r - base da representação
  complemento de um número - o negativo do número.


  "objetivo de sistemas digitais" - Entender como um microprocessador funciona (e até projetar um).
				    Veremos os primeiros passos para isso.

  "Sinal analógico" - contínuo no tempo/amplitude
		    - infinitos valores
  "Sinal digital" - discreto no tempo/amplitude
		  - finitos valores
		  - pode ser a lógica de Boole
		  - é um sinal amostrado(tempo) e quantizado(amplitude)

  "Sistemas analógicos" - processam sinais analógicos(variantes no tempo que podem possuir qualquer valor dentro de um intervalo contínuo de tensão, corrente ou outro).
  "Sistemas digitais" - também processam sinais analógicos. A diferença é que podemos fingir que são sinais digitais (discretos).
		      - tensão_entrada->sistema digital-> tensão_saída
		      - "Abstração digital" -circuitos digitais não operam com entradas realmente digitais, mas sim tensões e correntes analógicas, e são contruídos com
					     componentes analógicos("transistores"). Com a abstração esse comportamente analógico pode ser ignorado de forma que o circuito
					     possa ser modelado como se processasse 0's e '1's.
					    -entrada analógica entre Vmin e Vil = 0;
					    -entrada analógica entre Vih e Vmax = 1;
					    -acima ou abaixo da damage;
					    -entre os dois = ?.
		      - Prós
			  -dadas as mesmas entradas, a saída é sempre a mesma. O analógico pode variar com temperatura e tensão de alimentação.
			  -o projeto do circuito é bem mais simples que o analógico.
			  -problema resolvível apenas com uma série de passos lógicos.
			  -"exemplo" chave com mensagem de voz secreta. Quase impossível de se fazer num sistema analógico.
			  -circuitos projetáveis através de linguagens de programação ("HDL-linguagem de descrição de hardware")
			  -são muito rápidos
			  -custo/benefício em funcionabilidade/tamanho_do_pacote
			  -resistente à ruído (mesmo com ruído acumulado o sinal pode ser restaurado)
			      -no sistema analógico: entra V + ruído, sai f(V + ruído)
			      -no sistema digital: entra V + ruído, sai f(V)
			  -a saída do sistema é mais inchuta que a entrada (menor distância em relação ao valor esperado)

  "Sinais Binários" - Circuitos só operam com sinais binários. Para operar com valores não binários, primeiro convertemo-os para binário, realizamos a operação e
		      então convertemos de volta para a base inicial.

		      "representação decimal" 3447 = 3.10³ + 4.10² + 4.10¹ + 7.10⁰

		      "binário para decimal" 100101 = 1.2⁵ + 0.2⁴ + 0.2³ + 1.2² + 0.2¹ + 1.2⁰ = 37

		      "decimal para binário" a) Divide número por 2 ("os restos são ou 1's ou 0's")
					     b) O resto é o bit menos significativo (LSB)
					     c) O quociente (inteiro) é dividido novamente por 2
					     d) o resto é o próximo bit menos significativo
					     e) Repete-se o processo até que o quociente seja 0 (ou que o dividendo seja menor que o divisor)

  "Circuitos Digitais só lidam com bits (o significado desses bits que depende)"

  Agrupamos 3 bits para formar um número octal.
  Agrupamos 4 bits para  formar um número hexadecimal. (1 byte precisa de 2 dígitos hexadecimais)

  IMPORTANTE
  'Adição de binários'
    - carry ("vai-um naquela casa??") só pode ser 0 ou 1. Não esquecer do último vai-um.

  'Subtração de binários'
    - borrow("aquela casa emprestou 1??").
    - tanto a soma quanto a subtração, se ambos os números possuírem 'n' bits, (n+1) bits no carry ou borrow.
    - soma 1 nos intermediários (0's viram 1's) e o que queria primeiro fica com 10 (que é igual a 2).

  'Multiplicação de binários'
    - mesmo forma que em decimal, porém mais fácil.(só há 0's e 1's).
    - no entanto, num sistema digital, a multiplicação é feita por somas parciais deslocadas.
    - Em geral, a multiplicação de um número de 'n' bits por um número de 'm' bits requer 'n' + 'm' bits (para que não haja overflow).
    - O algoritmo de deslocar e adicionar (shift and add) requer 'm' produtos parciais e adições.
    - O circuito pode ser feito com um registrador de deslocamento, um somador e uma lógica de controle.
    - Em complemento de 2,  essa multiplicação requer um pouco mais de cuidado.

  'Divisão de binários'
    - Mesma forma que os decimais.

  'Representação de números negativos' - Existem várias formas e podem ser usadas para qualquer base
       Signed Magnitude Representation (ou Represenção de Magnitude com Sinal)
	  -Em geral, usamos o MSB para o sinal, onde 0 representa o sinal positivo + e 1 representa o sinal negativo −.
	  -Quantidade igual e positivos e negativos.
	  -Com 'n' bits, o intervalo é -(2⁽n-1⁾ - 1) a (2⁽n-1⁾ - 1).
	  -Se temos 8 bits, representamos de -127 a 127. '= 255 valores, e não 256'
	  -Para negativar um número, invertemos o MSB
	  -'Contras' Duas representações para o zero: +0 e -0
		     Como fazer a adição?
	  -sequencial para baixo do 1000(zero) e sequencial para cima do 0000(zero).

       Complement Number System (ou sistema de complemento do número)
	  -Negativamos o número pegando seu complemento (a ser definido pelo sistema)
	  "Complemento de 1 (diminished radix complement ou complemento de base reduzido)"
	      -o complemento de um número é obtido invertendo-se cada bit
	      -o complemento também é obtido subtraindo-se ((r^n) - 1) do número.
	      -o peso do primeiro bit é sempre negativo dado por -(2⁽n-1⁾ - 1)
	      -zero possui duas representações: +0 (00...00) e -0 (11...11)
	      -um número negativo sempre tem MSB igual a 1, mas um número com MSB igual a 1 pode não ser negativo.
	      -Com 'n' bits, o intervalo é -(2⁽n-1⁾ - 1) a (2⁽n-1⁾ - 1).
	      -Se temos 8 bits, representamos de -127 a 127. '= 255 valores, e não 256'
	      -sequencial invertido, ou sequencial com trucamento, porém não representa todos os números.

	  "Complemento de 2 (radix complement ou complemento de base)"
	      -o complemento de um número é obtido invertendo-se cada bit e somando 1 ao resultado
	      -o complemento também é obtido subtraindo-se (r^n) do número.
	      -o peso do primeiro bit é sempre negativo dado por -2⁽n-1⁾
	      -zero possui só uma representação (00...00)
	      -se MSB é 1, o número é negativo, senão é positivo.
	      -Com 'n' bits, o intervalo é -2⁽n-1⁾ a (2⁽n-1⁾ - 1).
	      -Se temos 8 bits, representamos de -128 a 127. '= 256 valores'
	      -mais usado: soma e subtração fáceis!
	      -também sequencial invertido, ou melhor, sequencial truncando o MSB caso necessite de um bit a mais.
	      'Padding - extensão de sinal' de 'n' para m
		      -se m>n
			  -preenchemos um número positivo com 0s
			  -e um negativo com 1s à esquerda do número.
		      -se m<n (condição para dar certo)
			  -truncamos se todos os bits descartados forem iguais ao bit de sinal.
	      'Adição' comum, apenas ignorando o último carry.
		       O resultado sempre será correto desde que o intervalo não seja excedido!
	      'Subtração' Para fazer A − B podemos fazer A + (−B)!
			  Ou seja, basta tirar o complemento de 2 do subtraendo e somar normalmente.
	      'Overflow' Se o resultado excede o intervalo do sistema
			 Adição de dois números de sinais diferentes nunca causa overflow.
			 Adição de dois números com sinais iguais PODE causae overflow.
			    -Ocorre overflow se o sinal dos adendos é igual, mas o do resultado for diferente, ou se
			     o carry entrando no MSB e o carry saindo no MSB forem diferentes.
			    -No caso de números sem sinal, há overflow se houve carry ou borrow no MSB.
	      'Utilizamos o mesmo circuito tanto para somar, quanto para subtrair'
			-Porém temos que cuidar se estamos somando em complemento de 2 números com sinal (de -8 a 7) ou números sem
			 sinal (de 0 a 15).

       Excess Representation (representação por excesso) - "Excess-B"
	  -número de 'm' bits com valor absoluto M (na representação de binário normal), representa na verdade M-B.
	  -é o próprio número binário menos B.
	  -B é chamado viés do sistema
	  -sistema utilizado em notação de ponto flutuante.
	  -Com 'n' bits, o intervalo é -2⁽n-1⁾ a (2⁽n-1⁾ - 1).
	  -Se temos 8 bits, representamos de -128 a 127. '= 256 valores'
	  -representação sequencial.

  'Representação em Ponto Flutuante'
    -notação padrão para representar números fracionários.
    - v= -1⁽s⁾ . m . b⁽e⁾		s = sinal (0-positivo, 1-negativo)
					m = mantissa
					b = base (IEEE- 10 ou 2, sistemas digitais- 2)
					e = expoente

	single precision (float)		double precision (double)
 sinal		1 bit					1 bit
 expoente	8 bits					11 bits
 mantissa	23 bits					52 bits

 total		32 bits					64 bits

    - De acordo com o expoente, podem ser:
	"Normalizados"
	  -Se 'e'!= 00..00 e 'e'!= 11..11
	  -'e' é um Excess code com BIAS= 2⁽m-1⁾ - 1 (m=nº de bits do expoente)
			      bias		intervalo
	  single precision    127		-126 a 127
	  double precision   1023	       -1022 a 1023
	  -Para a mantissa: M = 1.XXXXXXXX2(o 2 quer dizer que é em binário)
	"Não Normalizados"
	  -Se 'e'=00..00 (ou seja, zero)
	  -'e' = -BIAS + 1 (ou seja, -2⁽m-1⁾)
	  -Para a mantissa: M = 0.XXXXXXXX2(o 2 quer dizer que é em binário)
	  -Usado para representar números próximos de zero.
	  -'gradual underflow' - precisão vai diminuindo à medida que os números ficam menores.
	"Especiais"
	  -se 'e'=11..11
	  -M= 000..000 representa  o infinito positivo e negativo. Geralmente, ocorre ou por divisão por zero ou porque houve overflow.
	  -M!=000.000 representa Not A Number, ou seja, um valor sem representação númerica.

  "Álgebra de Boole"
    - 'and' ((.),&) e 'or' ((+), |) e 'not' ((-), !)
    -Só há 0(conj. vazio ou 'falso') e 1(universo ou 'true').
    -A ́álgebra de Boole não lida com números, mas com variáveis lógicas!
    -Precedência = não > e > ou
    -'Tabela Verdade' - Todas as combinações possíveis das variáveis de entradas estão presentes.
			Tem 2^n linhas, sendo n o número de variáveis da função.
			usado quando se quer provar algo.
    -Veremos como aplicar ́algebra booleana para analisar e projetar circuitos elétricos digitais, o que ́e uma de suas maiores aplicações.
    -Considere um 'universo fundamental U' , por exemplo, os alunos de engenharia da UnB. Podemos gerar sub-conjuntos de U através de
     'operadores de seleção': x(U) o conjunto de todos os alunos de Cálculo, 'x(.) e y(.)'
			      y(U) o conjunto de todos os alunos de SD
    -x(y(U)) = xy = y(x(U)) = yx = conjunto de todos os alunos de Cálculo e SD.
    -x+y = y+x = conjunto de todos os alunos de engenharia que cursam Cálculo ou SD.
      'obs. Usamos aqui o ou-inclusivo, significando que x+y é o conjunto de todos os alunos de engenharia que cursam Cálculo mas não SD, '
            'todos os alunos de engenharia que cursam SD mas não Cálculo, e todos os alunos de engenharia que cursam Cálculo e SD.	  '
    -!x = 1-x

    'Propriedades'
    (0).(0)=0
    (1).(1)=1
    (0).(1)=(1).(0)=0
    (0)+(1)=(1)+(0)=1
    x(x(U)) = x   -->	xx=x

    'Axiomas'
    -identidade		1.x   = x,	0 + x = x
    -aniquilação	0.x   = 0,	1 + x = 1
    -negação		!0    = 1,	!1    = 0

    -idempotência	x + x = x,	x.x   = x
    -complementos	x+ !x = 1,	x.  !x= 0
    -involução		!!x   = x

    -comutatividade	x+y = y+x	x.y = y.x
    -associatividade	((x + y) + z = x + (y + z)	(x·y)·z = x·(y·z)
    -distributividade	x·y + x·z = x·(y + z)		(x + y)·(x + z) = x + (y·z)
    -cobertura		x + x·y = x			x·(x + y) = x
    -combinação		x·y + x· !y = x			(x + y)·(x + !y) = x
    -consenso		x·y + !x·z + y·z = x·y + !x · z		(x + y)·(!x + z)·(y + z) = (x + y)·(!x + z)

      'obs. indução perfeita = mostrar que identidades são verdadeiras para todos os valores (no caso, só assumem 0 e 1!!)'
    "Teorema de De Morgan" pode ser extendida (generalizada)
    1) !(x.y) = !x + !y
    2) !(x + y) = !x . !y
    3) "o dual de uma função aplicada ao complemento das variáveis de entrada ́e igual ao complemento da função"
		  f(dual)(!x1,!x2,...,!xn) = !f(x1,x2,...,xn)

    'Função Dual' - f(índiceD)
      - quando substituímos todos os 'e' por 'ou', 'ou' por 'e', 0 por 1 e 1 por 0.
      - não mexemos nos x e y.

    'Comparar expressões booleanas'
    1) Construindo a tabela verdade das duas expressões;
    2) Manipular as expressões, usando as identidades e teoremas;
    3) Expressar ambas na forma canônica;
	'Forma Canônica Conjuntiva =  soma de produtos'
	'Forma Canônica Disjuntiva =  produto de somas'

	Sabemos que com 3 varáveis, podemos fazer uma tabela verdade com 2³ = 8 linhas.Porém, cada linha da tabela tem duas possibilidades,
	ou 0 ou 1, com isto temos 2^(2³) = 2⁸ = 256 funções possíveis com 3 variáveis.

	  'aqui não se tem repetições de variáveis por termo'
	  -literal		variável ou complemento				X,Y,!X
	  -termo produto	literal ou produto lógico de literais		X,XY, !XYZ
	  -termo soma		literal ou soma lógica de literais		X, X+Y, !X + Z
	  -soma de produtos	soma lógica de termos produtos			X + XY + !XYZ
	  -produto de somas	produto lógico de termos somas			(X).(X + Y)
	  -termo normal		termo produto ou termo soma em que nenhuma	XY!Z, XY
				variável aparece mais de uma vez

	  "mintermo" de 'n' variáveis é um produto normal com exatamente 'n' literais.
				mintermo de 4 variáveis: X.Y.!Z.!W

	  "maxtermo" de 'n' variáveis é uma soma normal com exatamente 'n' literais.
				maxtermo de 4 variáveis: X + Y + !Z + !W

	  'mintermo, maxtermo e tabela verdade'
	    - mintermo = um termo produto que tem valor 1 em exatamente uma linha da tabela verdade.
	    - maxtermo = um termo soma que tem valor 0 em exatamente uma linha da tabela verdade.

	    Linha  X  Y  Z	F	Mintermo	Maxtermo
	      0	   0  0  0   F(0,0,0)	!X.!Y.!Z	X + Y + Z
	      1	   0  0  1   F(0,0,1)   !X.!Y. Z	X + Y +!Z
				     ...
	      7	   1  1  1   F(1,1,1)	 X. Y. Z       !X +!Y +!Z

	    - Podemos representar facilmente uma função qualquer como uma soma de mintermos simplesmente multiplicando o valor da função em
	      cada linha pelo mintermo daquela linha.
		F(X,Y,Z) = F(0,0,0).!X!Y!Z + F(0,0,1).!X!YZ + ... + F(1,1,1).XYZ

	    - E comum representar mintermos pelo seu número na tabela verdade. Assim, representamos a tabela verdade como:
		F(X,Y,Z) = SOM_em_xyz(0,3,4,7) = !X·!Y·!Z + !X·Y·Z + X·!Y·!Z + X·Y·Z.

	    - Dada uma função booleana qualquer, podemos chegar na forma canônica simplesmente completando os termos (utilizando o axioma do
	      complemento, X + !X = 1).

	    - Além de mintermos, podemos expressar uma função usando maxtermos. De maneira geral, temos que mi = !Mi , ou seja, o mintermo e o
	      maxtermo de mesmo ́ındice são complementares.

	    - Da mesma forma, podemos representar facilmente uma função qualquer como um produto de maxtermos simplesmente multiplicando o
	      complemento do valor da função em cada linha pelo maxtermo daquela linha.
		F(X,Y,Z) = (!F(0,0,0).(X + Y + Z)).(!F(0,0,1).(X + Y + !Z)) + ... + (!F(1,1,1).(!X + !Y + !Z))

	    - Da mesma forma, ́e comum representar maxtermos pelo seu número na tabela verdade. Note que, agora, procuramos os maxtermos com
	      valor 0 na tabela verdade.
		F(X,Y,Z) = PROD_em_xyz(1,2,5,6) = (X + Y + !Z).(X + !Y + Z).(!X + Y + !Z).(!X + !Y + Z)

	    'Convertendo mintermos em maxtermos e vice-versa' basta utilizar os índices de maxtermos que não aparecem na expansão de
	     mintermos (ou vice-versa).
		F(X,Y,Z) = SOM_em_xyz m(0,3,4,7) = PROD_em_xyz M(1,2,5,6)

	    'Encontrando a forma canônica do complemento da função'
	    Da mesma forma, para encontrar a forma canônica do complemento da função, basta utilizar para a expansão de F os ́ındices de
	    mintermos que não aparecem na expansão de mintermos de F . A mesma ideia pode ser aplicada para maxtermos, isto ́e, utilizar para
	    a expansão de F os ́ındices de maxtermos que não aparecem na expansão de maxtermos de F.
		F(X,Y,Z) = SOM_em_xyz m(0,3,4,7)
		!F(X,Y,Z) = SOM_em_xyz m(1,2,5,6)

    4) Uma lista de mintermos usando a notação SOM;
    5) Uma lista de maxtermos usando a notação PROD.

  "Portas Lógicas"
  - Diagrama lógico - desenho esquemático de portas simbólicas (gate symbols) conectadas por linhas e usadas para 'representar função booleanas'.
  - 3 portas lógicas básicas: E , OU , NÃO( ou porta inversora). Com apenas estes 3 símbolos desenhamos diagramas lógicos para qualquer função
    booleana.
  - Podemos utilizar portas lógicas E e OU de múltiplas entradas.
  - 'Porta XOR (OU-EXCLUSIVO)' - saída é 1 se e somente se as entradas são diferentes, e 0 se forem iguais.
	'comutatividade' x XOR y = y XOR x
	'associatividade' (x XOR y) XOR z = x XOR (y XOR z)
	- F(x,y) = x XOR y = x.y' + x'y
	- Em aritmética módulo-2 , a porta XOR funciona exatamente como a adição módulo-2.
	- XOR é muito usado para 'bit paridade' = se qtd de entradas for ímpar resulta no bit 1, se for par, resulta em 0 sempre.
				      'se entrada for ímpar, adiciona-se um bit 1 ao final para indicar a paridade'
	- XOR só faz sentido para duas entradas.
  - operador 'bubble' o = também serve para negar.
  - 'Três últimas portas lógicas básicas'
      'NAND' porta AND com saída invertida.	(xy)'			primeiro operação, depois nega a saída da operação
      'NOR' porta OR com saída invertida.	(x + y)'
      'NXOR' porta XOR com saída invertida.	xy + x'y'

  - As portas lógicas que vimos podem ser implementadas utilizando transistores.  Transistores são dispositivos de 3 terminais que agem como
   uma resistência controlada por tensão. A tensão aplicada no terminal de entrada ( Vin ) controla a resistência entre os demais terminais.
   Em um negador, se entrada é 0V, terra é desligado e passa para Vout o Vdd de 5V.
		  se entrada é 5V, terra é ligado e passa para Vout 0V do terra, pois Vdd está desligado.

  - Um 'modelo' é uma representação de um dispositivo real. Em relação à realidade, temos duas limitações:
      'Fan-out'
      Número de entradas que a porta lógica pode alimentar sem eceder a sua especificação de carga de pior caso. Depende tanto das caracterís-
      ticas de entrada quanto das de saída. De modo geral, uma porta lógica tem dois fan-outs diferentes, um para o nível lógico 0 e outro para
      o nível lógico 1, 'e o fan-out médio da porta será utilizado como o pior deles'.
      'Atraso'
      A saída não responde imediatamente após a mudança de entrada. Em geral, ela responde após um certo atraso.

  - Portas lógicas podem ser encontradas na forma de 'circuitos integrados (CIs)'.
     - No mesmo CI, em geral temos várias portas lógicas.
     - o CI deve ser alimentado. Deve-se fornecer tensão e uma referência gnd.
     - Características de 'fan-in', 'fan-out', 'atraso' e outros são fornecidos pelo fabricante no 'datasheet' do CI.
     'famílias lógicas dos CIs'
      -CMOS(Complementary Metal Oxide Semiconductor) , ECL(Emiter Coupled Logic) e TTL(Transistor-Transistor Logic).

  'obs' É mais fácil implementar portas NANDs e NORs com transistores do que implementar portas ANDs e ORs.
	É importante implementar circuitos usandos apenas NANDs e NORs, dado que são 'universais' - a partir deles posso encontrar os 3 básicos.

  "Mapas de Karnaugh"
  Em especial, as formas canônicas que vimos são particularmente grandes, pois o número de mintermos e maxtermos (e, portanto, de portas
  lógicas) cresce exponencialmente com o número de variáveis.

  Chamamos de minimização de circuitos a redução do número e do tamanho (número de entradas) das portas lógicas necessárias para construir
  esse circuito.

  A ideia do mapa de karnaugh ́e representar a tabela verdade de uma função booleana de forma gráfica.

  'Os mintermos de células vizinhas diferem por apenas um bit!'

  Um conjunto de 2^i células pode ser agrupada se existem i variáveis da função lógica que incluem todas as 2^i combinações naquele grupo,
  enquanto as outras n − i variáveis tem o mesmo valor naquele grupo.
  O termo produto resultante tem n − i literais, e o termo produto contém o complemento de cada variável que tem o valor 0 para todo o grupo,
  e a variável que tem o valor 1 para todo o grupo.

  'Isso significa que podemos agrupar ́areas retangulares! E podemos afrouxar a definição de retângulos para considerar as bordas do mapa.'

  'ex do que se considerar'
  Fizemos um grupo de 2² = 4 células ( i = 2 ).
  X e Z não mudam dentro do grupo. W e Y mudam dentro do grupo. Além disso,todas as combinações de W e Y (00,01,10 e 11 ) estão contidas no
  grupo. Logo, o termo produto resultante terá n − i = 4 − 2 = 2 literais, X e Z .
  Os elementos do grupo são: WXYZ = 0101 , 0111 , 1101 , 1111 . X = 1 para todos os elementos do grupo. Z = 1 para todos os elementos do grupo.
  Logo, o termo produto resultantante ́e: X · Z!

  O mapa de Karnaugh ́e conectado de forma toroidal ! As bordas são, na verdade, adjacentes.

  'Usando o mapa para encontrar a forma mínima da expressão booleana'
  A soma mínima de uma função lógica F(X0,X1,...,Xn) ́e uma expressão em soma de produtos de F de tal forma que nenhuma outra soma de produtos
  de F tenha menos termos produtos, e qualquer outra expressão para F tenha pelo menos o mesmo número de literais.

  'implica' Uma função lógica P(X0,X1,...,Xn) implica uma outra função lógica F(X0,X1,...,Xn) se para todas as combinações de entrada onde P=1,
  F=1 também. Ou seja, se P implica  F ( P ⇒ F ), F ́e 1 sempre que P ́e 1 , e talvez F seja 1 em algumas combinações onde P seja 0 . Dizemos
  também que F inclui P ou que F cobre P.

  'implicante primo' Um implicante primo de uma função F(X0,X1,...,Xn) ́e um termo produto P(X0,X1,...,Xn) que implica F de tal forma que, se
  qualquer variável for removida de P , o resultado não implicará F .
  No mapa de Karnaugh, um implicante primo de F ́e um agrupamento que satisfaz a nossa regra de combinação de tal forma que, se tentarmos
  aumentá-lo, ele necessariamente iá cobrir um ou mais 0s.

  'Uma soma mínima ́e uma soma de implicantes primos.'
  Logo, para encontrar a soma mínima, não precisamos considerar nenhum agrupamento que não seja um implicante primo.

  'Soma completa'
  A soma de todos os implicantes primos de uma função lógica ́e chamada de soma completa.
  Uma soma completa não necessariamente ́e mínima.

  'Célula 1 distinta'
  Uma célula 1 distinta é uma combinação de entrada que ́e coberta por apenas um implicante primo.

  'Implicante Primo essencial'
  Um implicante primo essencial ́e um implicante primo que cobre uma (ou mais) célula 1 distinta.
  Como um implicante primo essencial ́e o ́unico implicante primo que cobre alguma célula 1 distinta, ele deve estar incluído na soma mínima
  (senão, a soma estaria necessariamente incompleta).

  'Algoritmo'
  Logo, o primeiro passo na seleção de implicantes primos ́e simples: identificamos as células 1 distintas e os implicantes primos essenciais
  correspondentes, e incluímos esses termos na soma.
  Depois, precisamos determinar como cobrir as células 1 que não foram cobertas pelos implicantes primos essenciais (se houver).

  'Eclipsar'
  Dados dois implicantes primos P e Q em um mapa reduzido (isto ́e, após a retirada dos implicantes primos essenciais), dizemos que P eclipsa
  Q se P cobre pelo menos todas as células 1s cobertas por Q.
  Se P não custa mais do que Q (isto ́e, se P tem menos literais do que Q ), então remover Q da consideração não pode nos impedir de chegar a
  soma mínima. P ́e, pelo menos, tão bom quanto Q .
  'e então pegamos o retângulo maior!'
  'O que foi pego após a retirada dos implicantes primos é chamado de implicante primo secundário'

  'Para funções que não tem nenhum implicante primo'
     Método Branching
      Começando com uma célula 1 qualquer, selecionamos um implicante primo que cobre essa célula como se ele fosse essencial, e removemos ele
      do mapa. Isso simplifica o problema, e podemos aplicar o método visto anteriormente (identificar as células 1 distintas, identificar os
      implicantes primos essenciais, etc...). Quando terminarmos, repetimos o processo utilizando o outro implicante primo (isto  ́e, aquele
      que deixamos de fora inicialmente), gerando uma segunda tentativa de soma mínima. Finalmente, comparamos o custo de todas as alternativas
      e escolhemos a menor.

  'Simplificando produto de somas'
  -Cada 0 no mapa de Karnaugh corresponde a um maxtermo.
  -Entretanto, existe uma forma mais simples de se obter o produto mínimo, uma vez que sabemos como obter a soma mínima.
  -O primeiro passo  ́e complementar a função lógica F, obtendo F'. Utilizando as técnicas já vistas, encontramos o resultado da soma de
   produtos da função lógica F'.
  -Finalmente, utilizando o Teorema de De Morgan generalizado, podemos obter o produto mínimo de F'' = F.

  'Don’t Cares, Indiferenças ou Irrelevâncias'
  -Ás vezes, a especificação do circuito  ́e feita de tal forma que a saída não importa para algumas combinações de entrada.
  -São combinações de entrada para as quais a saída não importa, e marcadas na tabela verdade e no mapa de Karnaugh com o símbolo
   x, d ou −.
  -Função com dont cares é chamada 'função de especificação incompleta'
     Utilizar os don’t cares para formar agrupamentos maiores.
     Não utilizar agrupamentos contendo apenas don’t cares.

  'Minimização com Múltiplas Saídas'
  A ideia básica da minimização com múltiplas saídas  ́e encontrar agrupamentos comuns a todas as saídas, mesmo que estes agrupamentos não
  sejam implicantes primos.

  'Mapas com 5 variáveis'
  Em mapas de 5 variáveis, devemos ter cuidado com o 2^1, para que desprezemos exatamente a quantidade i de variáveis.
  Agrupamentos com 4 espaços em linha ou coluna não contam.

  As i=3 variáveis agrupadas: V,W e X.
  Mas será que todas as 2³ = 8 combinações foram contempladas?
  As combinações no agrupamento são: 001, 011, 010 e 110.
  existem ainda 4 combinações que não foram contempladas no agrupamento: 000,111,110 e 100.
  Logo o agrupamento não pode ser feito.

  1) Desenhamos o mapa como dois mapas de 4 variáveis, sendo a que sobrou 0 no primeiro e 1 no segundo.

  Os agrupamentos são feitos como se fosse um mapa de 4 variáveis, sendo possível também agrupar quando a variável está exatamente em cima
  da mesma posição do outro mapa.

  2) Usamos variáveis introduzidas

  A ideia básica  ́e expressar F em termos de uma variável V . Para funções de especificação completa (isto  ́e, sem don’t cares ), temos
  quatro possibilidades:

      V | F | F(V)		V | F | F(V)
      0   0    0		0   1	 1
      1   0			1   1

      V | F | F(V)		V | F | F(V)
      0   0    V		0   1	V'
      1   1			1   0

  Com isto podemos representar o mapa com 1 variável a menos. Geralmente colocamos F em função da última variável.

  Esta minimização é realizada em duas etapas:
      1) Na primeira etapa, devem ser cobertos os termos contendo Z e Z', sendo que não é necessário cobrir os termos 1s(não nessa etapa).
	 Devemos lembrar que os termos Z podem ser associados, em ordem de prioridade, com os termos Z e 1 (pois 1 = Z + Z'), e que os termos
	 Z' podem ser associados, em ordem de prioridade, com os termos Z' e 1 (pelo mesmo motivo anterior).

	 Note que devemos multiplicar o valor do termo gerado pelo agrupamento pelo valor da variável dentro do mapa.

      2) Redesenhamos o mapa fazendo as seguintes substituições:
	      Termo original				Substituído por
		 Z, Z', 0				     0
	1, se foi associado com Z e Z'			     d
	1, se não foi associado com Z e Z'		     1

	e aí agrupamos os 1's novamente.

  'Riscos Estáticos e riscos dinâmicos'
    'Timing Hazards (Azares Estáticos)'
      -Os métodos de análise vistos até aqui não levam em consideraçlão os atrasos das portas lógicas, analisando apenas o comportamente
       em regime permanente ('steady state behaviour') do circuito.
      -Isto  ́e, estes métodos analisam apenas o comportamento do circuito assumindo que as entradas estavam estáveis por um tempo
       relativamente longo (comparado com o atraso típico das portas).
      -Devido ao atraso, o comportamento transitório (transient behaviour) do circuito pode ser diferente do comportamento em regime
       permanente!
      -Em particular, o circuito pode produzir um pulso curto ('glitch') em uma situação onde a análise em regime permanente não deveria
       mudar. Quando pode ocorrer um 'glitch', dizemos que existe um "azar" estático ('static hazard').
      -As vezes  ́e difícil prever se o glitch vai de fato ocorrer, pois isso depende do atraso das portas. Ainda assim, o projetista deve
       estar preparado para eliminar estes hazards(isto  ́e, a possibilidade do glitch), mesmo que a probabilidade de ocorrência seja pequena.
      -Dependendo de como o circuito será utilizado, o glitch pode ou não afetar o comportamento do sistema. No entanto, em um tipo de
       circuito muito importante, os circuitos sequenciais, glitches podem ser muito danosos e hazards devem ser eliminados.

       'risco estático 1' ou static 1 hazard: possibilidade de um circuito produzir um glitch em 0 quando a saída deveria ser 1.
	  É um par de combinações de entrada que:
	    "difere por apenas uma variável"
	    "ambas as combinações geram saída 1, de forma que é possível ocorrer um pulso em 0 na transição entre essas combinações de entrada"

       'risco estático 0' ou static 0 hazard: possibilidade de um circuito produzir um glitch em 1 quando a saída deveria ser 0.
	  É um par de combinações de entrada que:
	    "difere por apenas uma variável"
	    "ambas as combinações geram saída 0, de forma que é possível ocorrer um pulso em 1 na transição entre essas combinações de entrada"

       'o risco estático 0 é o dual do risco estático 1.Se um circuito AND-OR possui um risco estático 1, o dual OR-AND possuirá risco'
       'estático 0'

       Um circuito bem projetado em soma de produtos de dois níveis (AND-OR, e sua implementação NAND-NAND) não tem 'risco estáticos 0'.
       No entanto, pode ter riscos estáticos 1.

       Para resolver esse problema, podemos adicionar outra porta para gerar um consenso entre as entradas. O mapa gerado ́e redundante
       (logo, não  ́e mínimo), mas o glitch não pode ocorrer, isto  ́e, o risco estático 1 foi eliminado.

       Algo similar ocorre com circuitos em produtos de somas: um risco estático 1 não pode ocorrer, mas um risco estático 0 pode.

       Estes hazards podem ser detectados e eliminados observando os 0s adjacentes no mapa de Karnaugh.

    O 'risco dinâmico (dynamic hazard )' é a possibilidade de uma saída mudar múltiplas vezes em resposta a uma  ́unica mudança na entrada.
    Esse tipo de risco pode ocorrer se existem múltiplos caminhos com atrasos diferentes.
    'ex' Quando a entrada muda de XYZ = 000 para XYZ = 010 , a saída muda de estado 3 vezes antes de se estabilizar.

    Riscos dinâmicos 'não' ocorrem em circuitos de dois níveis AND-OR e OR-AND (e seus equivalentes NAND-NAND e NOR-NOR) bem projetados,
    mas podem ser difíceis de encontrar em circuitos com múltiplos caminhos.

    Finalmente, se o custo não for um problema, um método “força-bruta” de se obter um circuito hazard-free ́e utilizar a soma completa ,
    isto  ́e, a soma de todos os implicantes primos do circuito.

  'HDL design'
  Desde os anos 90, com as linguagens HDL (hardware description language) sintetizáveis em conjunto com PLDs
  (programmable logic devices), essa estrutura mudou radicalmente.

    'PALASM' (PAL Assembler), in´ıcio dos anos 80.
    'ABEL' (Advanced Boolean Equation Language), 1983.
    'VHDL' (VHSIC Hardware Description Language), 1983.
    'Verilog'(IEEE 1364), 1984

    A situação em HDL é similar. O circuito projetado usando VHDL ou Verilog pode n˜ao ser t˜ao bom quanto um
circuito otimizado “à m˜ao”, mas essas ferramentas facilitam a criação de circuitos maiores e mais complexos.
Vários circuitos hoje em dia possuem milh˜oes (ou mesmo bilh˜oes) de portas lógicas.
    Gera, quando sintetizado, um circuito lógico!
    Criar circuitos a partir de descrições VHDL, em um processo chamado de síntese.


'editor de texto'
'compilador' - "compila", verificando a sintaxe e criando um arquivo intermediário que é a descrição não ambígua
das interconexões e operações lógicas.
'sintetizador' - realiza o programa em uma implementação específica, como PLD, CPLD, FPGA ou ASIC. Utiliza
bibliotecas dessa plataforma, como flip-flops, multiplexadores, decodificadores, etc.. e tenta inferir como
implementar o código utilizando esses elementos.
'simulador' - utiliza o código HDL e uma sequência de entradas para simular o circuito. A sequência de entradas
pode ser descrita por outro programa HDL, chamado de test bench, ou descrita graficamente utilizando um waveform
editor.
'template generator'
'schematic viewer' - cria um diagrama esquemático baseado no código HDL. Esse esquemático representa a função que
o circuito final vai realizar, mas a implementação final pode ser bem diferente desse esquemático.
'translator' - adapta o programa compilado para o dispositivo real, utilizando os recursos disponíveis naquele
dispositivo.
'timing analyzer' - calcula os atrasos e mostra o caminho crítico do sistema.
'back annotator' - insere atrasos na descrição do código, de forma que o circuito pode ser simulado com esses
atrasos.

    "simuladores lógicos" - capazes de simular circuitos documentados em VHDL.
    "síntese" - criar circuitos a partir de descrições VHDL.

    - Especificações funcionais podem usar tanto um algoritmo comportamental(behavioral) quanto uma estrutura em hardware.
    - Concorrência, temporização e clocking podem ser bem modelados.
    - Podem ser utilizadas tanto estruturas sequenciais síncronas como assíncronas.
    - A operação lógica e o comportamento no tempo podem ser simulados.

    'VHDL n˜ao é case sensitive'
    'Declarações s˜ao terminadas com ; '
    'Comentários s˜ao escritos com o identificador --'
    'VHDL foi projetado com as ideias da programação estruturada'

    "entity" - define a interface (isto é, as entradas e saídas do módulo).
    "architecture" - define uma descrição detalhada do funcionamento do módulo. É a parte onde se descreve o que um módulo faz, isto é, descreve a
                     implementação interna do módulo.
                     VHDL permite que se definam várias architectures para uma mesma entity. Isto porque, dependendo do código escrito, o circuito
                     sintetizado pode ser bem diferente. Isto possibilita que se possam testar várias alternativas de implementação para um mesmo
                     circuito (por exemplo, uma mais rápida, uma menor, uma que n˜ao acarrete em riscos, etc...).
                     Existem vários modelos de se escrever a architecture: dataflow, behavioral, structural e modelos híbridos entre estas. A forma de
                     se codificar o circuito é bem diferente dependendo do modelo!
    "port" - um sinal que faz interface com o mundo exterior.
    "signals" - nome que damos às variáveis em VHDL (sinais).
        "in" - entrada(este sinal não pode ser alterado dentro da entidade).
        "out" - saída(este sinal não pode ser lido dentro da entidade).
        "buffer" - é um sinal de saída que também pode ser lido dentro da entidade.
        "inout" - entrada e saída.
    Tipos "bit", "bit_vector", -> "boolean", -> "character", -> "integer","severity_level","string", "time",
    "integer" - define números inteiros no intervalo de -2^31 + 1 até 2^31 - 1.
    "boolean" - true e false.
    "character" - todos os ASCII mais os caracteres definidos na ISO 8-bit character set.
    "enumerated" - usado quando queremos criar variáveis de máquina de estados.
                        type traffic_light_state is (reset, stop, wait, go);
    "biblioteca IEEE: STD_LOGIC" - tipo de dado mais útil que o BIT, pois além dos valores '0' e '1', ele pode assumir outros sete valores:
                        Valor Significado
                        ’U’   Unitialized
                        ’X’   Forced Unknown
                        ’0’   Forcing 0
                        ’1’   Forcing 1
                        ’Z’   High Impedance
                        ’W’   Weak Unkwnown
                        ’L’   Weak 0
                        ’H’   Weak 1
                        ’-’   Don’t Care
    "subtypes de um type"
                        subtype twoval logic is std logic range ’0’ to ’1’
                        subtype fourval logic is std logic range ’X’ to ’Z’
                        subtype negint is integer range −2147483647 to −1
                        subtype bitnum is integer range 31 downto 0
    "Arrays já implementados ou criáveis"
                        type type_name is array (start to end) of element_type;
                        type type_name is array (start downto end) of element_type;

                        signal var_down : STD_LOGIC_VECTOR (3 downto 0);
                        signal var_up : STD_LOGIC_VECTOR (0 to 3);
                        var_down(2) <= ’1’;
                        var_down <= “0011”;
    "Concurrent Statements" Mais importantes declarações
            signal assignment
            conditional signal assignment
            selected signal assignment
            process statement
    "Operador relacional" <=. Com este operador, e com os operadores simples (AND, NAND, OR, NOR, NOT, XOR e XNOR) podemos descrever todos os
    circuitos que vimos até aqui!


    entity entity_name is                               port (
         [port clause]                                      signal_name : mode signal_type;
    end entity_name;                                        signal_name : mode signal_type;
                                                            signal_name : mode signal_type;
                                                                       ...
                                                            input_1 : in BIT;
                                                            output_1: out BIT;
                                                                       ...
                                                        );

    entity meu_circuito is
        port ( inputs : in STD_LOGIC_VECTOR (3 downto 0);
            outputs : out STD_LOGIC_VECTOR (2 downto 0));
    end meu circuito;

architecture  architecture_name of entity_name is
              type declarations
              signal declarations
              constant declarations
              function declarations
              procedure declarations
              components declarations
       begin
              concurrent-statement
              ..
              concurrent-statement
        end   architecture name;

 1: library IEEE;
 2: use IEEE.STD LOGIC 1164.ALL;
 3:
 4: entity meu circuito is
 5:  port (A,B,C,D: in STD LOGIC;
 6:        F : out STD LOGIC);
 7: end meu circuito;
 8:
 9: architecture meu_circuito_op of meu_circuito is
10:     signal P1,P2,P3 : STD LOGIC;
11: begin
12:     P1 <= A and not(B);
13:     P2 <= not(A) and B and D;
14:     P3 <= A and C;
15:     F <= P1 or P2 or P3;
16: end meu circuito op;

1: architecture meu_circuito_op_delay of meu_circuito_is
2:      signal BN,AN,P1,P2,P3 : STD LOGIC;
3: begin
4:      AN <= not(A) after 10 ns;
5:      BN <= not(B) after 10 ns;
6:      P1 <= (A and BN) after 10 ns;
7:      P2 <= (AN and B and D) after 10 ns;
8:      P3 <= (A and C) after 10 ns;
9:      F <= (P1 or P2 or P3) after 10 ns;
10: end meu_circuito_op delay;

  - Todas as operações definidas na arquitetura são concorrentes.

  'VHDL Relational Operators'
                                    =   equivalência
                                    /=  n˜ao-equivalência
                                    <   menor que
                                    <=  menor ou igual a
                                    >   maior que
                                    >=  maior ou igual a
  'Modelo dataflow'
  Modelo de descrição que usamos até agora, com ele podemos visualizar bem um circuito e suas operações. Operadores mais usados:
    "1) signal assignment operator" (<=)
            -associa um alvo a uma expressão.

    "2) conditional signal assignment"
            -associa um alvo à várias expressões, cada uma com uma consição associada.
            -As condições individuais s˜ao avaliadas sequencialmente até que a primeira condição seja verdadeira. Quando isso acontece, a
             express˜ao associada à essa condição é designada ao alvo. Apenas uma designação é feita.
            -Em geral, a cláusula else é requerida, pois o conjunto de condições combinadas deve cobrir todas as possíveis combinações de
             entrada.
3: F <= ’1’ when ((A = ’0’) AND (B = ’1’) AND (C = ’1’)) else
4:      ’1’ when ((A = ’1’) AND (B = ’0’) AND (C = ’1’)) else
5:      ’1’ when ((A = ’1’) AND (B = ’1’) AND (C = ’0’)) else
6:      ’1’ when ((A = ’1’) AND (B = ’1’) AND (C = ’1’)) else
7:      ’0’;

2:  signal ABC : STD LOGIC VECTOR (2 downto 0);
3: begin
4:  F <= ’1’ when (ABC = “011”) else
5:       ’1’ when (ABC = “101”) else
6:       ’1’ when (ABC = “110”) else
7:       ’1’ when (ABC = “111”) else
8:       ’0’;
9: end maioria dataflow 2;

    "3) selected signal assignment"
            -associa um alvo à várias express˜oes utilizando uma única condiç˜ao associada, que escolhe qual das express˜oes será designada
             ao alvo.
            -As escolhas para cada cláusula devem ser mutualmente exclusivas e devem incluir todas as possíveis combinaç˜oes de entrada. A
             palavra-chave 'others' pode ser utilizada na última cláusula para cobrir todas as combinaç˜oes que n˜ao foram cobertas.

2:  signal ABC : STD LOGIC VECTOR (2 downto 0);
3: begin
4:  ABC <= A & B & C;   //operador de concatenação para "juntar" vários sinais em um vetor. É bastante usado em VHDL, pois simplifica
5:                      //o uso da estrutura with-select e possibilita utilizar módulos que usam vetores com sinais separados.
6:  with ABC select
7:      F <= ’0’ when “000”,
8:           ’0’ when “001”,
9:           ’0’ when “010”,
10:          ’1’ when “011”,
11:          ’0’ when “100”,
12:          ’1’ when “101” |“110” |“111”,
13:          ’0’ when others;
14:
15: end maioria dataflow 3;

  'Modelo Estrutural'
  -Se baseia no encapsulamento de circuitos em 'components'.
  -Antes de ser instanciado, um component deve ser declarado na definiç˜ao da architecture. A declaraçao de um component é essencialmente
   a mesma da declaraç˜ao da entity: ela lista o nome, o modo, e o tipo de cada uma das suas portas.
  -Quando um component é criado (instanciado), um instância da entity é criada para cada declaração de component que chama seu nome, e cada
   instância deve ser rotulada com um nome diferente.

1: architecture maioria_structural_1 of maioria is
2:      component porta_and_2 is
3:          port (A,B: in STD LOGIC;
4:                  S: out STD LOGIC);
5:      end component;
6:
7:      component porta_or_3 is
8:          port (A,B,C: in STD LOGIC;
9:                    S: out STD LOGIC);
10:     end component;
11:
12:     signal P1,P2,P3 : STD LOGIC;
13: begin
14:     U1: porta_and_2 port map(A,B,P1);
15:     U2: porta_and_2 port map(A,C,P2);
16:     U3: porta_and_2 port map(B,C,P3);
17:     U4: porta_or_3 port map(P1,P2,P3,F);
18: end maioria_structural_1;

    "VHDL generate statement"
    -Em alguns circuitos comuns, é necessário criar múltiplas cópias de uma estrutura em particular dentro de uma architecture. Por exemplo,
     um circuito somador de n (ripple adder) bits pode ser criado pelo cascateamento de n somadores de 1 bit (full adder). Para simplificar
     a declaraç˜ao desse tipo de circuito, VHDL oferece uma declaraç˜ao chamada generate que permite que se criem estruturas repetitivas
     utilizando um tipo de for loop.

7:      component INV is
8:          port (X: in STD LOGIC;
9:                Y: out STD LOGIC);
10:     end component;
11: begin
12:     g1: for i 7 downto 0 generate
13:         U1: INV port map (X(i),Y(i));
14: end generate;

  'Modelo Behavioral'
  -O modelo comportamental (behavioral) n˜ao fornece nenhum detalhe de como implementar o módulo em hardware, ou seja, o código VHDL escrito
   nesse modelo n˜ao reflete necessariamente como o circuito vai ser implementado quando sintetizado.
  -O estilo comportamental descreve como a saída do circuito reage (se comporta) dadas as entradas do circuito. E trabalho do sintetizador
   decidir como será à implementaçao do circuito.
  -O conceito mais importante do modelo comportamental é o 'process statement'.

    "Process Statement"
    -Em VHDL, um process é uma coleçao de sequential statements que executam em paralelo com outros concurrent statements. Isto é, dentro
     de um process, as declaraç˜oes s˜ao sequenciais, mas um process é concorrente com as outras declaraç˜oes concorrentes que vimos
     (concurrent signal assignment, conditional signal assignment, selected signal assignment e inclusive outros process).
    -Utilizando um process, podemos especificar uma interaç˜ao complexa de sinais e eventos de tal forma que ela é executada em “tempo zero”
     na simulaçao e que gere um circuito combinacional ou sequencial que execute a operaçao modelada diretamente.
    -Nos operadores concurrent signal assignment do modelo dataflow, a qualquer momento que ocorrer uma mudança nos sinais listados do lado
     direito do operador, essa mudança faz com que o lado esquerdo (isto é, o alvo) da express˜ao seja re-avaliado.
    -No caso do process, a qualquer momento que ocorrer uma mudança em um dos sinais listados na sensitivity list do process, todos os
     sequential statements do process s˜ao executados. Ou seja, a execuç˜ao do processo é controlada pelos sinais que s˜ao colocados na sua
     sensitivity list.
    -Um process em VHDL tem apenas dois estados: running ou suspended. Um process está inicialmente no estado suspended: quando qualquer
     sinal em sua sensitivity list mudar, o process vai para o estado running, iniciando no primeiro sequential statement e continuando até
     o último. Se, durante a execuç˜ao do process algum outro sinal de sua sensitivity list mudar, ele será executado novamente. Isto
     continua até que o process seja executado sem que nenhum desses sinais mude (ou seja, até que ele se estabilize).
    - Tipos principais: 'signal and variable', 'if' e 'case'.
    - signal assignemnt <=
      variable assignment :=

3:      process (A,B,C)
4:          variable P1,P2,P3 : STD LOGIC;
5:      begin
6:          P1 := A and B;
7:          P2 := A and C;
8:          P3 := B and C;
9:          F <= P1 or P2 or P3;
10:     end process;

    -Dentro de um process, n˜ao podemos declarar novos sinais, podemos apenas declarar variáveis. Uma variável em VHDL n˜ao é visível de
     fora do process, mas elas mantém seu valor quando o process n˜ao estiver sendo executado (isto é, quando ele estiver no estado
     suspended).
    -Dependendo do seu uso, uma variável pode ou n˜ao se tornar um sinal no circuito sintetizado. Enquanto um sinal tipicamente corresponde
     a um fio no circuito físico, as variáveis s˜ao efêmeras.
    -A principal diferença é que, dentro de um process, a designação de variáveis é executada imediatamente, enquanto a designaç˜ao de
     sinais é executada após o simulador completar a execuçao do process. Logo, se sinais forem usados em condiç˜oes ou express˜oes, devemos
     lembrar desse detalhe, pois isso pode levar a códigos que n˜ao funcionam da forma desejada.

     "if statement"
     -Diferente do conditional signal assignment, as condições não precisam cobrir todas as opções possíveis.
5:      if ((A = ’1’) and (B = ’1’)) then F <= ’1’;
6:      elsif ((A = ’1’) and (C = ’1’)) then F <= ’1’;
7:      elsif ((B = ’1’) and (C = ’1’)) then F <= ’1’;
8:      else F <= ’0’;
9:      end if;

     "case statement"
     -Similar ao selected signal assignment, as escolhas precisam cobrir todas as opções possíveis e devem ser mutuamente excludentes.
12:     ABC := ConvVector(A,B,C);
13:     case ABC is
14:         when “011” =>F <= ’1’;
15:         when “101” =>F <= ’1’;
16:         when “110” |“111” =>F <= ’1’;
17:         when others =>F <= ’0’;
18:     end case;

     "Funções"
     -Uma funç˜ao em VHDL, como em linguagens de programaç˜ao, aceita um número de argumentos e retorna um resultado. Além disso, a funçao
      pode declarar variáveis (que só existem no escopo da funç˜ao), e seu corpo é formado de sequential statements. Funçoes podem ser
      chamadas dentro de um process (onde será chamada quando aquela linha for executada) ou dentro da architecture (onde será chamada de
      forma concorrente).

      "Loop"
      -Tipo mais simples de estrutura de repetição. Cria um loop infinito, que pode ser utilizado na simulação para gerar um sinal de
       relógio (clock). Como é uma estrutura sequencial, ele pode ser usado apenas em process e functions.
      -'exit' sai do loop executando a instrução seguinte ao laço. (break)
      -'next' pula as instruções que faltam e inicia um novo loop. (continue)

      "for"
      -Cria um laço de repetição finito. Note que a variável do loop é criada implicitamente.Como é uma estrutura sequencial, ele pode ser
       usado apenas em process e functions.

      "while"
      -Cria laço condicionado. Só no process e functions.
3: process(A,B,C)
4:      variable ABC : STD LOGIC VECTOR (1 to 3);
5:      variable cont: integer;
6:      begin
7:          ABC := A & B & C;
8:          cont := 0;
9:          for i in 1 to 3 loop
10:             if (ABC(i) = ’1’) then
11:                 cont := cont + 1;
12:             end if;
13:         end loop;
14:
15:     if (cont >= 2) then F <= ’1’;
16:     else F <= ’0’;
17:     end if;
18: end process;

      "VHDL Time Dimension"
      Na simulação, tudo ocorre em tempo zero. Mas também podemos simular o atraso dos circuitos, utilizando por exemplo.
                        Z <= ’1’ after 4 ns when X=’1’ and Y=’0’
                             else ’0’ after 3 ns;
      Também podemos simular atraso dentro de process e functions.
1: process
2: begin
3:      A <= ’0’; B <= ’0’;
4:      wait for 10 ns;
5:      A <= ’0’; B <= ’1’;
6:      wait for 10 ns;
7:      wait;
8: end process;

       "VHDL simulation"
       Para testar, podemos ou usar um dispositivo FPGA ou com um outro código VHDL.
       Este código de teste tem as seguintes características:
            -É uma entity sem sinais de entrada ou saída.
            -Acessa o módulo que se deseja testar via uma component.
            -Usa um process para testar todas as possibilidades de entrada (pelo menos as desejadas).
4: entity sim maioria is
5: end sim maioria;
6:
7: architecture sim maioria op of sim maioria is
8:      component maioria is
9:      port (A,B,C: in STD LOGIC;
10:         F: out STD LOGIC);
11:     end component;
12:     signal a sim,b sim,c sim,f sim: STD LOGIC;
13: begin
14:     U1: maioria port map(a sim, b sim, c sim, f sim);
15:     process
16:     begin
17:         -- O código de teste vai aqui!
18:         wait;
19:     end process;
20: end sim maioria op;

          "VHDL Test Bench"
          Debug automático pelo console, é um código de teste.
          O test bench pode ter outras funcionalidades como, por exemplo, comparar os resultados de um módulo implementado utilizando o
           modelo comportamental (mais fácil) com os resultados de um módulo feito sob o modelo dataflow (mais rápido).
                                        assert boolean-expression
                                                report string-expression severity severity-expression;
                                        report string-expression severity severity-expression;
1: U1: maioria port map(a sim, b sim, c sim, f sim);
2: process
3: begin
4:      report “Iniciando teste” severity NOTE;
5:      a sim <= ’0’; b sim <= ’0’; c sim <= ’0’;
6:      wait for 50 ns;
7:      assert (f sim = ’0’) report “Falhou: 000” severity ERROR;
8:
9:      a sim <= ’0’; b sim <= ’0’; c sim <= ’1’;
10:     wait for 50 ns;
11:     assert (f sim = ’0’) report “Falhou: 001” severity ERROR;
12:
13:     wait;
14: end process;


    "Práticas de Projetos Lógicos Combinacionais"

        Padr˜oes de Documentação
        Diagramas de Tempo
        Programmable Logic Arrays - PLAs
        Field Programmable Gate Arrays - FPGAs

        Porém, um circuito prático pode ter dezenas de entradas e saídas, e pode precisar de milhares de termos para descrevê-lo como uma soma de produtos
         e milh˜oes de linhas para descrevê-lo como uma tabela verdade.
        Como proceder nesse caso? O problema é claramente muito grande para tentarmos resolvê-lo utilizando força bruta.

        Resposta é 'pensamento estruturado'.
        Um circuito complexo é concebido como uma coleção de circuitos menores, cada um deles com uma descriç˜ao simples.
            'decodificadores'
            'multiplexadores'
            'comparadores'
            'somadores'

            Mesmo que você utilize PLDs ou FPGAs para realizar seus circuitos, as funções da família 74 muitas vezes aparecem como bibliotecas (entidades
             VHDL, funções ou macros), muitas vezes até mesmo com o mesmo nome do CI que realiza aquela função!

            'Especificação' o que o circuito faz.
            'Diagrama de Blocos'
            'Esquemático' componentes, interconex˜oes, pinagem,..
            'Diagrama de Tempo'
            'Descrição do Dispositivo Lógico ' descrição em VHDL, Verilog, etc...
            'Descrição do Circuito' como o circuito foi projetado e como ele funciona. Deve conter o “pulo do gato”.

            ENABLE Ativo em 1
            ENABLE_L Ativo em 0

            Quando escrevemos o diagrama do circuito usamos símbolos e nomes de sinais que facilitam o entendimento.

            Hierarquia esquemática: desenhar o circuito como caixinhas, e em outras folhas desenhar o que tem dentro da caixinha.

            O Diagrama de Tempo do circuito mostra o comportamento dos sinais como uma função do tempo.
            A especificação de tempo mais importante é o atraso.

            Máxima: em certas condições (temperatura, tens˜ao, carga capacitiva), mostra qual é o atraso máximo de um dado caminho no circuito.
            Típica: em condições próximas do ideal.
            Mínima: o menor atraso possível. Em geral, trabalhamos para que o circuito funcione mesmo que o atraso seja zero.

            Qu˜ao típico é típico?
            A maioria dos CIs, digamos 99%, funcionam com um atraso perto do típico. Porém, se você projetar um circuito com 100 CIs que só funciona
            se todos os 100 CIs forem “típicos”, 63% deles n˜ao funcionar˜ao (1 − 0.99100).

            'Programmable Logic Arrays - PLAs'
            Um PLA (Programmable Logic Array) é um circuito combinacional de 2 níveis AND-OR que pode ser programado para realizar “qualquer” express˜ao
            lógica em soma de produtos.

            Lembrando que, para duas variáveis, temos: F(X, Y) = F(0, 0)· nX · nY + F (0, 1) · nX · Y + F (1, 0) · X · nY + F (1, 1) · X · Y
            Quantos termos-produto precisamos para realizar qualquer função de 2 variáveis?

            De maneira geral, para n variáveis, precisamos de no máximo 2^(n− 1) termos-produto para representar qlq função lógica.
            Então, para duas variáveis, precisamos apenas de 2 termos produtos.

            A limitação do PLA é:
                O número de entradas, n
                O número de saídas, m
                O número de termos-produto, p
            Em geral, p < 2n, e portanto podemos representar funções que precisam de p termos ou menos.


            'Complex Programmable Logic Arrays - CPLD'
            Placa programável interconectada.
            Baseados EEPROM - após corte de energia, os dados ainda estão lá.

            'Field Programmable Gate Array - FPGA'
            Interconexão programável.
            Bloco lógico programável.
            Pad de entrada e saída.

            CLB: Configurable Logic Block. Blocos capazes de realizar funções lógicas.
            Programmable Interconnect: Como todos os CLBs se inter-conectam.
            IO blocks: Blocos de Entrada-Saída.

            Baseados em RAM - Em geral, o FPGA “esquece” a configuração que foi feita quando ele desliga. Por isso, é como que placas FPGA venham com
            uma memória FLASH que pode regravar a configuração quando o FPGA é ligado.

                Vantagens do FPGA:
            Podem fazer qualquer coisa
            S˜ao muito rápidos
            Programáveis
            Altamente paralelizados
            Alta contagem de blocos de I/O

                Desvantagens do FPGA:
            Caros
            Alto consumo de energia
            Volatilidade / Boot Time
            Complicados / Requerem Ferramentas Complicadas
            Alta contagem de blocos de I/O

                Possui: Basys2 FPGA Spartan 3E-100 CP132
            100.000 portas l´ogicas equivalentes
            Velocidade de 500+ MHz


    "Decoders e Encoders"
        Decodificadores
        Decodificadores em Cascata
        Codificadores
        Codificadores em Cascata
        Decodificadores e Codificadores em VHDL

        'Decodificadores'
            Um decodificador é um circuito de múltiplas entradas e múltiplas saídas que converte códigos de entrada em códigos de saída, onde os dois
            códigos s˜ao diferentes. Em geral, o código de entrada tem menos bits que o código de saída, e existe um mapeamento um-pra-um do código de
            entrada para o código de saída. O código de saída mais utilizado é o 1-de-m, que usa m bits para m códigos e, para cada código, apenas um
            dos m bits está ativo. Por exemplo:

            Para que o decodificador funcione, todas as suas entradas de enable (habilitadoras) devem estar ativadas. Caso qualquer uma delas n˜ao esteja
            ativa, o decodificador mapeia qualquer entrada para um código “desativado”.

            O decodificador mais comum é o n-para-2^n, ou decodificador binário, que mapeia um código binário de n bits para um de 2^n códigos diferentes
            (em geral, números decimais de 0 a 2^n − 1). Às vezes, utilizamos menos que os 2^n valores possíveis. Por exemplo, é comum utilizar
            um decodificador BCD, que tem 4 entradas e 10 saídas (os números BCD, de 0 a 9).

            Podemos usar decodificadores como geradores de mintermos. Note que o 74x138 nos dá mintermos.

        'Codificadores'
            Em geral, um decodificador tem mais bits no código de saída do que no código de entrada. Se o código de saída de um dispositivo tem menos
            bits do que o código de entrada, chamamos esse dispositivo de codificador.

            O codificador mais simples é o 2^n-para-n codificador binário, que tem a funç˜ao oposta ao n-para-2^n decodificador binário.

            'Priority Encoder'
            Uma das principais aplicações de codificadores é em um circuito de requisição de serviços, como o encontrado em subsistemas de entrada/saída
            de microprocessadores, onde as entradas podem ser pedidos de interrupção. Por exemplo, podemos ter várias fontes de interrupção (as entradas)
            e o microprocessador vai atender apenas uma delas (a saída). O encoder que acabamos de montar tem um defeito: ele só funciona da forma correta
            se apenas uma de suas entradas estiver ativa a cada momento. Por exemplo, se as entradas I2 e I4 estiverem ativas, a saída é 110, que é a
            codificação binária do número 6. Na aplicação de requisição de serviços, tanto 2 ou 4 seriam saídas úteis, mas 6 n˜ao é. Mas como decidir qual
            a saída para esta entrada? Uma solução comum é assinalar prioridade às entradas. Por exemplo, podemos dizer que a entrada Ij tem maior
            prioridade que a entrada Ik se i > k. Assim, a saída é sempre a mesma saída da entrada com a maior prioridade.

            'O CI 74x148'
            Este CI tem 9 entradas, sendo uma delas um enable, e 5 saídas:
            I7-I0: entradas.
            EI (Enable Input): deve estar ativa para que qualquer saída esteja ativa.
            A2-A0: saídas.
            GS (Group Select) (ou Got Something): indica se alguma das entradas está ativa.
            EO (Enable Output) : usada para cascatear o CI. É ativa se EI estiver ativa mas nenhuma outra entrada está ativa(ou seja, um outro 74x148 de
             menor prioridade pode ser ativado).

             'Decodificador com Definição Hierárquica'
             Se tiver um monte de coisa LOW, faça o decodificador normal e por fora da caixa negue o que for preciso.

    "Dispositivos de Três estados e Multiplexadores"
    Dispositivos de Três Estados
    Multiplexadores
    Multiplexadores em Cascata
    Dispositivos de Três Estados e Multiplexadores em VHDL
    
    O mais básico dispositivo de três estados é o “buffer de três estados”
    A entrada de enable controla o buffer.
    
    Se a entrada de enable estiver ativa, o sinal de entrada  ́e repetido na saída, e o dispositivo funciona como um buffer.
    Se estiver desativada, o dispositivo “flutua” (floats), isto  ́e, ele vai para um estado de alta impedância (high Z ), e se comporta 
    como se ele nem estivesse lá.
    
    Esse tipo de dispositivo permite que múltiplas fontes compartilhem um mesmo canal(chamado de party line), desde que apenas um deles use 
    o canal a cada momento!
    
    Tipicamente, dispositivos desse tipo são projetados de forma que eles entram em um estado de alta impedância mais rápido do que eles saem
    desse estado.
    Isto significa que se as saídas de dois dispositivos estão conectados na mesma linha e nós simultaneamente desativamos um e ativamos o 
    outro, o dispositivo que estava ativo é desativado antes do dispositivo que estava desativado seja ativado.
    Esta propriedade  ́e importante pois se ambos os dispositivos tentassem usar o canal ao mesmo tempo poderíamos ter problemas se eles 
    tentassem colocar sinais opostos no canal.
    
    Infelizmente,  ́e difícil controlar o atraso nesse ponto, principalmente se dispositivos de fabricantes diferentes (e, portanto, com 
    atrasos diferentes) forem usados.
    
    Por isso, a única opção realmente segura de se evitar o problema  ́e no projeto lógico do circuito, projetando o circuito de tal forma que 
    garanta um dead time, em que nenhum dispositivo controle o canal.
    
    Standard MSI Buffers: 74x541 (linha a linha**)
    Standard MSI Buffers: 74x245 (vai e volta)
    
   'Multiplexadores'
   Um multiplexador (ou mux) ́e um switch digital. Para cada saída, usamos n bits de seleção (em geral, com o nome de s_i ) para selecionar 
   entre 2^n entradas (logo, s = ⌈log2 n⌉ ).
   
   Podemos projetar um mux de 4 entradas e 1 saída. Para isso, precisamos de s = ⌈log 2 4⌉ = 2 bits de seleção.
   
   Standard MSI Multiplexers: 74x151 Mux 8-para-1
   Standard MSI Multiplexers: 74x153 Dois Mux 4-para-1
   Standard MSI Multiplexers: 74x157 Quatro Mux 2-para-1
   
   Multiplexadores com Saídas de Três Estados
   -Nesses multiplexadores, a entrada de enable força a saída para alta impedância caso esteja desativada. Temos três multiplexadores 
    principais:			74x251 → 74x151
				74x253 → 74x153
				74x257 → 74x157
   Multiplexadores em Cascata: Mux 32-para-1
   
   Demultiplexadores
   -Um demultiplexador (demux) tem 1 entrada, n bits de seleção e 2^n saídas.
   -O que  ́e muito similar a um... decodificador!

   Dispositivos de Três Estados em VHDL
   -A linguagem VHDL não oferece tipos built-in para utilizar dispositivos de três estados. Porém, a biblioteca padrão do IEEE permite que se
    utilizem esses dispositivos (e este é oprincipal motivo para usarmos STD_LOGIC ao invés de BIT).Em VHDL, não existe nenhum construtor para 
    juntar buffers de três estados em um único barramento. Isto  ́e, VHDL não permite que se faça:
		A <= expressão 1;
		A <= expressão 2;
  -Porém, o compilador VHDL irá automaticamente conectar sinais que são assinalados em dois ou mais diferentes processos. Porém, para que isso 
  aconteça, os sinais devem ter o tipo apropriado.
  
  -O tipo STD_LOGIC  ́e um resolved type, que é um subtipo de um unresolved type chamado STD_ULOGIC.
  -A definição de um resolved type inclui uma resolution function, que  ́e chamada toda vez que um dado é assinalado à sinais daquele tipo. 
  Essa função resolve o valor do sinal quando este tem múltiplos drivers, permitindo que se simule o comportamento de dispositivos reais.
	  'SUBTYPE std logic IS resolved std ulogic;'
	  
  Note a ordem em que os sinais são resolvidos:
  ’U’ >’X’ >’0’ >’1’ >’W’ >’L’ >’H’ >’-’
  
  'Algoritmo 4' Four 8-bit Three-State Buffers

    "Circuitos de Paridade e Comparadores"
    -Circuitos de Paridade
    -Circuitos Iterativos
    -Comparadores
    -Circuitos de Paridade e Comparadores em VHDL
    
      'Circuitos de Paridade'
      Note que, se complementamos quaisquer dois sinais (entradas ou saídas) das portas XOR e XNOR, continuamos com a mesma função lógica! Na 
      lógica bubble-to-bubble,  ́e comum encontrarmos algumas delas ao invés dos símbolos usuais.
      
      Já vimos também o circuito de detecção de paridade  ́ımpar (odd-parity circuit), em que a saída  ́e 1 se um número ímpar de entradas 
      for 1 (o circuito de detecção de paridade par,ou even-parity circuit, pode ser obtido simplesmente complementando a saída do circuito 
      de paridade  ́ımpar).
      
      'Standard MSI Parity Generator'
      -Como essa é uma função bastante utilizada, temos o CI 74x280 que gera a paridade de 9 bits (por que 9 bits?).
      
      'Parity Generation and Checking for an 8-bit memory'
      - 74X280(paridade 9 bits)
      - Memory Chips(read e write)
      - 74X541(linha a linha**)
      
      'Error-correcting circuit for a 7-bit Hamming code'
      - 74X280(paridade 9 bits)
      - 74X280(paridade 9 bits)
      - 74X280(paridade 9 bits)
      - 74X138(decodificador)
      
      'Comparadores'
       É comum precisarmos comparar palavras binárias para verificar a igualdade entre elas. Um circuito desse tipo  ́e chamado de comparador.
       Alguns comparadores interpretam suas entradas como números (com ou sem sinal) e indicam uma relação aritmética entre eles (maior que 
       ou menor que, por exemplo). Esses circuitos são chamados de comparadores de magnitude.
       
       As portas XOR e XNOR podem ser vistas como comparadores de 1-bit.
       
       Comparador paralelo: olha todos os bits simultâneamente.
       
       Comparador iterativo: Possuem 'n' módulos idênticos, cada um com:
				entradas primárias (primary inputs)
				entradas de cascateamento (cascading inputs)
				saídas primárias (primary outputs)
				saídas de cascateamento (cascading outputs)
	Além disso, as entradas de cascateamento mais à esquerda são chamadas de entradas de borda (boundary inputs), enquanto as saídas de 
	cascateamento mais à direta são chamadas de saídas de borda (cascading outputs).
	
	'Circuitos Iterativos'
	Circuitos iterativos são apropriados para problemas que podem ser solucionados por um algoritmo iterativo:
	
	1 Ajuste C0 para seu valor inicial e i para zero.
	2 Use Ci e PIi para determinar os valores de POi e Ci+1.
	3 Incremente i.
	4 Se i<n, volte para o passo 2.
	
	Note que, em um circuito iterativo combinacional não há, de fato, nenhuma iteração: os passos são desenrolados (unwound) e executados 
	por circuitos combinacionais separados!
	
	'Comparador Iterativo'
	Duas palavras de 'n' bits podem ser comparadas (verificando apenas a igualdade) um bit de cada vez, usando um bit EQi para rastrear 
	se as palavras são iguais até o momento i.
	
	1 Ajuste EQ0 = 1 e i para zero.
	2 Se EQ i = 1 e Xi = Yi , então EQi+1 = 1. Caso contrário, EQ i+1 = 0.
	3 Incremente i.	
	4 Se i < n, volte para o passo 2.
	
	'Standard MSI Comparators'
	  74x85 - compara duas palavras de 4 bits, e tem três saídas: maior que, menor que e igual a, além de entradas e saídas de 
		  cascateamento para comparar mais do que 4 bits.
	  Podemos cascatear o 74x85 para comparar 12 bits. Note que este comparador compara os bits menos significativos primeiro!
	  
	  74x682 - compara palavras de 8 bits. Este CI tem apenas duas saídas: maior que e igual a, e podemos gerar outras saídas a partir
		   dessas.
		   
	'Comparadores em VHDL'
	Em geral, as linguagens HDL fornecem operadores relacionais para ser usados com os tipos de varíaveis, e o sintetizador monta o 
	circuito conforme necessário. Porém, devemos ter cuidado pois nem sempre o circuito sintetizado tem o melhor design para o seu 
	projeto, e isso pode tornar seu circuito muito mais lento.
  
	Portanto,  ́e importante que tenhamos uma ideia de que tipo de circuito será sintetizado quanto usamos comparações nos nossos 
	circuitos.
	
	Em VHDL, os operadores = (igual a) e /= (diferente de) se aplicam para todos os tipos de dados.
	
	Quando usados com arrays, os arrays devem ter o mesmo tamanho e os operandos são comparados elemento por elemento. Caso os arrays 
	tenham tamanhos diferentes, eles são considerados diferentes (mesmo que eles sejam “iguais”).
	
	Os outros operadores relacionais, >, <, >= e <= se aplicam para tipos inteiros (integer) e para enumerated types (como STD LOGIC) e para 
	arrays uni-dimensionais destes. Para tipos inteiros, esses operadores funcionam como esperado. Para enumerated types, ele utiliza a 
	ordem em que os tipos foram declarados. Portanto, para STD LOGIC, temos:
			      ′U ′ < ′ X ′ < ′ 0 ′ < ′ 1 ′ < ′ Z ′ < ′ W ′ < ′ L ′ < ′ H ′ < ′ − ′
			      
	Para arrays, a comparação sempre começa pelo elemento mais à esquerda (independentemente se o array foi declarado como downto ou to).
	
	Para arrays de tamanhos iguais, a comparação funciona conforme o esperado. Para arrays de tamanhos diferentes, se todos os elementos
	do menor array são iguais aos elementos do maior array, o menor array (em comprimento)  ́e considerado menor (em magnitude). Porém, a 
	comparação começa pelo elemento mais à esquerda.
	
	No pacote std_logic_arith são definidos dois novos tipos para realizar comparações aritméticas:
		type SIGNED is array (NATURAL range <>) of STD LOGIC;
		type UNSIGNED is array (NATURAL range <>) of STD LOGIC;
		
	O mais importante é que este pacote declara também funções para realizar comparações entre os tipos com o comportamento esperado 
	(isto ́e, ela primeiro converte os arrays para o mesmo tamanho e tipo para poder realizar a comparação, e lida com os detalhes da 
	comparação entre tipos diferentes internamente).
	
	Porém, note que essas funções realizam a comparação entre UNSIGNED, SIGNED e INTEGER. Para comparar dados do tipo STD LOGIC VECTOR,
	devemos fazer primeiro um cast para o tipo que queremos.
	
	
	Comparação				Res.			Motivo
       (vec1 = vec2)				0		Tamanhos diferentes
(unsigned(vec1) = unsigned(vec2)) 		1		vec1  ́e expandido para “001110” e fica igual a vec2
  (signed(vec1) = signed(vec2)) 		0		vec1  ́e expandido para “111110” e fica diferente de vec2
      (uvec1 = uvec2) 				1		uvec1  ́e expandido para “001110” e fica igual a uvec2
  (unsigned(vec1) = uvec1) 			1		vec1  ́e transformado para unsigned e fica igual a uvec1
      (vec1 <vec2) 				0		A comparação  ́e feita da esquerda para a direita
(unsigned(vec1) <unsigned(vec2)) 		0		vec1  ́e expandido para “001110” e fica igual a vec2, nao menor
  (signed(vec1) <signed(vec2)) 			1		vec1  ́e expandido para “111110” e fica negativo, logo, menor que vec2.

  "Somadores"
  Somadores
  Ripple Adder
  Carry-Lookahead Adders
  MSI Adders
  Somadores em VHDL
  
  'Somadores'
  Um circuito somador(adder) combina dois operandos aritméticos usando as regras da adição binária. Vimos que o mesmo circuito pode ser 
  usado para somar palavras sem sinal (unsigned) e em complemento-de-2.
  
      'Somador Parcial'
      O circuito para somar dois bits (ou somar duas palavras de 1 bit) é chamado de somador parcial (half adder). Este circuito soma dois bits,
      A e B , e gera uma soma de dois bits (de 0 a 2).
	  A   B   C   S
	  0   0   0   0		C = A.B
	  0   1   0   1		S = A xor B
	  1   0   0   1
	  1   1   1   0
	  
      'Somador Total'
      O circuito para somar três bits (ou somar duas palavras de 1 bit mais um carry ) ́e chamado de somador total( full adder). Este circuito 
      soma três bits, A , B e Cin , e gera uma soma de dois bits (de 0 a 3).
	  Cin A   B  Cout S
	  0   0   0   0   0	Cout = A.B + A.Cin + B.Cin
	  0   0   1   0   1	S = A xor B xor Cin
	  0   1   0   0   1
	  0   1   1   1   0
	  1   0   0   0   1
	  1   0   1   1   0
	  1   1   0   1   0
	  1   1   1   1   1
	  
       'Somadores de n bits'
       Considere um circuito somador de duas palavras de n bits. Como este ́e um circuito puramente combinacional, podemos montar sua tabela
       verdade (com 2^2^n variáveis), e minimizá-lo usando qualquer técnica que desejarmos. 
       
       Porém, para somar apenas palavras de 4 bits, temos 8 variáveis ( 9 , se considerarmos o carry in da entrada) e 256 linhas ( 512 com o 
       carry ) na tabela verdade. 
       
       Uma outra opção ́e utilizar um circuito iterativo! Note que, durante a soma, fazemos a mesma operação em cada bit.
       
       'Somadores Iterativos'
       A adição binária pode então ser feita usando o algoritmo:
       1 Ajuste C0 = 0 e i = 0.
       2 Some os bits Ci, Ai e Bi para obter Si (saída primária) e Cout (saída de cascateamento).
       3 Incremente i.
       4 Se i < n, volte ao passo 2.

	Assim, precisamos de um módulo que realize a soma entre Ci, Ai e Bi para obter Si e Cout. 
	Ou seja, precisamos do circuito somador total.
	
  'Ripple Adder' (circuito iterativo é aquele que tem memória)
  O circuito de somador iterativo ́e chamado de Ripple Adder.
       'Subtrator'
       Podemos construir um circuito “subtrator” binário análogo ao somador usando a tabela verdade da subtração com borrow, que realiza a 
       subtração A−B.
	    Bin  A   B  Bout D
	    0   0   0   0   0		Bout = Ã.B + Ã.Bin + B.Bin
	    0   0   1   1   1		D = A xor B xor Cin
	    0   1   0   0   1
	    0   1   1   0   0
	    1   0   0   1   1
	    1   0   1   1   0
	    1   1   0   0   0
	    1   1   1   1   1
	    
	'Subtração usando o Ripple Adder'
	Porém, vimos que, para subtrair números em complemento de 2 , basta somar o número com o seu complemento (isto  ́e, ao invés de fazer
	A − B , fazemos A + ( − B ) ). Para obter o inverso de um número em complemento de 2 , basta inverter todos os bits e somar 1.
	Temos um sinal de controle que entra numa xor com todas as entradas e entra como o primeiro carry in.
	SC = 0 ==> SOMA
	SC = 1 ==> SUBTRAÇÃO
  O maior problema do ripple adder ́e o atraso. No pior caso, o carry tem que ser propagado do bit menos significativo até a saída carry out do 
  módulo mais significativo (por exemplo, quando somamos 11 ... 11 com 00 ... 01 ). O atraso do pior caso ́e:
				TADD = TABCout + (n − 2)TCinCout + TTCinS
				
	Podemos criar uma lógica de soma com apenas 2 níveis de atraso (típico da estrutura AND-OR) se tentarmos minimizar o circuito 
	diretamente da tabela verdade, ou seja, fazendo as equações para cada bit de saída si a partir das entradas (aia0,bib0 e cin). 
	
	Porém, a partir de s2 (ou seja, apenas o terceiro bit da soma!), as equações já ficam muito grandes e necessitariam de 14 4-input ANDs, 
	4 5-input ANDs e uma 18-input OR! E isso apenas para s2.
	
    'Carry Lookahead'
    Podemos acelerar este atraso. A ideia do circuito com carry lookahead ́e manter as portas xor e gerar apenas o carry.
    
    Para isso, ele usa duas definições chave. Para uma combinação ai , bi no estágio i, dizemos que:
	    1) um carry ́e gerado nesse estágio se ele produz um carry out 1 independente das entradas ai − 1 a0 , bi − 1 b0 e cin. 
	    2) um carry ́e propagado nesse estágio se ele produz um carry out 1 se e somente se o carry in desse estágio for 1.
						  gi = ai·bi
						  pi = ai+bi
    Ou seja, um estágio gera um carry out incondicionalmente se ambas as entradas desse estágio são 1 e ele propaga um carry in se pelo menos 
    um de seus adendos for 1. Assim, podemos escrever o carry out como:
					      ci+1 = gi + pi·ci
    Cada uma dessas equações corresponde a um circuito com 3 níveis de atraso (um para gerar gi e pi) e duas para a estrutura AND-OR.
    
    'Standard MSI Adders'
    74x283(somador de duas palavras de 4 bits que utiliza a ideia de carry lookahead).
    A maior diferença ́e que ele usa versões ativas em nível baixo de pi e gi , além de outras otimizações de ́algebra booleana para chegar nas 
    equações utilizadas.
    
    'Somadores em VHDL'
    Em VHDL, os operadores + e − só funcionam de forma built in com tipos inteiros e reais. Especificamente, eles não funcionam com arrays do 
    tipo STD_LOGIC_VECTOR e BIT_VECTOR. O pacote std_logic_arith define os tipos SIGNED e UNSIGNED, e define os operadores + e − para estes 
    tipos. Quando usamos esses operadores para os mesmos tipos, o funcionamento ́e simples (isto ́e, a soma de operandos do tipo UNSIGNED ́e 
    UNSIGNED, e a soma de operandos do tipo SIGNED ́e SIGNED). Quando usamos esses operadores com tipos diferentes, o resultado ́e um pouco mais
    complicado. Em geral, se um dos operandos for SIGNED, o resultado ́e SIGNED.
   
'Multiplicadores'
    Multiplicadores
    Multiplicadores em VHDL
    
    A multiplicação em binário se dá da mesma forma que a multiplicação em decimal: adicionando uma lista de multiplicandos deslocados computados
    de acordo com os dígitos do multiplicador. Na multiplicação em binário esse processo  ́e ainda mais fácil, pois ou o bit do multiplicador
    ́e 0 (e o multiplicando deslocado  ́e 0 ) ou  ́e 1 (e o multiplicando deslocado ́e igual ao multiplicando).
    
    Embora possamos projetar circuitos sequenciais para realizar a multiplicação, não há nada inerentemente sequencial ou dependente do tempo 
    na multiplicação binária.
    
    Poderíamos montar tabela verdade e fazer and-or, mas ela cresce muito rápido.
    
    Considere a multiplica ̧c ̃ao de dois operandos de 3 bits.
    Para representar o resultado sem que haja overflow precisamos de 2n = 6 bits (o maior número que pode ser representado  ́e 7 × 7 = 49 ).
    
    Obviamente, o maior problema do circuito anterior ́e o atraso.
    
    O circuito tem apenas seis somadores mas, no pior caso, o sinal deve ser propagado por cinco deles até que chegue a saída.
    
    'carry save addition' Podemos “acelerar” este circuito utilizando a ideia de carry save addition , ligando o carry out de um somador no 
    somador abaixo dele, não ao lado.
    
    No multiplicador de apenas 3 bits, o carry save addition economiza apenas 1 atraso, pois o pior caso do circuito anterior ́e que um carry se 
    propague por 4 somadores.
    
    Pode não parecer muito, especialmente porque o entendimento do circuito fica um pouco mais complexo, mas em um circuito multiplicador de 8 
    bits a economia ́e de 20 somadores para 14 (e ainda menos se utilizarmos um circuito carry lookahead na ́ultima linha).
    
    Em VHDL, é interessante fazer um código comportamental ou até estrutural. A chave é utilizar a estrutura 'generate' para evitar de escrever 
    muitas e muitas repetições de componentes!
    
    Finalmente, como era de se esperar, podemos utilizar o pacote std_logic_arith para realizar a multiplicação de tipos signed e unsigned 
    utilizando o operador *.
    
    Considere a multiplicação de dois números de 16 bits, A e B . Podemos fazer um circuito para multiplicar esses números similar aos circuitos
    anteriores. Note que precisamos de 32 bits na saída.
    
    Este circuito ficaria razoavelmente grande, mas podemos fazer um circuito mais simples cascateando multiplicadores e somadores!
    
    Note que:  A =A15 A14 A13 A12 A11 A10 A9 A8 A7 A6 A5 A4 A3 A2 A1 A0
    pode ser escrito como:  A = AH · 2⁸ + AL
    onde		    AH = A15 A14 A13 A12 A11 A10 A9 A8 
			    AL= A7 A6 A5 A4 A3 A2 A1 A0
			    
    E similarmente para B.

"Unidade Lógico-Aritmética (ULA)"
    Central Processing Unit - CPU
    Arithmetic Logic Unit - ALU
    
    'CPU'
    A CPU ́e o circuito eletrônico em um computador que executa instruções de um programa.
    Essas instruções são compostas de operações de entrada/saída, operações de controle e operações básicas aritméticas e lógicas.
    
    Para executar uma instrução, a CPU faz três passos:
	1 Fetch(busca) - Busca na memória qual instrução deve ser executada.
	2 Decode(decodifica) - Decodifica essa instrução, lendo o que deve ser feito e com quais operandos.
	3 Execute(executa) - Efetivamente executa essa instrução.
    Ao fim de uma instrução, a CPU atualiza o contador de programa e repete esses passos novamente.
    
    As instruções que uma CPU pode executar são (em geral) simples e sempre bem definidas.
    Instrução					Descrição
      ADD   A,#20			Adiciona o valor 20 ao conteúdo posição de memória A
      MOV   A,R0			Copia o conteúdo da posição R0 para a posição A
      INC    R2				Incrementa a posição de memória R2
      JMP   LB0				Pula para a instrução rotulada como LB0
      JB     F0,LB1			Se a flag F0 for 1 , pula para LB1
      CJNE   R1,#32,LB2	 		Compara o valor da posição R1 com 32 e, se forem diferentes, pula para LB2
      
      Note que muitas dessas instruções envolvem operações aritméticas (ADD, INC) ou lógicas (CJNE, JB). Note também que essas operações são 
      simples - já vimos como projetar circuitos combinacionais para fazer esse tipo de operação!
      
      O modelo de Von Neumann
	A 'memória' pode guardar tanto o programa a ser executado quanto os dados (resultados).
	A 'unidade de controle' coordena os operandos e as operações, buscando os dados na memória e disponibilizando para que outros circuitos 
	executem essas operações.
	A 'unidade lógico-aritmética' executa propriamente essas operações, retornando um valor.
	
      Uma unidade lógico-aritmética (ULA) (ou ALU - arithmetic logic  unit )  ́e um circuito combinacional que pode realizar uma série de 
      operações aritméticas e/ou lógicas em um par de operandos de n-bits. A operação  ́e especificada em suas entradas de seleção.
      
      Standard MSI ALUs: 74x181 (ULA de 4 bits)
      Outras ALU de 8 bits mais simples são os CIs 74x381 e 74x382. A ́unica diferença entre esses CIs ́e que o 74x381 tem saídas para group 
      carry lookahead.
      
      Quando vimos o circuito com carry lookahead , usamos a ideia do gerador de carry e do propagador de carry para realizar a soma com menos
      atraso. Porém, os sinais gi e pi são internos ao circuito! Por exemplo, se quisermos somar palavras de 8 bits utilizando o CI 74x283 temos 
      que usar o carry output para “passar de um CI para o outro”.
      
      Para permitir uma soma mais rápida, o CI 74x381 tem duas saídas com o gerador e propagador de carry do circuito.
      Essa saídas são G_L e P_L. A saída G_L indica se essa ALU vai gerar um carry no  ́ultimo estágio de maneira incondicional, enquanto a 
      saída P_L indica se a ALU vai propagar um carry. Estes sinais podem ser combinados em um lookahead carry circuit para gerar os carries
      dos estágios seguintes. Um exemplo de CI MSI que realiza essa função  ́e o 74x182.
      
      Podemos montar ALUs em VHDL de duas formas: utilizando apenas declarações concorrentes ou utilizando um processo. No segundo caso, temos 
      que tomar cuidado com a lista de sensibilidade.
      
      O código anterior (2) não funciona porque não podemos utilizar port maps , que são declarações concorrentes, dentro de processos.
      
      Todas as três são executadas ao mesmo tempo mas o processo precisa do valor de F_arith, que só vai ser conhecido depois que o somador 
      for executado!
	
      Podemos resolver isso de forma simples, apenas adicionando F_arith à lista de sensibilidade do processo.

"Revisão"
	Projeto de Circuitos Digitais
	Decodificadores
	Codificadores
	Dispositivos de 3 Estados
	Multiplexadores
	Circuitos de Paridade
	Comparadores
	Somadores
	Multiplicadores
	Unidade Lógico-Aritmética
	
    "PROVA 3"
    Aula 19 - Circuitos Sequenciais e Latches
	Circuitos Combinacionais e Sequenciais
	Elementos Biestáveis
	Latches e Flip-Flops
	Latch SR
	Latch SR com Enable
	Latch D
	
	'Circuitos combinacionais'
	Circuitos Combinacionais são aqueles onde as saídas dependem apenas das entradas em um dado instante de tempo.
	Ex.: Velocidade de um ventilador com dial.
	
	'Circuitos sequencias'
	Circuitos Sequenciais são aqueles onde as saídas dependem não apenas das entradas em um dado momento, mas também da sequência passada de 
	entradas arbitrariamente longa, possivelmente até o momento em que o circuito foi ligado.
	Ex.: Velocidade de um ventilador com botões up / down.
	
	Não ́e conveniente descrever um circuito sequencial usando uma lista de todas as suas entradas passadas.
	Podemos facilmente determinar a saída se olharmos o “estado” atual.
	Ex.: Se sabemos que o estado atual  ́e 50, e sabemos a lista das próximas 1000 entradas (ups e downs), podemos determinar a saída do 
	circuito após as 1000 entradas.
	
	Estado 
	O estado de um circuito sequencial ́e uma coleção de “variáveis de estado” cujos valores em um dado momento contém toda a informação 
	necessária sobre o passado do circuito para que possamos determinar o comportamento futuro desse circuito.
	
	Em circuitos digitais, as variáveis de estado são binárias e, portanto, 'n' variáveis podem descrever 2^n estados.
	Embora 2^n possa ser um número bastante grande, ele ́e um número finito e, por isso,esse tipo de circuito ́e chamado de finite state 
	machine ('FSM').
	
	Mudanças de Estado
	As mudanças de estado em circuitos sequenciais são muitas vezes gatilhadas por um clock.
	  
	  'clock period': tempo entre duas transições na mesma direção.
	  'clock frequency': recíproco do período.
	  'duty cycle': tempo em que o clock fica ativo.
	  
	'Feedback Sequential Circuits': usa portas e feedback loops (laços de realimentação) para criar um efeito memória, e cria os blocos 
	básicos como 'latches' e 'flip-flops'.
	'Clocked Synchronous State Machine': usa esses blocos básicos, em especial 'flip-flops',para criar projetos mais avançados.
	
	Elementos Biestáveis
	-O circuito não tem entrada! Mas podemos realizar uma análise digital (isto  ́e, com níveis lógicos) para entender o que acontece com o 
	circuito.
	
	-Quando ligamos o circuito, ele assume um de dois estados possíveis: Q = 0 ou Q = 1.
	
	-Porém, ́e importante realizar também uma análise analógica para melhor compreender o funcionamento desse circuito. Em especial, vamos 
	lembrar que o circuito tem uma 'função de transferência' T :
							    Vout = T(Vin)
        No nosso circuito temos duas portas inversoras, onde:
							    Vin1 = Vout2
							    Vin2 = Vout1
	Considerando apenas o comportamento em regime permanente, temos:
							    V in1 = V out2
								  = T (V in2 )
								  = T (V out1 )
								  = T (T (V in1 ))
				E da mesma forma:
							    V in2 = T (T (V in2 ))
        Ou seja, temos alguns pontos de equilíbrio, que ocorrem quando essas equações são satisfeitas. No gráfico, isso ocorre quando as curvas 
        se tocam:		"Porém, temos três pontos de equilíbrio!"
	Note que as duas condições estáveis foram descobertas pela análise digital, mas a terceira condição, instável, só foi descoberta pela 
	análise analógica.
	
        Note também que Q e Q L não possuem valores lógicos válidos nessa condição (isto ́e, não são nem 0 nem 1), mas ainda assim esse ponto 
        satisfaz às equações. Essa condição ́e chamada de 'meta-estabilidade'.
        
        Comportamento Meta-Estável
        Chamamos essa condição de meta-estável porque essa condição não ́e realmente estável. Qualquer flutuação de tensão irá levar o circuito a
        uma das condições estáveis (mesmo um pequeno ruído por flutuação de temperatura, por exemplo). Isso não ocorre nos casos estáveis.
	
	Circuitos Sequenciais e Meta-Estabilidade
	Se o circuito sequencial mais simples de todos ́e suscetível a meta-estabilidade, podemos ter certeza que todos os circuitos sequenciais 
	também são. Este comportamtento ́e análogo ao que acontece com latches e flip-flops sob marginal triggering conditions (condições de 
	gatilhamento marginais). Por exemplo, no Latch SR um pulso na entrada S força o latch do estado 0 para o estado 1. Uma largura mínima 
	para esse pulso  ́e especificada: aplique um pulso menor e a mudança não ocorre, aplique um pulso maior e a mudança ocorre, mas aplique 
	um pulso igual e ele pode ir para um estado de meta-estabilidade. Uma vez nesse estado, a operação depende da “forma de sua colina”. 
	Latches de alta performance tendem a sair do estado de meta-estabilidade mais rápido do que latches feitos com tecnologias de menor 
	performance.
	
	Latches e Flip-Flops
	'Latch': a saída pode variar a qualquer momento em que a entrada variar (isto  ́e,  ́e assíncrono).
	'Flip-Flop': a saída varia apenas quando o sinal de clock variar (isto ́e, ́e síncrono).
	
	'Latch SR'
	O latch SR pode ser construído com portas NOR:
	
	Minimum Pulse Width
	Duração mínima de pulso e meta-estabilidade.
	
	Quando chamamos a mudança de duas entradas de simultânea? 
	Um parâmetro chamado recovery time indica o quão perto dois sinais podem mudar para ser chamados de simultâneos (por exemplo, se o 
	recovery time de um latch for 10 ns, qualquer mudança dentro dessa janela  ́e dita simultânea e pode desencadear meta-estabilidade).
	
	'Latch S^R^'
	O latch S^R^ possui um comportamento similar ao latch SR, porém  ́e construído com portas NAND.
	
	'Latch SR com Enable'
	Funciona como um Latch SR onde a saída apenas varia se a entrada de enable estiver ativa.
	
	Note que agora  ́e fácil mudar as entradas S e R ao mesmo tempo: se SR = 11 e C transitar de 1 para 0, as duas entradas do latch SR 
	serão negadas simultaneamente. Nesse caso, o próximo estado ́e imprevisível e a saída pode apresentar meta-estabilidade.
	
	'Latch D'
	O latch SR ́e usado geralmente em aplicações que necessitam de um controle, onde queremos usar as entradas SET e RESET de forma 
	independente. Porém, se tudo o que queremos ́e guardar um bit de informação, podemos modificar o latch SR para torná-lo mais simples 
	(e, ainda por cima, evitar a situação onde SR = 11).
	
	No entanto, o comportamento meta-estável não foi eliminado! Existe uma janela de tempo ao redor da transição de C de 1 para 0 (isto ́e, 
	quando desativamos o latch) onde a entrada D não pode mudar. O tempo dessa janela antes da borda de descida ́e chamado de setup time e o 
	tempo dessa janela após a borda ́e chamado de hold time.
	
    Aula 20 Flip-Flops
      Flip-Flop SR Mestre-Escravo
      Flip-Flop JK Mestre-Escravo
      Edge-Triggered D Flip-Flop
      Edge Triggered JK Flip-Flop
      Flip-Flop T
      
      Flip-Flop SR Mestre-Escravo
      - Os circuitos que vimos até agora são latches, isto ́e, a saída muda a qualquer momento em que a entrada de enable estiver ativa. Porém, 
        queremos um circuito que mude apenas na borda (de subida ou de descida) do clock.
        
      - Note que, quando C=1, o primeiro latch (chamado de mestre) está ativo, enquanto o segundo latch (chamado de escravo) está inativo.Quando
        C muda de 1→0, a situação se inverte, e o latch mestre está inativo enquanto o escravo está ativo.  Assim, na borda de descida do clock, 
	a informção ́e passada do mestre para o escravo, que então apresenta essa informação na saída.
	
      - Porém, note que precisamos de um pulso completo no clock para transferimos a informação!
      
      - Como o latch SR tem um estado de hold, se um pulso ocorrer na entrada S enquanto o mestre estiver ativo, a informação ́e transferida para
        o mestre, que então transfere para o escravo quando C muda de 1→0 , mesmo que SR = 00 no momento da borda de descida.
        
      - Este comportamento ́e chamado de 'pulse-triggered flip-flop'. Na figura do elemento, usamos o símbolo de 
        postponed output indicator.
        
      - Porém, ainda temos o problema de quando as entradas SET e RESET estão ativas ao mesmo tempo.
      
      Flip-Flop JK Mestre-Escravo
      - Podemos resolver o problema das entradas SET e RESET usando o flip-flop JK mestre-escravo:
      
      - As entradas J e K são análogas às entradas S e R. Porém, ativar J apenas ativa S se QN = 1 , e ativar K apenas ativa R se Q = 1.  
        Assim, se ativarmos J e K, invertemos o estado do flip-flop.  Entretanto, ainda temos um pulse-triggered flip-flop, e não um edge-
        triggered flip-flop, pois o flip-flop JK ainda tem um estado hold.
        
      Edge Triggered D Flip-Flop
      - Vimos que o latch D não tem um estado hold .Logo, podemos tentar fazer o flip-flop D mestre-escravo.
      
      - No símbolo do flip-flop vemos um dynamic input indicator.
      
      - O funcionamento desse flip-flop  ́e análogo ao mestre-escravo: quando CLK=1, o mestre está aberto e a entrada D é copiada para o mestre. 
        Quando CLK muda de 1→0, o mestre fica inativo e a informação ́e transferida para o escravo e, por sua vez,à saída. Porém, a informação 
        transferida para o escravo ́e sempre a última informação,pois o latch D não tem um estado hold!
      
      - Note que esse flip-flop muda na borda de descida do clock. Podemos facilmente fazer um flip-flop que muda na borda de subida.
      
      - Como o latch D, o Flip-Flop D ainda tem problemas com meta-establida se seus tempos de setup e hold n ̃ao forem observados.
      
      - E comum utilizarmos  flip-flops D com entradas assíncronas de PRESET e CLEAR:
      
      - Agora que temos um flip-flop realmente gatilhado pela borda, podemos fazer facilmente um flip-flop JK gatilhado pela borda.
      
      - Outro circuito bastante  ́util  ́e o flip-flop T (toggle).
      
      - E o flip-flop T com enable:
	
    Aula 21 Análise de Máquinas de Estados
		Estrutura de Máquinas de Estados
		Equações Características
		Análise de Máquinas de Estados usando Flip-Flops D
		
		"Clocked synchronous state-machine" (ou máquina de estados síncrona ativada por clock) = State-Machine
		
		O termo clocked indica que os elementos de armazenamento (os flip-flops) utilizados apresentam uma entrada de clock.
		
		Finalmente, o termo synchronous indica que todos os flip-flops utilizam o mesmo sinal de clock. 
		
		Assim, o estado da m´aquina s´o muda quando a borda de ativa¸c˜ao do sinal de clock ocorrer.
		
		Estrutura de Máquina de Estados
			- A "memória" é um conjunto de 'n' flip-flops que guardam o estado atual da máquina (portanto, podemos ter 2^n estados).
			- O próximo estado da máquina é determinado pela "lógica de próximo estado", que é um circuito combinacional F cujas entradas s˜ao as entradas do 
			  circuito e o estado atual da máquina.
			- A saída é determinada pela "lógica de saída", que também é um circuito combinacional G cujas entradas s˜ao as entradas do circuito e o estado 
			  atual da máquina.
				"Mealy"
			- Next_state = F(current state , input)
			  Output = G(current state , input)
			- No circuito que mostramos, a saída depende tanto do estado atual quanto da entrada atual (e, portanto, a saída pode mudar independendente do 
			  clock). Esse tipo de máquina é chamada de 'Mealy machine'.
			
				"Moore"
			- Next_state = F(current state , input)
			  Output = G(current state)
			- No circuito, a saída depende apenas do estado atual (logo, a saída é síncrona - só muda quando o estado muda, isto é, na borda de ativação do clock). Esse 
			  tipo de máquina é chamada de Moore 'machine'.
			  
			Na prática, as máquinas de estados tem algumas saídas do tipo Mealy (isto é, que dependem da entrada e do estado atual) e algumas saídas do tipo 
			Moore (que dependem apenas do estado atual).
			
		    Outra estrutura de máquina de estados é projetar a máquina de tal forma que 
			'as saídas em um período de clock dependem das entradas em um período de clock anterior '(isto é, a saída é atrasada). Chamamos essa máquina de 
			"Mealy Machine with Pipelined Outputs".
			
			'equações características' = descrever o funcionamento dos flip-flops através de equações booleanas. Descreve o próximo estado desse flip-flop 
			(após a borda de ativação do clock) em função do estado atual e das entradas desse flip-flop.
																		Q* = f(Q, inputs)
            Note que essa equação n˜ao descreve os detalhes de funcionamento do flip-flop (se é ativo em borda de subida, descida, etc..), apenas a resposta 
			funcional às entradas de controle.																						
			
			Três passos básicos:
				1) Determinar as funções de próximo estado F e de saída G ; 
				2) Usar F e G para construir uma "tabela de transição de estados e saída", que especifica completamente qual é o próximo estado e a saída para
				   cada combinação de estado atual e entrada.
				3) Desenhar um diagrama de estados, que apresenta essa informação em um fluxograma.
				
				Finalmente, podemos analisar a saída do circuito: MAX = Q1·Q0·EN
				O Diagrama de Estados mostra a informação de forma gráfica.
			
    Aula 22 Projeto de Máquinas de Estados			
		Projeto de Máquinas de Estados
		Minimizando a Tabela de Estados
		State Assignment
		Projeto de Máquinas de Estados usando Flip-Flops D
		
	    1 Construir uma tabela de estado/saída que corresponde à descrição do circuito desejado. Nesse ponto, usamos mnemônicos para o nome dos estados. Nesta 
		etapa, também é comum construir o diagrama de estados.
		2 Minimizar o número de estados na tabela.
		3 Escolher um conjunto de variáveis de estado e assinalar códigos aos estados.
		4 Substituir os códigos dos estados nas tabelas de estado/saída.
		5 Escolher um flip-flop (no nosso caso, o flip-flop D).
		6 Construir as equações de excitação para o flip-flop desejado.
		7 Derivar as equações de saída.
		8 Desenhar o esquemático do circuito.
		
		Uma vez assinalados os códigos dos estados, podemos montar nossas tabelas de transição com os valores do estado em cada momento.
		Porém, se n˜ao tivermos utilizado todos os estados possíveis, essa tabela vai ser incompleta (isto é, se tivermos escolhido os estados decompostos 
		000,100,101,110 e 111, o que acontece com a máquina se estivermos, por algum defeito, nos estados 001,010 ou 011?).
		Existem duas abordagens principais: custo mínimo e risco mínimo.
		
		- Na abordagem de risco mínimo, preenchemos os estados n˜ao usados para levar a máquina a um novo estado de recuperação (por exemplo, o estado inicial).
		Assim, se por algum erro a máquina cair num desses estados, sabemos que ela irá voltar ao estado inicial e voltar a funcionar normalmente depois 
		disso (isto ´w, ela se recupera). 
		- Na abordagem de custo mínimo, assumimos que a máquina nunca entra em um desses estados. Assim, podemos usar essas entradas como don’t cares para 
		minimizar nossa lógica de próximo estado. Em geral, isso simplifica bastante a lógica do circuito, mas o comportamento da máquina pode ser bem 
		estranho caso a máquina caia em um dos estados n˜ao usados (pior ainda, ela pode ficar num desses estados para sempre e jamais se recuperar).

    Aula 23 Flip-Flops, Registradores e Contadores
		Flip-Flops
		Registradores
		Contadores
		Circuitos com Contadores
		
		-Comercialmente, o CI mais conhecido que contém flip-flops D é o 74x74, que contém dois flip-flops D independentes com PRESET e CLEAR, ativo na borda 
		de subida do clock. As funcionalidades de PRESET e CLEAR s˜ao assíncronas, isto é, independente do clock do flip-flop.
		
		-Para o flip-flop JK, existem vários tipos de encapsulamento: 74x76 (flip-flop JK mestre-escravo, com transferência por pulso), 74x112 (flip-flop 
		JK gatilhado pela borda) e 74x109 (flip-flop JK gatilhado pela borda, com entrada K negada). Todos eles tem funções assíncronas de PRESET e CLEAR.

		-Para os latches, temos o 74x375, que possui quatro latches D com apenas dois enables (cada enable controla dois latches).
		
		'Registradores'
		-Uma coleção de dois ou mais flip-flops D que compartilham o mesmo clock é chamada de registrador. Um exemplo é o 74x175, que contém quatro latches D.
		-Outro registrador interessante é o 74x374, que tem oito flip-flops D com uma saída de 3 estados, de forma que podemos “desocupar” o barramento de 
		saída.
		-Outros registradores interessantes s˜ao o 74x373, que tem 8 latches D, e o 74x377, que tem oito flip-flops D.
		
		'Contadores'
		-Chamamos de contadores qualquer circuito sequencial cujo diagrama de estados contenha um único ciclo.
		-O módulo do contador é o número de estados em um ciclo. Um contador de m estados é chamado de “modulo-m counter” (ou de “divide-by-m counter”). 
		Note que se m n˜ao for uma potência de 2, temos estados extras que n˜ao s˜ao utilizados.
		
		'Ripple Counters'
		-Podemos construir um contador de m estados usando apenas flip-flops T, sem lógica adicional! Este contador é chamado de ripple counter porque a 
		contagem se propaga (ripples) pelos flip-flops.
		
		'Synchronous Counters'
		-Embora o ripple counter use poucos componentes, o circuito apresenta muito atraso, pois temos que esperar a contagem se propagar até os últimos 
		flip-flops. Além disso, os flip-flops transitam em momentos diferentes, o que é muitas vezes indesejável..
		-Por isso, o mais comum é utilizar contadores síncronos, que s˜ao máquinas de estado projetadas para mudar todos os bits ao mesmo tempo (isto é,
		sincronizados).
		
		'Synchronous Counters'
		- Uma forma de fazer isso é utilizando um flip-flop T com enable. Dizemos que esse circuito tem uma lógica de enable em série (serial enable logic).
		- Outra forma melhor é utilizando a lógica de enable em paralelo (parallel enable logic) (por que?).
		- O CI mais popular é o 74x163, que é um contador módulo-16 que apresenta funç˜oes de CLEAR, LOAD e ENABLES síncronos.
		
		- Como contar até 10 usando o 74x163?
		- Para isso, precisamos resetar a contagem quando chegarmos no décimo estado (de 0 a 9). A funç˜ao CLEAR do 74x163 é síncrona, isto é, só vai ser ativada 
		quando na borda de ativação do clock, e portanto isso pode ser feito facilmente.
		
		- Como contar até 20 usando o 74x163? Para isso, precisamos de dois contadores. Podemos pensar que o primeiro conta até 10 e o segundo conta 2 vezes o 
		primeiro. Assim, o segundo contador só conta quando o primeiro estoura!
		
		- Usando o 74x163 como um divisor de frequências.
		
		- E se eu quiser dividir uma frequência base por 10?

		
		
		
		

		
		
		
		
		

	
		
		
			 
			
			
			
		
	
	
	
	
	

      