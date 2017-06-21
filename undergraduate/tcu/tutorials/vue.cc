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

# text interpollation
#
<div id="app">  {{ message }}  </div>
data: { message: 'Hello Vue!' }

#  bind element attributes
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

# Conditionals
#
<div id="app-3">
  <p v-if="seen">Now you see me</p>
</div>

data: {
    seen: true
}

# Loops
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

# Handling User Input
# 
<div id="app-5">
  <button v-on:click="reverseMessage">Reverse Message</button>
</div>

methods: {
    reverseMessage: function () {
      this.message = this.message.split('').reverse().join('')
}

# v-model directive that makes two-way binding between form input and app state
# 
<div id="app-6">
  <p>{{ message }}</p>
  <input v-model="message">
</div>

data: {
    message: 'Hello Vue!'
}

# Composing with Components
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

-> data binding com interpolação de texto
	<span> Message: {{ msg }} </span>

-> data binding com interpolação dentro da tag HTLM só com valor
tem falha de segurança
	<div v-html="rawHtml"></div>

-> data binding com interpolação dentro da tag HTLM com chave:valor
	<div v-bind:id="dynamicId"></div>
	<button v-bind:disabled="someDynamicCondition">Button</button>

-> binding por javascript é permitido
	{{ number + 1 }}
	{{ ok ? 'YES' : 'NO' }}
	{{ message.split('').reverse().join('') }}
	<div v-bind:id="'list-' + id"></div>

-> escuta por eventos
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


