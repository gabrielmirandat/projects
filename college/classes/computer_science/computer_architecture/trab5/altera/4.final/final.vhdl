library ieee;
use ieee.std_logic_1164.all;

entity final is
	port(	SW : in STD_LOGIC_VECTOR(16 downto 0);
		segs_final: out STD_LOGIC_VECTOR(6 downto 0);
end somador_2_4bits_BCD;

architecture arc1 of final is 
	component mux5x1 is
	port (  -- seletor das entradas => i0 a i4
		sel : in std_logic_vector(2 downto 0);
		-- entradas de dados
		i0,i1,i2,i3,i4 : in std_logic_vector(2 downto 0);
		-- saida escolhida
		sai : out std_logic_vector(2 downto 0));
	end component;

	component seteseg is
		port (codigo : in std_logic_vector (2 downto 0);
		      segs : out std_logic_vector (6 downto 0));
	end component;

signal S,A,B,C,D,E,SAI,COD : STD_LOGIC_VECTOR(2 downto 0);
signal SEGS : STD_LOGIC_VECTOR(6 downto 0);
begin
	U1: mux5x1 port map(S,A,B,C,D,E,SAI);
	U2: seteseg port map(COD,SEGS);
	
	S <= SW(17 downto 15);
	A <= SW(14 downto 12);
	B <= SW(11 downto 9);
	C <= SW(8 downto 6);
	D <= SW(5 downto 3);
	E <= SW(2 downto 0);
	COD <= SAI;
	
	segs_final <= SEGS; 
end arc1;



