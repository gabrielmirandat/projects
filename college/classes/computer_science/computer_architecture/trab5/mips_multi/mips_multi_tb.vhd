library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_signed.all;
use ieee.numeric_std.all;
use ieee.std_logic_arith.all;

entity mips_multi_tb is
end mips_multi_tb;

architecture mips_multi_tb_arch of mips_multi_tb is
	--signals
	signal clk: std_logic := '0';
	signal clk_rom: std_logic := '1';
	signal rst: std_logic := '0';
	signal debug : std_logic_vector(1 downto 0) := "00";
	signal data : std_logic_vector(31 downto 0);
	
	component mips_multi is
	port 
	(
		clk		: in std_logic;
		clk_rom	: in std_logic;
		rst	   : in std_logic;
		debug		: in std_logic_vector(1 downto 0);
		data  	: out std_logic_vector(31 downto 0)
	);
	end component;

begin
	i1 : mips_multi	port map ( clk => clk, clk_rom => clk_rom, data => data, debug => debug, rst => rst );
	
	clk <= not(clk) after 10 ns;
	clk_rom <= not(clk_rom) after 10 ns;

init : process                                                                                
begin                                                        
	rst <= '1';
	wait for 15 ns;
	rst <= '0';
	wait;                                                       
end process init;         
end mips_multi_tb_arch;