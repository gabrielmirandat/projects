
//Incluir fun��es SDL e seus tipos de dados
	#include "SDL/SDL.h"

//Imagens
	SDL_Surface* hello = NULL;
	SDL_Surface* screen = NULL;

//Come�a SDL.Inicializa todos os subsistemas SDL para que possamos come�ar a usar fun��es gr�ficas do SDL.
	SDL_Init( SDL_INIT_EVERYTHING );

//Configura tela. SDL_SetVideoMode () � chamado para criar uma janela de 640 pixels de largura, 480 pixels de altura e que tem 32 bits por pixel. 
O �ltimo argumento (SDL_SWSURFACE) configura a superf�cie na mem�ria software. Ap�s SDL_SetVideoMode () ser executado, ele retorna um ponteiro para a 
superf�cie da janela para que possamos us�-lo.
	screen = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE );

//Ap�s a janela ser criada, n�s carregamos nossa imagem usando SDL_LoadBMP (). SDL_LoadBMP () recebe em um caminho para um arquivo de bitmap como um 
argumento e retorna um ponteiro para a SDL_Surface carregada. Esta fun��o retorna NULL se houve um erro ao carregar a imagem.
	hello = SDL_LoadBMP( "hello.bmp" );

//Carregar imagem na tela. O primeiro argumento de SDL_BlitSurface ()  � a superf�cie de fonte. O terceiro argumento � a superf�cie destino. 
SDL_BlitSurface () cola a superf�cie de origem na superf�cie do destino.  Neste caso, ele vai aplicar a nossa imagem carregada na tela.
	SDL_BlitSurface( hello, NULL, screen, NULL );

//Update a tela. Agora  que a nossa imagem esta aplicada � tela, precisamos atualizar a tela para que possamos v�-la. Fazemos isso utilizando SDL_Flip (). 
Se voc�  n�o chamar SDL_Flip (), voc� s� ver� uma tela em branco desatualizada.
	SDL_Flip( screen );

//Pausa. N�s temos que fazer com que a janela fique vis�vel para que n�o apenas pisque por uma fra��o de segundo e desapare�a. N�s vamos fazer 
a janela permanecer por 2 segundos chamando SDL_Delay ().
	SDL_Delay( 2000 );

//Libera a imagem carregada. Voc� n�o pode apenas usar delete(), voc� tem que usar SDL_FreeSurface () para remover a imagem de mem�ria.
	SDL_FreeSurface( hello );

//Sair do SLD. N�o � necess�rio liberar a SDL_Surface screen pois SDL_Quit() limpa para n�s.
	SDL_Quit();




