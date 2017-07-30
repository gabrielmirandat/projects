https://cppcodetips.wordpress.com/2013/12/23/uml-class-diagram-explained-with-c-samples/

#Different visibility of the class can be represented as
“+” Public
“-” Private
“#” Protected

#Different Parameter direction
“in”       The parameter is an input parameter.
“Inout”    The parameter is capable of both input and output.
“Out”      The parameter is an output parameter.

#Different type of members in a class
1) Static members are represented as underlined.
2) Pure virtual functions are represented as italics.

#Class relationship
In a system a class may be related to different classes,following are the different relation ship.
- Association (knows a)
- Dependency (uses a)
- Aggregation (has a)
- Composition (has a)
- Inheritance (is a)
- Class template

-> Different Multiplicity in a relation
“0..1”            No instances, or one instance (optional, may)
“1”                  Exactly one instance
“0..* or *”    Zero or more instances
“1..*”              One or more instances (at least one)

-> Association (sabe de um)
One object is aware of another; it contains a pointer or reference to another object.

class X {
  X(Y *y) : y_ptr(y) {}
  void SetY(Y *y) { y_ptr = y;   }
  void f()        { y_ptr->Foo();}
  ----
  Y *y_ptr; // pointer
};

-> Dependency (utiliza um)
One class depends on another if the independent class is a parameter variable or local variable of 
a method of the dependent class

class X {
 ...
 void f1(Y y)  {…;  y.Foo();       }
 void f2(Y *y) {…;  y->Foo();      }
 void f3(Y &y) {…;  y.Foo();       }
 void f4()     {   Y y; y.Foo();  …}
 void f5()     {…; Y::StaticFoo(); }
 ...
};

-> Aggregation (tem um)
Aggregation can occur when a class is a collection or container of other classes, but where the 
contained classes do not have a strong life cycle dependency on the container—essentially, if the 
container is destroyed, its contents are not. It is like Association with containment.

class Window {
 public:
  //...
 private:
 vector<Shape*> itsShapes;
};

-> Composition (tem um)
Composition is the stronger form of aggregation. Composition can occur when a class is a collection 
or container of other classes, but where the contained classes have a strong life cycle dependency 
on the container—essentially, if the container is destroyed, its contents are also destroyed.

class Circle{
private:
     ...
    Point center;
....
};

-> Inheritance (eh um)
In Inheritance relationship a class is derived from another class. It is a “is a” relationship 
between two classes.

-> Class Template
Template class mean generic classes.Languages like C++, java, C# supports generic programming.

template <class T>
class X {
...
...
...
};
X Y
...
X<Y> a;
...

https://code.google.com/archive/p/doxygraph/
http://bouml.fr/features.html
http://doxygraph.sourceforge.net/doxyviz/doxygen.html
