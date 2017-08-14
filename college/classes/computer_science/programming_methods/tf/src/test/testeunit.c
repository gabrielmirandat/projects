#include"unit.h"

extern int saida;
extern int DINHEIRO;
extern int COMIDA;
extern int FASE;
extern int hp_inim_1,hp_inim_2,hp_inim_3;
extern int CARREGAR;

int main(){

	CU_pSuite pSuite1 = NULL;
	CU_ErrorCode TestRegistry;

	TestRegistry = CU_initialize_registry();

	if (CUE_SUCCESS != TestRegistry){
		return CU_get_error();
	}

	pSuite1 = CU_add_suite("Teste das funcoes do jogo",0,0);
	if ((NULL == CU_add_test(pSuite1,"Teste da funcao unicia_unidade",testiniciaunidade)) || 
	  (NULL == CU_add_test(pSuite1,"Teste da Posição no mapa",testPosicaoMapa)) || 
	  (NULL == CU_add_test(pSuite1,"Teste da velocidade",testVel)) || 
	  (NULL == CU_add_test(pSuite1,"Teste do Angulo da unidade",testAngulo)) ||
	  (NULL == CU_add_test(pSuite1,"Teste da Velocidade Angular",testVelangular)) || 
	  (NULL == CU_add_test(pSuite1,"Teste do range de tiro",testDistMaxTiro)) || 
	  (NULL == CU_add_test(pSuite1,"Teste para Vida",testVida)) || 
	  (NULL == CU_add_test(pSuite1,"Teste do dano por Turno",testDanoPSeg)) ||
	  (NULL == CU_add_test(pSuite1,"Teste do dano depende Angulo",testDanoDAngulo)) ||
	  (NULL == CU_add_test(pSuite1,"Teste para liberar",testlibera))){ 
	  
	    CU_cleanup_registry();
	    return CU_get_error();
  	}

	
   /* Run all tests using the CUnit Basic interface */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}