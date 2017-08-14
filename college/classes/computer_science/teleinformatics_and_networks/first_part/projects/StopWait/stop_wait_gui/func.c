#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "func.h"

int Rnext,Slast,timeout;

void delay(int milliseconds){
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

int decimal_binary(int n)  /* Function to convert decimal to binary.*/
{
    int rem, i=1, binary=0;
    while (n!=0)
    {
        rem=n%2;
        n/=2;
        binary+=rem*i;
        i*=10;
    }
    return binary;
}

int random_binary(int binario){
	int decimal,i;
	
	 srand(100);
	for(i = 0; i > 10 ;i = i+1){
		decimal = rand() % 50;
		binario = decimal_binary(decimal);
	}
	return(binario);
}

//void enviar_pacote(int tamanho){}

void Fazer_Pedido(void){
	int resp,dados[500],a,i,problema,erro,bits;
	
	// 	                  Perguntas ao usuário                        //
	printf("______________________________________________________________\n");
	printf("quantos bits desejamos enviar?\n");
	scanf("%d", &bits);
	getchar();
	//                      Declarações iniciais                         //
	for(i=0; i<500;i=i+1){// Nesse for descrevemos um vetor de 500 bits que serve como fonte da camada superior //
		dados[i] = 1;
	}
	Rnext = 0;
	Slast = 0;
	printf("______________________________________________________________\n");
	for(a=0; a<(bits/8); a=a+1){// Esse for ira ser responsavel por chamar o emissor quantas vezes for necessario //
		printf("%d)\n",a+1);
		Emissor(dados);
	}
}

int receptor(int dados[500],int enviar[7]){
	int i,erro,recebido[7],numerosequencia;
	erro = 0;
	
	//  Verifica se existe erros no envio //
	printf("Verificando se existe erros no envio\n");
	delay(1000);
	srand((unsigned) time(NULL));
	if((rand() % 100 )> 70){
		erro = 1;
		printf("ERRO\n");
		return(0);
	}else{
		printf("Nao Ocorreu erro no envio\n");
	}
	if(Rnext == 0){
		Rnext = Rnext + 1;
	}else{
		Rnext = Rnext - 1;
	}
	printf("Estado atual (%d,%d)\n",Slast,Rnext);
	if(Rnext != Slast){
		if(Slast == 0){
			Slast = Slast + 1;
		}else{
			Slast = Slast - 1;
		}
		for(i=0; i<8;i=i+1){
			recebido[i] = enviar[i];
		}
		return(1);
	}
	
	
		
}

void Emissor(int dados[500]){
	
	int enviar[7],permissao,i,n,pacotes,ack,tpacote1,tpacote2;
	long m;
	// com permissao = 1 podemos enviar novos pacotes //
	permissao = 1;
	printf("Pedido foi feito pela camada superior\n");
	printf("Estado atual (%d,%d)\n",Slast,Rnext);
	delay(1000);
	if(permissao == 1){
		for(i=0; i<8;i=i+1){ // aqui pegamos os 8 bits da camada superior que desejamos enviar//
			enviar[i] = dados[i];
		}
		permissao = 0; // impedimos novos pedidos //
		
	}
	ack = 0;
	while(ack != 1){ // temos esse while que representa o modo de espera do emissor so saimos dele quando recebemos o ack //
		printf("enviando pedido para o receptor\n");
		delay(2000);
		srand((unsigned) time(NULL));
	if((rand() % 100 )> 70){
		printf("Verificando se existe erros no envio\n");
		delay(1000);
		printf("Nao Ocorreu erro no envio\n");
		if(Rnext == 0){
		Rnext = Rnext + 1;
	}else{
		Rnext = Rnext - 1;
	}
	printf("Estado atual (%d,%d)\n",Slast,Rnext);
			delay(1000);
			if(Rnext == 0){
		Rnext = Rnext + 1;
	}else{
		Rnext = Rnext - 1;
	}
		
	}else{
		ack = receptor( dados,enviar); // mandamos o pacote para o emissor e esperamos o ack //
	}
		printf("Verificando se tempo de pedido excedeu o limite\n");
		srand((unsigned) time(NULL));
		if(ack == 1){
			printf("Ack recebido\n");
			printf("Estado atual (%d,%d)\n",Slast,Rnext);
		}
		else{
			printf("Pedido excedeu o tempo limite reenviando\n");
			delay(1000);
			ack = 0;
		}
	printf("______________________________________________________________\n");
	}
	
}