-- inclusão das bibliotecas

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_signed.all;

-- entidade da ula_tb não recebe entradas nem saidas, é apenas testador
entity ula_tb is
end ula_tb;
-- arquitetura estrututal
architecture estrutural of ula_tb is
-- possui um componente ulamips
	component ulamips
		port(opULA: 	in  std_logic_vector(3 downto 0);
	         A, B:	in  std_logic_vector(31 downto 0);
	         aluout:	out std_logic_vector(31 downto 0);
	         zero, ovfl:	out std_logic);
	end component;
	-- possui sinais para representar cada uma das entradas e saídas
		signal opULA1 : std_logic_vector(3 downto 0);
		signal a1,b1, aluout1: std_logic_vector(31 downto 0);
		signal zero1, ovfl1: std_logic;
begin
	-- o componente ula1 é do tipo ulamips e os sinais são atribuídos às entradas e saidas
		ula1: ulamips port map (opULA=>opULA1, A=>a1, B=> b1, aluout=> aluout1, zero =>zero1, ovfl=> ovfl1);

	-- início do processo
	process
	begin
	-- a1 e b1 são inicializados para podemos realizar o testes
		a1 <= X"00001111";
		b1 <= X"00002222";
		-- opULA recebe os variados valores possíveis para testar cada caso e um espaço de 10s é dado para se visualizar
		opULA1 <= "0000"; -- op AND
		wait for 10 ns;	
		opULA1 <= "0001" after 10 ns; -- op OR
		wait for 10 ns;		
		opULA1 <= "0010" after 10 ns; -- op SOMA	
		wait for 10 ns;
		a1 <= X"80001111"; -- coloco outros valores em a1 e b1 para poder visualizar o overflow em 1
		b1 <= X"80002222";
		opULA1 <= "0011" after 10 ns; -- op SRL
		wait for 10 ns;
		opULA1 <= "0100" after 10 ns; -- op SRA
		wait for 10 ns;
		opULA1 <= "0101" after 10 ns;-- op SLL
		wait for 10 ns;
		opULA1 <= "0110" after 10 ns;-- op SUBTRAÇAO
		wait for 10 ns;
		opULA1 <= "0111" after 10 ns; -- op SLT
		wait for 10 ns;
		opULA1 <= "1000" after 10 ns;-- op NOT
		wait for 10 ns;
		opULA1 <= "1001" after 10 ns;-- op XOR
		wait for 10 ns;
		opULA1 <= "1100" after 10 ns;-- op NAND
		wait for 10 ns;
		opULA1 <= "1101" after 10 ns;-- op NOR
		wait for 10 ns;
			
		wait;
	end process;

end estrutural;

