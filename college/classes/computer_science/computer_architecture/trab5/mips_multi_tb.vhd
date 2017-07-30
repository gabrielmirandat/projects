-- Copyright (C) 1991-2013 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- ***************************************************************************
-- This file contains a Vhdl test bench template that is freely editable to   
-- suit user's needs .Comments are provided in each section to help the user  
-- fill out necessary details.                                                
-- ***************************************************************************
-- Generated on "12/01/2015 12:32:26"
                                                            
-- Vhdl Test Bench template for design  :  mips_multi
-- 
-- Simulation tool : ModelSim-Altera (VHDL)
-- 

LIBRARY ieee;                                               
USE ieee.std_logic_1164.all;                                

ENTITY mips_multi_tb IS
END mips_multi_tb;

ARCHITECTURE mips_multi_tb_arch OF mips_multi_tb IS
-- constants                                                 
-- signals                                                   
SIGNAL clk : STD_LOGIC := '0';
SIGNAL clk_rom : STD_LOGIC := '1';
SIGNAL data : STD_LOGIC_VECTOR(31 DOWNTO 0);
SIGNAL debug : STD_LOGIC_VECTOR(1 DOWNTO 0) := "00";
SIGNAL rst : STD_LOGIC := '0';

COMPONENT mips_multi
	PORT (
		clk : IN STD_LOGIC;
		clk_rom : IN STD_LOGIC;
		data : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
		debug : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
		rst : IN STD_LOGIC
	);
END COMPONENT;

BEGIN
	i1 : mips_multi	PORT MAP ( clk => clk, clk_rom => clk_rom, data => data, debug => debug, rst => rst );
	
	clk <= not(clk) after 10 ns;
	clk_rom <= not(clk_rom) after 10 ns;

init : PROCESS                                                                                
BEGIN                                                        
	rst <= '1';
	wait for 15 ns;
	rst <= '0';
	WAIT;                                                       
END PROCESS init;                                                                                    

END mips_multi_tb_arch;
