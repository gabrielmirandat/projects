NAO Robot Programming Guide
Creating a TCP/IP Module

-> Windows Server
  2.1 Message Structure
  2.2 Creating the Socket Server
  2.3 Sending Messages
  2.4 Main Loop
  
-> NAO Module
  3.1 CMakeLists.txt
  3.2 Module Loader
  3.3 Module Header
  3.4 Module Implementation
  3.4.1 Impl Struct
  3.4.2 Public Methods
  3.5 Module Client
  3.6 Compiling and Running the Module
  
-> Como criar módulo TCP/IP no NAO.
-> Módulo = cliente que recebe as mensagens de um servidor rodando num PC windows.
-> Este PC roda o software Motion Capture do qual o servidor recebe os dados usando Vicon Datastream SDK.
-> Estes dados são filtrados e então mandados ao robô diretamente.
-> O módulo TCP/IP tem duas tarefas principais:
  1) Receber dados usando sockets.
  2) Salvar estes dados na memória compartilhada do computador.
  #As duas tarefas são executadas em Threads diferentes.
  
-> Tutorial dividido em duas partes principais:
  1) Servidor Windows
  2) Módulo NAO
  
'Windows Server'
-> Conexão entre Vicon Nexus e o robô, usando para isto o Vicon Data Stream SDK e um socket TCP/IP que mandará mensagens para o robô 
usando Wi-fi. Foi usado: Windows 7 64 bits, Microsoft Visual Studio 2013 e Vicon Nexus 1.8.5.

  'Estrutura da mensagem'
  A conexão ao software Motion Capture usa o SDK fornecido pela compania.
  Selecionar apenas os dados desejados: posições X, Y e Z.
  A posição de cada marcador é adquirida com uma frequência de 30 frames por segundo e armazenado nas seguintes estruturas definidas 
  no arquivo header Enumerators.h.
  
#define MARKER_NUMBER 18
#define FIRST_SIZE 10

typedef struct {
  int set;
  int marker;
  double x;
  double y;
  double z;
  double bar;
} MessageCell;

typedef struct {
  MessageCell message[FIRST_SIZE];
  int frame;
  int foo;
} Message1;

typedef struct {
  MessageCell message[MARKER_NUMBER - FIRST_SIZE];
  int frame;
  int foo;
} Message2;

-> "double bar" e "int foo" são tokens que casam com o alinhamento do byte de ambos os sistemas operacionais, Windows e Gentoo Linux 32 bits, 
caso contrário a mensagem no cliente e no servidor terão tamanhos diferentes.
-> Umas das especificações TCP/IP são que pacotes maiores que 576 bytes podem ser divididos em pacotes menores. Isto estava causando vários 
erro no Cliente devido ao tamanho dos dados não constante. Para resolver isto, nós dividimos a mensagem em dois pacotes, Message 1 e Message 2,
que são menores que 576 bytes, então temos certeza sobre o tamanho de cada pacote. Usamos os defines para facilmente mudar o tamanho das 
mensagens se preciso.

  'Criando o servidor de socket'
  O header SocketServer.h contém as declarações da classe SocketServer. Os primeiros detalhes importantes são os defines e includes, assim o 
  socket pode funcionar no windows.
  