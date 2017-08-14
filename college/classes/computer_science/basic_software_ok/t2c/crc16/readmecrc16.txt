
Bárbara Varanda Rangel
Gabriel Martins de Miranda
Jadiel Teófilo Amorim de Oliveira
Marcos Cordeiro Fleury
Túlio de Carvalho Matias


CRC16 Calculando e Verificando

Desenvolvido em C na plataforma linux e compilado utilizando do comando <gcc -std=c99 crc16.c -lm -o crc16>. 
Em windows ele pode ser compilado com o mesmo comando.

A execucao ocorre por meio do comando <./crc16 "arquivo_entrada" c> ou <./crc16 "arquivo_entrada" v
 "arquivo_crc" >. Onde o primeiro comando serve para o calculo do crc, dando como saida o proprio, e 
 o segundo comando serve para a verificação da integridade, tendo como saida o parecer sobre tal. As 
 entradas são : "arquivo_entrada" deve ser alterado de acordo com o arquivo de entrada (binario) 
 desejado, o "arquivo_crc" é o arquivo que deve conter o crc para a verificacao e a sigla da operacao 
 que deve ser 'c' para calculo do crc e 'v' para verificacao. Portando exmplos de comandos para 
 execucao seriam:

<./crc16 amostra_h1.bin c> para decodificar
<./crc amostra_h1.bin v crc_amostra.txt > para codificar

Existe tambem a possibilidade de nao especificar arquivos nem operacao no momento de execucao, fazendo-o apos a 
execucao:

<./crc16> arquivo e operacao selecionado depois.

Em windows deve-se apenas se abster do "./".






Como funciona?

O programa funciona da mesma forma que o algoritmo enunciado abaixo.

Calculo 
1.  Utilizasse de uma variável crc que conterá o resultado do cálculo. A mesma é iniciada com 0xffff;
2.  Utiliza-se de uma variável polGerador que contém os 16 bits LSB do polinômio gerador x^16 x^15 x^2 x^1 ou 11000000000000101. Logo polGerador = 1000000000000101;
3.  O dado recebido é revertido byte a byte;
4.  Se o MSB do crc é igual ao MSB do dado:
    a.  Realiza-se o shitf do crc à esquerda.
5.  Se não:
    a.  Realiza-se o shitf do crc à esquerda;
    b.  Faz-se o crc receber a operação xor entre o crc e o polGerador.
6.  Verifica-se se já se encontra no fim do dado. Se não, volta para o passo 4.
7.  Inverte-se os bits do crc, e encerra-se o programa.

Verificacao
1.  Realiza-se o cálculo do crc da mesma forma que descrito no calculo. 
2.  Compara-se o resultado com o encontrado no arquivo.
3.  Imprime o status do arquivo.
4.  Encerra o programa.

