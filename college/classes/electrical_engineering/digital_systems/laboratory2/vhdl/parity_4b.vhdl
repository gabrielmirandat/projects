----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    08:35:35 05/08/2015 
-- Design Name: 
-- Module Name:    detector_paridade_4bits - detector_paridade_4bits_op 
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

entity detector_paridade_4bits is
	port(a,b,c,d: in STD_LOGIC;
	           s: out STD_LOGIC);
end detector_paridade_4bits;

architecture detector_paridade_4bits_op of detector_paridade_4bits is
signal e,f: STD_LOGIC;
begin
	e <= a xor b;
	f <= c xor d;
	s <= e xor f;
end detector_paridade_4bits_op;


