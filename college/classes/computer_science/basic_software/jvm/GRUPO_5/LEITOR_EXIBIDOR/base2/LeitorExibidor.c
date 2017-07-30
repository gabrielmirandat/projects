#include "LeitExib.h"
#include "opcode.h"

// Array de mnemônicos
char *op_codesJVM[] = {"nop",
					   "aconst_null",
					   "iconst_m1",
					   "iconst_0",
					   "iconst_1",
					   "iconst_2",
					   "iconst_3",
					   "iconst_4",
					   "iconst_5",
					   "lconst_0",
					   "lconst_1",
					   "fconst_0",
					   "fconst_1",
					   "fconst_2",
					   "dconst_0",
					   "dconst_1",
					   "bipush",
					   "sipush",
					   "ldc",
					   "ldc_w",
					   "ldc2_w",
					   "iload",
					   "lload",
					   "fload",
					   "dload",
					   "aload",
					   "iload_0",
					   "iload_1",
					   "iload_2",
					   "iload_3",
					   "lload_0",
					   "lload_1",
					   "lload_2",
					   "lload_3",
					   "fload_0",
					   "fload_1",
					   "fload_2",
					   "fload_3",
					   "dload_0",
					   "dload_1",
					   "dload_2",
					   "dload_3",
					   "aload_0",
					   "aload_1",
					   "aload_2",
					   "aload_3",
					   "iaload",
					   "laload",
					   "faload",
					   "daload",
					   "aaload",
					   "baload",
					   "caload",
					   "saload",
					   "istore",
					   "lstore",
					   "fstore",
					   "dstore",
					   "astore",
					   "istore_0",
					   "istore_1",
					   "istore_2",
					   "istore_3",
					   "lstore_0",
					   "lstore_1",
					   "lstore_2",
					   "lstore_3",
					   "fstore_0",
					   "fstore_1",
					   "fstore_2",
					   "fstore_3",
					   "dstore_0",
					   "dstore_1",
					   "dstore_2",
					   "dstore_3",
					   "astore_0",
					   "astore_1",
					   "astore_2",
					   "astore_3",
					   "iastore",
					   "lastore",
					   "fastore",
					   "dastore",
					   "aastore",
					   "bastore",
					   "castore",
					   "sastore",
					   "pop",
					   "pop2",
					   "dup",
					   "dup_x1",
					   "dup_x2",
					   "dup2",
					   "dup2_x1",
					   "dup2_x2",
					   "swap",
					   "iadd",
					   "ladd",
					   "fadd",
					   "dadd",
					   "isub",
					   "lsub",
					   "fsub",
					   "dsub",
					   "imul",
					   "lmul",
					   "fmul",
					   "dmul",
					   "idiv",
					   "ldiv",
					   "fdiv",
					   "ddiv",
					   "irem",
					   "lrem",
					   "frem",
					   "drem",
					   "ineg",
					   "lneg",
					   "fneg",
					   "dneg",
					   "ishl",
					   "lshl",
					   "ishr",
					   "lshr",
					   "iushr",
					   "lushr",
					   "iand",
					   "land",
					   "ior",
					   "lor",
					   "ixor",
					   "lxor",
					   "iinc",
					   "i2l",
					   "i2f",
					   "i2d",
					   "l2i",
					   "l2f",
					   "l2d",
					   "f2i",
					   "f2l",
					   "f2d",
					   "d2i",
					   "d2l",
					   "d2f",
					   "i2b",
					   "i2c",
					   "i2s",
					   "lcmp",
					   "fcmpl",
					   "fcmpg",
					   "dcmpl",
					   "dcmpg",
					   "ifeq",
					   "ifne",
					   "iflt",
					   "ifge",
					   "ifgt",
					   "ifle",
					   "if_icmpeq",
					   "if_icmpne",
					   "if_icmplt",
					   "if_icmpge",
					   "if_icmpgt",
					   "if_icmple",
					   "if_acmpeq",
					   "if_acmpne",
					   "goto",
					   "jsr",
					   "ret",
					   "tableswitch",
					   "lookupswitch",
					   "ireturn",
					   "lreturn",
					   "freturn",
					   "dreturn",
					   "areturn",
					   "return",
					   "getstatic",
					   "putstatic",
					   "getfield",
					   "putfield",
					   "invokevirtual",
					   "invokespecial",
					   "invokestatic",
					   "invokeinterface",
					   "invokedynamic",
					   "new",
					   "newarray",
					   "anewarray",
					   "arraylength",
					   "athrow",
					   "checkcast",
					   "instanceof",
					   "monitorenter",
					   "monitorexit",
					   "wide",
					   "multianewarray",
					   "ifnull",
					   "ifnonnull",
					   "goto_w",
					   "jsr_w",
					   "breakpoint",
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   NULL,
					   "impdep1",
					   "impdep2"};

void mostrarClasseDeArquivo(ClasseDeArquivo *ca, FILE *saida) {
	fprintf(saida, "\t\t\tLeitor/Exibidor Cruzeiro - Software Basico "
				   "1/2016\n\n");
	mostrarInfo(ca, saida);
	mostrarConstPool(ca, saida);
	mostrarInterfaces(ca, saida);
	mostrarCampos(ca, saida);
	mostrarMetodos(ca, saida);
	mostrarAtributos(NULL, NULL, NULL, ca, saida);
}

void mostrarInfo(ClasseDeArquivo *ca, FILE *saida) {
	float versao;
	constPoolInf *constPool;

	// Mostrar Informação Geral

	fprintf(saida, "Magic: \t\t\t\t0x%" PRIx32 "\n", ca->magic);

	fprintf(saida, "Versao Min: \t\t\t%" PRId16 "\n", ca->Min_version);

	if (ca->Principal_version == 45) {
		versao = 1.1;
	} else if (ca->Principal_version == 46) {
		versao = 1.2;
	} else if (ca->Principal_version == 47) {
		versao = 1.3;
	} else if (ca->Principal_version == 48) {
		versao = 1.4;
	} else if (ca->Principal_version == 49) {
		versao = 1.5;
	} else if (ca->Principal_version == 50) {
		versao = 1.6;
	} else if (ca->Principal_version == 51) {
		versao = 1.7;
	} else if (ca->Principal_version == 52) {
		versao = 1.8;
	} else {
		versao = 0.0;  // signfica que deu erro ...
	}

	fprintf(saida, "Principal versao: \t\t%" PRIu16 "\t[%.1f]\n",
			ca->Principal_version, versao);

	fprintf(saida, "Tamanho do CONSTANTE Pool: \t%" PRIu16 "\n",
			ca->Cont_ConstPool);

	fprintf(saida, "Flags de acesso: \t\t0x%.4" PRIX16 "\t[", ca->flags_acesso);

	uint16_t flags_acesso = ca->flags_acesso;
	if (flags_acesso >= FLAG_ABSTRATA) {
		fprintf(saida, "abstract ");
		flags_acesso -= FLAG_ABSTRATA;
	}
	if (flags_acesso >= FLAG_INTERFACE) {
		fprintf(saida, "interface ");
		flags_acesso -= FLAG_INTERFACE;
	}
	if (flags_acesso >= FLAG_SUPER) {
		fprintf(saida, "super ");
		flags_acesso -= FLAG_SUPER;
	}

	if (flags_acesso >= FLAG_FINAL) {
		fprintf(saida, "final ");
		flags_acesso -= FLAG_FINAL;
	}
	if (flags_acesso >= FLAG_PUBLIC) {
		fprintf(saida, "public ");
		flags_acesso -= FLAG_PUBLIC;
	}
	fprintf(saida, "]\n");

	setlocale(LC_ALL, "");

	fprintf(saida, "Classe carregada: \t\t\tcp_info #%" PRIu16, ca->classe_arq);
	if (ca->CONSTANTEe_pool[ca->classe_arq - 1].tag != Classe_const) {
		puts("\nERRO: classe_arq nao aponta para uma CONSTANTE_Class_info.\n");
		exit(EXIT_FAILURE);
	} else {
		uint16_t indicador_nome;
		indicador_nome =
			ca->CONSTANTEe_pool[ca->classe_arq - 1].u.Class.indicador_nome;
		constPool = ca->CONSTANTEe_pool + indicador_nome - 1;
		if (constPool->tag != CONSTANTE_Utf8) {
			puts("\nERRO: classe_arq nao referencia um indicador_nome "
				 "valido.\n");
			exit(EXIT_FAILURE);
		} else {
			fprintf(saida, "\t<");
			ImprimeConstUtf8(constPool, saida);
			fprintf(saida, ">\n");
		}
	}

	if (!ca->super_classe) {
		fprintf(saida, "Super classe: \t\t\tNone\n");
	} else {
		if (ca->CONSTANTEe_pool[ca->super_classe - 1].tag != Classe_const) {
			puts("\nERRO: super_classe nao aponta para uma "
				 "CONSTANTE_Class_info.\n");
			exit(EXIT_FAILURE);
		} else {
			fprintf(saida, "Super class: \t\t\tcp_info #%" PRIu16,
					ca->super_classe);
			uint16_t indicador_nome;
			indicador_nome =
				ca->CONSTANTEe_pool[ca->super_classe - 1].u.Class.indicador_nome;
			constPool = ca->CONSTANTEe_pool + indicador_nome - 1;
			if (constPool->tag != CONSTANTE_Utf8) {
				puts("\nERRO: super_classe nao referencia um indicador_nome valido.\n");
				exit(EXIT_FAILURE);
			} else {
				fprintf(saida, "\t<");
				ImprimeConstUtf8(constPool, saida);
				fprintf(saida, ">\n");
			}
		}
	}


	fprintf(saida, "Quantidade de Interfaces: \t%" PRIu16 "\n",
			ca->interfaces_count);
	fprintf(saida, "Quantidade de Campos: \t\t%" PRIu16 "\n", ca->conts_campos);
	fprintf(saida, "Quantidade de Metodos: \t\t%" PRIu16 "\n",
			ca->conts_metodo);
	fprintf(saida, "Quantidade de Atributos: \t%" PRIu16 "\n",
			ca->conts_atributos);
}


void ImprimeConstUtf8(constPoolInf *constPool, FILE *saida) {
	char *string = (char *)constPool->u.Utf8.bytes;
	string[constPool->u.Utf8.length] = '\0';
	fprintf(saida, "%s", string);
}

// Imprime no arquivo de saida os valores apontados pelo Classe_const
void ImprimeCONSTANTEeClasse(ClasseDeArquivo *ca, constPoolInf *constPool,
							 FILE *saida) {
	constPoolInf *cp_a0;
	cp_a0 = ca->CONSTANTEe_pool + constPool->u.Class.indicador_nome - 1;
	if (cp_a0->tag != CONSTANTE_Utf8) {
		puts("\nERRO: valor da tag invalido (Diferente de CONSTANTE_Utf8).\n");
		exit(EXIT_FAILURE);
	} else {
		for (uint16_t i = 0; i < cp_a0->u.Utf8.length; i++) {
			fprintf(saida, "%c", cp_a0->u.Utf8.bytes[i]);
		}
	}
}

// Imprime no arquivo de saida os valores apontados pelo CONSTANTE_String
void ImprimeCONSTANTEeString(ClasseDeArquivo *ca, constPoolInf *constPool,
							 FILE *saida) {
	constPoolInf *cp_a0;
	cp_a0 = ca->CONSTANTEe_pool + constPool->u.String.indicador_string - 1;
	if (cp_a0->tag != CONSTANTE_Utf8) {
		puts("\nERRO: valor da tag invalido (Diferente de CONSTANTE_Utf8).\n");
		exit(EXIT_FAILURE);
	} else {
		ImprimeConstUtf8(cp_a0, saida);
	}
}

// Imprime no arquivo de saida os valores apontados pelo CONSTANTE_NameType
void ImprimeCONSTANTEeNomeTipo(ClasseDeArquivo *ca, constPoolInf *constPool,
							   char descritor_nome, FILE *saida) {
	constPoolInf *cp_a0 = constPool;

	if (descritor_nome == 'n') {
		cp_a0 = ca->CONSTANTEe_pool + cp_a0->u.NameAndType.indicador_nome - 1;
		if (cp_a0->tag != CONSTANTE_Utf8) {
			puts("\nERRO: valor da tag invalido (Diferente de "
				 "CONSTANTE_Utf8).\n");
			exit(EXIT_FAILURE);
		} else {
			for (uint16_t i = 0; i < cp_a0->u.Utf8.length; i++) {
				fprintf(saida, "%c", cp_a0->u.Utf8.bytes[i]);
			}
		}
	} else if (descritor_nome == 'd') {
		cp_a0 = ca->CONSTANTEe_pool + cp_a0->u.NameAndType.descriptor_index - 1;
		if (cp_a0->tag != CONSTANTE_Utf8) {
			puts("\nERRO: valor da tag invalido (Diferente de "
				 "CONSTANTE_Utf8).\n");
			exit(EXIT_FAILURE);
		} else {
			for (uint16_t i = 0; i < cp_a0->u.Utf8.length; i++) {
				fprintf(saida, "%c", cp_a0->u.Utf8.bytes[i]);
			}
		}
	} else {
		// nada faz
	}
}

// Imprime no arquivo de saida os valores apontados pelos
// CONSTANTEe_campo_referencia, CONSTANTEe_metodo_referencia,
// CONSTANTEe_Interface_referencia
void ImprimeCONSTANTEeReferencia(ClasseDeArquivo *ca, constPoolInf *constPool,
								 char tipo_indicador, FILE *saida) {
	constPoolInf *cp_a0;
	constPoolInf *cp_a2;
	switch (tipo_indicador) {
		case 'c':
			cp_a0 = ca->CONSTANTEe_pool + constPool->u.Ref.indicador_nome - 1;
			if (cp_a0->tag != Classe_const) {
				puts("\nERRO: valor da tag invalido (Diferente de "
					 "Classe_const).\n");
				exit(EXIT_FAILURE);
			} else {
				cp_a0 = ca->CONSTANTEe_pool + cp_a0->u.Class.indicador_nome - 1;
				if (cp_a0->tag != CONSTANTE_Utf8) {
					puts("\nERRO: valor da tag invalido (Diferente de "
						 "CONSTANTE_Utf8).\n");
					exit(EXIT_FAILURE);
				} else {
					for (uint16_t i = 0; i < cp_a0->u.Utf8.length; i++) {
						fprintf(saida, "%c", cp_a0->u.Utf8.bytes[i]);
					}
				}
			}
			break;

		case 'n':
			cp_a0 = ca->CONSTANTEe_pool +
					constPool->u.Ref.indicador_nome_e_tipo - 1;
			if (cp_a0->tag != CONSTANTE_NameAndType) {
				puts("\nERRO: valor da tag invalido (Diferente de "
					 "CONSTANTE_NameAndType).\n");
				exit(EXIT_FAILURE);
			} else {
				cp_a2 = cp_a0;
				cp_a0 = ca->CONSTANTEe_pool +
						cp_a0->u.NameAndType.indicador_nome - 1;
				if (cp_a0->tag != CONSTANTE_Utf8) {
					puts("\nERRO: valor da tag invalido (Diferente de "
						 "CONSTANTE_Utf8).\n");
					exit(EXIT_FAILURE);
				} else {
					for (uint16_t i = 0; i < cp_a0->u.Utf8.length; i++) {
						fprintf(saida, "%c", cp_a0->u.Utf8.bytes[i]);
					}
				}
				cp_a2 = ca->CONSTANTEe_pool +
						cp_a2->u.NameAndType.descriptor_index - 1;
				if (cp_a2->tag != CONSTANTE_Utf8) {
					puts("\nERRO: valor da tag invalido (Diferente de "
						 "CONSTANTE_Utf8).\n");
					exit(EXIT_FAILURE);
				} else {
					for (uint16_t i = 0; i < cp_a2->u.Utf8.length; i++) {
						fprintf(saida, "%c", cp_a2->u.Utf8.bytes[i]);
					}
				}
			}
			break;
	}
}

// Imprime no arquivo de saida a CONSTANTEe_pool do ClasseDeArquivo
void mostrarConstPool(ClasseDeArquivo *ca, FILE *saida) {
	int64_t bits;
	fprintf(saida, "CONSTANTE Pool:\n");
	constPoolInf *constPool;
	uint16_t i;
	for (constPool = ca->CONSTANTEe_pool, i = 1;
		 constPool < (ca->CONSTANTEe_pool + ca->Cont_ConstPool - 1);
		 constPool++, i++) {
		switch (constPool->tag) {
			case Classe_const:
				fprintf(saida, "[%" PRIu16 "]\tCONSTANTE_Class_info\n", i);
				fprintf(saida, "\tNome da Classe:\t\tcp_info #%" PRIu16 "\t<",
						constPool->u.Class.indicador_nome);
				ImprimeCONSTANTEeClasse(ca, constPool, saida);
				fprintf(saida, ">\n\n");
				break;
			case CONSTANTEe_campo_referencia:
			case CONSTANTEe_metodo_referencia:
			case CONSTANTEe_Interface_referencia:
				if (constPool->tag == CONSTANTEe_campo_referencia)
					fprintf(saida,
							"[%" PRIu16 "]\tCONSTANTEe_campo_referencia\n",
							i);  //???PRI u16, que porra é essa?, faz uma
								 // leitura direta?
				else if (constPool->tag == CONSTANTEe_metodo_referencia)
					fprintf(saida,
							"[%" PRIu16 "]\tCONSTANTEe_metodo_referencia\n", i);
				else if (constPool->tag == CONSTANTEe_Interface_referencia)
					fprintf(saida,
							"[%" PRIu16 "]\tCONSTANTEe_Interface_referencia\n",
							i);

				fprintf(saida, "\tNome da classe:\t\tcp_info #%" PRIu16 "\t<",
						constPool->u.Ref.indicador_nome);
				ImprimeCONSTANTEeReferencia(ca, constPool, 'c', saida);
				fprintf(saida, ">\n\tNome e tipo:\t\tcp_info #%" PRIu16 "\t<",
						constPool->u.Ref.indicador_nome_e_tipo);
				ImprimeCONSTANTEeReferencia(ca, constPool, 'n', saida);
				fprintf(saida, ">\n\n");
				break;
			case CONSTANTE_String:
				fprintf(saida, "[%" PRIu16 "]\tCONSTANTE_String_info\n", i);
				fprintf(saida, "\tString:\t\t\tcp_info #%" PRIu16 "\t<",
						constPool->u.String.indicador_string);
				ImprimeCONSTANTEeString(ca, constPool, saida);
				fprintf(saida, ">\n\n");
				break;
			case CONSTANTE_Integer:
				fprintf(saida, "[%" PRIu16 "]\tCONSTANTE_Integer_info\n", i);
				fprintf(saida, "\tBytes:\t\t\t0x%.8" PRIx32,
						constPool->u.Integer_Float.bytes);
				fprintf(saida, "\n\tInteger:\t\t%" PRId32 "\n\n",
						constPool->u.Integer_Float.bytes);
				break;
			case CONSTANTE_Float:
				fprintf(saida, "[%" PRIu16 "]\tCONSTANTE_Float_info\n", i);
				fprintf(saida, "\tBytes:\t\t\t0x%.8" PRIx32,
						constPool->u.Integer_Float.bytes);
				float float_number;
				memcpy(&float_number, &constPool->u.Integer_Float.bytes,
					   sizeof(constPool->u.Integer_Float.bytes));
				fprintf(saida, "\n\tFloat:\t\t\t%f\n\n", float_number);
				break;
			case CONSTANTE_Long:
				fprintf(saida, "[%" PRIu16 "]\tCONSTANTE_Long_info\n", i);
				fprintf(saida, "\tHigh bytes:\t\t0x%.8" PRIx32,
						constPool->u.Long_Double.high_bytes);
				fprintf(saida, "\n\tLow bytes:\t\t0x%.8" PRIx32,
						constPool->u.Long_Double.low_bytes);
				bits = (((int64_t)constPool->u.Long_Double.high_bytes) << 32) +
					   constPool->u.Long_Double.low_bytes;
				fprintf(saida, "\n\tLong:\t\t\t%" PRId64 "\n\n", bits);
				fprintf(saida, "[%" PRIu16 "]\t(large numeric continued)\n\n",
						++i);
				constPool++;
				break;
			case CONSTANTE_Double:
				fprintf(saida, "[%" PRIu16 "]\tCONSTANTE_Double_info\n", i);
				fprintf(saida, "\tHigh bytes:\t\t0x%.8" PRIx32,
						constPool->u.Long_Double.high_bytes);
				fprintf(saida, "\n\tLow bytes:\t\t0x%.8" PRIx32,
						constPool->u.Long_Double.low_bytes);
				bits = (((int64_t)constPool->u.Long_Double.high_bytes) << 32) +
					   constPool->u.Long_Double.low_bytes;
				switch (bits) {
					case 0x7ff0000000000000L:
						fprintf(saida, "\n\tDouble:\t\t\t+8\n\n");
						break;
					case 0xfff0000000000000L:
						fprintf(saida, "\n\tDouble:\t\t\t-8\n\n");
						break;
					default:
						if ((bits >= 0x7ff0000000000001L &&
							 bits <= 0x7ffffffffffffL) ||
							(bits >= 0xfff0000000000001L &&
							 bits <= 0xffffffffffffffffL)) {
							fprintf(saida, "\n\tDouble:\t\t\tNaN\n\n");
						} else {
							int32_t s = ((bits >> 63) == 0) ? 1 : -1;
							int32_t e = ((bits >> 52) & 0x7ffL);
							int64_t m = (e == 0) ?
											(bits & 0xfffffffffffffL) << 1 :
											(bits & 0xfffffffffffffL) |
												0x10000000000000L;
							fprintf(saida, "\n\tDouble:\t\t\t%f\n\n",
									(double)s * m * pow(2, (e - 1075)));
						}
				}
				fprintf(saida, "[%" PRIu16 "]\t(large numeric continued)\n\n",
						++i);
				constPool++;
				break;
			case CONSTANTE_NameAndType:
				fprintf(saida, "[%" PRIu16 "]\tCONSTANTE_NameAndType_info\n",
						i);
				fprintf(saida, "\tNome:\t\t\tcp_info #%" PRIu16 "\t<",
						constPool->u.NameAndType.indicador_nome);
				ImprimeCONSTANTEeNomeTipo(ca, constPool, 'n', saida);
				fprintf(saida, ">\n\tDescritor:\t\tcp_info #%" PRIu16 "\t<",
						constPool->u.NameAndType.descriptor_index);
				ImprimeCONSTANTEeNomeTipo(ca, constPool, 'd', saida);
				fprintf(saida, ">\n\n");
				break;
			case CONSTANTE_Utf8:
				fprintf(saida, "[%" PRIu16 "]\tCONSTANTE_Utf8_info\n", i);
				fprintf(saida, "\tTamanho do array de byte:\t%" PRIu16,
						constPool->u.Utf8.length);
				fprintf(saida, "\n\tString:\t\t\t");
				ImprimeConstUtf8(constPool, saida);
				fprintf(saida, "\n\n");
				break;
		}
	}
}


void mostrarInterfaces(ClasseDeArquivo *ca, FILE *saida) {
	fprintf(saida, "Interfaces:\n\tQuantidade de interfaces:\t%" PRIu16 "\n\n",
			ca->interfaces_count);
	for (uint16_t i = 0; i < ca->interfaces_count; i++) {
		fprintf(saida, "Interface %" PRIu16, i);
		fprintf(saida, "\t\tcp_info #%" PRIu16, ca->interfaces[i]);
		if (ca->CONSTANTEe_pool[ca->interfaces[i] - 1].tag != Classe_const) {
			puts("\nERRO: interface nao referencia uma "
				 "CONSTANTE_Class_info.\n");
			exit(EXIT_FAILURE);
		} else {
			uint16_t indicador_nome;
			constPoolInf *constPool;

			indicador_nome = ca->CONSTANTEe_pool[ca->interfaces[i] - 1]
								 .u.Class.indicador_nome;
			constPool = ca->CONSTANTEe_pool + indicador_nome - 1;
			if (constPool->tag != CONSTANTE_Utf8) {
				puts("\nERRO: interface nao referencia um class_name_index "
					 "valido.\n");
				exit(EXIT_FAILURE);
			} else {
				fprintf(saida, "\t<");
				ImprimeConstUtf8(constPool, saida);
				fprintf(saida, ">\n\n");
			}
		}
	}
}

void mostrarCampos(ClasseDeArquivo *ca, FILE *saida) {
	fprintf(saida, "Fields:\nQuantidade de fields:\t\t%" PRIu16 "\n",
			ca->conts_campos);
	for (uint16_t i = 0; i < ca->conts_campos; i++) {
		fprintf(saida, "\n");
		uint16_t indicador_nome = (ca->fields + i)->indicador_nome;
		constPoolInf *constPool = ca->CONSTANTEe_pool + indicador_nome - 1;
		if (constPool->tag != CONSTANTE_Utf8) {
			puts("\nERRO: field nao referencia um indicador_nome valido.\n");
			exit(EXIT_FAILURE);
		}
		fprintf(saida, "[%" PRIu16 "]\t", i);
		ImprimeConstUtf8(constPool, saida);
		fprintf(saida, "\n");

		fprintf(saida, "\tNome:\t\t\tcp_info #%" PRIu16,
				(ca->fields + i)->indicador_nome);
		fprintf(saida, "\t<");
		ImprimeConstUtf8(constPool, saida);
		fprintf(saida, ">\n");

		uint16_t descriptor_index = (ca->fields + i)->descriptor_index;
		constPool = ca->CONSTANTEe_pool + descriptor_index - 1;
		if (constPool->tag != CONSTANTE_Utf8) {
			puts("\nERRO: field nao referencia um descriptor_index valido.\n");
			exit(EXIT_FAILURE);
		}
		fprintf(saida, "\tDescritor:\t\tcp_info #%" PRIu16,
				(ca->fields + i)->descriptor_index);
		fprintf(saida, "\t<");
		ImprimeConstUtf8(constPool, saida);
		fprintf(saida, ">\n");


		fprintf(saida, "\tFlags de Acesso:\t\t0x%.4" PRIx16 "\t\t[",
				(ca->fields + i)->flags_acesso);
		uint16_t flags_acesso = (ca->fields + i)->flags_acesso;
		if (flags_acesso >= 0x80) {
			fprintf(saida, "transient ");
			flags_acesso -= 0x80;
		}
		if (flags_acesso >= 0x40) {
			fprintf(saida, "volatile");
			flags_acesso -= 0x40;
		}
		if (flags_acesso >= FLAG_FINAL) {
			fprintf(saida, "final ");
			flags_acesso -= FLAG_FINAL;
		}
		if (flags_acesso >= 0x8) {
			fprintf(saida, "static ");
			flags_acesso -= 0x8;
		}
		if (flags_acesso >= 0x4) {
			fprintf(saida, "protected ");
			flags_acesso -= 0x4;
		}
		if (flags_acesso >= 0x2) {
			fprintf(saida, "private ");
			flags_acesso -= 0x2;
		}
		if (flags_acesso >= FLAG_PUBLIC) {
			fprintf(saida, "public");
			flags_acesso -= FLAG_PUBLIC;
		}
		fprintf(saida, "]\n");

		fprintf(saida, "\n\tField's attributes count:\t%" PRIu16 "\n",
				(ca->fields + i)->conts_atributos);
		field_info *fd_in = (ca->fields + i);
		mostrarAtributos(fd_in, NULL, NULL, ca, saida);
	}
	fprintf(saida, "\n");
}

void mostrarMetodos(ClasseDeArquivo *ca, FILE *saida) {
	fprintf(saida, "Metodos:\nQuantidade de metodos:\t\t%" PRIu16 "\n",
			ca->conts_metodo);
	for (uint16_t i = 0; i < ca->conts_metodo; i++) {
		fprintf(saida, "\n");
		uint16_t indicador_nome = (ca->methods + i)->indicador_nome;
		constPoolInf *constPool = ca->CONSTANTEe_pool + indicador_nome - 1;
		if (constPool->tag != CONSTANTE_Utf8) {
			puts("\nERRO: metodo nao possui um indicador_nome valido.\n");
			exit(EXIT_FAILURE);
		}
		fprintf(saida, "[%" PRIu16 "]\t", i);
		ImprimeConstUtf8(constPool, saida);
		fprintf(saida, "\n");

		fprintf(saida, "Nome:\t\t\tcp_info #%" PRIu16,
				(ca->methods + i)->indicador_nome);
		fprintf(saida, "\t<");
		ImprimeConstUtf8(constPool, saida);
		fprintf(saida, ">\n");

		fprintf(saida, "Descritor:\t\tcp_info #%" PRIu16,
				(ca->methods + i)->descriptor_index);
		uint16_t descriptor_index = (ca->methods + i)->descriptor_index;
		constPool = ca->CONSTANTEe_pool + descriptor_index - 1;
		if (constPool->tag != CONSTANTE_Utf8) {
			puts("\nERRO: metodo nao possui um descriptor_index valido.\n");
			exit(EXIT_FAILURE);
		} else {
			fprintf(saida, "\t<");
			ImprimeConstUtf8(constPool, saida);
			fprintf(saida, ">\n");
		}

		fprintf(saida, "Flags de Acesso:\t\t0x%.4" PRIx16 "\t\t[",
				(ca->methods + i)->flags_acesso);
		uint16_t flags_acesso = (ca->methods + i)->flags_acesso;
		if (flags_acesso >= 0x800) {
			fprintf(saida, "strict ");
			flags_acesso -= 0x800;
		}
		if (flags_acesso >= FLAG_ABSTRATA) {
			fprintf(saida, "abstrato ");
			flags_acesso -= FLAG_ABSTRATA;
		}
		if (flags_acesso >= 0x100) {
			fprintf(saida, "native ");
			flags_acesso -= 0x100;
		}
		if (flags_acesso >= FLAG_SUPER) {
			fprintf(saida, "synchronized ");
			flags_acesso -= FLAG_SUPER;
		}
		if (flags_acesso >= FLAG_FINAL) {
			fprintf(saida, "final ");
			flags_acesso -= FLAG_FINAL;
		}
		if (flags_acesso >= 0x8) {
			fprintf(saida, "static ");
			flags_acesso -= 0x8;
		}
		if (flags_acesso >= 0x4) {
			fprintf(saida, "protected ");
			flags_acesso -= 0x4;
		}
		if (flags_acesso >= 0x2) {
			fprintf(saida, "private ");
			flags_acesso -= 0x2;
		}
		if (flags_acesso >= FLAG_PUBLIC) {
			fprintf(saida, "public");
			flags_acesso -= FLAG_PUBLIC;
		}
		fprintf(saida, "]\n");

		fprintf(saida, "\nContador de atributos do metodo:\t%" PRIu16 "\n",
				(ca->methods + i)->conts_atributos);
		method_info *mt_in = (ca->methods + i);
		mostrarAtributos(NULL, mt_in, NULL, ca, saida);
	}
}

void mostrarAtributos(field_info *fd_in, method_info *mt_in,
					  attribute_info *attr_in, ClasseDeArquivo *ca,
					  FILE *saida) {
	uint16_t conts_atributos;
	attribute_info *attributes;
	int attribute_tab;

	if (fd_in != NULL) {
		conts_atributos = fd_in->conts_atributos;
		attributes = fd_in->attributes;
		attribute_tab = METHOD_FIELD;
	} else if (mt_in != NULL) {
		conts_atributos = mt_in->conts_atributos;
		attributes = mt_in->attributes;
		attribute_tab = METHOD_FIELD;
	} else if (attr_in != NULL) {
		conts_atributos = attr_in->u.Code.conts_atributos;
		attributes = attr_in->u.Code.attributes;
		attribute_tab = ATTRIBUTE;
	} else if (ca != NULL) {
		fprintf(saida, "Atributos da Classe:");
		fprintf(saida, "\nQuantidade de atributos da classe:\t%" PRIu16 "\n",
				ca->conts_atributos);
		conts_atributos = ca->conts_atributos;
		attributes = ca->attributes;
		attribute_tab = CLASS;
	}

	uint16_t indicador_nome;
	constPoolInf *constPool;
	attribute_info *attributes_aux = attributes;
	for (uint16_t i = 0; i < conts_atributos; i++) {
		indicador_nome = attributes_aux->attribute_name_index;
		constPool = ca->CONSTANTEe_pool + indicador_nome - 1;
		if (constPool->tag != CONSTANTE_Utf8) {
			puts("\nERRO: atributo nao referencia um indicador_nome valido.\n");
			exit(EXIT_FAILURE);
		}

		switch (attribute_tab) {
			case CLASS:
				fprintf(saida, "\n");
				fprintf(saida, "[%" PRIu16 "]\t", i);
				ImprimeConstUtf8(constPool, saida);
				fprintf(saida, "\n");

				fprintf(saida, "Informacoes gerais:\n");
				fprintf(saida,
						"\tIndice do nome do atributo:\tcp_info #%" PRIu16,
						attributes_aux->attribute_name_index);
				fprintf(saida, "\t");
				ImprimeConstUtf8(constPool, saida);
				fprintf(saida, "\n");

				fprintf(saida, "\tTamanho do atributo:\t%" PRIu16 "\n",
						attributes_aux->attribute_length);
				fprintf(saida, "Informacoes especificas:\n");
				break;
			case METHOD_FIELD:
				fprintf(saida, "\n");
				fprintf(saida, "[%" PRIu16 "]", i);
				fprintf(saida, "\t");
				ImprimeConstUtf8(constPool, saida);
				fprintf(saida, "\n");

				fprintf(saida, "\tInformacoes gerais:\n");
				fprintf(saida,
						"\t\tIndice do nome do atributo:\tcp_info #%" PRIu16,
						attributes_aux->attribute_name_index);
				fprintf(saida, "\t");
				ImprimeConstUtf8(constPool, saida);
				fprintf(saida, "\n");

				fprintf(saida, "\t\tTamanho do atributo:\t%" PRIu16 "\n",
						attributes_aux->attribute_length);
				fprintf(saida, "\tInformacoes especificas:\n");
				break;
			case ATTRIBUTE:
				fprintf(saida, "\n");
				fprintf(saida, "\t[%" PRIu16 "]", i);
				fprintf(saida, "\t");
				ImprimeConstUtf8(constPool, saida);
				fprintf(saida, "\n");

				fprintf(saida, "\t\tInformacoes gerais:\n");
				fprintf(saida,
						"\t\t\tIndice do nome do atributo:\tcp_info #%" PRIu16,
						attributes_aux->attribute_name_index);
				fprintf(saida, "\t");
				ImprimeConstUtf8(constPool, saida);
				fprintf(saida, "\n");

				fprintf(saida, "\t\t\tTamanho do atributo:\t%" PRIu16 "\n",
						attributes_aux->attribute_length);
				fprintf(saida, "\t\tInformacoes especificas:\n");
				break;
		}
		constPoolInf *cp_a0;
		int64_t bits;
		int32_t branch;
		switch (getTipoAtributo(attributes_aux, ca)) {
			case CONSTANTE_VALUE:;
				uint16_t CONSTANTEvalue_index =
					attributes_aux->u.CONSTANTEValue.CONSTANTEvalue_index;
				fprintf(saida, "\t\tCONSTANTE value index:\tcp_info #%" PRIu16,
						CONSTANTEvalue_index);
				cp_a0 = ca->CONSTANTEe_pool + CONSTANTEvalue_index - 1;
				switch (cp_a0->tag) {
					case CONSTANTE_Integer:
						fprintf(saida, "\t<%" PRId32 ">\n",
								cp_a0->u.Integer_Float.bytes);
						break;
					case CONSTANTE_Long:
						bits =
							(((int64_t)cp_a0->u.Long_Double.high_bytes) << 32) +
							cp_a0->u.Long_Double.low_bytes;
						fprintf(saida, "\t<%" PRId64 ">\n", bits);
						break;
					case CONSTANTE_Float:;
						float float_number;
						memcpy(&float_number, &cp_a0->u.Integer_Float.bytes,
							   sizeof(uint32_t));
						fprintf(saida, "\t<%f>\n", float_number);
						break;
					case CONSTANTE_Double:
						bits =
							(((int64_t)cp_a0->u.Long_Double.high_bytes) << 32) +
							cp_a0->u.Long_Double.low_bytes;
						switch (bits) {
							case 0x7ff0000000000000L:
								fprintf(saida, "\t<+8>\n");
								break;
							case 0xfff0000000000000L:
								fprintf(saida, "\t<-8>\n");
								break;
							default:
								if ((bits >= 0x7ff0000000000001L &&
									 bits <= 0x7ffffffffffffL) ||
									(bits >= 0xfff0000000000001L &&
									 bits <= 0xffffffffffffffffL)) {
									fprintf(saida, "\t<NaN>\n");
								} else {
									int32_t s = ((bits >> 63) == 0) ? 1 : -1;
									int32_t e = ((bits >> 52) & 0x7ffL);
									int64_t m = (e == 0) ?
													(bits & 0xfffffffffffffL)
														<< 1 :
													(bits & 0xfffffffffffffL) |
														0x10000000000000L;
									fprintf(saida, "\t<%f>\n",
											(double)s * m * pow(2, (e - 1075)));
								}
						}
						break;
					case CONSTANTE_String:
						fprintf(saida, "\t<");
						ImprimeCONSTANTEeString(ca, cp_a0, saida);
						fprintf(saida, ">\n");
						break;
				}
				break;
			case CODE:
				fprintf(saida, "\t\tBytecode:\n");
				fprintf(saida, "\t\t\tlinha\n");
				uint8_t *nextCode;
				uint32_t lineNumber = 1;
				uint16_t index;
				uint32_t i;
				int32_t default_, n;
				int16_t const_;

				for (uint32_t offset = 0;
					 offset < attributes_aux->u.Code.code_length;) {
					fprintf(saida, "\t\t\t%" PRIu32 "\t", lineNumber++);
					nextCode = attributes_aux->u.Code.code + offset;
					switch (*nextCode) {
						// 0 bytes
						case aaload:
						case aastore:
						case aconst_null:
						case aload_0:
						case aload_1:
						case aload_2:
						case aload_3:
						case areturn:
						case arraylength:
						case astore_0:
						case astore_1:
						case astore_2:
						case astore_3:
						case athrow:
						case baload:
						case bastore:
						case breakpoint:
						case caload:
						case castore:
						case d2f:
						case d2i:
						case d2l:
						case dadd:
						case daload:
						case dastore:
						case dcmpg:
						case dcmpl:
						case dconst_0:
						case dconst_1:
						case ddiv:
						case dload_0:
						case dload_1:
						case dload_2:
						case dload_3:
						case dmul:
						case dneg:
						case drem:
						case dreturn:
						case dstore_0:
						case dstore_1:
						case dstore_2:
						case dstore_3:
						case dsub:
						case dup:
						case dup_x1:
						case dup_x2:
						case dup2:
						case dup2_x1:
						case dup2_x2:
						case f2d:
						case f2i:
						case f2l:
						case fadd:
						case faload:
						case fastore:
						case fcmpg:
						case fcmpl:
						case fconst_0:
						case fconst_1:
						case fconst_2:
						case fdiv:
						case fload_0:
						case fload_1:
						case fload_2:
						case fload_3:
						case fmul:
						case fneg:
						case frem:
						case freturn:
						case fstore_0:
						case fstore_1:
						case fstore_2:
						case fstore_3:
						case fsub:
						case i2b:
						case i2c:
						case i2d:
						case i2f:
						case i2l:
						case i2s:
						case iadd:
						case iaload:
						case iand:
						case iastore:
						case iconst_m1:
						case iconst_0:
						case iconst_1:
						case iconst_2:
						case iconst_3:
						case iconst_4:
						case iconst_5:
						case idiv:
						case iload_0:
						case iload_1:
						case iload_2:
						case iload_3:
						case impdep1:
						case impdep2:
						case imul:
						case ineg:
						case ior:
						case irem:
						case ireturn:
						case ishl:
						case ishr:
						case istore_0:
						case istore_1:
						case istore_2:
						case istore_3:
						case isub:
						case iushr:
						case ixor:
						case l2d:
						case l2f:
						case l2i:
						case ladd:
						case laload:
						case land:
						case lastore:
						case lcmp:
						case lconst_0:
						case lconst_1:
						case ldiv_:
						case lload_0:
						case lload_1:
						case lload_2:
						case lload_3:
						case lmul:
						case lneg:
						case lor:
						case lrem:
						case lreturn:
						case lshl:
						case lshr:
						case lstore_0:
						case lstore_1:
						case lstore_2:
						case lstore_3:
						case lsub:
						case lushr:
						case lxor:
						case monitorenter:
						case monitorexit:
						case nop:
						case pop:
						case pop2:
						case return_:
						case saload:
						case sastore:
						case swap:
							fprintf(saida, "%s\n", op_codesJVM[*nextCode]);
							offset++;
							break;
						// 1 byte
						//	local variable index (uint8_t)
						case aload:
						case astore:
						case dload:
						case dstore:
						case fload:
						case fstore:
						case iload:
						case istore:
						case lload:
						case lstore:
						case ret:
							fprintf(saida, "%s", op_codesJVM[*nextCode]);
							fprintf(saida, "\t%" PRIu8 "\n", *(nextCode + 1));
							offset += 2;
							break;

						//	signed integer (s1)
						case bipush:
							fprintf(saida, "%s", op_codesJVM[*nextCode]);
							fprintf(saida, "\t%" PRId8 "\n", *(nextCode + 1));
							offset += 2;
							break;

						//	array type (uint8_t)
						case newarray:
							fprintf(saida, "%s\t", op_codesJVM[*nextCode]);
							fprintf(saida, "%" PRId8, *(nextCode + 1));
							switch (*(nextCode + 1)) {
								case T_BOOLEAN:
									fprintf(saida, " (boolean)\n");
									break;
								case T_CHAR:
									fprintf(saida, " (char)\n");
									break;
								case T_FLOAT:
									fprintf(saida, " (float)\n");
									break;
								case T_DOUBLE:
									fprintf(saida, " (double)\n");
									break;
								case T_BYTE:
									fprintf(saida, " (byte)\n");
									break;
								case T_SHORT:
									fprintf(saida, " (short)\n");
									break;
								case T_INT:
									fprintf(saida, " (int)\n");
									break;
								case T_LONG:
									fprintf(saida, " (long\n");
									break;
								default:
									printf("ERRO: newarray aplicado tipo "
										   "invalido.\n");
									exit(EXIT_FAILURE);
									break;
							}
							offset += 2;
							break;

						//	CONSTANTE pool index (integer, float, string)
						//(uint8_t)
						case ldc:
							fprintf(saida, "%s", op_codesJVM[*nextCode]);
							fprintf(saida, "\t#%" PRIu8, *(nextCode + 1));
							cp_a0 = ca->CONSTANTEe_pool + *(nextCode + 1) - 1;
							switch (cp_a0->tag) {
								case CONSTANTE_Integer:
									fprintf(saida, "\t<%" PRId32 ">\n",
											cp_a0->u.Integer_Float.bytes);
									break;
								case CONSTANTE_Float:;
									float float_number;
									memcpy(&float_number,
										   &cp_a0->u.Integer_Float.bytes,
										   sizeof(uint32_t));
									fprintf(saida, "\t<%f>\n", float_number);
									break;
								case CONSTANTE_String:
									fprintf(saida, "\t<");
									ImprimeCONSTANTEeString(ca, cp_a0, saida);
									fprintf(saida, ">\n");
									break;
								default:
									puts("ERRO: instrucaoo ldc com argumento "
										 "invalido\n");
									exit(EXIT_FAILURE);
							}
							offset += 2;
							break;

						// 2 bytes
						//	CONSTANTEe_pool index (class) (uint16_t)
						case anewarray:
						case checkcast:
						case instanceof:
						case new:
							fprintf(saida, "%s", op_codesJVM[*nextCode]);
							index = (uint16_t)(*(nextCode + 1) << 8) +
									*(nextCode + 2);
							fprintf(saida, "\t#%" PRIu16, index);
							cp_a0 = ca->CONSTANTEe_pool + index - 1;
							if (cp_a0->tag != Classe_const) {
								printf("\nERRO: %s nao referencia um "
									   "Classe_const valido.\n",
									   op_codesJVM[*nextCode]);
								exit(EXIT_FAILURE);
							} else {
								uint16_t indicador_nome =
									cp_a0->u.Class.indicador_nome;
								cp_a0 =
									ca->CONSTANTEe_pool + indicador_nome - 1;

								fprintf(saida, "\t<");
								ImprimeConstUtf8(cp_a0, saida);
								fprintf(saida, ">\n");
							}
							offset += 3;
							break;

						//	branch offset (s2)
						case goto_:
						case if_acmpeq:
						case if_acmpne:
						case if_icmpeq:
						case if_icmpge:
						case if_icmpgt:
						case if_icmple:
						case if_icmplt:
						case if_icmpne:
						case ifeq:
						case ifge:
						case ifgt:
						case ifle:
						case iflt:
						case ifne:
						case ifnonnull:
						case ifnull:
						case jsr:
							fprintf(saida, "%s", op_codesJVM[*nextCode]);
							branch = ((int8_t) * (nextCode + 1) << 8) +
									 *(nextCode + 2);
							fprintf(saida, "\t%" PRId32 "\t(%+" PRId32 ")\n",
									(int32_t)offset + branch, branch);
							offset += 3;
							break;

						//	CONSTANTE pool index (integer, float, string)
						//(uint16_t)
						case ldc_w:
							fprintf(saida, "%s", op_codesJVM[*nextCode]);
							index = (uint16_t)(*(nextCode + 1) << 8) +
									*(nextCode + 2);
							fprintf(saida, "\t#%" PRIu16 "\n", index);
							cp_a0 = ca->CONSTANTEe_pool + *(nextCode + 1) - 1;
							switch (cp_a0->tag) {
								case CONSTANTE_Integer:
									fprintf(saida, "\t<%" PRId32 ">\n",
											cp_a0->u.Integer_Float.bytes);
									break;
								case CONSTANTE_Float:;
									float float_number;
									memcpy(&float_number,
										   &cp_a0->u.Integer_Float.bytes,
										   sizeof(uint32_t));
									fprintf(saida, "\t<%f>\n", float_number);
									break;
								case CONSTANTE_String:
									fprintf(saida, "\t<");
									ImprimeCONSTANTEeString(ca, cp_a0, saida);
									fprintf(saida, ">\n");
									break;
								default:
									puts("ERRO: instrucao ldc_w com argumento "
										 "invalido\n");
									exit(EXIT_FAILURE);
							}
							offset += 3;
							break;

						//	CONSTANTE pool index (fieldref; methodref)
						//(uint16_t)
						case getfield:
						case getstatic:
						case invokespecial:
						case invokestatic:
						case invokevirtual:
						case putfield:
						case putstatic:
							fprintf(saida, "%s", op_codesJVM[*nextCode]);
							index = (uint16_t)(*(nextCode + 1) << 8) +
									*(nextCode + 2);
							fprintf(saida, "\t#%" PRIu16, index);
							cp_a0 = ca->CONSTANTEe_pool + index - 1;
							if (cp_a0->tag != CONSTANTEe_metodo_referencia &&
								cp_a0->tag != CONSTANTEe_campo_referencia) {
								printf("\nERRO: %s nao referencia um "
									   "CONSTANTE_ref valido.\n",
									   op_codesJVM[*nextCode]);
								exit(EXIT_FAILURE);
							} else {
								uint16_t indicador_nome =
									cp_a0->u.Ref.indicador_nome;
								uint16_t indicador_nome_e_tipo =
									cp_a0->u.Ref.indicador_nome_e_tipo;

								cp_a0 =
									ca->CONSTANTEe_pool + indicador_nome - 1;
								if (cp_a0->tag != Classe_const) {
									printf("\nERRO: %s nao referencia um "
										   "CONSTANTE_ref valido.\n",
										   op_codesJVM[*nextCode]);
									exit(EXIT_FAILURE);
								} else {
									uint16_t indicador_nome =
										cp_a0->u.Class.indicador_nome;
									cp_a0 = ca->CONSTANTEe_pool +
											indicador_nome - 1;

									fprintf(saida, "\t<");
									ImprimeConstUtf8(cp_a0, saida);

									cp_a0 = ca->CONSTANTEe_pool +
											indicador_nome_e_tipo - 1;
									if (cp_a0->tag != CONSTANTE_NameAndType) {
										printf("\nERRO: %s nao referencia um "
											   "CONSTANTE_ref valido.\n",
											   op_codesJVM[*nextCode]);
										exit(EXIT_FAILURE);
									} else {
										indicador_nome =
											cp_a0->u.NameAndType.indicador_nome;
										cp_a0 = ca->CONSTANTEe_pool +
												indicador_nome - 1;

										fprintf(saida, ".");
										ImprimeConstUtf8(cp_a0, saida);
										fprintf(saida, ">\n");
									}
								}
							}
							offset += 3;
							break;

						//	CONSTANTE pool index (long, double) (uint16_t)
						case ldc2_w:
							fprintf(saida, "%s", op_codesJVM[*nextCode]);
							index = (uint16_t)(*(nextCode + 1) << 8) +
									*(nextCode + 2);
							fprintf(saida, "\t#%" PRIu16, index);
							cp_a0 = ca->CONSTANTEe_pool + index - 1;
							switch (cp_a0->tag) {
								case CONSTANTE_Long:
									bits =
										(((int64_t)cp_a0->u.Long_Double.high_bytes)
										 << 32) +
										cp_a0->u.Long_Double.low_bytes;
									fprintf(saida, "\t<%" PRId64 ">\n", bits);
									break;
								case CONSTANTE_Double:
									bits =
										(((int64_t)cp_a0->u.Long_Double.high_bytes)
										 << 32) +
										cp_a0->u.Long_Double.low_bytes;
									switch (bits) {
										case 0x7ff0000000000000L:
											fprintf(saida, "\t<+8>\n");
											break;
										case 0xfff0000000000000L:
											fprintf(saida, "\t<-8>\n");
											break;
										default:
											if ((bits >= 0x7ff0000000000001L &&
												 bits <= 0x7ffffffffffffL) ||
												(bits >= 0xfff0000000000001L &&
												 bits <= 0xffffffffffffffffL)) {
												fprintf(saida, "\t<NaN>\n");
											} else {
												int32_t s =
													((bits >> 63) == 0) ? 1 :
																		  -1;
												int32_t e =
													((bits >> 52) & 0x7ffL);
												int64_t m =
													(e == 0) ?
														(bits & 0xfffffffffffffL)
															<< 1 :
														(bits &
														 0xfffffffffffffL) |
															0x10000000000000L;
												fprintf(saida, "\t<%f>\n",
														(double)s * m *
															pow(2, (e - 1075)));
											}
									}
									break;
								default:
									puts("ERRO: instrucao ldc2_w com argumento "
										 "invalido\n");
									exit(EXIT_FAILURE);
							}
							offset += 3;
							break;

						//	signed short (s2)
						case sipush:
							fprintf(saida, "%s", op_codesJVM[*nextCode]);
							fprintf(saida, "\t%" PRId16 "\n", *(nextCode + 1));
							offset += 3;
							break;

						//	unsigned byte (uint8_t); signed byte (s1)
						case iinc:  // 1 byte 1 byte
							fprintf(saida, "%s", op_codesJVM[*nextCode]);
							fprintf(saida, "\t%" PRIu8, *(nextCode + 1));
							fprintf(saida, " by %" PRId8 "\n", *(nextCode + 2));
							offset += 3;
							break;
						// 3 bytes
						// CONSTANTEe_pool index (class) (uint16_t) ; unsigned
						// byte (uint8_t)
						case multianewarray:
							fprintf(saida, "%s", op_codesJVM[*nextCode]);
							index = (uint16_t)(*(nextCode + 1) << 8) +
									*(nextCode + 2);
							fprintf(saida, "\t#%" PRIu16, index);
							cp_a0 = ca->CONSTANTEe_pool + index - 1;
							if (cp_a0->tag != Classe_const) {
								printf("\nERRO: %s nao referencia um "
									   "Classe_const valido.\n",
									   op_codesJVM[*nextCode]);
								exit(EXIT_FAILURE);
							} else {
								uint16_t indicador_nome =
									cp_a0->u.Class.indicador_nome;
								cp_a0 =
									ca->CONSTANTEe_pool + indicador_nome - 1;

								fprintf(saida, "\t<");
								ImprimeConstUtf8(cp_a0, saida);
								fprintf(saida, ">");
							}
							fprintf(saida, "\tdim %" PRIu8 "\n",
									*(nextCode + 3));
							offset += 4;
							break;

						// 4 bytes
						// branch offset (uint32_t)
						case goto_w:
						case jsr_w:
							fprintf(saida, "%s", op_codesJVM[*nextCode]);
							branch = ((uint32_t) * (nextCode + 1) << 24) +
									 ((uint32_t) * (nextCode + 2) << 16) +
									 ((uint32_t) * (nextCode + 3) << 8) +
									 *(nextCode + 4);
							fprintf(saida, "\t%" PRIu32 "\t(+%" PRIu32 ")\n",
									offset + branch, branch);
							offset += 5;
							break;

						// CONSTANTEe_pool index (uint16_t); unsigned byte
						// (uint8_t); unsigned byte (uint8_t)
						case invokeinterface:
						case invokedynamic:
							fprintf(saida, "%s", op_codesJVM[*nextCode]);
							index = (uint16_t)(*(nextCode + 1) << 8) +
									*(nextCode + 2);
							fprintf(saida, "\t#%" PRIu16, index);
							cp_a0 = ca->CONSTANTEe_pool + index - 1;
							if (cp_a0->tag != CONSTANTEe_Interface_referencia &&
								cp_a0->tag != CONSTANTEe_metodo_referencia) {
								printf("\nERRO: %s nao referencia um "
									   "CONSTANTE_ref valido.\n",
									   op_codesJVM[*nextCode]);
								exit(EXIT_FAILURE);
							} else {
								uint16_t indicador_nome =
									cp_a0->u.Ref.indicador_nome;
								uint16_t indicador_nome_e_tipo =
									cp_a0->u.Ref.indicador_nome_e_tipo;

								cp_a0 =
									ca->CONSTANTEe_pool + indicador_nome - 1;
								if (cp_a0->tag != Classe_const) {
									printf("\nERRO: %s nao referencia um "
										   "CONSTANTE_ref valido.\n",
										   op_codesJVM[*nextCode]);
									exit(EXIT_FAILURE);
								} else {
									uint16_t indicador_nome =
										cp_a0->u.Class.indicador_nome;
									cp_a0 = ca->CONSTANTEe_pool +
											indicador_nome - 1;

									fprintf(saida, "\t<");
									ImprimeConstUtf8(cp_a0, saida);

									cp_a0 = ca->CONSTANTEe_pool +
											indicador_nome_e_tipo - 1;
									if (cp_a0->tag != CONSTANTE_NameAndType) {
										printf("\nERRO: %s nao referencia um "
											   "CONSTANTE_ref valido.\n",
											   op_codesJVM[*nextCode]);
										exit(EXIT_FAILURE);
									} else {
										indicador_nome =
											cp_a0->u.NameAndType.indicador_nome;
										cp_a0 = ca->CONSTANTEe_pool +
												indicador_nome - 1;

										fprintf(saida, ".");
										ImprimeConstUtf8(cp_a0, saida);
										fprintf(saida, ">");
									}
									fprintf(saida, "\t<%" PRIu8 ">\n",
											*(nextCode + 3));
								}
							}
							offset += 5;
							break;

						// 4 ou + bytes
						//	<0-3 byte pad>; default (s4); n (s4); key1,
						// offset_label1 ... keyn, offset_labeln (s4)
						case lookupswitch:
							fprintf(saida, "%s", op_codesJVM[*nextCode]);
							i = (offset + 1) % 4;
							default_ = (*((1 + i) + nextCode) << 24) |
									   (*((2 + i) + nextCode) << 16) |
									   (*((3 + i) + nextCode) << 8) |
									   *((4 + i) + nextCode);

							n = (*((5 + i) + nextCode) << 24) |
								(*((6 + i) + nextCode) << 16) |
								(*((7 + i) + nextCode) << 8) |
								*((8 + i) + nextCode);
							i += 8;
							fprintf(saida, "\t%" PRId32 "\n", n);

							int32_t key, offset_label;
							for (uint32_t j = 0; j < n; j++) {
								fprintf(saida, "\t\t\t\t\t%" PRIu32,
										lineNumber++);
								key = (*((1 + i) + nextCode) << 24) |
									  (*((2 + i) + nextCode) << 16) |
									  (*((3 + i) + nextCode) << 8) |
									  *((4 + i) + nextCode);
								i += 4;
								fprintf(saida, "\t\t\t%" PRId32, key);
								offset_label = (*((1 + i) + nextCode) << 24) |
											   (*((2 + i) + nextCode) << 16) |
											   (*((3 + i) + nextCode) << 8) |
											   *((4 + i) + nextCode);
								i += 4;
								fprintf(saida,
										":\t%" PRId32 " (%+" PRId32 ")\n",
										offset + offset_label, offset_label);
							}
							fprintf(saida, "\t\t\t\t\t%" PRIu32, lineNumber++);
							fprintf(saida, "\t\t\tdefault:\t%" PRId32
										   " (+%" PRId32 ")\n",
									offset + default_, default_);
							offset += i;
							offset++;
							break;

						//	<0-3 byte pad>; default (s4); low (s4); high (s4);
						// label1 ... labeln (s4)
						case tableswitch:
							fprintf(saida, "%s", op_codesJVM[*nextCode]);
							i = (offset + 1) % 4;
							default_ = (*((1 + i) + nextCode) << 24) |
									   (*((2 + i) + nextCode) << 16) |
									   (*((3 + i) + nextCode) << 8) |
									   *((4 + i) + nextCode);

							int32_t low = (*((5 + i) + nextCode) << 24) |
										  (*((6 + i) + nextCode) << 16) |
										  (*((7 + i) + nextCode) << 8) |
										  *((8 + i) + nextCode);

							int32_t high = (*((9 + i) + nextCode) << 24) |
										   (*((10 + i) + nextCode) << 16) |
										   (*((11 + i) + nextCode) << 8) |
										   *((12 + i) + nextCode);

							i += 12;
							fprintf(saida, "\t%" PRId32 " to %" PRId32 "\n",
									low, high);

							n = high - low + 1;

							int32_t label;
							for (uint32_t j = 0; j < n; j++) {
								fprintf(saida, "\t\t\t\t\t%" PRIu32,
										lineNumber++);
								label = (*((1 + i) + nextCode) << 24) |
										(*((2 + i) + nextCode) << 16) |
										(*((3 + i) + nextCode) << 8) |
										*((4 + i) + nextCode);
								i += 4;
								fprintf(saida, "\t\t\t%" PRId32 ":\t%" PRId32
											   " (%+" PRId32 ")\n",
										j, offset + label, label);
							}
							fprintf(saida, "\t\t\t\t\t%" PRIu32, lineNumber++);
							fprintf(saida, "\t\t\tdefault:\t%" PRId32
										   " (%+" PRId32 ")\n",
									offset + default_, default_);
							offset += i;
							offset++;
							break;
						// 3 ou 5 bytes
						case wide:
							fprintf(saida, "%s", op_codesJVM[*nextCode]);
							fprintf(saida, "\t\t\t\t\t%" PRIu32, lineNumber++);
							fprintf(saida, "%s", op_codesJVM[*(nextCode + 1)]);
							index = (uint16_t)(*(nextCode + 2) << 8) +
									*(nextCode + 3);
							fprintf(saida, "\t%" PRIu16, index);
							switch (*(nextCode + 1)) {
								case aload:
								case dload:
								case iload:
								case fload:
								case lload:
								case astore:
								case dstore:
								case istore:
								case fstore:
								case lstore:
								case ret:
									offset += 4;
									break;
								case iinc:
									const_ = (uint16_t)(*(nextCode + 4) << 8) +
											 *(nextCode + 5);
									fprintf(saida, "\t%" PRId16, const_);
									offset += 6;
									break;
								default:
									printf("ERRO: wide aplicado a uma "
										   "instrucao invalida\n");
									exit(EXIT_FAILURE);
							}
							fprintf(saida, "\n");
							break;
					}
				}
				fprintf(saida, "\n\t\t\tTamanho da Tabela de "
							   "Excecoes:\t\t%" PRId16 "\n",
						attributes_aux->u.Code.exception_table_length);
				if (attributes_aux->u.Code.exception_table_length) {
					fprintf(saida, "\n\t\t\tException table:\n");
					fprintf(saida, "\t\t\tNr.\tstart_pc\tend_pc\thandler_"
								   "pc\tcatch_type\tverbose\n");
					for (uint16_t i = 0;
						 i < attributes_aux->u.Code.exception_table_length;
						 i++) {
						fprintf(saida, "\t\t\t%" PRId16, i);
						fprintf(saida, "\t%" PRId16,
								(attributes_aux->u.Code.exception_table +
								 i)->start_pc);
						fprintf(saida, "\t%" PRId16,
								(attributes_aux->u.Code.exception_table +
								 i)->end_pc);
						fprintf(saida, "\t%" PRId16,
								(attributes_aux->u.Code.exception_table +
								 i)->handler_pc);
						fprintf(saida, "\tcp_info #%" PRId16,
								(attributes_aux->u.Code.exception_table +
								 i)->catch_type);
						constPoolInf *cp_a0 =
							ca->CONSTANTEe_pool +
							(attributes_aux->u.Code.exception_table +
							 i)->catch_type -
							1;
						ImprimeCONSTANTEeClasse(ca, cp_a0, saida);
						fprintf(saida, "\n");
					}
				}
				fprintf(saida, "\n\t\tMiscellaneous:\n");
				fprintf(saida, "\t\t\t\tProfundidade Maxima da "
							   "Pilha:\t\t%" PRId16 "\n",
						attributes_aux->u.Code.max_stack);
				fprintf(saida,
						"\t\t\t\tVariaveis locais maximas:\t%" PRId16 "\n",
						attributes_aux->u.Code.max_locals);
				fprintf(saida, "\t\t\t\tTamanho do Code:\t\t\t%" PRId32 "\n",
						attributes_aux->u.Code.code_length);
				fprintf(saida,
						"\n\t\tQuantidade de atributos de Code:\t%" PRId16 "\n",
						attributes_aux->u.Code.conts_atributos);
				mostrarAtributos(NULL, NULL, attributes_aux, ca, saida);
				break;
			case DEPRECATED:
				/* */
				break;
			case EXCEPTIONS:
				fprintf(saida, "\t\t\tNumero de excecoes: %" PRId16,
						attributes_aux->u.Exceptions.number_of_exceptions);
				fprintf(saida, "\t\t\tTabela de indice de excecoes:\n");
				for (uint16_t i = 0;
					 i < attributes_aux->u.Exceptions.number_of_exceptions;
					 i++) {
					fprintf(
						saida, "\t\t\t constPoolInf #%" PRId16 "\n",
						attributes_aux->u.Exceptions.exception_index_table[i]);
				}
				break;
			case INNER_CLASSES:
				fprintf(saida, "\t\tNumero de classes: %" PRId16 "\n",
						attributes_aux->u.InnerClasses.number_of_classes);
				fprintf(saida, "\t\t\tClasses:\n");
				classes_type *classes_aux =
					attributes_aux->u.InnerClasses.classes;
				for (uint16_t i = 0;
					 i < attributes_aux->u.InnerClasses.number_of_classes;
					 i++) {
					fprintf(saida, "\t\t\t\tClass %" PRId16 "\n", i);
					fprintf(saida, "\t\t\t\t\tinner_class_info_index:\t\tcp_"
								   "info #%" PRId16 "\t",
							(classes_aux)->inner_class_info_index);
					ImprimeCONSTANTEeClasse(
						ca, ca->CONSTANTEe_pool +
								(classes_aux)->inner_class_info_index - 1,
						saida);
					fprintf(saida, "\n\t\t\t\t\tsaider_class_info_index:\t\tcp_"
								   "info #%" PRId16 "\t",
							(classes_aux)->outer_class_info_index);
					ImprimeCONSTANTEeClasse(
						ca, ca->CONSTANTEe_pool +
								(classes_aux)->outer_class_info_index - 1,
						saida);
					fprintf(saida, "\n\t\t\t\t\tinner_name_index:\t\tcp_info "
								   "#%" PRId16 "\t",
							(classes_aux)->inner_name_index);
					ImprimeConstUtf8(ca->CONSTANTEe_pool +
										 (classes_aux)->inner_name_index - 1,
									 saida);
					fprintf(saida, "\n\t\t\t\t\tinner_class_access_flags:\t0x%."
								   "4" PRIx16 "\t\t",
							(classes_aux)->inner_class_access_flags);
					uint16_t flags_acesso =
						(classes_aux)->inner_class_access_flags;
					fprintf(saida, "[");
					if (flags_acesso >= FLAG_ABSTRATA) {
						fprintf(saida, "abstract ");
						flags_acesso -= FLAG_ABSTRATA;
					}
					if (flags_acesso >= FLAG_INTERFACE) {
						fprintf(saida, "interface ");
						flags_acesso -= FLAG_INTERFACE;
					}
					if (flags_acesso >= FLAG_FINAL) {
						fprintf(saida, "final ");
						flags_acesso -= FLAG_FINAL;
					}
					if (flags_acesso >= 0x8) {
						fprintf(saida, "static ");
						flags_acesso -= 0x08;
					}
					if (flags_acesso >= 0x4) {
						fprintf(saida, "protected ");
						flags_acesso -= 0x4;
					}
					if (flags_acesso >= 0x2) {
						fprintf(saida, "private ");
						flags_acesso -= 0x2;
					}
					if (flags_acesso >= FLAG_PUBLIC) {
						fprintf(saida, "public");
						flags_acesso -= FLAG_PUBLIC;
					}
					fprintf(saida, "]\n");
					classes_aux++;
				}
				break;
			case LINE_NUMBER_TABLE:
				fprintf(
					saida, "\t\t\t\tTamanho da Tabela de Numero de "
						   "Linha:\t%" PRId16 "\n",
					attributes_aux->u.LineNumberTable.line_number_table_length);
				fprintf(saida, "\t\t\t\tTabela de Numero de Linha:\n");
				fprintf(saida, "\t\t\t\tNr.\tstart_pc\tline_number\n");
				for (uint16_t i = 0;
					 i <
					 attributes_aux->u.LineNumberTable.line_number_table_length;
					 i++) {
					fprintf(saida, "\t\t\t\t%" PRId16, i);
					fprintf(
						saida, "\t%" PRId16,
						((attributes_aux->u.LineNumberTable.line_number_table) +
						 i)->start_pc);
					fprintf(
						saida, "\t%" PRId16 "\n",
						((attributes_aux->u.LineNumberTable.line_number_table) +
						 i)->line_number);
				}
				break;
			case LOCAL_VARIABLE_TABLE:
				fprintf(saida, "\t\t\tTamanho da Tabela de Variavel "
							   "Local:\t%" PRId16 "\n",
						attributes_aux->u.LocalVariableTable
							.local_variable_table_length);
				fprintf(saida, "\t\t\tTabela de Variavel Local:\n");
				fprintf(saida, "\t\t\tNr.\tstart_pc\tlength\tindex\tname_"
							   "index\tdescriptor_index\n");
				for (uint16_t i = 0; i < attributes_aux->u.LocalVariableTable
											 .local_variable_table_length;
					 i++) {
					fprintf(saida, "\t\t\t%" PRId16, i);
					fprintf(saida, "\t%" PRId16,
							((attributes_aux->u.LocalVariableTable
								  .local_variable_table) +
							 i)->start_pc);
					fprintf(saida, "\t%" PRId16,
							((attributes_aux->u.LocalVariableTable
								  .local_variable_table) +
							 i)->length);
					fprintf(saida, "\t%" PRId16,
							((attributes_aux->u.LocalVariableTable
								  .local_variable_table) +
							 i)->index);
					fprintf(saida, "\tcp_info #%" PRId16,
							((attributes_aux->u.LocalVariableTable
								  .local_variable_table) +
							 i)->indicador_nome);
					fprintf(saida, "\tcp_info #%" PRId16 "\n",
							((attributes_aux->u.LocalVariableTable
								  .local_variable_table) +
							 i)->descriptor_index);
					cp_a0 = ca->CONSTANTEe_pool +
							(((attributes_aux->u.LocalVariableTable
								   .local_variable_table) +
							  i)->indicador_nome) -
							1;
					fprintf(saida, "\t\t\t\t\t\t\t\t");
					ImprimeConstUtf8(cp_a0, saida);
					fprintf(saida, "\t");
					cp_a0 = ca->CONSTANTEe_pool +
							(((attributes_aux->u.LocalVariableTable
								   .local_variable_table) +
							  i)->descriptor_index) -
							1;
					ImprimeConstUtf8(cp_a0, saida);
					fprintf(saida, "\n");
				}
				break;
			case SOURCE_FILE:
				fprintf(saida, "\t\tIndice do nome do arquivo fonte:\tcp_info "
							   "#%" PRId16,
						attributes_aux->u.SourceFile.sourcefile_index);
				uint16_t sourcefile_index =
					attributes_aux->u.SourceFile.sourcefile_index;
				cp_a0 = ca->CONSTANTEe_pool + sourcefile_index - 1;
				if (cp_a0->tag != CONSTANTE_Utf8) {
					puts("\nERRO: SourceFile Attribute nao referencia um nome "
						 "valido.\n");
					exit(EXIT_FAILURE);
				} else {
					fprintf(saida, "\t");
					ImprimeConstUtf8(cp_a0, saida);
					fprintf(saida, "\n");
				}
				break;
			case UNKNOWN:
				/*				// IGNORANDO ATRIBUTOS DESCONHECIDOS*/
				break;
		}
		attributes_aux++;
	}
}


// retorna 1 byte lido da stream fileInput
uint8_t read1Byte(FILE *fi) {
	uint8_t paraRetorno = getc(fi);
/*	if (paraRetorno == EOF) {
		puts("ClassFormatError");
		exit(EXIT_FAILURE);
	}*/
	return paraRetorno;
}

// retorna 2 bytes lidos da stream fileInput
uint16_t read2Byte(FILE *fi) {
	uint16_t paraRetorno = getc(fi);
/*	if (paraRetorno == EOF) {
		puts("ClassFormatError");
		exit(EXIT_FAILURE);
	}
*/
	uint8_t paraRetorno2 = read1Byte(fi);

	paraRetorno = (paraRetorno << 8) | paraRetorno2;
	return paraRetorno;
}
// retorna 4 bytes lidos da stream fileInput
uint32_t read4Byte(FILE *fi) {
	uint32_t paraRetorno = getc(fi);
	if (paraRetorno == EOF) {
		puts("ClassFormatError");
		exit(EXIT_FAILURE);
	}

	uint8_t paraRetorno2 = read1Byte(fi);
	paraRetorno = (paraRetorno << 8) | paraRetorno2;

	paraRetorno2 = read1Byte(fi);
	paraRetorno = (paraRetorno << 8) | paraRetorno2;

	paraRetorno2 = read1Byte(fi);
	paraRetorno = (paraRetorno << 8) | paraRetorno2;
	return paraRetorno;
}

// retorna o tipo de atributo.
TIPO_ATRIBUTO getTipoAtributo(attribute_info *attr, ClasseDeArquivo *ca) {
	uint16_t indicador_nome = attr->attribute_name_index;
	constPoolInf *constPool = ca->CONSTANTEe_pool + indicador_nome - 1;

	// CONSTANTE_Utf8
	uint16_t length = constPool->u.Utf8.length;
	uint8_t *bytes = constPool->u.Utf8.bytes;

	if (length != 0) {
		switch (bytes[0]) {
			case 'C':
				if (!strcmp((char *)bytes, "Code")) {
					return CODE;
				} else if (!strcmp((char *)bytes, "CONSTANTEValue")) {
					return CONSTANTE_VALUE;
				}
				break;
			case 'D':
				if (!strcmp((char *)bytes, "Deprecated")) {
					return DEPRECATED;
				}
				break;
			case 'E':
				if (!strcmp((char *)bytes, "Exceptions")) {
					return EXCEPTIONS;
				}
				break;
			case 'I':
				if (!strcmp((char *)bytes, "InnerClasses")) {
					return INNER_CLASSES;
				}
				break;
			case 'L':
				if (!strcmp((char *)bytes, "LineNumberTable")) {
					return LINE_NUMBER_TABLE;
				} else if (!strcmp((char *)bytes, "LocalVariableTable")) {
					return LOCAL_VARIABLE_TABLE;
				}
				break;
			case 'S':
				if (!strcmp((char *)bytes, "Synthetic")) {
					return SYNTHETIC;
				} else if (!strcmp((char *)bytes, "SourceFile")) {
					return SOURCE_FILE;
				}
				break;
			default:
				return UNKNOWN;
		}
	}
	return UNKNOWN;
}


// Faz a leitura do arquivo .class, e retorna um ponteiro para estrutura
// ClasseDeArquivo com os campos preenchidos;
ClasseDeArquivo *loadClasseDeArquivo(FILE *fi) {
	// alocando espaço para estrutura do tipo ClasseDeArquivo.
	ClasseDeArquivo *ca = (ClasseDeArquivo *)malloc(sizeof(ClasseDeArquivo));
	if (ca == NULL) {
		printf("Erro ao alocar memoria CLASSEDEARQUIVO");
		exit(1);
	}

	// le uint32_t (4 bytes) do arquivo e atualiza o campo magic do
	// ClasseDeArquivo.
	ca->magic = read4Byte(fi);
	if (ca->magic != 0xCAFEBABE) {
		puts("ClassFormatError");
		free(ca);
		exit(EXIT_FAILURE);
	}

	// le dois uint16_t (2 bytes) do arquivo e atualiza os campos Min_version e
	// Principal_version do ClasseDeArquivo
	ca->Min_version = read2Byte(fi);
	ca->Principal_version = read2Byte(fi);
	// 45 = versao 1.1
	// 46 = versao 1.2
	if ((ca->Principal_version > 46) || (ca->Principal_version < 45) ||
		(ca->Principal_version == 46 && ca->Min_version != 0)) {
		puts("UnsupportedClassVersionError");
		exit(EXIT_FAILURE);
	}

	// le e armazena o pool de CONSTANTEes.
	setCONSTANTEPool(ca, fi);

	// le uint16_t (2 bytes) do arquivo e atualiza o campo flags_acesso do
	// ClasseDeArquivo
	ca->flags_acesso = read2Byte(fi);

	// le e armazena o campo classe_arq do ClasseDeArquivo (uint16_t) 2 bytes
	ca->classe_arq = read2Byte(fi);

	// le e armazena o campo super_classe do ClasseDeArquivo (uint16_t)	2 bytes
	ca->super_classe = read2Byte(fi);

	setInterfaces(ca, fi);

	setFields(ca, fi);

	setMethods(ca, fi);

	setAttributes(NULL, NULL, NULL, ca, fi);

	// Aqui verifica o final do arquivo class, se não tiver acabado ou erro de
	// leitura ou de arquivo.
	if (getc(fi) != EOF) {
		puts("ClassFormatError");
	}
	return ca;
}

// le e armazena o pool de CONSTANTEes do ClasseDeArquivo
void setCONSTANTEPool(ClasseDeArquivo *ca, FILE *fi) {
	ca->Cont_ConstPool =
		read2Byte(fi);  // le o numero de elementos na CONSTANTE pool
	/*	printf("Cont_ConstPool = %" PRIu16, ca->Cont_ConstPool);*/
	if (ca->Cont_ConstPool == 0) {
		puts("VerifyError");
		exit(EXIT_FAILURE);
	}
	ca->CONSTANTEe_pool = (constPoolInf *)malloc(
		(ca->Cont_ConstPool - 1) * sizeof(constPoolInf));  // FREE OK

	constPoolInf *constPool;  // declara um tipo const pool para usar e setar
	for (constPool = ca->CONSTANTEe_pool;
		 constPool < (ca->CONSTANTEe_pool + ca->Cont_ConstPool - 1);
		 constPool++) {
		constPool->tag = 0;
		constPool->tag = read1Byte(fi);
		/*		printf("\ncp_tag = %" PRIu8, constPool->tag);*/
		switch (constPool->tag) {
			case Classe_const:
				constPool->u.Class.indicador_nome = read2Byte(fi);
				break;
			// Field, method e interfacemethod recebem name and type e class
			// index (u2)
			case CONSTANTEe_campo_referencia:
			case CONSTANTEe_metodo_referencia:
			case CONSTANTEe_Interface_referencia:
				constPool->u.Ref.indicador_nome = read2Byte(fi);
				constPool->u.Ref.indicador_nome_e_tipo = read2Byte(fi);
				break;
			// recebe string (u2)
			case CONSTANTE_String:
				constPool->u.String.indicador_string = read2Byte(fi);
				break;
			// Inteiro e float recebem os Bytes (u4)
			case CONSTANTE_Integer:
			case CONSTANTE_Float:
				constPool->u.Integer_Float.bytes = read4Byte(fi);
				break;
			// Long e Double recebem 8 bytes (u4, u4)
			// Long e Double ocupam dois índices da CONSTANTEe_pool: High, Low
			case CONSTANTE_Long:
			case CONSTANTE_Double:
				constPool->u.Long_Double.high_bytes = read4Byte(fi);
				constPool->u.Long_Double.low_bytes = read4Byte(fi);
				constPool++;
				break;

			// Nome e tipo (u2 , u2)
			case CONSTANTE_NameAndType:
				constPool->u.NameAndType.indicador_nome = read2Byte(fi);
				constPool->u.NameAndType.descriptor_index = read2Byte(fi);
				break;

			// Unicode recebe o tamanho (u2), aloca um vetor e coloca no array
			// os bytes (u1)
			case CONSTANTE_Utf8:
				constPool->u.Utf8.length = read2Byte(fi);
				if (constPool->u.Utf8.length) {
					constPool->u.Utf8.bytes =
						(uint8_t *)malloc((constPool->u.Utf8.length + 1) *
										  sizeof(uint8_t));  // FREE OK
					for (uint16_t i = 0; i < constPool->u.Utf8.length; i++) {
						constPool->u.Utf8.bytes[i] = read1Byte(fi);
					}
					constPool->u.Utf8.bytes[constPool->u.Utf8.length] = '\0';
				} else {
					constPool->u.Utf8.bytes = NULL;
				}

				break;
			default:
				puts("VerifyError");
				exit(EXIT_FAILURE);
		}
	}
}

// le e armazena as interfaces do ClasseDeArquivo (u2)
void setInterfaces(ClasseDeArquivo *ca, FILE *fi) {
	ca->interfaces_count = read2Byte(fi);  // recebe o numéro direto de
										   // superinterfaces dessa classe ou
										   // tipos de interface
	if (ca->interfaces_count) {
		// declara o vetor, aloca e recebe os valores de index para dentro da
		// CONSTANTE pool para cada interface
		// implemetada pela classe.
		ca->interfaces = (uint16_t *)malloc((ca->interfaces_count) *
											sizeof(uint16_t));  // FREE OK
		for (uint16_t *in = ca->interfaces;
			 in < (ca->interfaces + ca->interfaces_count); in++) {
			*in = read2Byte(fi);
		}
	} else {
		ca->interfaces = NULL;
	}
}

// le e armazena os fields do ClasseDeArquivo
void setFields(ClasseDeArquivo *ca, FILE *fi) {
	ca->conts_campos = read2Byte(fi);  // recebe o numero de estruturas
									   // field_info para alocar e receber
									   // informa

	if (ca->conts_campos) {
		ca->fields = (field_info *)malloc((ca->conts_campos) *
										  sizeof(field_info));  // FREE OK
		for (field_info *fd_in = ca->fields;
			 fd_in < (ca->fields + ca->conts_campos); fd_in++) {
			fd_in->flags_acesso = read2Byte(fi);
			fd_in->indicador_nome = read2Byte(fi);
			fd_in->descriptor_index = read2Byte(fi);
			setAttributes(fd_in, NULL, NULL, ca, fi);
		}
	} else {
		ca->fields = NULL;
	}
}

// le e armazena os métodos do ClasseDeArquivo
void setMethods(ClasseDeArquivo *ca, FILE *fi) {
	ca->conts_metodo =
		read2Byte(fi);  // Pega o número de estruturas de method_info

	if (ca->conts_metodo) {
		// aloca e le as informacoes para o array method_info
		ca->methods = (method_info *)malloc((ca->conts_metodo) *
											sizeof(method_info));  // FREE OK
		for (method_info *mt_in = ca->methods;
			 mt_in < (ca->methods + ca->conts_metodo); mt_in++) {
			mt_in->flags_acesso = read2Byte(fi);
			mt_in->indicador_nome = read2Byte(fi);
			mt_in->descriptor_index = read2Byte(fi);
			setAttributes(NULL, mt_in, NULL, ca, fi);
		}
	} else {
		ca->methods = NULL;
	}
}

// le e armazena os atributos do ClasseDeArquivo
void setAttributes(field_info *fd_in, method_info *mt_in,
				   attribute_info *attr_in, ClasseDeArquivo *ca, FILE *fi) {
	attribute_info *attributes;
	uint16_t conts_atributos;

	if (fd_in != NULL) {
		fd_in->conts_atributos = read2Byte(fi);

		if (fd_in->conts_atributos) {
			fd_in->attributes = (attribute_info *)malloc(
				fd_in->conts_atributos * sizeof(attribute_info));
		} else {
			fd_in->attributes = NULL;
		}
		conts_atributos = fd_in->conts_atributos;
		attributes = fd_in->attributes;
	} else if (mt_in != NULL) {
		mt_in->conts_atributos = read2Byte(fi);
		if (mt_in->conts_atributos) {
			mt_in->attributes = (attribute_info *)malloc(
				mt_in->conts_atributos * sizeof(attribute_info));
		} else {
			mt_in->attributes = NULL;
		}
		conts_atributos = mt_in->conts_atributos;
		attributes = mt_in->attributes;
	} else if (attr_in != NULL) {
		attr_in->u.Code.conts_atributos = read2Byte(fi);
		if (attr_in->u.Code.conts_atributos) {
			attr_in->u.Code.attributes = (attribute_info *)malloc(
				attr_in->u.Code.conts_atributos * sizeof(attribute_info));
		} else {
			attr_in->u.Code.attributes = NULL;
		}
		conts_atributos = attr_in->u.Code.conts_atributos;
		attributes = attr_in->u.Code.attributes;
	} else if (ca != NULL) {
		ca->conts_atributos = read2Byte(fi);
		if (ca->conts_atributos) {
			ca->attributes = (attribute_info *)malloc(ca->conts_atributos *
													  sizeof(attribute_info));
		} else {
			ca->attributes = NULL;
		}


		conts_atributos = ca->conts_atributos;
		attributes = ca->attributes;
	} else {
		puts("Erro ao setar atributos");
		exit(EXIT_FAILURE);
	}

	for (attribute_info *attr = attributes;
		 attr < (attributes + conts_atributos); attr++) {
		attr->attribute_name_index = read2Byte(fi);
		attr->attribute_length = read4Byte(fi);

		TIPO_ATRIBUTO attrTypeResult = getTipoAtributo(attr, ca);

		if (attrTypeResult == CONSTANTE_VALUE) {
			attr->u.CONSTANTEValue.CONSTANTEvalue_index = read2Byte(fi);
		} else if (attrTypeResult == CODE) {
			attr->u.Code.max_stack = read2Byte(fi);
			attr->u.Code.max_locals = read2Byte(fi);
			attr->u.Code.code_length = read4Byte(fi);
			if (attr->u.Code.code_length) {
				attr->u.Code.code = (uint8_t *)malloc(attr->u.Code.code_length *
													  sizeof(uint8_t));
				for (uint8_t *cd = attr->u.Code.code;
					 cd < (attr->u.Code.code + attr->u.Code.code_length); cd++)
					*cd = read1Byte(fi);
			}


			attr->u.Code.exception_table_length = read2Byte(fi);
			if (attr->u.Code.exception_table_length) {
				attr->u.Code.exception_table = (exception_table_type *)malloc(
					attr->u.Code.exception_table_length *
					sizeof(exception_table_type));

				for (exception_table_type *ex_tb = attr->u.Code.exception_table;
					 ex_tb < (attr->u.Code.exception_table +
							  attr->u.Code.exception_table_length);
					 ex_tb++) {
					ex_tb->start_pc = read2Byte(fi);
					ex_tb->end_pc = read2Byte(fi);
					ex_tb->handler_pc = read2Byte(fi);
					ex_tb->catch_type = read2Byte(fi);
				}
			}

			setAttributes(NULL, NULL, attr, ca, fi);
		} else if (attrTypeResult == DEPRECATED) {
			// TEM QUE FAZER ALGO ???
		} else if (attrTypeResult == EXCEPTIONS) {
			attr->u.Exceptions.number_of_exceptions = read2Byte(fi);
			attr->u.Exceptions.exception_index_table = (uint16_t *)malloc(
				attr->u.Exceptions.number_of_exceptions * sizeof(uint16_t));
			for (uint16_t *ex_in_tb = attr->u.Exceptions.exception_index_table;
				 ex_in_tb < (attr->u.Exceptions.exception_index_table +
							 attr->u.Exceptions.number_of_exceptions);
				 ex_in_tb++)
				*ex_in_tb = read2Byte(fi);
		} else if (attrTypeResult == INNER_CLASSES) {
			attr->u.InnerClasses.number_of_classes = read2Byte(fi);
			attr->u.InnerClasses.classes = (classes_type *)malloc(
				attr->u.InnerClasses.number_of_classes * sizeof(classes_type));
			for (classes_type *cl = attr->u.InnerClasses.classes;
				 cl < (attr->u.InnerClasses.classes +
					   attr->u.InnerClasses.number_of_classes);
				 cl++) {
				cl->inner_class_info_index = read2Byte(fi);
				cl->outer_class_info_index = read2Byte(fi);
				cl->inner_name_index = read2Byte(fi);
				cl->inner_class_access_flags = read2Byte(fi);
			}
		} else if (attrTypeResult == LINE_NUMBER_TABLE) {
			attr->u.LineNumberTable.line_number_table_length = read2Byte(fi);
			if (attr->u.LineNumberTable.line_number_table_length) {
				attr->u.LineNumberTable.line_number_table =
					(line_number_table_type *)malloc(
						attr->u.LineNumberTable.line_number_table_length *
						sizeof(line_number_table_type));

				for (line_number_table_type *ln_tb =
						 attr->u.LineNumberTable.line_number_table;
					 ln_tb < (attr->u.LineNumberTable.line_number_table +
							  attr->u.LineNumberTable.line_number_table_length);
					 ln_tb++) {
					ln_tb->start_pc = read2Byte(fi);
					ln_tb->line_number = read2Byte(fi);
				}
			}
		} else if (attrTypeResult == LOCAL_VARIABLE_TABLE) {
			attr->u.LocalVariableTable.local_variable_table_length =
				read2Byte(fi);
			if (attr->u.LocalVariableTable.local_variable_table_length) {
				attr->u.LocalVariableTable.local_variable_table =
					(local_variable_table_type *)malloc(
						attr->u.LocalVariableTable.local_variable_table_length *
						sizeof(local_variable_table_type));

				for (local_variable_table_type *lv_tb =
						 attr->u.LocalVariableTable.local_variable_table;
					 lv_tb <
					 (attr->u.LocalVariableTable.local_variable_table +
					  attr->u.LocalVariableTable.local_variable_table_length);
					 lv_tb++) {
					lv_tb->start_pc = read2Byte(fi);
					lv_tb->length = read2Byte(fi);
					lv_tb->indicador_nome = read2Byte(fi);
					lv_tb->descriptor_index = read2Byte(fi);
					lv_tb->index = read2Byte(fi);
				}
			}
		} else if (attrTypeResult == SYNTHETIC) {
			// TEM QUE FAZER ALGO ???
		} else if (attrTypeResult == SOURCE_FILE) {
			attr->u.SourceFile.sourcefile_index = read2Byte(fi);
		} else {
			// UNKNOWN TYPE JA QUE NAO CAIU EM NENHUM CASO CONHECIDO
		}
	}
}


// libera memória alocada da estrutura ClasseDeArquivo
void freeClasseDeArquivo(ClasseDeArquivo *ca) {
	if (!ca) {
		return;
	}
	free(ca->interfaces);
	freeFields(ca);
	freeMethods(ca);
	// Gambiarra 2
	for (attribute_info *attr = ca->attributes;
		 attr < (ca->attributes + ca->conts_atributos); attr++) {
		freeAttribute(attr, ca);
	}
	if (ca->conts_atributos) {
		free(ca->attributes);
	}
	freeCONSTANTEPool(ca);
	free(ca);
}

void freeCONSTANTEPool(ClasseDeArquivo *ca) {
	for (constPoolInf *constPool = ca->CONSTANTEe_pool;
		 constPool < (ca->CONSTANTEe_pool + ca->Cont_ConstPool - 1);
		 constPool++) {
		if (constPool->tag == CONSTANTE_Utf8) {
			free(constPool->u.Utf8.bytes);
		}
	}
	free(ca->CONSTANTEe_pool);
}

void freeFields(ClasseDeArquivo *ca) {
	for (field_info *fd_in = ca->fields;
		 fd_in < (ca->fields + ca->conts_campos); fd_in++) {
		for (attribute_info *attr = fd_in->attributes;
			 attr < (fd_in->attributes + fd_in->conts_atributos); attr++) {
			freeAttribute(attr, ca);
		}
		if (fd_in->conts_atributos) {
			free(fd_in->attributes);
		}
	}
	if (ca->conts_campos) {
		free(ca->fields);
	}
}

void freeMethods(ClasseDeArquivo *ca) {
	for (method_info *mt_in = ca->methods;
		 mt_in < (ca->methods + ca->conts_metodo); mt_in++) {
		for (attribute_info *attr = mt_in->attributes;
			 attr < (mt_in->attributes + mt_in->conts_atributos); attr++) {
			freeAttribute(attr, ca);
		}
		if (mt_in->conts_atributos) {
			free(mt_in->attributes);
		}
	}
	if (ca->conts_metodo) {
		free(ca->methods);
	}
}

void freeAttribute(attribute_info *attr, ClasseDeArquivo *ca) {
	switch (getTipoAtributo(attr, ca)) {
		case CONSTANTE_VALUE:
			break;
		case CODE:
			if (attr->u.Code.code_length) {
				free(attr->u.Code.code);
			}

			if (attr->u.Code.exception_table_length) {
				free(attr->u.Code.exception_table);
			}

			for (attribute_info *attr_ = attr->u.Code.attributes;
				 attr_ <
				 (attr->u.Code.attributes + attr->u.Code.conts_atributos);
				 attr_++) {
				freeAttribute(attr_, ca);
			}
			if (attr->u.Code.conts_atributos) {
				free(attr->u.Code.attributes);
			}

			break;
		case DEPRECATED:
			break;
		case EXCEPTIONS:
			free(attr->u.Exceptions.exception_index_table);
			break;
		case INNER_CLASSES:
			if (attr->u.InnerClasses.number_of_classes) {
				free(attr->u.InnerClasses.classes);
			}
			break;
		case LINE_NUMBER_TABLE:
			if (attr->u.LineNumberTable.line_number_table_length) {
				free(attr->u.LineNumberTable.line_number_table);
			}
			break;
		case LOCAL_VARIABLE_TABLE:
			if (attr->u.LocalVariableTable.local_variable_table_length) {
				free(attr->u.LocalVariableTable.local_variable_table);
			}
			break;
		case SYNTHETIC:
			break;
		case SOURCE_FILE:
			break;
		case UNKNOWN:
			break;
	}
}
