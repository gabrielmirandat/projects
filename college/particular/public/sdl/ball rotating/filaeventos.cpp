#include<SDL/SDL.h>
#include<stdio.h>
#include<stdlib.h>

int main(){

  SDL_Surface *tela;
  SDL_Event evento;
  int fim = 0;

  if(SDL_Init(SDL_INIT_VIDEO)!=0){
    printf("Erro: %s\n", SDL_GetError());
    exit(-1);
  }

  tela = SDL_SetVideoMode(300, 200, 16, SDL_SWSURFACE);
  if(!tela){
    printf("Erro: %s\n", SDL_GetError());
    exit(-1);
  }
  while(!fim)
    if(SDL_PollEvent(&evento)){
    switch(evento.type){
      case SDL_KEYDOWN:
	printf("Tecla pressionada\n");
	break;
      case SDL_KEYUP:
	printf("Tecla solta.\n");
	break;
      case SDL_QUIT:
	printf("Saída requerida.\n");
	fim = 1;
	break;
    }
  }
  SDL_Quit();
}