#include "LeitorExibidor.h"
#include "opcodes.h"

// Array de mnemônicos opcodes.h
char *op_codesJVM[] = {
    "nop", "aconst_null", "iconst_m1", "iconst_0", "iconst_1", "iconst_2", "iconst_3", "iconst_4", "iconst_5", "lconst_0",
    "lconst_1", "fconst_0", "fconst_1", "fconst_2", "dconst_0", "dconst_1", "bipush", "sipush", "ldc", "ldc_w",
    "ldc2_w", "iload", "lload", "fload","dload", "aload", "iload_0", "iload_1", "iload_2", "iload_3",
    "lload_0", "lload_1", "lload_2", "lload_3", "fload_0", "fload_1", "fload_2", "fload_3", "dload_0", "dload_1",
    "dload_2", "dload_3", "aload_0", "aload_1", "aload_2", "aload_3", "iaload", "laload", "faload", "daload",
    "aaload", "baload", "caload", "saload", "istore", "lstore", "fstore", "dstore", "astore", "istore_0",
    "istore_1", "istore_2", "istore_3", "lstore_0", "lstore_1", "lstore_2", "lstore_3", "fstore_0", "fstore_1", "fstore_2",
    "fstore_3", "dstore_0", "dstore_1", "dstore_2", "dstore_3", "astore_0", "astore_1", "astore_2", "astore_3", "iastore",
    "lastore", "fastore", "dastore", "aastore", "bastore", "castore", "sastore", "pop", "pop2", "dup",
    "dup_x1", "dup_x2", "dup2", "dup2_x1", "dup2_x2", "swap", "iadd", "ladd", "fadd", "dadd",
    "isub", "lsub", "fsub", "dsub", "imul", "lmul", "fmul", "dmul", "idiv", "ldiv",
    "fdiv", "ddiv", "irem", "lrem", "frem", "drem", "ineg", "lneg", "fneg", "dneg",
    "ishl", "lshl", "ishr", "lshr", "iushr", "lushr", "iand", "land", "ior", "lor",
	"ixor", "lxor", "iinc", "i2l", "i2f", "i2d", "l2i", "l2f", "l2d", "f2i",
    "f2l", "f2d", "d2i", "d2l", "d2f", "i2b", "i2c", "i2s", "lcmp", "fcmpl",
    "fcmpg", "dcmpl", "dcmpg", "ifeq", "ifne", "iflt", "ifge","ifgt", "ifle", "if_icmpeq",
    "if_icmpne", "if_icmplt", "if_icmpge", "if_icmpgt", "if_icmple", "if_acmpeq", "if_acmpne", "goto", "jsr", "ret",
    "tableswitch", "lookupswitch", "ireturn", "lreturn", "freturn", "dreturn", "areturn", "return", "getstatic", "putstatic",
    "getfield", "putfield", "invokevirtual", "invokespecial", "invokestatic", "invokeinterface", "invokedynamic", "new", "newarray", "anewarray",
    "arraylength", "athrow", "checkcast", "instanceof", "monitorenter", "monitorexit", "wide", "multianewarray", "ifnull", "ifnonnull",
    "goto_w", "jsr_w", "breakpoint", NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, "impdep1", "impdep2"
};

void	showClassFile(ClassFile * cf, FILE * saida){
    fprintf(saida, "Leitor/Exibidor JVM\n");
    showGeneralInfo(cf, saida);
    showConstantPool(cf, saida);
    showInterfaces(cf, saida);
    showFields(cf, saida);
    showMethods(cf, saida);
}

void	showGeneralInfo(ClassFile * cf,  FILE * saida){
    float versao;
    constant_pool_info * constPool;
    
    //Mostrar Informação Geral
    
    fprintf(saida,"\t\tInformacoes\n\n");
    
    fprintf(saida, "Magic: \t\t\t\t0x%" PRIX32 "\n", cf->magic);
    
    fprintf(saida, "Versao Min: \t\t\t%" PRId16 "\n", cf->minor_version);
    
    if (cf->major_version == 45) {
        versao = 1.1;
    }
    else if (cf->major_version == 46) {
        versao = 1.2;
    }
    else if (cf->major_version == 47) {
        versao = 1.3;
    }
    else if (cf->major_version == 48) {
        versao = 1.4;
    }
    else if (cf->major_version == 49) {
        versao = 1.5;
    }
    else if (cf->major_version == 50) {
        versao = 1.6;
    }
    else if (cf->major_version == 51) {
        versao = 1.7;
    }
    else if (cf->major_version == 52) {
        versao = 1.8;
    }
    else
    {
        versao = 0.0; //signfica que deu erro ...
    }
    
    fprintf(saida, "Principal versao: \t\t%" PRIu16 "\t[%.1f]\n", cf->major_version, versao);
    
    fprintf(saida, "Tamanho do CONSTANTE Pool: \t%" PRIu16 "\n", cf->constant_pool_count);
    
    fprintf(saida, "Flags de acesso: \t\t0x%.4" PRIX16 "\t[", cf->access_flags);
    
    uint16_t	access_flags = cf->access_flags;
    if(access_flags >= ACC_ABSTRACT){
        fprintf(saida, "abstract ");
        access_flags -= ACC_ABSTRACT;
    }
    if(access_flags >= ACC_INTERFACE){
        fprintf(saida, "interface ");
        access_flags -= ACC_INTERFACE;
    }
    if(access_flags >= ACC_SUPER){
        fprintf(saida, "super ");
        access_flags -= ACC_SUPER;
    }
    
    if(access_flags >= ACC_FINAL){
        fprintf(saida, "final ");
        access_flags -= ACC_FINAL;
    }
    if(access_flags >= ACC_PUBLIC){
        fprintf(saida, "public ");
        access_flags -= ACC_PUBLIC;
    }
    fprintf(saida,"]\n");
    
    obtainlocale (LC_ALL, "" );
    
    fprintf(saida, "Classe carregada: \t\tcp_info #%" PRIu16, cf->this_class);
    if(cf->constant_pool[cf->this_class-1].tag != CONSTANT_Class){
        puts("\nERRO: this_class nao aponta para uma CONSTANTE_Class_info.\n");
        exit(EXIT_FAILURE);
    }
    else{
        uint16_t	name_index;
        name_index = cf->constant_pool[cf->this_class-1].u.Class.name_index;
        constPool = cf->constant_pool + name_index - 1;
        if(constPool->tag != CONSTANT_Utf8){
            puts("\nERRO: this_class nao referencia um name_index valido.\n");
            exit(EXIT_FAILURE);
        }
        else{
            fprintf(saida, "\t<");
            printConstUtf8(constPool, saida);
            fprintf(saida, ">\n");
        }
    }
    
    if(!cf->super_class){
        fprintf(saida, "Super classe: \t\t\tNone\n");
    }
    else{
        if(cf->constant_pool[cf->super_class-1].tag != CONSTANT_Class){
            puts("\nERRO: super_class nao aponta para uma CONSTANTE_Class_info.\n");
            exit(EXIT_FAILURE);
        }
        else{
            fprintf(saida, "Super class: \t\t\tcp_info #%" PRIu16 , cf->super_class);
            uint16_t	name_index;
            name_index = cf->constant_pool[cf->super_class-1].u.Class.name_index;
            constPool = cf->constant_pool + name_index - 1;
            if(constPool->tag != CONSTANT_Utf8){
                puts("\nERRO: super_class nao referencia um name_index valido.\n");
                exit(EXIT_FAILURE);
            }
            else{
                fprintf(saida, "\t<");
                printConstUtf8(constPool, saida);
                fprintf(saida, ">\n");
            }
        }
    }
    
    
    fprintf(saida, "Quantidade de Interfaces: \t%" PRIu16 "\n", cf->interfaces_count);
    fprintf(saida, "Quantidade de Campos: \t\t%" PRIu16 "\n", cf->fields_count);
    fprintf(saida, "Quantidade de Metodos: \t\t%" PRIu16 "\n", cf->methods_count);
    fprintf(saida, "Quantidade de Atributos: \t%" PRIu16 "\n", cf->attributes_count);
}


void printConstUtf8(constant_pool_info * constPool, FILE * saida)
{
    char * string = (char *) constPool->u.Utf8.bytes;
    string[constPool->u.Utf8.length] = '\0';
    fprintf(saida, "%s", string );
}

//Imprime no arquivo de saida os valores apontados pelo CONSTANT_Class
void    printConstantClass(ClassFile * cf, constant_pool_info * constPool, FILE * saida)
{
    constant_pool_info * cp_a0;
    cp_a0 = cf->constant_pool + constPool->u.Class.name_index - 1;
    if(cp_a0->tag != CONSTANT_Utf8)
    {
        puts("\nERRO: valor da tag invalido (Diferente de CONSTANT_Utf8).\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        for(uint16_t i = 0; i < cp_a0->u.Utf8.length; i++)
        {
            fprintf(saida, "%c" , cp_a0->u.Utf8.bytes[i]);
        }
    }
}

//Imprime no arquivo de saida os valores apontados pelo CONSTANT_String
void    printConstantString(ClassFile * cf, constant_pool_info * constPool, FILE * saida)
{
    constant_pool_info * cp_a0;
    cp_a0 = cf->constant_pool + constPool->u.String.string_index - 1;
    if(cp_a0->tag != CONSTANT_Utf8)
    {
        puts("\nERRO: valor da tag invalido (Diferente de CONSTANT_Utf8).\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printConstUtf8(cp_a0, saida);
    }
}

//Imprime no arquivo de saida os valores apontados pelo CONSTANTE_NameType
void    printConstantNameAndType(ClassFile * cf, constant_pool_info * constPool, char descritor_nome, FILE * saida)
{
    constant_pool_info * cp_a0 = constPool;
	
	if (descritor_nome == 'n') 
	{
		cp_a0 = cf->constant_pool + cp_a0->u.NameAndType.name_index - 1;
            if(cp_a0->tag != CONSTANT_Utf8)
            {
                puts("\nERRO: valor da tag invalido (Diferente de CONSTANT_Utf8).\n");
                exit(EXIT_FAILURE);
            }
            else
            {
                for(uint16_t i = 0; i < cp_a0->u.Utf8.length; i++)
                {
                    fprintf(saida, "%c" , cp_a0->u.Utf8.bytes[i]);
                }
            }
	} 
	else if (descritor_nome == 'd') {
		cp_a0 = cf->constant_pool + cp_a0->u.NameAndType.descriptor_index- 1;
            if(cp_a0->tag != CONSTANT_Utf8)
            {
                puts("\nERRO: valor da tag invalido (Diferente de CONSTANT_Utf8).\n");
                exit(EXIT_FAILURE);
            }
            else
            {
                for(uint16_t i = 0; i < cp_a0->u.Utf8.length; i++)
                {
                    fprintf(saida, "%c" , cp_a0->u.Utf8.bytes[i]);
                }
            }
	} 
	else 
	{
		//nada faz
	}
    
}

//Imprime no arquivo de saida os valores apontados pelos CONSTANT_Fieldref, CONSTANT_Methodref, CONSTANT_InterfaceMethodref
void    printConstantRef(ClassFile * cf, constant_pool_info * constPool,char tipo_indicador, FILE * saida)
{
    constant_pool_info * cp_a0;
    constant_pool_info * cp_a2;
    switch(tipo_indicador)
    {
        case 'c':
            cp_a0 = cf->constant_pool + constPool->u.Ref.name_index - 1;
            if(cp_a0->tag != CONSTANT_Class)
            {
                puts("\nERRO: valor da tag invalido (Diferente de CONSTANT_Class).\n");
                exit(EXIT_FAILURE);
            }
            else
            {
                cp_a0 = cf->constant_pool + cp_a0->u.Class.name_index - 1;
                if(cp_a0->tag != CONSTANT_Utf8)
                {
                    puts("\nERRO: valor da tag invalido (Diferente de CONSTANT_Utf8).\n");
                    exit(EXIT_FAILURE);
                }
                else
                {
                    for(uint16_t i = 0; i < cp_a0->u.Utf8.length; i++)
                    {
                        fprintf(saida, "%c" , cp_a0->u.Utf8.bytes[i]);
                    }
                }
            }
            break;
            
        case 'n':
            cp_a0 = cf->constant_pool + constPool->u.Ref.name_and_type_index - 1;
            if(cp_a0->tag != CONSTANT_NameAndType)
            {
                puts("\nERRO: valor da tag invalido (Diferente de CONSTANT_NameAndType).\n");
                exit(EXIT_FAILURE);
            }
            else
            {
                cp_a2 = cp_a0;
                cp_a0 = cf->constant_pool + cp_a0->u.NameAndType.name_index - 1;
                if(cp_a0->tag != CONSTANT_Utf8)
                {
                    puts("\nERRO: valor da tag invalido (Diferente de CONSTANT_Utf8).\n");
                    exit(EXIT_FAILURE);
                }
                else
                {
                    for(uint16_t i = 0; i < cp_a0->u.Utf8.length; i++)
                    {
                        fprintf(saida, "%c" , cp_a0->u.Utf8.bytes[i]);
                    }
                }
                cp_a2 = cf->constant_pool + cp_a2->u.NameAndType.descriptor_index - 1;
                if(cp_a2->tag != CONSTANT_Utf8)
                {
                    puts("\nERRO: valor da tag invalido (Diferente de CONSTANT_Utf8).\n");
                    exit(EXIT_FAILURE);
                }
                else
                {
                    for(uint16_t i = 0; i < cp_a2->u.Utf8.length; i++)
                    {
                        fprintf(saida, "%c" , cp_a2->u.Utf8.bytes[i]);
                    }
                }
            }
            break;
            
    }
    
}

//Imprime no arquivo de saida a constant_pool do ClassFile
void	showConstantPool(ClassFile * cf, FILE * saida){
    int64_t bits;
    fprintf(saida,"CONSTANTE Pool:\n");
    constant_pool_info * constPool;
    uint16_t	i;
    for(constPool = cf->constant_pool, i = 1; constPool < (cf->constant_pool + cf->constant_pool_count - 1); constPool++, i++){
        switch(constPool->tag){
            case	CONSTANT_Class:
                fprintf(saida, "[%" PRIu16 "]\tCONSTANTE_Class_info\n", i);
                fprintf(saida, "\tNome da Classe:\t\tcp_info #%" PRIu16 "\t<", constPool->u.Class.name_index);
                printConstantClass(cf,constPool,saida);
                fprintf(saida, ">\n\n");
                break;
            case	CONSTANT_Fieldref:
            case	CONSTANT_Methodref:
            case	CONSTANT_InterfaceMethodref:
                if(constPool->tag == CONSTANT_Fieldref)
                    fprintf(saida, "[%" PRIu16 "]\tCONSTANTEe_campo_referencia\n", i); //???PRI u16, que porra é essa?, faz uma leitura direta?
                else if(constPool->tag == CONSTANT_Methodref)
                    fprintf(saida, "[%" PRIu16 "]\tCONSTANTEe_metodo_referencia\n", i);
                else if(constPool->tag == CONSTANT_InterfaceMethodref)
                    fprintf(saida, "[%" PRIu16 "]\tCONSTANTEe_Interface_referencia\n", i);
                
                fprintf(saida, "\tNome da classe:\t\tcp_info #%" PRIu16 "\t<", constPool->u.Ref.name_index);
                printConstantRef(cf,constPool,'c',saida);
                fprintf(saida, ">\n\tNome e tipo:\t\tcp_info #%" PRIu16 "\t<", constPool->u.Ref.name_and_type_index);
                printConstantRef(cf,constPool,'n',saida);
                fprintf(saida, ">\n\n");
                break;
            case	CONSTANT_String:
                fprintf(saida, "[%" PRIu16 "]\tCONSTANTE_String_info\n", i);
                fprintf(saida, "\tString:\t\t\tcp_info #%" PRIu16 "\t<", constPool->u.String.string_index);
                printConstantString(cf,constPool,saida);
                fprintf(saida, ">\n\n");
                break;
            case	CONSTANT_Integer:
                fprintf(saida, "[%" PRIu16 "]\tCONSTANTE_Integer_info\n", i);
                fprintf(saida, "\tBytes:\t\t\t0x%.8" PRIx32, constPool->u.Integer_Float.bytes);
                fprintf(saida, "\n\tInteger:\t\t%" PRId32 "\n\n", constPool->u.Integer_Float.bytes);
                break;
            case	CONSTANT_Float:
                fprintf(saida, "[%" PRIu16 "]\tCONSTANTE_Float_info\n", i);
                fprintf(saida, "\tBytes:\t\t\t0x%.8" PRIx32, constPool->u.Integer_Float.bytes);
                float	float_number;
                memcpy(&float_number,&constPool->u.Integer_Float.bytes, sizeof(constPool->u.Integer_Float.bytes));
                fprintf(saida, "\n\tFloat:\t\t\t%f\n\n", float_number);
                break;
            case	CONSTANT_Long:
                fprintf(saida, "[%" PRIu16 "]\tCONSTANTE_Long_info\n", i);
                fprintf(saida, "\tHigh bytes:\t\t0x%.8" PRIx32, constPool->u.Long_Double.high_bytes);
                fprintf(saida, "\n\tLow bytes:\t\t0x%.8" PRIx32, constPool->u.Long_Double.low_bytes);
                bits = (((int64_t) constPool->u.Long_Double.high_bytes) << 32) + constPool->u.Long_Double.low_bytes;
                fprintf(saida, "\n\tLong:\t\t\t%" PRId64 "\n\n", bits);
                fprintf(saida, "[%" PRIu16 "]\t(large numeric continued)\n\n", ++i);
                constPool++;
                break;
            case	CONSTANT_Double:
                fprintf(saida, "[%" PRIu16 "]\tCONSTANTE_Double_info\n", i);
                fprintf(saida, "\tHigh bytes:\t\t0x%.8" PRIx32, constPool->u.Long_Double.high_bytes);
                fprintf(saida, "\n\tLow bytes:\t\t0x%.8" PRIx32, constPool->u.Long_Double.low_bytes);
                bits = (((int64_t) constPool->u.Long_Double.high_bytes) << 32) + constPool->u.Long_Double.low_bytes;
                switch(bits){
                    case 0x7ff0000000000000L:
                        fprintf(saida, "\n\tDouble:\t\t\t+8\n\n");
                        break;
                    case 0xfff0000000000000L:
                        fprintf(saida, "\n\tDouble:\t\t\t-8\n\n");
                        break;
                    default:
                        if((bits >= 0x7ff0000000000001L && bits <= 0x7ffffffffffffL) ||
                           (bits >= 0xfff0000000000001L && bits <= 0xffffffffffffffffL )){
                            fprintf(saida, "\n\tDouble:\t\t\tNaN\n\n");
                        }
                        else{
                            int32_t s = ((bits >> 63) == 0) ? 1 : -1;
                            int32_t e = ((bits >> 52) & 0x7ffL);
                            int64_t m = (e == 0) ?
                            (bits & 0xfffffffffffffL) << 1 :
                            (bits & 0xfffffffffffffL) | 0x10000000000000L;
                            fprintf(saida, "\n\tDouble:\t\t\t%f\n\n", (double) s*m*pow(2, (e-1075)));
                        }
                }
                fprintf(saida, "[%" PRIu16 "]\t(large numeric continued)\n\n", ++i);
                constPool++;
                break;
            case	CONSTANT_NameAndType:
                fprintf(saida, "[%" PRIu16 "]\tCONSTANTE_NameAndType_info\n", i);
                fprintf(saida, "\tNome:\t\t\tcp_info #%" PRIu16 "\t<", constPool->u.NameAndType.name_index);
                printConstantNameAndType(cf,constPool,'n',saida);
                fprintf(saida, ">\n\tDescritor:\t\tcp_info #%" PRIu16 "\t<", constPool->u.NameAndType.descriptor_index);
                printConstantNameAndType(cf,constPool,'d',saida);
                fprintf(saida, ">\n\n");
                break;
            case	CONSTANT_Utf8:
                fprintf(saida, "[%" PRIu16 "]\tCONSTANTE_Utf8_info\n", i);
                fprintf(saida, "\tTamanho do array de byte:\t%" PRIu16, constPool->u.Utf8.length);
                fprintf(saida, "\n\tString:\t\t\t");
                printConstUtf8(constPool, saida);
                fprintf(saida, "\n\n");
                break;
        }
    }
}


void	showInterfaces(ClassFile * cf, FILE * saida){
    fprintf(saida,"Interfaces:\n\tQuantidade de interfaces:\t%" PRIu16 "\n\n", cf->interfaces_count);
    for(uint16_t i = 0; i < cf->interfaces_count; i++){
        fprintf(saida, "Interface %" PRIu16, i);
        fprintf(saida,"\t\tcp_info #%" PRIu16, cf->interfaces[i]);
        if(cf->constant_pool[cf->interfaces[i]-1].tag != CONSTANT_Class){
            puts("\nERRO: interface nao referencia uma CONSTANTE_Class_info.\n");
            exit(EXIT_FAILURE);
        }
        else{
            uint16_t		name_index;
            constant_pool_info *	constPool;
            
            name_index = cf->constant_pool[cf->interfaces[i]-1].u.Class.name_index;
            constPool = cf->constant_pool + name_index - 1;
            if(constPool->tag != CONSTANT_Utf8){
                puts("\nERRO: interface nao referencia um class_name_index valido.\n");
                exit(EXIT_FAILURE);
            }
            else{
                fprintf(saida, "\t<");
                printConstUtf8(constPool, saida);
                fprintf(saida, ">\n\n");
            }
        }
    }
}

void	showFields(ClassFile * cf, FILE * saida){
    fprintf(saida,"Fields:\nQuantidade de fields:\t\t%" PRIu16 "\n", cf->fields_count);
    for(uint16_t i = 0; i < cf->fields_count; i++){
        fprintf(saida,"\n");
        uint16_t		name_index = (cf->fields+i)->name_index;
        constant_pool_info *	constPool = cf->constant_pool + name_index - 1;
        if(constPool->tag != CONSTANT_Utf8){
            puts("\nERRO: field nao referencia um name_index valido.\n");
            exit(EXIT_FAILURE);
        }
        fprintf(saida, "[%" PRIu16 "]\t", i);
        printConstUtf8(constPool, saida);
        fprintf(saida, "\n");
        
        fprintf(saida,"\tNome:\t\t\tcp_info #%" PRIu16, (cf->fields+i)->name_index);
        fprintf(saida, "\t<");
        printConstUtf8(constPool, saida);
        fprintf(saida, ">\n");
        
        uint16_t	descriptor_index = (cf->fields+i)->descriptor_index;
        constPool = cf->constant_pool + descriptor_index - 1;
        if(constPool->tag != CONSTANT_Utf8){
            puts("\nERRO: field nao referencia um descriptor_index valido.\n");
            exit(EXIT_FAILURE);
        }
        fprintf(saida,"\tDescritor:\t\tcp_info #%" PRIu16, (cf->fields+i)->descriptor_index);
        fprintf(saida, "\t<");
        printConstUtf8(constPool, saida);
        fprintf(saida, ">\n");
        
        
        fprintf(saida,"\tFlags de Acesso:\t\t0x%.4" PRIx16 "\t\t[", (cf->fields+i)->access_flags);
        uint16_t	access_flags = (cf->fields+i)->access_flags;
        if(access_flags >= 0x80){
            fprintf(saida, "transient ");
            access_flags -= 0x80;
        }
        if(access_flags >= 0x40){
            fprintf(saida, "volatile");
            access_flags -= 0x40;
        }
        if(access_flags >= ACC_FINAL){
            fprintf(saida, "final ");
            access_flags -= ACC_FINAL;
        }
        if(access_flags >= 0x8){
            fprintf(saida, "static ");
            access_flags -= 0x8;
        }
        if(access_flags >= 0x4){
            fprintf(saida, "protected ");
            access_flags -= 0x4;
        }
        if(access_flags >= 0x2){
            fprintf(saida, "private ");
            access_flags -= 0x2;
        }
        if(access_flags >= ACC_PUBLIC){
            fprintf(saida, "public");
            access_flags -= ACC_PUBLIC;
        }
        fprintf(saida,"]\n");
        
        fprintf(saida,"\n\tField's attributes count:\t%" PRIu16 "\n", (cf->fields+i)->attributes_count);
        field_info *	fd_in = (cf->fields+i);
        showAttributes(fd_in, NULL, NULL, cf, saida);
    }
    fprintf(saida, "\n");
}

void	showMethods(ClassFile * cf, FILE * saida){
    fprintf(saida,"Metodos:\nQuantidade de metodos:\t\t%" PRIu16 "\n", cf->methods_count);
    for(uint16_t i = 0; i < cf->methods_count; i++){
        fprintf(saida,"\n");
        uint16_t		name_index = (cf->methods+i)->name_index;
        constant_pool_info *	constPool = cf->constant_pool + name_index - 1;
        if(constPool->tag != CONSTANT_Utf8){
            puts("\nERRO: metodo nao possui um name_index valido.\n");
            exit(EXIT_FAILURE);
        }
        fprintf(saida, "[%" PRIu16 "]\t", i);
        printConstUtf8(constPool, saida);
        fprintf(saida, "\n");
        
        fprintf(saida,"Nome:\t\t\tcp_info #%" PRIu16, (cf->methods+i)->name_index);
        fprintf(saida, "\t<");
        printConstUtf8(constPool, saida);
        fprintf(saida, ">\n");
        
        fprintf(saida,"Descritor:\t\tcp_info #%" PRIu16, (cf->methods+i)->descriptor_index);
        uint16_t	descriptor_index = (cf->methods+i)->descriptor_index;
        constPool = cf->constant_pool + descriptor_index - 1;
        if(constPool->tag != CONSTANT_Utf8){
            puts("\nERRO: metodo nao possui um descriptor_index valido.\n");
            exit(EXIT_FAILURE);
        }
        else{
            fprintf(saida, "\t<");
            printConstUtf8(constPool, saida);
            fprintf(saida, ">\n");
        }
        
        fprintf(saida,"Flags de Acesso:\t\t0x%.4" PRIx16 "\t\t[", (cf->methods+i)->access_flags);
        uint16_t	access_flags = (cf->methods+i)->access_flags;
        if(access_flags >= 0x800){
            fprintf(saida, "strict ");
            access_flags -= 0x800;
        }
        if(access_flags >= ACC_ABSTRACT){
            fprintf(saida, "abstrato ");
            access_flags -= ACC_ABSTRACT;
        }
        if(access_flags >= 0x100){
            fprintf(saida, "native ");
            access_flags -= 0x100;
        }
        if(access_flags >= ACC_SUPER){
            fprintf(saida, "synchronized ");
            access_flags -= ACC_SUPER;
        }
        if(access_flags >= ACC_FINAL){
            fprintf(saida, "final ");
            access_flags -= ACC_FINAL;
        }
        if(access_flags >= 0x8){
            fprintf(saida, "static ");
            access_flags -= 0x8;
        }
        if(access_flags >= 0x4){
            fprintf(saida, "protected ");
            access_flags -= 0x4;
        }
        if(access_flags >= 0x2){
            fprintf(saida, "private ");
            access_flags -= 0x2;
        }
        if(access_flags >= ACC_PUBLIC){
            fprintf(saida, "public");
            access_flags -= ACC_PUBLIC;
        }
        fprintf(saida,"]\n");
        
        fprintf(saida,"\nContador de atributos do metodo:\t%" PRIu16 "\n", (cf->methods+i)->attributes_count);
        method_info *	mt_in = (cf->methods+i);
        showAttributes(NULL, mt_in, NULL, cf, saida);
    }
}

void	showAttributes(field_info * fd_in, method_info * mt_in, attribute_info * attr_in, ClassFile * cf, FILE * saida){
    uint16_t			attributes_count;
    attribute_info *	attributes;
    int	attribute_tab;
    
    if(fd_in != NULL){
        attributes_count = fd_in->attributes_count;
        attributes = fd_in->attributes;
        attribute_tab = METHOD_FIELD;
    }
    else if(mt_in != NULL){
        attributes_count = mt_in->attributes_count;
        attributes = mt_in->attributes;
        attribute_tab = METHOD_FIELD;
    }
    
    uint16_t	name_index;
    constant_pool_info *	constPool;
    attribute_info	* attributes_aux = attributes;
    for(uint16_t i = 0; i < attributes_count; i++){
        name_index = attributes_aux->attribute_name_index;
        constPool = cf->constant_pool + name_index - 1;
        if(constPool->tag != CONSTANT_Utf8){
            puts("\nERRO: atributo nao referencia um name_index valido.\n");
            exit(EXIT_FAILURE);
        }
        
        switch(attribute_tab){
            case	CLASS:
                fprintf(saida,"\n");
                fprintf(saida, "[%" PRIu16 "]\t", i);
                printConstUtf8(constPool, saida);
                fprintf(saida, "\n");
                
                fprintf(saida, "Informacoes gerais:\n");
                fprintf(saida, "\tIndice do nome do atributo:\tcp_info #%" PRIu16, attributes_aux->attribute_name_index);
                fprintf(saida, "\t");
                printConstUtf8(constPool, saida);
                fprintf(saida, "\n");
                
                fprintf(saida, "\tTamanho do atributo:\t%" PRIu16 "\n", attributes_aux->attribute_length);
                fprintf(saida, "Informacoes especificas:\n");
                break;
            case	METHOD_FIELD:
                fprintf(saida,"\n");
                fprintf(saida, "[%" PRIu16 "]", i);
                fprintf(saida, "\t");
                printConstUtf8(constPool, saida);
                fprintf(saida, "\n");
                
                fprintf(saida, "\tInformacoes gerais:\n");
                fprintf(saida, "\t\tIndice do nome do atributo:\tcp_info #%" PRIu16, attributes_aux->attribute_name_index);
                fprintf(saida, "\t");
                printConstUtf8(constPool, saida);
                fprintf(saida, "\n");
                
                fprintf(saida, "\t\tTamanho do atributo:\t%" PRIu16 "\n", attributes_aux->attribute_length);
                fprintf(saida, "\tInformacoes especificas:\n");
                break;
            case	ATTRIBUTE:
                fprintf(saida,"\n");
                fprintf(saida, "\t[%" PRIu16 "]", i);
                fprintf(saida, "\t");
                printConstUtf8(constPool, saida);
                fprintf(saida, "\n");
                
                fprintf(saida, "\t\tInformacoes gerais:\n");
                fprintf(saida, "\t\t\tIndice do nome do atributo:\tcp_info #%" PRIu16, attributes_aux->attribute_name_index);
                fprintf(saida, "\t");
                printConstUtf8(constPool, saida);
                fprintf(saida, "\n");
                
                fprintf(saida, "\t\t\tTamanho do atributo:\t%" PRIu16 "\n", attributes_aux->attribute_length);
                fprintf(saida, "\t\tInformacoes especificas:\n");
                break;
        }
        constant_pool_info *	cp_a0;
        int64_t		bits;
        int32_t		branch;
        switch(getAttributeType(attributes_aux, cf)){
            case	CONSTANT_VALUE:
                ;
                uint16_t	constantvalue_index = attributes_aux->u.ConstantValue.constantvalue_index;
                fprintf(saida, "\t\tCONSTANTE value index:\tcp_info #%" PRIu16, constantvalue_index);
                cp_a0 = cf->constant_pool + constantvalue_index - 1;
                switch(cp_a0->tag){
                    case	CONSTANT_Integer:
                        fprintf(saida, "\t<%" PRId32 ">\n", cp_a0->u.Integer_Float.bytes);
                        break;
                    case	CONSTANT_Long:
                        bits = (((int64_t) cp_a0->u.Long_Double.high_bytes) << 32)
                        + cp_a0->u.Long_Double.low_bytes;
                        fprintf(saida,"\t<%" PRId64 ">\n", bits);
                        break;
                    case	CONSTANT_Float:
                        ;
                        float	float_number;
                        memcpy(&float_number,&cp_a0->u.Integer_Float.bytes, sizeof(uint32_t));
                        fprintf(saida, "\t<%f>\n", float_number);
                        break;
                    case	CONSTANT_Double:
                        bits = (((int64_t) cp_a0->u.Long_Double.high_bytes) << 32)
                        + cp_a0->u.Long_Double.low_bytes;
                        switch(bits){
                            case 0x7ff0000000000000L:
                                fprintf(saida, "\t<+8>\n");
                                break;
                            case 0xfff0000000000000L:
                                fprintf(saida, "\t<-8>\n");
                                break;
                            default:
                                if((bits >= 0x7ff0000000000001L &&
                                    bits <= 0x7ffffffffffffL) ||
                                   (bits >= 0xfff0000000000001L &&
                                    bits <= 0xffffffffffffffffL )){
                                       fprintf(saida, "\t<NaN>\n");
                                   }
                                else{
                                    int32_t s = ((bits >> 63) == 0) ? 1 : -1;
                                    int32_t e = ((bits >> 52) & 0x7ffL);
                                    int64_t m = (e == 0) ?
                                    (bits & 0xfffffffffffffL) << 1 :
                                    (bits & 0xfffffffffffffL) |
                                    0x10000000000000L;
                                    fprintf(saida, "\t<%f>\n",
                                            (double) s*m*pow(2, (e-1075)));
                                }
                        }
                        break;
                    case	CONSTANT_String:
                        fprintf(saida,"\t<");
                        printConstantString(cf, cp_a0, saida);
                        fprintf(saida,">\n");
                        break;
                }
                break;
            case	CODE:
                fprintf(saida, "\t\tBytecode:\n");
                fprintf(saida,"\t\t\tlinha\toffobtain\n");
                uint8_t *	nextCode;
                uint32_t	lineNumber = 1;
                uint16_t	index;
                uint32_t	i;
                int32_t default_, n;
                int16_t	const_;
                
                for(uint32_t offobtain = 0; offobtain < attributes_aux->u.Code.code_length;){
                    fprintf(saida,"\t\t\t%" PRIu32 "\t%" PRIu32"\t", lineNumber++,offobtain);
                    nextCode = attributes_aux->u.Code.code + offobtain;
                    switch(*nextCode){
                            // 0 bytes
                        case	aaload:
                        case	aastore:
                        case	aconst_null:
                        case	aload_0:
                        case	aload_1:
                        case	aload_2:
                        case	aload_3:
                        case	areturn:
                        case	arraylength:
                        case	astore_0:
                        case	astore_1:
                        case	astore_2:
                        case	astore_3:
                        case	athrow:
                        case	baload:
                        case	bastore:
                        case	breakpoint:
                        case	caload:
                        case	castore:
                        case	d2f:
                        case	d2i:
                        case	d2l:
                        case	dadd:
                        case	daload:
                        case	dastore:
                        case	dcmpg:
                        case	dcmpl:
                        case	dconst_0:
                        case	dconst_1:
                        case	ddiv:
                        case	dload_0:
                        case	dload_1:
                        case	dload_2:
                        case	dload_3:
                        case	dmul:
                        case	dneg:
                        case	drem:
                        case	dreturn:
                        case	dstore_0:
                        case	dstore_1:
                        case	dstore_2:
                        case	dstore_3:
                        case	dsub:
                        case	dup:
                        case	dup_x1:
                        case	dup_x2:
                        case	dup2:
                        case	dup2_x1:
                        case	dup2_x2:
                        case	f2d:
                        case	f2i:
                        case	f2l:
                        case	fadd:
                        case	faload:
                        case	fastore:
                        case	fcmpg:
                        case	fcmpl:
                        case	fconst_0:
                        case	fconst_1:
                        case	fconst_2:
                        case	fdiv:
                        case	fload_0:
                        case	fload_1:
                        case	fload_2:
                        case	fload_3:
                        case	fmul:
                        case	fneg:
                        case	frem:
                        case	freturn:
                        case	fstore_0:
                        case	fstore_1:
                        case	fstore_2:
                        case	fstore_3:
                        case	fsub:
                        case	i2b:
                        case	i2c:
                        case	i2d:
                        case	i2f:
                        case	i2l:
                        case	i2s:
                        case	iadd:
                        case	iaload:
                        case	iand:
                        case	iastore:
                        case	iconst_m1:
                        case	iconst_0:
                        case	iconst_1:
                        case	iconst_2:
                        case	iconst_3:
                        case	iconst_4:
                        case	iconst_5:
                        case	idiv:
                        case	iload_0:
                        case	iload_1:
                        case	iload_2:
                        case	iload_3:
                        case	impdep1:
                        case	impdep2:
                        case	imul:
                        case	ineg:
                        case	ior:
                        case	irem:
                        case	ireturn:
                        case	ishl:
                        case	ishr:
                        case	istore_0:
                        case	istore_1:
                        case	istore_2:
                        case	istore_3:
                        case	isub:
                        case	iushr:
                        case	ixor:
                        case	l2d:
                        case	l2f:
                        case	l2i:
                        case	ladd:
                        case	laload:
                        case	land:
                        case	lastore:
                        case	lcmp:
                        case	lconst_0:
                        case	lconst_1:
                        case	ldiv_:
                        case	lload_0:
                        case	lload_1:
                        case	lload_2:
                        case	lload_3:
                        case	lmul:
                        case	lneg:
                        case	lor:
                        case	lrem:
                        case	lreturn:
                        case	lshl:
                        case	lshr:
                        case	lstore_0:
                        case	lstore_1:
                        case	lstore_2:
                        case	lstore_3:
                        case	lsub:
                        case	lushr:
                        case	lxor:
                        case	monitorenter:
                        case	monitorexit:
                        case	nop:
                        case	pop:
                        case	pop2:
                        case	return_:
                        case	saload:
                        case	sastore:
                        case	swap:
                            fprintf(saida, "%s\n", op_codesJVM[*nextCode]);
                            offobtain++;
                            break;
                            // 1 byte
                            //	local variable index (uint8_t)
                        case	aload:
                        case	astore:
                        case	dload:
                        case	dstore:
                        case	fload:
                        case	fstore:
                        case	iload:
                        case	istore:
                        case	lload:
                        case	lstore:
                        case	ret:
                            fprintf(saida, "%s", op_codesJVM[*nextCode]);
                            fprintf(saida, "\t%" PRIu8 "\n", *(nextCode+1));
                            offobtain +=2;
                            break;
                            
                            //	signed integer (s1)
                        case	bipush:
                            fprintf(saida, "%s", op_codesJVM[*nextCode]);
                            fprintf(saida, "\t%" PRId8 "\n", *(nextCode+1));
                            offobtain +=2;
                            break;
                            
                            //	array type (uint8_t)
                        case	newarray:
                            fprintf(saida, "%s\t", op_codesJVM[*nextCode]);
                            fprintf(saida,"%" PRId8, *(nextCode+1));
                            switch(*(nextCode+1)){
                                case	T_BOOLEAN:
                                    fprintf(saida," (boolean)\n");
                                    break;
                                case	T_CHAR:
                                    fprintf(saida," (char)\n");
                                    break;
                                case	T_FLOAT:
                                    fprintf(saida," (float)\n");
                                    break;
                                case	T_DOUBLE:
                                    fprintf(saida," (double)\n");
                                    break;
                                case	T_BYTE:
                                    fprintf(saida," (byte)\n");
                                    break;
                                case	T_SHORT:
                                    fprintf(saida," (short)\n");
                                    break;
                                case	T_INT:
                                    fprintf(saida," (int)\n");
                                    break;
                                case	T_LONG:
                                    fprintf(saida," (long\n");
                                    break;
                                default:
                                    printf("ERRO: newarray aplicado tipo invalido.\n");
                                    exit(EXIT_FAILURE);
                                    break;
                            }
                            offobtain +=2;
                            break;
                            
                            //	CONSTANTE pool index (integer, float, string) (uint8_t)
                        case	ldc:
                            fprintf(saida, "%s", op_codesJVM[*nextCode]);
                            fprintf(saida, "\t#%" PRIu8, *(nextCode+1));
                            cp_a0 = cf->constant_pool + *(nextCode+1) - 1;
                            switch(cp_a0->tag){
                                case	CONSTANT_Integer:
                                    fprintf(saida, "\t<%" PRId32 ">\n", cp_a0->u.Integer_Float.bytes);
                                    break;
                                case	CONSTANT_Float:
                                    ;
                                    float	float_number;
                                    memcpy(&float_number,&cp_a0->u.Integer_Float.bytes, sizeof(uint32_t));
                                    fprintf(saida, "\t<%f>\n", float_number);
                                    break;
                                case	CONSTANT_String:
                                    fprintf(saida,"\t<");
                                    printConstantString(cf, cp_a0, saida);
                                    fprintf(saida,">\n");
                                    break;
                                default:
                                    puts("ERRO: instrucaoo ldc com argumento invalido\n");
                                    exit(EXIT_FAILURE);
                            }
                            offobtain +=2;
                            break;
                            
                            // 2 bytes
                            //	constant_pool index (class) (uint16_t)
                        case	anewarray:
                        case	checkcast:
                        case	instanceof:
                        case	new:
                            fprintf(saida, "%s", op_codesJVM[*nextCode]);
                            index = (uint16_t) (*(nextCode+1) << 8) + *(nextCode+2);
                            fprintf(saida, "\t#%" PRIu16, index);
                            cp_a0 = cf->constant_pool + index - 1;
                            if(cp_a0->tag != CONSTANT_Class){
                                printf("\nERRO: %s nao referencia um CONSTANT_Class valido.\n",
                                       op_codesJVM[*nextCode]);
                                exit(EXIT_FAILURE);
                            }
                            else{
                                uint16_t	name_index = cp_a0->u.Class.name_index;
                                cp_a0 = cf->constant_pool + name_index - 1;
                                
                                fprintf(saida, "\t<");
                                printConstUtf8(cp_a0, saida);
                                fprintf(saida, ">\n");
                            }
                            offobtain +=3;
                            break;
                            
                            //	branch offobtain (s2)
                        case	goto_:
                        case	if_acmpeq:
                        case	if_acmpne:
                        case	if_icmpeq:
                        case	if_icmpge:
                        case	if_icmpgt:
                        case	if_icmple:
                        case	if_icmplt:
                        case	if_icmpne:
                        case	ifeq:
                        case	ifge:
                        case	ifgt:
                        case	ifle:
                        case	iflt:
                        case	ifne:
                        case	ifnonnull:
                        case	ifnull:
                        case	jsr:
                            fprintf(saida, "%s", op_codesJVM[*nextCode]);
                            branch = ( (int8_t) *(nextCode+1) << 8) + *(nextCode+2);
                            fprintf(saida, "\t%" PRId32 "\t(%+" PRId32 ")\n", (int32_t) offobtain + branch, branch);
                            offobtain +=3;
                            break;
                            
                            //	CONSTANTE pool index (integer, float, string) (uint16_t)
                        case	ldc_w:
                            fprintf(saida, "%s", op_codesJVM[*nextCode]);
                            index = (uint16_t) (*(nextCode+1) << 8) + *(nextCode+2);
                            fprintf(saida, "\t#%" PRIu16 "\n", index);
                            cp_a0 = cf->constant_pool + *(nextCode+1) - 1;
                            switch(cp_a0->tag){
                                case	CONSTANT_Integer:
                                    fprintf(saida, "\t<%" PRId32 ">\n", cp_a0->u.Integer_Float.bytes);
                                    break;
                                case	CONSTANT_Float:
                                    ;
                                    float	float_number;
                                    memcpy(&float_number,&cp_a0->u.Integer_Float.bytes, sizeof(uint32_t));
                                    fprintf(saida, "\t<%f>\n", float_number);
                                    break;
                                case	CONSTANT_String:
                                    fprintf(saida,"\t<");
                                    printConstantString(cf, cp_a0, saida);
                                    fprintf(saida,">\n");
                                    break;
                                default:
                                    puts("ERRO: instrucao ldc_w com argumento invalido\n");
                                    exit(EXIT_FAILURE);
                            }
                            offobtain +=3;
                            break;
                            
                            //	CONSTANTE pool index (fieldref; methodref) (uint16_t)
                        case	getfield:
                        case	getstatic:
                        case	invokespecial:
                        case	invokestatic:
                        case	invokevirtual:
                        case	putfield:
                        case	putstatic:
                            fprintf(saida, "%s", op_codesJVM[*nextCode]);
                            index = (uint16_t) (*(nextCode+1) << 8) + *(nextCode+2);
                            fprintf(saida, "\t#%" PRIu16, index);
                            cp_a0 = cf->constant_pool + index - 1;
                            if(cp_a0->tag != CONSTANT_Methodref && cp_a0->tag != CONSTANT_Fieldref){
                                printf("\nERRO: %s nao referencia um CONSTANTE_ref valido.\n",
                                       op_codesJVM[*nextCode]);
                                exit(EXIT_FAILURE);
                            }
                            else{
                                uint16_t	name_index = cp_a0->u.Ref.name_index;
                                uint16_t	name_and_type_index = cp_a0->u.Ref.name_and_type_index;
                                
                                cp_a0 = cf->constant_pool + name_index - 1;
                                if(cp_a0->tag != CONSTANT_Class){
                                    printf("\nERRO: %s nao referencia um CONSTANTE_ref valido.\n",
                                           op_codesJVM[*nextCode]);
                                    exit(EXIT_FAILURE);
                                }
                                else{
                                    uint16_t	name_index = cp_a0->u.Class.name_index;
                                    cp_a0 = cf->constant_pool + name_index - 1;
                                    
                                    fprintf(saida, "\t<");
                                    printConstUtf8(cp_a0, saida);
                                    
                                    cp_a0 = cf->constant_pool + name_and_type_index - 1;
                                    if(cp_a0->tag != CONSTANT_NameAndType){
                                        printf("\nERRO: %s nao referencia um CONSTANTE_ref valido.\n",
                                               op_codesJVM[*nextCode]);
                                        exit(EXIT_FAILURE);
                                    }
                                    else{
                                        name_index = cp_a0->u.NameAndType.name_index;
                                        cp_a0 = cf->constant_pool + name_index - 1;
                                        
                                        fprintf(saida, ".");
                                        printConstUtf8(cp_a0, saida);
                                        fprintf(saida, ">\n");
                                    }
                                }
                                
                            }
                            offobtain +=3;
                            break;
                            
                            //	CONSTANTE pool index (long, double) (uint16_t)
                        case	ldc2_w:
                            fprintf(saida, "%s", op_codesJVM[*nextCode]);
                            index = (uint16_t) (*(nextCode+1) << 8) + *(nextCode+2);
                            fprintf(saida, "\t#%" PRIu16, index);
                            cp_a0 = cf->constant_pool + index - 1;
                            switch(cp_a0->tag){
                                case	CONSTANT_Long:
                                    bits = (((int64_t) cp_a0->u.Long_Double.high_bytes) << 32)
                                    + cp_a0->u.Long_Double.low_bytes;
                                    fprintf(saida,"\t<%" PRId64 ">\n", bits);
                                    break;
                                case	CONSTANT_Double:
                                    bits = (((int64_t) cp_a0->u.Long_Double.high_bytes) << 32)
                                    + cp_a0->u.Long_Double.low_bytes;
                                    switch(bits){
                                        case 0x7ff0000000000000L:
                                            fprintf(saida, "\t<+8>\n");
                                            break;
                                        case 0xfff0000000000000L:
                                            fprintf(saida, "\t<-8>\n");
                                            break;
                                        default:
                                            if((bits >= 0x7ff0000000000001L &&
                                                bits <= 0x7ffffffffffffL) ||
                                               (bits >= 0xfff0000000000001L &&
                                                bits <= 0xffffffffffffffffL )){
                                                   fprintf(saida, "\t<NaN>\n");
                                               }
                                            else{
                                                int32_t s = ((bits >> 63) == 0) ? 1 : -1;
                                                int32_t e = ((bits >> 52) & 0x7ffL);
                                                int64_t m = (e == 0) ?
                                                (bits & 0xfffffffffffffL) << 1 :
                                                (bits & 0xfffffffffffffL) |
                                                0x10000000000000L;
                                                fprintf(saida, "\t<%f>\n",
                                                        (double) s*m*pow(2, (e-1075)));
                                            }
                                    }
                                    break;
                                default:
                                    puts("ERRO: instrucao ldc2_w com argumento invalido\n");
                                    exit(EXIT_FAILURE);
                            }
                            offobtain +=3;
                            break;
                            
                            //	signed short (s2)
                        case	sipush:
                            fprintf(saida, "%s", op_codesJVM[*nextCode]);
                            fprintf(saida, "\t%" PRId16 "\n", *(nextCode+1));
                            offobtain +=3;
                            break;
                            
                            //	unsigned byte (uint8_t); signed byte (s1)
                        case	iinc: // 1 byte 1 byte
                            fprintf(saida, "%s", op_codesJVM[*nextCode]);
                            fprintf(saida, "\t%" PRIu8 , *(nextCode+1));
                            fprintf(saida, " by %" PRId8 "\n", *(nextCode+2));
                            offobtain +=3;
                            break;
                            // 3 bytes
                            // constant_pool index (class) (uint16_t) ; unsigned byte (uint8_t)
                        case	multianewarray:
                            fprintf(saida, "%s", op_codesJVM[*nextCode]);
                            index = (uint16_t) (*(nextCode+1) << 8) + *(nextCode+2);
                            fprintf(saida, "\t#%" PRIu16, index);
                            cp_a0 = cf->constant_pool + index - 1;
                            if(cp_a0->tag != CONSTANT_Class){
                                printf("\nERRO: %s nao referencia um CONSTANT_Class valido.\n",
                                       op_codesJVM[*nextCode]);
                                exit(EXIT_FAILURE);
                            }
                            else{
                                uint16_t	name_index = cp_a0->u.Class.name_index;
                                cp_a0 = cf->constant_pool + name_index - 1;
                                
                                fprintf(saida, "\t<");
                                printConstUtf8(cp_a0, saida);
                                fprintf(saida, ">");
                            }
                            fprintf(saida, "\tdim %" PRIu8 "\n", *(nextCode+3));
                            offobtain +=4;
                            break;
                            
                            // 4 bytes
                            // branch offobtain (uint32_t)
                        case	goto_w:
                        case	jsr_w:
                            fprintf(saida, "%s", op_codesJVM[*nextCode]);
                            branch = ((uint32_t) *(nextCode+1) << 24) + ((uint32_t) *(nextCode+2) << 16) +
                            ((uint32_t) *(nextCode+3) << 8) + *(nextCode+4);
                            fprintf(saida, "\t%" PRIu32 "\t(+%" PRIu32 ")\n", offobtain + branch, branch);
                            offobtain +=5;
                            break;
                            
                            // constant_pool index (uint16_t); unsigned byte (uint8_t); unsigned byte (uint8_t)
                        case	invokeinterface:
                        case	invokedynamic:
                            fprintf(saida, "%s", op_codesJVM[*nextCode]);
                            index = (uint16_t) (*(nextCode+1) << 8) + *(nextCode+2);
                            fprintf(saida, "\t#%" PRIu16, index);
                            cp_a0 = cf->constant_pool + index - 1;
                            if(cp_a0->tag != CONSTANT_InterfaceMethodref && cp_a0->tag != CONSTANT_Methodref){
                                printf("\nERRO: %s nao referencia um CONSTANTE_ref valido.\n",
                                       op_codesJVM[*nextCode]);
                                exit(EXIT_FAILURE);
                            }
                            else{
                                uint16_t	name_index = cp_a0->u.Ref.name_index;
                                uint16_t	name_and_type_index = cp_a0->u.Ref.name_and_type_index;
                                
                                cp_a0 = cf->constant_pool + name_index - 1;
                                if(cp_a0->tag != CONSTANT_Class){
                                    printf("\nERRO: %s nao referencia um CONSTANTE_ref valido.\n",
                                           op_codesJVM[*nextCode]);
                                    exit(EXIT_FAILURE);
                                }
                                else{
                                    uint16_t	name_index = cp_a0->u.Class.name_index;
                                    cp_a0 = cf->constant_pool + name_index - 1;
                                    
                                    fprintf(saida, "\t<");
                                    printConstUtf8(cp_a0, saida);
                                    
                                    cp_a0 = cf->constant_pool + name_and_type_index - 1;
                                    if(cp_a0->tag != CONSTANT_NameAndType){
                                        printf("\nERRO: %s nao referencia um CONSTANTE_ref valido.\n",op_codesJVM[*nextCode]);
                                        exit(EXIT_FAILURE);
                                    }
                                    else{
                                        name_index = cp_a0->u.NameAndType.name_index;
                                        cp_a0 = cf->constant_pool + name_index - 1;
                                        
                                        fprintf(saida, ".");
                                        printConstUtf8(cp_a0, saida);
                                        fprintf(saida, ">");
                                    }
                                    fprintf(saida,"\t<%" PRIu8  ">\n", *(nextCode+3));
                                }
                            }
                            offobtain +=5;
                            break;
                            
                            // 4 ou + bytes
                            //	<0-3 byte pad>; default (s4); n (s4); key1, offobtain_label1 ... keyn, offobtain_labeln (s4)
                        case	lookupswitch:
                            fprintf(saida, "%s", op_codesJVM[*nextCode]);
                            i = (offobtain+1) % 4;
                            default_ = (*((1+i) + nextCode) << 24) | (*((2+i) + nextCode) << 16) |
                            (*((3+i) + nextCode) << 8) | *((4+i) + nextCode);
                            
                            n = (*((5+i) + nextCode) << 24) | (*((6+i) + nextCode) << 16) |
                            (*((7+i) + nextCode) << 8) | *((8+i) + nextCode);
                            i += 8;
                            fprintf(saida,"\t%" PRId32 "\n", n);
                            
                            int32_t	key, offobtain_label;
                            for(uint32_t j = 0; j < n; j++){
                                fprintf(saida,"\t\t\t\t\t%" PRIu32, lineNumber++);
                                key = (*((1+i) + nextCode) << 24) | (*((2+i) + nextCode) << 16) |
                                (*((3+i) + nextCode) << 8) | *((4+i) + nextCode);
                                i += 4;
                                fprintf(saida, "\t\t\t%" PRId32, key);
                                offobtain_label = (*((1+i) + nextCode) << 24) | (*((2+i) + nextCode) << 16) |
                                (*((3+i) + nextCode) << 8) | *((4+i) + nextCode);
                                i += 4;
                                fprintf(saida, ":\t%" PRId32 " (%+" PRId32 ")\n",
                                        offobtain + offobtain_label, offobtain_label);
                            }
                            fprintf(saida, "\t\t\t\t\t%" PRIu32, lineNumber++);
                            fprintf(saida, "\t\t\tdefault:\t%" PRId32 " (+%" PRId32 ")\n",
                                    offobtain + default_, default_);
                            offobtain +=i;
                            offobtain++;
                            break;
                            
                            //	<0-3 byte pad>; default (s4); low (s4); high (s4); label1 ... labeln (s4)
                        case	tableswitch:
                            fprintf(saida, "%s", op_codesJVM[*nextCode]);
                            i = (offobtain+1) % 4;
                            default_ = (*((1+i) + nextCode) << 24) | (*((2+i) + nextCode) << 16) |
                            (*((3+i) + nextCode) << 8) | *((4+i) + nextCode);
                            
                            int32_t	low = (*((5+i) + nextCode) << 24) | (*((6+i) + nextCode) << 16) |
                            (*((7+i) + nextCode) << 8) | *((8+i) + nextCode);
                            
                            int32_t	high = (*((9+i) + nextCode) << 24) | (*((10+i) + nextCode) << 16) |
                            (*((11+i) + nextCode) << 8) | *((12+i) + nextCode);
                            
                            i += 12;
                            fprintf(saida, "\t%" PRId32 " to %" PRId32 "\n", low, high);
                            
                            n = high - low + 1;
                            
                            int32_t	label;
                            for(uint32_t j = 0; j < n; j++){
                                fprintf(saida,"\t\t\t\t\t%" PRIu32, lineNumber++);
                                label = (*((1+i) + nextCode) << 24) | (*((2+i) + nextCode) << 16) |
                                (*((3+i) + nextCode) << 8) | *((4+i) + nextCode);
                                i += 4;
                                fprintf(saida, "\t\t\t%" PRId32 ":\t%" PRId32 " (%+" PRId32 ")\n",
                                        j, offobtain + label, label);
                            }
                            fprintf(saida, "\t\t\t\t\t%" PRIu32, lineNumber++);
                            fprintf(saida, "\t\t\tdefault:\t%" PRId32 " (%+" PRId32 ")\n",
                                    offobtain + default_, default_);
                            offobtain +=i;
                            offobtain++;
                            break;
                            // 3 ou 5 bytes
                        case	wide:
                            fprintf(saida, "%s", op_codesJVM[*nextCode]);
                            fprintf(saida,"\t\t\t\t\t%" PRIu32, lineNumber++);
                            fprintf(saida, "%s", op_codesJVM[*(nextCode+1)]);
                            index = (uint16_t) (*(nextCode+2) << 8) + *(nextCode+3);
                            fprintf(saida, "\t%" PRIu16, index);
                            switch(*(nextCode+1)){
                                case	aload:
                                case	dload:
                                case	iload:
                                case	fload:
                                case	lload:
                                case	astore:
                                case	dstore:
                                case	istore:
                                case	fstore:
                                case	lstore:
                                case	ret:
                                    offobtain +=4;
                                    break;
                                case	iinc:
                                    const_ = (uint16_t) (*(nextCode+4) << 8) + *(nextCode+5);
                                    fprintf(saida,"\t%" PRId16, const_);
                                    offobtain +=6;
                                    break;
                                default:
                                    printf("ERRO: wide aplicado a uma instrucao invalida\n");
                                    exit(EXIT_FAILURE);
                            }
                            fprintf(saida, "\n");
                            break;
                    }
                }
                fprintf(saida, "\n\t\t\tTamanho da Tabela de Excecoes:\t\t%" PRId16 "\n", attributes_aux->u.Code.exception_table_length);
                if(attributes_aux->u.Code.exception_table_length){
                    fprintf(saida, "\n\t\t\tException table:\n");
                    fprintf(saida, "\t\t\tNr.\tstart_pc\tend_pc\thandler_pc\tcatch_type\tverbose\n");
                    for(uint16_t i = 0; i < attributes_aux->u.Code.exception_table_length; i++){
                        fprintf(saida,"\t\t\t%" PRId16, i);
                        fprintf(saida,"\t%" PRId16,
                                (attributes_aux->u.Code.exception_table + i)->start_pc);
                        fprintf(saida,"\t%" PRId16,
                                (attributes_aux->u.Code.exception_table + i)->end_pc);
                        fprintf(saida,"\t%" PRId16,
                                (attributes_aux->u.Code.exception_table + i)->handler_pc);
                        fprintf(saida,"\tcp_info #%" PRId16,
                                (attributes_aux->u.Code.exception_table + i)->catch_type);
                        constant_pool_info	* cp_a0 = cf->constant_pool + (attributes_aux->u.Code.exception_table + i)->catch_type - 1;
                        printConstantClass(cf, cp_a0, saida);
                        fprintf(saida,"\n");
                        
                    }
                }
                fprintf(saida, "\n\t\tMiscellaneous:\n");
                fprintf(saida, "\t\t\t\tProfundidade Maxima da Pilha:\t\t%" PRId16 "\n", attributes_aux->u.Code.max_stack);
                fprintf(saida, "\t\t\t\tVariaveis locais maximas:\t%" PRId16 "\n", attributes_aux->u.Code.max_locals);
                fprintf(saida, "\t\t\t\tTamanho do Code:\t\t\t%" PRId32 "\n", attributes_aux->u.Code.code_length);
                fprintf(saida,"\n\t\tQuantidade de atributos de Code:\t%" PRId16 "\n", attributes_aux->u.Code.attributes_count);
                showAttributes(NULL, NULL, attributes_aux, cf, saida);
                break;
            case	DEPRECATED:
                /* */
                break;
            case	EXCEPTIONS:
                fprintf(saida, "\t\t\tNumero de excecoes: %" PRId16, attributes_aux->u.Exceptions.number_of_exceptions);
                fprintf(saida,"\t\t\tTabela de indice de excecoes:\n");
                for(uint16_t i = 0; i < attributes_aux->u.Exceptions.number_of_exceptions; i++){
                    fprintf(saida,"\t\t\t constant_pool_info #%" PRId16 "\n", attributes_aux->u.Exceptions.exception_index_table[i]);
                }
                break;
            case	INNER_CLASSES:
                fprintf(saida, "\t\tNumero de classes: %" PRId16 "\n", attributes_aux->u.InnerClasses.number_of_classes);
                fprintf(saida, "\t\t\tClasses:\n");
                classes_type	* classes_aux = attributes_aux->u.InnerClasses.classes;
                for(uint16_t i = 0; i < attributes_aux->u.InnerClasses.number_of_classes; i++){
                    fprintf(saida, "\t\t\t\tClass %" PRId16 "\n", i);
                    fprintf(saida, "\t\t\t\t\tinner_class_info_index:\t\tcp_info #%" PRId16 "\t",
                            (classes_aux)->inner_class_info_index);
                    printConstantClass(cf, cf->constant_pool +
                                       (classes_aux)->inner_class_info_index - 1, saida);
                    fprintf(saida, "\n\t\t\t\t\tsaider_class_info_index:\t\tcp_info #%" PRId16 "\t",
                            (classes_aux)->saidaer_class_info_index);
                    printConstantClass(cf, cf->constant_pool +
                                       (classes_aux)->saidaer_class_info_index - 1, saida);
                    fprintf(saida, "\n\t\t\t\t\tinner_name_index:\t\tcp_info #%" PRId16 "\t",
                            (classes_aux)->inner_name_index);
                    printConstUtf8(cf->constant_pool +
                                     (classes_aux)->inner_name_index - 1, saida);
                    fprintf(saida, "\n\t\t\t\t\tinner_class_access_flags:\t0x%.4" PRIx16 "\t\t",
                            (classes_aux)->inner_class_access_flags);
                    uint16_t	access_flags = (classes_aux)->inner_class_access_flags;
                    fprintf(saida, "[");
                    if(access_flags >= ACC_ABSTRACT){
                        fprintf(saida, "abstract ");
                        access_flags -= ACC_ABSTRACT;
                    }
                    if(access_flags >= ACC_INTERFACE){
                        fprintf(saida, "interface ");
                        access_flags -= ACC_INTERFACE;
                    }
                    if(access_flags >= ACC_FINAL){
                        fprintf(saida, "final ");
                        access_flags -= ACC_FINAL;
                    }
                    if(access_flags >= 0x8){
                        fprintf(saida, "static ");
                        access_flags -= 0x08;
                    }
                    if(access_flags >= 0x4){
                        fprintf(saida, "protected ");
                        access_flags -= 0x4;
                    }
                    if(access_flags >= 0x2){
                        fprintf(saida, "private ");
                        access_flags -= 0x2;
                    }
                    if(access_flags >= ACC_PUBLIC){
                        fprintf(saida, "public");
                        access_flags -= ACC_PUBLIC;
                    }
                    fprintf(saida, "]\n");
                    classes_aux++;
                }
                break;
            case	LINE_NUMBER_TABLE:
                fprintf(saida, "\t\t\t\tTamanho da Tabela de Numero de Linha:\t%" PRId16 "\n",
                        attributes_aux->u.LineNumberTable.line_number_table_length);
                fprintf(saida, "\t\t\t\tTabela de Numero de Linha:\n");
                fprintf(saida, "\t\t\t\tNr.\tstart_pc\tline_number\n");
                for(uint16_t i = 0; i < attributes_aux->u.LineNumberTable.line_number_table_length; i++){
                    fprintf(saida,"\t\t\t\t%" PRId16, i);
                    fprintf(saida,"\t%" PRId16, ((attributes_aux->u.LineNumberTable.line_number_table)+i)->start_pc);
                    fprintf(saida,"\t%" PRId16 "\n",
                            ((attributes_aux->u.LineNumberTable.line_number_table)+i)->line_number);			
                }
                break;
            case	LOCAL_VARIABLE_TABLE:
                fprintf(saida, "\t\t\tTamanho da Tabela de Variavel Local:\t%" PRId16 "\n",
                        attributes_aux->u.LocalVariableTable.local_variable_table_length);
                fprintf(saida, "\t\t\tTabela de Variavel Local:\n");
                fprintf(saida, "\t\t\tNr.\tstart_pc\tlength\tindex\tname_index\tdescriptor_index\n");
                for(uint16_t i = 0; i < attributes_aux->u.LocalVariableTable.local_variable_table_length; i++){
                    fprintf(saida,"\t\t\t%" PRId16, i);
                    fprintf(saida,"\t%" PRId16,
                            ((attributes_aux->u.LocalVariableTable.local_variable_table)+i)->start_pc);		
                    fprintf(saida,"\t%" PRId16,
                            ((attributes_aux->u.LocalVariableTable.local_variable_table)+i)->length);
                    fprintf(saida,"\t%" PRId16,
                            ((attributes_aux->u.LocalVariableTable.local_variable_table)+i)->index);
                    fprintf(saida,"\tcp_info #%" PRId16,
                            ((attributes_aux->u.LocalVariableTable.local_variable_table)+i)->name_index);
                    fprintf(saida,"\tcp_info #%" PRId16 "\n",
                            ((attributes_aux->u.LocalVariableTable.local_variable_table)+i)->descriptor_index);
                    cp_a0 = cf->constant_pool + (((attributes_aux->u.LocalVariableTable.local_variable_table)+i)->name_index) - 1;
                    fprintf(saida,"\t\t\t\t\t\t\t\t");
                    printConstUtf8(cp_a0, saida);
                    fprintf(saida,"\t");
                    cp_a0 = cf->constant_pool + (((attributes_aux->u.LocalVariableTable.local_variable_table)+i)->descriptor_index) - 1;
                    printConstUtf8(cp_a0, saida);	
                    fprintf(saida, "\n");
                    
                }
                break;
            case	SOURCE_FILE:
                fprintf(saida, "\t\tIndice do nome do arquivo fonte:\tcp_info #%" PRId16,
                        attributes_aux->u.SourceFile.sourcefile_index);
                uint16_t	sourcefile_index = attributes_aux->u.SourceFile.sourcefile_index;
                cp_a0 = cf->constant_pool + sourcefile_index - 1;
                if(cp_a0->tag != CONSTANT_Utf8){
                    puts("\nERRO: SourceFile Attribute nao referencia um nome valido.\n");
                    exit(EXIT_FAILURE);
                }
                else{
                    fprintf(saida, "\t");
                    printConstUtf8(cp_a0, saida);
                    fprintf(saida, "\n");	
                }
                break;
            case	UNKNOWN:
                /*				// IGNORANDO ATRIBUTOS DESCONHECIDOS*/
                break;			
        }
        attributes_aux++;
    }
}


// retorna 1 byte lido da stream fileInput
uint8_t		u1Read(FILE * file){
    int8_t	to_return = getc(file);
    if(to_return == EOF){
        puts("ClassFormatError");
        exit(EXIT_FAILURE);
    }
    return	to_return;
}

// retorna 2 bytes lidos da stream fileInput
uint16_t		u2Read(FILE * file){
    int16_t	to_return = getc(file);
    if(to_return == EOF){
        puts("ClassFormatError");
        exit(EXIT_FAILURE);
    }
	
	uint8_t to_return2 = u1Read(file);
	
    to_return = (to_return << 8) | to_return2;
    return	to_return;
}

// retorna 4 bytes lidos da stream fileInput
uint32_t		u4Read(FILE * file){
    uint32_t	to_return = getc(file);
    if(to_return == EOF){
        puts("ClassFormatError");
        exit(EXIT_FAILURE);
    }

	uint8_t to_return2 = u1Read(file);
    to_return = (to_return << 8) | to_return2; 
    
	to_return2 = u1Read(file);
    to_return =  (to_return << 8) | to_return2;
    
	to_return2 = u1Read(file);
    to_return =  (to_return << 8) | to_return2;
    return	to_return;
}

// retorna o tipo de atributo.
ATTRIBUTE_TYPE	getAttributeType(attribute_info * attr, ClassFile * cf){
    uint16_t		name_index = attr->attribute_name_index;
    constant_pool_info *	constPool = cf->constant_pool + name_index - 1;
    
    // CONSTANT_Utf8
    uint16_t		length = constPool->u.Utf8.length;
    uint8_t*		bytes = constPool->u.Utf8.bytes;
    
    if(length != 0){
        switch(bytes[0]){
            case	'C':
                if(!strcmp((char *) bytes, "Code")){
                    return	CODE;
                }
                else if(!strcmp((char *) bytes, "ConstantValue")){
                    return	CONSTANT_VALUE;					
                }
                break;
            case	'D':
                if(!strcmp((char *) bytes, "Deprecated")){
                    return	DEPRECATED;
                }
                break;
            case	'E':
                if(!strcmp((char *) bytes, "Exceptions")){
                    return	EXCEPTIONS;
                }
                break;
            case	'I':
                if(!strcmp((char *) bytes, "InnerClasses")){
                    return	INNER_CLASSES;
                }
                break;
            case	'L':
                if(!strcmp((char *) bytes, "LineNumberTable")){
                    return	LINE_NUMBER_TABLE;
                }
                else if(!strcmp((char *) bytes, "LocalVariableTable")){
                    return	LOCAL_VARIABLE_TABLE;
                }
                break;
            case	'S':
                if(!strcmp((char *) bytes, "Synthetic")){
                    return	SYNTHETIC;
                }
                else if(!strcmp((char *) bytes, "SourceFile")){
                    return	SOURCE_FILE;
                }
                break;
            default:
                return	UNKNOWN;
        }
    }
    return	UNKNOWN;	
}


// Faz a leitura do arquivo .class, e retorna um ponteiro para estrutura ClassFile com os campos preenchidos;
ClassFile *	obtainClassFile(FILE * file){
    
	// alocando espaço para estrutura do tipo ClassFile.
	ClassFile *	cf = (ClassFile *) malloc(sizeof(ClassFile)); 
    if (cf == NULL) {
		printf("Erro ao alocar memoria CLASSEDEARQUIVO");
		exit(1);
	}
	
	// le uint32_t (4 bytes) do arquivo e atualiza o campo magic do ClassFile.
    cf->magic = u4Read(file);	
    if(cf->magic != 0xCAFEBABE){
        puts("ClassFormatError");
        free(cf);
        exit(EXIT_FAILURE);
    }
	
	// le dois uint16_t (2 bytes) do arquivo e atualiza os campos minor_version e major_version do ClassFile
	cf->minor_version = u2Read(file);
    cf->major_version = u2Read(file);
	//45 = versao 1.1
	//46 = versao 1.2 
    if((cf->major_version > 46) || (cf->major_version < 45) 
		|| (cf->major_version == 46 && cf->minor_version != 0)){
        puts("UnsupportedClassVersionError");
        exit(EXIT_FAILURE);
    }
	
	// le e armazena o pool de CONSTANTEes.
    obtainConstantPool(cf, file);
	
	// le uint16_t (2 bytes) do arquivo e atualiza o campo access_flags do ClassFile
    cf->access_flags = u2Read(file);		
	
	// le e armazena o campo this_class do ClassFile (uint16_t) 2 bytes
    cf->this_class = u2Read(file);	

	// le e armazena o campo super_class do ClassFile (uint16_t)	2 bytes
    cf->super_class = u2Read(file);	
	
    obtainInterfaces(cf, file);
	
    obtainFields(cf, file);
	
    obtainMethods(cf, file);
	
    obtainAttributes(NULL, NULL, NULL, cf, file);
	
	//Aqui verifica o final do arquivo class, se não tiver acabado ou erro de leitura ou de arquivo.
    if(getc(file) != EOF){
        puts("ClassFormatError");
    }
    return	cf;
}

// le e armazena o pool de CONSTANTEes do ClassFile
void		obtainConstantPool(ClassFile * cf, FILE * file){
    cf->constant_pool_count = u2Read(file);  // le o numero de elementos na CONSTANTE pool
    /*	printf("constant_pool_count = %" PRIu16, cf->constant_pool_count);*/
    if(cf->constant_pool_count == 0){
        puts("VerifyError");
        exit(EXIT_FAILURE);
    }
    cf->constant_pool = (constant_pool_info *) malloc((cf->constant_pool_count -1)*sizeof(constant_pool_info)); //FREE OK
    
    constant_pool_info * constPool; // declara um tipo const pool para usar e obtainar
    for(constPool = cf->constant_pool; constPool < (cf->constant_pool + cf->constant_pool_count - 1); constPool++){
        constPool->tag = 0;
        constPool->tag = u1Read(file);
        /*		printf("\ncp_tag = %" PRIu8, constPool->tag);*/
        switch(constPool->tag){			
            case	CONSTANT_Class:
                constPool->u.Class.name_index = u2Read(file);
                break;
                // Field, method e interfacemethod recebem name and type e class index (u2)
            case	CONSTANT_Fieldref:
            case	CONSTANT_Methodref:
            case	CONSTANT_InterfaceMethodref:
                constPool->u.Ref.name_index = u2Read(file);
                constPool->u.Ref.name_and_type_index = u2Read(file);
                break;
                // recebe string (u2)
            case	CONSTANT_String:
                constPool->u.String.string_index = u2Read(file);
                break;
                // Inteiro e float recebem os Bytes (u4)
            case	CONSTANT_Integer:
            case	CONSTANT_Float:
                constPool->u.Integer_Float.bytes = u4Read(file);
                break;
                // Long e Double recebem 8 bytes (u4, u4)
                // Long e Double ocupam dois índices da constant_pool: High, Low
            case	CONSTANT_Long:
            case	CONSTANT_Double:
                constPool->u.Long_Double.high_bytes = u4Read(file);
                constPool->u.Long_Double.low_bytes = u4Read(file);
                constPool++;	
                break;
                
                //Nome e tipo (u2 , u2)
            case	CONSTANT_NameAndType:
                constPool->u.NameAndType.name_index = u2Read(file);
                constPool->u.NameAndType.descriptor_index = u2Read(file);
                break;
                
                //Unicode recebe o tamanho (u2), aloca um vetor e coloca no array os bytes (u1)
            case	CONSTANT_Utf8:
                constPool->u.Utf8.length = u2Read(file);
                if(constPool->u.Utf8.length){
                    constPool->u.Utf8.bytes = (uint8_t *) malloc((constPool->u.Utf8.length + 1) * sizeof(uint8_t)); // FREE OK
                    for(uint16_t i = 0; i < constPool->u.Utf8.length; i++){
                        constPool->u.Utf8.bytes[i] = u1Read(file);
                    }	
                    constPool->u.Utf8.bytes[constPool->u.Utf8.length] = '\0';
                }
                else{
                    constPool->u.Utf8.bytes = NULL;
                }
                
                break;
            default:
                puts("VerifyError");
                exit(EXIT_FAILURE);
        }	
    }
}

// le e armazena as interfaces do ClassFile (u2)
void		obtainInterfaces(ClassFile * cf, FILE * file){
    cf->interfaces_count = u2Read(file); // recebe o numéro direto de superinterfaces dessa classe ou tipos de interface
    if(cf->interfaces_count){
        // declara o vetor, aloca e recebe os valores de index para dentro da CONSTANTE pool para cada interface 
        // implemetada pela classe.
        cf->interfaces = (uint16_t *) malloc((cf->interfaces_count)*sizeof(uint16_t));	// FREE OK
        for(uint16_t * in = cf->interfaces; in < (cf->interfaces + cf->interfaces_count); in++){
            *in = u2Read(file);
        }
    }
    else{
        cf->interfaces = NULL;
    }
    
}

// le e armazena os fields do ClassFile
void		obtainFields(ClassFile * cf, FILE * file){
    cf->fields_count = u2Read(file); // recebe o numero de estruturas field_info para alocar e receber informa
    
    if(cf->fields_count){
        cf->fields = (field_info *) malloc((cf->fields_count)*sizeof(field_info));	// FREE OK
        for(field_info * fd_in = cf->fields; fd_in < (cf->fields + cf->fields_count); fd_in++){
            fd_in->access_flags = u2Read(file);
            fd_in->name_index = u2Read(file);
            fd_in->descriptor_index = u2Read(file);
            obtainAttributes(fd_in, NULL, NULL, cf, file);
			}
    }
    else{
        cf->fields = NULL;
    }
}

// le e armazena os métodos do ClassFile
void		obtainMethods(ClassFile * cf, FILE * file){
    cf->methods_count = u2Read(file); // Pega o número de estruturas de method_info
    
    if(cf->methods_count){
        // aloca e le as informacoes para o array method_info
        cf->methods = (method_info *) malloc((cf->methods_count)*sizeof(method_info));	// FREE OK
        for(method_info * mt_in = cf->methods; mt_in < (cf->methods + cf->methods_count); mt_in++){
            mt_in->access_flags = u2Read(file);
            mt_in->name_index = u2Read(file);
            mt_in->descriptor_index = u2Read(file);
            obtainAttributes(NULL, mt_in, NULL, cf, file);
        }
    }
    else{
        cf->methods = NULL;
    }
    
}

// le e armazena os atributos do ClassFile
void	obtainAttributes(field_info * fd_in, method_info * mt_in, attribute_info * attr_in, ClassFile * cf,FILE * file){
    attribute_info *	attributes;
    uint16_t			attributes_count;
    
    if(fd_in != NULL){
        fd_in->attributes_count = u2Read(file);
        
        if(fd_in->attributes_count){
            fd_in->attributes = (attribute_info *) malloc(fd_in->attributes_count * sizeof(attribute_info));	
        }
        else{
            fd_in->attributes = NULL;
        }
        attributes_count = fd_in->attributes_count;
        attributes = fd_in->attributes;
    }
    else if(mt_in != NULL){
        mt_in->attributes_count = u2Read(file);
        if(mt_in->attributes_count){
            mt_in->attributes = (attribute_info *) malloc(mt_in->attributes_count * sizeof(attribute_info));	
        }
        else{
            mt_in->attributes = NULL;
        }		
        attributes_count = mt_in->attributes_count;
        attributes = mt_in->attributes;
    }
    else if(attr_in != NULL){
        attr_in->u.Code.attributes_count = u2Read(file);
        if(attr_in->u.Code.attributes_count){
            attr_in->u.Code.attributes = (attribute_info *) malloc(attr_in->u.Code.attributes_count * sizeof(attribute_info));
        }
        else{
            attr_in->u.Code.attributes = NULL;
        }
        attributes_count = attr_in->u.Code.attributes_count;
        attributes = attr_in->u.Code.attributes;
    }
    else if(cf != NULL){
        cf->attributes_count = u2Read(file);
        if(cf->attributes_count){
            cf->attributes = (attribute_info *) malloc(cf->attributes_count * sizeof(attribute_info));
        }
        else{
            cf->attributes = NULL;
        }
        
        
        attributes_count = cf->attributes_count;
        attributes = cf->attributes;
    }
    else{
        puts("Erro ao obter atributos");
        exit(EXIT_FAILURE);
    }
    
    for(attribute_info * attr = attributes; attr < (attributes + attributes_count); attr++){
        attr->attribute_name_index = u2Read(file);
        attr->attribute_length = u4Read(file);
        
		ATTRIBUTE_TYPE attrTypeResult = getAttributeType(attr, cf);
		
		if (attrTypeResult == CONSTANT_VALUE) 
		{
			attr->u.ConstantValue.constantvalue_index = u2Read(file);
		} 
		else if (attrTypeResult == CODE) 
		{
			 attr->u.Code.max_stack = u2Read(file);
                attr->u.Code.max_locals = u2Read(file);
                attr->u.Code.code_length = u4Read(file);
                if(attr->u.Code.code_length){
                    attr->u.Code.code = (uint8_t *) malloc(attr->u.Code.code_length * sizeof(uint8_t));
                    for(uint8_t * cd = attr->u.Code.code; cd < (attr->u.Code.code + attr->u.Code.code_length); cd++)
                        *cd = u1Read(file);
                }
                
                
                attr->u.Code.exception_table_length = u2Read(file);
                if(attr->u.Code.exception_table_length){
                    attr->u.Code.exception_table =
                    (exception_table_type *) malloc(attr->u.Code.exception_table_length * sizeof(exception_table_type));
                    
                    for(exception_table_type * ex_tb = attr->u.Code.exception_table;
                        ex_tb < (attr->u.Code.exception_table + attr->u.Code.exception_table_length); ex_tb++){
                        ex_tb->start_pc = u2Read(file);
                        ex_tb->end_pc = u2Read(file);
                        ex_tb->handler_pc = u2Read(file);	
                        ex_tb->catch_type = u2Read(file);					
                    }
                }
                
                obtainAttributes(NULL, NULL, attr, cf, file);
		} 
		else if (attrTypeResult == DEPRECATED) 
		{
			//TEM QUE FAZER ALGO ???
		} 
		else if (attrTypeResult == EXCEPTIONS)
			{
			attr->u.Exceptions.number_of_exceptions = u2Read(file);
                attr->u.Exceptions.exception_index_table = (uint16_t *) malloc(attr->u.Exceptions.number_of_exceptions * sizeof(uint16_t));
                for(uint16_t * ex_in_tb = attr->u.Exceptions.exception_index_table; 
                    ex_in_tb < (attr->u.Exceptions.exception_index_table + attr->u.Exceptions.number_of_exceptions); ex_in_tb++)
                    * ex_in_tb = u2Read(file);	
		} 
		else if (attrTypeResult == INNER_CLASSES)
		{
			attr->u.InnerClasses.number_of_classes = u2Read(file);
                attr->u.InnerClasses.classes =
                (classes_type *) malloc(attr->u.InnerClasses.number_of_classes * sizeof(classes_type));
                for(classes_type * cl = attr->u.InnerClasses.classes;
                    cl < (attr->u.InnerClasses.classes + attr->u.InnerClasses.number_of_classes); cl++){
                    cl->inner_class_info_index = u2Read(file);
                    cl->saidaer_class_info_index = u2Read(file);
                    cl->inner_name_index = u2Read(file);
                    cl->inner_class_access_flags = u2Read(file);
                }
		} 
		else if (attrTypeResult == LINE_NUMBER_TABLE) 
		{
			attr->u.LineNumberTable.line_number_table_length = u2Read(file);
                if(attr->u.LineNumberTable.line_number_table_length){
                    attr->u.LineNumberTable.line_number_table = (line_number_table_type *)
                    malloc(attr->u.LineNumberTable.line_number_table_length * sizeof(line_number_table_type));
                    
                    for(line_number_table_type * ln_tb = attr->u.LineNumberTable.line_number_table; 
                        ln_tb < (attr->u.LineNumberTable.line_number_table + attr->u.LineNumberTable.line_number_table_length); ln_tb++){	
                        ln_tb->start_pc = u2Read(file);
                        ln_tb->line_number = u2Read(file);
                    }			
                }
		} 
		else if (attrTypeResult == LOCAL_VARIABLE_TABLE) 
		{
			attr->u.LocalVariableTable.local_variable_table_length = u2Read(file);
                if(attr->u.LocalVariableTable.local_variable_table_length){
                    attr->u.LocalVariableTable.local_variable_table = (local_variable_table_type *)
                    malloc(attr->u.LocalVariableTable.local_variable_table_length * sizeof(local_variable_table_type));
                    
                    for(local_variable_table_type * lv_tb = attr->u.LocalVariableTable.local_variable_table; 
                        lv_tb < (attr->u.LocalVariableTable.local_variable_table +
                                 attr->u.LocalVariableTable.local_variable_table_length); lv_tb++){
                            lv_tb->start_pc = u2Read(file);
                            lv_tb->length = u2Read(file);
                            lv_tb->name_index = u2Read(file);
                            lv_tb->descriptor_index = u2Read(file);
                            lv_tb->index = u2Read(file);
                        }
                }
		} 
		else if (attrTypeResult == SYNTHETIC) 
		{
			//TEM QUE FAZER ALGO ???
		} 
		else if (attrTypeResult == SOURCE_FILE) 
		{
			attr->u.SourceFile.sourcefile_index = u2Read(file);
		} 
		else 
		{
			//UNKNOWN TYPE JA QUE NAO CAIU EM NENHUM CASO CONHECIDO
		}
		
    }
}



// libera memória alocada da estrutura ClassFile
void	freeClassFile(ClassFile * cf){
    
    if(!cf){
        return;
    }
    free(cf->interfaces);
    freeFields(cf);
    freeMethods(cf);
//Gambiarra 2
    for(attribute_info * attr = cf->attributes; attr < (cf->attributes + cf->attributes_count); attr++){
        freeAttribute(attr, cf);
    }
    if(cf->attributes_count){
        free(cf->attributes);
    }
    freeConstantPool(cf);	
    free(cf);
}

void	freeConstantPool(ClassFile * cf){
    for(constant_pool_info * constPool = cf->constant_pool; constPool < (cf->constant_pool + cf->constant_pool_count - 1); constPool++){
		if (constPool->tag == CONSTANT_Utf8) {
			free(constPool->u.Utf8.bytes);
		}
    }
    free(cf->constant_pool);
}

void	freeFields(ClassFile * cf){
    for(field_info * fd_in = cf->fields; fd_in < (cf->fields + cf->fields_count); fd_in++){
        for(attribute_info * attr = fd_in->attributes; attr < (fd_in->attributes + fd_in->attributes_count); attr++){
            freeAttribute(attr, cf);
        }
        if(fd_in->attributes_count){
            free(fd_in->attributes);
        }
    }
    if(cf->fields_count){
        free(cf->fields);
    }
}

void	freeMethods(ClassFile * cf){
    for(method_info * mt_in = cf->methods; mt_in < (cf->methods + cf->methods_count); mt_in++){
        for(attribute_info * attr = mt_in->attributes; attr < (mt_in->attributes + mt_in->attributes_count); attr++){
            freeAttribute(attr, cf);
        }
        if(mt_in->attributes_count){
            free(mt_in->attributes);
        }
    }
    if(cf->methods_count){
        free(cf->methods);
    }
}

void	freeAttribute(attribute_info * attr, ClassFile * cf){
    switch(getAttributeType(attr, cf)){
        case	CONSTANT_VALUE:
            break;
        case	CODE:
            if(attr->u.Code.code_length){
                free(attr->u.Code.code);				
            }
            
            if(attr->u.Code.exception_table_length){
                free(attr->u.Code.exception_table);
            }
            
            for(attribute_info * attr_ = attr->u.Code.attributes;
                attr_ < (attr->u.Code.attributes + attr->u.Code.attributes_count); attr_++){
                freeAttribute(attr_, cf);
            }
            if(attr->u.Code.attributes_count){
                free(attr->u.Code.attributes);
            }
            
            break;
        case	DEPRECATED:
            break;
        case	EXCEPTIONS:
            free(attr->u.Exceptions.exception_index_table);					
            break;
        case	INNER_CLASSES:
            if(attr->u.InnerClasses.number_of_classes){
                free(attr->u.InnerClasses.classes);
            }
            break;
        case	LINE_NUMBER_TABLE:
            if(attr->u.LineNumberTable.line_number_table_length){
                free(attr->u.LineNumberTable.line_number_table);
            }
            break;
        case	LOCAL_VARIABLE_TABLE:
            if(attr->u.LocalVariableTable.local_variable_table_length){
                free(attr->u.LocalVariableTable.local_variable_table);
            }
            break;
        case	SYNTHETIC:
            break;
        case	SOURCE_FILE:
            break;
        case	UNKNOWN:
            break;							
    }
}


int	main(int argc, char* argv[]){
    
    char * class_filename = argv[1];
    
    if(argc == 3){
        FILE*	class_file;
        FILE* output;
		
		//Seleção de saida em [t]ela ou em [a]rquivo texto
        if (*argv[2] == 't')
        {
            output = stdout;
        }
        else if (*argv[2] == 'a')
        {
            output = fopen("output.txt","w");
        }
		
		//Erro de chamada
        else
        {
            printf("Uso:\tWIN: LeitorExibidor.exe NomeDaClasse.class t||a\n\tLINUX: ./LeitorExibidor NomeDaClasse.class t||a\n");
            exit(-1);
        }
        
        class_file = fopen(class_filename, "rb");
        if (class_file == NULL) {
            printf("Falha na Abertura do Arquivo\n");
            exit(-1);
        }
        
        ClassFile *cf = obtainClassFile(class_file);
        showClassFile(cf, output);
        freeClassFile(cf);
        fclose(class_file);
    } else {
        printf("Uso:\tWIN: LeitorExibidor.exe NomeDaClasse.class t||a\n\tLINUX: ./LeitorExibidor NomeDaClasse.class t||a\n");
    }
    
    
    return	0;
}
