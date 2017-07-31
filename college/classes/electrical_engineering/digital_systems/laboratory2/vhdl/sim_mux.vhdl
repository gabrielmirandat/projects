library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity sim_mux is
end sim_mux;

architecture sim_mux_op of sim_mux is
	component mux4in8b is
    port (
	   -- Select inputs 0-3 => A-D
	   S : in STD_LOGIC_VECTOR (1 downto 0);    
       -- Data bus input
	   A, B, C, D: in STD_LOGIC_VECTOR (7 downto 0);
	   -- Data bus output
	   Y: out STD_LOGIC_VECTOR (7 downto 0)
	   ) ;
    end component;
	
	signal s_sim : STD_LOGIC_VECTOR (1 downto 0);
	signal a_sim, b_sim, c_sim, d_sim, y_sim : STD_LOGIC_VECTOR (7 downto 0);

begin
		U1: mux4in8b port map( s_sim , a_sim, b_sim, c_sim, d_sim, y_sim );

		process		
			variable contbin : STD_LOGIC_VECTOR (1 downto 0);
		begin
		    a_sim <= "00000011";
			b_sim <= "00001100";
			c_sim <= "00110000";
			d_sim <= "11000000";
					
		    contbin := "00";
			for i in 1 to 4 loop
				s_sim   <= contbin;
				wait for 50 ns;
				contbin := contbin + 1;
			end loop;
			
			--Para tudo.
			wait;			
		end process;
end sim_mux_op;
