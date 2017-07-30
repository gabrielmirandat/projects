#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <wchar.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>

#define CLASS 1
#define METHOD_FIELD 2
#define ATTRIBUTE 3

#define T_BOOLEAN 4
#define T_CHAR 5
#define T_FLOAT 6
#define T_DOUBLE 7
#define T_BYTE 8
#define T_SHORT 9
#define T_INT 10
#define T_LONG 11

/* Flags de classe ou interface */
#define FLAG_ABSTRATA 0x400
#define FLAG_INTERFACE 0x200
#define FLAG_SUPER 0x20
#define FLAG_FINAL 0x10
#define FLAG_PUBLIC 0x1

/* Flags de field */
#define		ACC_PUBLIC		0x0001	// 0000 0000 0000 0001
#define		ACC_PRIVATE		0x0002	// 0000 0000 0000 0010
#define		ACC_PROTECTED		0x0004	// 0000 0000 0000 0100
#define		ACC_STATIC		0x0008	// 0000 0000 0000 1000
#define		ACC_FINAL		0x0010	// 0000 0000 0001 0000
#define		ACC_VOLATILE		0x0040	// 0000 0000 0100 0000
#define		ACC_TRANSIENT		0x0080	// 0000 0000 1000 0000

/* Flags de metodo */
#define		ACC_PUBLIC		0x0001	// 0000 0000 0000 0001
#define		ACC_PRIVATE		0x0002	// 0000 0000 0000 0010
#define		ACC_PROTECTED		0x0004	// 0000 0000 0000 0100
#define		ACC_STATIC		0x0008	// 0000 0000 0000 1000
#define		ACC_FINAL		0x0010	// 0000 0000 0001 0000
#define		ACC_SYNCHRONIZED	0x0020	// 0000 0000 0010 0000
#define		ACC_NATIVE		0x0100	// 0000 0001 0000 0000
#define		ACC_ABSTRACT		0x0400	// 0000 0100 0000 0000
#define		ACC_STRICT		0x0800	// 0000 1000 0000 0000

/* Access Flags de InnerClasses */
#define		ACC_PUBLIC		0x0001	// 0000 0000 0000 0001
#define		ACC_PRIVATE		0x0002	// 0000 0000 0000 0010
#define		ACC_PROTECTED		0x0004	// 0000 0000 0000 0100
#define		ACC_STATIC		0x0008	// 0000 0000 0000 1000
#define		ACC_FINAL		0x0010	// 0000 0000 0001 0000
#define		ACC_INTERFACE		0x0200	// 0000 0010 0000 0000
#define		ACC_ABSTRACT		0x0400	// 0000 0100 0000 0000

//	TAGS (CONSTANTE Pool)
#define Classe_const 7
#define CONSTANTEe_campo_referencia 9
#define CONSTANTEe_metodo_referencia 10
#define CONSTANTEe_Interface_referencia 11
#define CONSTANTE_String 8
#define CONSTANTE_Integer 3
#define CONSTANTE_Float 4
#define CONSTANTE_Long 5
#define CONSTANTE_Double 6
#define CONSTANTE_NameAndType 12
#define CONSTANTE_Utf8 1

/*======================================================*/
//	TIPOS DE ATRIBUTOS
#define CONSTANTE_VALUE 0
#define CODE 1
#define DEPRECATED 2
#define EXCEPTIONS 3
#define INNER_CLASSES 4
#define LINE_NUMBER_TABLE 5
#define LOCAL_VARIABLE_TABLE 6
#define SYNTHETIC 7
#define SOURCE_FILE 8
#define UNKNOWN 9

#define TIPO_ATRIBUTO short

/*======================================================*/


//	INFO

// constPoolInf. itens do pool de CONSTANTEes.
// **The memory required to store a union variable is the memory required for
// largest element of an union.
typedef struct constPoolInf {
	uint8_t tag;
	union {
		struct {
			uint16_t indicador_nome;
		} Class;

		struct {
			uint16_t indicador_nome;
			uint16_t indicador_nome_e_tipo;
		} Ref;

		struct {
			uint16_t indicador_nome;
			uint16_t descriptor_index;
		} NameAndType;

		struct {
			uint16_t length;
			uint8_t *bytes;
		} Utf8;

		struct {
			uint16_t indicador_string;
		} String;

		struct {
			uint32_t bytes;
		} Integer_Float;

		struct {
			uint32_t high_bytes;
			uint32_t low_bytes;
		} Long_Double;
	} u;
} constPoolInf;

// definicao de tipos para attribute_info
typedef struct exception_table_type {
	uint16_t start_pc;
	uint16_t end_pc;
	uint16_t handler_pc;
	uint16_t catch_type;
} exception_table_type;

typedef struct classes_type {
	uint16_t inner_class_info_index;
	uint16_t outer_class_info_index;
	uint16_t inner_name_index;
	uint16_t inner_class_access_flags;
} classes_type;

typedef struct line_number_table_type {
	uint16_t start_pc;
	uint16_t line_number;
} line_number_table_type;

typedef struct local_variable_table_type {
	uint16_t start_pc;
	uint16_t length;
	uint16_t indicador_nome;
	uint16_t descriptor_index;
	uint16_t index;
} local_variable_table_type;

// attribute_info
typedef struct attribute_info {
	uint16_t attribute_name_index;  // aponta para um índice na CONSTANTEe_pool
									// contendo uma CONSTANTE_Utf8 com nome do
									// atributo
	uint32_t attribute_length;
	union {
		struct {
			uint16_t CONSTANTEvalue_index;
		} CONSTANTEValue;

		struct {
			uint16_t max_stack;
			uint16_t max_locals;
			uint32_t code_length;
			uint8_t *code;
			uint16_t exception_table_length;
			exception_table_type *exception_table;
			uint16_t conts_atributos;
			struct attribute_info *attributes;
		} Code;

		struct {
		} Deprecated;

		struct {
			uint16_t number_of_exceptions;
			uint16_t *exception_index_table;
		} Exceptions;

		struct {
			uint16_t number_of_classes;
			classes_type *classes;
		} InnerClasses;

		struct {
			uint16_t line_number_table_length;
			line_number_table_type *line_number_table;
		} LineNumberTable;

		struct {
			uint16_t local_variable_table_length;
			local_variable_table_type *local_variable_table;
		} LocalVariableTable;

		struct {
		} Synthetic;

		struct {
			uint16_t sourcefile_index;
		} SourceFile;
	} u;
} attribute_info;

typedef struct field_info {
	uint16_t flags_acesso;	/* máscara de bits que especifica permissões de
						acesso
						e propriedades do field */
	uint16_t indicador_nome;  // índice para o CONSTANTEe_pool contendo o nome
							  // do field
	uint16_t descriptor_index;   // índice para o CONSTANTEe_pool contendo um
								 // descritor de field válido
	uint16_t conts_atributos;	// número de atributos do field
	attribute_info *attributes;  // array contendo informações sobre os
								 // atributos do field
} field_info;

typedef struct method_info {
	uint16_t flags_acesso;   /* máscara de bits que especifica permissões de
			 acesso
			 e propriedades do método */
	uint16_t indicador_nome; /* índice para o CONSTANTEe_pool contendo o nome
			 simples
			 do método, ou nome especial <init> */
	uint16_t descriptor_index;  // índice para o CONSTANTEe_pool contendo um
								// descritor de método válido
	uint16_t conts_atributos;   // número de atributos do metodo
	attribute_info *attributes;
} method_info;


// estrutura de dados ClasseDeArquivo
typedef struct {
	uint32_t magic;  // assinatura do arquivo .class = 0xCAFEBABE

	uint16_t Min_version;		 // (m)
	uint16_t Principal_version;  // (M)	indicam a versao do arquivo no
								 // formato M.m
	// 4 bytes, versão para comparar com o que a JVM pode ler.

	uint16_t Cont_ConstPool;  // número de entradas da tabela CONSTANTEe_pool +
							  // 1
	// Cada array de elemento contem um byte que representa o tipo da CONSTANTEe
	// (string, char, int, etc)


	constPoolInf *CONSTANTEe_pool; /* tabela de estruturas representando
				strings, nomes de classes,
				interfaces, nomes de campos, etc. */

	uint16_t flags_acesso; /* máscara de bits que especifica permissões de
		   acesso
		   e propriedades da classe ou interface */

	uint16_t classe_arq; /* aponta para uma estrutura CONSTANTE_Class_info.
			 representa a classe ou interface definida pelo ClasseDeArquivo */

	uint16_t super_classe; /* aponta para uma estrutura CONSTANTE_Class_info.
		   representa a superclasse direta (classe mãe) */

	uint16_t interfaces_count;  // número de entradas no array 'interfaces'
	uint16_t *interfaces;		/* cada entrada desse array é um índice da
					CONSTANTEe_pool do tipo CONSTANTE_Class_info,
					representa uma interface que é uma superinterface direta desta
					classe ou interface */

	uint16_t conts_campos;  // número de entradas no array 'fields'
	field_info *fields; /* cada entrada desse array é uma estrutura 'field_info'
			variaveis de classe ou de instâncias declaradas nesta classe ou
			interface*/

	uint16_t conts_metodo;  // número de entradas no array 	'methods'
	method_info *methods;   /* cada entrada desse array é uma estrutura
				'method_info', contendo
				a descrição completa de um método da classe ou interface*/

	uint16_t conts_atributos;	// número de entradas no array 'attributes'
	attribute_info *attributes;  // cada entrada desse array é uma estrutura
								 // 'attribute_info'
} ClasseDeArquivo;
/*======================================================*/
//	MÉTODOS

uint8_t read1Byte(FILE *);
uint16_t read2Byte(FILE *);
uint32_t read4Byte(FILE *);
TIPO_ATRIBUTO getTipoAtributo(attribute_info *, ClasseDeArquivo *);

ClasseDeArquivo *loadClasseDeArquivo(FILE *);
ClasseDeArquivo *newClasseDeArquivo();
void setCONSTANTEPool(ClasseDeArquivo *, FILE *);
void setAccessFlags(ClasseDeArquivo *, FILE *);
void setThisClass(ClasseDeArquivo *, FILE *);
void setSuperClass(ClasseDeArquivo *, FILE *);
void setInterfaces(ClasseDeArquivo *, FILE *);
void setFields(ClasseDeArquivo *, FILE *);
void setMethods(ClasseDeArquivo *, FILE *);
void setAttributes(field_info *, method_info *, attribute_info *,
				   ClasseDeArquivo *, FILE *);
void freeClasseDeArquivo(ClasseDeArquivo *);
void freeCONSTANTEPool(ClasseDeArquivo *);
void freeFields(ClasseDeArquivo *);
void freeMethods(ClasseDeArquivo *);
void freeAttribute(attribute_info *, ClasseDeArquivo *);
/*======================================================*/

void ImprimeConstUtf8(constPoolInf *, FILE *);
void ImprimeCONSTANTEeClasse(ClasseDeArquivo *, constPoolInf *, FILE *);
void ImprimeCONSTANTEeString(ClasseDeArquivo *, constPoolInf *, FILE *);
void ImprimeCONSTANTEeNomeTipo(ClasseDeArquivo *, constPoolInf *, char, FILE *);
void ImprimeCONSTANTEeReferencia(ClasseDeArquivo *, constPoolInf *, char,
								 FILE *);
void mostrarClasseDeArquivo(ClasseDeArquivo *, FILE *);
void mostrarInfo(ClasseDeArquivo *, FILE *);
void mostrarConstPool(ClasseDeArquivo *, FILE *);
void mostrarInterfaces(ClasseDeArquivo *, FILE *);
void mostrarCampos(ClasseDeArquivo *, FILE *);
void mostrarMetodos(ClasseDeArquivo *, FILE *);
void mostrarAtributos(field_info *, method_info *, attribute_info *,
					  ClasseDeArquivo *,
					  FILE *);  // atributos de field, metodo,
								// de Code_Attribute ou de classe.
