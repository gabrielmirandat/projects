----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:01:34 05/08/2015 
-- Design Name: 
-- Module Name:    bin4to7segmentos - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

entity bin4to7segmentos is
	port(	B: in STD_LOGIC_VECTOR(3 downto 0);  
			S: out STD_LOGIC_VECTOR(6 downto 0);  --a b c d e f g
			x,y,z,w: out BIT);								  --saída para AN0
end bin4to7segmentos;

architecture bin4to7segmentos_op of bin4to7segmentos is
	signal f: STD_LOGIC_VECTOR(6 downto 0);  

begin

x <= '0';
y <= '1';
z <= '1';
w <= '1';

with B select
	f <= 	"1111110" when "0000",
			"0110000" when "0001",
			"1101101" when "0010",
			"1111001" when "0011",
			"0110011" when "0100",
			"1011011" when "0101",
			"1011111" when "0110",
			"1110000" when "0111",
			"1111111" when "1000",
			"1110011" when "1001",
			"1110111" when "1010",
			"0011111" when "1011",
			"1001110" when "1100",
			"0111101" when "1101",
			"1001111" when "1110",
			"1000111" when "1111",
			"0000000" when others;

S <= not(f);

end bin4to7segmentos_op;

