.data
	aux: .word 0xFA00		#64000
	aux2: .word 0x000002		#2
.text
LB0:	lw   $t2,aux			#
	addi $t1,$t2,0x00CA		#faca
	add  $t2,$t1,$t2		#1f4ca
	or   $t3,$t1,$t2		#1feca
	nor  $t3,$t3,$t1		#fffe0135
	xor  $t4,$t2,$t1		#10e00
	and  $t2,$t2,$t1		#f0ca
	slt  $t2,$t3,$t1 		#1







