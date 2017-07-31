$MOD51									;início
ORG 0									;para gravar a partir de 0
MOV R0, #0H								;para zerar a porta R0	(saida menos significativa)
MOV R1, #0H								;para zerar a porta R1  (saida mais significativa)

START:									;inicio - seleção da operação
JB P2.0, SOMA							;se P2.0 está ativo, realizamos a SOMA
JB P2.1, SUBT							;se P2.1 está ativo, realizamos a SUBT
JB P2.2, MULT							;se P2.2 está ativo, realizamos a MULT
JB P2.3, DIVI							;se P2.3 está ativo, realiamos a DIVI
JMP ENDING								;caso contrário, sai do programa

SOMA:									;realiza soma
MOV A, P0								;Acumulador = P0
ADD A, P1								;Acumulador = Acumulador + P1
MOV R0, A								;R0 = Acumulador	(R0 = P0 + P1)
JMP START								;pula para START

SUBT:									;realiza subtração
MOV A, P0								;Acumulador = P0
SUBB A, P1								;Acumulador = Acumulador - P1
MOV R0, A								;R0 = Acumulador 	(R0 = P0 - P1)
JMP START								;pula para START

MULT:									;realiza multiplicação
MOV B, P1								;B = P1
MOV A, P0								;A = P0
MUL AB									;AB = A*B (A = menos significativo ; B = mais significativo )
MOV R0, A								;R0 = A (saida menos significativas)
MOV R1, B								;R1 = B (saida mais significativa)
JMP START								;pula para START

DIVI:									;realiza divisão
MOV B, P1								;B = P1
MOV A, P0								;A = P0
DIV AB									;AB = A/B (A = quociente; B = resto)
MOV R0, A								;R0 = A	  (quociente da divisão)
MOV R1, B								;R1 = B	  (resto da divisão)
JMP START								;pula para START

ENDING:									;fim do programa
END