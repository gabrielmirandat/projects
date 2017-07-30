atributo x entidade = se queremos fazer pesquisa
multivalorado x entidade fraca
só faz entidade fraca se ela não tiver como ser identificada
colocar atributos temporais se necessário


--------------------------------------------//--------------------------------------------//--------------------------------------------
Cap 1. Introdução à modelagem conceitual

SGBD - sistema gerenciador de bancos de dados - coleção de programas que permite aos usuários criar e manter 
	   um banco de dados.
definir um bd - especificar tipos de dado, estruturas e restriões.
compartilhamento - múltiplos usuários acessam bd de forma concorrente.
banco de dados (bom) != processamento de arquivos (ruim - atualização custosa - o comum de programação)

catalogo - software e users - metadados do sistema

biblioteca da unb - emprestimo/disponibilidade de livros
online transaction processing (bd com concorrencia) - sistema de cadeiras do cinema em vários caixas

administrador de banco de dados (DBA - database admin) - monitora software e hardware.
projectista de banco de dados 						   - ver qual o BD é mais apropriado ao tipo de dados.
usuário final
engenheiro de software 								   - determinam as solicitações do usuários finais
bastidores 											   - desenvolvem os softwares do SGBD

SGBD
- Controle de redundancia - evitar repetição de dado .(existe redundância controlada)
- Restrição de acesso não autorizado - uso de senhas (nem todos consultam e atualizam)
- Armazenamento persistente - entendimento dos dados de linguagens orientadas a objetos (C++ e Java)
- Consultas eficientes - indices (arvore ou hash)
- Backup e restauração 
- Multiplas interfaces ao usuário 

Banco de dados relacional - separar armazenamento físico dos dados da sua representação conceitual e prover 
uma fundamentação matemática para os bancos de dados. Linguages de consulta de alto nível.

Banco de dados orientado a objetos - competidor do relacional - não pego, muito complexo.

XML - relação WWW e banco de dados

Novas aplicações - científicas, de restauração, recuperação de vídeos, data mining, espaciais, séries temporais.
Dados específicos e complexos - necessidades de bancos não relacionais.

--------------------------------------------//--------------------------------------------//--------------------------------------------

#################1. Introdução

Profissionais 
- DBA
- Projetista/Programadores (MCITP - Microsoft Certified IT Professional)
- Usuário

SGDBs
- (IBM) DB2
- (Microsoft) SQL Server
- PostgreSQL
- MySQL
- Oracle

Bancos de dados
- Distribuído
- Móveis
- Heterogêneos
- Data Warehouse
- Específicos: geográfico, biológico..
- Big Data
- noSQL

Novos rumos
- Ciência dos dados

SQL
- SELECT email, telefone
  FROM TB_PESSOA
  WHERE nome='Maria'

SGBD
- Processamento de transações
- Processamento de consulta
- Recuperação a falhas

/*Caps 1 e 2*/
#################2. Sistemas de banco de dados

- Um banco de dados é uma coleção de dados relacionados
- Dados persistentes
- Dado: bits armazenados
- Informação: significado do dado
- esquema: descrição do banco
- estado: dados em um particular momento (conjunto de instâncias)

SBD
- Usuário
- Interface (aplicativos) = {programas de aplicações/consultas e SGBD}
- Dados

Usuário
- Administrador (DBA)
- Projetista
- Analista de sistemas - mexe com BD, redes, Engenharia de Software - e programador de aplicações
- Usuário final

Administração
- DA (Data Administrator) - decide em relação aos dados da empresa
- DBA (Database Administrator) - suporte técnico para as decições do DA.
	- Define restrições de segurança e integridade
	- Define normas de backup e recuperação
	- Monitorar desempenho

SGBD - BD + programas de acesso aos dados (Independência entre dados e programas)
BD - dados + metadados

Quando NÃO usar um SGBD
- se quer muita segurança
- se quer controle de concorrências
- se quer aplicações em tempo real
- não se espera muitos acessos (alterações)

Modelos de dados - conceitos usados para descrever a estrutura do banco de dados
	Modelo conceitual - percepção do usuário
		| MER - MODELO ENTIDADE RELACIONAMENTO (textual)
	Modelo de implementação - usado em SGBDs comerciais
		| MR - MODELO RELACIONAL
	Modelo Físico - descreve como dados são armazenados


#################3. Modelo Entidade Relacionamento (MER - textual)
- Modelo conceitual de alto nível
- Feito para o usuário
- Diagrama Entidade Relacionamento (DER - esquemático)
- Considerações
	- Diferentes modelos podem ser equivalentes
	- outras notações: UML, cardinalidade min/max

Projeto de um BD
- modelo conceitual MER -> modelo de implementação MR -> projeto físico

("ENTIDADE") - elemento do mundo real
- física/concreta: 	pessoa, carro, casa, empregado, ..
- conceitual/abstrata: viagem, curso, profissão, ..
	FORTE : 
	FRACA: depende/precisa da chave de outra entidade 
		|envolve RELACIONAMENTO DE IDENTIFICAÇÃO com pelo menos uma RESTRIÇÃO DE PARTICIPAÇÃO TOTAL

("ATRIBUTO") - descrevem entidade
- Empregado: nome, endereço, idade, fone, ..
	SIMPLES (indivisível): cpf, matrícula
	*COMPOSTO: é composto de vários atributos básicos -> endereço = {local, cidade, estado, cep}
	MONOVALORADO (unico valor): nome 
	*MULTIVALORADO: conjunto numa mesma entidade -> telefone = {telefone1, telefone2, ..}
	*VIRTUAL: obtivel a partir de outros -> idade da data de nascimento, média final das notas dos alunos 

("RELACIONAMENTO") - associa entidades
- trabalha_para: entidade empregado é "trabalhador" e entidade departamento é "empregador"
	GRAU: numero de entidades que participam do relacionamento
	RECURSIVO: uma mesma entidade se relaciona com ela mesma - distinção de papéis é necessário.
			   empregado (supervisor) x empregado (supervisionado)
	*CARDINALIDADE: restringe instanciações (1:1, 1:N, N:N)
	*RESTRIÇÃO DE PARTICIPAÇÃO: 
		|TOTAL - todos fazem parte do relacionamento
		|PARCIAL - podem ou não fazer parte
	*DE IDENTIFICAÇÃO: especifica necessidade de chave de entidade fraca
	TERNARIO: envolve 3 entidades

("ESPECIALIZAÇÃO/GENERALIZAÇAÕ") - associa entidades como subgrupos
- cliente = {pessoa fisica, pessoa juridica}
		|TOTAL - para cada entidade genérica sempre ocorre uma entidade especializada
		|PARCIAL - nem toda genérica envolve uma especializada (genérica tem atributo de tipo de especifica)

("UNIÃO")

Notações
- UML
- Cardinalidade min/max

ESTUDO DE CASO - empresa
vide slide 19

departamento - (nome,
			    numero,
			    {local} "diversos",
			    empregado "gerenciador", 
			    data_empregado_gerente_departamento, 
			    "controla" projetos)

projeto - (nome, 
		   numero, 
		   local "unico",
		   departamento "controlador")

empregado - ((nome),
			 matricula, 
			 (endereço) podia ser, 
			 sexo,
			 salario,
			 data de nascimento,
			 departamento "associado", 
			 empregado "supervisor",
			 projetos "trabalhados",
			 horas_semanais_empregado_projeto,
			 (pode possuir) dependentes)

dependente - (empregado,
			  nome, 
			  sexo, 
			  data de nascimento, 
			  parentesco_empregado)


#################4. Modelo Relacional (MR)

- Dados do bd como tabela (coleção de relações)
- linha: tupla
- coluna: atributo
- tabela: relação

Domínio
- coleção de valores atômicos (indivisíveis)
- está associado a colunas da tabela(atributos) - diz qual o tipo de dados do atributo

Esquema da relação
- descreve uma relação
- esquema R(A1, A2, .., An)  é um conjunto de atributos
- A relação EMPREG pode ser representada pelo seguinte esquema de relação
	EMPREG(uMatricula, Nome, Sexo, Salario)

Grau de relação
Numero de atributos do esquema de relação da relação

Instância vs Esquema
- A instância da relação é modificada com o tempo para refletir as mudanças do mundo real
- O esquema da relação é mais estático (adição ou remoção de atributos)

Chave Primária
- Valor identifica unicamente tupla na relação
- pk

Chave Estrangeira
- coluna ou combinação de colunas que fazem referência à chave primária de outra tabela
- relacionamentos no banco relacional
- fk

Chave Alternativa
- As colunas que não são pks

Restrições de integridade
- O objetivo de um SGDB é a integridade
- são integros se refletem corretamente a realidade e são consistentes
	- Integridade de domínio: valor do campo deve obedecer domínio da coluna
	- Integridade de vazio: especifica se um campo é obrigatório ou opcional (se pode ser zero ou não)
	- Integridade de Entidade: valores de chaves primárias nunca podem ser nulos
	- Integridade referencial: integridade de chave estrangeira
		- atributos de fk em R1 tem o mesmo domínio dos atributos de pk em R2
		- fk pode assumir os valores da pk ou ser nula

#################5. MER para MR

- Tradução inicial de entidades e atributos
- Tradução de relacionamentos e seus atributos

- Para cada entidade forte: tabela que inclui todos os atributos
- atributos compostos: incluir somente os simples 
- pk: chave primária da tabela

Nomes atributos x nomes colunas
- não se deve simplesmente transcrever
- nome da coluna curto, sem espaço em branco, sem acento
- atributos chave: NOME COMPOSTO PELO NOME DA TABELA E O NOME DO PRÓPRIO ATRIBUTO

Entidade fraca
- cria-se tabela T com todos os atributos simples da entidade fraca como suas colunas
- inclui-se em T chave estrangeira fk referente à chave primária da entidade E
- a pk de T será a combinação da primária de E com a parcial da fraca W

Relacionamento
- fator determinante: cardinalidade e participação no relacionamento
- sempre tem: colunas aos identificadores das entidades relacionadas
			  colunas aos atributos do relacionamento
			  coluna fk em uma das tabelas
- na tabela com cardinalidade 1:
			  identificador da entidade relacionada (fk)
			  atributos do relacionamento

CASO 1:1
	- duas com participação parcial:
		- fk em uma das tabelas junto com atributos de relacionamento
	- participação total x parcial
		- fk na total ou todos os atributos na total
	- duas com total
		- junção numa única tabela

CASO 1:N
	- adição de fp na de cardinalidade 1

CASO N:N
	- tabela própria cujas colunas: identificadores de entidades relacionadas
									atributos do relacionamento

Atributo multivalorado
	- P/ cada, nova tabela com próprio atributo mais atributo chave primária da tabela
	  que representa a entidade.
	- Essa pk da tabela é combinação do atributo com chave estrangeira 

Relacionamento com grau maior que 2
	- nova tabela S
	- como fk entra as pks das tabelas envolvidas
	- se o relacionamento tem atributo entra em S
	- pk será combinação das fks

Generalização/Especialização
	- Escolhe: 
		- uma tabela pra tudo
		- subdivisão de entidade genérica
		- uma tabela pra cada entidade


#################6. Normalização

- Bom MER já deixa MR normalizado
- somente para validar projeto relacinal

1FN, 2FN ou 3FN

1FN - valor de todas as colunas indivisível
	- dependência funcional = A -> B
							- A funcionalmente determina B
							- B é funcionalmente dependente de A
							- B é função de A
							- P/ cada A só existe um B
	- negação funcional = A - -> B
						- negação de A -> B
						- A ou B podem ser um conjunto de atributos

2FN - se 1FN e todo atributo de uma chave candidata (o complemento) é totalmente
	  funcionalmente dependente daquela chave.

	- se A,B,C ? D, só existe um D para um A,B,C e 
					- A,B,c separados não define D

3FN - se 2FN e todos não-chaves forem dependentes não-transitivos da pk.
	- se B->C e A->B, logo A->C
	- se isto ocorre, separa B e C em duas tabelas.

#################7. Álgebra relacional

- operações para manipular tabelas
	- Seleção: selecionar subconjunto de tuplas
	- Projeção: selecionar atributos da tabela
	- Produto cartesiano: combina tuplas de ambas as tabelas
	- Renomeação: para operação com duas tabelas iguais
	- Join: relacionamento entre tabelas (seleção no produto cartesiano direto)
	- Junção Natural: relacionamento entre tabelas, eliminando repetição dos atributos de ligação
					  entre tabelas.
	- Junção Externa: para manter todas as tuplas da relação(LEFT, RIGHT, FULL). 					  
	- Conjuntos: união, interseção, subtração
	- Divisão (%): recuperar os empregados que trabalham em todos os projetos em que John Smith trabalha

Cálculo Relacional
	- {t|condição(t)}
	- Quantificadores: existencial e universal.
	- Domínio: {x1,x2,x3,..,xn | condição(x1,x2,x3,..,xn)}




