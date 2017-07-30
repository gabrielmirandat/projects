1) Descreva a arquitetura da JVM do grupo, indicando os módulos, funções, estruturas de dados com os nomes 
   reais do fonte. Apresente um DCM para ilustrar a descrição apresentada.

2) Descreva o fluxo de execução de uma instrução cat 2 que retorna de um método e como o valor é passado para 
   o método chamador. Apresente as alterações necessárias nas manipulações dos funções e das estruturas de dados
   runtime. Utilize nomes reais do fonte.

3) Descreva o funcionamento de 10 instruções, (duas de cada tipo?)

4) Como são as instruções de double e de long?

5) Explique o funcionamento do interpretador implementado, indicando lógica, estruturas de dados, nomes de funções 
chamadas. Exemplifique considerando a execução de uma instrução qualquer.

5) Considere instruções das seguintes categorias: movimentação de dados, aritméticas, lógicas, invoke, conversão de tipo, 
manipulação de fields e objetos. Para essas categorias apresente 15 instruções (pelo menos uma de cada categoria) e 
descreva como funciona e qual a lógica utilizada para implementá-las no interpretador. Use nomes de estruturas de dados 
e funções reais.


 
1) Descreva a arquitetura da JVM do grupo, indicando os módulos, funções, estruturas de dados com os nomes 
   reais do fonte. Apresente um DCM para ilustrar a descrição apresentada.

Módulos::main, jvm, leitor_exibidor, opcodes, interpreter, checker

main -> funçao main do codigo
		so tem a fc main
		chama o jvm(startJVM)
		escolhe se e leitor_exibidor ou executar classe

jvm -> 	 iniciador da jvm, finalizador da jvm, 
		(des)carregar classe,
 		free objetos (frames, operandos e etc) 

		Iniciar_JVM (arquivo.class, numero argumentos, NULL ou t/a ou parametros)
			-Se for para ler/exibir-
			obtainClassFile(arquivoBinario)
			showClassFile(cf, arquivoSaidaJVM);
			
			-Se for para executar-
			loadClass(nomeDoArquivoDeClasse, CLASS_DATA ** ma, null, JVM * jvm)
				Exp: essa funcao carrega todo o arquivo na memoria (buffer) e vai 
					 lendo preenchendo os campos cafebabe minversion majorversion alem da 
					 constant pool.
			
			linkClass(dados_classe_principal, jvm);
				Exp: chama 2 funcoes que verificam se os campos iniciais foram 
				     preenchidos e estao corretos, classlinking verification verifica os 
				     headers dos arquivos e classlinkingpreparation carrega as variaveis de 
				     classe para memoria

			(Cria thread vazia)
			
			initializeClass(dados_classe_principal, jvm, main_thread);
				LOOP{
					loadClass
					linkClass
					initializeClass
				}
				executeMethod("<clinit>", "()V", cd, jvm, thread, NULL, 0, NULL)
				
				executeMethod(char * method_name, char * method_descriptor, CLASS_DATA * cd, 
					 		  JVM * jvm, THREAD * thread, void * this, uint16_t nargs, uint32_t * args)
			
					method_data = GetMethod - entra em um laço até encontrar ou não um method
				
					verifica se é abstract ( illegalacesserror)
				
					executeMethod nao trata string, se o method descriptor receber String e devolver Void ou ser main, ignora os argumentos 
			
					interpreter(method, thread, jvm);


leitor_exibidor -> leitor exibidor 
                    le o .class e extrai seus campos, tais como: magic, versions, 
                    constant_pool, access_flags, this_class e super_class, interfaces, fields, methods e attributes


opcode -> lista de opcodes das instruçoes


interpreter -> logica do interpretador com implementaçoes de instruçoes
// INTERPRETADOR
// 2.11. Instruction Set Summary 
// do {
//     atomically calculate pc and fetch opcode at pc;
//     if (operands) fetch operands;
//     execute the action for the opcode;
// } while (there is more to do);
void interpreter(METHOD_DATA* method, THREAD* thread, JVM* jvm)
{
	thread->program_counter = method->bytecodes;

	// enquanto houver instruções
	while(thread->program_counter < (method->bytecodes + method->code_length))
	{	
		func[*thread->program_counter](method, thread, jvm);
	}
}

Checker -> chamado pelos outros modulos para validar as estruturas

|  - métodos que tem
-> - chama método 
*  - o que faz

main
| -
-> startJVM
	

jvm
| startJVM
| tem um monte de estruturas
* inicia só o leitor exibidor ou a jvm
| carregarClasse_01
	-> 'leitor_eibidor'
	-> 'checker'
| classLinkingVerification
	-> 'checker'
| executeMethod
	-> 'interpreter'
| freeClassData
	-> 'leitor_exibidor'

interpreter
| interpreter
| impĺementação de altos upcodes
* executa as instruções dos opcodes
* inicia func com altas funcoes
| Tconst, Tipush
	-> 'so coisas de pilha da jvm'
| accessField
	-> 'altas funcoes da jvm'
| handleObject
	-> 'tem leitor_exibidor(constPoolInf) e altas jvm'


checker
* valida as estruturas
| isMethodDescriptor
	-> 'leitor_exibidor'
| verifyClassfile
	-> 'leitor_exibidor'

leitor_exibidor
* le e exibe classfile 
| so se chama


Principais Estruturas de Dados::

- Each instance of the JVM has one method area and one heap.
- These areas are shared by all threads running inside the virtual machine
- As the program runs, the virtual machine places all objects the program instantiates onto the heap.
- As each new thread comes into existence, it gets its own pc register (program counter) and Java stack.
- A threads Java stack stores the state of Java (not native) method invocations for the thread.
- The state of a Java method invocation includes its local variables, the parameters with which it was invoked, 
  its return value (if any), and intermediate calculations.
- The Java stack is composed of stack frames (or frames).
- A stack frame contains the state of one Java method invocation. 
- When a thread invokes a method, the JVM pushes a new frame onto that threads Java stack. When the method completes, 
  the virtual machine pops and discards the frame for that method. 
- The JVM has no registers to hold intermediate data values. The instruction set uses the Java stack for storage of intermediate data values.

The Method Area
- Information about loaded types is stored in a logical area of memory called the method area. When the JVM loads a type, 
  it uses a class loader to locate the appropriate class file.
- The virtual machine extracts information about the type from the binary data and stores the information in the method area.
- All threads share the same method area, so access to the method areas data structures must be designed to be thread-safe.

The Heap
- Whenever a class instance or array is created in a running Java application, the memory for the new object is allocated from a single heap.

The Java Stack
- When a new thread is launched, the JVM creates a new Java stack for the thread.

The Stack Frame
- The stack frame has three parts: local variables, operand stack, and frame data.

DATA_TYPES: pode ser primitive types, como short, integer, float_ ou reference

// - Each instance of the JVM has one method area and one heap.
// - These areas are shared by all threads running inside the virtual machine
typedef struct jvm 
{
	THREAD *thread_jvm;
	HEAP *heap_jvm;
	CLASS_DATA * method_area_jvm;  
} JVM;

// - The stack frame has three parts: local variables, operand stack, and frame data.
typedef struct operand 
{
	uint32_t value;
	TYPE type;
	struct operand *next;
} OPERAND_STACK;

// - The stack frame has three parts: local variables, operand stack, and frame data.
typedef struct frame 
{
	uint32_t *local_variables; 						// 3.6.1 Local Variables
	OPERAND_STACK *operand_stack; 					// 3.6.2 Operand Stacks
	constant_pool_info *current_constant_pool;
	struct frame *next;
} FRAME;

// - As each new thread comes into existence, it gets its own pc register (program counter) and Java stack.
typedef struct thread 
{
	OPCODE * program_counter;  // https://docs.oracle.com/javase/specs/jvms/se6/html/Overview.doc.html#6648
	FRAME * jvm_stack;  	   // https://docs.oracle.com/javase/specs/jvms/se6/html/Overview.doc.html#6654
	struct thread *next;
} THREAD;

// - Whenever a class instance or array is created in a running Java application, the memory for the new object is allocated from a single heap.
typedef struct heap_area 
{  // https://docs.oracle.com/javase/specs/jvms/se6/html/Overview.doc.html#15730
	struct object *objects;
	struct array *arrays;
} HEAP;

typedef struct object 
{
	CLASS_DATA *class_data_reference;
	VARIABLE *instance_variables;
	struct object *next;
} OBJECT;

typedef struct array 
{
	CLASS_DATA *class_data_reference;
	int32_t count;
	DATA_TYPES *entry;
	ARRAY_TYPE atype;
	struct array *next;
} ARRAY;


typedef struct method_data {
	constant_pool_info *method_name;		  // CONSTANTE_Utf8
	constant_pool_info *method_descriptor;  // CONSTANTE_Utf8
	uint16_t modifiers;				  // access_flags
	struct CLASS_DATA *CLASS_DATA;
	// se o método não é abstrato.
	uint32_t code_length;
	uint8_t *bytecodes;	// instruções da jvm
	uint16_t stack_size;   // tamanho da pilha de operandos
	uint16_t locals_size;  // tamanho do vetor de variaveis locais
	uint16_t exception_table_length;
	exception_table_type *exception_table;
	method_info *info;
} METHOD_DATA;

// CLASS_DATA
typedef struct CLASS_DATA 
{
	constant_pool_info *class_name;  // CONSTANTE_Utf8
	ClassFile *classfile;
	uint16_t modifiers;
	struct CLASS_DATA *class_loader_reference;
	constant_pool_info *runtime_constant_pool;
	FIELD_DATA *field_data;
	METHOD_DATA *method_data;
	VARIABLE *class_variables;
	struct object *instance_class;
	struct CLASS_DATA *next;
} CLASS_DATA;


typedef struct field_data 
{
	constant_pool_info *field_name;		 // CONSTANTE_Utf8
	constant_pool_info *field_descriptor;  // CONSTANTE_Utf8
	TYPE field_type;
	uint16_t modifiers;  // access_flags
	field_info *info;
	struct variable *var;
} FIELD_DATA;

typedef struct variable 
{
	FIELD_DATA *field_reference;
	DATA_TYPES value;
	struct variable *next;
} VARIABLE;

startJVM
loadClass
linkClass {verifyLink, prepareLink, resolveLink}
initializeClass
executeMethod
unloadClass
getCodeAttribute, getClassName, getSuperClass, getClassget, ClassVariable, getInstanceVariable, getMethod
isSuperClass
exitJVM

typedef struct constant_pool_info
{
	uint8_t	tag; // representa o numero do CONSTANT_X
	union
	{
		struct{									// 4.4.1
			uint16_t	name_index;				
		}Class;

		struct{									// 4.4.2
			// class_index;
			uint16_t	name_index;				
			uint16_t	name_and_type_index;
		}Ref;

		struct{									// 4.4.3
			uint16_t	string_index;
		}String;

		struct{									// 4.4.4
			uint32_t	bytes;
		}Integer_Float;

		struct{									// 4.4.5
			uint32_t 	high_bytes;
			uint32_t 	low_bytes;
		}Long_Double;

		struct{									// 4.4.6			
			uint16_t	name_index;
			uint16_t	descriptor_index;
		}NameAndType;

		struct{									// 4.4.7
			uint16_t	length;
			uint8_t*	bytes;
		}Utf8;


	}u;
}constant_pool_info;

// 4.7.3. The Code Attribute 
typedef struct exception_table_type{
	uint16_t	start_pc;
	uint16_t	end_pc;
	uint16_t	handler_pc;
	uint16_t	catch_type;
}exception_table_type;

// 4.7.6. The InnerClasses Attribute
typedef struct classes_type{
	uint16_t	inner_class_info_index;
	uint16_t	outer_class_info_index;
	uint16_t	inner_name_index;
	uint16_t	inner_class_access_flags;
}classes_type;

// 4.7.12. The LineNumberTable Attribute 
typedef struct line_number_table_type{
	uint16_t	start_pc;
	uint16_t	line_number;
}line_number_table_type;

// 4.7.13. The LocalVariableTable Attribute
typedef struct local_variable_table_type{
	uint16_t	start_pc;
	uint16_t	length;
	uint16_t	name_index;
	uint16_t	descriptor_index;
	uint16_t	index;
}local_variable_table_type;

typedef struct attribute_info{
	// The constant_pool entry at that index must be a CONSTANT_Utf8_info of attribute name
	uint16_t	attribute_name_index;
	uint32_t	attribute_length;
	union{
		struct{											// 4.7.2
			uint16_t	constantvalue_index;
		}ConstantValue;

		struct{											// 4.7.3
			uint16_t		max_stack;
			uint16_t 		max_locals;
			uint32_t		code_length;
			uint8_t*		code;
			uint16_t		exception_table_length;
			exception_table_type *	exception_table;
			uint16_t		attributes_count;
			struct attribute_info*	attributes;
		}Code;

		struct{											// 4.7.15
		}Deprecated;

		struct{											// 4.7.5
			uint16_t		number_of_exceptions;
			uint16_t*		exception_index_table;
		}Exceptions;

		struct{											// 4.7.6
			uint16_t		number_of_classes;
			classes_type *	classes;
		}InnerClasses;

		struct{											// 4.7.12
			uint16_t		line_number_table_length;
			line_number_table_type *	line_number_table;
		}LineNumberTable;

		struct{
			// local_variable_type_table_length
			uint16_t		local_variable_table_length; // 4.7.14
			local_variable_table_type *	local_variable_table;
		}LocalVariableTable;

		struct{											// 4.7.8
		}Synthetic;

		struct{											// 4.7.10
			uint16_t		sourcefile_index;
		}SourceFile;
	}u;
}attribute_info;

// 4.5. Fields
// Each field is described by a field_info structure. No two fields in one class 
// file may have the same name and descriptor (§4.3.2). 
typedef	struct field_info{
	uint16_t		access_flags;			// máscara de bits que especifica permissões de acesso e propriedades do field
	uint16_t		name_index;				// índice para o contant_pool contendo o nome do field
	uint16_t		descriptor_index;		// índice para o contant_pool contendo um descritor de field válido
	uint16_t		attributes_count;		// número de atributos do field
	attribute_info*	attributes;				// array contendo informações sobre os atributos do field
}field_info;

// 4.6. Methods 
// Each method, including each instance initialization method (§2.9) and the class or interface initialization 
// method (§2.9), is described by a method_info structure. No two methods in one class file may have the same 
// name and descriptor (§4.3.3). 
typedef struct method_info{
	uint16_t		access_flags;			// máscara de bits que especifica permissões de acesso e propriedades do método 
	uint16_t		name_index;			// índice para o contant_pool contendo o nome simples do método, ou nome especial <init> 
	uint16_t		descriptor_index;		// índice para o contant_pool contendo um descritor de método válido
	uint16_t		attributes_count;		// número de atributos do metodo
	attribute_info*	attributes;
}method_info;

// 4.1. The ClassFile Structure 
// class file consists of a single ClassFile structure
typedef struct ClassFile{
	uint32_t		magic;					// assinatura do arquivo .class = 0xCAFEBABE
	uint16_t		minor_version;			// (m)
	uint16_t		major_version;			// (M)	indicam a versao do arquivo no formato M.m
											//4 bytes, versão para comparar com o que a JVM pode ler.
	uint16_t		constant_pool_count;	// número de entradas da tabela constant_pool + 1 
											// Cada array de elemento contem um byte que representa o tipo da contant_pool (string, char, int, etc)
	constant_pool_info*	constant_pool;		// tabela de estruturas representando strings, nomes de classes, interfaces, nomes de campos, etc.
	uint16_t		access_flags;			// máscara de bits que especifica permissões de acesso e propriedades da classe ou interface
	uint16_t		this_class;				// aponta para uma estrutura CONSTANT_Class_info. Representa a classe ou interface definida pelo ClassFile 
	uint16_t		super_class;			// aponta para uma estrutura CONSTANT_Class_info. Representa a superclasse direta (classe mãe)
	uint16_t		interfaces_count;		// número de entradas no array 'interfaces'
	uint16_t*		interfaces;				// cada entrada desse array é um índice da constant_pool do tipo CONSTANT_Class_info, representa uma interface que é uma superinterface direta desta classe ou interface

	uint16_t		fields_count;			// número de entradas no array 'fields'
	field_info *	fields;					// cada entrada desse array é uma estrutura 'field_info'. Variaveis de classe ou de instâncias declaradas nesta classe ou interface

	uint16_t		methods_count;			// número de entradas no array 	'methods'
	method_info*	methods;				// cada entrada desse array é uma estrutura 'method_info', contendo a descrição completa de um método da classe ou interface
	uint16_t		attributes_count;		// número de entradas no array 'attributes'
	attribute_info*	attributes;				// cada entrada desse array é uma estrutura 'attribute_info'
}ClassFile;

// Methods
// para ler bytes do arquivo
uint8_t	u1Read(FILE *);
uint16_t u2Read(FILE *);
uint32_t u4Read(FILE *);

// para obter tipo do atributo
ATTRIBUTE_TYPE	getAttributeType(attribute_info *, ClassFile *);

// obtem campos do ClassFile
ClassFile * obtainClassFile(FILE *);
void obtainConstantPool(ClassFile *, FILE *);
void obtainInterfaces(ClassFile *, FILE *);
void obtainFields(ClassFile *, FILE *);
void obtainMethods(ClassFile *, FILE *);
void obtainAttributes(field_info *, method_info *, attribute_info *, ClassFile *, FILE *);

// mostra ClassFile no arquivo de saida
void showClassFile(ClassFile *, FILE *);
void showGeneralInfo(ClassFile *, FILE *);
void showConstantPool(ClassFile *, FILE *);
void showInterfaces(ClassFile *, FILE *);
void showFields(ClassFile *, FILE *);
void showMethods(ClassFile *, FILE *);
void showAttributes(field_info *, method_info *, attribute_info *, ClassFile *, FILE *);	// atributos de field, metodo, de Code_Attribute ou de classe.

// mostra constantes no arquivo de saida
void printConstUtf8(constant_pool_info *, FILE *);
void printConstantClass(ClassFile *,constant_pool_info *, FILE *);
void printConstantString(ClassFile *, constant_pool_info *, FILE *);
void printConstantNameAndType(ClassFile *, constant_pool_info *, char, FILE *);
void printConstantRef(ClassFile *,constant_pool_info *, char, FILE *);

// limpa cada estrutura
void freeClassFile(ClassFile *);
void freeConstantPool(ClassFile *);
void freeFields(ClassFile *);
void freeMethods(ClassFile *);
void freeAttribute(attribute_info *, ClassFile *);

5) Explique o funcionamento do interpretador implementado, indicando lógica, estruturas de dados, nomes de funções 
chamadas. Exemplifique considerando a execução de uma instrução qualquer.

// Define um ponteiro pra função chamado INSTRUCTION que retorna void e recebe METHOD_DATA*, 
// THREAD* e JVM* como parâmetros.
typedef void (*INSTRUCTION)(METHOD_DATA *, THREAD *, JVM *);

typedef struct method_data {
	constant_pool_info *method_name;		  // CONSTANTE_Utf8
	constant_pool_info *method_descriptor;  // CONSTANTE_Utf8
	uint16_t modifiers;				  // access_flags
	struct CLASS_DATA *CLASS_DATA;
	// se o método não é abstrato.
	uint32_t code_length;
	uint8_t *bytecodes;	// instruções da jvm
	uint16_t stack_size;   // tamanho da pilha de operandos
	uint16_t locals_size;  // tamanho do vetor de variaveis locais
	uint16_t exception_table_length;
	exception_table_type *exception_table;
	method_info *info;
} METHOD_DATA;

// - As each new thread comes into existence, it gets its own pc register (program counter) and Java stack.
typedef struct thread 
{
	OPCODE * program_counter;  // https://docs.oracle.com/javase/specs/jvms/se6/html/Overview.doc.html#6648
	FRAME * jvm_stack;  	   // https://docs.oracle.com/javase/specs/jvms/se6/html/Overview.doc.html#6654
	struct thread *next;
} THREAD;

// - Each instance of the JVM has one method area and one heap.
// - These areas are shared by all threads running inside the virtual machine
typedef struct jvm 
{
	THREAD *thread_jvm;
	HEAP *heap_jvm;
	CLASS_DATA * method_area_jvm;  
} JVM;

// funcao interpreter - executa todas as instrucoes
void interpreter(METHOD_DATA*, THREAD*, JVM*);

// do {
//     atomically calculate pc and fetch opcode at pc;
//     if (operands) fetch operands;
//     execute the action for the opcode;
// } while (there is more to do);
void interpreter(METHOD_DATA* method, THREAD* thread, JVM* jvm)
{
	thread->program_counter = method->bytecodes;

	// enquanto houver instruções
	while(thread->program_counter < (method->bytecodes + method->code_length))
	{	
		func[*thread->program_counter](method, thread, jvm);
	}
}

executeMethod("<clinit>", "()V", cd, jvm, thread, NULL, 0, NULL)

executeMethod(char * method_name, char * method_descriptor, CLASS_DATA * cd, JVM * jvm, THREAD * thread, void * this, uint16_t nargs, uint32_t * args)

method_data = GetMethod - entra em um laço até encontrar ou não um method

verifica se é abstract ( illegalacesserror)

executeMethod nao trata string, se o method descriptor receber String e devolver Void ou ser main, ignora os argumentos 

interpreter(method, thread, jvm);

Chamado em 
void executeMethod(char * method_name,
				   char * method_descriptor,
				   CLASS_DATA * cd,
				   JVM * jvm,
				   THREAD * thread,
				   void * this,
				   uint16_t nargs,
				   uint32_t * args)
do jvm.c 

executeMethod

obtem metodo (um METHOD_DATA) com getMethod				  
se tem metodo
	se o metodo eh ABSTRACT eh um ERRO
	caso contrario e se tem bytecodes
		cria frame para metodo
		se o metodo nao eh STATIC entao nao tem variáveis locais
		se (index + nargs > method->locals_size ) entao eh um ERRO
		armazena variaveis locais do metodo na pilha do frame

		pilha de operandos nula 
		cp do frame eh a cp atual
		proximo frame eh o q ta na pilha jvm da thread
		e a atual eh o frame
		chama interpretador
	se nao tem bytecode eh erro
se nao eh metodo eh erro

interpretador executa enquanto houver instrução da thread