library IEEE;
use IEEE.std_logic_1164.all;

entity parity9 is
    port (
	   I: in STD_LOGIC_VECTOR (8 downto 0);
	   EVEN, ODD : out STD_LOGIC
	   ) ;
end parity9;

architecture arch of parity9 is
begin
	process (I)
	  variable p : STD_LOGIC;
	begin
	  p := I(0);
	  for j in 1 to 8 loop
	    if I(j) = '1' then p := not p; end if;
	  end loop;
	  ODD  <= p;
	  EVEN <= not p;
	end process;
 end arch;