//-- 31% SQL.

- Structured Query Language
- SQL é padrão ANSI
- Para criar um website
	- Programa de dados RDBMS, como MS Access, SQL Server, MySQL
		- Relational Database Management System
		- Dados armazenados em objetos chamados tabelas
	- Rodar uma linguagem de script server-side, como PHP ou ASP
	- Usar SQL para obter os dados
	- Usar HTML/CSS para dar estilo as páginas 

- SQL (Structured Query Language)
	- DDL (Data Definition Language) 'define o esquema, cria (create) ou destoi (..)'
	- DML (Data Manipulation Language) 'faz crud, obtem (select), insere (insert), atualiza (update) e deleta (delete) '
	- DCL (Data Control Language) 'para dar (grant) ou retirar (revoke) poder de acesso'

- Manipular tabelas
	- create table (constraints chaves primária e estrangeira)
		- cria tabelas
			- create table Departamento (Cod Integer Not Null, Nome Varchar(20) Not Null, Constraint pkdepart Primary Key (Cod));
			- Create Table Empregados 
				(Cod Integer Not Null,
				 Coddepart Int Not Null,
				 Constraint pkempregado Primary Key (Cod),
				 Constraint fkdepart Foreign Key (Coddepart)
				 References departamento(Cod)
				 );
	- alter table
		- alterar estrutura de uma tabela no banco de dados
		- alter table Empregados add column (DTNasc Datetime Not Null);
		- Alter table Empregados modify column (Endereço varchar(40));
		- alter table Empregados drop Endereço cascade;
		- alter table Empregados drop Endereço restrict;
		- alter table Empregados drop Column Endereço;
	- drop table
		- apaga tabela do banco de dados
		- drop table Empregados
	- truncate table 
		- apaga dados da tabela
		- truncate table Empregados

- Consultas SQL
	- select
		- select <lista de atributos e funções>
		  from <lista de tabelas>
		  where <condicoes>
		  group by <atributos de agrupamento>
		  having <condicoes de agrupamento>	
		  order by <lista de atributos>	

- Selecionar campos (select)
	- select * from pcnfsaid; 'seleciona todas as colunas'
	- select numnota, dtsaida, vltotal from pcnfsaid; 'seleciona colunas específicas'

- Atribui apelidos (as, ' ')
	- select codprod as codigo from pcprodut; 'usando as'
	- select codprod codigo from pcprodut; 'nomeando diretamente'
	- select codprod as “Codigo do Produto“ from pcprodut; 'usando as quando há espaço em branco'
	- select codprod “Codigo do Produto“ from pcprodut; 'nomenado diretamente quando há espaço em branco'

- Concatenar (||)
	- unificar informações de dois campos da tabela para serem exibidos em um campo
	- pode-se usar strings que não informações existentes na tabela
	- select especie || serie, numnota from pcnfsaid; 'seleciona campo concatenado com outro'
	- select “Emitido em:“ || dtemissao || “ com vencimento em:“ || dtvenc from pcprest; 'seleciona campo concatenado com texto'

- Distinct
	- select distinct codcli from pcnfsaid; 'mostra informação do campo de forma que os registros apareçam apenas uma vez'

- Where
	- para restringir dados
	- com comparação (=, >, >=, <, <=, <>, in, like, between, is null)
		- select * from pcnfsaid where  numnota = 50; 'igual'
		- select * from pcnfsaid where numnota > 45; 'maior'
		- select * from pcnfsaid where  numnota >=50; 'maior ou igual' 
		- select * from pcnfsaid where  numnota < 10; 'menor'
		- select * from pcnfsaid where numnota <= 5; 'menor ou igual'
		- select * from pcnfsaid where numnota <> 2; 'diferente'
		- select * from pcnfsaid where numnota in (1,3,5,6,8); 'dentro da lista'
		- select * from pcnfsaid where numnota like “1%”; 'que comece com 1, não importando quantos e quais números venham na sequência'
		- select * from pcnfsaid where numnota like “1_”; 'que comece com 1, e que tenham apenas um número na sequência, com qualquer valor'
		- select * from pcnfsaid where numnota like “1__”; 'que comece com 1, e que tenham apenas dois números na sequência, com qualquer valor'
		- select * from pcnfsaid where numnota like “_1%”; 'que comece com qualquer número, seguido de 1, não importando quantos e quais números venham na sequência'
		- select * from pcnfsaid where numnota between 1 and 10; 'em que valor do campo esteja entre 1 e 10, incluindo 1 e 10'
		- select * from pcnfsaid where  comissao is null; 'em que valor do campo é nulo/vazio, espaço ou zero não são null'
	- com condições lógicas (not, and, or)
		- select * from pcprest where  duplic = 4 and codcob not in (“DESD”,”CHP”); 'campo não pode ser os valores na lista'
		- select * from pcnfsaid where comissao is not null; 'campo não é nulo'
		- select * from pcclient where cliente not like “%JOSE%”; 'em que conteudo não parece com "JOSE"'
		- select * from pcclient where dtcadastro not between “01-jan-2007” and “31-jan-2007”; 'que não estiver entre “01-jan-2007” e “31-jan-2007”'
		- select * from pcprest where duplic = 2 and codcob <> “DESD”; 'somente se duplic for 2 e codcob diferente de “DESD”'
		- select * from pcprest where  
		  duplic = 2 and codcob = “BK” or duplic = 3 and codcob = “CHP”;'somente se a primeira regra é verdadeira ou a segunda, sendo que and tem precedencia'

- Ordenar resultados (order by, order by desc)
	- select * from pcempr order by matricula; 'ordena por campo matricula em ordem crescente'
	- select * from pcempr order by matricula desc; 'ordena por campo matricula decrescente'
	- select * from pcprest order by duplic, codcli, codcob; 'ordena por duplic, codcli e codcob, em ordem crescente'
	- select * from pcprest order by duplic, codcli, codcob desc; 'ordena por dupli, codcli em ordem crescente e por codcob em ordem decrescente'

// FCC
- Ataques
	- SQL injection
		- ocorre quando se pede entrada de usuário num form HTML por exemplo, como username/userid, e em vez disso o usuario coloca um statement sql que o banco não esperava
		- txtUserId = getRequestString("UserId");
		  txtSQL = "SELECT * FROM Users WHERE UserId = " + txtUserId;
	- XSS 
		- Cross-site scripting (XSS) é um tipo de vulnerabilidade do sistema de segurança de um computador, encontrado normalmente em aplicações web 
		  que ativam ataques maliciosos ao injectarem client-side script dentro das páginas web vistas por outros usuários

- SGBDL
	- existe uma sintaxe bem definida tanto para DDL quando DML
	- operadores únicos para DML, select, insert, update e delete
	- a ideia do modelo de dados relacional é reduzir o conhecimento sobre a estrutura física do banco, logo UM MODELO LÓGICO

- SQL 
	- não possue distinção entre letras maiúsculas e minúsculas.

- Renaming
	- com as ou não
	- se for uma só palavra, não precisa '', senão precisa

- PRIMARY KEY
	- Para setar chave primaria
	- ATENTE-SE: chave primária não se repete
	- ATENTE-SE: pode haver combinação de chaves(se duas chaves com dois valores cada, temos 4 combinações)
	- ATENTE-SE: vêm intrínsecas as restrições de integridade NOT NULL e UNIQUE

- JOINS
	- LEFT JOIN 'A com meio'
		- SELECT <select_list> FROM TableA A LEFT JOIN TableB B 
		  ON A.Key = B.Key
	- LEFT JOIN 'A sem meio'
		- SELECT <select_list> FROM TableA A LEFT JOIN TableB B 
		  ON A.Key = B.Key
		  WHERE B.Key IS NULL
	- RIGHT JOIN 'B com meio'
		- SELECT <select_list> FROM TableA A RIGHT JOIN TableB B 
		  ON A.Key = B.Key
	- RIGHT JOIN 'B sem meio'
		- SELECT <select_list> FROM TableA A RIGHT JOIN TableB B 
		  ON A.Key = B.Key
		  WHERE A.Key IS NULL
	- INNER JOIN 'meio'
		- SELECT <select_list> FROM TableA A INNER JOIN TableB B 
		  ON A.Key = B.Key
	- OUTER JOIN 'A com meio B'
		- SELECT <select_list> FROM TableA A FULL OUTER JOIN TableB B 
		  ON A.Key = B.Key
	- OUTER JOIN 'A sem meio B'
		- SELECT <select_list> FROM TableA A FULL OUTER JOIN TableB B 
		  ON A.Key = B.Key
		  WHERE A.Key IS NULL || B.Key IS NULL

- GRANT 'atribui permissão para usuário'
- REVOKE 'remove uma permissão dada a um usuário; se tiver recebido permissão de outro usuário ainda tem acesso, até que este outro usuário também remova'
- DELETE '(DML) elimina registros da tabela dada uma condição, senão elimina todos os registros da tabela; NÃO PODE TER *'
- TRUNCATE TABLE '(DDL) elimina todos os registros da tabela'
- DROP TABLE '(DDL) elimina a tabela do banco'
- UNION 'usado para combinar o set de resultados de dois ou mais selects, sendo os sets de colunas de tipos similares e na mesma ORDER e valores únicos'
- UNION ALL 'UNION que permite valores duplicados'
- UNIQUE 'indica que os valores de uma coluna na tabela não podem se repetir, podendo ser nulo'
- DISTINCT 'valores retornados de um select sem repetição'
- GROUP BY 'usado com funções agregadas para agrupar o resultado em uma ou mais colunas'
- HAVING 'usado com GROUP BY e adicionado ao SQL pois o WHERE não podia ser usado com funções agregadas (COUNT, MAX, MIN, SUM, AVG)'

// DDL
- Alter table válidos 
	- Alter Table Tab_InfJuv 
			Add Primary Key (Id) 'adiciona campo Id como chave primaria'
	- ALTER TABLE Processo 
			ADD PRIMARY KEY(NumeroSeqProcesso, DigitoProcesso, AnoAjuizamentoProcesso);
	- ALTER TABLE YourTable 
			ALTER COLUMN YourColumn VARCHAR (500) NOT NULL;
	- 'MySQL' ALTER TABLE Envolvido 
			ADD COLUMN dataNascEnvolvido DATE NOT NULL 
			AFTER cpfEnvolvido; 'preenchimento obrigatório, imediatamente após preencher o campo cpfEnvolvido'

- Create table válidos
	- CREATE TABLE IF NOT EXISTS Filiado ( cpfFiliado VARCHAR(20) NOT NULL, nomeFiliado VARCHAR(50), emailFiliado VARCHAR(40), siglaPartido VARCHAR(10) NOT NULL, 
 			PRIMARY KEY (cpfFiliado), 
 			FOREIGN KEY (siglaPartido) REFERENCES Partido (siglaPartido) );
	- CREATE TABLE Contribuinte_Imposto (IDContribuinte INT NOT NULL, SiglaImposto VARCHAR(10) NOT NULL, VAlor_Imposto DOUBLE, 
			PRIMARY KEY (IDContribuinte, SiglaImposto), 
			FOREIGN KEY (IDContribuinte) REFERENCES Contribuinte (IDContribuinte), FOREIGN KEY(SiglaImposto) REFERENCES Imposto (SiglaImposto));
	- CREATE TABLE Obra (idObra INTEGER NOT NULL, siglaOrgao VARCHAR(20) NOT NULL, Descricao VARCHAR(255) NULL, Valor DOUBLE NULL,
 			PRIMARY KEY(idObra),
 			INDEX Obra_FKIndex1(siglaOrgao),
  			FOREIGN KEY(siglaOrgao) REFERENCES Orgao(siglaOrgao) ON UPDATE CASCADE); 'qualquer alteracao na chave da tabela original reflete automaticamente na tabela Obra' 
	- 'MySQL 5.6'CREATE TABLE NAMES (Id integer PRIMARY KEY, Name text);

- create view válidos 'uma view é vista como uma tabela comum'
	- CREATE VIEW processos2010 
	  		AS SELECT numeroProcesso Número_do_Processo, tribunalProcesso Número_do_Tribunal FROM processo WHERE anoInicioProcesso>2007;
	- CREATE VIEW VENDAS_REGIAO 
	  		AS SELECT t1.Regiao_Nome REGIÃO, SUM(t2.Vendas) VENDAS FROM REGIAO t1, LOJA t2  WHERE t1.Cidade_Loja = t2.Cidade_Loja  
	  		GROUP BY t1.Regiao_Nome;  

- truncate table válido 
	- TRUNCATE TABLE Shippers;

- drop table válido
	-TDROP TABLE Shippers;


// DML
- Select válido 
	- SELECT AVG(salario) FROM TRAB WHERE sexo=’FEMININO’;
	- SELECT COUNT(*) AS 'Ano < 2000' FROM Processo WHERE AnoAjuizamentoProcesso<2000; 
	- SELECT DISTINCT AnoAjuizamentoProcesso AS Anos FROM Processo ORDER BY AnoAjuizamentoProcesso DESC;
	- SELECT Tipo FROM Catálogo WHERE Tipo IN (‘gde’, ‘médio’, ‘pequeno’)
	- SELECT Tipo FROM Catálogo WHERE Tipo = ‘gde’ OR Tipo = ‘médio’ OR Tipo = ‘pequeno’
	- SELECT * FROM Processos ORDER BY Envolvido ASC;
	- SELECT COUNT(CustomerID), Country FROM Customers 
			GROUP BY Country; 'conta quantos clientes existem por país'
	- SELECT COUNT(CustomerID), Country FROM Customers 
			GROUP BY Country 
			HAVING COUNT(CustomerID) > 5; 'conta quantos clientes existem por país mas restringe os com mais de 5'
	- SELECT Nro_Proc, SUM(Custas_Proc) FROM Tab_Processos 
			GROUP BY Nro_Proc HAVING SUM(Custas_Proc) > 1000000.00; 'mostra ids e somas dos processos cuja soma passa de 1000000'
	- 'MySQL 5.6'SELECT Name FROM NAMES WHERE Id = 3 or Id = 5;


- Subconsultas válidas
	- Geralmente usa-se NOT IN, ALL, ANY, e SOME
	- SELECT nomeAdvogado FROM advogado WHERE numeroOABAdvogado 
			NOT IN
			(SELECT numeroOABAdvogado FROM advogado_processo);
	- SELECT * FROM funcionario t1 WHERE salario
			> 
			(SELECT AVG(salario) FROM funcionario t2 WHERE t2.idDepartamento = t1.idDepartamento); 'aqui não poderia ser GROUP BY, pois retorna um SET não entendido por >'

- Inserts válidos
	- INSERT INTO advogado_processo VALUES ('34001', '000467', 'Acusação', 'Aprovado');
	- INSERT INTO advogado_processo (numeroOABAdvogado, numeroProcesso, tipoAtuacao) VALUES ('67812', '0001467', 'Acusação');
	- 'MySQL 5.6'INSERT INTO NAMES VALUES(1,'Tom');
	- 'PostgreSQL 9.3'INSERT INTO tabTRT 
			DEFAULT VALUES;

- Update válido
	- UPDATE Filiado 
			SET siglaPartido='PMDB' WHERE siglaPartido='PDT';

- Delete válido
	- DELETE FROM Customers 
			WHERE CustomerName='Alfreds Futterkiste';
	- DELETE FROM Customers 'deleta todos os registros da tabela Customers'

// DCL
- Grant válido
	- GRANT SELECT 
			ON employee 
			TO user1
			WITH GRANT OPTION; 'atribui permissão de SELECT e de dar GRANT na tabela EMPLOYEE para user1'

- Revoke válido
	- REVOKE SELECT 
			ON employee 
			FROM user1; 'remove a permissão QUE VOCÊ DEU de SELECT na tabela employee de user1'



//-- 19% Modelo Entidade-Relacionamento.

- Para estudo e levantamento dos requisitos necessários
- Identifica-se as principais partes e objetos envolvidos, possíveis ações e responsabilidades
- características e como interagem entre sistema
- Daí, desenvolver modelo conceitual que será utilizado para orientar o desenvolvimento

- MER/ER
	- modelo conceitual para descrever objetos/entidades envolvidos em um domínio, suas características/atributos e relacionamentos
	- Entidades
		- objetos ou partes envolvidas
		- Físicas ou lógicas
			- físicas'realmente tangíveis, existentes e visíveis no mundo real, como cliente/produto'
			- lógicas'existem em decorrência da interação entre ou com entidades físicas, como venda/modelo/espécie/função'
		- Segundo existência
			- fortes'existência independe de outras entidades, como produto num sistema de vendas'
			- fracas'dependem de outras para existirem, não fazem sentido sozinhas, venda depende de produto'
			- associativas'quando se precisa associar a entidade a um caso específico de outra entidade, pode possuir duas chaves primárias'
	- Relacionamentos
		- 1..1
			- cada uma das duas entidades envolvidas referenciam obrigatoriamente apenas uma unidade da outra
			- cada usuário só pode ter um currículo, cada currículo só pertence a um único usuário
		- 1..n/1..*
			- uma das entidades envolvidas pode referenciar várias unidades da outra, porém, do outro lado cada uma das 
			  várias unidades referenciadas só pode estar ligada uma unidade da outra entidade
			- um usuário pode ter vários dependentes, mas cada dependente só pode estar ligado a um usuário principal
		- n..n/.*..*
			-  cada entidade, de ambos os lados, podem referenciar múltiplas unidades da outra
			- um título pode ser escrito por vários autores, um autor pode escrever vários títulos
	- Atributos
		- descrevem cada entidade dentro do domínio
		- um cliente possui nome, endereço e telefone
		- Função
			- descritivos'característica intrínsecas de uma entidade, como nome/cor'
			- nominativos'além de definir identificam um objeto, como nome/código/número'
			- referenciais'representam a ligação de uma entidade com outra em um relacionamento, uma venda possui o CPF do cliente, que a relaciona com a entidade cliente'
		- Estrutura 
			- simples'um único atributo define uma característica da entidade, como nome/peso'
			- compostos'para definir uma informação da entidade, são usados vários atributos, endereço pode ser composto por rua, número, bairro, etc'
		- chave primária'representam valores únicos que identificam a entidade, sendo que não podem repetir, como CPF'
		- chave estrangeira'referenciais, ligados a uma chave primária, venda tem campo CPF do cliente que se relaciona com campo CPF da entidade cliente'
	- DER/ER
		- enquanto MER é modelo conceitual, DER é sua representação gráfica e principal ferramenta
		- Notação
			- entidades'retângulos'
			- Para Peter Chen, entidades fracas'retângulo duplo'
			- atributos'elipses'
			- relacionamentos'losangos, ligados por linhas, contendo cardinalidade (1..1, 1..n ou n..n)'
			- Em notações mais modernas, abandonou-se as elipses e passou-se a utilizar o formato 'UML'
		- Se tem entidade1-card1-relacionamento-card2-entidade2, lê-se entidade1 relacionamento card2 entidade2
			- imovel-1-aluga-n-inquilino, lê-se um inquilino aluga um imóvel, um imóvel é alugado por n inquilinos
		- Se representação por cardinalidade completa, como entidade1-(card1,card2)-relacionamento-(card3,card4)-entidade2
			- lê-se card1 ou card2 entidade1 relacionamento card3 ou card4 entidade2
			- grupo-(1,1)-possui-(0,n)-produto, lê-se 1ou1 grupos possuem 0oun produtos
		- o formato UML é o mais usado hoje em dia
		- atributo com asterisco'chave primária da tabela'
		- não é necessário especificar tipo de cada atributo 
	- Num relacionamento n:m 
		- deriva em três tabelas no modelo relacional normalizado, sendo uma delas a correspondência entre as instâncias específicas de uma entidade com as da outra
		- Em um relacionamento (n:n) é necessário criar uma tabela contento a chave primária de ambas.
		- Em um relacionamento (1:n) é necessário criar uma chave estrangeira no lado n referenciando a chave primária no lado 1.
	- Se uma entidade depende de um atributo de outra entidade para poder existir/fazer sentido, é uma entidade fraca


// FCC
- modelo conceitual (MER)
- modelo lógico (entra especificidades de SGBD)
- modelo físico (entra especificidades do banco)
- esquema relacional (implementação no banco de dados relacional)
- conjunto/set = instâncias da entidade

- MER 
	- utilizado para compreender os dados necessários às funções do sistema e obter uma base para o projeto do banco de dados
	- responsável por realizar uma representação mais conceitual dos dados de uma aplicação

- Notação (Peter Chen)
	- Retângulo 'entidade'
	- Retângulo Duplo 'entidade fraca/depende da existência de uma entidade forte/identificador'
	- Losando 'relacionamento'
	- Elipse 'atributo'
	- Elipse Dupla 'atributo multivalorado'
	- Elipse Pontilhada 'atributo derivado/nao armazenado no banco'
	- Elipses Ligadas 'atributo composto'

- Notação (Pé-de-galinha)
	- | 'um'
	- O 'zero'
	- pé-de-galinha 'muitos'

- Relacionamento
	- 1-1 'exige chave estrangeira em uma das entidades'
	- 1-N 'exige chave estrangeira na entidade N'
	- N-M 'gera entidade associativa'
		- exige geração de nova tabela que herda atributos da associação cujo identificador é composto a partir dos identificadores das entidades participantes na associação
		- necessário no esquema relacional
		- No MER não é possível que um relacionamento seja associado a uma entidade, então tornamos esse relacionamento uma entidade associativa, 
				que a partir daí poderá se relacionar com outras entidades. Uma entidade é relacionada com o relacionamento entre duas outras entidades.
		- situação em que é desejável permitir a associação de uma entidade a um relacionamento 
	- binário 'liga dois conjuntos de entidades distintos'

- Participação
	- Total 
		- para um entidade existir deve estar associada a pelo menos uma ocorrência de outra entidade
		- todas as instâncias da entidade participam do relacionamento
	- Parcial 
		- entidade existe mesmo que no relacionamento não ocorra nenhuma ocorrência da outra entidade
		- podem haver instâncias da entidade que não participam do relacionamento

- Composição 'autorrelacionamento'


















































Justaposição é um processo de formação de coisas por composição, ou seja, ocorre a fusão das coisas

- Um Administrador de bancos de dados e tuning
	- tem por função organizar o sistema de BD para melhor desempenho
	- tem por função ajuste fino quando mudança de requisitos

- Tuning 
	- é propor e aplicar mudanças visando otimizar o desempenho na recuperação ou atualização de dados, otimização
	- Objetiva minimizar tempo de resposta e recuperação dos dados das aplicações
	- Um dos fatores usados no módulo de tuning em um SGBD é avaliar o número de acessos a disco para realizar uma consulta

- Uma instancia do banco de dados
	- é a coleção das informações armazenadas nele em determinado momento

- O SGBD Microsoft SQL Server 2008
	- possui uma função sys.dm_index_physical_stats que retorna o nível de fragmentação de índices do banco de dados (status físico do indice do modelo de dados)

- Bancos de dados normalizados
	- tem por característica várias tabelas estreitas com poucas colunas

Um SGBD (Sistema Gerenciador de Bancos de Dados)
	- (Navathe) é uma coleção de programas que permite aos usuários criar e manter um banco de dados
	- (Slberschatz) é constituído por um conjunto de dados associados a um conjunto de programas para acesso a esses dados
	- (Carlos Heuser) é um software que incorpora as funções de definição, recuperação e alteração de dados em um banco de dados

Um SBD (Sistema de Bancos de Dados)
	- é a junção de BD + SGBD
	- tem propriedades ACID (Atomicidade, Consistência, Isolamento, Durabilidade)
	- tem por característica que a recuperação de falhas nas transações é mais complexa que o controle de concorrência

- Um SGBD relacional
	- deve possibilitar a identificação única de uma linha de uma tabela

- Triggers
	- são objetos armazenados que são automaticamente executados em resposta à execução de algum evento
	- é um código procedural que é automaticamente executado em resposta a certos eventos numa tabela, view ou banco de dados