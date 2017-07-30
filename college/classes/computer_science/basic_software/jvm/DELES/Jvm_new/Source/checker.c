#include "checker.h"

/*==========================================*/
// função isFieldDescriptor
bool isFieldDescriptor(constPoolInf *cp, uint16_t index) {
	uint16_t length = cp->u.Utf8.length;
	uint8_t *bytes = cp->u.Utf8.bytes + index;
	if (index == length) {
		return true;
	}
	switch (*bytes) {
		case BOOLEAN:
		case BYTE:
		case CHAR:
		case DOUBLE:
		case FLOAT:
		case INT:
		case LONG:
		case SHORT:
		case REF_ARRAY:
			return isFieldDescriptor(cp, ++index);
			break;
		case REF_INST:;
			char *string = (char *)bytes;
			string[cp->u.Utf8.length - index] = '\0';

			if ((length - index) < 3 || !strchr(string, ';')) {
				return false;
			}
			index += strlen(string);
			return isFieldDescriptor(cp, index);
			break;
		default:
			return false;
	}
	return false;
}
// fim da função isFieldDescriptor

/*==========================================*/
// função isMethodDescriptor
bool isMethodDescriptor(constPoolInf *cp, uint16_t index) {
	uint16_t length = cp->u.Utf8.length;
	uint8_t *bytes = cp->u.Utf8.bytes + index;

	/*	printf("index = %" PRIuint8_t6 " length = %" PRIuint8_t6 "\n", index,
	 * length);*/
	if (index == length) {
		return true;
		;
	}

	bool returnDescriptor = false;
	if ((*bytes) == ')') {
		returnDescriptor = true;
		index++;
		bytes++;
		while (((*bytes) == '[')) {
			index++;
			bytes++;
		}
		if (index == length) {
			puts("erro tipo retorno");
			return false;
		}
	}
	switch (*bytes) {
		case BOOLEAN:
		case BYTE:
		case CHAR:
		case DOUBLE:
		case FLOAT:
		case INT:
		case LONG:
		case SHORT:
		case REF_ARRAY:
			if (!returnDescriptor) {
				return isMethodDescriptor(cp, ++index);
			}
			if (index == (length - 1)) {
				return true;
			}
			puts("erro tipo retorno");
			return false;
			break;
		case REF_INST:;
			char *string = (char *)bytes;
			string[cp->u.Utf8.length - index] = '\0';


			if ((length - index) < 3 || !strchr(string, ';')) {
				puts("Erro ref inst");
				return false;
			}
			index += strlen(string);
			if (!returnDescriptor) {
				return isMethodDescriptor(cp, index);
			}
			if (index == length) {
				return true;
			}
			/*			ImprimeConstUtf8(cp, stdout);*/
			puts("erro ref inst retorno");
			return false;
			break;
		case 'V':
			if (!returnDescriptor) {
				puts("erro void parametro");
				return false;
			}
			if (index == (length - 1)) {
				return true;
			}
			puts("erro void retorno");
			return false;
			break;
		default:
			printf("index = %" PRIu16 " length = %" PRIu16 "\n",
				   index, length);
			printf("%c\n", *bytes);
			ImprimeConstUtf8(cp, stdout);
			puts("erro tipo desconhecido");
			return false;
	}
}
// fim da função isFieldDescriptor

/*==========================================*/
// função verifyConstantPool
void verifyConstantPool(ClasseDeArquivo *cf) {
	// Verify Constant Pool
	constPoolInf *cp;
	for (uint16_t i = 0; i < (cf->Cont_ConstPool - 1); i++) {
		cp = cf->CONSTANTEe_pool + i;
		switch (cp->tag) {
			case Classe_const:
				if ((cf->CONSTANTEe_pool + cp->u.Class.indicador_nome - 1)->tag !=
					CONSTANTE_Utf8) {
					puts("VerifyError: invalid class name index");
					exit(EXIT_FAILURE);
				}
				break;
			case CONSTANTEe_campo_referencia:
			case CONSTANTEe_metodo_referencia:
			case CONSTANTEe_Interface_referencia:
				if ((cf->CONSTANTEe_pool + cp->u.Ref.indicador_nome - 1)->tag !=
					Classe_const) {
					puts("VerifyError: invalid ref class index");
					exit(EXIT_FAILURE);
				}
				if ((cf->CONSTANTEe_pool + cp->u.Ref.indicador_nome_e_tipo -
					 1)->tag != CONSTANTE_NameAndType) {
					puts("VerifyError: invalid name_and_type index");
					exit(EXIT_FAILURE);
				}
				if (cp->tag != CONSTANTEe_campo_referencia) {
					constPoolInf *cp_aux;
					cp_aux =
						cf->CONSTANTEe_pool + cp->u.Ref.indicador_nome_e_tipo - 1;
					cp_aux = cf->CONSTANTEe_pool +
							 cp_aux->u.NameAndType.descriptor_index - 1;
					if (cp_aux->tag != CONSTANTE_Utf8) {
						puts("VerifyError: invalid field descriptor index");
						exit(EXIT_FAILURE);
					}
					if ((cp_aux->u.Utf8).length < 3) {
						puts("VerifyError: invalid field descriptor");
						exit(EXIT_FAILURE);
					}
					if (((cp_aux->u.Utf8).bytes)[0] != '(') {
						puts("VerifyError: invalid field descriptor");
						exit(EXIT_FAILURE);
					}
				}
				break;
			case CONSTANTE_String:
				if ((cf->CONSTANTEe_pool + cp->u.String.indicador_string -
					 1)->tag != CONSTANTE_Utf8) {
					puts("VerifyError: invalid string index");
					exit(EXIT_FAILURE);
				}
				break;
			case CONSTANTE_Integer:
			case CONSTANTE_Float:
			case CONSTANTE_Long:
			case CONSTANTE_Double:
				break;
			case CONSTANTE_NameAndType:
				if ((cf->CONSTANTEe_pool + cp->u.NameAndType.indicador_nome -
					 1)->tag != CONSTANTE_Utf8) {
					puts("VerifyError: invalid NameAndType indicador_nome");
					exit(EXIT_FAILURE);
				}
				constPoolInf *cp_aux;
				if ((cp_aux = cf->CONSTANTEe_pool +
							  cp->u.NameAndType.descriptor_index - 1)
						->tag != CONSTANTE_Utf8) {
					puts("VerifyError: invalid NameAndType descriptor_index");
					exit(EXIT_FAILURE);
				}
				if (cp_aux->u.Utf8.length == 0) {
					puts("VerifyError: invalid descriptor");
					exit(EXIT_FAILURE);
				}
				uint16_t length = cp_aux->u.Utf8.length;
				uint8_t *bytes = cp_aux->u.Utf8.bytes;

				char *string = (char *)cp_aux->u.Utf8.bytes;
				string[cp_aux->u.Utf8.length] = '\0';
				switch (*bytes) {
					case BOOLEAN:
					case BYTE:
					case CHAR:
					case DOUBLE:
					case FLOAT:
					case INT:
					case LONG:
					case SHORT:
						if (length != 1) {
							puts("VerifyError: invalid descriptor");
							exit(EXIT_FAILURE);
						}
						break;
					case REF_INST:
						if (length < 3 || bytes[length - 1] != ';') {
							puts("VerifyError: invalid descriptor");
							exit(EXIT_FAILURE);
						}
						break;
					case REF_ARRAY:
						if (length < 2) {
							puts("VerifyError: invalid descriptor");
							exit(EXIT_FAILURE);
						}
						uint16_t index = 0;
						while ((*bytes) == REF_ARRAY) {
							index++;
							bytes++;
						}
						if (!isFieldDescriptor(cp_aux, index)) {
							puts("VerifyError: invalid descriptor");
							exit(EXIT_FAILURE);
						}
						break;
					case '(':
						if (length < 3) {
							puts("VerifyError: invalid descriptor");
							exit(EXIT_FAILURE);
						}
						if (!isMethodDescriptor(cp_aux, 1)) {
							puts("VerifyError: invalid descriptor");
							exit(EXIT_FAILURE);
						}
						break;
					default:
						puts("VerifyError: invalid descriptor");
						exit(EXIT_FAILURE);
						break;
				}
			case CONSTANTE_Utf8:
				break;
		}
	}
}  // fim da função verifyConstantPool

/*==========================================*/
// função verifyAccessFlags
void verifyAccessFlags(ClasseDeArquivo *cf) {
	uint16_t access_flags;

	// Testando flags de classes
	access_flags = cf->flags_acesso;
	if (access_flags & 0xF9CE) {
		puts("VerifyError: invalid class access flags");
		exit(EXIT_FAILURE);
	}

	// Testando flags de fields
	for (uint16_t i = 0; i < cf->conts_campos; i++) {
		access_flags = (cf->fields + i)->flags_acesso;
		if (access_flags & 0xFF20) {
			puts("VerifyError: invalid field access flags");
			exit(EXIT_FAILURE);
		}
	}

	// Testando flags de métodos
	for (uint16_t i = 0; i < cf->conts_metodo; i++) {
		access_flags = (cf->methods + i)->flags_acesso;
		if (access_flags & 0xF2C0) {
			puts("VerifyError: invalid method access flags");
			exit(EXIT_FAILURE);
		}
	}
}  // fim da função verifyAccessFlag

/*==========================================*/
// função verifyBytecode
void verifyBytecode(attribute_info *attr, ClasseDeArquivo *cf) {
	// verifica atributo CODE
	// 4.8 Constraints on Java Virtual Machine Code
	/*
	Branches must be within the bounds of the code array for the method.
	The targets of all control-flow instructions are each the start of an
	instruction. In the case of a wide instruction, the wide opcode is
	considered the start of the instruction, and the opcode giving the operation
	modified by that wide instruction is not considered to start an instruction.
	Branches into the middle of an instruction are disallowed.
	No instruction can access or modify a local variable at an index greater
	than or equal to the number of local variables that its method indicates it
	allocates.
	All references to the constant pool must be to an entry of the appropriate
	type. For example: the instruction ldc can be used only for data of type int
	or float or for instances of class String; the instruction getfield must
	reference a field.
	The code does not end in the middle of an instruction.
	Execution cannot fall off the end of the code.
	For each exception handler, the starting and ending point of code protected
	by the handler must be at the beginning of an instruction or, in the case of
	the ending point, immediately past the end of the code. The starting point
	must be before the ending point. The exception handler code must start at a
	valid instruction, and it may not start at an opcode being modified by the
	wide instruction.
	*/

}  // fim da funcao verifyBytecode

/*==========================================*/
// função verifyClassfile
void verifyClassfile(ClasseDeArquivo *cf) {
	// checa inconsistências na Constant Pool
	verifyConstantPool(cf);

	// checa flags inválidas
	verifyAccessFlags(cf);

	constPoolInf *cp_aux;

	// checa this_class
	cp_aux = cf->CONSTANTEe_pool + cf->classe_arq - 1;
	if (cp_aux->tag != Classe_const) {
		puts("VerifyError: invalid this_class index");
		exit(EXIT_FAILURE);
	}

	// checa super_class
	if (cf->super_classe) {
		cp_aux = cf->CONSTANTEe_pool + cf->super_classe - 1;
		if (cp_aux->tag != Classe_const) {
			puts("VerifyError: invalid super_class index");
			exit(EXIT_FAILURE);
		}
	} else {
		// Toda classe, exceto Object, deve ter uma superclasse FALTA TESTAR
		// ISSO
		cp_aux = cf->CONSTANTEe_pool + cf->classe_arq - 1;
		cp_aux = cf->CONSTANTEe_pool + cp_aux->u.Class.indicador_nome - 1;
		char *string = (char *)cp_aux->u.Utf8.bytes;
		string[cp_aux->u.Utf8.length] = '\0';
		if (strcmp(string, "java/lang/Object")) {
			puts("VerifyError: Without superclass");
			exit(EXIT_FAILURE);
		}
	}

	// checa interfaces
	for (uint16_t i = 0; i < cf->interfaces_count; i++) {
		cp_aux = cf->CONSTANTEe_pool + (*(cf->interfaces + i)) - 1;
		if (cp_aux->tag != Classe_const) {
			puts("VerifyError: invalid interface index");
			exit(EXIT_FAILURE);
		}
	}

	// checa fields
	for (uint16_t i = 0; i < cf->conts_campos; i++) {
		uint16_t indicador_nome = (cf->fields + i)->indicador_nome;
		cp_aux = cf->CONSTANTEe_pool + indicador_nome - 1;
		if (cp_aux->tag != CONSTANTE_Utf8) {
			puts("VerifyError: field indicador_nome");
			exit(EXIT_FAILURE);
		}
		uint16_t descriptor_index = (cf->fields + i)->descriptor_index;
		cp_aux = cf->CONSTANTEe_pool + descriptor_index - 1;
		if (cp_aux->tag != CONSTANTE_Utf8) {
			puts("VerifyError: field descriptor_index");
			exit(EXIT_FAILURE);
		}
		// checa atributos de fields
		uint16_t attributes_count = (cf->fields + i)->conts_atributos;
		for (uint16_t j = 0; j < attributes_count; j++) {
			cp_aux = cf->CONSTANTEe_pool +
					 ((cf->fields + i)->attributes + j)->attribute_name_index -
					 1;
			if (cp_aux->tag != CONSTANTE_Utf8) {
				puts("VerifyError: field attribute_indicador_nome");
				exit(EXIT_FAILURE);
			}
			switch (getTipoAtributo(((cf->fields + i)->attributes + j), cf)) {
				case CODE:
				case EXCEPTIONS:
				case INNER_CLASSES:
				case LINE_NUMBER_TABLE:
				case LOCAL_VARIABLE_TABLE:
				case SOURCE_FILE:
					puts("VerifyError: invalid field attribute");
					exit(EXIT_FAILURE);
					break;
				case DEPRECATED:
				case SYNTHETIC:
					if (((cf->fields + i)->attributes + j)->attribute_length) {
						puts("VerifyError: invalid attribute");
						exit(EXIT_FAILURE);
					}
					break;
			}
		}
	}

	// checa métodos
	for (uint16_t i = 0; i < cf->conts_metodo; i++) {
		uint16_t indicador_nome = (cf->methods + i)->indicador_nome;
		cp_aux = cf->CONSTANTEe_pool + indicador_nome;
		if (cp_aux->tag != CONSTANTE_Utf8) {
			puts("VerifyError: invalid method indicador_nome");
			exit(EXIT_FAILURE);
		}

		uint16_t descriptor_index = (cf->methods + i)->descriptor_index;
		cp_aux = cf->CONSTANTEe_pool + descriptor_index;
		if (cp_aux->tag != CONSTANTE_Utf8) {
			puts("VerifyError: invalid method descriptor_index");
			exit(EXIT_FAILURE);
		}

		// checa atributos de métodos
		uint16_t attributes_count = (cf->methods + i)->conts_atributos;
		for (uint16_t j = 0; j < attributes_count; j++) {
			cp_aux = cf->CONSTANTEe_pool +
					 ((cf->methods + i)->attributes + j)->attribute_name_index -
					 1;
			if (cp_aux->tag != CONSTANTE_Utf8) {
				puts("VerifyError: invalid attribute_indicador_nome");
				exit(EXIT_FAILURE);
			}
			switch (getTipoAtributo(((cf->methods + i)->attributes + j), cf)) {
				case CODE:
					verifyBytecode(((cf->methods + i)->attributes + j), cf);
					// checa atributos do atributo Code
					uint16_t code_attributes_count =
						((cf->methods + i)->attributes +
						 j)->u.Code.conts_atributos;
					for (uint16_t k = 0; k < code_attributes_count; k++) {
						attribute_info *attr = ((cf->methods + i)->attributes +
												j)->u.Code.attributes +
											   k;
						cp_aux = cf->CONSTANTEe_pool +
								 attr->attribute_name_index - 1;
						if (cp_aux->tag != CONSTANTE_Utf8) {
							puts("VerifyError: invalid attribute_indicador_nome");
							exit(EXIT_FAILURE);
						}
						switch (getTipoAtributo(attr, cf)) {
							case CODE:
							case DEPRECATED:
							case EXCEPTIONS:
							case INNER_CLASSES:
							case SOURCE_FILE:
							case SYNTHETIC:
								puts("VerifyError: invalid Code's attribute");
								exit(EXIT_FAILURE);
								break;
							case LINE_NUMBER_TABLE:
								break;
							case LOCAL_VARIABLE_TABLE:
								for (uint16_t l = 0;
									 l < attr->u.LocalVariableTable
											 .local_variable_table_length;
									 l++) {
									cp_aux = cf->CONSTANTEe_pool +
											 (attr->u.LocalVariableTable
												  .local_variable_table)
												 ->indicador_nome;
									if (cp_aux->tag != CONSTANTE_Utf8) {
										puts("VerifyError: invalid local "
											 "variable table indicador_nome");
										exit(EXIT_FAILURE);
									}
									cp_aux = cf->CONSTANTEe_pool +
											 (attr->u.LocalVariableTable
												  .local_variable_table)
												 ->descriptor_index;
									if (cp_aux->tag != CONSTANTE_Utf8) {
										puts("VerifyError: invalid local "
											 "variable table descriptor_index");
										exit(EXIT_FAILURE);
									}
									if (!isFieldDescriptor(cp_aux, 0)) {
										puts("VerifyError: invalid field "
											 "descriptor");
										exit(EXIT_FAILURE);
									}
								}
								break;
						}
					}
					break;
				case EXCEPTIONS:;
					uint16_t number_of_exceptions =
						((cf->methods + i)->attributes +
						 j)->u.Exceptions.number_of_exceptions;
					for (uint16_t k = 0; k < number_of_exceptions; k++) {
						uint16_t exception_index =
							*(((cf->methods + i)->attributes +
							   j)->u.Exceptions.exception_index_table +
							  k);
						if (!exception_index) {
							puts("VerifyError: invalid exception index");
							exit(EXIT_FAILURE);
						}
						cp_aux = cf->CONSTANTEe_pool + exception_index - 1;
						if (cp_aux->tag != Classe_const) {
							puts("VerifyError: invalid exception index");
							exit(EXIT_FAILURE);
						}
					}
					break;
				case INNER_CLASSES:
				case LINE_NUMBER_TABLE:
				case LOCAL_VARIABLE_TABLE:
				case SOURCE_FILE:
					puts("VerifyError: invalid method attribute");
					exit(EXIT_FAILURE);
					break;
				case DEPRECATED:
				case SYNTHETIC:
					if (((cf->methods + i)->attributes + j)->attribute_length) {
						puts("VerifyError: invalid method attribute");
						exit(EXIT_FAILURE);
					}
					break;
			}
		}
	}

	// checa atributos de classe
	for (uint16_t i = 0; i < cf->conts_atributos; i++) {
		cp_aux = cf->CONSTANTEe_pool +
				 (cf->attributes + i)->attribute_name_index - 1;
		if (cp_aux->tag != CONSTANTE_Utf8) {
			puts("VerifyError: invalid class attribute_indicador_nome");
			exit(EXIT_FAILURE);
		}
		switch (getTipoAtributo(cf->attributes + i, cf)) {
			case CODE:
			case EXCEPTIONS:
			case LINE_NUMBER_TABLE:
			case LOCAL_VARIABLE_TABLE:
				puts("VerifyError: invalid class attribute");
				exit(EXIT_FAILURE);
				break;
			case INNER_CLASSES:;
				uint16_t number_of_classes =
					(cf->attributes + i)->u.InnerClasses.number_of_classes;
				for (uint16_t j = 0; j < number_of_classes; j++) {
					classes_type *class =
						((cf->attributes + i)->u.InnerClasses.classes + j);
					if (!(class->inner_class_info_index) ||
						!(class->outer_class_info_index) ||
						!(class->inner_name_index)) {
						puts("VerifyError: invalid inner class index");
						exit(EXIT_FAILURE);
					}
					cp_aux =
						cf->CONSTANTEe_pool + class->inner_class_info_index - 1;
					if (cp_aux->tag != Classe_const) {
						puts("VerifyError: invalid inner_class_info_index");
						exit(EXIT_FAILURE);
					}
					cp_aux =
						cf->CONSTANTEe_pool + class->outer_class_info_index - 1;
					if (cp_aux->tag != Classe_const) {
						puts("VerifyError: invalid outer_class_info_index");
						exit(EXIT_FAILURE);
					}
					cp_aux = cf->CONSTANTEe_pool + class->inner_name_index - 1;
					if (cp_aux->tag != CONSTANTE_Utf8) {
						puts("VerifyError: invalid inner_indicador_nome");
						exit(EXIT_FAILURE);
					}
					uint16_t access_flags = class->inner_class_access_flags;
					if (access_flags & 0xF9E0) {
						puts("VerifyError: invalid inner_class_access_flags");
						exit(EXIT_FAILURE);
					}
				}
				break;
			case SOURCE_FILE:
				if ((cf->attributes + i)->attribute_length != 2) {
					puts("VerifyError: invalid source file attribute");
					exit(EXIT_FAILURE);
				}
				cp_aux = cf->CONSTANTEe_pool +
						 (cf->attributes + i)->u.SourceFile.sourcefile_index -
						 1;
				if (cp_aux->tag != CONSTANTE_Utf8) {
					puts("VerifyError: invalid sourcefile_index");
					exit(EXIT_FAILURE);
				}
				break;
			case DEPRECATED:
			case SYNTHETIC:
				if ((cf->attributes + i)->attribute_length) {
					puts("VerifyError: invalid class attribute");
					exit(EXIT_FAILURE);
				}
				break;
		}
	}
}  // fim da funcao verifyClassfile


/*==========================================*/
// função verifyFinal
void verifySuperFinal(ClasseDeArquivo *cf, JVM *jvm) {
	// verifica se a classe atual foi herdada uma classe final
	DADOS_CLASSE *cd_super;
	if ((cd_super = getSuperClass(cf, jvm))) {
		if ((cd_super->classfile)->flags_acesso & ACC_FINAL) {
			puts("VerifyError: final superclass inherited");
			exit(EXIT_FAILURE);
		}
	}
}

/*==========================================*/
// função verifyOverrideMethodFinal
void verifyOverrideMethodFinal(ClasseDeArquivo *cf, JVM *jvm) {
	// verifica se método final é sobrecarregado
	constPoolInf *cp_aux = NULL;
	for (uint16_t i = 0; i < cf->conts_metodo; i++) {
		cp_aux = (cf->methods + i)->indicador_nome + cf->CONSTANTEe_pool - 1;
		char *method_name = (char *)cp_aux->u.Utf8.bytes;
		method_name[cp_aux->u.Utf8.length] = '\0';
		DADOS_CLASSE *cd_super = cd_super = getSuperClass(cf, jvm);
		while (cd_super) {
			for (uint16_t i = 0; i < (cd_super->classfile)->conts_metodo;
				 i++) {
				cp_aux = ((cd_super->classfile)->methods + i)->indicador_nome +
						 (cd_super->classfile)->CONSTANTEe_pool - 1;
				char *super_method_name = (char *)cp_aux->u.Utf8.bytes;
				super_method_name[cp_aux->u.Utf8.length] = '\0';
				if (!strcmp(method_name, super_method_name)) {
					if (((cd_super->classfile)->methods + i)->flags_acesso ==
						ACC_FINAL) {
						puts("VerifyError: override final method");
						exit(EXIT_FAILURE);
					}
				}
			}
			cd_super = getSuperClass(cd_super->classfile, jvm);
		}
	}
}
