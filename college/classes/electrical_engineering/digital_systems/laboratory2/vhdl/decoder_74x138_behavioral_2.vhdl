library IEEE;
use IEEE.std_logic_1164.all;



library IEEE;
use IEEE.std_logic_1164.all;

entity V3to8dec is
  port (G1, G2A, G2B: in  STD_LOGIC;
                   A: in  STD_LOGIC_VECTOR (2 downto 0);
		           Y: out STD_LOGIC_VECTOR (7 downto 0));
end V3to8dec;


architecture arch_behavioral2 of V3to8dec is

  --Função para converter de STD_LOGIC_VECTOR para Inteiro.
  function CONV_INTEGER (X: STD_LOGIC_VECTOR) return INTEGER is
    variable result: integer;
  begin
    result := 0;
    for i in X'range loop
      result := result * 2;
      case X(i) is
        when '0' | 'L' => null;
	when '1' | 'H' => result := result + 1;
	when others => null;
      end case;
    end loop;
    return result;
  end CONV_INTEGER;

begin
  process (G1, G2A, G2B, A)
    variable i: INTEGER range 0 to 7;
    begin
	  Y <= "00000000";
	  if (G1 and G2A and G2B) = '1' then
	    for i in 0 to 7 loop
		  if (i = CONV_INTEGER(A)) then Y(i) <= '1'; end if;
		end loop;
	  end if;	  
  end process;
end arch_behavioral2;  
