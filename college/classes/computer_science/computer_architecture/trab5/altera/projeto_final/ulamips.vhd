library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.mips_pkg.all;

entity ulamips is
	generic (
		SIZE : natural := 32
		);
	port (
		aluctl		: 	in  std_logic_vector(3 downto 0);
		A, B			:	in  std_logic_vector(SIZE-1 downto 0);
		aluout		:	out std_logic_vector(SIZE-1 downto 0);
		zero  		:	out std_logic
		);
end ulamips;

architecture behavioral of ulamips is

signal tmp : std_logic_vector(SIZE-1 downto 0); 
signal a32 : std_logic_vector(SIZE-1 downto 0);

begin
	tmp <= std_logic_vector(signed(A) - signed(B));
	
ula: process (A, B, aluctl, a32, tmp) 
	begin
		case aluctl is
		when ULA_AND => a32 <= (A and B);
		when ULA_OR  => a32 <= (A or B);
		when ULA_NOR => a32 <= (A nor B);
		when ULA_XOR => a32 <= (A xor B);
		when ULA_ADD => a32 <= std_logic_vector(signed(A) + signed(B));
		when ULA_SUB => a32 <=  tmp;
		when ULA_SLT => a32 <= (0=>tmp(SIZE-1), others=>'0');
		when ULA_SLL => a32 <= std_logic_vector(unsigned(B) sll  TO_INTEGER(unsigned(A)));
		when ULA_SRL => a32 <= std_logic_vector(unsigned(B) srl  TO_INTEGER(unsigned(A)));
		when others  => a32 <= (others=>'0');
	end case;
end process;

		
	aluout <= a32;
	
	zero <= '1' when (tmp = ZERO32) else '0';
			   
end architecture behavioral;
