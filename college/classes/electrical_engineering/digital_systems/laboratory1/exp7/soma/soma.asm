;Soma de P0 com P1, resultado apresentado em P2

$MOD51								;arquitetura 8051
ORG 0								;lugar da memoria onde ficara o codigo de maquina (a partir de 0)

MOV A,#0H							;acumulador = 0

LOOP:

MOV A, P0							;acumulador = P0
ADD A, P1							;acumulador = acumulador + P1
MOV P2, A							;P2 = acumulador

JMP LOOP

END
