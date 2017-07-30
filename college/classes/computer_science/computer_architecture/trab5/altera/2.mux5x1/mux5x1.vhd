LIBRARY ieee;
USE ieee.std_logic_1164.all;

entity mux5x1 is
	port (
		-- seletor das entradas => i0 a i4
		sel : in std_logic_vector(2 downto 0);
		-- entradas de dados
		i0,i1,i2,i3,i4 : in std_logic_vector(2 downto 0);
		-- saida escolhida
		sai : out std_logic_vector(2 downto 0)
	);
end mux5x1;

architecture arc1 of mux5x1 is
begin

	with sel select
	  sai <= i0 when "000",
		 i1 when "001",
		 i2 when "010",
		 i3 when "011",
		 i4 when "100",
                 (others => 'U') when others; -- cria vetor de 3 bits de U

end arc1;



