-- describe para confirmar criaçao da tabela
-- describe <NOME DA TABELA>

-- DML - manipulaçao
-- INSERT
-- UPDATE
-- DELETE

insert into TB_CLIENTE
values (1, 'Cruzeiro Q 1105', 82574744, 'Gabriel Miranda'),
       (2, 'Cruzeiro Q 1105', 32338382, 'Marina Miranda'),
       (3, 'Asa Sul Q 302', 34432341, 'Matheus Farias'),
       (4, 'Asa Norte Q 505', 32647586, 'Barbara Fernandes'),
       (5, 'Lago Norte Q 26 ', 32111111, 'Katiolino Miranda');


insert into TB_ATOR
values (1, 'Smigol', 'Bruno Silva', 1967-02-15),
       (2, 'Jean Valjean', 'Marcio Pires', 1963-09-12),
       (3, 'Chopin', 'Minor Mendeley', 1957-03-07),
       (4, 'Dexter', 'Brandon Sandmann', 1963-09-12),
       (5, 'Aaron Stampler', 'Edward Norton', 1969-08-18);

insert into TB_CATEGORIA
values (1, 'Ficçao Cientifica'),
       (2, 'Musical'),
       (3, 'Drama'),
       (4, 'Romance'),
       (5, 'Comedia');
       

insert into TB_FILME
values (1, 'Senhor dos Aneis'),
       (2, 'Os Miseraveis'),
       (3, 'O Pianista'),
       (4, 'Dexter'),
       (5, 'As Duas Faces de um Crime');

insert into TB_FITA
values (1, 1),
       (2, 1),
       (3, 2),
       (4, 3),
       (5, 4),
       (6, 5);

insert into TB_FITA_CLIENTE
values (1, 1, 2016-05-15),
       (2, 2, 2016-06-15),
       (2, 6, 2016-03-15),
       (3, 5, 2016-05-15),
       (4, 3, 2017-03-15),
       (5, 4, 2017-02-15);

insert into TB_FILME_ATOR
values (1,1),
       (2,2),
       (3,3),
       (4,4),
       (5,5);

insert into TB_FILME_CATEGORIA
values (1,1),
       (2,2),
       (3,3),
       (4,3),
       (5,3);

