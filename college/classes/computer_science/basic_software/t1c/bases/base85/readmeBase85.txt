Bárbara Varanda Rangel
Gabriel Martins de Miranda
Jadiel Teófilo Amorim de Oliveira
Marcos Cordeiro Fleury
Túlio de Carvalho Matias


Base 85 encodificando e decodificando

Desenvolvido em C na plataforma linux e compilado utilizando do comando <gcc -std=c99 base85.c -lm -o base85>. 
Em windows ele pode ser compilado com o mesmo comando.

A execucao ocorre por meio do comando <./base85 "arquivo_entrada" "sigla_operacao">. Onde o "arquivo_entrada" 
deve ser alterado de acordo com o arquivo de entrada desejado e a sigla da operacao deve ser 'e' para 
encodificar e 'd' para decodificar. Portando exmplos de comandos para execucao seriam:

<./base85 arquivoCodificado d > para decodificar
<./base85 arquivoNaoCodificado c > para codificar

Existe tambem a possibilidade de nao especificar arquivo nem operacao no momento de execucao, fazendo-o apos a 
execucao:

<./base85> arquivo e operacao selecionado depois.

Em windows deve-se apenas se abster do "./".



-Como funciona?
O Programa tem como entrada um arquivo em txt que contem determinado texto codificado ou nao. De acordo com a escolha do usuario ele realiza a codificacao ou decodificacao do requisitado. A saida eh escrita na tela e em um arquivo, "decodificado" ou "codificado", de acordo com a operacao.

A codificacao ocorre da seguinte forma:

-O codigo ascii é separado a cada 32 bits, e convertido para o decimal.
-Ao valor é calculado o equivalente na base 85 realizando divisões sucessivas e pegando o resto.
-Para cada um dos 5 restos gerados, é adicionado 33.
-Cada um dos novos valores resultantes correspondem à um novo caracter codificado.

A decodificacao ocorre da seguinte forma:

-O texto é dividido em grupos de 5 caracteres os quais são todos subtraidos de 33.
-O valor resultante é convertido para o binario.
-O codigo encontrado é o texto decodificado

