3. ARCHITECTURE

- NgModules: Angular modules
	- root Module: AppModule.
	- tem decorator @NgModule.
	- bootstrap: indica a view principal, ou a root Component.
	- main.ts bootstrepa o AppModule. 

- Angular libraries
	- coleção de módulos Javascript.
	- começam com @angular.
	- instala com npm e importa com import.
	- para acessar lib, nome no array imports de AppModule.

- Components
	- controla um pedaço de tela chamado view.
	- Ng cria, atualiza e destrói components a medida que usuário usa a aplicação.

- Templates
	- template dá a cara da view da component.
	- formulário HTML que diz ao Ng como renderizar a component.
	- se a component linka outra no template, ela vira sua filha.

- Metadata
	- metadados dizem ao Ng como processar uma classe.
	- providers indica os serviços com injeção de dependência na component.
	- view: template + metadata + component.
	- @Injectable, @Input, and @Output.

- Data binding
	- liga partes da component com partes do template de maneira muito mais fácil.
	- existem 4 formas de binding:
		- COMP {{value }} 				 DOM          <li>{{hero.name}}</li>
		- COMP [property] = "value" 	 DOM          <hero-detail [hero]="selectedHero"></hero-detail>
		- DOM  (event) = "handler" 		 COMP 	      <li (click)="selectHero(hero)"></li>
		- [(ng-model)] = "property" 				  <input [(ngModel)]="hero.name"> TWO-WAY DATA BIND
	- comunica templates com components e components pais com filhas.

- Directives
	- a DOM dinâmica é transformada de acordo com as diretivas.
	- é uma classe com decorator @Directive.
	- component: directive + template.
	- @Component: @Directive + features orientadas a template.
	- Podem ser estruturais ou de atributo.
		- Estrutural: alteram layout com adição, remoção ou alteração de elementos na DOM - *ngFor e *ngIf.
		- Atributo: alteram a aparência ou comportamento de um elemento existente - ngModel para two-way data bind.

- Services
	- engloba qualquer valor, função ou feature que a aplicação precisa.
	- é uma classe com restrições bem específicas e definidas.
	- exemplos 
		- serviço de logar
		- serviço de dados
		- mensagem num bus
		- cálculo de taxa
		- configuração da aplicação
	- components não devem pegar dados do server, validar entrada de usuário ou logar diretamente no console.

- Dependency injection
	- fornece uma nova instância de uma classe com todas as dependências requeridas, em geral serviços.
	- injeta os serviços requeridos por umas classe.
	- ao criar uma component, primeiro pergunta a um injetor pelos serviços requeridos pela component.
	- injetor mantém container de instâncias de serviços que criou. Se não tem no container, injetor faz um e 
	  adiciona antes de retornar o serviço.
	- para o injetor saber como instanciar um serviço, é necessário ter registrado um provider no injetor, capaz 
	  de criar ou retornar um serviço.
	- adiciona-se providers no AppModule.
	- pode-se adicionar também no decorator de uma component, significando que ter-se-á uma nova instância do serviço 
	  a cada nova instância da component. 