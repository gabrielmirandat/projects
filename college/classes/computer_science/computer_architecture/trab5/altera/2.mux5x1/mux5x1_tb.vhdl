library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity mux5x1_tb is
end mux5x1_tb;

architecture sim1 of mux5x1_tb is	
	component mux5x1 is
	port (
		-- seletor das entradas => i0 a i4
		sel : in std_logic_vector(2 downto 0);
		-- entradas de dados
		i0,i1,i2,i3,i4 : in std_logic_vector(2 downto 0);
		-- saida escolhida
		sai : out std_logic_vector(2 downto 0)
	  );
	end component;
	
	signal S,A,B,C,D,E,SAI: STD_LOGIC_VECTOR(2 downto 0);
	
begin
		U1: mux5x1 port map(S,A,B,C,D,E,SAI);

		process		
			variable contbin : STD_LOGIC_VECTOR (2 downto 0);
		begin
		    A <= "111";
		    B <= "000";
		    C <= "001";
		    D <= "100";
		    E <= "111";
					
		    contbin := "000";
			for i in 1 to 6 loop
				S   <= contbin;
				wait for 50 ns;
				contbin := contbin + 1;
			end loop;
			
			--Para tudo.
			wait;			
		end process;
end sim1;






