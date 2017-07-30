collection of 55 specific suggestions (I call them Items) for how you can improve your programs and designs.

intro
How do you choose between inheritance and templates?
Between public and private inheritance?
Between private inheritance and composition?
Between member and non-member functions?
Between pass-by-value and pass-by-reference?
What’s the proper return type for assignment operators?
When should a destructor be virtual?
How should operator new behave when it can’t find enough memory?

template<typename T>        // template declaration

1) vector , deque , and string operators [] returns a std::sizet

template<typename T>
class GraphNode {
public:
    GraphNode();
    ~GraphNode()

2) The constructors for classes B and C are declared explicit here. That
prevents them from being used to perform implicit type conversions,
though they may still be used for explicit type conversions:
Constructors declared explicit are usually preferable to non- explicit
ones, because they prevent compilers from performing unexpected
(often unintended) type conversions. Unless I have a good reason for
allowing a constructor to be used for implicit type conversions, I
declare it explicit . I encourage you to follow the same policy.

class B {
public:
    explicit B(int x = 0, bool b = true);
};

3) The copy constructor is used to initialize an object with a different
object of the same type, and the copy assignment operator is used
to copy the value from one object to another of the same type:

class Widget {
public:
    Widget();                               // default constructor
    Widget(const Widget& rhs);              // copy constructor
    Widget& operator=(const Widget& rhs);   // copy assignment operator
    ...
};
Widget w1;                                  // invoke default constructor
Widget w2(w1);                              // invoke copy constructor    
w1 = w2;                                    // invoke copy
                                            // assignment operator
Widget w3 = w2;                             // invoke copy constructor!

4) The copying is done by Widget ’s
copy constructor. Pass-by-value means “call the copy constructor.”
(However, it’s generally a bad idea to pass user-defined types by value.
Pass-by-reference-to- const is typically a better choice. For details, see
Item 20.)

5) The STL is the Standard Template Library, the part of C++’s standard
library devoted to containers (e.g., vector , list , set , map , etc.), iterators
(e.g., vector<int>::iterator , set<string>::iterator , etc.), algorithms (e.g.,
for_each , find , sort , etc.), and related functionality. Much of that related
functionality has to do with function objects: objects that act like
functions. Such objects come from classes that overload operator() , the
function call operator.

6) It’s true: a program with undefined behavior could erase your
hard drive. But it’s not probable.

lhs and rhs . They stand for “left-hand side” and “righthand side,” respectively.
        operator*(a, b)
In Item 24, I declare operator* like this:
        const Rational operator*(const Rational& lhs, const Rational& rhs);
As you can see, the left-hand operand, a , is known as lhs inside the
function, and the right-hand operand, b , is known as rhs .

class Airplane;
Airplane *pa;       // pa = ptr to Airplane

I can’t ignore the fact that thread safety is an issue many programmers confront.

(Item 54 for TR1, Item 55 for Boost)

7) Destructors that emit exceptions are dangerous.
✦ 'Destructors should never emit exceptions'. If functions called in a
destructor may throw, the destructor should catch any exceptions,
then swallow them or terminate the program.
✦ If class clients need to be able to react to exceptions thrown during
an operation, the class should provide a regular (i.e., non-destruc-
tor) function that performs the operation.

Item 9) 'Never call virtual functions during construction or destruction'.
Item 10: 'Have assignment operators return a reference to *this'.



