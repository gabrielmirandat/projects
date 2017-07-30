library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_signed.all;
use ieee.numeric_std.all;
--use ieee.std_logic_arith.all;
use work.mips_pkg.all;

--aritmeticas imediatas de um jeito e logicas imediatas de outro jeito (estende normal, estende só com 0)

entity processador_mips is
	port 
	(
		clk		: in std_logic;
		rst		: in std_logic;
		ula_out  : out std_logic_vector(WORD_SIZE-1 downto 0);
		bregrs	: out std_logic_vector(WORD_SIZE-1 downto 0);
		bregrt	: out std_logic_vector(WORD_SIZE-1 downto 0);
		Opula		: out std_logic_vector(2 downto 0);
		funct		: out std_logic_vector(5 downto 0);
		pc			: out std_logic_vector(WORD_SIZE-1 downto 0)
		
	);
end entity;


--architecture
architecture mips_multi_arch of processador_mips is
 
	--declaracao de sinais temporarios
	-- sinais PC
	signal habilita_pc : std_logic;
	signal saida_pc : std_logic_vector(WORD_SIZE-1 downto 0);
	-- sinais Mux 21
	signal auxInst, auxData : std_logic_vector(7 downto 0);
	signal saida_mux_2_1 : std_logic_vector(7 downto 0);
	-- sinais Memória
	signal not_clk : std_logic;
	signal saida_memoria : std_logic_vector(WORD_SIZE-1 downto 0);
	-- sinais Registrador de Instruçao
	signal saida_regInstrucao : std_logic_vector(WORD_SIZE-1 downto 0);
	-- sinais Registrador de dados da memória
	signal saida_regDados : std_logic_vector(WORD_SIZE-1 downto 0);
	-- sinais Mux 22
	signal saida_mux_2_2 : std_logic_vector(WORD_SIZE-1 downto 0);
	-- sinais Mux 23
	signal auxIn0,auxIn1 : std_logic_vector(4 downto 0);
	signal saida_mux_2_3 : std_logic_vector(4 downto 0);
	-- sinais Extensão de sinal
	signal saida_extSinal : std_logic_vector(WORD_SIZE-1 downto 0);
	-- sinais Banco de Registradores
	signal saida_breg_A, saida_breg_B : std_logic_vector(WORD_SIZE-1 downto 0);
	-- sinais Registradores A e B
	signal saida_regA, saida_regB : std_logic_vector(WORD_SIZE-1 downto 0);
	-- sinais Mux 24 (alterado para nmux_3)
	signal SHAMNT, saida_mux_n3 : std_logic_vector(WORD_SIZE-1 downto 0);
	-- sinais Mux 4
	signal saida_mux_4, saida_extSinal_deslocado : std_logic_vector(WORD_SIZE-1 downto 0);
	-- sinais Controle da ULA
	signal saida_alu_ctr : std_logic_vector(3 downto 0);
	-- sinais ULA
	signal saida_alu : std_logic_vector(WORD_SIZE-1 downto 0);
	signal saida_aluZero : std_logic;
	-- sinais SaidaALU
	signal saida_saidaALU : std_logic_vector(WORD_SIZE-1 downto 0);
	-- sinais Mux 3
	signal end_desvio_aux : std_logic_vector(27 downto 0);
	signal end_desvio, saida_mux_3 : std_logic_vector(WORD_SIZE-1 downto 0);
	signal saida_extSinal_jump : std_logic_vector(27 downto 0);
	-- sinais Controle Mips
	signal opcode : std_logic_vector(5 downto 0);
	signal EscreveIR, EscrevePC, EscreveMem, EscrevePCCond, branchifnotequal, MemparaReg, IouD,
			 EscreveReg, RegDst, is_BxxZ : std_logic;
   signal OrigPC, origAALU, origBALU : std_logic_vector(1 downto 0);
	signal opALU : std_logic_vector(2 downto 0);	
	
begin
	-- PC
	habilita_pc <= (saida_aluZero and EscrevePCCond) 
						or EscrevePC
						or (is_BxxZ and saida_regInstrucao(16) and not(saida_regA(31)))	--rt[0], not(breg[rs[31]])	
						or (is_BxxZ and not(saida_regInstrucao(16)) and saida_regA(31));  --not(rt[0]) ,breg[rs[31]]
	U1 : reg generic map (SIZE => 32)port map(clk, habilita_pc, rst, saida_mux_3, saida_pc);
	-- Mux 21
	auxInst <= saida_pc(9 downto 2);
	auxData <= '1' & saida_saidaALU(8 downto 2);
	U2 : mux_2 generic map(SIZE => 8) port map(auxInst,auxData, IouD, saida_mux_2_1);
	-- Memória
	not_clk <= not(clk);
	U3 : mips_mem generic map (WIDTH => 32 ,WADDR => 8) port map(saida_mux_2_1(7 downto 0), not_clk, saida_breg_B, EscreveMem, saida_memoria);
	-- Registrador de Instruçao
	U4 : reg generic map(SIZE => 32) port map(clk, EscreveIR, rst, saida_memoria, saida_regInstrucao);
	-- Registrador de dados da memória
	U5 : regbuf generic map (SIZE => 32) port map(clk, saida_memoria, saida_regDados);
	-- Controle Mips
	opcode <= saida_regInstrucao(31 downto 26);
	U6 : mips_control port map(clk, rst, opcode, EscreveIR, EscrevePC,
										 EscreveMem, EscrevePCCond, branchifnotequal, MemparaReg, opALU, IouD,
										 OrigPC, OrigAALU, OrigBALU, EscreveReg, RegDst, is_BxxZ);
	-- Mux 22
	U7 : mux_2 generic map (SIZE => 32) port map(saida_saidaALU,saida_regDados, MemparaReg, saida_mux_2_2);
	-- Mux 23
	auxIn0 <= saida_regInstrucao(20 downto 16);
	auxIn1 <= saida_regInstrucao(15 downto 11);
	U8 : mux_2 generic map (SIZE => 5) port map(auxIn0, auxIn1, RegDst, saida_mux_2_3);
	-- Extensão de sinal
	U9 : extsgn generic map (IN_SIZE => 16, OUT_SIZE => 32) port map(saida_regInstrucao(15 downto 0), saida_extSinal);
	-- Banco de Registradores
	U10 : breg generic map (SIZE => 32, ADDR => 5) port map(clk, EscreveReg, saida_regInstrucao(25 downto 21), 
																			  saida_regInstrucao(20 downto 16),saida_mux_2_3, 
																			  saida_mux_2_2, saida_breg_A, saida_breg_B);
	-- Registrador A
	U11: regbuf generic map (SIZE => 32) port map (clk,saida_breg_A,saida_regA);
	-- Registrador B
	U12: regbuf generic map (SIZE => 32) port map (clk,saida_breg_B,saida_regB);
	-- Mux 24 (alterado para nmux_3)
	--U10 : mux_2 port map(saida_pc,saida_breg_A, OrigAALU, saida_mux_2_4);
	SHAMNT <= "000" & x"000000" & saida_regInstrucao(10 downto 6);
	U13 : mux_3 generic map(W_SIZE => 32)  port map(saida_pc,saida_regA, SHAMNT, OrigAALU, saida_mux_n3);
	-- Mux 4
	saida_extSinal_deslocado <= saida_extSinal(29 downto 0) & "00"; 
	U14 : mux_4 generic map(W_SIZE => 32) port map(saida_regB, X"00000004", saida_extSinal, saida_extSinal_deslocado, OrigBALU, saida_mux_4);
	-- Controle da ULA
	U15 : alu_ctr port map(opALU, saida_regInstrucao(5 downto 0), saida_alu_ctr);
	-- ULA
	U16 : ulamips port map(saida_alu_ctr, saida_mux_n3, saida_mux_4, saida_alu, saida_aluZero);
	-- SaidaALU
	U17 : regbuf port map(clk, saida_alu, saida_saidaALU);
	-- Mux 3
	U18: extsgn generic map (IN_SIZE =>26, OUT_SIZE => 28) port map (saida_regInstrucao(25 downto 0),saida_extSinal_jump);
	end_desvio_aux <= std_logic_vector(unsigned(saida_extSinal_jump) sll 2);
	end_desvio <=saida_pc(31 downto 28)& end_desvio_aux;
	U19 : mux_3 generic map (W_SIZE => 32) port map(saida_alu, saida_saidaALU, end_desvio, OrigPC, saida_mux_3);
	-- saida						 
	ula_out<= saida_saidaALU;
	bregrs <= saida_breg_A;	--saida_regInstrucao
	bregrt <= saida_breg_B;	--saida_regDados
	Opula	 <= opALU;
	funct  <= saida_regInstrucao(5 downto 0);
	pc     <= saida_pc;
	
end mips_multi_arch;