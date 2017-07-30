#include "interpreter.h"

/*==========================================*/

//	MÉTODOS

/*==========================================*/

// função iniciar_jvm
void	iniciar_jvm(char * nomeDoArquivoDeClasse, int num_args, char ** args){
/*
https://docs.oracle.com/javase/specs/jvms/se6/html/Concepts.doc.html#16491
https://docs.oracle.com/javase/specs/jvms/se6/html/Concepts.doc.html#19042
*/


	JVM	* jvm;
	jvm = (JVM *) malloc(sizeof(JVM)); // FREE OK
	jvm->method_area_jvm = NULL;
	jvm->thread_jvm = NULL;
	jvm->heap_jvm = (HEAP_AREA *) malloc(sizeof(HEAP_AREA)); // FREE OK
	(jvm->heap_jvm)->objects = NULL;
	(jvm->heap_jvm)->arrays = NULL;

	DADOS_CLASSE	* dados_classe_principal;

//Caso tenha apenas um parâmetro após o nome do arquivo e da classe, esse parâmetro será considerado o tipo de saida desejado
/////////////LeitorExibidor/////////////
	if(num_args == 1){
		FILE * arquivoSaidaJVM;
		if(strcmp(args[0], "t") == 0){
			arquivoSaidaJVM = stdout;
		}else if(strcmp(args[0], "a") == 0){
			arquivoSaidaJVM = fopen("arquivoSaidaJVM.txt", "w");
		}		
		FILE * arquivoBinario;
		if(strstr(nomeDoArquivoDeClasse, ".class\0")){
			arquivoBinario = fopen(nomeDoArquivoDeClasse, "rb");
		}
		else{
			arquivoBinario = fopen(strcat(nomeDoArquivoDeClasse, ".class"), "rb");
		}
		ClasseDeArquivo	* cf	= loadClasseDeArquivo(arquivoBinario);
		mostrarClasseDeArquivo(cf, arquivoSaidaJVM);
		freeClasseDeArquivo(cf);
		fclose(arquivoBinario);
		jvmExit(jvm);
		exit(0);		
	}

/////////////Executor/////////////
/*	puts(nomeDoArquivoDeClasse);*/
	if(strstr(nomeDoArquivoDeClasse, ".class\0")){
		carregarClasse_01(nomeDoArquivoDeClasse, &dados_classe_principal, NULL, jvm);
	}
	else{
		carregarClasse_01(strcat(nomeDoArquivoDeClasse, ".class"), &dados_classe_principal, NULL, jvm);
	}

	ligadorDeClasse(dados_classe_principal, jvm);

	// INICIA THREAD PRINCIPAL
	THREAD		* main_thread = (THREAD *) malloc(sizeof(THREAD));
	main_thread->program_counter = NULL;
	main_thread->jvm_stack = NULL;
	main_thread->prox = NULL;
	jvm->thread_jvm = main_thread;

	classInitialization(dados_classe_principal, jvm, main_thread);

	if(dados_classe_principal->modifiers & ACC_ABSTRACT){
		puts("ERROR: method 'main' not found.");
		jvmExit(jvm);
		exit(EXIT_FAILURE);
	}

	OBJECT	*	string = NULL;

	ARRAY *		string_array = NULL;
	
	if(num_args ){
		
	 	string_array = (ARRAY *) malloc(sizeof(ARRAY));	// FREE OK
	 	string_array->prox = (jvm->heap_jvm)->arrays;
		(jvm->heap_jvm)->arrays = string_array;
		string_array->count = (int32_t) num_args;
		
		if(string_array->count){
			string_array->entry = (VALUE *) malloc(string_array->count * sizeof(VALUE));
		}
		
		for(uint16_t i = 0; i < string_array->count; i++){
			string = (OBJECT *) malloc(sizeof(OBJECT));
			string->prox = (jvm->heap_jvm)->objects;
			(jvm->heap_jvm)->objects = string;
			string->instance_variables = NULL;
			string->instance_variables = (VARIABLE *) malloc(sizeof(VARIABLE));
			(string->instance_variables)->value.u.InstanceReference.reference = (OBJECT *) args[i];
			(string_array->entry[i]).u.InstanceReference.reference = string;
		}
	}	
	executeMethod("main", "([Ljava/lang/String;)V", dados_classe_principal, jvm, main_thread, NULL, 1, (uint32_t *) &string_array);
	
	jvmExit(jvm);
}// fim da função iniciar_jvm
/*==========================================*/

// função carregarClasse_01
void	carregarClasse_01(char * nomeDoArquivoDeClasse, DADOS_CLASSE ** cd, DADOS_CLASSE * carregadorClasse, JVM * jvm){

/*
The loading process consists of three basic activities. To load a type, the Java virtual machine must:
O processo de carregar consiste em 3 atividades básicas, para carregar um tipo a JVM deve:

- given the type's fully qualified name (char * nomeDoArquivoDeClasse), produce a stream of binary data (ClasseDeArquivo ** cf) that represents the type - OK
Nomear o tipo, produzir um stream de binários que representem o tipo

- parse the stream of binary data into internal data structures in the method area - OK


- create an instance of class java.lang.Class that represents the type - OK
Criar uma instancia da classe que represente o tipo
*/
	FILE	* arquivoBinarioDeClasse;
	ClasseDeArquivo	* cf;
	
//	printf("\npasseo aqui . ");
	//Caso o nome do arquivo esteja em .class
	//INUTIL, VERIFICADO ANTES DE CHAMAR.
	//Abrir o arquivo binário da classe
	if(!strstr(nomeDoArquivoDeClasse, ".class\0")){
		char	* nomeDaClasseComPontoClass = (char *) malloc((strlen(nomeDoArquivoDeClasse) + 7) * sizeof(char));	// FREE OK
		strcpy(nomeDaClasseComPontoClass, nomeDoArquivoDeClasse);
		strcat(nomeDaClasseComPontoClass, ".class");
		arquivoBinarioDeClasse = fopen(nomeDaClasseComPontoClass, "rb");
		free(nomeDaClasseComPontoClass);
	}
	else{
		arquivoBinarioDeClasse = fopen(nomeDoArquivoDeClasse, "rb");
	}
	
//	printf("%p - %s", arquivoBinarioDeClasse, nomeDoArquivoDeClasse); 
	if(!arquivoBinarioDeClasse){
		puts("ClassNotFoundException");
		jvmExit(jvm);
		exit(EXIT_FAILURE);
	}
	else{

		cf = loadClasseDeArquivo(arquivoBinarioDeClasse);

	}
	fclose(arquivoBinarioDeClasse);
	(*cd) = (DADOS_CLASSE *) malloc(sizeof(DADOS_CLASSE));
	constPoolInf	* cp_aux = cf->CONSTANTEe_pool + cf->classe_arq - 1;
	(*cd)->nomeClasse = cf->CONSTANTEe_pool + cp_aux->u.Class.indicador_nome - 1;
	(*cd)->prox = jvm->method_area_jvm;
	jvm->method_area_jvm = (*cd);
	(*cd)->variaveisClasse = NULL;
	(*cd)->instanceClasse = NULL;


	if(!carregadorClasse){
		(*cd)->referencia_carregadorClasse = (*cd);
	}
	else{
		(*cd)->referencia_carregadorClasse = carregadorClasse;
	}
	(*cd)->classfile = cf;
	(*cd)->modifiers = ((*cd)->classfile)->flags_acesso;
	(*cd)->runtime_constant_pool = cf->CONSTANTEe_pool;

	// armazena informações dos fields
	if(cf->conts_campos){
		(*cd)->field_data = (FIELD_DATA *) malloc(cf->conts_campos * sizeof(FIELD_DATA));
		for(uint16_t i = 0; i < cf->conts_campos; i++){
			((*cd)->field_data + i)->field_name = cf->CONSTANTEe_pool + (cf->fields + i)->indicador_nome - 1;
			((*cd)->field_data + i)->field_descriptor = cf->CONSTANTEe_pool + (cf->fields + i)->descriptor_index - 1;
			((*cd)->field_data + i)->modifiers = (cf->fields + i)->flags_acesso;
			((*cd)->field_data + i)->info = (cf->fields + i);
			if(! isFieldDescriptor(((*cd)->field_data + i)->field_descriptor, 0)){
				puts("VerifyError: field descriptor");
				jvmExit(jvm);
				exit(EXIT_FAILURE);
			}
			((*cd)->field_data + i)->field_type = *(((*cd)->field_data + i)->field_name)->u.Utf8.bytes;
		}
	}
	// armazena informações dos métodos
	if(cf->conts_metodo){
		(*cd)->method_data = (METHOD_DATA *) malloc(cf->conts_metodo * sizeof(METHOD_DATA));
		for(uint16_t i = 0; i < cf->conts_metodo; i++){
			((*cd)->method_data + i)->method_name = cf->CONSTANTEe_pool + (cf->methods + i)->indicador_nome - 1;
			((*cd)->method_data + i)->method_descriptor = cf->CONSTANTEe_pool + (cf->methods + i)->descriptor_index - 1;
			((*cd)->method_data + i)->modifiers = (cf->methods + i)->flags_acesso;
			((*cd)->method_data + i)->info = (cf->methods + i);
			((*cd)->method_data + i)->DADOS_CLASSE = (*cd);
	
			if(*(((*cd)->method_data + i)->method_descriptor)->u.Utf8.bytes != '('){
				puts("VerifyError: method descriptor");
				jvmExit(jvm);
				exit(EXIT_FAILURE);
			}
	
			if(! isMethodDescriptor(((*cd)->method_data + i)->method_descriptor, 1)){
				puts("VerifyError: method descriptor");
				jvmExit(jvm);
				exit(EXIT_FAILURE);
			}
	
			if(!(((*cd)->method_data + i)->modifiers & ACC_ABSTRACT) && !(((*cd)->method_data + i)->modifiers & ACC_NATIVE)){
				attribute_info	* code_attr = getCodeAttribute((*cd)->method_data + i, *cd);
				if(!code_attr){
					puts("VerifyError: No code attribute");
					jvmExit(jvm);
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

}// fim da função carregarClasse_01



/*==========================================*/
// função ligadorDeClasse
void	ligadorDeClasse	(DADOS_CLASSE * cd, JVM * jvm){
	classLinkingVerification(cd, jvm);
	classLinkingPreparation(cd, jvm);
}// fim da função ligadorDeClasse

/*==========================================*/
// função classLinkingVerification
void	classLinkingVerification(DADOS_CLASSE * cd, JVM * jvm){
/*	A IMPLEMENTAR
Verification: ensuring the correctness of the imported type
https://www.artima.com/insidejvm/ed2/security3.html
Structural Checks on The ClasseDeArquivo
- magic number = 0xCAFEBABE = OK (carregarClasse_01)
- major/minor version supported = <= java 1.2 = OK (carregarClasse_01)
- tipo e tamanho dos componentes do ClasseDeArquivo (bytes truncados ou extras) = OK (carregarClasse_01)
Semantic Checks on the Type Data
- verificar se um componente do ClasseDeArquivo está bem formado. (exemplo: descritor de um método); = OK (verifyClasseDeArquivo)
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
}// fim da função classLinkingVerification

/*==========================================*/
// função classLinkingPreparation
void	classLinkingPreparation(DADOS_CLASSE * cd, JVM * jvm){
/*
Preparation: allocating memory for class variables and initializing the memory to default values
*/

	if(!(cd->classfile)->conts_campos){
		cd->variaveisClasse = NULL;
	}
	else{
		for(uint16_t i = 0; i < (cd->classfile)->conts_campos; i++){
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
					jvmExit(jvm);
					exit(EXIT_FAILURE);
			}
			uint16_t	flags_acesso = (cd->field_data + i)->modifiers;
				if((flags_acesso & ACC_STATIC) || ((cd->classfile)->flags_acesso & ACC_INTERFACE)){
					var->prox = cd->variaveisClasse;
					cd->variaveisClasse = var;
				}
				else{
					free(var);
				}
		}
	}
}// fim da função classLinkingPreparation
/*==========================================*/
// função classLinkingResolution
void	classLinkingResolution(ClasseDeArquivo * cf, JVM * jvm){
/*	A IMPLEMENTAR = EM TEMPO DE EXECUÇÃO
Verification of Symbolic References
ao executar bytecodes e carregar ClasseDeArquivos
Resolution: transforming symbolic references from the type into direct references.
*/
}// fim da função classLinkingResolution

/*==========================================*/
// função getClassName
char	*	getClassName(DADOS_CLASSE * cd){
 	constPoolInf	* cp_aux = cd->nomeClasse;
 	char	* nomeClasse = (char *) cp_aux->u.Utf8.bytes;
 	nomeClasse[cp_aux->u.Utf8.length] = '\0';
 	return	nomeClasse;
 }

 /*==========================================*/
// função getSuperClass
DADOS_CLASSE	* getSuperClass(ClasseDeArquivo * cf, JVM * jvm){
	if(cf->super_classe){
		constPoolInf	* cp_aux = cf->CONSTANTEe_pool + cf->super_classe - 1;
		cp_aux = cf->CONSTANTEe_pool + cp_aux->u.Class.indicador_nome - 1;
		char	* super_name = (char *) cp_aux->u.Utf8.bytes;
		super_name[cp_aux->u.Utf8.length] = '\0';
		if(strcmp(super_name, "java/lang/Object")){
			DADOS_CLASSE	* cd = jvm->method_area_jvm;
/*			printf("length = %" PRIuint8_t6 "\n", (cd->nomeClasse)->u.Utf8.length);*/
			while(cd){
				char	* name = (char *) (cd->nomeClasse)->u.Utf8.bytes;
				name[(cd->nomeClasse)->u.Utf8.length] = '\0';
				if(!strcmp(super_name, name)){
					return	cd;
				}
				else{
					cd = cd->prox;
				}
			}
		}
	}
	return	NULL;
}// fim da função getSuperClass

bool		isSuperClass(DADOS_CLASSE * super_cd, DADOS_CLASSE * cd, JVM * jvm){
	DADOS_CLASSE	* super = cd;
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
DADOS_CLASSE	* getClass(constPoolInf * cp_class_name, JVM * jvm){
	char	* nomeClasse = (char *) cp_class_name->u.Utf8.bytes;
	nomeClasse[cp_class_name->u.Utf8.length] = '\0';

	DADOS_CLASSE	* cd = jvm->method_area_jvm;
	while(cd){
		char	* cd_class_name = getClassName(cd);
		if(!strcmp(nomeClasse, cd_class_name)){
			return	cd;
		}
		else{
			cd = cd->prox;
		}
	}
	return	NULL;
}

/*==========================================*/
// funcao getClassVariable
VARIABLE	* getClassVariable(constPoolInf * cp_field_name, DADOS_CLASSE * field_class){
	VARIABLE	* cv = field_class->variaveisClasse;

	while(cv){
		char	*string1 = (char *) cp_field_name->u.Utf8.bytes;
		string1[cp_field_name->u.Utf8.length] = '\0';

		char	*string2 = (char *) ((cv->field_reference)->field_name)->u.Utf8.bytes;
		string2[((cv->field_reference)->field_name)->u.Utf8.length] = '\0';
		if(!strcmp(string1, string2)){
			return	cv;
		}
		else{
			cv = cv->prox;
		}
	}
	return	NULL;

}

/*==========================================*/
// funcao getInstanceVariable
VARIABLE	* getInstanceVariable(constPoolInf * cp_field_name, OBJECT * objectref){
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
			iv = iv->prox;
		}
	}
	
	
	return	NULL;
}

/*==========================================*/
// função classInitialization
void	classInitialization(DADOS_CLASSE * cd, JVM * jvm, THREAD * thread){
/*	A IMPLEMENTAR
Initialization of a class consists of two steps:

Initializing the class's direct superclass (if any), if the direct superclass hasn't already been initialized
Executing the class's class initialization method, if it has one
*/

	if((cd->classfile)->super_classe){
		constPoolInf	* cp_aux = (cd->classfile)->CONSTANTEe_pool + (cd->classfile)->super_classe - 1;
		cp_aux = (cd->classfile)->CONSTANTEe_pool + cp_aux->u.Class.indicador_nome - 1;
		char	* super_classe_name = (char *) cp_aux->u.Utf8.bytes;
		super_classe_name[cp_aux->u.Utf8.length] = '\0';
		DADOS_CLASSE	* cd_super;
		if(!(cd_super = getClass(cp_aux, jvm))){
			carregarClasse_01(super_classe_name, &cd_super, cd, jvm);
		}
		ligadorDeClasse(cd_super, jvm);
		classInitialization(cd_super, jvm, thread);
	}
	executeMethod("<clinit>", "()V", cd, jvm, thread, NULL, 0, NULL);
}// fim da função classInitialization

/*==========================================*/
// função getMethod
METHOD_DATA	* getMethod(char * method_name, char * method_descriptor, DADOS_CLASSE * cd, JVM * jvm){
	char	* name;
	char	* descriptor;
	
	DADOS_CLASSE * super_classe = cd;
	while(super_classe){
		for(uint16_t	i = 0; i < (super_classe->classfile)->conts_metodo; i++){
			name = (char *) ((super_classe->method_data + i)->method_name)->u.Utf8.bytes;
			name[((super_classe->method_data + i)->method_name)->u.Utf8.length] = '\0';
	
			descriptor = (char *) ((super_classe->method_data + i)->method_descriptor)->u.Utf8.bytes;
			descriptor[((super_classe->method_data + i)->method_descriptor)->u.Utf8.length] = '\0';
	
			if(!strcmp(method_name, name) && !strcmp(method_descriptor, descriptor)){
				return	(super_classe->method_data + i);
			}
		}
		super_classe = getSuperClass(super_classe->classfile, jvm);
	}
	return	NULL;
}// fim da função getMethod

/*==========================================*/
// função getCodeAttribute
attribute_info	* getCodeAttribute(METHOD_DATA * method, DADOS_CLASSE * cd){
	constPoolInf	* cp_aux;
	char	* attribute_name;
	for(uint16_t	i = 0; i < (method->info)->conts_atributos; i++){
		cp_aux = (cd->classfile)->CONSTANTEe_pool + ((method->info)->attributes + i)->attribute_name_index - 1;
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
void	executeMethod(char * method_name, char * method_descriptor, DADOS_CLASSE * cd, JVM * jvm, THREAD * thread, void * this, uint16_t nargs, uint32_t * args){

	METHOD_DATA	* method = getMethod(method_name, method_descriptor, cd, jvm);
	if(method){
		if(method->modifiers & ACC_ABSTRACT){
			puts("ERROR: IllegalAccessError");
			jvmExit(jvm);
			exit(EXIT_FAILURE);
		}
/*		attribute_info	* code_attr = getCodeAttribute(method, cd);*/

/*		if(code_attr){*/
		if(method->bytecodes){
			// CRIA NOVO FRAME PRO MÉTODO
			FRAME	* frame = (FRAME *) malloc(sizeof(FRAME));
			frame->local_variables = (uint32_t *) malloc(method->locals_size * sizeof(uint32_t));

			uint16_t	index = 0;
			if(!(method->modifiers & ACC_STATIC)){
				frame->local_variables[0] = (uint32_t) this;
				index = 1;
			}
			if((index + nargs) > method->locals_size){
				puts("LocalsOutofBoundsError");
				jvmExit(jvm);
				exit(EXIT_FAILURE);
				
			}
			for(uint16_t pos_arg = 0; pos_arg < nargs; pos_arg++, index++){
				frame->local_variables[index] = args[pos_arg];
			}

			if(args){
				if(strcmp(method_name, "main") || strcmp(method_descriptor, "([Ljava/lang/String;)V")){
					free(args);
				}
			}

			frame->operand_stack = NULL;
			frame->current_constant_pool = cd->runtime_constant_pool;
			frame->prox = thread->jvm_stack;
			thread->jvm_stack = frame;

			// CHAMA O INTERPRETADOR
			interpreter(method, thread, jvm);
		}
		else{
			puts("ERROR: non-abstract method without code attribute.");
			jvmExit(jvm);
			exit(EXIT_FAILURE);
		}
	}
	else{
		if(strcmp(method_name, "<clinit>")){
			printf("método %s não encontrado.\n", method_name);
			jvmExit(jvm);
			exit(EXIT_FAILURE);
		}
	}
}// fim da função execute

/*==========================================*/
// função classUnloading
void	classUnloading(DADOS_CLASSE * cd, JVM * jvm){
/*	A IMPLEMENTAR
https://docs.oracle.com/javase/specs/jvms/se6/html/Concepts.doc.html#19175
*/
/*	free(cd);*/
}// fim da função classUnloading
/*==========================================*/
// função jvmExit
void	jvmExit(JVM * jvm){
	freeThreads(jvm->thread_jvm);
	freeHeap(jvm->heap_jvm);
	freeMethodArea(jvm->method_area_jvm);
	free(jvm);
}// fim da funçao jvmExit
/*==========================================*/

void	pushOperand(uint32_t word, FRAME * frame){
	OPERAND	* aux = (OPERAND *) malloc(sizeof(OPERAND));	// FREE OK

	aux->value = word;
	aux->prox = frame->operand_stack;
	frame->operand_stack = aux;	
	
}

uint32_t	popOperand(FRAME * frame){
	uint32_t	word;
	if(frame->operand_stack){
		OPERAND	* aux = frame->operand_stack;
		frame->operand_stack = aux->prox;
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
	OPERAND	* aux = frame->operand_stack;
	while(aux){
		frame->operand_stack = aux->prox;
		free(aux);
		aux = frame->operand_stack;
	}
}

void		freeThreads(THREAD * thread_jvm){
	THREAD	* aux = thread_jvm;
	while(aux){
		thread_jvm = aux->prox;
		freeJvmStack(aux->jvm_stack);
		free(aux);
		aux = thread_jvm;
	}
}
void		freeJvmStack(FRAME * jvm_stack){
	FRAME	* aux = jvm_stack;
	while(aux){
		jvm_stack = aux->prox;
		freeFrame(aux);
		aux = jvm_stack;
	}
}

void		freeMethodArea(DADOS_CLASSE * method_area_jvm){
	DADOS_CLASSE	* aux = method_area_jvm;
	while(aux){
		method_area_jvm = aux->prox;
		freeClassData(aux);
		aux = method_area_jvm;
	}
}
void		freeClassData(DADOS_CLASSE * DADOS_CLASSE){
	if(DADOS_CLASSE->classfile){
		if((DADOS_CLASSE->classfile)->conts_campos){
			free(DADOS_CLASSE->field_data);
		}
		if((DADOS_CLASSE->classfile)->conts_metodo){
			free(DADOS_CLASSE->method_data);
		}
	
		freeClasseDeArquivo(DADOS_CLASSE->classfile);
	}
	
	if(DADOS_CLASSE->variaveisClasse){
		freeVariables(DADOS_CLASSE->variaveisClasse);
	}

	free(DADOS_CLASSE);
}

void		freeVariables(VARIABLE * vars){
	VARIABLE	* aux = vars;
	while(aux){
		vars = aux->prox;
		free(aux);
		aux = vars;
	}
}

void		freeHeap(HEAP_AREA * heap_jvm){
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
		objects = aux->prox;
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
		arrays = aux->prox;
		free(aux->entry);
		free(aux);
		aux = arrays;
	}
}

