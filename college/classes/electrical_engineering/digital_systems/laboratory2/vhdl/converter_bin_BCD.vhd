----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:22:04 05/15/2015 
-- Design Name: 
-- Module Name:    binario_BCD - Behavioral 
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

entity binario_BCD is
	port(	S: in STD_LOGIC_VECTOR(4 downto 0);  
		D: out STD_LOGIC_VECTOR(3 downto 0); 
		U: out STD_LOGIC_VECTOR(3 downto 0)); 
end binario_BCD;

architecture binario_BCD_op of binario_BCD is
begin

  with S select
    U <= "0000" when "00000" | "01010" | "10100" | "11110" ,
			"0001" when "00001" | "01011" | "10101" | "11111" ,
			"0010" when "00010" | "01100" | "10110",
			"0011" when "00011" | "01101" | "10111",
			"0100" when "00100" | "01110" | "11000",
			"0101" when "00101" | "01111" | "11001",
			"0110" when "00110" | "10000" | "11010",
			"0111" when "00111" | "10001" | "11011",
			"1000" when "01000" | "10010" | "11100",
			"1001" when "01001" | "10011" | "11101",
			"0000" when others;

  with S select
    D <="0000" when "00000" | "00001" | "00010" | "00011" | "00100" | "00101" | "00110" | "00111" | "01000" | "01001", 
		  "0001" when "01010" | "01011" | "01100" | "01101" | "01110" | "01111" | "10000" | "10001" | "10010" | "10011",
		  "0010" when "10100" | "10101" | "10110" | "10111" | "11000" | "11001" | "11010" | "11011" | "11100" | "11101",
		  "0011" when   "11110" | "11111",
		  "0000" when others;

end  binario_BCD_op;

