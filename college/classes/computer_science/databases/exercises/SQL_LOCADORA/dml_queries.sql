-- DML - consulta

select nome
from TB_CLIENTE;

select distinct nome
from TB_CATEGORIA
order by nome desc;

select count(*)
from TB_FILME;

select count(*)
from TB_CLIENTE
where telefone = 32338382;

select a.nome, c.titulo
from TB_CLIENTE a, TB_FITA b, TB_FILME c, TB_FITA_CLIENTE d
where a.numero = d.numeroCLIENTE and b.numero = d.numeroFITA and 
      b.idFILME = c.id;