/*
TRABALHO 1
Nome: OTÁVIO ALVES DIAS
Matrícula: 12/0131480
Curso: Engenharia de Computação
Disciplina: Métodos de Programação
Turma: A
Prof: Jan Mendonça
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "unit.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"


int main(){

	CU_pSuite pSuite1 = NULL;
	CU_ErrorCode TestRegistry;

	TestRegistry = CU_initialize_registry();

	if (CUE_SUCCESS != TestRegistry){
		return CU_get_error();
	}

	pSuite1 = CU_add_suite("Teste das funcoes de lista",0,0);
	if ((NULL == CU_add_test(pSuite1,"Teste da funcao CriarLista",TesteCriarLista)) || (NULL == CU_add_test(pSuite1,"Teste da funcao CriarPosicao",TesteCriarPosicao)) || (NULL == CU_add_test(pSuite1,"Teste da funcao Vazia",TesteVazia)) || (NULL == CU_add_test(pSuite1,"Teste da funcao InserirListaInicio",TesteInserirListaInicio)) || (NULL == CU_add_test(pSuite1,"Teste da funcao InserirListaFinal",TesteInserirListaFinal)) || (NULL == CU_add_test(pSuite1,"Teste da funcao RetirarListaInicio",TesteRetirarListaInicio)) || (NULL == CU_add_test(pSuite1,"Teste da funcao RetirarListaFinal",TesteRetirarListaFinal)) || (NULL == CU_add_test(pSuite1,"Teste da funcao BuscarLista",TesteBuscarLista)) || (NULL == CU_add_test(pSuite1,"Teste da funcao RetirarLista",TesteRetirarLista)) || (NULL == CU_add_test(pSuite1,"Teste da funcao InserirOrdenado",TesteInserirOrdenado)) || (NULL == CU_add_test(pSuite1,"Teste da funcao ArrumarIndice",TesteArrumarIndice)) || (NULL == CU_add_test(pSuite1,"Teste da funcao InserirIndice",TesteInserirIndice)) || (NULL == CU_add_test(pSuite1,"Teste da funcao RetirarIndice",TesteRetirarIndice)) || (NULL == CU_add_test(pSuite1,"Teste da funcao LerArquivo",TesteLerArquivo)) || (NULL == CU_add_test(pSuite1,"Teste da funcao GravarArquivo",TesteGravarArquivo))) {
	  CU_cleanup_registry();
      return CU_get_error();
  	}

	
   /* Run all tests using the CUnit Basic interface */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}