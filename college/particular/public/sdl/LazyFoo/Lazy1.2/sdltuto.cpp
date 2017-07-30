
//Incluir funções SDL e seus tipos de dados
	#include "SDL/SDL.h"

//Imagens
	SDL_Surface* hello = NULL;
	SDL_Surface* screen = NULL;

//Começa SDL.Inicializa todos os subsistemas SDL para que possamos começar a usar funções gráficas do SDL.
	SDL_Init( SDL_INIT_EVERYTHING );

//Configura tela. SDL_SetVideoMode () é chamado para criar uma janela de 640 pixels de largura, 480 pixels de altura e que tem 32 bits por pixel. 
O último argumento (SDL_SWSURFACE) configura a superfície na memória software. Após SDL_SetVideoMode () ser executado, ele retorna um ponteiro para a 
superfície da janela para que possamos usá-lo.
	screen = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE );

//Após a janela ser criada, nós carregamos nossa imagem usando SDL_LoadBMP (). SDL_LoadBMP () recebe em um caminho para um arquivo de bitmap como um 
argumento e retorna um ponteiro para a SDL_Surface carregada. Esta função retorna NULL se houve um erro ao carregar a imagem.
	hello = SDL_LoadBMP( "hello.bmp" );

//Carregar imagem na tela. O primeiro argumento de SDL_BlitSurface ()  é a superfície de fonte. O terceiro argumento é a superfície destino. 
SDL_BlitSurface () cola a superfície de origem na superfície do destino.  Neste caso, ele vai aplicar a nossa imagem carregada na tela.
	SDL_BlitSurface( hello, NULL, screen, NULL );

//Update a tela. Agora  que a nossa imagem esta aplicada à tela, precisamos atualizar a tela para que possamos vê-la. Fazemos isso utilizando SDL_Flip (). 
Se você  não chamar SDL_Flip (), você só verá uma tela em branco desatualizada.
	SDL_Flip( screen );

//Pausa. Nós temos que fazer com que a janela fique visível para que não apenas pisque por uma fração de segundo e desapareça. Nós vamos fazer 
a janela permanecer por 2 segundos chamando SDL_Delay ().
	SDL_Delay( 2000 );

//Libera a imagem carregada. Você não pode apenas usar delete(), você tem que usar SDL_FreeSurface () para remover a imagem de memória.
	SDL_FreeSurface( hello );

//Sair do SLD. Não é necessário liberar a SDL_Surface screen pois SDL_Quit() limpa para nós.
	SDL_Quit();




