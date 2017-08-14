instruções de referência à memória: lw, sw.
instruções lógico-aritméticas: add, sub, and, or, slt.
branch e jump: beq, j.

1. Manda pc pra memória que contém o código e fetch a instrução da memória.
2. Lê um ou dois registradores, usando campos da instrução para selecionar os registradores a serem lidos.
Para o lw, precisamos ler apenas um registrador, mas a maioria das outras instruções requerem dois deles.

Todas as instruções, exceto jump, usam a ULA depois de ler dos registradores.
Instruções de referência à memória usam a ULA para calcular endereço.
Instruções lógico-aritméticas usam a ULA para execução da operação.
Branches usam a ULA para comparação.

Após usar a ULA, cada classe de instruções difere.
Uma instrução de referência à memória precisará acessar a memória ou para escrever dados para um store ou ler para um load.
Uma instrução lógico-aritméticas deve escrever dados da ULA de volta a um registrador.
Para um branch, podemos precisar mudar o endereço da próxima instrução baseado na comparação, caso contrário incrementar PC de 4 para a próxima instrução.

As linhas de controle são setadas baseadas primariamente na informação tomada da instrução sendo executada.
Muitas unidades devem ser controladas dependendo do tipo de instrução. Por exemplo, a Memória de Dados deve ler num load e escrever num store.
O arquivo de registradores deve ser escrito num load e numa instrução lógico-aritmética.

'BASICAS'
- 'lógicas'
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


- 'aritméticas'
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
- 'lógicas'
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




























