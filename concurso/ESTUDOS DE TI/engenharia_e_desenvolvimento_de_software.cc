// -- 20% Aspectos gerais das linguagens PHP, HTML5, XML, Java SE, Java EE, JUnit.

- PHP 'permite criar páginas web dinâmicas'
	- HTML cria páginas estáticas
	- permite manipular página no servidor antes de ser entregue ao browser cliente
	- executado no servidor 
	- pode alterar ou gerar código HTML

	- 'página'
		- contém parte estática
			<!DOCTYPE html>
			<html>
			<head>..
		- contém parte dinâmica
			<?php 
				$nome = $_POST['nome']
				echo // adiciona conteúdo HTML dinâmico
			?>

	- 'superglobais'
		- variáveis acessadas por qualquer arquivo, classe, função
		->  $GLOBALS 'array que armazena todas as variáveis - $GLOBALS[indice]'
			$_SERVER 'infos do servidor, cabeçalhos, caminhos relativos, localização de scripts'
			$_REQUEST 'coleta dados após submissão de form HTML'
			$_POST 'retorna dados de form após submissão com post - usado também para passar variáveis entre páginas'
			$_GET 'retorna dados de form após submissão com get - coleta dados enviados pela URL'
			$_FILES 'fazer upload e recuperar arquivos'
			$_ENV 'recupera variáveis de ambiente no server'
			$_COOKIE 'recupera cookies no cliente'
			$_SESSION 'guarda variáveis e valores recuperáveis durante a sessão'

	- 'arrays'
		- guardar múltiplos valores - começa do índice 0!!
		- 'indexados' índices numéricos
			- $carros = array("Volvo", "BMW", "Toyota") // $carros[0]
		- 'associativos' chaves nominais
			- $idades = array("Pedro"=>"35", "Beto"=>"37", "Carlos"=>"43") // $idade['Pedro']
			- foreach($idade as $x_chave => $x_valor)
		- 'multidimensionais' com um ou mais arrays

		- tamanho do array
			- count() 'retorna tamanho de um array'
		- ordenação
			- sort()  'ordem crescente'
			- rsort() 'ordem decrescente'
			- ksort() 'associativo em ordem crescente de acordo com chave'
			- asort() 'associativo em ordem crescente de acordo com valor'
			- krsort() 'associativo em ordem decrescente de acordo com chave'
			- arsort() 'associativo em ordem decrescente de acordo com valor'

	- 'funções'
		<?php
		function foo ($arg_1, $arg_2, /*..., */ $arg_n)
		{
			echo "Exemplo de função. \n";
			return $valor_retornado;
		}
		?>

		- tipadas ou com tipos dinâmicos
		- $ = passagem por valor
		- &$= passagem por referência
			




- HTML5 'linguagem de marcação'
	- linguagem pois as tags são pre-definidas 
	- busca exibir dados com foco na aparência
	- usa 'HTTP'
	- roda no servidor e é acessada por 'URL'
	- não é 'case-sensitive'
	- XHTML é 'case-sensitive'
	- estrutura em duas partes - 'head' e 'body'
	- '<!DOCTYPE html>' - primeira linha - declara tipo do documento e versão da linguagem, não é tag
	- '<html> ... </html>' - envolve todo documento menos primeira linha
	- '!DOCTYPE' e '<title>' - obrigatórios no 'HTML5'
	- '<meta charset="utf-8"/>' - permite acentos língua portuguesa e diversas escritas - 80% das páginas usam
	- deu foco em acessibilidade e usabilidade
	- inclusão de elementos multimídea de vídeo e áudio com suporte nativo
	- suporte de armazenamento local com sessionStorage e localStorage
	- total suporte a CSS3
	- suporte offline com Application Cache
	- PAG 33

	- '<head>'
		- <title>
			'título da janela'
		
		- <style>
			'estilo do doc'
		
		- <base>
			'endereço base'
		
		- <link>
			'link fonte externa'
		
		- <meta>
			'metadados do doc'
		
		- <script>
			'script client-side (javascript)'
		
		- <noscript>
			'conteúdo para não uso de scripts'

	- '<body>'
		- <p>..</p> 
			'paragrafo'
		
		- <q>..</q> 
			'citação (aspas duplas)'
		
		- <h1>..</h6> 
			'paragrafo de níveis diferentes'
		
		1- <a href="">..</a> 
			'hiperlink'
		
		- <img src=""/> 
			'imagem'
		
		- <ol><li>..</li></ol> 
			'lista ordenada (números)'
		
		- <ul><li>..</li></ul> 
			'lista desordenada (bolas)'
		
		- <!-- bla bla --> 
			'comentário'
		
		- <style="propriedade:valor ; propriedade:valor">
			 'separador é ponto-e-vírgula'
			-> font-size: 10px 'seta tam fonte 10 pixels'
			   color: red 'seta cor texto vermelha'
			   text-align: left 'texto na esquerda da tela'
			   font-family: Consolas 'fonte do texto consolas'
			   background-color: red 'seta cor fundo vermelha'
		
		- <strong>..</strong>
			'texto em negrito'
		
		- <b>..</b> 
			'texto em negrito'
		
		- <em>..</em> 
			'texto em itálico'
		
		- <span style="..">..</span> 
			'tag sem função - separadora'
				
		- <table>
			<thead> //cabeça - primeira linha
				<caption> Descrição </caption> //descrição da tabela
				<tr>
					<th colspan="2">Tabela de despesas</th> //titulo negritado - define grupo de colunas
				</tr>
				<tr> //linha
					<th>Gastos</th> //coluna - negritada
				</tr>
			</thead>
			<tbody> //corpo
				<tr> //linha
					<td>R$100,00</th> //coluna
				</tr>
			</tbody>
			<tfoot> //pé
				<tr> //linha
					<td>Total</td>    //coluna
				</tr>
			</tfoot>
		  </table>
		  	'tabela'
		
		- <form>..</form>
			'constroi formulario'
			-> accept-charset 'codificação de caracteres'
			   action 'funcao de envio do formulario'
			   enctype 'tipo de codificação do formulario na submissão'
			   novalidate 'não valida no envio'
			   target 'campo de resposta do servidor'
			   autocomplete, method, name

		// input de CPF/CNPJ
		- <input>..</input>
			'input do formulario'
			'antes validar demandava javascript, agora HTML5 faz, responsabilidade do navegador, mais rápido, sem sobrecarga'
			-> autofocus 'foca no elemento ao carregar a página'
			   placeholder 'dica de entrada'
			   form 'especifica form que elemento pertence'
			   pattern 'valida com expressão regular - REGEX'
			   		REGEX telefone do Brasil - ^\d{2}-\d{4}-\d{4}$
			   formaction 'substitui action do form'
			   formenctype 'substitui enctype do form'
			   formmethod 'substitui method do form'
			   formnovalidate 'substitui novalidate do form'
			   formtarget 'substitui target do form'
			   type 'define tipo de dados do input'
			   		tel, search, url, email, datetime, date, month, week, time, datetime-local, number, range, color
			   required, autocomplete

		// pesquisa de nome com seleção de itens
		- <select> <option value="TST">..</option> </select> 
			'cria lista dropdown (select)'
			* select -> autofocus 'foco automatico' 
						form 'formas seleção' 
						name 'define nome' 
						size 'num opcoes'
						disabled, multiple, required
			
			// apenas compartilham disabled, DECORARRR
			1* option -> label 'rótulo menor' 
						selected 'valor padrão selecionado' 
						value 'valor enviado'
						disabled

	- ADICIONADOS HTML5
		-> article 'artigo em documento - post em forum, blog'
		   aside 'sidebar - barra lateral'
		   audio 'sons - música, outros'
		   bdi 'troca direção do texto - escrever em árabe'
		   canvas 'desenha jogos e gráficos - usa JS dinâmico'
		   datalist 'lista de itens padrão para input'
		   details 'detalhes para visualizar ou esconder componentes'
		   dialog 'popups e modais'
		   embed 'container para plugin'
		   figcaption 'legenda para figure'
		   figure 'imagens em geral - fotos, diagramas'
		   footer 'rodape de documento ou seção'
		   header 'cabeçalho para itens introdutórios'
		   keigen 'gerador de pares de chaves para forms'
		   main 'conteúdo principal de documento - um por documento'
		   mark 'marcatexto'
		   menuitem 'define menu de popup'
		   meter 'gráfico de barras'
		   nav 'links de navegação'
		   output 'resultado de cálculo com script'
		   progress 'progresso de atividade'
		   section 'define capítulos, cabeçalhos, rodapés'
		   source 'define códigos para vídeo e áudio'
		   svg 'desenhar imagens vetorizadas usando SVG'
		   rp 'para navegadores sem RUBY'
		   rt 'pronuncia de caractere em RUBY'
		   ruby 'anotação RUBY'
		   summary 'cabeçalho para elemento details'
		   template 'fragmentos HTML clonáveis e inseridos por script'
		   time 'formatos de data/hora'
		   track 'faixas de texto para mídia de vídeo e audio'
		   video 'um vídeo'
		   wbr 'marcar sugestões de quebra de linha'

	- ABANDONADOS HTML5
		- APRESENTAÇÂO - melhor tratado pelo CSS
			- basefont, big, center, font, strike, tt
	
		- MÁ USABILIDADE
			- frame, frameset, noframes
	
		- POUCO UTILIZADOS
			- acronym (abbr), applet (embed), isindex (controles form), dir (ul)

- XML 'metalinguagem de marcação'
	- metalinguagem pois não possui tags pre-definidas, são criadas pelo usuário 
	- mas 'linguagem se banca perguntar', a não ser que foquem na diferença
	- padrão W3C
	- busca transportar e armazenar dados
	- provê intercâmbio de documentos na web
	- é 'independente de plataforma'
	- pode desenvolver e definir outras linguagens (metalinguagem - criação de tags)
	- busca e processamento otimizado e simplicado
	- não faz nada! Estrutura, armazena e transporta informações

	- 'elementos' tudo entre tag inicial e final
		<book></book> / <book />
	
	- 'atributos' informações adicionais sobre o elemento
		<file type="gif"> computer.gif </file>
	
	- 'namespaces' para diferenciar conflitos de nomes iguais
		- prefixo deve ser definido com atributo 'xmlns'
		- pode-se definir no próprio elemento ou no elemento raiz do documento
		- util para remover conflito de tags 'html' e 'xml'
		- 'URI' é qualquer coisa! Deve ser um identificador único! 
		xmlns:prefix="URI"
		<root xmlns:h="http://www.w3.org/TR/html4/">
		<h:table xmlns:h="http://www.w3.org/TR/html4/"><h:tr>.. 
		<f:table xmlns:f="..."><f:name>..

	- regras
			- 'bem formado' documento que obedece regras de construção (NECESSÁRIO PARA SER DOCUMENTO XML)
			- 1. possui um único elemento raiz
			- 2. todos elementos tem tag de fechamento
			- 3. elementos corretamente aninhados (tags fechadas na ordem correta)
			- 4. atributos com valor em aspas simples ou duplas
			- 5. nomes de tags e atributos são case-sensitive
			- 6. possui caracteres especiais (deve-se usar o da esquerda, e não o da direita)
				- &lt;   < 
				- &gt;   >
				- &amp   &
				- &apos  ''
				- &quote ""
			- 7. atributos não podem repetir no mesmo elemento
			- 8. atributos devem seguir regra de nomenclatura
				- não podem !""#$%&''()*+,/;<=>?@[\]^`{|} nem espaços nem começar com ńumero, ponto ou hífen

	- esquema
		- 'válido' documento consistente com seu esquema (SEMPRE È BEM FORMADO, MAS NÃO OBRIGATÓRIO, SEGUINDO AS REGRAS DE UM DTD)
		- esquema ajuda a padronizar, compartilhar, fornecer referência
		- são arquivos 'DTD' e 'XSD'
		
		- 'DTD' informam quais tags são válidas no XML e como devem ser estruturadas (ANTIGO)
			<!DOCTYPE note SYSTEM "Note.dtd">
			ex.
			<!DOCTYPE note[
			<!ELEMENT note (to, from, heading, body)>
			<!ELEMENT to (#PCDATA)>
			]>
		
		- 'XSD'
			- suporta namespaces, criação de novos tipos, definição de restrições, conversão de dados, manipular schemas com DOM,
				utilizar parser do XML, editor do XML, escrito em XML, extensível por adições
			ex.
			<xs:element name="note">
			<xs:complexType>
				<xs:sequence>
					<xs:element name="to" type="xs:string" />
					<xs:element name="from" type="xs:string">
				</xs:sequence>
			</xs:complexType>
			</xs:element>	

	- analisadores XML
		- 'DOM' (abordagem hierárquica)
			- representa como marcações HTML, XHTML, XML são organizadas e lidas pelo navegador
			- Javascript manipula a DOM dinamicamente usando a árvore DOM
			- opera sobre documento como um todo
			- grande uso pelos elementos da memória - lento

		- 'SAX' (abordagem orientada a eventos) - Simple API for XML
			- opera cada parte do documento sequencialmente
			- desencadeia eventos durante análise do arquivo XML
			- gera apenas elementos necessários - usa memória constante


	- DECLARAÇÃO XML 'primeira linha'
		<?xml version="1.0" encoding="UTF-8">

	- ELEMENTO RAIZ 'primeira elemento da árvore'


- *JAVA SE (Standard Edition)

- JAVA EE (Enterprise Edition)
	- altíssima competitividade - diminuir custos, tempo de resposta, prevenção de falhas, alta disponibilidade, redundância, escalabilidade e segurança
	- conjunto de especificações para 'aplicações distribuídas', 'robustas', 'escaláveis', 'multicamadas' e de 'alta disponibilida'

	- 'Java EE 6' 
		- profiles (perfis)
		- Java API for RESTful Web Services (JAX-RS)
		- Managed Beans
		- Contexts and Dependency Injection (CDI)
		- Dependency Injection for Java
		- Bean Validation
		- Enterprise JavaBeans, JavaServer Faces e Servlets

	- 'Java EE 7'
		- WebSocket, JSON, Servlet, Faces, Expression Language, Pages, Batch, Concurrency, Dependency Injection, Bean, 
		  Connector, Persistence, Annotations, Message Service, Transaction, JavaMail, RESTful, Web, XML-Based, Authentication, 
		  Debugging, Database, Streaming

	- 'arquitetura Java EE'
		- SISTEMA CLIENTE 'camada do cliente (máquina cliente)'
			- Browser 
			- Container do Cliente
				- Client Application
			- *APPLET

		- SERVIDOR DA APLICAÇÃO (JEE)
			- Container WEB 'camada web (servidor)'
				- Java Servlet
				- JavaServer Pages (JSP)
				- JavaServer Faces (JSF)
			- Container EJB 'camada de negócio (servidor)'
				- Enterprise Beans (EJB)
				- Enterprise Beans (EJB)
		- Database 'camada de dados'

	- 'modelo de aplicações Java EE'
		- aplicações de serviços para 'clientes', 'empregados', 'fornecedores', 'parceiros', 'terceiros'
		- escalabilidade, acessibilidade, gerenciabilidade
		- desenvolvedor implementa 
			- lógica de apresentação
			- lógica de negócio
		- fornecido pela Java EE
			- outros serviços
		- camada EIS roda no servidor EIS 
	
	- 'Profiles' 
		- define subconjunto de tecnologias da JEE configuráveis
		- como cada aplicação tem sua particularidade, não implementa todas as tecnologias 
		- 'Web Profile'
			- cria aplicações mais leves que rodam num 'Servlet Container'
			- EJB 3.1 Lite, mais leve (apenas [Stateless, Stateful, Singleton Beans], Interceptors, Declarative security, [Declarative, Programmatic transactions])
			- apenas arquivos 'WAR' e não 'EAR'
		- 'Full Profile'

	- 'deploy' implantar aplicação em servidor JEE
		- componentes são agrupados em módulos e compactados em .ZIP
		- aqui mapeia-se cada 'componente' do Java EE para seu 'contêiner' correspondente

		- 'tipos de módulos' 
			- EAR File META-INF/application.xml 'Enteprise Application Archives - aplicação completa - vários arquivos .war e .jar'
				- Web Module (WAR) WEB-INF/web.xml 'Web Application Archives - Aplicação Web (JSP, HTML, Servlets, Arquivos de Configuração, Imagens, etc) - forma uma página'
				- EJB Module (JAR) META-INF/ejb-jar.xml 'Java Application Archives - Aplicação EJB, Aplicação Cliente e Applets e arquivos de configuração dos aplicativos'
				- Connector Module (RAR) META-INF/ra.xml 'Resource Adapter - contém interfaces, classes, bibliotecas, etc'

	- 'JSP (JAVA SERVER PAGES)'
		- tecnologia JEE para usar código JAVA dentro de páginas WEB ou tags que realizam lógica
		- geração de documentos baseados em texto executados do lado servidor (como 'Servlets')
		- o texto é um conjunto de 'dados estáticos' (HTML e XML) ou 'dados dinâmicos' (elementos JSP e tags customizadas)
		- o código JAVA é o conteúdo dinâmico!
		- é uma linguagem de script SERVER-SIDE para geração simples, prática e rápida de conteúdo dinâmico para páginas WEB
		- possui o suporte de vários servidores ('Tomcat', 'GlassFish', 'JBoss')
		- define a interação entre 'Servidor' e 'Página JSP'

		- 'Páginas JSP'
			- tags 'XML' e 'Scriplets' escritos em 'JAVA' para encapsular lógica que gera o conteúdo para a 'página web'
			- separa a lógica do conteúdo da sua apresentação
			- são 'compiladas em Servlets' e podem chamar 'beans' a fim de executar o processamento no servidor
			- tipicamente se tornam uma 'Servlet'
				- 'camada adicional' em que a página é compilada e transformada em uma 'Servlet' no 'Servidor Web'
				- ciclo de vida exatamente igual ao de uma 'Servlet', porém com métodos diferentes
			- JSP foi desenhada para simplificar o processo de criação de páginas ao separar a 'apresentação' do 'conteúdo'
			- conceitos de 'coesão', 'acoplamento' e 'modularidade'
			- permite separação de especialidades
				- Desenvolvedores Java criam as Servlets (Lógica de Negócio)
				- Web Designers criam as Páginas JSP (Lógica de Apresentação)
			- manipulação de arquivos texto ('PDF', 'DOCX', etc)
			- criptografia de dados, utilização de cookies e sessões, manipulação de Arquivos XML, diversos bancos de dados e sistemas de relatórios

			- 'objetos implícitos' são criados automaticamente 	pelo 'Contêiner JSP' e disponibilizados para os desenvolvedores
				- 1. request 'HttpServletRequest com info do pedido HTTP'
				- 2. response 'HttpServletResponse com resposta HTTP que será enviada ao cliente'
				- 3. pageContext 'PageContext contém info de contexto para executar a página'
				- 4. application 'ServletContext para compartilhar info entre todos os componentes web'
				- 5. out 'JspWriter para imprimir para o response com println'
				- 6. config 'ServletConfig da página JSP'
				- 7. page 'HttpJspPage - sinônimo de this'
				- 8. session 'HttpSession que guarda info da sessão de usuário específico'
				- 9. exception 'Throwable resultante de erro na página'

			- 'declaraçoes (!)' definem variáveis, objetos e métodos para uso em expressões ou scriplets
					<%! public final static String[] estacoes = {"Primavera", "Verão", "Outono", "Inverno"} %>

			- 'expressões (=)' retornam valores que são inseridos dinamicamente na página no lugar da expressão
				- é avaliada, executada, 'convertida' em uma 'string' e inserida no local onde aparece a expressão no Arquivo JSP
				- convertido em um objeto 'string' e inserido no objeto implícito 'out'
					<%= idade = idade + 1 %>
					<%= "Esse é seu aniversário de " + idade + "anos" %>

			3- 'scriplets ()' blocos de Código Java embutidos em uma Página JSP
				- inclui 'Blocos' ou trechos de operações em 'JAVA' na página
				- na transformação JSP -> Servlet, 'scriptlets' são traduzidos para 'out.println()' no método '_jspService' da servlet gerada
				- variável criada na scriplet pode ser acessada de qualquer lugar dentro da Página JSP
				- expressão é similar a scriplets (porque são convertidas em 'string!!')
					<%= expressão %> é equivale a out.println(expressão)

					<html>
						<body>
							<% String mensagem = "Bem vindo!"; %>
							<% out.println(mensagem); %>
						</body>
					</html>

			- 'comentários (--)' tipo HTML
					<%-- Comentário JSP --%> // Em HTML, seria: <!-- Comentário HTML -->

			- 'ações (jsp)' permitem acessar e alterar 'regras de negócio' por meio das 'propriedades de JavaBeans'
				- redirecionamento de Requisições JSP para outra Servlet ou Página JSP
				- ajudam a controlar o comportamento da Engine da Servlet
				- são 20
					- 'jsp:include' inserir conteúdo dinâmico em tempo de solicitação
					- 'jsp:forward' redirecionar requisições para outra Página JSP
					- 'jsp:param' passar parâmetros para outra Ação JSP
					- 'jsp:useBean' invocar/instanciar um JavaBean
					- 'jsp:plugin' executar e mostrar um objeto (Ex: Applet) no browser
					- 'jsp:setProperty' setar o valor da propriedade de um JavaBean
					- 'jsp:getProperty' recuperar o valor da propriedade de um JavaBean

					<jsp: useBean id="user" scope="session" type="org.apache.struts"/>

			- 'diretivas (@)' instruções enviadas ao servidor para definir procedimento de compilação da ṕagina
				- instruções processadas quando página JSP é compilada em Servlet
				- 'importar classes de um pacote', 'inserir dados de arquivos externos',' habilitar uso de bibliotecas de tags'
				- podem afetar estrutura da página, mas não criam saídas visíveis
				- são 'interpretadas pelo container' antes de tudo!!
				- são 3 principais
					- 'page' define atributos de configuração da página
						- buffer, autoFlush, contentType, errorPage, isErrorPage, Extends, Import, Info, isThreadSafe, language, Session, isELIgnored, isScriptingEnabled
					<%@ page import="java.swing.*" %>
					
					1- 'include' inclui recursos estáticos em uma Página JSP
					<%@ include file="teste.jsp" %>

					- 'taglib' estende o conjunto de tags adicionando uma biblioteca
					<%@ taglib uri="http://serlets.com/testes" prefix="ops" %>

			- 'expression language' 
				- Scriplets e expressões usam código 'JAVA' para 'VIEW' (apresentação)
				- mas Web Designers acham JAVA é difícil
				- é interpretada pelo 'Servlet Container' para remover código 'JAVA' da 'página' para tags HTML-like
				- permite especificar expressões para atributos de componente 'JavaBeans' usando ${...}
				- operadores mais usados são '.' e '[]'
				- permite operadores aritméticos, lógicos, funções estendidas de mapeamento, textos estáticos e atributos de tags de 'JAVA'
				- mapeamento é definição de funções com tags personalizadas, sendo a função 'public static' na classe e declarada na 'TLD'
				- com 'taglib' importamos a Biblioteca de Tags personalizada criada

					<jsp:setProperty name="cubo" property="aresta" value="10"/>
					<jsp:setProperty name="cubo" property="perimetro" value="${12*cubo.aresta}"/>
					
					// equivalentes
					${Lista[1]}
					${Lista["1"]}

					// equivalentes
					${Lista["Carro"]}
					${Lista.Carro}

			// PAGINA JSP
			// HTML COM ALGUMAS COISAS DE JAVA
			# HelloWorld.jsp (No MVC, em geral, é utilizada como Visão)
			<html>
				<head>
					<title>
						<%="Hello World"%>
					</title>
				</head>
				<body>
					<%out.println("Hello Again!");%>
				</body>
			</html>

			'RESUMO'
				Declarations	<%! ... %>
				Expressions		<%= Expressão %>
				Scriplets 		<% Scriplet %>
				Comments 		<%-- Comentário --%>
				Actions 		<jsp: Ação />
				Directives 		<%@ Diretiva %>

	- 'Servlet'
		- API independente de plataforma, escrita em Java, que roda no 'servidor' (Container Web)
		- 'SERVIDORZINHO' pois estende funcionalidades de um servidor
		- funcionam para fornecer 'conteúdo web dinâmicos' processando 'requisições/respostas', 'filtrando dados', 'acessando o banco de dados'

		- 'páginas web dinâmicas'
			- 'client-side' permitem mudanças na interface usando ações do mouse, teclado, outros.. [ANGULAR/VIEW]
			- 'server-side' variam de acordo com os parâmetros fornecidos por um usuário/programa   [SERVLET/JSP]

			// SERVLET
			// JAVA COM ALGUMAS COISAS DE HTML
			# HelloWorld.java (No MVC, em geral, utilizada como Controladora)
			public class ServletTeste extends HttpServlet
			{
				public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException, ServletException 
				{
					res.setContentType("text/html");
					PrintWriter out = res.getWriter();
				
					out.println("<html>");
					out.println("<body bgcolor = \"white\">");
					out.println("<h1>Hello Servlet</h1>");
					out.println("</body>");
					out.println("</html>");
				}
			}

		- pacotes
			- 'javax.servlet'
				- classes e interfaces para comunicação com diversos protocolos, interfaces 'ServletRequest', 'ServletResponse' e 'ServletContext'
				- 'ServletContext' define um 'contexto', unidade de 'aplicação web' que possui suas próprias 'configurações'
					- Servlets e Páginas JSP precisam estar num 'contexto' de 'aplicação web', sendo um contexto de aplicação web por 'JavaMail'
					- conjunto de métodos que uma 'servlet' utiliza para interagir com seu 'Servlet Container'
					- métodos são 'recuperar um arquivo', 'despachar requisições' ou 'escrever em um arquivo' de log
					- 'ServletContext' serve para qualquer 'servlet do contexto' e pode ser acessado por meio do objeto 'ServletConfig'
					- cada 'servlet' possui seu 'ServletConfig'

			- 'javax.servlet.http'
				- classes e interfaces para comunicação usando 'HTTP', interfaces 'HttpServletRequest' e 'HttpServletResponse', classe abstrata 'HttpServlet'
				- 'HttpServletRequest'
					- método 'getParameter' retorna o valor do parâmetro de uma requisição como uma String
					- permite 'servlet' capturar dados de formulários

				- 'HttpServlet' define os métodos 'doGet', 'doPost', 'doPut', 'doDelete', 'doHead', 'doTrace' e 'doOptions'

		- 'ciclo de vida'
			- 1. Servidor recebe 'Requisição HTTP' e 'repassa' para 'Servlet Container'
				- já existe instancia: delega a requisição para ela
				- não existe instancia: carrega classe servlet na memória, cria uma instância e inicializa com método 'init' e parâmetro 'ServletConfig'
			- 2. Chama método service com dois parâmetros: ServletRequest 'solicitação do cliente' e ServletResponse 'resposta' - ambos criados pelo contêiner
			- 3. Contêiner chama o método 'destroy' a fim de remover a instância da servlet
			'PARA CADA REQUISIÇÃO, A SERVLET GERA UMA NOVA THREAD'

	- 'EJB (ENTERPRISE JAVABEANS)'
		- núcle da aplicação JEE
		- 'Container EJB' de um 'Servidor de Aplicação'
		- arquitetura para aplicações corporativas orientada à 'transação' e baseada em 'componentes'
		- componentes 'server-side' com infraestrutura para o desenvolvimento e implantação de aplicações 'distribuídas', 'escaláveis', 'seguras', 'persistentes' e 'portáteis'

		- programador livre para concentrar na 'lógica de negócio' e na 'resolução do problema'
		- não se preocupa com infraestrutura 'segurança, escalabilidade, entre outros'
		- extremamente portáveis e reusáveis
		- rodam em qualquer servidor de aplicação JEE
		- recomendado quando aplicação necessite ser 'escalável', 'segura', 'transacional', 'persistente', 'escalável', 'portável', 'distribuída'
		- neutra em relação a protocolos 'HTTP, IIOP, RMP, DOM'

		- 'Objetivos'
			- padrão para aplicações corporativas em JAVA
			- suporta desenvolvimento, implantação e utilização de aplicações corporativas em JAVA
			- suporta o desenvolvimento, implantação e utilização de Web Services
			- facilita a escrita de aplicações
			- implantadas em múltiplas plataformas sem recompilação ou modificação do código-fonte
			- aborda aspectos de desenvolvimento, implantação e tempo de execução do ciclo de vida de uma aplicação corporativa
			- defini contratos a ferramentas de terceiros interoperáveis em runtime
			- torna possível criação de aplicativos utilizando ferramentas de diferentes fabricantes
			- fornece interoperabilidade entre Beans Corporativos, componentes do Java EE e outras linguagens
			- compatível com as plataformas de servidores existentes
			- compatível com outras APIs JAVA
			- compatível com Protocolos CORBA

		- 'Contêiner EJB' 
			- 'recipiente' (em tempo de execução) para 'EJBs' que são implantados em um 'Servidor de Aplicação'
			- 'serviços' 
				- gerenciamento de ciclo de vida 'desenvolvedor não se preocupa com criação de processos, threads, ativação ou destruição de objetos'
				- geração de código 
				- gerenciamento de persistência 'beans não precisam se preocupar com sua persistência em um banco de dados'
				- gerenciamento de segurança 'fornece suporte a autenticação e controle de acesso orientado a papéis'
				- gerenciamento de transações 'gerencia o início, enrollment, commitment e rollback de transações'
				- controle de concorrência 'estado conversacional de Beans (se houver) é gerenciado (salvo/recuperado) automaticamente'

		- 'Descritores de implantação'
			- são anotações 'XML' 
			- definem estrutura e comportamento do EJB
			- criados no processo de empacotamento de EJB sendo parte dele na compilação
			- 'EJB 3.2' é o 'ejb-jar.xml'
			- 'anotações' geram artefatos
				- documentar o código, mapear classes Java para XML, mapear classes Java para bancos de dados, mapear métodos para operações, dependências externas
				- 'Java EE' prefere anotações
				- 'EJB 3' define anotações para o tipo de bean, tipo de interface, referências de recurso, atributos de transação, segurança e muito mais

		- 'Formatos'
			- padronizar o encapsulamento da lógica de negócio sob uma única interface
			- EAR, WAR, JAR

		- 'novidades EJB 3.1'
			- componente 'Singleton Session Bean' para capturar eventos de inicialização e encerramento da aplicação
			- 'Interface opcional' para componentes sem a obrigatoriedade da criação de uma interface remota ou local
			- Melhorias no serviço de 'agendamento'
			- *'deploy' de EJBs diretamente na 'camada web' (.war)
			- 'Chamadas assíncronas' a métodos
			- Nomes JNDI globais padronizados para 'portabilidade'
			- versão mais 'leve EJB Lite'
			- 'EJBs executados no JavaSE' com Embeddable EJB 

		- PAG 81!!!


			

- JUNIT 'framework de teste para a linguagem JAVA'
	- TDD 'Test Driven Development'
		- prática ágil de desenvolvimento de software
		- testes de unidade definem requisitos
		- desenvolvimento orientado a testes
	- conjunto de classes que usuário estende para criar um ambiente de testes automatizado
	- cada teste implementado como um 'objeto' e um 'executor' realiza os testes
	- usa TDD - primeiro teste, depois aplicação
		- aumenta 'produtividade' e 'estabilidade', reduzindo 'stress' e 'tempo gasto' 
	
	- 'manuais' sem apoio de ferramentas
		- demorado, tedioso, muito investimento, menos confiável, não programável
	- 'automatizados' usa ferramenta
		- rápido, menos investimento, confiável, programável 

	- 'características'
		- opensource
		- 'anottations' - identificar métodos dos testes
		- 'assertions' - resultados esperados dos testes
		- permite escrita rápida de código
		- simples - de baixa complexidade
		- resultados automaticos
		- barra verde (OK) ou vermelha (NÃO OK)
		- relatório dos casos de teste
		- teste do todo ou parte do sistema
		- testes 'unitários', de 'regressão' e 'funcionais'
		- facilmente integrado com 'eclipse', 'ant' e 'maven'
		- deve-se estender classe 'TestCase'
			public class JavaTest extends TestCase
		- TIPO DESCRIBE 'suite de testes' agregação de testes de unidade executáveis em conjunto ou agregação de suites
		- PROBLEMA: não fornece informações de cobertura dos casos de teste
				 

//-- 2%  CSS3.

- CSS3
	- necessidade de dissociar a linguagem de estruturação/conteúdo (HTML) da linguagem de apresentação/formatação (CSS)
	- padrão W3C (empresas que estabelecem padrões da internet)
	- desvantagem é que nem todos os navegadores implementam W3C
	- é em cascata, para tratar estilos em conflito
		- usuário !important prevalece sobre demais
		- desenvolvedor prevalece sobre usuário no resto
		- se num class com definições contraditórias no mesmo elemento, prevalece a última
	- /**/ são comentários

	- usuário com dificuldades visuais pode alterar fonte para grande usando !important
	- usado também para definir posições de elementos e formação de páginas 'em vez de tabelas HTML' - padrão W3C (Tableless)
	- usado também com XML
		- CSS/XML  <?xml-stylesheet type="text/css" href="arquivo.css">
		- XSL/XML  <?xml-stylesheet type="text/xsl" href="arquivo.xsl">
		- CSS/HTML <link rel="stylesheet" type="text/css" href="arquivo.css">
		
	- tipos por localização
		- 'inline' LOCAL NA TAG DE ABERTURA HTML USANDO STYLE
			- perde-se as vantagens do CSS pois mistura apresentação com marcação
			- deve ser usado excepcionalmente

		- 'incorporadas' REGRAS DECLARADAS NA SEÇÃO HEAD DENTRO DE <STYLE></STYLE> NO HTML
			- ideal para ser aplicada numa única página
			- perde-se a vantagem de aplicar estilos a toda a aplicação

		- 'externas' REGRAS DECLARADAS NUM ARQUIVO .CSS EXTERNO
			- ideal para ser aplicado em várias páginas
			- deve ser linkado dentro do head

	'seletor1, seletor2 {propriedade1: valor1 ; propriedade2: valor2 !important}'
		- seletor 'identificado por tag, classe, ID'
			- <p>, <h1>, <form>, .classe
		- propriedade 'atributo em que será aplicada a regra'
			- font, color, background
		- valor 'característica assumidade pela propriedade'
			- arial, blue, green

	- EXEMPLOS
		// aplicados diretamente a tags HTML
		h1, h2, h3{ 
			color: #0f0;
		}

		// usados no mesmo tag HTML diferenciados por class
		p.cor-um{ 
			color: #000
		}
		p.cor-dois{
			color: #ff
		}

		// usadas em tags HTML diferentes agrupadas por class
		.cor-três{
			color: ##00f
		}

		// aplicado a único elemento HTML usando ID
		#meuID{
			propriedade: valor;
		}

		// com seletor de atributos aplica-se estilo a propriedade com valor específico
		// aplica a todo atributo <a> com target sendo blank
		a[target = "blank"]{
			background-color="yellow"
		}

	- TAMANHOS PADRÃO
		- usar 'px' depende do tamanho da tela
		- usar 'em' é tamanho relativo da fonte dependendo do dispositivo

	- PRINCIPAIS PROPRIEDADES (são 226)
		- position 'static, relative, absolute, fixed'
			- diz posição do elemento
			- 'top, bottom, left, rigth' só funcionam se 'position' for configurada primeiro
			- 'static' padrão pelo fluxo da página - não aceita posicionamento manual com 'top, bottom, left, rigth'
			- 'relative' aceita coordenadaas em relação à pos original 'top: 20px indica elemento 20px abaixo do topo'
			- 'absolute' se refere a qualquer pai na estrutura HTML que seja 'static'
			- 'fixed' mantém posição fixa no navegador mesmo com rolagem da tela
		
		- list-style 'coisinha aos itens das listas'
			- propriedades de todas as listas
			- 'list-style-image' define imagem como marcador da lista
			- 'list-stule-position' define posicionamento do marcador
			- 'list-style-type' define tipo de marcador da lista

		- font 'estilo, largura, tamanho,..'
			- todas as propriedades de fontes
			- 'font-family/size/style/variant/weight'
			
		- background 'cor, imagem, posição,..'
			- propriedades de plano de fundo
			- 'background-color/image/position/size/repeat/origin/clip/attachment'

	- ADICIONADOS CSS3
		-> compatível totalmente com versões anteriores
		   construir animações, efeitos de rotação, movimento e transição
		   cálculos aritméticos simples
		   seletores avançados
		   manipula fontes 
		   tipos de bordas e planos de fundo
		   divisão de textos em colunas
		   Selectors 'Pesquisa Nome'
		   Box Model
		   Backgrounds
		   Borders
		   Image Values
		   Replaced Content
		   Text Effects
		   2D/3D Transformations
		   Animations
		   Multiple Column Layout
		   User Interface




//-- 17% Análise e projeto orientados a objetos (UML).

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



// 8%  Princípios sobre qualidade de software: modelo MPS.BR e CMMI-DEV 1.3

- CMMI 1.3 e MPS.BR
	- ambos funcionam como um guia para a melhoria dos processos da organização, visando a melhoria da qualidade e produtividade de software e serviços correlatos

- CMMI 1.2/1.3 (5 NÍVEIS!)
	- modelo de maturidade que prescreve boas práticas para desenvolvimento e manutenção de software 
	- 'CMMI for Development (CMMI-DEV)' processo de desenvolvimento de produtos e serviços
	- 'CMMI for Acquisition (CMMI-ACQ)' processos de aquisição e terceirização de bens e serviços
	- 'CMMI for Services (CMMI-SVC)' processos de empresas prestadoras de serviços
	- falaremos do CMMI-DEV que tem 22 áreas de processos
	- cada área é um conjunto de práticas que atingem metas para melhorias de uma categoria

	- Uma “constelação” é definida como uma coleção de componentes que são usados para construir modelos, materiais de treinamento e documentos relacionados 
			à avaliação para uma área de interesse. Por exemplo, aquisição, desenvolvimento, serviços. 

	1- 'abordagem contínua' permite escolher as áreas de processos para as quais deseja ser avaliada por níveis de capacidade
		- liberdade para aperfeiçoar na ordem que for conveniente, livre escolha

	- 'abordagem por estágios' classificar a empresa em um determinado nível de maturidade
		- Para alcançar determinado nível a empresa deve realizar um conjunto de áreas de processos

// - contínua
// 	- níveis de capacidade
// 		- Nível 0: Incompleto/Ad-hoc 'processo não executado ou executado parcialmente'
// 		- Nível 1: Executado 'satisfaz às metas específicas da área de processo'
// 		- Nível 2: Gerenciado/Gerido 'planejado/executado de acordo com uma política, experientes, saídas controladas, interessados, monitorado, controlado, revisado, avaliado'
// 		- Nível 3: Definido 'é gerenciado e adaptados pelos processos padrão da empresa por diretrizes de adaptação e gerindo produtos e medidas de melhoria pra ativos'
// 		'SO1.2'- Nível 4: Gerenciado Quantitativamente 'definido e controlado por técnicas estatísticas e quantitativas'
// 		'SO1.2'- Nível 5: Em otimização/Otimizado 'gerenciado quantitativamente e melhorado com base nas causas comuns de variação inerentes'

- estágios
	- níveis de maturidade (5)
		- Nível 1: Inicial/Ad-hoc 'processos ad hoc e caóticos e não oferece ambiente estável para apoiar processos'
		1- Nível 2: Gerenciado/Gerido 'planejados/executados de acordo com uma política, experientes, saídas controlas, interessados, monitoreados, controlados, revisados, avaliados'
		2- Nível 3: Definido 'bem caracterizados e entendidos, descritos em padrões, procedimentos, ferramentas e métodos'
		1- Nível 4: Gerenciado Quantitativamente 'objetivos quantitativos para qualidade e desempenho sendo critérios na gestão'
		1- Nível 5: Em otimização/Otimizado 'melhoria contínua com base nas causas comuns de variação inerentes'
	- é necessário que todas as áreas de processos de nível dois sejam executados para que a empresa seja certificada com nível dois
	- Para o nível dois de maturidade, todos os processos deste nível devem ser executados com nível dois de capacidade
	- Para os níveis de maturidade 3, 4 e 5, os processos correspondentes deverão ser executados no nível de capacidade três

- categorias
	- 1.Gestão de Processos 'atividades transversais, definição, planejamento, execução, monitoramento e contole, avaliação, medição e melhoria de processos'
		- 3.Foco nos Processos da Organização (OPF) 'colaborar para planejamento, implementação, implantação de melhorias compreendendo pontos fortes e fracos de processos e ativos'
		- 3.Definição dos Processos da Organização (OPD) 'estabele/contém conjunto de processos padrão'
		- 3.Treinamento na Organização (OT) 'identifica necessidades de treinamento estratégico e tático'
		1- 4.Desempenho dos Processos da Organização(OPP) 'objetivos quantitativos para qualidade e desempenho a partir de objetivos estratégicos'
		- 5.Gestão do Desempenho da Organização (OPM) 'analise de linhas de base para entender habilidade em alcançar objetivos'
			'NO1.2' Implantação de Inovações na Organização (OID)
	
	- 2.Gestão de Projetos 'gestão relacionadas a planejamento, monitoramento e controle de projeto'
		- 2.Planejamento de Projeto (PP) 'define planos para realização do projeto tais como plano de gestão, de configuração, de verificação, de medição e análise'
		- 2.Monitoramento e Controle de Projeto (PMC) 'atividades de monitoramento e implementação de ações corretivas'
		- 2.Gestão de Requisitos (REQM) 'gerencia os requisitos do projeto'
			'NO1.2' pertencia à categoria de Engenharia
		- 2.Gestão de Contrato com Fornecedores (SAM) 'aquisição de partes do trabalho que envolvem fornecedores'
		- 3.Gestão Integrada de Projeto (IPM) 'estabele e mantém o processo definido para o projeto que é adaptado a partir do conjunto de processos padrão'
		- 3.Gestão de Riscos (RSKM) 'abordagem proativa e em regime contínuo para a gestão de riscos'
		1- 4.Gestão Quantitativa de Projeto (QPM) 'técnicas quantitativas e estatísticas para gerenciar o desempenho e a qualidade'
	
	- 3.Engenharia 'tratam de atividades de desenvolvimento e manutenção das disciplinas de Engenharia'
		- 3.Desenvolvimento de Requisitos (RD) 'identifica as necessidades do cliente e as traduz para requisitos fornecendo-os para a Solução Técnica'
		- 3.Solução Técnica (TS) 'converte os requisitos em arquitetura e design desenvolvendo dados utilizados pela Integração de Produto e Gestão de Contrato com Fornecedores'
		- 3.Verificação (VER) 'assegura que produtos satisfaçam requisitos especificados'
		- 3.Validação (VAL) 'valida produtos incrementalmente em relação às necessidades do cliente'
		- 3.Integração de Produto (PI) 'objetiva a geração da melhor sequência de integração possível dos componentes e entrega ao cliente'
	
	- 4.Suporte 'tratam de atividades que apoiam o desenvolvimento e a manutenção para todas as áreas de processo'
		- 2.Gestão de Configuração (CM) 'estabele e mantém integridade dos produtos pela identificação, controle, balanço de atividades e auditorias de configuração'
		- 2.Garantia da Qualidade de Processo e Produto (PPQA) 'fornece práticas para avaliar processos, produtos de trabalho e serviços'
		- 2.Medição e Análise (MA) 'práticas para orientar os projetos no alinhamento das necessidades e objetivos de medição'
		- 3.Análise e Tomada de Decisões (DAR) 'quais questões críticas devem ser submetidas a um processo de avaliação formal'
		- 5.Análise e Resolução de Causas (CAR) 'possibilita identificar causas de defeitos e implementar ações'
			- objetivo do processo 'fornecer subsídios para identificar causas de defeitos e de outros problemas implementando ações para prevenir sua recorrência'
			- notas introdutórias 'melhora a qualidade e a produtividade da organização'
			- áreas relacionadas 'Gestão Quantitativa de Projeto, Gestão de Desempenho Organizacional, Medição e Análise'

		'NÍVEIS4 - Desempenho dos Processos e Gestão Quantitativa'
		'NÍVEIS5 - Gestão do Desempenho e Análise e Resolução de Causas'

- para cada processo (área do processo)
	- componentes
		- exigidos/requeridos (retângulo arredondado) 'metas específicas (SG) e genéricas (GG)'
			- metas genéricas 'aplicada a todos os processos descrevendo características para institucionalizar os processos'
			- metas específicas 'descreve características adequadas daquele processo'
		- esperados (losango) 'práticas específicas (SP) e genéricas (GP)'
			- descrevem atividades importantes para a satisfação da meta
			- podem não ser seguidas desde que a meta seja alcançada
		- informativos (elipse) 'componentes que auxiliam compreensão dos exigidos e esperados'
			- produtos de trabalho típico (saída de práticas específicas)
			- subpráticas genéricas e específicas (descrições detalhadas para a melhoria dos processos)
			- objetivo do processo, notas introdutórias, áreas relacionadas

	- metas genéricas	
		GG 1 – Processo Executado (generic goals)
			- alcançar todas as metas específicas da área de processo
			- não possui práticas genéricas
		GG 2 – Processo Gerenciado
			GP 2.1 – Estabelecer uma Política Organizacional (generic practices)
			GP 2.2 – Planejar o Processo
			GP 2.3 – Fornecer Recursos
			GP 2.4 – Atribuir Responsabilidades
			GP 2.5 – Treinar Pessoas
			GP 2.6 – Gerenciar Configurações
			GP 2.7 – Identificar e Envolver as Partes Interessadas Relevantes
			GP 2.8 – Monitorar e Controlar o Processo
			GP 2.9 – Avaliar Objetivamente a Aderência
			GP 2.10 – Revisar Status com a Gerência de Nível Superior
		GG 3 – Processo Definido
			GP 3.1 – Estabelecer um Processo Definido
			GP 3.2 – Coletar Experiências Relacionadas aos Processos

	- avaliação
		// - na contínua para Análise de Resolução e Causas
		// 	- receberá uma nota de 0 a 3
		// 	- se cumprir todas as metas específicas alcança a meta genérica 1 e a área é executada (nível 1 de capacidade)
		// 	- se alcançar a meta genéricas 2 ou 3, nível de capacidade sobe

		- nos estágios
			- para alcançar nível 5 precisa atingir o nível 3 em todas as 22 áreas de processo do CMMI

- MPS-BR (7 NÍVEIS!)
	- programa mobilizador, de longo prazo, criado no Brasil
	- objetiva disseminar-se tanto em micro, pequenas e médias empresas quanto em grandes organizações privadas e governamentais
	- similar ao CMMI, baseia-se nos conceitos de maturidade e capacidade para avaliar qualidade e produtividade
	- 'Modelo de Referência MPS para Software (MR-MPS-SW)'
	- 'Modelo de Referência MPS para Serviços (MR-MPS-SV)'
	- 'Método de Avaliação (MA-MPS)'
	- 'Modelo de Negócio para Melhoria de Processo de Software e Serviços'

	- busca definir e aprimorar um modelo melhoria e avaliação de processo de software
	- busca ser reconhecido nacional e internacionalmente como um modelo aplicável à indústria de software
	- estabelece também um modelo de negócio para apoiar a sua adoção pelas empresas brasileiras desenvolvedoras de software

	- 'Guia Geral MPS de Sofware' descrição detalhada do MR-MPS-SW e fornece uma visão geral sobre os demais guias
	- 'Guia Geral MPS de Serviços' descrição geral do MR-MPS-SV e definições comuns necessárias para seu entendimento e aplicação
	- 'Guia Geral MPS Gestão de Pessoas' descrição da estrutura dos modelos MPS e detalha o MR-MPS-RH e definições comuns necessárias para seu entendimento e aplicação
	- 'Guia de Avaliação' descreve o processo e o método de avaliação MA-MPS, requisitos para avaliadores líderes, avaliadores adjuntos e Instituições Avaliadoras
	- 'Guias de Implementação' documentos que fornecem orientações para implementar nas organizações os níveis de maturidade descritos nos Modelos de Referência
	- 'Guia de Aquisição de Software' descreve um processo de aquisição de software e serviços correlatos

- 9 atributos do processo (APS detalhados em termos de Resultados esperados)
	1- AP 1.1 – o processo é executado
	1- AP 2.1 – a execução do processo é gerenciada
	- AP 2.2 – os produtos de trabalho do processo são gerenciados
	- AP 3.1 – o processo é definido
	- AP 3.2 - o processo está implementado
	- AP 4.1 – o processo é objeto de análise quantitativa
	- AP 4.2 – o processo é controlado quantitativamente
	1- AP 5.1 – o processo é objeto de melhorias incrementais e inovações
	- AP 5.2 – o processo é objeto de melhorias inovadoras e incrementais

- níveis de maturidade (MR-MPS-SW)
	- 19 grupos de processos em 7 níveis

	- não existe abordagem contínua
	- mantém visão segundo capacidade

	1- 'capacidade' atributos de processo descritos em RESULTADOS ESPERADOS
		- à medida que se evolui nos níveis de maturidade, a capacidade de alguns processos precisa aumentar por meio do alcance de mais atributos
		- é a caracterização da habilidade do processo para alcançar os objetivos de negócio, atuais e futuros
		- está relacionada com o atendimento aos atributos de processo associados aos processos de cada nível de maturidade
		- expressa o grau de refinamento e institucionalização com que o processo é executado na organização ou na unidade organizacional
		- é representada por um conjunto de atributos de processo, dentre os quais se encontra "O processo é objeto de análise quantitativa"

	- para evoluir, deve-se cumprir os atributos de processos exigidos no atual nível preservando dos níveis anteriores

	- alguns processos podem ser excluidos (total ou parcial) da avaliação MPS senão pertinentes à organização
		- AQU, desde que não executado
		- GPP, desde que unica atividade da empresa seja evolução
		- DRU, depende

	A (Em Otimização)
		- sem processos
		
		- processos nível A, B,C,D,E,F,G devem alcançar atributos AP 1.1, 2.1, 2.2, 3.1, 3.2, 4.1, 4.2, 5.1, 5.2
		- os atributos de processo AP 5.1 e AP 5.2 devem ser integralmente satisfeitos pela implementação de pelo menos um dos processos 
		  selecionados para análise de desempenho
	
	1.B (Gerenciado Quantitativamente)
		- Gerência de Projetos - GPR (evolução)
			resultados esperados
			GPR 22 'objetivos de qualidade e de desempenho definidos são estabelecidos e mantidos'
			GPR 23 'o processo é composto com base em técnicas estatísticas e outras técnicas quantitativas'
			GPR 24 'subprocessos e atributos críticos para avaliar o desempenho são selecionados'
		
		- processos nível B,C,D,E,F,G devem alcançar atributos AP 1.1, 2.1, 2.2, 3.1, 3.2, 4.1, 4.2
		- os atributos de processo AP 4.1 e AP 4.2 somente devem ser implementados para os processos críticos da organização/unidade organizacional, 
		  selecionados para análise de desempenho
	
	C (Definido) - alcance de todos os processos
		- Gerência de Riscos - GRI 'identificar, analisar, tratar, monitorar os riscos'
			GRI 1 'escopo da gerência de riscos é determinado'
			GRI 2 'origens e categorias de riscos determinadas e parâmetros usados para analisar riscos, categorizá-los e controlar o esforço da gerência não definidos'
			GRI 3 'estratégias apropriadas para a gerência de riscos são definidas e implementadas'
		- Desenvolvimento para Reutilização - DRU 'identificar oportunidades de reutilização sistemática de ativos e estabelecer programa de reutilização para desenvolver ativos'
			DRU 1 'domínios de aplicação em que serão investigadas reutilização de ativos são identificados, detectando os respectivos potenciais de reutilização'
			DRU 2 'a capacidade de reutilização sistemática da organização é avaliada e ações corretivas são tomadas'
			DRU 3 'um programa de reutilização com propósitos, escopo, metas e objetivos é planejado para atender às necessidades de reutilização de domínios'
		- Gerência de Decisões - GDE 'analisar decisões críticas com critérios para avaliação das alternativas identificadas'
			GDE 1 'guias para gerência de decisões são estabelecidos e mantidos'
			GDE 2 'o problema ou questão a ser objeto de um processo formal de tomada de decisão é definido'
			GDE 3 'critérios para avaliação das alternativas de solução são estabelecidos e mantidos em ordem de importância'
		
		- processos nível C,D,E,F,G devem alcançar atributos AP 1.1, 2.1, 2.2, 3.1, 3.2
	
	D (Largamente Definido)
		- Verificação - VER 'confirmar que cada serviço e/ou produto de trabalho do processo ou do projeto atende os requisitos especificados'
			VER 1 'produtos de trabalho a serem verificados são identificados'
			VER 2 'estratégia de verificação é desenvolvida e implementada, estabelecendo cronograma, revisores envolvidos, métodos para verificação'
			VER 3 'critérios e procedimentos para verificação são identificados e um ambiente para verificação é estabelecido'
		- Validação - VAL 'confirmar que um produto ou componente atenderá a seu uso pretendido quando colocado no ambiente para o qual foi desenvolvido'
			VAL 1 'produtos de trabalho a serem validados são identificados'
			VAL 2 'estratégia de validação é desenvolvida e implementada, estabelecendo cronograma, participantes envolvidos, métodos para validação'
			VAL 3 'critérios e procedimentos para validação são identificados e um ambiente para validação é estabelecido'
		- Projeto e Construção do Produto - PCP 'projetar, desenvolver e implementar soluções para atender aos requisitos'
			PCP 1 'alternativas de solução e critérios de seleção desenvolvidos para atender requisitos'
			PCP 2 'soluções são selecionadas para produto ou suas componentes com base em cenários definidos'
			PCP 3 'produto e/ou componente do produto é projetado e documentado'
		- Integração do Produto - ITP 'compor componentes produzindo produto consistente e demonstrar que requisitos funcionais e não-funcionais são satisfeitos'
			ITP 1 'estratégia de integração desenvolvida e mantida para os componentes'
			ITP 2 'ambiente para integração dos componentes estabelecido e mantido'
			ITP 3 'compatibilidade das interfaces internas e externas dos componentes do produto é assegurada'
		- Desenvolvimento de Requisitos - DRE 'definir os requisitos do cliente, produto e componentes'
			DRE 1 'necessidades, expectativas e restrições identificados'
			DRE 2 'conjunto definido de requisitos do cliente é especificado e priorizado por necessidades, expectativas e restrições'
			DRE 3 'conjunto de requisitos funcionais e não-funcionais é definido e mantido a partir dos requisitos do cliente'

		- processos nível D,E,F,G devem alcançar atributos AP 1.1, 2.1, 2.2, 3.1, 3.2
	
	E (Parcialmente Definido)
		- Gerência de Projetos - GPR (evolução)
			GPR 4 'planejamento e estimativas feitos baseados no repositório de estimativas e no conjunto de ativos'
			GPR 8 'recursos e ambiente de trabalho necessários são planejados a partir dos ambientes padrão'
			GPR 20 'equipes envolvidas estabelecidas e mantidas a partir das regras e diretrizes para estruturação, formação e atuação'
		- Gerência de Reutilização - GRU 'gerenciar o ciclo de vida dos ativos reutilizáveis'
			GRU 1 'estratégia de gerencia de ativos documentada defindo ativo reutilizável,caceitação, certificação, classificação, descontinuidade e avaliação'
			GRU 2 'mecanismo de armazenamento e recuperação de ativos reutilizáveis é implantado'
			GRU 3 'dados de utilização dos ativos reutilizáveis registrados'
		- Gerência de Recursos Humanos - GRH 'prover recursos humanos necessários e manter competências às necessidades'
			GRH 1 'necessidades revistas para identificar recursos, conhecimentos e habilidades requeridas e planejar como desenvolvê-los ou contratá-los'
			GRH 2 'indivíduos com habilidades e competências requeridas são identificados e recrutados'
			GRH 3 'necessidades de treinamento são identificadas'
		- Definição do Processo Organizacional - DFP 'estabelecer e manter conjunto de ativos e padrões aplicáveis às necessidades'
			DFP 1 'conjunto definido de processos estabelecido e mantido com indicação da aplicabilidade de cada um'
			DFP 2 'biblioteca de ativos estabelecida e mantida'
			DFP 3 'tarefas, atividades, papéis e produtos identificados e detalhados junto com desempenho esperado do processo'
		- Avaliação e Melhoria do Processo Organizacional - AMP 'determinar o quanto processos contribuem para objetivos e planejar, realizar e implantar melhorias'
			AMP 1 'descrição de necessidades e objetivos estabelecidos e mantidos'
			AMP 2 'informações e dados de processos existem e mantidos'
			AMP 3 'avaliações realizadas para identificar pontos fracos, fortes e oportunidades de melhoria'
		
		- processos nível E,F,G devem alcançar atributos AP 1.1, 2.1, 2.2, 3.1, 3.2
	
	F (Gerenciado)
		- Medição - MED 'coletar, armazenar, analisar e relatar dados dos processos para apoiar os objetivos'
			MED 1 'objetivos de medição estabelecidos e mantidos dados objetivos e necessidades de processos técnicos e gerenciais'
			MED 2 'conjunto de medidas dados objetivos de medição identificados e priorizados, documentados, revisados e atualizados'
			MED 3 'procedimentos para coleta e armazenamento de medidas especificados'
		- Garantia da Qualidade - GQA 'assegurar que processos em conformidade com os planos, procedimentos e padrões'
			GQA 1 'aderência dos produtos aos padrões, avaliação objetiva em marcos do ciclo de vida'
			GQA 2 'aderência dos processos executados às descrições, padrões e procedimentos'
			GQA 3 'problemas e não-conformidades identificados, registrados e comunicados'
		- Gerência de Portfólio de Projetos - GPP 'iniciar/manter projetos necessários, suficientes e sustentáveis para atender objetivos'
			GPP 1 'oportunidades, necessidades e investimentos identificados, qualificados, priorizados de acordo com objetivos'
			GPP 2 'recursos e orçamentos identificados e alocados'
			GPP 3 'responsabilidades e autoridades estabelecidas'
		- Gerência de Configuração - GCO 'estabelecer/manter integridade dos processos e disponibilizá-los aos envolvidos'
			GCO 1 'Sistema de Gerência de Configuração estabelecido'
			GCO 2 'ICs identificados com base em critérios definidos'
			GCO 3 'ICS sob controle formal de baseline'
		- Aquisição - AQU 'gerenciar aquisição de produtos que satisfaçam necessidades do cliente'
			AQU 1 'necessidades de aquisição, metas, critérios de aceite, tipos e estratégias definidos'
			AQU 2 'critérios de seleção de fornecedores'
			AQU 3 'seleção de fornecedor com base em propostas e critérios'

		- processos nível F,G devem alcançar atributos AP 1.1, 2.1, 2.2
	
	2.G (Parcialmente Gerenciado)
		1- Gerência de Requisitos - GRE 'gerenciar requisitos e identificar inconsistência de requisitos, planos e produtos'
			GRE 1 'entendimento dos requisitos junto com fornecedores'
			GRE 2 'requisitos avaliados com critérios objetivos e equipe técnica'
			GRE 3 'rastreabilidade bidirecional de requisitos e produtos'
		- Gerência de Projetos - GPR 'estabelecer e manter planos de atividades, recursos e responsabilidades, informações sobre andamento, correções em grandes desvios'
			GPR 1 'escopo do projeto definido'
			GPR 2 'tarefas e produtos dimensionados com métodos apropriados'
			GPR 3 'modelo e fases do ciclo definidos'
		
		- processos nível G devem alcançar atributos AP 1.1, 2.1



// 7%  Conceitos sobre orientação a objetos (classes, atributos, objetos, métodos, herança, interfaces e outras hierarquias)

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
