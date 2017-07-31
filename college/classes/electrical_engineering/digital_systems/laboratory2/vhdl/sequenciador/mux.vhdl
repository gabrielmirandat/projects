library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;

entity mux is
	port(I: in STD_LOGIC_VECTOR (7 downto 0);
	     SE: in STD_LOGIC_VECTOR (2 downto 0);
	     F: out STD_LOGIC);
end mux;

architecture mux_arch of mux is	 
begin
process (I,SE)
begin
	case SE is
	when "000" => F <=I(0);
	when "001" => F <=I(1);
	when "010" => F <=I(2);
	when "011" => F <=I(3);
	when "100" => F <=I(4);
	when "101" => F <=I(5);
	when "110" => F <=I(6);
	when "111" => F <=I(7);
	when others => F <='U';
	end case;
end process;
end mux_arch;
		 
		
	
