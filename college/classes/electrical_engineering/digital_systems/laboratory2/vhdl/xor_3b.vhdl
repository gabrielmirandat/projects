library IEEE;
use IEEE.std_logic_1164.all;

entity vxor3 is
    port (
	   A, B, C: in STD_LOGIC;
	   Y : out STD_LOGIC
	   ) ;
end vxor3;

architecture arch of vxor3 is
begin
    Y <= A xor B xor C;
 end arch;
  
