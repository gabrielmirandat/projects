// http://groovy-lang.org/documentation.html#gettingstarted

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