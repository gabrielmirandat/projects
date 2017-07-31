library ieee;
use ieee.std_logic_1164.all;

entity somador_completo is
	port ( A, B, Cin: in STD_LOGIC;
		S, Cout: out STD_LOGIC);
end somador_completo;

architecture somador_completo_op of somador_completo is
begin
	S <= Cin xor (A xor B);
        Cout <= (A and B) or (Cin and(A xor B));
end somador_completo_op;


