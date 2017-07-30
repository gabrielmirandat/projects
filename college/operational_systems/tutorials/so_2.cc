//PROVA 3
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//
memoria.pdf

Gerenciamento de  memória

- Bare memory
- Monitor residente
- Multiprogramação
	- Partições fixas
	- Partições variáveis
	- Memória virtual
		- Paginação
		- Segmentação
		- Segmentação paginada

Monoprogramação sem Paginação ou Swapping
	- Bare memory
		não existe esquema de gerenciamento da memória. O usuário possui controle absoluto sobre todo o espaço de memória
		não há sistema operacional

	- Monitor residente
		uma área para o usuário e outra para o sistema operacional
		Hardware adicional:É necessário um dispositivo de hardware que impeça o processo de usuário de acessar a área do sistema operacional

Multiprogramação
	Como manter mais de um processo de usuário ativo em memória simultaneamente?
	
	- Partições fixas
		O processo roda na mesma partição fixa até terminar
		Fragmentação interna
	
	- Partições variáveis
		O número, o tamanho e a localização dos processos em memória varia com o tempo
		First fit, best fit, worst fit
		Fragmentação externa 

	- Memória virtual
		Como executar um processo que não cabe inteiramente na memória?
		devemos quebrar o processo em unidades menores e carregar estas unidades em memória à medida em que elas são necessárias
		Com a memória virtual, o processo não referencia mais endereços físicos e sim endereços virtuais

		- Paginação
			divide a memória física e a memória virtual em unidades de tamanho fixo
			O endereço virtual é dividido em unidades de tamanho fixo chamadas páginas
			memória física é dividida em unidades de tamanho igual ao das páginas, chamadas page frames
			Tabela foward: A tabela de páginas é um vetor de entradas, armazenada em memória.
			Tabela invertida: classificada pela página física (frame) e não pela página virtual, ficando menor

			Algoritmos realizáveis de substituição de páginas:
				- NUR
				- FIFO
				- Segunda
				- Relógio
				- LRU

		- Segmentação
			divide a memória física e a memória virtual em unidades de tamanho variável
			A segmentação facilita a implementação de bibliotecas compartilhadas. As bibliotecas compartilhadas não são
				ligadas no código executável do programa. Seu código é colocado em um segmento, que pode ser compartilhado
				por vários processos, em tempo de execução
			paginar os segmentos
			Exemplos típicos de segmentos são os segmentos de código, dados e pilha de um processo
			somente as páginas realmente necessárias são mantidas em memória



		- Segmentação paginada
			paginação dentro da segmentação

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//
arquivo.pdf

Estruturas de arquivos mais comuns são:
- sequência de bytes
	- raw, sem estrutura
- sequência de registros
	- registros de tamanho fixo
- árvore de registros
	- árvore de tamanho variável

Tipos de arquivos
- arquivos regulares: contem os dados do usuário
- arquivos diretório: arquivos utilizados na manutenção do sistema de arquivos.
- arquivos especiais: arquivos ligados a dispositivos de E/S.

Acesso
- sequencial
	- leitura e escrita
- direto (aleatório)
	- leitura(n) e escrita(n)

Implementação de arquivos
- Alocação contígua
- Alocação com lista encadeada e índice
- Nós-i

Gerência de Espaço
- Lista encadeada
- Mapa de bits

Confiabilidade do sistema
- Gerência de blocos ruins
- Backups
- Gerência da consistência

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//
e/s.pdf

Dispositivos de bloco    - unidades de tam fixo, acesso direto, disco
Dispositivos de caracter - tam variavel, temporariamente, terminais, impressoras, mouse

unidades de E/S são compostas de uma parte
mecânica (o dispositivo propriamente dito) e uma parte
eletrônica (controladora de dispositivo) que controla a
operação do dispositivo

- Manipuladores de interrupção
- Drivers de dispositivos
- SO independente do dispositivo
- Aplicações de usuário

- Aplicações
- E/S independente de dispositivo
- Drivers de Dispositivo
- Manipuladores de Interrupção Hardware

Algoritmos mais conhecidos de seek do braço de disco:
- FCFS 			First Come First Served
- SSTF			Shortest Seek Time First (pode causar starvation facilmente)
- Elevador
	- SCAN 		Zero ao fim do disco
	- LOOK 		Até ultimo bloco na fila de requisições
	- C-SCAN/   Só serve em uma direção
	C-LOOK