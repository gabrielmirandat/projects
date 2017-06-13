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