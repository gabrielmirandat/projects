library IEEE;
use IEEE.std_logic_1164.all;

entity vcompare is
    port (
	   A, B : in STD_LOGIC_VECTOR (7 downto 0);
	   EQ, NE, GT, GTE, LT, LTE : out STD_LOGIC
	   ) ;
end vcompare;

architecture arch of vcompare is	  
begin
	process (A,B)
	begin	
	  EQ <= '0'; NE <= '0'; GT <= '0';
	  GTE <= '0'; LT <= '0'; LTE <= '0';
	  
	  if A = B  then EQ  <= '1'; end if;
	  if A /= B then NE  <= '1'; end if;
	  if A > B  then GT  <= '1'; end if;
	  if A >= B then GTE <= '1'; end if;
	  if A < B  then LT  <= '1'; end if;
	  if A <= B then LTE <= '1'; end if;
	  
	end process;
 end arch;