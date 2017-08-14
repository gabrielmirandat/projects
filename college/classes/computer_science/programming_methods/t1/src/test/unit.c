#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "CUnit/CUError.h"
#include "projeto1mp.h"
#include "unit.h"

Lista* lista_teste;

void testcria(void){
   lista_teste=NULL;
   lista_teste =cria ("aaaa");
   
   CU_ASSERT_STRING_EQUAL("aaaa",lista_teste->palavra);
   CU_ASSERT_PTR_NULL(lista_teste->ant);
   CU_ASSERT_PTR_NULL(lista_teste->prox);
   CU_ASSERT(0==lista_teste->ocorrencias);
}

void testvazia(void){
   Lista* aux;
   aux =NULL;

   CU_ASSERT(1==vazia(aux));
   CU_ASSERT(0==vazia(lista_teste));
}

void testinsere_ordenado(void){
   lista_teste = insere_ordenado(lista_teste,"bbbb"); 
   lista_teste = insere_ordenado(lista_teste,"cccc");
   
   CU_ASSERT_STRING_EQUAL("aaaa",lista_teste->palavra);
   CU_ASSERT_STRING_EQUAL("bbbb",lista_teste->prox->palavra);
   CU_ASSERT_STRING_EQUAL("cccc",lista_teste->prox->prox->palavra);
   CU_ASSERT_STRING_EQUAL("aaaa",lista_teste->prox->ant->palavra);
   CU_ASSERT_STRING_EQUAL("bbbb",lista_teste->prox->prox->ant->palavra);
   CU_ASSERT_STRING_EQUAL("cccc",lista_teste->prox->prox->ant->prox->palavra);
   CU_ASSERT_PTR_NULL(lista_teste->ant);
   CU_ASSERT_PTR_NULL(lista_teste->prox->prox->prox);
}

void testconstrucao_lista(void){
    FILE* arq;
    arq = fopen("aux.txt", "w");
    fprintf(arq,"&&*dddd  eeee((");
    fclose(arq);
    arq = fopen("aux.txt", "r");
    
    lista_teste = construcao_lista(lista_teste,arq);
    
    CU_ASSERT_STRING_EQUAL("dddd",lista_teste->prox->prox->prox->palavra);
    CU_ASSERT_STRING_EQUAL("eeee",lista_teste->prox->prox->prox->prox->palavra);
}


void testretirar_elemento(void){
  lista_teste = retirar_elemento(lista_teste,"aaaa");
  lista_teste = retirar_elemento(lista_teste,"bbbb");
  lista_teste = retirar_elemento(lista_teste,"eeee");
  
  CU_ASSERT_STRING_EQUAL("cccc",lista_teste->palavra);
  CU_ASSERT_STRING_EQUAL("dddd",lista_teste->prox->palavra);
  
}


void testbuscar_elemento(void){
  CU_ASSERT(1==buscar_elemento(lista_teste,"cccc"));
  CU_ASSERT(1==buscar_elemento(lista_teste,"dddd"));
  CU_ASSERT(0==buscar_elemento(lista_teste,"eeee"));
}


void testinserir_elemento(void){
  lista_teste = inserir_elemento(lista_teste,"aaaa");
  lista_teste = inserir_elemento(lista_teste,"eeee");

  CU_ASSERT_STRING_EQUAL("aaaa",lista_teste->palavra);
  CU_ASSERT_STRING_EQUAL("eeee",lista_teste->prox->prox->prox->palavra);
}

void testlibera(void){
  libera(lista_teste);  
  
  CU_ASSERT_PTR_NOT_NULL(lista_teste);
  
}  
