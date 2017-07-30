https://docs.oracle.com/javase/specs/jvms/se6/html/Overview.doc.html#6656
https://docs.oracle.com/javase/specs/jvms/se7/html/jvms-2.html#jvms-2.11
https://docs.oracle.com/javase/specs/jvms/se7/html/jvms-4.html
https://docs.oracle.com/javase/specs/jvms/se7/html/jvms-6.html
https://docs.oracle.com/javase/specs/jvms/se7/html/jvms-7.html
https://docs.oracle.com/javase/specs/jvms/se7/html/jvms-7.html

https://docs.oracle.com/javase/specs/jvms/se6/html/Overview.doc.html#6656
For example, the memory layout of run-time data areas, 
			 the garbage-collection algorithm used, and 
			 any internal optimization of the Java virtual machine instructions (for example, translating them into machine code) 
are left to the discretion of the implementor. 

3.1 The class File Format
	- Compiled code to be executed by the Java virtual machine
	- Chapter 4, "The class File Format", covers the class file format in detail.

3.2 Data Types
	- two kinds of types: primitive types and reference types.
	- two kinds of values that can be stored in variables:  primitive values and reference values.
	- For instance, 'iadd, ladd, fadd, and dadd' are all Java virtual machine instructions that add two numeric values
	  but each is specialized for its operand type: int, long, float, and double, respectively.
	- For a summary of type support in the Java virtual machine instruction set, see §3.11.1.

	- The Java virtual machine contains explicit support for objects. 
	  An object is either a dynamically allocated class instance or an array.
	  A reference to an object is considered to have Java virtual machine type reference.
	  Values of type reference can be thought of as pointers to objects.
	  More than one reference to an object may exist.
	  Objects are always operated on, passed, and tested via values of type reference.

3.3 Primitive Types and Values
	- numeric types, the boolean type (§3.3.4),1 and the returnAddress type (§3.3.3).
	- The numeric types consist of the integral types (§3.3.1) and the floating-point types (§3.3.2).
	- The values of the boolean type encode the truth values true and false.
	- The values of the returnAddress type are pointers to the opcodes of Java virtual machine instructions.
	- Of the primitive types only the returnAddress type is not directly associated with a Java programming language type.
	- The floating-point types are float and double
	- The IEEE 754 standard includes not only positive and negative sign-magnitude numbers, but also 
	  positive and negative zeros, positive and negative infinities, and a special Not-a-Number value
	- The NaN value is used to represent the result of certain invalid operations such as dividing zero by zero.
	- The finite nonzero values of any floating-point value set can all be expressed in the form s · m· 2(e -N + 1)
	- If a value in a value set cannot be represented in such a way that m 2N -1, then the value is said to be a 
	  denormalized value, because it has no normalized representation.


The Architecture of the Java Virtual Machine
- the behavior of a virtual machine instance is described in terms of subsystems, memory areas, data types, and instructions
- each Java virtual machine has a class loader subsystem: a mechanism for loading types (classes and interfaces) given fully qualified names. 
  Each Java virtual machine also has an execution engine: a mechanism responsible for executing the instructions contained in the methods of loaded classes. 
- it needs memory to store many things, including bytecodes and other information it extracts from loaded class files, objects the program instantiates, 
  parameters to methods, return values, local variables, and intermediate results of computations.  

- Each instance of the Java virtual machine has one method area and one heap.
- These areas are shared by all threads running inside the virtual machine
- When the virtual machine loads a class file, it parses information about a type from the binary data contained in the class file. 
- It places this type information into the method area.
- As the program runs, the virtual machine places all objects the program instantiates onto the heap.

- As each new thread comes into existence, it gets its own pc register (program counter) and Java stack.

- A threads Java stack stores the state of Java (not native) method invocations for the thread.
- The state of a Java method invocation includes its local variables, the parameters with which it was invoked, 
  its return value (if any), and intermediate calculations.
- The Java stack is composed of stack frames (or frames).
- A stack frame contains the state of one Java method invocation. 
- When a thread invokes a method, the Java virtual machine pushes a new frame onto that threads Java stack. When the method completes, 
  the virtual machine pops and discards the frame for that method. 
- The Java virtual machine has no registers to hold intermediate data values. The instruction set uses the Java stack for storage of intermediate data values.

Data Types
- The data types can be divided into a set of primitive types and a reference type. 
- Variables of the primitive types hold primitive values, and variables of the reference type hold reference values. 
- Reference values refer to objects, but are not objects themselves.
- Primitive values, by contrast, do not refer to anything. They are the actual data themselves.
- Arrays of boolean are accessed as arrays of byte, though they may be represented on the heap as arrays of byte or as bit fields. 
- As with the Java programming language, the primitive types of the Java virtual machine have the same range everywhere. 
- A long in the Java virtual machine always acts like a 64-bit signed twos complement number, independent of the underlying host platform. 
- the returnAddress type. This primitive type is used to implement finally clauses of Java programs. 
- The use of the returnAddress type is described in detail in Chapter 18, "Finally Clauses." 
- Values of type reference come in three flavors: the class type, the interface type, and the array type.
- All three types have values that are references to dynamically created objects.

Word Size
- The word size must be large enough to hold a value of type byte, short, int, char, float, returnAddress, or reference. 
- Two words must be large enough to hold a value of type long or double.
- For example, two sections of a Java stack frame--the local variables and operand stack-- are defined in terms of words.
- When placed into the local variables or operand stack, a value occupies either one or two words. 

The Class Loader Subsystem
- The part of a Java virtual machine implementation that takes care of finding and loading types is the class loader subsystem.
- the Java virtual machine contains two kinds of class loaders: a bootstrap class loader and user-defined class loaders.
- The bootstrap class loader is a part of the virtual machine implementation, and user-defined class loaders are part of the running Java application. 
- The class loader subsystem involves many other parts of the Java virtual machine and several classes from the java.lang library.
- For example, user-defined class loaders are regular Java objects whose class descends from java.lang.ClassLoader.
- Like all objects, user-defined class loaders and instances of class Class reside on the heap. 
- Data for loaded types resides in the method area. 

Loading, Linking and Initialization
- It must also verify the correctness of imported classes, allocate and initialize memory for class variables, 
  and assist in the resolution of symbolic references.

The Method Area
- Information about loaded types is stored in a logical area of memory called the method area. When the Java virtual machine loads a type, 
  it uses a class loader to locate the appropriate class file.
- The virtual machine extracts information about the type from the binary data and stores the information in the method area.
- All threads share the same method area, so access to the method areas data structures must be designed to be thread-safe.

The Heap
- Whenever a class instance or array is created in a running Java application, the memory for the new object is allocated from a single heap.

The Java Stack
- When a new thread is launched, the Java virtual machine creates a new Java stack for the thread.

The Stack Frame
- The stack frame has three parts: local variables, operand stack, and frame data.


1) Descreva a arquitetura da JVM do grupo, indicando os módulos, funções, estruturas de dados com os nomes 
   reais do fonte. Apresente um DCM para ilustrar a descrição apresentada.

2) Descreva o fluxo de execução de uma instrução cat 2 que retorna de um método e como o valor é passado para 
   o método chamador. Apresente as alterações necessárias nas manipulações dos funções e das estruturas de dados
   runtime. Utilize nomes reais do fonte.

3) Descreva o funcionamento de 10 instruções, (duas de cada tipo?)

4) Como são as instruções de double e de long?