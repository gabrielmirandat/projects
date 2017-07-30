


// jvm.h

/*==========================================*/
// 	DESCRIÇÃO

// Define os tipos e métodos utilizados pela JVM.

/*==========================================*/
//	INCLUDES
#include "LeitExib.h"
/*==========================================*/
//	TIPOS

typedef uint8_t OPCODE;
typedef char TYPE;
typedef uint32_t ARRAY_TYPE;

// Descritores de Fields
#define BYTE 'B'
#define CHAR 'C'
#define DOUBLE 'D'
#define FLOAT 'F'
#define INT 'I'
#define LONG 'J'
#define REF_INST 'L'
#define SHORT 'S'
#define BOOLEAN 'Z'
#define REF_ARRAY '['

// OBJECT
typedef struct object obj;
typedef struct array ar;


// VALUE
typedef struct value {
	TYPE type;
	union {
		struct {  // BYTE
			int8_t byte;
		} Byte;

		struct {  // SHORT
			int16_t short_;
		} Short;

		struct {  // INTEGER
			int32_t integer;
		} Integer;

		struct {  // LONG
			uint32_t high_bytes;
			uint32_t low_bytes;
		} Long;

		struct {  // FLOAT
			uint32_t float_;
		} Float;

		struct {  // DOUBLE
			uint32_t high_bytes;
			uint32_t low_bytes;
		} Double;

		struct {  // CHAR
			uint16_t char_;
		} Char;

		struct {  // boolean
			uint8_t boolean;
		} Boolean;

		struct {  // INSTANCE REFERENCE
			struct object *reference;
		} InstanceReference;

		struct {  // ARRAY REFERENCE
			struct array *reference;
		} ArrayReference;

		struct {  // RETURN ADDRESS
			OPCODE *return_address;
		} ReturnAddress;
	} u;
} VALUE;

// OPERAND
typedef struct operand {
	uint32_t value;
	TYPE type;
	struct operand *prox;
} OPERAND;

// FRAME
typedef struct frame {
	uint32_t *local_variables;
	OPERAND *operand_stack;
	constPoolInf *current_constant_pool;
	struct frame *prox;
} FRAME;


// THREAD
typedef struct thread {
	OPCODE *
		program_counter;  // https://docs.oracle.com/javase/specs/jvms/se6/html/Overview.doc.html#6648
	FRAME *
		jvm_stack;  // https://docs.oracle.com/javase/specs/jvms/se6/html/Overview.doc.html#6654
	struct thread *prox;
} THREAD;


// HEAP_AREA
typedef struct heap_area {  // https://docs.oracle.com/javase/specs/jvms/se6/html/Overview.doc.html#15730
	struct object *objects;
	struct array *arrays;
} HEAP_AREA;

// FIELD_DATA
typedef struct field_data {
	constPoolInf *field_name;		 // CONSTANTE_Utf8
	constPoolInf *field_descriptor;  // CONSTANTE_Utf8
	TYPE field_type;
	uint16_t modifiers;  // access_flags
	field_info *info;
	struct variable *var;
} FIELD_DATA;

// VARIABLE
typedef struct variable {
	FIELD_DATA *field_reference;
	VALUE value;
	struct variable *prox;
} VARIABLE;


// METHOD_DATA
typedef struct method_data {
	constPoolInf *method_name;		  // CONSTANTE_Utf8
	constPoolInf *method_descriptor;  // CONSTANTE_Utf8
	uint16_t modifiers;				  // access_flags
	struct DADOS_CLASSE *DADOS_CLASSE;
	// se o método não é abstrato.
	uint32_t code_length;
	uint8_t *bytecodes;	// instruções da jvm
	uint16_t stack_size;   // tamanho da pilha de operandos
	uint16_t locals_size;  // tamanho do vetor de variaveis locais
	uint16_t exception_table_length;
	exception_table_type *exception_table;
	method_info *info;
} METHOD_DATA;

// DADOS_CLASSE
typedef struct DADOS_CLASSE {
	constPoolInf *nomeClasse;  // CONSTANTE_Utf8
	ClasseDeArquivo *classfile;
	uint16_t modifiers;
	struct DADOS_CLASSE *referencia_carregadorClasse;
	constPoolInf *runtime_constant_pool;
	FIELD_DATA *field_data;
	METHOD_DATA *method_data;
	VARIABLE *variaveisClasse;
	struct object *instanceClasse;
	struct DADOS_CLASSE *prox;
} DADOS_CLASSE;

typedef struct object {
	DADOS_CLASSE *class_data_reference;
	VARIABLE *instance_variables;
	struct object *prox;
} OBJECT;

typedef struct array {
	DADOS_CLASSE *class_data_reference;
	int32_t count;
	VALUE *entry;
	ARRAY_TYPE atype;
	struct array *prox;
} ARRAY;

// JVM
typedef struct jvm {
	THREAD *thread_jvm;
	HEAP_AREA *heap_jvm;
	DADOS_CLASSE * method_area_jvm;  // https://docs.oracle.com/javase/specs/jvms/se6/html/Overview.doc.html#6656
} JVM;
/*==========================================*/


void iniciar_jvm(char *, int, char **);
void carregarClasse_01(char *, DADOS_CLASSE **, DADOS_CLASSE *, JVM *);
void ligadorDeClasse(DADOS_CLASSE *, JVM *);
void classLinkingVerification(DADOS_CLASSE *, JVM *);
void classLinkingPreparation(DADOS_CLASSE *, JVM *);
void classLinkingResolution(ClasseDeArquivo *, JVM *);
void classInitialization(DADOS_CLASSE *, JVM *, THREAD *);
void executeMethod(char *, char *, DADOS_CLASSE *, JVM *, THREAD *, void *,
				   uint16_t, uint32_t *);
void classUnloading(DADOS_CLASSE *, JVM *);
attribute_info *getCodeAttribute(METHOD_DATA *, DADOS_CLASSE *);
char *getClassName(DADOS_CLASSE *);
DADOS_CLASSE *getSuperClass(ClasseDeArquivo *, JVM *);
DADOS_CLASSE *getClass(constPoolInf *, JVM *);
void jvmExit(JVM *);
VARIABLE *getClassVariable(constPoolInf *, DADOS_CLASSE *);
VARIABLE *getInstanceVariable(constPoolInf *, OBJECT *);
METHOD_DATA *getMethod(char *, char *, DADOS_CLASSE *, JVM *);
bool isSuperClass(DADOS_CLASSE *, DADOS_CLASSE *, JVM *);


void freeFrame(FRAME *);
void freeOperandStack(FRAME *);

void freeThreads(THREAD *);
void freeJvmStack(FRAME *);

void freeMethodArea(DADOS_CLASSE *);
void freeClassData(DADOS_CLASSE *);

void freeVariables(VARIABLE *);

void freeHeap(HEAP_AREA *);
void freeObjects(OBJECT *);
void freeArrays(ARRAY *);

void pushOperand(uint32_t, FRAME *);
uint32_t popOperand(FRAME *);
