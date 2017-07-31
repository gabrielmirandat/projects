----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:11:49 05/15/2015 
-- Design Name: 
-- Module Name:    somador_completo - Behavioral 
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

entity somador_completo is
	port(Cin,A,B: in STD_LOGIC;
	         S,Cout: out STD_LOGIC);
end somador_completo;

architecture somador_completo_op of somador_completo is
begin
	S <= Cin xor (A xor B);
	Cout <= (A and B) or (Cin and(A xor B));
end somador_completo_op;
