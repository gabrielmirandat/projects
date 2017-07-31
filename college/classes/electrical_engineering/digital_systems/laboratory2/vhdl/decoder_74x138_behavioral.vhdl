library IEEE;
use IEEE.std_logic_1164.all;

entity V3to8dec is
  port (G1, G2A, G2B: in  STD_LOGIC;
                   A: in  STD_LOGIC_VECTOR (2 downto 0);
		           Y: out STD_LOGIC_VECTOR (7 downto 0));
end V3to8dec;


architecture arch_behavioral of V3to8dec is
  signal Y_s: STD_LOGIC_VECTOR (7 downto 0);
begin
  process (A, G1, G2A, G2B, Y_s)
    begin
	  case A is
	    when "000" => Y_s <= "00000001";
		when "001" => Y_s <= "00000010";
		when "010" => Y_s <= "00000100";
		when "011" => Y_s <= "00001000";
		when "100" => Y_s <= "00010000";
		when "101" => Y_s <= "00100000";
		when "110" => Y_s <= "01000000";
		when "111" => Y_s <= "10000000";
		when others => Y_s <= "00000000";
	  end case;
	  
	  if (G1 and G2A and G2B) = '1' then Y <= Y_s;
	  else Y <= "00000000";
	  end if;
  end process;
end arch_behavioral;  
