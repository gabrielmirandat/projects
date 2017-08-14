
/************************************************************************/
// Universidade de Brasilia
//
// Aplicação do CRC 
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



#include "crc16.h"




/**
 * @param 	arquivo_entrada nome do arquivo de entrada
 * @param 	arquivo_crc nome do arquivo com o crc
 * @param 	operacao operacao a ser realizada
 */
int main(int argc, char **argv){
	float	tempoInicio = 0, tempoFim = 0, tempoGasto;
	char 	*arquivo_entrada 		= NULL;
	char 	*arquivo_crc 			= NULL;
	char 	*operacao 				= NULL;
	uint8_t *bin;
	uint16_t crc_aux;
	uint16_t crc;

	tempoInicio = (float)clock()/CLOCKS_PER_SEC;//Pega o momento inicial


	//Argumentos - se foram passado como parametro na execucao, utiliza-se dos mesmos
	if((argc == 3 )&&(*argv[2] == 'c')){
		arquivo_entrada 	= argv[1];
		operacao 			= argv[2];
	}
	else{
		if((argc == 4 )&&(*argv[2] = 'v')){
			arquivo_entrada 	= argv[1];
			operacao 			= argv[2];
			arquivo_crc		 	= argv[3];
		}else{//Se algum dos dois nao foi especificado (arquivo ou operacao)
			operacao  			= (char*) malloc(sizeof(char));
			arquivo_entrada  	= (char*) malloc(10*sizeof(char));
			arquivo_crc		 	= (char*) malloc(10*sizeof(char));
			//tamanho maximo do nome do arquivo em 10 caracteres

			printf("Digite a operacao desejada:\n~>");
			scanf("%c", operacao);
			getchar();

			printf("Digite o arquivo de entrada desejado:\n~>");
			scanf("%s", arquivo_entrada);
			getchar();

			if(*operacao == 'v'){//se deseja-se a verificacao deve-se passar o arq com o crc
				printf("Digite o arquivo com o crc para a verificacao:\n~>");
				scanf("%s", arquivo_crc);
				getchar();
			}
		}
	}


	//chama a funcao que le o binario do arquivo selecionado
	bin = lerArq(arquivo_entrada);
	// Calcula o valor do crc de bin
	crc = calcularCRC(bin);


	// Verifica se deseja-se calcularCRC ou verificarCRC
	if(*operacao  == 'c')
			printf("\nO crc eh - \t Em decimal %d \t Em hexadecimal %04x \n", crc, crc);
	else
		if(*operacao  == 'v'){
			//Abre o arquivo do crc e se pega o crc de verificacao
			FILE * fp = NULL;
			fp = fopen(arquivo_crc, "r");
			if (fp == NULL) {
				printf("Arquivo crc nao encontrado.\n");
				exit(1); //   execao
			}

			fscanf(fp, "%d", &crc_aux);

			fclose(fp);
			//Se o crc armazenado for igual ao calculado sabe-se que o arquivo esta inteiro
			if(crc == crc_aux){
				printf("O arquivo se encontra sao\n");
			}
			else// Se nao, sabe-se que o mesmo esta corrompido
				printf("O arquivo se encontra corrompido\n");
		}
		else{//Caso nao se tenha encontrado nem c nem v
			printf("Comando de execucao incorreto, consulte o readmecrc16 para instrucoes\n");
			free(bin);
			exit(0);
		}
		

	tempoFim = (float)clock()/CLOCKS_PER_SEC; //Pega o tempo em que acabou 

	tempoGasto = tempoFim - tempoInicio; // Pega o tempo da duracao do programa

	printf("O tempo gasto foi %fs\n", tempoGasto); // Imprime o tempo gasto
	return 0;

}

//Variavel com o tamanho do arquivo
int tam = 0;

/**
 * Funcao que le o binario do arquivo, devolve um ponteiro para o binario
 * @param 	arquivo_entrada nome do arquivo de entrada
 */
uint8_t *lerArq(uint8_t *arquivo_entrada){
	

	uint8_t *bin;
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
	bin = (uint8_t *)malloc(tam);



	// Realiza a leitura
	fread(bin, tam, 1 , fp);


	fclose(fp);

	return bin;


}

/**
 * Funcao inversao de bits de um byte
 * @param 	byte a ser invertido
 */
uint8_t reverter(uint8_t bin) {
   bin = (bin & 0xF0) >> 4 | (bin & 0x0F) << 4;
   bin = (bin & 0xCC) >> 2 | (bin & 0x33) << 2;
   bin = (bin & 0xAA) >> 1 | (bin & 0x55) << 1;
   return bin;
}


/**
 * Funcao de calculo CRC
 * @param 	ponteiro dado que eh um vetor de bytes a ser calculado o crc
 */
int calcularCRC(uint8_t *bin){
	uint16_t crc_polinomial = CRC_POL; // x^16+ x^15+ x^2+ 1
	uint16_t crc = 0xffff; // Inicializa o "shift register" com 1s
	int shiftOP = 8; // Para controle de acesso de bits 
	int i = 0;


	// A variação USB exige que os bits em cada byte estejam invetidos
	bin[i] = reverter(bin[i]);

	// Laco que realiza toda a logica, soh sai quando encontra o fim do vetor de bytes
	while(i<tam){

		// caso MSB de bin[i] igual ao MSB do crc, realiza o shift do crc
		if(((bin[i] >> --shiftOP) & 1) == (crc >>15)){ 
			crc <<= 1;
		}
		else{ // Caso contrario alem de realizar o shift faz tbm o xor do crc com o crc_polinomial
			crc <<= 1;
			crc ^= crc_polinomial;
		}

		if(shiftOP<1){// se percorreu todo o byte passa para o proximo 
			i++; //passa para o proximo byte do vetor
			shiftOP = 8;  //Coloca novamente o valor do shift em 8
			bin[i] = reverter(bin[i]);
		}
	}
	
	//Realiza a inversão do resultado
	crc = ~crc;

	//Retorna para a main o valor do crc
	return (crc);

}

