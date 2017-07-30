
##Transition Classes

v-enter: Starting state for enter. Added before element is inserted, removed one frame after element is inserted.
v-enter-active: Active state for enter. Applied during the entire entering phase. Added before element is inserted, removed when transition/animation finishes. This class can be used to define the duration, delay and easing curve for the entering transition.
v-enter-to: Only available in versions 2.1.8+. Ending state for enter. Added one frame after element is inserted (at the same time v-enter is removed), removed when transition/animation finishes.
v-leave: Starting state for leave. Added immediately when a leaving transition is triggered, removed after one frame.
v-leave-active: Active state for leave. Applied during the entire leaving phase. Added immediately when leave transition is triggered, removed when the transition/animation finishes. This class can be used to define the duration, delay and easing curve for the leaving transition.
v-leave-to: Only available in versions 2.1.8+. Ending state for leave. Added one frame after a leaving transition is triggered (at the same time v-leave is removed), removed when the transition/animation finishes.

##Custom directives

In addition to v-model and v-show
cases where you just need some low-level DOM access on plain elements

// Register a global custom directive called v-focus
Vue.directive('focus', {
  // When the bound element is inserted into the DOM...
  inserted: function (el) {
    // Focus the element
    el.focus()
  }
})

##Hook Functions
bind: called only once, when the directive is first bound to the element. This is where you can do one-time setup work
inserted: called when the bound element has been inserted into its parent node (this only guarantees parent node presence, not necessarily in-document).
update: called after the containing component’s VNode has updated, but possibly before its children have updated. The directive’s value may or may not have changed, but you can skip unnecessary updates by comparing the binding’s current and old values (see below on hook arguments).
componentUpdated: called after the containing component’s VNode and the VNodes of its children have updated.
unbind: called only once, when the directive is unbound from the element.

Directive Hook Arguments

el: The element the directive is bound to. This can be used to directly manipulate the DOM.
binding: An object containing the following properties.
	name: The name of the directive, without the v- prefix.
	value: The value passed to the directive. For example in v-my-directive="1 + 1", the value would be 2.
	oldValue: The previous value, only available in update and componentUpdated. It is available whether or not the value has changed.
	expression: The expression of the binding as a string. For example in v-my-directive="1 + 1", the expression would be "1 + 1".
	arg: The argument passed to the directive, if any. For example in v-my-directive:foo, the arg would be "foo".
	modifiers: An object containing modifiers, if any. For example in v-my-directive.foo.bar, the modifiers object would be { foo: true, bar: true }.
	vnode: The virtual node produced by Vue’s compiler. See the VNode API for full details.
	oldVnode: The previous virtual node, only available in the update and componentUpdated hooks.


example
<div id="hook-arguments-example" v-demo:foo.a.b="message"></div>


##Plugins

Plugins usually add global-level functionality to Vue. There is no strictly defined scope for a plugin - there are typically several types of plugins you can write:
Add some global methods or properties. e.g. vue-custom-element
Add one or more global assets: directives/filters/transitions etc. e.g. vue-touch
Add some component options by global mixin. e.g. vuex
Add some Vue instance methods by attaching them to Vue.prototype.
A library that provides an API of its own, while at the same time injecting some combination of the above. e.g. vue-router

Using a Plugin

Vue.use(MyPlugin)

##Production Deployment Tips

Without Build Tools
make sure to use the minified version (vue.min.js) for production


##Unit Testing

// Import Vue and the component being tested
import Vue from 'vue'
import MyComponent from 'path/to/MyComponent.vue'
// Here are some Jasmine 2.0 tests, though you can
// use any test runner / assertion library combo you prefer
describe('MyComponent', () => {
  // Inspect the raw component options
  it('has a created hook', () => {
    expect(typeof MyComponent.created).toBe('function')
  })
  // Evaluate the results of functions in
  // the raw component options
  it('sets the correct default data', () => {
    expect(typeof MyComponent.data).toBe('function')
    const defaultData = MyComponent.data()
    expect(defaultData.message).toBe('hello!')
  })
  // Inspect the component instance on mount
  it('correctly sets the message when created', () => {
    const vm = new Vue(MyComponent).$mount()
    expect(vm.message).toBe('bye!')
  })
  // Mount an instance and inspect the render output
  it('renders the correct message', () => {
    const Ctor = Vue.extend(MyComponent)
    const vm = new Ctor().$mount()
    expect(vm.$el.textContent).toBe('bye!')
  })
})

