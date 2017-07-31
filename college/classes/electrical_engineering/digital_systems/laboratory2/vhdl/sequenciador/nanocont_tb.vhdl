library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;

entity nanocont_TB is
end nanocont_TB;

architecture nanocont_TB_arch of nanocont_TB is
component nanocont port(I: in STD_LOGIC_VECTOR (7 downto 0);
	     OC: in STD_LOGIC_VECTOR (2 downto 0);
	     SE: in STD_LOGIC_VECTOR (2 downto 0);
	     D: in UNSIGNED (3 downto 0);
	     RES,CLK: in STD_LOGIC;
	     Q: out unsigned (3 downto 0));
end component;
component rom_reg port(Q: in UNSIGNED (3 downto 0);
	     CLK: in STD_LOGIC;
	     OC: out STD_LOGIC_VECTOR (2 downto 0);
	     SE: out STD_LOGIC_VECTOR (2 downto 0);
	     D: out UNSIGNED (3 downto 0);
	     S: out STD_LOGIC_VECTOR (3 downto 0));
end component;
signal ST,RCD,CL,EJT,MOK,OP,PL,CD: STD_LOGIC:='0';
signal I: STD_LOGIC_VECTOR (7 downto 0);
signal OC: STD_LOGIC_VECTOR (2 downto 0);
signal SE: STD_LOGIC_VECTOR (2 downto 0);
signal D: UNSIGNED(3 downto 0);
signal CLK: STD_LOGIC:='0';
signal RES: STD_LOGIC:='1';
signal Q: unsigned (3 downto 0);
signal S: STD_LOGIC_VECTOR (3 downto 0);
begin
	U1: nanocont port map (I,OC,SE,D,RES,CLK,Q);
	U2: rom_reg port map (Q,CLK,OC,SE,D,S);
	CLK <= not CLK after 30 ns;
	RES <= '0' after 60 ns;
	I(7)<=ST;
	I(6)<=RCD;
	I(5)<=CL;
	I(4)<=EJT;
	I(3)<=MOK;
	I(2)<=OP;
	I(1)<=OP or PL;
	I(0)<=CD;
process 
begin
 wait for 95 ns;
 OP<='1', '0' after 80 ns;
 wait for 80 ns;
 EJT<='1', '0' after 80 ns;
 wait for 80 ns;
 CL <='1','0' after 80 ns;
 wait for 80 ns;
 RCD<='1','0' after 80 ns;
 wait for 80 ns;
 CD<='1';
 wait for 80 ns;
 PL<='1','0' after 80 ns;
 wait for 80 ns;
 MOK<='1';
 wait for 80 ns;
 ST<='1', '0' after 80 ns;
 wait;
 end process;
end nanocont_TB_arch;





