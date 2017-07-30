/*
Universidade de Brasília 01/2015
Organização e Arquitetura de Computadores
Aluna: Marina Martins de Miranda
Matrícula: 11/0132351
CodeBlocks gcc 4.7.1 Windows/unicode - 32 bit
*/

#include<stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MEM_SIZE 4096
#define BREG_SIZE 32

int32_t mem[MEM_SIZE];//array que representa memoria
int32_t breg[BREG_SIZE];
//breg[0] = 0;
uint32_t pc, ri;
int32_t opcode, rs, rt, rd, shamnt,funct, k26, hi,lo,aux32;
int FLAG = 0;
//int conint = 0;

int16_t k16;
int64_t aux64;
int passo = 1;

int32_t lb(uint32_t *address, uint16_t kte);
int32_t lh(uint32_t *address, uint16_t kte);
int32_t lw(uint32_t *address, uint16_t kte);
void sb(uint32_t *address, uint16_t kte, int8_t dado);
void sh(uint32_t *address, uint16_t kte, int16_t dado);
void sw(uint32_t *address, uint16_t kte, int32_t dado);
void fetch(void);
void decode (void);
void execute (void);
void step(void);
void run(void);
void dump_mem(int start, int end, char format);
void dump_reg(char format);

enum OPCODES { // lembrem que so sao considerados os 6 primeiros bits dessas constantes
EXT=0x00, LW=0x23, LB=0x20, LBU=0x24,
LH=0x21, LHU=0x25, LUI=0x0F, SW=0x2B,
SB=0x28, SH=0x29, BEQ=0x04, BNE=0x05,
BLEZ=0x06, BGTZ=0x07, ADDI=0x08, ADDIU=0X09, SLTI=0x0A,
SLTIU=0x0B, ANDI=0x0C, ORI=0x0D, XORI=0x0E,
J=0x02, JAL=0x03
};
enum FUNCT {
ADD=0x20, SUB=0x22, MULT=0x18, DIV=0x1A, MFHI=0x10, MFLO=0x12, AND=0x24,
OR=0x25, XOR=0x26, NOR=0x27, SLT=0x2A, JR=0x08,
SLL=0x00, SRL=0x02, SRA=0x03, SYSCALL=0x0c
};

int main(void)
{
  FILE *arq;
  FILE *arqdata;
  int32_t aux;
  char string[100];
  int32_t result;
  int32_t cont, contdata;
  cont = 0;
  contdata = MEM_SIZE/2;
  int i,j;
  int inicio, fim;
  char format;
  // Abre um arquivo BINÁRIO para LEITURA
  arq = fopen("code.bin", "rb");
  arqdata = fopen("data.bin", "rb");
  if (arq == NULL || arqdata == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura dos arquivos\n");
     return 0;
  }
  else{
    //fscanf(arq, "%[^\n]s", string);
    //sscanf(string, "%"SCNd32, &Vet[0]);

  while(!feof(arq)){
    result = fread (&aux, sizeof(int32_t), 1, arq);
    mem[cont] = aux;
    cont++;
    }
  while(!feof(arqdata)){
    result = fread (&aux, sizeof(int32_t), 1, arqdata);
    mem[contdata] = aux;
    contdata++;
    }
    pc = 0;
    breg[0]=0;
    breg[28] = 0x00001800;
    breg[29] = 0x00003ffc;
  while(FLAG!=1){
    printf("Escolha a forma desejada de executar o programa: \n");
    printf("1 - step() (para executar apenas uma instrucao) \n");
    printf("2 - run() ( ate encontrar uma chamada de sistema para encerramento) \n");
    printf("3 - sair \n");
    scanf("%d", &i);
    switch(i){
        case 1:
        //printf("Executando apenas uma instrucao. \n");
        step();
        printf("Instrucao executada. \n");
        printf("Deseja verificar o conteudo da memoria e dos registradores? \n");
        printf(" 1 - SIM   2-NAO \n");
        scanf("%d", &j);
            if(j == 1){
                printf("Digite o tipo de formato para visualizacao : \n");
                printf(" h - hexa   d - decimal \n");
                getchar();
                scanf("%c", &format);
                getchar();
                printf("Digite a posicao inicial para dump_mem (EM DECIMAL), de 0 a %d : \n", MEM_SIZE);
                scanf("%d", &inicio);
                printf("Digite a posicao final para dump_mem (EM DECIMAL), de 0 a %d : \n", MEM_SIZE);
                scanf("%d", &fim);
                dump_mem(inicio, fim, format);
                dump_reg(format);
            }
        break;
        case 2:
        run();
        printf("Digite o formato para visualizacao do conteudo da memoria e registradores : \n");
        printf(" h - hexa   d - decimal \n");
        getchar();
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

  fclose(arq);
  fclose(arqdata);
  return 0;
  }
}

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
    q = (t0/4);

    // para achar qual byte da palavra é solicitado
    //r = t0%4; // AQUI CONSIDEREI QUE O VALOR SEMPRE SERA MULTIPLO DE 4

    mem[q] = dado;
}
//fetch: lê uma instrução da memória e a coloca em ri, atualizando o pc para apontar para a próxima instrução (soma 4).
void fetch(void){
    ri = lw(&pc,0);
    pc = pc+4;
}

// função decode faz máscaras para extrair  os campos da instrução e as desloca para obter cada campo separadamente
void decode(void){
    opcode = (ri & 0xFC000000)>>26; //código da operação
    rs = (ri & 0x03E00000)>>21; //índice do primeiro registrador fonte
    rt = (ri & 0x001F0000)>>16; //índice do segundo registrador fonte
    rd = (ri & 0x0000F800)>>11; //índice do registrador destino, que recebe o resultado da operação
    shamnt = (ri & 0x000007C0)>>6; //quantidade de deslocamento em instruções shift e rotate
    funct = (ri & 0x0000003F); //código auxiliar para determinar a instrução a ser executada
    k16 = (uint16_t)(ri & 0x0000FFFF); //constante de 16 bits, valor imediato em instruções tipo I
    k26 = (ri & 0x03FFFFFF); //constante de 26 bits, para instruções tipo J
    }

void execute (void) {
    switch(opcode){
    case EXT:
    //if((shamnt >= 0 && shamnt<32) && (rd>0 && rd<=32) && ((shamnt + rd)<32)){
      //  int32_t aux = 0xFFFFFFFF;
      //  breg[rt] = breg[rs]>>shamnt;
      //  aux = aux >> (32 - rd -1);
      //  breg[rt] = breg[rt] & aux;
    //
     switch (funct){
        case ADD:
        breg[rd] = breg[rs] + breg[rt];
        break;
        case SUB:
        breg[rd] = breg[rs] - breg[rt];
        break;
        case MULT:
        aux64 = breg[rs] * breg[rt];
        hi = (int32_t) ((aux64 & 0xFFFFFFFFF00000000) >> 32);
        lo = (int32_t) (aux64 & 0x00000000FFFFFFFFF);
        break;
        case DIV:
        lo=breg[rs]/breg[rt];
        hi=breg[rs]%breg[rt];
        break;
        case MFHI:
        breg[rd] = hi;
        break;
        case MFLO:
        breg[rd] = lo;
        break;
        case AND:
        breg[rd] = breg[rs] & breg[rt];
        break;
        case OR:
        breg[rd] = breg[rs] | breg[rt];
        break;
        case XOR:
        breg[rd] = breg[rs] ^ breg[rt];
        break;
        case NOR:
        breg[rd] = ~(breg[rs] | breg[rt]);
        break;
        case SLT:
        if (breg[rs] < breg[rt])
            breg[rd] = 0x00000001;
        else
            breg[rd] = 0x00000000;
        break;
        case JR:
        pc = breg[rs];
        break;
        case SLL:
        breg[rd] = breg[rt] << shamnt;
        break;
        case SRL:
        breg[rd] = breg[rt] >> shamnt;
        break;
        case SRA:
        aux32 = (breg[rt] & 0x800000000)>>31;
        if(aux32==0x00000001){
            aux32 = (0xFFFFFFFF) << (32 - shamnt);
            breg[rd] = (breg[rt] >> shamnt) | aux32;
        }
        else
            if (aux32==0x00000000)
            breg[rd] = breg[rt] >> shamnt;
        break;
        case SYSCALL:

        if(breg[2]==1){
            printf("CHAMADA DE IMPRESSAO DE INTEIRO\n");
            printf("0x%.8x \n", breg[4]);
            //conint++;
            }
        if(breg[2]==4) {
        printf("CHAMADA DE IMPRESSAO DE ASCIIZ\n");
        //printf("chegou ate v0==4, breg[4] = %8x \n", breg[4]);
        int32_t *a;
        a = &mem[(breg[4]/4)];
        char *msg = (char *) a;
        printf("%s \n", msg);
        //printf("fantasma \n");
            //char *msg;
            //msg = (char*) (mem[a]);
            //printf("%s \n", msg);
            }
        if(breg[2]==10){
            FLAG = 1;
            printf("CHAMADA DE ENCERRAMENTO\n");
            //exit(0);
            }
        break;
        default:
        printf("FUNCT nao implementada: 0x%x", funct);
        exit(0);
        break;
        }
    break;
    case LW:
    breg[rt] = lw(&breg[rs], k16);
    break;
    case LB:
    breg[rt] = lb(&breg[rs], k16);
    break;
    case LBU:
    breg[rt] = (uint32_t) (lb(&breg[rs], k16));
    break;
    case LH:
    breg[rt] = lh(&breg[rs], k16);
    break;
    case LHU:
    breg[rt] = (uint32_t) (lh(&breg[rs], k16));
    break;
    case LUI:
    breg[rt] = ((int32_t) (k16))<< 16;
    break;
    case SW:
    sw(&breg[rs],k16,breg[rt]);
    //void sw(uint32_t *address, uint16_t kte, int32_t dado)
    break;
    case SB:
    sb(&breg[rs],k16,breg[rt]);
    break;
    case SH:
    sh(&breg[rs],k16,breg[rt]);
    break;
    case BEQ:
    if(breg[rs]==breg[rt])
    pc = pc + 4*((int32_t)(k16));
    break;
    case BNE:
    if(breg[rs]!=breg[rt])
    pc = pc + 4*((int32_t)(k16));
    break;
    case BLEZ:
    if(breg[rs]<=0)
    pc = pc + 4*((int32_t)(k16));
    break;
    case BGTZ:
    if(breg[rs]>0)
    pc = pc + 4*((int32_t)(k16));
    break;
    case ADDI:
    breg[rt] = breg[rs] + (int32_t)(k16);
    break;
    case ADDIU:
    breg[rt] = breg[rs] + (int32_t)(k16);
    break;
    case SLTI:
    if (breg[rs] < ((int32_t) k16))
    breg[rt] = 0x00000001;
    else
    breg[rt] = 0x00000000;
    break;
    case SLTIU:
    if (((uint32_t) breg[rs]) < ((uint32_t) k16))
    breg[rt] = 0x00000001;
    else
    breg[rt] = 0x00000000;
    break;
    case ANDI:
    breg[rt] = breg[rs] & ((int32_t) k16);
    break;
    case ORI:
    breg[rt] = breg[rs] | ((int32_t) k16);
    break;
    case XORI:
    breg[rt] = breg[rs] ^ ((int32_t) k16);
    break;
    case J:
    //pc = ((pc + 4) & 0xF0000000) + (k26<<2);
    pc = (pc  & 0xF0000000) + (k26<<2);
    break;
    case JAL:
    //breg[31] = pc + 8;
    //pc = ((pc + 4) & 0xF0000000) + (k26<<2);
    breg[31] = pc;
    pc = (pc  & 0xF0000000) + (k26<<2);
    break;
    default:
    printf("opcode nao implementada: 0x%x", opcode);
    exit(0);
    break;
    }
}

void step(void){
 if(FLAG!=1){
    fetch();
    decode();
    execute();
    }
    //printf("passo %d feito\n", passo);
   // printf("pc = %x\n", pc);
    //printf("ri = %x\n", ri);
    passo++;
   }

void run (void){
    while((FLAG!=1) && (pc < (MEM_SIZE/2))){
        step();
        //printf("passo feito \n");
    }
    if(FLAG==1)
    printf("-- program is finished running  --\n");
    if(pc>=(MEM_SIZE/2))
        printf("Registrador pc ultrapassou o segmento de codigo.");

}
void dump_mem(int start, int end, char format){
    int i;
    if(format == 'h' || format == 'H'){
    printf("Conteudo da memoria (em hexa) do endereco %d ate endereco %d \n", start, end);
        for(i=start; i<=end; i++){
            printf("mem[%d] = 0x%.8x \n", i, mem[i]);
    }
    }
    else
        if(format == 'd' || format == 'D'){
            printf("Conteudo da memoria (em decimal) do endereco %d ate endereco %d \n", start, end);
            for(i=start; i<=end; i++){
                printf("mem[%d] = %d \n", i, mem[i]);
            }
        }
        else
        printf("caracter invalido = %c", format);
}

void dump_reg(char format){
    int i;
    if(format == 'h' || format == 'H'){
        printf("Conteudo dos registradores (em hexa) \n");
        for(i=0; i<BREG_SIZE; i++){
            printf("breg[%d] = 0x%.8x \n", i, breg[i]);
        }
        printf("pc = 0x%.8x \n", pc);
        printf("ri = 0x%.8x \n", ri);
        printf("hi = 0x%.8x \n", hi);
        printf("lo = 0x%.8x \n", lo);
    }
    if(format == 'd' || format == 'D'){
         printf("Conteudo dos registradores (em decimal) \n");
        for(i=0; i<BREG_SIZE; i++){
            printf("breg[%d] = %d \n", i, breg[i]);
        }
        printf("pc = %d \n", pc);
        printf("ri = %d \n", ri);
        printf("hi = %d \n", hi);
        printf("lo = %d \n", lo);
    }
}

