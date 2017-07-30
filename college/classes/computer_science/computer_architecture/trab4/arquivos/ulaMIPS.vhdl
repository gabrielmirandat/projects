library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_signed.all;
use ieee.numeric_std.all;
use ieee.std_logic_arith.all;

--Operacao 			Significado 																			OpCode
--add Reg1, Reg2 	Saida Reg3 recebe a soma das entradas Reg1, Reg2 incluindo o vem-um 	000
--sub Reg1, Reg2 	Saida Reg3 recebe Reg1 - Reg2 													001
--and Reg1, Reg2 	Saida Reg3 recebe a operacao logica Reg1 and Reg2, bit a bit 			010
--or Reg1, Reg2 	Saida Reg3 recebe a operacao logica Reg1 or Reg2, bit a bit 			011
--not Reg1 			Saida Reg3 recebe a entrada Reg1 invertida bit a bit 						100
--xor Reg1, Reg2 	Saida Reg3 recebe a operacao logica Reg1 xor Reg2, bit a bit 			101
--bypass Reg1 		Saida Reg3 recebe Reg1, sem alteracao 											110
--slt Reg1, Reg2 	Reg3 = 1 se Reg1 < Reg2 															111

entity ulaMIPS is
	port (
		opcode : in std_logic_vector(2 downto 0);
		A, B : in std_logic_vector(31 downto 0);
		Z : out std_logic_vector(31 downto 0);
		zero, ovfl : out std_logic);
end ulaMIPS;


--using if_then_else
architecture ulaMIPS_if_then_else of ulaMIPS is
 
	--declaracao de sinais temporarios
	signal Reg1,Reg2,Reg3 : std_logic_vector(31 downto 0);
	signal Rzero, Rovfl : std_logic;

begin
 
	Reg1 <= A;
	Reg2 <= B;
	Z <= Reg3;
	zero <= Rzero;
	ovfl <= Rovfl;
	
	process(Reg3)
	begin
	
	if(opcode="000") --adicao
	then	Reg3 <= Reg1 + Reg2;  
			--caso de Reg3=0
			if(Reg3=X"00000000") then Rzero <='1'; else Rzero <='0'; end if;
			--caso de overflow
			if ((Reg1(31)='0' and Reg2(31)='0' and Reg3(31)='1') or (Reg1(31)='1' and Reg2(31)='1' and Reg3(31)='0')) then Rovfl<='1';
			else Rovfl<='0'; end if;
	elsif(opcode="001") --subtracao
	then	Reg3 <= Reg1 - Reg2; 
			--caso de Reg3=0
			if(Reg3=X"00000000") then Rzero <='1'; else Rzero <='0'; end if;
			--caso de overflow
			if ((Reg1(31)='0' and Reg2(31)='1' and Reg3(31)='1') or (Reg1(31)='1' and Reg2(31)='0' and Reg3(31)='0')) then Rovfl<='1';
			else Rovfl<='0'; end if;
	elsif(opcode="010") --and
	then	Reg3 <= Reg1 and Reg2;
			--caso de Reg3=0
			if(Reg3=X"00000000") then Rzero <='1'; else Rzero <='0'; end if;
			Rovfl<='0';
	elsif(opcode="011") --or
	then 	Reg3 <= Reg1 or Reg2; 
			--caso de Reg3=0
			if(Reg3=X"00000000") then Rzero <='1'; else Rzero <='0'; end if;
			Rovfl<='0';
	elsif(opcode="100") --not
	then 	Reg3 <= not Reg1; 
			--caso de Reg3=0
			if(Reg3=X"00000000") then Rzero <='1'; else Rzero <='0'; end if;
			Rovfl<='0';
	elsif(opcode="101") --xor					
   then    Reg3 <= Reg1 xor Reg2; 
			--caso de Reg3=0 
			if(Reg3=X"00000000") then Rzero <='1'; else Rzero <='0'; end if;
			Rovfl<='0';
	elsif(opcode="110") --bypass
	then 	Reg3 <= Reg1; 
			--caso de Reg3=0
			if(Reg3=X"00000000") then Rzero <='1'; else Rzero <='0'; end if;
			Rovfl<='0';
   else --slt
	   	if(Reg1 < Reg2) then Reg3 <= X"00000001"; else Reg3 <= X"00000000"; end if; 
			--caso de Reg3=0 
			if(Reg3=X"00000000") then Rzero <='1'; else Rzero <='0'; end if;
			Rovfl<='0';
	end if;
   end process;
end ulaMIPS_if_then_else;


--usign with-select
architecture ulaMIPS_concorrente of ulaMIPS is
 
	--declaracao de sinais temporarios
	signal Reg1,Reg2,Reg3,auxSLT : std_logic_vector(31 downto 0);
	signal Rzero, Rovfl, auxOVFL_sum, auxOVFL_dif : std_logic;

begin
	Reg1 <= A;
	Reg2 <= B;
	Z <= Reg3;
	zero <= Rzero;
	ovfl <= Rovfl;
	
	auxSLT <= X"00000001" when Reg1 < Reg2 else
	          X"00000000";
			  
	auxOVFL_sum  <= '1' when (Reg1(31)='0' and Reg2(31)='0' and Reg3(31)='1') or (Reg1(31)='1' and Reg2(31)='1' and Reg3(31)='0') else
	                '0';
	                
	auxOVFL_dif  <= '1' when (Reg1(31)='0' and Reg2(31)='1' and Reg3(31)='1') or (Reg1(31)='1' and Reg2(31)='0' and Reg3(31)='0') else
			'0';
	
	Rzero  <= '1' when Reg3=X"00000000" else
	          '0';
			  
	with opcode select
	Rovfl <= 	auxOVFL_sum	when "000",
			auxOVFL_dif	when "001",
			'0'		when others;
	
	
	with opcode select
	Reg3 <=  	Reg1 + Reg2	when "000",	--adicao
			Reg1 - Reg2	when "001",	--subtracao
			Reg1 and Reg2	when "010",	--and
			Reg1 or Reg2	when "011",	--or
			not Reg1	when "100",	--not
			Reg1 xor Reg2	when "101",	--xor
			Reg1		when "110",	--bypass
			auxSLT		when others;	--slt
				
end ulaMIPS_concorrente;

--using case
architecture ulaMIPS_case of ulaMIPS is
 
	--declaracao de sinais temporarios
	signal Reg1,Reg2,Reg3 : std_logic_vector(31 downto 0);
	signal Rzero, Rovfl : std_logic;

begin
 
	Reg1 <= A;
	Reg2 <= B;
	Z <= Reg3;
	zero <= Rzero;
	ovfl <= Rovfl;
	
	process(opcode,Reg1,Reg2,Reg3,Rzero,Rovfl)
	begin
	case opcode is
				when "000" => --adicao
								Reg3 <= Reg1 + Reg2;  
								--caso de Reg3=0
								if(Reg3=X"00000000") then Rzero <='1'; else Rzero <='0'; end if;
								--caso de overflow
								if ((Reg1(31)='0' and Reg2(31)='0' and Reg3(31)='1') or (Reg1(31)='1' and Reg2(31)='1' and Reg3(31)='0')) then Rovfl<='1';
								else Rovfl<='0'; end if;
				when "001" => --subtracao
								Reg3 <= Reg1 - Reg2; 
								--caso de Reg3=0
								if(Reg3=X"00000000") then Rzero <='1'; else Rzero <='0'; end if;
								--caso de overflow
								if ((Reg1(31)='0' and Reg2(31)='1' and Reg3(31)='1') or (Reg1(31)='1' and Reg2(31)='0' and Reg3(31)='0')) then Rovfl<='1';
								else Rovfl<='0'; end if;
            when "010" => --and
								Reg3 <= Reg1 and Reg2;
								--caso de Reg3=0
								if(Reg3=X"00000000") then Rzero <='1'; else Rzero <='0'; end if;
								Rovfl<='0';
            when "011" => --or
								Reg3 <= Reg1 or Reg2; 
								--caso de Reg3=0
								if(Reg3=X"00000000") then Rzero <='1'; else Rzero <='0'; end if;
								Rovfl<='0';
            when "100" => --not
								Reg3 <= not Reg1; 
								--caso de Reg3=0
								if(Reg3=X"00000000") then Rzero <='1'; else Rzero <='0'; end if;
								Rovfl<='0';
            when "101" => --xor
								Reg3 <= Reg1 xor Reg2; 
								--caso de Reg3=0 
								if(Reg3=X"00000000") then Rzero <='1'; else Rzero <='0'; end if;
								Rovfl<='0';
            when "110" => --bypass
								Reg3 <= Reg1; 
								--caso de Reg3=0
								if(Reg3=X"00000000") then Rzero <='1'; else Rzero <='0'; end if;
								Rovfl<='0';
            when others => --slt
								if(Reg1 < Reg2) then Reg3 <= X"00000001"; else Reg3 <= X"00000000"; end if; 
								--caso de Reg3=0 
								if(Reg3=X"00000000") then Rzero <='1'; else Rzero <='0'; end if;
								Rovfl<='0';
	   end case;
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




