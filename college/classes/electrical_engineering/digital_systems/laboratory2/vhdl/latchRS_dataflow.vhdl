library ieee;
use ieee.std_logic_1164.all;

entity Vsrlatch is
	Port (S,R: in STD_LOGIC;
		Q, QN: buffer STD_LOGIC);	--usada tanto como entrada como saída
	end Vsrlatch;

architecture VSRlatch_arch of VsrLatch is
begin
	QN <= S nor Q;
	Q <= R nor QN after 1 ms;
end Vsrlatch_arch;
