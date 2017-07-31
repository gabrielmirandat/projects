$MOD51 		           ;início
ORG   0                ;para gravar a partir de 0
MOV   R0,#0H           ;para zerar o registrador R0
MOV   R1,#0H           ;para zerar o registrador R1
CLR   A                ;para zerar o acumulador


inicio: JNB   P0.0, P00        ;se no começo do programa P0.0 for 0, vai para a rotina 'P00'
		JMP   P01              ;senão vai para a rotina 'P01'

P00:    JNB   P0.1, CASO0      ;se P0.1 for 0, vai para a rotina 'CASO0'
        JMP   CASO1            ;senão vai para a rotina 'CASO1'

P01:    JB    P0.1, P01        ;se P0.0 continuar em 1 ele permanece aqui,
		JMP   P00              ;senão ele segue para 'P00'		
		
		
LB2:	MOV   A, R0;           ;se P0.0 for 1, copia o valor de R0 para o acumulador
		ADD   A, R1;           ;soma o valor do acumulador com R1
		XCH   A, R1;           ;troca o valor de A com R1
		MOV   R0,#0H           ;para zerar o registrador R0




CASO0:  JNB   P0.1,CASO0       ;enquanto P0.1 não mudar para 1, ele permanece aqui.

CASO1:  JB    P0.1,CASO1       ;enquanto P0.1 não mudar, permanece aqui.
        INC   R0               ;Completou um ciclo de 0 e 1,
        JB    P0.1,LB2         ;se P0.0 for 1, vai para a rotina 'LB2'
        JMP   CASO0            ;se P0.0 ainda for 0,volta para 'CASO0' para reiniciar o processo
END