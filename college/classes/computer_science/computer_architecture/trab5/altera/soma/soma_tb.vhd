LIBRARY ieee;
USE ieee.std_logic_1164.all;
use ieee.numeric_std.all;

ENTITY soma_tb IS
END soma_tb;

ARCHITECTURE soma_arch OF soma_tb IS
	-- signals
	SIGNAL a : STD_LOGIC_VECTOR(7 DOWNTO 0);
	SIGNAL b : STD_LOGIC_VECTOR(7 DOWNTO 0);
	SIGNAL result : STD_LOGIC_VECTOR(7 DOWNTO 0);

	COMPONENT soma

	PORT (
		a : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
		b : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
		result : OUT STD_LOGIC_VECTOR(7 DOWNTO 0));
	END COMPONENT;

BEGIN
	i1 : soma
	PORT MAP (
		a => a,
		b => b,
		result => result
	);

	init : PROCESS
	-- variable declarations
	BEGIN
		a <= X"04"; b <= X"05";
		wait for 4 ps;
		
		a <= X"32"; b <= X"05";
		wait for 4 ps;

		a <= X"04"; b <= X"FF";
		wait for 4 ps;
	END PROCESS init;
END soma_arch;