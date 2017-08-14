#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/prj2oa.h"

extern int IND_RAIZ;
extern int IND_PAG_ATUAL;
extern int FLAG_COMPARACAO;
extern int FLAG_ARV;
extern int FLAG_PROBLEMA;
extern int SEEKS;
extern int ACHOU;
extern int IND;

/******************************MAIN*****************************/

int main() {
  PAGINA* current=NULL;

  current = inicia_pagina(current);

  printar_pagina_atual_arquivo(current,IND_RAIZ);
  
  leitor_arquivo(current); 
  
  menu();
  
  return 1;
}