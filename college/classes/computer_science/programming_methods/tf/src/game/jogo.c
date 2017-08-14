#include"engine.h"
#include"grafico.h"



extern int saida;
extern int DINHEIRO;
extern int COMIDA;
extern int FASE;
extern int hp_inim_1,hp_inim_2,hp_inim_3;
extern int CARREGAR;

int main(){
     
    Unidade* ninja = NULL;
    Unidade* mago = NULL;
    Unidade* feiticeira = NULL;
    
    Unidade* inim1 = NULL;
    Unidade* inim2 = NULL;
    Unidade* inim3 = NULL;
    Unidade* boss = NULL;
    
    ninja = inicia_unidade(1,1,6,2,1,410,160,13);
    mago = inicia_unidade(1,1,1,4,1,280,190,20);
    feiticeira = inicia_unidade(1,1,5,4,1,340,185,17);
    inim1 = inicia_unidade(1,1,1,0,0,350,5,14);
    inim2 = inicia_unidade(1,1,1,0,0,300,7,14);
    inim3 = inicia_unidade(1,1,1,0,0,250,15,14);
    boss = inicia_unidade(1,1,1,0,0,9999,120,60);
    
    Unidade* cabeca = (Unidade*) malloc(7*sizeof(Unidade));
    
    cabeca = cria_cabeca(cabeca,0, ninja);
    cabeca = cria_cabeca(cabeca,1, mago);
    cabeca = cria_cabeca(cabeca,2, feiticeira);
    cabeca = cria_cabeca(cabeca,3, inim1);
    cabeca = cria_cabeca(cabeca,4, inim2);
    cabeca = cria_cabeca(cabeca,5, inim3);
    cabeca = cria_cabeca(cabeca,6, boss);
    
    initscr();
    
    /*SDL*/
    SDL_Init(SDL_INIT_AUDIO); /*inicia SDL*/
    Mix_Music* music = NULL; /*variavel da musica*/
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ); /*inicia audio*/
    music = Mix_LoadMUS( "sounds/Lego.wav" );/*load na musica*/
    Mix_PlayMusic( music,-1); /*toca musica*/
    /**/
    
    DINHEIRO = 10;
    COMIDA = 40;
    CARREGAR=0;
    FASE=1;
   
    cabeca = menu_principal(cabeca);    
    
    /** FASE 1*/
    if((saida!=1 && CARREGAR==0) || (saida!=1 && CARREGAR==1 && FASE==0)){
      FASE = 1; 
      cabeca = ajuste_hp_inim(cabeca,1);
      cabeca = game(cabeca);
    }
   
    /** FASE 2*/
    if((saida!=1 && CARREGAR==0) || (saida!=1 && CARREGAR==1 && FASE==1)){
      FASE = 2;
      cabeca = ajuste_hp_inim(cabeca,2);
      cabeca = upgrade_inimigo(cabeca, 1);
      cabeca = ajuste_hp_inim(cabeca,1);      
      cabeca = game(cabeca);
     }
    
    /** FASE 3*/
    
      if((saida!=1 && CARREGAR==0) || (saida!=1 && CARREGAR==1 && FASE==2)){
	FASE = 3;
        cabeca = ajuste_hp_inim(cabeca,2);
        cabeca = upgrade_inimigo(cabeca, 1);
        cabeca = ajuste_hp_inim(cabeca,1);
      
        cabeca = game(cabeca);
      }
    
    /** FASE 4*/
    if((saida!=1 && CARREGAR==0) || (saida!=1 && CARREGAR==1 && FASE==3)){
      FASE = 4;      
      cabeca = ajuste_hp_inim(cabeca,2);
      cabeca = upgrade_inimigo(cabeca, 1);
      cabeca = ajuste_hp_inim(cabeca,1);
      
      
      cabeca = upgrade_inimigo(cabeca, 2);
      cabeca = ajuste_hp_inim(cabeca,1);
      
      cabeca = game(cabeca);
      
      cabeca = ajuste_hp_inim(cabeca,2);
      cabeca = upgrade_inimigo(cabeca, 3);
      cabeca = ajuste_hp_inim(cabeca,1);
    }
    
    /** FASE 5*/
    if((saida!=1 && CARREGAR==0) || (saida!=1 && CARREGAR==1 && FASE==4)){
      FASE = 5;
      cabeca = upgrade_inimigo(cabeca, 1);
      cabeca = ajuste_hp_inim(cabeca,1);
      
      cabeca = game(cabeca);
    }
    
    /** FASE 6*/
    if((saida!=1 && CARREGAR==0) || (saida!=1 && CARREGAR==1 && FASE==5)){
      FASE = 6;
      cabeca = ajuste_hp_inim(cabeca,2);
      cabeca = upgrade_inimigo(cabeca, 1);
      cabeca = ajuste_hp_inim(cabeca,1);
      
      cabeca = game(cabeca);
    }
    
    /** FASE 7*/
    if((saida!=1 && CARREGAR==0) || (saida!=1 && CARREGAR==1 && FASE==6)){
      FASE = 7;
      cabeca = ajuste_hp_inim(cabeca,2);
      cabeca = upgrade_inimigo(cabeca, 1);
      cabeca = ajuste_hp_inim(cabeca,1);
      
      cabeca = game(cabeca);
    }
    
    /** FASE 8*/
    if((saida!=1 && CARREGAR==0) || (saida!=1 && CARREGAR==1 && FASE==7)){
      FASE = 8;
      cabeca = ajuste_hp_inim(cabeca,2);
      cabeca = upgrade_inimigo(cabeca, 1);
      cabeca = ajuste_hp_inim(cabeca,1);
      
      
      cabeca = upgrade_inimigo(cabeca, 4);
      cabeca = ajuste_hp_inim(cabeca,1);
      
      cabeca = game(cabeca);
      
      cabeca = ajuste_hp_inim(cabeca,2);
      cabeca = upgrade_inimigo(cabeca, 5);
      cabeca = ajuste_hp_inim(cabeca,1);
    }
    
    /** FASE 9*/
    if((saida!=1 && CARREGAR==0) || (saida!=1 && CARREGAR==1 && FASE==8)){
      FASE = 9;
      cabeca = upgrade_inimigo(cabeca, 1);
      cabeca = ajuste_hp_inim(cabeca,1);
      
      cabeca = game(cabeca);
    }
    
    
    /** FASE 10*/
    if((saida!=1 && CARREGAR==0) || (saida!=1 && CARREGAR==1 && FASE==9)){
      FASE = 10;
      cabeca = game(cabeca);
    }
    
    endwin();

    /*SDL*/
    if( Mix_PlayingMusic()!=0)
      Mix_HaltMusic();
    Mix_FreeMusic( music ); /*libera memoria da musica*/
    Mix_CloseAudio(); /*fecha mixer*/
    SDL_Quit(); /*sai do sdl*/
    /**/
    
    libera_memoria(ninja);
    libera_memoria(mago);
    libera_memoria(feiticeira);
    libera_memoria(inim1);
    libera_memoria(inim2);
    libera_memoria(inim3);


    return 0;
  
}  