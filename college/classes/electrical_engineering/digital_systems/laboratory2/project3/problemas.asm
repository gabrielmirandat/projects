;Problema 1
;CLR A
;MOV R0, #0x0F
;MOV R1, #0xF0
;ADD A, R0
;ADD A, R1
;MOV R7,A

;Problema 2
;CLR A
;MOV R0, #0xFF
;MOV R1, #0xF0
;ADD A, R0
;ADD A, R1
;MOV R6,A
;CLR A
;MOV R2,#0x0
;ADDC A, R2
;RLC A
;MOV R7, A

;Problema 3
CLR A
MOV R6, #0x05
MOV R7, #0x06
CLR C	;zera o carry pq subb usa ele
MOV A, R6
SUBB A, R7
CLR C	;zera o carry pq subb usa ele
RLC A
ANL A,#0x01

;Problema 4 (compara)
CLR C ;
MOV A,R7
SUBB A,R6
JNC Fim
MOV A,R7
XCH A,R6
XCH A,R7 ; Aqui poderiamos usar tambem MOV (qual?)
Fim: JMP $

;Problema 5 (comparar com o conteudo do endereço do registrador)
CLR C
MOV A, @R0
MOV R6, A  ;R6 = @R0

INC R0
MOV A, @R0
MOV R7, A  ;R7 = @R0+1

CALL compara
Fim: JMP $

compara:
    MOV A,R6
	SUBB A,R7
	JNC Fim
	MOV A,R7
	XCH A,R6
	XCH A,R7 ; Aqui poderiamos usar tambem MOV (qual?)
	MOV A,R7
	MOV @R0, A
	DEC R0
	MOV A,R6
	MOV @R0, A 
RET







