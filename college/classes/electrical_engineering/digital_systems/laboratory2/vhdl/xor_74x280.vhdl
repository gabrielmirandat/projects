library IEEE;
use IEEE.std_logic_1164.all;

entity V74x280 is
    port (
	   I: in STD_LOGIC_VECTOR (8 downto 0);
	   EVEN, ODD : out STD_LOGIC
	   ) ;
end V74x280;

architecture arch of V74x280 is
  component vxor3
    port (A, B, C: in STD_LOGIC; Y: out STD_LOGIC);
  end component;
  signal Y1, Y2, Y3, Y3N : STD_LOGIC;
begin
	U1: vxor3 port map (I(0),I(1),I(2),Y1);
	U2: vxor3 port map (I(3),I(4),I(5),Y2);
	U3: vxor3 port map (I(6),I(7),I(8),Y3);
	Y3N <= not Y3;
	U4: vxor3 port map (Y1,Y2,Y3,ODD);
	EVEN <= not ODD;	
 end arch;