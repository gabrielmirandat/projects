library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity seteseg is
	port (
		codigo : in std_logic_vector (2 downto 0);
		segs : out std_logic_vector (6 downto 0)
	);
end seteseg;

architecture arc1 of seteseg is
signal f: STD_LOGIC_VECTOR(6 downto 0);  
begin

with codigo select
	f <= "1000111" when "000",
	     "1110111" when "001",
	     "1001110" when "011",
	     "0110000" when "111",
	     "0001110" when "110",
	     "1001111" when others;

	segs <= not(f);

end arc1;
