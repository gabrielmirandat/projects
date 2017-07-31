----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:35:50 05/15/2015 
-- Design Name: 
-- Module Name:    somador_2_4bits_BCD - Behavioral 
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

entity somador_2_4bits_BCD is
	port(	A : in STD_LOGIC_VECTOR(3 downto 0);
		B : in STD_LOGIC_VECTOR(3 downto 0);
		D : out STD_LOGIC_VECTOR(3 downto 0);
		U : out STD_LOGIC_VECTOR(3 downto 0));
end somador_2_4bits_BCD;

architecture somador_2_4bits_BCD_op of somador_2_4bits_BCD is 
	component somador_2_4bits is
		port(A: in STD_LOGIC_VECTOR(3 downto 0);
		       B: in STD_LOGIC_VECTOR(3 downto 0);
		       S: out STD_LOGIC_VECTOR(4 downto 0));
	end component;

	component binario_BCD is
		port(	S: in STD_LOGIC_VECTOR(4 downto 0);  
			D: out STD_LOGIC_VECTOR(3 downto 0); 
			U: out STD_LOGIC_VECTOR(3 downto 0)); 
	end component;

signal S : STD_LOGIC_VECTOR(4 downto 0);
begin
	U1: somador_2_4bits port map(A, B, S);
	U2: binario_BCD port map(S, D, U);
end somador_2_4bits_BCD_op;


