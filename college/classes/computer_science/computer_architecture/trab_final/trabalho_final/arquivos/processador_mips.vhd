library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_signed.all;
use ieee.numeric_std.all;
--use ieee.std_logic_arith.all;
use work.mips_pkg.all;

--aritmeticas imediatas de um jeito e logicas imediatas de outro jeito (estende normal, estende com 0)

entity processador_mips is
	port 
	(
		iKEY	   : in std_logic_vector(3 downto 0);
		ula_out  : out std_logic_vector(WORD_SIZE-1 downto 0);
		inst		: out std_logic_vector(WORD_SIZE-1 downto 0);
		data		: out std_logic_vector(WORD_SIZE-1 downto 0);
		pc			: out std_logic_vector(WORD_SIZE-1 downto 0);
		-- FPGA --
		iSW	: in std_logic_vector(1 downto 0);
		oLEDG : out std_logic_vector(7 downto 0);
		oHEX7_D, oHEX6_D, oHEX5_D, oHEX4_D, oHEX3_D, oHEX2_D, oHEX1_D, oHEX0_D : out std_logic_vector(6 downto 0)
	);
end entity;


--architecture
architecture mips_multi_arch of processador_mips is
 

	-- FPGA
	signal clk : std_logic;
	signal rst : std_logic;
	signal output_mux : std_logic_vector(WORD_SIZE-1 downto 0);
	
	
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
	signal end_desvio, saida_mux_3 : std_logic_vector(WORD_SIZE-1 downto 0);
	-- sinais Controle Mips
	signal opcode : std_logic_vector(5 downto 0);
	signal EscreveIR, EscrevePC, EscreveMem, EscrevePCCond, branchifnotequal, MemparaReg, IouD,
			 EscreveReg, RegDst, is_BxxZ, is_imm : std_logic;
   signal OrigPC, origAALU, origBALU : std_logic_vector(1 downto 0);
	signal opALU : std_logic_vector(2 downto 0);
	--
	signal ext_end_desvio : std_logic_vector(27 downto 0);
begin
	-- PC
	habilita_pc <= (saida_aluZero and EscrevePCCond) 
						or EscrevePC
						or (is_BxxZ and saida_regInstrucao(16) and not(saida_regA(31)))	--rt[0], not(breg[rs[31]])	
						or (is_BxxZ and not(saida_regInstrucao(16)) and saida_regA(31));--not(rt[0]) ,breg[rs[31]]
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
										 OrigPC, OrigAALU, OrigBALU, EscreveReg, RegDst, is_BxxZ,is_imm);
	-- Mux 22
	U7 : mux_2 generic map (SIZE => 32) port map(saida_saidaALU,saida_regDados, MemparaReg, saida_mux_2_2);
	-- Mux 23
	auxIn0 <= saida_regInstrucao(20 downto 16);
	auxIn1 <= saida_regInstrucao(15 downto 11);
	U8 : mux_2 generic map (SIZE => 5) port map(auxIn0, auxIn1, RegDst, saida_mux_2_3);
	-- Extensão de sinal
	U9 : extsgn generic map (IN_SIZE => 16, OUT_SIZE => 32) port map(saida_regInstrucao(15 downto 0),is_imm, saida_extSinal);
	-- Banco de Registradores
	U10 : breg generic map (SIZE => 32, ADDR => 5) port map(clk, EscreveReg, saida_regInstrucao(25 downto 21), saida_regInstrucao(20 downto 16), 
							 saida_mux_2_3, saida_mux_2_2, saida_breg_A, saida_breg_B);
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
	U18: extsgn generic map (IN_SIZE => 26, OUT_SIZE => 28) port map(saida_regInstrucao(25 downto 0),'0', ext_end_desvio);
	end_desvio <= saida_pc(31 downto 28)& (std_logic_vector(unsigned (ext_end_desvio) sll 2));
	U19 : mux_3 generic map (W_SIZE => 32) port map(saida_alu, saida_saidaALU, end_desvio, OrigPC, saida_mux_3);
	-- saida						 
	data <= saida_saidaALU;
	inst <= saida_regInstrucao;
	pc   <= saida_pc;
	
	-- FPGA
	clk <= not(iKEY(0));
	rst <= not(iKEY(1));
	
	oLEDG(0) <= clk;
	oLEDG(1) <= rst;
	
	U20 : mux_4 generic map(W_SIZE => 32) port map(saida_pc, saida_saidaALU, saida_regInstrucao, saida_regDados, iSW(1 downto 0), output_mux);
	
	with output_mux(31 downto 28) select oHEX7_D <=
		"1000000" when x"0",
		"1111001" when x"1",
		"0100100" when x"2",
		"0110000" when x"3",
		"0011001" when x"4",
		"0010010" when x"5",
		"0000010" when x"6",
		"1111000" when x"7",
		"0000000" when x"8",
		"0011000" when x"9",
		"0001000" when x"A",
		"0000011" when x"B",
		"1000110" when x"C",
		"0100001" when x"D",
		"0000110" when x"E",
		"0001110" when x"F",
		"0000000" when others;
		
	with output_mux(27 downto 24) select oHEX6_D <=
		"1000000" when x"0",
		"1111001" when x"1",
		"0100100" when x"2",
		"0110000" when x"3",
		"0011001" when x"4",
		"0010010" when x"5",
		"0000010" when x"6",
		"1111000" when x"7",
		"0000000" when x"8",
		"0011000" when x"9",
		"0001000" when x"A",
		"0000011" when x"B",
		"1000110" when x"C",
		"0100001" when x"D",
		"0000110" when x"E",
		"0001110" when x"F",
		"0000000" when others;
		
	with output_mux(23 downto 20) select oHEX5_D <=
		"1000000" when x"0",
		"1111001" when x"1",
		"0100100" when x"2",
		"0110000" when x"3",
		"0011001" when x"4",
		"0010010" when x"5",
		"0000010" when x"6",
		"1111000" when x"7",
		"0000000" when x"8",
		"0011000" when x"9",
		"0001000" when x"A",
		"0000011" when x"B",
		"1000110" when x"C",
		"0100001" when x"D",
		"0000110" when x"E",
		"0001110" when x"F",
		"0000000" when others;
		
	with output_mux(19 downto 16) select oHEX4_D <=
		"1000000" when x"0",
		"1111001" when x"1",
		"0100100" when x"2",
		"0110000" when x"3",
		"0011001" when x"4",
		"0010010" when x"5",
		"0000010" when x"6",
		"1111000" when x"7",
		"0000000" when x"8",
		"0011000" when x"9",
		"0001000" when x"A",
		"0000011" when x"B",
		"1000110" when x"C",
		"0100001" when x"D",
		"0000110" when x"E",
		"0001110" when x"F",
		"0000000" when others;
		
	with output_mux(15 downto 12) select oHEX3_D <=
		"1000000" when x"0",
		"1111001" when x"1",
		"0100100" when x"2",
		"0110000" when x"3",
		"0011001" when x"4",
		"0010010" when x"5",
		"0000010" when x"6",
		"1111000" when x"7",
		"0000000" when x"8",
		"0011000" when x"9",
		"0001000" when x"A",
		"0000011" when x"B",
		"1000110" when x"C",
		"0100001" when x"D",
		"0000110" when x"E",
		"0001110" when x"F",
		"0000000" when others;
		
	with output_mux(11 downto 8) select oHEX2_D <=
		"1000000" when x"0",
		"1111001" when x"1",
		"0100100" when x"2",
		"0110000" when x"3",
		"0011001" when x"4",
		"0010010" when x"5",
		"0000010" when x"6",
		"1111000" when x"7",
		"0000000" when x"8",
		"0011000" when x"9",
		"0001000" when x"A",
		"0000011" when x"B",
		"1000110" when x"C",
		"0100001" when x"D",
		"0000110" when x"E",
		"0001110" when x"F",
		"0000000" when others;
		
	with output_mux(7 downto 4) select oHEX1_D <=
		"1000000" when x"0",
		"1111001" when x"1",
		"0100100" when x"2",
		"0110000" when x"3",
		"0011001" when x"4",
		"0010010" when x"5",
		"0000010" when x"6",
		"1111000" when x"7",
		"0000000" when x"8",
		"0011000" when x"9",
		"0001000" when x"A",
		"0000011" when x"B",
		"1000110" when x"C",
		"0100001" when x"D",
		"0000110" when x"E",
		"0001110" when x"F",
		"0000000" when others;
		
	with output_mux(3 downto 0) select oHEX0_D <=
		"1000000" when x"0",
		"1111001" when x"1",
		"0100100" when x"2",
		"0110000" when x"3",
		"0011001" when x"4",
		"0010010" when x"5",
		"0000010" when x"6",
		"1111000" when x"7",
		"0000000" when x"8",
		"0011000" when x"9",
		"0001000" when x"A",
		"0000011" when x"B",
		"1000110" when x"C",
		"0100001" when x"D",
		"0000110" when x"E",
		"0001110" when x"F",
		"0000000" when others;
end mips_multi_arch;