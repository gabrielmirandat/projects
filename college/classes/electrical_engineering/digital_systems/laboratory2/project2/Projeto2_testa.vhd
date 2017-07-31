library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity sim is
end sim;

architecture sim_op of sim is   
    component Projeto2 is
        port(   RST : in STD_LOGIC;                     --Reset
                S : in STD_LOGIC_VECTOR (3 downto 0);   --Seletores (opcodes)
                A : in STD_LOGIC_VECTOR (7 downto 0);   --Primeiro Operando
                B : in STD_LOGIC_VECTOR (7 downto 0);   --Segundo Operando
                Z : in STD_LOGIC_VECTOR (7 downto 0);   --Terceiro Operando
              Cin : in STD_LOGIC;                       --Carry para o BIT 7
             ACin : in STD_LOGIC;                       --Carry para o BIT 4
                F : out STD_LOGIC_VECTOR (7 downto 0);  --Saída Principal
                G : out STD_LOGIC_VECTOR (7 downto 0);  --Saída Secundária
             Cout : out STD_LOGIC;                      --Carry out para o BIT 7
            ACout : out STD_LOGIC;                      --Carry out para o BIT 4
               OV : out STD_LOGIC);                     --Overflow
    end component;
    
    signal RST, Cin, ACin, Cout, ACout, OV : STD_LOGIC;
    signal A, B, Z, F, G : STD_LOGIC_VECTOR(7 downto 0);
    signal S : STD_LOGIC_VECTOR(3 downto 0);
    
    begin 
        U1: Projeto2 port map(RST, S, A, B, Z, Cin, ACin, F, G, Cout, ACout, OV);
        
        process
        begin
            RST<= '0';
            S  <= "0100";
            A  <= "00001010";
            B  <= "00000010";
            Cin <= '0';
            Z   <= "10101010";
            ACin <= '0';
            wait for 100 ns;
                
            wait;
        end process;
    end sim_op;





