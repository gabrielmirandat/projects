-- constantes
## geral
SIZE := 32 bits
## mips_mem
WIDTH : natural := 32;
WADDR : natural := 8);
## extsgn
IN_SIZE : natural := 16;
OUT_SIZE : natural := 32
## breg
ADDR : natural := 5	


-- ula do mips
ulamips
	aluctl		: 	in  std_logic_vector(3 downto 0);			'seleciona operação'
	A, B		:	in  std_logic_vector(SIZE-1 downto 0);		'entradas'
	aluout		:	out std_logic_vector(SIZE-1 downto 0);		'saida'
	zero  		:	out std_logic								'sinal se saída foi zero'
	
-- registrador comum
regbuf
	clk		: in std_logic;										'clock'
	sr_in	: in std_logic_vector(SIZE-1 downto 0);				'entrada'
	sr_out	: out std_logic_vector(SIZE-1 downto 0)				'saida'
	
-- registrador com enable e reset
reg
	clk		: in std_logic;										'clock'
	enable	: in std_logic;										'sinal de enable'
	rst		: in std_logic;										'sinal de reset'
	sr_in	: in std_logic_vector(SIZE-1 downto 0);				'entrada'
	sr_out	: out std_logic_vector(SIZE-1 downto 0)				'saida'
	
-- mux 4 entradas
mux_4	
	in0, in1, in2, in3: in std_logic_vector(W_SIZE-1 downto 0); 'as 4 entradas'
	sel		            	 : in std_logic_vector(1 downto 0); 'seleciona a entrada'
	m_out			: out std_logic_vector(W_SIZE-1 downto 0)); 'saida'
	
-- mux 3 entradas
mux_3
	in0, in1, in2	: in std_logic_vector(W_SIZE-1 downto 0);	'as 3 entradas'
	sel				: in std_logic_vector(1 downto 0);			'seleciona a entrada'
	m_out			: out std_logic_vector(W_SIZE-1 downto 0)); 'saida'
	
-- mux 2 entradas
mux_2
	in0, in1	: in std_logic_vector(SIZE-1 downto 0);			'as 2 entradas'
	sel			: in std_logic;									'seleciona a entrada'
	m_out		: out std_logic_vector(SIZE-1 downto 0));		'saida'
	
-- pacote que integra todos os módulos e tem todos os sinais do MIPS
mips_pkg

-- memoria do MIPS
mips_mem
	address	: in STD_LOGIC_VECTOR (WADDR-1 DOWNTO 0);			'endereço de entrada'
	clk		: in STD_LOGIC;										'clock'
	data	: in STD_LOGIC_VECTOR (WIDTH-1 DOWNTO 0);			'dados de entrada'
	wren	: in STD_LOGIC ;									'write enable'				EscreveMem
	q		: out STD_LOGIC_VECTOR (WIDTH-1 DOWNTO 0));			'saida da memoria'
	
-- parte de controle do mips
mips_control #16
	clk, rst						: in std_logic;				'clock e reset'
	opcode	:     in std_logic_vector (5 DOWNTO 0);				'opcode'
	wr_ir							:out std_logic;				'EscreveIR'
	wr_pc						   : out std_logic;				'EscrevePC'
	wr_mem						   : out std_logic;				'EscreveMem'
	is_beq						   : out std_logic;				'EscrevePCCond'
	is_bne						   : out std_logic; 			'não tem...'
	s_datareg					   : out std_logic;				'MemparaReg'
	op_alu	   : out std_logic_vector (1 DOWNTO 0);				'opALU'
	s_mem_add			           : out std_logic;	 			'IouD'
	s_PCin	   : out std_logic_vector (1 DOWNTO 0);		    	'OrigPC'
	s_aluAin 					   : out std_logic;  			'OrigAAlu'
	s_aluBin   : out std_logic_vector (1 DOWNTO 0);				'OrigBAlu'
	wr_breg						   : out std_logic;				'EscreveReg'
	s_reg_add					   : out std_logic	     		'RegDst'
	
-- entensão de sinal para instruções tipo I
extsgn
	input : in std_logic_vector(IN_SIZE-1 downto 0);			'entrada'
	output: out std_logic_vector(OUT_SIZE-1 downto 0)			'saida'
	
-- banco de registradores
breg
	clk		: in  std_logic;									'clock'
	enable	: in  std_logic;									'enable'
	idxA		: in  std_logic_vector(ADDR-1 downto 0);		'indice do registrador de entrada A'
	idxB		: in  std_logic_vector(ADDR-1 downto 0);		'indice do registrador de entrada B'
	idxwr		: in  std_logic_vector(ADDR-1 downto 0);		'indice do registrador de saída'
	data_in		: in  std_logic_vector(SIZE-1 downto 0);		'dados para escrita'
	regA 		: out std_logic_vector(SIZE-1 downto 0);		'registrador de saida A'
	regB 		: out std_logic_vector(SIZE-1 downto 0)			'registrador de saida B'
	
-- parte de controle da ula
alu_ctr
	op_alu		: in std_logic_vector(1 downto 0);				'operação da ULA - 2bits'
	funct			: in std_logic_vector(5 downto 0);			'funct - 6bits'
	alu_ctr	   : out std_logic_vector(3 downto 0)				'saida - 4bits'
	
	
-- TAMANHOS GLOBAIS	
	constant IMEM_SIZE	: integer := 1024;
	constant IMEM_ADDR	: integer := 8;
	constant WORD_SIZE 	: natural := 32;
	constant BREG_IDX 	: natural := 5;
	constant ZERO32 		: std_logic_vector(WORD_SIZE-1 downto 0) := (others=>'0');
	constant INC_PC		: std_logic_vector(WORD_SIZE-1 downto 0) := (2=>'1', others=>'0');
	
	
	
	