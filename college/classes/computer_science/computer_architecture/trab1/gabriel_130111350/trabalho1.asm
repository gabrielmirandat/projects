# Aluno: Gabriel Martins de Miranda
# Matricula: 130111350

.data       
	# variable declarations follow this line
.text     
	 # instructions follow this line	
main: 
	add  $t0, $zero, $zero	#t0 = 0
	addi $t1, $t1, -3	#t1 = -3
	addi $t2, $t2, 3	#t2 = 3
	ori  $t3, $t1, -2	#t3 = t1 or -2 
	andi $t4, $t3, 4	#t4 = t3 and 4
	bgez $t1, branchBGEZ 	#se t1 >=0 , branchBGEZ
	bgez $t2, branchBGEZ	#se t2 >=0 , branchBGEZ
	sub  $t4, $t2, $t3	#nao executado
branchBGEZ:
	sll  $t3, $t1, $t2	#t3 = t1 << t2
	srl  $t4, $t1, $t2	#t4 = t1 >> t2
	slti $t5, $t1, 2	#t5 = t1 < 2
	slti $t5, $t1, -5	#t5 = t1 < -5
	bltz $t2, branchBGEZ 	#se t2 < 0 , exit
	bltz $t1, branchBGEZ	#se t1 < 0 , exit
	and  $t4, $t2, $t3	#nao executado	
exit:
# Fim do programa (pule uma linha)
