
library ieee;
use ieee.std_logic_1164.all;
use work.mips_pkg.all;

entity extsgn is
	generic (
		IN_SIZE : natural := 16;
		OUT_SIZE : natural := 32	
		);
	port (
		input : in std_logic_vector(IN_SIZE-1 downto 0);
		is_imm: in std_logic;
		output: out std_logic_vector(OUT_SIZE-1 downto 0)
		);
end entity;
		
architecture wires of extsgn is
signal tmp : std_logic_vector(OUT_SIZE-1 downto 0);
begin
	output <= tmp;
	tmp(IN_SIZE-1 downto 0) <= input;
	process (tmp,is_imm) 
	begin
		if is_imm = '0' then
			tmp(OUT_SIZE-1 downto IN_SIZE) <= (others => input(IN_SIZE-1));
		else
			tmp(OUT_SIZE-1 downto IN_SIZE) <= (others => '0');
		end if;
	end process;
end wires;