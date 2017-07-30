.data
	dois:  .word 0x00000002		#64000
.text
	
	lw   $t1,dois	#2									2
	addi $t2,$t1,8	#10									a
	addi $t3,$t1,-8 #-6									fffffffa
	sub  $t4,$t3,$t1		#t4 = -6 - (+2)   = -8					fffffff8
	sub  $t5,$t1,$t3		#t5 =  2 - (-6)   = 8					8
	sub  $t6,$t2,$t1		#t6 = 10 - (+2)   = 8					8
