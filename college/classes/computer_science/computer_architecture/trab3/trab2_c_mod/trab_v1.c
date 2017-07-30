#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

#ifdef _WIN32
    #define CLEAR "cls" /* soh funciona no windows */
#else
    #define CLEAR "clear" /* soh funciona no linux ou mac (unix) */
#endif

int32_t mem[256];           //array que representa memoria
int32_t s0, s1, t0, t1;     //variaveis que representam regs

int32_t mascara_byte = 0x000000FF;
int32_t mascara_half = 0x0000FFFF;
int opcao;

int8_t lb(uint32_t, uint16_t);
int16_t lh(uint32_t, uint16_t);
int32_t lw(uint32_t, uint16_t);
void sb(uint32_t, uint16_t, int8_t);
void sh(uint32_t, uint16_t, int16_t);
void sw(uint32_t, uint16_t, int32_t);

int8_t lb(uint32_t address, uint16_t kte) {
    system(CLEAR);

    int endereco = address + kte;
    int celula = endereco/4;     //pega a posicao na memoria
    int offset = endereco%4;     //pega o offset dentro de uma celula

    t0 = mem[celula];                              //t0 recebe a posicao escolhida
    printf("t0 = %x\n",t0);
    t1 = t0 >> (offset*8);                         //t1 recebe o byte com o offset sem mascara
    printf("t1 (offset sem mascara) = %x\n",t1);
    s0 = mascara_byte & t1;                        //s0 recebe o byte com o offset com mascara
    printf("s0 (offset com mascara) = %x",s0);
    return (int8_t) s0;
}

int16_t lh(uint32_t address, uint16_t kte) {
    system(CLEAR);

    int endereco = address + kte;   printf("endereco: %d\n",endereco);
    if(endereco%2 != 0){
        printf("impossivel ler meia palavra --> endereco nao eh multiplo de 2.");
        return ;
    }

    int celula = endereco/4;     //pega a posicao na memoria
    int offset = endereco%4;     //pega o offset dentro de uma celula

    t0 = mem[celula];                              //t0 recebe a posicao escolhida
    printf("t0 (celula de memoria ) = %x\n",t0);
    t1 = t0 >> (offset*8);                         //t1 recebe a meia palavra com o offset sem mascara
    printf("t1 (offset sem mascara) = %x\n",t1);
    s0 = mascara_half & t1;                        //s0 recebe a meia palavra com o offset com mascara
    printf("s0 (offset com mascara) = %x",s0);
    return (int16_t) s0;
}

int32_t lw(uint32_t address, uint16_t kte) {
    system(CLEAR);

    int endereco = address + kte;
    if(endereco%4 != 0){
        printf("impossivel ler palavra --> endereco nao eh multiplo de 4.");
        return ;
    }

    int celula = endereco/4;

    t0 = mem[celula];                              //t0 recebe a posicao escolhida
    printf("t0 (celula de memoria ) = %x\n",t0);
    t1 = t0;                                       //t1 recebe a word
    printf("t1 (offset sem mascara) = %x\n",t1);
    s0 = t1;                                       //s0 recebe a word
    printf("s0 (offset com mascara) = %x",s0);
    return s0;
}

void sb(uint32_t address, uint16_t kte, int8_t dado) {
    system(CLEAR);

    int endereco = address + kte;
    int celula = endereco/4;     //acessa a posicao na memoria
    int offset = endereco%4;     //acessa o offset dentro de uma celula

    t0 = mem[celula];                  //t0 recebe o conteúdo da posicao escolhida
    printf("t0 (valor contido na celula de memoria)= %.08x\n",t0);
    t1 = (int32_t) dado;                         //t1 recebe o byte a ser escrito com offset
    t1 = t1 << (offset*8);
    printf("t1 (byte a ser escrito com offset) = %.08x\n",t1);
    s0 = ((~(mascara_byte << (offset*8)) & t0) | t1);         //s0 recebe o novo valor da celula
    printf("s0 (novo valor da celula de memoria) = %.08x",s0);
    mem[celula] = s0;
}

void sh(uint32_t address, uint16_t kte, int16_t dado) {
    system(CLEAR);

    printf("\nendereco apos chamada da funcao: %" PRIu32 "\n",address);
    printf("\nkte apos chamada da funcao: %u\n",kte);

    int endereco = address + kte;
    if(endereco%2 != 0){
        printf("impossivel escrever meia palavra --> endereco nao eh multiplo de 2.");
        return ;
    }

    int celula = endereco/4;     printf("celula: %d\n",celula);//acessa a posicao na memoria
    int offset = endereco%4;     printf("offset: %d\n",offset);//acessa o offset dentro de uma celula

    t0 = mem[celula];                  //t0 recebe o conteúdo da posicao escolhida
    printf("t0 (valor contido na celula de memoria) = %.08x\n",t0);
    t1 = (int32_t) dado;                         //t1 recebe o byte a ser escrito com offset
    t1 = t1 << (offset*8);
    printf("t1 (byte a ser escrito com offset) = %.08x\n",t1);
    s0 = ((~(mascara_half << (offset*8)) & t0) | t1);         //s0 recebe o novo valor da celula
    printf("s0 (novo valor da celula de memoria) = %.08x",s0);
    mem[celula] = s0;
}

void sw(uint32_t address, uint16_t kte, int32_t dado) {
    system(CLEAR);

    int endereco = address + kte;
    if(endereco%4 != 0){
        printf("impossivel escrever palavra --> endereco nao eh multiplo de 4.");
        return ;
    }

    int celula = endereco/4;
    mem[celula] = dado;                          //t0 recebe a posicao escolhida
    s0 = t1 = t0 = dado;                         //t1 recebe a word
    printf("t0 = %.08x\n",t0);
    printf("t1 = %.08x\n",t1);
    printf("s0 = %.08x",s0);
}

int main() {
    uint32_t address;
    uint16_t kte;
    int8_t dado8;
    int16_t dado16;
    int32_t dado32;


    printf("1. lb\n2. lh\n3. lw\n4. sb\n5. sh\n6. sw\n7. sair");
    printf("\nselecione opcao:");
    scanf("%d",&opcao);
    getchar();

    while(opcao != 7){
        switch(opcao){
            case 1:
                printf("insira o endereco:");
                scanf("%u",&address);
                getchar();
                printf("insira o offset em bytes:");
                scanf("%u",&kte);
                getchar();
                //carrega byte
		 (int32_t)lb(address, kte);
                break;
            case 2:
                printf("insira o endereco:");
                //scanf("%d",&address);
                address = 40;
                //getchar();
                printf("insira o offset em bytes:");
                //scanf("%d",&kte);
                kte = 2;
                //getchar();
                //carrega half
                lh(address, kte);
                break;
            case 3:
                printf("insira o endereco:");
                scanf("%u",&address);
                getchar();
                printf("insira o offset em bytes:");
                scanf("%u",&kte);
                getchar();
                //carrega word
                lw(address, kte);
                break;
            case 4:
                printf("insira o endereco:");
                scanf("%u",&address);
                getchar();
                printf("insira o offset em bytes:");
                scanf("%u",&kte);
                getchar();
                printf("insira dado a ser armazenado:");
                scanf("%x" ,&dado32);
                getchar();
                //armazena byte
                sb(address, kte, (int8_t) dado8);
                break;
            case 5:
                printf("insira o endereco:");
                scanf("%u",&address);
                getchar();

                printf("\naddress apos scanf: %d\n",address);

                printf("insira o offset em bytes:");
                scanf("%u",&kte);
                getchar();

                printf("\nkte apos scanf: %d\n",kte);

                printf("insira dado a ser armazenado:");
                scanf("%x",&dado16);
                getchar();
                //armazena half
                sh(address, kte, dado16);
                break;
            case 6:
                printf("insira o endereco:");
                scanf("%u",&address);
                getchar();
                printf("insira o offset em bytes:");
                scanf("%u",&kte);
                getchar();
                printf("insira dado a ser armazenado:");
                scanf("%x",&dado32);
                getchar();
                //armazena word
                sw(address, kte, dado32);
        }
        getchar();
        system(CLEAR);
        printf("1. lb\n2. lh\n3. lw\n4. sb\n5. sh\n6. sw\n7. sair");
        printf("\nselecione opcao:");
        scanf("%d",&opcao);
        getchar();
    }

    return 1;
}
