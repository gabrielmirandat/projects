library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity sim_codificador is
end sim_codificador;

architecture sim_codificador_op of sim_codificador is
	component V74x148 is
      port (EI_L : in STD_LOGIC;
              I_L: in STD_LOGIC_VECTOR(7 downto 0);
              A_L: out STD_LOGIC_VECTOR (2 downto 0);
      EO_L, GS_L : out STD_LOGIC);		
    end component;
	
	signal ei_l_sim, eo_l_sim, gs_l_sim : STD_LOGIC;
	signal i_l_sim : STD_LOGIC_VECTOR (7 downto 0);
	signal a_l_sim: STD_LOGIC_VECTOR (2 downto 0);

begin
		U1: V74x148 port map(ei_l_sim , i_l_sim , a_l_sim , eo_l_sim, gs_l_sim );

		process		
			variable contbin : STD_LOGIC_VECTOR (7 downto 0);
		begin
		    -- desabilitando ei.
			contbin := "00000000";
			ei_l_sim    <= '1';
			for i in 1 to 256 loop
				i_l_sim   <= not (contbin);
				wait for 50 ns;
				contbin := contbin + 1;
			end loop;
			
			-- habilitando ei.
			contbin := "00000000";
			ei_l_sim    <= '0';
			for i in 1 to 256 loop
				i_l_sim   <= not (contbin);
				wait for 50 ns;
				contbin := contbin + 1;
			end loop;
			
			--Para tudo.
			wait;			
		end process;
end sim_codificador_op;