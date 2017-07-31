library IEEE;
use IEEE.std_logic_1164.all;

entity hamcorr is
    port (
	   DU : in STD_LOGIC_VECTOR (6 downto 0);
	   DC : out STD_LOGIC_VECTOR (6 downto 0);
	   NOERROR : out STD_LOGIC
	   ) ;
end hamcorr;

architecture arch of hamcorr is
  
  function syndrome (D: STD_LOGIC_VECTOR) return STD_LOGIC_VECTOR is
    variable: syn : STD_LOGIC_VECTOR (2 downto 0);
  begin
    syn(0) := D(6) xor D(4) xor D(2) xor D(0);
	syn(1) := D(5) xor D(4) xor D(1) xor D(0);
	syn(2) := D(3) xor D(2) xor D(1) xor D(0);
	return syn;
  end syndrome;
	  
begin
	process (DU)
	  variable i: INTEGER;
	begin	
	  DC <= DU;
	  i := CONV_INTEGER(syndrome(DU));
	  if i = 0 then 
	    NOERROR <= '1';
	  else 
	    NOERROR <= '0';
		DC(i)   <= not DU(i);
	  end if;	
	end process;
 end arch;