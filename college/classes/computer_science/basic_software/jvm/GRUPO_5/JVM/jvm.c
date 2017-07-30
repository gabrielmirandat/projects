#include "interpreter.h"

// função startJVM
// https://docs.oracle.com/javase/specs/jvms/se6/html/Concepts.doc.html#16491
// https://docs.oracle.com/javase/specs/jvms/se6/html/Concepts.doc.html#19042
void startJVM(char * nomeDoArquivoDeClasse, int num_args, char ** args)
{

	JVM	* jvm;
	jvm = (JVM *) malloc(sizeof(JVM)); // FREE OK
	jvm->method_area_jvm = NULL;
	jvm->thread_jvm = NULL;
	jvm->heap_jvm = (HEAP *) malloc(sizeof(HEAP)); // FREE OK
	(jvm->heap_jvm)->objects = NULL;
	(jvm->heap_jvm)->arrays = NULL;

	CLASS_DATA * dados_classe_principal;

//Caso tenha apenas um parâmetro após o nome do arquivo e da classe, esse parâmetro será considerado o tipo de saida desejado
/////////////LeitorExibidor/////////////
	if(num_args == 1)
	{
		FILE * arquivoSaidaJVM;
		if(strcmp(args[0], "t") == 0)
		{
			arquivoSaidaJVM = stdout;
		}else if(strcmp(args[0], "a") == 0)
		{
			arquivoSaidaJVM = fopen("arquivoSaidaJVM.txt", "w");
		}		
		
		FILE * arquivoBinario;
		if(strstr(nomeDoArquivoDeClasse, ".class\0"))
		{
			arquivoBinario = fopen(nomeDoArquivoDeClasse, "rb");
		}
		else
		{
			arquivoBinario = fopen(strcat(nomeDoArquivoDeClasse, ".class"), "rb");
		}

		ClassFile	* cf	= obtainClassFile(arquivoBinario);
		showClassFile(cf, arquivoSaidaJVM);
		freeClassFile(cf);
		fclose(arquivoBinario);
		exitJVM(jvm);
		exit(0);		
	}

//Caso tenha zero parâmetros após o nome do arquivo e da classe
/////////////Executor/////////////
	if(strstr(nomeDoArquivoDeClasse, ".class\0"))
	{
		loadClass(nomeDoArquivoDeClasse, &dados_classe_principal, NULL, jvm);
	}
	else{
		loadClass(strcat(nomeDoArquivoDeClasse, ".class"), &dados_classe_principal, NULL, jvm);
	}

	linkClass(dados_classe_principal, jvm);

	// INICIA THREAD PRINCIPAL
	THREAD * main_thread = (THREAD *) malloc(sizeof(THREAD));
	main_thread->program_counter = NULL;
	main_thread->jvm_stack = NULL;
	main_thread->next = NULL;
	jvm->thread_jvm = main_thread;

	initializeClass(dados_classe_principal, jvm, main_thread);

	if(dados_classe_principal->modifiers & ACC_ABSTRACT)
	{
		puts("ERROR: method 'main' not found.");
		exitJVM(jvm);
		exit(EXIT_FAILURE);
	}

	OBJECT * string = NULL;
	ARRAY * string_array = NULL;
	
	// se num_args eh dois ou mais
	if(num_args)
	{
	 	string_array = (ARRAY *) malloc(sizeof(ARRAY));	// FREE OK
	 	string_array->next = (jvm->heap_jvm)->arrays;
		(jvm->heap_jvm)->arrays = string_array;
		string_array->count = (int32_t) num_args;
		
		if(string_array->count){
			string_array->entry = (DATA_TYPES *) malloc(string_array->count * sizeof(DATA_TYPES));
		}
		
		for(uint16_t i = 0; i < string_array->count; i++){
			string = (OBJECT *) malloc(sizeof(OBJECT));
			string->next = (jvm->heap_jvm)->objects;
			(jvm->heap_jvm)->objects = string;
			string->instance_variables = NULL;
			string->instance_variables = (VARIABLE *) malloc(sizeof(VARIABLE));
			(string->instance_variables)->value.u.InstanceReference.reference = (OBJECT *) args[i];
			(string_array->entry[i]).u.InstanceReference.reference = string;
		}
	}	
	
	executeMethod("main", "([Ljava/lang/String;)V", dados_classe_principal, jvm, main_thread, NULL, 1, (uint32_t *) &string_array);
	
	exitJVM(jvm);
}// fim da função startJVM

// função loadClass
void loadClass(char * nomeDoArquivoDeClasse, CLASS_DATA ** cd, CLASS_DATA * carregadorClasse, JVM * jvm)
{

/*
The loading process consists of three basic activities. To load a type, the Java virtual machine must:
O processo de carregar consiste em 3 atividades básicas, para carregar um tipo a JVM deve:

- given the type's fully qualified name (char * nomeDoArquivoDeClasse), produce a stream of binary data (ClassFile ** cf) that represents the type - OK
Nomear o tipo, produzir um stream de binários que representem o tipo

- parse the stream of binary data into internal data structures in the method area - OK

- create an instance of class java.lang.Class that represents the type - OK
Criar uma instancia da classe que represente o tipo
*/
	FILE * arquivoBinarioDeClasse;
	ClassFile	* cf;
	
	//	printf("\npasseo aqui . ");
	//Caso o nome do arquivo esteja em .class
	//INUTIL, VERIFICADO ANTES DE CHAMAR.
	//Abrir o arquivo binário da classe
	if(!strstr(nomeDoArquivoDeClasse, ".class\0"))
	{
		char * nomeDaClasseComPontoClass = (char *) malloc((strlen(nomeDoArquivoDeClasse) + 7) * sizeof(char));	// FREE OK
		strcpy(nomeDaClasseComPontoClass, nomeDoArquivoDeClasse);
		strcat(nomeDaClasseComPontoClass, ".class");
		arquivoBinarioDeClasse = fopen(nomeDaClasseComPontoClass, "rb");
		free(nomeDaClasseComPontoClass);
	}
	else
	{
		arquivoBinarioDeClasse = fopen(nomeDoArquivoDeClasse, "rb");
	}
	
	// printf("%p - %s\n", arquivoBinarioDeClasse, nomeDoArquivoDeClasse); 
	if(!arquivoBinarioDeClasse)
	{
		puts("\nClassNotFoundException\nCoco\n");
		exitJVM(jvm);
		exit(EXIT_FAILURE);
	}
	else
	{

		cf = obtainClassFile(arquivoBinarioDeClasse);

	}
	fclose(arquivoBinarioDeClasse);
	(*cd) = (CLASS_DATA *) malloc(sizeof(CLASS_DATA));
	constant_pool_info	* cp_aux = cf->constant_pool + cf->this_class - 1;
	(*cd)->class_name = cf->constant_pool + cp_aux->u.Class.name_index - 1;
	(*cd)->next = jvm->method_area_jvm;
	jvm->method_area_jvm = (*cd);
	(*cd)->class_variables = NULL;
	(*cd)->instance_class = NULL;


	if(!carregadorClasse){
		(*cd)->class_loader_reference = (*cd);
	}
	else{
		(*cd)->class_loader_reference = carregadorClasse;
	}
	(*cd)->classfile = cf;
	(*cd)->modifiers = ((*cd)->classfile)->access_flags;
	(*cd)->runtime_constant_pool = cf->constant_pool;

	// armazena informações dos fields
	if(cf->fields_count){
		(*cd)->field_data = (FIELD_DATA *) malloc(cf->fields_count * sizeof(FIELD_DATA));
		for(uint16_t i = 0; i < cf->fields_count; i++){
			((*cd)->field_data + i)->field_name = cf->constant_pool + (cf->fields + i)->name_index - 1;
			((*cd)->field_data + i)->field_descriptor = cf->constant_pool + (cf->fields + i)->descriptor_index - 1;
			((*cd)->field_data + i)->modifiers = (cf->fields + i)->access_flags;
			((*cd)->field_data + i)->info = (cf->fields + i);
			if(! isFieldDescriptor(((*cd)->field_data + i)->field_descriptor, 0)){
				puts("VerifyError: field descriptor");
				exitJVM(jvm);
				exit(EXIT_FAILURE);
			}
			((*cd)->field_data + i)->field_type = *(((*cd)->field_data + i)->field_name)->u.Utf8.bytes;
		}
	}
	// armazena informações dos métodos
	if(cf->methods_count){
		(*cd)->method_data = (METHOD_DATA *) malloc(cf->methods_count * sizeof(METHOD_DATA));
		for(uint16_t i = 0; i < cf->methods_count; i++){
			((*cd)->method_data + i)->method_name = cf->constant_pool + (cf->methods + i)->name_index - 1;
			((*cd)->method_data + i)->method_descriptor = cf->constant_pool + (cf->methods + i)->descriptor_index - 1;
			((*cd)->method_data + i)->modifiers = (cf->methods + i)->access_flags;
			((*cd)->method_data + i)->info = (cf->methods + i);
			((*cd)->method_data + i)->CLASS_DATA = (*cd);
	
			if(*(((*cd)->method_data + i)->method_descriptor)->u.Utf8.bytes != '('){
				puts("VerifyError: method descriptor");
				exitJVM(jvm);
				exit(EXIT_FAILURE);
			}
	
			if(! isMethodDescriptor(((*cd)->method_data + i)->method_descriptor, 1)){
				puts("VerifyError: method descriptor");
				exitJVM(jvm);
				exit(EXIT_FAILURE);
			}
	
			if(!(((*cd)->method_data + i)->modifiers & ACC_ABSTRACT) && !(((*cd)->method_data + i)->modifiers & ACC_NATIVE)){
				attribute_info	* code_attr = getCodeAttribute((*cd)->method_data + i, *cd);
				if(!code_attr){
					puts("VerifyError: No code attribute");
					exitJVM(jvm);
					exit(EXIT_FAILURE);
				}
				((*cd)->method_data + i)->code_length = code_attr->u.Code.code_length;
				((*cd)->method_data + i)->bytecodes = code_attr->u.Code.code;
				((*cd)->method_data + i)->stack_size = code_attr->u.Code.max_stack;
				((*cd)->method_data + i)->locals_size = code_attr->u.Code.max_locals;
				((*cd)->method_data + i)->exception_table_length = code_attr->u.Code.exception_table_length;
				((*cd)->method_data + i)->exception_table = code_attr->u.Code.exception_table;
			}
		}
	}
}// fim da função loadClass



/*==========================================*/
// função linkClass
void	linkClass	(CLASS_DATA * cd, JVM * jvm){
	verifyLink(cd, jvm);
	prepareLink(cd, jvm);
}// fim da função linkClass

/*==========================================*/
// função verifyLink
void	verifyLink(CLASS_DATA * cd, JVM * jvm){
/*	A IMPLEMENTAR
Verification: ensuring the correctness of the imported type
https://www.artima.com/insidejvm/ed2/security3.html
Structural Checks on The ClassFile
- magic number = 0xCAFEBABE = OK (loadClass)
- major/minor version supported = <= java 1.2 = OK (loadClass)
- tipo e tamanho dos componentes do ClassFile (bytes truncados ou extras) = OK (loadClass)
Semantic Checks on the Type Data
- verificar se um componente do ClassFile está bem formado. (exemplo: descritor de um método); = OK (verifyClasseDeArquivo)
- verificações de classe:
-- toda classe, exceto Object, tem q ter uma superclasse  = OK (verifyClasseDeArquivo) = TESTAR
-- classe final não é herdada; = OK (verifyFinal) = TESTAR
-- método final não é sobrecarregado = OK (verifyFinal) = TESTAR
- entradas válidas da Constant Pool (índices referem-se ao tipo correto) = OK (verifyConstantPool)
- verificação de regras da linguagem java que deveriam ter sido vistas em tempo de compilação ????
Bytecode Verifier: FALTANDO
- nao importa o caminho de execução, ao chegar num certo bytecode, a operand_stack tem o mesmo numero de itens e mesmo tipo;
- variavel local nao pode ser acessada antes de conter um valor apropriado.
- atribuição de valores apropriados à fields de classe
- metodos da classe sao sempre invocados com o correto numero e tipo de argumentos.
- verifica que cada opcode é valido, que tem operandos válidos
- cada opcode tem operandos válidos na pilha e o no vetor de variaveis locais
*/
	verifyClassfile(cd->classfile);
	verifySuperFinal(cd->classfile, jvm);
	verifyOverrideMethodFinal(cd->classfile, jvm);
}// fim da função verifyLink

/*==========================================*/
// função prepareLink
void	prepareLink(CLASS_DATA * cd, JVM * jvm){
/*
Preparation: allocating memory for class variables and initializing the memory to default values
*/

	if(!(cd->classfile)->fields_count){
		cd->class_variables = NULL;
	}
	else{
		for(uint16_t i = 0; i < (cd->classfile)->fields_count; i++){
			VARIABLE	* var = (VARIABLE *) malloc(sizeof(VARIABLE));
			var->field_reference = cd->field_data + i;
			(cd->field_data + i)->var = var;

			uint16_t	descriptor_index = ((cd->field_data + i)->info)->descriptor_index;
			(var->value).type = (cd->runtime_constant_pool + descriptor_index - 1)->u.Utf8.bytes[0];
			switch((var->value).type){
				case	BOOLEAN:
					(var->value).u.Boolean.boolean = 0;
					break;
				case	BYTE:
					(var->value).u.Byte.byte = 0;
					break;
				case	CHAR:
					(var->value).u.Char.char_ = 0;
					break;
				case	DOUBLE:
					(var->value).u.Double.high_bytes = 0;
					(var->value).u.Double.low_bytes = 0;
					break;
				case	FLOAT:
					(var->value).u.Float.float_ = 0;
					break;
				case	INT:
					(var->value).u.Integer.integer = 0;
					break;
				case	LONG:
					(var->value).u.Long.high_bytes = 0;
					(var->value).u.Long.low_bytes = 0;
					break;
				case	REF_INST:
					(var->value).u.InstanceReference.reference = NULL;
					break;
				case	SHORT:
					(var->value).u.Short.short_ = 0;
					break;
				case	REF_ARRAY:
					(var->value).u.ArrayReference.reference = NULL;
					break;
				default:
					puts("VerifyError: Unknown type");
					exitJVM(jvm);
					exit(EXIT_FAILURE);
			}
			uint16_t	access_flags = (cd->field_data + i)->modifiers;
				if((access_flags & ACC_STATIC) || ((cd->classfile)->access_flags & ACC_INTERFACE)){
					var->next = cd->class_variables;
					cd->class_variables = var;
				}
				else{
					free(var);
				}
		}
	}
}// fim da função prepareLink
/*==========================================*/
// função resolveLink
void	resolveLink(ClassFile * cf, JVM * jvm){
/*	A IMPLEMENTAR = EM TEMPO DE EXECUÇÃO
Verification of Symbolic References
ao executar bytecodes e carregar ClasseDeArquivos
Resolution: transforming symbolic references from the type into direct references.
*/
}// fim da função resolveLink

/*==========================================*/
// função getClassName
char	*	getClassName(CLASS_DATA * cd){
 	constant_pool_info	* cp_aux = cd->class_name;
 	char	* class_name = (char *) cp_aux->u.Utf8.bytes;
 	class_name[cp_aux->u.Utf8.length] = '\0';
 	return	class_name;
 }

 /*==========================================*/
// função getSuperClass
CLASS_DATA	* getSuperClass(ClassFile * cf, JVM * jvm){
	if(cf->super_class){
		constant_pool_info	* cp_aux = cf->constant_pool + cf->super_class - 1;
		cp_aux = cf->constant_pool + cp_aux->u.Class.name_index - 1;
		char	* super_name = (char *) cp_aux->u.Utf8.bytes;
		super_name[cp_aux->u.Utf8.length] = '\0';
		if(strcmp(super_name, "java/lang/Object")){
			CLASS_DATA	* cd = jvm->method_area_jvm;
/*			printf("length = %" PRIuint8_t6 "\n", (cd->class_name)->u.Utf8.length);*/
			while(cd){
				char	* name = (char *) (cd->class_name)->u.Utf8.bytes;
				name[(cd->class_name)->u.Utf8.length] = '\0';
				if(!strcmp(super_name, name)){
					return	cd;
				}
				else{
					cd = cd->next;
				}
			}
		}
	}
	return	NULL;
}// fim da função getSuperClass

bool		isSuperClass(CLASS_DATA * super_cd, CLASS_DATA * cd, JVM * jvm){
	CLASS_DATA	* super = cd;
	while(super){
		super = getSuperClass(super->classfile, jvm);
		if(super == super_cd){
			return	true;
		}
	}
	return	false;
}

/*==========================================*/
// funcao getClass
CLASS_DATA	* getClass(constant_pool_info * cp_class_name, JVM * jvm){
	char	* class_name = (char *) cp_class_name->u.Utf8.bytes;
	class_name[cp_class_name->u.Utf8.length] = '\0';

	CLASS_DATA	* cd = jvm->method_area_jvm;
	while(cd){
		char	* cd_class_name = getClassName(cd);
		if(!strcmp(class_name, cd_class_name)){
			return	cd;
		}
		else{
			cd = cd->next;
		}
	}
	return	NULL;
}

/*==========================================*/
// funcao getClassVariable
VARIABLE	* getClassVariable(constant_pool_info * cp_field_name, CLASS_DATA * field_class){
	VARIABLE	* cv = field_class->class_variables;

	while(cv){
		char	*string1 = (char *) cp_field_name->u.Utf8.bytes;
		string1[cp_field_name->u.Utf8.length] = '\0';

		char	*string2 = (char *) ((cv->field_reference)->field_name)->u.Utf8.bytes;
		string2[((cv->field_reference)->field_name)->u.Utf8.length] = '\0';
		if(!strcmp(string1, string2)){
			return	cv;
		}
		else{
			cv = cv->next;
		}
	}
	return	NULL;

}

/*==========================================*/
// funcao getInstanceVariable
VARIABLE	* getInstanceVariable(constant_pool_info * cp_field_name, OBJECT * objectref){
	VARIABLE	* iv = objectref->instance_variables;

	while(iv){
		FIELD_DATA	* fr = iv->field_reference;

		char	*string1 = (char *) cp_field_name->u.Utf8.bytes;
		string1[cp_field_name->u.Utf8.length] = '\0';

		char	*string2 = (char *) (fr->field_name)->u.Utf8.bytes;
		string2[((iv->field_reference)->field_name)->u.Utf8.length] = '\0';
		if(!strcmp(string1, string2)){
			return	iv;
		}
		else{
			iv = iv->next;
		}
	}
	
	
	return	NULL;
}

/*==========================================*/
// função initializeClass
void	initializeClass(CLASS_DATA * cd, JVM * jvm, THREAD * thread){
/*	A IMPLEMENTAR
Initialization of a class consists of two steps:

Initializing the class's direct superclass (if any), if the direct superclass hasn't already been initialized
Executing the class's class initialization method, if it has one
*/

	if((cd->classfile)->super_class){
		constant_pool_info	* cp_aux = (cd->classfile)->constant_pool + (cd->classfile)->super_class - 1;
		cp_aux = (cd->classfile)->constant_pool + cp_aux->u.Class.name_index - 1;
		char	* super_classe_name = (char *) cp_aux->u.Utf8.bytes;
		super_classe_name[cp_aux->u.Utf8.length] = '\0';
		CLASS_DATA	* cd_super;
		
		if(!(cd_super = getClass(cp_aux, jvm))){
			loadClass(super_classe_name, &cd_super, cd, jvm);
		}
		linkClass(cd_super, jvm);
		initializeClass(cd_super, jvm, thread);
	}
	executeMethod("<clinit>", "()V", cd, jvm, thread, NULL, 0, NULL);
}// fim da função initializeClass

/*==========================================*/
// função getMethod
METHOD_DATA	* getMethod(char * method_name, char * method_descriptor, CLASS_DATA * cd, JVM * jvm){
	char	* name;
	char	* descriptor;
	
	CLASS_DATA * super_class = cd;
	while(super_class){
		for(uint16_t	i = 0; i < (super_class->classfile)->methods_count; i++){
			name = (char *) ((super_class->method_data + i)->method_name)->u.Utf8.bytes;
			name[((super_class->method_data + i)->method_name)->u.Utf8.length] = '\0';
	
			descriptor = (char *) ((super_class->method_data + i)->method_descriptor)->u.Utf8.bytes;
			descriptor[((super_class->method_data + i)->method_descriptor)->u.Utf8.length] = '\0';
	
			if(!strcmp(method_name, name) && !strcmp(method_descriptor, descriptor)){
				return	(super_class->method_data + i);
			}
		}
		super_class = getSuperClass(super_class->classfile, jvm);
	}
	return	NULL;
}// fim da função getMethod

/*==========================================*/
// função getCodeAttribute
attribute_info	* getCodeAttribute(METHOD_DATA * method, CLASS_DATA * cd){
	constant_pool_info	* cp_aux;
	char	* attribute_name;
	for(uint16_t	i = 0; i < (method->info)->attributes_count; i++){
		cp_aux = (cd->classfile)->constant_pool + ((method->info)->attributes + i)->attribute_name_index - 1;
		attribute_name = (char *) cp_aux->u.Utf8.bytes;
		attribute_name[cp_aux->u.Utf8.length] = '\0';
		if(!strcmp("Code", attribute_name)){
			return	((method->info)->attributes + i);
		}
	}
	return	NULL;
}// fim da função getCodeAttribute

/*==========================================*/
// função execute
void executeMethod(char * method_name, char * method_descriptor, CLASS_DATA * cd, JVM * jvm, THREAD * thread, void * this, uint16_t nargs, uint32_t * args){

	METHOD_DATA	* method = getMethod(method_name, method_descriptor, cd, jvm);
	if(method)
	{
		if(method->modifiers & ACC_ABSTRACT)
		{
			puts("ERROR: IllegalAccessError");
			exitJVM(jvm);
			exit(EXIT_FAILURE);
		}
/*		attribute_info	* code_attr = getCodeAttribute(method, cd);*/

/*		if(code_attr){*/
		if(method->bytecodes)
		{
			// CRIA NOVO FRAME PRO MÉTODO
			FRAME	* frame = (FRAME *) malloc(sizeof(FRAME));
			frame->local_variables = (uint32_t *) malloc(method->locals_size * sizeof(uint32_t));

			uint16_t index = 0;

			if(!(method->modifiers & ACC_STATIC))
			{
				frame->local_variables[0] = (uint32_t)(uintptr_t) this;
				index = 1;
			}

			if((index + nargs) > method->locals_size)
			{
				puts("LocalsOutofBoundsError");
				exitJVM(jvm);
				exit(EXIT_FAILURE);
				
			}
			
			for(uint16_t pos_arg = 0; pos_arg < nargs; pos_arg++, index++)
			{
				frame->local_variables[index] = args[pos_arg];
			}

			if(args)
			{
				if(strcmp(method_name, "main") || strcmp(method_descriptor, "([Ljava/lang/String;)V"))
					free(args);
			
			}

			frame->operand_stack = NULL;
			frame->current_constant_pool = cd->runtime_constant_pool;
			frame->next = thread->jvm_stack;
			thread->jvm_stack = frame;

			// CHAMA O INTERPRETADOR
			interpreter(method, thread, jvm);
		}
		else
		{
			puts("ERROR: non-abstract method without code attribute.");
			exitJVM(jvm);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if(strcmp(method_name, "<clinit>"))
		{
			printf("método %s não encontrado.\n", method_name);
			exitJVM(jvm);
			exit(EXIT_FAILURE);
		}
	}
}// fim da função execute

/*==========================================*/
// função unloadClass
void	unloadClass(CLASS_DATA * cd, JVM * jvm){
/*	A IMPLEMENTAR
https://docs.oracle.com/javase/specs/jvms/se6/html/Concepts.doc.html#19175
*/
/*	free(cd);*/
}// fim da função unloadClass
/*==========================================*/
// função exitJVM
void	exitJVM(JVM * jvm){
	freeThreads(jvm->thread_jvm);
	freeHeap(jvm->heap_jvm);
	freeMethodArea(jvm->method_area_jvm);
	free(jvm);
}// fim da funçao exitJVM
/*==========================================*/

void	pushOperand(uint32_t word, FRAME * frame){
	OPERAND_STACK	* aux = (OPERAND_STACK *) malloc(sizeof(OPERAND_STACK));	// FREE OK

	aux->value = word;
	aux->next = frame->operand_stack;
	frame->operand_stack = aux;	
	
}

uint32_t	popOperand(FRAME * frame){
	uint32_t	word;
	if(frame->operand_stack){
		OPERAND_STACK	* aux = frame->operand_stack;
		frame->operand_stack = aux->next;
		word = aux->value;
		
		free(aux);

	}
	else{
		puts("StackUnderflowError");
		exit(EXIT_FAILURE);
	}
	return	word;
}

void		freeFrame(FRAME * frame){
	freeOperandStack(frame);
	free(frame->local_variables);
	free(frame);
}

void		freeOperandStack(FRAME * frame){
	OPERAND_STACK	* aux = frame->operand_stack;
	while(aux){
		frame->operand_stack = aux->next;
		free(aux);
		aux = frame->operand_stack;
	}
}

void		freeThreads(THREAD * thread_jvm){
	THREAD	* aux = thread_jvm;
	while(aux){
		thread_jvm = aux->next;
		freeJvmStack(aux->jvm_stack);
		free(aux);
		aux = thread_jvm;
	}
}
void		freeJvmStack(FRAME * jvm_stack){
	FRAME	* aux = jvm_stack;
	while(aux){
		jvm_stack = aux->next;
		freeFrame(aux);
		aux = jvm_stack;
	}
}

void		freeMethodArea(CLASS_DATA * method_area_jvm){
	CLASS_DATA	* aux = method_area_jvm;
	while(aux){
		method_area_jvm = aux->next;
		freeClassData(aux);
		aux = method_area_jvm;
	}
}
void		freeClassData(CLASS_DATA * CLASS_DATA){
	if(CLASS_DATA->classfile){
		if((CLASS_DATA->classfile)->fields_count){
			free(CLASS_DATA->field_data);
		}
		if((CLASS_DATA->classfile)->methods_count){
			free(CLASS_DATA->method_data);
		}
	
		freeClassFile(CLASS_DATA->classfile);
	}
	
	if(CLASS_DATA->class_variables){
		freeVariables(CLASS_DATA->class_variables);
	}

	free(CLASS_DATA);
}

void		freeVariables(VARIABLE * vars){
	VARIABLE	* aux = vars;
	while(aux){
		vars = aux->next;
		free(aux);
		aux = vars;
	}
}

void		freeHeap(HEAP * heap_jvm){
	if(heap_jvm->objects){
		freeObjects(heap_jvm->objects);
	}
	if(heap_jvm->arrays){
		freeArrays(heap_jvm->arrays);
	}
	free(heap_jvm);
}
void		freeObjects(OBJECT * objects){
	OBJECT	* aux = objects;
	while(aux){
		objects = aux->next;
		if(aux->instance_variables){
			freeVariables(aux->instance_variables);
		}
		free(aux);
		aux = objects;
	}
}

void		freeArrays(ARRAY * arrays){
	ARRAY	* aux = arrays;
	while(aux){
		arrays = aux->next;
		free(aux->entry);
		free(aux);
		aux = arrays;
	}
}

