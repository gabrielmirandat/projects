when to use inheritance?
The subclass IS-A superclass
When the subclass needs most of the methods in a superclass
Dont: just to reuse code, or if dont have a IS-A relationship
Avoid duplicate code
All subclasses have all of the superclass methods


when to put members?
When the subclass HAS-A member

polymorphism
vector<Superclass> super = {new Sub1, new Sub2};
for i from 0 to super.size(){
  super[i].overridedMethod;
}

abstract class
At least one method is virtual/abstract

interface 
All methods are virtual/abstract

Não posso usar coisas não static dentro de coisas static (estou chamando não static de qual objeto??)

tutorial 3


