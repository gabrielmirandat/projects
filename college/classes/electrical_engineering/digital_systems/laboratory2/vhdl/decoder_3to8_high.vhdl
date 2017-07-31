library IEEE;
use IEEE.std_logic_1164.all;

entity V3to8dec is
  port (G1, G2A, G2B: in  STD_LOGIC;
                   A: in  STD_LOGIC_VECTOR (2 downto 0);
		           Y: out STD_LOGIC_VECTOR (7 downto 0));
end V3to8dec;

architecture arch of V3to8dec is
  signal Y_s: STD_LOGIC_VECTOR (7 downto 0);
begin
  with A select
   Y_s <= "00000001" when "000",
          "00000010" when "001",
		  "00000100" when "010",
	      "00001000" when "011",
		  "00010000" when "100",
		  "00100000" when "101",
		  "01000000" when "110",
		  "10000000" when "111",
		  "00000000" when others;
			
  Y <= Y_s when (G1 and G2A and G2B) = '1' else "00000000";
end arch;  