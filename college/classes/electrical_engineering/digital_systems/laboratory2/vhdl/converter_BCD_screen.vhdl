library ieee;
use ieee.std_logic_1164.all;

entity BCD_mostrador is	//BCD_mostrador  bin4to7segmentos
	port(	BCD : in STD_LOGIC_VECTOR(3 downto 0);  
		BCDseg: out STD_LOGIC_VECTOR(6 downto 0);
end BCD_mostrador;

architecture BCD_mostrador_op of BCD_mostrador is
signal f: STD_LOGIC_VECTOR(6 downto 0);  
begin

with B select
	f <= 	'1111110' when "0000",
		'0110000' when "0001",
		'1101101' when "0010",
		'1111001' when "0011",
		'0110011' when "0100",
		'1011011' when "0101",
		'1011111' when "0110",
		'1110000' when "0111",
		'1111111' when "1000",
		'1110011' when "1001",
		'1110111' when "1010",
		'0011111' when "1011",
		'1001110' when "1100",
		'0111101' when "1101",
		'1001111' when "1110",
		'1000111' when "1111",
		'0000000' when others;

BCDseg = not(f);

end BCD_mostrador_op ;
