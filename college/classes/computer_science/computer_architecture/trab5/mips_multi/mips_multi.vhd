library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_signed.all;
use ieee.numeric_std.all;
use ieee.std_logic_arith.all;
use work.mips_pkg.all;

--aritmeticas imediatas de um jeito e logicas imediatas de outro jeito (estende normal, estende só com 0)

entity mips_multi is
	port 
	(
		clk		: in std_logic;
		clk_rom	: in std_logic;
		rst		: in std_logic;
		debug    : in std_logic_vector(1 downto 0);
		data  	: out std_logic_vector(WORD_SIZE-1 downto 0)
	);
end entity;


--architecture
architecture mips_multi_arch of mips_multi is
 
	--declaracao de sinais temporarios
	-- sinais PC
	signal habilita_pc : std_logic := '0';
	signal saida_pc : std_logic_vector(WORD_SIZE-1 downto 0)  := (others => '0');
	-- sinais Mux 21
	signal auxInst, auxData : std_logic_vector(WORD_SIZE-1 downto 0)  := (others => '0');
	signal saida_mux_2_1 : std_logic_vector(WORD_SIZE-1 downto 0)  := (others => '0');
	-- sinais Memória
	signal not_clk : std_logic := '0';
	signal saida_memoria : std_logic_vector(WORD_SIZE-1 downto 0)  := (others => '0');
	-- sinais Registrador de Instruçao
	signal saida_regInstrucao : std_logic_vector(WORD_SIZE-1 downto 0)  := (others => '0');
	-- sinais Registrador de dados da memória
	signal saida_regDados : std_logic_vector(WORD_SIZE-1 downto 0)  := (others => '0');
	-- sinais Mux 22
	signal saida_mux_2_2 : std_logic_vector(WORD_SIZE-1 downto 0)  := (others => '0');
	-- sinais Mux 23
	signal auxIn0,auxIn1 : std_logic_vector(WORD_SIZE-1 downto 0)  := (others => '0');
	signal saida_mux_2_3 : std_logic_vector(WORD_SIZE-1 downto 0)  := (others => '0');
	-- sinais Extensão de sinal
	signal saida_extSinal : std_logic_vector(WORD_SIZE-1 downto 0)  := (others => '0');
	-- sinais Banco de Registradores
	signal saida_breg_A, saida_breg_B : std_logic_vector(WORD_SIZE-1 downto 0)  := (others => '0');
	-- sinais regs A e B
	signal saida_reg_A, saida_reg_B : std_logic_vector(WORD_SIZE-1 downto 0)  := (others => '0');
	-- sinais Mux 24
	signal saida_mux_2_4 : std_logic_vector(WORD_SIZE-1 downto 0)  := (others => '0');
	-- sinais Mux 4
	signal saida_mux_4, saida_extSinal_deslocado : std_logic_vector(WORD_SIZE-1 downto 0)  := (others => '0');
	-- sinais Controle da ULA
	signal saida_alu_ctr : std_logic_vector(3 downto 0)  := (others => '0');
	-- sinais ULA
	signal saida_alu : std_logic_vector(WORD_SIZE-1 downto 0)  := (others => '0');
	signal saida_aluZero : std_logic;
	-- sinais SaidaALU
	signal saida_saidaALU : std_logic_vector(WORD_SIZE-1 downto 0)  := (others => '0');
	-- sinais Mux 3
	signal end_desvio, saida_mux_3 : std_logic_vector(WORD_SIZE-1 downto 0)  := (others => '0');
	-- sinais Controle Mips
	signal opcode : std_logic_vector(5 downto 0)  := (others => '0');
	signal EscreveIR, EscrevePC, EscreveMem, EscrevePCCond, branchifnotequal, MemparaReg, IouD, OrigAAlu, 
			 EscreveReg, RegDst : std_logic  := '0';
   signal opALU, OrigPC, origBALU : std_logic_vector(1 downto 0)  := (others => '0');	
	
	
	
begin
	-- PC
	habilita_pc <= ((saida_aluZero and EscrevePCCond) or EscrevePC);
	U1 : reg port map(clk, habilita_pc, rst, saida_mux_3, saida_pc);
	-- Mux 21
	auxInst <= X"000000" & saida_pc(9 downto 2);
	auxData <= X"000000" & '1' & saida_saidaALU(8 downto 2);
	U2 : mux_2 port map(auxInst,auxData, IouD, saida_mux_2_1);
	-- Memória
	not_clk <= not(clk);
	U3 : mips_mem port map(saida_mux_2_1(7 downto 0), not_clk, saida_reg_B, EscreveMem, saida_memoria);
	-- Registrador de Instruçao
	U4 : reg port map(clk, EscreveIR, rst, saida_memoria, saida_regInstrucao);
	-- Registrador de dados da memória
	U5 : regbuf port map(clk, saida_memoria, saida_regDados);
	-- Mux 22
	U6 : mux_2 port map(saida_saidaALU,saida_regDados, MemparaReg, saida_mux_2_2);
	-- Mux 23
	auxIn0 <= "000" & x"000000" & saida_regInstrucao(20 downto 16);
	auxIn1 <= "000" & x"000000" & saida_regInstrucao(15 downto 11);
	U7 : mux_2 port map(auxIn0, auxIn1, RegDst, saida_mux_2_3);
	-- Extensão de sinal
	U8 : extsgn port map(saida_regInstrucao(15 downto 0), saida_extSinal);
	-- Banco de Registradores
	U9 : breg port map(clk, EscreveReg, saida_regInstrucao(25 downto 21), saida_regInstrucao(20 downto 16), 
							 saida_mux_2_3(4 downto 0), saida_mux_2_2, saida_breg_A, saida_breg_B);
	-- regs A e B
	U10 : regbuf port map(clk, saida_breg_A, saida_reg_A);
	U11 : regbuf port map(clk, saida_breg_B, saida_reg_B); 
	-- Mux 24
	U12 : mux_2 port map(saida_pc,saida_reg_A, OrigAALU, saida_mux_2_4);
	-- Mux 4
	saida_extSinal_deslocado <= saida_extSinal(29 downto 0) & "00"; 
	U13 : mux_4 port map(saida_reg_B, X"00000004", saida_extSinal, saida_extSinal_deslocado, OrigBALU, saida_mux_4);
	-- Controle da ULA
	U14 : alu_ctr port map(opALU, saida_regInstrucao(31 downto 26), saida_alu_ctr);
	-- ULA
	U15 : ulamips port map(saida_alu_ctr, saida_mux_2_4, saida_mux_4, saida_alu, saida_aluZero);
	-- SaidaALU
	U16 : regbuf port map(clk, saida_alu, saida_saidaALU);
	-- Mux 3
	end_desvio <= saida_pc(31 downto 28) & saida_regInstrucao(25 downto 0) & "00";
	U17 : mux_3 port map(saida_alu, saida_saidaALU, end_desvio, OrigPC, saida_mux_3);
	-- Controle Mips
	opcode <= saida_regInstrucao(31 downto 26);
	U18 : mips_control port map(clk, rst, opcode, EscreveIR, EscrevePC,
										 EscreveMem, EscrevePCCond, branchifnotequal, MemparaReg, opALU, IouD,
										 OrigPC, OrigAALU, OrigBALU, EscreveReg, RegDst);
	-- saida						 
	data <= saida_saidaALU;
end mips_multi_arch;