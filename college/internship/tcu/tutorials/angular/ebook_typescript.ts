79 - 3.2.14

TypeScript é uma linguagem com suporte ao ES6 (ECMAScript 2015, nova especificação do JavaScript), 
                           com suporte a annotations 
                           e suporte a tipos (definição de tipos em variáveis, parâmetros e retorno de métodos). 

2.3.1 TiposBásicos

• boolean: Pode assumir os valores true ou false 
• number: Assume qualquer número, como inteiro ou ponto flutuante. 
• string: Tipo texto, pode ser atribuído com aspas simples ou duplas.

var NOME_DA_VARIAVEL : TIPO = VALOR
		
2.3.2 Arrays

var list:number[] = [1,2,3];
ou 
var list:Array<number> = [1,2,3];

var arr:Array<Point> = [ new Point(10,10), new Point(20,30), new Point(30,10) ]


2.3.3 Enum

enum Color {Red, Green, Blue}; 
var c: Color = Color.Green;

2.3.4 Any

O tipo any assume qualquer tipo, sendo string, number, boolean etc.

2.3.5 Void

function warnUser(): void { 
	alert("This is my warning message"); 
}

## Passar variáveis entre components

#app/videolist.component.ts
@Component({ 
	selector: 'video-list', 
	templateUrl: 'app/videolist.component.html', 
	inputs: ['videos'] 
}) 
export class VideoListComponent {
}

#app/videolist.component.ts
@Component({ 
	selector: 'video-list', 
	templateUrl: 'app/videolist.component.html' 
}) 
export class VideoListComponent { 
	@input() videos; 
}

#app/app.component.html
<h1 class="jumbotron"> 
	{{title}} 
</h1> 
<video-list [videos]="videos"></video-list>


# Mostrar erros na tela
console.log(JSON.stringify(vid));

# Repasse de variáveis vs Eventos
Nos tempaltes, usamos [ ] para repassar variáveis ao componente, e usamos ( ) para indicar eventos.
















