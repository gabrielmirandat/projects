-- Gabriel Martins de Miranda
-- Exercicio de banco de dados
-- Modelo da locadora na linguagem SQL

-- sudo -u postgres psql gabriel
-- to run: psql -f ddl_tables_creation.sql -d gabriel

-- \cd [ directory ] Changes the current working directory to directory.
--  \d[S+] [ pattern ] For each relation (table, view, index, sequence, or foreign table)
--           or composite type matching the pattern, show all columns, their
--           types, the tablespace (if not the default) and any special
--           attributes such as NOT NULL or defaults.

-- DDL

drop table TB_CLIENTE,
           TB_FITA,
           TB_FITA_CLIENTE,
           TB_FILME,
           TB_ATOR,
           TB_CATEGORIA,
           TB_FILME_ATOR,
           TB_FILME_CATEGORIA;


create table TB_CLIENTE(
  numero      integer primary key,
  endereço    varchar(40) not null,
  telefone    integer not null,
  nome        varchar(30)
);

create table TB_FILME(
  id        integer primary key,
  titulo    varchar(30) not null
);

create table TB_FITA(
  numero      integer primary key,
  idFILME     integer
              references TB_FILME(id)
);

create table TB_FITA_CLIENTE(
  numeroCLIENTE     integer
                    references TB_CLIENTE(numero),
  numeroFITA        integer
                    references TB_FITA(numero),
  data_entrega      integer,
  primary key(numeroCLIENTE, numeroFITA)
);

create table TB_ATOR(
  codigo          integer primary key,
  nome_artistico  varchar(30) not null,
  nome_real       varchar(30) not null,
  data_nascimento integer
);

create table TB_CATEGORIA(
  codigo    integer primary key,
  nome      varchar(30) not null
);

create table TB_FILME_ATOR(
  idFILME     integer
              references TB_FILME(id),
  codigoATOR  integer
              references TB_ATOR(codigo),
  primary key(idFILME, codigoATOR)
);

create table TB_FILME_CATEGORIA(
  idFILME           integer
                    references TB_FILME(id),
  codigoCATEGORIA   integer
                    references TB_CATEGORIA(codigo),
  primary key(idFILME, codigoCATEGORIA)
);
