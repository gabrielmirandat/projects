library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity sim_decodificador is
end sim_decodificador;

architecture sim_decodificador_op of sim_decodificador is
	component V74x138 is
      port (G1, G2A_L, G2B_L: in  STD_LOGIC;
                           A: in  STD_LOGIC_VECTOR (2 downto 0);
		                 Y_L: out STD_LOGIC_VECTOR (7 downto 0));
    end component;
	
	signal g1_sim, g2a_L_sim,g2b_L_sim : STD_LOGIC;
	signal a_sim : STD_LOGIC_VECTOR (2 downto 0);
	signal y_l_sim: STD_LOGIC_VECTOR (7 downto 0);

begin
		U1: V74x138 port map(g1_sim, g2a_L_sim, g2b_L_sim, a_sim, y_l_sim);

		process		
			variable contbin : STD_LOGIC_VECTOR (2 downto 0);
		begin
		    -- desabilitando g1.
			contbin := "000";
			g1_sim    <= '0';
			g2a_L_sim <= '0';
			g2b_L_sim <= '0';
			for i in 1 to 8 loop
				a_sim   <= contbin;
				wait for 50 ns;
				contbin := contbin + 1;
			end loop;
			
			-- desabilitando g2a.
			contbin := "000";
			g1_sim    <= '1';
			g2a_L_sim <= '1';
			g2b_L_sim <= '0';
			for i in 1 to 8 loop
				a_sim   <= contbin;
				wait for 50 ns;
				contbin := contbin + 1;
			end loop;
			
			-- desabilitando g2b.
			contbin := "000";
			g1_sim    <= '1';
			g2a_L_sim <= '0';
			g2b_L_sim <= '1';
			for i in 1 to 8 loop
				a_sim   <= contbin;
				wait for 50 ns;
				contbin := contbin + 1;
			end loop;
			
			-- habilitando o decoder
			contbin := "000";
			g1_sim    <= '1';
			g2a_L_sim <= '0';
			g2b_L_sim <= '0';
			for i in 1 to 8 loop
				a_sim   <= contbin;
				wait for 50 ns;
				contbin := contbin + 1;
			end loop;
			
			--Para tudo.
			wait;			
		end process;
end sim_decodificador_op;