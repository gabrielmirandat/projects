//******************************************************************************************//
";" - força Prolog a encontrar outra resposta
"," - conjunção => AND(/\) ex.	?- parent(X,ann),parent(X,pat).			//X aqui é o mesmo. 
									//Só retorna se X for pai ou mãe tanto de ann quanto de pat
";" - disjunção => OR(\/)  

"!"									//Átomo especial = Impede backtracking. Acaba backtracking de onde tá sendo usado.
"::="									//Átomo especial = Operador restring. Restringe o escopo de algo.

help(assert).								//sai do prolog
['family.pl']. ou [family] 						//carrega programa
halt.									//sai do prolog
listing(grandparent).							//mostra seu módulo no terminal

assert (..)								//insere fato ou regra
retract(..)								//elimina fato ou regra

consult('pai.txt').							//carrega base de conhecimentos (arquivo com fatos ou regras)

//Carregar um programa 
load ou load_files(arquivo). 						// fonte ou objeto
consult(arquivo). 							// fonte
consult(user). 								// carrega via teclado. Fim ^Z
reconsult(arquivo). 							// recarrega arquivo

//Capacidade especial (de algumas implementações)
//Armazenar o atual BC em arquivo
save(arquivo). 								// salva a BC no arquivo, objeto
save_predicates(predicados, arquivo).					// salva os predicados em arquivo, código
//Recuperar o arquivo salvo
restore(arquivo). 							// recupera o código objeto
load ou load_files(arquivo).  						// objeto

#PROCEDIMENTO
consult('pai.txt'). ou ['pai.txt']
['familia.pl']


//******************************************************************************************//

//------------------------------------------------------------------------------------------//
SWI-PROLOG
-> um interpretador
?- prompt principal
| prompt secundario

//------------------------------------------------------------------------------------------//
SISTEMA DE REGRAS:
- Base de conhecimentos (BC) 
- Memória de trabalho (MT) 
- Máquina de inferências
//BC - composta de fatos e regras
//--Fatos: declarações sobre objetos específicos 
//--Regras: declarações sobre classes de objetos 

//MT - estado do problema em um dado instante.Permite a comunicação entre regras.
//--dados dinâmicos de curta duração que existem enquanto uma regra estiver sendo interpretada.Variáveis da regra não são estáticas.
//--Ação da regra implica modificações na memória de trabalho ou efeitos colaterais eventuais.

//Máquina de inferências
//--Ativada com a especificação da meta (problema a resolver).
//--escolha de quais regras aplicar e execução.

//------------------------------------------------------------------------------------------//
CICLO DE EXECUÇÃO
- 'seleção das regras'
- 'resolução de conflitos '
    -> na existência de mais de uma regra a aplicar. 
- 'ação'
    -> execução da(s) regra(s) selecionada(s) com as conseqüentes alterações na MT ou efeitos colaterais.

CICLO DE EXECUÇÂO DETALHADO
- SELEÇÃO DAS REGRAS (matching)
    -> Casamento das regras com dados da MT
    -> Conjunto de conflito (regras casadas)
- ESTRATÉGIAS UTILIZADAS
    -> guiada por dados (forward-chaining)
    -> guiada por metas (backward-chaining)
- ESTADO INICIAL (dados da MT)
- RACIOCÍNIO PARA FRENTE
    -> Casamento: MT com condições das regras.
    -> Estados: gerados com o disparo das ações.
    -> Meta: permanece a mesma. 
    -> Parada : casamento com meta.
- RACIOCÍNIO PARA TRÁS
    -> Início: configuração objetivo final (meta).
    -> Casamento: MT com ação da meta (mesmo em parte).
    -> Estados: gerados com as condições.
    -> Meta: estado atual
    -> Parada: casamento com estado inicial. 

//------------------------------------------------------------------------------------------//
Máquina de Inferências no Ciclo de execução

- Resolução de conflitos
    -> Seleção da ordem de aplicação das regras do conjunto de conflito. Preferência baseada na:
      - ordem em que as regras aparecem (Prolog)
      - importância dos objetos que foram casadas (ELIZA, Weizenbaum, 1966) 
      Talvez eu pudesse aprender a conviver com a minha mãe.
      //Talvez você pudesse aprender a conviver com a sua mãe.
      //Fale mais sobre a sua família.
      - em estados 
	  -> Consiste em, temporariamente, disparar todas as regras selecionadas e utilizar uma função heurística para avaliar os resultados de cada uma delas, e 
	  priorizá-las segundo o seu mérito.
	  
   -> Inferência
      'resolução por refutação'
   -> Seleção das regras
      'raciocínio para trás com indexação das regras pelo predicado e casamento (matching) precedido pelas instanciações das variáveis das regras (unificação)'
   -> Resolução de conflitos
      'preferência baseada em regras (ordem)'
	  
//------------------------------------------------------------------------------------------//
Cláusulas Prolog
-Fatos, regras ou consultas
  
 ->Base de conhecimentos (BC)
 -fatos
 -regras	//arquivo texto carregado via “consult(arquivo-texto).”
 
 ->Prompt interpretador
 -consultas
 -BC é modificada via 
    -assert (insere fato ou regra)
    -retract(elimina fato ou regra)
    
FATOS
- Relação verdadeira entre termos, via predicado.	//Predicado, é aquilo que atribui algo ao sujeito
- Cláusula sem nenhuma condição.
- <functor> (t1,t2,...,tn). 
- expressa uma relação entre termos.
- aridade: <functor>/aridade.

REGRA
- cabeça :- corpo.		//o operador “:-” é denominado pescoço (neck) 
- meta :- sm1, sm2,..., smk	//para 
- meta só é verdadeira se suas submetas também o forem. 

//------------------------------------------------------------------------------------------//
'Functor' e átomo iniciam com letra minúscula.	//É o termo composto??

Programa Prolog: Fatos e Regras
-mais(0,X,X).  			//fato
-mais(A,B,C) :- C is A + B.  	//regra
        
//------------------------------------------------------------------------------------------//

TIPOS
  - TERMOS SIMPLES 
    - CONSTANTES
      -> inteiros
      -> reais
      -> átomos (strings constantes)
    - VARIÁVEIS
  - TERMOS COMPOSTOS
    -> listas
    -> estruturas
	  
-Atomos e números são definidos sobre os caracteres:	//ou seja, todos??
//A,B,..,Z
//a,b,...,z
//0,1,...,9
//caracteres especiais como + - * / < > = : . & _ ~

ÁTOMOS
- Strings iniciadas por minúsculas		//anna	x_25	nil
- String de caracteres especiais		//*.=@#$
- Átomos especiais				//::== .:. [] !		! = cut    [] = representa lista vazia
- Strings de caracteres entre aspas simples	//'Tom' 'x_>:'
- Qualquer caracter desde que não seja operador primitivo.
- Átomos são nomes textuais usados para identificar dados, predicados, operadores, módulos, arquivos, janelas, etc.
+++
#atomic(Termo).	//retorna true quando o Termo é atômico, não estruturado.

NÚMEROS
- reais: 	3.14 	-0.57	1.23	1.23^4
- inteiros: 	23	5753	-42
+++
# number(X). 	//retorna true quando o Termo é número.

VARIÁVEIS
- Iniciam com maiúsculas ou underscore		//X_25	_chica	 X	Barao	Fred
- Variável anônima (pense como “não importa!”)	//(_) - underscore
+++
- É uma incógnita. Designa uma entidade  até o momento desconhecida. 
Ex.: X  _   _x   Avo   Gente   G12  Pai_sangue    _b


TERMO COMPOSTO
- Átomo seguido por uma seqüência de um ou mais termos, entre parenteses e separados por vírgula	//parent(pam,bob). deseja(estudante,passar(lp,2013,2)).
  -> não é função (é ED tipo registro)
- listas 
- estruturas
+++
# compound(X).	//retorna true quando Termo é termo composto.

LISTAS
- É uma seqüência de termos entre colchetes , separados por vírgulas.
+++
#[X|Xs] = [1,2,3].	//X= 1 e Xs = [2,3] 
#[X,Y|Xs] = [1,2,3,4]	//X=1, Y=2, e Xs =[3,4]
  
ESTRUTURA
- É semelhante a um registro, com tipo, nome, e campos.
Ex.: nome(t1,t2,...,tn),   nome/n

	  
TERMOS (OBJETOS DE DADOS)
Objetos de dados(Objetos simples, Estruturas);
Objetos simples(Constantes e Variáveis)
Constantes(Átomos e Números)

//------------------------------------------------------------------------------------------//	 
ARITMÉTICA
#X is 1+2.		//X = 3.
#X is ceiling( 2.1 ).	//X = 3.	->arredonda pra cima
#X is ceiling( -2.1).	//X = -2.
  
Nome/aridade			Explicação
e / 0				número 2.71828. . . 
exp / 1				e**exp  (ISO)
** / 2				exponenciação (ISO)
float / 1			conversão para float (ISO)
/  / 2				divisão (ISO)
index / 3			localiza substring em string
// / 2				divisão inteira (ISO)
random / 1			gera número aleatório inteiro
floor / 1			maior inteiro não maior que
length / 1			comprimento da string
log / 1				logaritmo neperiano (ISO)
log10 / 1			logaritmo decimal
mod / 2				módulo de divisão inteira (ISO)
* / 2				multiplicação (ISO)
pi / 0				número 3.14159. . . 
rem / 2				resto de divisão inteira (ISO)
round / 1			inteiro mais próximo (ISO)
sign / 1			retorna -1, 0 ou +1 (ISO)
- / 1				inverte o sinal (ISO)
sin / 1				seno (ISO)
sinh / 1			seno hiperbólico
sqrt / 1			raiz quadrada (ISO)
- / 2				subtração (ISO)
tan / 1				tangente
tanh / 1			tangente hiperbólica 
truncate / 1			parte inteira de um real (ISO)
< / 2				menor do que (ISO)
> / 2				maior do que (ISO)
=< / 2				menor ou igual a (ISO)
>= / 2				maior ou igual (ISO)
=\= / 2				diferente (ISO)
=:= / 2				igual (ISO)

Avaliador de Expressões
X is E			//X variável não ligada. E expressão aritmética. 
E1 op E2 		//Onde op E {<, =<, >=, >, =:=, =\=}. E1 e E2 são expressões aritméticas avaliadas antes da comparação. 

#?- X = 2, Y = 5, Y - X =\= X. 	//X = 2.  Y = 5		estranho.

//------------------------------------------------------------------------------------------//	  
RECUPERANDO INFORMAÇÕES
- Consulta existencial				//?- pai(P,joao). 		% existe um P pai de joao?
- Consulta conjuntiva e variáveis cotizadas	//? pai(joao, F), pai(F,N). 	%Quem são os netos de joão?   
	  
	  
//------------------------------------------------------------------------------------------//
PROLOG

- Programação em lógica
    -> definições lógicas são vistas como programas.
       Em Prolog definições lógicas são cláusulas de Horn.
       
    -> Negação
       ausência da declaração. //Não é uma negação lógica.
    -> Resolução por refutação
       P é consistente se falhar a prova de ^P.
    
    -> Implicação	//A->B == ^A\/B
    
    -> Cláusulas de Horn
      - Cláusula que tem, no máximo, um literal positivo
      - Lógica decidível

//Cláusulas de Horn
Uma cláusula de Horn pode ser de quatro tipos diferentes:
  'regra' = tem um literal positivo, e pelo menos um literal negativo. Sua forma é ^P1 \/ ^P2 \/ ... ^Pk \/ Q,
	    logicamente equivalente a (P1 /\ P2 /\ ... Pk) -> Q
	    
	    'regra p -> q' = 'q :- p'		//q é a AND de todos os outros negados.
	    cabeça :- lista de predicados.
//------------------------------------------------------------------------------------------//    
PREDICADOS
- bidirecionais		//?- pai(ze, F)		F = zefa ; F=ruth; false.
			//?- tio(T,zefa). 	T = mane ; T = quim ; false.
- unidirecionais	//?- fat(0,F). 		F = 1
			//?- fat(N,120).	ERROR: is/2: Arguments are not sufficiently instantiated
	 
//------------------------------------------------------------------------------------------//    
Unificando com Variável
1) variável com variável
#X = Y		//X unifica com Y e retorna true -> passam a representar a mesma variável.
#X \= Y 		//retorna sempre false -> false.

2)Variável em dados estruturados, há unificação se as estruturas forem isomórficas e se houver uma substituição sobre as variáveis que torne as estruturas 
dênticas. 
#X = arco(a,b,10).    //X = arco(a,b,10)
#livro(autor(teixeira, joao), Titulo) =  livro(Autor,titulo('Amor e Paz')).    //Titulo = titulo('Amor e Paz') , Autor = autor(teixeira,joao)
#?- [[X|Xs],Y,c,d] = [[1,2,3],a,c,d].	//X = 1 , Xs = [2,3] , Y = a

Unificando Constantes
T1 = T2		//Unificam se tiverem valores idênticos e forem estruturalmente isomórficos. 
#?- arco(a,b,10) = arco(a,b,10). 	//true.
#?- 'wagner' = wagner.

Comparação de Termos Arbitrários
Com os operadores ==/2 (idênticos), \==/2 , @>=/2, @>/2 ,  @</2, @=</2
'Com o @ posso comparar qualquer coisa'

Tipo	          	Comparação
variáveis 		endereços
números			valor numérico
átomos			valor ASCII

- Segue a ordem variáveis < flutuantes < inteiros < átomos < strings < listas < termos-compostos 
- Se os termos são do mesmo tipo, então uma “comparação de tipo” é feita. 
- Rs = [2.3, 3, 4, 7, "dada", "manoel", dada, wagner, arco(a,b,5), arco(b,d,3)] ;

//------------------------------------------------------------------------------------------//    
Teoria Lógica (TL) = programa = Base de Dados dedutivo = Base de Conhecimento

Teoremas da TL
  -> deduzidos a partir dos axiomas e das regras
  -> dados implícitos do Banco de Dados dedutivo
  
- computação simbólica não numérica
- interpretador
- base de conhecimentos, memória de trabalho e máquina de inferência
- Definir relações e formular perguntas sobre as relações.

//------------------------------------------------------------------------------------------//
Regras de Produção
  -> conhecimento representado por regras situação-ação 	//SE <condição> ENTÃO <ação>.
  -> o conhecimento existente pode ser refinado com a adição de regras, permitindo um crescimento incremental da base de conhecimentos.
  -> A performance do sistema cresce proporcionalmente ao crescimento da base de conhecimentos
  -> definições lógicas = 'conhecimento procedimental '

//------------------------------------------------------------------------------------------//
Controle e busca
  - com estratégia linear (sempre tenta unificar ultimo fato a provar com a conclusão de uma cláusula do programa), 
  - na ordem de escrita das cláusulas no programa, 
  - com encadeamento de regras para trás,
  - busca em profundidade e
  - da esquerda para direita das premissas das cláusulas,
  - e com backtracking sistemático e linear quando a unificação falha,
  - e sem occur-check na unificação.
 
//------------------------------------------------------------------------------------------//
//Aqui /\ é intersecção e \/ é união
SE animal de estimação /\ pequeno ENTÃO bicho de apartamento.
SE gato \/ cachorro ENTÃO animal de estimação.
SE poodle ENTÃO cachorro /\ pequeno.
Fido é poodle.

//------------------------------------------------------------------------------------------//
Vantagens
  - Ampla expressividade
  - Aplicação: sistemas especialistas, em especial, de diagnóstico

//------------------------------------------------------------------------------------------//
Fatos:
parent(pam,bob).
parent(tom,bob).
...

queries;
?- parent(bob,pat).
true.
?- parent(liz,pat)...

Se eu jogar:
?- parent(X,liz), ele retorna X = ??
//------------------------------------------------------------------------------------------//
Observações
-Prolog avalia and até encontrar False.
-Tudo retorna True ou False.
-OU tem precedência com AND.

//------------------------------------------------------------------------------------------//
INCLUINDO CLAÚSULAS NA BC

#dynamic(pai/2).	//diz que o predicado pode mudar
#asserta(clausula). 	//adiciona no início das cláusulas com mesmo nome.
#listing(pai/2).	//lista predicado => MOSTRA CONFIGURAÇÃO ATUAL DA BASE DE CONHECIMENTOS DO FUNCTOR PAI ARIDADE 2!!!!!!!!!!!
#assertz(cláusula)  	//inclui no final das cláusulas de mesmo nome.

//------------------------------------------------------------------------------------------//
Operador Univ
'=../2' = transforma termo em lista.
-Apenas um dos seus operandos pode ser variável.

?- struct(hello, X) =.. L.	//L = [struct, hello, X]
?- Term =.. [baz, foo(1)]	//Term = baz(foo(1))
?- Pai = [pai, joao, ze].	//Pai = [pai,joao,ze]
?- P =.. [pai,joao,X], call(P).	//P = pai(joao,maria) , X = maria

//------------------------------------------------------------------------------------------//
UNIFICAÇÃO

a) variáveis unificam com variáveis		//X = Y.
b) variáveis unificam com termos		//X = gosta(joao,ler).
c) termos unificam com termos, se eles casam	//pai(P,F) = pai(joao, ze) com =(P/joao, F/ze). 
						//2 = 2, joao = ‘joao’, etc.
d) Um termo não-atômico unifica com outro se houver correspondência estrutural.	//livro(autor(Sn,N),titulo(‘Clarissa’)) =livro(autor(‘Verissimo’,’Erico’), T).
										//com theta = (Sn/’Verissimo’, N/’Erico’, T/titulo(‘Clarissa’) )
										//theta representa a relação de casamentos.

										
Controle do Programa
//repeat - fail, loops, recursão e cut. 

Meta
-Sucede, se todas as submetas no corpo sucedem. 
-Falha, se ao menos uma submeta no corpo falha. 
-Quando há falha, o Prolog tenta satisfazer a meta com outras alternativas, buscando um casamento a partir de onde a meta ficou.
-Esse processo de tentar satisfazer todas as submetas, antes de dá-la por falha é o backtracking.



										
										
										
//------------------------------------------------------------------------------------------//
CRIANDO MÓDULO E OPERADORES

#module(if,[se/1, entao/2, senao/2]).
#:- op(800,xfx,entao).
#:- op(750,fx, se).
#:- op(810,xfx,senao).
#se X :- X.
#X entao Y :- X, Y.
#X senao _ :- X,!.
#_ senao Z :- Z.
#X = 12, se X=10.     
#false.
#X = 12, X=12 entao Y=1.   			// implicação
#X=12, 
#Y=1. 	
#X = 10, X==10 senao Y = 2. 			// ou
#X=10.

#?- X = 12, se X=10 entao Y=1 senao Y = 2.  	//X=12, Y=2.

Operadores
Especifier  		Class      	Associatively
 fx			prefix		non-associative
 fy			prefix		right-associative
 xfx			infix		non-associative
 xfy			infix		right-associative
 yfx			infix		left-associative
 xf			postfix		non-associative
 yf			postfix		left-associative
 
Priority	Specifier	Operator(s)
 1200		xfx		:-				//menor prioridade
 1200		fx		:-
 1100		xfy		;
 1050		xfy		->
 1000		xfy		,
 900		fy		\+
 700		xfx		 =, \=
 700		xfx		==, \==, @<, @=<, @>, @>=
 700		xfx		is, =:=, =\=, <, =<, >, >=
 500		yfx		+, -, /\, \/
 400		yfx		*, /, //, rem, mod, <<, >>
 200		xfx		**
 200		xfy		^
 200		fy		-, \				
# 0		termo entre parenteses				//maior prioridade
- Quanto menor o valor da prioridade, maior prioridade tem.

Priority	Specifier	Operator(s)
 1000		xfy		|
 900		fy		not
 700		xfx		is_string
 600		yfx		&
 200		fy		+
 
 
OPERADORES E PREDICADOS DE CONTROLE
ifthen (P,Q) :- P, !, Q.     	// falha sob retrocesso
ifthen(P,Q) :- !.      
ifthenelse(P,Q,R) :- P, !, Q.  	// falha sob retrocesso
ifthenelse(P,Q,R) :- not(P), !, R. 
case([C1 -> P1, C2 -> P2, ...., Cn -> Pn|P]).

! - cut. Sempre verdadeiro. Sob retrocesso, o predicado que o contém falha.
//O corte é usado para reduzir o espaço de busca, instruindo o interpretador a não retroceder sobre os predicados que precedem o cut. 

#?- idade(joao, Y), !.			//Y = 36 
//Obs.: dado que cada pessoa só tem uma idade, o corte é desejável

#?- idade(X,Y),!,  Y > 18.		//X = joao ,Y = 36
//obs.: Neste último caso, quer-se mais de uma resposta, para diferentes valores de X, contudo,   o cut impediu. 

Isolando o efeito do corte
-O predicado souma(P) enseja um uso adequado do cut, quando a pretensão é eliminar buscas desnecessárias, ou restringir a uma só resposta. 
//Não precisa usar cut diretamente na consulta
//Não precisa usar cut sobre cláusulas na base. 
//souma(P)  falha sob retrocesso, mas não impende que variáveis em predicados anteriores, no mesmo corpo, sejam revaloradas.
//É assim uma solução mais limpa para o cut.  

//P -> Q  			% Se P então Q.
#X = 2 -> Y is X+3, Y < 7 -> Z is Y+4. 					//X = 2 , Y = 5 , Z = 9

//repeat - fail

//------------------------------------------------------------------------------------------//
#offspring(Y,X) :- parent(X,Y).
#Semântica: se parent(X,Y) então offspring(Y,X).
-offspring significa filho.
-meta: offspring(Y,X)
-submeta: parent(X,Y)
-para a meta suceder, a submeta tem que suceder.

#assert(data(17, novembro, 2012)).
#data(Dia, novembro, 2012).	//Dia = 17

#repeat/0						//Succeed, leaving infinite backtrack points
#							//repeat é para fazer um loop. O predicado em que é usado é repetido até que cada todos retornem True

#member(N,['S','s','N','n']).				//pergunta se N é membro da lista

#write('x1 = ').					//printa string

#fail/0							//Always false

#write(X),fail.						//ao final da expressão força Prolog a mostrar todos os resultados de uma só vez, sem ponto-e-vírgula

#dynamic/1						//Indicate predicate definition may change
