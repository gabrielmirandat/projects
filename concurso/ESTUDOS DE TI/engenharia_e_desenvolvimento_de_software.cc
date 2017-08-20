// -- 20% Aspectos gerais das linguagens PHP, HTML5, XML, Java SE, Java EE, JUnit.

- HTML
- input
	- entrada de texto
	- id 'atributo para identificar e manipular texto'
- label
	- define uma label para o elemento input
	- provê usabilidade melhorada para usuarios de mouse, se clicar no texto ele clica no input também
	- for 'atributo deve ser igual a atributo id do elemento para dar bind'

- CSS
	- <p id="t1">TRT</p>
	  <p class="t2">11ª Região</p>
	  #t1, .t2{color:#ff0000} 'associa a cor vermelha aos dois paragrafos'
	  'exemplos válidos'
		  p {text-align: right; color: #BA2;}
	      p.minhaclasse01 { color:#ABC; }
	      .minhaclasse02 { color:#CAD; }
	      # iddomeuelemento { color:#ACD; }
	      p.minhaclasse03 .minhaclasse04 { color:#ACD; }
	- # se refere a id
	- . se refere a class


- Java SE

- (JEE/J2EE) 
- Java Enterprise Edition,  Plataforma Java
- coleção de tecnologias e APIs para aplicações de empresas, ou seja, grande escala, distribuidas, transacionais, 
  boa disponibilidade para suportar requisitos criticos de negocios
- inclui todas as funcionalidades do Java SE mais funcionalidades necessarias para desenvolver aplicações em ambiente corporativo
- JCP é um processo formalizado que permite que partes interessadas se envolvam nas definições de versões futuras e funcionalidades da plataforma Java

- Containers
	- a arquitetura Java EE independente de plataforma e baseada em componentes, que torna aplicações Java EE faceis de escrever usando lógica de componentes reusáveis
	- O servidor Java EE prove serviços na forma de containers para todos os tipos de componentes
	- Container é a interface entre uma componente e a plataforma de baixo-nivel que a suporta
	- Antes que possa executar, uma aplicação web, enterprise bean ou componente cliente deve ser montada num módulo Java EE e botada em produção no seu container
	- (EJB) - Enterprise Java Bean é um componente JEE que roda num container num servidor de aplicação
	- Como a arquitetura JEE prove serviços configuraveis, componentes da mesma aplicação podem se comportar diferente baseado em onde são botadas em produção
	- Uma EJB pode fornecer configurações de acesso a banco de dados diferentes para ambientes de produção diferentes
	- O container também gerencia serviços não configuraveis, como enterprise bean e ciclos de vida servlet, conexão de banco com pooling de recurso, persistencia de dados
	
	- containers e servidores JEE
		- 'MÁQUINA CLINTE (2 itens)'
			
			- CLIENT CONTAINER
				- gerencia a execução de componentes do cliente (clientes da aplicação e seus containers rodam no cliente)
			
			- WEB BROWSER
		
		- 'SERVIDOR JEE (2 itens)'
			- porção runtime do JEE 
			
			- WEB CONTAINER (3 itens)
				- gerencia a execução de páginas JSP e componentes servlets (componentes web e seus containers rodam no servidor JEE)
				
				- SERVLET
					- programas que rodam na web ou servidor de aplicação e agem como camada entre request de browser ou cliente HTTP e bancos ou aplicações de servidor HTTP
					- você pode coletar entrada de usuário, mostrar registros de um banco, criar páginas dinâmicas
					- é HTML em java
					- rodam mais rapido que JSP
					- é programa java já compilado que cria conteudo web dinâmico
					- é CONTROLLER
				
				- PÁGINAS JSP
					- tecnologia para criar páginas dinamicas com HTML e XML, similar a PHP
					- para por em produção e rodar, é necessário um servidor web compatível com servlet container, tais como Apache Tomcat ou Jetty
					- contem dois tipos de texto, HTML e XML como dados estáticos e elementos JSP como dados dinâmicos
					- tecnologia para desenvolver páginas dinâmicas que suporta conteudo dinâmico
					- é java em HTML usando tags JSP especiais, começando com <% e terminando com %>
					- é linguagem de script que gera conteudo dinâmico
					- é VIEW
				
				- PÁGINA WEB
			
			- CONTAINER EJB (sem item)
				- gerencia a execução dos enterprise beans para aplicações JEE (enterprise beans e seus containers rodam no servidor JEE)
				- 2 enterprise bean ou beans de sessão
				- é MODEL
		
		- 'BANCO DE DADOS'
			- classes de entidade
		
		- 'APPLET CONTAINER'
			- gerencia a execução de applets
			- consiste de um web browser com um plugin java rodando juntos no cliente

- JUnit,  Frameworks Java
- framework java para realizar testes de unidade	

//-- 17% Análise e projeto orientados a objetos (UML).

- Diagramas UML 2.5
	- 'DIAGRAMAS ESTRUTURAIS (6 tipos)'
		- aspecto estrutural tanto do sistema quanto classes
		- esqueleto e estruturas relativamente 'estáveis' do sistema
		- classes, interfaces, colaborações, componentes

		- DE CLASSES
			- representar estruturas de classes de negócio, interface, de controle
			- considerado o mais importante, serve de apoio para a maioria dos demais diagrama-
			- representa coleção de classes e seus inter-relacionamentos
			ex. quadros com três divisões, sendo nome, atributos, métodos, as relações são como em bancos de dados, 1,1; 1,N; ..

		- DE OBJETOS
			- representa objetos em diagrama de classes em instante do tempo
			- representa instancias e relacionamentos
			- modelagem da visão estática do projeto do sistema
			- é um retrato em tempo de execução dos objetos do software e seus inter-relacionamentos
			ex. quadros com duas divisões, sendo nome do objeto:classe e seus atuais atributos da classe a que pertence

		- DE COMPONENTES 
			- artefatos de que os componentes são feitos
			- código fonte,  bibliotecas de programação ou tabelas de bancos de dados
			- modelar software baseado em componentes
			- indicar os componentes do software e seus relacionamentos
			- coleção de componentes de software e seus interrelacionamentos
			ex. relações de nomes de arquivos e bibliotecas

		- DE IMPLEMENTAÇÂO/INSTALAÇÂO/IMPLANTAÇÃO/DEPURAÇÃO
			- organização do conjunto de elementos de um sistema para sua execução
			- mostra layout físico do sistema relacionando software e hardware
			- enfoca estrutura física onde software sera implantado e executado no hardware
			- como máquinas estarão conectadas e protocolos de comunicação
			- seus elementos são os nós e os caminhos de comunicação
			- mostra como uma coleção de componentes são distribuidos em vários nos de hardware

		- DE PACOTES
			- tem pacotes 
			- relacionamentos entre pacotes 
			- representa coleção de outros elementos de modelagem e diagramas
		
		- DE ESTRUTURA COMPOSTA
			- para modelar colaborações
			- uma colaboração descreve uma visão de um conjunto de entidades cooperativas

	- 'DIAGRAMA COMPORTAMENTAL (5 tipos no 2.5, 4 tipos no 2.0)'
		- vizualizar, especificar, construir e documentar aspectos 'dinâmicos' de um devido sistema
		- itens que passam por alteração, como fluxo de mensagem ao longo do tempo

		- DE CASOS DE USO
			- casos de uso são narrativas em texto, descrevendo a unidade funcional, usados para representar requisitos funcionais nos sistemas 
			- organiza os comportamentos do sistema
			- mostra um conjunto de casos de uso e atores e seus relacionamentos
			- representa conjunto de comportamentos de alto nível que o sistema deve executar para um determinado autor
			- para organização e modelagem dos comportamentos de um sistema
			- includes representa obrigatoriedade de realizar determinada ação
			- extends indica que é opcional
			ex. autor: usuário
				casos de uso: consultar cliente, consultar fornecedor, cadastrar fornecedor, ...

		- DE ESTADOS
			- enfatiza o estado de mudança de um sistema orientado por eventos
			- mostra uma máquina de estados, que consiste de estados, transições, eventos e atividades.
			- para ilustar a visão dinâmica de um sistema
			- para fazer a modelagem do comportamento de uma interface, classe ou colaboração
			- dão enfase ao comportamento de um objeto, solicitado por eventos, que é de grande ajuda para a modelagem de sistemas relativos
			- mostra o conjunto de estados que um objeto pode estar e os "gatilhos" que estimulam a transição de estados desse objeto
			ex. é uma máquina de estados

		- DE ATIVIDADES
			- enfatiza o fluxo de controle de uma atividade para outra
			- mostra o fluxo de uma atividade para outra em um sistema
			- mostra um conjunto de atividades, o fluxo em sequencia ou ramificado de uma atividade para outra e os objetos que realizam ou sofrem ações
			- para ilustrar a visão dinâmica de um sistema
			- fazer a modelagem da função de um sistema
			- dão ênfase ao fluxo de controle na execução de um comportamento
			- fluxo de tarefas que podem ser executadas pelo sistema ou por um ator
			ex. é um diagrama de fluxo de código, tem inicio, losando é if, fim
				item 1 - retangulo com cantos arredondados: indica a atividade
				item 2 - retangulo perfeito: são as notas. Notas são úteis para adicionar informações mais detalhadas sobre um objeto ou situação específica. 
				item 3 - losango invertido/rombóide vazio: branch/merge: indica uma ramificação.
				item 4 - linha sólida: indicam a transição da atividade
				item 5 - circulo preenchido preto: indica uma atividade inicial
				item 6 - circulo preenchido preto com contorno: indica o fim das atividades
				item 7 - circulo com X: indica o final de uma atividade

		- DE SEQUÊNCIA
			- enfatiza a ordem temporal das mensagens
			- diagrama de interação que dá ênfase à ordenação temporal de mensagens
			- mostra um conjunto de papéis e as mensagens enviadas e recebidas pelas instâncias que representam os papéis
			- para ilustrar a visão dinâmica de um sistema
			- representa perspectiva, orientada por tempo, da colaboração entre objetos

		- DE COMUNICAÇÃO/COLABORAÇÃO
			- enfatiza a organização estrutural de objetos que enviam e recebem mensagens
			- diagrama de interação que dá enfase a organização estrutural dos objetos que enviam e recebem mensagens
			- mostra um conjunto de papéis, as conexões existentes entre eles e as mensagens enviadas e recebidas pelas instâncias que representam os papéis
			- para ilustrar a visão dinâmica de um sistema
			- coleção de objetos que trabalham em conjunto para atender algum comportamento do sistema
			ex. grade com um campo sendo nome do objeto e relacionamentos sendo setas unidirecionais com ações/métodos

		- 'DE INTERAÇÃO NO 2.0'
			- DE SEQUÊNCIA

			- DE COMUNICAÇÃO/COLABORAÇÃO

			- DE INTERAÇÃO/VISÃO GERAL DE INTERAÇÃO 

			- DE TEMPO/TEMPORAL