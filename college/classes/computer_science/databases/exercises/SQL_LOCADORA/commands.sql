# DDL

CREATE TABLE pessoa (
codigo INTEGER(7) PRIMARY KEY,
fone VARCHAR(15) NOT NULL,
nome VARCHAR(35) NOT NULL )

CREATE TABLE pessoa (
codigo INTEGER(7) ,
fone VARCHAR(15) NOT NULL,
nome VARCHAR(35) NOT NULL,
PRIMARY KEY (codigo) )

CREATE TABLE TB_PESSOA(
codigo INTEGER(7) PRIMARY KEY,
fone VARCHAR(15) NOT NULL,
nome VARCHAR(35) NOT NULL,
cpf VARCHAR(13) UNIQUE,
casado INTEGER(7)
REFERENCES TB_PESSOA(codigo),
sexo char(1) check (sexo IN ('F','M')) );

DESCRIBE <NOME DA TABELA>
DESC <NOME DA TABELA>

ALTER TABLE nome_tabela
ADD [CONSTRAINT nome_constraint]
tipo_constraint (nome_coluna)

ALTER TABLE <nome_tabela>
DROP PRIMARY KEY | UNIQUE (nome_coluna) |
CONSTRAINT nome_constraint [CASCADE];

ALTER TABLE nome_tabela
DROP PRIMARY KEY | UNIQUE (nome_coluna) | CONSTRAINT
<nome da constraint> [CASCADE];

DROP TABLE <nome da tabela>
[CASCADE CONSTRAINTS];

RENAME tipo_objeto objeto_antigo TO
objeto_novo;

TRUNCATE TABLE nome_tabela;

#DML - consulta

SELECT nome, salario*12 “Salario Anual”
FROM Empregado

SELECT nome, salario*12 + salario + salario/3 as “Salario Anual”
FROM Empregado

SELECT Prinome || UltimoNome “Nome do empregado”
FROM Empregado

SELECT DISTINCT cargo
FROM Empregado;

SELECT DISTINCT cargo
FROM Empregado
ORDER BY cargo;

SELECT DISTINCT cargo
FROM Empregado
ORDER BY 1 DESC;

SELECT nome, salario*12 “Salario Anual”
FROM Empregado
ORDER BY 2

SELECT nome, departamento, salarioa
FROM Empregado
ORDER BY departamento, salario DESC;

SELECT nome, cargo
FROM Empregado
WHERE cargo = ‘Analista’ ;

SELECT nome, salario
FROM Empregado
WHERE salario > 7000
ORDER BY 2

SELECT nome, salario
FROM Empregado
WHERE salario =10000

SELECT nome, salario
FROM Empregado
WHERE salario > 7000
AND nome = ‘Maria’

SELECT nome, salario
FROM Empregado
WHERE salario > 7000
OR nome = ‘Maria’

SELECT AVG(salario) “Média Salarial”,
SUM(salario) “Soma dos salários”
MIN(salario) “Menor Salario”
MAX(salario) “Maior Salário”
FROM empregado

SELECT COUNT(*)
FROM departamento

SELECT count(*)
FROM empregado
WHERE sexo = ‘M’

SELECT AVG(salario)“Média Salarial”’ , cargo
FROM empregado
GROUP BY cargo

SELECT *
FROM empregado, departamento

SELECT *
FROM empregado, departamento
WHERE empregado.Dep = Departamento.codDep

SELECT empregado.nome, departamento.NomeDep
FROM empregado, departamento
WHERE empregado.Dep = departamento.codDep

SELECT empregado.nome, departamento.NomeDep
FROM empregado, departamento
WHERE empregado.Dep = departamento.codDep
AND empregado.sexo = ‘M’

SELECT nome
FROM empregado
WHERE dep = ( SELECT dep
			  FROM empregado
			  WHERE nome = ‘Maria’ )

SELECT b.nome
FROM empregado a, empregado b
WHERE a.nome = ‘Maria’
AND a.dep = b.dep;

SELECT nome, salario
FROM empregado
WHERE salario < ( SELECT AVG(salario)
FROM empregado)

SELECT nome
FROM empregado
WHERE dep = ( SELECT dep
FROM departamento
WHERE nome = ‘Vendas’
OR nome = ‘Finanças’ )

SELECT nome
FROM empregado
WHERE dep IN ( SELECT dep
FROM departamento
WHERE nome = ‘Vendas’
OR nome = ‘Finanças’ )

SELECT dep_id , AVG(salario)
FROM empregado
GROUP BY dep_id
HAVING AVG(salario) > ( SELECT AVG(salario)
FROM empregado
WHERE dep_id = 30)

#DML - manipulaçao
# INSERT
# UPDATE
# DELETE

INSERT INTO departamento
VALUES (1, ‘VENDA’ , 1);

INSERT INTO departamento
VALUES (1, ‘VENDA’ , NULL);

UPDATE empregado
SET NumDep = 7
WHERE matrEmp=‘12345’ ;

UPDATE empregado
SET NumDep = 7, fone=‘222-3333’
WHERE matrEmp=‘12345’ ;

DELETE empregado

DELETE empregado
WHERE matrEmp=‘12345’ ;

