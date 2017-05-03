#https://angular.io/docs/ts/latest/
ANGULAR COM IONIC E CORDOVA - ANDROID E IOS.
JAVASCRIPT COMPLETO - ANGULAR + NODEJS + MONGODB.

#https://angular.io/docs/ts/latest/quickstart.html
#A quick look at Angular basics

.ts // Type Script.
.Plunker // Teste de apps na propria web.
.QuickStart seed // Desktop para aplicações locais na máquina.
.node (Node.js) // Desenvolvimento cliente poderoso e ferramentas de construção (node -v)
				// Plataforma para desenvolvimento de aplicações server-side baseadas em rede utilizando 
				// JavaScript e o V8 JavaScript Engine, ou seja, com Node.js podemos criar uma variedade 
				// de aplicações Web utilizando apenas código em JavaScript.
.npm // Node Package Manager 
	 // Gerenciador de pacotes, uma das aplicações do node que instala as bibliotecas JavaScript (npm -v).
	 // Primeiro, e mais importante, é um repositório online para publicação de projetos de código aberto para o Node.js
	 // Segundo, ele é um utilitário de linha de comando que interage com este repositório online, que ajuda na instalação 
	 // de pacotes, gerenciamento de versão e gerenciamento de dependências..
.bootstrap loader // primeiro pedaço de código que roda quando uma máquina é iniciada.
.bootstrapper // simples arquivo que inicia todos os outros processos, iniciador.
.decorator // funcao que adiciona metadados a uma classe, seus membros (propriedades, metodos) e argumentos de funcoes.
		   // sao caracteristica da linguagem Javascript e implementada em Typescript.
.Typescript // Typescript é um SUPERCONJUNTO de Javascript.
			// Angular usa Typescript porque seus tipos tornam facil o suporte e o uso de ferramentas.
			// Também pode-se usar Angular com Javascript.
.binding // ligadura
		 // associação de uma tag a um nome.
.DOM // Document Object Model
	 // O conteúdo na tela.
.ng  // Prefixo para angular. Usado em muitas diretivas build-in.
.mocking // Objetos que simulam o comportamento de objetos reais de forma controlada.
		 // Usado em teste de unidade, unit test.
		 // Uso de dados irreais para testar uma funcionalidade.
		 // Permite que se testem circunstâncias que seriam muito difíceis de serem testadas no mundo real.
.AngularJS vs Node.js // Angular é frontend e Node é backend.

.npm start // Runs an arbitrary command specified in the package's "start" property of its "scripts" object. 
		   // If no "start" property is specified on the "scripts" object, it will run node server.js.
		   // Npm start will run whatever you have defined for the start command of the scripts object 
		   // in your package.json file.

// problema
"start": "tsc && concurrently \"tsc -w\" \"lite-server\" "

- app de Angular são feitas de Components.
- 'Component' é a combinação de um template HTML com uma Component class que controla uma porção da tela.
- Toda Component começa com a funcao 'decorator' @Component que recebe um objeto de metadados.
  O objeto descreve como o template HTML e a classe component trabalham juntas.
- A propriedade 'selector' diz ao Angular para mostrar a component dentro de uma tag custom <my-app> para ser usada no body do index.html.
  <my-app>Loading AppComponent content here ...</my-app>
- A propriedade 'template' define uma mensagem dentro do cabeçalho <h1>.
  Começa com Hello e termina com {{name}}, uma expressao de interpolacao do Angular.
  No runtime, Angular substitui {{name}} com o valor da propriedade da component chamada name.


%%%%%%%%%%% Component que mostra string %%%%%%%%%%%
app/app.component.ts
{
	import { Component } from '@angular/core';

	@Component({
	  selector: 'my-app',
	  template: `<h1>Hello {{name}}</h1>`
	})
	export class AppComponent { name = 'Angular'; }
}
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

#https://angular.io/docs/ts/latest/guide/setup.html
#Whats in the QuickStart seed?

- Focar em /app 
app
|_app.component.ts
|_app.module.ts
|_main.ts

- app/app.component.ts: define o mesmo AppComponent do app anterior. 
						É o 'componente raiz' da arvore de componentes que se formara quando o app evoluir.

- app.module.ts: define AppModule, é o 'modulo raiz' que diz ao angular como montar a aplicacao.
				 Por enquanto apenas declara o AppComponent.

- main.ts: compila a aplicacao com o compilador JIT e bootstraps (inicia/carrega) a aplicação para rodar no browser.
		   Otima forma para desenvolver a maioria das aplicacoes.


#https://docs.npmjs.com/getting-started/installing-node
#instalation
- Node.js
	- windows installer
- QuickStart seed e npm
	- git clone https://github.com/angular/quickstart.git quickstart
	- cd quickstart
	- npm install
	- npm start