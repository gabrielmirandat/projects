library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;

entity rom_reg_TB is
end rom_reg_TB;

architecture rom_reg_TB_arch of rom_reg_TB is
component counter port (CLK, CLR_L, LD_L, ENP, ENT: in STD_LOGIC;
		D: in UNSIGNED (3 downto 0);
		Q: out UNSIGNED (3 downto 0);
		RCO: out STD_LOGIC); 
end component;
component rom_reg port(Q: in UNSIGNED (3 downto 0);
	     CLK: in STD_LOGIC;
	     OC: out STD_LOGIC_VECTOR (2 downto 0);
	     SE: out STD_LOGIC_VECTOR (2 downto 0);
	     D: out UNSIGNED (3 downto 0);
	     S: out STD_LOGIC_VECTOR (3 downto 0));
end component;
signal CLK,CLR_L: STD_LOGIC:='0';
signal LD_L,ENP,ENT: STD_LOGIC:='1';
signal D: UNSIGNED(3 downto 0):="1001";
signal DR: UNSIGNED(3 downto 0);
signal RCO: STD_LOGIC;
signal Q: UNSIGNED (3 downto 0);
signal OC: STD_LOGIC_VECTOR (2 downto 0);
signal SE: STD_LOGIC_VECTOR (2 downto 0);
signal S: STD_LOGIC_VECTOR (3 downto 0);
begin
	U1: counter port map (CLK,CLR_L,LD_L,ENP,ENT,D,Q,RCO);
	U2: rom_reg port map (Q,CLK,OC,SE,DR,S);
	CLK <= not CLK after 30 ns;
	CLR_L <= '1' after 60 ns;
end rom_reg_TB_arch;



