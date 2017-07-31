library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity mul_3bits is
	port ( A: in STD_LOGIC_VECTOR (2 downto 0);	
	       B: in STD_LOGIC_VECTOR (2 downto 0);
	      PH: out STD_LOGIC_VECTOR (2 downto 0);
	      PL: out STD_LOGIC_VECTOR (2 downto 0));
end mul_3bits;

architecture arch of mul_3bits is
	component somador_completo is
		port ( A, B, Cin: in STD_LOGIC;
			 S, Cout: out STD_LOGIC);
	end component;
	
	type array3x3 is array (0 to 2) of STD_LOGIC_VECTOR (2 downto 0);
	signal termo : array3x3; 
	signal S2,S4,C1,C2,C3,C4,C5,C6: STD_LOGIC;
begin
--Arquitetura do multiplicador de 3 bits
	
	termo(0)(0) <= B(0) and A(0);
	termo(0)(1) <= B(0) and A(1);
	termo(0)(2) <= B(0) and A(2);
	termo(1)(0) <= B(1) and A(0);
	termo(1)(1) <= B(1) and A(1);
	termo(1)(2) <= B(1) and A(2);
	termo(2)(0) <= B(2) and A(0);
	termo(2)(1) <= B(2) and A(1);
	termo(2)(2) <= B(2) and A(2);
	
	PL(0) <= termo(0)(0);
	
	U1: somador_completo port map (termo(0)(1),termo(1)(0),'0',PL(1), C1);
	
	U2: somador_completo port map (termo(0)(2),termo(1)(1),C1,S2, C2);
	U3: somador_completo port map (S2,termo(2)(0),'0',PL(2), C3);
	
	U4: somador_completo port map (termo(1)(2),termo(2)(1),C2,S4, C4);
	U5: somador_completo port map (S4,C3,'0',PH(0), C5);
	
	U6: somador_completo port map (termo(2)(2), C4, C5, PH(1), C6);

	PH(2)<= C6;
end arch;



