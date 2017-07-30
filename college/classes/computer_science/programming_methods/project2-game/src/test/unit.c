#include"unit.h"

Unidade* vet;
extern int saida;
extern int DINHEIRO;
extern int COMIDA;
extern int FASE;
extern int hp_inim_1,hp_inim_2,hp_inim_3;
extern int CARREGAR;

void testiniciaunidade(void){
   initscr();

   FASE=1;
   
   Unidade* lista_teste=NULL;
   Unidade* lista_lixo1=NULL;
   Unidade* lista_lixo2=NULL;
   Unidade* lista_lixo3=NULL;
   Unidade* lista_lixo4=NULL;
   Unidade* lista_lixo5=NULL;
   lista_teste =inicia_unidade(1,1,3,2,1,500,120,50);
   lista_lixo1 =inicia_unidade(0,0,0,0,0,0,0,0); 
   lista_lixo2 =inicia_unidade(0,0,0,0,0,0,0,0);
   lista_lixo3 =inicia_unidade(0,0,0,0,0,350,5,30);
   lista_lixo4 =inicia_unidade(0,0,0,0,0,300,10,30);
   lista_lixo5 =inicia_unidade(0,0,0,0,0,250,15,30);
   vet = (Unidade*) malloc(6*sizeof(Unidade));
   vet = cria_cabeca(vet,0, lista_teste);
   vet = cria_cabeca(vet,1, lista_lixo1);
   vet = cria_cabeca(vet,2, lista_lixo2);
   vet = cria_cabeca(vet,3, lista_lixo3);
   vet = cria_cabeca(vet,4, lista_lixo4);
   vet = cria_cabeca(vet,5, lista_lixo5);
}

void testPosicaoMapa(void){
  int yrel = vet[0].y;
  int xrel = vet[0].x;
  mostra_heroi(stdscr,yrel,xrel,0);
  getyx(stdscr,yrel,xrel);
  CU_ASSERT_EQUAL(vet[0].y + 8,yrel);
  CU_ASSERT_EQUAL(vet[0].x + 12,xrel);
}


void testVel(void){
  erase();
  int yini,yfinal;
  int xini,xfinal;
  int VEL = vet[0].velocidade;
  getyx(stdscr,yini,xini);
  mostra_heroi(stdscr,yini,xini+VEL,0);
  getyx(stdscr,yfinal,xfinal);
  CU_ASSERT_EQUAL(yini + 8,yfinal);
  CU_ASSERT_EQUAL(xini + 12 + VEL,xfinal);
}

void testAngulo(void){
  int xrel,yrel;
  getyx(stdscr,yrel,xrel);
  vet = troca_pangular(stdscr,yrel,xrel,vet,0);
  CU_ASSERT_EQUAL(vet[0].pangular,2);
}

void testVelangular(void){
  int xrel,yrel;
  getyx(stdscr,yrel,xrel);
  vet = troca_pangular(stdscr,yrel,xrel,vet,0);
  vet = troca_pangular(stdscr,yrel,xrel,vet,0);
  CU_ASSERT_EQUAL(vet[0].pangular,2);
}

void testDistMaxTiro(void){
  int bol;
  bol = range_dist_maxima(80,50,vet,0,0);
  CU_ASSERT_EQUAL(bol,1);
  bol = range_dist_maxima(35,10,vet,0,0);
  CU_ASSERT_EQUAL(bol,1);
  bol = range_dist_maxima(5,60,vet,0,0);
  CU_ASSERT_EQUAL(bol,0);
  bol = range_dist_maxima(90,5,vet,0,0);
  CU_ASSERT_EQUAL(bol,0);
 
}

void testVida(void){
  int vida;
  vida = vet[0].vida;
  
  vet = tira_vida_heroi(vet,0,30,15);
  CU_ASSERT_EQUAL(vida-30,vet[0].vida);
  vet[3].vida=0;
  vet = tira_vida_heroi(vet,0,10,30);
  CU_ASSERT_EQUAL(vida-55,vet[0].vida); 

}

void testDanoPSeg(void){
  int dano = vet[0].dano;
  vet[3].vida=500;
  vet = tira_vida_ini(vet,60,25,3,0);
  vet = tira_vida_ini(vet,60,25,3,0);
  
  CU_ASSERT_TRUE(500 - 2*dano > vet[3].vida );
  
}

void testDanoDAngulo(void){
  int dano =  dano_relativo(vet,0);

  CU_ASSERT_TRUE(dano > vet[0].dano);  
}

void testlibera(void){

  libera_memoria(vet); 
  
  CU_ASSERT_PTR_NOT_NULL(vet);

  endwin();
}  
  