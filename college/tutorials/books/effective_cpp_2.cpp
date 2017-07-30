A virtual function or virtual method is a function or method whose behavior can be overridden 
within an inheriting class by a function with the same signature whereas..

A pure virtual function or pure virtual method is a virtual function that is required to be 
implemented by a derived class that is not abstract" - Wikipedia 

So, the virtual function can be overriden and the pure virtual must be implemented.

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
Shifting from C to C++
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

#Item 1: Prefer const and inline to #define .
-> #define ASPECT_RATIO 1.653(x)
-> const double ASPECT_RATIO = 1.653;(k)
To define a constant char* -based string in a header file, for example, you have to write const twice:
-> const char * const authorName = "Scott Meyers"; (k)
'For a discussion of the meanings and uses of const , especially in conjunction with pointers, see Item 21.'

(k)
class GamePlayer {
private:
  static const int NUM_TURNS = 5;
  int scores[NUM_TURNS];
  ...
};

You must still define static class members in an implementation file:
-> const int GamePlayer::NUM_TURNS; (k)		// mandatory definition;
						// goes in class impl. file
(k)
class GamePlayer {
private:
  enum { NUM_TURNS = 5 };	// "the enum hack" — makes
				// NUM_TURNS a symbolic name
				// for 5
  int scores[NUM_TURNS];	// fine
...
};

-> #define max(a,b) ((a) > (b) ? (a) : (b)) (x)
-> inline int max(int a, int b) { return a > b ? a : b; } (k)
-> template<class T> (k)
   inline const T& max(const T& a, const T& b) (k)
   { return a > b ? a : b; }
   
Given the availability of const s and inline s, your need for the preprocessor is reduced, but it's not
completely eliminated. The day is far from near when you can abandon #include , and
#ifdef / #ifndef continue to play important roles in controlling compilation. It's not yet time to retire
the preprocessor, but you should definitely plan to start giving it longer and more frequent vacations.

#Item 2: Prefer <iostream> to <stdio.h> .
int i;
Rational r;	// r is a rational number
cin >> i >> r;
cout << i << r;

(k)
class Rational {
public:
  Rational(int numerator = 0, int denominator = 1);
private:
  int n, d;	// numerator and denominator
  friend ostream& operator<<(ostream& s, const Rational& r);
};

ostream& operator<<(ostream& s, const Rational& r){
  s << r.n << '/' << r.d;
  return s;
}

The type safety and extensibility offered by the classes and functions in the iostream library are more
useful than you might initially imagine, so don't throw them away just because you're used to
<stdio.h> . After all, even after the transition, you'll still have your memories.

If you #include <iostream.h> , you get those same elements at global scope. Getting them at global scope can lead to
name conflicts, precisely the kinds of name conflicts the use of namespaces is designed to prevent.
Besides, <iostream> is less to type than <iostream.h> . For many people, that's reason enough to
prefer it.

#Item 3: Prefer new and delete to malloc and free .
The problem with malloc and free (and their variants) is simple: they don't know about constructors
and destructors.

-> string *stringArray1 = static_cast<string*>(malloc(10 * sizeof(string))); (x)
-> string *stringArray2 = new string[10]; (k)

-> free(stringArray1); (x)
-> delete [] stringArray2; (k)	// see Item 5 for why the
				// "[]" is necessary
Given that malloc and free are ignorant of constructors and destructors and that mixing
malloc / free with new / delete can be more volatile than a fraternity rush party, you're best off
sticking to an exclusive diet of new s and delete s whenever you can.

Never use strup function!

#Item 4: Prefer C++-style comments.
Use // against /**/
C++ dont have multi-line comments!!!

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
Memory Management (treats memory leaks)
Getting it right and 
making it perform efficiently
For most programmers, getting things right means calling memory allocation and deallocation routines correctly.
In C, a memory leak arises whenever memory allocated through malloc is never returned through free.
new implicitly calls constructors and delete implicitly calls destructors.
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

#Item 5: Use the same form in corresponding uses of new and delete.
(x)
string *stringArray = new string[100];
...
delete stringArray; //just delete the firt member of array! Need brackets!

Their destructors will probably never be called. 	
With new , two things happen: memory is allocated (Items 7-10 as well as Item M8) and one or more constructors are called for that memory.
With delete , two things happen: one or more destructors are called for the memory, memory is deallocated (Items 8 and M8).

(k)
string *stringPtr1 = new string;
string *stringPtr2 = new string[100];
...
delete stringPtr1; // delete an object
delete [] stringPtr2; // delete an array of
		      // objects
if you use [] when you call new , you must use [] when you call delete .
If you don't use [] when you call new , don't use [] when you call delete .

#Item 6: Use delete on pointer members in destructors.
Classes performing dynamic memory allocation will use new in the constructor(s) to allocate the memory and will later 
use delete in the destructor to free up the memory.

Adding a pointer member requires:
-> Initialization of the pointer in each of the constructors. If no memory is to be allocated to the
pointer in a particular constructor, the pointer should be initialized to 0 (i.e., the null pointer).
-> Deletion of the existing memory and assignment of new memory in the assignment operator.
-> Deletion of the pointer in the destructor.

One way to avoid the need to delete pointer members is to replace those
members with smart pointer objects like the standard C++ Librarys 'auto_ptr'.Take a look at Items M9 and M10.

#Item 7: Be prepared for out-of-memory conditions.
When operator new can't allocate the memory you request, it throws an exception.
You know that handling out-of-memory exceptions is a pain in the neck.

(x)
#define NEW(PTR, TYPE)			\
try { (PTR) = new TYPE; }		\
catch (std::bad_alloc&) { assert(0); }

bad_alloc is the type of exception operator new throws when it cant satisfy a memory allocation request, 
and std is the name of the namespace (see Item 28) where bad_alloc is defined.

<cassert> — see Item 49), youll find that assert is a macro.

You thus check 'assert'ions only when debugging).

(k)
// function to call if operator new can't allocate enough memory
void noMoreMemory(){
  cerr << "Unable to satisfy request for memory\n";
  abort();
}

int main(){
  set_new_handler(noMoreMemory);
  int *pBigDataArray = new int[100000000];
  ...
}

// If, as seems likely, operator new is unable to allocate space for 100,000,000 integers,
// noMoreMemory will be called, and the program will abort after issuing an error message.

#Item 8: Adhere to convention when writing operator new and operator delete .
How to create own operator new and delete.

#Item 9: Avoid hiding the "normal" form of new .
A declaration of a name in an inner scope hides the same name in outer scopes, so for a function f at
both global and class scope.

#Item 10: Write operator delete if you write operator new .
More often than not, the answer is efficiency.

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
Constructors, Destructors, and Assignment Operators
Almost every class you write will have one or more constructors, a destructor, and an assignment
operator.
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

#Item 11: Declare a copy constructor and an assignment operator for classes with dynamically allocated memory.
(x)
// a poorly designed String class
class String {
public:
  String(const char *value);
  ~String();
  ...
  // no copy ctor or operator=
private:
  char *data;
};

String::String(const char *value){
  if (value) {
    data = new char[strlen(value) + 1];
    strcpy(data, value);
  }
  else {
    data = new char[1];
    *data = '\0';
  }
}

inline String::~String() { delete [] data; }

#Item 12: Prefer initialization to assignment in constructors.
When you write the NamedPtr constructor, you have to transfer the values of the parameters to the corresponding 
data members. There are two ways to do this. The first is to use the member initialization list:

template<class T>
NamedPtr<T>::NamedPtr(const string& initName, T *initPtr
: name(initName), ptr(initPtr)
{}

The second is to make assignments in the constructor body:

template<class T>
NamedPtr<T>::NamedPtr(const string& initName, T *initPtr)
{
  name = initName;
  ptr = initPtr;
}

There are important differences between these two approaches.From a purely pragmatic point of view, there are times 
when the initialization list must be used. In particular, const and reference members may only be initialized, never
assigned. const members may only be initialized, never assigned.

When a member initialization list is used, only a single string member function is called. 
When assignment inside the constructor is used, two are called.

However, you can take advantage of the fact that there is no operational difference between
initialization and assignment for (non- const , non-reference) objects of built-in types, so you can
safely replace the memberwise initialization lists with a function call to a common initialization
routine.

Note that static class members should never be initialized in a class's constructor. Static members
are initialized only once per program run, so it makes no sense to try to "initialize" them each time an
object of the class's type is created.

#Item 13: List members in an initialization list in the order in which they are declared.
The bottom line is this: if you hope to understand what is really going on when your objects are
initialized, be sure to list the members in an initialization list in the order in which those members are
declared in the class.

#Item 14: Make sure base classes have virtual destructors.
Sometimes it's convenient for a class to keep track of how many objects of its type exist. The
straightforward way to do this is to create a static class member for counting the objects.

The member is initialized to 0, is incremented in the class constructors, and is decremented in the class destructor.

//---
class EnemyTarget {
public:
  EnemyTarget() { ++numTargets; }
  EnemyTarget(const EnemyTarget&) { ++numTargets; }
  ~EnemyTarget() { --numTargets; }
  static size_t numberOfTargets(){ return numTargets; }
  virtual bool destroy();	// returns success of
				// attempt to destroy
				// EnemyTarget object
private:
  static size_t numTargets;	// object counter
};

// class statics must be defined outside the class;
// initialization is to 0 by default
size_t EnemyTarget::numTargets;
//---
class EnemyTank: public EnemyTarget {
public:
  EnemyTank() { ++numTanks; }
  EnemyTank(const EnemyTank& rhs) : EnemyTarget(rhs) { ++numTanks; }~EnemyTank() { --numTanks; }
  static size_t numberOfTanks(){ return numTanks; }
  virtual bool destroy();
private:
  static size_t numTanks;	// object counter for tanks
};

The C++ language standard is unusually clear on this topic. When you try to delete a derived class
object through a base class pointer and the base class has a nonvirtual destructor (as EnemyTarget
does), the results are undefined.

To avoid this problem, you have only to make the EnemyTarget destructor virtual. Declaring the
destructor virtual ensures well-defined behavior that does precisely what you want: both
EnemyTank 's and EnemyTarget 's destructors will be called before the memory holding the object is
deallocated.

If a class does not contain any virtual functions, that is often an indication that it is not meant to be
used as a base class.

When a class is not intended to be used as a base class, making the destructorvirtual is usually a bad idea.

#Item 15: Have operator= return a reference to *this .






















