//------------------------------------------------------------
:r - regarrega arquivo
tamanho de uma lista 						=> sum [1 | _ <- xs]
soma de todos os elementos de uma lista		=> sum [x | x <- xs]




//------------------------------------------------------------

Imperativa x funcional
- Vc não pode atribuir um valor pra a e depois atribuir outro valor. Você é algum tipo de mentiroso?
- Uma função não tem efeitos colaterais.A única coisa que faz é calcular algo e retorná-lo como resposta.
- Haskell usa tipagem ESTÁTICA! Muitos erros encontrados em tempo de compilação.
- Haskell usa INFERÊNCIA DE TIPOS.
#Haskell provides the type Dynamic, which can safely be used but is hardly needed.
#Scripting languages usually rely entirely on dynamic typing.
#
#Dynamically typed: Scripting languages (Perl, PHP, Python, Ruby), PROLOG
#Statically typed: C, Ada, Wirthian languages, Eiffel, Haskell

- modo interativo: ghci, no mesmo diretorio do arquivo .hs.
- Se você mudar o script, use :l myfunctions de novo ou :r, que é equivalente porque recarrega o script atual. //o winhugs faz isso sozinho

-> Ordens de precedência normais. Parêntesis para mudar precedência.
-> Números negativos entre parêntesis
-> &&(and) ||(or) not(nega um True ou False)
-> ==(igual) /=(diferente)
-> number + number 
-> tipo1 == tipo1
-> 5 + 4.0 (possível => int + Double = Double + Double) //--ocorre adaptaçao

-> * é uma função. Você chama ela colocando-a entre dois números. É uma função 'INFIXADA'.
//Um infixo (ou interfixo) é um afixo que se localiza dentro da raiz, dividindo-a em duas partes descontínuas.

-> A maioria das função não usadas com números são 'PREFIXADAS'. 
//Morfemas que se colocam antes dos radicais basicamente a fim de modificar-lhes o sentido.

-> Em Haskell, funções são chamadas escrevendo-se o nome com espaços nos parâmetros.
-> Funções e seus parâmetros tem a maior precedência.
-> Podemos 'INFIXAR' uma função, envolvendo-a com ``.
-> bar (bar 3) em HASKELL <=> bar(bar(3))
-> funções são definidas de forma similar como são chamadas, porém existe um '=' e depois o que a função faz.
-> para carregar um arquivo.hs, use ':l arquivo'
-> Um arquivo pode ter várias funções diferentes (ou módulos).

-> if then else
	-> Em HASKELL, se temos if, o else é obrigatório.
	-> Em linguagens imperativas você pode simplesmente pular algumas etapas se a condição não for satisfeita , mas em Haskell cada expressão e função deve 
	retornar algo. O if é uma expressão aqui, e deve retornar algo. 
	-> Esta função explica isto: doubleSmallNumber' x = (if x > 100 then x else x*2) + 1  
	-> O prompt só aceita expressões.
-> ' é um caractere normal, geralmente para denovar uma versão estrita de uma função.
-> Toda função começa com letra minúscula.
-> Quando uma função não tem nenhum parâmetro, chamamos ela de 'definição' ou 'nome'
	
#listas
-> Em HASKELL, listas são estruturas de dados homogêneas.
-> Podemos usar "LET" para definir um nome numa expressão. 'let x = 1 in x + x'
-> String é apenas uma lista de caracteres.
-> "hello" é o mesmo que ['h','e','l','l','o']. Como strings são listas, podemos usar funções de listas nelas.
-> operador concatenação '++' = uni apenas duas listas (percorre a lista inteira da esquerda do operando).	//PODE-SE COLOCAR O ELEMENTO ENTRE []
-> operador cons ':' = uni duas listas de forma instantânea, ou um elemento de lista com lista (não precisa percorrer tudo). //É MAIS GERAL
-> ['a'] ++ "ba" é o mesmo que 'a': "ba"
-> É válido 1:2:3:[]
-> "Steve Buscemi" !! 6 //Com !! podemos pegar um elemento da lista em específico (começa em 0).
-> [3,2,1] > [2,10,100] //True. Compara na ordem em que aparece.
-> [3,2,1] == [3,10,100] //False.
-> head(primeiro), tail(todos menos o primeiro), init(todos menos o ultimo), last(ultimo)
-> testar null [1,2,3] é melhor que testar xs = [].
-> take(pega os primeiros), drop(tira os primeiros)
-> elem retorna booleano que indica se existe o elemento na lista.

####list comprehension####
-> Possui casamento de padrões
-> O operador <- faz casamento elemento a elemento.
-> [x*2 | x <- [1..10], x*2 >= 12] //a virgula aqui representa AND
-> boomBangs xs = [ if x < 10 then "BOOM!" else "BANG!" | x <- xs, odd x] //odd x retorna True se x for impar
-> Só acontece o que tá à esquerda da guarda se o direito como um todo retornar True.
-> length'' xs = sum [1 | _ <- xs] //substitui todos os elementos da lista por 1 e depois soma. Note que armazenamos cada elemento em _.
-> removeNonUppercase st = [ c | c <- st, c `elem` ['A'..'Z']] //c <- st sempre retorna True, c `elem` ['A'..'Z'] só retorna True se c for maiúscula.

#tuplas
-> Numa tupla, o 'tipo' dela é definido como sendo quantidade de elementos e tipo dos elementos.
-> Numa lista, só podem haver tuplas iguais.
-> Uma tupla pode ser composta de elementos heterogêneos.
-> [(1,2),(8,11),(4,5)] //lista cujos elementos são tuplas [(Integer,Integer)]
-> Use tuplas quando vc sabe quantos componentes um tipo de dados deve ter.
-> para tuplas pares(2 elementos) => fst(primeiro elemento das tuplas), snd(segundo elemento da tupla)
-> zip = produz uma lista de pares (tuplas de 2 elementos)!!
-> zip [1,2,3] [5,5,5,5,5] 	//[(1,5),(2,5),(3,5)] :: [(Integer,Integer)]
-> unzip [(1,5),(2,3)]		//([1,2],[5,3]) :: ([Integer],[Integer])

#tipos e typeclasses
-> Tudo em HASKELL tem um tipo.
-> HASKELL possui inferência de tipos (ele sabe o tipo das coisas sem que seja dito para ele).
-> Um tipo é uma label que cada expressão tem. Ele nos diz em qual categoria de coisas a expressão se encaixa.
-> True é booleano, "hello" é uma string, etc.
-> :t <expressão> = tipo que representa a expressão.
-> :t 'a' //'a' :: Char
-> :: entendido como"tem tipo de".
-> Todo tipo explícito começa com letra maiúscula.
-> Cada tamanho de tupla tem seu próprio tipo.
-> Funções também tem tipos. Podemos escolher em declarar explicitamente o tipo ou não. É uma boa prática declarar, exceto quando temos funções muito curtas.
-> removeNonUppercase :: [Char] -> [Char]	//recebe String como parâmetro e retorna String	como resultado
-> addThree :: Int -> Int -> Int -> Int 	//recebe 3 Ints como parâmetro e retorna 1 Int como resultado
-> [Char] = String
-> Parâmetros separados por ->, sem distinção do que é entrada e saída. O último é o retorno.
-> Se você não sabe qual o parâmetro que sua função retorna, pode usar um :t antes da chamada dela!
	-> Int : em 32 bits, máximo é 2147483647 e mínimo é -2147483648.
	-> Integer : pode representar qualquer número, sem truncamento.
	-> Float : ponto flutuante real com precisão simples.
	-> Double : ponto flutuante normal com precisão dupla.
	-> Bool : True ou False.
	-> Char : aspas simples.
	-> String : lista de caracteres ou aspas duplas.
	
#variável de tipo
-> São o tipo das 'funções polimórficas!'
-> :t head  //head :: [a] -> a	, ou [b] -> b
-> Entra uma lista do tipo a e é retornado um elemento do tipo a.
-> Em [a], a não pode ser um tipo já que não está em letra maíuscula, logo é uma 'variável de tipo'. Significa que a pode ter qualquer tipo.
-> Nomes comuns para variáveis de tipo: a,b,c,d..
-> :t fst	//fst :: (a, b) -> a

#typeclasses 101
-> Uma typeclass é um tipo de interface que define algum comportamento. Se um tipo é parte de uma typeclass, significa que suporta e implementa o comportamento
descrito pela typeclass.
-> :t (==)  //(==) :: (Eq a) => a -> a -> Bool
-> O operador ==, assim como +, *, -, /, são todos funções. Funções de poucos caracteres costumam ser infixadas. Para analisar seu tipo, transforme-a 
em prefixada usando parêntesis.
-> <restrição_de_classe> => tipo_da_função
-> (Eq a) => a -> a -> Bool //recebe duas entradas de tipos quaisquer iguais e retorna um Booleano. Porém, o tipo das duas entradas deve ser membro da classe 
							//Eq.
-> A typeclass Eq provê uma interface para teste de igualdade. Qualquer tipo possível de teste de igualdade deve ser membro da classe Eq.
-> Todos os tipos padrões de HASKELL exceto IO e funções são parte do typeclass Eq.
-> elem 	//(Eq a) => a -> [a] -> Bool
	-> Eq : usada por tipos que suportam teste de igualdade. As funções que estes membros implementam são == e /=.
	-> Ord : são pra tipos que tem uma ordenação. 'Ordering' é um tipo que pode ser GT, LT ou EQ, significando greater than, lesser than e equal, 
	respectivamente. "Abrakadabra" `compare` "Zebra"	//LT :: Ordering
	-> Show : permite a representação como String. A função mais usada que aceita Show é show. Toma um valor cujo tipo é membro de Show e mostra-o como uma 
	string. 
	-> Read é a typeclass oposta a Show. A função read toma uma String e retorna um tipo que é um membro de Read.
			read "True" || False  //True
			read "5"			  //Erro
			com anotação de tipo explícita, read "5" :: Int 	//5
	-> Enum : para tipos sequencialmente ordenáveis.	['a'..'e']  //"abcde"
	-> Bounded : para membros com truncamento superior ou inferior.		ghci> minBound :: Int	//-2147483648
	-> Num : para membros que podem agir como números.
	-> Integral : para apenas Int e Integer. Números integrais.
	-> Floating : para apenas Float e Double.
	
#Sintaxe em funções
####Casamento de padrões####
-> Pattern Matching consiste em especificar padrões cujos dados devem estar em conformidade e se estiverem, descontrui-los de acordo com estes padrões.
-> Quando definindo uma função, você pode definir corpos de funções separados para diferentes padrões. Isto torna o código limpo, simples e legível.
-> Você pode casar padrão em qualquer tipo de dados - números, caracteres, lista, tuplas.
		.ex1	lucky :: (Integral a) => a -> String  
				lucky 7 = "LUCKY NUMBER SEVEN!"  
				lucky x = "Sorry, you're out of luck, pal!"
		-> Se o número não for 7, não casa com o primeiro, pula pro próximo padrão e casa com certeza.
				
-> Os padrões serão checados de cima para baixo e quando entrar em conformidade com algum padrão, o corpo de função correspondente é usado.
		.ex2	sayMe :: (Integral a) => a -> String  
				sayMe 1 = "One!"  
				sayMe 2 = "Two!"  
				sayMe 3 = "Three!"  
				sayMe 4 = "Four!"  
				sayMe 5 = "Five!"  
				sayMe x = "Not between 1 and 5"
		-> Note que o padrão mais geral sempre deve vir por ultimo, caso contrario iria casar com todos os números sempre.
-> Podemos definir um função recursivamente e ainda com casamento de padrão.
		.ex3	factorial :: (Integral a) => a -> a  
				factorial 0 = 1  	
				factorial n = n * factorial (n - 1)  
		-> Note a importância de 'factorial 0 = 1' vir antes do geral. Caso contrário seriam multiplicados números negativos e ficaria em loop infinito.
		   Até estourar a pilha.
-> Especificar as mais específicas antes e mais gerais depois.
		.ex4 	charName :: Char -> String  
				charName 'a' = "Albert"  
				charName 'b' = "Broseph"  
				charName 'c' = "Cecil"
		-> Gera exceções para uma entrada não esperada. Em casamento de padrões, é importante cobrir todas as entradas possíveis (com padrões gerais).
-> Podemos usar casamento de padrões em tuplas:
		.ex5 	addVectors :: (Num a) => (a, a) -> (a, a) -> (a, a)  
				addVectors (x1, y1) (x2, y2) = (x1 + x2, y1 + y2)  
		-> Note que o único padrão que a função possui sempre casa com qualquer possibilidade.
		-> As funções "fst e snd" extraem as componentes das tuplas pares. "primeiro" e "segundo" elementos respectivamente.
-> Função para obter primeiro, segundo e terceiro elementos de uma tupla.
		.ex6	first :: (a, b, c) -> a  
				first (x, _, _) = x  
  
				second :: (a, b, c) -> b  
				second (_, y, _) = y  
  
				third :: (a, b, c) -> c  
				third (_, _, z) = z  
		-> O _ sempre casa, mas significa que não ligamos para o valor que vai casar.
-> Pode-se usar casamento de padrões em list comprehension.
		.ex7	[a+b | (a,b) <- [(1,3), (4,3), (2,4), (5,3), (5,6), (3,1)]]
		-> Se algum casamento de padrão falhar, ele apenas pula para o próximo elemento.
-> Você pode usar casamento de padrões em listas por si só. Com x:y:z:zs, isto apenas ira casar com listas que tem 3 elementos ou mais.
		.ex8	head' :: [a] -> a  
				head' [] = error "Can't call head on an empty list, dummy!"  
				head' (x:_) = x  
		-> casamento usando o operador : de listas.
		-> Note que (x:_) deve estar entre parêntesis para funcionar.
		-> Com error "string" , se o padrão casar em [] o programa crash e printa a String após error.
-> (x:y:_) "casa com qualquer lista de dois ou mais elementos"
-> Já fizemos uma função para calcular length de lista com "list comprehension", aqui vai uma usando pattern matching e recursão.
		.ex9	length* :: (Num b) => [a] -> b  
				length* [] = 0  
				length* (_:xs) = 1 + length' xs 
-> Existe algo chamado "patterns". Serve para quebrar uma estrutura de acordo com um padrão e ainda armazenar uma referência pro objeto por completo. 
		-> Formato =>	capital all@(x:y:xs)
						-capital = nome da função
						-all = nome que representa a lista
						-x = cabeça da lista
						-y = segundo elemento
						-xs = cauda
-> Não se pode usar ++ em casamento de padrões.
		
####Guardas####
-> Enquanto em casamento de padrões tem-se um modo de ter certeza que um valor está em conformidade com alguma forma e descontruí-lo, 
   guardas são um modo de testar se alguma propriedade de um valor (ou vários deles) é verdadeira ou falsa. Soa como um if, e realmente é 
   bem similar.
-> A diferença é que guardas são bem mais legíveis quando tem-se várias condições e eles se encaixam muito bem com padrões.
		.ex1	bmiTell :: (RealFloat a) => a -> String  
				bmiTell bmi  
					| bmi <= 18.5 = "You're underweight, you emo, you!"  
					| bmi <= 25.0 = "You're supposedly normal. Pffft, I bet you're ugly!"  
					| bmi <= 30.0 = "You're fat! Lose some weight, fatty!"  
					| otherwise   = "You're a whale, congratulations!"  
		-> Guardas são indicadas por '|' seguidas pelos nomes das funções e seus parâmetros. Geralmente são indentadas um pouco pra direita.
		-> É basicamente uma expressão booleana. Se ela for True, então o corpo de função correspondente é usado. Se for False, continua nas guards.
-> É exatamente vários if else mais legível.
-> Geralmente, a última guarda é 'otherwise'. É definida simplesmente como 'otherwise = True' e casa com tudo.
-> Isto é parecido com casamento de padrões, porém guardas checam por condições booleanas.
-> Se todas as guardas de uma função resultarem em False (e não colocarmos otherwise no final), passa-se para o outro padrão. Por isso que casamento de 
   padrões e guardas se dão tão bem. Se nenhuma guarda ou padrão é encontrado, um erro é lançado.
		.ex2	bmiTell :: (RealFloat a) => a -> a -> String  
					bmiTell weight height  
					| weight / height ^ 2 <= 18.5 = "You're underweight, you emo, you!"  
					| weight / height ^ 2 <= 25.0 = "You're supposedly normal. Pffft, I bet you're ugly!"  
					| weight / height ^ 2 <= 30.0 = "You're fat! Lose some weight, fatty!"  
					| otherwise                   = "You're a whale, congratulations!"  
		-> Note que não existe '=' após o nome da função e seus parâmetros, antes da primeira guarda.
		.ex3	max' :: (Ord a) => a -> a -> a  
				max' a b   
					| a > b     = a  
					| otherwise = b
		.ex4	myCompare :: (Ord a) => a -> a -> Ordering  
				a `myCompare` b  
					| a > b     = GT  
					| a == b    = EQ  
					| otherwise = LT 
		
####Where####
-> Repare como a função de calcular o IMC é repetitiva. 		
-> Desde que repetimos a mesma expressão 3 vezes, seria ideal se pudéssemos calcular apenas uma vez, ligar a um nome e então usar este nome em vez 
   da expressão.
		.ex1	bmiTell :: (RealFloat a) => a -> a -> String  
				bmiTell weight height  
					| bmi <= 18.5 = "You're underweight, you emo, you!"  
					| bmi <= 25.0 = "You're supposedly normal. Pffft, I bet you're ugly!"  
					| bmi <= 30.0 = "You're fat! Lose some weight, fatty!"  
					| otherwise   = "You're a whale, congratulations!"  
					where bmi = weight / height ^ 2
		-> O where fica identado junto com as guards, e então definimos vários nomes e funções.
		-> Estes nomes são visíveis através das guardas e nos dão a vantagem de não de não ter que repetir código.
		.ex2	bmiTell :: (RealFloat a) => a -> a -> String  
				bmiTell weight height  
					| bmi <= skinny = "You're underweight, you emo, you!"  
					| bmi <= normal = "You're supposedly normal. Pffft, I bet you're ugly!"  
					| bmi <= fat    = "You're fat! Lose some weight, fatty!"  
					| otherwise     = "You're a whale, congratulations!"  
					where bmi = weight / height ^ 2  
						  skinny = 18.5  
						  normal = 25.0  
						  fat = 30.0  
		-> Definimos cada estado de comparação. O código fica mais legível.
		-> Os nomes definidos no where são apenas visíveis para aquela função. 
		-> Os nomes não são compartilhados por padrões de funções. Se quer que vários padrões de uma mesma função compartilhem os mesmos nomes, você 
		   deve defini-lo globalmente.
-> Você também pode usar where para casamento de padrões! 
		.ex3	initials :: String -> String -> String  
				initials firstname lastname = [f] ++ ". " ++ [l] ++ "."  
					where (f:_) = firstname  
					(l:_) = lastname 
		.ex4	calcBmis :: (RealFloat a) => [(a, a)] -> [a]  
				calcBmis xs = [bmi w h | (w, h) <- xs]  
					where bmi weight height = weight / height ^ 2
			
		  -> Aqui temos uma junção de list comprehension e where!!!
	
####Let in####	
-> Muito similar ao where.
-> Lets permitem ligar-se a variáveis ​​em qualquer lugar e são eles próprios expressões, mas são muito locais, ficando no escopo das guardas.
-> Também podem ser usadas para casamento de padrões.
		.ex1	cylinder :: (RealFloat a) => a -> a -> a  
				cylinder r h = 
					let sideArea = 2 * pi * r * h  
						topArea = pi * r ^2  
					in  sideArea + 2 * topArea  
		-> let <bindings> in <expression>
		-> Os nomes que você declara dentro da parte 'let' são acessíveis à expressão depois do 'in'.
-> A diferença entre where e let..in é que lets são expressões por si só. Where é apenas construções sintáticas.
		.ex2	4 * (let a = 9 in a + 1) + 2 
		.ex3	[let square x = x * x in (square 5, square 3, square 2)]  
		.ex4	(let a = 100; b = 200; c = 300 in a*b*c, let foo="Hey "; bar = "there!" in foo ++ bar)  
				//(6000000,"Hey there!")  
		-> Podemos separá-los por ponto-e-virgula.
		.ex5	(let (a,b,c) = (1,2,3) in a+b+c) * 100  
		-> Como 'list comprehension'
		.ex6	calcBmis :: (RealFloat a) => [(a, a)] -> [a]  
				calcBmis xs = [bmi | (w, h) <- xs, let bmi = w / h ^ 2, bmi >= 25.0]
		-> Nós omitimos a parte in do let..in aqui porque quando usamos ele em 'list comprehension' a visibilidade dos nomes já está definida.
-> O problema do let..in é que ele não pode ser usado com guardas.

####Case####
-> Case são expressões como if else e let..in.
-> Não apenas obter valor das expressões baseados nos possíveis casos do valor de uma variável, podemos também usar em casamento de padrões.
-> Tomar uma variável, casar padrão com ela, dar valor a pedaços de código baseados neste valor...casamento de parâmetros em definições de funções!!
-> É um jeito açucarado para expressões case do C.
		.ex1	head' :: [a] -> a  
				head' xs = case xs of [] -> error "No head for empty lists!"  
								  (x:_) -> x 
		-> Note a setinha '->' para ligar um padrão numa consequencia.
-> case expression of pattern -> result  
					  pattern -> result  
					  pattern -> result  
					  ...  
	'expression' é casada com padrões.
-> Se passar por todas as opções runtime error.
-> Case pode ser usado em qualquer lugar.
		.ex2	describeList :: [a] -> String  
				describeList xs = "The list is " ++ case xs of [] -> "empty."  
                                                              [x] -> "a singleton list."   
                                                               xs -> "a longer list."  
															   