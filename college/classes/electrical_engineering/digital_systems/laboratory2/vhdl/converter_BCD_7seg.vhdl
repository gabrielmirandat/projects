----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:34:16 05/15/2015 
-- Design Name: 
-- Module Name:    BCD_7segmentos - Behavioral 
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

entity BCD_7segmentos is
	port ( D: in STD_LOGIC_VECTOR(3 downto 0); 		--primeira palavra de 4 bits
	       U: in STD_LOGIC_VECTOR(3 downto 0); 		--segunda palavra de 4 bits
          ck: in STD_LOGIC;							 		--clock da placa
	 digito : out STD_LOGIC_VECTOR (6 downto 0); 	--digito a ser mostrado   
  displays : out STD_LOGIC_VECTOR (3 downto 0) ); 	--seletor de mostrador
end BCD_7segmentos;

architecture BCD_7segmentos_op of BCD_7segmentos is 
	component BCD_mostrador is
		port(	BCD : in STD_LOGIC_VECTOR(3 downto 0);  
				BCDseg: out STD_LOGIC_VECTOR(6 downto 0);
	end component;

	component mostrador is
		port ( ck: in STD_LOGIC; 							--clock da placa
		     Dseg:   in STD_LOGIC_VECTOR (6 downto 0);  	--dezenas
		     Useg:   in STD_LOGIC_VECTOR (6 downto 0); 	   --unidades
         digito: out STD_LOGIC_VECTOR (6 downto 0); 	--digito a ser mostrado
	    displays: out STD_LOGIC_VECTOR (3 downto 0));  --seletor de mostrador
	end component;

signal Dseg,Useg : STD_LOGIC_VECTOR(6 downto 0);
begin
	U2: BCD_mostrador port map(D, Dseg);
	U3: BCD_mostrador port map(U, Useg);
	U4: mostrador port map(ck,Dseg,Useg,digito, displays);

end BCD_7segmentos_op;