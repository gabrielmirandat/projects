library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;

entity vadd is
    port (
	   A8, B8 : in  UNSIGNED (7 downto 0);
	       S8 : out UNSIGNED (7 downto 0);
		   S9 : out STD_LOGIC_VECTOR (8 downto 0)) ;
end vadd;

architecture arch of vadd is	  
begin
    S8 <= A8 + B8;
	S9 <= ('0' & A8) + ('0' & B8);
 end arch;