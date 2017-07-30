library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_signed.all;
use ieee.numeric_std.all;
use ieee.std_logic_arith.all;

 entity ulaMIPS_tb is
 end ulaMIPS_tb;

 architecture ulaMIPS_tb_arch of ulaMIPS_tb is
	--signals
	signal op : std_logic_vector(2 downto 0);
	signal inA,inB,outZ : std_logic_vector(31 downto 0);
	signal outZero, outOvfl : std_logic;
	
	component ulaMIPS is
		port (
			opcode : in std_logic_vector(2 downto 0);
			A, B : in std_logic_vector(31 downto 0);
			Z : out std_logic_vector(31 downto 0);
			zero, ovfl : out std_logic);
	end component;
 
	
begin
	--U1: configuration work.conf_ulaMIPS_if_then_else port map(op, inA, inB, outZ, outZero, outOvfl);
	--U2: configuration work.conf_ulaMIPS_concorrente port map(op, inA, inB, outZ, outZero, outOvfl);
	U3: configuration work.conf_ulaMIPS_case port map(op, inA, inB, outZ, outZero, outOvfl);
	
	process
	begin
		-- teste das operacoes aritmeticas
		inA <= X"00001111";
		inB <= X"00001111";
		op <= "000"; -- adicao
		wait for 4 ps;	
		op <= "001"; -- subtracao
		wait for 4 ps;	
		
		inA <= X"00002222";
		inB <= X"00001111";
		op <= "000"; -- adicao
		wait for 4 ps;	
		op <= "001"; -- subtracao
		wait for 4 ps;
		
		inA <= X"00001111";
		inB <= X"00002222";
		op <= "000"; -- adicao
		wait for 4 ps;	
		op <= "001"; -- subtracao
		wait for 4 ps;
		
		inA <= X"80001111";
		inB <= X"70001111";
		op <= "000"; -- adicao
		wait for 4 ps;	
		op <= "001"; -- subtracao
		wait for 4 ps;
		
		-- teste das operacoes logicas		
		op <= "010"; -- and
		wait for 4 ps;
		op <= "011"; -- or
		wait for 4 ps;
		op <= "100"; -- not
		wait for 4 ps;
		op <= "101"; -- xor
		wait for 4 ps;
		op <= "110"; -- bypass
		wait for 4 ps;
		op <= "111"; -- slt
		wait for 4 ps;
		wait;
	end process;
end ulaMIPS_tb_arch;





