#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projeto1mp.h"

int mudanca_lista=1;
int tamanho_atual=0;


int main(){
  Lista* l;
  FILE* fp;
  l=NULL;
  vet=NULL;

  fp=fopen("content/palavras.txt","r");

  l = construcao_lista(l,fp);

  tela(l);
  
  free(vet);

  libera(l);

  return 0;
}