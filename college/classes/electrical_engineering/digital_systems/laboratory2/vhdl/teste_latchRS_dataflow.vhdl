library IEEE;
use IEEE.std_logic_1164.all;

entity TB_srlatch is
end TB_srlatch;

architecture TB_srlatch_a of TB_srlatch is
	component vsrlatch port (S,R: in STD_LOGIC; Q,QN: buffer STD_LOGIC); end component;
	signal Q, QN, R, S: STD_LOGIC;

begin
	U1: vsrlatch port map (S,R,Q,QN);

	process
	begin		
		S<='0';
		R<='0';
		wait for 100 ns;
	
		S<='1';
		wait for 100 ns;
	
		S<='0';
		wait for 100 ns;
		
		S<='1';
		R<='1';
		wait for 100 ns;
		
		S<='0';
		R<='0';
		wait for 100 ns;
		
		wait;
	end process;
end TB_srlatch_a;
