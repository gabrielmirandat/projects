//-- 14% Data Warehouse. 

- DW 
	- conjunto de ferramentas e técnicas de projeto
	- armazena dados atuais e históricos de vários sistemas
	1- aconselhado para custo/benefício armazenar informações de caráter 'histórico' e 'estatístico'
	- orientados por assunto, integrados, variáveis com o tempo e não voláteis
	- dados tem natureza estática, sem atualização contínua
	- auxilia na tomada de decisão
	- estrutura de dados usa modelagem multidimensional
	- para BI 'informação acessível mais facilmente, consistente, adaptado a mudanças e informação temporal'

	- Resolução de identidades (limpeza antes de carregar no DW)
		- 'Redução/eliminação de duplicados' identificação de múltiplas representações da mesma entidade num conjunto de dados e eliminação de todas essas, exceto uma
		
		1- 'Merge/purge' similar ao anterior mas que envolve a agregação de vários conjuntos de dados seguida de eliminação de duplicados
		
		- 'Householding' resolução de um conjunto de características associadas a conjuntos de dados que mapeiam com uma entidade de ordem mais elevada. 

	1- Agregações SQL/DW 
		- 'HAVING' restringe os resultados do GROUP BY.
		- 'GROUP BY' ROLLUP, CUBE e GROUPING SETS são extensões para esta cláusula 
		- 'AVG' média dos valores de uma coluna.
		- 'GROUPING SETS' extensão da cláusula GROUP BY e pode gerar um conjunto de resultados equivalente ao gerado por um UNION ALL
		- 'ORDER BY' especifica uma coluna ou expressão na qual o conjunto de resultados da consulta deve ser classificado

	- características

		- orientação por assunto 'informações sobre temas específicos importantes para o negócio da empresa'
			- produtos, atividades, contas, clientes

		- integração 'consistência de nomes, das unidades, das variáveis'
			- estado uniforme, sexo no DW só pode ser H/M, e não M/F e outros
			- há uma conversão de dados ao armazenar no DW

		- variação no tempo 'registro refere-se a algum momento específico, significando que ele não é atualizável'
			- dado de produção é atualizado com mudanças de estado do objeto em questão refletindo seu estado no acesso
			- a cada ocorrência de uma mudança, uma nova entrada é criada para marcar esta mudança

		- não-volatilidade 'permite apenas a carga inicial dos dados e consultas a estes dados'
			- dados carregados em blocos
			- no ambiente operacional existem atualizações 
				- rollback, recuperação de falhas, commits e bloqueios

		- granularidade 'nível de sumarização dos elementos e de detalhe disponíveis nos dados'
			- mais importante aspecto
			- nível muito alto necessita pouco espaço e índices no disco
			- afeta diretamente o volume de dados armazenado no DW e o tipo de consulta que pode ser respondida

		- credibilidade dos dados

	- tipos 
		
		- Data Warehouse Empresarial (EDW) 'coleção enorme de dados'
			- usado para decisões de médio a longo prazo
			- DW de larga escala usado por toda a organização
			- congrega informações de diversas fontes de dados

		1- Data Mart (DM) 'coleção menor de dados'
			- dados de um assunto ou departamento 'específico' extraídos do DW
			- público mais focado
			- subconjunto de um armazém de dados
			- subconjunto do EDW por tamanho (podendo ser geografia, linha de produtos, área funcional)
			- deve ser especializado, volátil, integrado, variável
			- mais frequente modificado (diferente do DW)

			- 'dependente' subconjunto criado diretamente a partir do armazém de dados, dados consistentes, qualidade
				- mesma versão dos dados para todos os usuários
				- para grandes empresas
			- 'independente' pequeno armazém concebido para uma unidade estratégica de negócios ou um departamento
				- não vem de EDW
		
		1- Armazenamento de Dados Operacionais (ODS) 'de prazo mais curto'
			- 'DDS (Dynamic Data Storage)' os dados não são voláteis, mas se granularidade compatível pode ser considerado 'ODS'
			- Staging Area
			- combina bases de dados de toda a empresa
			- processo bem definido para a criação e manutenção
			- subconjunto do EDW por tempo (dados da semana apenas)
			- conteúdo é atualizado durante todo o curso das operações de negócios (diferente do DW)
			- usado para decisões de curto prazo envolvendo aplicações de missão crítica
			- armazena apenas informações mais recentes (diferente do DW)

	- processos
		- 'Fontes de dados' dados vêm de vários sistemas independentes "legados" e provedores externos
			- dados também podem vir de 'OLTP' ou 'ERP' ou logs da 'Web'
		
		- 'Extração e transformação de dados' usando ferramentas de 'ETL'
		
		- 'Carregamento dos dados' dados transformados e limpos na área de preparação; daqui prontos para irem ao 'DW' ou 'DM'
		
		- 'Banco de dados abrangente' 'EDW' para apoiar todas as análises de suporte à decisão
			- visão resumida relevante e informações detalhadas proveniente de fontes diferentes
		
		- 'Metadados' metadados avaliados por diferentes pessoas e usuários de TI
			- incluem programas sobre os dados e regras para organizar resumos dos dados para facilitar indexar e pesquisar
		
		- 'Ferramentas de middleware' habilitam o acesso ao 'DW'
			- analistas de BI podem escrever as próprias consultas SQL
			- outros podem usar um gerenciador de consultas 'Business Objects'

	- arquitetura
		- 3 partes do DW
			- próprio DW 'contém dados e software associados'
			- software de aquisição de dados (backend) 'extrai dados de sistemas legados e fontes externas, os consolida e resume, e depois os carrega'
			- software cliente (frontend) 'permite aos usuários acessar e analisar dados a partir do DW'

		- 4 componentes do ambiente de DW/BI
			- (1) sistemas operacionais de origem 
			- (2) sistema de ETL
			- (3) área de apresentação de dados
			- (4) aplicações de BI

		- camadas
			- 'camada 1' composto de (1) e (2) - sistema operacional com os dados e o software para aquisição
			- 'camada 2' composto de (3) - é o DW
			- 'camada 3' composto de (4) - é o servidor de aplicação e cliente

		- arquiteturas
			- Data Marts (DM) independentes 'DM independente visando atender unidades organizacionais individuais'
				- mais simples e menos onerosa
				- independência pode causar dados inconsistentes, diferentes dimensões e medidas, dificultando análise por 'DM'

			- Arquitetura de barramento de Data Mart (KIMBALL) 'liga DMs individuais entre si por meio de middleware.'
				- alternativa viável para os data marts independentes
				- melhor chance de manter a consistência entre os dados de toda a empresa (pelo menos metadados)
				- mesmo que permita consultas complexas de diversos DMs, desempenho não satisfatório

			- Hub-and-spoke (Inmon) 'data warehouse centralizado e vários data marts dependentes (um para cada unidade organizacional)'
				- arquitetura de DW mais famosa
				- infraestrutura escalável e sustentável (desenvolvida iterativamente)
				- customização fácil de interfaces de usuário e relatórios
				- pode levar a redundância e a latência de dados (tempo máximo permitido para disponibilização dos dados)

			- Data warehouse centralizado 'similar a hub-and-spoke sem DMs dependentes, mas um DW da empresa inteira que serve todas as unidades'
				- fornece acesso a todos os dados no DW e não limitados a DM
				- simplifica o gerenciamento e administração de dados
				- visão oportuna e holística da empresa

			- Armazém de dados federado 'integração de sistemas distintos'
				- usa todos os meios possíveis para integrar recursos analíticos de várias fontes para atender evolução das necessidades e condições do negócio
				- estruturas estáticas/fixas e dados cedidos a partir dessas fontes conforme necessário
				- ferramentas baseadas em XML que oferecem visão global das fontes de dados distribuídas (armazéns de DM, sites, documentos e sistemas operacionais)
				- especialistas concordam que devem trabalhar de forma complementar aos DW, e não os substituir
			

	- Ralph Kimball x Bill Inmon
		
		- 'Ralph Kimball - Data Warehouse Bus Architeture'
				- DW 'bottom-up' estilo mais simples e incremental
			- 'DW' deve ser dividido para depois ser conquistado
			-  mais viável é desenvolver vários 'DMs' para posteriormente integrá-los e chegar ao 'EDW'
			- 'DMs' devem ser orientados por assuntos, gerando pontos de conexão como tabelas Fato e Dimensões em conformidade
			- permitindo informações íntegras e seguras entre 'DMs'
			- criador do 'star-schema'

		- 'Bill Inmon'
			- DW 'top-down' grande depósito central de informações 
			- primeiro um 'DW' modelando toda a empresa e depois partir aos 'DMs' por assuntos ou departamentos
			- partida são os CIF (Corporate Information Factory), infraestrutura para os dados
			- ODS (Operational Data Store) opcionais, sendo que ajuda a reduzir a complexidade de construção do 'DW'
			- pai do conceito de 'DW'

	- Modelagem multidimensional
		- técnica de modelagem do banco para auxiliar consultas em DW em diferentes perspectivas
		- permite melhor processamento para OLAP
		- possui tabelas 'Fatos' e tabelas 'Dimensões'
		- Dimensões são os descritores dos dados oriundos das tabelas Fato
		- Fato armazena as medições de desempenho de eventos dos processos de negócios da organização
		- Um Fato é uma linha, cada linha é um evento de medição, dados da linha tem nível de detalhe chamado grão
		- Dimensões é 1,n de Fatos
		- Linha da Fato é 1,1 com evento de medição
		
		- Fatos
			- é 'quantitativa'
			- são extraídas 'métricas' cruzadas com os dados das Dimensões
			- categorias de medidas numéricas
				- 'aditivos' podem ser agrupadas com qualquer das dimensões, fatos mais flexíveis e úteis
				- 'semi-aditivos' agrupadas em algumas dimensões, saldos de conta são aditivos/agrupados em todas as dimensões menos no tempo
				- 'não-aditivos' preços unitários/índices, não podem ser adicionados
			- valores nulos ficam em tabelas fatos, sendo que funções de agregação (SUM, COUNT, MIN, MAX e AVG) tratam fatos nulos
			- os valores nulos devem ser evitados em chaves estrangeiras da tabela de fatos e em vez disso usar uma linha padrão que representa a condição não aplicável

			- tipos
				- 'de transações (Transaction Fact Tables)' linha é um evento de medição em um ponto no espaço e no tempo
					"nota fiscal"
					- são as tabelas mais expressivas e dimensionais
					- permite o máximo de operações de slice and dice sobre os dados
					- podem ser densas ou esparsas, só existem linhas se as medições acontecem
					- sempre contêm uma chave estrangeira para cada dimensão associada
					- contêm carimbos (stamps) de hora precisos e as chaves de dimensões degeneradas

				- 'de snapshot periódicos' linha resume muitos eventos de medição que ocorrem ao longo de um período normal (dia, uma semana ou um mês)
					"vendas no dia"
					- granularidade é o período
					- são uniformemente densas em suas chaves estrangeiras, uma linha mesmo vazia é sempre inserida

				- 'de snapshot acumulativos'
					"valor/gasto realizado"
					- resume os eventos que ocorrem em etapas de medição previsíveis entre o início e o fim de um processo
					- existe uma chave estrangeira data para cada etapa crítica no processo
					- deve conter chaves estrangeiras para outras dimensões e conter dimensões degeneradas

			- 'tabelas fatos sem fatos' apenas registra um conjunto de entidades dimensionais que se juntam em um momento no tempo
				"um aluno assiste a uma aula em um determinado dia"
				- não tem um fato numérico associado, mas uma linha fato com chaves estrangeiras para o dia de calendário, estudante, professor, localização e classe
				- analisar o que não aconteceu
				- captura alguns relacionamentos muitos-para-muitos entre as chaves de dimensões
				- usada para representar eventos ou prover informação de cobertura que não aparece em outras tabelas de fatos.

			- 'dimensão degenerada' chave de dimensão (número de uma transação, número de fatura, de ticket) sem nenhum atributo associado
				- não se constitui com uma tabela de dimensão

			- 'dimensão multivalorada' ocasionalmente, é válido conectar um registro de fato a uma dimensão representando um número aberto de valores
				- número de diagnósticos simultâneos no mesmo tratamento

			- duas ou mais chaves estrangeiras que ligam para as chaves primárias das tabelas de dimensão
			- corresponde a um evento de medição (fato)
			- contém as medidas numéricas produzidas por um evento de medição operacional no mundo real
			- sempre contém chaves estrangeiras para cada uma das suas dimensões associadas
			- contém chaves de dimensão degenerados opcionais
		
		- Dimensão
			- é 'descritiva'
			- 'qualifica' informações da tabela Fato
			- tem uma única coluna de chave primária que é incorporada como uma chave estrangeira em qualquer tabela de fatos
			- são grandes, desnormalizadas, com muitos atributos de texto de baixa cardinalidade
			- com uma coluna que funciona como uma chave primária única
			- sistema de DW/BI precisa reivindicar o controle das chaves primárias de todas as dimensões
			- 'chaves artificiais' chaves primárias inteiras (numéricas) anônimas para cada dimensão
			- dimensão 'data' é isenta da regra fundamental da chave substituta, pode usar uma chave primária mais significativa
			- um número de funcionário (chave natural) pode ser alterado se o empregado se demite e depois é recontratado
			- uma nova 'chave durável' deve ser criada que seja persistente e não se altere nesta situação
			- devem ser inteiros simples atribuídos em sequência começando de um
			- enquanto várias 'chaves de substituição' podem ser associadas com um funcionário ao longo do tempo a 'chave durável' nunca muda
			- designers de modelos dimensionais devem resistir à 'normalização'
			- nulos em atributos de dimensão devem ser evitados
			- dimensões 'calendário' ou 'data' estão ligadas a praticamente todas as tabelas de fatos
			- 'papéis' dimensões separadas com nomes exclusivos de colunas de atributo
			- 'dimensão junk' opção em vez de criar dimensões diferentes, dimensão de perfil de transação em um esquema
				- deve conter apenas a combinação de valores que ocorrem realmente nos dados de origem
			- 'floco de neve' estrutura característica com vários níveis
				- ocorre quando tabela de dimensão é normalizada
				- atributos de baixa cardinalidade aparecem como tabelas secundárias ligadas à tabela de dimensão base, por uma chave de atributo
				- deve-se evitá-lo por ser difícil para os usuários de negócios compreenderem
				- podem tornar consulta mais lenta
			- 'dimensão Snowflaked' tabela de dimensão desnormalizada
			- 'dimensões outrigger' dimensão secundária, quando uma dimensão pode conter uma referência para outra tabela dimensão
				- devem ser usadas com moderação
				- na maior parte, as correlações entre as dimensões devem ser rebaixadas para uma tabela fato
			- contém o contexto textual associado a um evento de medição dos processos de negócios
			- contêm os atributos descritivos usados pelas aplicações de BI para filtrar e agrupar os fatos
			- observações numéricas continuamente valorizadas são quase sempre medidas da tabela fato
			- observações numéricas discretas e extraídas de uma lista pequena, quase sempre são atributos de dimensão

		- Esquemas
			
			2- Star Schema '4 dimensões para um fato, sendo uma delas DESNORMALIZADA'
				- Dimensões são 'ligadas diretamente' a tabela Fato
				- tabela Fato armazena os 'indicadores' que serão analisados e as 'chaves' que caracterizam a transação
				- tabela Dimensão registra uma 'entidade' que caracteriza a transação e os seus 'atributos'
				- processo de negócio = 'uma tabela fato com medições numéricas do evento' + 'conjunto de tabelas dimensão com contexto do evento'
				- é modelo relacional: mais fácil de navegar, menos suscetível a erros, desempenho, eficiente, facilmente extensíveis
			
			- Snowflake '7 dimensões para um fato, sendo 5 delas NORMALIZADAS'
			
			- Multiestrela '2 dimensões para uma fato, 2 para outra fato, duas dimensões CONFORME para ambas as fato'

		- Processo
			
			- 1.Selecionando o processo de negócio 'decidir o negócio para o modelo combinando a compreensão dos requisitos com a análise dos dados de origem disponíveis'
				- viabilidade inclui disponibilidade, qualidade dos dados e capacidade organizacional
			
			- 2.Declare a granularidade 'estabelece exatamente o que uma única linha da tabela fato representa'
				- cada proposta de granularidade da tabela fato resulta em uma tabela física separada
				- um sistema de DW/BI exige quase sempre os dados expressos no mais baixo possível de granularidade
			
			- 3.Identificando as dimensões 'a declaração da granularidade determina a dimensão primária da tabela fato'
				- após adiciona-se mais dimensões para a tabela fato que tenham apenas um valor para cada combinação das dimensões principais
				- o número do bilhete da transação é incluído como uma dimensão especial chamada dimensão degenerada para números de transação
				- aparece apenas como uma das colunas da tabela fato
			
			- 4.Identificando os fatos 'determinação dos fatos que aparecerão na tabela fato'
				- dados coletados incluem a quantidade de vendas por unidade regular, o desconto, preços líquidos pagos, valores de vendas em dólares
 

//-- 44% Arquitetura OLAP.

- OLAP 'On-Line Analitical Processing'
	- modelo relacional 'dados em tabelas'
	- OLAP 'arrays multidimensionais'
	- processamento de dados para 'suporte a decisão' via visualização de dados agregados em várias dimensões do modelo de dados dimensional 
			(tempo, espaço, categoria de produto, quantidade vendida, preço)
	- dados em BDs especializados com modelo lógico de dados multidimensional
			(Data Warehouse, Data Mart ou BD multidimensionais)
	- dados hierarquicos em níveis de granularidade
	- manipular/analisar grandes volumes sob múltiplas perspectivas
	- software que permite interagir com grande banco online (Data Warehouse) e 'solicitar/receber qualquer relatório' no formato desejado
	- possibilitam a análise multidimensional para a 'descoberta de tendências e cenários', de forma a transformar dados de um Data Warehouse em 'informação estratégica'

1. OLAP x OLTP
	- OLAP 'On-Line Analytical Processing' é muito diferente de OLTP 'OnLine Transaction Processing'
	- 'OLTP'
		- foco nas transações individuais
		- só mantém o controle dos dados mais atual
		- detalhes sobre dados individuais não são armazenados para análise
		- informações armazenadas em banco de dados relacional normalizado
		- otimizado para recuperação/atualização de pequena quantidade de tuplas
		- operação típica é atualização, telas imutáveis, nível de dados atomizado, recuperação de poucos registros, orientado a registros, modelagem de processo, 
				permite atualizações contínuas
		- acesso em tempo-real, beaseado em transação, dados em mais de uma tabela, otimizados para velocidade, operações de inserir, atualizar e excluir
		- usados para consultas simples
		- usados por sistemas 'LOB' Line-of-Business e 'ERP' Enterprise-Resource-Planning
		- gerenciado pela ferramenta Microsoft 'SSMS' Server Management Studio
		- segue regras de normalização e usa bancos de dados relacional
		- usa menos índices e mais junção
		- faz consulta de várias tabelas 
		- nível operacinal da organização, visa a execução operacional do negócio
	- 'OLAP'
		- mantém o controle de cada registro individual, como informações específicas e informações sobre o banco de dados multidimensional
		- em geral não apaga nem atualiza os dados, apenas adições periódicas
		- otimizado para recuperar/sumarizar grandes quantidades de dados
		- operação típica é a análise, telas definidas pelo usuário, nível de dados altamente sumarizado, recuperação de muitos registros, orientado a arrays, modelagem de assunto,
				dados históricos, sumarizados e integrados
		- uso de dados online ou históricos
		- usado para análise e navegação sobre os dados
		- dados em mais de uma tabela
		- otimizado para desempenho analítico dos dados
		- banco de dados apenas de leitura
		- usados para consultas complexas
		- bancos analíticos, usado por sistemas Cognos e Business Objects
		- gerenciado pela ferramenta Microsoft 'SSAS' Server Analysis Services
		- relaxa regras de normalização
		- utiliza banco de dados relacional ou multidimensional
		- usa mais índices e menos junção
		- consulta executada em menos tabelas
		- nível estratégico da organização, visa a análise empresarial e tomada de decisão

2. Operações OLAP
	- aplicadas nos cubos ou Data Warehouse
	- granularidade 'nível de detalhe/resumo, quanto mais granularidade, menor o detalhe'
		- afeta o volume de dados no DW e a resposta
	- OLAP oferece cálculo para desvio padrão, variância, processamento de medidas em múltiplas dimensões
	- OLAP oferece sumarizações, agregações e hierarquias em cada granularidade e cruzamento de dimensões
	- OLAP suporta previsão, análise de tendências e análise estatística

	- 1.Drill-up/roll-up 'aumenta granularidade reduzindo detalhe'
		- aplica uma agregação sobre o cubo de dados
		- sobe na hierarquia, dados mais agrupados ou sumarizados
		- ex. se dimensão X é street < city < province_or_state < country vai de city para country
	
	- 2.Drill-down 'inverso do roll-up, diminui granularidade aumentando detalhe'
		- navega de um dado com menor detalhe para maior detalhe
		- pode descer em uma hierarquia de uma dimensão OU introduzir dimensões adicionais
		- ex. se dimensão Y é day < month < quater < year vai de quater para month

	- 3.Slice and dice 'slice seleciona uma dimensão do cubo e dice seleciona duas ou mais dimensões'
		- 'FCC' slice corta o cubo 'MANTEM PERSPECTIVA DA VISÃO', redução do escopo dos dados em análise
		- 'FCC' dice extrai um subcubo 'MUDA PERSPECTIVA DA VISÃO', mudança de ordem das dimensões e consequentemente da orientação
		-  trocar 'linhas por colunas' de maneira a facilitar a compreensão dos usuários e 'girar o cubo sempre que tiver necessidade'
		- ex. slice seleciona as vendas por cidade em um determinado semestre (quarter = Q1)
		- ex. um dice que envolve três dimensões seria (location = “Toronto” ou “Vancouver” || time = “Q1” ou “Q2” || item = “home entertainment” ou “computer”)
	
	- 4.Pivot 'rotaciona os eixos do cubo provendo uma visão alternativa dos dados'
		- 'FCC' adicionar ou rearranjar as dimensões das tabelas
		- rotações podem ser feitas em uma ou mais dimensões

	- 5. Rotação 'permite visualizar dados de uma nova perspectiva'

	'within->across->through'
	- 6.Drill-within 'MESMA DIMENSÃO - CATEGORIA DE PRODUTO -> SETOR DE PRODUTO'
		- 'FCC' pula de uma classificação para outra no mesmo nível na mesma dimensão!! "MESMA DIMENSÃO" 
		- passa de uma classificação para outra diferente na mesma dimensão
		- É possível pois numa dimensão é possível que exista diferentes classificações
		- ex. produto pode ter uma classificação grupo de produto que pode ser dividido em categorias e essas por sua vez divididas em setores

	- 7.Drill-across 'MESMA DIMENSÃO - TEMPO PULA PRA DIA'
		- 'FCC' pula de um nível intermediário para outro na mesma dimensão!! "MESMA DIMENSÃO"
		- consulta com mais de uma tabela em dois cubos com pelo menos uma dimensão em comum
		- ex. se dimensão tempo é composta por ano, semestre, trimestre, mês e dia, passa de ano direto para trimestre ou mês
		- 'Kimball' consulta envolvendo mais de uma tabela exigindo que dois cubos tenham pelo menos uma das dimensões em comum
		- ex. se livraria com duas formas de venda, física ou internet, temos um cubo pra cada, combina dados nas dimensões comuns soma e obtem resultado
		- 'Outro' significa mudar de uma classificação em uma dimensão para outra em uma dimensão diferente
		- 'Outro' similar ao drill-down com diferença que é feito horizontalmente e não verticalmente
		- ex. depois de exibir o resultado das vendas anuais, drill-across exibe as vendas em cada mês
		
	- 8.Drill-through 'MUDA A DIMENSÃO - TEMPO -> REGIÃO'
		- 'FCC' pula de uma informação para outra em outra dimensão!! "DIMENSÕES DIFERENTES" 
		- penetra na hierarquia para ver mais detalhes chegando a consultar bases de dados
		1- ex. inicia na dimensão do tempo e no próximo passo analisa a informação por região
		- usa SQL para penetrar até as tabelas relacionais de back-end
		- visa o entendimento dos registros que derivaram o cubo
		- usado para determinar a razão de um ponto fora da curva no cubo
		- permite exibir detalhes dos dados não sumarizados a partir de células do banco sumarizadas
		- permite acesso aos dados que não estão no servidor OLAP provenientes do DW ou bases transacionais
		- permite transição suave de uma base multidimensional e agregada para o nível de detalhamento de registro nas fontes de dados do repositório de DW
		- mergulhar na hierarquia para observar dados com mais detalhes chegando a consultar bases de dados transacionais que deram origem aos dados do DW

	- 9.Rank 'ordena membros de uma dimensão de acordo com algum critério'
		- cria ranking dos n maiores/menores itens em uma lista, podendo calcular médias móveis, crescimento dos índices, taxa de retorno, depreciação, estatística
		- resultados em tabela cruzada

	- 10.Nest-unnest 'redução das dimensões'

	- 11.Slipt 'planificação das faces do cubo'

	- 12.Push/Pull 'junção de valores'

	- 13.Push/Pull 'junção de valores'

	- 14.Cross-join 'dados são unidos e colunas e linhas são invertidas, permitindo uma melhor visualização sob a ótica do negócio'

3. Taxonomias de servidores OLAP
	- arquitetura física e implementação de servidores OLAP
	
	- dados são copiados das fontes para dentro do servidor OLAP, onde são organizados e preparados para consultas rápidas
		- Fontes de dados 'fontes que provem dados para serem analisados podendo ser um DW, BD legado, coleção de spreadsheets ou combinação de todos'
			- OLAP deve ser capaz de trabalhar com várias fontes diferentes
		- Servidor OLAP 'back-end do sistema OLAP'
			- faz todo o processamento e é onde os dados são efetivamente acessados e armazenados
			- pode usar um banco de dados multidimensional ou um banco de dados relacional
		- Clientes OLAP 'fornecem aplicações de mineração de dados e/ou geração de resultados'

	- categorias de servidores OLAP
		- ROLAP 'baseado em bases de dados relacionais RDBs'
			- dados de origem inseridos em um banco de dados relacional com esquema estrela ou floco de neve tornando a recuperação rápida
			- fornece modelo multidimensional dos dados por meio de consultas SQL otimizadas
			- são bem estabelecidos e abertos a otimizações sendo que suporta mais dados que o MDDB
			- intermediário entre base de dados relacional de back-end e ferramentas de front-end
			- usam SGBDs relacionais para gravar e gerenciar os dados do DW e middleware OLAP para suporte
			- o excesso de tabelas normalizadas pode comprometer a performance das buscas
			- modelo relacional tanto para desenhar o projeto físico do data warehouse quanto para data marts integrados
			- ideal para grande volume de dados com tecnologia otimizada e aprovada
			- SQL não é otimizado para queries complexas e determinar um esquema para armazenamento ótimo é mais importante e difícil
		
		- MOLAP 'usam um MDDB para armazenar dados'
			- são usados gerenciadores de banco de dados proprietários
			- armazenamento especiais e ferramentas para tratamento dimensional de dados
			- migração dos dados do SGBD relacional para multidimensional e a sua constante atualização
			- em tese apresenta melhor desempenho do que as alternativas relacionais
			- planilha multidimensional armazenando tanto as estruturas básicas quanto agregadas/cubos
			- explosão de dados
			- a manipulação de dados esparsos dinamicamente permite a analise do armazemento e aperfeiçoeamento para evitar a explosão de dados
			- matrizes esparsas, operações com array e indexações de bitmap
			- não oferece debug, paralelismo, log, otimizadores e monitoração
		
		- HOLAP 'abordagem de uso misto das estratégias ROLAP e MOLAP'
			- estruturas relacionais usadas para dados de menor granularidade e estruturas dimensionais nativas dedicadas aos dados de maior granularidade

		- DOLAP 'estruturas dimensionais ou relacionais são transferidas do DW/DM para as estações cliente'
			- objetivo de facilitar o desempenho de certas análises, minimizando o tráfego de informações entre o cliente e o servidor

		- WOLAP

4. 12 regras de avaliação OLAP
	- 1. Visão conceitual multidimensional 'facilita operações'
	- 2. Transparência 'incorporada em qualquer necessidade'
	- 3. Acessibilidade 'deve acessar apenas dados necessários'
	- 4. Desempenho consistente na geração de relatórios 'vários clientes possam ser conectados com o mínimo de esforço'
	- 5. Arquitetura cliente-servidor 'capazes de funcionar num ambiente cliente-servidor'
	- 6. Dimensionalidade genérica 'estrutura básica de dados, fórmulas e formatos de relatórios não deve ser inclinada para uma dimensão específica'
	- 7. Manuseio dinâmico de matriz esparsa 'ajustar o seu esquema físico para o máximo desempenho'
	- 8. Suporte a multiusuários 'permite o acesso multiusuário e controla o acesso e permissões para células individuais'
	- 9. Operações irrestritas de cruzamento de dimensões 'qualquer célula ou intervalo de dados ou pode ser acessada por meio de cálculos em qualquer momento'
	- 10. Manipulação de dados intuitiva 'criação do modelo, manipulação e tarefas de animação ocorrem por meio de cliques no mouse'
	- 11. Relatório flexível 'analistas são capazes de apresentar dados em qualquer formato'
	- 12. Dimensões e agregação de níveis ilimitados 'especificação e manipulação de um número ilimitado de dimensões'

- sistema What-if 'usuário final introduz mudanças nas variáveis ou nas relações entre varáveis, observando mudanças em outras variáveis'

//-- 18% Data Mining.

- Data mining
	- identificar padrões (“X” acontece se...),
				  exceções (isto é diferente de... por causa de...), 
				  tendências (ao longo do tempo, “Y” deve acontecer...) 
				  correlações (se “M” acontece, “N” também deve acontecer)

	- 'extração/análise' eficiente
		de 'informação'/padrões útil, interessante, válida, abrangente, antes desconhecida
		usando algoritmos de extração de padrões, com processo 'iterativo', 'supervisionado', não automático
		em 'grandes bases' de dados, arquivos e bancos de dados como 'Data Warehouse'
		que sirvam para orientar 'tomada de decisões' cruciais e 'previsão' do comportamento futuro
		em que mistura 'estatística', 'aprendizado de máquina', 'crescimento-poda-validação' focando em 'conceitos' em vez de algoritmos
		que 'depende de fatores' para o sucesso e recuperação do investimento
		e atribui ao 'especialista' a 'identificação da causa'dos fenômenos observados

- tarefas
	
	1- .Associação 'identificar atributos relacionados'
		- "quando se compra uma bolsa, se está propenso a comprar sapatos na mesma loja"
		- "clientes que compram pão também compram leite"
		- "SE atributo X ENTÃO atributo Y"

		- trata de probabilidade, induzir a comprar mais, compra casada, lado mão esquerda e direita (conjunto-item)

		- medidas
			- 'suporte' medida objetiva para avaliar interesse da regra de Associação
				- porcentagem de transações no banco em que a regra ocorre (quantidade de vezes que uma regra se verifica)
			- 'confiança' medida objetiva que mede o grau de certeza de uma associação
				- probabilidade condicional P (Y | X), porcentagem de transações contendo os itens de X que também contém os itens de Y 

	
	1- .Clustering/Agrupamento 'classificação em que as labels não são definidas, aprendizado não-supervisionado'
		- "aplicar análise de clusters sobre o banco de dados de um supermercado a fim de identificar grupos homogêneos de clientes"
		- "uma população de dados sobre uma doença que pode ser dividida em grupos baseados na similaridade dos efeitos colaterias produzidos"
		- "para auditoria, separando comportamentos suspeitos"

		- medida de distância/similaridade
			- 'simetria' D (A,B) = D (B,A)
			- 'constância de auto simetria' D (A,A) = 0
			- 'positividade' D(A,B) = 0 -> A = B
			- 'desigualdade triangular' D (A,B) <= D(A,C) + D (B,C)

		- 'Particionamento'
			- organizam os objetos em k agrupamentos 
			- 'K-means' por centroide

		- 'Hierárquicos'
			- aglomeração ou divisão dos elementos do conjunto (Dendrograma - gráfico em formato de árvore)
			- 'aglomerativos' bottom-up começando com cada objeto sendo um agrupamento
			- 'divisivos' top-down começando com todos os objeto no mesmo agrupamento

		- 'Densidade', 'Grade', 'Modelo'

	1- .Classificação 'objetos a serem categorizados num banco predefinido de castas, aprendizado supervisionado'
		- "clientes da faixa econômica B, com idade entre 50 e 60 são maus compradores"
		
		- 'Árvore de Decisão'
			- cada nó não folha é uma decisão e nós folhas são categorias (labels)
			- pra classificar basta começar na raiz e chegar num folha

		- 'Baysiana'
			- encontrar a probabilidade de um certo evento ocorrer, dada a probabilidade de um outro evento que já ocorreu

		- 'Regras'
			- SE condição ENTÃO conclusão (semelhante a associação)

		- 'Redes Neurais'
			- conjunto de unidades de entrada e saída conectados por camadas intermediárias e cada ligação possui um peso associado

		- 'SVM'
			- usada para relações lineares e não-lineares
			- o tanto para tarefas de classificação quanto de predição

	- .Regressão/Estimação 'similar a classificação mas usada quando o registro é identificado por um valor numérico e não categórico'
		- "estimar o valor de uma determinada variável analisando-se os valores das demais"
		- "estimar a quantia a ser gasta por uma família de quatro pessoas durante a volta às aulas"
		- "estimar a pressão ideal de um paciente baseando-se na idade, sexo e massa corporal"

	- .Predição 'similar a classificação e estimação mas quer descobrir o valor futuro de um determinado atributo'
		- "predizer o valor de uma ação três meses adiante"
		- "predizer o vencedor do campeonato baseando-se na comparação das estatísticas dos times"

		- 'Regressão Linear'
			- relação entre as variáveis preditoras e a resposta segue um comportamento linear (y = b + wx)

		- 'Regressão Não-Linear'
			- a relação entre as variáveis preditoras e a resposta não segue um comportamento linear (Polinomial)
	
	1- .Detecção de desvios/outliers 'dados que fogem o comportamento padrão da maioria'
		- bom para detecção de fraudes

	1- .Padrões sequenciais
		- < {carro}, {pneu, toca-fitas} > "clientes que compram carro, tempos depois compram pneu e toca-fitas de carro"

	- .Padrões em séries temporais 'coleção de observações feitas sequencialmente ao longo do tempo'
		- sequencias de eventos, cada evento pode ser um tipo fixo dado uma transação

	- .Teste de hipotese 'comportamento no banco passado usado para verificar ou refutar notações pre-concebidas'
	
	- .Decoberta de conhecimento 'analise sobre os dados é feita sem suposições prévias, dados falam por si'

	- .Descrição ' descrever os padrões e tendências revelados pelos dados'
		-  utilizada em conjunto com as técnicas de 'análise exploratória' para comprovar a influência de certas variáveis no resultado obtido



- características
	- dimensão 'quantidade de atributos de um conjunto de dados'
	- dispersão 'para um atributo relevante, a maioria dos valores é NULL ou um valor padrão'
	- resolução 'granularidade dos dados'
- métodos
	- simples 'consultas baseadas em SQL, OLAP, raciocínio humano'
	- intermediários 'regressão, árvores de decisão, agrupamento'
	- complexos 'redes neurais, indução de regras'
- classificações
	- Preditivo 'mostrar como certos atributos dos dados irão se comportar no futuro'
	- Textual   'obtenção de informação utilizando fontes de dados textuais'
	- Espacial  'descoberta de padrões utilizando bancos de dados espaciais povoados por mapas'
- conhecimento
	- não-estruturado 'regras ou lógica proposicional'
	- estruturado 'árvores de decisão, redes semânticas, redes neurais ou hierarquias de classes ou frames'
- visualização
	- exibir resultados em forma gráfica para tomadores de decisões
	- visualização interativa 'dispositivos para penetrar em gráficos visando obter mais detalhes e em tempo real fazer modificações nos dados'
- análise exploratória de dados
	- analisar conjuntos visando resumir principais características
	- métodos visuais
	- sugerir hipóteses sobre as causas dos fenômenos observados
	- fornecer uma base para uma futura coleta de dados através de pesquisas ou experimento

- 'CRISP-DM' ciclo de vida
	- sequencia de fases não obrigatória
	- um processo continua após solução ter sido desenvolvida
	- Processos subsequentes se beneficiarão das experiências de processos anteriores

	- 1. Entendimento do negócio 'obter conhecimento sobre objetivos e requisitos'
	- 2. Seleção dos dados 'coleta inicial de dados, procedimentos visando a familiarização dos dados, identificar problemas de qualidade, formar hipóteses'
	- 3. Limpeza dos dados 'limpeza, transformação, integração e formatação; ruídos, dados estranhos ou inconsistentes são tratados'
		- uso de DW facilita esta etapa
		- mais esforço, em torno de 50% do tempo
		- Data Cleansing 'detecção, validação e correção de erros em bases de dados'
	- 4. Modelagem dos dados 'técnicas de modelagem são selecionadas e aplicadas com parâmetros calibrados para valores otimizados'
	- 5. Avaliação do processo 'garantir que o modelo gerado atenda às expectativas da organização'
		- aqui é contruido um modelo de alta qualidade para análise de dados
	- 6. Execução 'definição das fases de implantação de MD'
		- pode ser simples como gerar um relatório ou complexo quanto executar processos de mineração de dados repetidamente
		- geralmente executada pelo cliente

- 'KDD' todo processo de descoberta do conhecimento
	- processos executados de forma interativa e iterativa

	- 1. Seleção 'gera dados escolhidos'
	- 2. Pré-processamento 'gera dados pré-processados'
	- 3. Transformação 'gera dados transformados'
	- 4. Data mining 'gera padrões'
		- uma das atividades do KDD
	- 5. Interpretação/Avaliação 'gera conhecimento'

I. Lógica proposicional. 
II. Árvores de decisão. 
III. Redes neurais. 
IV. Redes semânticas. 


//-- 6%  Business Intelligence: Conceitos Princípios e Processos.

- BI (ou Sistemas de suporte à decisão ou de inteligência de negócio)
	- conjunto de 'ferramentas', 'tecnologias', 'metodologias', 'conceitos' e 'recursos'
	  usando 'informações estratégicas', dados operacionais, históricos e externos
	  para suporte a tomada de'decisões gerenciais e estratégicas'
	  impactando 'estratégia corporativa', 'performance' e 'competitividade'

	- tabelas de fatos consolidados (DW) aliviam a carga analítica sobre as aplicações de BI
	- os atributos da tabela de dimensão (DW) são o principal alvo de especificações de restrições e agrupamento de consultas em aplicações de BI

	- engloba
		- Data Mining (análise preditiva), OLAP, Data Warehouses, sistemas ETL, DSS, EIS/ESS
		- KM (gestão do conhecimento), CI (inteligência competitiva), BSC (cartão de escore balanceado) 
		- Portais, ferramentas de transmissão, alertas e notificações, fluxo de trabalho, indicadores (dashboards), cockpits digitais, relatórios financeiros, Datamarts, planilhas

	- OLAP 'processamento analítico online normalmente executado pelo usuário final oferecendo recursos de grandes qtds de dados disponibilizando info gerenciais'
	- DSS 'sistema de suporte à decisão - suporta atividades de tomada de decisões empresariais resultando na ordenação, classificação ou escolha entre alternativas'
	- EIS/ESS 'sistema de informação/suporte executivas - suporta as necessidades de informação e tomada de decisões com acesso fácil a informações internas e externas'
		- forma especializada do DSS

	- 'sistemas operacionais' tarefas que fazem parte do dia- a-dia das organizações, individuais
	
	- 'sistemas analíticos' agregar dados das tarefas para prover informações aos gestores
		- aqui surge o 'DW' como armazém de dados padrozinado com informações dos diversos sistemas operacionais da empresa
		- DW também protege os ativos de informação da empresa

	- projeto 'DW/BI'
		- compreender os usuários de negócios 'entender as responsabilidades, metas, objetivos'
			- determinar decisões que usuários querem fazer com o DW e encontrar melhores usuários de negócio
		- fornecer informações/análises de alta qualidade, relevante e acessível para os usuários de negócios 
			- mostrar melhores fontes de dados
		- sustentar o ambiente DW/BI 'justificar o custo pessoal e gastos contínuos com os créditos das decisões de negócios'

	- componentes do sistema
		- Data Warehouse (DW) 'fontes de dados'
			- inclui dados históricos organizados e resumidos e dados atuais para apoio em tempo real
		
		- Business Analytics 'coleção de ferramentas para manipulação, mineração, análise de dados do DW, análise de negócios'
			- Relatórios e consultas 'relatórios estáticos e dinâmicos, consultas, informações, visão multidimensional, drill down, relacionados com BPM'
			- Mineração de dados 'busca de relações desconhecidas ou informações em grandes bases, computação neural, técnicas preditivas ou métodos estatísticos'
		
		- Business/corporate performance management (BPM/CPM) 'monitoramento e análise de performance e a Interface com o usuário'
			- carteira emergente de aplicativos e metodologias que contém a evolução da arquitetura e ferramentas de BI em seu núcleo
			- amplia monitoramento, medição/comparação das vendas, lucro, custos, rentabilidade e outros indicadores de desempenho, introduzindo gestão e feedback
			- DSS, EIS, BI 'extração bottom-up de informação a partir dos dados'
			- BPM 'top-down da estratégia corporativa'
			- combinado com 'BSC' e dashboards

		- Dashboard 'visão abrangente e visual das medidas de desempenho corporativo, tendências e exceções'
			- interface com os usuários com informações de várias áreas de negócio
			- KPI 'indicadores chave de desempenho'
			- painel apresenta uma visão geral da saúde da organização

- KM (gestão do conhecimento)
	- objetivo primária é tornar o conhecimento acessível a todos
	- envolve dados, informação, conhecimento e inteligência

	- 'dado' sucessões de fatos brutos desorganizados representando partes isoladas, unidades básicas da informação
		- observações do estado do mundo, facilmente estruturado, obtido por máquinas, quantificado e transferível
		- fatos, textos, gráficos, imagens estáticas, sons, segmentos de vídeo analógicos ou digitais
		- coletados nos ambientes interno e externo

		- 'estruturado'
			- organizados e armazenados em SGBD relacional
			- metadados
			- esquema ou um formato padrão para cada um dos atributos
			- blocos semânticos conhecidos como relações no modelo relacional

		- 'semiestruturados'
			- não mantida nos SGBDs
			- organização heterogênea dificultando consultas
			- não são estritamente tipados
			- esquema de representação presente de forma explícita ou implícita
			- análise do dado necessária para identificar sua estrutura
			- XML (eXtensible Markup Language), RDF (Resource Description Framework), OWL (Web Ontology Language)
			- esquemas definidos depois da existência dos dados 
			- estrutura irregular, implícita e parcial

		- 'não estruturado'
			- sem estrutura definida
			- documentos, textos, imagens e vídeos
			- sem descrição para estrutura
			- grande maioria dos dados

	- 'informação' quando dados passam por avaliação e organização, a partir deste momento permitem tomada de decisão
		- dados com relevância e propósito, requer análise, consenso quanto ao significado, mediação humana
		- inclui a revelação de fotografias de um filme, as transmissões de rádio transformadas em um formato de relatório padronizado
		- procedimentos que incluem formatação, tradução, fusão, impressão
		- pode ser automático
		- 'elaboração' refinar as informações
			- características adicionais do problema, hipóteses, consequências, soluções, explanação e justificativas de sugestões, crítica de argumentos
	
	- 'conhecimento/capital intelectual' informação com contexto e relevância, informação em ação, inclui reflexão, síntese e contexto, de transparência complexa
		- informação valiosa da mente humana, difícil estruturação, captura em máquinas, transferência, sendo não formalmente expresso (tácito)
		- informações avaliadas na confiabilidade com interpretação e integração de dados e informações
		- insumos analisados e combinados na síntese de um produto final
		- daqui os tomadores de decisões compreendem a situação do problema
		- 'aprendizado' não é estático, modifica-se com o ambiente
			- integração de informações em estruturas de conhecimento

		- 'tácito' armazenado nas pessoas e adquirido pela experiências de vida

		- 'explícito' em forma textual formalizada facilmente transmitido por meio físico

		- transmissão
			- 1.'Socialização' interação do conhecimento pela troca de ideias e experiências, observação e prática
			- 2.'Externalização' conhecimento pessoal passa para domínio público pela documentação
			- 3.'Combinação' conhecimento explícito de diferentes fontes agrupado visando agregar valor para gerar um novo conhecimento
			- 4.'Internalização' adquirido pela leitura disponível em livro, revistas, internet
			
	
	- 'inteligência' o conhecimento contextualmente relevante que permite atuar com vantagem no ambiente considerado
		- conhecimento sintetizado e aplicado a uma situação para aprofundamento
		- síntese de corpos de conhecimentos
		- base do processo decisório, evitar efeitos ruins eminentes de uma decisão
		- vem do conhecimento pela 'síntese', habilidade humana baseada em experiência e intuição que ultrapassa a capacidade de qualquer inteligência artificial
		- 'experiência' é a efetividade da inteligência de uma organização, aperfeiçoada pelas decisões tomadas
			- agregação de valor ao processo decisório

- CI (inteligência competitiva)
	- prover um processo de coleta/análise de informações de 'atividades correlatas e tendências de mercado'
	- absorver maior número de informações para melhoria na tomada de decisões e desenvolvimento
	- explorar competidores e mercado
	- CI é um BI aplicado fora da própria empresa, detectando ameaças e oportunidades 

	- seleção, coleção, interpretação e distribuição da informação publicamente segura que têm importância estratégica

	- visa 'detectar ameaças competitivas', eliminar ou 'minimizar surpresas', 'acrescentar vantagem' competitiva, 
			minimizar o 'tempo de reação' e encontrar 'novas oportunidades'

	- atividades
		- 1. Area de CI 'definição dos Kits - tópicos chave de inteligência'
		- 2. Ameaças de mercado, entrantes na competição, decisões pendentes
		- 3. Análise de fontes internas e externas com coleta de informações competitivas
		- 4. Análise e interpretação de dados com obtenção de diferencial competitivo
	

//-- 13% ERP.

- ERP 'Enterprise-Resource-Planning'
	- usa modelo OLTP

//-- 4%  ETL. 

- ETL
	- ferramentas de extração, transformação de dados e carga
	- desenvolvimento do DW possui um trade-off entre aplicações 'BI' e trabalho do sistema 'ETL'
		- BI são feitos várias vezes pelos usuários de negócios
		- ETL é feito uma vez pela equipe de ETL

	- ETL é o processo mais crítico e demorado na construção de um 'DW'
	- ETL e ferramentas de limpeza consomem 1/3 do orçamento num projeto de 'DW'
	- processos de ETL consomem 80% do tempo de desenvolvimento do 'DW'
	- tabelas de fatos consolidados (DW) adicionam um peso ao processamento de ETL

	- 1. Entender as necessidades de negócio e o contexto legal do sistema
		- preocupação com qualidade dos dados
		- definir o nível de qualidade para o dado ser ou não aceito

	- 2. Entender os requisitos de segurança e privacidade
		- definir requisitos de segurança

	- 3. Entender a forma de integração dos dados (MDM) e a latência dos dados
		- descreve o quão rápido os dados das fontes de dados de origem devem ser entregues aos usuários de negócio por meio do sistema de BI/DW
		- listar todas as tabelas de fato e dimensão
		- listar todos os cubos OLAP e estruturas de dados especiais
		- listar todos os índices conhecidos e agregações
		- inventariar o seu departamento: SO, ETL, linguagem de programação, SQL, SGBDs e habilidades OLAP
		- enumerar as habilidades necessárias para apoiar seus sistemas atuais e seus sistemas futuros prováveis
		- listar os seus sistemas legados

	- componentes principais das etapas dos processos
		
		- 'extração' coleta de dados brutos da origem e gravação em disco no ambiente de ETL antes de qualquer reestruturação dos dados
			- subsistemas de 1 a 3 apoiam o processo

			- 1. Sistema de extração 'extração de dados dos sistemas de origem'
				- esperar dados de sistemas diferentes com diferentes tipos de dados e outros desafios

			- 2. Perfil de dados (profiling) 'técnica de análise dos dados para descrever o seu conteúdo, consistência e estrutura'
				- orientação de quanto a limpeza de dados é muito importante para o projeto
				- sempre que se consulta "SELECT DISTINCT" se está traçando o “perfil de dados”

			- 3. Sistema de captura das alterações nos dados 'capacidade de transferir apenas as alterações relevantes da fonte'
				- isolar os dados de origem mais recentes
				- transferir os dados que foram alterados desde a última carga
				- técnicas são: colunas de auditoria, extração de tempo, comparação diferencial total, log do BD, monitorar fila de mensagens
		
		- 'limpeza e conformidade' etapas no ETL para melhorar a qualidade dos dados recebidos da fonte e fusão a partir de mais fontes para aplicar dimensões e métricas
			- subsistemas de 4 a 8 descrevem arquitetura necessária

			- 1. Sistema de limpeza de dados 'corrigir dados sujos'
				- porém espera-se que DW forneça quadro preciso dos dados

			- 2. Esquema de eventos de erro 'esquema dimensional centralizado para registrar todos os eventos de erro lançada por tela no mapa ETL'
				- pode ser usada em integração de dados genéricos (DI), em que dados transferidos entre aplicações legadas

			- 3. Dimensão de auditoria 'contém o contexto dos metadados no momento em que uma linha específica da tabela de fatos é criada'

			- 4. Sistema de deduplicação 'combinar um conjunto de registros duplicados em uma imagem unificada'
				- combina as colunas dos registros pareados em uma linha conformada
				- criação de uma única linha com os atributos mais relevantes e consistentes

			- 5. Sistema de conformidade 'ajuste e verificações dentro do processo de ETL'
		
		- 'entrega' estruturação e carregamento dos dados em modelos multidimensionais de destino no servidor de apresentação
			- subsistemas de 9 a 21 fornecem capacidade

			- 1. Gestão da alteração lenta da dimensão
			- 2. Gerador de chave substituta
			- 3. Gerencia de hierarquia
			- 4. Gerencia de dimensões especiais 'Date/Time Dimensions, Junk(lixo) Dimensions, Mini-Dimensions, Shrunken Subset Dimensions, Small Static Dimensions'
			- 5. Construtores da tabela fato
			- 6. Pipeline da chave substituta
			- 7. Construção da tabela ponte para dimensões multivaloradas
			- 8. Gerenciador de dados atrasados
			- 9. Sistema de gerenciamento das dimensões
			- 10.Sistema provedor dos fatos
			- 11.Construção dos agregados
			- 12.Construção do cubo OLAP
			- 13.Gerencia da propagação de dados
		
		- 'gestão' gestão dos sistemas e processos relacionados do ambiente de ETL
			- subsistemas de 22 a 34 descrevem os componentes necessários
			- 'confiabilidade' processos sempre executados consistentemente, em tempo hábil, confiáveis, qualquer granularidade 
			- 'disponibilidade' deve cumprir SLAs, DW deve estar pronto e disponível como prometido
			- 'gerenciamento' processos precisam evoluir
			
			- 1. Agendador de Jobs 'Job definition, Job scheduling, Metadata capture, Logging, Notification'
			- 2. Sistema de backup
			- 3. Sistema de recuperação e restart
			- 4. Sistema de controle de versão
			- 5. Sistema de migração de versão
			- 6. Workflow Monitor
			- 7. Sistema de ordenação
			- 8. Analisador de ancestrais e dependência
			- 9. Sistemas para problemas de escala
			- 10.Sistema de paralelismo/pipeline
			- 11.Sistema de segurança
			- 12.Gerenciamento de conformidade
			- 13.Gerenciar repositório de Metadados

	- processo
		- 1. Desenvolver um plano 'de alto nível, escolher a ferramenta ETL, desenvolver estratégias padrão e fazer “Drill Down by Target Table”'
		- 2. Desenvolver o documento de especificação do ETL 'temos o nosso DW devidamente povoado com dados'
		- 3. Processo incremental do DW 'processamento incremental das tabelas dimensões e da tabela fato'
		- 4. Operação e automação do sistema de ETL 'visando um melhor desempenho e resiliência'

