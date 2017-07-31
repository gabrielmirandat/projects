library IEEE;
use IEEE.std_logic_1164.all;

entity V3statex is
    port (
	   -- Global output enable
	   G_L : in STD_LOGIC;    
       -- Input select: 0,1,2,3 => A,B,C,D	   
	   SEL : in STD_LOGIC_VECTOR (1 downto 0);
	   -- Input buses
	   A, B, C, D: in STD_LOGIC_VECTOR (7 downto 0);
	   -- Output bus (three state)
	   X: out STD_LOGIC_VECTOR (7 downto 0)
	   ) ;
end V3statex;

architecture V3states of V3statex is
begin

  process (G_L, SEL, A)
  begin
    if G_L = '0' and SEL = "00" then X <= A;
	else X <= (others => 'Z');
	end if;
  end process;
  
  process (G_L, SEL, B)
  begin
    if G_L = '0' and SEL = "01" then X <= B;
	else X <= (others => 'Z');
	end if;
  end process;
  
  process (G_L, SEL, C)
  begin
    if G_L = '0' and SEL = "10" then X <= C;
	else X <= (others => 'Z');
	end if;
  end process;
  
  process (G_L, SEL, D)
  begin
    if G_L = '0' and SEL = "11" then X <= D;
	else X <= (others => 'Z');
	end if;
  end process;
  
 end V3states;
  