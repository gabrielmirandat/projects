-- A entidade "comparador3bits" compara a palavra A com a palavra B (ambas de 3 bits).
-- Se A > B, X = 1 e Y = 0.
-- Se A < B, X = 0 e Y = 1. 
-- Se A = B, X = 0 e Y = 0. 
-- obs: ver visto 3 do exp. 4

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity comparador3bits is
       port( A,B: in STD_LOGIC_VECTOR(2 downto 0);
             X,Y: out STD_LOGIC);
end comparador3bits;

architecture comparador3bits_arch of comparador3bits is

-- O component "comp1bit" compara o bit Ai com o bit Bi
-- A saída Xi=1 indica que Ai > Bi, enquanto que Yi=1 indica que A < B.
-- Se Ai = Bi, então Xi = 0 e Yi = 0.
-- Entretanto, a entidade leva em consideração o resultado da comparação
-- anterior (bit mais significativo), codificada nas entradas Xiplus1 e Yplus1.
component comparador1bit is
       port( Xiplus1,Yiplus1: in STD_LOGIC;
             Ai,Bi: in STD_LOGIC;
             Xi,Yi: out STD_LOGIC);
end component;

signal X2,Y2,X1,Y1: STD_LOGIC;

begin
  u2: comparador1bit port map('0','0',A(2),B(2),X2,Y2);
  u1: comparador1bit port map(X2,Y2,A(1),B(1),X1,Y1);
  u0: comparador1bit port map(X1,Y1,A(0),B(0),X,Y);        
end comparador3bits_arch;

