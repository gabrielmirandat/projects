1) Instalar Bytecode Viewer e JClassLib
http://bytecodeviewer.com/
http://freecode.com/projects/jclasslib
2) Estudar e saber todos os componentes de um Java.Class
http://viralpatel.net/blogs/tutorial-java-class-file-format-revealed/
http://www.codeproject.com/Articles/24029/Home-Made-Java-Virtual-Machine
https://docs.oracle.com/javase/specs/jvms/se7/html/jvms-4.html




"LeitorExibidor.c"
ClasseDeArquivo *ca = loadClasseDeArquivo(arquivo_class);
mostrarClasseDeArquivo(ca, output);
freeClasseDeArquivo(ca);
fclose(arquivo_class);

Especificação do formato ponto class
- 'Introdução'
- 'Estrutura interna de arquivo .class'
- 'Pool de constantes'
- 'Campos (fields)' - A data member of a class. Field marks an instance variable.
- 'Métodos' - function of a class
- 'Atributos' - attributes are the instance variables of an Object.

Arquivo .class
- única classe ou interface
- Stream de bytes de 8 bits
- Tipos de dados
	u1 		 typedef unsigned char;
	u2 		 typedef unsigned short;
	u4 		 typedef unsigned int;
- Itens são sucessivos
	- Armazenados sequencialmente sem caracteres de preenchimento ou alinhamento
- Tabelas
	- Consistem de zero ou mais itens de tamanho variável - n da pra usar indice de offset
- Arrays
	- Consistem de zero ou mais itens de tamanho fixo - pode ser indexado como array
- Nomes de classes e interfaces
	- Representação completa de nomes qualificados
	- contantes em UTF-8
	- ponto qualificador é substituido pela barra de divisão
		- nome da classe Thread é java.lang.Thread que fica representado como java/lang/Thread
- Descritores: Strings representando o tipo de 'field' ou 'método'
	- Representado em UTF-8
	- Gramática: Tipo de classe, instância ou variável local
	- de CAMPO
		- 'FieldDescriptor': FieldType
		- 'ComponentType': FieldType
		- 'FieldType': BaseType, ObjectType, ArrayType
		- 'BaseType': 	B, 					byte 				Byte com sinal
					  	C, 					char 				Caracter Unicode 
					  	D, 					double 				Ponto flutuante (dupla precisão)
					  	F, 					float  				Ponto flutuante (precisão simples)
					  	I, 					int  				Inteiro
					  	J, 					long 				Inteiro longo
					  	S, 					short 				Inteiro curto com sinal
					  	Z 					boolean 			true ou false
		- 'ObjectType': L <classname> ; 	referência 			Instância da classe <nome_classe>
		- 'ArrayType':  [ ComponentType	    referência 			Uma dimensão de array
	- de MÉTODO 
		- representam tipos dos parâmetros passados e do valor que ele retorna
			- MethodDescriptor: ( ParameterDescriptor* ) ReturnDescriptor
			- ParameterDescriptor: FieldType
			- ReturnDescriptor: FieldType, V (void, retorna nada)
				- Para o método Object mymethod(int i, double d, Thread t), 
				  o descritor é (IDLjava/lang/Thread)

Estrutura ClassFile
ClassFile 
{      
	u4 				magic;      									//assinatura do arquivo .class (valor 0xCAFEBABE)
	u2 				minor_version;       							//m
	u2 				major_version;       							//M. Versão no formato M.m
	u2 				constant_pool_count;      						//# de entradas na tabela contant_pool + 1; 
																	//1 <= índice constant_pool < constant_pool_count
	cp_info 		constant_pool [constant_pool_count-1];			//tabela de estruturas {string, nomes classes e interfaces, nomes campos}
																	//dentro de estruturas e subestruturas ClassFile
																	//formato de cada entrada indicado pelo byte "tag"
	u2 				access_flags;      								//mascara de bits que especifica permissões de acesso
																	//e propriedades da classe ou interface
	u2 				this_class;    									//deve ser um índice válido da constant_poll
																	//aponta para estrutura CONSTANT_Class_info
																	//CONSTANT_Class_info representa a classe ou interface definida
	u2 				super_class;     								//deve ser um índice válido da constant_poll
																	//aponta para estrutura CONSTANT_Class_info
																	//representa super classe direta da classe definida
																	//0 se não for derivada - estende classe Object
	u2 				interfaces_count;      							//# de entrada no array interfaces[]
																	//0 <= índice interfaces < interfaces_count
																	//representa número de superinterfaces diretas
	u2 				interfaces [interfaces_count];      			//cada valor deve ser índice válido na tabela constant_poll
																	//a entrada deve ser do tipo CONSTANT_Class_info
																	//representa interface superinterface direta
	u2 				fields_count;      								//# de variáveis de classe ou de instâncias declaradas na classe ou interface
																	//# de entradas field_info da tabela fields[]
	field_info 		fields [fields_count];							//cada entrada na tabela deve ser uma estrutura field_info
																	//tem descrição completa de um campo da classe ou interface
																	//não inclui campos herdados de superclasses ou superinterfaces
	u2 				methods_count;     								//# de estruturas method_info na tabela methods[]
	method_info 	methods [methods_count];      					//cada entrada deve ser um method_info
																	//descrição completa de um método na classe ou interface
																	//se método não nativo ou não abstrato, são fornecidas as instruções que o implementam
																	//não inclui métodos de superclasses ou superinterfaces
	u2 				attributes_count;      							//# de estruturas attributes_info na tabela attributes[]		
	attribute_info 	attributes [attributes_count];     				//cada entrada em atributtes[] deve ser um attribute_info
																	//a JVM deve ignorar qualquer atributo que não reconheça
} 

access_flags
-ACC_PUBLIC			0x0001 			Declarada pública: pode ser acessada de fora do pacote.
-ACC_FINAL			0x0010 			Declarada final: não pode ter subclasses.
-ACC_SUPER			0x0020 			Chama métodos de superclasse via a instrução invokeespecial.
-ACC_INTERFACE		0x0200 			É interface, não uma classe.
-ACC_ABSTRACT		0x0400 			Declarada abstrata: não pode ser instanciada.
-DEMAIS BITS 		0x0000

CONSTANT_Class_info 
{
   		u1 tag;      
		u2 name_index; 
}

Pool de constantes
- armazena info simbólicas
- cada entrada tem a seguinte forma

cp_info 
{
	u1 tag;      //byte que define tipo da informação em cp_info
	u1 info[ ];  //
}  

Tipos válidos para tag:
CONSTANT_Class 					//7  - representa classe ou interface
CONSTANT_Fieldref 				//9  - representa um field
CONSTANT_Methodref 				//10 - representa um método
CONSTANT_InterfaceMethodref 	//11 - representa um método de interface
CONSTANT_String 				//8  - representa objetos constantes do tipo String
CONSTANT_Integer 				//3  - reprsenta constante inteira de 4 bytes
CONSTANT_Float 					//4  - representa constante de ponto flutuante de 4 bytes
CONSTANT_Long 					//5  - representa constante inteira de 8 bytes, big-endian, ocupa 2 índices da constant_poll
CONSTANT_Double 				//6  - representa constante de ponto flutuante de 8 bytes, big-endian, ocupa 2 índices da constant_poll
CONSTANT_NameAndType 			//12 - representa field ou método sem indicar classe ou interface a que pertence
CONSTANT_Utf8 					//1  - representa valores strings constantes, inclusive Unicode

//entrada deve ser estrutura CONSTANT_Utf8_info representando 
//nome completo qualificado da classe ou interface desse arquivo
//ex: Ljava/lang/Thread
CONSTANT_Class_info
{
	u1 tag;
	u2 name_index; 		//índice válido para tabela constant poll
}

CONSTANT_Fieldref_info
{
	u1 tag; 					
	u2 class_index; 			//indice válido para tabela constant_poll
								//CONSTANT_Utf8_info de nome completo da classe ou interface que contém esse field
	u2 name_and_type_index;     //indice válido para tabela constant_poll
								//CONSTANT_NameAndType_info indicando nome e descritor do field
}

CONSTANT_NameAndType_info
{
	ui tag;
	u2 name_index;				//CONSTANT_Utf8_info de nome simples de field ou método
	u2 descriptor_index; 		//CONSTANT_Utf8_info com descritor válido de field ou método
}

//codigos de 1 (char de 1 a 127),2 (char de 128 a 2047) ou 3 bytes (char de 2048 a 65535)
CONSTANT_Utf8_info
{
	u1 tag;
	u2 lenght; 					//indica # de bytes no array bytes[]. Não acaba com nulo.
	u1 bytes[lenght]; 			//contém bytes da string
}

CONSTANT_Methodref_info
{
	u1 tag;
	u2 class_index;				//indice válido para tabela constant_poll
								//CONSTANT_Utf8_info de nome completo da classe que contém a definição desse método
	u2 name_and_type_index; 	//indice válido para tabela constant_poll
								//indica nome e descritor do método
}

CONSTANT_InterfaceMethodref_info
{
	u1 tag;
	u2 class_index;				//indice válido para tabela constant_poll
								//CONSTANT_Utf8_info de nome completo da interface que contém a declaração do método
	u2 name_and_type_index;		//indica nome e descritor do método
}

CONSTANT_String_info
{
	u1 tag;						
	u2 string_index;			//indice válido para tabela constant_poll
								//CONSTANT_Utf8_info representando sequência de caracteres com o qual o objeto String será iniciado
}

CONSTANT_Integer_info
{
	u1 tag; 	
	u4 bytes;					//valor da constante int, em big-endian		
}

//0x7f800000 - infinito positivo
//0xff800000 - infinito negativo
//0x7f800001 até 0x7fffffff ou 0xff800001 até 0xffffffff - NaN
//int s = ((bits >> 31) == 0) ? 1 : -1;
//int e = ((bits >> 23) & 0xff);
//int m = (e == 0) ? (bits & 0x7fffff) << 1 : (bits & 0x7fffff) | 0x800000;
//s.m.2^(e-150)
CONSTANT_Float_info
{
	u1 tag; 	
	u4 bytes;					//valor da constante float, em big-endian, em precisão simples ponto flutuante
}

//((long) high_bytes << 32) + low_bytes
CONSTANT_Long_info
{
	u1 tag;
	u4 high_bytes;				//unsigned
	u4 low_bytes;				//unsigned
}

//0x7ff0000000000000L - infinito positivo
//0xfff0000000000000L - infinito negativo
//0x7ff0000000000001L até 0x7ffffffffffffL ou 0xfff0000000000001L até 0xffffffffffffffffL - NaN
//int s = ((bits >> 63) == 0) ? 1 : -1;
//int e = ((bits >> 52) & 0x7ffL);
//long m = (e == 0) ? (bits & 0xfffffffffffffL) << 1 : (bits & 0xfffffffffffffL) | 0x10000000000000L;
//s·m·2^(e-1075)
//(long bits) = ((long) high_bytes << 32) + low_bytes;
CONSTANT_Double_info
{
	u1 tag;
	u4 high_bytes;				//unsigned
	u4 low_bytes;				//unsigned
}

"SLIDE 37 - .class do programa HELLO WORLD"
BYTECODE VIEWER

Campos
//cada field é descrito por um field_info
//dois campos não podem ter o mesmo nome na classe
field_info
{
	u2 access_flags;								//máscara de hexas especificando permissões de acesso e propriedades do campo
	u2 name_index; 									//índice válido para tabela constant_poll
													//CONSTANT_Utf8_info representando nome simples de field
	u2 descriptor_index;							//índice válido para tabela constant_poll
													//CONSTANT_Utf8_info representando um descritor de campo válido
	u2 attributes_count;							//# de atributos do campo
	attribute_info atributtes[attributes_count] 	//atributos
}

access_flags
-ACC_PUBLIC			0x0001 			Declarada pública: pode ser acessada de fora do pacote.
-ACC_PRIVATE		0x0002 			Declarada privada: contexto restrito à definição da classe.
-ACC_PROTECTED		0x0004			Declarada protegida: pode ser usada na classe e nas subclasses.
-ACC_STATIC			0x0008			Decladarada estática: variável de classe e não de instância.
-ACC_FINAL			0x0010 			Declarada final: não pode ter seu valor alterado após a iniciação.
-ACC_VOLATILE 		0x0040 			Declarada volátil: não pode ser colocada em cache.
-ACC_TRANSIENT		0x0080 			Declarada transiente: não pode ser lida ou gravada por um gerente de objetos persistentes.

Métodos
//cada método é descrito por uma estrutura method_info
//métodos da mesma classe não podem ter mesmo nome e descritor
- u2 methods_count;							//# de estruturas method_info na tabela methods
- method_info methods [methods_count];		//métodos
method_info 
{      
	u2 access_flags; 								//máscara de hexas especificando permissões de acesso e propriedades do métdo
	u2 name_index;      							//índice válido para a tabela constant_poll
													//CONSTANT_Utf8_info como um nome especial de método ou simples, válido como nome do método
	u2 descriptor_index; 							//índice válido para a constant_poll
													//CONSTANT_Utf8_info representando descritor de método válido
	u2 attributes_count; 							//# de atributos do método
	attribute_info attributes[attributes_count]; 	//atributos
}

access_flags
-ACC_PUBLIC			0x0001 			público: pode ser acessado de fora do pacote.
-ACC_PRIVATE		0x0002 			privado: acesso restrito à definição da classe.
-ACC_PROTECTED		0x0004			protegido: pode ser chamado na classe e nas subclasses.
-ACC_STATIC			0x0008			estático: método de classe (chamado sem referir o objeto);
-ACC_FINAL			0x0010 			final: não pode ser sobre-escrito em subclasses.
-ACC_SYNCRONIZED	0x0020 			sincronizado: requer um monitor antes de ser executado
-ACC_NATIVE 		0x0100 			nativo: implementado em linguagem não Java
-ACC_ABSTRACT 		0x0400 			abstrato: sem definição, deve ser sobre-escrito em uma subclasse
-ACC_STRICT			0x0800 			estrito: utiliza modo ponto-flutuante não normalizado

Atributos
//usados nas estruturas ClassFile, field_info, method_info e code_attribute
//uma classe pode conter um número qualquer de atributos
attribute_info
{
	u2 attribute_name_index; 		//índice válido para a tabela constant_poll
									//CONSTANT_Utf8_info representando o nome do atributo
	u4 attribute_lenght; 			//indica tamanho, em bytes, do restante do atributo
									//não inclui 6 bytes que contém índice do nome e o comprimento do atributo
	u1 info [attribute_lenght]
}

Pré-definidos
ConstantValue 						//deve ser implementado
Code 								//deve ser implementado
Deprecated (op)
Exceptions 							//deve ser implementado
InnerClasses 						//deve ser implementado
SourceFile (op)
Synthetic 							//deve ser implementado
LineNumberTable (op)
LocalVariableTable (op)

ConstantValue
- em estrutura field_info para iniciar variáveis (implícitas ou explícitas) estáticas
- se field_info contém atributo ConstantValue associado a uma var não estática, a JVM deve ignorar
- toda JVM deve reconhecer atributos ConstantValue
- variáveis declaradas em interfaces são implicitamente estáticas, finais e públicas

ConstantValue_attribute
{
	u2 attribute_name_index;		//índice válido p/ tabela cp
									//CONSTANT_Utf8_info representando a string ConstantValue
	u4 attribute_lenght;			//assume sempre o valor 2
	u2 constantvalue_index;			//índice para CONSTANT_<tipo>_info contendo valor a ser atribuido 
									//na iniciação da variável estática
									//é índice válido para a tabela cp com estrutura CONSTANT_<tipo>_info
									//representando o valor constante associado ao atributo
}

constantvalue_index
//CONSTANT_<tipo>_info do tipo apropriado para a variável estática associada
long 								- CONSTANT_Long
float 								- CONSTANT_Float
double 								- CONSTANT_Double
int, short, char, byte, boolean 	- CONSTANT_Integer
String 								- CONSTANT_String

Code
- utilizado em method_info
- tam variável
- um code por método
	- método não nativo: contém o código JVM e info do método, método de iniciação de instância, classe ou interface
	- método nativo ou abstrato: não possui esse atributo
- toda JVM deve reconhecer o atributo Code

Code_attribute 
{      
	u2 attribute_name_index;		//IVCP
									//CUtf8 representando a string Code
	u4 attribute_length;      		//# de bytes do atributo, exceto esses 6 bytes iniciais
	u2 max_stack; 					//profundidade max da pilha de operandos durante a execução desse método
	u2 max_locals;  				//# de variáveis locais (incluindo parâmetros) do seu vetor de variáveis locais
	u4 code_length;   				//# de bytes no seu array code (deve ser maior que zero)
	u1 code[code_length]; 			//bytecodes da JVM que implementam o código desse método
	u2 exception_table_length;      //# de entradas na tabela exception_table
	
	exception_table [exception_table_length];	//cada entrada descreve um manipulador das exceções que podem ocorrer
	{ 											//no código JVM contido no array code
		u2 start_pc;				//manipulador ativo para índices para code
		u2 end_pc;  
		u2 handler_pc; 				//indice para code indicando o bytecode inicial do manipulador
		u2 catch_type;   			//se não nulo - cláusula catch de um comando try
									//se nulo - cláusula finally de um comando try
	}
	u2 attributes_count;      		//# de atributos associados ao code de um método
	attribute_info attributes[attributes_count];//# qualquer de atributos opcionais
												//LineNumberTable - associa posições no array code com linhas do arquivo fonte
												//LocalVariableTable - Utilizado por debuggers para determinar o valor de uma variável local durante a execução
} 

Localização do manipulador de exceções pela JVM
-busca no método corrente 						- desvia a execução para handler_pc
-senão método corrente terminado abruptamente	- pilha de operandos e vetor de variáveis locais são descartados
-frame é desempilhado e o controle é passado para o método chamador do método corrente
-exceção é relançada para o método chamador que se torna o corrente
-esse processo continua até encontrar um manipulador ou o final da cadeia dos métodos chamadores
-Se nenhum manipulador adequado for encontrado, a execução da thread onde a exceção foi lançada é terminada

Deprecated
-Opcional, tamanho fixo: tabela attributes de estrutura ClassFile, field_info ou method_info
-informa ao usuário que a classe, interface, campo ou método está superado
Deprecated_attribute 
{
	u2 attribute_name_index;		//índice válido para a tabela constant_pool 
									//CONSTANT_Utf8_info representando a string "Deprecated".
	u4 attribute_length;			//valor fixo em zero
}

Exceptions
-Utilizado em estrutura method_info 
-Atributo de tamanho variável
-um atributo Exceptions por método
-Indica quais exceções verificadas o método pode lançar
Exceptions_attribute 
{
	u2 attribute_name_index;							//índice válido para a tabela constant_pool
														//CONSTANT_Utf8_info representando a string "Exceptions".
	u4 attribute_length;								//# de bytes desse atributo, exceto esses 6 bytes iniciais. 
	u2 number_of_exceptions;							//Número de entradas na tabela exception_index_table
	u2 exception_index_table[number_of_exceptions];		//índice válido para a tabela constant_pool 
														//CONSTANT_Class_info representando um tipo de classe de exceção que o método pode lançar
														//Por exemplo, classe ou subclasse de RuntimeException, Error ou Throwable
}

InnerClasses
-Atributo de tamanho variável utilizado na tabela attributes de estrutura ClassFile
-Pool de constantes de uma classe ou interface refere a classe ou interface C que não é membro de um pacote
-sua estrutura ClassFile deve conter exatamente um atributo InnerClasses na sua tabela attributes
InnerClasses_attribute 
{
	u2 attribute_name_index;			//é índice válido para a tabela constant_pool 
										//CONSTANT_Utf8_info representando a string "InnerClasses"
	u4 attribute_length;				//número de bytes desse atributo, exceto esses 6 bytes iniciais.
	u2 number_of_classes;				//Número de entradas na tabela classes
	
	classes [number_of_classes];		//um membro de uma classe ou interface aninhada terá o atributo InnerClasses para toda classe envolvente e para cada membro imediato.
	{ 
		u2 inner_class_info_index;		//índice válido para a tabela constant_pool 
										//CONSTANT_Class_info representando a classe C. Os outros itens dão informação sobre a classe ou interface C.
		u2 outer_class_info_index;		//Zero (se C não é um membro) ou índice válido da tabela  constant_pool 
										//CONSTANT_Class_info representando a classe ou interface da qual C é um membro.
		u2 inner_name_index;			//Zero (se C is anônima) ou índice válido da tabela constant_pool 
										//CONSTANT_Utf8_info representando nome simples original de C, como no fonte do qual esse arquivo foi compilado.
		u2 inner_class_access_flags;	//Máscara de bits especificando permissões de acesso e propriedades da classe ou interface C declaradas no fonte.
	} 
}

Atributo InnerClasses
-ACC_PUBLIC		0x0001 	Marcada ou implicitamente public no fonte.
-ACC_PRIVATE	0x0002 	Marcada private no fonte.
-ACC_PROTECTED	0x0004 	Marcada protected no fonte.
-ACC_STATIC		0x0008 	Marcada ou implicitamente static no fonte.
-ACC_FINAL		0x0010 	Marcada final no fonte. Não pode ser estendida.
-ACC_INTERFACE	0x0200 	É uma interface no fonte.
-ACC_ABSTRACT	0x0400 	Marcada abstract no fonte. Possui apenas métodos abstratos. Não pode ser instanciada.

LineNumberTable 
-Opcional, tamanho variável: tabela attributes do atributo Code
-permite a debugger determinar que posições no array code correspondem a uma dada linha do arquivo fonte 
-relação 1-1 entre um atributo LineNumberTable e um linha no fonte original não é requerida.
-múltiplos atributos LineNumberTable juntos podem representar uma linha
LineNumberTable_attribute 
{  
	u2 attribute_name_index;						//índice válido para a tabela constant_pool
													//CONSTANT_Utf8_info representando a string “LineNumberTable”.
	u4 attribute_length;    						//# de bytes desse atributo, exceto esses 6 bytes iniciais.
	u2 line_number_table_length;					//# de entradas no array line_number_table
	
	line_number_table [line_number_table_length]; 
	{ 
		u2 start_pc;								//índice para o array code correspondendo ao código que inicia uma nova linha no arquivo fonte original  
		u2 line_number; 							//número dessa linha no arquivo fonte
	} 
}

LocalVariableTable
-Opcional, tamanho variável: tabela attributes do atributo Code
-permite a debugger determinar o valor de uma dada variável local, durante a execução de um método 
-No máximo, um atributo LocalVariableTable por variável local em Code
LocalVariableTable_attribute 
{
	u2 attribute_name_index;								//é índice válido para a tabela constant_pool 
															//CONSTANT_Utf8_info representando a string “LocalVariableTable”
	u4 attribute_length;									//número de bytes desse atributo, exceto esses 6 bytes iniciais.
	u2 local_variable_table_length;							//número de entradas no array local_variable_table
	
	local_variable_table [local_variable_table_length];		//uma faixa de índices no array code na qual uma dada variável local mantém o mesmo valor. 
															//o índice dessa variável local no array de variáveis locais do frame corrente no qual ela pode ser encontrada. 
	{	u2 start_pc;										//offsets de code
		u2 length;											//índices válidos em code que apontam para opcode da JVM
		u2 name_index;										//índice válido para a tabela constant_pool
															//CONSTANT_Utf8_info representando um nome válido de variável local armazenado como um nome simples 
		u2 descriptor_index;								//índice válido para a tabela constant_pool
															//CONSTANT_Utf8_info representando um descritor de campo válido com o tipo da variável local no programa fonte
		u2 index;											//índice no array de variáveis locais do frame corrente correspondendo à variável local em questão
															//se do tipo double ou long a variável ocupa as posições index e index+1
	} 
}

SourceFile
-Opcional, tamanho fixo: tabela attributes de estrutura ClassFile
-nome (relativo) do fonte a partir do qual a classe foi compilada.
-apenas um atributo SourceFile pode aparecer por ClassFile
SourceFile_attribute 
{ 
	u2 attribute_name_index; 		//índice válido para a tabela constant_pool 
									//CONSTANT_Utf8_info representando a string “SourceFile”.
	u4 attribute_length;			//assume sempre o valor 2
	u2 sourcefile_index;			//índice válido para a tabela constant_pool 
									//CONSTANT_Utf8_info representando uma string com o nome do fonte.
} 

//------------------------------------------------------------------------------------------//

'fopen'
FILE* fopen(const char* filename, const char* mode); 
"r" text reading 
"w" text writing 
"a" text append 
"r+" text update (reading and writing) 
"w+" text update, discarding previous content (if any) 
"a+" text append, reading, and writing at end 
"b" after the first character for binary files.

'Lendo .class'
Formato big-endian 
static u2 u2Read(FILE *fd) 
{
	u2 toReturn = getc(fd);
	toReturn = (toReturn << 8) | (getc(fd));
	return toReturn;
}
Não use nessa forma: transforme em uma macro

'Estrutura ClassFile'
ClassFile 
{      
	u4 			magic;      
	u2 			minor_version;      
	u2 			major_version;      
	u2 			constant_pool_count;      
	cp_info 		constant_pool [constant_pool_count-1];
	u2 			access_flags;      
	u2 			this_class;      
	u2 			super_class;      
	u2 			interfaces_count;      
	u2 			interfaces [interfaces_count];      
	u2 			fields_count;      
	field_info 	fields [fields_count];
	u2 			methods_count;     
	method_info 	methods [methods_count];      
	u2 			attributes_count;      
	attribute_info 	attributes [attributes_count];     
} 

'Lendo .class'
ClassFile *cf = (ClassFile *) malloc(sizeof(Class));
cf->magic = u4Read(fd); 
cf->minor_version = u2Read(fd);
cf->major_version = u2Read(fd);
cf->constant_pool_count = u2Read(fd); 

'Pool de Constantes'
-Cada entrada em constant_pool tem a forma
cp_info 
{
    u1 tag;      
	u1 info[ ]; 
}  
O byte de tag define o tipo da informação em cp_info

'Tipos Válidos de Tags '
CONSTANT_Class 					7
CONSTANT_Fieldref 				9
CONSTANT_Methodref 				10
CONSTANT_InterfaceMethodref 	11
CONSTANT_String 				8
CONSTANT_Integer 				3
CONSTANT_Float  				4
CONSTANT_Long 					5
CONSTANT_Double  				6
CONSTANT_NameAndType 			12
CONSTANT_Utf8  					1

'Exemplos de estruturas CONSTANT'
CONSTANT_Class_info {      
	u1 tag;      				// valor 7
	u2 name_index; 
} 
CONSTANT_Fieldref_info {      
	u1 tag;      				// valor 9
	u2 class_index; 
	u2 name_and_type_index;
} 
CONSTANT_NameAndType_info {      
	u1 tag;      				// valor 12
	u2 name_index; 
	u2 descriptor_index;
} 

'Lendo constant_pool'
typedef struct 
{
	u1 tag;
	union 
	{
   		struct 
   		{
      		u2 name_index;
		} Class;
		
		struct 
		{
		      u2 class_index;
		      u2 name_and_type_index;
		} Fieldref;
		...

'Lendo constant_pool'
Constant *constantPool = (Constant*) malloc(…
Constant *cp;
for (cp = constantPool; cp < constantPool + count - 1; cp++) 
{
		cp->tag = u1Read(cf);
		switch (cp->tag) 
		{
			 case CONSTANT_Class:
			    cp->u.Class.name_index = u2Read(fd);
			    break;
			 case CONSTANT_Fieldref:
			    cp->u.Fieldref.class_index = u2Read(fd); 
			    cp->u.Fieldref.name_and_type_index = u2Read(fd);
			    break;


