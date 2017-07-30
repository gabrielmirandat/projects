#include "funcoes.hpp"

extern int32_t mem[256];           															//array que representa memoria
extern int32_t s0, s1, t0, t1;       															//variaveis que representam regs

extern int32_t mascara_byte;
extern int32_t mascara_half ;
extern int opcao;

int main() {
    uint32_t address;
    uint16_t kte;
    //int8_t dado8;							//ERRO! O próprio compilador trata isto como um char. Ler como int e casting para int8_t
    int dado8;
    int16_t dado16;
    int32_t dado32;

    address = 40;  kte = 0; dado32 = 2130771712;	//01111111000000001111111100000000
    cout << "sw(40, 0, 2130771712);	//01111111000000001111111100000000" << endl;
    sw(address, kte, dado32);
    getchar();
    
    kte = 3;
    cout << "lb(40, 3);" << endl;
    lb(address, kte);
    getchar();
	
    kte = 2;
    cout << "lh(40, 2);" << endl;
    lh(address, kte);
    getchar();

    kte = 0;
    cout << "lw(40, 0);" << endl;
    lw(address, kte);
    getchar();

    address = 40;  kte = 2; dado8 = 127;			//01111111
    cout << "sb(40, 2, 127);	//01111111" << endl;
    sb(address, kte, dado8);
    getchar();
    
    address = 40;  kte = 3; dado16 = 32767;		//0111111111111111
    cout << "sh(40, 3, 32767);	//0111111111111111" << endl;
    sh(address, kte, dado16);
    getchar();
   
    address = 40;  kte = 2; dado16 = 32767;		//0111111111111111
    cout << "sb(40, 2, 32767);	//0111111111111111" << endl;
    sh(address, kte, dado16);
    getchar();

    return 1;
}
