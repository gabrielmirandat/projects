$MOD51 				; início
ORG 0 				; para gravar a partir de 0
MOV R0, #0H         ; para zerar o registrador R0
JNB P0.0, CASO0 	; se o primeiro bit de P0 for 0,
					; vai para a rotina 'CASO0'
JMP CASO1 			; senão vai para a rotina 'CASO1'
CASO0: JNB P0.0, CASO0 ; enquanto o primeiro bit de P0 não
					   ; mudar para 1, ele permanece aqui.
CASO1: JB P0.0, CASO1 ; enquanto o primeiro bit de P0 não mudar
					  ; de volta para 0, ele permanece aqui.
INC R0 				; completou um ciclo de 0 e 1,
					; indicando que foi feito um pulso.
JMP CASO0 			; Volta para 'CASO0' para reiniciar
					; o processo
END