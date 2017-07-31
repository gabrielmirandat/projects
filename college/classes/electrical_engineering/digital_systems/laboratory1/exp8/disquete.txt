$MOD51                    ;início
ORG  0                    ;para gravar a partir de 0
CLR  A                    ;para zerar o acumulador
		
EP      EQU 20H 	      ;estado presente
HP      BIT P1.0 		  ;entrada HP
MOK     BIT P1.1 		  ;entrada MOK
Tmenor  BIT P1.2		  ;entrada T<
TOK		BIT P1.3		  ;entrada TOK
Tmaior	BIT P1.4		  ;entrada T>
SO		BIT P1.5		  ;entrada SO
SOK		BIT P1.6		  ;entrada SOK
LEU		BIT P1.7		  ;entrada LEU
RESET	BIT P2.7		  ;entrada RESET
LER		BIT P2.6		  ;saida LER
LS		BIT P2.5		  ;saida LS
RETR	BIT P2.4          ;saida RETR
AVAN	BIT P2.3		  ;saida AVÇ
LTa		BIT P2.2		  ;saida LT
LDHD	BIT P2.1		  ;saida LDHD
MT 		BIT P2.0		  ;saida MT

;limpa todas as variaveis
CLR HP    		  		  ;entrada HP
CLR MOK    	  			  ;entrada MOK
CLR Tmenor 				  ;entrada T<
CLR TOK					  ;entrada TOK
CLR Tmaior		  		  ;entrada T>
CLR SO			  		  ;entrada SO
CLR SOK		  			  ;entrada SOK
CLR LEU			  		  ;entrada LEU
CLR RESET		  		  ;entrada RESET
CLR LER		  			  ;saida LER
CLR LS			  		  ;saida LS
CLR RETR	        	  ;saida RETR
CLR AVAN		  		  ;saida AVÇ
CLR LTa			  		  ;saida LT
CLR LDHD	  			  ;saida LDHD
CLR MT 	  				  ;saida MT

A0: 	MOV EP, #0		  ;estado 0
		CLR  LER          ;LER = 0
		CLR  LDHD         ;LDHD = 0
		CLR  MT           ;MT = 0
		JB RESET, RES	  ;se RESET, RES
		JNB   HP, A0	  ;se A e HP==0, A, senão B

B1:		MOV EP, #1		  ;estado 1
		CLR  LS           ;LS = 0
		SETB  LDHD        ;LDHD = 1
		SETB  MT          ;MT = 1
		JB RESET, RES	  ;se RESET, RES
		JNB   MOK, B1	  ;se B e MOK==0, B, senão C

C2:	    MOV EP, #2		  ;estado 2
		SETB  LTa         ;LT = 1
		CLR  AVAN         ;AVÇ = 0
		CLR  RETR         ;RETR = 0
		JB RESET, RES	  ;se RESET, RES
		JB   TOK, D3	  ;se C e TOK==1, D
		JB   Tmenor, G6   ;se C e Tmenor==1, G
		JB   Tmaior, H7   ;se C e Tmaior==1, H
		JMP  C2		      ;senão, C

D3:		MOV EP, #3		  ;estado 3
		CLR  LTa          ;LT = 0
		JB RESET, RES	  ;se RESET, RES
		JNB   SO, D3	  ;se D e SO==0, D, senão E

E4:		MOV EP, #4		  ;estado 4
		SETB  LS          ;LS = 1
		JB RESET, RES	  ;se RESET, RES
		JB  SO, B1		  ;se E e SO==1, B
		JNB  SOK,F5		  ;se E e SO==0 e SOK==0, E, senão F

F5:		MOV EP, #5		  ;estado 5
		CLR  LS           ;LS = 0
		SETB LER          ;LER = 1
		JB RESET, RES	  ;se RESET, RES
		JNB  LEU, F5	  ;se F e LEU==0, F
		JMP	 A0			  ;senão, A

G6:		MOV EP, #6		  ;estado 6
		CLR  LTa          ;LT = 0
		SETB  AVAN        ;AVÇ = 1
		JB RESET, RES	  ;se RESET, RES
		JMP  C2		      ;pula sempre para C

H7:		MOV EP, #7		  ;estado 7
		CLR  LTa          ;LT = 0
		SETB RETR         ;RETR = 1
		JB RESET, RES	  ;se RESET, RES
		JMP  C2		      ;pula sempre para C
		
RES:
		MOV P2, 0		;zera todas as saídas
		JMP A0		    ;retorna ao estado inicial A

END