
/************************************************************************/
// Universidade de Brasilia
//
// Codificacao e decodificacao base 85
//
// Ultima modificacao - 14/09/2016
//
// Bárbara Varanda Rangel
// Gabriel Martins de Miranda
// Jadiel Teófilo Amorim de Oliveira
// Marcos Cordeiro Fleury
// Túlio de Carvalho Matia
//
/************************************************************************/



#include "base85.h"


//Variavel com o tamanho do arquivo
int tam = 0;


int main(int argc, char **argv){
	float tempoInicio = 0, tempoFim = 0, tempoGasto;
	uint8_t *arquivo_entrada = NULL;
	char *operacao 			= NULL;
	uint8_t *texto;

	tempoInicio = (float)clock()/CLOCKS_PER_SEC;//Pega o momento inicial


	//Argumentos - se foram passado como parametro na execucao, utiliza-se dos mesmos
	if(argc == 3 ){
		arquivo_entrada 	= argv[1];
		operacao 			= argv[2];
	}
	else{//Se algum dos dois nao foi especificado (arquivo ou operacao)
		operacao  			= (char*) malloc(sizeof(char));
		arquivo_entrada  	= (char*) malloc(10*sizeof(char));
		//tamanho maximo do nome do arquivo em 10 caracteres

		printf("Digite a operacao desejada:\n~>");
		scanf("%c", operacao);
		getchar();

		printf("Digite o arquivo de entrada desejado:\n~>");
		scanf("%s", arquivo_entrada);
		getchar();
	}


	//chama a funcao que le o texto do arquivo selecionado
	texto = lerArq(arquivo_entrada);

	// Verifica se deseja-se codificar ou decodificar
	if(*operacao  == 'c')
		codificar(texto);
	else
		if(*operacao  == 'd')
			decodificar(texto);
		else{
			printf("Comando de execucao incorreto, consulte o readmeBase85 para instrucoes\n");
			exit(0);
		}
		



	free(texto);

	tempoFim = (float)clock()/CLOCKS_PER_SEC; //Pega o tempo em que acabou 

	tempoGasto = tempoFim - tempoInicio; // Pega o tempo da duracao do programa

	printf("O tempo gasto foi %fs\n", tempoGasto); // Imprime o tempo gasto
	return 0;

}



/**
 * Funcao que le o texto do arquivo, devolve um ponteiro para a string
 * @param 	arquivo_entrada nome do arquivo de entrada
 */
uint8_t *lerArq(uint8_t *arquivo_entrada){
	

	
	uint8_t *texto;
	FILE * fp = NULL;

	fp = fopen(arquivo_entrada, "rb");
	if (fp == NULL) {
		printf("Arquivo nao encontrado.\n");
		exit(1); //   execao
	}

	//Pega o tamanho do arquivo para a alocacao
	fseek(fp, 0, SEEK_END);
	tam = ftell(fp);
	fseek(fp,0,SEEK_SET);

	// aloca a memoria
	texto = (uint8_t *)malloc(tam+1);



	// Realiza a leitura
	fread(texto, tam, 1 , fp);


	fclose(fp);
	return texto;
}



/**
 * Funcao que le o texto do arquivo, devolve um ponteiro para a string
 * @param 	texto ponteiro vetor  inteiro 8 bits a ser codificada
 * @param 	arquivo de saida com o a codificacao
 */
void codificar(uint8_t *texto){
//Pegar esse valor em decimal, usar o codigo que fiz para encontrar 5 numeros em radix 85
//Cada um deles somado a 33 vira um codigo ascii
	int texto_incompleto = 1;
	uint8_t palavra8bit[4];
	int32_t palavra32bit;
	uint32_t base10; // para a conversao base 85
	uint32_t base85[5]; // para a conversao base 85
	int i = 0; // para o tratamento da sting
	int contaNull = 0; // para saber quantos caracteres nulos estao em uma palavra 
	FILE *fp = NULL;

	//Abre arquivo para colocar a saida
	fp = fopen("codificado.b85", "w");

	while(texto_incompleto){
	//Pegar o texto, dividir em segmentos de 32 bytes, 
		
		//Percorre 4 caracteres do texto passando para um vetor de inteiro 8 bits
		do{
			if(i < tam){
				palavra8bit[i%4] = texto[i];
			}else{
				if(i%4 == 0) exit(1);// Caso o primeiro byte seja o final sai do programa
				contaNull = 4 - i%4; // verifica-se quanto vai ser preenxido com 0
				for(; i%4!=0; i++){ // caso se tenha encontrado o final preenxe o resto com 0
					palavra8bit[i%4] = 0;
				}
				texto_incompleto = 0;
				break;
			}
			i++;
		}while(i%4!=0);

		// a partir do vetor de 4 inteiros de 8 bits gera um inteiro de 32 bits
		palavra32bit = palavra8bit[0];
		palavra32bit = (palavra32bit << 8) | palavra8bit[1];
		palavra32bit = (palavra32bit << 8) | palavra8bit[2];
		palavra32bit = (palavra32bit << 8) | palavra8bit[3];

		//Realiza a conversao para a base 85 a partir de divisoes sucessivas 
		//Realiza tambem a soma com 33 para a aplicacao em ascii
		base10 = palavra32bit;
		for(int j = 4; j >= 0; j--){		
			base85[j] = base10%85 + 33;
			base10 = base10/85;

		}


		// Escreve no arquivo
		for(int j = 0; j < 5 - contaNull; j++){	//Coloca no arquivo descartando os nulos
			fprintf(fp, "%c", (char)base85[j]);
		}
		contaNull = 0;
		
	}
	fclose(fp);

}


/**
 * Funcao que le o texto do arquivo, devolve um ponteiro para a string
 * @param 	texto ponteiro vetor  inteiro 8 bits a ser decodificada
 * @param 	arquivo de saida com o a decodificacao
 */
void decodificar(uint8_t *texto){
// divide a mensagem em pedacos de 5 caracteres, as remanecentes devem ser preexidas com u
	int texto_incompleto = 1;
	uint8_t palavra8bit[5];
	uint32_t palavra32bit;
	uint32_t base10 = 0; // para a conversao base 85
	int i = 0; // para o tratamento da sting
	int contaUs = 0; // para saber quantos caracteres u estao em uma palavra 
	uint8_t result[4];
	FILE *fp = NULL;


	//Abre arquivo para colocar a saida
	fp = fopen("decodificado", "wb");

	while(texto_incompleto){
	//Pegar o texto, dividir em segmentos de 32 bytes, 
		
		//Percorre 5 caracteres do texto passando para um vetor de inteiro 8 bits
		do{
			if(i < tam){
				palavra8bit[i%5] = texto[i];
			}else{
				if(i%5 == 0) exit(1);// Caso o primeiro byte seja o fim sai do programa
				contaUs = 5 - i%5; // verifica-se quanto vai ser preenxido com u
				for(; i%5!=0; i++){ // caso se tenha encontrado o fim preenxe o resto com u
					palavra8bit[i%5] = 'u';
				}
				texto_incompleto = 0;
				break;
			}
			i++;
		}while(i%5!=0);
		


		//Realiza a conversao para a base 85 a partir de divisoes sucessivas 
		//Realiza tambem a subtracao de 33 
		for(int j = 4; j >=0; j--){		
			base10 = (uint32_t)(base10 + (palavra8bit[j]-33) * pow(85, 4 - j));
		}

		result[0] = base10 >> 24;
		result[1] = base10 >> 16;
		result[2] = base10 >> 8;
		result[3] = base10 >> 0;

		base10 = 0;


		// Escreve no arquivo
		for(int j = 0; j < 4 - contaUs; j++){	//Coloca no arquivo descartando os nulos
			fprintf(fp, "%c", result[j]);
		}
		contaUs = 0;
	}
	fclose(fp);

}