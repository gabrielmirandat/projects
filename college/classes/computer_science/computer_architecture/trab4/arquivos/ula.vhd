-- inclusão de bibliotecas
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_signed.all;
use ieee.numeric_std.all;
use ieee.std_logic_arith.all;

-- entidade ulamios com entradas e saídas
entity ulamips is
	port ( opULA: 	in  std_logic_vector(3 downto 0);
	         A, B:	in  std_logic_vector(31 downto 0);
	         aluout:	out std_logic_vector(31 downto 0);
	         zero, ovfl:	out std_logic );
end ulamips;

--arquitetura
architecture behavioral of ulamips is
--sinais temporários
   signal tmp, BN : std_logic_vector(31 downto 0); --tmp será A - B e BN será B negado, para fazer o overflow na subtraçao
   signal a32 : std_logic_vector(31 downto 0); -- sinal de saida
	signal A5 : std_logic_vector(31 downto 0); -- sinal que será apenas os 5 bits de A para as operaçoes de rotaçao
begin
  tmp <= A - B;
  aluout <= a32;
  A5 <= A and X"0000001F"; -- A5 recebe os 5 bits LSB de A
  BN <= not B; -- BN recebe B negado para fazer o overflow na subtraçao
  
  proc_ula: process(opULA, A, B, a32, A5, tmp) begin
  --psrs ativar o sinal de zero, verificamos se o sinal é todo igual a zero
      if (a32 = X"00000000") then zero <= '1';  else zero <= '0'; end if; 
		--ovfl recebe zero
		ovfl <= '0';
		-- para ativar o sinal de ovfl, precisamos estar no caso de add ou sub (OP = 0010 ou 0110)
		if opULA = "0010" then
		-- há overflow quando, na soma os MSB dos operandos forem iguais e o MSB do resultado for diferente dos operandos
			if (A(31) xnor B(31)) = '1' and (a32(31) xor A(31))= '1' then ovfl <= '1';
			end if;
		end if;
		
		if opULA = "0110" then 
		-- há overflow quando, na soma os MSB dos operandos forem iguais e o MSB do resultado for diferente dos operandos
		-- então consiiderando uma sub como uma soma de A +(-B), foi criado um sinal BN de B negado
			if (A(31) xnor BN(31)) = '1' and (a32(31) xor A(31))= '1' then ovfl <= '1';
			end if; 
		end if;
		-- para cada código de opULA, ocorre uma operaçao diferente
      case opULA is  
          when  "0000" => a32 <= A and B; -- op E
          when  "0001" => a32 <= A or B; -- op OU
          when  "0010" => a32 <= A + B; -- op SOMA
			 when  "0011" => a32 <= to_stdlogicvector(to_bitvector(B) srl conv_integer(A5)); -- op SRL
			 when  "0100" => a32 <= to_stdlogicvector(to_bitvector(B) sra conv_integer(A5));-- op SRA
			 when  "0101" => a32 <= to_stdlogicvector(to_bitvector(B) sll conv_integer(A5));-- op SLL
          when  "0110" => a32 <= tmp;-- op SUBTRAÇAO			 
			 when  "0111" => a32 <= (0 => tmp(31), others => '0'); -- op SLT
			 --a32 <= 1 se A < B, 0 caso contrário
			 when  "1000" => a32 <= not A; -- op NOT
			 when  "1001" => a32 <= A xor B; -- op XOR
			 when  "1100" => a32 <= A nand B; --op NAND
          when  "1101" => a32 <= A nor B; -- op NOR
          when others  => a32 <= (others => '0'); -- quando não for nenhum dos casos, a sída recebe 0
     end case;
	  end process;
end architecture behavioral;