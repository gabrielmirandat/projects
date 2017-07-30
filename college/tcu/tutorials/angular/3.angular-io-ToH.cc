App que ajuda uma agência gerenciar estabilidade de seus herois, até eles precisam de emprego
Tera todas as caracteristicas esperadas de um app orientado a dados
- recebe e mostra uma lista de herois
- edita os detalhes de um herói selecionado
- navegação em diferentes visadas nos dados do herói

- usa diretivas build-in para mostra/esconder elementos e mostra listas dos dados dos heróis.
- cria component para mostrar detalhes dos herois e outra para mostrar um array de herois.
- usa one-way data binding para apenas ler dados.
- adiciona campos editáveis para atualizar um modelo com two-way data binding.
- liga métodos de components para eventos de usuário para teclas e cliques.
- selecionar um heroi numa master list e editar este herói numa view de detalhes.
- formatar dados com pipes.
- criar um serviço compartilhado para montar nossos heróis.
- rotas para navegar em diferentes views e suas components.

- Tem dashboard view e heroes view.
- Se na Dashboard clicarmos num herói somos roteados para a hero details view daquele heroi onde podemos mudar seu nome.
- Ao clicar em heroes, vamos para a heroes master list view.
- Se na Heroes clicarmos num heroi, uma lista mini-detail read-only daquele heroi é mostrada.
- clicando em View Detail, vamos para a hero details view desse heroi.

1. Setup to develop locally
- criada pasta angular-tour-of-heroes
- entra na pasta angular-tour-of-heroes
- clone ou download o Quick start seed 
	- git clone https://github.com/angular/quickstart.git quickstart
	- cd quickstart
- instala os pacotes npm
	- npm install
- carrega a aplicação
	- npm start

IMPORTANTES
angular-tour-of-heroes
| app
|| app.component.ts
|| app.module.ts
|| main.ts
| node_modules ...
| index.html
| package.json
| styles.css
| systemjs.config.js
| tsconfig.json

2. Keep the app transpiling and running
- inicia compilador TypeScript, monitorando mudanças, e inicia nosso servidor.
- roda o compilador em watch mode (monitora mudanças), inicia servidor, carrega aplicação no browser
  e o mantem rodando enquanto construimos a aplicação.
	- npm start

3. Show our Hero
- Para mostrar dados do herói no app.

- atualize AppComponent para que tenha duas propriedades:
	- title: para nome da aplicação.
	- hero: para um herói chamado "Windstorm"
- atualize o template do decorator @Component com data binding para as novas propriedades.

## app.component.ts (AppComponent class)
export class AppComponent {
  title = 'Tour of Heroes';
  hero = 'Windstorm';
}
template: '<h1>{{title}}</h1><h2>{{hero}} details!</h2>'

- O browser deve atualizar sozinho.

4. Hero object
- Convertendo o herói de apenas um nome para uma classe com propriedades.
- Agora com a classe Hero, refatoramos as propriedades da nossa component hero para ser do tipo Hero.
- Iniciamos com id=1 e nome=Windstorm
- Atualizamos o binding do template para referenciar ao nome do hero.

## app.component.ts (Hero class)
export class Hero {
  id: number;
  name: string;
}

## dentro do AppComponent
hero: Hero = {
  id: 1,
  name: 'Windstorm'
};

## dentro do @Component
template: '<h1>{{title}}</h1><h2>{{hero.name}} details!</h2>'

5. Adding more HTML
- Queremos mostrar não só o nome, mas todas as propriedades do herói com <div>.

template: '<h1>{{title}}</h1><h2>{{hero.name}} details!</h2><div><label>id: </label>{{hero.id}}</div><div><label>name: </label>{{hero.name}}</div>'

6. Multi-line template strings
- String grandes de html são ruins.
- Vamos tomar vantagem da feature de string template no ES2015 e TypeScript.

template:
  `
  <h1>{{title}}</h1>
  <h2>{{hero.name}} details!</h2>
  <div><label>id: </label>{{hero.id}}</div>
  <div><label>name: </label>{{hero.name}}</div>
  `

7. Editing Our Hero
- Queremos editar o nome do herói num textbox.
- Refatore o nome do herói como de <label> para <label> e <input>.
- O problema é que, mudando o nome na textbox, a mudança não é refletida na tag <h2>.
- Não vamos conseguir o efeito de reflexão usando um binding de uma via a <input>.

template:
  `
  <h1>{{title}}</h1>
  <h2>{{hero.name}} details!</h2>
  <div><label>id: </label>{{hero.id}}</div>
  <div>
    <label>name: </label>
    <input value="{{hero.name}}" placeholder="name">
  </div>
  `

8. Two-Way Binding
- Para automaticamente atualizar o nome mostrado quando altera-se a textbox, queremos binding de dados de duas vias.
- Para usar two-way data binding para form inputs, importamos FormsModule. 
- Adicionamos ele no array imports do decorator @NgModule. Este array contém a lista de módulos externos usados na aplicação.
- Incluimos o pacote forms que inclui ngModel.
- Agora atualizamos o template para usar a diretiva build-in do ngModel para binding de duas vias.
- Propaga mudanças para qualquer outro binding do hero.name

## app.module.ts (FormsModule import)
import { NgModule }      from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { FormsModule }   from '@angular/forms';

import { AppComponent }  from './app.component';

@NgModule({
  imports: [
    BrowserModule,
    FormsModule
  ],
  declarations: [
    AppComponent
  ],
  bootstrap: [ AppComponent ]
})
export class AppModule { }

## app.component.ts
<input [(ngModel)]="hero.name" placeholder="name">

9. Creating Heroes
- Criamos um array de 10 heróis
- O array HEROES é tipo da classe Hero. 
- Queremos capturar este array de um serviço web.

## app.component.ts (hero array)
const HEROES: Hero[] = [
  { id: 11, name: 'Mr. Nice' },
  { id: 12, name: 'Narco' },
  { id: 13, name: 'Bombasto' },
  { id: 14, name: 'Celeritas' },
  { id: 15, name: 'Magneta' },
  { id: 16, name: 'RubberMan' },
  { id: 17, name: 'Dynama' },
  { id: 18, name: 'Dr IQ' },
  { id: 19, name: 'Magma' },
  { id: 20, name: 'Tornado' }
];

10. Exposing heroes
- Criamos uma propriedade pública em AppComponent para expor o array de heróis para binding.

heroes = HEROES;

11. Displaying heroes in a template
- Criamos uma lista desordenada no nosso template para mostrar o array de heróis.
- Adicionamos o pedaço html abaixo do título e acima dos detalhes dos herói.

## app.component.ts (heroes template)
<h2>My Heroes</h2>
<ul class="heroes">
  <li>
    <!-- each hero goes here -->
  </li>
</ul>

12. Listing heroes with ngFor
- Queremos bind o array de heróis em nosso template, iterando neles e mostrando cada individualmente.
- Precisaremos da ajuda do angular para fazer isso.
- Modifique a tag <li> adicionando a diretiva build-in *ngFor.
- A seguir colocamos propriedades de cada hero.

<li *ngFor="let hero of heroes">
  <span class="badge">{{hero.id}}</span> {{hero.name}}
</li>

13. Styling our heroes
- Vamos melhorar visualmente a lista e torná-la selecionável.
- Adicionamos estilos aos componentes setando styles no decorator @Component em classes CSS.
- Quando colocamos styles num component ele fica restrito ao seu escopo, no caso, apenas em AppComponent.
- 

styles: [`
  .selected {
    background-color: #CFD8DC !important;
    color: white;
  }
  .heroes {
    margin: 0 0 2em 0;
    list-style-type: none;
    padding: 0;
    width: 15em;
  }
  .heroes li {
    cursor: pointer;
    position: relative;
    left: 0;
    background-color: #EEE;
    margin: .5em;
    padding: .3em 0;
    height: 1.6em;
    border-radius: 4px;
  }
  .heroes li.selected:hover {
    background-color: #BBD8DC !important;
    color: white;
  }
  .heroes li:hover {
    color: #607D8B;
    background-color: #DDD;
    left: .1em;
  }
  .heroes .text {
    position: relative;
    top: -3px;
  }
  .heroes .badge {
    display: inline-block;
    font-size: small;
    color: white;
    padding: 0.8em 0.7em 0 0.7em;
    background-color: #607D8B;
    line-height: 1em;
    position: relative;
    left: -1px;
    top: -4px;
    height: 1.8em;
    margin-right: .8em;
    border-radius: 4px 0 0 4px;
  }
`]

14. Selecting a Hero
- Queremos que ao selecionar um herói da lista, seus detalhes que apareçam abaixo na tela.
- Este padrão de UI é conhecido como "master-detail".
- No nosso caso, o master é nossa lista de heróis e o detail é nosso herói selecionado.
- Vamos conectar o master ao detail através da propriedade selectedHero linkada a um evento do mouse.
- Modificamos o <li> colocando um bind de eventos do Angular ao evento de clique.
- O parêntesis identifica o <li> como target para o evento de clique.
- Chama o método onSelect() de AppComponent passando a variável template de entrada hero como argumento.

<li *ngFor="let hero of heroes" (click)="onSelect(hero)">
  <span class="badge">{{hero.id}}</span> {{hero.name}}
</li>

15. Add the click handler
- Criado método onSelect() para gerenciar eventos de clique.
- Deve setar o componente selecionado no herói que o usuário clicou.

16. Expose the selected hero
- Não precisamos mais da propriedade estática hero em AppComponent.
- Substitua por selectedHero.
- Agora crie o método onSelect() que seta a propriedade selectedHero ao hero clicado pelo usuário.
- Conserte no template de hero para selectedHero.

selectedHero: Hero;

onSelect(hero: Hero): void {
  this.selectedHero = hero;
}

<h2>{{selectedHero.name}} details!</h2>
<div><label>id: </label>{{selectedHero.id}}</div>
<div>
    <label>name: </label>
    <input [(ngModel)]="selectedHero.name" placeholder="name"/>
</div>

17. Hide the empty detail with ngIf
- Aqui o hero está indefinido, dando um erro no JavaScript da página.
- Estamos mostrando selectedHero.name, que não existe ainda já que não há hero selecionado.
- Corrigido mantendo os detalhes de fora enquanto não houver hero selecionado.
- Encapsulamos os detalhes HTML do hero com <div> e adicionamos a diretiva build-in ngIf para 
  setar o selectedHero a nossa componente.
- ngIf e ngFor são chamadas diretivas estruturais pois podem mudar a estrutura parcial da DOM.

ngIf and ngFor are called “structural directives” because they can change the structure of portions of the DOM.

EXCEPTION: TypeError: Cannot read property 'name' of undefined in [null]

<div *ngIf="selectedHero">
  <h2>{{selectedHero.name}} details!</h2>
  <div><label>id: </label>{{selectedHero.id}}</div>
  <div>
    <label>name: </label>
    <input [(ngModel)]="selectedHero.name" placeholder="name"/>
  </div>
</div>


18. Styling the selection
- Podemos ver o hero selecionado nos detalhes, mas não fica claro na lista quem foi selecionado.
- Arrumado aplicando a classe selected do CSS ao apropriado <li> na master list.
- Vamos colocar uma cor de fundo no herói selecionado.
- Adicionada uma propriedade binding na classe selected do template.
- A key é o nome da classe CSS (selected).
- O value é true se os dois heróis baterem e false caso contrário.
- Aplica a selected class se os heróis baterem, remova cc.
- [] é a sintaxe para binding de propriedade.

[class.selected]="hero === selectedHero"

<li *ngFor="let hero of heroes"
  [class.selected]="hero === selectedHero"
  (click)="onSelect(hero)">
  <span class="badge">{{hero.id}}</span> {{hero.name}}
</li>

19. Making a Hero Detail Component
- Vamos separar a lista de heróis dos detalhes do herói em duas components.
- Agora estão na mesma component no mesmo arquivo.
- Cada component deve seguir o princípio de única responsabilidade.
- Adicione o arquivo hero-detail.component.ts com a component HeroDetailComponent.
- Importamos os decorators Component e Input do Angular pois usaremos em breve.
- Criamos metadados com o decorator @Component em que especificamos o nome de identificação. 

import { Component, Input } from '@angular/core';

@Component({
  selector: 'my-hero-detail',
})
export class HeroDetailComponent {
}

20. HERO DETAIL TEMPLATE
- Tanto a lista quanto os detalhes do herói estão no mesmo template, vamos cortá-lo.

21. ADD THE HERO PROPERTY
- adicionamos a propriedade hero na classe component, mas hero está definido na app.component.ts.
- Relocamos a classe Hero para o arquivo hero.ts.
- Fizemos isso pois vamos referenciar Hero nas duas components.
- Importamos em cada arquivo.

hero: Hero;

export class Hero {
  id: number;
  name: string;
}

import { Hero } from './hero';

22. THE HERO PROPERTY IS AN INPUT
- AppComponent deve dizer qual é o herói a mostrar os detalhes para a HeroDetailComponent.
- Faremos um bind da propriedade selectedHero da AppComponent com a hero da HeroDetailComponent.
- hero é target do binding.
- Angular insiste que declaremos uma propriedade target como sendo de input. 
- Podemos declarar que hero é de input com o decorator @Input.

<my-hero-detail [hero]="selectedHero"></my-hero-detail>

@Input()
  hero: Hero;

23. Refresh the AppModule
- O módulo raiz da aplicação é o AppModule.
- Precisamos ensiná-la a usar HeroDetailComponent.
- Primeiro importamos HeroDetailComponent.
- Depois adicionamos HeroDetailComponent ao decorator NgModule no array declarations.
- Este array contém a lista de todas as components, pipes e diretivas que criamos e pertencem ao app.

import { HeroDetailComponent } from './hero-detail.component';

@NgModule({
  imports: [
    BrowserModule,
    FormsModule
  ],
  declarations: [
    AppComponent,
    HeroDetailComponent
  ],
  bootstrap: [ AppComponent ]
})
export class AppModule { }

24. Refresh the AppComponent
- Adicione <my-hero-detail> no template de AppComponent onde hero details foi retirado.
- Este foi o nome dado ao seletor nos metadados de HeroDetailComponent.
- As duas components não vão se coordenar até que associemos a propriedade selectedHero de AppComponent 
  a propriedade hero de HeroDetailComponent.

<my-hero-detail [hero]="selectedHero"></my-hero-detail>

25. Creating a Hero Service
- Refatorar acesso a dados com serviços torna mais fácil o teste unitário de uma component com um serviço mock.
- Serviços de dados são invariavelmente assíncronos.
- AppComponent define heróis mock para mostrar. Entretando, definir heróis não é tarefa de uma component. Com isto, 
  fica difícil compartilhar a lista de heróis com outras components e views.
- Refatoraremos a aquisição de dados de heróis para um serviço que pode ser chamado por qualquer component.

26. Create the HeroService
- Criado serviço chamado hero.service.ts.

import { Injectable } from '@angular/core';

@Injectable()
export class HeroService {
}

27. Injectable Services
- @Injectable emite metadados do serviço, metadados que angular pode precisar para injetar outras dependências no serviço.

28. Getting Heroes
- Adicionado método getHeroes
- Nosso serviço encapsula a obtenção de dados de heroi pelas components. E pode obtê-los de qualquer lugar, seja um web service, 
  armazenamento local ou de uma fonte de dados mock.

@Injectable() export class HeroService 
{
	getHeroes(): void {} // stub
}


29. Mock Heroes
- Já temos dados Mock Hero na AppComponent, mas que não pertence a ela. E também não pertence ao serviço.
- Movemos os dados mock para seu próprio arquivo.
- Tire o array HEROES de app.component.ts e mova para mock-heroes.ts.

import { Hero } from './hero';
export const HEROES: Hero[] = [
  {id: 11, name: 'Mr. Nice'},
  {id: 12, name: 'Narco'},
  {id: 13, name: 'Bombasto'},
  {id: 14, name: 'Celeritas'},
  {id: 15, name: 'Magneta'},
  {id: 16, name: 'RubberMan'},
  {id: 17, name: 'Dynama'},
  {id: 18, name: 'Dr IQ'},
  {id: 19, name: 'Magma'},
  {id: 20, name: 'Tornado'}
];

30. Return Mocked Heroes
- O serviço retorna os heróis por meio do método getHeroes.

import { Injectable } from '@angular/core';

import { Hero } from './hero';
import { HEROES } from './mock-heroes';

@Injectable()
export class HeroService {
  getHeroes(): Hero[] {
    return HEROES;
  }
}

31. Use the Hero Service
- Importe o HeroService.

import { HeroService } from './hero.service';
 
32. Do we new the HeroService? No way!
- Não use new em serviços por uma série de razões, incluindo criar uma instancia de  serviço toda vez.

heroService = new HeroService(); // don't do this

33. Inject the HeroService
- A injeção é feita em dois passos: construtor que define uma propriedade privada, adiciona providers de metadados da component.
- O injetor ainda não sabe como criar um HeroService.
- Ensinamos como o injetor deve criar um HeroService registrando um provider HeroService.
- Adicione o array de providers ao fim de metadados de components.
- O array diz ao angular para criar uma instancia de HeroService quando criar um novo AppComponent. O AppComponent pode usar o serviço 
  para obter os heróis e assim pode cada component filha obtê-la.

##app/app.component.ts (constructor)
constructor(private heroService: HeroService) { }

providers: [HeroService]

34. getHeroes in the AppComponent
- O serviço está na variável privada heroService.
- Criamos um método para obter os heróis.

getHeroes(): void {
	this.heroes = this.heroService.getHeroes();
}

35. The ngOnInit Lifecycle Hook
- Não é indicado chamar um server dentro do contrutor. Isto atrapalha testes.
- Chamamos o ngOnInit para chamar o método getHeroes.
- Angular fornece interfaces para se infiltrar no ciclo de vida de uma component: criação, mudanças e destruição.
- Cada interface tem um método simples. Quando a component implementa esse método, Angular chama no tempo apropriado.

import { OnInit } from '@angular/core';

export class AppComponent implements OnInit {
  ngOnInit(): void {
  		this.getHeroes();
  }
}

36. Async Services and Promises
- A assinatura de getHeroes é síncrona.
- Um dia vamos querer ober heróis de um servidor remoto. 
- Quando fizermos isso, precisaremos esperar o servidor responder e não poderemos bloquear a UI enquanto esperamos, mesmo que 
  quiséssemos - não deveriámos - pois o browser não permite.
- Teremos de usar uma técnica assíncrona que mudará a assinatura do método getHeroes.
- Usaremos Promises.

37. The Hero Service makes a Promise
- Uma promise é uma promessa para nos ligar mais tarde quando os resultados estiverem prontos.
- Pedimos a um serviço assíncrono para fazer algum trabalho e entregamo-lhes uma função callback.  
- Ele faz o trabalho e eventualmente chama nossa função com os resultados do trabalho ou um erro.
- Atualize o HeroService com o método Promising-returning getHeroes.
- Ainda usamos dados em mock, pois simulamos o comportamento de um servidor ultra rápido e sem latência retornando uma 
  promessa imediatamente resolvida aos nossos mock heroes como resultado.

38. Act on the Promise
- this.heroes está a receber uma promessa em vez de um array de heroes.
- Precisamos trocar nossa implementação para agir em cima da Promise quando ela resolver.
- Quando a promise se resolver, teremos heroes para mostrar.
- Passamos nossa função callback como argumento ao método de promises chamado 'then'.
- A arrow é mais sucinta que a equivalência, muita usada em callbacks e funções anônimas.
- Nosso callback seta a propriedade da component heroes ao array de heroes retornado pelo serviço.
- Construimos nosso serviço para retornar uma Promise e nosso component para obter dados da Promise.

getHeroes(): Promise<Hero[]> {
  return Promise.resolve(HEROES);
}

##app/app.component.ts (getHeroes - revised)
getHeroes(): void {
  this.heroService.getHeroes().then(heroes => this.heroes = heroes);
}

getHeroesSlowly(): Promise<Hero[]> {
  return new Promise(resolve => {
    // Simulate server latency with 2 second delay
    setTimeout(() => resolve(this.getHeroes()), 2000);
  });
}

###EXEMPLO DE ARROW

getUser()
  .then(function(user) {
    return getRights(user); // getRights is returning a promise
  })
  .then(function(rights) {
    return updateMenu(rights);
  })

CAN BE WRITTEN WITH ARROW FUNCTIONS LIKE THIS:

getUser()
  .then(user => getRights(user))
  .then(rights => updateMenu(rights))

39. Action plan
- Tornar AppComponent numa aplicação que apenas gerencia navegação.
- Relocar coisas de Heroes da AppComponent para uma component separada, a HeroesComponent.
- Adicionar roteamento (ou nevagação).
- Criar um novo DashboardComponent.
- Ligar o Dashboard na estrutura de navegação.

40. HeroesComponent
- AppComponent já é dedicada a heróis. Renomeamos ela para HeroesComponent e criamos outra AppComponent.
- Mude a classe e my-app para my-heroes.

41. Create AppComponent
- Shell da aplicação. Terá links de navegação e topo uma área de display abaixo para as páginas que navegamos.
- Crie app.component.ts, exporte a classe, adiciona @Component com selector my-app, mova title para my-app,
  adiciona my-heroes como chamada, adicione os imports.
- Adicione HeroesComponent no array de declaraçoes AppModule para angular recconhecer tags <my-heroes>.
- Adicione HeroService ao array de providers de AppModule pois iremos usá-los para as views da página.
- Remova HeroService do array de providers da HeroesComponent pois será usado na AppModule.

42. Add Routing
- A lista de heróis será acessada agora por navegação.
- Usaremos o Angular Router.
- É um NgModule chamado RouterModule.
- É a combinação de serviços (RouterModule), múltiplas diretivas (RouterOutlet, RouterLink, RouterLinkActive) e uma 
  configuração (Routes). Iremos configurar as rotas primeiro.

43. Add the base tag
- Abra index.html e adicione <base href="/"> no <head>.

44. Configure routes
- Routes dizem ao roteador qual a view a se mostrar.
- Routes é um array com definições de rotas.
- Temos apenas uma rota definida por enquanto.
- A definição de rota tem: path(bate com o caminho da rota na url), component(component que a rota deve criar quando navega).

import { RouterModule }   from '@angular/router';

##app/app.module.ts (heroes route)
RouterModule.forRoot([
  {
    path: 'heroes',
    component: HeroesComponent
  }
])

45. Make the router available
- Adicionamos o RouterModule configurado ao AppModule através do array de imports.

##app/app.module.ts (app routing)
import { RouterModule }   from '@angular/router';

@NgModule({
  imports: [
    
    RouterModule.forRoot([
      {
        path: 'heroes',
        component: HeroesComponent
      }
    ])
  ],
})

46. Router Outlet
- Se colocar /heroes no browser, deve-se mostrar HeroesComponent. Mas onde na tela?
- Devemos dizê-lo onde na tela adicionando <router-outlet> abaixo do template.
- RouterOutlet é uma das diretivas do RouterModule. 
- Mostra cada component imediatamente abaixo do <router-outlet> enquanto navegamos na aplicação.

47. Router links
- Criamos um link de click para a HeroesComponent.
- diretiva routerLink é ligada a string que diz ao roteador para onde navegar quando o usuário clicar.  
AppComponent é chamada de Router Component.	

template: `
   <h1>{{title}}</h1>
   <a routerLink="/heroes">Heroes</a>
   <router-outlet></router-outlet>
 ` 

48. Add a Dashboard
 - Adiciona outra view.
 - Adicione DashBoardComponent que nos dê algo para navegar para ou de.

##app/dashboard.component.ts (v1)
import { Component } from '@angular/core';

@Component({
  selector: 'my-dashboard',
  template: '<h3>My Dashboard</h3>'
})
export class DashboardComponent { }

49. Configure the dashboard route
- Ensine ao AppModule como navegar na dashboard.
- Importe a component Dashboard e adicione a definição de rota para o array de definições de rotas.

##app/app.module.ts (Dashboard route)
{
  path: 'dashboard',
  component: DashboardComponent
},

declarations: [
  AppComponent,
  DashboardComponent,
  HeroDetailComponent,
  HeroesComponent
],


50. REDIRECTTO
- Queremos que o app mostre o dashboard quando começar.

##app/app.module.ts (redirect)
{
  path: '',
  redirectTo: '/dashboard',
  pathMatch: 'full'
},

51. ADD NAVIGATION TO THE TEMPLATE
- Adicionar um link ao dashboard logo acima do de heroes.

template: `
   <h1>{{title}}</h1>
   <nav>
     <a routerLink="/dashboard">Dashboard</a>
     <a routerLink="/heroes">Heroes</a>
   </nav>
   <router-outlet></router-outlet>
 `

52. Dashboard Top Heroes
- Para mostrar os 4 herois top.
- Troque metadados template para uma templateUrl que aponta.
- Setar moduleId para module.id para carregamento de modulo relativo ao templateUrl.

##dashboard.component.ts
@Component({
  // moduleId: module.id, // moduleId should be a string.
  selector: 'my-dashboard',
  templateUrl: 'dashboard.component.html',
})

##dashboard.component.html
<h3>Top Heroes</h3>
<div class="grid grid-pad">
  <div *ngFor="let hero of heroes" class="col-1-4">
    <div class="module hero">
      <h4>{{hero.name}}</h4>
    </div>
  </div>
</div>

53. Share the HeroService
- Colocar o HeroService no array providers de AppModule criou uma instancia singleton do serviço, 
  disponível para todas as components da aplicação.
- Usaremos na DashboardComponent.

54. Get Heroes
- Implemente a classe DashboardComponent da seguinte forma.
- Define uma propriedade array de heroes.
- Injeta o HeroService no construtor e coloca num campo privado heroService.
- Chama o serviço para obter heroes dentro do ngOnInit.
- Pegamos do segundo ao quinto herói.

import { Component, OnInit } from '@angular/core';

import { Hero } from './hero';
import { HeroService } from './hero.service';

export class DashboardComponent implements OnInit {

  heroes: Hero[] = [];

  constructor(private heroService: HeroService) { }

  ngOnInit(): void {
    this.heroService.getHeroes()
      .then(heroes => this.heroes = heroes.slice(1, 5));
  }
}

55. Navigate to Hero Details
- Faltou ir aos detalhes do Dashboard.
- Já vamos aos detalhes da lista.
- Através da url direto também.

56. Routing to a hero detail
- Adicionamos uma rota para HeroDetailComponent em app.module.ts onde nossas outras rotas estão configuradas.
- A rota é um pouco diferente pois teremos de dizer ao HeroDetailComponent qual o herói a se mostrar.
- Não devemos dizer nada a HerosComponent ou a DashboardComponent.
- Até o momento o pai HerosComponent seta a propriedade hero de HeroDetailComponent com um binding assim:
  <my-hero-detail [hero]="selectedHero"></my-hero-detail>
- Não podemos fazer isto com uma url.

57.Parameterized route
- Podemos adicionar o id do herói na url.
- Quando rotear ao herói de id 11, esperamos ver a url da forma /detail/11.

58. Configure a Route with a Parameter

{
  path: 'detail/:id',
  component: HeroDetailComponent
},

59. Revise the HeroDetailComponent
- Não vamos mais receber o herói num binding de propriedade numa component pai.
- HeroDetailComponent deve obter o id dos parâmetros observados no serviço ActivateRoute 
  e usar o HeroService para obter o hero com o id correspondente.
- Usaremos os serviços ActivateRoute, HeroService e Location injetados no construtor, 
  salvando seus valores em campos privados.
- Importe o operador switchMap para usar com os parâmetros de rotas Observable.
- Queremos implementar também a interface OnInit também para poder usar o ngOnInit.
- Dentro do ngOnInit, catamos os parâmetros private e extraímos o id do serviço ActivatedRoute
  e usamos o HeroService para obter o herói com o id correspondente.
- switchMap mapeia o id observado nos parâmetros da rota em um novo Observable, resultado do 
  HeroService.getHero.
- O + converte o param da rota de string para número. 



// Keep the Input import for now, we'll remove it later:
import { Component, Input, OnInit } from '@angular/core';
import { ActivatedRoute, Params }   from '@angular/router';
import { Location }                 from '@angular/common';

import { HeroService } from './hero.service';
import 'rxjs/add/operator/switchMap';

##app/hero-detail.component.ts (constructor)
constructor(
  private heroService: HeroService,
  private route: ActivatedRoute,
  private location: Location
) {}

export class HeroDetailComponent implements OnInit {

ngOnInit(): void {
this.route.params
  .switchMap((params: Params) => this.heroService.getHero(+params['id']))
  .subscribe(hero => this.hero = hero);


60. Add HeroService.getHero
- HeroService não tem um método getHero.

getHero(id: number): Promise<Hero> {
  return this.getHeroes()
             .then(heroes => heroes.find(hero => hero.id === id));
}


61. Find our way back
- Método para voltar para a página anterior.
- Atualizamos os metadados com um moduleId e templateUrl apontando pro 
  arquivo de template criado.

goBack(): void {
  this.location.back();
}

<div *ngIf="hero">
  <h2>{{hero.name}} details!</h2>
  <div>
    <label>id: </label>{{hero.id}}</div>
  <div>
    <label>name: </label>
    <input [(ngModel)]="hero.name" placeholder="name" />
  </div>
  <button (click)="goBack()">Back</button>
</div>

@Component({
  // moduleId: module.id,
  selector: 'my-hero-detail',
  templateUrl: './hero-detail.component.html',
})

62. Select a Dashboard Hero
- Vamos tornar os heróis da dashboard selecionáveis.
 
<a *ngFor="let hero of heroes"  [routerLink]="['/detail', hero.id]"  class="col-1-4"> </a

63. Refactor routes to a Routing Module
- Passamos as definições de rotas no AppModule para uma classe RoutingModule.
- Criamos app-routing.module.ts.

import { NgModule }             from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { DashboardComponent }   from './dashboard.component';
import { HeroesComponent }      from './heroes.component';
import { HeroDetailComponent }  from './hero-detail.component';
const routes: Routes = [
  { path: '', redirectTo: '/dashboard', pathMatch: 'full' },
  { path: 'dashboard',  component: DashboardComponent },
  { path: 'detail/:id', component: HeroDetailComponent },
  { path: 'heroes',     component: HeroesComponent }
];
@NgModule({
  imports: [ RouterModule.forRoot(routes) ],
  exports: [ RouterModule ]
})
export class AppRoutingModule {}


64. Update AppModule
- Remova antigas configurações de rotas de AppModule e importe AppRoutingModule.

import { NgModule }       from '@angular/core';
import { BrowserModule }  from '@angular/platform-browser';
import { FormsModule }    from '@angular/forms';
import { AppComponent }         from './app.component';
import { DashboardComponent }   from './dashboard.component';
import { HeroDetailComponent }  from './hero-detail.component';
import { HeroesComponent }      from './heroes.component';
import { HeroService }          from './hero.service';
import { AppRoutingModule }     from './app-routing.module';
@NgModule({
  imports: [
    BrowserModule,
    FormsModule,
    AppRoutingModule
  ],
  declarations: [
    AppComponent,
    DashboardComponent,
    HeroDetailComponent,
    HeroesComponent
  ],
  providers: [ HeroService ],
  bootstrap: [ AppComponent ]
})
export class AppModule { }

65. Select a Hero in the HeroesComponent
- Atualmente os detalhes aparecem logo abaixo da lista de heróis.
- Queremos que seja feita numa view diferente.
- Mostraremos os detalhes numa página separada que iremos rotear.
- Colocaremos mini-detalhes na mesma página com um botão para a view de detalhes.

<div *ngIf="selectedHero">
  <h2>
    {{selectedHero.name | uppercase}} is my hero
  </h2>
  <button (click)="gotoDetail()">View Details</button>
</div>

66. Format with the uppercase pipe
- O nome do herói está em letras maiúsculas devido ao | uppercase.
- É um pipe interpolado com o binding.
- Pipes são bons para formatar strings, montantes de moedas, datas e outros dados.

67. Move content out of the component file
- Migramos os conteúdos html e css para um arquivo separado.
- Ligue os arquivos com templateUrl e styleUrl.

@Component({
  moduleId: module.id,
  selector: 'my-heroes',
  templateUrl: 'heroes.component.html',
  styleUrls: [ 'heroes.component.css' ]
})


68. Update the HeroesComponent class.
- Falta importar router da lib router do Angular.
- Injetar router no construtor com o HeroService.
- Implementar gotoDetail chamando o método router.navigate.

export class HeroesComponent implements OnInit {
  heroes: Hero[];
  selectedHero: Hero;

  constructor(
    private router: Router,
    private heroService: HeroService) { }

  getHeroes(): void {
    this.heroService.getHeroes().then(heroes => this.heroes = heroes);
  }

  ngOnInit(): void {
    this.getHeroes();
  }

  onSelect(hero: Hero): void {
    this.selectedHero = hero;
  }

  gotoDetail(): void {
    this.router.navigate(['/detail', this.selectedHero.id]);
  }
}

69. Styling the App
- Melhorando o visual.

70. Stylish Hero Details

label {
  display: inline-block;
  width: 3em;
  margin: .5em 0;
  color: #607D8B;
  font-weight: bold;
}
input {
  height: 2em;
  font-size: 1em;
  padding-left: .4em;
}
button {
  margin-top: 20px;
  font-family: Arial;
  background-color: #eee;
  border: none;
  padding: 5px 10px;
  border-radius: 4px;
  cursor: pointer; cursor: hand;
}
button:hover {
  background-color: #cfd8dc;
}
button:disabled {
  background-color: #eee;
  color: #ccc; 
  cursor: auto;
}

[class*='col-'] {
  float: left;
  padding-right: 20px;
  padding-bottom: 20px;
}
[class*='col-']:last-of-type {
  padding-right: 0;
}
a {
  text-decoration: none;
}
*, *:after, *:before {
  -webkit-box-sizing: border-box;
  -moz-box-sizing: border-box;
  box-sizing: border-box;
}
h3 {
  text-align: center; margin-bottom: 0;
}
h4 {
  position: relative;
}
.grid {
  margin: 0;
}
.col-1-4 {
  width: 25%;
}
.module {
  padding: 20px;
  text-align: center;
  color: #eee;
  max-height: 120px;
  min-width: 120px;
  background-color: #607D8B;
  border-radius: 2px;
}
.module:hover {
  background-color: #EEE;
  cursor: pointer;
  color: #607d8b;
}
.grid-pad {
  padding: 10px 0;
}
.grid-pad > [class*='col-']:last-of-type {
  padding-right: 20px;
}
@media (max-width: 600px) {
  .module {
    font-size: 10px;
    max-height: 75px; }
}
@media (max-width: 1024px) {
  .grid {
    margin: 0;
  }
  .module {
    min-width: 60px;
  }
}

71. Style the Navigation Links 

h1 {
  font-size: 1.2em;
  color: #999;
  margin-bottom: 0;
}
h2 {
  font-size: 2em;
  margin-top: 0;
  padding-top: 0;
}
nav a {
  padding: 5px 10px;
  text-decoration: none;
  margin-top: 10px;
  display: inline-block;
  background-color: #eee;
  border-radius: 4px;
}
nav a:visited, a:link {
  color: #607D8B;
}
nav a:hover {
  color: #039be5;
  background-color: #CFD8DC;
}
nav a.active {
  color: #039be5;
}

72. The routerLinkActive directive
- Esta diretiva permite adicionar uma classe ao elemento de navegação HTML cuja rota bate com a rota ativa.
- Percisamos apenas definir seu estilo.

##app/app.component.ts (active router links)
template: `
  <h1>{{title}}</h1>
  <nav>
    <a routerLink="/dashboard" routerLinkActive="active">Dashboard</a>
    <a routerLink="/heroes" routerLinkActive="active">Heroes</a>
  </nav>
  <router-outlet></router-outlet>
`,

73. Global application styles
- Empacotar html, css e código num pacote para reusar depois.
- Podemos usar styles globais por todo o app.

##styles.css (excerpt)
/* Master Styles */
h1 {
  color: #369;
  font-family: Arial, Helvetica, sans-serif;
  font-size: 250%;
}
h2, h3 {
  color: #444;
  font-family: Arial, Helvetica, sans-serif;
  font-weight: lighter;
}
body {
  margin: 2em;
}
body, input[text], button {
  color: #888;
  font-family: Cambria, Georgia;
}
/* . . . */
/* everywhere else */
* {
  font-family: Arial, Helvetica, sans-serif;
}

74. Providing HTTP Services
- HttpModule não é core do Angular. 
- Módulo adicional chamado @angular/http.
- Adicionado como parte do pacote npm.
- Podemos importar de @angular/http pois systemjs.config configurou SystemJS para carregar a biblioteca 
  quando precisarmos dela.

75. Register for HTTP services.
- Registramos todos os serviços adicionando HttpModule a lista de imports no AppModule onde nós 
  bootstrap a aplicação e temos AppComponent como root.

import { NgModule }      from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { FormsModule }   from '@angular/forms';
import { HttpModule }    from '@angular/http';
import { AppRoutingModule } from './app-routing.module';
import { AppComponent }         from './app.component';
import { DashboardComponent }   from './dashboard.component';
import { HeroesComponent }      from './heroes.component';
import { HeroDetailComponent }  from './hero-detail.component';
import { HeroService }          from './hero.service';
@NgModule({
  imports: [
    BrowserModule,
    FormsModule,
    HttpModule,
    AppRoutingModule
  ],
  declarations: [
    AppComponent,
    DashboardComponent,
    HeroDetailComponent,
    HeroesComponent,
  ],
  providers: [ HeroService ],
  bootstrap: [ AppComponent ]
})
export class AppModule { }

[ERROR - angular-in-memory] 76. Simulating the web API
- Não temos um servidor web para gerenciar requests para heróis.
- Então precisamos criar um fake.
- Vamos enganar o cliente HTTP para buscar e salvar dados de um serviço de 
  simulação, a API in-memory web.
- Em vez de requerer uma API de servidor real, vamos simular a comunicação com o 
  servidor remoto adicionando InMemoryWebApiModule ao imports de módulos,
  alterando o servidor backend http cliente XHR com uma alternativa in-memory.
- forRoot toma uma classe InMemoryDataService.
- mock-heroes.ts é substituído e pode ser removido.



import { NgModule }      from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { FormsModule }   from '@angular/forms';
import { HttpModule }    from '@angular/http';

import { AppRoutingModule } from './app-routing.module';

// Imports for loading & configuring the in-memory web api
import { InMemoryWebApiModule } from 'angular-in-memory-web-api';
import { InMemoryDataService }  from './in-memory-data.service';

import { AppComponent }         from './app.component';
import { DashboardComponent }   from './dashboard.component';
import { HeroesComponent }      from './heroes.component';
import { HeroDetailComponent }  from './hero-detail.component';
import { HeroService }          from './hero.service';

@NgModule({
  imports: [
    BrowserModule,
    FormsModule,
    HttpModule,
    InMemoryWebApiModule.forRoot(InMemoryDataService),
    AppRoutingModule
  ],
  declarations: [
    AppComponent,
    DashboardComponent,
    HeroDetailComponent,
    HeroesComponent,
  ],
  providers: [ HeroService ],
  bootstrap: [ AppComponent ]
})
export class AppModule { }

##app/in-memory-data.service.ts
import { InMemoryDbService } from 'angular-in-memory-web-api';
export class InMemoryDataService implements InMemoryDbService {
  createDb() {
    let heroes = [
      {id: 11, name: 'Mr. Nice'},
      {id: 12, name: 'Narco'},
      {id: 13, name: 'Bombasto'},
      {id: 14, name: 'Celeritas'},
      {id: 15, name: 'Magneta'},
      {id: 16, name: 'RubberMan'},
      {id: 17, name: 'Dynama'},
      {id: 18, name: 'Dr IQ'},
      {id: 19, name: 'Magma'},
      {id: 20, name: 'Tornado'}
    ];
    return {heroes};
  }
}

77. Heroes and HTTP
- Precisamos alterar a Promise de receber de um mock para um http.

import { Injectable }    from '@angular/core';
import { Headers, Http } from '@angular/http';

import 'rxjs/add/operator/toPromise';

import { Hero } from './hero';
  

private heroesUrl = 'api/heroes';  // URL to web api

constructor(private http: Http) { }

getHeroes(): Promise<Hero[]> {
  return this.http.get(this.heroesUrl)
             .toPromise()
             .then(response => response.json().data as Hero[])
             .catch(this.handleError);
}

private handleError(error: any): Promise<any> {
  console.error('An error occurred', error); // for demo purposes only
  return Promise.reject(error.message || error);
}

78. HTTP Promise
- O http.get do angular retorna um RxJS Observable. 
- Observables são uma maneira de gerenciar fluxos de dados assíncronos.

79. Extracting the data in the then callback
- No callback then da promessa chamamos o método JSON da resposta HTTP para extrair os dados de dentro da resposta.

80. Error Handling
- Ao fim de getHeroes capturamos falhas do servidor e passamos ao handler de erros.

81. Get hero by id
- É normal obter um único hero com um id. 
- Podemos usar um método request get-by-id.

82. Unchanged getHeroes API
- Retornaremos Promises do dois métodos.

83. Update Hero details
- Agora as mudanças no nome dos heroes são perdidas.
- A lista mock compartilhada agora é um server, temos que atualizar o valor no server.

84. Save hero details
- Adicione botão e método de salvar dados no server.

<button (click)="save()">Save</button>

save(): void {
  this.heroService.update(this.hero)
    .then(() => this.goBack());
}

85. Hero service update method
- A troca de mensagem para o servidor é feita via um JSON.
- Identificamos qual herói deve ser atualizado codificando o id do herói na url.
- O corpo do put é a string codificada JSON do herói, obtida chamando JSON.stringify.
- Identificamos o tipo de conteúdo do corpo (application/json) no header do request.

update(hero: Hero): Promise<Hero> {
  const url = `${this.heroesUrl}/${hero.id}`;
  return this.http
    .put(url, JSON.stringify(hero), {headers: this.headers})
    .toPromise()
    .then(() => hero)
    .catch(this.handleError);
}

86. Add a hero
- Precisamos saber o nome de um herói para adicioná-lo.
- Usamos um elemento input pairado com um botão de add.
- Em resposta ao evento de clique, chamamos o gerenciador de cliques para limpar a input 
  para ser usada novamente.
- O html chama as funções de javascript.

<div>
  <label>Hero name:</label> <input #heroName />
  <button (click)="add(heroName.value); heroName.value=''">
    Add
  </button>
</div>

add(name: string): void {
  name = name.trim();
  if (!name) { return; }
  this.heroService.create(name)
    .then(hero => {
      this.heroes.push(hero);
      this.selectedHero = null;
    });
}

create(name: string): Promise<Hero> {
  return this.http
    .post(this.heroesUrl, JSON.stringify({name: name}), {headers: this.headers})
    .toPromise()
    .then(res => res.json().data)
    .catch(this.handleError);
}

87. Delete a hero
- Adicionado um botão de delete para cada hero.

<li *ngFor="let hero of heroes" (click)="onSelect(hero)"
      [class.selected]="hero === selectedHero">
    <span class="badge">{{hero.id}}</span>
    <span>{{hero.name}}</span>
    <button class="delete"
      (click)="delete(hero); $event.stopPropagation()"">x
    </button>
</li>

delete(hero: Hero): void {
  this.heroService
      .delete(hero.id)
      .then(() => {
        this.heroes = this.heroes.filter(h => h !== hero);
        if (this.selectedHero === hero) { this.selectedHero = null; }
      });
}

button.delete {
  float:right;
  margin-top: 2px;
  margin-right: .8em;
  background-color: gray !important;
  color:white;
}

88. Hero service delete method
- Usa método delete do HTTP para remover o herói do servidor.

delete(id: number): Promise<void> {
  const url = `${this.heroesUrl}/${id}`;
  return this.http.delete(url, {headers: this.headers})
    .toPromise()
    .then(() => null)
    .catch(this.handleError);
}

89. Observables
- Cada método de serviço HTTP retorna objetos HTTP Response Observable.
- HeroService converte o observável numa promessa e retorna a promessa ao chamador.
- Aprenderemos como retornar o observável diretamente.

90. Background
- Um Observable é uma stream de eventos que podemos processar com operadores de arrays.
- Nós desenvolvedores aumentamos esse suporte com operadores e extensões da biblioteca RxJS Observables.
- Vamos ver como em breve.
- Usar promessa facilita que o chamador entenda os dados recebidos, sendo muito usada em Javascript.
- Porém sequências request-cancel-new-request são difíceis de implementar em Promises.
- Mas é fácil com Observables.

91. Search-by-name
- Adicionamos procura por heróis.
- Enquanto o usuário tecla na searchbox, faremos requests http para heróis filtrados por nome.
- Criamos HeroSearchService para mandar queries para nossa api de server.
- http.get() é similar, mas manda uma string query na url e não chama mais toPromise.

##app/hero-search.service.ts
import { Injectable }     from '@angular/core';
import { Http, Response } from '@angular/http';
import { Observable } from 'rxjs';
import { Hero }           from './hero';

@Injectable()
export class HeroSearchService 
{
  constructor(private http: Http) {}
  search(term: string): Observable<Hero[]> {
    return this.http
               .get(`app/heroes/?name=${term}`)
               .map((r: Response) => r.json().data as Hero[]);
  }
}

92. HeroSearchComponent
- Enquanto o user digita, um evento keyup chama o método search da componenet com novo valor de busca.
- *ngFor não pode fazer nada com um Observável até que joguemos ele num pipe assíncrono (AsyncPipe). 
- O pipe assíncrono se inscreve no Observável e produz o array de heroes para *ngFor.
- Crie a classe e metadados HeroSearchComponents.

##app/hero-search.component.html
<div id="search-component">
  <h4>Hero Search</h4>
  <input #searchBox id="search-box" (keyup)="search(searchBox.value)" />
  <div>
    <div *ngFor="let hero of heroes | async"
         (click)="gotoDetail(hero)" class="search-result" >
      {{hero.name}}
    </div>
  </div>
</div>

##app/hero-search.component.css
.search-result{
  border-bottom: 1px solid gray;
  border-left: 1px solid gray;
  border-right: 1px solid gray;
  width:195px;
  height: 20px;
  padding: 5px;
  background-color: white;
  cursor: pointer;
}
#search-box{
  width: 200px;
  height: 20px;
}


##app/hero-search.component.ts
import { Component, OnInit } from '@angular/core';
import { Router }            from '@angular/router';
import { Observable }        from 'rxjs/Observable';
import { Subject }           from 'rxjs/Subject';
import { HeroSearchService } from './hero-search.service';
import { Hero } from './hero';
@Component({
  moduleId: module.id,
  selector: 'hero-search',
  templateUrl: 'hero-search.component.html',
  styleUrls: [ 'hero-search.component.css' ],
  providers: [HeroSearchService]
})
export class HeroSearchComponent implements OnInit {
  heroes: Observable<Hero[]>;
  private searchTerms = new Subject<string>();
  constructor(
    private heroSearchService: HeroSearchService,
    private router: Router) {}
  // Push a search term into the observable stream.
  search(term: string): void {
    this.searchTerms.next(term);
  }
  ngOnInit(): void {
    this.heroes = this.searchTerms
      .debounceTime(300)        // wait for 300ms pause in events
      .distinctUntilChanged()   // ignore if next search term is same as previous
      .switchMap(term => term   // switch to new observable each time
        // return the http search observable
        ? this.heroSearchService.search(term)
        // or the observable of empty heroes if no search term
        : Observable.of<Hero[]>([]))
      .catch(error => {
        // TODO: real error handling
        console.log(error);
        return Observable.of<Hero[]>([]);
      });
  }
  gotoDetail(hero: Hero): void {
    let link = ['/detail', hero.id];
    this.router.navigate(link);
  }
}

93. SEARCH TERMS
- Subject é um produtor de um evento de stream observável.
- searchTerms produz um Observável de strings, o critério de filtro para a procura de nome.
- cada chamada a search coloca uma nova string na stream observável do sujeito chamando next.

private searchTerms = new Subject<string>();

// Push a search term into the observable stream.
search(term: string): void {
  this.searchTerms.next(term);
}

94. INITIALIZE THE HEROES PROPERTY (NGONINIT)
- Um Subject é também um Observable. 
- Tornamos a stream de procura em streams de arrays de herois e colocamos o resultado 
  na property heroes.
- Se passássemos todas as nossas keystrokes diretamente ao a HeroSearchService, teríamos uma 
  tempestade de requests HTTP.
- Encadeamos operadores Observable à string Observable que reduz o fluxo de request.
- Fazemos menos chamadas a HeroSearchService;
- switchMap chama nosso serviço de procura para cada termo de procura que lança debounce e 
  distinctUntilChanged. Cancela e descarta procuras anteriores observable.


heroes: Observable<Hero[]>;

ngOnInit(): void {
  this.heroes = this.searchTerms
    .debounceTime(300)        // wait for 300ms pause in events
    .distinctUntilChanged()   // ignore if next search term is same as previous
    .switchMap(term => term   // switch to new observable each time
      // return the http search observable
      ? this.heroSearchService.search(term)
      // or the observable of empty heroes if no search term
      : Observable.of<Hero[]>([]))
    .catch(error => {
      // TODO: real error handling
      console.log(error);
      return Observable.of<Hero[]>([]);
    });
}

95. Import RxJS operators
- Adiciona operadores aos Observáveis.

// Observable class extensions
import 'rxjs/add/observable/of';
import 'rxjs/add/observable/throw';

// Observable operators
import 'rxjs/add/operator/catch';
import 'rxjs/add/operator/debounceTime';
import 'rxjs/add/operator/distinctUntilChanged';
import 'rxjs/add/operator/do';
import 'rxjs/add/operator/filter';
import 'rxjs/add/operator/map';
import 'rxjs/add/operator/switchMap';

96. Add the search component to the dashboard
- Adicionamos a procura de heroes no html.

<h3>Top Heroes</h3>
<div class="grid grid-pad">
  <a *ngFor="let hero of heroes"  [routerLink]="['/detail', hero.id]"  class="col-1-4">
    <div class="module hero">
      <h4>{{hero.name}}</h4>
    </div>
  </a>
</div>
<hero-search></hero-search>


