-- Quartus II VHDL Template
-- Basic Shift Register

library ieee;
use ieee.std_logic_1164.all;
use work.mips_pkg.all;

entity alu_ctr is
	port 
	(
		op_alu		: in std_logic_vector(2 downto 0);
		funct			: in std_logic_vector(5 downto 0);
		alu_ctr	   : out std_logic_vector(3 downto 0)
	);
end entity;

architecture behav of alu_ctr is

begin

alu_ctr <= -- Default (PC+4)
				ULA_ADD when (op_alu="000") else
				-- Type-R
				ULA_AND when (op_alu="010" and funct=iAND) else		--AND
				ULA_OR  when (op_alu="010" and funct=iOR)  else		--OR
				ULA_XOR when (op_alu="010" and funct=iXOR) else		--XOR
				ULA_SLL when (op_alu="010" and funct=iSLL) else		--SLL - shift left logical
				ULA_SRA when (op_alu="010" and funct=iSRA) else		--SRA - shift right arith
				ULA_SRL when (op_alu="010" and funct=iSRL) else		--SRL - shift right logical
				ULA_ADD when (op_alu="010" and funct=iADD) else		--ADD
				ULA_SUB when (op_alu="010" and funct=iSUB) else		--SUB
				ULA_SLT when (op_alu="010" and funct=iSLT) else		--SLT
				ULA_NOR when (op_alu="010" and funct=iNOR) else		--NOR
				-- Type-I
				ULA_SUB  when (op_alu="011") else							--BEQ, BGEZ, BLTZ
				ULA_OR   when (op_alu="100") else							--ORI
				ULA_AND  when (op_alu="101") else							--ANDI
				ULA_SLT  when (op_alu="110") else							--SLTI
				ULA_NOP;
end architecture;