#include"SDL/SDL.h"
#undef main
#include<stdio.h>
#include<stdlib.h>
int main(){
SDL_Surface *tela;
SDL_Surface *bola;
SDL_Rect fonte, destino;
if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("Erro SDL:\n%s\n", SDL_GetError());
exit(-1);
}
tela = SDL_SetVideoMode(300, 200, 16, SDL_SWSURFACE);
if(!tela){
printf("Erro vídeo:\n%s\n", SDL_GetError());
exit(-1);
}
bola = SDL_LoadBMP("bola.bmp");
if(!bola){ printf("Erro ao carregar bitmap.\n"); exit(-1); }
fonte.x = 0;
fonte.y = 0;
fonte.w = 64;
fonte.h = 64;
destino.x = 30;
destino.y = 10;
destino.w = 64;
destino.h = 64;
SDL_FillRect(tela, NULL,
SDL_MapRGB(tela->format, 255, 255, 255));
SDL_BlitSurface(bola, &fonte, tela, &destino);
SDL_UpdateRect(tela, 0, 0, 0, 0);
SDL_Delay(1000);
SDL_Quit();
}
