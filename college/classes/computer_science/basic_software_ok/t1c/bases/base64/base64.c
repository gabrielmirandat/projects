#include "base64.h"


int main(int argc, char **argv){
    
    char *arquivo_entrada 	= NULL;
    char *operacao 			= NULL;
    uint8_t *texto;
    float tempoInicio = 0, tempoFim = 0, tempoGasto;
    
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
            printf("Comando de execucao incorreto, consulte o readmeBase64 para instrucoes\n");
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
        
    int tam;
    uint8_t *texto;
    FILE * fp = NULL;
        
    fp = fopen(arquivo_entrada, "rb");
    if (fp == NULL) {
        printf("Arquivo nao encontrado.\n");
        exit(1); //   execao
    }
        
    //Pega o tamanho do arquivo para a alocacao
    fseek(fp, 0, SEEK_END);
    tam = (int)ftell(fp);
    fseek(fp,0,SEEK_SET);
        
    // aloca a memoria
    texto = (uint8_t *)malloc(tam+1);
        
        
        
    // Realiza a leitura
    fread(texto, tam, 1 , fp);
        
        
    fclose(fp);
    TAMANHO = tam;
    return texto;
    
}


/**
 * Funcao que le o texto do arquivo, devolve um ponteiro para a string
 * @param 	texto string a ser codificada
 * @param 	arquivo de saida com o a codificacao
 */
void codificar(uint8_t *texto){
    
    int letra; //inteiro com o indice do vetor de letras na base64
    FILE *fp = NULL;
    
    //Abre arquivo para colocar a saida
    fp = fopen("codificado.b64", "w");
    
    //Percorre todos os bytes do arquivo
    for(int i = 0; i < TAMANHO; i += 3){

        letra = (texto[i] & 0xFC) >> 2;
        fprintf(fp, "%c", tabela64[letra]);
        
        letra = (texto[i] & 0x03) << 4;
        
        if (i + 1 < TAMANHO){
            
            letra |= (texto[i + 1] & 0xF0) >> 4;
            fprintf(fp, "%c", tabela64[letra]);
            
            letra = (texto[i + 1] & 0x0F) << 2;
            
            if (i + 2 < TAMANHO){
                
                letra |= (texto[i + 2] & 0xC0) >> 6;
                fprintf(fp, "%c", tabela64[letra]);
                
                letra = texto[i + 2] & 0x3F;
                fprintf(fp, "%c", tabela64[letra]);
                
            } else{
                
                fprintf(fp, "%c", tabela64[letra]);
                fprintf(fp, "=");
                
            }
        } else{
            
            fprintf(fp, "%c", tabela64[letra]);
            fprintf(fp, "==");
            
        }
    }
    fclose(fp);
    
}


/**
 * Funcao que le o texto do arquivo, devolve um ponteiro para a string
 * @param 	texto string a ser decodificada
 * @param 	arquivo de saida com o a decodificacao
 */
void decodificar(uint8_t *texto){
    FILE *fp = NULL;
    int8_t palavra8bit[4];
 
    //Abre arquivo para colocar a saida
    fp = fopen("decodificado.b64", "w");
    
    if (TAMANHO % 4 != 0)    {
        printf("Erro no tamanho do arquivo.");
        return;
    }
    for (int i = 0; i < TAMANHO; i += 4)     {
        // This could be made faster (but more complicated) by precomputing these index locations.
        palavra8bit[0] = buscaletra(texto[i]);
        palavra8bit[1] = buscaletra(texto[i + 1]);
        palavra8bit[2] = buscaletra(texto[i + 2]);
        palavra8bit[3] = buscaletra(texto[i + 3]);
        fprintf(fp, "%c", (char) ((palavra8bit[0] << 2) | (palavra8bit[1] >> 4)) );
        if (palavra8bit[2] < 64)      {
            fprintf(fp, "%c", (char) ((palavra8bit[1] << 4) | (palavra8bit[2] >> 2)) );
            if (palavra8bit[3] < 64)  {
                fprintf(fp, "%c", (char) ((palavra8bit[2] << 6) | palavra8bit[3]) );
            }
        }
    }
    fclose(fp);
    
}

int8_t buscaletra(char letra){
    for(int i = 0; i < 64; i++){
        if(letra == tabela64[i])
            return i;
    }
    return -1;
}