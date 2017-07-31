----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:12:48 05/15/2015 
-- Design Name: 
-- Module Name:    somador_2_4bits - Behavioral 
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

entity somador_2_4bits is
	port(A: in STD_LOGIC_VECTOR(3 downto 0);
	       B: in STD_LOGIC_VECTOR(3 downto 0);
	       S: out STD_LOGIC_VECTOR(4 downto 0));

end somador_2_4bits;

architecture somador_2_4bits_op of somador_2_4bits is
	component somador_completo is
		port(Cin,A,B: in STD_LOGIC;
	         	         S,Cout: out STD_LOGIC);
	end component;

signal AUXin, C1, C2, C3: STD_LOGIC;
begin
	AUXin <= '0';
	U1:somador_completo port map(AUXin,A(0),B(0),S(0),C1);
	U2:somador_completo port map(      C1,A(1),B(1),S(1),C2);
	U3:somador_completo port map(      C2,A(2),B(2),S(2),C3);
	U4:somador_completo port map(      C3,A(3),B(3),S(3),S(4));


end somador_2_4bits_op;
