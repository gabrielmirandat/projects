library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;

entity nanocont is
	port(I: in STD_LOGIC_VECTOR (7 downto 0);
	     OC: in STD_LOGIC_VECTOR (2 downto 0);
	     SE: in STD_LOGIC_VECTOR (2 downto 0);
	     D: in UNSIGNED (3 downto 0);
	     RES,CLK: in STD_LOGIC;
	     Q: out unsigned (3 downto 0));
end nanocont;

architecture nanocont_arch of nanocont is
component counter port (CLK, CLR_L, LD_L, ENP, ENT: in STD_LOGIC;
		D: in UNSIGNED (3 downto 0);
		Q: out UNSIGNED (3 downto 0);
		RCO: out STD_LOGIC); 
end component;

component mux port (I: in STD_LOGIC_VECTOR (7 downto 0);
		    SE: in STD_LOGIC_VECTOR (2 downto 0);
		    F: out STD_LOGIC);
end component;

signal SZ,CLR_L,RCO,F,LD_L: STD_LOGIC; 
signal DC: UNSIGNED (3 downto 0);
signal ENT: STD_LOGIC:='1';	 
signal ENP: STD_LOGIC;
begin
U1: counter port map (CLK,CLR_L,LD_L,ENP,ENT,DC,Q,RCO);   
U2: MUX port map (I,SE,F);
CLR_L <= not RES;
ENP <= (F and (not OC(2))) or (OC(2) and (not OC(1)));	 
SZ<=OC(2) and OC(1);
process (F,OC,D,SZ)
variable LD: STD_LOGIC;
begin
	LD := (F and OC(2) and (not OC(1)) and (not OC(0))) or 
		(F and (not OC(2)) and OC(0)) or
		(not F and (not OC(1)) and OC(0)) or
		(OC(2) and OC(1) and OC(0));
	LD_L<= not LD;
	if (SZ='1') then DC <= (others => '0'); 
	 else DC <= D;
	 end if;
end process;	 
end nanocont_arch;
	 
		
	



