#include"engine.h"
#include"grafico.h"

extern int saida;
extern int DINHEIRO;
extern int COMIDA;
extern int FASE;
extern int hp_inim_1,hp_inim_2,hp_inim_3;
extern int CARREGAR;


/***********************************ENGINE******************************************/

Unidade* inicia_unidade(int y,int x,int vel,int ang, int pang,int life,int damage,int dist_tiro)
{   
    /* //assertivas*/ 
    ////assert(y>0 && y<=LINES);
    ////assert(x>0 && y<=COLS);
    //assert(vel>0);
    //assert(ang>=0);
    //assert(pang>=0 && pang<=2);
    //assert(life>=0);
    //assert(damage>0);
    ////assert(dist_tiro>0 && dist_tiro<COLS);
    
    
    Unidade* novo = (Unidade*) malloc(sizeof(Unidade));
    novo->y = y;
    novo->x = x;
    novo->velocidade = vel;
    novo->qtd_angulo = ang;
    novo->pangular = pang;
    novo->vida = life;
    novo->dano = damage;
    novo->dist_tiro = dist_tiro;
    return novo;
}  



void libera_memoria(Unidade* unity)
{        
    free(unity);
}

Unidade* menu_principal(Unidade* cabeca)
{
   /* //assertivas*/ 
    //assert(cabeca!=NULL);
    
    int i;
    FILE* fp;
    char* choices[] = { 
			"Novo Jogo",
			"Carregar jogo",
			"Sair",
		  };


    
    int choice; 
    clear();
    noecho();
    cbreak();   /** Buffer de linha desabilitado. Passando em tudo.*/

    /** Inicia cor */
    start_color();	
    init_pair(1, COLOR_BLACK, COLOR_WHITE);

    /**Retira cursor piscando */
    curs_set(0);
    
    attron(COLOR_PAIR(1));

    /** criacao da tela que possui os personagens.*/
    WINDOW* imtela = newwin(12,65,LINES - 13,COLS/2 - 33);

    mostra_heroi(imtela,1,1,0);
    apaga_personagem(imtela,1,13);
    mostra_heroi(imtela,1,25,1);
    apaga_personagem(imtela,1,37);
    mostra_heroi(imtela,1,49,2);
    
    /** criacao da tela com o nome do jogo*/
    WINDOW* imnome = newwin(10,60,LINES/2 - 20,COLS/2 -30);
    printa_nome(imnome,1,1);
    
    /** criacao da tela de instrucoes*/
    WINDOW* iminstrucao = newwin(13,40,LINES/2 -7,COLS/2);
    printa_instrucoes(iminstrucao,1,1);
    
        
    
    refresh();
    wrefresh(imtela);
    wrefresh(imnome);
    wrefresh(iminstrucao);
    
    
    choice = cria_menu(5,16,17,10,choices,3);
    
    attroff(COLOR_PAIR(1));

    apaga_janela(imtela);
    apaga_janela(imnome);
    apaga_janela(iminstrucao);


    if(choice==1)
    {   
      saida=0;
    }else if(choice==2)
    {  
      fp = fopen("saves/saveatual.txt", "r+");
      if (fp == NULL) {
        WINDOW* imcarregar = newwin(3,32,LINES/2-1,COLS/2 - 15);
	box(imcarregar, 0, 0);
	mvwprintw(imcarregar,1,1,"     Não existe save atual     ");
	wrefresh(imcarregar);
	getchar();
	wborder(imcarregar, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	apaga_janela(imcarregar);
        cabeca = menu_principal(cabeca);
      }else{
	CARREGAR=1;
        for(i=0;i<7;i++){
	  fscanf(fp,"%d %d %d %d %d %d %d %d\n",&cabeca[i].y,&cabeca[i].x,&cabeca[i].velocidade,
	    &cabeca[i].qtd_angulo,&cabeca[i].pangular,&cabeca[i].vida,&cabeca[i].dano,&cabeca[i].dist_tiro);
	}
        fscanf(fp,"%d\n",&DINHEIRO);
	fscanf(fp,"%d\n",&COMIDA);
	fscanf(fp,"%d\n",&FASE);
	fscanf(fp,"%d %d %d\n",&hp_inim_1,&hp_inim_2,&hp_inim_3);
	fclose(fp);
      }
    }else if(choice==3)
    {
      saida=1;
    }
    return cabeca;
}

Unidade* game(Unidade* cabeca)
{
  /* //assertivas*/ 
  //assert(cabeca!=NULL);
  
  int y_hero,x_hero,y_ang,x_ang,y_inim,x_inim;
  int unidade;
  int ch,pang_atual;
  int INIM_NA_MIRA;
  int ITERADOR;
  int IND_INIM;
  int TAM_INIM;
  
  INIM_NA_MIRA = 3;
  ITERADOR=-1;
  saida=1;
 
    
  /** JANELA DE STATUS*/
  
  WINDOW* statuswin = newwin(LINES-1,COLS-1,1,1);
 
  printa_status(statuswin,1,COLS/2 - 20,cabeca,0);
  printa_status(statuswin,LINES - 21,3,cabeca,1);
  printa_status(statuswin,LINES - 21,COLS - 42,cabeca,2);
  
  wrefresh(statuswin);
  
  
  /**Escolha do heroi */
  char* escolha_heroi[] = { 
			"Ninja das Montanhas",
			"Mago",
			"Feiticeira",
		  };
		  

  unidade = cria_menu(5,21,LINES/2 + 4,COLS/2 - 11,escolha_heroi,3) -1;
  
  apaga_janela(statuswin);
  

    /** JANELA DO HEROI*/
  WINDOW* herowin = newwin(LINES-3,COLS-2,3,1);
  keypad(herowin, TRUE);
  wrefresh(herowin);

  curs_set(0);
   
  /** JANELA DA POSIÇÂO DO ANGULO E TIRO*/
  WINDOW* angwin = newwin(LINES-3,COLS-2,3,1);
     
  /** JANELA DO HP*/
  WINDOW* HPwin = newwin(3,COLS-2,0,1);
  
  /** JANELA DOS INIMIGOS*/
  WINDOW* inimwin = newwin(LINES-3,COLS-2,3,1);
  
  if(FASE!=10){ 
    mostra_inimigo(inimwin,1,COLS-20);
    IND_INIM = 3;
    TAM_INIM = 12;
  }else if(FASE==10){
    printa_boss(inimwin,COLS - 45);
    IND_INIM = 6;
    TAM_INIM = 39;
  }
  
  mostra_heroi(herowin,1,4,unidade);
  
  mvwprintw(angwin,6,18,"o");
  
  wrefresh(angwin);

  mostra_HP(HPwin,cabeca,unidade);

  int VEL = cabeca[unidade].velocidade;
  
  int VEL_INIM = cabeca[IND_INIM].velocidade;  
  
  wrefresh(inimwin);
  
  getyx(inimwin, y_inim, x_inim);
  
  /** arrumar angulo por fase*/
  cabeca[0].pangular = 1;
  cabeca[1].pangular = 1;
  cabeca[2].pangular = 1;
    
  while(cabeca[unidade].vida>0 && x_inim > (TAM_INIM + VEL_INIM) && COMIDA>0 && (ch = wgetch(herowin)) != 27)
  {
    
    getyx(angwin,y_ang,x_ang);
    getyx(herowin, y_hero, x_hero);
    getyx(inimwin, y_inim, x_inim);
    
    cabeca[unidade].y = y_hero;
    cabeca[unidade].x = x_hero;
    /** usado para localização dos inimigos*/
    cabeca[IND_INIM].y = y_inim; 
    cabeca[IND_INIM].x = x_inim;

    switch(ch)
    {
      case KEY_LEFT:
        if(x_hero>18){
	  apaga_personagem(herowin,y_hero-8,x_hero-12);
          mostra_heroi(herowin,y_hero-8,x_hero-12-VEL,unidade);
          mostra_pangular(angwin,y_ang,x_ang,-VEL,MOVEX);
	}
      break;
      case KEY_RIGHT:
        if(x_hero<COLS-9-VEL){
	  apaga_personagem(herowin,y_hero-8,x_hero-12);
          mostra_heroi(herowin,y_hero-8,x_hero-12 + VEL,unidade);
          mostra_pangular(angwin,y_ang,x_ang,VEL,MOVEX);
	}
      break;
      case KEY_UP:
	if(INIM_NA_MIRA!=3){
          apaga_personagem(herowin,y_hero-8,x_hero-12);
          mostra_heroi(herowin,y_hero-18,x_hero-12,unidade);
          mostra_pangular(angwin,y_ang,x_ang,-10,MOVEY);
	  INIM_NA_MIRA--;
	}  
      break;
      case KEY_DOWN:
	if(INIM_NA_MIRA!=5){
          apaga_personagem(herowin,y_hero-8,x_hero-12);
          mostra_heroi(herowin,y_hero+2,x_hero-12,unidade);
          mostra_pangular(angwin,y_ang,x_ang,10,MOVEY);
          INIM_NA_MIRA++;
        }  
        break;
      case 119: /** mudar o angulo de ataque*/
        cabeca = troca_pangular(angwin,y_ang,x_ang,cabeca,unidade);
        wrefresh(angwin);
        mostra_heroi(herowin,y_hero-8,x_hero-12,unidade);
        break;
      case 101: /** trocar presonagem*/
        pang_atual = cabeca[unidade].pangular; 
	unidade = (unidade+1)%3;
	cabeca[unidade].pangular = pang_atual;
        apaga_personagem(herowin,y_hero-8,x_hero-12);
        mostra_heroi(herowin,y_hero-8,x_hero-12,unidade);
        wrefresh(herowin);
        mostra_HP(HPwin,cabeca,unidade);
        VEL = cabeca[unidade].velocidade;
        break;
      case 32: /** atirar*/
        cabeca = tira_vida_ini(cabeca,x_hero,x_inim-TAM_INIM,INIM_NA_MIRA,unidade);
	printa_tiro(angwin,y_ang,x_ang,cabeca,unidade);
        if(cabeca[unidade].pangular==1) mvwprintw(angwin,y_ang,x_ang-1,"o");
        if(cabeca[unidade].pangular==2) mvwprintw(angwin,y_ang,x_ang-1,"o");
        wrefresh(angwin);
        if((FASE!=10)){
	  if(cabeca[3].vida==0)  apaga_personagem(inimwin,1,x_inim-12);
          if(cabeca[4].vida==0)  apaga_personagem(inimwin,11,x_inim-12);
          if(cabeca[5].vida==0)  apaga_personagem(inimwin,21,x_inim-12);
	}  
        wrefresh(inimwin);
        mostra_HP(HPwin,cabeca,unidade);
        break;
    }
  
    
    getyx(herowin, y_hero, x_hero);
    
    if(ITERADOR%2==0){
        cabeca = tira_vida_heroi(cabeca,unidade,x_hero,x_inim-TAM_INIM);
        if(FASE!=10){
          apaga_inimigo(inimwin,1,x_inim-TAM_INIM);
          mostra_inimigo(inimwin,1,x_inim-TAM_INIM - VEL_INIM);
          if(cabeca[3].vida==0)  apaga_personagem(inimwin,1,x_inim-12 - VEL_INIM);
          if(cabeca[4].vida==0)  apaga_personagem(inimwin,11,x_inim-12 - VEL_INIM);
          if(cabeca[5].vida==0)  apaga_personagem(inimwin,21,x_inim-12 - VEL_INIM);
        }else if(FASE==10 && ITERADOR%4==0){
	  apaga_inimigo(inimwin,((LINES-3)/2)-15,x_inim-TAM_INIM);
	  printa_boss(inimwin,x_inim-TAM_INIM - VEL_INIM);
        }
        wrefresh(inimwin);
        mostra_HP(HPwin,cabeca,unidade);
        COMIDA++;
    }
    
    COMIDA--;
    
    ITERADOR++;
    if(FASE!=10){ /**matou inimigos*/
      if((cabeca[3].vida==0 && cabeca[4].vida==0 && cabeca[5].vida==0)){
       saida=2; /**sai para a tela de upgrades*/
       break;
      } 
    }else if(FASE==10){
      if(cabeca[6].vida==0){ /**matou chefão*/
	saida=-1; /**sai do jogo*/
	break;
      }
    }
  }
  
  apaga_janela(herowin);
    
  apaga_janela(angwin);

  apaga_janela(HPwin);
  
  apaga_janela(inimwin);
  
  if(saida==1 && ch!=27){
    mvprintw(LINES/2-1,COLS/2-5,"GAME OVER");
    refresh();
    ch = getch();
  }else if(saida==2){
    cabeca = tela_upgrades(cabeca);   
  }
  
  
  
  
  return cabeca;
}

Unidade* cria_cabeca(Unidade* vet,int pos, Unidade* uni)
{
  /* //assertivas*/ 
  //assert(pos>=0 && pos<=6);
  //assert(uni!=NULL);
  
  vet[pos].y = uni->y;
  vet[pos].x = uni->x;
  vet[pos].velocidade = uni->velocidade;
  vet[pos].qtd_angulo = uni->qtd_angulo;
  vet[pos].pangular = uni->pangular;
  vet[pos].vida = uni->vida;
  vet[pos].dano = uni->dano;
  vet[pos].dist_tiro = uni->dist_tiro;

  return vet;
  
} 

Unidade* tira_vida_ini(Unidade* cabeca,int x_hero,int x_inimigo,int INIM_NA_MIRA, int unidade)
{
  /* //assertivas*/ 
  //assert(cabeca!=NULL);
  ////assert(x_hero>0 && x_hero<=COLS);
  ////assert(x_inimigo>0 && x_inimigo<=COLS);
  //assert(INIM_NA_MIRA>=3 && INIM_NA_MIRA<=5);
  //assert(unidade>=0 && unidade<=2);
  
  int IND_INIM,dano;  
  if(FASE==10){
    IND_INIM=6;
    dano = tira_vida_boss(unidade,cabeca);
  }else if(FASE!=10){
    IND_INIM=INIM_NA_MIRA;
    dano = dano_relativo(cabeca,unidade);
  }
  
  
    if(range_dist_maxima(x_hero,x_inimigo,cabeca,unidade,unidade))
    {  
	 if(cabeca[IND_INIM].vida > dano){
	   cabeca[IND_INIM].vida=cabeca[IND_INIM].vida - dano;
	 }else{
	    if(cabeca[IND_INIM].vida!=0) DINHEIRO = DINHEIRO + 30 + (cabeca[IND_INIM].vida)/100;
	    cabeca[IND_INIM].vida=0;
	 }  
     }
  return cabeca;
}

int range_dist_maxima(int x_heroi,int x_ini,Unidade* cabeca,int unidade,int ind_range)
{
    /* //assertivas*/ 
  //assert(cabeca!=NULL);
  ////assert(x_heroi>0 && x_heroi<=COLS);
  ////assert(x_ini>0 && x_ini<=COLS);
  //assert(ind_range>=0 && ind_range<=5);
  //assert(unidade>=0 && unidade<=2);
  
  
  int TAM_REL_INIM;
  int range = cabeca[ind_range].dist_tiro;
  
  if(FASE!=10){
    TAM_REL_INIM = 6;
  }else if (FASE==10){
    TAM_REL_INIM = 19;
  }
  
  if(ind_range==unidade){
    if (cabeca[unidade].pangular==1){
      if((x_ini-x_heroi>0 && x_ini-x_heroi<range) || (x_heroi-x_ini>0 && x_heroi-x_ini<TAM_REL_INIM)){
        return 1;
      }  
    }else if(cabeca[unidade].pangular==2){
      x_heroi = x_heroi -12;
      x_ini = x_ini + 2*TAM_REL_INIM;
      if((x_heroi-x_ini>0 && x_heroi-x_ini<range) || (x_ini-x_heroi>0 && x_ini-x_heroi<TAM_REL_INIM)){
        return 1;
      }
    }
  }else{
    if(((x_ini-x_heroi>0 && x_ini-x_heroi<range) || (x_heroi-x_ini>0 && x_heroi-x_ini<TAM_REL_INIM)) || 
      ((x_heroi-x_ini>0 && x_heroi-x_ini<range) || (x_ini-x_heroi>0 && x_ini-x_heroi<TAM_REL_INIM)))
        return 1;
  }
  return 0;
}

Unidade* tira_vida_heroi(Unidade* cabeca,int unidade,int x_heroi,int x_inimigo)
{
      /* //assertivas*/ 
  //assert(cabeca!=NULL);
  ////assert(x_heroi>0 && x_heroi<=COLS);
  ////assert(x_inimigo>0 && x_inimigo<=COLS);
  //assert(unidade>=0 && unidade<=2);
  
  int i,IND_INIM;
  if(FASE==10){
    IND_INIM=6;
  }else if(FASE!=10){
    IND_INIM=3;
  }
  
  
  if(range_dist_maxima(x_heroi,x_inimigo,cabeca,unidade,IND_INIM)){
    if(FASE!=10){
      for(i=3;i<6;i++){
        if(cabeca[i].vida != 0){
          cabeca[unidade].vida = cabeca[unidade].vida - cabeca[i].dano;     
        }
      }
    }else if(FASE==10){
       cabeca[unidade].vida = cabeca[unidade].vida - cabeca[IND_INIM].dano;
    }
  }
  return cabeca;
}

int dano_relativo(Unidade* cabeca,int unidade)
{
      /* //assertivas*/ 
  //assert(cabeca!=NULL);
  //assert(unidade>=0 && unidade<=2);
  
  int dano;
  int n = rand()%30 + 1;
 
  dano = cabeca[unidade].dano;
  if(cabeca[unidade].pangular==2){
    dano = dano + n;
  }
  return dano;
}

int tira_vida_boss(int unidade, Unidade* cabeca)
{
        /* //assertivas*/ 
  //assert(cabeca!=NULL);
  //assert(unidade>=0 && unidade<=2);
  
  int dano;
  
  if(unidade==0){
    dano = cabeca[0].dano;
  }else if(unidade==1){
    dano = (cabeca[1].dano/( rand()%3 + 1));
  }else if(unidade==2){
    dano = (cabeca[1].dano/(rand()%2 + 1));
  }
  
  if(cabeca[unidade].pangular==2) dano = dano + rand()%30 + 1;
  return dano;
}

Unidade* tela_upgrades(Unidade* cabeca)
{
        /* //assertivas*/ 
  //assert(cabeca!=NULL);
  
  FILE* fp;
  int i;
  char* escolha_upgrade[] = { 
			"R$ 80  Upgrade prédio do ninja das montanhas ",
			"R$ 80  Upgrade prédio do mago",
			"R$ 80  Upgrade prédio da feiticeira",
			"R$ 30  Comprar comida",
			"Salvar",
			"Próxima fase",
		  };
  
  
  
  int upgrade=0;
  
  if(FASE==9){
    COMIDA+=60;
    DINHEIRO+=240;
  }
  
  WINDOW* casaswin = newwin(LINES-1,COLS-1,1,1);
  printa_casas(casaswin);
  wrefresh(casaswin);
  
  
  while(upgrade!=6){
    upgrade = cria_menu(10,COLS-2,LINES-11,1,escolha_upgrade,6);
    switch(upgrade){
      case 1:
        if(DINHEIRO>=80){
          DINHEIRO = DINHEIRO -80;
	  cabeca[0].velocidade = cabeca[0].velocidade + 2;
          cabeca[0].vida = cabeca[0].vida + 85;
	  cabeca[0].dano = cabeca[0].dano + 21;
	  cabeca[0].dist_tiro = cabeca[0].dist_tiro + 4;
	  
	  mvwprintw(casaswin,23,COLS-20,"               ");
	  mvwprintw(casaswin,23,COLS-20,"DINHEIRO: %d",DINHEIRO);
	}
        break;
      case 2:
	if(DINHEIRO>=80){
	  DINHEIRO = DINHEIRO -80;
	  cabeca[1].velocidade = cabeca[1].velocidade + 1;
          cabeca[1].vida = cabeca[1].vida + 47;
	  cabeca[1].dano = cabeca[1].dano + 24;
	  cabeca[1].dist_tiro = cabeca[1].dist_tiro + 7;
	  
	  mvwprintw(casaswin,23,COLS-20,"               ");
	  mvwprintw(casaswin,23,COLS-20,"DINHEIRO: %d",DINHEIRO);
	}
        break;
      case 3:
	if(DINHEIRO>=80){
	  DINHEIRO = DINHEIRO -80;
	  cabeca[2].velocidade = cabeca[2].velocidade + 1;
          cabeca[2].vida = cabeca[2].vida + 54;
	  cabeca[2].dano = cabeca[2].dano + 22;
	  cabeca[2].dist_tiro = cabeca[2].dist_tiro + 5;
	  
	  mvwprintw(casaswin,23,COLS-20,"               ");
	  mvwprintw(casaswin,23,COLS-20,"DINHEIRO: %d",DINHEIRO);
	}
        break;
      case 4:
        if(DINHEIRO>=30){
	  DINHEIRO = DINHEIRO -30;
          COMIDA = COMIDA + 30;
	
	  mvwprintw(casaswin,23,1,"            ");
	  mvwprintw(casaswin,23,1,"COMIDA: %d",COMIDA);
	  mvwprintw(casaswin,23,COLS-20,"               ");
	  mvwprintw(casaswin,23,COLS-20,"DINHEIRO: %d",DINHEIRO);
	}  
        break;
      case 5:
	/**salvar*/
	fp = fopen("saves/saveatual.txt", "w");
	for(i=0;i<7;i++){
	  fprintf(fp,"%d %d %d %d %d %d %d %d\n",cabeca[i].y,cabeca[i].x,cabeca[i].velocidade,
	    cabeca[i].qtd_angulo,cabeca[i].pangular,cabeca[i].vida,cabeca[i].dano,cabeca[i].dist_tiro);
	}
        fprintf(fp,"%d\n",DINHEIRO);
	fprintf(fp,"%d\n",COMIDA);
	fprintf(fp,"%d\n",FASE);
	fprintf(fp,"%d %d %d\n",hp_inim_1,hp_inim_2,hp_inim_3);
	
	fclose(fp);
	break;
    }

    wrefresh(casaswin);
  }  
  
  apaga_janela(casaswin);
  return cabeca;
}  

Unidade* upgrade_inimigo(Unidade*cabeca, int tipo)
{
        /* //assertivas*/ 
  //assert(cabeca!=NULL);
  //assert(tipo>=1 && tipo<=5);
  
  int i;
  /**upgrade comum*/
  if(tipo==1){
    for(i=3;i<6;i++){
      cabeca[i].velocidade = cabeca[i].velocidade+1;
      cabeca[i].vida = cabeca[i].vida+65 ;
      cabeca[i].dano = cabeca[i].dano+2;
      cabeca[i].dist_tiro = cabeca[i].dist_tiro+3;
    }
  /**upgrade fast*/
  }else if(tipo==2){
    for(i=3;i<6;i++){
      cabeca[i].velocidade = cabeca[i].velocidade+7;
      cabeca[i].vida = cabeca[i].vida-150;
    }
   /**downgrade fast*/ 
  }else if(tipo==3){
    for(i=3;i<6;i++){
      cabeca[i].velocidade = cabeca[i].velocidade-7;
      cabeca[i].vida = cabeca[i].vida+150;
    }
  /**upgrade strong*/ 
  }else if(tipo==4){
    for(i=3;i<6;i++){
      cabeca[i].velocidade = cabeca[i].velocidade-5;
      cabeca[i].vida = cabeca[i].vida+500;
    }
  /**downgrade strong*/  
  }else if(tipo==5){
    for(i=3;i<6;i++){
      cabeca[i].velocidade = cabeca[i].velocidade+5;
      cabeca[i].vida = cabeca[i].vida-500;
    }
  }  
  return cabeca;
}

Unidade* ajuste_hp_inim(Unidade* cabeca, int tipo)
{
        /* //assertivas*/ 
  //assert(cabeca!=NULL);
  //assert(tipo==1 || tipo==2);
  
  /** atualiza variaveis globais */
  if(tipo==1){
    hp_inim_1 = cabeca[3].vida;
    hp_inim_2 = cabeca[4].vida;
    hp_inim_3 = cabeca[5].vida;
   /** atualiza a struct*/ 
  }else if(tipo==2){
    cabeca[3].vida = hp_inim_1;
    cabeca[4].vida = hp_inim_2;
    cabeca[5].vida = hp_inim_3;
  }
  return cabeca;
  
}

/************************************FIM*******************************************/

