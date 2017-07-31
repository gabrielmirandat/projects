----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:26:49 05/09/2015 
-- Design Name: 
-- Module Name:    compara_duas_4bit - Behavioral 
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

entity compara_duas_4bit is
	port(	A : in STD_LOGIC_VECTOR(3 downto 0);
			B : in STD_LOGIC_VECTOR(3 downto 0);
	   xi,yi: out STD_LOGIC);
end compara_duas_4bit;

architecture compara_duas_4bit_op of compara_duas_4bit is 
	component compara_bit is
		port(	Ai , Bi , xj , yj : in STD_LOGIC;
							 xi ,  yi: out STD_LOGIC);
		end component;

	signal p1,p2,p3,p4,p5,p6: STD_LOGIC;
	signal ini: STD_LOGIC;
begin
	ini <='0';
	U1:compara_bit port map(A(3),B(3),ini,ini, p1, p2);
	U2:compara_bit port map(A(2),B(2), p1, p2, p3, p4);
	U3:compara_bit port map(A(1),B(1), p3, p4, p5, p6);
	U4:compara_bit port map(A(0),B(0), p5, p6, xi, yi);

end compara_duas_4bit_op;


