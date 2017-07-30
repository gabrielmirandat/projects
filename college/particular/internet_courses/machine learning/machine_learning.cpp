	m = nº de exemplos de treino
	n = nº de features
	x's = variáveis de entrada/características
	y's = variáveis de saída/ variável target
	(x,y) = um exemplo de treino
	(xi,yi) = um exemplo de treino específico (i-ésimo treino de exemplo)
	
	a:=b (atribuição) "a recebe o valor de b"
	a=b  (teste de verdade) "afirma que a tem o valor de b"
	
	a:=a+1 (a é incrementado de 1)
	a=a+1  (isso é uma mentira)


Aprendizado Supervisionado
	-Problema de regressão:
		Estamos tentando prever um valor de saída contínuo. (um preço de uma casa, qtd de itens vendidos dado uma base enorme)
		
	-Problema de classificação
		Estamos tentando prever um valor de saída discreto. (0 ou 1 (maligno ou benigno))
		
	*Quantidade de features usadas em consideração =  quantidade de eixos no problema.
	
	SVM - Suport Vector Machine
		Truque matemático que permite ao computador analisar uma qtd infinita de atributos.
		
Aprendizado Não-Supervisionado
	-Conjunto de dados com mesmo rótulo.
	-Sim, aqui há um monte de dados, mas não sabemos à que grupos eles pertencem.
	
	-Algoritmo de Agrupamento (clustering)
		Dado um conjunto sem classificação, o algoritmo consegue prever clusters e assim rotular os dados em grupos.
		
	*Problema da separação de audio da festa de coquetel
		[W,s,v] = svd((repmat(sum(x.*x,1),size(x,1),1).*x)*x') ==> SINGULAR VALUE DECOMPOSITION!!
		
	* Memória associativa das pessoas.
		
Tutores:
Colin Beckingham, Kevin Burnham, Maxim Haytovich, Tom Mosher, Richard Gayle, Simon Crase, Michael Reardon and Paul Mielke.

Definição Machine Learning informal : 'O campo de estudo que dá aos computadores a capacidade de aprender, sem ser explicitamente programados.'
Definição formal : 'Um programa de computador é dito para aprender com a experiência E com relação a alguma classe de tarefas T e medida de desempenho P, se '
				   'o seu desempenho em tarefas em T, medida pelo P, melhora com a experiência E.'
				   
				   Example: jogar xadrez.

					E = a experiência de jogar vários jogos de xadrez
					T = a tarefa de jogar xadrez
					P = a probabilidade que o programa vai ganhar o próximo jogo.

-> REGRESSÃO

-> REGRESSÃO LINEAR COM UMA VARIAVEL (regressão linear univariada)
	*DADO UM CONJUNTO DE VALORES DE X E Y NUMA TABELA, QUERO ACHAR A RETA QUE MAIS SE APROXIMA DA FUNÇÃO GERADA POR ESSES VALORES.
	*Prever um valor de saída simples para um valor de entrada simples.
	*Estamos fazendo aprendizado supervisionado = já temos ideia de causa/efeito entre entrada/saida.
	
	-> Função de hipótese: hθ(x)=θ0+θ1x
	é a função hθ que relaciona x com y(saída) pelos parâmetros escolhidos θ0 e θ1.
	
	-> Função de custo(Média dos erros ao quadrado): J(θ0,θ1)=(1/2m)*∑/*i=1->m*/(hθ(xi)−yi)2
	é a função que mede a acurácia da nossa função de hipótese.
	equivale a 1/2x¯ onde x¯ é a média dos quadrados de hθ(xi))−yi, ou a diferença entre o valor previsto e o valor real.
	
	ASSIM JÁ PODEMOS PREVER VALORES QUE NÃO TEMOS.
	
	-> Gradiente Descendente
	automaticamente melhora a função de hipótese.
	Imagine que plotamos nossas hipóteses com θ0 em x e θ1 em z com a função de custo em y. A plotagem será da função de custo.
	Sabemos que quanto mais no chão estiver a função, melhor nossa previsão. A maneira de fazermos isso é tomando a derivada da função.
	Como temos uma direção, tomamos passos para baixo na derivada por um parâmetro α, chamado 'taxa de aprendizagem'.
	A equação é 
															repeat until convergence:
															θj:=θj− [(α∂/∂θj)J(θ0,θ1)] sendo [] a inclinação da tangente (derivada)
															for j=0 and j=1
															
	-> Gradiente Descendente para regressão linear
															repeat until convergence: {
															θ0:= θ0−α(1/m)∑/*i=1->m*/(hθ(xi)−yi)
															θ1:= θ1−α(1/m)∑/*i=1->m*/((hθ(xi)−yi)xi)
															}
	'm'= tamanho do set de treinamento
	'θ0' = cte que mudara contantemente com  θ1
	'xi,yi'= valores do set de treinamento dado (dados).
	Note que θj foi dividido em dois casos e que estamos multiplicando xi em θ1 devido à derivada.
	
-------- LINEAR ALGEBRA REVIEW ---------
	-> multiplicação matricial : 3x2 com 2x1 resulta em 3x1(um vetor coluna)
	->	* Not commutative. A*B≠B*A
		* Associative. (A*B)*C=A*(B*C)
	-> Inversa de A : A^-1 = multiplicar pela inversa resulta na identidade.
	   Uma matriz não quadrada não tem inversa. (Pseudoinversa para as q n tem inversa).
	-> Transposta : rotacionar a matriz no sentido horário.
----------------------------------------
	
	-> função de custo
		-> Qdo só usamos θ1 : parábola 2d
		-> Qdo usamos θ0 e θ1 : arco 3d (mas representamos com curvas de nível)
			- Eixos θ0 e θ1, função J(θ0,θ1), cada elipse significa que J tem o mesmo valor.
			
	-> Método: gradiente descendente
		-> Objetivo: minimizar a função de custo J, porém pode minimizar qualquer função.
		- α = taxa de aprendizagem (controla tamanho do passo para onde descemos o morro na maior rapidez).

		*1º algoritmo de aprendizagem (algoritmo da regressão linear) mínimos quadrados??
			=> União das funções de custo com a função gradiente descendente. (ou gradiente descendente de pacote - já que é em todo o banco m) 
			=> Método da equação normal(não iterativo) ~ multiplicação matricial.
		
-------- PROPRIEDADES MATRIZES ---------
	-Não comutativas (não pode inverter ordem)
	-Associativas (não importa que termo é multiplicado primeiro)
	-MATRIZ INVERSA: (como nos numeros 3*(1/3) = 1)
		->A*(A^-1) = (A^-1)*A = I 
		-> Apenas matriz quadrada tem inversa
		-> Matriz sem inverso: matriz singular ou degenerada.
	-MATRIZ TRANSPOSTA: trocar linhas por colunas
		-> Bij = Aji
---------------------------------------

-> REGRESSÃO LINEAR COM VÁRIAS VARIÁVEIS (regressão linear multivariada)
	*xij = i-ésimo exemplo de treino na j-ésima feature.
	*hθ(x)=θ0 + θ1x1 + θ2x2 + θ3x3 + θnxn = transposto(θ)*x
	*x0 = 1 (apenas para convenção)
	
-> FAZER A REGRESSÃO CONVERGIR BEM E RÁPIDO
	- É importante deixar as features numa mesma escala para que as curvas de nível fiquem arredondadas e o algoritmo ache o mínimo local (q na verdade é global)
mais facilmente. Não precisa ser muito fechada, exatamente entre -1 e 1, mas só não é bom numa faixa muito distante, como -30 e 30. Não pode ser uma faixa muito 
menor que ou muito maior que -1 e 1, e deve ser proximo desses valores.
		-0.00001 <= x1 <= 0.000001 É RUIM
		     -30 <= x2 <= 30 é RUIM
			   0 <= x3 <= 3 é BOM
			   
		*Métodos
			1)Dividir todos os valores da feature pelo valor máximo que assume.
			2)Normalização pela Média
			
	*OBS* plotar gráfico de (número_iterações_grad_descendente) X (função_custo) e ver se está caindo a cada iteração.
	- Escolha da "taxa de aprendizagem" -α-  se através do gráfico a função estiver crescendo, deve-se então escolher um α menor.
											 se estiver descendo e subindo, também deve-se escolher um valor menor para α.
											 se alfa for muito pequeno, a convergencia pelo número de iterações vai demorar muito.
	
-> REGRESSÃO POLINOMIAL(quando uma reta não representa bem os dados)
		- Usar features ao quadrado ou ao cubo, ou raiz em cima da função hipótese.
		
	
	->equação normal
		- Outro algoritmo para obter regressão linear, diferente de gradiente descendente. 
		- Não iterativo, acha os θ analíticamente.
		- Derivar a função de custo e igualar a zero. => encontra o mínimo.
		- Dimensionamento de variáveis não é necessário aqui.
		
		Calculo MATLAB dos θ => pinv(X'*X)*X'*y
		
		scatter plot = gráfico de dispersão (aquele com bolinhas).
	
""códigos matlab interessantes""
	--> format long = variáveis mostrando mais casas decimais.
	--> format short = variáveis com casas menores (default)
	--> size = retorna as dimensões da matriz
	--> length = retorna o tamanho da maior dimensão da matriz
	--> pwd = diretório atual
	--> cd = trocar para um diretório
	--> who = mostra as variáveis que temos carregadas no matlab/octave
	--> whos = mostra variáveis com detalhes
	--> save hello.mat v; = salva a variável v do matlab num arquivo no HD chamado hello.mat
	--> save hello.txt v -ascii; = salva variável de forma que possamos lê-la
	--> magic(3) = retorna matriz 3x3 cujos linhas, colunas e diagonais possuem a mesma soma
	--> hold on; plota em cima da janela antiga (por cima)
	--> imagesc(A); = mostra a matriz como uma imagem
	--> imagesc(A),colorbar, colormap gray; = o de cima em tons de cinza
	--> addpath('nome_diretorio') = adiciona o seguinte diretorio para pesquisa por dados pelo matlab
	--> submit()
	
-> CLASSIFICAÇÃO
	- y E {0,1} - problema de classificação de classe binária
		- 0: classe negativa (tumor benigno) (evento não ocorre)
		- 1: classe positiva (tumor malígno) (evento ocorre)
	- y E {0, 1, 2, 3} - problema de classificação de múltiplas classes
	- Regressão linear em problema de classificação NÃO PRESTA!
	- y=1 (significa cruz no gráfico) y=0 (significa bolinha no gráfico)
	
-> REGRESSÃO LOGÍSTICA
	-> hipótese: interpretada como a chance (em porcentagem) de y ser 1.
	-> ou P(y=1|x;θ)
	
	->função custo para regressão logística
		-Queremos uma função convexa (com apenas um mínimo global, sem mínimos locais).
		-Isto não acontece já que a função de hipótese p/ regressão logística é não linear.
		-Derivada da estatística por máxima verossimilhança.
		
	-> A função gradiente descendente minimiza para tetha,mas em geral utilizam-se outras funções mais robustas.
	
-> CLASSIFICAÇÂO MULTI-CLASSE
	- Algoritmo de classificação um-contra-todos
	
**** GUIA MATLAB ****
Modo de especificar funções com o @(t)(costFunction(t,x,y ) ) . Este cria uma função , com o argumento t , que chama a sua costFunction (parâmetro theta 
reutilizável) . Este nos permite envolver o costFunction para uso com fminunc (usando o parâmetro ' GradObj' de options = optimset('GradObj','on','MaxIter',400).
	
-> OVERFITTING
	-Overfitting = não temos dados suficientes para levá-los a nos dar uma boa hipótese, então isso é chamado de sobreajuste.
	-Pode ocorrer quando há muitas features pra poucos exemplos de treino (relativo).
	-O problema do overfitting (sobreajuste das regressões lineares e logística) = performance ruim
	*Correção = reduzir features (manual ou automático) ou/e regularização.
	- quanto mais variável, mas fácil o overfitting.
	
-> REDES NEURAIS
	- As redes neurais é um modelo inspirado em como o cérebro funciona. É amplamente utilizado hoje em muitas aplicações: quando seu telefone interpreta e 
	entende seu comando de voz, é provável que uma rede neural está ajudando a entender o seu discurso; quando você trocar um cheque, as máquinas que lêem 
	automaticamente os dígitos também usam redes neurais.
	- Para hipóteses complexas não-lineares.
	- POLINÔMIOS DE TERCEIRA ORDEM = 3 termos multiplicados.
	- só termos quadráticos => (n^2)/2, sendo n o numero de features.
	- Não rola usar termos quadráticos, ou maiores, com muitas features e limite não-linear.
	- Redes neurais são para problemas não-lineares de muitas features.
	- Grupo de neurônios artificiais amarrados entre si. 
	-> DENDRITOS (CAMADA DE ENTRADA) -> CORPO CELULAR (CAMADA OCULTA) -> AXÔNIO (CAMADA DE SAÌDA).
	- aij - neurônio de ativação i (ou unidade i) na camada j. (ou valor de ativação).
	- As variáveis de entrada (x) podem ser pensadas como unidade de ativação 1. Os valores da camada 2 são unidades de ativação 2.
	
	método: forward propagation = calcular as ativações da entrada, camada oculta e da saída.
	
	A rede aprende das entradas os parametros θ(1). Que na verdade ela aprendeu e transformou em features melhores e mais consistentes, e então usa esses 
	melhores como entrada na regressão logística.
	
Regressão logística = linear
redes neurais = não-linear (consegue formar boundaries mais complexas)

Backpropagation  = tem o objetivo de aprender os parâmetros da rede neural.

#Para a função de minimização pronta com multiclasse, com (y == label_atual), criamos matriz de 1s onde y=label e 0s onde é diferente.
When training the classifier for class k ∈ {1, ..., K}, you will want a mdimensional vector of labels y, where yj ∈ 0, 1 indicates whether the j-th
training instance belongs to class k (yj = 1), or if it belongs to a different
class (yj = 0). You may find logical arrays helpful for this task.
	
-> COMO TREINAR REDES NEURAIS (OBTER OS PESOS)
	- Algoritmo BackPropagation
		k = numero de neurônios na camada de saída.
		- Os valores delta da retropropagação representa o quanto devemos alterar os pesos da rede neural a fim de afetar os valores intermediários z
		  e consequentemente a saída prevista pela rede e o custo total.
- Checagem de gradiente = para saber se o gradiente descendente está funcionando adequadamente.
- Inicialização aleatória dos pesos (Theta) = inicializar a rede neural com todos os thetas zero torna a rede irrelevante.
											  - Para contornar inicializamos com valores aleatórios próximos a zero entre -epslon e +epslon.
- A retro-propagação mostra a direção onde a função de custo é mínima.

Informally, given a particular hidden unit, one way to visualize what it computes is to find an input x that will cause it to activate (that is, to have an 
activation value (a(il)) close to 1)
		
AVALIAR/MELHORAR A PERFORMANCE(ACERTO) DO ALGORITMO DE APRENDIZAGEM

BIAS x VARIÂNCIA
- Má predição = problema de viés alto(subajuste) OU problema de alta variância(sobreajuste).
- Lembra-se que a regularização ajudava a diminuir o overfitting? Como ela interfere em viés alto ou variância alta?

DIAGNÓSTICO COMPLETO = LEARNING CURVES
CURVAS DE APRENDIZAGEM

SUBAJUSTE = mais conjunto de treino não adianta. Erro de treino e de validação cruzada altos e similares.
SOBREAJUSTE = mais conjunto de treino adianta. Erro de treino baixo (pouco maior que zero => subindo com m) e de validação cruzada alto (=> descendo com m).
			  vão se cruzar em um momento.
			  



					


	
	
	