//-- 31% SQL.

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