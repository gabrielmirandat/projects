#include"engine.h"
#include"grafico.h"

extern int saida;
extern int DINHEIRO;
extern int COMIDA;
extern int FASE;
extern int hp_inim_1,hp_inim_2,hp_inim_3;
extern int CARREGAR;


/***********************************GRAFICOS******************************************/

void printa_nome(WINDOW *local_win,int yrel,int xrel)
{
         /* //assertivas*/ 
  //assert(local_win!=NULL);
  ////assert(yrel>=0 && yrel<=LINES);
  ////assert(xrel>=0 && xrel<=COLS);
  
  mvwprintw(local_win,yrel+0,xrel,"                     )          )                    ");
  mvwprintw(local_win,yrel+1,xrel,"        (         ( /(   (   ( /(      (      (      ");
  mvwprintw(local_win,yrel+2,xrel," `  )   )(    (   )\\()) ))\\  )\\()) (   )(    ))\\ (   ");
  mvwprintw(local_win,yrel+3,xrel," /(/(  (()\\   )\\ (_))/ /((_)(_))/  )\\ (()\\  /((_))\\  ");
  mvwprintw(local_win,yrel+4,xrel,"((_)_\\  ((_) ((_)| |_ (_))  | |_  ((_) ((_)(_)) ((_) ");
  mvwprintw(local_win,yrel+5,xrel,"| '_ \\)| '_|/ _ \\|  _|/ -_) |  _|/ _ \\| '_|/ -_)(_-< ");
  mvwprintw(local_win,yrel+6,xrel,"| .__/ |_|  \\___/ \\__|\\___|  \\__|\\___/|_|  \\___|/__/ ");
  mvwprintw(local_win,yrel+7,xrel,"|_|                                                  ");
}


void printa_casas(WINDOW *local_win)
{
          /* //assertivas*/ 
  //assert(local_win!=NULL);
   
  mvwprintw(local_win,12,1,"           _____________________           ");
  mvwprintw(local_win,13,1,"          /<3<3<3<3<3<3<3<3<3<3<3\\        ");
  mvwprintw(local_win,14,1,"         /<3<3<3<3<3<3<3<3<3<3<3<3\\       ");
  mvwprintw(local_win,15,1,"        ||____________**_______***||   () ");
  mvwprintw(local_win,16,1,"        ||_| ^   ^ |_|**|     |***||  ()()");
  mvwprintw(local_win,17,1,"        ||_|(=ºoº=)|_|**|     |  @||  ()()");
  mvwprintw(local_win,18,1,"        ||_|___u___|_|**|    >| @@||  ()()");
  mvwprintw(local_win,19,1,"  mmmmmm||______________|_____|\\_/||mm\\__/m");
  mvwprintw(local_win,21,1,"         vel+1 hp+54 dano+22 range+5       ");   

  mvwprintw(local_win,1,1,"     /\\     _______________(___(          ");
  mvwprintw(local_win,2,1,"      /\\\\  /\\              (  ( \\  /\\ ");
  mvwprintw(local_win,3,1,"   /\\/  \\ /  \\       ____   (_)  \\/  \\");
  mvwprintw(local_win,4,1,"  /  \\   /____\\      |[]|   [_]   \\    ");
  mvwprintw(local_win,5,1,"    / \\ /XXXXXX\\_____|__|__________\\  ");
  mvwprintw(local_win,6,1,"    /\\  I_I|  |I_I_____[]_|_[]_____I    ");
  mvwprintw(local_win,7,1,"        I_II  II_I_____[]_|_[]_____I    ");
  mvwprintw(local_win,8,1,"~~~~~~~~I_II__II_I     XXXXXXX     I~~~~");
 mvwprintw(local_win,10,1,"       vel+2 hp+85 dano+21 range+4      ");

  mvwprintw(local_win,1,50," ()   ___/|\\____________________/|\\___   /00)  ");
  mvwprintw(local_win,2,50,"((() /~//|||\\_(||\\ ~ __~~ /||)_/|||\\~ \\ /  /__ ");
  mvwprintw(local_win,3,50,")() /~ /|||||\\~ ~~  /||\\  ~~ ~/|||||\\~ /  //00)");
  mvwprintw(local_win,4,50,"()(/~~/|/ | \\|\\ ~~ /||||\\ ~~ /|/ | \\|\\VvVv/  / ");
  mvwprintw(local_win,5,50,"())) /||)_|_(||\\  /||||||\\  /||)_|_(||\\ (/  /  ");
  mvwprintw(local_win,6,50,"() )||_)|_|_|(_||||/====\\||||_)|_|_|(_||VvVv   ");
  mvwprintw(local_win,7,50,"|_@|||||||||||||||| |++| ||||||||||||||||@_|   ");
  mvwprintw(local_win,8,50,"|_@@ @@@ @@@ @@@ @@@|++|@@@ @@@ @@@ @@@ @@_|   ");
 mvwprintw(local_win,10,50,"          vel+1 hp+47 dano+24 range+7          ");
  
  mvwprintw(local_win,12,50,"  ___  ___  ___  ___  ___.---------------.     ");
  mvwprintw(local_win,13,50,".'\\__\\'\\__\\'\\__\\'\\__\\'\\__,`   .  ____ ___ \\    ");
  mvwprintw(local_win,14,50,"|\\/ __\\/ __\\/ __\\/ __\\/ _:\\   |`.  \\  \\___ \\   ");
  mvwprintw(local_win,15,50," \\'\\__\\'\\__\\'\\__\\'\\__\\'\\_`.__|""`. \\  \\___ \\  ");
  mvwprintw(local_win,16,50,"  \\/ __\\/ __\\/ __\\/ __\\/ __:                \\ ");
  mvwprintw(local_win,17,50,"   \\'\\__\\'\\__\\'\\__\\ \\__\\'\\_;-----------------`");
  mvwprintw(local_win,18,50,"    \\/   \\/   \\/   \\/   \\/ :               hh|");
  mvwprintw(local_win,19,50,"     \\|______________________;________________|");
  mvwprintw(local_win,21,50,"                   comida+30                   ");   
  
  mvwprintw(local_win,23,1,"COMIDA: %d",COMIDA);
  mvwprintw(local_win,23,COLS-20,"DINHEIRO: %d",DINHEIRO);
 
}

void mostra_heroi(WINDOW *local_tela, int yrel, int xrel, int tipo)
{
     /* //assertivas*/ 
  //assert(local_tela!=NULL);
  ////assert(yrel>=0 && yrel<=LINES);
  ////assert(xrel>=0 && xrel<=COLS);
  //assert(tipo>=0 && tipo<=2);
  
  if(tipo==0){   
      mvwprintw(local_tela,yrel,xrel,"    __      ");   
    mvwprintw(local_tela,yrel+1,xrel,"   |..|    /");
    mvwprintw(local_tela,yrel+2,xrel,"   |__|  // ");
    mvwprintw(local_tela,yrel+3,xrel,"  --||--//  ");
    mvwprintw(local_tela,yrel+4,xrel,"  ##\\/#//   ");
    mvwprintw(local_tela,yrel+5,xrel,"  \\#||@     ");
    mvwprintw(local_tela,yrel+6,xrel,"   |HH|     ");
    mvwprintw(local_tela,yrel+7,xrel,"   =||=     ");
    mvwprintw(local_tela,yrel+8,xrel,"  <<  >>    ");
  }

  if(tipo==1){   
      mvwprintw(local_tela,yrel,xrel,"     __     ");     
    mvwprintw(local_tela,yrel+1,xrel,"    |..|    ");
    mvwprintw(local_tela,yrel+2,xrel,"    |__|    ");
    mvwprintw(local_tela,yrel+3,xrel,"   /----\\   ");
    mvwprintw(local_tela,yrel+4,xrel,"  |--||--|  ");
    mvwprintw(local_tela,yrel+5,xrel,"  |--HH--|  ");
    mvwprintw(local_tela,yrel+6,xrel,"  |  ||  |  ");
    mvwprintw(local_tela,yrel+7,xrel,"  | =||= |  ");
    mvwprintw(local_tela,yrel+8,xrel,"  --------  ");
  }

  if(tipo==2){   
      mvwprintw(local_tela,yrel,xrel,"    ______  ");
    mvwprintw(local_tela,yrel+1,xrel,"   ((|..|)) ");
    mvwprintw(local_tela,yrel+2,xrel,"   ))|__|(( ");
    mvwprintw(local_tela,yrel+3,xrel,"   (( || )) ");
    mvwprintw(local_tela,yrel+4,xrel,"   /(_,_)\\  ");
    mvwprintw(local_tela,yrel+5,xrel,"   \\\\) (//  ");
    mvwprintw(local_tela,yrel+6,xrel,"    /___\\   ");
    mvwprintw(local_tela,yrel+7,xrel,"     |||    ");
    mvwprintw(local_tela,yrel+8,xrel,"     < >    ");
  }
}


void apaga_personagem(WINDOW *local_tela,int yrel,int xrel)
{
          /* //assertivas*/ 
  //assert(local_tela!=NULL);
  ////assert(yrel>=0 && yrel<=LINES);
  ////assert(xrel>=0 && xrel<=COLS);
  
    mvwprintw(local_tela,yrel,xrel,"            ");   
  mvwprintw(local_tela,yrel+1,xrel,"            ");
  mvwprintw(local_tela,yrel+2,xrel,"            ");
  mvwprintw(local_tela,yrel+3,xrel,"            ");
  mvwprintw(local_tela,yrel+4,xrel,"            ");
  mvwprintw(local_tela,yrel+5,xrel,"            ");
  mvwprintw(local_tela,yrel+6,xrel,"            ");
  mvwprintw(local_tela,yrel+7,xrel,"            ");
  mvwprintw(local_tela,yrel+8,xrel,"            ");
}

void apaga_inimigo(WINDOW *local_tela,int yrel,int xrel)
{
          /* //assertivas*/ 
  //assert(local_tela!=NULL);
  ////assert(yrel>=0 && yrel<=LINES);
  ////assert(xrel>=0 && xrel<=COLS);
    
  int i;
  for(i=0;i<=28;i++){
    mvwprintw(local_tela,yrel+i,xrel,"            ");   
  }
}

void apaga_boss(WINDOW *local_tela,int yrel,int xrel)
{
          /* //assertivas*/ 
  //assert(local_tela!=NULL);
  //assert(yrel>=0 && yrel<=LINES);
  //assert(xrel>=0 && xrel<=COLS);

  int i;
   for(i=0;i<=24;i++){
     mvwprintw(local_tela,yrel+i,xrel,"                                       ");   
   }
}

void apaga_janela(WINDOW *local_win)
{	
          /* //assertivas*/ 
  //assert(local_win!=NULL);

  werase(local_win);
  wrefresh(local_win);
  delwin(local_win);
      
}

void mostra_inimigo(WINDOW *local_tela, int yrel, int xrel)
{
          /* //assertivas*/ 
  //assert(local_tela!=NULL);
  ////assert(yrel>=0 && yrel<=LINES);
  ////assert(xrel>=0 && xrel<=COLS);

     mvwprintw(local_tela,yrel,xrel,"    ___     ");
   mvwprintw(local_tela,yrel+1,xrel,"   /* *\\    ");
   mvwprintw(local_tela,yrel+2,xrel," _|_____|_  ");
   mvwprintw(local_tela,yrel+3,xrel,"| | === | | ");
   mvwprintw(local_tela,yrel+4,xrel,"|_|  O  |_| ");
   mvwprintw(local_tela,yrel+5,xrel," ||  O  ||  ");
   mvwprintw(local_tela,yrel+6,xrel,"|~ \\___/ ~| ");
   mvwprintw(local_tela,yrel+7,xrel,"/=\\ /=\\ /=\\ ");
   mvwprintw(local_tela,yrel+8,xrel,"[_]_[_]_[_] ");
   mvwprintw(local_tela,yrel+9,xrel,"            ");
  mvwprintw(local_tela,yrel+10,xrel,"     /~\\    ");
  mvwprintw(local_tela,yrel+11,xrel,"    |oo )   ");
  mvwprintw(local_tela,yrel+12,xrel,"#   _\\=/_   ");
  mvwprintw(local_tela,yrel+13,xrel,"\\\\//|/.\\|\\\\ ");
  mvwprintw(local_tela,yrel+14,xrel," \\/ |\\ /| ||");
  mvwprintw(local_tela,yrel+15,xrel,"    \\_ _/ # ");
  mvwprintw(local_tela,yrel+16,xrel,"    | | |   "); 
  mvwprintw(local_tela,yrel+17,xrel,"    []|[]   ");
  mvwprintw(local_tela,yrel+18,xrel,"   /_]_[_\\  ");
  mvwprintw(local_tela,yrel+19,xrel,"            ");
  mvwprintw(local_tela,yrel+20,xrel,"    | |     ");
  mvwprintw(local_tela,yrel+21,xrel,"   (O O)    ");
  mvwprintw(local_tela,yrel+22,xrel,"    \\=/     ");
  mvwprintw(local_tela,yrel+23,xrel,"   __||__   ");
  mvwprintw(local_tela,yrel+24,xrel,"  //\\*/\\\\   ");
  mvwprintw(local_tela,yrel+25,xrel,"_///_*_\\\\\\_ ");
  mvwprintw(local_tela,yrel+26,xrel,"@/ || || \\@ "); 
  mvwprintw(local_tela,yrel+27,xrel,"   || ||    ");
  mvwprintw(local_tela,yrel+28,xrel,"`##() ()##  ");
  
}

void printa_instrucoes(WINDOW *local_win,int yrel,int xrel)
{
          /* //assertivas*/ 
  //assert(local_win!=NULL);
  ////assert(yrel>=0 && yrel<=LINES);
  ////assert(xrel>=0 && xrel<=COLS);  
  
   mvwprintw(local_win,yrel+0,xrel," / ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \\ ");
   mvwprintw(local_win,yrel+1,xrel,"|  /~~\\       INSTRUCOES      /~~\\  |");
   mvwprintw(local_win,yrel+2,xrel,"|\\ \\   | (<) move p/ esquerda|   / /|");
   mvwprintw(local_win,yrel+3,xrel,"| \\   /| (>) move p/ direita |\\   / |");
   mvwprintw(local_win,yrel+4,xrel,"|  ~~  | (v) move p/ baixo   |  ~~  |");
   mvwprintw(local_win,yrel+5,xrel,"|      | (^) move p/ cima    |      |");
   mvwprintw(local_win,yrel+6,xrel,"|      | (w) troca angulo    |      |");
   mvwprintw(local_win,yrel+7,xrel,"|      |(esp)atira           |      |");
   mvwprintw(local_win,yrel+8,xrel,"|      | (e) troca personagem|      |");
   mvwprintw(local_win,yrel+9,xrel," \\     |~~~~~~~~~~~~~~~~~~~~~|     / ");
  mvwprintw(local_win,yrel+10,xrel,"  \\   /                       \\   /  ");
  mvwprintw(local_win,yrel+11,xrel,"   ~~~                         ~~~   ");
  
  
}

void printa_status(WINDOW *local_win,int yrel,int xrel,Unidade* cabeca, int unidade)
{
          /* //assertivas*/ 
  //assert(local_win!=NULL);
  ////assert(yrel>=0 && yrel<=LINES);
  ////assert(xrel>=0 && xrel<=COLS);
  //assert(cabeca!=NULL);
  //assert(unidade>=0 && unidade<=2);

  char str[3];
  if(unidade==0){
    strcpy(str,"NM");
  }else if(unidade==1){
    strcpy(str,"MG");
  }else if(unidade==2){
    strcpy(str,"FT");
  }
   
   
   mvwprintw(local_win,yrel+0,xrel,"              .      .               ");
   mvwprintw(local_win,yrel+1,xrel,"         '    }\\    /{    `          ");
   mvwprintw(local_win,yrel+2,xrel,"        / \\   ) \\__/ (   / \\         ");
   mvwprintw(local_win,yrel+3,xrel,"       /   \\  (*\\  /*)  /   \\        ");
   mvwprintw(local_win,yrel+4,xrel,"      /     \\_ \\    / _/     \\       ");
   mvwprintw(local_win,yrel+5,xrel,"     (        \\|\\../|/        )      ");
   mvwprintw(local_win,yrel+6,xrel,"     /         | VV |         \\      ");
   mvwprintw(local_win,yrel+7,xrel,"    /                          \\     ");
   mvwprintw(local_win,yrel+8,xrel,"   /                            \\    ");
   mvwprintw(local_win,yrel+9,xrel,"  (              %s              )   ",str);
  mvwprintw(local_win,yrel+10,xrel,"   \\          VEL:  %02d          /    ",cabeca[unidade].velocidade);
  mvwprintw(local_win,yrel+11,xrel,"  /           HP:   %03d         \\   ",cabeca[unidade].vida);
  mvwprintw(local_win,yrel+12,xrel," /            DANO: %03d          \\  ",cabeca[unidade].dano);
  mvwprintw(local_win,yrel+13,xrel,"/             RANGE:%02d            \\ ",cabeca[unidade].dist_tiro);
  mvwprintw(local_win,yrel+14,xrel,"(                                  ) ");
  mvwprintw(local_win,yrel+15,xrel," |    /\\ /~\\|T|\\/~\\/~\\/T\\/~\\ /\\   |  ");
  mvwprintw(local_win,yrel+16,xrel," |  /   V   '|`   \\\\  '|`   V  \\  | ");
  mvwprintw(local_win,yrel+17,xrel," |/     `          ))       '    \\|  ");
  mvwprintw(local_win,yrel+18,xrel," `                ((              '  ");
  mvwprintw(local_win,yrel+19,xrel,"                   V                 ");

 
}

void printa_boss(WINDOW *local_win, int xrel)
{
          /* //assertivas*/ 
  //assert(local_win!=NULL);
  ////assert(xrel>=0 && xrel<=COLS);

  int yrel = ((LINES-3)/2)-15;
  
  
  mvwprintw(local_win,yrel+ 0,xrel,"      ^                       ^        ");
  mvwprintw(local_win,yrel+ 1,xrel,"      |\\   \\        /        /|        ");
  mvwprintw(local_win,yrel+ 2,xrel,"     /  \\  |\\__  __/|       /  \\       ");
  mvwprintw(local_win,yrel+ 3,xrel,"    / /\\ \\ \\ _ \\/ _ /      /    \\      ");
  mvwprintw(local_win,yrel+ 4,xrel,"   / / /\\ \\ {*}\\/{*}      /  / \\ \\     ");
  mvwprintw(local_win,yrel+ 5,xrel,"   | | | \\ \\( (00) )     /  // |\\ \\    ");
  mvwprintw(local_win,yrel+ 6,xrel,"   | | | |\\ \\ (V""V) \\    /  / | || \\| ");
  mvwprintw(local_win,yrel+ 7,xrel,"   | | | | \\ |^--^| \\  /  / || || ||   ");
  mvwprintw(local_win,yrel+ 8,xrel,"  / / /  | |( WWWW__ \\/  /| || || ||   ");
  mvwprintw(local_win,yrel+ 9,xrel," | | | | | |  \\______\\  / / || || ||   ");
  mvwprintw(local_win,yrel+10,xrel," | | | / | | )|______\\ ) | / | || ||   ");
  mvwprintw(local_win,yrel+11,xrel," / / /  / /  /______/   /| \\ \\ || ||   ");
  mvwprintw(local_win,yrel+12,xrel,"/ / /  / /  /\\_____/  |/ /__\\ \\ \\ \\ \\  ");
  mvwprintw(local_win,yrel+13,xrel,"| | | / /  /\\______/   |  \\\\__| \\ \\  | ");
  mvwprintw(local_win,yrel+14,xrel,"| | | | | |\\______ __   \\   | \\__|_| | ");
  mvwprintw(local_win,yrel+15,xrel,"| | ,___ /\\______ _  _   \\   \\_ _ \\  | ");
  mvwprintw(local_win,yrel+16,xrel,"| |/    /\\_____  /    \\   \\    | \\ \\ | ");
  mvwprintw(local_win,yrel+17,xrel,"|/ |   |\\______ |      |   \\_   \\_\\ || ");
  mvwprintw(local_win,yrel+18,xrel,"v  |   |\\______ |      |     \\      \\| ");
  mvwprintw(local_win,yrel+19,xrel,"   |   |\\______ |      |      \\__      ");
  mvwprintw(local_win,yrel+20,xrel,"    \\   \\________\\_    _\\        \\__   ");
  mvwprintw(local_win,yrel+21,xrel,"  __/   /\\_____ __/   /   )\\_,      \\  ");
  mvwprintw(local_win,yrel+22,xrel," /  ___/  \\uuuu/  ___/___)    \\______\\ ");
  mvwprintw(local_win,yrel+23,xrel," VVV  V        VVV  V                  ");
  
}

void printa_tiro(WINDOW* local_win,int yrel, int xrel, Unidade* cabeca,int unidade)
{
          /* //assertivas*/ 
  //assert(local_win!=NULL);
  ////assert(yrel>=0 && yrel<=LINES);
  ////assert(xrel>=0 && xrel<=COLS);
  //assert(cabeca!=NULL);
  //assert(unidade>=0 && unidade<=2);

  int ytiro = yrel;
  int xtiro = xrel;
  int range=1;

  while(xtiro!=3 && xtiro!= COLS-4 && range!= cabeca[unidade].dist_tiro){
    if(cabeca[unidade].pangular==1){
      mvwprintw(local_win,ytiro,xtiro,"-");
      wrefresh(local_win);
      usleep(DELAY);
      xtiro+=1;
  
    }else if(cabeca[unidade].pangular==2){
      mvwprintw(local_win,ytiro,xtiro-2,"-");
      wrefresh(local_win);
      usleep(DELAY);
      xtiro-=1;
    }
    range+=1;
  }
  
  xtiro = xrel;
  range=1;
  while(range!= cabeca[unidade].dist_tiro){
    if(cabeca[unidade].pangular==1){
      mvwprintw(local_win,ytiro,xtiro," ");
      xtiro+=1;
    }else if(cabeca[unidade].pangular==2){
      mvwprintw(local_win,ytiro,xtiro-2," ");
      xtiro-=1;
    }
  range++;  
  }
  wrefresh(local_win);
  
}


void mostra_pangular(WINDOW*local_tela,int yrel,int xrel,int fator,int coordenada)
{
          /* //assertivas*/ 
  //assert(local_tela!=NULL);
  ////assert(yrel>=0 && yrel<=LINES);
  ////assert(xrel>=0 && xrel<=COLS);
  //assert(fator>=0 || fator<=0);
  //assert(coordenada==0 || coordenada==1);

  mvwprintw(local_tela,yrel,xrel-1," ");

  if(coordenada==MOVEX){
    mvwprintw(local_tela,yrel,xrel+fator-1,"o");
  }else if(coordenada==MOVEY){
    mvwprintw(local_tela,yrel+fator,xrel-1,"o");
  }
  wrefresh(local_tela);
}

Unidade* troca_pangular(WINDOW *local_tela,int yrel,int xrel,Unidade* cabeca,int unidade){
          /* //assertivas*/ 
  //assert(local_tela!=NULL);
  ////assert(yrel>=0 && yrel<=LINES);
  ////assert(xrel>=0 && xrel<=COLS);
  //assert(cabeca!=NULL);
  //assert(unidade>=0 && unidade<=2);

  mvwprintw(local_tela,yrel,xrel-1," ");
  
  if(cabeca[unidade].pangular==1){
    cabeca[unidade].pangular=2;
    mvwprintw(local_tela,yrel,xrel-17-1,"o");
  }else if(cabeca[unidade].pangular==2){
    cabeca[unidade].pangular=1;
    mvwprintw(local_tela,yrel,xrel+17-1,"o");
  }
  return cabeca;
}

void  mostra_HP(WINDOW *local_tela,Unidade*cabeca,int unidade)
{
          /* //assertivas*/ 
  //assert(local_tela!=NULL);
  //assert(cabeca!=NULL);
  //assert(unidade>=0 && unidade<=2);

  werase(local_tela);
  mvwprintw(local_tela,0,1,"HP HEROI = %d",cabeca[unidade].vida);
  mvwprintw(local_tela,0,COLS/2-3,"DINHEIRO = %d",DINHEIRO);
  mvwprintw(local_tela,0,COLS-12,"FASE = %d",FASE);
  if (FASE!=10) mvwprintw(local_tela,1,1,"HP INIMIGOS = %d %d %d",cabeca[3].vida,cabeca[4].vida,cabeca[5].vida);
  if (FASE==10) mvwprintw(local_tela,1,1,"HP BOSS = %d",cabeca[6].vida);
  mvwprintw(local_tela,1,COLS/2-3,"COMIDA = %d",COMIDA);
  wrefresh(local_tela);
  
}

int cria_menu(int Colunas, int Linhas, int y_inicial, int x_inicial,char** choices, int qtd_opcoes)
{
          /* //assertivas*/ 
  ////assert(Colunas>0 && Colunas<=LINES);
  ////assert(Linhas>0 && Colunas<=COLS);
  ////assert(y_inicial>=0 && y_inicial<=LINES);
  ////assert(x_inicial=0 && x_inicial<=COLS);
  //assert(choices!=NULL);
  //assert(qtd_opcoes>0); 
  
  int n_choices = qtd_opcoes;
  int highlight = 1;
  int choice = 0;
  int c;

    
  WINDOW* menu_win = newwin(Colunas, Linhas, y_inicial, x_inicial);
  keypad(menu_win, TRUE);
  /** mvprintw(0, 0, "Usando teclas do teclado. Enter entra na opção.");*/

  print_menu(menu_win, highlight,choices,n_choices);

    
  while(1)
  {  
    c = wgetch(menu_win);	/** IMPORTANTE*/
    switch(c)
    { 
      case KEY_UP:
        if(highlight == 1)
        highlight = n_choices;
        else
          --highlight;
	 break;
      case KEY_DOWN:
        if(highlight == n_choices)
	  highlight = 1;
	  else 
	    ++highlight;
        break;
      case 10:
        choice = highlight;
        break;
      default:
        mvprintw(2, 40, "'%c'não é uma tecla válida.", c, c);
        refresh();
      break;
    }
    print_menu(menu_win, highlight,choices,n_choices);
    if(choice != 0)	/** saindo do loop infinito. Usuario fez escolha. */
      break;
  }
    
  wborder(menu_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
  apaga_janela(menu_win);
 
  return choice;
}

void print_menu(WINDOW *menu_win, int highlight,char** choices,int n_choices)
{
          /* //assertivas*/ 
  //assert(menu_win!=NULL);
  //assert(choices!=NULL);
  //assert(n_choices>0); 

  int x, y, i;	

  x = 1;
  y = 1;
  box(menu_win, 0, 0);
  for(i = 0; i < n_choices; ++i)
  {
    if(highlight == i + 1) /* Highlight a escolha atual*/
    {	
      wattron(menu_win, A_REVERSE); 
      mvwprintw(menu_win, y, x, "%s", choices[i]);
      wattroff(menu_win, A_REVERSE);
    }
      else
	mvwprintw(menu_win, y, x, "%s", choices[i]);
	++y;
  }
  wrefresh(menu_win);
}

/************************************FIM*******************************************/
