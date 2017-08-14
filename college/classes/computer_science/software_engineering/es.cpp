2 provas
1 trabalho com 2 entregas

LIVRO - 1x, 2, 3, 4, 5 e Slides de Metodos Ageis em Ingles de Sommerville 10a ed.

--------------------------------------------//--------------------------------------------//--------------------------------------------
ACM, IEEE, SBC

PLANO A : Dados abertos
PLANO B : Web semântica
PLANO C : A+B 

Cap2
Processo e Modelos de Processo
processo = conjunto estruturado de atividades, com entradas, saídas, recursos e responsáveis bem definidos.
Modelos prescritivos
Modelos Ágeis
Processo Unificado (um pouco dos dois: também é prescritivo?)

--------------------------------------------//--------------------------------------------//--------------------------------------------

("0. Interação humano-computador")
TESTING IDEAS					- gathering data*, interpreting data*
EXPLORATION AND DISCOVERY		- making observations, asking questions, sharing data and ideas, finding inspiration, exploring the literature
COMMUNITY ANALYSES AND FEEDBACK	- feedback and peer review, replication, publication, discussion with colleagues
BENEFITS AND OUTCOMES			- delevop technology, address societal issues, inform policy, solve everyday problems, satisfy curiosity, buld knowledge

Sociedades Cientificas
- internacionais: ACM, IEEE
- nacionais: SBC

Auxilio à pesquisa
- nacionais: Capes, CNPp 
- unb: Finatec, DPP/unb - decanato de pesquisa e pos-graduação

Publicações
- Capes possui o webQualis

Fontes
- Comunidades cientificas
- Eventos cientificos
- Periodicos
- CSBC, CBSOFT, SBES, IHC

Identificação
- Lattes, Research Gate, LinkedIn, Google Citations

Mestrado acadêmico vs mestrado profissional?

("Cap 1. Introdução")

Crise do software
Mitos do software
Engenharia do software

Crise do software
Desenvolvedores estavam se perdendo, hardware evoluindo muito rápido, ES ainda era incipiente.
Projeto passa cronograma, má qualidade, má evolução
Empresas reclamam: prazos quebrados, custos altos, custo de manutenção, profissionais ruins
Usuarios reclaman: erros, insegurança, prazos longos de espera
Desenvolvedores reclamam: não produz, dificil treinar novos, mudança constante do objetivo
Problemas: tecnicas imaturas, baixa utilização de código pronto, má documentação, conhecimento concentrado

Mitos do software
da Administração: manual n suficiente; é usado? tem processos corretores de falhas? 
				  só ferramentas top n são suficientes. Adicionar gente no atraso atrasa mais.
do Cliente: maximo de detalhes ao programador antecipadamente. Fazer software flexivel à mudanças.
			definir requisitos permanentes e transitorios antecipadamente.
do profissional: codificação não acaba depois da entrega. É possivel avaliar qualidade intermediaria.

Engenharia de software
Engenheiro de software: não desenvolve
'desenvolvedor': analista, projetista, programador, gerente de projeto
'analista e projetista': especificação do projeto
'analista' = identificar requisitos
'projetista' = desenhar uma solução que utilize a tecnologia p/ transformar os requisitos num 
			   sistema executável.
'eng. de software' = fornece aos desenvolvedores -analistas e projetistas- as ferramentas e processos 
					 q estes deverão usar e tem de verificar se está dando certo.
'gerente de projeto' = planejar e garantir que projeto seja executado de forma adequada dentro dos 
					   prazos e orçamento especificados.

Principios
- abstração, generalização, padronização, formalidade, arquiteturas, modelagem, controle, gerencia de riscos.


("Cap 2. Processos")

Processo de desenvolvimento de software
fases
disciplinas
atividades
documentos descritivo de uma atividade
equipe
normas tecnicas

"Processo" : conjunto de passos parcias que envolve artefatos do software para conseguir
alcançar/manter o produto final.

Atividades do processo -bem elaboradas: são interdependentes, com resposaveis e entradas e saidas bem definidas

"Projeto": execução concreta das atividades visando o produto, é temporal
"Processo": regras de execução do projeto
"Modelo de processo": regras abstratas que especificam o geral do processo. Tem filosofia e comportamento bem 
					  definidos

Processo bem definido e documentado facilita aprendizagem de novos membros, facilita trabalho da equipe, 
e permite melhorias facilmente.

Estrutura do processo
"Fase:" com macro-objetivo bem definido
"Disciplina:" atividades correlacionadas que visam objetivo específico dentro do processo
"Atividade:" visa criação e produção visível

Correlatos à atividade
"Artefato"
"Papel"
"Recurso" 

Atividade
"Passo:" especifica de forma concisa o que deve ser feito
"Procedimento:" execução do passo com tecnologia especificada no passo
"Regra:" limita formas de execução da atividade

Documento de processo evolui, necessita controle de versão

Equipe de processo
Engenheiros que mantém, avalia e otimiza o processo
1a3% do time
centraliza esforço do time

Norma de processos
"fundamentais:" para software ser construido e executado
	- desenvolvimento, manutenção
"de apoio:" garentem qualidade dos outros tipos de processo
	- documentação, garantia de qualidade
"organizacionais:" para acompanhamento dos outros processos
	- gerencia, infraestrutura
"de adaptação:" estabelece como propria norma pode ser aplicada a um projeto

("Cap 3. Processos Prescritivos")

Codificar e consertar
Modelo Cascata
Modelo Sashimi
Modelo V
Modelo W
Modelo Cascata com Subprojetos
Modelo Cascata com redução de Risco
Modelo Espiral 
Prototipação Evolucionária
Entrega em Estágios
Modelo Orientado a cronograma
Entrega Evolucionária
Modelos Orientados a Ferramentas
Linhas de Produto de Software

Questões para escolha do modelo
o quanto é conhecido pelos membros? Visa confiabilidade? Visa cronograma?
Visa entregas periódicas? Visa adaptação a grande fluxo de membros? 

Cascata
- 1 a 1
- Requisitos, análise, projeto, codificação, teste,	operação

Cascata dupla
- Cascata com vai-e-volta

Cascata na prática
- Cascata dupla sendo que de teste pode voltar pra projeto e de projeto para requisitos
//Sugestão de Royce, de Marcos
//LCR, SRR, PDR, CDR, UTC, SAR, SyAR
Sashimi
- Concepção, análise, projeto, codificação, teste
- Operações seguidas se interpolam duas a duas

V
- Requisitos, projeto arquitetual, projeto detalhado, 
  implementação, 
  teste de unidade (detalhado), volta projeto detalhado?
  teste de integração (arquitetural), volta projeto arquitetural?
  teste de sistema (requisitos), volta requisitos?

W
- de W n tem nada
- Requisitos, prepara teste de sistema
  projeto arquitetural, prepara teste de integração
  projeto detalhado, prepara teste de unidade
  codifica, 
  teste de unidade, volta codifica?
  teste de integração, volta codifica?
  teste de sistema, volta codifica?

Cascata com subprojetos
- Concepção, análise, projeto arquitetural
  em 3 threads ou mais: projeto detalhado, codificação, teste,
  teste geral, operação

Cascata com redução de risco
- qualquer cascata com espiral de redução de risco

Espiral
- Revisa, 
  determina objetivos, alternaticas, restrições
  avalia alternativa, identifica e resolve riscos,
  desenvolve e verifica o produto no nível seguinte,
  planeja a próxima fase, 
  repete do início agora com mais tempo e atenção
//Propotipação evolucionário - enquanto não fica bom vai refinando
// 							 - engloba modificações gerais
//Entregas em estágios - entregando de projeto detalhado em projeto detalhado
//					   - engloba modificações detalhadas
Orientado a cronograma
- Como estregas em estágios, mas entregando os mais críticos primeiro

Orientado a ferramentas
- uso intersivo de ferramentas
- rápida produção de sistemas executáveis
- desenvolvimento extremamente rápido, mas limitado às funcionalidades da ferramenta

SPL - linhas de produto de software
- Evolução: subrotinas, modulos, objetos, componentes, serviços, slp
- apresenta menor curto no decorrer do tempo
- Gerência
	- Organizacional - spl é uma boa nesse projeto?
	- Técnica - vai verificando o andamento das atividades, dando certo?


("Cap 4. Modelos Ágeis")

FDD - Feature Driven Development 
DSDM - Dynamic Systems Development Method
Scrum
XP - eXtreme Programming 
Crystal Clear
ASD - Adaptive Software Development 

Manifesto Ágil
indivíduo acima do processo, software funcional acima de documentação, 
cliente acima de negociação contrato, mudanças acima de plano

Principios Ágeis
satisfazer cliente - entrega rápida e contínua
mudanças são bem vindas - até mesmo no fim do projeto
entrega rápida - de duas em duas semanas
administradores e trabalhadores juntos diariamente
conversa face a face entre membros
software funcionando
desenvolvimento sustentado
excelência técinica para agilidade
equipes auto-organizadas
frequentemente questionar rendimento da equipe

("FDD" - MUITO MASSSAAAA (para UnBeatables)
- Ágil que enfatiza orientação a objetos (sempre voltado em todo processo)
- concepção e planejamento - 1 a 2 semanas de levantamento do modelo
- construção - desenvolvimento iterativo de 1 a 2 semanas

concepção e planejamento
DMA - Desenvolver modelo abrangente - equipe de modelagem e arquiteto líder
		- formar equipe de modelagem (rodizio entre membros, especialistas no dominio)
		- estudo dirigido sobre o dominio (equipe apresenta suas especialidades)
		- estudar documentação
		- desenvolver modelo (busca por modelos canditados por grupo - de 3 pessoas)
		- refinar modelo de objetos abrangentes (prever integração entre modelo específico p/ geral)
		SAÌDA: diagrama de classes, de sequência e máquina de estados, comentários explicativos da escolha
CLF - Construir lista de funcionalidades - lider da equipe
		- Área de negócio, atividades da área e passos da atividade
		SAÌDA: documento
PPF - planejar por funcionalidade - gerente do projeto e equipe de planejamento
		- formar equipe de planejamento (gerente + programadores líderes)
		- determinar sequência de desenvolvimento 
			- prazos para conclusão de atividades, 
			- priorização de atividades
			- união de atividades dependentes/similares
			- criação de releases
		- atribuir atividades de negocio aos programadores líderes
		- atribuir classes aos desenvolvedores
		SAÌDA: prazos para atividades, atribuiçao de programadores lideres (variam?), propriedade das classes

construção
DPF - detalhar por funcionalidade
		- formar equipe de funcionalidades - programador lider
			- definir pacotes de fincionalidades
		- estudo dirigido de domínio - especialista de domínio
			- dependendo da complexidade da funcionalidade, necessidade de especialista mais específico
		- estudar documentação - equipe de funcionalidades
			- dependendo da complexidade da funcionalidade, estudar documentação
		- desenvolver diagramas de sequencia
			- específicos e com controle de versão
		- refinar modelo de objetos - programador lider
			- com controle de versões e por enquanto apenas dentro da equipe
		- escrever interfaces das classes e métodos - equipe de funcionalidades
		SAÌDA: comentários do pacote, 	requisitos especificos, diagramas especificos, modelos atualizados
CPF - costruir por funcionalidade
		- implementar classes e métodos - equipe de funcionalidades
		- inspecionar código - equipe de funcionalidades
		- teste de unidade - equipe de funcionalidades
		- promover versão atual - programador lider
		SAÌDA - classes com sucesso, build, funcionalidades

ferramentas para o FFD
	- CaseSpec
	- TexExcel DevSuite

("DSDM")
- agil com desenvolvimento iterativo e incremental
- participação ativa do usuário
- evolução do Rapid Application Development
- pre-projeto - projeto identificado, negociado, orçamento assinado
- ciclo de vida - análise de viabilidade e negócio seguido de ciclos iterativos de desenvolvimento
- pos-projeto - manutenção como continuação do desenvolvimento
FILOSOFIA
- envolvimento do usuário
- autonomia dos desenvolvedores
- entregas frequentes e releases
- eficácia das entregas
- feedback dos usuários
- reversibilidade de ações
- previsibilidade
- ausencia de testes no escopo, testes são uma atividade fora do ciclo de vida
- boa comunicação
PAPÉIS
- campeão do projeto: tem decisão final, gerente executivo capaz de administrar prazos
- visionário: inspeciona usabilidade dos requisitos iniciais
- intermediador: interface de conversação entre equipe e cliente
- anunciante: trazedor de informações importantes para a equipe
- gerente de projeto: manter atividades e orçamento no prazo
- coordenador técnico: projeto da arquitetura do sistema
- lider de equipe: desenvolvedor especial capaz de motivar e manter a equipe
- desenvolvedor: transforma requisitos em código executável
- testador: responsável pelos testes do sistema
- escrivão: registrador de requisitos identificados
- facilitador: disponibiliza ambiente de trabalho e avalia progresso

ciclo de vida
Analise de viabilidade
		- relatorio, prototipo, plano de desenvolvimento e controle de risco
Analise de negocio
		- características e possiveis tecnologias
		- prioriza requisitos e arquitetura inicial
		- Técnicas: Timeboxing e Moscow: requisitos que MUST, SHOULD, COULD e WOULD.
Iteração do modelo funcional (protótipo funcional)
		- Identificar - funcionalidades a serem implementadas
		- Agendar - como e quando da implementação
		- Criar - implementação preliminar da agenda
		- Revisar - tanto pela documentação quanto pelo usuário. Gera um documento de revisão
Iteração de elaboração e construção (protótipo de design)
		- identificar modelo - identificar requisitos funcionais e não funcionais
							 - evidências de teste para criar a estratégia de implementação
		- Agendar - quando e como da implantação dos requisitos
		- Criar - utilizado pelos usuários finais e para efeito de teste
		- Revisar - teste e revisão gerando documentação para usuário e evidências de teste
Implementação
		- Orientações e aprovação do usuário - a partir do uso e da documentação
		- Treinamento - gera artefato usuários finais treinados
		- Implantação - gera artefato sistema entregue
		- Revisão de negócio - impacto do sistema sobre objetivos de negócio


("SCRUM")
- modelo automobilistico
PAPEIS
- scrum master - facilitador (conhece bem o modelo) e resolvedor de conflitos.
- product owner - responsável pelo projeto. Define requisitos no sprint. Conhece e avalia necessidades do cliente
- scrum team - equipe de desenvolvimento. Sem papeis, todos interagem para desenvolver o produto em conjunto (6a10)

PRODUCT BACKLOG
- lista de funcionalidades exigidas por projeto (requisitos ou historias de usuário)

SPRINT 
- estrutura do SCRUM. Ciclos de desenvolvimento de 2 semanas.
- sprint planning meeting - prioriza funcionalidades do product backlog, transferindo-os do 
(inicio)				  - product backlog para o sprint backlog (p/ o ciclo iniciado).
						  - se o product owner descobrir novas funcionalidades, este não compromete
						  - o sprint atual e só aborda em sprints posteriores.
- sprint review meeting   - verificar o que foi feito
(fim)					  - partir para nova sprint
						  - sprint retrospective: avaliar equipe e andamento de processos
- daily scrum 			  - reuniões diárias rápidas sobre feitos ou impedimentos do dia anterior
						  - em pé e em frente a um quadro de anotações, logo após o almoço


PERFIS DE EQUIPE
- fakey-fakey: desonesta, linha reta de desenvolvimento (perfeito)
- late-learner: acumulo de tarefas no final (iniciantes)
- middle-learner: equipe amadurecendo, tarefas no meio
- early-learner: equipe muito boa, acha coisas logo no inicio (quase perfeito)
- plateau - inicio e fim com tarefas. Não conseguem manter até o fim
- never-never: surpresas desagradáveis no final do sprint
- scope increase: subito aumento de carga. Falar com product owner

("XP")
- p/ equipes pequenas e médias
FILOSOFIA
- presumir simplicidade
- respeito
- comunicação
- feedback rápido
- coragem
- mudanças incrementais
- abraçar mudaças 
- trabalho de alta qualidade

PRATICAS
planning game - reuniões semanais com cliente para priorizar funcionalidades que são entregues ao final desta
metaphor - comunicar-se com o cliente na linguagem que ele entende
whole team - cliente faz parte da equipe de desenvolvimento
stand-up meeting - igual do scrum
simple design - não customizar a gosto do desenvolvedor, só o que o cliente requisitou
small releases - liberar versões mínimas para teste pelo clente (IMPORTANTE)
sustainable pace (ritmo) - nada de horas extras, só se muito necessário
collective ownership - código sem dono, não é necessário pedir permissão
pair programming - experiente e aprendiz -> aprendiz código, experiente olha
coding standards - definir e seguir padrão de codificação (IMPORTANTE)
customer tests - testes visualizados pelos programadores e pelo cliente
test driven development - antes de programar unidade deve-se definir e implementar os testes
refactoring - para manter complexidade do código gerenciável
continuos integration - integrar ao sistema o mais rápido possível (IMPORTANTE)

REGRAS 
- planejamento - histórias de usuário, cronograma de entregas frequentes e iterativas
- gerenciamento - jornada sustentável, reuniões em pé, velocidade medida, consertos se inadequado
- design - simplicidade, metáfora, soluções afiadas, refatoração sempre
- codificação - cliente sempre disponível, teste antes, pair programming, integração frequente, posse coletiva
- teste - testes de unidade obrigatórios, testes de aceitação frequentes

("Crystal Clear")
- medida de riscos de projeto. É o mais ágil de todos.

CICLO DE VIDA
- Iteração: poucas semanas, estimação, desenvolvimento e celebração
- Entrega: várias iterações, prazo maximo de 2 meses para entregar funcionalidades ao cliente
- Projeto: formado pelo conjunto de todas as entregas

7 PILARES
- entregas frequentes - máximo de 2 meses com intermediárias
- melhoria reflexiva - comunicação constante sobre projeto
- comunicação osmótica - todos os subprojetos se desenvolvendo na mesma sala, interferir no trab dos outros
- segurança pessoal - membros devem interferir sem medo de repreensões
- foco - 2 ou 3 tópicos de maior prioridade, sem novas atribuições
- acesso fácil a especialistas - especialistas de domínios sempre disponíveis
- ambiente tecnologicamente rico - que permita testes automáticos e integração frequente

("ASD")
- vem da teoria do caos - áreas de sistemas adaptativos
- sistema complexo com agentes, ambiente e saídas emergentes
- agentes - desenvolvedores, clientes, outros
- ambientes - organizacional, tecnológico e de processo
- saídas emergentes - produto

CICLO DE VIDA
- ciclos iterativos de 4 a 8 semanas
- prazos pré-fixados
- tolerante à mudança e adaptação
- desenvolver primeiro elementos de maior risco

FASES 
- Especular 	- planejamento adaptativo do ciclo (geralmente não se sabe de inicio o que fazer)
				- objetivos e prazos devem ser estabelecidos: determinar tempos de durações, descrever 
				- grande objetivo, 	definir componentes de software, definir tecnologia, desenvolver lista
				- de tarefas
- Colaborar 	- engenharia concorrente de componentes, equipe realiza atividades mais previsíveis 
				- e naturalmente mais incertas
- Aprender  	- revisão de qualidade, pequenas interações de projeto, codificação e teste.
				- repetidas revisões com cliente e especialistas 
					- foco no usuário: workshop onde usuários tentam usar produto apontando opnião
					- inspeção de software: detectar defeitos
					- postmortems: avaliação e talvez mudança no modo de trabalhar
- Inicialização - workshop de poucos dias, missões e objetivos, requisitos inicias, restrições e riscos, esforço.
- Garantia final - testes finais e implantação 


("Cap 5. Processo Unificado")

- Caracterização do UP 
- Fases do UP 
- Implementações
	RUP (Rational Unified Process)
	AUP (Agile Unified Process)
	OpenUP (Open Unified Process)
	EUP (Enterprise Unified Process)
	OUM (Oracle Unified Process)
	RUP-SE (Rational Unified Process Systems Engineering)

UP
- inteiramente adaptado ao UML
- baseado nas práticas de maior retorno de invertimento do mercado (ROI).
- dirigido por casos de uso
- centrado na arquitetura 
- iterativo (modelos ágeis) e incremental (ágeis)
- focado em riscos

Dirigido por casos de uso
- deve definir e esgotar toda a funcionalidade possível do sistema
- casos de uso
	- definir e validar arquitetura do sistema
	- criar casos de teste
	- planejar iterações
	- base para documentação do usuário

Centrado na arquitetura
- arquitetura deve ser solidamente desenvolvida
- funcionalidades dos casos de uso devem ser integradas incrementalmente
- casos dos mais críticos/complexos aos mais simples (evitar surpresas)

Iterativo e Incremental
- ciclos iterativos de fixa duração
- ciclo = incremento no design do sistema
- reduz riscos, facilita testes, melhora o aprendizado da equipe sobre o sistema

Focado em riscos
- casos complexos tratados o quanto antes
- riscos positivos e negativos são dominados o mais cedo possível

("fases") => colunas do gráfico de baleia
Concepção
Elaboração
Construção
Transição

Concepção
- Não longa. Duas semanas a dois meses
- Análise dos requisitos do projeto (em abrangência)
- Indentificação dos casos de uso de alto nível	e esforços calculados
- Planejamento a longo prazo do desenvolvimento dos casos de uso abordados
- Estudo de viabilidade(questões tecnológicas, de orçamento e de cronograma)

Elaboração
- detalhe da análise e projeto como um todo
- ocorre em ciclos, sendo desenvolvido e integrado ao longo de cada ciclo
- produzir arquitetura confiavel 
- desenvolver modelo de requisitos (80%)
- projeto geral para fase de construção
- garantir ferramentas para a fase de construção
- entender e eliminar riscos de alta prioridade
- permite análise detalhada do domínio do Problema
- permite acomodação de mudanças mas procura minimizar seu impacto

Construção
- produto completo e usável deve estar disponível, testado e adequado para o usuário final
- ciclos iterativos 
- novas funcionalidades adicionadas a cada ciclo (incremental)
- descrever requisitos faltantes
- garantir andamento do sistema com o pedido do usuário
- garantir componentes desenvolvidos e testados (tanto software quando documentação)
- otimizar recursos e garantir qualidade
- sistema de versões
- explorar casos de uso menos crítico (sem impacto no sistema como um todo)

Transição
- migrar sistema em uso ao ambiente final
- teste de aceitação, treinamento do usuário e transição de dados
- teste de comparação com sistemas legados
- EVOLUÇÃO= atualizações periódicas para correções ou incrementos

(((((((((((#RUP)))))))))))
papel - define habilidades por atividade
work product - define produção da atividade = artefato (diagramas, relatórios ou código)
atividade - atribuida no papel e que produz artefato
workflow - grafos que definem dependências entre atividades

("papeis")

Analista

Analista de sistemas - coordena análise de requisitos. Define escopo e casos de uso.
Designer de negócio - faz modelo de negócio (diagramas de atividade, máquinas de estados)
Revisor do modelo de negócio - revisa coerência e consistência do modelo de negócio
Analista do processo de negócio - coordena a modelagem da organização (casos de uso de negócio)
Especificador de requisitos - responsável pelos casos de uso de alto nível, especifica requisitos suplementares
Revisor de requisitos - revisa casos de uso e garante padronização desse documento
Designer de interface com o usuário - responsável pelos requisitos de interface (não implementa)

Desenvolvedores

Implementador - produção e teste do código fonte
Revisor de código - garante qualidade do software
Integrador - inclue componentes do software ao sistema
Arquiteto de software - design das camadas do sistema
Revisor de arquitetura - revisa papel do arquiteto de software
Designer - decide design das classes, atributos e associações, método (FOOODA)
Revisor de design - revisa boas práticas do designer
Designer de banco de dados - descreve tabelas e códigos do banco de dados
Designer de cápsula - para sistemas de tempo real. Garantir requisitos não funcionais atuando

Testador

Designer de teste - define estratégia de testes 
Analista de teste - projeto e elaboração dos casos de teste
Testador - realização efetiva dos teste (ESTAGIARIO)
Gerente de teste - coordena as atividades

Gerente

Engenheiro de processo - aplica processo de desenvolvimento
Gerente de projeto - planeja atividades, aloca recursos e acompanha garantindo prazos e orçamentos
Gerente de controle de mudança - controle requisições de mudança
Gerente de configuração - planeja e disponibiliza ambiente, garante acesso a artefatos
Gerente de implantação - planeja e acompanha implantação do sistema
Revisor do projeto - revisa planos e avaliações

Outros

Interessados
Desenvolvedor de curso - criação de material de treinamento para usuários
Artista gráfico - criação das arte final do produto
Especialista em ferramentas - seleção, instalação e treinamento das ferramentas de apoio
Administrador do sistema - cuida do ambiente, mentém hardware, versões
Redator técnico - faz redação final dos manuais

("Atividades")
Trabalho executado por indivíduo que exerce um papel dentro do processo
Toda atividade precisa gerar um artefato : modelos, elementos ou planos
Atividades devem poder serem executadas de 1 a 3 dias
Dividida em passos

("Passos")
De pensamento - compreende escopo da atividade e examina artefatos de entrada e saída
De realização - cria ou atualiza artefatos
De revisão - inspeciona resultados

("Artefatos")
Diagrama, modelo, elemento, texto, fonte, executável, qualquer produto criado ao longo do processo
Artefatos podem mudar - controle de versão
São entradas e saídas de atividades
Entregas - artefatos de saída para usuários
Podem ser definidos por templates
Tipos: de gerenciamento, de gerenciamento de configuração e mudança, de ambiente, de modelo de negócio, 
	   de requisitos, de design, de implementação, de teste, de implantação

("Workflow")
Grafos direcionados que definem ordem de execução das atividades dentro de uma disciplina
Define conjunto de atividades e de papéis dentro dessas atividades
Indica dependências entre diferentes atividades 
Tipos:
	- núcleo: forma geral de condução de dada disciplina
	- detalhe: refinamento do núcle, mais detalhe nas atividades, artefatos de entrada e saída
	- planos de iteração: instância do processo para iteração específica

("Guidelines")	
Detalha atividades de forma que leigos entendam
("Templates")
Protótipos de artefatos
("Mentores de ferramentas")
Especificam detalhadamente como usar uma ferramenta

("Disciplinas") => linhas do gráfico de baleia
Projeto
	- Modelagem de negócio
	- Requisitos
	- Análise e design
	- Implementação
	- Teste 
	- Implantação
Suporte
	- Mudança e configuração
	- Projeto
	- Ambiente

("DISCIPLINAS") x ("FASES") -> baleia

("Planos")
De fase ou projeto
	- De medição - métricas para definir andamento do projeto
	- De gerenciamento de riscos - como riscos serão tratados
	- Lista de riscos - lista de riscos conhecidos ainda não resolvidos
	- De resolução de problemas - como problemas são reportados e resolvidos
	- De aceitação de produto - define a avaliação que o usuário final fará

De iteração
	- mais detalhados que os de fase
	- inclue cronograma de atividades com recursos alocados, prazos e dependências

("Cenários")
Organograma - diagrama da organização que descreve setores e responsabilidades
Modelagem de domínio - aplicações para gerenciar e apresentar informação, é estatico, workflows não considerados
					 - concepção/elaboração 
Uma empresa, vários sistemas - família de sistema para uma empresa, modelo de negócio p/ descobrir requisitos únicos
Modelo de negócio genérico - um ou mais aplicativos a um grupo de empresas, modelo de negócio p/ alinhas visões
Novo negócio - novo negócio com sistemas de informação, modelo de negócio p/ verificar viabilidade
Renovação - novo negócio do zero, modelo e negócio p/ várias etapas

("Requisitos")
Manter concordância entre cliente e envolvidos
Desenvolvedores com conhecimento sobre os requisitos
Delimitar escopo
Base técnica para iterações
Base para estimação de custo e tempo
Focar nas necessidades do usuário

("Análise e Design")
Análise - estudo aprofundado do problema.
Design - possível solução tecnológica para o design
no RUP - modelagem, transformação dos requisitos em modelos úteis

("Implementação")
Versões - devem ser controladas e rastreadas, para que alterações tenham pouco impacto no sistema como um todo
		- uma por semana
Integração - combinação de software independente
		   - no RUP (contínua como nos ágeis, diferente da por fase como no cascata com subprojetos)
		   - mínimo de uma integração por ciclo
Protótipo - necessário para reduzir riscos

("Teste")
Exclui os testes de unidade - estes são feitos pelo proprio programador durante a implementação
Verificar interação entre objetos
Verificar integração do todo
Verificar implementação dos requisitos
Garantir que todos os defeitos foram identificados e tratados

("Implantação")
Depende se serão implantados diretamente no computador do cliente ou disponibilizado na internet 

("Gerenciamento de configuração e mudança")
Gerenciamento de configuração - estruturação sistemática de produtos. Atefatos e diagramas como documentos 
							  - sob controle de versão e rastreáveis
Gerenciamento de requisitos de mudança
Gerenciamento de status e medição - apenas verifica os status no processo de mudança
								  - deve ser contínuo e apresentado periodicamente ao gerente do projeto

("Ambiente")
Suporte a projeto - local e ferramentas

(((((((((((#AUP)))))))))))
Versão simplificada do RUP
Aplica técnicas ágeis - desenvolvimento dirigido por testes, modelagem ágil e refatoração
Apenas 7 disciplinas:
	- Modelagem - guia de requisitos usando diagramas UML
	- Implementação - transformar modelo em executável e criar testes de unidade
	- Teste - testes de integração, de sistema e de aceitação
	- Implantação - planejar entregas de sistema
	- Gerenciamento de configuração - gerenciar versões e acesso aos artefatos do projeto
	- Gerenciamento de projeto - controlar atividades, pessoas e prazos
	- Ambiente - dar suporte à equipe com ferramentas, guias e padrões

(((((((((((#OpenUP)))))))))))
Implementação aberta do UP
Versão mais leve do RUP
independente de ferramentas e de baixa exigêcia quanto à precisão e detalhes nos documentos 

(((((((((((#EUP)))))))))))
Extensão do RUP, duas novas fases para tratar a evolução ou suporte ao sistema e a aposentadoria
do sistema

("Produção")
Trata das atividades que ocorrem após a transição, como suporte, correção, ajustes e evolução

("Aposentadoria")
Retirada de um sistema de operação
Sistemas antigos substituídos por novos pode gerar sérios problemas à empresa se não for gerenciado
adequadamente

("Modelagem de negócio de empresa")
A modelagem de negócio do RUP é focada no sistema a ser desenvolvido. Aqui é mais abrangente

("Gerenciamento de portfólio")
Gerenciar softwares em andamento e concluídos

("Arquitetura de empresa")

("Reuso estratégico")

("Gerenciamennto de pessoas")
Gerencia recursos humanos na área de tecnologia da informação
Gerenciar pessoal, contratar, demitir, substituir, alocar pessoas e projetos e investir no crescimento.

("Administração de empresa")
Gerencia dos produtos e informações da empresa

("Melhoria de processo de software")
Adequação da evolução do software

(((((((((((#OUM)))))))))))
É um framework
Para o processo de desenvolvimento iterativo e incremental adequado para bancos de dados, aplicações
e middleware.

(((((((((((#RUP-SE)))))))))))
Extensão do RUP para engenheria de sistemas
Adequada especialmente para sistemas de grande porte
Quando suporta várias equipes trabalhando em paralelo
Necessitam concorrência de hardware e software
implantação impacta arquitetura
Inclue reengenharia de infraestrutura de tecnologia

######################################################################################################
("Chapter 3. Agile Software Development")
Plan-driven(prescritivo) x Agile
Small or medium size product
Customer involved in the development process

XP
User stories broken by the developers in tasks
Refactoring (re-organize class hierarchy, renaming attributes)
Test first for any release, and before any code, as a program, and with Junit for example
Customer make the tests that will be run by the team after every new functionality
Management requires are incremental

Scrum
Small team (7 people)
Product Backlog - list of todo items which the Scrum team must tackle
Product Owner - 
Scrum master - protect the development team from external distractions

Scaling agile methods
For big projects
25/33

######################################################################################################

PROVA 2

6,
8,
9,
14, 
Qualidade de Software (apenas as partes apresentadas em sala, dos caps 
	11, 
	12, 
	Slides de Qualidade em Ingles de Sommerville 10a ed).

VAI CAIR
cap 6 
	- WBS - regras e mandamentos, o que é?
	- Diagrama de Pert - estimar datas das iterações
	- Declaração de escopo
	- Fatores que alteram a duração do ciclo

cap 8
	- Quais são as métricas de prevenção de riscos
	- O que é plano de contingência
	- Três técnicas de contenção de riscos

cap 9
	- Métricas, gerente e registro de artefatos, principio de Prince
	- três tipos de gerente, 
	- cite uma técnica de gerenciamento

cap 14
	- Lei de Lehman, complexidade crescente, tipos de estimar, 
	- o que é evolução adaptativa, quais os tipos de evolução, 
	- leis de evolução

cap 11, 12
	- CMMI, GQM, 
	- diferenças de engenharia reversa, reengenharia, 
	- tipos de qualidade



----------------------------------------------------------------------------------------------------------------------------------


cap 6 
	- WBS - regras e mandamentos, o que é?
	- Diagrama de Pert - estimar datas das iterações
	- Declaração de escopo
	- Fatores que alteram a duração do ciclo

6) Planejamento de projeto

- Seleção de projetos
- Termo de abertura
- Declaração de escopo
- Planejamento de projeto com ciclos iterativos
	- Duração e esforço das fases
	- Duração e numero de ciclos iterativos
	- Numero de iterações
	- Marcos ou entregas
- Planejamento de iteração
	- WBS - estrutura analítica
	- Responsáveis
	- Recursos
	- Dependências
	- Cronograma

Seleção
	- Nem todo pode ser desenvolvido (empresa competente? dá conta dado outros projetos? cliente confiável? Bom retorno em dinheiro?)
	- P/ Cliente: vale o investimento? melhora empresa no mercado? Sua imagem? 

Termo de abertura (project charter)
	- objetivos, justificativas, descrição alto nível, requisitos alto nível, nomeações de gerente e autoridade (pode usar recursos, 
	  contratar?), 
	- cronogramas resumidos, papéis e responsabilidades, organização funcional, premissas e hipóteses (perguntas sem respostas mas 
	  aceitas em princípio), restrições, estudo de viabilidade (business case) sobre retorno previsto, orçamento previsto do projeto.

Declaração de escopo
	- quais os objetivos finais? Nem sempre só software rodando, outros necessários e desejáveis
	- A definição de onde o projeto vai chegar é necessária para estabelecer um bom plano e seus objetivos (iterações) deve sempre 
	  gerar artefatos
	- Descrever produto (refina descrição do TDA), principais entregas (versões, manuais, treinamento), 
	  objetivos(métricas de prazo, custo, qualidade) e critérios de aceitação do projeto(finalizado?)

Planejamento de projeto com ciclos iterativos
	- Plano geral
	- Previsão do esforço a ser despendido (ferramentas)
	- Geração do cronograma geral
	- Estimar esforço geral, cálculo do tempo linear necessário e tamanho médio de equipe, estimar duração e esforço em cada 
	  fase, estimar duração e número de ciclos iterativos.

		Duração e esforço (desenvolvedor*mes) de cada fase: concepção, elaboração, construção, transição (recurso x tempo)
			- esforço/mês = número médio de desenvolvedores na fase
			- No UP: concepção (10% tempo, 5% esforço)
					 elaboração (30% tempo, 20% esforço)
					 construção (50% tempo, 65% esforço) em fases
					 transição (10% tempo, 10% esforço)
			- Alterações do perfil típico: 
					- alongar concepção: necessário achar financiadores, pesquisa de mercado, provas de conceito
					- alongar elaboração: alto risco técnico, restrições de desempenho, sem arquitetura prévia definida
					- encolher concepção e elaboração: evolução de um produto, sem grandes alterações na arquitetura
					- encolher construção e alongar transição: criação ou concorrência de mercado (versões executáveis mais cedo)
					- alongar transição: substituir sistema sem interromper serviços, certificações ou regulamentos (medicina...)

		Duração e número de ciclos iterativos
			- Duração:
				equipes pequenas (5 pessoas): planeja segunda, executa na semana, release na sexta (1 semana)
				equipes médias (20 pessoas): tempo p/ sincronização da info e integração, (3 a 4 semanas)
				equipes grandes (40 pessoas): fluxo de info bem mais lento, precisa documentação (6 a 8 semanas)
			- Alterações do perfil típico em ciclos: 
				- encurtar ciclo: automatização do processo, familiaridade da equipe com o UP
				- alongar ciclo: fator "qualidade" crítico
			- Número de iterações
				- depende do tempo linear proposto (especialmente elaboração e construção)
				- se iterações de 2 semanas, cuja elaboração e construção devem durar 24 semanas no tempo linear, tem-se 12 ciclos.

		Entregas: após definição dos anteriores, retorna à declaração de escopo e define marcos e datas.

Planejamento de iteração
	- Depende do processo escolhido
	- No UP: implementar casos de uso
			 mitigar riscos: gerar plano de redução de probabilidade, de redução de impacto, de recuperação de desastre	
			 implementar modificações solicitadas
	- Prioriza: casos críticos, riscos importantes (lucro), modificações urgentes (refatoração de arquitetura).

		WBS (Work Breakdown Structure) ou workflow
			- apresentada atividades que devem ser executadas para atingir os objetivos determinados
			- exaustiva, inclui todas as atividades necessárias para executar projeto ou iteração
			- estruturável em árvore, aglutinar e detalhar atividades
			- define responsáveis pelas atividades (papeis), sendo que cada uma precisa de pelo menos um responsável
				- pode mudar cronograma, mesmo papel em diferentes atividades
			- alocar recursos nas atividades (humanos, físicos consumíveis ou não-consumíveis)
			- dependências entre atividades (entrada de uma é saída de outra)
				- alocar atividades pré-requisitos primeiro

			REDE PERT: grafo de dependências entre atividades com durações previstas
				- caminho crítico: mais longo caminho, se qualquer etapa atrasar atraso todo o projeto (mais jornada, equipe, 
								   menos artefatos?)

			DIAGRAMA DE GANTT: de cronograma, tempo linear transcorrido por atividades




				Regra 8-80: nenhuma atividade dura menos de 8h (1 dia) nem mais de 80h (2 semanas)
					- XP: de 8 a 24h
					- WBS organizada, precisa e pequena
				Regra dos níveis: WBS sem mais de 3 ou 4 níveis de decomposição (subatividades) de atividades.
				Regra do número de atividades: WBS não deve ultrapassar 200 pacotes (100 já é alto)
				Regra dos 100%: WBS deve incluir 100% de todo o trabalho que deve ser feito na iteração
					- A soma das subatividades deve dar os 100% da atividade

			*- se ciclo de vida prescritivo, indicam atividades e dependências entre elas
			*- se método ágil, pode usar workflows existentes



cap 8
	- Quais são as métricas de prevenção de riscos
	- O que é plano de contingência
	- Três técnicas de contenção de riscos

8) Gerenciamento de riscos

- Plano de gerência de riscos
- Identificação de riscos
	- Riscos tecnológicos, relacionados à pessoas, de projeto
	- Checklist de riscos
- Análise de riscos
- Planos de mitigação de riscos
	- Plano de redução de probabilidade de risco
	- Plano de redução de Impacto de Risco
- Plano de contingência
- Monitoramento de riscos
	- Controle de risco
- Comunicação de riscos

Risco: incertezas

SEI: Modelo de gerenciamento de riscos
	- Identificação, análise, planejamento, rastreamento/Monitoramento, controle, comunicação

Plano de gerência de riscos
	- Quais os riscos? Probabilidade e impacto caso ocorra? Como reduzir essa probabilidade? E esse impacto? E se ele ocorrer?
	- Como monitorar? 
	- TRATAR riscos conhecidos; MINIMIZAR riscos desconhecidos

Identificação de riscos
	- causa (condição incerta) e problema (efeito no projeto ou iteração)
	- No UP:
		- Concepção: riscos de requisitos e de negócios
		- Elaboração: riscos de tecnologia e arquitetura de sistema
		- Construção: riscos de programação e teste de sistema
		- Transição: riscos de utilização do sistema no ambiente final
	- p/ identificar risco: checklists com possíveis riscos, reuniões e brainstorms, análise de cenários (lições de projs anteriores)
	- fontes de riscos: tecnologia (em hardware e software), 
							- experiência, obsolescência
						pessoas (cliente, equipe, mercado), 
							- perder pessoa insubstituível da equipe
							- cliente interessado e disponível?
							- apelo comercial do produto?
							- direitos autorais? Contratos de terceiros? 
						projeto (atrasos, custos)
							- equipe inexperiente na Identificação dos requisitos, insuficientes, excessivos ou incorretos
							- modelo de processo adequado? 
							- custos bem previstos? Tem verba?
							- prazos de cronograma ajustáveis? E a ordem de entrega?

	- Checklists de riscos (SEI): engenheria do produto, ambiente de desenvolvimento, restrições externas

Análise de riscos: após definição dos riscos, definir quais são verdadeiramente relevantes, probabilidade de ocorrência e impacto.

Importância do risco (exposição) = probabilidade x impacto

Planos de mitigação de riscos
	- executados antes que o risco ocorra
	- plano de redução de probabilidade (age nas causas) e plano de redução de impacto (age nos efeitos)

Plano de contingência (ou plano de resposta ao risco)
	- ações a serem efetuados caso o risco efetivamente ocorra
	- eliminação, transferência, aceitação

Monitoramento de riscos
	- necessidade de documentação do risco, sistema de controle de risco
	- ID, descrição, probabilidade, impacto, Importância, planos de mitigação, responsável, prazo, status

	Controle de risco: acompanhamento do estado do risco
		- visa evitar prejuízo
		- execução prévia dos dos planos de mitigação
		- Lei de Parkinson ou síndrome do estudante: uma tarefa se expande até preencher todo o tempo livre

Comunicação de riscos
	- reunião para levantamento de riscos
	- boatos, vazamento de info, política interna, falta de integração, questões pendentes, postergar decisões
	- interesses na resolução de diferentes riscos por diferentes pessoas


cap 9
	- Métricas, gerente e registro de artefatos, principio de Prince
	- três tipos de gerente, 
	- cite uma técnica de gerenciamento

9) Gerenciamento de projeto

- Gerente de projeto
- PMBOK
- Prince 2
- Condução de projeto de software
	- Folha de tempo
	- Acompanhamento de problemas
	- Registro de artefatos
- Medição
	- Classificação de métricas
	- Planejamento de um programa de métricas
- Revisão e avaliação
- Fechamento

Gerência de projeto
	- produção dos objetivos previamente planejados, dentro dos prazos, custos e qualidade previstos.
	- gerente deve manter riscos no nível mais baixo possível de probabilidade e impacto
	- cliente não enxerga dificuldade na mudança dos requisitos, processos de eng. soft acabam introduzindo requisitos, 
	  grau de complexidade de software é frequentemente alto, tecnologia muda rapidamente

	SWEBOK (subareas do gerenciamento de projetos de software)
		- iniciar e definir escopo, planejar projeto, conduzir projeto, revisar e avaliar, fechar, medição em eng. de soft

	Gerente: prevê, é organizado, lidera, bom comunicador, pragmático, empático.
		- equilibra triângulo: tempo, custo, escopo
		- equilibra haxágono: escopo, qualidade, cronograma, orçamento, recursos, riscos

PMBOK (project Management book of Knowledge)
	- iniciar, planejar, monitorar e controlar, encerrar
	- gerência de integração, escopo, tempo, custos, qualidade, recursos humanos, comunicações, riscos, aquisições(serviços terceiros)

	iniciar: termo de abertura e identificar partes interessadas
	planejar: plano de gerenciamento do projeto, criar WBS e iterações, atividades, recursos, cronograma, custo, orçamento, qualidade, 
			  plano de recursos humanos, comunicações, riscos e respostas, aquisições, integração
	monitorar
	e controlar: integração, escopo, tempo, custos, qualidade, riscos, aquisição

	encerrar: integração, comunicação, aquisição

Prince2 (projects in controlled environments 2) - 12 - ajuste ao ambiente de trabalho
	- método estruturado de gerência de projetos
	- justificação continuada (ativa e válida - documentada no caso de negócio), 
	  aprender com experiência (lições aprendidas registradas a cada ciclo - documentada no diário de lições), 
	  papeis e responsabilidades definidos (cada participante sabe exatamente o que tem de cuidar), 
	  gerenciar por estágios (compatível com ciclos iterativos - objetivos cumpridos por estágios), 
	  gerenciar por exceção (limites de tempo, custo, qualidade, escopo e risco - se furado, nível maior de gerência de procedência), 
	  foco nos produtos (foco na entrega com qualidade ), 
	  ajuste ao ambiente de trabalho (Prince2 deve ser personalizado para se adequar ao ambiente de trabalho)

Condução de projeto de software
	- Pq um projeto falha, mesmo que bem planejado?  Erros da equipe, no próprio projeto, na concepção do processo, fatores imprevistos
	- Maior desafio do gerente? Indisciplina, membros não seguem padrões, prazos ou prioridades.
	
	Perfis de gerência: 
		- Ditador: planeja e estima tudo, determina tudo
		- Coordenador: planeja e prevê com equipe, diagramas Gantt levados à sério. Bom com métodos prescritivos!
		- Facilitador: agiliza e facilita trabalho da equipe, não toma decisões, equipe planeja. Bom com métodos ágeis!

	Objetivos:
		- confrontar resultados e desempenhos reais contra o plano.
		- ações corretivas caso a existe grande discrepância entre objetivos reais e ideias.
		- acompanhar quanto à eficácia.

	Técnicas:
		- folha de tempo
		- acompanhamento de problemas
		- registro de artefatos

	Folha de tempo
		- acompanhamento e registro das atividades realizadas pelos desenvolvedores
		- contém ações dos desenvolvedores ao longo do dia (métodos, diagramas, entrevistas)
		- o que vc fez em métodos de programação!!
	
	Acompanhamento de  problemas
		- dificuldade: processo de software não tão bem definido à priori qto o de outros processos de engenharia
		- controle eficiente de problemas, bem como suas causas (pq não fazer no Clara e na UnBeatables?)
		
		Possibilidades de problemas apontados pelos usuários:
			- Se urgente: parar uma equipe para resolver
			- Se real não urgente: entra na lista de problemas da versão corrente, e na de modificações solicitadas. No proximo artefato
				deve estar resolvido
			- Se real não atualizado: usuário deve atualizar versão 
			- Não real: dicas 

		FAP - folha de acompanhamento de problema
			- documento de problemas identificados, origem (cliente/desenvolvedores), localização (quem/setor responsável), estados, 
			  que podem ser:
				- aguardando análise, em análise, aguardando solução, em solução, aguardando complemento, aguardando aprovação, resolvido

	Registro de artefatos
		- controle de problemas depende de bom controle de versões
		- acesso por outros desenvolvedores de um artefato só quando liberado pelo proprietário
		- após, submissão de artefato à controle de qualidade
		- se passou, salvo no sistema de gerenciamento de configuração

Medição
	- Como saber que tarefa não sendo feita? que qualidade inaceitável? Uso de métricas
	- Medida, métrica, medição
	- Uma boa métrica: simples, objetiva (n depende de opniões), facilmente obtida, válida, robusta
	- Métricas diretas: custo financeiro, esforço desenvolvedor/hora, linhas de código, vel de execução, memória, defeitos 
		localizados, complexidade ciclomática (quantidade de caminhos de execução independentes a partir de um código fonte).
	- Métricas indiretas: funcionalidade, qualidade, complexidade, eficácia, confiabilidade, manutenibilidade, usabilidade

	Agrupamento por utilidade para gerente
		- Produtividade: custo, esforço e defeitos localizados
		- Qualidade: defeitos, qualidade, eficácia, confiabilidade, manutenibilidade
		- Técnicas: complexidade ciclomática, modularidade, paralelismo, distribuição

	Absolutas ou relativas
		- Um sistema com 5 erros não é pior que um de dois (erros por linhas)
		- relativizar métricas: pelo tamanho, pela funcionalidade, tempo, esforço

	Úteis ao gerente
		- de defeitos, de confiabilidade, de manutenibilidade
	
	Identificar e coletar dados
		- especificidade dos dados, obtenção de dados, manutenção do banco de dados, previsões de esforço e custo

	Iniciar programa de métricas
		- Esclarecimento de uso, pessoal responsável

	Avaliação do programa
		- de Resultados, de ajuste do modelo


Revisão e avaliação
	- Reuniões planejadas com antecedência
	- Pessoal avisadas e objetivos esclarecidos (artefatos de saída da reunião)

	Sugestões:
		- marcos alcançados, desvios, modificações de esforços, despesas de atividades, se houve mudança no escopo, mudança de métrica, 
		  status dos riscos, riscos identificados, andamentos de ações de reuniões passadas, lições aprendidas para projetos futuros.

Fechamento
	- formalizar entrega do produto e aprovação pelo cliente 

Pontos na reunião de fechamento
	- objetivos iniciais alcançados? Desvio importante? Medidas de esforços foram corretas? Recursos alocados suficientes? 
	- Mudanças de escopo importantes? Resultados das métricas? Riscos de operação? Problemas surgidos não resolvidos? Lições aprendidas? 

cap 14
	- Lei de Lehman, complexidade crescente, tipos de estimar, 
	- o que é evolução adaptativa, quais os tipos de evolução, 
	- leis de evolução

14) Manutenção de software

Manutenção: adaptação e otimização de um sotware já desenvolvido (correção de defeitos)
			manter qualidade ao longo do tempo
			também chamado evolução de software

Com o tempo, um software perde o seu valor:
			- falhas são descobertas
			- requisitos mudam
			- produtos mais eficientes são disponibilizados
			A manutenção é a adaptação do software para acodar estas novas coisas

Leis de Lehman - sobre evolução de software
	- Sistema tipo-S: especificados formalmente (correções de especificações provados formalmente)
	- Sistema tipo-E: desenvolvidos pelos processos usuais de análise, projeto e codificação (não gerados por métodos formais)

	1. Lei da mudança contínua: 
		- um sistema efetivamente usado deve ser continuamente melhorado, senão acaba sendo substituído
		- programas grandes nunca são terminados, simplesmente evoluem

	2. Lei da complexidade crescente: 
		- quanto mais evolução, mais a complexidade aumenta. Correções podem deteriorar a organização interna: 
		  refatoração corrige estes problemas

    3. Lei fundamental da evolução de programas: 
    	- esforço gasto nas diferentes atividades deve permanecer distribuído de forma normal

    4. Lei da conservação da estabilidade organizacional: taxa de trabalho invariante
    	- taxa média de trabalho não varia no tempo
	
	5. Lei da conservação da familiaridade: complexidade percebida
		- familiaridade pelos membros sobre o programa é perdida à medida que ele evolui

	6. Lei do crescimento contínuo
		- conteúdo funcional do sistema deve crescer continuamente (satisfação do usuário)
		- mudança é sempre necessário: corrigir erros, aperfeiçoar funções, adaptar a novos contextos

	7. Lei da qualidade descrescente
		- Com tempo, usuários vão ficando insatisfeitos com o software

	8. Lei do sistema realimentado
		- retroalimentado: complexo que recebe feedback constante dos vários interessados

Classificação das atividades de manutenção
	- Corretiva: corrigir erros (erros conhecidos, novos erros)
	- Adaptativa: adaptar a novos requisitos (novas funções ou outros)
		- aos permanentes, é barato incorporar, difícil manter. Aos transitórios, o contrário
	- Perfectiva: melhorar desempenho sem alterar funcionalidade (em função de pressão do mercado)
	- Preventiva: para encontrar erros mais facilmente (reengenharia)

Processo de manutenção
	- análise de esforço para manutenção, análise de risco para manutenção, planejamento de prazos e recursos, execução

Norma ISO 1219-98
	- Classificação e identificação da requisição de mudança: também recebe indicador de urgência
	- análise: casos de uso, artefatos, ...
	- designe: camadas de interface, persistência, comunicação
	- implementação: código, testes de unidade e itegração
	- teste de sistema: ponto de vista do usuário
	- teste de aceitação: cliente aprova ou não? 
	- entrega: novo ambiente

Ferramenta para manutenção de software
	- Bugzilla: sistemas de rastreamento de defeitos (usado por grandes corporações como NASA)

Tipos de atividades de manutenção e métricas
	- atividade de maior esforço das empresas
		- reparação de defeitos (número de defeitos reparados em um mês)
	- fatores: 
		- defeitos suspensos (10% vezes, "na minha máquina funciona" )
		- inválidos (15% vezes, erros dos próprios usuários)
		- ruins (7% das correções introduzem novos erros)
		- duplicados (10%)

Remoção de módulos sujeitos a erros 
	- erros tendem a se concentrar em determinados módulos

Suporte a usuários
	- usualmente recebe reclamações dos usuários

Migração entre plataformas
	- demanda de cliente, aumentar mercado

Conversão de arquitetura
	- geralmente por pressão tecnológica, manutenibilidade do sistema

Adaptações obrigatórias
	- prazo estrito e penalidades altas

Modelos de estimação de esforço de manutenção
	- ACT (porcentagem de linhas de código que sofreram manutenção) -> E = ACT*SDT
	- COCOMO 
	- FP e SMPEEM (FP unicamente em pontos de função - adicionadas, alteradas, removidas, conversão)
				  (o SMPEEM inclui mais 10 fatores, conhecimento, familiaridade, experiência, estruturação, independência, legibilidade, 
				   reusabilidade, atualização, conformidade)

Taxionomia de Chikofsky e Cross 2
	- 
	- engenharia direta: normal, mais alto nível à executável
	- engenheria reversa: exame e explicação
	- redocumentação :formas alternativas de artefato
	- recuperação de projeto: produzir artefatos de nível mais alto
	- reestruturação: refatoração
	- reengenharia: reconstrução de forma diferente

Técnicas de engenheria reversa no código
	- análise de fluxo de dados: análise como caixa preta
	- dessassemblagem: conversor de código executável em mnemônicos assembly  
	- descompilação: obter aproximação do código original usado para produzir o executável

Descompilador
	- carregador
	- desassemblador
	- identificador de expressões idiomáticas
	- análise de programa
	- análise de fluxo de dados
	- análise de tipos
	- estruturação
	- geração de código

cap 11, 12
- CMMI, GQM, 
- diferenças de engenharia reversa, reengenharia, 
- tipos de qualidade


11) Qualidade

ISO 25010:2011
	- Adequação funcional : completude, corretude, funcionalidade apropriada
	- confiabilidade : maturidade, disponibilidade, tolerância a falhas, recuperabilidade
	- Usabilidade : apropriação reconhecível, inteligibilidade, operabilidade, proteção contra erro de usuário, estética de interface 
					com usuário, acessibilidade
	- Eficiência de desempenho : comportamento em relação ao tempo, utilização de recursos, capacidade
	- Segurança : confidencialidade, integridade, não repúdio, rastreabilidade de uso, autenticidade
	- Compatibilidade: coexistência, interoperabilidade
	- Capacidade de manutenção: modularidade, reusabilidade, analisabilidade, modificabilidade, testabilidade
	- Portabilidade: adaptabilidade, Instalabilidade, substituibilidade
	- Efetividade
	- Eficiência
	- Satisfação: utilidade, prazer, conforto, confiança
	- Uso sem riscos: mitigação de risco econômico, à saúde e segurança, ambiental
	- Cobertura de contexto: completude de contexto, flexibilidade

Modelo GQM
	- Goal/Question/Metric
	- Níveis:
		- Conceitual (objetivo): objetivo definido para objeto por uma variedade de razões  
		- Operacional (questão): conjunto de questões é usado para definir modelos de objetos de estudo
		- Quantitativo (métrica): conjunto de dados baseados nos modelos é associado a cada questão para respondê-la de forma quantitativa

12) Qualidade de processo
	
CMMI - Capability Maturity Model Integration
	- melhoria de processos de acordo com norma ISO 15504
	- sucessor do CMM 
	- representação contínua: focar em processos específicos que e empresa deseja melhorar em função de suas prioridades (CAPACIDADE)
	- representação em estágios: permite que se compare a maturidade de diferentes organizações (MATURIDADE)

	- Níveis de capacidade:
		- 0 - incompleto: não existem objetivos genéricos
		- 1 - realizado: seguido, mas não institucionalizado
		- 2 - gerenciado : planejamento e política definidos, monitorado, revisado e controlado, porém ainda bem heterogêneos
		- 3 - definido: segue regras de processo

	- Níveis de maturidade
		- 1 - inicial: processos ad-hoc e caóticos, abandonos e dependências individuais
		- 2 - gerenciado : planejados e executados com política, 
		- 3 - definido : padrões de processos
		- 4 - quantitativamente gerenciado : qualidade de processo
		- 5 - em otimização : continuamente melhorada

MPS.BR - Modelo de referência para melhoria do Processo de Software
	- modelo independente, mas compatível com normas ISO 12207 e 15504, bem como com o CMMI
	- devido ao custoso modelo internacional para pequenas e médias empresas
	- apresenta 7 níveis de maturidade

	- Níveis de maturidade
		- A - em otimização 
		- B - gerenciado quantitativamente
		- C - definido
		- D - largamente definido
		- E - parcialmente definido 
		- F - gerenciado
		- G - parcialmente gerenciado