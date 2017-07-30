.data
	aux: .word 0xFA00		#64000
	aux2: .word 0x000002		#2
.text
LB0:	lw   $t2,aux			#5 ciclos	- 0	- indefinido (‘1’ & alu_out(8 downto 2))
	addi $t1,$t2,0x00CA		#4 ciclos	- 4	- 0x0000faca
	ori  $t2,$t1,0x00000FF		#4 ciclos	- 8	- 0x0000faff
	andi $t3,$t1,0x000000FF		#4 ciclos	- 12	- 0x000000ca
	sll  $t3,$t3,2			#4 ciclos	- 16	- 0x00000328
	srl  $t2,$t2,2			#4 ciclos	- 20	- 0x00003ebf
	bgez $t3,LB			#3 ciclos	- 24 	- nada
	add  $t2,$t1,$t2		#pulado		- 28	- pulado
LB:     lw   $t4,aux2			#5 ciclos	- 32	- indefinido (‘1’ & alu_out(8 downto 2))
	addi $t2,$t4, -6		#4 ciclos	- 36	- 0xfffffffc
	bltz $t2,LB1			#3 ciclos	- 40	- nada
	addi $t2,$t2, 8			#pulado		- 44	- pulado
LB1:	slti $t3,$t2, 4 		#4 ciclos	- 48	- 0x00000001
	bgez $t2,LB0			#3 ciclos	- 52	- nada
	bltz $t1,LB1			#3 ciclos	- 56	- nada
	addi $t1,$t1,100		#4 ciclos	- 60	- 0x0000fb2e
	j    LB		                #3 ciclos	- 64	- nada
					#total = 10 + 32 + 15 = 57 ciclos = 15 instrucoes
