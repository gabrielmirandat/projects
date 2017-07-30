PROVA 3

@'Controle de sequência'
• Estruturas de controle:
  – provêm arcabouço para combinar operações e dados em programas e conjunto de programas.
  – aspectos da combinação de dados e operações:
    • controle da seqüência de execução das operações,
    • controle da transmissão de dados entre subprogramas de um programa (controle de dados) (Capítulos 7 e 8)
• Sumário
6.1 Controle de seqüência implícito e explícito.
6.2 Sequenciamento com expressões aritméticas.
6.3 Sequenciamento com expressões não aritméticas.
6.4 Controle de seqüência entre comandos.

'Controle de Seqüência Implícito e Explícito'
• Grupos de estruturas de controle de seqüência
  – usadas em expressões (dentro de comandos), p. ex.:
    • regras de precedência, associatividade e parênteses.
  – estruturas usadas entre (grupos de) comandos, p. ex.:
    • comandos de iteração e condicionais
  – estruturas usadas entre subprogramas, p. ex.:
    • chamada de subprogramas,
    • corotinas,
    • outras formas de comunicação entre subprogramas.
  – Obs.: esta divisão é imprecisa.
    • Lisp e APL não possuem comandos e possuem expressões, mas usam mecanismo de controle de seqüência similar.

• Controle implícito: estruturas definidas pela LP
  – ordem física da seqüência dos comandos,
  – precedência das operações em expressões.
• Controle explícito:
  – estruturas de controle inseridas pelo programador para modificar a seqüência implícita de operações
    • comando go to e rótulos de comandos,
    • uso de parênteses em expressões,
    • comandos de iteração e condicionais.
    
'Sequenciamento com Expressões Aritmética'
• Qual a ordem de execução das operações?
  - fórmula de báskara
• O controle básico é a composição funcional:
  – as operações e seus operandos são especificados,
  – um operando pode ser uma constante, OD ou outra operação, e assim por diante, em qualquer nível,
  – um estrutura de árvore para a expressão aritmética é induzida pela composição funcional, com a definição da prioridade e associatividade 
  das operações. 
  - Em assembly a codificação dessa fórmula requer 15 ou mais instruções. Controla ordem de execução.
  
'Representação em Árvore'
- Vai descendo nos filhos da esquerda e faz:
  -> se só um filho:operador-pai filho
  -> se dois filhos:nó-esquerda operador-pai nó-direita.
- Ai sobe e faz a mesma coisa, ela é de baixo para cima.

'Sequenciamento com EA'
'Sintaxe para expressões'
• É necessário uma notação para escrever árvores como uma seqüência linear de símbolos:
  
				r1=(-b+sqrt(b^2-4*a*c))/(2*a)

1) Notação prefixada: operador, op. esquerda -> direita (Notação prefixada é usual em funções.)
  • Polonesa de Cambridge (utilizada em Lisp)
    (/ (+ (-b) (sqrt ( (^ b 2) (* (* 4 a) c ) ) ) ) (* 2 a))
  • Notação polonesa (Lukasiewicz)
    / + - b sqrt  ^ b 2 * * 4 a c * 2 a
2) Notação pósfixada ou polonesa reversa
    b- b 2 ^ 4 a * c *  sqrt + 2 a * /
3) Notação infixada, mais comum
    (-b + sqrt(b^2-4*a*c))/2*a	<expr. booleana>? <cmd1>: <cmd2>
    
'Semântica das expressões'
• O algoritmo que o tradutor de uma LP usa para avaliar expressões aritméticas determina a semântica utilizada.
  – Qualquer dos formatos de expressão pode ser utilizado na representação interna de uma expressão aritmética.
  -> avaliação:
    - prefixada
    - pósfixada
    - infixada
 
'Avaliação prefixada'
• Aridade dos operadores conhecida -> única varredura. Senão os parênteses são necessários.
  Seja P uma EA consistindo de operadores e operandos:
    1. se (op = next(P)) é operador então push(op); 
       n = número(operandos,op), N op = 0;
    2. se opn =next(P) é operando então push(opn);
       Nop = Nop + 1;
    3. Se Nop = n, 
       então substitua os n operandos e operador pela avaliação de (op op n1 , op n2 ,...,op nn )

    obs: requer batimento do número de operandos.
    Notação prefixada é genérica (para qualquer número de operandos).
    
'Avaliação Pósfixada'
• Seja P uma EA em notação pósfixada:
  1. se op n = next(P) é um operando então push(op n );
  2. se op=next(P) é um operador n-ário então seus n argumentos devem estar no topo da pilha. Substitua- os pelo resultado de aplicar o operador 
  op a eles.
– Observações:
  • esta estratégia é usada para geração de códigos em muitos tradutores de LP.
  • se next(P) é um operador então todos os seus operandos já foram avaliados e empilhados.
  
'Avaliação infixada'
• Embora a notação infixada seja comum, seu uso em computação leva a ambiqüidades:
  – precedência entre os operadores deve estar definida na LP ou explicitado pelo programador:
    2*3+4 = (2*3)+4 ou 2*(3+4) ?
  – associatividade dos operadores também deve estar definida na LP ou explicitada pelo programador:
    2-3-4 = (2-3)-4 = -5 ou 2-(3-4) = 3 ?
    – o mais comum é à esquerda: a-b-c = (a-b)-c
    – há casos em que deve ser à direita: 4^3^2 = 4^(3^2)
  – é mais adequada para operadores binários.
O mais seguro é verificar os padrões que a LP adota!

'Semântica das Expressões'
'Precedência em ADA'
  • Maior: Unários, binários e relacionais.
  • Menor: Booleanos.
  
'Sequenciamento com EA'
'Representação em run time'
• O tradutor trabalha em dois estágios:
  1. estabelece a árvore básica de controle, (utiliza regras implícitas de precedência e associatividade)
  2. detalha as decisões referentes à ordem de avaliação. (gera uma seqüência [otimizada] de código).
Formas mais fáceis para decodificação de EA são:
  1. seqüência em código de máquina
    a) EA traduzida para código de máquina usando os 2 estágios 
    b) máquinas convencionais usam armazenamento temporário para tratar resultados intermediários,
    c) representação em código de máquina possibilita interpretação por hardware, muito mais rápida.
    Forma executável é necessária devido a inadequação da forma infixada do programa fonte.
  2. Estrutura em árvore:
    • nessa representação, obtida ao final do estágio 1, a EA pode ser avaliada usando um interpretador por software.
    • execução (estágio 2) implica percorrer a árvore. – em Lisp, onde o programa inteiro tem uma estrutura em árvore.
  3. Forma pósfixada e prefixada:
    • a representação em run time é obtida executando os dois estágios em um único passo.
    • a EA pode ser avaliada por um algoritmo simples, visto anteriormente.
    • em máquinas com organização baseada em pilha, o código é representado em forma pósfixada. 
    Como as estruturas em árvores de EA são avaliadas?
    
'Avaliação da expressão representada em árvore'
• O tradutor opera em duas fases:
  1) geração da representação em árvore.
  2) determinação da ordem de avaliação (seqüência de códigos primitivos)
• Esta segunda fase apresenta vários problemas relacionados à ordem de avaliação dos termos da EA:
  1) regra de avaliação uniforme,
  2) efeitos colaterais,
  3) condições de erros,
  4) expressões booleanas com curto circuito.
  
'Problema 1: regra de avaliação uniforme'
• Regra Gulosa (passagem de parâmetros por valor):
  1) para cada nó operador, avalie primeiro seus nós operandos,
  2) aplique o operador aos operandos avaliados.
  • A ordem de avaliação dos operandos ou de operações independentes pode ser escolhida para otimizar o uso de temporários.
    – Ex.: (a+b)*(c-a): somar ou subtrair primeiro leva ao mesmo resultado.
  • A uniformidade gulosa, nem sempre é desejável.
    – Ex.: function SE (a:boolean; b, c:integer): integer
	begin if a then SE := b else SE := c; end;
	      .....
	Z := SE (X==0, X,Y/X); - gera a divisão por zero
  • Regra preguiçosa (passagem de parâmetros por referência):
    1) aplique o operador sobre os operandos não avaliados,
    2) só avalie uma expressão quando ela for requerida.
  
• Avaliação gulosa e preguiçosa são por si SÓ inadequadas
• Uma mistura dessas regras parece mais ser adequada:
  – duas categorias de funções Lisp: as que recebem operandos já avaliados e as que recebem sem avaliação.
  – Algol: suas primitivas são gulosas. Operações definidas pelo usuário são gulosas ou preguiçosas (por nome)
• Avaliação preguiçosa requer uma substancial simulação por software, isto pode torná-la uma sobrecarga para algumas LP a moda aritmética 
  como C e Fortran.
• A avaliação preguiçosa é o padrão em LP funcionais puras, como Haskell, Goffer e Hugs.

'Problema 2: efeitos colaterais'
• Seja a expressão y * f(x) + y. 
A ordem de avaliação dos termos pode alterar seu resultado?
  1) Não, se f() não tem efeito colateral sobre y.
  2) Sim, se f() tem efeito colateral sobre y.
• Suponha que y =2 e f(x) retorne o valor 5. Mas a execução de f() altera o valor de y =3. Considere as seqüências:
  1) avaliar cada termo na seqüência: 2 * 5 + 3 = 13
  2) avalia y apenas uma vez: 2*5 +2 = 12
  3) avalia f(x) antes de y: 3*5+3=18
Todos esses valores são válidos de acordo com a sintaxe da LP.
• Há duas posições sobre efeitos colaterais:
  1) não permiti-los e avaliar de modo otimizado as expressões.
  2) permiti-los e avaliar as expressões na ordem declarada, deixando a responsabilidade da repercussão de efeito colateral com o programador.
  
'Problema 3: condições de erros'
• Um tipo especial de efeito colateral é ocasionado por falha de operações gerando condições de erros (divide by zero, overflow, underflow)
• Como tais erros podem ser decorrentes da ordem de avaliação, o programador precisa poder definir a ordem de avaliação usada. Isto impede a
  otimização do código.
• A solução de tais dificuldades é ad hoc e varia de LP para LP e de implementação para implementação.

'Problema 4: expressões lógicas em curto-circuito'
• Seja as operações booleanas:
  1) b1 or b2, se b1=true, b1||b2=true
  2) b3 and b4, se b3=false, b3&&b4=false
O valor de primeiro operando pode curto-circuitar toda a expressão.
  • Muitos erros são gerados na expectativa que a LP implemente o comportamento acima, contudo nem todas o fazem, em nome da “avaliação uniforme”.
Exemplo:
  1) if ((A==0) ||(B/A>C)) { ... }
  2) while ((I<=UB) &&(V[I]>C)) { ... }
  
'Sequenciamento em expressões não aritméticas'
'Casamento de padrões'
• Em LP como ML, Haskell, Prolog e Snobol casamento de padrões é crucial
• Em Haskell
		  qsort [ ] = [ ]
		  qsort [x] = [x]
		  qsort (x:xs) = qsort ys ++ [x] ++ qsort zs
		  where ys = [y | y <- xs, y <= x]
		  zs = [z | z <- xs, z > x]
• Em Snobol, há o casamento de string por substituição, baseado na gramática BNF. Ex.:
  1) A::= 0|1|0A0|1A1, gramática que reconhece palíndromos impares sobre o alfabeto 0 e 1.
  2) seja o palíndromo 00100. A = 0A0; A=0A0 e A=1
  
• Prolog casa padrões usando tuplas como elementos pertencentes a uma relação. Outras instâncias podem ser derivadas dessas tuplas.
  – Assim, a partir da base de conhecimentos:
    pai(joao, jose).
    pai(joao, joana).
    pai(jose, bob).
    irmao(A,B) :- pai(P,A), pai(P,B), dif(A,B).
  – O interpretador Prolog, para
    ?- pai(joao,X). 	#conclui: X= jose, X=joana
    ?- pai(P,joana).	#conclui: P=joao
    ?- irmao(jose,X).	#conclui: X=joana
• O poder de Prolog é construir relações que podem ser inferidas a partir de fatos e regras. Os fatos são batidos CONTRA a base de conhecimento.
Hipótese do mundo fechado e negação.

'Reescrita de Termo'
• Reescrita de termo ocorre quando substituímos um termo pelo seu equivalente, de acordo com a regras estabelecidas. É uma forma restrita de
  casamento de padrões.
• Seja a seguinte regra BNF
A -> 1|0A podemos gerar a string 0001, com a seguinte derivação
    A -> 0A      , pela regra A -> 0A
    0A -> 00A    , pela regra A -> 0A
    00A -> 000A  , pela regra A -> 0A
    000A -> 0001 , pela regra A -> 1
• Exemplo em Haskell
    fib 0 = 1
    fib 1 = 1
    fib (n+1) = fib n + fib(n-1)
-- Só definida para valores > = 0

'Unificação'
• Dado duas expressões U e V, acha substituições para as variáveis em U e V que torne essas expressões idênticas.
    pai(joao, jose).
    pai(joao, joana).
    pai(jose, bob).
    pai(jose, juba).
    irmao(A,B) :- pai(P,A), pai(P,B), dif(A,B).
    tio(T,S) :- pai(P,S), irmao(P,T).
– Consultas
    ?- tio(X,bob).	#conclui: X=joana
    ?- irmao(joana,X).	#conclui: X= jose
    ?- livro(autor(“jorge amado”), titulo(T)) = livro(A, titulo(“mar morto”))	#conclui: A= autor(“jorge amado”), T= “mar morto”
Comentar sobre substituição na passagem de parâmetros e expansão de macros.

'Retrocesso (Backtracking)'
  pai(joao, jose).
  pai(joao, joana).
  pai(jose, bob).
  pai(jose, juba).
  pai(juba, zeca).
  mae(joana,jo).
  irmaos(A,B) :- pai(P,A), pai(P,B), dif(A,B).
  tio(T,S) :- (pai(P,S); mae(P,S)) , irmaos(P,T).
• Consulta
  ?- pai(X,Y), write(X), write(‘ eh pai de ’), write(Y), nl, fail.
  ?- tio(T,S).
  
'Controle de Seqüência entre comandos'
'Comandos básicos'
  • Controle de seqüência determina a ordem na qual os comandos individuais são executados.
  • Comandos básicos aplicam operações sobre os OD, alterando o estado do sistema.
  • Exemplos de comandos básicos:
  1) Atribuição
    - liga um valor a um OD .
  2) Chamada de subprograma
    - liga valores aos parâmetros formais.
  3) Entrada e Saída
    - entrada de dados é feita para OD e a saída altera os valores da variável em um buffer.
    
'Controle de seqüência a nível de comando'
  •Composição
    - É uma seqüência textual de comandos. Os comandos nessa seqüência são executados quando a estrutura maior do programa que os contém for
    executada.
  •Alternação
    - apenas uma de duas seqüência de comandos é executada quando a estrutura maior do programa que as contém for executada.
    Pode se ter alternação com várias seqüências opcionais, das quais apenas uma é executada.
  •Iteração
    - Uma seqüência de comandos pode ser executada, repetidamente, zero ou mais vezes, quando a estrutura maior do programa que a contém for 
    executada.
  •Controle de sequência explícito:
    - goto incondicional, goto condicional, break e continue.
  
'Controle de Seqüência estruturada'
  • Comando composto: begin .. end; 
    É a estrutura básica para representar a composição de comandos.
  • Comandos condicionais
    Um comando condicional expressa alternação. As formas mais comuns de comandos condicionais são: if e case.
  1) if <cond> then <comando> endif
    if <cond> then <comando 1 > else <comando 2 > endif
    A escolha entre muitas opções pode ser feita por aninhamento de if.
  2) case tag
    caso 1: comando 1 ;
    caso 2: comando 2 ;
    ...
    caso n: comando n ;
  Outros casos: comando;
    end case;

'Interação'
  • Repetição simples
    perform <corpo> k times, como em COBOL
  • Repetição enquanto uma condição se mantém ou até que uma condição se estabeleça.
    while <teste> do <corpo>;
    repeat <corpo> until <teste>
  • Repetição enquanto incrementa um contador
    for i:= 1 step 2 until 30 do <corpo>;
    (Estrutura típica do Algol)
    de modo geral, tem-se
    for i:= <exp 1 > step <exp 2 > until <exp 3 > do <corpo>;
    
  • Repetição indefinida
    1) loop ... exit when <condition> ... end loop; (ADA)
    2) while true do begin ... end; (Pascal)
      • C permite todos esses tipos na mesma estrutura for:
      for (exp1; exp2; exp3) {corpo};
    1) contador simples de 1 a 10
      for (i=1; i<=10; i++) {corpo};
    2) loop infinito
      for (; ;){corpo};
    3) Contador com condição de saída
      for (i=1; i<=100 &&NotEndfile; i++) {corpo};
      •Loops com múltiplas saídas o desvio incondicional é necessário: faz-se uso do goto ou exit (Ada) ou break (C).
  
'Teoria de Programas Primos'
  • Elaborada por R. Madux (1975) em sua tese “A study of Program Structure”, na Universidade de Waterloo.
  • Pode ser usada para descrever uma teoria consistente de estruturas de controle.
  • Foi desenvolvida para generalizar a programação estruturada e definir uma única decomposição hierárquica de um diagrama.
  
'Programa próprio'
  • Definição: é um programa formado por estruturas de controle (blocos) possuindo:
    1) um único arco de entrada,
    2) um único arco de saída,
    3) um caminho do arco de entrada para cada nó e um caminho destes para o arco de saída.
    
  • Definição:	
    é um programa próprio que não pode ser dividido em programas próprios menores.
  • Uma longa seqüência de funções é um primo.
  • Um programa composto é um programa próprio que não é primo.
  • Substituindo cada componente primo no programa próprio por um nó de função se obtém um primo ao final.
  
'Teorema da Estrutura'
  • Todo programa pode ser decomposto em programas primos.
  • Böm e Jacobini mostram que qualquer programa primo pode ser escrito em termos das estruturas if e while.
  1. Dado qualquer fluxograma, rotule cada nó. Rotule o arco de saída com 0.
  2. Defina I como nova variável do programa.
  3. Transforme cada nó, básico, acrescentando as suas saídas um nó de função com I:=s, onde s é o número do nó para onde o arco vai. 
  4. Reconstrua o programa, I=1; while I != 0 faça case I of 1:..; 2:.. n:..end;
Motivação: usar apenas as estruturas de controle limita o poder dos programas?

  • Programa estruturado não é sinônimo de bom programa.
  • Apenas usa estruturas de controles que são primas, com poucos tipos de nós.
  • Um código espaguete, gera um código estruturado ruim.
  • Todo programa pode ser feito com as estruturas padrão: if, while, do-until, etc.
  • Não há melhoria do algoritmo por isto.
  • Sabe-se que haverá uma solução não pior e talvez até muito melhor que uma estruturada.
  
@'CONTROLE DE SUBPROGRAMA (PARTE 1)'
CONTEÚDO
  -> Controle de seqüência (ativação) de subprograma 
  -> Subprogramas simples e recursivos.
  -> Atributos de controle de dados 
  -> Nomes e ambientes de referências, escopo estático e dinâmico, estrutura de blocos, dados locais e ambiente de referência local.
  
'CONTROLE DE SEQÜÊNCIA DE SUBPROGRAMA'
  -> Mecanismos simples para seqüenciamento entre dois subprogramas:
  -> Como um subprograma invoca outro e como o subprograma chamado retorna ao chamador.
  -> Uso dos comandos call e return.
  Call e return são comuns a muitas linguagens.

'CALL/RETURN DE SUBPROGRAMAS'
'REGRA DA CÓPIA' (como se copiasse o programa inteiro onde foi chamado)
  -> Um programa tem um único programa principal, o qual durante a execução pode chamar vários subprogramas; que por sua vez também podem
  chamar outros subprogramas.
  -> Espera-se que uma subprograma chamado, terminada sua execução, retorne o controle ao seu chamador, no comando subsequente à sua chamada.
  -> Regra da cópia (efeito do comando call). Tudo acontece, como se para o lugar da chamada fossem copiados os comandos do subprograma, com
  as substituições adequadas para parâmetros e identificadores em conflito.
  -> Visto dessa forma, chamada de subprograma é uma estrutura de controle que torna desnecessário copiar centenas de comandos para os diversos
  pontos onde o subprograma é invocado.
  Hierarquia de programas
  Gerência de armazenamento baseada em pilha
  
  -> Subprograma não recursivo
  Não chama a si próprio e nem inicia uma cadeia na qual algum elemento o chama.
  -> Subprograma diretamente recursivo
  Chama a si próprio.
      Ex.: A -> A
  -> Subprograma indiretamente recursivo
  Inicia uma cadeia, na qual há um elemento que o chama.
      Ex.: A -> B -> C -> A
  Visão regra da cópia implica que subprograma não pode ser recursivo
  
'HIPÓTESES IMPLÍCITAS NA REGRA DA CÓPIA'  
  1. Subprogramas não recursivos
  Aplica-se a regra da cópia. Durante a tradução, faz-se a cópia onde o subprograma é invocado, não havendo necessidade de subprogramas em
  separado (em princípio, não na prática).
  
  2. Subprogramas recursivos
  Não se aplica a regra da cópia. Se em cada ponto onde há uma chamada se fizer cópia, e nesta cópia há outra chamada, não há parada.
  Programas recursivos são necessários pois alguns algoritmos são recursivos.
  
  3. Chamada explícita
  Cada ponto de chamada precisa ter um call explícito. No entanto subprogramas para tratar exceções não têm chamadas explícitas.
  
  4. Execução completa
  Os subprogramas executam completamente, a cada chamada, do início ao fim. Chamado uma segunda vez, executam completamente, do início ao fim.
  No entanto, co-rotina inicia sua execução do ponto de sua ultima terminação.
  Manipuladores de interrupções e traps são ativados de forma especial
  
  5. Transferência de controle (call explícito)
  Um call transfere o controle diretamente para o subprograma, com o mesmo efeito de se copiar o corpo do subprograma no chamador.
  -> Para subprograma sincronizável, a chamada pode ser programada para execução posterior.
  
  6. Seqüência de execução simples
  Na hierarquia de subpgm, num dado instante, podemos identificar: um em execução, outros suspensos, e os demais (os já executados e os ainda não
  chamados). Mas tasks são paralelas.
  
  Fortran é baseado diretamente na visão da regra da cópia de subprogramas
  
'PONTEIRO DA INSTRUÇÃO CORRENTE (CIP)'
  ->  O tradutor gera um código executável, a partir do fonte e o armazena no segmento de código, na área de ativação.
    1) Esse código é um conjunto de instruções. 
    2) Essas instruções são executadas pelo hardware ou por interpretador simulado por software.
    3) Em qualquer ponto durante a execução, alguma instrução está sendo executada ou próximo de sê-lo.
    4) Essa instrução é chamada instrução corrente. 
  -> A variável CIP é um apontador para ela. O interpretador faz o seguinte:
    a) Pega a instrução apontada pelo CIP.
    b) Atualiza o CIP para apontar para a próxima instrução na seqüência.
    c) Executa a instrução (que pode alterar o CIP).
  
'PONTEIRO DO AMBIENTE CORRENTE  (CEP)'
  -> Todas as ativações do mesmo subprograma usam o mesmo segmento de código mas registros de ativações distintos. É necessário saber qual
  o registro de ativação que está em uso.
  -> CEP aponta para o registro de ativação em uso.
  -> O registro de ativação representa um ambiente de referência local do subprograma.
  -> Um segmento de código e um registro de ativação são criados para o programa principal:
    1) O CIP aponta para a instrução corrente no segmento de código.
    2) O CEP aponta para a posição inicial do registro de ativação.
  -> Quando uma instrução call é alcançada, cria-se um registro de ativação para essa chamada, junto com um par (CIP,CEP).
  
  -> O subprograma call salva os valores correntes do (CIP,CEP) antes de atualizar com os novos valores do programa chamado.
  -> Quando uma instrução return é alcançada, os velhos valores do par (CIP,CEP) são restabelecidos.
  -> Os valores de (CIP,CEP) são salvos no registro de ativação do subprograma que está sendo chamado, num OD criado pelo sistema, 
  chamado “ponto de retorno”.
  -> O ponto de retorno contém dois ponteiros (ip,ep), que representam os velhos valores de CIP e CEP.
  -> Observe! Há apenas um par (CIP,CEP) para cada programa em execução.
  
'MODELO FORTRAN E COBOL'
  -> Propriedades da regra da cópia:
    1) No máximo uma ativação de qualquer subprograma está em uso, em qualquer ponto durante a execução.
    2) Um subprograma P pode ser chamado várias vezes, durante a execução, mas cada ativação estará completa e terminada quando a próxima 
    ativação começar.
  -> Das propriedades 1 e 2, pode-se chegar a um modelo mais simples de implementação.
    Nesse modelo, estaticamente é alocado um único registro de ativação para cada subprograma, junto com seu segmento de código. Ao invés 
    de criar um registro de ativação a cada chamada. 
    CS e registros de ativação dos subpgm e principal estão na memória
    
    PAR: program address register (hardware) ou PC
    Alocação única: CEP é desnecessário; call e return por hardware
  
'SUBPROGRAMAS RECURSIVOS'
  -> Um subprograma recursivo chama a si próprio ou inicia uma cadeia na qual algum elemento chama o subprograma inicial.
  -> O modelo com CIP e CEP é geral e suficiente para permitir recursão.
  -> Seja S um subprograma recursivo. A cada chamada de S, um novo registro de ativação para S é criado.
  
  Chamada recursiva de S: encadeamento dinâmico de registros de ativação
  
'ATRIBUTOS DE CONTROLE DE DADOS'
  -> Está relacionado ao acesso aos dados de diferentes pontos durante a execução do pgm.
  -> Dados precisam ser providos para a operação em realização, na seqüência de execução.
  -> As características de controle de dados da LP determinam como os dados são providos para cada operação e como o resultado de
  uma operação pode ser salvo e recuperado depois, como operando de outra operação.
  
'NOMES E AMBIENTE DE REFERÊNCIA'
  ->  Modos de um OD se tornar disponível para uma operação:
    1) Transmissão direta (usado em expressões): 
      - Um OD computado em um operação pode ser transmitido diretamente para outra operação. Como 2*Z na expressão X:=Y+2*Z;
      - É alocada uma armazenagem temporária para o OD (anônimo)
    2) Referenciando através de um OD nomeado.
      a) Dá-se um nome para um OD, quando ele é criado, e esse nome é usado para designá-lo como operando de uma operação.
      b) Um OD pode ser criado como componente de um outro OD, nesse caso o nome do OD maior e o nome do componente são usados na seleção.
  
      O problema central é o significado dos nomes, em controle de dados.

'ELEMENTOS QUE PODEM SER NOMEADOS'
  -> Categorias de nomes encontradas na maioria das LP: 
    1) Variáveis
    2) Parâmetros formais
    3) Subprogramas
    4) Tipos definidos
    5) Constantes
    6) Rótulos
    7) Exceções
    8) Operações primitivas: +, sqrt, etc. 
    9) Literais constantes: 3.5, 17, etc. 
  -> Categorias 1 a 3 serão objeto de estudo nesse tópico
  -> Nas categorias de 4 a 9,  referência a nomes são resolvidos em tempo de tradução, em geral. 
  -> Casos especiais: 
    1) Exceções via encadeamento dinâmico em ADA.
    2) Goto referenciando rótulos em outros subprogramas, como em Pascal. 
    3) Símbolos de operações primitivas, em SNOBOL4, podem ser redefinidos. 
 
'Nomes'
  1) Nomes simples (sem qualificação).
  2) Nome composto (nome para um componente de um ODE).
     Ex.: var disc: array[1..100] of 
                                record
                                   codisc: string[10] ;
                                   turma: array [1..10] of 
                                                    record
                                                         id: char;
                                                         sala: string[15];
                                                         prof: string[30];
                                                    end ;
				   end ;  
  -> Referência: disc[5].turma[3].sala := “ICC BT 10/30” 
  
  -> Associação é a ligação de identificador ao OD ou subprograma. Durante a execução do programa, em geral, observa-se:
    1) Variáveis declaradas: identificadores são associados aos OD.
    2) Nomes de subpgm chamados são ligados às suas definições.
    3) O pgm invoca operações de referenciamento para determinar o particular OD ou subpgm associado com um identificador.  
      Ex.: Para a expressão A:=B+FN(C); 4 operações de referenciamento são necessárias para recuperar os OD (A, B, C) e subpgm FN envolvidos. 
    4) A cada chamada de um subpgm, um novo conjunto de associações é criado para aquele subpgm: 
      a) nome de parâmetros e nomes de variáveis declaradas são associadas com OD. Pode-se criar novas associações para os subpgm 
      declarados aninhados. 
    Durante a execução do programa, em geral, observa-se:
   5. Enquanto um subprograma executa, ele usa operações de referenciamento para determinar OD ou subprogramas associados aos identificadores.
      a) Algumas referencias podem ser as criadas por associações na entrada do subprograma. 
      b) Outras podem ser as associações criadas no programa principal. 
   6. Quando o subprograma retorna o controle ao programa principal, suas associações são destruídas (ou tornam-se inativas).
   7. Quando o controle retorna ao programa principal, a execução continua como antes, usando as associações criadas no início da execução. 
   Eventos observados durante a execução em muitas LP
   
'Principais Conceitos de Controle de Dados'
  -> Associados ao padrão de criação, uso e destruição de associações:
    - Ambiente de referência
    - Visibilidade
    - Escopo dinâmico
    - Operação de referenciamento
    - Referências local, não local e global
    
'Ambiente de Referência'
  -> Definição: conjunto de associações de identificadores  disponíveis para referenciamento: OD e subprogramas visíveis ao subprograma 
  (ou programa) corrente, disponível para uso durante a sua execução. 
  -> O ambiente de referência de um subprograma é em geral invariante. 
  -> Os valores nos OD podem mudar, mas a associação de nomes com os OD e subprogramas permanencem constantes. 
  -> O ambiente de referência pode ter os seguintes componentes:
	1. Ambiente local: contexto criado pelo registro de ativação do subpgm.
	2. Ambiente não-local: associações usadas dentro do subpgm mas não criadas durante a sua ativação.
	3. Ambiente Global: contido no ambiente de referência não-local mas criado pela ativação do programa principal.
	4. Ambiente Predefinido: conjunto de associações de identificadores providos pela LP. Qualquer programa ou subpgm pode usa-los. 
	
'Visibilidade'
  -> Uma associação é visível dentro de um subpgm se faz parte do seu ambiente de referência. 
  -> Uma associação existente está escondida se ela não faz parte do ambiente de referência do subprograma corrente. 
  -> Se o subprograma redefine um identificador em uso em outra parte, a associação atual fica visível e as anteriores são escondidas. 
  
'Escopo Dinâmico'
  -> Cada associação tem um escopo dinâmico.
  -> O escopo da associação é a parte da execução do pgm durante a qual ela existe como parte de um ambiente de referência.  
  -> Portanto é o conjunto de ativações de subpgm  no qual ela é visível. 
  
'Nomes e Ambiente de Referência'
  -> Operação de referenciamento
    -> Assinatura
      - op_ref: identificador x amb._referência -> OD ou definição de subpgm.
      - Dado um id e um ambiente de referência, encontra a associação adequada para o id no ambiente. Retorna o OD/definição subpgm associado.
    -> Referências local, não local e global
      - Local: op_ ref acha a associação no ambiente local.
      - Não-local: op_ref acha a associação no ambiente não-local.
      - Global: idem, no global. 
      - Global e  não-local às vezes são usados indistintamente.
      
#30
  -> Ambiente de referência Sub2
     Local: C e D.
     Não local: A e Sub2 em Sub1, B e Sub1 em main.
  -> Ambiente de referência Sub1
     Local: A, D e Sub2.
     Não local: B, C e Sub1 em main.
  -> Ambiente de referência main
     Local: A, B, C e Sub1.
  -> Ambiente predefinido: write,read, sqrt, MAXINT, etc.
A, D e C são declarados duas vezes mas uma associação é visível por vez.

'ALIAS PARA OD'
  -> Nomes (dois ou +) pelos quais um OD pode ser referenciado no mesmo ambiente de referência. Exemplos:
    1.  Passagem de parâmetro por referência: nome do parâmetro formal é visível no subpgm ativado embora o nome atual também o seja. 
    2.  Há mais de um caminho, via ponteiro, para o mesmo OD, no mesmo escopo. 
    Alias cria dificuldades para o programador (entender o pgm) e para o implementador da LP (otimizar o código):
					  x:= a+b; y:= c+d; /*x,c alias*/
    Enfoque atual: limitar alias.
    Múltiplos nomes, mas apenas um visível por ambiente, não traz problemas.
    
'Escopo Estático e Dinâmico'
  1) Escopo estático é aquela parte do texto do programa onde o uso de um identificador é uma referência a uma particular declaração 
  do identificador. 
  2) O escopo dinâmico de uma associação é o conjunto de ativações de subprogramas  no qual ela é visível durante a execução. 
  
  Regras de escopo estático relacionam referências com declarações de nomes no texto do programa.
  
  Regras de escopo dinâmico relacionam referências com associações a nomes, durante a execução do programa. Definem o escopo dinâmico de
  cada associação em termos do curso dinâmico de execução do programa.
  
  Essas duas regras de escopo precisam ser consistentes. 
  
  Lisp, Snobol4 e APL são interpretados e não usam regras de escopo estático.
  
'Estrutura em Bloco'
  -> Definição
	1) Em uma LP estruturada em bloco, cada programa ou subprograma é organizado como um conjunto de blocos aninhados. 
	2) A principal característica de um bloco é que ele introduz um novo ambiente de referência local. 
	3) Um bloco é composto de declarações seguidas por comandos.
  -> Um bloco nomeado é um subprograma.
     procedure P(A:real); <declarações>; <comandos>;
     
'Declarações'
  -> As declarações definem um ambiente de referência local para o bloco:
    - Parâmetros formais
    - Constantes 
    - Variáveis
    - Subprogramas
    Esse ambiente é invariante durante a execução do subprograma.
  -> Declarações constituem a cabeça (head) do bloco enquanto comandos formam o seu corpo.
  
'Exemplos de LP com Blocos'
  Algol: blocos aninhados, com ou sem nome.
  Pascal: blocos aninhados nomeados.
  PL/I: blocos aninhados.
  ADA: blocos aninhados.
  C: cada subprograma é um único bloco que pode conter blocos não nomeados aninhados. Tem facilidades para tratar nomes não-locais.
  
'Aninhamento'
  -> Um programa forma um bloco principal
    - Cada subprograma é um bloco.
    - Um subprograma pode declarar outros subprogramas.
    - Subprogramas são blocos com nomes. 
    - Pode haver bloco sem nome (LISP, Algol, etc).
    - Há blocos nomeados que não são subprogramas (LISP).
  Blocos podem declarar qualquer objeto. 
  
'Regras de Escopo Estática'
  -> Referência Local
    - Qualquer referência a um identificador, no corpo de um bloco, se o identificador existir no bloco, é uma referência local. 
  -> Referência não local
	1) Se o identificador não é declarado no bloco. 
	2) A busca pelo identificador vai do presente bloco interno até o bloco mais externo. 
	3) Não encontrando, busca-se entre os termos pré-definidos pela LP.
	4) Não encontrando, considera-se um erro. 
  -> Declarações em sub-blocos aninhados. 
      Ficam escondidas, encapsuladas, dos blocos mais externos . 
  -> Nome de bloco (usualmente um subprograma)
      Faz parte do ambiente do bloco que o declara. 
  -> Parâmetros formais
      Fazem parte do ambiente de referência local do subprograma que os declara.
      
'Dados e Ambiente de Referência Locais'
  -> Essa seção aborda referência local. As seguintes abordam ambiente não local, parâmetros e transmissão de parâmetros.
    - Ambiente local de um subprograma Q
    - Nomes dos seus parâmetros formais.
    - Nomes de suas variáveis declaradas.
    - Nomes dos subprogramas aninhados.
    - O identificador Q não é parte desse ambiente.
 
'Regra'
  -> Regra de escopo estática
    Referência a X no corpo de Q está relacionado a declaração de X em Q. 
  -> Regra de escopo dinâmica
    Referência a X, durante a execução de Q, refere-se a associação de X na corrente ativação de Q.  
  -> São facilmente mantidas consistentes. 
  
'Implementação'
  -> Regra de escopo estática
    O compilador mantém uma tabela dos identificadores locais, enquanto compila o corpo de Q.  Quando uma referência é feita a um 
    identificador, ele olha nessa tabela primeiro.
  -> Regra de escopo dinâmica
      A implementação em ambiente de referência local tem 2 enfoques:
	a) retenção
	b) eliminação
      Cada um desse enfoque atribui diferentes semânticas para referências locais.  
      
      -> Retenção (Cobol e diversas versões de Fortran)
	1) As variáveis locais retidas preservam seus valores entre chamadas de um mesmo subprograma.
	2) Variáveis retidas são armazenadas no 'segmento de código'.
	3) O mesmo resultado pode ser obtido com variáveis não locais.
      -> Eliminação (C, Pascal, Ada, LISP, APL)
	1) Os OD, declarados localmente a Q, são criados a cada chamada de Q. 
	2) O ambiente local a Q é eliminado ao final da execução daquela chamada de Q. 
	3) As variáveis não retidas e parâmetros de Q são incluídas no 'segmento de dados da área de ativação' (registro de ativação) de Q. 

'Retenção ou Eliminação?'
'Implementação:'
  -> Tanto a abordagem de retenção, quanto a de eliminação são facilmente implementadas no modelo  de “área de ativação”. Contudo, alguns
  pontos merecem atenção: 
    
    Retenção e Eliminação: Pontos Importantes
    -> Subprograma sem recursão (Fortran e Cobol)
      - Retenção e eliminação: mesma implementação pois somente existirá um registro de ativação, o qual pode ser alocado estaticamente.
	Inicialização de OD pode resultar em duas implementações diferentes:
	  a) inicializa a cada chamada (atribuição no código do subprograma)
	  b) inicializa só na 1a. chamada quando cria o segmento de código do subprograma
  
    -> Ambos retenção (em segmento de código) e eliminação (via registro de ativação)
      - PL/1 e C
	- variáveis estáticas  retidas
	- variáveis automáticas (default)  eliminadas
      - ALGOL 60
	- variáveis OWN  retidas
	Algumas implementações de COBOL e Fortran apresentam enfoque de retenção.
	
    -> Nomes de subprogramas são sempre retidos.
      - A associação do nome de um subprograma declarado no ambiente local e sua definição pode ser representada por um ponteiro para a 
      área do segmento de código representando o subprograma.
 
    -> Parâmetros formais 
      - São inicializados a cada chamada, logo não podem ser retidos entre chamadas.
  
    -> Recursão 
      - Múltiplas ativações geram múltiplos registros de ativações armazenados simultâneos, no stack central. Exemplares da variável “x”
      podem existir em registros de ativações distintos, sendo o enfoque de eliminação desejável. Contudo pode ser útil haver variáveis
      retidas, acessíveis às várias ativações do mesmo subprograma, mantendo os valores entre as chamadas.

 @'Controle de Subprograma (parte 2)'
'Conteúdo'
  -> Dados compartilhados em subprogramas
    - Parâmetros e transmissão de parâmetros 
    - Ambiente comum explícito
    - Escopo dinâmico
    - Escopo estático e estrutura de blocos.
    
'Compartilhamento de Dados em Subprogramas'
  -> Dados podem ser compartilhados através de:
    a) transmissão de parâmetros ou
    b) acesso a dados em ambientes não locais,  segundo os enfoques de:
      - ambiente comum explícito e
      - ambiente não local implícito, baseado em:
	- escopo dinâmico,
	- escopo estático,
	- herança (cap. 8).
	
  -> O principal método para compartilhamento de dados entre subprogramas é a transmissão explícita de parâmetros e resultados.
  -> Com ambiente não local, o compartilhamento é obtido tornando alguns nomes visíveis aos subprogramas que os utilizam.
  -> Na transmissão de parâmetros e resultados, OD são transmitidos ou recebidos sem nomes associados.
  
'Transmissão de Parâmetros'
  -> Compartilhamento sem vinculação de nomes:
      x = mdc (x1,x2);
      y = mdc (12,15);
      x1 = sqrt(y);
      x2 = sqrt(100);
      
  -> Parâmetros Atuais e Formais
    - Argumento: nome do OD transmitido como parâmetro ou operando.
    - Resultado: refere-se ao OD retornado ao final de um subprograma. 
     - Os argumentos (ou resultados) de um subprograma podem ser obtidos (ou retornados) via: 
	- passagem de parâmetros,
	- referência não local, 
	- arquivo.

'Parâmetros Atuais e Formais'
  -> Parâmetro Formal
    - É um tipo particular de OD local ao subprograma
    - É nomeado e declarado como parte da especificação do subprograma. 
    - Exemplo:
	  void Sub (int x; char y); 
    Nomeia os objetos x e y e declara seus tipos.
  -> Parâmetro Atual
    - É o OD compartilhado pelo chamador do subprograma. Pode ser:
      - OD local ao chamador, parâmetro formal do chamador, 
      - OD não local mas visível ao chamador, resultado de expressão diretamente transmitida.
  
'Estabelecendo Correspondência'
  -> Correspondência Posicional:
    - Parâmetros formais e atuais são relacionados com base na posição relativa nas suas listas respectivas, considerando a mesma ordem em que 
    aparecem e seus tipos.
  -> Correspondência Explicitada por Nome:
    - Em algumas LP, a correspondência pode ser estabelecida pelos nomes dos parâmetros, independente da ordem, mas para tipos idênticos. 
    Exemplo (Ada):  				Sub (Y => B, X => 27);
    
  ->Coincidência da Quantidade de Parâmetros
    - Algumas linguagens não exigem que a quantidade de parâmetros coincida (LISP, HASKEL, GOFER e HUGS):
	

'Métodos para Transmissão de Parâmetros'
  -> Call by Name (Algol)
    - A expressão formando o parâmetro atual é substituída em cada parte onde o parâmetro formal aparece, SEM nenhuma avaliação, antes da 
      execução do subprograma. Requer indicar o ambiente de referência a ser usada para avaliar essa expressão.
    - O argumento é avaliado em cada ponto onde é referenciado.
    - Implementação: referência a um parâmetro formal é vista como chamada a um subprograma sem parâmetro, que resulta na avaliação do 
    parâmetro atual (no ambiente de referência do chamador) e o retorno do valor como um resultado passado para o subprograma em questão.
    - Implementação é cara, por isso esse método não é popular.
    
  -> Call by Reference (é método mais comum)
    - O parâmetro formal é um PONTEIRO (l-value) para o OD associado ao parâmetro atual. Desta forma é criado um alias para o OD atual.
    - O parâmetro atual é avaliado, gerando um endereço (l-value) do OD associado (isto é aquele que está sendo passado como parâmetro). O 
    OD não muda de lugar.
    - Durante a execução do subprograma chamado, a cada mudança no parâmetro formal, altera o OD passado como parâmetro real (atual) no ambiente
    do chamador. 
    
  -> Call by Value (C, java, C++)
    - Semelhante a passagem por referência, exceto que ao invés do l-value do OD associado ao parâmetro atual, passa-se o r-value.
    - Os parâmetros formais são iniciados com valores dos r-values dos parâmetros atuais. 
    - Alterações em parâmetros formais não afetam os parâmetros atuais. Elas são perdidas com o término do subprograma.
    - Parâmetros formais são variáveis locais ao subprograma chamado, do mesmo tipo dos parâmetros atuais.
    - Call by value é chamado by copy na linguagem Ada 95. 
    
  -> Call by Value-Result (Algol W)
    - O parâmetro formal é implementado como uma variável local do mesmo tipo do parâmetro atual correspondente.
    - O valor do parâmetro atual é utilizado para iniciar o r-value do parâmetro formal correspondente. 
    - Durante a execução do subprograma, alterações em parâmetros formais não afetam os parâmetros atuais.
    - Ao término do subprograma, os r-values dos parâmetros formais são copiados para os parâmetros atuais.
    - O parâmetro atual mantém seu valor até o término do subprograma chamado.
    - Call by value-result foi proposto por Nicklaus Wirth no projeto da linguagem Algol-W.
    
  -> Call by Constant Value
    - O valor do parâmetro formal, passado como constante, não pode ser alterado durante a execução do subprograma.
    - Esse parâmetro não pode ser passado (como parâmetro atual) para outro subprograma, exceto se por call by constant value. 
    - Durante a execução do subprograma, os parâmetros formais podem ser vistos como constantes locais.
    - Implementação: como “por valor” ou “por referência”.
    - Call by value e call by constant value impedem alterações nos valores dos parâmetros atuais, tornando-os argumentos de entrada 
    para o procedimento chamado.
    
  -> Call by Result
    - O parâmetro formal transmitido by result é utilizado apenas para retornar um resultado para o procedimento chamador.
    - O valor inicial do parâmetro atual não pode ser utilizado no procedimento chamado. 
    - O parâmetro formal é uma variável local sem inicialização ou com a inicialização própria para as variáveis locais implementada pelo 
    projetista da LP.
    - Quando o procedimento chamado termina, o valor do parâmetro formal é copiado para o parâmetro atual associado.
    
  -> Implementações utilizadas em algumas LP
    - A maioria implementa um ou dois dos métodos vistos.
      - Fortran: passagem por referência. 
      - Pascal: passagem por referência (usando o sufixo var) e por valor (default).
      - C: passagem por valor. O uso de ponteiro permite ao programador utilizar passagem por referência:
      - Algol-W: passagem por valor-resultado.
    
  -> Semântica da Transmissão
    - O programador deve saber quais os métodos para transmissão de parâmetros implementados na LP para depois decidir qual deles vai usar.
    - Ada adota uma abordagem diferente: informa o significado pretendido ao invés do método de transmissão implementado.
	      Exemplo: procedure sub (X: in integer, Y: out float, Z: in out float);
    - TD elementares são passados por “valor constante” (in) ou por “valor-resultado” (parâmetro do tipo out ou in out).
    - TD estruturados (arrays e registros) são passados por “referência”.
  
'Métodos para Transmissão de Parâmetros'
'Passagem de Subprograma como Parâmetro'
  -> O uso do nome de um subprograma como parâmetro atual na chamada de um subprograma traz dificuldades:
    a) Como checar os tipos para os parâmetros do SUBPGM, durante a tradução, já que o seu nome só será conhecido quando for passado como um
    parâmetro atual?
    Solução:
      A assinatura do SUBPGM precisa ser especificada como parâmetro formal.
      Os tipos de parâmetros desse SUBPGM também precisam ser especificados.
      Ex.: procedure Q (x:integer; function R(y,x: integer): integer);
      
  -> O uso do nome de um subprograma como parâmetro atual na chamada de um subprograma traz dificuldades:
    b) Que ambiente usar para resolver referências não locais?
    Se há referências a variáveis não locais no SUBPGM passado como parâmetro, qual o ambiente de referência não local a usar? E se o 
    SUBPGM chamador possuir identificadores com o mesmo nome que as referências não locais?
    - REGRA: a referência não local significa o mesmo, durante a execução do SUBPGM passado como parâmetro, que se ele fosse chamado no
    ponto em que aparece como um parâmetro atual na lista de parâmetros. Passa-se de fato o par <cp,scp>, o que define o ambiente de 
    referência. 
    
'Rótulo de Comando Passado como Parâmetro'
  -> Passar um rótulo para ser usado em goto no subprograma chamado. Esse mecanismo introduz duas dificuldades:
    a) Para qual ativação do segmento de código que contêm o rótulo se deve transferir o controle?
      - O goto não pode simplesmente alterar o CIP pois várias ativações podem estar usando o mesmo segmento de código.
      - O rótulo deve ser passado com a indicação de qual registro de ativação usar.
      - É necessário passar o par (ip, ep) como parâmetro, onde: ip é o endereço de instrução (em um segmento de código) e ep é o 
      endereço do ambiente (segmento de dados) a que se refere.
    b) Como implementar o desvio para um parâmetro rótulo?
      - Não é suficiente apenas desviar o controle para (ip, ep) pois é necessário finalizar o subprograma em execução e tratar a 
      cadeia dinâmica de ativações de subprogramas.
      - A implementação usual é: 
	- finalizar a execução do subprograma ativo.
        - finalizar a execução de todos os seus chamadores até encontrar um que corresponda a ativação designada no goto (isto é se refira 
	ao ep do par (ip, ep)).
	- valores finais dos parâmetros passados como resultado ou valor-resultado dependem da implementação da LP.
      
'Ambiente Comum Explícito'
  -> Um bloco de dados construído para compartilhar OD é o método mais direto para compartilhar dados entre os subprogramas que o declaram.
  -> Os OD são visíveis dentro dos subprogramas e usados normalmente.
  -> São declarados de forma diversa em diferentes LP:
    - bloco COMMON em Fortran.
    - package em Ada.
    - variáveis etiquetadas com extern em C.
    - classes em C++ e Smalltalk (embora não seja esse o objetivo principal de se ter classes)
    
  -> Ambiente comum parece com um ambiente local mas não é parte de nenhum subprograma.
  -> Pode conter definições de váriaveis, constantes e tipos.
  -> Não contém definição de subprogramas e parâmetros:
	  package Tab-compartilhada is
	  Tam-tab: constant integer := 100;
	  type Tabela is array (1..Tam-tab) of real;
	  Tab1, Tab2: Tabela;
	  K: integer range 1..Tam-tab;
	  end;
  -> O package (Ada) é definido fora de qualquer subprograma que usa as variáveis nele definidas.
  
  -> Se P é um subprograma que usa Tab-compartilhada então P precisa declarar “with Tab-compartilhada” entre suas declarações:
	  procedure P is .... 
	  with Tab-compartilhada; 
	  ....
	  Tab-compartilhada.Tab1(Tab-compartilhada.K):= 
	  Tab-compartilhada.Tab2(Tab-compartilhada.K) + 10.5;
	  end;
  -> P pode usar os nomes no pacote como se fossem do seu ambiente local, mas as referências são qualificadas (nome do pacote é usado 
  como prefixo).
  
  -> P pode compartilhar diversos pacotes. Se não existem nomes locais em conflito, então pode-se dispensar a qualificação, declarando 
  após o “with” o comando use:
	  with Tab-compartilha; 
	  use Tab-compartilha; 
  -> Em geral qualquer número de subprogramas pode compartilhar o mesmo ambiente comum e um subprograma pode acessar qualquer número de
  ambientes comuns.
  
  -> Em Fortran e C cada subprograma que usar ambiente comum deve incluir declarações para as variáveis que serão compartilhadas.
  -> Em Ada o compilador recupera a declaração para o ambiente comum, após encontrar o comando with, a partir de biblioteca ou de outra 
  parte do texto do pgm.
  -> Em ambas, o compilador inclui as declarações em uma tabela de símbolos, como um conjunto adicional de nomes locais que podem ser 
  referenciados no subpgm. Isto permite CHECAGEM ESTÁTICA de tipos.
  
'Em tempo de execução:'
  -> O ambiente comum é representado como um bloco contendo os OD declarados na sua definição.
  -> O bloco é tratado como um registro (base+offset).
  -> O nome do bloco é o nome do registro e os seus componentes são as variáveis declaradas.
  -> O bloco é alocado estaticamente no início da execução do programa e permanece até o final do mesmo.
  -> O subprograma que referencia um OD no bloco deve conhecer o endereço de base do bloco. 
  -> Uma implementação simples é colocar um ponteiro no segmento de código do subprograma P, apontando para cada um dos blocos comuns
  que utiliza.
  -> São utilizados ponteiros similares para indicar o endereço de base dos subprogramas chamados em P.
  -> A inicialização desses ponteiros é tarefa do carregador de ligação em tempo de carga (link editor).
  -> O acesso a cada variável de um bloco comum é dado por base (r-value do ponteiro) + deslocamento.
  
'Variáveis Compartilhadas Explicitamen'
  -> Provê um meio de tornar um OD, no ambiente local de um subprograma, visível para outros subprogramas.
  -> Cada variável a ser compartilhada possui um proprietário (o subprograma que a declara como sendo visível por outros).
  -> O proprietário pode compartilha-la com outros, exportando-a via uma declaração explícita como “define” em Ada ou declarando-a fora 
  de qualquer função em C e C++
  -> O subprograma que deseja importar uma variável exportada precisa explicitar essa intenção via um declaração “uses” em Ada ou “extern”
  em C ou C++.
  
  -> Exportador (em Ada)
      procedure P (...);
      defines X,Y,Z; 	- X, Y e Z são disponíveis para exportação.
      X,Y,Z: real;	- Declaração usual para X, Y e Z.
      U,V: integer;	- Declaração de outras variáveis.
      begin ... end;	- Comandos.
  -> Importador
      procedure Q (...);
      uses P.X,P.Z;	- uses <nome-pgm>.<nome-variável-externa>
      Y: integer;	- Y é local, apenas X e Z são importadas.
      begin ... end;	- Comandos podem incluir referência a X e Z
      
'Implementação'
  -> O efeito é similar ao uso de variável em um ambiente comum.
  -> A variável é implementada como retida.
  -> Variáveis exportadas são armazenadas no segmento de código de seu proprietário.
  -> O importador usa o endereço de base do proprietário e o deslocamento apropriado para poder ter acesso a variável compartilhada.
  
'Ambiente não Local Implícito'
'Escopo Dinâmico'
  -> Alternativa a transmissão de parâmetros e ao uso de ambiente comum explícito para compartilhar dados é associação de ambiente não 
  local a cada SUBPGM em execução.
  -> O ambiente não local associado a P é o conjunto de todos os outros ambientes locais de subprogramas que P enxerga, durante sua execução.
  -> Quando uma variável X é referenciada em P e X não tem associação local então o ambiente não local é utilizado para determinar a 
  associação para X.
  Qual deve ser o ambiente não local a P?
  
  -> Em LP estruturadas em blocos as regras de escopo estático determinam o ambiente não local explícito a cada subprograma (a ser visto 
  no fim dessa Seção).
  -> Uma alternativa mais simples (mas pouco usada) é utilizar os ambientes locais da atual cadeia dinâmica de ativação de subprogramas, 
  mesmo que eles não tenham definição aninhada (LISP, APL e Snobol).
  -> Essa idéia usa a regra da associação-mais-recente.
  
'Regra da Associação-mais-recente:'  
  -> Aplicada quando a LP não é estruturada em blocos e:
    - os subprogramas são definidos em separado um dos outros.
    - os ambientes locais são eliminados ao término do subpgm.
    - não existe estrutura de programa estática na qual basear regras de escopo para referenciar identificadores não locais.
    - a LP utiliza checagem de tipos dinâmica.
  -> Se P referencia X e não existe uma associação para X em P, então é utilizada a mais recente associação criada para X, na cadeia 
  dinâmica de ativações.
  -> Ambiente não local da ativação P de um subprograma consiste da cadeia dinâmica das ativações de seus subpgm chamadores.
  
  -> Se a regra da associação-mais-recente for aplicada:
    - a regra de escopo estático NÃO se aplica pois em tempo de tradução não é feita verificação de tipo nem associação de referências 
    com declaração de variáveis.
    - o ambiente não local pode variar entre ativações de P, para atender a lógica de chamada dos subprogramas.
    - é necessário armazenar uma tabela de símbolos locais (isto é, identificadores) em cada registro de ativação.
    - a referência não local não faz uso de base mais deslocamento pois em cada registro de ativação tanto a base como o deslocamento 
    podem variar para um mesmo identificador.
    
'Implementação'      
  -> a) Pilha Central (implementação direta)
      - A pilha central é utilizada para armazenar os registros de ativações (RAt) dos subprogramas. O ambiente local de cada um desses
      subprogramas é parte do seu RAt.
      - A implementação é cara pois requer pesquisar o identificador nos RAt, começando com o ambiente local do ativo e seguindo a cadeia
      ativa em ordem reversa.
      - O próprio identificador é armazenado e não pode ser utilizado o esquema de base-deslocamento porque a posição de um identificador
      pode variar em cada RAt onde comparecer.
  -> b) Tabela Central (evita busca para referência não local)
      - É comum a todos os subprogramas, sendo chamada Tabela de Ambiente de Referenciamento Central:
	- contém todas as associações ativas de identificadores do programa, independente do fato de serem ou não locais, durante toda 
	a execução.
	- possui 3 campos: identificador, flag (indica a existência ou não de associação ativa para o identificador) e valor (ponteiro 
	para o OD ligado).
      - Se o conjunto de identificadores que pode ser referenciado em cada um dos subprogramas é determinado durante a tradução, a tabela
      conterá UMA única entrada para cada identificador.
  -> As referências não locais são direcionadas para a tabela central, usando o método de base mais deslocamento, evitando uma pesquisa 
  pelo identificador referido, se o flag estiver ativo.
  -> Na ativação de um subprograma, todos os identificadores ativos (da tabela central) que aparecem no seu ambiente local são salvos em 
  uma pilha escondida e restaurados quando o subprograma termina.
  -> Esse método é eficiente se a freqüência de uso de variáveis não locais justifica o maior custo de ativação e término dos subprogramas,
  devido a manutenção da tabela central.
  
'Escopo Estático e Estrutura de Blocos'
  -> Em LP estruturadas em bloco (Pascal, Ada e Algol), compartilhar dados via referências não locais é mais complexo e não se pode
  usar regra de escopo dinâmico.
  -> O ambiente não local é determinado pelas regras de escopo estático (associando declarações e referências).
  -> A cadeia estática é determinada em tempo de tradução e assim uma referência é resolvida no ambiente local ou no bloco (subprograma)
  mais próximo que envolve o bloco onde a referência ocorreu.
  -> As referências não locais, em tempo de execução, são determinadas pelas regras de escopo estático usadas durante a tradução do fonte.
  -> O significado de uma determinada referência não local a um identificador não depende de uma particular cadeia dinâmica e ativação
  de blocos, como no caso da regra da associação-mais-recente.
  -> Referência a um identificador em um subprograma é associada com a sua declaração no fonte, mesmo se o identificador for não local
  ao subprograma em questão.
  
  -> Como o ambiente não local é determinado pelas regras de escopo estático, x (em R) é inteiro e não real ou lógico.
  -> Assim x em R está associado a x no programa principal e independe de como R foi ativado (se através de P ou diretamente via Q).
  
'Implementação'
  -> a) Regras de Escopo Estático
    - Na compilação do subprograma R, uma tabela de declarações locais (TLR) é criada e encadeada em uma lista de tabelas que representa
    os ambientes locais do programa principal e de todos os subprogramas dentro dos quais R está aninhado.
			TLmain <= TLR 
    - Na compilação, o identificador é buscado na TLR. Se não for encontrado, é pesquisado na TL anterior e assim por diante.
			x (em R) é associado ao x declarado no programa principal
    - Quando a compilação de R termina, o compilador elimina TLR da lista de tabelas locais. 
			TLmain
  -> b) Pilha Central e Consistência entre os Escopos
    - Dentro de R a associação para x deve ser com x no programa principal (de acordo com a regra de escopo estático) e não com o x 
    declarado em Q (de acordo com a regra de escopo dinâmico).
    - Como representar o escopo estático com pilha central?
    
    CEP - Current Environment Pointer, DCP - Dynamic Chain Pointer
  -> c) Cadeia Estática
    - O ambiente de referência não local é determinado pela cadeia estática, construída durante a tradução.
    - Requer ponteiro para a TL do bloco que precede (no programa principal) e que envolve o bloco em execução.
    - O ponteiro de cadeia estática (SCP) aponta o endereço de base do RAt do envolvente.
    
    SCP - Static Chain Pointer
'Implementação'
  -> Quando o compilador cria entradas na TL para uma declaração local, controla os subpgm que estão estaticamente aninhados. 
  -> Na referência a x, por exemplo, o compilador conta o número de ambientes envolvendo o subpgm em questão, para encontrar a associação
  correta e gera o código apropriado para seguir a cadeia estática até o RAt que contém o OD x adequado.
  -> No segmento de código, uma referência a x é da forma <número de passos atrás na cadeia estática, deslocamento no RAt que contém x>.
  Assim, os identificadores não precisam ser armazenados quer no RAt, quer no segmento de código.
  -> n acessos são necessários para acessar uma variável declarada no nível k e referenciada no nível k+n.
  
  -> d)Vetor Mostrador (Pilha Central e Display). 
    - Melhora implementação de cadeia estática por permitir acesso a OD não local com UMA referência a um ponteiro da cadeia estática,
    evitando percorrê-la. Para subprograma em execução, o comprimento da cadeia estática é constante (e igual a profundidade do
    aninhamento). Uma referência não local será satisfeita no mesmo ponto na cadeia, determinado em tempo de tradução.
    - Identificador é representado como (posição atrás, deslocamento) onde posição (num. de passos atrás) é um ponteiro na cadeia
    estática para o RAt onde o identificador é definido. Na entrada de um subprograma a cadeia estática é copiada no vetor display 
    (armazenado fora da pilha central, em memória rápida). Se a referência é da forma x=(2,10), o endereço é l-value= display[2]+10 
    (deslocamento 10 no segundo RAt atrás, na cadeia estática) ou seja base + deslocamento.
    
'Declarações em Blocos Locais'
  -> Algol e C permitem declarações de variáveis em blocos de comandos aninhados em procedimentos. 
    real proc1(...)
      { int i, j;
	  ...
	  { int k, l;
	    ...
	  }
	  { int m, n;
	    ...
	    {int x; ...}
	    {int y; ...}
	  }
      }   
  -> A e B são não simultâneos. C e D também são não simultâneos.
  -> Devido a não simultaneidade, essas declarações são implementadas via uma estrutura tipo registro de comprimento variável (variante):






  








      
      

  
  








  





 

