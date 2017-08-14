0.3* PROVA DE LINGUAGENS(Hugs e Prolog) = 0.2 teórica + 0.1 prática(sábados)
0.4* PROVA TEÓRICA (2 provas)
0.1* EXERCÍCIOS
0.2* SEMINÁRIO (Python ou JAVA Me)	1.7.1 livro pag 40

//----------------------------------------------------------------------------------------------------------------------------------------------//
-- PROVA 1

linguagem funcional: LISP
linguagem imperativa: C, PASCAL, JAVA (do modelo Von Neumann)


1.1 Motivos para estudar conceitos de LP
1.2 Domínios de programação
1.3 Critérios de avaliação da linguagem
1.4 Influências sobre o projeto da linguagem
1.5 Categorias de linguagens
1.6 Compromissos no projeto da linguagem
1.7 Métodos de implementação
1.8 Ambientes de programação

1.1 Razões para Estudar LP
  1. Aumentar a capacidade para expressar conceitos 
	A LP impõe limites  às formas de algoritmos.Pode-se simular facilidades inexistentes.
  2. Melhorar a capacidade de escolher LP adequadas
	“Quando só se tem martelo, tudo parece prego”.As LP mais populares nem sempre são melhores  
  3. Facilitar aprender novas linguagens
	O domínio dos conceitos das LP facilita entender como eles são incorporados ao projeto de uma LP 
  4. Entender melhor a importância da implementação
	Melhora o uso da LP utilizada
	Ex.: acesso a matrizes, common em Fortran, uso de recursão, alocação de struct em C
  5. Aumentar a capacidade de projeto de novas LP
  
1.2 Domínios Típicos de Programação
  O domínio da aplicação força o projeto da LP no sentido de atender as suas especificidades
  
  1. Aplicações Científicas (início nos anos 40)
	Estruturas de dados simples: arranjos (arrays) e matrizes.
	Grande número de cálculos aritméticos. 
	Estruturas de controle: laços iterativos e seleções
	Ex.: Fortran (melhor) e Algol.
  2. Aplicações Comerciais (início nos anos 50)
	Facilidades para produzir relatórios elaborados
	Precisão ao descrever e armazenar números decimais e dados de caracteres.
	Capacidade de especificar aritmética decimal.
	Ex. COBOL, planilhas e banco de dados
  3. Inteligência Artificial
	Início: manipulação simbólica e não numérica. 
	(Computação simbólica significa que símbolos, que consistem em nomes no lugar de números, são manipulados)
	Estrutura de dados: listas encadeadas em vez de arrays.
	Capacidade de criar e executar código durante a execução é conveniente (runtime).
	Ex. linguagem funcional LISP, Prolog.
  4. Programação de Sistemas
	Software básico: SO e ferramentas de suporte à programação de um computador
	Eficiência de execução: rapidez. 
	Recursos de baixo nível para interface com dispositivos externos.
	Ex.: C, C++ e Assembly
  5. Linguagens de Scripting (início últimos 25 anos)
	Permitem a criação de um arquivo com uma lista de comandos a serem executados.
	Ex. csh (C shell), ksh (korn shell) e Perl
  6. Linguagens de Propósito Especiais
	Características e aplicabilidade muito específicas torna difícil compara-las com outras.
	Ex. RPG e EasyTreave (geradores de relatórios), GPSS (simulação de sistemas), SPSS e SAS (estatística), CSMP (simula sistemas contínuos).
	
1.3 Critérios de avaliação da linguagem
  1. Legibilidade
	O critério mais importante: facilita a manutenção (tópico mais relevante na computação)
	
	- Simplicidade global
		- Muitos componentes básicos: ruim
		- Multiplicidade de recursos (mais de uma maneira de realizar 1 operação particular): ruim
		- Sobrecarga: boa mas pode ser mal usada
		- Muita simplicidade (falta estrutura): ruim
	- Ortogonalidade (toda combinação possível de conceitos primitivos é legal e significativa)
	'Em linguagem de programação, ortogonalidade significa que um conjunto relativamente pequeno de construções primitivas podem ser '
	'combinadas em um número pequeno de maneiras para construir as estruturas de controle e de dados de uma linguagem.'
		- Significado é independente do contexto
		- Torna a LP fácil de aprender e de ler
		- Muita ortogonalidade: maior complexidade = problema
		- C não é ortogonal (registros podem ser retomados de funções, mas arrays não.)...
		- Linguagem mais ortogonal = ALGOL 68 (Toda construção de linguagem em ALGOL 68 tem um tipo, e não há nenhuma restrição para ele)
		- Alguns acreditam que as linguagens funcionais oferecem uma boa combinação de simplicidade e de ortogonalidade. 
	- Instruções de controle
		- Ex.: goto em Fortran e assign em PL/1: ruim
	- Tipos de dados e estruturas
		- Facilidades adequadas para defini-los: bom
		- Ex.: tipos booleanos, registros e listas (JAVA seria bom)
	- Aspectos da sintaxe
		- identificadores pequenos: ruim
		- palavras especiais (delimitadores): bom (ADA tem 'end if', 'end loop', várias palavras)
		- forma e semântica compatível: bom
  2. Capacidade de Escrita
	Medida da facilidade de se usar uma LP para criar programas em um certo domínio. É difícil comparar duas linguagens, já que cada uma
	é/foi projetada para tal domínio de aplicação.

	- Simplicidade e ortogonalidade
		- Poucos componentes básicos e regras consistentes para combiná-las: bom
		- Muita ortogonalidade: difícil depuração (ortogonalidade X capacidade de escrita)
	
	- Suporte para abstração
		Capacidade de definir/usar estruturas ou operações complicadas, abstraindo os detalhes, facilita a escrita de programas.
		- importante para a capacidade de escrita.
		  - abstração de processo: subprogramas (ex. usar subprograma para implementar um algoritmo de classificação exigido diversas 
							 vezes em um programa).
		  - abstração de dados: classes, registros, etc.
	
	- Expressividade
		Existência de formas convenientes de especificar computações facilita a escrita.
		Em APL, (permite que uma grande quantidade de computação seja realizada com um programa muito pequeno).
		Em C, count++ é melhor que count = count + 1.
	
	- Sintaxe (restrita pode reduzir a legibilidade)
		- delimitadores e operadores poderosos: bom
  3. Confiabilidade
	Programa é confiável caso se comporte de acordo com as especificações em todas as situações.

	- Verificação de tipos
		- Tempo de compilação (desejável) ou execução (não desejável)
		“Quando mais cedo se descobrir um erro, melhor”
		- Ada exige verificação dos tipos de quase todas as variáveis e expressões em tempo de compilação, exceto quando o usuário declara explicitamente 
		  que a verificação de tipos deve ser suspensa.
		- Programa chamado LINT (faz a verificação de problemas em programas C)
		- Em Pascal, a faixa de subscrito de uma variável array faz parte do tipo da variável e é testada na verificação de tipos, assim como Ada e Java. 
	
	- Tratamento de exceções
		Capacidade de interceptar erros na execução, pôr em prática medidas corretivas e prosseguir.
		- Ex.: on <condição> do <comando>
		- Ada, C++, Java.
	
	- Aliasing(union)
		- É ter dois ou mais métodos, ou nomes, distintos para fazer referência à mesma célula de memória.
		Ex.: Membros de união e ponteiros definidos para apontar para a mesma posição de memória: perigoso.
	
	- Legibilidade e capacidade de escrita
		Quanto mais fácil for escrever um programa, mais provável que ele seja correto, mais fácil entender e mais fácil mantê-lo.
  4. Custo
	Custo final de 1 LP é função de muitas de suas características.

	- Custo de treinamento de programadores para usar a linguagem
		- simplicidade e ortogonalidade da LP
		- experiência dos programadores
	
	- Custo para escrever programas na linguagem +
		- capacidade de escrita e adequação a aplicação particular 
		- esforço em linguagens de alto nível = desejo de diminuir custos para criar software.
	
	- Custo para compilar programas
		- nível de otimização do código: compromisso tamanho do código X velocidade de execução(-)
		- impecilho Ada primeira geração = custo de compilação. Problema diminuído pelo surgimento de compiladores melhores.
	
	- custo para executar programas
		- projeto da LP. Ex.: verificação de tipos.
		- a verificação constante de tipos proíbe a execução rápida de código.

	- Custo do sistema de implementação da linguagem
	- Custo da má confiabilidade em sistemas críticos +
	- Custo da manutenção dos programas + (2 a 4x o custo de desenvolvimento)
		- Custo de uma linguagem (desenvolvimento do programa, manutençao e confiabilidade).
		- tanto correções como modificações para adicionar novas capacidades.
		- legibilidade e capacidade de escrita.
  5. Outros
	
	- Portabilidade
		Facilidade com que programas podem ser mudados de uma implementação para outra
		- Grau de padronização da LP
	
	- Generalidade 
		Aplicação a uma ampla faixa de aplicações

	- Qualidade da Definição 
		- Qualidade do documento oficial(gramática) que define a LP
	
  => Existência de Conflitos em critérios 

	- Projetistas: elegância e generalidade
	- Implementadores: dificuldade de implementar as construções e os recursos da LP 
	- Programadores: capacidade de escrita e legibilidade
	
  => Qualidade e Fatores Externos 
  
	- COBOL e ADA
		Forçadas pelo Departamento de Defesa Americano
			
	- FORTRAN 
		Forte suporte dos fabricantes

	- Snobol
		Excelente descrição da LP
	
	- Pascal e LISP
		Uso acadêmico e prático
		
1.4 Influências sobre o projeto da linguagem
  1. Arquitetura do Computador
	Arquitetura de Von Neumann
	      - CPU
		*unidade lógica aritmética (ALU), unidade de controle (UC), registradores (propósito geral, apontadores e flags), contador 
		de programa (PC)
	      - Barramentos
		*dados, endereço, controle
	      - Periféricos de entrada/saída mapeados na memória
	      
	“Usamos linguagens imperativas porque usamos a arquitetura de Von Neumann”
	      - Dados e programas armazenados na memória 
	      - Ciclo busca-decodificação-busca de operandos-execução (fetch-execute cycle)
	      - Processamento é seqüencial (localidade de referência)
	      - Execução rápida porque são armazenadas em posições adjacentes da memória
			- Efeito do desvio incondicional (goto) ?
	      - Essa rapidez desencoraja o uso da recursão, o qual é básico em linguagens funcionais
	      - Gargalo: velocidade da CPU >> velocidade de transferência da memória para CPU >> velocidade de transferência de dados dos 
	      periféricos para a CPU (e impossível programação paralela)
	
	*Técnicas para redução do gargalo de von Neumann
	      - diferença de velocidade entre a CPU e memória de acesso direto:
		    - Memória cache
		    - Processadores com pipelining 

	      - diferença de velocidade entre a memória de acesso direto e os dispositivos de entrada/saída: 
		    - blocagem e bufferização  
		    - DMA (Acesso Direto à Memória)
		    - canais de controle de dispositivos de entrada/saída

  2. Metodologias de Programação
	Preocupação migrou de maximizar uso do hardware para maximizar a produtividade e manutenabilidade. 

	- Anos 50 e início dos anos 60 
		- Aplicações simples
		- Preocupação: eficiência do uso do hardware

	- Final dos anos 60 (programação estruturada)
		- Pessoas tornam-se importantes
		- Preocupação: legibilidade e melhores estruturas de controle
		- Projeto top-down e refinamento sucessivo

	- Final dos anos 70
		- Abstração de dados
		- Preocupação: mudança da orientação para processos para a orientação para dados

	- Meados dos anos 80 (Orientação a objetos: reuso)
		- Abstração de dados, encapsulamento e herança
		- Vinculação dinâmica de tipos.
		- Programação orientada ao processo é, em certo sentido, o oposto da programação orientada a dados.
		
1.5 Categorias de linguagens

      1. Imperativas
	- algoritmo é especificado com detalhes
	- a ordem de execução dos comandos é incluída
	- possui comando de atribuição

      2. Funcionais (ou aplicativas)
	- principal meio de fazer computações é aplicando funções a determinados parâmetros
	- não possui comando de atribuição
	- utiliza recursão extensamente
	- fluxo de execução é determinado pelas funções

      3. Lógicas
	- regras especificadas sem ordem particular 
	- implementação escolhe a ordem de execução
	- fluxo de execução é determinado pelas regras
	- Prolog

      4. Orientadas a Objetos
	- abstração de dados encapsula processamento com objetos de dados e oculta o acesso a eles
	- herança e vinculação de tipos em tempo de execução

1.6 Compromissos no projeto da linguagem

      1. Confiabilidade vs custo de execução
	- validação de subscritos
		- Ada (valída) = mais confiável
		- C (não valída) = mais rápido

      2. Capacidade de escrita vs legibilidade 
		- APL (boa capacidade de escrita, legibilidade ruim)
		  - muitos operadores para operações com arrays
		  - expressões longas e complexas

      3. Flexibilidade vs segurança
		- unions em C ou variant records em Pascal(permite que uma célula de memória contenha diferentes valores de tipos)
		  - impossibilita a verificação estática de tipos
		
1.7 Métodos de implementação

      1. Compilação
	- Tradução de instruções de alto-nível para código de máquina
	- Tradução demorada
	- Execução rápida
	- C, COBOL e ADA.
	
	A velocidade da conexão entre a memória de um computador e seu processador usualmente determina a velocidade do computador, porque, 
	muitas vezes, as instruções podem ser executadas mais rapidamente do que podem ser transferidas para o processador para serem executadas.
	Essa conexão é chamada de gargalo de von Neumann; ele é o principal fator limitante na velocidade da arquitetura de computadores de von 
	Neumann. O gargalo de von Neumann foi uma das principais motivações para a pesquisa e para o desenvolvimento de computadores paralelos.

      2. Interpretação Pura 
	- Sem tradução
	- Execução lenta
	- Raro hoje em dia, sendo mais utilizada para linguagens de scripts
	- APLe da LIST, A maioria dos comandos do sistema operacional, como por exemplo, o conteúdo dos scripts do shell do UNIXe dos arquivos. 
	  BAT do DOS, são implementados com interpretadores puros.

      3. Sistemas de Interpretação Híbrida
	- Custo de tradução é pequeno
	- Velocidade média de execução
	- Perl, Java (forma intermediária é chamada bytecode)
	
	As implementações iniciais de Java eram todas híbridas. Sua forma intermediária, chamada código de bytes, oferece portabilidade a 
	qualquer máquina que tenha um interpretador de código de bytes e um sistema de run-time associado. Juntos, eles são chamados de Java 
	Virtual Machine. Agora há sistemas que traduzem código de bytes Java para código de máquina para permitir uma execução mais rápida. 
	Porém, os applets Java são sempre descarregados do servidor Web na forma de código de bytes.
	
#COMPILAÇÂO
Programa fonte -> ANALISADOR LÉXICO -> (TABELA DE SIMBOLOS + tokens)
tokens -> ANALISADOR SINTÁTICO -> (TABELA DE SIMBOLOS + parse trees)
parse trees -> ANALISADOR SEMÂNTICO -> (OTIMIZAÇÃO + código intermediário otimizado)
código intermediário otimizado -> GERADOR DE CÓDIGO -> linguagem de máquina
TABELA DE SIMBOLOS -> (ANALISADOR SEMÂNTICO + GERADOR DE CÓDIGO)
TABELA DE OPERANDOS -> GERADOR DE CÓDIGO
	
#INTERPRETAÇÃO
Programa fonte -> INTERPRETADOR -> resultados

#IMPLEMENTAÇÃO HÍBRIDA
...tem os dois.

1.8 Computadores Virtuais

      1. firmware (microcódigo)
	- lógica fiada vs chips de microinstrução 
	- memória de controle
	- “instruções de máquina” em ambiente com microcódigo
	- vantagens e desvantagens
      2. software	
	- camadas de interface: computadores virtuais
      3. hardware

//----------------------------------------------------------------------------------------------------------------------------------------------//
--PARTE 2

LINGUAGEM: HASKELL
INTERPETRADOR: HUGS
PRELUDE: BIBLIOTECA PADRÃO ACESSADA POR TODOS OS PROGRAMADORES HASKELL ('FUNÇÕES, OPERADORES E CLASSES')

HUGS 98

- Referência – Hugs98 User Manual
- Distribuição e informações –http://haskell.org/hugs/
			     
– 'Procedural (ou imperativo)'
     Solução algorítmica (passo a passo).
    
/*  function mdc(a,b:integer):integer
      var t:integer;
      begin
	while b<> 0 do begin
          t := b;  b:=a mod b;  a:= t;
	end;
          mdc :=a ;
        end;
*/	
– 'Funcional (chamadas recursivas na ordem em que aparecem)'
     Declara a solução como valores a retornar.
    
/*  mdc a 0 = a
    mdc a b = mdc b (a  `mod` b)
*/
– 'Relacional (ou lógico) (functor é manipulação simbólica)'
     Declara a solução como  relação entre entidades do discurso.
    
/*  mdc(A,0,A).
    mdc(A,B,X) :- BB is A mod B, mdc(B, BB, X).
*/
– 'Orientado a objetos'
     Descreve o problema em termos do próprio problema, ao invés de descrevê-lo em termos de um algoritmo que o computador vai rodar.
    

'LINGUAGENS DECLARATIVAS' --funcional lógica e restritiva (não imperativa)
- Realizam o processamento simbólico
- Processam listas (ES)
- Bloco básico de construção: funções
- Declaram o problema fazendo sua especificação (não resolvendo passo a passo)
- implementam funções complexas, 
- implementam metas programas 
- Tratam símbolos e operações da lógica matemática com relativa facilidade. 

'AMBIENTE HUGS'
- É um interpretador com o ciclo lê-avalia-exibe resultados.
- Funções primitivas:
  - 'lidas do Prelude'
- Funções definidas pelo usuário:
  - 'usando expressões let ou where'
  - 'carregadas de um arquivo de texto.'
  
'expressões LET e WHERE'
let <definição> in <expressão>
let {d1; d2; ....; dn} in expressão
	Prelude> let soma a b = a+b in soma 12 15
	27 :: Integer

<expressão> where <definição>
expressão where {d1; d2; ....; dn}
	Prelude> fat 5 where fat n = product [1..n]
	120 :: Integer
	
'LISTAR COMANDOS EXISTENTES DO PRELUDE'
Prelude> :?
LIST OF COMMANDS: Any command may be
abbreviated to :c where c is the first character in the full name.

'OPERADOR RE-ESCRITA'
- Permite transformar (re-escrever) termos em outros
- É a base do processo de avaliação de expressões
- Programas funcionais são executados usando a redução ou re-escrita de termos.
- Exemplo:
	- No arquivo 'Append.hs'
	append [ ] ys = ys
	append (x:xs) ys = x:append xs ys

	- No terminal, após clicar no arquivo
	append [1,3,5] [4,6] =1:append [3,5] [4,6]
						 = 1:3:append [5] [4,6]
						 = 1:3:5:append [ ] [4,6]
						 = 1:3:5:[4,6]
						 = [1,3,5,4,6]
			
'FUNÇÕES E OPERADORES'
- São estruturas da LF que aplicadas a parâmetros e operandos retornam valores.
- Funções são em geral prefixadas, associativas à esquerda e com prioridade máxima (10).
	– Exemplo: f a b = (f a) b
- Operadores são em geral infixados e podem ter suas prioridades e associatividades declaradas.
	– Exemplo: x^y^2 = x^(y^2), mas x+y+2 = (x+y)+2

'FUNÇÕES'
- Tem nomes com letras e dígitos, começando com letra. São prefixadas:
a) fatorial n = product [1..n]
b) mdc a b
	| b == 0 = a
	| otherwise = mdc b (a `mod` b)
- Uma função pode ser tratada de forma infixada se for envolvida por apóstrofes.
	
'FUNÇÃO LAMBDA'
- Função anônima. É definida como:
	(\args -> corpo)
	Exemplo: (\x y -> x^2 + y^2)

	Prelude> (\x -> x^2) 3
	9 :: Integer
	Prelude> map (\x ->x^2) [1,2,3,4]
	[1,4,9,16] :: [Integer]

'FUNÇÕES COM GUARDAS' -SLIDE 13
- Operador "guarda" = '|'
- Reescreve o que tá à direita se for True.
-> Uma função é definida como:
	eq1 mdc a 0 = a
	eq2 mdc a b = mdc b (mod a b)
	... fat 0 = 1
	eqn fat (n+1) = (n+1) * fat n
	
-> Onde cada equação tem uma das formas:
a) f p1 p2 ... pk | <guarda> = expressão
b) f p1 p2 ... pk = expressão

mdc a b
	| b == 0 = a
	| otherwise = mdc b (mod a b)
	
'EXPRESSÕES CASE'
- Uma expressão case tem a forma geral: 
case <exp> of { p1 match1 ; ... ; pn matchn }
		
	merge xs ys = case (xs,ys) of
	     (z:zs,w:ws) | z<=w -> z:merge zs ys
			 | z>w  -> w:merge xs ws
		        ([],ws) -> ys
			(zs,[]) -> xs
- PERGUNTAR SLIDE 15

'OPERADORES'
- Operador tem nome formado por símbolo especial (não letras ou dígito) e é infixado:

Prelude> map (\x ->x^2) [1,2,3,4]
[1,4,9,16] :: [Integer]
Prelude> 5 == 9
False :: Bool
Prelude> [1,2,3] ++ [5,6] ou (++) [1,2,3] [5,6]
[1,2,3,5,6] :: [Integer]

- Operadores são definidos de forma similar a funções
- Funções e operadores podem fazer uso de definições locais com let ou where
- \/ é a união de listas.

-> A definição de um operador leva em conta:
- prioridade
- associatividade
- comportamento
-> Prioridade (inteiro entre 1 e 9)
 2*3+4 = (2*3) +4 =10 ?
 = 2*(3 + 4) =14 ?
-> Associatividade
1 - 2 - 3 = (1-2)-3 = -4 ?
 = 1-(2-3) = 2
-> xyz = (x  y)  z - à esquerda infixl
 = x  (y  z) - à direita infixr
 = erro! - não associado. infix

'TIPO BOOLEANO'
- (&&), (||) :: Bool -> Bool -> Bool
	True && x = x
	False && _ = False
	True || _ = True
	False || x = x
- not :: Bool -> Bool
	not True = False
	not False = True
- otherwise :: Bool
	otherwise = True
	
'TIPO CHAR'
- É uma enumeração e consiste de valores de 16 bits (2 bytes), conforme o padrão unicode.
- É representado pelo caractere entre aspas simples: ‘a’, ‘b’, ‘A’, ‘0’, ‘1’, ..., ‘9’, etc.
- Cada um dos caracteres de controle ascii tem mais de uma representação possível:
	– Ex.: ‘\7’, ‘\a’ e ‘\BEL’, ‘\b’ e ‘\BS’, ‘\f’ e ‘\FF’, ‘\r’ e ‘ \CR’, ‘\t’ e ‘\HT’, ‘\v’ e ‘\VT’, ‘\n’ e ‘\LF’
- Funções de conversão: chr e ord
	– disponível após “import Data.Char” ou “:l Data.Char” 
	chr :: Int -> Char
	ord :: Char -> Int
	
'TIPO STRING'
- É uma lista de caracteres type String = [Char] é um tipo sinônimo
- Strings podem ser abreviadas envolvendo os caracteres por aspas " string” abrevia a notação [‘ ‘,’s’,’t’,’r’,‘i’,’n’,’g’]
- Todas as operações para lista se aplicam a strings

'STRING E I/O'
- String são objetos visíveis: podem ser lidos ou impressos.
- Exemplo:
	Prelude> let { leia = do
				 putStr "informe uma string >";
				 str <- getLine; putStr str}
			 in leia

informe uma string > lah vai a string, pega!
lah vai a string, pega! :: IO ()

Prelude> putStr "Isto eh uma string"
Isto eh uma string :: IO ()

- Qualquer objeto para ser impresso deve antes ser convertido em string
	Exemplo:
	Prelude> putStr (show [1,2,3,4,5])
	[1,2,3,4,5] :: IO ()

	Prelude> read "[1,2,3,4]" :: [Int] -- converte string em objeto
	[1,2,3,4] :: [Int]

	Prelude> show (23,5.4) -- converte objeto em string
	"(23,5.4)" :: [Char]

	Prelude> read "[('a','b',4.5),('c','d',6.0)]" ::[(Char,Char,Float)]
	[('a','b',4.5),('c','d',6.0)] :: [(Char,Char,Float)]
	
'TIPOS NUMÉRICOS'
- Int e Integer
	- Int tem valores limitados (POR HARDWARE - TAM DO REGISTRADOR)
	- Integer tem valores ilimitado (POR SOFTWARE)
	- Operadores para inteiros
		+, -, *, /, ^, negate, div, rem, mod, odd, even, abs,etc
	- Funções diversas existem no prelude para inteiros
		- Float
		- Complex
		
'TIPO LISTAS'
- É um tipo algébrico de dois construtores: ‘[]’ e ‘:’
- Há muitas funções no Prelude para manipular listas
- Exemplos:
	[ ] lista vazia ou nula
	[3] == 3:[] lista com 1 elemento
	[1,2,3,4,5] == 1:2:3:4:5:[] lista com 5 elementos numéricos
	
	Prelude> [1,3..15]
	[1,3,5,7,9,11,13,15] :: [Integer]
	
	Prelude> ['a'..'z']
	"abcdefghijklmnopqrstuvwxyz" :: [Char]
	
	Prelude> [0.1,0.3 .. 2.0]
	[0.1,0.3,0.5,0.7,0.9,1.1,1.3,1.5,1.7,1.9] :: [Double]

	Prelude> length [1..10]
	10 :: Int
	
- É um conjunto ordenado e homogêneo de elementos com repetição permitida.
- Se t é um tipo, então [t] é uma lista de elementos do tipo t.
- Operadores e funções sobre listas: length, ++, :, concat, filter, head, tail, last, take,drop, replicate, reverse, zip, unzip, elem, and, or,foldl1, 
									 foldl, etc.
- OLHAR O QUE OS DIVERSOS OPERADORES FAZEM NO SLIDE									 
- foldl = envelopado.

1)length [1..1000] 	2)[1,3..10]++[2,4..8]
1000 				[1,3,5,7,9,2,4,6,8]

3)[1,2]:[2,3]:[] 	4)filter even [1..10]
[[1,2],[2,3]]  		[2, 4, 6, 8, 10]

5)concat [['1'],['2'],['3']," abc"," efg"]
 "123 abc efg"

6)head (tail [1,5..200])
5

7)last (reverse [1,10..200])
1

8)drop 2 (take 4 ["jan","fev","mar","abr","mai","jun"])
"mar", "abr"

9)replicate 5 ‘a’ replicate 3 “a”  
“aaaaa”  [“a”, “a”, “a”]

10)elem 13 [1,3..20]
True

11)zip [1,3..10] [0,2..15]
[(1,0),(3,2),(5,4),(7,6),(9,8)]

12)unzip (zip [1,3..10] [0,2..15])
([1,3,5,7,9],[0,2,4,6,8])

13)and (map even [1,2,3,4])  	14)or (map even [1,2,3,4])
False 						 	True

15)foldl (+) 2 [-2..2] 	16)foldl1 (+) [-2..2]
2 						0
17)foldr (-) 2 [-2..2]  18)foldr1 (-) [-2..2]
-2 						0
19)foldl (-) 2 [-2..2]  20)foldl1 (-) [-2..2]
2 						4

'EXEMPLOS DE FOLD'
foldl (op) arg0 [a,b,c] = ((arg0 op a) op b) op c
foldl1 (op) [a,b,c] = (a op b) op c
foldr (op) arg0 [a,b,c] = a op (b op (arg0 op c))
foldr1 (op) [a,b,c] = a op (b op c)

'TIPO TUPLAS'
- É uma estrutura do tipo registro.
- Uma relação fixa de campos de tipos quaisquer.
- Se t1, t2, ..., tn são tipos, então o tipo da n-tupla é (t1, t2, ..., tn).
- Exemplo:
	((“Nome”,“Gisele”),“mulher”,“casada”,(“idade”, 28))
	(5, [1,2,3], “Brasília”)
	
'ENTRADA/SAIDA'
entrada = do putStr "\n dados> "
	dados <- getLine
	putStr “Digitado: "
	putStr (concat [dados, "\n"])
	putStr "continua, (s/n)?"
	carac <- getChar
	if carac=='S' || carac=='s' then entrada
	else return ()

Main> entrada
dados> primeira
Digitado: primeira
continua, (s/n)?s
dados> Segunda
Resultado: Segunda
continua, (s/n)?T :: IO [Char]

'IMPORTANTE'
- Identação indica onde um bloco de código começa e falta de quantidade igual de identação indica que o código do bloco anterior acabou.
if boolean				ou 				if boolean then expr1 else expr2
    then expr1
    else expr2
	
do  input <- getLine
    let ....
    let .....   where 
          unfld ....
		  
'PARADIGMA FUNCIONAL'
- Uma função é definida como um conjunto de equações.
- Cada equação é uma regra de reescrita (redução).
- Exemplo:
filtro p (x:xs)
 | p x = x:filtro p xs
 | otherwise = filtro p xs
filtro _ [] = []

Main> filtro even [1..50]
[2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,4
4,46,48,50] :: [Int]

'CASAMENTO DE PADRÕES' guarda
- É o processo de avaliar um ou mais dos argumentos para determinar qual a expressão do lado direito que se aplica.
- É o processo de identificar a regra de reescrita que se aplica.
- Reescrita (redução) substituir a expressão corrente pela expressão do lado direito, conforme os padrões casados com a instância de argumentos.

'GUARDAS'
- Cada uma das equações na definição pode conter guardas.
- Uma guarda é uma função predicativa.
- Se a guarda for verdadeira, a expressão correspondente na função é executada.
- Exemplo:
	fat n | n == 0 || n==1  = 1
		  | n > 1  = n* fat (n-1)
	Main> fat 5
	120 :: Integer
	
'RECURSÃO'
- É a única estrutura de controle entre comandos em uma linguagem funcional pura.
- O controle de seqüência intra-comando, em expressões, é definido pelas prioridades e associatividades das funções e operadores.
- É o processo da função chamar a si mesma, direta ou indiretamente.
- Exemplo:
	fat 0 = 1
	fat 1 = 1
	fat n = n * fat (n-1) -- e se n < 0 ?

'POLIMORFISMO'
- Tipos polimórficos descrevem famílias de tipos: 
[a] é uma família de listas para diferentes instâncias de tipos:
	a = Int, tem-se [Int]
	a = Char, “ [Char]
	a = [Float], “ [[Float]]
	a - é uma variável de tipo
Nesse sentido a é mais geral que as instâncias de tipos Int, Char, [Float], etc.
- Funções Polimórficas
		Uma função que se aplica a qualquer tipo de parâmetro é uma função polimórfica.
		
'AVALIAÇÃO PREGUIÇOSA'
- Uma expressão só é avaliada quando seu valor é requerido.
- Uma expressão cotizada, aparecendo em vários lugares, é avaliada uma única vez
- zero $! (1/0) -- Força avaliação argumento

'OBJETOS INFINITOS'
- Graças a avaliação preguiçosa é possível lidar com lista infinitas.
- let naturais n = take n [0..] in naturais 8
- let impar n = take n [1,3..] in impar 10

'FUNÇÕES DE ORDEM ALTA'
- Funções que manuseiam outras funções:
	– composição de funções.
	– passadas como parâmetros.
	– resultado da chamada de função.
	– aplicação parcialmente aos seus argumentos.
	– usadas em estrutura de dados.
	
	'COMPOSIÇÃO DE FUNÇÕES'
	- f.gx = f(gx)  	
	
	var xs = (sum . map (^2)) xs / n - (sum xs / n)^2
		where n = length xs
	
	((^3) . (/2)) 10
	
	 (sum . take 10) [1..]
	 
	 let uns = 1:uns in (sum . take 20) uns
	 
	 let uns n | n==1 = [1] | n/=1 = 1:uns (n-1) in (sum.uns) 30
	 
	 'FUNÇÕES COMO PARÂMETROS'
	 par x = x `mod` 2 == 0
	 filtro p (x:xs)
		| p x = x:filtro p xs
		| otherwise = filtro p xs
	 filtro _ [] = []
	 
	 'FUNÇÃO COMO RESULTADO'
	 somat = foldl (+) 0	//quando chamar somat na verdade estará chamando foldl
	 produt = foldl (*) 1	
	 append = foldr (++) []
	 
	 'APLICAÇÃO PARCIAL'
	 suc 4 where suc = (+1)
	 somatorio [1..10] where somatorio = foldr (+) 0
	 ola "Joao" where ola = ("Oi " ++) . (++ " como vai voce?")
	 soma 3 5 where soma = (+)
	 
	 'FUNÇÕES EM ESTRUTURAS DE DADOS'
	 let operacao (f, x, y) = f x y in operacao ((+), 4, 6)
	 let operacao (f, x, y) = f x y in map operacao [((+),4,6),((*),3,4)]
	 
	 'MAP'
	 map f xs = [f x | x <- xs]
	 map2 f xs ys = [f x y | (x,y) <- zip xs ys]
	 
	 - representação f x y versus f(x,y)
	 f(x,y) - uncurry f x y

//----------------------------------------------------------------------------------------------------------------------------------------------//
Montadores, Ligadores, Carregadores, Compiladores e Interpretadores
- Montadores (Assemblers)
	- Montam um programa em linguagem de máquina a partir de sua versão em linguagem de montagem.
	- Geram um arquivo objeto. Em geral, não pode ser executado diretamente pela máquina, por conter referências a sub-rotinas e dados especificados 
	em outros arquivos.

- Ligadores (Linkers)
	- São programas especiais que recebem como entrada arquivos objetos e geram como saída o programa final em linguagem de máquina.
	- Gera um programa executável a partir de um ou mais arquivos objeto.

- Carregadores (Loaders)
	- Para executar um programa, um loader deve ser utilizado.
	- O carregador é, em geral, parte do sistema operacional.
	
- Compiladores
	- São programas que recebem como entrada arquivos texto contendo módulos escritos em linguagem de alto nível e geram como saída arquivos
	objeto correspondentes a cada módulo.
	- Se todas as bibliotecas ou módulos são apresentados como entrada, geram um programa executável diretamente.
	
- Interpretadores
	- Recebem como entrada arquivos texto contendo programas em linguagem assembly ou linguagem de alto nível, ou arquivos binários com instruções
	de máquina, e os executam diretamente.
	- Interpretadores percorrem os programas, a partir de seu ponto de entrada, executando cada comando.
	- Processadores são interpretadores implementados em hardware!

Paradigmas: Procedural, funcional, imperativa, orientada a objetos, estruturada

- Procedural: chamadas a procedimento ( rotinas, subrotinas, métodos, ou funções(similares àquelas usadas na programação funcional))
			  #ADA, C, C++, COBOL, FORTRAN, LUA, MATLAB, MAPLE, PASCAL, PERL, PYTHON
- Funcional:  trata a computação como uma avaliação de funções matemáticas e que evita estados ou dados mutáveis. Ela enfatiza a aplicação
	      de funções, em contraste da programação imperativa, que enfatiza mudanças no estado do programa.
			  #HASKELL, LISP, R, WOLFRAN
- Imperativa: especifica os passos que um programa deve seguir para alcançar um estado desejado. Descreve a computação como ações, enunciados 
	      ou comandos que mudam o estado (variáveis) de um programa. Muito parecido com o comportamento imperativo das linguagens naturais 
	      que expressam ordens, programas imperativos são uma sequência de comandos para o computador executar.
			  #ADA, ALGOL, C, JAVA, COBOL, FORTRAN, PASCAL, PYTHON, LUA
- OO:		  composição e interação entre diversas unidades de software chamadas de objetos.
			  #C++, JAVA, PYTHON
- Estruturada:preconiza que todos os programas possíveis podem ser reduzidos a apenas três estruturas: sequência, decisão e iteração (esta 
	      última também é chamada de repetição)
		  
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
  






  








      
      

  
  








  





 


	







    
    
    


