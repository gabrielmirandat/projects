library IEEE;
use IEEE.std_logic_1164.all;

entity vmul_8bits is
    port (
	   X,Y : in  STD_LOGIC_VECTOR (7 downto 0);
	   P   : out STD_LOGIC_VECTOR (15 downto 0)) ;
end vmul_8bits;

architecture arch of vmul_8bits is	  
	-- Returns the carry of the sum between three inputs
	function ADD_CARRY (I1, I2, I3: STD_LOGIC) return STD_LOGIC is
	begin
		return ((I1 and I2) or (I1 and I3) or (I2 and I3));
	end ADD_CARRY;
	-- Returns the sum between tree inputs
	function ADD_SUM (I1, I2, I3: STD_LOGIC) return STD_LOGIC is
	begin
		return (I1 xor I2 xor I3);
	end ADD_SUM;
begin

	process (X,Y)
		type array8x8 is array (0 to 7) of STD_LOGIC_VECTOR (7 downto 0);
		variable PC : array8x8;    -- product component bits
		variable PCS : array8x8;   -- full-adder sum bits
		variable PCC : array8x8;   -- full-adder carry output bits
		variable RAS : STD_LOGIC_VECTOR(7 downto 0); -- Ripple Adder Sum
		variable RAC : STD_LOGIC_VECTOR(7 downto 0); -- Ripple Adder Carry
		
	begin
	
		-- Compute ALL product component bits (x0y0, x1y0, etc..)
		for i in 0 to 7 loop
			for j in 0 to 7 loop
				PC(i)(j) := Y(i) and X(j); -- Compute product component bits
			end loop;
		end loop;
		
		-- Initialize first row "virtual adders"
		for j in 0 to 7 loop
			PCS(0)(j) := PC(0)(j);
			PCC(0)(j) := '0';
		end loop;
	
		-- Do all full adders except last row.
		for i in 1 to 7 loop
			for j in 0 to 6 loop
				PCS(i)(j) := ADD_SUM( PC(i)(j) , PCS(i-1)(j+1) , PCC(i-1)(j) );
				PCC(i)(j) := ADD_CARRY( PC(i)(j) , PCS(i-1)(j+1) , PCC(i-1)(j) );
				PCS(i)(7) := PC(i)(7); --leftmost virtual adder sum output.			
			end loop;
		end loop;
	
		-- Final Ripple Adder
		RAC(0) := '0';
		for i in 0 to 6 loop
			RAS(i)   := ADD_SUM   (PCS(7)(i+1) , PCC(7)(i) , RAC(i) );
			RAC(i+1) := ADD_CARRY (PCS(7)(i+1) , PCC(7)(i) , RAC(i) );
		end loop;
		
		-- Consolidate the results
		-- Gets the first 8 bits from full-adder sums
		for i in 0 to 7 loop
			P(i) <= PCS(i)(0);
		end loop;
		--Gets the next 7 bits from the Ripple Adder Sums
		for i in 8 to 14 loop
			P(i) <= RAS(i-8);
		end loop;
		-- Gets the last bit from the Ripple Adder Carry
		P(15) <= RAC(7);
	
	end process;

 end arch;
