library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.STD_LOGIC_ARITH.ALL;

entity vmul_8bits_arith is
    port (
	   X,Y : in  STD_LOGIC_VECTOR (7 downto 0);
	   P   : out STD_LOGIC_VECTOR (15 downto 0)) ;
end vmul_8bits_arith;

architecture arch of vmul_8bits_arith is	  	
begin
	P <= unsigned(X) * unsigned(Y);
 end arch;

