//-- 44% Arquitetura OLAP.
OLAP'Online Analytical Processing'
	- capacidade para manipular e analisar um grande volume de dados sob múltiplas perspectivas
	- usadas pelos gestores em qualquer nível da organização
	  para lhes permitir análises comparativas que facilitem a sua tomada de decisões diárias
	- possui ferramentas classificadas em 5 tipos
		- ROLAP
		- MOLAP
		- HOLAP
		- DOLAP
		- WOLAP

	- OLAP fornece um método para acessar, visualizar, e analisar dados corporativos com alta flexibilidade e performance
	- OLAP apresenta informações para usuários via um modelo de dados natural e intuitivo
	- Usuários finais podem rapidamente analisar inúmeros cenários, gerar relatórios sob demanda, e descobrir tendências e fatos relevantes
	  independente do tamanho, complexidade, e fonte dos dados corporativos
	- OLAP é utilizado para integrar e disponibilizar informações gerenciais contidas em bases de dados operacionais, sistemas ERP e CRM, sistemas contábeis, e Data Warehouses

	- Modelo OLAP
		- Informação organizada em cubos que armazenam valores quantitativos ou medidas
		- As medidas são identificadas por duas ou mais categorias descritivas denominadas dimensões que formam a estrutura de um cubo
		- Uma dimensão pode ser qualquer visão do negócio que faça sentido para sua análise, como produto, departamento ou tempo

		- Este modelo de dados multidimensional simplifica para os usuários o processo de formular pesquisas ou "queries" complexas, 
		  criar relatórios, efetuar análises comparativas, e visualizar subconjuntos (slice) de maior interesse

		.ex
			- Um cubo contendo informações de vendas poderá ser composto pelas dimensões tempo, região, produto, cliente, cenário (orçado ou real) e medidas
			- Medidas típicas seriam valor de venda, unidades vendidas, custos, margem, etc

		- Dentro de cada dimensão os dados podem ser organizados em uma hierarquia que define diferentes níveis de detalhe
		- Dentro da dimensão tempo, você poderá ter uma hierarquia representando os níveis anos, meses, e dias
		- A dimensão região poderá ter os níveis país, região, estado e cidade
		- Assim, um usuário visualizando dados em um modelo OLAP irá navegar para cima (drill up) ou para baixo (drill down) 
		  entre níveis para visualizar informação com maior ou menor nível de detalhe sem a menor dificuldade

		- Operações no modelo OLAP
			- SLICE'selecionar dados de uma única dimensão'
			- DICE'extrai um subcubo da seleção de duas ou mais dimensões'
			- DRILL DOWN'examina dados com mais detalhe'
			- ROLL UP'combinação de células de uma ou mais dimensões para atingir um nível maior de generalização' 
			- PIVOT ou ROTATION'visualiza dados por uma nova perspectiva'

	- Aplicações em que OLAP é empregado
		- Finanças'Análise de L&P, Relatórios L&P, Orçamento'
		- Vendas'Análise de vendas (por região, produto, vendedor, etc.), Previsões'
		- Marketing'Análise de Preço/Volume, Lucratividade de Produto'
		- Recursos Humanos'Análise de Benefícios, Projeção de Salários, Análise de "Headcount"'
		- Manufatura'Gerência de Estoque, Cadeia de Fornecimento, Planejamento de Demanda'

	- Regras do OLAP por  E. F. Codd '12'
		- Conceito de visão multidimensional;
		- Transparência;
		- Acessibilidade;
		- Performance consistente de relatório;
		- Arquitetura cliente/servidor;
		- Dimensionamento genérico;
		- Tratamento dinâmico de matrizes esparsas;
		- Suporte a multiusuários;
		- Operações de cruzamento dimensional irrestritas;
		- Manipulação de dados intuitiva;
		- Relatórios flexíveis;
		- Níveis de dimensões e agregações ilimitados.

	- Regras adicionais por Gartner Group '9'
		- Dados Arrays múltiplos;
		- OLAP joins;
		- Ferramentas para gerenciar as bases de dados;
		- Armazenar objetos;
		- Seleção de subconjuntos;
		- Detalhe drill-down em nível de linha;
		- Suporte a dados locais;
		- Refresh incremental das bases de dados;
		- Interface SQL.


	- Sistemas OLAP e sistemas Data Mining são complementares
	- Sistemas OLAP podem ser usados com sistemas Data Warehouse
	- Sistemas OLAP fornecem uma visão multidimensional de dados, incluindo suporte a hierarquias, servindo como uma forma natural de analisar negócios e organizações.
	- OLAP é adequado para atividades como indexação de dados, alocação de custos, análises de séries temporais e análises “what-if”
	- OLAP possibilita a análise multidimensional para a descoberta de tendências e cenários, de forma a transformar dados de um Data Warehouse em informação estratégica
	- Não tem a capacidade de realizar inferências indutivas, processo que permite chegar a conclusões genéricas a partir de exemplos específicos
	- OLAP é para análise de dados complexos a partir do Data Warehouse. Auxilia o nível estratégico na tomada de decisão e na análise empresarial.
	- OLTP são sistemas que registram as transações de uma operação organizacional. Visa a execução operacional do negócio



//-- 18% Data Mining.
Data Mining
	- Data Mining é o processo de explorar grandes quantidades de dados à procura de padrões consistentes, como regras de associação ou sequências temporais, 
	  para detectar relacionamentos sistemáticos entre variáveis, detectando assim novos subconjuntos de dados.
	- Data Mining é o uso da tecnologia da informação para descobrir regras, identificar fatores e tendências-chave, descobrir padrões e relacionamentos ocultos em 
	  grandes bancos de dados para auxiliar a tomada de decisões sobre estratégia e vantagens competitivas

	- O conhecimento pode ser apresentado de diversas formas
		- Agrupamentos
		- Hipóteses
		- Regras 
		- Árvores de decisão
		- Grafos 
		- Dendrogramas

	- Se fizermos estatística ao final do dia para repor estoques e detectar tendências de compra, estaremos praticando 'business intelligence (BI)'
	- Se analisarmos os dados com estatística de modo mais refinado, à procura de padrões de vinculações entre as variáveis registradas, fazemos 'mineração de dados'

	- Objetivo é conhecer melhor os clientes, seus padrões de consumo e motivações.

	- Através da MD 
		- Esses dados agora podem agregar valor às decisões da empresa, 
		- Sugerir tendências, 
		- Desvendar particularidades dela e de seu meio ambiente 
		- E permitir ações melhor informadas aos seus gestores

	- BI busca subsidiar a empresa com conhecimento novo e útil acerca do seu meio ambiente e funciona no plano estratégico.
	- MD visa obter a partir dos dados operativos brutos, informação útil para subsidiar a tomada de decisão nos escalões médios e altos da empresa e funciona no plano táctico

	
	- DM deve ocorrer a partir de uma fonte de dados limpa e consistente (pouco ruído) como os repositórios organizados (Data Warehouses e Data Marts)

	- Informações obtidas da DM
		- Associações'ocorrências ligadas a um único evento'
		- Sequências'eventos estão ligados ao longo do tempo'
		- Classificação'reconhece modelos que descrevem o grupo ao qual o item pertence por meio do exame dos itens já classificados' 
		- Aglomeração'semelhante a classificação quando ainda não foram definidos grupos'
		- Prognósticos'partem de uma série de valores existentes para prever quais serão os outros valores'

	- Técnicas da DM
		- Profiling
			- processo de construção e aplicação de perfis de usuários gerados pela análise de dados computadorizada
			- descoberta de padrões ou correlações em grandes quantidades de dados para identificar ou representar pessoas
		- Regras de associação
			- identificar grupos que apresentam coocorrência entre si, como uma cesta de compras.
			- compreende a busca por itens que frequentemente ocorrem de forma simultânea em uma quantidade mínima de transações do conjunto de dados
		- Regressão ou Predição
			- aprendizado de uma função que pode ser usada para mapear os valores associados aos dados em um ou mais valores reais
			- similar à tarefa de Classificação, com a diferença de que o atributo alvo assume valores numéricos
			- Regressão linear
				- busca encontrar a melhor linha de ajustamento para duas variáveis
				- objetiva fornecer uma 'previsão de certos dados' de acordo com uma 'série histórica'
			- Regressão múltipla 
				- é uma' extensão da regressão linear'
				- onde duas ou mais variáveis são envolvidas e os dados são combinados numa superfície multidimensional
		- Classificação
			- aprendizado de uma função que pode ser usada para 'mapear dados em uma de várias classes' discretas 'definidas previamente'
		
	- Sistemas Data Mining e sistemas OLAP são complementares
	- Tem a capacidade de realizar inferências indutivas, processo que permite chegar a conclusões genéricas a partir de exemplos específicos
	- Podem ajudar a detectar tendências, encontrar padrões e relações entre as informações disponíveis em bancos de dados
	- Podem encontrar informações ocultas nos dados disponíveis, mas é o gestor quem deve atribuir o valor de cada uma dessas descobertas para a organização.

