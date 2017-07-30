#include<SDL/SDL.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
    SDL_Surface *tela;
    SDL_Surface *bolas;
    SDL_Rect fonte, destino;
    int bola_x=0, bola_y=0, bola_largura, bola_altura;
    int acrescimo_x=1, acrescimo_y=1, bolas_quadros, i;
    if(SDL_Init(SDL_INIT_VIDEO)!=0){
        printf("Erro SDL:\n%s\n", SDL_GetError());
        exit(-1);
    }
    tela = SDL_SetVideoMode(300, 200, 16, SDL_SWSURFACE);
    if(!tela){
        printf("Erro vídeo:\n%s\n", SDL_GetError());
        exit(-1);
    }
    bolas = SDL_LoadBMP("bolas.bmp");
    if(!bolas){
        printf("Erro ao carregar bitmap.\n");
        exit(-1);
    }
    bola_x = 0;
    bola_y = 0;
    bola_largura = 131;
    bola_altura = 131;
    bolas_quadros = 20;
    fonte.x = 0;
    fonte.y = 0;
    fonte.w = bola_largura;
    fonte.h = bola_altura;
    destino = fonte;
    for(i=0;i<600;i++){
        SDL_FillRect(tela, NULL,
        SDL_MapRGB(tela->format, 0, 0, 0));
        if((destino.y + bola_altura + acrescimo_y > 200)
            || (destino.y + acrescimo_y < 0))
            acrescimo_y = -acrescimo_y;
        if((destino.x + bola_largura + acrescimo_x > 300)
            || (destino.x + acrescimo_x < 0))
            acrescimo_x = -acrescimo_x;
    destino.x += acrescimo_x;
    destino.y += acrescimo_y;
    fonte.x = (i % bolas_quadros) * bola_largura;
    SDL_BlitSurface(bolas, &fonte, tela, &destino);
    SDL_UpdateRect(tela, 0, 0, 0, 0);
    SDL_Delay(20);
    }
    SDL_Quit();
}
