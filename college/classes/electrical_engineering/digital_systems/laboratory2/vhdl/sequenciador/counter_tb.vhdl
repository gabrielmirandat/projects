library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;

entity counter_TB is
end counter_TB;

architecture counter_TB_arch of counter_TB is
component counter port (CLK, CLR_L, LD_L, ENP, ENT: in STD_LOGIC;
		D: in UNSIGNED (3 downto 0);
		Q: out UNSIGNED (3 downto 0);
		RCO: out STD_LOGIC); end component;
signal CLK,ENP,ENT: STD_LOGIC:='0';
signal CLR_L,LD_L: STD_LOGIC:='1';
signal D: UNSIGNED(3 downto 0):="1001";
signal RCO: STD_LOGIC;
signal Q: UNSIGNED (3 downto 0);
begin
	U1: counter port map (CLK,CLR_L,LD_L,ENP,ENT,D,Q,RCO);
	CLK <= not CLK after 30 ns;
	process
	begin
	wait for 40 ns;
	ENP <='1';
	wait for 40 ns;
	ENT <='1';
	wait for 40 ns;
	CLR_L <='0';
	wait for 40 ns;
	CLR_L <='1';
	wait for 100 ns;
	LD_L <='0';
	wait for 40 ns;
	LD_L <='1';
	wait for 200 ns;
	end process;
	end counter_TB_arch;
