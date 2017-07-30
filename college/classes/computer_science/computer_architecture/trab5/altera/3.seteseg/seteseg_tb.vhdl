library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;



entity seteseg_tb is
end seteseg_tb;

architecture sim1 of seteseg_tb is	
	component seteseg is
	port (
		codigo : in std_logic_vector (2 downto 0);
		segs : out std_logic_vector (6 downto 0)
	);
	end component;
	
	signal cod: STD_LOGIC_VECTOR(2 downto 0);
	signal sai: STD_LOGIC_VECTOR(6 downto 0);
	
begin
		U1: seteseg port map(cod, sai);

		process		
		begin
		    cod <= "000";
		    wait for 50 ns;		   
		    
		    cod <= "001";
		    wait for 50 ns;
		    
		    cod <= "011";
		    wait for 50 ns;
		    
		    cod <= "111";
		    wait for 50 ns;
		    
		    cod <= "110";
		    wait for 50 ns;
		    
		    --Para tudo.
		    wait;			
		end process;
end sim1;







