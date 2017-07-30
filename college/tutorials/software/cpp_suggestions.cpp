'When use structs or classes?'
I would recommend using structs as plain-old-data structures without any class-like features, and using classes as 
aggregate data structures with private data and member functions.
'Destructor'
Escreva que o objeto foi finalizado no destrutor.
'C++ Inheritance'
Define a class in terms of another class.
When creating a class, instead of writing completely new data members and member functions, the programmer can 
designate that the new class should inherit the members of an existing class.
The idea of inheritance implements the 'is a' relationship.
For example, 'mammal IS-A animal', 'dog IS-A mammal' hence 'dog IS-A animal' as well and so on.

'C++ friend functions'
A friend function of a class is defined outside that class scope but it has the right to access all private and 
protected members of the class. Even though the prototypes for friend functions appear in the class definition, 
friends are not member functions.
    class Box{
      double width;
    public:
      double length;
      friend void printWidth( Box box );
      void setWidth( double wid );
    };
To declare all member functions of class ClassTwo as friends of class ClassOne, place a following declaration in 
the definition of class ClassOne:
    friend class ClassTwo;
'C++ inline functions'
With an inline function, the compiler tries to expand the code in the body of the function in place of a call to
the function.
'Static members of a class'
Both data members and function members of a class can be declared as static.
No matter how many objects of the class are created, there is only one copy of the static member.
'C++ virtual functions'
When the derived class has a same function as its base class, the base class function should be virtual.
'Interfaces in C++ (Abstract Classes)'
A class is made abstract by declaring at least one of its functions as pure virtual function. A pure 
virtual function is specified by placing "= 0" in its declaration.
The purpose of an abstract class (often referred to as an ABC) is to provide an appropriate base class 
from which other classes can inherit. Abstract classes cannot be used to instantiate objects and serves
only as an interface. Attempting to instantiate an object of an abstract class causes a compilation error.
    class Box{
      public:   
    // pure virtual function
    virtual double getVolume() = 0;
      private:
    double length;      // Length of a box
    double breadth;     // Breadth of a box
    double height;      // Height of a box
      };

Given a class C and a function f related to C, I developed the following algorithm:
    if (f needs to be virtual)
    {
      make f a member function of C;
    }
    else if (f is operator>> or operator<<)
    {
      make f a non-member function;
      if (f needs access to non-public members of C)
      {
    make f a friend of C;
      }
    }
    else if (f needs type conversion on its left-most argument)
    {
      make f a non-member function;
      if (f needs access to non-public members of C)
      {
     make f a friend of C;
      }
    }
    else if (f can be implemented via Cs public interface)
    {
      make f a non-member function;
    }
    else
    {
      make f a member function of C;
    }
    
'Encapsulation'
Encapsulation is a means, not an end.
In particular, it yields flexibility and robustness.
The weakness of this struct is that its not flexible in the face of change.
'not encapsulated'
    struct Point {
        int x, y;
    };
'encapsulated'
    class Point {
        public:
            int getXValue() const; 
            int getYValue() const; 
            void setXValue(int newXValue);
            void setYValue(int newYValue);
 
        private:
        ...// whatever...
    };







    


