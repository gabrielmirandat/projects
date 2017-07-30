//gcc (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef _WIN32
    #define CLEAR "cls" /* soh funciona no windows */
#else
    #define CLEAR "clear" /* soh funciona no linux ou mac (unix) */
#endif

/*-- observacoes
-> (fetch()), decodificação da instrução (decode()) e execução da instrução (execute()).
-> *address aponta para o registrador que fornece a valor base para o endereçamento.
-> GPR = general purpose registers

1. Construa um programa para testar cada uma das instruções acima. Não precisa 
fazer nenhuma função específica, apenas verifica se cada instruções executa ok.
2. Monte o programa na primeira página e a série fibonacci fornecida junto com o
MARS.
para cada exemplo:
3. Salve o código e dados nos arquivos indicados.
4. Leia os arquivos para a memória.
5. Execute o programa.
6. Utilize as funções dump_mem e dump_reg para mostrar os conteúdos.
7. Verifique o funcionamento de cada instrução do simulador.
*/

//----------------------------------------------------------------------------------------------------------------------------------------------//
//-- memoria
#define MEM_SIZE 4096		//8192
int32_t mem[MEM_SIZE];
int cont_text = 0;
int cont_data = MEM_SIZE/2;


//-- banco de registradores (sem contar os 3 ultimos - pc, hi e lo)
#define BREG_SIZE 32
int32_t breg[BREG_SIZE];

//-- registradores
uint32_t pc,ri;

//-- campos da instrucao
int32_t opcode, rs, rt, rd, shamt, funct, k26, hi, lo;
int16_t  k16;

//-- flag de encerramento do programa
int ENCERRAMENTO = 0;

//-- auxiliares
int32_t aux32;		//auxiliar 32 bits para carregar na memória.
int64_t aux64;		//auxiliar 64 bits para multiplicação
int passo=1;

//----------------------------------------------------------------------------------------------------------------------------------------------//
//-- funcoes de acesso à memoria
int32_t lb(uint32_t *address, uint16_t kte);
int32_t lh(uint32_t *address, uint16_t kte);
int32_t lw(uint32_t *address, uint16_t kte);
void sb(uint32_t *address, uint16_t kte, int8_t dado);
void sh(uint32_t *address, uint16_t kte, int16_t dado);
void sw(uint32_t *address, uint16_t kte, int32_t dado);

//-- funcoes novas
//lê uma instrução da memória e coloca-a em ri, atualizando o pc para apontar para a próxima instrução (soma 4).
void fetch();

//extrair todos os campos da instrução: opcode,rs,rt,rd,shamt,funct,k16,k26.
void decode();

//executa a instrução lida por fetch() e decodificada por decode().
void execute();

//executa uma instrução do MIPS: step() => fecth(), decode(), execute()
void step();

//executa o programa até encontrar uma chamada de sistema para encerramento, ou até o pc ultrapassar o limite do segmento de código (4k words). 
void run();

//Imprime o conteúdo da memória a partir do endereço start até o endereço end. O formato pode ser em hexa (‘h’) ou decimal (‘d’).
void dump_mem(int start, int end, char format);

//Imprime o conteúdo dos registradores do MIPS, incluindo o banco de registradores e os registradores pc, hi e lo. O formato pode ser em 
//hexa (‘h’) ou decimal (‘d’).
void dump_reg(char format);

enum OPCODES {//lembrem que so sao considerados os 6 primeiros bits dessas constantes
  EXT=0x00  ,	// Geral
  LH=0x21   ,	// Load Halfword
  SB=0x28   ,	// Store Byte
  BLEZ=0x06 ,	// Branch on Less Than or Equal to Zero
  SLTIU=0x0B,	// Set on Less Than Immediate Unsigned
  J=0x02    ,	// Jump
  JAL=0x03  ,	// Jump and Link
  LW=0x23   ,	// Load Word
  LB=0x20   ,	// Load Byte
  LBU=0x24  ,	// Load Byte Unsigned
  LHU=0x25  ,	// Load Halfword Unsigned
  LUI=0x0F  ,	// Load Upper Immediate
  SW=0x2B   ,	// Store Word
  SH=0x29   ,	// Store HalfWord
  BEQ=0x04  ,	// Branch on Equal
  BNE=0x05  ,	// Branch on Not Equal
  BGTZ=0x07 ,	// Branch on Greater Than Zero
  ADDI=0x08 ,	// Add Immediate Word
  ADDIU=0x09,	// Add Immediate Unsigned Word
  SLTI=0x0A ,	// Set on Less Than Immediate
  ANDI=0x0C ,	// And Immediate
  ORI=0x0D  ,	// Or Immediate
  XORI=0x0E ,	// Exclusive OR Immediate
};

//caso em que o opcode é 0
enum FUNCT {
  ADD=0x20    , // Add Word
  SUB=0x22    , // Subtract Word
  MULT=0x18   , // Multiply Word
  DIV=0x1A    , // Divide Word
  AND=0x24    , // And
  MFLO=0x12   , // Move From LO Register
  OR=0x25     , // Or
  XOR=0x26    , // Exclusive OR
  NOR=0x27    , // Not Or
  SLT=0x2A    , // Set on Less Than
  JR=0x08     , // Jump Register
  SLL=0x00    , // Shift Word Left Logical
  SRL=0x02    , // Shift Word Right Logical
  SRA=0x03    , // Shift Word Right Arithmetic
  SYSCALL=0x0c, // System Call
  MFHI=0x10   , // Move From HI Registercont_data
};

//Syscall: implementar as chamadas para
//✴ imprimir inteiro
//✴ imprimir string
//✴ encerrar programa


//----------------------------------------------------------------------------------------------------------------------------------------------//
int main(){
  FILE* arq_bin_data;
  FILE* arq_bin_text;
  FILE* arq_texto_data;
  FILE* arq_texto_text; 	
  int i,j,inicio,fim;
  char format,memoria;
  
  //leitura do arquivo binário de texto (código)
  arq_bin_text = fopen("text.bin","rb");  // para ler binario
  //arq_texto_text = fopen("arq_texto.txt","w");
  
  //leitura do arquivo binário de dados
  arq_bin_data = fopen("data.bin","rb");  // para ler binario
  //arq_texto_data = fopen("arq_data.txt","w");
  
  if((arq_bin_text == NULL) || (arq_bin_data == NULL)){
      printf("\nerro ao carregar arquivo binario.\n");
      return -1;
  }
  
  while(!feof(arq_bin_text)){
    fread (&aux32, sizeof(int32_t), 1, arq_bin_text);
    mem[cont_text] = aux32;
    cont_text++;
  }
  while(!feof(arq_bin_data)){
    fread (&aux32, sizeof(int32_t), 1, arq_bin_data);
    mem[cont_data] = aux32;
    cont_data++;
  }
  
  pc = 0;
  breg[0]=0;
  breg[28] = 0x00001800;
  breg[29] = 0x00003ffc;
  aux32 = 0;
  
  while(ENCERRAMENTO!=1){
    system(CLEAR);
    printf("1 - step()\n");
    printf("2 - run() \n");
    printf("3 - sair \n");
    scanf("%d", &i);
    getchar();
    switch(i){
        case 1:
	  step();
	  printf("verificar memoria? s/n:");
	  scanf("%c", &memoria);
	  getchar();
	    if(memoria=='s' || memoria=='S'){
              printf("h - hexa   d - decimal:");
              scanf("%c", &format);
              getchar();
              printf("pos inicial para dump_mem (decimal), de 0 a %d:", MEM_SIZE);
              scanf("%d", &inicio);
	      getchar();
              printf("pos final para dump_mem (decimal), de %d a %d:", inicio, MEM_SIZE);
              scanf("%d", &fim);
	      getchar();
              dump_mem(inicio, fim, format);
              dump_reg(format);
            }
	  break;
        case 2:
	  run();
	  printf("memoria e registradores : \n");
	  printf("h - hexa   d - decimal \n");
	  scanf("%c", &format);
	  getchar();
	  dump_mem((MEM_SIZE/2), (MEM_SIZE/2) + 32, format);
	  dump_reg(format);
	  break;
	case 3:
	  return 0;
	  break;
    }
  }
  
  //fclose(arq_texto_text);
  //fclose(arq_texto_data);
  
  fclose(arq_bin_text);
  fclose(arq_bin_data);
  
  printf("\n");
  return 0;
  
}

//-- funcoes de acesso à memoria
int32_t lb(uint32_t *address, uint16_t kte){
    int32_t valor;
    int32_t t0, q, w, r;
    t0 = *address;// pega o endereço da memória no registrador
    t0 = t0 + kte;// add $t0, $t0, $s1   soma com a constante
    // como o endereço é passado em bytes, divide por quatro para achar o índice na memória
    q = (t0/4);
    w = mem[q];
    // para achar qual byte da palavra é solicitado
    r = t0%4;
    w = w >> (8*r);
    //trata os casos de a palavra ser positiva ou negativa
    if(mem[q]>0)
        valor = (w & 0x000000FF); // and $t1, $t0, $t1
    else
        valor = (w | 0xFFFFFF00);
    //retorna o byte
    return valor;
}

int32_t lh(uint32_t *address, uint16_t kte){

    int32_t valor;
    int32_t t0, q, w, r;
    t0 = *address;// pega o endereço da memória no registrador
    t0 = t0 + kte;// add $t0, $t0, $s1   soma com a constante
    // t0 precisa ser múltiplo de 2
    // como o endereço é passado em bytes, divide por quatro para achar o índice na memória
    q = (t0/4);
    w = mem[q];
    // para achar qual byte da palavra é solicitado
    r = t0%4;
    w = w >> (8*r);
    //trata os casos de a palavra ser positiva ou negativa
    if(mem[q]>0)
        valor = (w & 0x0000FFFF); // and $t1, $t0, $t1
    else
        valor = (w | 0xFFFF0000);
    //retorna o byte
    return valor;
}

int32_t lw(uint32_t *address, uint16_t kte){
    int32_t t0, q, w, r;
    t0 = *address;// pega o endereço da memória no registrador
    t0 = t0 + kte;// add $t0, $t0, $s1   soma com a constante
    // t0 precisa ser múltiplo de 2
    // como o endereço é passado em bytes, divide por quatro para achar o índice na memória
    q = (t0/4);
    w = mem[q];
    // para achar qual byte da palavra é solicitado
    r = t0%4;// aqui consideraremos que o usuário sempre vai selecionar um valor correto e o resto sempre será 0
    w = w >> (8*r);
    //trata os casos de a palavra ser positiva ou negativa
    return w;
}

void sb(uint32_t *address, uint16_t kte, int8_t dado){
    int32_t valor;
    int32_t t0, q, w, r;
    t0 = *address;// pega o endereço da memória no registrador
    t0 = t0 + kte;// add $t0, $t0, $s1   soma com a constante
    // como o endereço é passado em bytes, divide por quatro para achar o índice na memória
    q = (t0/4);
    // para achar qual byte da palavra é solicitado
    r = t0%4;
    valor = (int32_t) dado;
    valor = valor << (8*r); //faz shift no valor para o dado ficar na posição certa do byte na palavra
    // faz mascara na palavra da memoria para apagar o valor anterior
    switch(r){
        case 0:
        mem[q] = mem[q] & 0xFFFFFF00;
        break;
        case 1:
        mem[q] = mem[q] & 0xFFFF00FF;
        break;
        case 2:
        mem[q] = mem[q] & 0xFF00FFFF;
        break;
        case 3:
        mem[q] = mem[q] & 0x00FFFFFF;
        break;
    }
    // poe o valor dado na posicao solicitada
    mem[q] = mem[q] | valor;
}

void sh(uint32_t *address, uint16_t kte, int16_t dado){ // AQUI CONSIDEREI QUE O VALOR SEMPRE SERA MULTIPLO DE 2
    int32_t valor;
    int32_t t0, q, w, r;
    t0 = *address;// pega o endereço da memória no registrador

    t0 = t0 + kte;// add $t0, $t0, $s1   soma com a constante

    // como o endereço é passado em bytes, divide por quatro para achar o índice na memória
    q = (t0/4);

    // para achar qual byte da palavra é solicitado
    r = t0%4; // AQUI CONSIDEREI QUE O VALOR SEMPRE SERA MULTIPLO DE 2
    valor = (int32_t) dado;
    valor = valor << (8*r); //faz shift no valor para o dado ficar na posição certa do byte na palavra
    // faz mascara na palavra da memoria para apagar o valor anterior
    switch(r){
        case 0:
        mem[q] = mem[q] & 0xFFFF0000;
        break;
        case 2:
        mem[q] = mem[q] & 0x0000FFFF;
        break;
        default:
        break;
    }
    // poe o valor dado na posicao solicitada
    mem[q] = mem[q] | valor;
}

void sw(uint32_t *address, uint16_t kte, int32_t dado){ // AQUI CONSIDEREI QUE O VALOR SEMPRE SERA MULTIPLO DE 4
    int32_t t0, q;
    t0 = *address;// pega o endereço da memória no registrador

    t0 = t0 + kte;// add $t0, $t0, $s1   soma com a constante
    // como o endereço é passado em bytes, divide por quatro para achar o índice na memória
    q = (t0/4);// AQUI CONSIDEREI QUE O VALOR SEMPRE SERA MULTIPLO DE 4
    
    mem[q] = dado;
}

//lê uma instrução da memória e coloca-a em ri, atualizando o pc para apontar para a próxima instrução (soma 4).
void fetch(){
  ri = lw(&pc,0);
  pc = pc + 4;
}

//extrair todos os campos da instrução: opcode,rs,rt,rd,shamt,funct,k16,k26.
void decode(){
  opcode = (ri & 0xFC000000) >> 26;	//operacao basica da instrucao: opcode
  rs     = (ri & 0x03E00000) >> 21;	//primeiro registrador de operando origem
  rt     = (ri & 0x001F0000) >> 16;	//segundo registrador de operando origem
  rd     = (ri & 0x0000F800) >> 11;	//registrador de operando destino: resultado
  shamt  = (ri & 0x000007C0) >> 6;	//deslocamento: shift amount
  funct  = (ri & 0x0000003F);		//variacao da operacao: function code
  k16    = (uint16_t) (ri & 0x0000FFFF);//constante de 16 bits, valor imediato em instruções tipo I
  k26    = (ri & 0x03FFFFFF);		//constante de 26 bits, para instruções tipo J
}

//executa a instrução lida por fetch() e decodificada por decode().
void execute (void) {
    switch(opcode){
    case EXT:				// Geral					
     switch (funct){
        case ADD:			// Add Word			 tipo:R  realiza:R[rd] = R[rs] + R[rt]
	  breg[rd] = breg[rs] + breg[rt];
	  break;
        case SUB:			// Subtract Word		 tipo:R  realiza:R[rd] = R[rs] - R[rt]
	  breg[rd] = breg[rs] - breg[rt];
	  break;
        case MULT:			// Multiply Word		 tipo:R  realiza:{Hi,Lo} = R[rs] * R[rt]
	  aux64 = breg[rs] * breg[rt];
	  hi = (int32_t) ((aux64 & 0xFFFFFFFF00000000) >> 32);
	  lo = (int32_t) (aux64 & 0x00000000FFFFFFFF);
	  break;
	case DIV:                       // Divide Word       tipo:R  realiza: Lo=R[rs]/R[rt]      Hi=R[rs]%R[rt]
	  lo=breg[rs]/breg[rt];
	  hi=breg[rs]%breg[rt];
	  break;
        case MFHI:              	// Move From HI Register    tipo:R  realiza:  R[rd] = Hi
	  breg[rd] = hi;
	  break;
        case MFLO:              	// Move From LO Register   tipo:R  realiza: R[rd] = Lo
	  breg[rd] = lo;
	  break;
        case AND:               	// And         tipo:R  realiza: R[rd] = R[rs] & R[rt]
	  breg[rd] = breg[rs] & breg[rt];
	  break;
        case OR:                	// Or        tipo:R  realiza: R[rd] = R[rs] | R[rt]
	  breg[rd] = breg[rs] | breg[rt];
	  break;
        case XOR:               	// Exclusive OR      tipo:R  realiza: R[rd] = R[rs] xor R[rt]
	  breg[rd] = breg[rs] ^ breg[rt];
	  break;
        case NOR:               	// Not Or      tipo:R  realiza: R[rd] = R[rs] nor R[rt]
	  breg[rd] = ~(breg[rs] | breg[rt]);
	  break;
        case SLT:               	// Set on Less Than    tipo:R  realiza: R[rd] = (R[rs] < R[rt]) ? 1 : 0
	  if (breg[rs] < breg[rt])
	      breg[rd] = 0x00000001;
	  else
	      breg[rd] = 0x00000000;
	  break;
        case JR:                	// Jump Register     tipo:R  realiza: PC=R[rs] 
	  pc = breg[rs];
	  break;
        case SLL:               	// Shift Word Left Logical   tipo:R  realiza:  R[rd] = R[rt] << shamt
	  breg[rd] = breg[rt] << shamt;
	  break;
        case SRL:               	// Shift Word Right Logical      tipo:R  realiza:  R[rd] = R[rt] >> shamt
	  breg[rd] = breg[rt] >> shamt;
	  break;
        case SRA:               	// Shift Word Right Arithmetic   tipo:R  realiza:  R[rd] = R[rt] >>> shamt
	  //no aritmético, se for impar completa com 1.
	  aux32 = (breg[rt] & 0x800000000)>>31;
	  if(aux32==0x00000001){
	      aux32 = (0xFFFFFFFF) << (32 - shamt);
	      breg[rd] = (breg[rt] >> shamt) | aux32;
	  }
	  else if (aux32==0x00000000)
	      breg[rd] = breg[rt] >> shamt;
	  break;
        case SYSCALL:           	// System Call

	  if(breg[2]==1){
            //imprimir inteiro
	    
	    printf("0x%.8x \n", breg[4]);
          }
	  if(breg[2]==4) {
	    //imprimir ascii
	  
	    int32_t *a;
	    a = &mem[(breg[4]/4)];;
	    char *msg = (char *) a;
	    printf("%s \n", msg);
	  }
	  if(breg[2]==10){
	    //encerrar
	    
            ENCERRAMENTO = 1;
          }
	  break;
        default:
	  printf("funct nao implementada: 0x%x\n", funct);
	  exit(0);
	  break;
        }
    break;
    case LW:	               		// Load Word          tipo:I  realiza: rt ← memory[base+offset]										
      breg[rt] = lw(&breg[rs], k16);
      break;
    case LB:				// Load Byte          tipo:I  realiza: rt ← memory[base+offset]						
      breg[rt] = lb(&breg[rs], k16);
      break;
    case LBU:				// Load Byte Unsigned       tipo:I  realiza: rt ← memory[base+offset]							
      breg[rt] = (uint32_t) (lb(&breg[rs], k16));
      break;
    case LH:		            	// Load Halfword        tipo:I  realiza: rt ← memory[base+offset]									
      breg[rt] = lh(&breg[rs], k16);
      break;
    case LHU:		            	// Load Halfword Unsigned     tipo:I  realiza: rt ← memory[base+offset]									
      breg[rt] = (uint32_t) (lh(&breg[rs], k16));
      break;
    case LUI:				// Load Upper Immediate       tipo:I  realiza: rt ← immediate || 0 16						
      breg[rt] = ((int32_t) (k16))<< 16;
      break;  
    case SW:				// Store Word          tipo:I  realiza: memory[base+offset] ← rt							
      sw(&breg[rs],k16,breg[rt]);
      break;
    case SB:                		// Store Byte         tipo:I  realiza: memory[base+offset] ← rt
      sb(&breg[rs],k16,breg[rt]);
      break;
    case SH:                		// Store HalfWord       tipo:I  realiza: memory[base+offset] ← rt
      sh(&breg[rs],k16,breg[rt]);
      break;
    case BEQ:               		// Branch on Equal        tipo:I  realiza: if(R[rs]==R[rt])    PC=PC+4+BranchAddr
      if(breg[rs]==breg[rt])
	pc = pc + 4*((int32_t)(k16));
      break;
    case BNE:               		// Branch on Not Equal        tipo:I  realiza: if(R[rs]!=R[rt])    PC=PC+4+BranchAddr
      if(breg[rs]!=breg[rt])
	pc = pc + 4*((int32_t)(k16));
      break;
    case BLEZ:              		// Branch on Less Than or Equal to Zero   tipo:I  realiza: if rs ≤ 0 then branch
      if(breg[rs]<=0)
	pc = pc + 4*((int32_t)(k16));
      break;
    case BGTZ:              		// Branch on Greater Than Zero      tipo:I  realiza: if rs > 0 then branch
      if(breg[rs]>0)
	pc = pc + 4*((int32_t)(k16));
      break;
    case ADDI:              		// Add Immediate Word       tipo:I  realiza: R[rt] = R[rs] + SignExtImm
      breg[rt] = breg[rs] + (int32_t)(k16);
      break;
    case ADDIU:
      breg[rt] = breg[rs] + (int32_t)(k16);
      break;
    case SLTI:              		// Set on Less Than Immediate     tipo:I  realiza: R[rt] = (R[rs] < SignExtImm)? 1 : 0
      if (breg[rs] < ((int32_t) k16))
	breg[rt] = 0x00000001;
      else
	breg[rt] = 0x00000000;
      break;
    case SLTIU:             		// Set on Less Than Immediate Unsigned    tipo:I  realiza: rt ← (rs < immediate)
      if (((uint32_t) breg[rs]) < ((uint32_t) k16))
	breg[rt] = 0x00000001;
      else
	breg[rt] = 0x00000000;
      break;
    case ANDI:              		// And Immediate       tipo:I  realiza: R[rt] = R[rs] & ZeroExtImm
      breg[rt] = breg[rs] & ((int32_t) k16);
      break;
    case ORI:               		// Or Immediate         tipo:I  realiza: R[rt] = R[rs] | ZeroExtImm
      breg[rt] = breg[rs] | ((int32_t) k16);
      break;
    case XORI:              		// Exclusive OR Immediate     tipo:I  realiza:  rt ← rs XOR immediate
      breg[rt] = breg[rs] ^ ((int32_t) k16);
      break;
    case J:                 		// Jump           tipo:J  realiza: J target
      pc = (pc  & 0xF0000000) + (k26<<2);
      break;
    case JAL:               		// Jump and Link        tipo:J  realiza: JAL target
      breg[31] = pc;
      pc = (pc  & 0xF0000000) + (k26<<2);
      break;
    default:
      printf("opcode nao implementada: 0x%x\n", opcode);
      exit(0);
      break;
    }
}

//executa uma instrução do MIPS: step() => fecth(), decode(), execute()
void step(){
  if(ENCERRAMENTO!=1){
    printf("\npasso:%d\n",passo);
    fetch();
    decode();
    execute();
    passo++;
  }
}

//executa o programa até encontrar uma chamada de sistema para encerramento, ou até o pc ultrapassar o limite do segmento de código (4k words). 
void run(){
  while(ENCERRAMENTO!=1 && pc < (MEM_SIZE/2)){
    fetch();
    decode();
    execute();
  }
  if(ENCERRAMENTO==1)     printf("\nfim\n");
  if(pc >= (MEM_SIZE/2))  printf("\nfim com erros\n");
}

//Imprime o conteúdo da memória a partir do endereço start até o endereço end. O formato pode ser em hexa (‘h’) ou decimal (‘d’).
void dump_mem(int start, int end, char format){
  int i;
  printf("\n");
  for(i=start; i<=end; i++){
    if(format == 'h')	printf("mem[%d] = %.08x\n",i,mem[i]);
    if(format == 'd')	printf("mem[%d] = %d\n",i,mem[i]);
  }
}
//Imprime o conteúdo dos registradores do MIPS, incluindo o banco de registradores e os registradores pc, hi e lo. O formato pode ser em 
//hexa (‘h’) ou decimal (‘d’).
void dump_reg(char format){
  int i;
  printf("\n");
  for(i=0; i<=31; i++){
    if(format == 'h')	printf("breg[%d] = %.08x\n",i,breg[i]);
    if(format == 'd')	printf("breg[%d] = %d\n",i,breg[i]);
  }
  //pc, hi e lo
  if(format == 'h'){
    printf("pc       = %.08x\n",pc);
    printf("hi       = %.08x\n",hi);
    printf("lo       = %.08x\n",lo);
  }else if(format == 'd'){
    printf("pc       = %d\n",pc);
    printf("hi       = %d\n",hi);
    printf("lo       = %d\n",lo);
  }
  getchar();
  printf("\n");
}