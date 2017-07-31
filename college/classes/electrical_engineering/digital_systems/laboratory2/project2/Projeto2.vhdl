library IEEE;
use IEEE.STD_LOGIC_1164.ALL;



entity Projeto2 is
    port( RST : in STD_LOGIC;                       --Reset
            S : in STD_LOGIC_VECTOR (3 downto 0);   --Seletores (opcodes)
            A : in STD_LOGIC_VECTOR (7 downto 0);   --Primeiro Operando
            B : in STD_LOGIC_VECTOR (7 downto 0);   --Segundo Operando
            Z : in STD_LOGIC_VECTOR (7 downto 0);   --Terceiro Operando
            Cin : in STD_LOGIC;                     --Carry para o BIT 7
            ACin : in STD_LOGIC;                    --Carry para o BIT 4
            F : out STD_LOGIC_VECTOR (7 downto 0);  --Saída Principal
            G : out STD_LOGIC_VECTOR (7 downto 0);  --Saída Secundária
            Cout : out STD_LOGIC;                   --Carry out para o BIT 7
            ACout : out STD_LOGIC;                  --Carry out para o BIT 4
            OV : out STD_LOGIC);                    --Overflow
end Projeto2;

architecture projeto2_op of Projeto2 is


    function somador_completo(Cin,A,B: in STD_LOGIC) return STD_LOGIC_VECTOR is
        variable SCout : STD_LOGIC_VECTOR(1 downto 0);
        begin
            SCout(1) := Cin xor (A xor B);
            SCout(0) := (A and B) or (Cin and(A xor B));
            
            return SCout;
    end somador_completo;
    
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

    function vmul_8bits(X,Y : in  STD_LOGIC_VECTOR(7 downto 0)) return STD_LOGIC_VECTOR is
        variable P : STD_LOGIC_VECTOR(15 downto 0) ;
        variable SCout : STD_LOGIC_VECTOR(1 downto 0);
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
                P(i) := PCS(i)(0);
            end loop;
            --Gets the next 7 bits from the Ripple Adder Sums
            for i in 8 to 14 loop
                P(i) := RAS(i-8);
            end loop;
            -- Gets the last bit from the Ripple Adder Carry
            P(15) := RAC(7);
            
            return P;
    end vmul_8bits;

    --Funcao para divisao--
    function divide(A,B: in STD_LOGIC_VECTOR(7 downto 0)) return STD_LOGIC_VECTOR is
        variable F_G : STD_LOGIC_VECTOR(15 downto 0);
        variable K   : STD_LOGIC_VECTOR (7 downto 0);   --F
            variable C   : STD_LOGIC_VECTOR (7 downto 0);
            variable L   : STD_LOGIC_VECTOR (7 downto 0);   --G
            variable SCout : STD_LOGIC_VECTOR (1 downto 0);
    begin
        C := A;
        K := "00000000";
        
        while (C>=B) loop
          SCout := somador_completo('1'     , K(0), '0');     K(0) := SCout(1);
          SCout := somador_completo(SCout(0), K(1), '0');     K(1) := SCout(1);
          SCout := somador_completo(SCout(0), K(2), '0');     K(2) := SCout(1);
          SCout := somador_completo(SCout(0), K(3), '0');     K(3) := SCout(1);
          SCout := somador_completo(SCout(0), K(4), '0');     K(4) := SCout(1);
          SCout := somador_completo(SCout(0), K(5), '0');     K(5) := SCout(1);
          SCout := somador_completo(SCout(0), K(6), '0');     K(6) := SCout(1);
          SCout := somador_completo(SCout(0), K(7), '0');     K(7) := SCout(1);
              
          SCout := somador_completo('1'     , C(0), not(B(0)));     C(0) := SCout(1);
          SCout := somador_completo(SCout(0), C(1), not(B(1)));     C(1) := SCout(1);
          SCout := somador_completo(SCout(0), C(2), not(B(2)));     C(2) := SCout(1);
          SCout := somador_completo(SCout(0), C(3), not(B(3)));     C(3) := SCout(1);
          SCout := somador_completo(SCout(0), C(4), not(B(4)));     C(4) := SCout(1);
          SCout := somador_completo(SCout(0), C(5), not(B(5)));     C(5) := SCout(1);
          SCout := somador_completo(SCout(0), C(6), not(B(6)));     C(6) := SCout(1);
              SCout := somador_completo(SCout(0), C(7), not(B(7)));     C(7) := SCout(1);
        end loop;
        
        L:= C;
        
        F_G := K & L;
        
        return F_G;

    end divide;
    

    
begin
    process(RST, S, A, B, Z, Cin, ACin)
        variable AUX1 : STD_LOGIC;
        variable AUX2 : STD_LOGIC_VECTOR(1 downto 0);
        variable AUX8 : STD_LOGIC_VECTOR(7 downto 0);
        variable AUX16  : STD_LOGIC_VECTOR(15 downto 0);
        variable SCout : STD_LOGIC_VECTOR (1 downto 0);
        
        
        
    begin
        if( RST = '1' ) then
            F <= "--------";
            G <= "--------";
            Cout <= '-';
            ACout <= '-';
            OV <= '-';
        else

            case S is
                when "0001" =>  --2.ADD
                    SCout := somador_completo(Cin     , A(0), B(0));  F(0) <= SCout(1);
                    SCout := somador_completo(SCout(0), A(1), B(1));  F(1) <= SCout(1);
                    SCout := somador_completo(SCout(0), A(2), B(2));  F(2) <= SCout(1);
                    SCout := somador_completo(SCout(0), A(3), B(3));  F(3) <= SCout(1);
                    ACout <= SCout(0);
                    SCout := somador_completo(SCout(0), A(4), B(4));  F(4) <= SCout(1);
                    SCout := somador_completo(SCout(0), A(5), B(5));  F(5) <= SCout(1);
                    SCout := somador_completo(SCout(0), A(6), B(6));  F(6) <= SCout(1);
                    AUX2(1) := SCout(0);
                    SCout := somador_completo(SCout(0), A(7), B(7));  F(7) <= SCout(1);
                    Cout  <= SCout(0);  AUX2(0) := SCout(0);

                    
                    OV    <= AUX2(1) xor AUX2(0);
                    G     <= "--------";
                    
                    
                when "0010" =>  --3.SUB
                    AUX8 := not(B);
                    
                    SCout := somador_completo(not(Cin), A(0), AUX8(0));   F(0) <= SCout(1);
                    SCout := somador_completo(SCout(0), A(1), AUX8(1));   F(1) <= SCout(1);
                    SCout := somador_completo(SCout(0), A(2), AUX8(2));   F(2) <= SCout(1);
                    SCout := somador_completo(SCout(0), A(3), AUX8(3));   F(3) <= SCout(1);
                    ACout <= SCout(0);                  
                    SCout := somador_completo(SCout(0), A(4), AUX8(4));   F(4) <= SCout(1);
                    SCout := somador_completo(SCout(0), A(5), AUX8(5));   F(5) <= SCout(1);
                    SCout := somador_completo(SCout(0), A(6), AUX8(6));   F(6) <= SCout(1);
                    AUX2(1) := SCout(0);
                    SCout := somador_completo(SCout(0), A(7), AUX8(7));   F(7) <= SCout(1);
                    Cout  <= SCout(0);  AUX2(0) := SCout(0);
                    
                    OV    <= AUX2(1) xor AUX2(0);
                    G     <= "--------";

                when "0011" =>  --4.MUL
                    AUX16 := vmul_8bits(A,B);
                    AUX8  := AUX16(15) & AUX16(14) & AUX16(13) & AUX16(12) & AUX16(11) & AUX16(10) 
                         & AUX16(9) & AUX16(8); 
                    
                    G <= AUX8;
                    F <= AUX16(7) & AUX16(6) & AUX16(5) & AUX16(4) & AUX16(3) & AUX16(2) 
                         & AUX16(1) & AUX16(0);
                         
                    if (AUX8 = "00000000") then OV <= '0';
                    else OV <= '1'; 
                    end if;
                    
                    Cout <= '-';
                                ACout <= '-';
                            
                when "0100" =>  --5.DIV
                    if (B /= "00000000") then
                        AUX16 := divide(A,B);
                        F <= AUX16(15) & AUX16(14) & AUX16(13) & AUX16(12) & AUX16(11) & AUX16(10) & AUX16(9) & AUX16(8);
                        G <= AUX16(7) & AUX16(6) & AUX16(5) & AUX16(4) & AUX16(3) & AUX16(2) & AUX16(1) & AUX16(0);
                    else  
                        OV <= '1';
                        F <= "--------";
                        G <= "--------";
                    end if;
                    
                    Cout <= '-';
                    ACout <= '-';
                    
                when "0101" =>  --6.DA
                    
                    AUX1 := '0';
                    AUX8 := A;
                    if( (ACin = '1') or (A(3 downto 0) > "1001") ) then
                    AUX1 := '1';
                        SCout := somador_completo('0'     , A(0), '0');   AUX8(0) := SCout(1);
                        SCout := somador_completo(SCout(0), A(1), '1');   AUX8(1) := SCout(1);
                        SCout := somador_completo(SCout(0), A(2), '1');   AUX8(2) := SCout(1);
                        SCout := somador_completo(SCout(0), A(3), '0');   AUX8(3) := SCout(1);
                        SCout := somador_completo(SCout(0), A(4), '0');   AUX8(4) := SCout(1);
                        SCout := somador_completo(SCout(0), A(5), '0');   AUX8(5) := SCout(1);
                        SCout := somador_completo(SCout(0), A(6), '0');   AUX8(6) := SCout(1);
                        SCout := somador_completo(SCout(0), A(7), '0');   AUX8(7) := SCout(1);
                    end if;
                    

                    if(Cin = '1' or AUX1 = '1')then
                        SCout := somador_completo('0'     , AUX8(0), '0');   AUX8(0) := SCout(1);
                        SCout := somador_completo(SCout(0), AUX8(1), '0');   AUX8(1) := SCout(1);
                        SCout := somador_completo(SCout(0), AUX8(2), '0');   AUX8(2) := SCout(1);
                        SCout := somador_completo(SCout(0), AUX8(3), '0');   AUX8(3) := SCout(1);
                        SCout := somador_completo(SCout(0), AUX8(4), '0');   AUX8(4) := SCout(1);
                        SCout := somador_completo(SCout(0), AUX8(5), '1');   AUX8(5) := SCout(1);
                        SCout := somador_completo(SCout(0), AUX8(6), '1');   AUX8(6) := SCout(1);
                        SCout := somador_completo(SCout(0), AUX8(7), '0');   AUX8(7) := SCout(1);
                    end if;
                    
                    F <= AUX8;
                    
                    if (AUX8 > "10011001") then
                        Cout <= '1';
                    else    Cout <= '0';
                    end if;
                    
                    G <= "--------";
                    ACout <= '-';
                    OV <= '-';
                    
                when "0110" =>  --7.NOT
                    F       <= not(A);
                    G       <= "--------";
                    Cout    <= '-';
                    ACout   <= '-';
                    OV  <= '-';
                when "0111" =>  --8.AND
                    F       <= A and B;
                    G       <= "--------";
                    Cout    <= '-';
                    ACout   <= '-';
                    OV      <= '-';
                when "1000" =>  --9.XOR
                    F       <= A xor B;
                    G       <= "--------";
                    Cout    <= '-';
                    ACout   <= '-';
                    OV      <= '-';
                when "1001" =>  --10.OR
                    F       <= A or B;
                    G       <= "--------";
                    Cout    <= '-';
                    ACout   <= '-';
                    OV      <= '-';
                when "1010" =>  --11.RL
                    F(7)    <= A(6);
                    F(6)    <= A(5);
                    F(5)    <= A(4);
                    F(4)    <= A(3);
                    F(3)    <= A(2);
                    F(2)    <= A(1);
                    F(1)    <= A(0);
                    F(0)    <= A(7);
                    G   <= "--------";
                    Cout    <= '-';
                    ACout   <= '-';
                    OV      <= '-';
                when "1011" =>  --12.RLC
                    F(7)    <= A(6);
                    F(6)    <= A(5);
                    F(5)    <= A(4);
                    F(4)    <= A(3);
                    F(3)    <= A(2);
                    F(2)    <= A(1);
                    F(1)    <= A(0);
                    F(0)    <= Cin;
                    Cout    <= A(7);
                    G       <= "--------";
                    ACout   <= '-';
                    OV      <= '-';
                when "1100" =>  --13.RR
                    F(7)    <= A(0);
                    F(6)    <= A(7);
                    F(5)    <= A(6);
                    F(4)    <= A(5);
                    F(3)    <= A(4);
                    F(2)    <= A(3);
                    F(1)    <= A(2);
                    F(0)    <= A(1);
                    G       <= "--------";
                    Cout    <= '-';
                    ACout   <= '-';
                    OV      <= '-';
                when "1101" =>  --14.RRC
                    F(7)    <= Cin;
                    F(6)    <= A(7);
                    F(5)    <= A(6);
                    F(4)    <= A(5);
                    F(3)    <= A(4);
                    F(2)    <= A(3);
                    F(1)    <= A(2);
                    F(0)    <= A(1);
                    Cout    <= A(0);
                    G       <= "--------";
                    ACout   <= '-';
                    OV      <= '-';
                when "1110" =>  --15.PCSADD
                    AUX16 := B & A;
                    
                    SCout := somador_completo('0'     , AUX16(0), Z(0));    F(0) <= SCout(1); 
                    SCout := somador_completo(SCout(0), AUX16(1), Z(1));    F(1) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(2), Z(2));    F(2) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(3), Z(3));    F(3) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(4), Z(4));    F(4) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(5), Z(5));    F(5) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(6), Z(6));    F(6) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(7), Z(7));    F(7) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(8), Z(7));    G(0) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(9), Z(7));    G(1) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(10),Z(7));    G(2) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(11),Z(7));    G(3) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(12),Z(7));    G(4) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(13),Z(7));    G(5) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(14),Z(7));    G(6) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(15),Z(7));    G(7) <= SCout(1);
                    
                    Cout <= '-';
                    ACout <= '-';
                    OV <= '-';                  
                    
                    
                when "1111" =>  --16.PCUADD
                    AUX16 := B & A;
                    
                    SCout := somador_completo('0'     , AUX16(0), Z(0));    F(0) <= SCout(1); 
                    SCout := somador_completo(SCout(0), AUX16(1), Z(1));    F(1) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(2), Z(2));    F(2) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(3), Z(3));    F(3) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(4), Z(4));    F(4) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(5), Z(5));    F(5) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(6), Z(6));    F(6) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(7), Z(7));    F(7) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(8), '0'); G(0) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(9), '0'); G(1) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(10),'0'); G(2) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(11),'0'); G(3) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(12),'0'); G(4) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(13),'0'); G(5) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(14),'0'); G(6) <= SCout(1);
                    SCout := somador_completo(SCout(0), AUX16(15),'0'); G(7) <= SCout(1);
                    
                    Cout <= '-';
                    ACout <= '-';
                    OV <= '-';  
                
                
                when others         =>  --1.None
                                F <= "--------";
                    G <= "--------";
                                Cout <= '-';
                                ACout <= '-';
                                OV <= '-';
            end case;
        end if;
    end process;
end  projeto2_op; 







