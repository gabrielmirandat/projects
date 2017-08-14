ORI: 		ori rs, rt, imediato 
breg[rt] = breg[rs] | 0x0000iiii;
/* TIPO I
1. adicionar instruçao ORI para o controle da ULA para fazer um OR
2. adiciona instrução no estado c_mem_add_st
	OrigAALU 			seleciona 1
	OrigBALU 			seleciona 2
	RegDST 				seleciona 0
	MemparaReg 			seleciona 0 
*/

ANDi: 		andi rs, rt, imediato 
breg[rt] = breg[rs] & 0x0000iiii;
/* TIPO I
1. adicionar instruçao ANDI para o controle da ULA para fazer um AND
2. adiciona instrução no estado c_mem_add_st
	OrigAALU 			seleciona 1
	OrigBALU 			seleciona 2
	RegDST 				seleciona 0
	MemparaReg 			seleciona 0 
*/

//desvio se maior que ou igual a zero
//Branch on Greater Than or Equal to Zero
BGEZ: 		bgez rs, label	//if breg[rs] >= 0 then branch
pc = pc + deslocamento*4;	//tipo beq
/* TIPO I
1. puxar 1º bit de rs negado e fazer um AND com isBGEZ e adicionar como condição de salto
2. OrigAALU 			seleciona 0


*/

//desvio se menor que zero
// Branch on Less Than Zero BLT
BLTZ: 		bgez rs, label  //if breg[rs] < 0 then branch
pc = pc + deslocamento*4;	//tipo beq
/* TIPO I




*/

//setar se menor que constante imediata
//Set on Less Than Immediate
SLTI: 		slti rt, rs, imediato  //rt <- (rs < immediate)
breg[rt] = breg[rt] < sgn_ext(imediato);
/* TIPO I




*/

//deslocamento lógico à esquerda
SLL: 		sll rd, rt, shamt 
breg[rd] = breg[rt] << shamt;
/* TIPO R
1. adicionar operação de deslocamento á esquerda na ULA quando SLL
2. adicionar instrução SLL para o controle da ULA para fazer um deslocamento á esquerda
3. MUX controlado por OrigAALU passa a ter 3 entradas (a última é o SHAMT)
4. adiciona instrução no estado rtype_ex_st
	OrigAALU 			seleciona 2
	OrigBALU			seleciona 0
	RegDST				seleciona 1
	MemparaReg 			seleciona 0 
*/

//deslocamento lógico à direita
SRL: 		srl rd, rt, shamt 
breg[rd] = breg[rt] >> shamt;
/* TIPO R
1. adicionar operação de deslocamento á direita na ULA (5 bits)
2. adicionar instrução SRL para o controle da ULA para fazer um deslocamento á direita
3. MUX controlado por OrigAALU passa a ter 3 entradas (a última é o SHAMT)
4. adiciona instrução no estado rtype_ex_st
	OrigAALU 			seleciona 2
	OrigBALU			seleciona 0
	RegDST				seleciona 1
	MemparaReg 			seleciona 0 
*/

ctr_mips: mips_control
port map ( 
clk => clk,
rst => rst,
opcode => , 
wr_ir => ,
wr_pc => ,
wr_mem => ,
is_beq => EscrevePCCond,
is_bne => não tem no desenho,
s_datareg => MemparaReg,
op_alu => ,
s_mem_add => IouD,
s_PCin => OrigPC,
s_aluAin => ,
s_aluBin => ,
wr_breg => EscreveReg,
s_reg_add => RegDst
);

ADDI breg[rt], breg[rs], immediate
breg[rt] <= breg[rs] + Imm

//------------------------------------------------------------------------------------------------------------------------------------------------------------
//TIPO I
lw => breg[rt] <- memory[rs + Imm]		//fetch - decode - execute - mem_access -> write_back
sw => 