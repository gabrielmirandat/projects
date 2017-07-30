.data
	aux: .word 0XFA00
	aux2: .word 0x000002
.text
LB0:	lw $t2,aux
	addi $t1,$t2,0x00CA
	ori $t2,$t1,0X00000FF
	ori $t2,$t1,0x000FFFF
	andi $t3,$t1,0X000000FF
	sll $t3,$t3,2
	srl $t2,$t2,2
	bgez $t3,LB
	add $t2,$t1,$t2
LB:     lw $t4,aux2
	addi $t2,$t4, -6
	bltz $t2,LB1
	addi $t2,$t2, 8
LB1:	slti $t3,$t2, 4 
	bgez $t2,LB0
	bltz $t1,LB1
	addi $t1,$t1,100
exit:
	j LB
