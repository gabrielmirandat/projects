LIBRARY IEEE;
USE IEEE.std_logic_1164.all;
use work.mips_pkg.all;

ENTITY mips_control IS

	PORT
	(
		clk, rst	: IN std_logic;
		opcode	: IN std_logic_vector (5 DOWNTO 0);
		wr_ir		: OUT std_logic;
		wr_pc		: OUT std_logic;
		wr_mem	: OUT std_logic;
		is_beq	: OUT std_logic; 
		is_bne	: OUT std_logic;
		s_datareg: OUT std_logic;
		op_alu	: OUT std_logic_vector (2 DOWNTO 0);
		s_mem_add: OUT std_logic;
		s_PCin	: OUT std_logic_vector (1 DOWNTO 0);
		s_aluAin : OUT std_logic_vector (1 DOWNTO 0);
		s_aluBin : OUT std_logic_vector (1 DOWNTO 0); 
		wr_breg	: OUT std_logic;
		s_reg_add: OUT std_logic;
		is_BxxZ  : OUT std_logic;
		is_imm	: OUT	std_logic
	);
	
END ENTITY;

ARCHITECTURE control_op OF mips_control IS

	type ctr_state is (	fetch_st,	--0000			--	fetch state									
							  decode_st,	--0001			-- decode state
						  c_mem_add_st,	--0010 ...		-- control memory address state
						    readmem_st,						-- read memory state
							   ldreg_st,						--	load register state
							writemem_st,						--	write memory state
							rtype_ex_st,						--	Rtype extention state
							writereg_st,						-- write register state
					     branch_ex_st,						-- branch extention state
						    jump_ex_st,						-- jump extention state
				      arith_imm_st); 						-- arith immediate state
						--escreve resultado de operaçao com aritmética imediata

	signal pstate, nstate : ctr_state;

	BEGIN
	
reg: process(clk, rst)
	begin
		if (rst = '1') then 
			pstate <= fetch_st;
		elsif (rising_edge(clk)) then 
			pstate <= nstate;
		end if;
	end process;
		
logic: process (opcode, pstate)
	begin
		wr_ir			<= '0';
		wr_pc			<= '0';
		wr_mem		<= '0';
		wr_breg		<= '0';
		is_beq 		<= '0';
		is_bne 		<= '0';
		op_alu		<= "000";
		s_datareg 	<= '0';
		s_mem_add 	<= '0';
		s_PCin		<= "00";
		s_aluAin 	<= "00";
		s_aluBin  	<= "00";
		s_reg_add 	<= '0';
		is_BxxZ		<= '0';
		is_imm		<= '0';
		case pstate is 
			when fetch_st => 	wr_pc 	<= '1';
									s_aluBin <= "01";
									wr_ir 	<= '1';
								
			when decode_st =>	s_aluBin <= "11";
								
			when c_mem_add_st => s_aluAin <= "01";		--serve para os imediatos, menos branch
								      s_aluBin <= "10";
										
										if opcode = iORI 
											then op_alu <= "100";
												  is_imm <= '1';
										elsif opcode = iANDI
											then op_alu <= "101";
												  is_imm <= '1';
										elsif opcode = iSLTI
											then op_alu <= "110";
										end if;
										
			when readmem_st => s_mem_add <= '1';
								 
			when ldreg_st =>	 s_datareg <= '1';
								    wr_breg   <= '1';
								
			when writemem_st =>  wr_mem 	 <= '1';
								      s_mem_add <= '1';
									
			when rtype_ex_st =>  s_aluAin <= "01";
								      op_alu <= "010";
										
										if (opcode = iSLL) or (opcode = iSRL)
											then s_aluAin <= "10";
										end if;
									
			when writereg_st =>  s_reg_add <= '1';
										wr_breg <= '1';
								  
			when branch_ex_st => s_aluAin <= "01";
										op_alu <= "011";
										
										if opcode = iBEQ 
											then is_beq <= '1';
										elsif opcode = iBNE 
											then is_bne <= '1';
										
										else 
											is_BxxZ <= '1';
											s_PCin <= "01";
										end if;
									
			when jump_ex_st =>	s_PCin <= "10";
										wr_pc <= '1';
			
			when arith_imm_st => wr_breg <= '1';	--escreve saidaALU no registrador rt (write_back imediatos)
		end case;
	end process;
	
new_state: process (opcode, pstate)
		begin
		
			nstate <= fetch_st;
			
			case pstate is
			when fetch_st => 	nstate <= decode_st;
			when decode_st =>	case opcode is
									when iRTYPE => nstate <= rtype_ex_st;					--execute Rtype
									when iLW | iSW | iADDI | iORI | iANDI | iSLTI => nstate <= c_mem_add_st; --execute lw,sw,I
									when iBEQ | iBNE | iBxxZ => nstate <= branch_ex_st;--execute branch
									when iJ => nstate <= jump_ex_st;							--execute jump
									when others => null;
									end case;
			when c_mem_add_st => case opcode is 
									when iLW => nstate <= readmem_st;													--mem_access load
									when iSW => nstate <= writemem_st; 													--mem_access store
									when iADDI | iORI | iANDI | iSLTI =>  nstate <= arith_imm_st;   			--writeback dos tipoI
									when others => null;
								end case;
			when readmem_st 	=> nstate <= ldreg_st;										--writeback load
			when rtype_ex_st 	=> nstate <= writereg_st;									--writeback dos tipoR
			when others 		=> null;
			end case;
		end process;
		
end control_op;
				
	
				
	