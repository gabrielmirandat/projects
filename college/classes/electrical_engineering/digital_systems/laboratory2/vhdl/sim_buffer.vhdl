library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity sim_buffer is
end sim_buffer;

architecture sim_buffer_op of sim_buffer is
	component V3statex is
    port (
	   -- Global output enable
	   G_L : in STD_LOGIC;    
       -- Input select: 0,1,2,3 => A,B,C,D	   
	   SEL : in STD_LOGIC_VECTOR (1 downto 0);
	   -- Input buses
	   A, B, C, D: in STD_LOGIC_VECTOR (7 downto 0);
	   -- Output bus (three state)
	   X: out STD_LOGIC_VECTOR (7 downto 0)
	   ) ;
end component;
	
	signal g_l_sim : STD_LOGIC;
	signal sel_sim : STD_LOGIC_VECTOR (1 downto 0);
	signal a_sim, b_sim, c_sim, d_sim, x_sim : STD_LOGIC_VECTOR (7 downto 0);

begin
		U1: V3statex port map( g_l_sim , sel_sim , a_sim, b_sim, c_sim, d_sim, x_sim );

		process		
			variable contbin : STD_LOGIC_VECTOR (1 downto 0);
		begin
		    a_sim <= "00000011";
			b_sim <= "00001100";
			c_sim <= "00110000";
			d_sim <= "11000000";
					
		    -- desabilitando g_l.
			contbin := "00";
			g_l_sim    <= '1';
			for i in 1 to 4 loop
				sel_sim   <= contbin;
				wait for 50 ns;
				contbin := contbin + 1;
			end loop;
			
			-- habilitando g_l.
			contbin := "00";
			g_l_sim    <= '0';
			for i in 1 to 4 loop
				sel_sim   <= contbin;
				wait for 50 ns;
				contbin := contbin + 1;
			end loop;
			
			--Para tudo.
			wait;			
		end process;
end sim_buffer_op;