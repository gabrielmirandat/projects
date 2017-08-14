instru��es de refer�ncia � mem�ria: lw, sw.
instru��es l�gico-aritm�ticas: add, sub, and, or, slt.
branch e jump: beq, j.

1. Manda pc pra mem�ria que cont�m o c�digo e fetch a instru��o da mem�ria.
2. L� um ou dois registradores, usando campos da instru��o para selecionar os registradores a serem lidos.
Para o lw, precisamos ler apenas um registrador, mas a maioria das outras instru��es requerem dois deles.

Todas as instru��es, exceto jump, usam a ULA depois de ler dos registradores.
Instru��es de refer�ncia � mem�ria usam a ULA para calcular endere�o.
Instru��es l�gico-aritm�ticas usam a ULA para execu��o da opera��o.
Branches usam a ULA para compara��o.

Ap�s usar a ULA, cada classe de instru��es difere.
Uma instru��o de refer�ncia � mem�ria precisar� acessar a mem�ria ou para escrever dados para um store ou ler para um load.
Uma instru��o l�gico-aritm�ticas deve escrever dados da ULA de volta a um registrador.
Para um branch, podemos precisar mudar o endere�o da pr�xima instru��o baseado na compara��o, caso contr�rio incrementar PC de 4 para a pr�xima instru��o.

As linhas de controle s�o setadas baseadas primariamente na informa��o tomada da instru��o sendo executada.
Muitas unidades devem ser controladas dependendo do tipo de instru��o. Por exemplo, a Mem�ria de Dados deve ler num load e escrever num store.
O arquivo de registradores deve ser escrito num load e numa instru��o l�gico-aritm�tica.

'BASICAS'
- 'l�gicas'
and		-R bitwise and
andi	-I bitwise and immediate
or		-R bitwise or
ori		-I bitwise or immediate
xor		-R bitwise xor
xori	-I bitwise xor immediate
nor		-R bitwise nor
sll		-I shift left logical
sra		-I shift right arithmetic
srl		-I shift right logical


- 'aritm�ticas'
add		-R addition with overflow
addi	-I addition immediate with overflow
div		-? division with overflow
divu	-? division unsigned without overflow
mul		-R multiplication without overflow
mult	-? multiplication
multu	-? multiplication unsigned
sub		-R subtraction with overflow
subu	-R subtraction unsigned without overflow

- 'saltos'
beq		-I branch if equal
bne		-I branch if not equal
j		-J jump unconditionally
jal		-J jump and link
jr		-R jump register unconditionally

- 'memoria'
lb		-I load byte
lbu		-I load byte unsigned
lh		-I load halfword
lhu		-I load halfword unsigned
lui		-I load upper immediate
lw		-I load word
lwl		-I load word left
lwr		-I load word right
sb		-I store byte
sh		-I store halfword
sw		-I store word
swl		-I store word left
swr		-I store word right

- 'condicionais'
slt		-R set less than
slti	-I set less than immediate

- 'outras'
nop		-R null operation
sycall	-? system call

'EXTENDIDAS'
- 'l�gicas'
not		-? bitwise not
rol		-R,I rotate left
ror		-R,I rotate right
seq		-R,I set equal
sge		-R,I set greater or equal
sgeu	-R,I set greater or equal unsigned 
sgt		-R,I set greater than
sgtu	-R,I set greater than unsigned
sle		-R,I set less or equal
sleu	-R,I set less or equal unsigned
sne		-R,I set not equal

- 'memoria'
la		-I load adress
li  	-I load immediate
move	-? move




























