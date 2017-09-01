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

// FCC
- UML 1.1 (ISO/IEC 19501:2005)
- É tão expressiva que pode modelar outras sistemas, não só software

- OCL 'linguagem formal para especificar restrições sobre elementos do modelo'

- Especificações UML
	- Infraestrutura
	- Superestrutura
	- OCL
	- Intercâmbio

- Mecanismos de uso geral
	- Estereótipo 'aumentar as capacidades da linguagem'
		- predefinidos ou definidos pelo usuário '<<interface>>, <<document>>, <<control>>, <<entity>>'
		- textuais ou gráficos
	- Notas Explicativas 'info que comenta ou esclarece'
		- retângulo com ponta dobrada
	- Tagged Values 'para definir outras propriedades para elementos'
	- Restrições 'estender ou alterar a semântica natural de um elemento gráfico'
		- formal ou informal
		- chaves dentro das notas explicativas
	- pacotes

- Arquitetura de Engenharia de Software
	- Visão de Casos de Uso 'consistência e validade do sistema - casos de Uso'
	- Visão Lógica 'requisitos funcionais - classe, objetos, pacotes'
	- Visão de Desenvolvimento 'organização estática dos módulos - componentes'
	- Visão de Processos 'requisitos não-funcionais - sequência, estrutura composta, máquina de estados, atividade'
	- Visão Física 'topologia físicas dos componentes - implantação e componentes'

- Modificadores
	- público '+' 
	- protegido '#'
	- pacote '~'
	- privado '-'

- Diagramas UML 2.4.1
	- #Estruturais 'estático - não leva tempo em consideração'
				   'representam aspectos estáticos do sistema sob diversas visões diferentes'
	'Cláudio Está Com o Objetivo Implícito de Persistir no Pacífico'
		
		- Classe 'Classe, Interface, Relacionamentos - Camera ou android.hardware::Camera'
		"formato já conhecido, caixas com duas divisórias ou três (nome classe, atributos, métodos), relacionamentos com setas e diamantes"
			- Relacionamentos
				- Dependência 'seta tracejada para classe independente <include> e <extend> - mudança de elemento independente causa mudança a outro dependente'
				- Generalização/Especialização/Herança 'seta sólida com ponta que aponta para superclasse - é-um - subclasse é especialização da superclasse'
				- Realização 'seta pontilhada com ponta para interface - um elemento executa/implmenta comportamento que outro elemento especifica'
				- Associação 'especifica objetos de uma classe ligados a objetos de outra classe'
					- Simples 'seta sólida dupla - uma instância de um elemento está ligada à instância de outro elemento'
					- Qualificada 'linha sólida com retângulo na classe de cardinalidade 1 - 
							como a simples porém com qualificador capaz de identificar uma instância dentre as demais - ocorre em 1-N ou N-M'
					- #Agregação 'linha sólida com diamante vazio na classe agregadora - o todo é relacionado às suas partes de forma independente' INDEPENDENCIA
					- #Composição 'linha sólida com diamante cheio na classe agregadora - agregação em que as partes não existem sem o todo' DEPENDENCIA
			- Considerações
				- classe abstrata 'representada em itálico'
				- classe concreta 'representada normal'
		
		- Estrutura Composta
		"possui nomes com dois pontos nas caixas, comunicações sem direção que possuem a palavra :Bus nas linhas"
			- Para mostrar como os objetos são compostos em tempo de execução
			- Modelar colaborações internas de classes, interfaces e componentes para especificar uma funcionalidade
		
		- Componente 
		"grandes caixas com caixas dentro, tem um livrinho no canto superior direito e muitos bolas e quadrados nas relações"
		"pode ter <<table>> e <<executable>>"
			- Expondo a organização de seus módulos e as relações entre seus componentes por meio de interfaces
			- Os componentes podem ser tabelas, documentos, etc
			- Um componente pode apresentar um estereótipo, i.e., uma definição do que é este componente
			- Quiser representar seus relacionamentos por intermédio de interfaces
		
		- Objetos
		"como o de classe, mas só com setas comuns com um X no início e os atributos aparecem com valores e nome vem com dois pontos antes ou no meio (nome classe:objeto)"
			- No diagrama de objetos, personaliza-se cada instância com seus valores
			- Elementos de um diagrama de objetos são especificações de instâncias, em vez de instâncias verdadeiras
			- novoCliente:Cliente
		
		- Implantação
		"caixas de pacotes enormes com caixas de componentes dentro"
		"<<manifest>> - quando um esteriótipo se manifesta em outro"
		"pode ter <<folder>>, <<file>>, <<library>>, <<component>>"
			- Apresenta layout físico de um sistema, revelando quais partes do software são executadas em quais partes do hardware
			- Os itens principais do diagrama são nós conectados por caminhos de comunicação. Um nó é algo que pode conter algum software
			- Preocupar com a configuração e topologia dos elementos de software sobre os elementos de hardware
		
		- Perfil
		"contém folhas com a orelha dobrada e setas comuns em sua maioria"
		"muitos esteriótipos, sendo <<Metaclass>>, <<stereotype>>, parece mais um diagrama de estereótipos"
			- Trata-se de uma UML com um conjunto de estereótipos predefinidos, valores atribuídos, restrições e classes de base
			- Permite representar esses novos elementos, operando no nível de metamodelos.
			- Imaginem que eu quero utilizar a UML para representar uma rede de computadores
			- Detalhe: um modelo tipicamente contém elementos que são instanciados a partir de um metamodelo
		
		- Pacotes
		"retângulos com retângulo encaixado na ponta superior esquerda e só tem seta tracejada"
			- "<<merge>> - merge de pacotes" 
			- "<<use>> - dependencia de uso" 
			- "<<access>> - importe privado" 
			- "<<import>> - importe publico"
			- Ele representa os pacotes e suas dependências
			- Pacotes ilustram a arquitetura de um sistema como um agrupamento de classes em um alto nível de abstração
			- Ajuda a manter as dependências de uma aplicação sob controle
	
	- #Comportamentais 'dinâmico - leva tempo em consideração'
					   'representam aspectos dinâmicos do sistema como um conjunto de mudanças'
	'O Ativista Internacional Comunicou o Tempo do Casório ao Maquinista Sequelado'
		
		- Atividades 'lógica de procedimento, processo de negócio e fluxos de trabalho' CAI MUITO
		"igualzinho um diagrama de fluxo de código, retângulos arredondados, diamantes como ifs, bola escura como início da execução"
		"suporta comportamento paralelo"
		"se concentra em mostrar o que acontece, mas não quem faz o que"
			- Descreve lógica de procedimento, processo de negócio e fluxos de trabalho
			- Diagrama de atividades tem um nível de abstração maior
			- Agrupa as atividades e as organizam de acordo com suas respectivas responsabilidades, com o auxílio de ações, bifurcações, fluxos e ramificações
			- É a sincronização de dois ou mais fluxos de controle concorrentes
			- Isso os torna uma excelente ferramenta para modelagem de fluxos de trabalho e de processos
				'retangulo com cantos arredondados' indica a atividade
				'retangulo perfeito' são as notas. Notas são úteis para adicionar informações mais detalhadas sobre um objeto ou situação específica. 
				'losango invertido/rombóide vazio' branch/merge: indica uma ramificação.
				'linha sólida' indicam a transição da atividade
				'circulo preenchido preto' indica uma atividade inicial
				'circulo preenchido preto com contorno' indica o fim das atividades
				'circulo com X' indica o final de uma atividade
		
		- Casos de Uso
		"tem muitos atores stickman, elipses e setas de relacionamentos"
		"podem representar vários casos de uso"
		"podem ter vários atores, cujo número varia em relação ao número de casos de uso"
		"atores representados por stickman ou retângulo com esteriótipo <<actor>>"
		"visa dar um comportamento do sistema como um todo"
			- "<<includes>> - relacionamento obrigatorio"
			- "<<extend>> - relacionamento opcional"
			- Técnica para captar os requisitos funcionais de um sistema
			- Cenário é uma instância de caso de uso, i.e., uma sequência de passos que descreve uma interação entre um usuário e o sistema
			- Diagrama de Casos de Uso descreve um conjunto de funcionalidades do sistema e interações com elementos externos e entre si
			- Um caso de uso conta uma história sobre como o usuário final interage com o sistema sob um conjunto de circunstâncias específicas
			- Há Casos de Uso Concretos e Abstratos
			- Quando um caso de uso concreto é iniciado, uma instância do caso de uso é criada
				- Atores - stickman
				- Relacionamentos
					- Comunicação 'ator se comunica com o sistema por meio do envio e recebimento de mensagens'
						- linha sólida no sentido do ator (Usuário) para o caso de uso (Navegar)
					- Inclusão 'um mesmo comportamento se repete em mais de um caso de uso'
						- para realizar um pagamento ou visualizar o saldo, é obrigatório que fazer Login
					- Extensão 'quando se deseja modelar um relacionamento alternativo'
						- para cadastrar um usuário, há duas opções: moderador ou administrador
					- Herança 'utilizado quando o ator filho é um uma especificação do ator genérico'
						- Vendedor é especialização de Pessoa
						- definir sobreposição de papéis entre atores e é representado com uma linha sólida com um triângulo no ator genérico
		
		- Máquina de estados / ou Modelo de estados / ou Estados
		"muito parecido com diagrama de atividades, mas existem métodos nas setas indicando ações, retângulos arredondados"
			- Apresenta diversos estados possíveis de um objeto no decorrer da execução de processos de um sistema
			- Não mostra a interação entre objetos. Geralmente, ele mostra estados possíveis de um objeto específico
			- Permite representar o ciclo de vida de objetos e como eles são afetados por eventos como erros, mensagens e condiçõe
			- Bons mesmo para descrever um comportamento que envolva vários objetos em colaboração
		
	
		- ##Interação 'comportamental para relacionamento e controle de fluxo'
					  'diagramas comportamentais que consideram o relacionamento dinâmico e colaborativo entre os objetos do sistema e suas trocas de informações'
		'Internacional Comunicou o Tempo Sequelado'
			
			- Interação Geral
			"diagramas diferentes um dentro do outro, muito informação e confuso"
				- Fornece uma visão geral do controle de fluxo entre objetos e engloba diversos tipos de diagramas de interação para demonstrar um processo geral.
				- Tem o objetivo de dar uma visão geral dos diversos cenários de um caso de uso
				- Diagramas de atividades nos quais as atividades são substituídas por pequenos diagramas de sequência
			
			- Comunicação 
			"tem autor, retângulos perfeitos com dois pontos, relacionamentos tem método e uma numeração de ordenação"
			"complementa o diagrama de sequência, mas com enfoque nas mensagens e não tempo"
				- Semelhante ao diagrama de sequência, mas com ênfase na ordem estrutural e, não, temporal
				- Geralmente, utiliza-se o diagrama de sequência para cenários mais complexos e o diagrama de comunicação para cenários mais simples
			
			- Tempo
			"tempo representado horizontalmente, separado num grid de retângulos, setas sobem e descem no grid"
				- Descreve o comportamento dos objetos no decorrer do tempo e a duração na qual eles permanecem em determinados estados
				- Para demonstrar a mudança no estado de um objeto no tempo em resposta a eventos externos
			
			- Sequência 'sequência temporal, linha da vida, comportamento de cenário e colaborações entre objetos' CAI MUITO
			"tempo de cima para baixo, espaçamento irrelevante"
			"não mostra sincronização exata de mensagens"
			"tempo em vertical, cada seta tem um método ou esteriótipo"
			"mostra um conjunto de papéis e as mensagens enviadas e recebidas pelas instâncias que representam os papéis"
			"pode vir com ordenação das mensagens!"
			"complementa o diagrama de comunicação, mas com enfoque no tempo e não nas mensagens"
			"<<ajax>>, <<callback>>, <<create>>"
				- Captura o comportamento de um único cenário, mostrando vários exemplos de objetos e mensagens que são trocadas dentro de caso de uso
				- Possui dois eixos: horizontal (objetos envolvidos) e vertical (tempo/linha da vida)
				- Esse diagrama mostra a sequência temporal de mensagens trocadas entre objetos em um sistema
				- Eles são bons para mostrar as colaborações entre os objetos, mas não são tão bons para uma definição precisa do comportamento
		
		
- Modelos
	- Classes 'descreve a estrutura dos objetos - sua identidade, seus relacionamentos com outros objetos, seus atributos e suas operações'
	- Estados 'descreve os aspectos dos objetos que tratam do tempo e da sequência de operações - eventos que marcam mudanças, estados que definem o contexto para eventos'
	- Interações 'descreve como os objetos individuais colaboram para alcançar o comportamento do sistema como um todo'


// 7%  Conceitos sobre orientação a objetos (classes, atributos, objetos, métodos, herança, interfaces e outras hierarquias)

// FCC

Interface 
	- possui todos os métodos abstratos
	- não possui constantes, variáveis ou atributos
	- não é instânciável
Classe abstrata 
	- possui métodos abstratos ou concretos, pode haver só com métodos concretos
	- não é instânciável
Classe concreta
	- só tem métodos concretos e implementa tds os métodos abstratos da superclasse
	- é instânciável

- Abstração
	- generalização por redução do conteúdo para reter apenas informação relevante
	- 
	- 

- Encapsulamento CAI MUITO
	- Protege os dados do objeto do uso arbitrário e não-intencional
	- atributos privados e métodos getters e setters públicos
	- Alterar estado de objeto apenas pelos seus métodos, mantendo ambos isolados
- Classe
	- Especifica uma estrutura de dados e as operações permissíveis que se aplicam a cada um de seus objetos
- Objeto 
	- Pode ser real ou abstrato; Possui informações (dados) e desempenha ações (funcionalidades)

- Herança múltipla
	- Java não permite herança múltipla
- Sobrecarga 'mesmo nome, parâmetros diferentes'
	- uma classe pode conter vários métodos com o mesmo nome, se recebem parâmetros diferentes
	- Subclasse pode sobrecarregar métodos de superclasse e também dela mesma
- Sobrescrita 'mesma assinatura'
	- Subclasse pode sobrescrever métodos de superclasse, mas não dela mesma
	- Precisa de herança
- Polimorfismo

- Protegido
	- método protegido pode ser acessado de classes que estão no mesmo pacote

- Teste de unidade
	- um método herdado por polimorfismo deve ser testado em cada subclasse

- Acoplamento
	- medida do grau de dependência que existe entre os objetos
	- 'Pressman'Acoplamento é uma medida qualitativa do grau em que as classes estão conectadas entre si



- Análise 'Modelagem do problema'
	- com foco no cliente
	- a tecnologia de implementação e os requisitos não-funcionais não são modelados

- Projeto 'Modelagem da solução'
	- com foco no programador
	- modelo a Arquitetura do Sistema

- Modelos
	- de Classes de Análise/Domínio 'Análise'
	"Identificar Classes" - quais são de fronteira, controle ou entidade
	"Identificar Responsabilidades" - cada classe deve ser especialista em realizar uma tarefa específica
	"Identificar Atributos" - descobrir quais são os atributos, sem nenhuma preocupação sobre qual seu tipo
	"Indentificar Relacionamentos" - como associações, agregações, composições, dependências, generalizações, especializações
		- contruido durante a análise
		- representa as classes de domínio do negócio
		- Não leva em consideração restrições inerentes à tecnologia a ser utilizada na solução de um problema
		- mais estável que o Modelo de Projeto

	- de Classes de Especificação/Projeto 'Projeto'
	"Arquitetura de software" - baixo acoplamento e alta coesão/ baixa dependencia e alta responsabilidade
	"Estrutura de classes" - organizar em camadas, como MVC
	"Comportamento de classes" - mudanças em uma camada mais baixa, que não afetem a sua interface, não implicarão mudanças nas camadas mais superiores
		- construído durante o projeto
		- estende o modelo de classes de análise e contém detalhes específicos inerentes à solução de software escolhida

	- de Classes de Implementação
		- construído durante a implementação
		- estende o modelo de classes de projeto e contém detalhes específicos inerentes ao desenvolvimento das classes em alguma linguagem

- Análise de Robustez por Ivar Jacobson
	- Classe de Fronteira 'modelar a interação entre um ator e o sistema'
	"comunicar-se com atores"
		- envolve transformar e converter eventos, bem como observar mudanças na apresentação do sistema
		- alterar a GUI ou o protocolo de comunicação significa alterar somente as classes de fronteira, e não as classes de entidade e de controle
		- também são úteis para capturar interfaces para APIs com código legado
		- um objeto de fronteira poderá durar mais que uma instância de caso de uso, porém costumam ter a mesma duração

	- Classe de Controle 'para controlar a lógica de execução ou negócio correspondente a cada caso de uso'
	"coordenar a realização de um caso de uso"
		- Servem como uma ponte de comunicação entre objetos de fronteira e objetos de entidade
		- encapsulam um comportamento específico de caso de uso
		- controlam as principais tarefas e fluxos de controle

	- Classe de Entidade 'para armazenar a informação que é manipulada ou processada pelo caso de uso'
	"manter as informações do sistema"
		- armazenam informações persistentes
		- há várias instâncias ou objetos de uma mesma classe de entidade coexistindo dentro do sistema
		- são usados para manter e atualizar informações sobre alguns fenômenos
		- geralmente não é específico para uma realização de casos de uso

- Camadas
	- de Apresentação / View 'apresentação dos dados aos usuários, não persiste nem busca dados, só os renderiza'
		- possui classes que contêm funcionalidades para visualização dos dados pelos usuários
	
	- de Lógica de Negócio/ Controler 'definir o comportamento da aplicação, responder a eventos e validar dados do usuário'
		- possui classes que implementam as regras de negócio no qual o sistema será implantado
	
	- de Acesso / Model 'modelar os dados da aplicação e regras de negócio, objetos reusáveis, distribuídos, persistentes e portáveis'
		- possui classes que se comunicam com outros sistemas para realizar tarefas ou adquirir informações para o sistema
		- mecanismo de armazenamento persistente





























- JPA 'Java Persistence API'
	- API que descreve interface comum para frameworks de persistência de dados
	- Define um meio de mapeamento objeto-relacional para objetos Java simples e comuns (POJOs), denominados beans de entidade.
	- Diversos frameworks de mapeamento objeto/relacional como o Hibernate implementam a JPA
	- Também gerencia o desenvolvimento de entidades do Modelo Relacional usando a plataforma nativa Java SE e Java EE
	- É utilizado principalmente para conexão e acesso a banco de dados relacionais