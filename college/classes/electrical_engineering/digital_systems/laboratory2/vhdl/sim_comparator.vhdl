library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;

entity sim_compare is
end sim_compare;

architecture arch of sim_compare is	
	signal vec1  : STD_LOGIC_VECTOR (3 downto 0);
	signal vec2  : STD_LOGIC_VECTOR (5 downto 0);
	signal uvec1 : UNSIGNED (3 downto 0);
	signal uvec2 : UNSIGNED (5 downto 0);		
	signal A,B,C,D,E,F,G,H : STD_LOGIC;	
begin
		process						
		begin
			A <= '0'; B <= '0'; C <= '0'; D <= '0'; E <= '0'; F <= '0'; G <= '0'; H <= '0';
	        vec1 <= "1110";   uvec1 <= "1110"; 
			vec2 <= "001110"; uvec2 <= "001110";
					
			if (vec1 = vec2) then A <= '1'; end if;                       -- 0 Tamanhos diferentes
			if (unsigned(vec1) = unsigned(vec2)) then B <= '1'; end if;   -- 1 vec1 é expandido para 001110 e fica igual a vec2
			if (signed(vec1) = signed(vec2)) then C <= '1'; end if;       -- 0 vec1 é expandido para 111110 e fica diferente de vec2			
			if (uvec1 = uvec2) then D <= '1'; end if;                     -- 1 uvec1 é expandido para 001110 e fica igual a uvec2
			if (unsigned(vec1) = uvec1)  then E <= '1'; end if;           -- 1 vec1 é transformado para unsigned e fica igual a uvec1			
			if (vec1 < vec2) then F <= '1'; end if;                       -- 0 Tamanhos diferentes
			if (unsigned(vec1) < unsigned(vec2)) then G <= '1'; end if;   -- 0 vec1 é expandido para 001110 e fica igual a vec2, nao menor
			if (signed(vec1) < signed(vec2)) then H <= '1'; end if;       -- 1 vec1 é expandido para 111110 e fica negativo, logo, menor que vec2
			
			--Para tudo.
			wait for 50 ns;
			wait;			
		end process;
end arch;
