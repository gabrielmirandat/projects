library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity mostrador is
	Port ( ck: in STD_LOGIC; --clock da placa
	     Dseg:   in STD_LOGIC_VECTOR (6 downto 0); --dezenas
	     Useg:   in STD_LOGIC_VECTOR (6 downto 0); --unidades
	    digito : out STD_LOGIC_VECTOR (6 downto 0); --digito a ser mostrado
   	displays : out STD_LOGIC_VECTOR (3 downto 0) ); --seletor de mostrador
end mostrador;

architecture mostrador_op of mostrador is
	signal cntDiv: STD_LOGIC_VECTOR(28 downto 0); -- general clock div/cnt
	alias clkDisp: STD_LOGIC is cntDiv(16); -- divided clock: 50MHz/2^17=381Hz
begin
	-- CODIGO PARA ALTERNAR ENTRE OS MOSTRADORES AN0 E AN1
	
	ckDivider: process(ck)
	begin
		if ck'event and ck='1' then
			cntDiv <= cntDiv + '1';
		end if;
		
		case clkDisp is
			when '0' =>
				digito <= Dseg;
				displays <= "1110"; -- seleciona mostrador AN0
			when others =>
				digito <= Useg;
				displays <= "1101"; -- seleciona mostrador AN1
		end case;
	end process;
end mostrador_op;
