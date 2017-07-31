library IEEE;
use IEEE.std_logic_1164.all;

entity V74x138 is
  port (G1, G2A_L, G2B_L: in  STD_LOGIC;
                       A: in  STD_LOGIC_VECTOR (2 downto 0);
		             Y_L: out STD_LOGIC_VECTOR (7 downto 0));
end V74x138;

architecture arch of V74x138 is
  signal Y_L_i: STD_LOGIC_VECTOR (7 downto 0);
begin
  with A select
   Y_L_i <= "11111110" when "000",
            "11111101" when "001",
			"11111011" when "010",
			"11110111" when "011",
			"11101111" when "100",
			"11011111" when "101",
			"10111111" when "110",
			"01111111" when "111",
			"11111111" when others;
			
  Y_L <= Y_L_i when (G1 and not G2A_L and not G2B_L) = '1' else "11111111";
end arch;  