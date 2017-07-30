#include<SDL/SDL.h>
#include<stdio.h>
#include<stdlib.h>

int trata_eventos(int *x, int *y){
  Uint8 *teclado;
  SDL_PumpEvents();
  teclado = SDL_GetKeyState(0);
  if(teclado[SDLK_UP])
    *y = -1;
  if(teclado[SDLK_DOWN])
    *y = 1;
  if(teclado[SDLK_RIGHT])
    *x = 1;
  if(teclado[SDLK_LEFT])
    *x = -1;
  if(teclado[SDLK_SPACE]){
    *x = 0;
    *y = 0;
  }
  return teclado[SDLK_ESCAPE];
}

int main(){
  SDL_Surface *tela;
  SDL_Surface *bolas;
  SDL_Rect fonte, destino;
  int bola_x = 0, bola_y = 0;
  int bola_largura, bola_altura;
  int acrescimo_x=1, acrescimo_y=1;
  int bolas_quadros, fim, quadros;
  if(SDL_Init(SDL_INIT_VIDEO)!=0){
    printf("Erro SDL:\n%s\n", SDL_GetError());
    exit(-1);
  }
  tela = SDL_SetVideoMode(600, 400, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);
  if(!tela){
    printf("Erro vídeo:\n%s\n", SDL_GetError());
    exit(-1);
  }
  bolas = SDL_LoadBMP("bolas.bmp");
  if(!bolas){
    printf("Erro ao carregar bitmap.\n");
    exit(-1);
  }
  SDL_SetColorKey(bolas, SDL_SRCCOLORKEY|SDL_RLEACCEL,(Uint16)SDL_MapRGB(bolas->format, 0,255,0));
  bola_x = 0;
  bola_y = 0;
  bola_largura = 131;
  bola_altura = 131;
  bolas_quadros = 20;
  fonte.x = 0; fonte.y = 0;
  fonte.w = bola_largura; fonte.h = bola_altura;
  destino = fonte;
  quadros = 0;
  fim = 0;
  while(!fim){
    fim = trata_eventos(&acrescimo_x, &acrescimo_y);
    SDL_FillRect(tela, NULL,
    SDL_MapRGB(tela->format, 0, 0, 0));
    if((destino.y + bola_altura + acrescimo_y > 400)
      || (destino.y + acrescimo_y < 0))
      acrescimo_y = -acrescimo_y;
    if((destino.x + bola_largura + acrescimo_x > 600)
      || (destino.x + acrescimo_x < 0))
      acrescimo_x = -acrescimo_x;
    destino.x += acrescimo_x;
    destino.y += acrescimo_y;
    fonte.x = (quadros % bolas_quadros) * bola_largura;
    SDL_BlitSurface(bolas, &fonte, tela, &destino);
    SDL_Flip(tela);
    //SDL_UpdateRect(tela, 0, 0, 0, 0);
    SDL_Delay(20);
    quadros++;
  }
  SDL_Quit();
}