-- a entidade "miniULA" implementa a ULA da questão 3 da prova do 2/2014

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity miniULA is
       port( S: in STD_LOGIC_VECTOR(1 downto 0);
             A: in STD_LOGIC_VECTOR(7 downto 0);
             B: in STD_LOGIC_VECTOR(7 downto 0);
             Cin: in STD_LOGIC;
             F: out STD_LOGIC_VECTOR(7 downto 0);
             Cout: out STD_LOGIC);
end miniULA;

architecture miniULA_arch of miniULA is

component AmaisB is
       port( A: in STD_LOGIC_VECTOR(7 downto 0);
             B: in STD_LOGIC_VECTOR(7 downto 0);
             Cin: in STD_LOGIC;
             F: out STD_LOGIC_VECTOR(7 downto 0);
             Cout: out STD_LOGIC);
end component;

component AmenosB is
       port( A: in STD_LOGIC_VECTOR(7 downto 0);
             B: in STD_LOGIC_VECTOR(7 downto 0);
             Cin: in STD_LOGIC;
             F: out STD_LOGIC_VECTOR(7 downto 0);
             Cout: out STD_LOGIC);
end component;

component BmenosA is
       port( A: in STD_LOGIC_VECTOR(7 downto 0);
             B: in STD_LOGIC_VECTOR(7 downto 0);
             Cin: in STD_LOGIC;
             F: out STD_LOGIC_VECTOR(7 downto 0);
             Cout: out STD_LOGIC);
end component;

component menosA is
       port( A: in STD_LOGIC_VECTOR(7 downto 0);
             F: out STD_LOGIC_VECTOR(7 downto 0);
             Cout: out STD_LOGIC);
end component;

type array4x8 is array (0 to 3) of STD_LOGIC_VECTOR(7 downto 0);

signal F_arith: array4x8;
signal Cout_arith: STD_LOGIC_VECTOR(0 to 3);

begin

   u0: AmaisB port map(A,B,Cin,F_arith(0),Cout_arith(0));
   u1: AmenosB port map(A,B,Cin,F_arith(1),Cout_arith(1));
   u2: BmenosA port map(A,B,Cin,F_arith(2),Cout_arith(2));
   u3: menosA port map(A,F_arith(3),Cout_arith(3));
   
   p0: process(S,A,B,Cin,F_arith,Cout_arith)
   begin
      case S is
         when "00" => F<=F_arith(0); Cout<=Cout_arith(0);
         when "01" => F<=F_arith(1); Cout<=Cout_arith(1);
         when "10" => F<=F_arith(2); Cout<=Cout_arith(2);
         when "11" => F<=F_arith(3); Cout<=Cout_arith(3);
         when others => F<="--------"; Cout<='-';
      end case;
   end process p0;
end miniULA_arch;
