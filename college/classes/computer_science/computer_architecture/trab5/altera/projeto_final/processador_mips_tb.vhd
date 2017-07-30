library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.mips_pkg.all;

entity processador_mips_tb is
end processador_mips_tb;

architecture arch of processador_mips_tb is 
	signal rst,clk : std_logic := '0';
	signal bregrs, bregrt ,reg_saidaula,pc: std_logic_vector (WORD_SIZE-1 downto 0);
	signal opula: std_logic_vector(2 downto 0);
	signal funct: std_logic_vector(5 downto 0);
	
	
	component processador_mips is 
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
	end component;
	begin 
		i1: processador_mips
		port map (
			clk 		=> clk,
			rst 		=> rst,
			ula_out 	=> reg_saidaula,
			bregrs 	=> bregrs,
			bregrt	=> bregrt,
			Opula		=> Opula,
			funct		=> funct,
			pc => pc 
		
		);
		
		clk <= not(clk) after 10 ps;

		init : process                                                                                
		begin                                                        
			rst <= '1';
			wait for 15 ps;
			rst <= '0';
			wait;                                                       
		end process init;         
end arch;