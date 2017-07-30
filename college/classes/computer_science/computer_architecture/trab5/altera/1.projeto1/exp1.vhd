LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY projeto1 IS
	PORT ( iSW : IN STD_LOGIC_VECTOR(17 DOWNTO 0);
	oLEDR  : OUT STD_LOGIC_VECTOR(17 DOWNTO 0)); -- red LEDs
END projeto1;

ARCHITECTURE Behavior OF projeto1 IS 
BEGIN
	oLEDR <= iSW;
END Behavior;