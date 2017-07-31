library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;

entity vaddshr is
    port (
	   A, B, C, D : in SIGNED (7 downto 0);
	   SEL : in STD_LOGIC;
	   S: out SIGNED (7 downto 0)) ;
end vaddshr;

architecture arch of vaddshr is	  
begin
	S <= A + B when SEL = '1' else C + D;
 end arch;