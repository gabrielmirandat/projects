$MOD51									;início
ORG 0									;para gravar a partir de 0
MOV R0, #0H								;para zerar a porta R0
JNB P0.0, CASOCONT010					;se P0.0 está inativo (controle inativo), pula para CASOCONT010

JMP CASOCONT101							;se P0.0 está ativo (controle ativo), pula para CASOCONT101

CASOCONT0:								;caso em que contador está em 0
	
	CASOCONT010: JB P0.1, CASOUP		;se P0.1 está ativo, CASOUP
	CASO00: JNB P0.0, CASOCONT010		;se P0.0 está inativo, CASOCONT010
	CASOCONT011: JB P0.1, CASOUP		;se P0.1 está ativo, CASOUP
	CASO10: JB P0.0, CASOCONT011		;se P0.0 está ativo, CASOCONT011
	
	INC R0								;R0 = R0 + 1 (incrementa contador de pulsos em P0.1)

	JMP CASOCONT0						;pula para CASOCONT0

CASOCONT1:								;caso em que contador está em 1
	CASOCONT100: JNB P0.1, CASOCONT0	;se P0.1 está inativo, CASOCONT0
	CASO01: JNB P0.0, CASOCONT100		;se P0.0 está inativo, CASOCONT100
	CASOCONT101: JNB P0.1, CASOCONT0	;se P0.1 está inativo, CASOCONT0
	CASO11: JB P0.0, CASOCONT101		;se P0.0 está ativo, CASOCONT101

	INC R0								;R0 = R0 + 1 (incrementa contador de pulsos em P0.1)

	JMP CASOCONT1						;pula para CASOCONT1

CASOUP: MOV A, R1						;A = R1
	    ADD A, R0						;A = A + R0
	    MOV R1, A						;R1 = A
	    MOV R0, #0H						;R0 = 0
	    JMP CASOCONT1					;pula para CASOCONT1

END