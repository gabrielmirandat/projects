https://jsfiddle.net/chrisvfritz/50wL7mdz/
https://yesno.wtf/api
camelCase or kebab-case

https://vuejs.org/v2/guide/installation.html
## INSTALLATION

$ sudo npm install -g vue
$ sudo npm install --global vue-cli
$ vue init webpack my-project
$ cd my-project
$ npm install
$ npm run dev

https://vuejs.org/v2/guide/index.html
## INTRODUCTION

# "text interpollation"
#
<div id="app">  {{ message }}  </div>
data: { message: 'Hello Vue!' }

# "bind element attributes"
#
<div id="app-2">
  <span v-bind:title="message">
    Hover your mouse over me for a few seconds
    to see my dynamically bound title!
  </span>
</div>

data: {
    message: 'You loaded this page on ' + new Date()
}

# "Conditionals"
#
<div id="app-3">
  <p v-if="seen">Now you see me</p>
</div>

data: {
    seen: true
}

# "Loops"
#
<div id="app-4">
  <ol>
    <li v-for="todo in todos">
      {{ todo.text }}
    </li>
  </ol>
</div>

data: {
    todos: [
      { text: 'Learn JavaScript' },
      { text: 'Learn Vue' },
      { text: 'Build something awesome' }
    ]
}

# "Handling User Input"
# 
<div id="app-5">
  <button v-on:click="reverseMessage">Reverse Message</button>
</div>

methods: {
    reverseMessage: function () {
      this.message = this.message.split('').reverse().join('')
}

# "v-model" directive that makes two-way binding between form input and app state
# 
<div id="app-6">
  <p>{{ message }}</p>
  <input v-model="message">
</div>

data: {
    message: 'Hello Vue!'
}

# "Composing with Components"
#
// ex1
// Define a new component called todo-item
<ol>
  <!-- Create an instance of the todo-item component -->
  <todo-item></todo-item>
</ol>

Vue.component('todo-item', {
  template: '<li>This is a todo</li>'
})

// ex2
<div id="app-7">
  <ol>
    <todo-item
      v-for="item in groceryList"
      v-bind:todo="item"
      v-bind:key="item.id">
    </todo-item>
  </ol>
</div>

Vue.component('todo-item', {
  props: ['todo'],
  template: '<li>{{ todo.text }}</li>'
})
var app7 = new Vue({
  el: '#app-7',
  data: {
    groceryList: [
      { id: 0, text: 'Vegetables' },
      { id: 1, text: 'Cheese' },
      { id: 2, text: 'Whatever else humans are supposed to eat' }
    ]
  }
})


https://vuejs.org/v2/guide/instance.html
## VUE INSTANCE 

vm
	referencia a instancia vue
opções para o construtor
	https://vuejs.org/v2/api/
extender construtores de components	
	var MyComponent = Vue.extend({/*extension options*/})
	var myComponentInstance = new MyComponent()
cada instancia Vue torna claro seu objeto 'data' (é reativo)
alterar variaveis data por fora alteram o valor dentro da instancia
	vm.a === data.a // -> true
Vue também torna claro propriedades e métodos prefixados com '$'
	vm.$data === data // -> true
	vm.$el === document.getElementById('example') // -> true
	// $watch is an instance method
	vm.$watch('a', function (newVal, oldVal) {
  	// this callback will be called when `vm.a` changes
Não usar função flexa em callback ou propriedade de instância '=>'
	senão comportamento indefinido

https://vuejs.org/v2/guide/syntax.html
## SINTAXE TEMPLATE

-> "data binding com interpolação de texto"
	<span> Message: {{ msg }} </span>

-> "data binding com interpolação dentro da tag HTLM só com valor"
tem falha de segurança
	<div v-html="rawHtml"></div>

-> "data binding com interpolação dentro da tag HTLM com chave:valor"
	<div v-bind:id="dynamicId"></div>
	<button v-bind:disabled="someDynamicCondition">Button</button>

-> "binding por javascript é permitido"
	{{ number + 1 }}
	{{ ok ? 'YES' : 'NO' }}
	{{ message.split('').reverse().join('') }}
	<div v-bind:id="'list-' + id"></div>

-> "escuta por eventos"
	<a v-on:click="doSomething">


Diretivas 'v-' reativamente aplica efeitos colaterais
	<p v-if="seen">Now you see me</p>
	<a v-bind:href="url"></a>
	<a v-on:click="doSomething">

Modificadores mudam o comportamento da diretiva de maneira especial
	.prevent chama event.preventDefault() quando há evento no v-on
	<form v-on:submit.prevent="onSubmit"></form>

Filtros são usados em {{}} e em v-bind para formatar texto
	<!-- in mustaches -->
	{{ message | capitalize }}
	<!-- in v-bind -->
	<div v-bind:id="rawId | formatId"></div>

Shorthands
	v-bind:href ==> :href
	v-on:click  ==> @click

https://vuejs.org/v2/guide/computed.html#Computed-Properties
## COMPUTED PROPERTIES AND WATCHERS

// mesmo que methods, mas usa cache baseado em dependencias
// só recalcula quando uma dependência muda
-> "computed property"
computed: {
    // a computed getter
    reversedMessage: function () {
      // `this` points to the vm instance
      return this.message.split('').reverse().join('')
  	}
}

console.log(vm.reversedMessage) // -> 'olleH'
vm.message = 'Goodbye'
console.log(vm.reversedMessage) // -> 'eybdooG'

// também observa e reage a mudança de dados
// mais genérica, mas preferivel usar computed
-> "watch properties"
// mau uso
watch: {
	firstName: function (val) {
      this.fullName = val + ' ' + this.lastName
    },
    lastName: function (val) {
      this.fullName = this.firstName + ' ' + val
    }
}

// bom uso (operações assíncronas ou caras em resposta a mudança de dados)
// nesse caso, conseguimos realizar operações assíncronas (acesso a API) 
// limitando o quão frequentemente fazemos isso e setar estados intermediários 
// até conseguirmos uma resposta final
// só é possível fazer estas coisas com watch
// _.debounc - limita frequencia de acesso quando é assíncrono diminuindo complexidade
getAnswer: _.debounce(
      function () {
        if (this.question.indexOf('?') === -1) {
          this.answer = 'Questions usually contain a question mark. ;-)'
          return
        }
        this.answer = 'Thinking...'
        var vm = this
        axios.get('https://yesno.wtf/api')
          .then(function (response) {
            vm.answer = _.capitalize(response.data.answer)
          })
          .catch(function (error) {
            vm.answer = 'Error! Could not reach the API. ' + error
          })
      },
      // This is the number of milliseconds we wait for the
      // user to stop typing.
      500
    )
}

// setando valores computed
-> "computed setter"
computed: {
  fullName: {
    // getter
    get: function () {
      return this.firstName + ' ' + this.lastName
    },
    // setter
    set: function (newValue) {
      var names = newValue.split(' ')
      this.firstName = names[0]
      this.lastName = names[names.length - 1]
    }
  }
}

https://vuejs.org/v2/guide/class-and-style.html
## CLASS AND STYLE BINDINGS

// mexer com concatenação de strings é suscetível a erro
// melhorias especiais quando v-bind é usado com class e style

// alterna dinamicamente entre classes
// presença da classe active depende de isActive
<div v-bind:class="{ active: isActive }"></div>

// podemos passar um array a v-bind:class para aplicar uma lista de classes
<div v-bind:class="[activeClass, errorClass]">

// alterna uma classe condicionalmente
<div v-bind:class="[isActive ? activeClass : '', errorClass]">

// sendo o mesmo de 
<div v-bind:class="[{ active: isActive }, errorClass]">

// style é como se fosse css, mas é javascript
<div v-bind:style="{ color: activeColor, fontSize: fontSize + 'px' }"></div>
data: {
  activeColor: 'red',
  fontSize: 30
}

// ou de forma mais limpa
<div v-bind:style="styleObject"></div>
data: {
  styleObject: {
    color: 'red',
    fontSize: '13px'
  }
}

// aplica multiplos estilos ao mesmo elemento
<div v-bind:style="[baseStyles, overridingStyles]">

// array de múltiplos valores (prefixado) para propriedade
// só renderiza último valor se o browser suportar
<div v-bind:style="{ display: ['-webkit-box', '-ms-flexbox', 'flex'] }">

https://vuejs.org/v2/guide/conditional.html
## CONDITIONAL RENDERING

-> "v-if v-else-if v-else"
<div v-if="type === 'A'">
  A
</div>
<div v-else-if="type === 'B'">
  B
</div>
<div v-else-if="type === 'C'">
  C
</div>
<div v-else>
  Not A/B/C
</div>

// template usado como encapsulador invisível
-> "v-if" com "template" para grupos condicionais
<template v-if="ok">
  <h1>Title</h1>
  <p>Paragraph 1</p>
  <p>Paragraph 2</p>
</template>

// reusar elementos com key
// não recria input, mas mantem valor
<template v-if="loginType === 'username'">
  <label>Username</label>
  <input placeholder="Enter your username">
</template>
<template v-else>
  <label>Email</label>
  <input placeholder="Enter your email address">
</template>

// se forem diferentes e não se quiser reusar
// usa-se key
<template v-if="loginType === 'username'">
  <label>Username</label>
  <input placeholder="Enter your username" key="username-input">
</template>
<template v-else>
  <label>Email</label>
  <input placeholder="Enter your email address" key="email-input">
</template>

// condicionalmente mostrar um elemento
// sempre renderiza e mantem na DOM
// simplesmente alterna no display propriedades CSS
-> "v-show"
<h1 v-show="ok">Hello!</h1>

-> "v-if vs v-show"
v-if é real renderização condicional
     bom quando não muda muito
v-show é mais simples, elemento é renderizado indiferente da condição inicial
	   simplesmente alternando o CSS
	   bom quando muda muito

https://vuejs.org/v2/guide/list.html
## LIST RENDERING

// can iterate over arrays, objects
// usar com :key="item.id"
-> "v-for"
<li v-for="(item, index) in/of items" :key="item.id">
    {{ parentMessage }} - {{ index }} - {{ item.message }}
</li>

data: {
	parentMessage: 'Parent',
    items: [
      { message: 'Foo' },
      { message: 'Bar' }
    ]
}

<ul>
  <template v-for="item in items" :key="item.id">
    <li>{{ item.msg }}</li>
    <li class="divider"></li>
  </template>
</ul>

data: {
    object: {
      firstName: 'John',
      lastName: 'Doe',
      age: 30
    }
}

<div v-for="(value, key, index) in object" :key="key.id">
  {{ index }}. {{ key }} : {{ value }}
</div>

<div>
  <span v-for="n in 10">{{ n }} </span>
</div>

// itera nos elementos com condicional
-> "v-for com v-if"
<li v-for="todo in todos" v-if="!todo.isComplete" :key="todo.id">
  {{ todo }}
</li>

// permite a vue ordenar lista de elementos
// vindas do javascript assincrono
// usar sempre com v-for
":key="item.id""

Mutadores no array
- push()
- pop()
- shift()
- unshift()
- splice()
- sort()
- reverse()

Não-mutadores (sempre retornam um array novo)
- filter()
- concat()
- slice()

Prob1 - Alterar valor de array ou tamanho não é detectado pelo Vue
vm.items[indexOfItem] = newValue
vm.items.length = newLength

Sol- necessário usar Vue.set(example1.items, indexOfItem, newValue)


## TIPS

- computed vs methods
Computed é como um método, mas coloca atributos em cache
Usado como getter de atributos
Só é chamado quando o atributo muda
Usado para remover complexidade de operações in-template

