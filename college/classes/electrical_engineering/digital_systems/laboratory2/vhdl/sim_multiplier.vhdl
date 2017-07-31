library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity sim_multiplier is
end sim_multiplier;

architecture sim_multiplier_op of sim_multiplier is
	component vmul_8bits is
		port ( X,Y : in  STD_LOGIC_VECTOR (7 downto 0);
			   P   : out STD_LOGIC_VECTOR (15 downto 0)) ;
	end component;

	component vmul_8bits_structural is
		port ( X,Y : in  STD_LOGIC_VECTOR (7 downto 0);
			   P   : out STD_LOGIC_VECTOR (15 downto 0)) ;
	end component;
	
	component vmul_8bits_arith is
		port ( X,Y : in  STD_LOGIC_VECTOR (7 downto 0);
			   P   : out STD_LOGIC_VECTOR (15 downto 0)) ;
	end component;
	
	signal A_sim, B_sim : STD_LOGIC_VECTOR (7 downto 0);
	signal M1_sim, M2_sim, M3_sim, M4_sim : STD_LOGIC_VECTOR(15 downto 0);
		
begin
		U1: vmul_8bits port map(A_sim, B_sim, M1_sim );
		U2: vmul_8bits port map(A_sim, B_sim, M2_sim );
		U3: vmul_8bits port map(A_sim, B_sim, M3_sim );

		process		
		begin
			A_sim <= "01100100";
			B_sim <= "00001100";
			wait for 5 ns;
			
			M4_sim <= unsigned(A_sim) * unsigned(B_sim);
			
			wait for 5 ns;
			wait for 50 ns;
			
			wait;			
		end process;
end sim_multiplier_op;
