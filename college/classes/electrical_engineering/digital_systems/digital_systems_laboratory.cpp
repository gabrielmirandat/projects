1) Portas lógicas e teorema de De Morgan
2) Mapas de Karnaugh
3) Introdução ao VHDL
4) Projeto com FPGA: Comparador
5) Projeto com FPGA: Somador Decimal
6) Multiplexadores e Decodificadores
7) Flip-Flops

Lista de compras:
  -Será necessário comprar fios. Para isso, recomenda-se comprar um pequeno cabo UTP (par trançado para redes locais).
   Com 1 metro de cabo UTP, você tem 8 metros de fio!

  -Recomenda-se também a aquisição de um jogo de alicates pequenos (um por grupo) para facilitar o corte dos fios e a
   montagem do circuito. Dois alicates serão úteis: um de bico (para segurar o fio) e outro de corte (para cortar o fio),
   ambos pequenos. Um jogo com esses alicates pode ser encontrado facilmente em lojas de componentes eletrônicos.

  -Alternativamente ou adicionalmente, recomenda-se a aquisição de fios jumpers (“jumper wire”), que são encontrados nas lojas
   e na Internet.

Obrigações:
  1) Projeto (ou pré-relatório). No começo da aula que dá início ao experimento, deve ser apresentado o projeto dos sistemas a
  serem implementados. Esse projeto deve ser feito em grupo e à mão. Recomenda-se realizar uma simulação com software do tipo CAD
  (computer-aided design), como o Circuit Maker, para evitar surpresas no laboratório. Quando o roteiro não pedir, a simulação não
  será obrigatória, mas pode auxiliar bastante no debug da montagem. O projeto vale 2 pontos e só poderá ser apresentado no
  começo da aula que dá início ao experimento.

  2) Vistos. A cada sistema implementado, o grupo deve chamar o professor ou o monitor para conferir o funcionamento do mesmo, e
  anotar o visto. Ao final da aula, sugere-se que o grupo confira com o professor se todos os vistos foram devidamente anotados na
  lista de controle.

  3) Tarefa (ou relatório). A cada experimento, o professor passará uma tarefa referente ao mesmo. Essa tarefa poderá ser, por
  exemplo, um questionário, um relatório, ou um trabalho. A tarefa de avaliação é INDIVIDUAL, deve ser feita à mão, e vale de
  0 a 8 pontos. A tarefa referente a um dado experimento deve ser entregue no começo da aula que dá início ao experimento seguinte.

  "Técnicas de Debug para Circuitos Digitais"
  Será utilizada a ponta lógica.
  Não colocar fios sobre CIs.
  Usar código de cores		Vermelho para +5V
				Preto ou azul terra
  • Conectando a alimentação e o terra: O pino +V, -V, +5V são fontes de alimentação. Nunca efetuar conexões entre elas, com outras fontes de
    alimentação ou com o pino terra.
  • Muitos CIs possuem entradas que vão habilitar (enable) as saídas.
  • A saída de um CI pode estar conectada a saídas de outros CIs.

  'Experimento 1:' FAMILIARIZAÇÃO COM O PAINEL , PORTAS LÓGICAS E TEOREMA DE DE MORGAN
    'Circuitos Digitais'
      -Informação é representada por dois níveis distintos de tensão, por exemplo, 0 e 5 V, os quais representam o valor lógico 0 e valor
       lógico 1, respectivamente.
      -Isso não é normalmente um problema, a menos que as flutuações sejam grandes ao ponto de causarem dúvida a cerca do nível lógico
       (ex: uma tensão de 5 V que flutuou para um valor de 1 V). Essa característica, denominada imunidade a ruído, é uma das maiores
       vantagens dos circuitos digitais sobre os analógicos.

    'Circuitos TTL (Transistor-Transistor Logic)'
      -São os usados no laboratório.
      -São alimentados com tensão de 5V.
      - 'ENTRADA:' nível 0 (de 0V a 0.8V) nível 1 (de 2V a 5.5V)
      - 'SAIDA:' nível 0 (de 0V a 0.4V) nível 1 (de 2.4V a 5.5V)
      -Na lógica TTL, uma entrada em aberto (não conectada) é tipicamente interpretada como um nível lógico 1.

    "Painel lógico"
      -O painel lógico utilizado em laboratório conta com alguns módulos destinados à entrada e à saída de dados, descrritos a seguir.
      'Chaves de 1 e 2 posições'

	'1 posição' botão de letra P, usado para aplicação manual de pulsos no sistema. A saída é normalmente 0 (terra), mas quando o botão
		    é pressionado a saída é 1.
	'2 posição' botão de letras A ou X, usada para aplicação de valores lógicos de entrada. Chave para baixo indica saída 0, enquanto que
		    para cima indica 1.

	Essas portas contam com um circuito destinado eliminar o ruído de comutação (“bouncing”). Quando a chave mecânica fecha, o contato
	 não se estabiliza imediatamente. Pode haver comutações microscó- picas durante um intervalo de 10 a 50 ms, produzindo vários pulsos
	 em forma de ruído.

      'Relógios'
	-Usado para sincronização de operações sequenciais. As saídas fornecem ondas quadradas com patamares em 0 e 5 volts, com freqüências
	 de 1 Hz ou 100 kHz.

      'Diodo foto-emissor (LED)'
	-Servem para indicar o nível lógico de um dado ponto num circuito.
	-Se entrada estiver no nível lógico 1, o diodo acenderá. O diodo apaga se o nível lógico for 0.
	-Se o diodo estiver desconectado, ele acenderá, pois a entrada em aberto é interpretada como nível lógico 1.
	-o LED é um diodo, e não uma lâmpada! Lâmpadas são dispositivos resistivos, enquanto que diodos são dispositivos semi-condutores,
	 com princípios de funcionamento bem diferentes.

      'Mostradores numéricos'
	-O painel dispõe de dois mostradores numéricos. Cada um conectado a um conjunto de 4 LEDS, à sua direita ou à sua esquerda.
	-O número mostrado nesses mostradores correspondem à representação em hexadecimal do número representado pelos 4
	 bits observados nas entradas dos LEDs correspondentes. Por exemplo, se nos LEDS aparece 1,0,0 e 1, o mostrador mostra 9.

      'Ponta lógica'
	-Módulo de teste e depuração de circuitos montados.É semelhante ao módulo do diodo emissor de luz, porém, com um refinamento.
	-É capaz de distinguir entre o nível lógico 0 (luz verde), nível lógico 1 (luz vermelha) e nível indeterminado.

    "Portas E, OU e INVERSORA"
      -Circuitos destinados a executar operações lógicas são denominados 'portas'.
      -3 operações lógicas básicas: E, OU e NEGAÇÂO.
      -As portas são implementadas com circuitos integrados (CIs).
      -Cada CI contém em geral mais de um porta.
      'CI nº 7408 é da família TTL e tem 14 pinos, 2 para alimentação, demais dão acesso a 4 portas E de 2 entradas, que podem ser usadas '
       'independentemente'
      -Conjunto de portas autosuficientes são ditas universais.

    "Portas NÃO-E e NÃO-OU"
      -Uma porta NÃO-E é equivalente a uma porta E seguida de uma porta INVERSORA.
      -Tanto NÃO-E quanto NÃO-OU são universais.

    "Portas OU-EXCLUSIVO"
      -A porta OU-EXCLUSIVO de duas entradas compara dois bits e a saída será 1 se, e somente se, eles forem diferentes.
      -Uma porta OU-EXCLUSIVO de várias entradas terá a saída igual a 1 se tiver um número ímpar de níveis lógicos 1 na entrada.
      -A porta NÃO-OU-EXCLUSIVO compara dois bits binários e a saída será 1 se, e somente se, eles forem iguais. No caso de várias entradas
       a saída só será 1 se houver um número par de níveis lógicos 1 na entrada.
      -As portas OU-EXCLUSIVO e NÃO-OU- EXCLUSIVO são muito utilizadas para comparar palavras em tomada de decisões. O emprego do bit de
       paridade para a detecção de erros é um exemplo típico de sua aplicação.

     "Teorema de De Morgan"
       - “se a barra de inversão entre duas variáveis for quebrada, a operação (· ou +) entre elas deve ser intercambiada”

     "Característica físicas das portas lógicas"
      'Atraso'
	-Uma consideração importante é o atraso de propagação das portas, isto é, o tempo necessário para que sua saída mude, depois que
	 uma entrada mudou.
	-Quando diversas portas são ligadas em cascata, o atraso total de propagação é igual à soma dos atrasos em cada porta.
	-Na família TTL, as portas têm um atraso típico na ordem de 10 ns.
	-Os atrasos de propagação estabelecem um limite superior para a velocidade de operação de qualquer sistema digital.

      'Fatores de Carga'
	-Se em um determinado circuito houver necessidade de acionar mais que 10 entradas, podemos usar portas especiais como “buffer” para
	 aumentar essa capacidade.

  'Experimento 2:' CIRCUITOS COMBINACIONAIS – MAPA DE KARNAUGH
        -Um circuito de decisão de maioria, em que a saída é 1 se e somente se a maioria das entradas for 1 é
         apresentado como um exemplo de aplicação.

        -Forma canônica disjuntiva = Soma de produtos.
        -Forma canônica conjuntiva = Produto de somas.
        -A forma canônica deve conter todas as entradas em cada termo.

  'Experimento 3:'INTRODUÇÃO À LINGUAGEM VHDL
        -A estrutura básica de uma descrição de uma unidade em VHDL:
            - entity declaration, é a definição estrutural do circuito. Nessa etapa, são apenas designados os sinais de entrada
              e de saída, sem que se definam relações entre esses sinais e sem qualquer detalhamento acerca do funcionamento do
              dispositivo.
                                entity nome-da-estrutura is
                                    port (nome-de-sinais : modo tipo-de-sinal;
                                        nome-de-sinais : modo tipo-de-sinal;
                                        ...
                                        nome-de-sinais : modo tipo-de-sinal);
                                end nome-da-estrutura;
              O modo atribuído classifica cada sinal como de entrada (IN) ou saída (OUT ou BUFFER); eventualmente, o
              sinal poderá ainda ser ora de entrada, ora de saída (INOUT).

            - architecture definition. Nessa seção, define-se uma implementação particular da unidade introduzida na primeira
              parte.
                                architecture nome-da-descrição-operacional of nome-da-estrutura is
                                    declarações de tipos
                                    declarações de sinais
                                    declarações de constantes
                                    declarações de funções
                                    declarações procedimentos
                                    declarações de componentes
                                begin
                                    declaração
                                    declaração
                                    ...
                                    declaração
                                end nome-da-descrição-operacional;
              Entre a primeira linha (architecture) e o begin, definem-se todas as funções, constantes, procedimentos, sinais
              e tipos de sinais a serem utilizados durante a descrição operacional do circuito. Também são declarados os
              componentes que serão referenciados no corpo da seção. Isso permite, por exemplo, que um dispositivo já descrito
              em VHDL seja uma das partes de um dispositivo maior, levando a uma estruturação hierárquica dos programas.
              Em seguida, entre o begin e o end principais da descrição operacional, estabelecem-se as relações entre os sinais
              de entrada e de saída do circuito. Podem estar presentes atribuições diretas de valores lógicos, funções,
              expressões booleanas, etc.

        Uma vez elaborada uma primeira descrição VHDL de um circuito, chega-se à fase de simulação. A forma mais sistemática
        de fazê-lo é criar uma outra unidade VHDL, sem sinais de entrada ou de saída, apenas com uma referência ao circuito a
        ser simulado e com um processo que gere todas as possíveis situações em que ele deve ser testado.
        'Note que as 4 combinações possíveis das entradas x e y são geradas entre as linhas process e end process, com um
        'intervalo de 20 ns entre elas.

        -------------- Simulação da porta x->y implementada -------------
entity sim_impl is
end sim_impl;
architecture sim_impl_op of sim_impl is
component porta_implica is
    port (x,y: in BIT;
        z: out BIT);
end component;
signal x_sim,y_sim,z_sim: BIT;
begin
    U1: porta_implica port map(x_sim,y_sim,z_sim);
    process
    begin
        x_sim <= '0';
        y_sim <= '0';
        wait for 20 ns;

        x_sim <= '0';
        y_sim <= '1';
        wait for 20 ns;

        x_sim <= '1';
        y_sim <= '0';
        wait for 20 ns;

        x_sim <= '1';
        y_sim <= '1';
        wait for 20 ns;

        x_sim <= '0';
        y_sim <= '0';
        wait;
    end process;
end sim_impl_op;

        Com tempo:
        begin
            z <='0' after 10 ns when x='1' and y='0' else
            '1' after 10 ns;
        end porta_implica_op;


