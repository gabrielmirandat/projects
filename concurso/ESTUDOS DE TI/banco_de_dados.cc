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
	- DDL (Data Definition Language) 'define o esquema'
	- DML (Data Manipulation Language) 'manipula o esquema'
	- DCL (Data Control Language) 'assegura o esquema'

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

- selecionar campos (select)
	- select * from pcnfsaid; 'seleciona todas as colunas'
	- select numnota, dtsaida, vltotal from pcnfsaid; 'seleciona colunas específicas'

- atribui apelidos (as, ' ')
	- select codprod as codigo from pcprodut; 'usando as'
	- select codprod codigo from pcprodut; 'nomeando diretamente'
	- select codprod as “Codigo do Produto“ from pcprodut; 'usando as quando há espaço em branco'
	- select codprod “Codigo do Produto“ from pcprodut; 'nomenado diretamente quando há espaço em branco'

- concatenar (||)
	- unificar informações de dois campos da tabela para serem exibidos em um campo
	- pode-se usar strings que não informações existentes na tabela
	- select especie || serie, numnota from pcnfsaid; 'seleciona campo concatenado com outro'
	- select “Emitido em:“ || dtemissao || “ com vencimento em:“ || dtvenc from pcprest; 'seleciona campo concatenado com texto'

- distinct
	- select distinct codcli from pcnfsaid; 'mostra informação do campo de forma que os registros apareçam apenas uma vez'

- where
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

- ordenar resultados (order by, order by desc)
	- select * from pcempr order by matricula; 'ordena por campo matricula em ordem crescente'
	- select * from pcempr order by matricula desc; 'ordena por campo matricula decrescente'
	- select * from pcprest order by duplic, codcli, codcob; 'ordena por duplic, codcli e codcob, em ordem crescente'
	- select * from pcprest order by duplic, codcli, codcob desc; 'ordena por dupli, codcli em ordem crescente e por codcob em ordem decrescente'




DICAS (depois passa pra cima)

- primary key
	- Para setar chave primaria

- Alter Table Tab_InfJuv Add Primary Key (Id)
	- Adiciona campo Id como chave primaria

- unique
	- Indica que os valores do campo não podem se repetir

- PostgreSQL 9.3
	- comando válido INSERT INTO tabTRT DEFAULT VALUES;


//-- 19% Modelo Entidade-Relacionamento.




































































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