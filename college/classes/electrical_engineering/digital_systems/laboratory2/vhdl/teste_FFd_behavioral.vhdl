library IEEE;
use IEEE.std_logic_1164.all;

entity TB_smexamp is
end TB_smexamp;

architecture TB_smexamp_a of TB_smexamp is
	component smexamp port (CLOCK,A,B: in STD_LOGIC; Z: out STD_LOGIC); end component;
					 
	signal CLOCK,A,B: STD_LOGIC:='0';
	signal Z: STD_LOGIC;
	begin
	U1: smexamp port map (CLOCK,A,B,Z);
	CLOCK <= not CLOCK after 30 ns;
	process
	begin
		wait for 50 ns;
		A<='1';
		wait for 150 ns;
		
		