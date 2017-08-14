#include "funcoes.hpp"

int32_t mem[256];           															//array que representa memoria
int32_t s0, s1, t0, t1;       															//variaveis que representam regs

int32_t mascara_byte = 0x000000FF;
int32_t mascara_half = 0x0000FFFF;
int opcao;


int lb(uint32_t address, uint16_t kte) {

    int endereco = address + kte;
    if(endereco > 1023){
       cout << "acesso negado." << endl;
        return -1;
    }


    int celula = endereco/4;    	 													//pega a posicao na memoria
    int offset = endereco%4;     														//pega o offset dentro de uma celula
   
    t0 = mem[celula];                              												//t0 recebe a posicao escolhida
    cout << "t0 (celula de memoria) = " <<  t0 << endl;
    t1 = t0 >> offset*8;                         													//t1 recebe o byte com o offset sem mascara
    cout << "t1 (offset sem mascara) = " << t1 << endl;
    s0 = mascara_byte & t1;                        												//s0 recebe o byte com o offset com mascara
    cout << "s0 (offset com mascara) = " << s0 << endl;
    return (int) s0;
}

int16_t lh(uint32_t address, uint16_t kte) {

    int endereco = address + kte;
    if(endereco%2 != 0){
       cout << "impossivel ler meia palavra --> endereco nao eh multiplo de 2." << endl;
        return -1;
    }

    if(endereco > 1022){
       cout << "acesso negado." << endl;
        return -1;
    }

    int celula = endereco/4;     														//pega a posicao na memoria
    int offset = endereco%4;   														//pega o offset dentro de uma celula

    t0 = mem[celula];                              												//t0 recebe a posicao escolhida
    cout << "t0 (celula de memoria ) = " << t0 << endl;
    t1 = t0 >> offset*8;                         													//t1 recebe a meia palavra com o offset sem mascara
    cout << "t1 (offset sem mascara) = " << t1 << endl;
    s0 = mascara_half & t1;                       									 			//s0 recebe a meia palavra com o offset com mascara
    cout << "s0 (offset com mascara) = " << s0 << endl;
    return (int16_t) s0;
}

int32_t lw(uint32_t address, uint16_t kte) {

    int endereco = address + kte;
    if(endereco%4 != 0){
        cout << "impossivel ler palavra --> endereco nao eh multiplo de 4." << endl;
        return -1;
    }

    if(endereco > 1020){
       cout << "acesso negado." << endl;
        return -1;
    }

    int celula = endereco/4;

    t0 = mem[celula];                             												 //t0 recebe a posicao escolhida
    cout << "t0 (celula de memoria ) = " << t0 << endl;
    t1 = t0;                                       													//t1 recebe a word
    cout << "t1 (celula de memoria) = "  << t1 << endl;
    s0 = t1;                                      									 					//s0 recebe a word
    cout << "s0 (celula de memoria) = " << s0 << endl;
    return s0;
}

void sb(uint32_t address, uint16_t kte, int dado) {

    int endereco = address + kte;
    if(endereco > 1023){
       cout << "acesso negado." << endl;
        return ;
    }

    int celula = endereco/4;     														//acessa a posicao na memoria
    int offset = endereco%4;     														//acessa o offset dentro de uma celula

    t0 = mem[celula];                  														//t0 recebe o conteúdo da posicao escolhida
    cout << "t0 (valor contido na celula de memoria) = " << t0 << endl;
    t1 = dado;                         															//t1 recebe o byte a ser escrito com offset
    t1 = t1 << offset*8;
    cout << "t1 (byte a ser escrito com offset) = " << t1 << endl;
    s0 = ((~(mascara_byte << (offset*8)) & t0) | t1);         									//s0 recebe o novo valor da celula
    cout << "s0 (novo valor da celula de memoria) = " << s0 << endl;
    mem[celula] = s0;
}

void sh(uint32_t address, uint16_t kte, int16_t dado) {

    int endereco = address + kte;
    if(endereco%2 != 0){
        cout << "impossivel escrever meia palavra --> endereco nao eh multiplo de 2." << endl;
        return ;
    }

    if(endereco > 1022){
       cout << "acesso negado." << endl;
        return ;
    }

    int celula = endereco/4;															//acessa a posicao na memoria
    int offset = endereco%4;															//acessa o offset dentro de uma celula

    t0 = mem[celula];                  														//t0 recebe o conteúdo da posicao escolhida
    cout << "t0 (valor contido na celula de memoria) = " << t0 << endl;
    t1 = dado;                         															//t1 recebe o byte a ser escrito com offset
    t1 = t1 << offset*8;
    cout << "t1 (meia palavra a ser escrita com offset) = " << t1 << endl;
    s0 = ((~(mascara_half << (offset*8)) & t0) | t1);         									//s0 recebe o novo valor da celula
    cout << "s0 (novo valor da celula de memoria) = " << s0 << endl;
    mem[celula] = s0;
}

void sw(uint32_t address, uint16_t kte, int32_t dado) {

    int endereco = address + kte;
    if(endereco%4 != 0){
        cout << "impossivel escrever palavra --> endereco nao eh multiplo de 4." << endl;
        return ;
    }

    if(endereco > 1020){
       cout << "acesso negado." << endl;
        return ;
    }

    int celula = endereco/4;
    mem[celula] = dado;                          												//t0 recebe a posicao escolhida
    s0 = t1 = t0 = dado;                                       											//t1 recebe a word
    cout << "t0 = (novo valor da celula de memoria) = " << t0 << endl;
    cout << "t1 = (novo valor da celula de memoria) = " << t1 << endl;
    cout << "s0 = (novo valor da celula de memoria) = " << s0 << endl;
}

