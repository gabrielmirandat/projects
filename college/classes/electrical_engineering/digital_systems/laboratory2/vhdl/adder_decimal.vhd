----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:34:16 05/15/2015 
-- Design Name: 
-- Module Name:    somador_saida_decimal - Behavioral 
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
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity somador_saida_decimal is
	port ( A: in STD_LOGIC_VECTOR(3 downto 0); 		--primeira palavra de 4 bits
	       B: in STD_LOGIC_VECTOR(3 downto 0); 		--segunda palavra de 4 bits
		   ck: in STD_LOGIC;							 		--clock da placa
		   digito : out STD_LOGIC_VECTOR (6 downto 0); 	--digito a ser mostrado   
		   displays : out STD_LOGIC_VECTOR (3 downto 0) ); 	--seletor de mostrador
end somador_saida_decimal;

architecture somador_saida_decimal_op of somador_saida_decimal is 
	component somador_2_4bits_BCD is
		port(	A : in STD_LOGIC_VECTOR(3 downto 0);
			B : in STD_LOGIC_VECTOR(3 downto 0);
			D : out STD_LOGIC_VECTOR(3 downto 0);
			U : out STD_LOGIC_VECTOR(3 downto 0));
	end component;

	component BCD_7segmentos is
		port ( D: in STD_LOGIC_VECTOR(3 downto 0); 		--primeira palavra de 4 bits
				U: in STD_LOGIC_VECTOR(3 downto 0); 		--segunda palavra de 4 bits
			   ck: in STD_LOGIC;							 		--clock da placa
		  digito : out STD_LOGIC_VECTOR (6 downto 0); 	--digito a ser mostrado   
		displays : out STD_LOGIC_VECTOR (3 downto 0) ); 	--seletor de mostrador
	end component;

signal D,U : STD_LOGIC_VECTOR(3 downto 0);
begin
	U1: somador_2_4bits_BCD port map(A,B,D,U);
	U2: BCD_7segmentos port map(D,U, ck, digito, displays);
	
end somador_saida_decimal_op;