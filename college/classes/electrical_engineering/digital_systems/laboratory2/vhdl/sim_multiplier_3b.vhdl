library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity sim is
end sim;

architecture sim_op of sim is	
	component mul_3bits is
		port ( A: in STD_LOGIC_VECTOR (2 downto 0);	
		       B: in STD_LOGIC_VECTOR (2 downto 0);
		      PH: out STD_LOGIC_VECTOR (2 downto 0);
		      PL: out STD_LOGIC_VECTOR (2 downto 0));
	end component;
	
	signal A, B, PH, PL: STD_LOGIC_VECTOR(2 downto 0);
	
begin 
		U1: mul_3bits port map(A, B, PH, PL);
		
		process
		begin
			A  <= "111";
			B  <= "111";
			wait for 100 ns;
				
			wait;
		end process;
end sim_op;




