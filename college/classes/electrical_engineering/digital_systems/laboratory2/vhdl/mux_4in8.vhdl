library IEEE;
use IEEE.std_logic_1164.all;

entity mux4in8b is
    port (
	   -- Select inputs 0-3 => A-D
	   S : in STD_LOGIC_VECTOR (1 downto 0);    
       -- Data bus input
	   A, B, C, D: in STD_LOGIC_VECTOR (7 downto 0);
	   -- Data bus output
	   Y: out STD_LOGIC_VECTOR (7 downto 0)
	   ) ;
end mux4in8b;

architecture arch of mux4in8b is
begin

  with S select
    Y <= A when "00",
	     B when "01",
		 C when "10",
		 D when "11",
		 (others => 'U') when others; -- this creates an 8 bit vector of U
  
 end arch;
  
