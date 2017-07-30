/*
    Programa para codificacao/decodificacao base 91.
    Este programa implementa dois algoritmos diferentes.

    Um delez (DakeHe) segue a especificacao do seguinte link: http://www.iiis.org/CDs2010/CD2010SCI/CCCT_2010/PapersPdf/TB100QM.pdf
    O outro (Henke) segue a especificao do seguinte link: http://base91.sourceforge.net/

        O programa implementa os algoritmo de codificacao de dados binarios para texto ASCII e decodificacao
    de texto ASCII de volta para binario seguindo o codificacao indicada pelos links acima (base 91).
        Essa codificacao transforma blocos de 13 bits em dois caracteres (16 bits), onde esses caracteres
    sempre serao imprimiveis. Assim, o tamanho do arquivo resultante sera algo em torno de 123% do tamanho
    original.
        Ha tambem a possibilidade dos dados de entrada nao serem multiplos de 13 bits, entao o algoritmo
    adiciona dados extra para indicar se existem bits de padding, ou seja, bits que nao fazem parte dos dados
    originais e servem apenas para preenchimento de espaco.
        O padrao DakeHe sempre adiciona 2 bytes de padding. O padrao Henke adiciona somente quando necessario.

    Por padrao, o programa codifica e decodifica utilizando o padrao Henke, pois foi o padrao utilizado pelos exemplos
    fornecidos. O padrao DakeHe pode ser forcado atraves de uma flag passada como argumento pela linha de comando.

    Comando para compilar:

        gcc -std=c99 base91.c -o base91

    Para executar:

        base91 [input] [output] [options]

        Caso o argumento "input" ou "output" sejam omitidos, o programa ira pedir essas informacoes em
    tempo de execucao e tambem ira pedir se o objetivo e codificar ou decodificar.
        Caso ambos "input" e "output" sejam fornecidos por linha de comando, porem nenhuma opcao seja
    fornecida, o programa assume os valores padroes para as opcoes.
        As opcoes podem ser:

            -d          Realiza decodificacao dos dados
            -n          Adiciona new lines ("\n") no arquivo de saida para facilitar a visualizacao
            -dakehe     Forca o padrao DakeHe em vez do padrao Henke
*/

#include <stdio.h>
#include <string.h>
#include <stdint.h>

// Numero de bytes a ser utilizado pelas strings
// de caminho para arquivo de entrada e saida.
#define PATH_SIZE 256

// Similar a scanf("%s", outBuffer), porem com limite
// de bytes que podem ser escritos em "outBuffer",
// inclui o \0.
void getUserInput(char* outBuffer, int maxBytes);



/****************************************************************/
void base91_encodeFile_Henke(FILE* input, char* outputPath, char addNewLines);
/**
    Funcao: base91_encodeFile_Henke
    Descricao: Le o conteudo de um arquivo (FILE*) de texto/binario ja aberto e codifica seus dados
        seguindo o formato Base 91, salvando o codigo em um arquivo de texto no local especificado.
        Essa funcao segue o padrao especificado pelo link: http://base91.sourceforge.net/
    Parametros:
        FILE* input: arquivo de entrada que tera o conteudo codificado
        char* outputPath: string contendo o caminho para o arquivo que sera gerada contendo a codificacao
        char addNewLines: booleano indicando se o arquivo de saida deve conter new lines para facilitar a leitura

**/



/****************************************************************/
char base91_decodeFile_Henke(FILE* input, char* outputPath);
/**
    Funcao: base91_decodeFile_Henke
    Descricao: Le o conteudo de um arquivo (FILE*) de texto ja aberto e decodifica
        seu texto seguindo o formato Base 91, salvando o codigo original que foi
        anteriormente codificado em um arquivo de texto no local especificado.
        Essa funcao segue o padrao especificado pelo link: http://base91.sourceforge.net/
    Parametros:
        FILE* input: arquivo de entrada que tera o conteudo decodificado
        char* outputPath: string contendo o caminho para o arquivo que sera gerada contendo os dados originais
    Retorno:
        Retorna o valor 1 caso a decodificacao tenha sido um sucesso, e 0 caso tenha falhado.

**/



/****************************************************************/
void base91_encodeFile_DakeHe(FILE* input, char* outputPath, char addNewLines);
/**
    Funcao: base91_encodeFile_DakeHe
    Descricao: Le o conteudo de um arquivo (FILE*) de texto/binario ja aberto e codifica seus dados
        seguindo o formato Base 91, salvando o codigo em um arquivo de texto no local especificado.
        Essa funcao e uma interpretacao do artigo: http://www.iiis.org/CDs2010/CD2010SCI/CCCT_2010/PapersPdf/TB100QM.pdf
    Parametros:
        FILE* input: arquivo de entrada que tera o conteudo codificado
        char* outputPath: string contendo o caminho para o arquivo que sera gerada contendo a codificacao
        char addNewLines: booleano indicando se o arquivo de saida deve conter new lines para facilitar a leitura

**/



/****************************************************************/
char base91_decodeFile_DakeHe(FILE* input, char* outputPath);
/**
    Funcao: base91_decodeFile_DakeHe
    Descricao: Le o conteudo de um arquivo (FILE*) de texto ja aberto e decodifica
        seu texto seguindo o formato Base 91, salvando o codigo original que foi
        anteriormente codificado em um arquivo de texto no local especificado.
        Essa funcao e uma interpretacao do artigo: http://www.iiis.org/CDs2010/CD2010SCI/CCCT_2010/PapersPdf/TB100QM.pdf
    Parametros:
        FILE* input: arquivo de entrada que tera o conteudo decodificado
        char* outputPath: string contendo o caminho para o arquivo que sera gerada contendo os dados originais
    Retorno:
        Retorna o valor 1 caso a decodificacao tenha sido um sucesso, e 0 caso tenha falhado.

**/

int main(int argc, char* argv[])
{
    char outputPath[PATH_SIZE];
    char isEncoding = 1;
    char includeNewLine = 0;
    char useHenkeStandard = 1;

    FILE* inputFile = NULL;

    if (argc >= 2)
    {
        inputFile = fopen(argv[1], "rb");

        if (inputFile == NULL)
        {
            printf("O arquivo de entrada nao pode ser aberto.\n");
            return 0;
        }

    }
    else
    {
        char inputPath[PATH_SIZE];

        do
        {
            printf("Entre o caminho para o arquivo de entrada:\n> ");
            getUserInput(inputPath, sizeof(inputPath));

            inputFile = fopen(inputPath, "rb");

            if (inputFile == NULL)
                printf("O arquivo no caminho \"%s\" nao pode ser lido.\n", inputPath);

        } while (inputFile == NULL);
    }

    if (argc >= 3)
    {
        strncpy(outputPath, argv[2], sizeof(outputPath));
    }
    else
    {
        printf("Entre o caminho para o arquivo que ira guardar a saida:\n> ");
        getUserInput(outputPath, sizeof(outputPath));
    }

    if (argc >= 4)
    {
        int argIndex;

        for (argIndex = 3; argIndex < argc; argIndex++)
        {
            // Se o programa for chamado com o argumento "-d", decodifica o arquivo
            // de entrada. O padrao e codificar o arquivo de entrada.
            if (strcmp(argv[argIndex], "-d") == 0)
                isEncoding = 0;
            else if (strcmp(argv[argIndex], "-n") == 0)
                includeNewLine = 1;
            else if (strcmp(argv[argIndex], "-dakehe") == 0)
                useHenkeStandard = 0;
        }
    }
    // Descobre durante execucao se o usuario quer codificar ou decodificar o arquivo.
    // Se o usuario especificou os arquivos de entrada e de saida e nao adicionou
    // a flag -d, assume que o objetivo e codificar.
    else if (argc < 3)
    {
        // Variavel para guardar a resposta do usuario.
        char answer[2];

        do
        {
            printf("Entre com a opcao 'E' para codificar o arquivo, ou 'D' para decodifica-lo.\n> ");

            getUserInput(answer, sizeof(answer));

            // Utiliza o segundo byte de 'answer' como booleano para saber se a entrada foi valida.
            answer[1] = (answer[0] == 'E' || answer[0] == 'e' || answer[0] == 'd' || answer[0] == 'D');

            if (!answer[1])
            {
                printf("Entrada invalida.\n");
            }
            else if (answer[0] == 'D' || answer[0] == 'd')
            {
                isEncoding = 0;
            }

        } while (!answer[1]);
    }

    if (isEncoding)
    {
        if (useHenkeStandard)
            base91_encodeFile_Henke(inputFile, outputPath, includeNewLine);
        else
            base91_encodeFile_DakeHe(inputFile, outputPath, includeNewLine);

        printf("O arquivo de entrada foi codificado com sucesso.\n");
    }
    else
    {
        if (useHenkeStandard)
        {
            if (base91_decodeFile_Henke(inputFile, outputPath))
                printf("O arquivo de entrada foi decodificado com sucesso.\n");
            else
                printf("O arquivo de entrada no pode ser decodificado.\n");
        }
        else
        {
            if (base91_decodeFile_DakeHe(inputFile, outputPath))
                printf("O arquivo de entrada foi decodificado com sucesso.\n");
            else
                printf("O arquivo de entrada no pode ser decodificado.\n");
        }
    }

    fclose(inputFile);
    return 0;
}

void getUserInput(char* outBuffer, int maxBytes)
{
    while (1)
    {
        int input = getchar();

        if (input == '\n')
        {
            if (maxBytes > 0)
                *outBuffer = '\0';

            break;
        }

        if (maxBytes > 0)
        {
            if (maxBytes == 1)
                *outBuffer = '\0';
            else
                *outBuffer++ = (char)input;

            maxBytes--;
        }
    }
}

void base91_encodeFile_Henke(FILE* input, char* outputPath, char addNewLines)
{
    FILE* outputFile = fopen(outputPath, "w");

    if (outputFile == NULL)
        return;

    // Alfabeto contendo os 91 caracteres que compoem a codificacao base 91.
    static const char base91Alphabet[91] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '#', '$',
        '%', '&', '(', ')', '*', '+', ',', '.', '/', ':', ';', '<', '=',
        '>', '?', '@', '[', ']', '^', '_', '`', '{', '|', '}', '~', '"'
    };

    // Blocos de 13 bits que vao sendo lidos sao guardados nessa variavel.
    uint32_t bitStream = 0;

    // Indica quantos bits estao sendo armazenados no stream de bits.
    uint8_t bitsInStream = 0;

    // Variavel que guarda os bytes que serao lidos do arquivo de entrada.
    int byteReadFromFile;

    // Contador para numero de bytes escritos no arquivo
    uint32_t bytesWritten = 0;

    while (1)
    {
        byteReadFromFile = fgetc(input);

        if (byteReadFromFile == EOF)
        {
            if (bitsInStream > 0)
            {
                fputc(base91Alphabet[bitStream % 91], outputFile);

                if (bitsInStream > 7 || bitStream > 90)
                    fputc(base91Alphabet[bitStream / 91], outputFile);
            }

            break;
        }
        else
        {
            bitStream = bitStream | (byteReadFromFile << bitsInStream);
            bitsInStream += 8;
        }

        if (bitsInStream > 13)
        {
            uint16_t block = bitStream & 0x1FFF;

            if (block <= 88)
            {
                block = bitStream & 0x3FFF;
                bitsInStream -= 14;
                bitStream >>= 14;
            }
            else
            {
                bitsInStream -= 13;
                bitStream >>= 13;
            }

            fputc(base91Alphabet[block % 91], outputFile);
            fputc(base91Alphabet[block / 91], outputFile);

            bytesWritten += 2;

            if (addNewLines && (bytesWritten % 76) == 0)
                fputc('\n', outputFile);
        }
    };

    fclose(outputFile);
}

char base91_decodeFile_Henke(FILE* input, char* outputPath)
{
    // Prepara o arquivo de saida
    FILE* outputFile = fopen(outputPath, "wb");

    // Caso a criacao deste arquivo falhe, a funcao para.
    if (outputFile == NULL)
        return 0;

    // Tabela que permite converter um caracter ASCII para o seu respectivo
    // valor do alfabeto base 91.
    uint8_t asciiToBase91Table[256] = {
        91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
        91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
        91, 62, 90, 63, 64, 65, 66, 91, 67, 68, 69, 70, 71, 91, 72, 73,
        52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 74, 75, 76, 77, 78, 79,
        80,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 81, 91, 82, 83, 84,
        85, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 86, 87, 88, 89, 91,
        91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
        91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
        91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
        91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
        91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
        91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
        91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
        91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91
    };

    // Blocos de 13 bits que vao sendo gerados sao guardados nessa variavel.
    uint32_t bitStream = 0;

    // Indica quantos bits estao sendo armazenados no stream de bits.
    uint8_t bitsInStream = 0;

    int32_t base91Block = -1;

    while (1)
    {
        // Obtem um caracter  da entrada codificada.
        int byteRead = fgetc(input);

        if (byteRead == EOF)
        {
            if (base91Block != -1)
            {
                fputc(bitStream | (base91Block << bitsInStream), outputFile);
            }
            break;
        }

        uint8_t base91Code = asciiToBase91Table[byteRead];

        // Ignora caracteres que nao fazem parte do alfabeto
        if (base91Code == 91)
            continue;

        if (base91Block == -1)
        {
            base91Block = base91Code;
        }
        else
        {
            base91Block += base91Code * 91;
            bitStream = bitStream | (base91Block << bitsInStream);
            bitsInStream += (base91Block & 0x1FFF) > 88 ? 13 : 14;

            while (bitsInStream > 7)
            {
                fputc(bitStream, outputFile);
                bitStream >>= 8;
                bitsInStream -= 8;
            }

            base91Block = -1;
        }
    };

    fclose(outputFile);
    return 1;
}

void base91_encodeFile_DakeHe(FILE* input, char* outputPath, char addNewLines)
{
    FILE* outputFile = fopen(outputPath, "w");

    if (outputFile == NULL)
        return;

    // Alfabeto contendo os 91 caracteres que compoem a codificacao base 91.
    char base91Alphabet[91];

    // Geracao dos 91 caracteres que compoem o alfabeto do base91
    {
        // O alfabeto contem todos os caracteres imprimiveis com excecao de
        // ponto final (.), espaco ( ), sinal de igual (=) e hifen (-).
        // Alem disso, o alfabeto e ordenado seguindo a ordem sequencial da tabela
        // ASCII.
        char* alphabetPtr = base91Alphabet;
        char c;

        // Itera sobre todos os caracteres da table ASCII, ignorando os 33 primeiros
        // caracteres (32 de controle e o espaco), e ignorando o caracter de codigo
        // 127, que tambem e de controle.
        for (c = 33; c <= 126; c++)
        {
            // Insere no alfabeto somente os caracteres que nao foram excluidos.
            if (c != '-' && c != ' ' && c != '.' && c != '=')
                *alphabetPtr++ = c;
        }
    }

    // Blocos de 13 bits que vao sendo lidos sao guardados nessa variavel.
    uint32_t bitStream = 0;

    // Indica quantos bits estao sendo armazenados no stream de bits.
    uint8_t bitsInStream = 0;

    // Quantos bits de padding serao necessarios
    uint16_t padding = 0;

    // Variavel que guarda os bytes que serao lidos do arquivo de entrada.
    int byteReadFromFile;

    // Variavel de controle do laco.
    char keepGoing = 1;

    // Contador para numero de bytes escritos no arquivo
    uint32_t bytesWritten = 0;

    while (keepGoing)
    {
        byteReadFromFile = fgetc(input);

        if (byteReadFromFile == EOF)
        {
            if (bitsInStream > 0)
            {
                bitStream <<= 13 - bitsInStream;
                padding = 8204 - bitsInStream;
                bitsInStream = 13;
            }

            keepGoing = 0;
        }
        else
        {
            bitsInStream += 8;
            bitStream = (bitStream << 8) | byteReadFromFile;
        }

        if (bitsInStream >= 13)
        {
            bitsInStream -= 13;
            uint16_t block = 0x1FFFu & (bitStream >> bitsInStream);

            fputc(base91Alphabet[block / 91], outputFile);
            fputc(base91Alphabet[block % 91], outputFile);

            bytesWritten += 2;

            if (addNewLines && bytesWritten % 76 == 0)
                fputc('\n', outputFile);
        }
    };

    if (padding == 0)
    {
        fputc('=', outputFile);
        fputc('=', outputFile);
    }
    else if (padding > 0)
    {
        fputc(base91Alphabet[padding / 91], outputFile);
        fputc(base91Alphabet[padding % 91], outputFile);
    }

    fclose(outputFile);
}

char base91_decodeFile_DakeHe(FILE* input, char* outputPath)
{
    // Prepara o arquivo de saida
    FILE* outputFile = fopen(outputPath, "wb");

    // Caso a criacao deste arquivo falhe, a funcao para.
    if (outputFile == NULL)
        return 0;

    // Tabela que permite converter um caracter ASCII para o seu respectivo
    // valor do alfabeto base 91.
    uint8_t asciiToBase91Table[256];

    // Geracao da tabela que faz a conversao de um caracter ascii no intervalo [0, 255]
    // para o respectivo valor seguindo o alfabeto do base91, no intervalo [0, 90]
    {
        // Usado para iterar sobre todos os valores ASCII [0, 255]
        int i;

        // Valor que aquele caracter ASCII tera no alfabeto base 91
        // Esse valor vai incrementando a medida que a tabela vai sendo preenchida
        uint8_t c = 0;

        for (i = 0; i <= 255; i++)
        {
            // Caso o valor seja imprimivel e nao seja um dos caracteres excluidos
            // pelo alfabeto base 91, atribui seu valor na tabela.
            if (i >= 33 && i <= 126 && i != '-' && i != ' ' && i != '.' && i != '=')
                asciiToBase91Table[i] = c++;
            else
                // Qualquer valor acima de 91 serviria
                asciiToBase91Table[i] = 100;
        }
    }

    // Blocos de 13 bits que vao sendo gerados sao guardados nessa variavel.
    uint32_t bitStream = 0;

    // Indica quantos bits estao sendo armazenados no stream de bits.
    uint8_t bitsInStream = 0;

    while (1)
    {
        // Obtem um caracter  da entrada codificada.
        int byte1 = fgetc(input);

        if (byte1 == EOF)
            break;

        // Ignora caracteres de line feed
        if (byte1 == '\n' || byte1 == '\r')
            continue;

        // Obtem o segundo caracter para compor o bloco de 16 bits
        int byte2 = fgetc(input);

        // Codigos base 91 sao sempre multiplos de 16 bits, entao se o primeiro byte
        // nao e EOF, o segundo tambem nao deve ser.
        if (byte2 == EOF)
        {
            fclose(outputFile);
            return 0;
        }

        // Realiza a conversao de ASCII -> Base91
        uint8_t base91Code1 = asciiToBase91Table[byte1];
        uint8_t base91Code2 = asciiToBase91Table[byte2];

        // Verifica se a conversao foi valida (o valor no alfabeto base 91 deve estar
        // contido no intervalo [0, 90]). O unico caso em que o valor pode estar fora
        // deste intervalo e quando os bytes lidos sao ambos iguais a '=', significando
        // o fim do codigo.
        if ((base91Code1 > 91 || base91Code2 > 91) && (byte1 != '=' || byte2 != '='))
        {
            fclose(outputFile);
            return 0;
        }

        // Gera o codigo original, que e um bloco de 13 bits.
        uint16_t block = base91Code1 * 91 + base91Code2;

        // Caso o bloco seja 13 bits validos, insere esses bits no stream
        if (block <= 8191)
        {
            // Como 13 serao inseridos, e necessario verificar se o stream
            // possui capacidade (o stream armazena apenas 32 bits). Na
            // falta de capacidade, salva os bytes armazenados no stream de
            // bits no arquivo de saida
            while (bitsInStream > 19)
            {
                fputc(bitStream >> (bitsInStream - 8), outputFile);
                bitsInStream -= 8;
            }

            // Insere os 13 bits no stream de bits. O motivo pelo qual os 13 bits
            // sao inseridos no stream em vez de diretamente serem escritos no arquivo
            // de saida e que pode ser que hajam bits de padding, ou seja, bits de
            // preenchimento que nao fazem parte do codigo original. Como os bits
            // ainda estao em memoria, e facil remover os bits de padding.
            bitStream = (bitStream << 13) | block;
            bitsInStream += 13;
        }
        // Caso o bloco lido nao caiba em 13 bits, significa que esse codigo
        // possui informacoes sobre o padding (ou entao a entrada nao e um
        // base 91 valido).
        else
        {
            // Informacoes sobre o padding devem ser os ultimos dois bytes da entrada,
            // entao e de se esperar que a proxima leitura no arquivo seja EOF. Caso
            // contrario, a entrada nao e valida.
            if (fgetc(input) != EOF)
            {
                fclose(outputFile);
                return 0;
            }

            // Caso os ultimos dois bytes lidos sejam '=', significa que nao ha
            // bits de padding adicionados, entao para o loop aqui.
            if (byte1 == '=' && byte2 == '=')
                break;

            // Para indicar padding, o bloco base 91 ira guardar mais do que
            // 13 bits, e ira conter o valor (8192 + n), onde "n" e o numero
            // de bits utilizados para padding.
            // "block" agora contem o numero de bits usados para padding
            block -= 8191;

            // Se o numero de bits de apdding for maior que o numero de bits
            // contidos no stream, a entrada possui algum problema, pois esta
            // nos dizendo para ignorar "block" bits de padding, sendo que nao
            // ha bits o suficiente para ignorar.
            if (bitsInStream < block)
            {
                fclose(outputFile);
                return 0;
            }

            // Remove os bits de padding da stream.
            bitsInStream -= block;
            bitStream >>= block;
            break;
        }
    };

    // Se o numero de bits que ainda estao no stream em memoria e precisam
    // ser escritos em disco nao for multiplo de 8, o arquivo de entrada
    // esta com algum problema.
    if (bitsInStream % 8 != 0)
    {
        fclose(outputFile);
        return 0;
    }

    // Para cada byte restante no stream, escreve este byte no arquivo de saida.
    while (bitsInStream > 0)
    {
        fputc(bitStream >> (bitsInStream - 8), outputFile);
        bitsInStream -= 8;
    }

    fclose(outputFile);
    return 1;
}