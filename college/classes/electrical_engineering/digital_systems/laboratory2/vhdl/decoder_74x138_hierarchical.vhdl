library IEEE;
use IEEE.std_logic_1164.all;

entity V74x138 is
  port (G1, G2A_L, G2B_L: in  STD_LOGIC;
                       A: in  STD_LOGIC_VECTOR (2 downto 0);
		             Y_L: out STD_LOGIC_VECTOR (7 downto 0));
end V74x138;

architecture arch2 of V74x138 is
  signal G2A, G2B : STD_LOGIC;
  signal Y : STD_LOGIC_VECTOR (7 downto 0);
  component V3to8dec port (G1, G2A, G2B: in STD_LOGIC;
                           A: in STD_LOGIC_VECTOR (2 downto 0);
						   Y: out STD_LOGIC_VECTOR (7 downto 0));
  end component;
begin
  G2A <= not G2A_L;
  G2B <= not G2B_L;
  Y_L <= not Y;
  U1: V3to8dec port map (G1, G2A, G2B, A, Y);
end arch2;  
