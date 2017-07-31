library IEEE;
use IEEE_std_logic_1164.all;

entity VposDff is
	Port (CLK,CLR,D: in STD_LOGIC;
			  Q, QN: out STD_LOGIC);
	end VposDff;

architecture VposDff_arch of VposDff is
begin
	process (CLK, CLR)
	begin
		if CLR = '1' then Q <= '0' ; QN <= '1';
		elsif CLK'event and CLK='1' then Q <= D ; QN <= not D;
		end if;
	end process;
end VposDff_arch;