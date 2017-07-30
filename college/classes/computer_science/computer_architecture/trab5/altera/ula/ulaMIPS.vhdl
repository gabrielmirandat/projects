library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_signed.all;
use ieee.numeric_std.all;
use ieee.std_logic_arith.all;

--Operacao 			Significado 																OpCode
--add A, B 			Saida Z recebe a soma das entradas A, B incluindo o vem-um 	000
--sub A, B 			Saida Z recebe A - B 													001
--and A, B 			Saida Z recebe a operacao logica A and B, bit a bit 			010
--or A, B 			Saida Z recebe a operacao logica A or B, bit a bit 			011
--not A 				Saida Z recebe a entrada A invertida bit a bit 					100
--xor A, B 			Saida Z recebe a operacao logica A xor B, bit a bit 			101
--bypass A 			Saida Z recebe A, sem alteracao 										110
--slt A, B 			Z = 1 se A < B 															111

entity ulaMIPS is
	port (
		opcode : in std_logic_vector(2 downto 0);
		A, B : in std_logic_vector(31 downto 0);
		Z : out std_logic_vector(31 downto 0);
		zero, ovfl : out std_logic);
end ulaMIPS;


--using if_then_else
architecture ulaMIPS_if_then_else of ulaMIPS is
begin
	process(opcode, A, B)
		variable Reg3 : std_logic_vector(31 downto 0);
	begin
	
	if(opcode="000") --adicao
	then	Reg3 := A + B;  
			--caso de Reg3=0
			if(Reg3=X"00000000") then zero <='1'; else zero <='0'; end if;
			--caso de overflow
			if ((A(31)='0' and B(31)='0' and Reg3(31)='1') or (A(31)='1' and B(31)='1' and Reg3(31)='0')) then ovfl<='1';
			else ovfl<='0'; end if;
	elsif(opcode="001") --subtracao
	then	Reg3 := A - B; 
			--caso de Reg3=0
			if(Reg3=X"00000000") then zero <='1'; else zero <='0'; end if;
			--caso de overflow
			if ((A(31)='0' and B(31)='1' and Reg3(31)='1') or (A(31)='1' and B(31)='0' and Reg3(31)='0')) then ovfl<='1';
			else ovfl<='0'; end if;
	elsif(opcode="010") --and
	then	Reg3 := A and B;
			--caso de Reg3=0
			if(Reg3=X"00000000") then zero <='1'; else zero <='0'; end if;
			ovfl<='0';
	elsif(opcode="011") --or
	then 	Reg3 := A or B; 
			--caso de Reg3=0
			if(Reg3=X"00000000") then zero <='1'; else zero <='0'; end if;
			ovfl<='0';
	elsif(opcode="100") --not
	then 	Reg3 := not A; 
			--caso de Reg3=0
			if(Reg3=X"00000000") then zero <='1'; else zero <='0'; end if;
			ovfl<='0';
	elsif(opcode="101") --xor					
   then    Reg3 := A xor B; 
			--caso de Reg3=0 
			if(Reg3=X"00000000") then zero <='1'; else zero <='0'; end if;
			ovfl<='0';
	elsif(opcode="110") --bypass
	then 	Reg3 := A; 
			--caso de Reg3=0
			if(Reg3=X"00000000") then zero <='1'; else zero <='0'; end if;
			ovfl<='0';
   else --slt
	   	if(A < B) then Reg3 := X"00000001"; else Reg3 := X"00000000"; end if; 
			--caso de Reg3=0 
			if(Reg3=X"00000000") then zero <='1'; else zero <='0'; end if;
			ovfl<='0';
	end if;
	Z <= Reg3;
   end process;
end ulaMIPS_if_then_else;


--usign with-select
architecture ulaMIPS_concorrente of ulaMIPS is
 
	--declaracao de sinais temporarios
	signal Reg3,auxSLT : std_logic_vector(31 downto 0);
	signal auxOVFL_sum, auxOVFL_dif : std_logic;

begin
	with opcode select
	Reg3 <=  	A + B		when "000",	--adicao
					A - B		when "001",	--subtracao
					A and B	when "010",	--and
					A or B	when "011",	--or
					not A		when "100",	--not
					A xor B	when "101",	--xor
					A			when "110",	--bypass
					auxSLT	when others;--slt
	
	
	auxSLT <= X"00000001" when A < B else
	          X"00000000";
			  
	auxOVFL_sum  <= '1' when (A(31)='0' and B(31)='0' and Reg3(31)='1') or (A(31)='1' and B(31)='1' and Reg3(31)='0') 
							  else '0';
	                
	auxOVFL_dif  <= '1' when (A(31)='0' and B(31)='1' and Reg3(31)='1') or (A(31)='1' and B(31)='0' and Reg3(31)='0') 
							  else '0';
	
	zero  <= '1' when Reg3=X"00000000" 
					 else '0';
			  
	with opcode select
	ovfl <= 	auxOVFL_sum	when "000",
				auxOVFL_dif	when "001",
				'0'		when others;

	Z <= Reg3;
				
end ulaMIPS_concorrente;

--using case
architecture ulaMIPS_case of ulaMIPS is
begin
	process(opcode, A, B)
		variable Reg3 : std_logic_vector(31 downto 0);
	begin
	case opcode is
				when "000" => --adicao
								Reg3 := A + B;  
								--caso de Reg3=0
								if(Reg3=X"00000000") then zero <='1'; else zero <='0'; end if;
								--caso de overflow
								if ((A(31)='0' and B(31)='0' and Reg3(31)='1') or (A(31)='1' and B(31)='1' and Reg3(31)='0')) then ovfl<='1';
								else ovfl<='0'; end if;
				when "001" => --subtracao
								Reg3 := A - B; 
								--caso de Reg3=0
								if(Reg3=X"00000000") then zero <='1'; else zero <='0'; end if;
								--caso de overflow
								if ((A(31)='0' and B(31)='1' and Reg3(31)='1') or (A(31)='1' and B(31)='0' and Reg3(31)='0')) then ovfl<='1';
								else ovfl<='0'; end if;
            when "010" => --and
								Reg3 := A and B;
								--caso de Reg3=0
								if(Reg3=X"00000000") then zero <='1'; else zero <='0'; end if;
								ovfl<='0';
            when "011" => --or
								Reg3 := A or B; 
								--caso de Reg3=0
								if(Reg3=X"00000000") then zero <='1'; else zero <='0'; end if;
								ovfl<='0';
            when "100" => --not
								Reg3 := not A; 
								--caso de Reg3=0
								if(Reg3=X"00000000") then zero <='1'; else zero <='0'; end if;
								ovfl<='0';
            when "101" => --xor
								Reg3 := A xor B; 
								--caso de Reg3=0 
								if(Reg3=X"00000000") then zero <='1'; else zero <='0'; end if;
								ovfl<='0';
            when "110" => --bypass
								Reg3 := A; 
								--caso de Reg3=0
								if(Reg3=X"00000000") then zero <='1'; else zero <='0'; end if;
								ovfl<='0';
            when others => --slt
								if(A < B) then Reg3 := X"00000001"; else Reg3 := X"00000000"; end if; 
								--caso de Reg3=0 
								if(Reg3=X"00000000") then zero <='1'; else zero <='0'; end if;
								ovfl<='0';
	   end case;
		Z <= Reg3;
      end process;
end ulaMIPS_case;

configuration conf_ulaMIPS_if_then_else of ulaMIPS is 

	for ulaMIPS_if_then_else
	end for;

end conf_ulaMIPS_if_then_else;

configuration conf_ulaMIPS_concorrente of ulaMIPS is 

	for ulaMIPS_concorrente
	end for;

end conf_ulaMIPS_concorrente;

configuration conf_ulaMIPS_case of ulaMIPS is 

	for ulaMIPS_case
	end for;

end conf_ulaMIPS_case;




