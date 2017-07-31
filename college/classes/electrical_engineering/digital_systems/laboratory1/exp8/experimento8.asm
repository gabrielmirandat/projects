;Leitor de disquete em Assembly

$MOD51			;início 
ORG 0			;para gravar a partir de 0  

INICIO:
EP EQU 20H		;estado presente
HP BIT P1.0		;entrada HP
MOK BIT P1.1	;entrada MOK
Tme BIT P1.2	;entrada T<
TOK BIT P1.3	;entrada TOK
Tma BIT P1.4	;entrada T>
S0 BIT P1.5		;entrada S0
SOK BIT P1.6	;entrada SOK
LEU BIT P1.7	;entrada LEU

MT BIT P2.0		;saída MT
LDHD BIT P2.1	;saída LDHD 
LET BIT P2.2	;saída LT
AVC BIT P2.3	;saída AVC
RETR BIT P2.4	;saída RETR
LS BIT P2.5		;saída LS
LER BIT P2.6	;saída LER
RESET BIT P2.7	;entrada RESET

estadoA: ;0000
	MOV EP, #0
	CLR LER				;zera LER
	JB RESET, resetar	;verifica a entrada reset para resetar as entradas e saídas
	CLR MT				;zera MT
	CLR LDHD			;zera LDHD
	JB HP, estadoB		;passa para estado B se HP estiver ativado
	JMP estadoA			;continua em A se HP estiver desativado

estadoB: ;0001
	MOV EP, #1
	CLR LS				;zera LS
	JB RESET, resetar
	SETB MT				;ativa MT
	SETB LDHD			;ativa LDHD
	JB MOK, estadoC		;passa para estado C se MOK estiver ativado
	JMP estadoB			;continua em B se MOK estiver desativado

estadoC: ;0011
	MOV EP, #3
	CLR AVC				;zera ANÇ
	CLR RETR			;zera RETR
	JB RESET, resetar
	SETB LET			;ativa LT
	JB TOK, estadoD		;passa para estado D se TOK estiver ativado
	JB Tme, estadoG		;passa para estado G se T< estiver ativado
	JB Tma, estadoH		;passa para estado H se T> estiver ativado
	JMP estadoC			;continua em C se TOK estiver desativado

estadoD: ;0100
	MOV EP, #4
	CLR LET				;zera LT
	JB RESET, resetar
	JB S0, estadoE		;passa para estado E se S0 estiver ativado
	JMP estadoD			;continua em D se S0 estiver desativado

estadoE: ;0010
	MOV EP, #2
	JB RESET, resetar
	SETB LS				;ativa LS
	JB S0, estadoB		;volta ao estado B se S0 estiver ativado
	JB SOK, estadoF		;passa para estado F se SOK estiver ativado e S0 desativado
	JMP estadoE			;continua em E se SOK e S0 estiverem desativados

estadoF: ;0101
	MOV EP, #5
	CLR LS				;zera LS
	JB RESET, resetar
	SETB LER			;ativa LER
	JB LEU, estadoA		;retorna ao estado incial A se LEU estiver ativo
	JMP estadoF			;continua em F se LEU estiver desativado

estadoG: ;0110
	MOV EP, #6
	CLR LET				;zera LT
	JB RESET, resetar
	SETB AVC			;ativa ANÇ
	JMP estadoC			;volta para estado C incondicionalmente

estadoH: ;0111
	MOV EP, #7
	CLR LET				;zera LT
	JB RESET, resetar
	SETB RETR			;ativa RETR
	JMP estadoC			;volta para estado C incondicionalmente
	
resetar:
	MOV P2, 0		;passa todas as saídas para 0
	JMP estadoA		;retorna ao estado inicial A

END