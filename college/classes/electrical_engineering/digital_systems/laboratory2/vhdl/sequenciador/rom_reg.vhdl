library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;

entity rom_reg is
	port(Q: in STD_LOGIC_VECTOR (3 downto 0);
	     CLK: in STD_LOGIC;
	     OC: out STD_LOGIC_VECTOR (2 downto 0);
	     SE: out STD_LOGIC_VECTOR (2 downto 0);
	     D: out UNSIGNED (3 downto 0);
	     S: out STD_LOGIC_VECTOR (3 downto 0));
end rom_reg;

architecture rom_reg_arch of rom_reg is

signal SI: STD_LOGIC_VECTOR(3 downto 0); 	 
begin
process (Q)
--variable LD: STD_LOGIC;
begin
	case Q is
	 when "0000" => OC <="101" ; D <="0100"; SE <="000"; SI <="0000";
	 when "0001" => OC <="010" ; SE <="001"; SI <="0000";
	 when "0010" => OC <="100" ; D <="0101"; SE <="010"; SI <="0000";	 
	 when "0011" => OC <="011" ; D <="1000"; SE <="011"; SI <="1000";	 
	 when "0100" => OC <="010" ; SE <="010"; SI <= "0000";	 
	 when "0101" => OC <="010" ; SE <="100"; SI <="0010";	 
	 when "0110" => OC <="010" ; SE <="101"; SI<="0000";	 
	 when "0111" => OC <="011" ; D<="0000"; SE <="110"; SI<="0001";	 
	 when "1000" => OC <="011" ; D<="0001";SE <="111"; SI<="1100";
	 when others => null;	 
	 end case;
end process;
process(CLK)
begin
if CLK'event and CLK='0' then S<=SI;
end if;
end process;
end rom_reg_arch;
	 
		
	


