#include "funcoes.hpp"

extern int32_t mem[256];           															//array que representa memoria
extern int32_t s0, s1, t0, t1;       															//variaveis que representam regs

extern int32_t mascara_byte;
extern int32_t mascara_half ;
extern int opcao;

int main() {
    uint32_t address;	//inteiro
    uint16_t kte;	//inteiro
    int8_t dado8;	//hexadecimal		ERRO! O próprio compilador trata isto como um char. Ler como int e casting para int8_t
    //int dado8;
    int16_t dado16;	//hexadecimal
    int32_t dado32;	//hexadecimal


    cout << "1. lb\n2. lh\n3. lw\n4. sb\n5. sh\n6. sw\n7. sair" << endl;
    cout << "selecione opcao:";
    cin >> opcao;
    getchar();

    while(opcao != 7){
        switch(opcao){
            case 1:
               cout << "insira o endereco:";
               cin >> address;
               getchar();
               cout << "insira o offset em bytes:";
               cin >> kte;
               getchar();
               //carrega byte
               system(CLEAR);
	       lb(address, kte);
               break;
            case 2:
               cout << "insira o endereco:";
               cin >> address;
               getchar();
               cout << "insira o offset em bytes:";
               cin >> kte;
               getchar();
               //carrega half
               system(CLEAR);
               lh(address, kte);
               break;
            case 3:
               cout << "insira o endereco:";
               cin >> address;
               getchar();
               cout << "insira o offset em bytes:";
               cin >> kte;
               getchar();
               //carrega word
               system(CLEAR);
               lw(address, kte);
               break;
            case 4:
               cout << "insira o endereco:";
               cin >> address;
               getchar();										
               cout << "insira o offset em bytes:";
               cin >> kte;
               getchar();
               cout << "insira dado a ser armazenado:";
               cin >> hex >> dado8;
               getchar();
               //armazena byte
               system(CLEAR);
               sb(address, kte, dado8);
               break;
            case 5:
               cout << "insira o endereco:";
               cin >> address;
               getchar();
               cout << "insira o offset em bytes:";
               cin >> kte;
               getchar();
               cout << "insira dado a ser armazenado:";
               cin >> hex >> dado16;
               getchar();
               //armazena half
               system(CLEAR);
               sh(address, kte, dado16);
               break;
            case 6:
               cout << "insira o endereco:";
               cin >> address;
               getchar();
               cout << "insira o offset em bytes:";
               cin >> kte;
               getchar();
               cout << "insira dado a ser armazenado:";
               cin >> hex >> dado32;
               getchar();
               //armazena word
               system(CLEAR);
               sw(address, kte, dado32);
        }
        getchar();;
        system(CLEAR);
        cout << "1. lb\n2. lh\n3. lw\n4. sb\n5. sh\n6. sw\n7. sair" << endl;
        cout << "selecione opcao:";
        cin >> opcao;
        getchar();
    }

    return 1;
}
