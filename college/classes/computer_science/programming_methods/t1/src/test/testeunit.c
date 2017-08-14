#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "CUnit/CUError.h"
#include "projeto1mp.h"
#include "unit.h"

int mudanca_lista=1;
int tamanho_atual=0;

int main(){

	CU_pSuite pSuite1 = NULL;
	CU_ErrorCode TestRegistry;

	TestRegistry = CU_initialize_registry();

	if (CUE_SUCCESS != TestRegistry){
		return CU_get_error();
	}

	pSuite1 = CU_add_suite("Teste das funcoes de lista",0,0);
	if ((NULL == CU_add_test(pSuite1,"Teste da funcao cria",testcria)) || 
	  (NULL == CU_add_test(pSuite1,"Teste da funcao vazia",testvazia)) || 
	  (NULL == CU_add_test(pSuite1,"Teste da funcao insere_ordenado",testinsere_ordenado)) || 
	  (NULL == CU_add_test(pSuite1,"Teste da funcao construcao_lista",testconstrucao_lista)) ||
	  (NULL == CU_add_test(pSuite1,"Teste da funcao retirar_elemento",testretirar_elemento)) || 
	  (NULL == CU_add_test(pSuite1,"Teste da funcao buscar_elemento",testbuscar_elemento)) || 
	  (NULL == CU_add_test(pSuite1,"Teste da funcao inserir_elemento",testinserir_elemento)) || 
	  (NULL == CU_add_test(pSuite1,"Teste da funcao libera",testlibera))) {
	  CU_cleanup_registry();
	    return CU_get_error();
  	}

	
   /* Run all tests using the CUnit Basic interface */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}