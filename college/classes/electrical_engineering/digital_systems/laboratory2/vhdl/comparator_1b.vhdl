----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:29:56 05/08/2015 
-- Design Name: 
-- Module Name:    compara_bit - Behavioral 
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

entity compara_bit is
	port(	Ai , Bi , xj , yj : in STD_LOGIC;
						  xi , yi: out STD_LOGIC);
end compara_bit;

architecture compara_bit_op of compara_bit is 
signal xyAB: STD_LOGIC_VECTOR(3 downto 0);

begin
xyAB <= xj & yj & Ai & Bi;

with xyAB select
	xi <= 	'0' when "0000" | "0011",
				'0' when "0001" | "01--",
				'1' when "0010" | "10--",
				'-' when others;

with xyAB select				
	yi <= 	'0' when "0000" | "0011",
				'1' when "0001" | "01--",
				'0' when "0010" | "10--",
				'-' when others;

end compara_bit_op;

