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
	







    
    
    


