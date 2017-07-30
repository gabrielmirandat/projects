.data
impares: .word 1, 3, 5
size: .word 3
msg: .asciiz "Os tres primeiros numeros impares sao : "
space: .ascii " "
.text
la $t0, impares
#carrega endereço inicial do array
la $t1, size
#carrega endereço de size
lw $t1, 0($t1) #carrega size em t1
li $v0, 4 #imprime mensagem inicial
la $a0, msg
syscall
loop: beq $t1, $zero, testa1 #se processou todo o array vai para a parte 2
li $v0, 1
#serviço de impressão de inteiros
lw $a0, 0($t0) #inteiro a ser exibido
syscall

li $v0, 4 #imprime separador
la $a0, space
syscall
addi $t0, $t0, 4 #incrementa indice array
addi $t1, $t1, -1 #decrementa contador
j loop #novo loop

testa1: addi $t2, $zero, 5
addi $t3, $zero, 20
add $t1, $t2, $t3
li $v1, 1
sub $t1, $t2, $t3
jal print
mult $t2, $t3
mfhi $t1
mflo $t0
jal print
add $a0, $zero, $t0 #inteiro a ser exibido
syscall
div $t3, $t2
mfhi $t1
mflo $t0
jal print
add $a0, $zero, $t0 #inteiro a ser exibido
syscall
and $t1, $t2, $t3
jal print
or $t1, $t2, $t3
jal print
xor $t1, $t2, $t3
jal print
nor $t1, $t2, $t3
jal print
slt $t3, $t2, $t1
sll $t3, $t3, 2
srl $t3, $t3, 2
sra $t3, $t3, 2
addi $t1, $zero, 300
jal print
add $a0, $zero, $t0 #inteiro a ser exibido
syscall
addi $t1, $zero, 8192
lh $a1, 0($t1) #inteiro a ser exibido
add $a0, $zero, $a1 #inteiro a ser exibido
syscall
lb $a1, 0($t1) #inteiro a ser exibido
add $a0, $zero, $a1 #inteiro a ser exibido
syscall
lbu $a1, 0($t1) #inteiro a ser exibido
add $a0, $zero, $a1 #inteiro a ser exibido
syscall
lhu $a1, 0($t1) #inteiro a ser exibido
add $a0, $zero, $a1 #inteiro a ser exibido
syscall
lui $t1,20
jal print
addi $t0, $zero, 8192
sw $t1, 0($t0)
jal print
sh $t1, 0($t0)
jal print
sb $t1, 0($t0)
jal print
bne $t1, $t0, testa2

testa2: addi $t1, $zero, 5
blez $t1, testa2
bgtz $t1, testa3

testa3: slti $t1, $t2, -5
sltiu $t1, $t2, -5
andi $t1, $t2, 100
ori $t1, $t2, 100
xori $t1, $t2, 100
j exit

print: li $v0, 1
add $a0, $zero, $t1 #inteiro a ser exibido
syscall
jr   $ra              # return

exit: li $v0, 10
syscall
