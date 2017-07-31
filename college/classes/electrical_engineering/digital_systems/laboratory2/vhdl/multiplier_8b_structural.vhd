library IEEE;
use IEEE.std_logic_1164.all;

entity vmul_8bits_structural is
    port (
	   X,Y : in  STD_LOGIC_VECTOR (7 downto 0);
	   P   : out STD_LOGIC_VECTOR (15 downto 0)) ;
end vmul_8bits_structural;

architecture arch of vmul_8bits_structural is	
    -- Eu tenho que declarar como component para que eu possa usar a estrutura generate! 
	component and2 is
    port ( I0, I1 : in  STD_LOGIC;
	            F : out STD_LOGIC);
	end component;
	component add_carry is
    port (I0, I1, I2 : in  STD_LOGIC;
	               F : out STD_LOGIC);
	end component;
	component add_sum is
    port (I0, I1, I2 : in  STD_LOGIC;
	               F : out STD_LOGIC);
	end component;
	
	--Sinais necessários
	type array8x8 is array (0 to 7) of STD_LOGIC_VECTOR (7 downto 0);
	signal PC : array8x8;    -- product component bits
	signal PCS : array8x8;   -- full-adder sum bits
	signal PCC : array8x8;   -- full-adder carry output bits
	signal RAS : STD_LOGIC_VECTOR(7 downto 0); -- Ripple Adder Sum
	signal RAC : STD_LOGIC_VECTOR(7 downto 0); -- Ripple Adder Carry
	
begin

	-- Compute ALL product component bits (x0y0, x1y0, etc..)
	g1: for i in 0 to 7 generate
		g2: for j in 0 to 7 generate
			U1: and2 port map (Y(i),X(j),PC(i)(j)); -- Compute product component bits
		end generate;
	end generate;
	
	-- Initialize first row "virtual adders"
	g3: for j in 0 to 7 generate
		PCS(0)(j) <= PC(0)(j);
		PCC(0)(j) <= '0';
	end generate;
	
	-- Do all full adders except last row.
	g4: for i in 1 to 7 generate
		g5: for j in 0 to 6 generate
			U2: add_sum port map (PC(i)(j) , PCS(i-1)(j+1) , PCC(i-1)(j) , PCS(i)(j));
			U3: add_carry port map (PC(i)(j) , PCS(i-1)(j+1) , PCC(i-1)(j) , PCC(i)(j));
			PCS(i)(7) <= PC(i)(7); --leftmost virtual adder sum output.			
		end generate;
	end generate;
	
	-- Final Ripple Adder
	RAC(0) <= '0';
	g6: for i in 0 to 6 generate
		U4: add_sum port map (PCS(7)(i+1) , PCC(7)(i) , RAC(i), RAS(i));
		U5: add_carry port map (PCS(7)(i+1) , PCC(7)(i) , RAC(i), RAC(i+1));
	end generate;
		
	-- Consolidate the results
	-- Gets the first 8 bits from full-adder sums
	g7: for i in 0 to 7 generate
		P(i) <= PCS(i)(0);
	end generate;
	--Gets the next 7 bits from the Ripple Adder Sums
	g8: for i in 8 to 14 generate
		P(i) <= RAS(i-8);
	end generate;
	-- Gets the last bit from the Ripple Adder Carry
	P(15) <= RAC(7);

 end arch;
 
library IEEE;
use IEEE.std_logic_1164.all;

entity add_sum is
    port (
	   I0, I1, I2 : in  STD_LOGIC;
	            F : out STD_LOGIC);
end add_sum;

architecture arch of add_sum is	  
begin
    F <= I0 xor I1 xor I2;
 end arch;
 
library IEEE;
use IEEE.std_logic_1164.all;

entity add_carry is
    port (
	   I0, I1, I2 : in  STD_LOGIC;
	            F : out STD_LOGIC);
end add_carry;

architecture arch of add_carry is	  
begin
    F <= (I0 and I1) or (I0 and I2) or (I1 and I2);
 end arch;
 
 library IEEE;
use IEEE.std_logic_1164.all;

entity and2 is
    port (
	   I0, I1 : in  STD_LOGIC;
	            F : out STD_LOGIC);
end and2;

architecture arch of and2 is	  
begin
    F <= I0 and I1;
 end arch;

