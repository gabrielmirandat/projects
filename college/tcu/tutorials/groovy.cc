http://groovy-lang.org/documentation.html#gettingstarted

// shell interativo
groovysh

Differences Groovy and Java

1. Multi-methods
// int method(String arg) {
//     return 1;
// }
// int method(Object arg) {
//     return 2;
// }
// Object o = "Object";
// int result = method(o);

Java
// assertEquals(2, result);

Groovy
// assertEquals(1, result);

#That is because Java will use the static information type, which is that o is declared as an Object, 
whereas Groovy will choose at runtime, when the method is actually called. Since it is called with a 
String, then the String version is called.

3. Array initializers
// int[] array = [1,2,3]


4. Package scope visibility
// class Person {
//     String name
// }

#Create a property, that is to say a private field, an associated getter and an associated setter.

// class Person {
//     @PackageScope String name
// }

#Create a package-private field

5. ARM blocks
// new File('/path/to/file').eachLine('UTF-8') {
//    println it
// }
ou
// new File('/path/to/file').withReader('UTF-8') { reader ->
//    reader.eachLine {
//        println it
//    }
// }

6. Inner classes
6.1. Static inner classes
// class A {
//     static class B {}
// }
// new A.B()
6.2. Anonymous Inner Classes
// Timer timer = new Timer()
// timer.schedule(new TimerTask() {
//     void run() {
//         called.countDown()
//     }
// }, 0)
6.3. Creating Instances of Non-Static Inner Classes
// public class Y {
//     public class X {}
//     public X foo() {
//         return new X()
//     }
//     public static X createX(Y y) {
//         return new X(y)
//     }
// }
// Groovy doesn’t support the y.new X() syntax. Instead, you have to write new X(y)

7. Lambdas
// Runnable run = { println 'run' }
// list.each { println it } // or list.each(this.&println)

8. GStrings
Com "", é GString, diferente de '' String

9. String and Character literals
// assert 'c'.getClass()==String
// assert "c${1}".getClass() in GString
// assert ((char) "c").class==Character
// assert ("c" as char).class==Character

10. Primitives and wrappers
// Because Groovy uses Objects for everything, it autowraps references to primitives.
// int i
// m(i)
// void m(Integer i) {        
//   println "in m(Integer)"
// }

11. Behaviour of ==
// In Groovy == translates to a.compareTo(b)==0, 
// if they are Comparable, and a.equals(b) otherwise. 
// To check for identity, there is is. E.g. a.is(b).


https://learnxinyminutes.com/docs/groovy/

$ groovyConsole

//Creating an empty list
def technologies = []

/*** Adding a elements to the list ***/
technologies.add("Um")
technologies << "Dois"
technologies.addAll(["Tres","Quatro"])

/*** Removing elements from the list ***/
technologies.remove("Quatro")
technologies = technologies - 'Tres'

// Iterate over elements of a list
println technologies
technologies.each { println "Technology: $it"}
technologies.eachWithIndex { it, i -> println "$i: $it"}

println ""

/*** Checking List contents ***/
contained = technologies.contains( 'Tres' )
println contained
contained = 'Dois' in technologies
println contained
println technologies.containsAll(['Um','Tres'])

// Sort a list (mutates original list)
println technologies.sort()

// To sort without mutating original, you can do:
sortedTechnologies = technologies.sort( false ) 
println sortedTechnologies

// Clear a list
technologies.clear()

// Creating an empty map
def devMap = [:]

// Add values
devMap = ['name':'Roberto', 'framework':'Grails', 'language':'Groovy']
devMap.put('lastName','Perez')

// Evaluate if a map contains a key
assert devMap.containsKey('name')

// Evaluate if a map contains a value
assert devMap.containsValue('Roberto')

// Get the keys of a map
println devMap.keySet()

// Get the values of a map
println devMap.values()

// For loop
// Iterate over a range
def x = 0
for (i in 0 .. 30) {
    x += i
}

// Iterate over a list
x = 0
for( i in [5,3,2,1] ) {
    x += i
}

// Iterate over an array
array = (0..20).toArray()
x = 0
for (i in array) {
    x += i
}

// Iterate over a map
def map = ['name':'Roberto', 'framework':'Grails', 'language':'Groovy']
x = 0
for ( e in map ) {
    x += e.value
}

/*
  Operators

  Operator Overloading for a list of the common operators that Groovy supports:
  http://www.groovy-lang.org/operators.html#Operator-Overloading

  Helpful groovy operators
*/
// Spread operator:  invoke an action on all items of an aggregate object.
def technologies = ['Groovy','Grails','Gradle']
technologies*.toUpperCase() // = to technologies.collect { it?.toUpperCase() }

// Safe navigation operator: used to avoid a NullPointerException.
def user = User.get(1)
def username = user?.username

/*
  Closures
  A Groovy Closure is like a "code block" or a method pointer. It is a piece of
  code that is defined and then executed at a later point.

  More info at: http://www.groovy-lang.org/closures.html
*/

//Example:
def clos = { println "Hello World!" }

println "Executing the Closure:"
clos()

//Passing parameters to a closure
def sum = { a, b -> println a+b }
sum(2,4)

//Closures may refer to variables not listed in their parameter list.
def x = 5
def multiplyBy = { num -> num * x }
println multiplyBy(10)

// If you have a Closure that takes a single argument, you may omit the
// parameter definition of the Closure
def clos = { print it }
clos( "hi" )

/*
  Groovy can memoize closure results [1][2][3]
*/
def cl = {a, b ->
    sleep(3000) // simulate some time consuming processing
    a + b
}

mem = cl.memoize()

/*
  Expando

  The Expando class is a dynamic bean so we can add properties and we can add
  closures as methods to an instance of this class

  http://mrhaki.blogspot.mx/2009/10/groovy-goodness-expando-as-dynamic-bean.html
*/
def user = new Expando(name:"Roberto")
  assert 'Roberto' == user.name

  user.lastName = 'Pérez'
  assert 'Pérez' == user.lastName

  user.showInfo = { out ->
      out << "Name: $name"
      out << ", Last name: $lastName"
  }

  def sw = new StringWriter()
  println user.showInfo(sw)
  
/*
  Metaprogramming (MOP)
*/

//Using ExpandoMetaClass to add behaviour
String.metaClass.testAdd = {
    println "we added this"
}

String x = "test"
x?.testAdd()

// Intercepting method calls
class Test implements GroovyInterceptable {
    def sum(Integer x, Integer y) { x + y }

    def invokeMethod(String name, args) {
        System.out.println "Invoke method $name with args: $args"
    }
}

def test = new Test()
test?.sum(2,3)
test?.multiply(2,3)

//Groovy supports propertyMissing for dealing with property resolution attempts.
class Foo {
   def propertyMissing(String name) { name }
}
def f = new Foo()

assertEquals "boo", f.boo

/*
  TypeChecked and CompileStatic
  Groovy, by nature, is and will always be a dynamic language but it supports
  typechecked and compilestatic

  More info: http://www.infoq.com/articles/new-groovy-20
*/
// TypeChecked
import groovy.transform.TypeChecked

void testMethod() {}

@TypeChecked
void test() {
    testMeethod()

    def name = "Roberto"

    println naameee

}

// CompileStatic example:
import groovy.transform.CompileStatic

@CompileStatic
int sum(int x, int y) {
    x + y
}

assert sum(2,5) == 7