###################################################################################################################################################
PROVA 2

'Questões em Tradução de Linguagens'
'sintaxe' é o conjunto de regras que determinam quando uma sentença é bem formada. Sequência de símbolos que tornam um programa válido.
'semântica' é o significado de suas expressões, instruções e unidades de programa.

– sentença: string de caracteres sobre um alfabeto.
– linguagem: conjunto de sentenças.
– lexema: unidade de menor nível sintático de uma linguagem (p.ex.: *, for, begin).
– token: categoria de lexemas (p.ex.: identificador).
– símbolos (tokens) são combinados em sentenças para formar um programa.

'Regras sintáticas são suficientes'
ANOS60: para projetar LP 'só era necessário' uma sintaxe formal, tipo BNF (Backus-Naur Form).
<inteiro> ::= <sinal><digito>|<inteiro><digito>
Em expressões ambíguas, gerava problema: 1-2-3 = -4 ou 2 ?
'Declarações, seqüência de controle, operações, ambiente de referência, etc, são necessários.'

'Sintaxe de LP'
- prover notação para comunicação entre o programador e o processador da linguagem. 
– 'legibilidade': ler e entender facilmente,
– 'capacidade de escrita': facilitar a programação,
– 'facilidade de verificação': facilitar o exame da exatidão do código,
– 'facilidade de tradução': facilitar trabalho do tradutor,
– 'ausência de ambigüidade'.

'Legibilidade'
- cmd estruturados palavras chaves, declarar dados, op. mnemônicos, variedade de construções sintáticas
'Exemplo': Cobol (auto-documentado)
'Contra-exemplo': programas Lisp ou Mumps

'Facilidade de escrever'
'Exemplo': Fortran, C, C++
'Contra-exemplo': Pascal, Cobol

'Facilidade de Verificação'
- envolve aspectos sintáticos e semânticos, que devem facilitar o exame.
'Exemplo': linguagens declarativas puras.
'Contra-exemplo': linguagens imperativas.

'Facilidade de tradução'
- regularidade das estruturas sintáticas, pequena variedade de estruturas.
'Exemplos': Lisp, Haskell, Hugs, ML.
'Contra-exemplos': Cobol.

'Ausência de ambigüidade'
- idealmente, cada construção sintática deve ter uma única interpretação.
- a ambigüidade aparece quando são consideradas combinações entre as diversas estruturas sintáticas permitidas pelas regras da LP.

Comentários
- é tratado ao nível do analisador léxico.

Espaço em branco (tem papel sintático)
- usado como separador, exceto se em uma string.

Delimitador e agrupamento (colchetes)
- marca inicio ou fim de unidade de unidade sintática.
- removem ambiguidades.

'Campos de formato fixos ou livres'
- Sintaxe de campo fixo (estritamente)		//Assembler, JCL, etc.
- Sintaxe de campo fixo (parcialmente)		//Fortran, Cobol
- Sintaxe de campo livre			//Algol, Pascal, C, etc.

'Expressões'
- acessam os objetos de dados e retornam algum valor 

'Comando'
- principal elemento sintático das linguagens imperativas.
- as linguagens funcionais puras não possuem comandos.

'Estrutura do Programa em Subprogramas'
- Definição de subprogramas separados (Fortran)
- Definição de dados separados (Java)
- Definição de subprogramas aninhados (Pascal)
- Definição separada de interfaces (C)
- Definição de subprogramas sem programa
- Principal (Lisp, linguagens declarativas)

'Definição de subprogramas separados (Fortran)'
- compilada em separado e ligada ao programa em tempo de carga.

'Definição de dados separados (Java)'
- operações que manipulam um objeto.

'Definição de subprogramas aninhados (Pascal)'
- subprogramas são declarados dentro do programa que os utiliza.

'Definição separada de interfaces (C)'
- implementação (.c) ou interface (.h)

'Definição de subprogramas sem programa'
- em tempo de carga (load), funções e variáveis ficam definidas.

'Estágios de Tradução'
'Divisão Lógica'
- análise do fonte e síntese do executável.
'Número de passos'
- classifica os tradutores.
- leitura do fonte e dos demais arquivos gerados.

'Análise do Fonte'
'Análise léxica (scanner)'
- segmenta identificadores, delimitadores, operadores, números, palavras chaves, palavras opcionais, comentários, ...
- identifica os itens léxicos (tokens) e os repassa.
- identifica o tipo de cada token e lhe anexa um rótulo de tipo.
- inclui identificadores na TABELA DE SÍMBOLOS e substitui referências ao identificador pelo endereço dado pelo semântico.
- modelado como um autômato de estados finitos.

'Análise sintática (parsing)'
- identifica as unidades sintáticas do programa: (comandos, declarações, expressões, etc) usando os itens léxicos.
- chama o analisador semântico para processar a unidade sintática.
- colocados numa pilha, recuperados e analisados pelo analisador semântico.

'Análise semântica'
- processa a unidade sintática e começa a gerar a estrutura do código objeto.
- ponte entre fase de análise e síntese.
- código objeto passa por um estágio de otimização do tradutor antes de ser gerado o código objeto final.
- um analisador para cada unidade sintática diferente.
- analisadores interagem via informações armazenadas na estrutura de dados TS.

'Síntese do Programa objeto'
- Gera o código executável a partir da saída do analisador semântico.
- Pode incluir otimização do código, com base em algoritmos bem conhecidos.
- Pode incluir otimização do código, com base em algoritmos bem conhecidos.
- Muitos compiladores usam recursos sofisticados para otimizar:
    - cálculos de valores comuns
    - eliminação de atribuições constantes em loops
    - cálculo de subscritos
    - variáveis temporárias, etc.
    
'O código de saída pode ser':
- diretamente executado ou
- montado ou
- ligado e carregado (requer código relocável!)

'Modelos Formais para Tradução'
'Gramática'
- Consiste num conjunto de regras (produções) que definem itens léxicos e combinações desses para formar sentenças válidas em uma linguagem.
  - gramática formal: usa uma notação formal, isto é, restrita e específica.
- gramáticas úteis na teoria de compilação:
  – 'BNF (gramática livre de contexto)',
  – 'Gramática regular'.
  
'Gramática Backus-Naur Form (BNF)'
- É uma metalinguagem ou seja uma linguagem usada para descrever outras linguagens.
- Gramática BNF é a definição formal da sintaxe de uma LP usando a notação BNF: terminais,  ́::= ́,  ́< ́,  ́> ́ ou  ́| ́.
'::='			 é definido como
'<ca>' 			 ca é uma categoria sintática, símbolo não terminal, definido em termos de outras entidades).
'terminais' 		 são palavras primitivas (itens léxicos) da LP.
'|' 			 ou

'EBNF'	//extendida
'[...]'			 indica elementos opcionais.
'[ | ]'			 indica alternativas de escolha.
'{...}*'		 indica seqüência arbitrária de instâncias (zero ou mais repetições) de elementos sintáticos.
'<identificador>'	::= <letra>{<letra>|<dígito>} *
'<inteiro>' 		::= [+|-]<dígito>{<dígito>} *
'<inteiro>'		::= [+|-]{<dígito>} +

'Diagrama de trilhas'

'Regra de produção' 
- substituir ::= por -> e em vez de representar não-terminais por <>, representar por letra maiúscula.
<X> ::= <B> | <C>		//equivalentes
X -> B | C

'Regra de substituição'
- regra para gerar strings válidas.
#- substitua qualquer não terminal pela expressão no lado direito de uma regra de produção que o contenha no lado esquerdo.

S -> SS | (S) | ()	//todos entre parentenses, todo '|' vira '=>' e não pode ter (()), isso vira  (()()).
S => (S) => (SS) => (()S) => (()())

'Árvore de análise (parse)'
- Após a análise puramente sintática da BNF, sem errors (programa válido), é gerada a árvore de parse.

'Limitações sintáticas'
- A estrutura da BNF é simples e muito poderosa mas não consegue expressar regras sintáticas com dependência contextual.
- BNF é uma gramática livre de contexto, isto é, o lado esquerdo de uma regra só pode conter um símbolo.

'Modelos Formais para Tradução'
'Autômato de estados finitos'
- reconhece os tokens criados após a análise léxica.
#- FSA = (E, ei , Ef , Ae , AO )
E = conjunto finito de estados (nós no grafo),
ei = estado inicial (um nó no grafo),
Ef = conjunto de estados finais, E f C E,
Ae = alfabeto de entrada (rótulos para os arcos),
AO = conjunto de arcos orientados ligando elementos de E.
- Cada nó pode ter zero ou mais arcos de saída, incluindo múltiplos arcos com o mesmo rótulo. Cada nó pode ter zero ou mais arcos de chegada.

'Autômato de Estados Finitos'
'Determinístico': FSA sem repetição de arcos de saídas com o mesmo rótulo em um mesmo nó.
'Não determinístico': FSA com repetição de arcos de saída com 1 o mesmo rótulo em um mesmo nó.
#Uma string é aceita pelo FSA não determinístico se existe algum caminho do nó inicial para o nó final, usando a string como entrada.

'Gramáticas regulares'
- regra: <não-terminal> ::= terminal <não-terminal> | terminal
- casos especiais de gramática BNF.
- O conjunto de linguagens aceitas por FSA é equivalente às linguagens geradas por gramáticas regulares.

Ex.: geração de binários pares.
<não-terminal> ::= terminal <não-terminal> | terminal
<B> ::= 0<B>| 1<B> | 0
B -> 0B| 1B | 0
- a regra de produção B -> 0B| 1B | 0 gera binários pares 0B e 1B geram um binário qualquer. A produção 0 multiplica-o por 2.

'Expressões regulares'
- Terceira forma de definição de linguagens (equivalente a FSA e a gramática regular).
- regra: <er> ::= terminal | <a> v <b> | <a><b> | (<a>) | {<a>}*
um símbolo terminal é uma expressão regular,
avb é a alternação das expressões regulares a ou b,
ab é a concatenação das expressões regulares a e b,
a*, fecho de Kleene, representa zero ou mais repetições de a (i.e. , a, aa, aaa, .... ).
- O asterisco também representa o estado terminal.

'Modelos Formais para Tradução'
'Autômatos pushdown (PDA)'
- Gerar strings em uma linguagem  = gramáticas BNF.
- Reconhecer strings na linguagem = autômato pushdown
- PDA é um FSA com uma pilha associada.
1. um símbolo de entrada é lido e o topo do stack também é lido;
2. os dois símbolos são comparados. O PDA entra em um novo estado e escreve zero ou mais símbolos na pilha;
3. a aceitação de uma string ocorre se a pilha ficar vazia (ou de forma equivalente, se o PDA atingir um estado final).
Para reconhecer a n b n , empilhe a. Para cada entrada b, desempilhe um a. A string é aceita se o término dos b ocorrer com pilha vazia.

'PDA não determinístico'
- PDA não determinístico é um autômato que possui mais de um estado com a mesma entrada.
- Uma string é aceita se existe uma seqüência possível de movimentos que aceita a string.
- PDA determinístico e não determinístico são DIFERENTES.



