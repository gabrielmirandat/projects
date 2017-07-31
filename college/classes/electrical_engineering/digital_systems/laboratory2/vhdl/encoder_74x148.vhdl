
library IEEE;
use IEEE.std_logic_1164.all;

entity V74x148 is
  port (EI_L : in STD_LOGIC;
          I_L: in STD_LOGIC_VECTOR(7 downto 0);
          A_L: out STD_LOGIC_VECTOR (2 downto 0);
  EO_L, GS_L : out STD_LOGIC);		
end V74x148;

-- Arquitetura Comportamental do codificador 74x148.
architecture arch_behavioral of V74x148 is

  --Função para converter de inteiro decimal para binário (de integer para STD_LOGIC_VECTOR)
  function CONV_STD_LOGIC_VECTOR(ARG: INTEGER; SIZE: INTEGER) return STD_LOGIC_VECTOR is
    variable result: STD_LOGIC_VECTOR (SIZE-1 downto 0);
	variable temp: integer;
  begin
    temp:= ARG;
	for i in 0 to SIZE-1 loop
	  if (temp mod 2) = 1 then result(i) := '1';
	  else result(i) := '0';
	  end if;
	  temp := temp/2;
	end loop;
    return result;
  end;

  signal EI: STD_LOGIC;
  signal I : STD_LOGIC_VECTOR (7 downto 0);
  signal EO,GS : STD_LOGIC;
  signal A: STD_LOGIC_VECTOR (2 downto 0);
begin
  EI   <= not EI_L;
  I    <= not I_L;
  EO_L <= not EO;
  GS_L <= not GS;
  A_L  <= not A;
  process (EI_L, I_L, EI, EO, GS, I, A)
    variable j: INTEGER range 7 downto 0;
  begin
    EO <= '1'; GS <= '0'; A <= "000";
	if (EI = '0') then 
	  EO <= '0';
	else 
	  for j in 7 downto 0 loop
	    if I(j)='1' then
		  GS <= '1'; EO <= '0';
		  A <= CONV_STD_LOGIC_VECTOR(j,3);
		  exit;
		end if;
	  end loop;
	end if;
  end process;
end arch_behavioral;  
