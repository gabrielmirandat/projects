#APLICAÇÂO

 HTTP(Hypertext Transfer Protocol) – 80, 8008, 8080 (TCP) server.
 FTP (File Transfer Protocol) – 20 (TCP) default data; 21 (TCP) control.
 SMTP(Simple Mail Transfer Protocol) – 25 (TCP). 366 (TCP) ODMR, On-Demand Mail Relay.
 DHCP(Dynamic Host Configuration Protocol) – 67 (UDP) server. 68 (UDP) host.
 Telnet – 23 (TCP) server; 107 (TCP) Remote User Telnet.
 SNMP(Simple Network Management Protocol) – 161 (TCP, UDP) server. 162 (TCP, UDP) traps. 5161 (TCP, UDP) over SSH. 5162 (TCP, UDP) traps over SSH.
 POP3(Post Office Protocol) – 109 (TCP), version 2; 110 (TCP), version 3.
 NNTP(Network News Transfer Protocol) – 119 (TCP). 563 (TCP) over TLS.
 DNS(Domain Name Server) - 53 (TCP, UDP) server.
 RTP(Real-time Transport Protocol) - 5004 (UDP).
 
'códigos de estado do HTTP'
2xx Sucesso
  - Ação solicitada pelo cliente foi recebida, compreendida, aceita e processada com êxito.
  200 OK
  201 Criado
  202 Aceito
5xx Erro de cliente
  403 Proibido
  404 Não encontrado
  503 Serviço indisponível
  
'servidor proxy'
'Proxy server' is any computer system offering a service that acts
as an intermediary between the two communicating parties, the client
and the server. In the presence of a proxy server, there is no direct
communication between the client and the server. Instead, the client
connects to the proxy server and sends requests for resources such as
a document, web page or a file that resides on a remote server. The 
proxy server handles this request by fetching the required resources 
from the remote server and forwarding the same to the client.

'SSH' (Secure Shell) e o protocolo 'Telnet'
Em informática o 'SSH (Secure Shell)' é, ao mesmo tempo, um programa de
computador e um protocolo de rede que permitem a conexão com outro computador
na rede de forma a permitir execução de comandos de uma unidade remota. O SSH
faz parte da suíte de protocolos TCP/IP que torna segura a administração remota
de servidores do tipo Unix. O SSH possui as mesmas funcionalidades do TELNET, 
com a vantagem da criptografia na conexão entre o cliente e o servidor.

O protocolo 'Telnet' é um protocolo standard de Internet que permite a interface 
de terminais e de aplicações através da Internet. Este protocolo fornece as regras
básicas para permitir ligar um cliente (sistema composto de uma afixação e um 
teclado) a um intérprete de comando (do lado do servidor).Com essa conexão é 
possível o acesso remoto para qualquer máquina ou equipamento que esteja sendo 
executado em modo servidor.

#TRANSPORTE

'portas de comunicação'
Together with the source and destination IP address, the port numbers constitutes 
a network socket (endpoint of an interprocess communication across a computer network),
i.e. an identification address of the process-to-process communication. In the OSI 
model, this function is supported by the session layer.

'janela deslizante no protocolo TCP'
Protocolos de Janela Deslizante ou Sliding Window são recursos usados na camada
de enlace de dados do modelo OSI, bem como no protocolo TCP (equivalente à camada de
transporte do modelo OSI). Janela deslizante é uma característica de alguns protocolos que
permite que o remetente transmita mais que um pacote de dados antes de receber uma
confirmação. Depois de receber a confirmação para o primeiro pacote enviado, o remetente
desliza a janela e manda outra confirmação. O número de pacotes transmitidos sem
confirmação é conhecido como o tamanho da janela; aumentando o tamanho da janela melhora-
se a vazão. TCP precisa re-ordenar os pacotes do fluxo da mensagem. Se o receptor envia 
ACK-8 quer dizer que já retirou do buffer todos os pacotes até o 8o pacote; nesta situação 
o emissor sabe que pode manter sem ACK os w pacotes depois do pacote de número 8 (PAC-8).
Se o temporizador do transmissor expirar antes de a confirmação ser recebida, o segmento 
será retransmitido.

'UDP'
O UDP. O UDP é uma escolha adequada para fluxos de dados em tempo real,
especialmente aqueles que admitem perda ou corrompimento de parte de seu conteúdo, tais como
vídeos ou voz (VoIP). Aplicações sensíveis a atrasos na rede, mas poucos sensíveis a perdas de
pacotes, como jogos de computadores, também podem se utilizar do UDP. O UDP não perde tempo
com criação ou destruição de conexões. As garantias de TCP envolvem retransmissão e espera de
dados, como consequência, intensificam os efeitos de uma alta latência de rede.
'Source port number' - identifies the senders port
'Destination port number' - identifies the receivers port 
'Length' - specifies the length in bytes of the UDP header and UDP data
'Checksum' - used for error-checking of the header and data

'Sockets'
Normally, a server runs on a specific computer and has a socket that is bound to a 
specific port number. The server just waits, listening to the socket for a client 
to make a connection request. 
If everything goes well, the server accepts the connection. Upon acceptance, the 
server gets a new socket bound to the same local port and also has its remote 
endpoint set to the address and port of the client. It needs a new socket so that
it can continue to listen to the original socket for connection requests while 
tending to the needs of the connected client. On the client side, if the connection
is accepted, a socket is successfully created and the client can use the socket to
communicate with the server. The client and server can now communicate by writing to
or reading from their sockets.
A socket is one endpoint of a two-way communication link between two programs 
running on the network. A socket is bound to a port number so that the TCP layer can
identify the application that data is destined to be sent to. An endpoint is a 
combination of an IP address and a port number. Every TCP connection can be uniquely 
identified by its two endpoints. That way you can have multiple connections between
your host and the server.

#REDE

'fragmentação no protocolo IP'
Not all link-layer protocols can carry network-layer packets of the same size.
Some protocols can carry big datagrams, whereas other protocols can carry only little
packets. The maximum amount of data that a link-layer frame can carry is called the 
maximum transmission unit (MTU).Fragment the data in the IP datagram into two or more 
smaller IP datagrams. Each of these smaller datagrams is referred to as a fragment. 
Fragments need to be reassembled before they reach the transport layer at the destination.
Reassembling datagrams in the routers would introduce significant complication into the 
protocol and put a damper on router performance. Reassembly in the end systems rather than 
in network routers. 'Identification, flag, and fragmentation offset fields' in the IP 
datagram header. The last fragment has a flag bit set to 0, whereas all the other fragments 
have this flag bit set to 1. The offset field is used to specify where the fragment fits 
within the original IP datagram. It can examine the identification numbers of the datagrams 
to determine which of the datagrams are actually fragments of the same larger datagram.

'ARP - do IP ao MAC!!!!'
The Address Resolution Protocol (ARP) is a telecommunication protocol used for resolution
of network layer addresses into link layer addresses, a critical function in multiple-access
networks. ARP was defined by RFC 826 in 1982, is Internet Standard STD 37, and is also the 
name of the program for manipulating these addresses in most operating systems.
ARP is used for mapping a network address (e.g. an IPv4 address) to a physical address like 
an Ethernet address (also named a 'MAC address').

'IPV4 - classes A, B e C'
The first IP of a network is network number and the last IP is reserved for Broadcast IP.
A - primeiro bit do primeiro octeto é 0 (range 1 a 127)
B - primeiros dois bits é 10	      (range 128 a 191)
C - primeiros três bits são 110	      (range 192 a 223)

PERGUNTA!
offset é em bytes! Off = 185 significa 185*8 = byte 1480. Meaning the data should be
inserted beginning at byte 1,480.
3100 bytes = 3080 payload + 20 header
MTU = 1000 bytes
1o datagrama = identifier 202 = identificador de todos
dados = 3080 bytes
3080/980 = 3
3080%980 = 140
total = |980 + 20| + |980 + 20| + |980 + 20| + |140 + 20| = 3160 bytes em 4 pacotes

'best effort do protocolo IP'
O Best-Effort é um modelo de serviço actualmente usado na Internet. Consiste num 
utilizador que envia um fluxo de dados, ao mesmo tempo que a largura de banda é 
partilhada com todos os fluxos de dados enviados por outros utilizadores, ou seja,
estas transmissões são concorrentes entre si. Em caso de congestionamento de dados,
os pacotes são descartados sem qualquer critério nem distinção, o que obviamente não
garante que este serviço seja bem sucedido, nem que tenha um bom desempenho. Em caso
de tráfego sensível a atrasos (delay) ou perdas de pacotes, este tipo de ruídos 
podem originar perdas acentuadas de qualidade de transmissão em tempo real e em casos
extremos inviabiliza-la.

#ENLACE/FÍSICA

'conectores físicos em fibra ótica'
Existem vários tipos de conectores de fibra óptica. O conector tem uma função importante,
já que a fibra deve ficar perfeitamente alinhada para que o sinal luminoso possa ser 
transmitido sem grandes perdas. Os quatro tipos de conector mais comuns são os LC, SC, 
ST e MT-RJ.

'ST (Straight Tip)' é um conector mais antigo, muito popular para uso com fibras
multimodo.Lembra os conectores BNC usados em cabos coaxiais.
'FC (Ferrule Connector)' connectors floating ferrule provides good mechanical isolation. FC
connectors need to be mated more carefully than the push-pull types due to the need to align the key,
and due to the risk of scratching the fiber end face while inserting the ferrule into the jack.
'LC (Lucent Connector)' é um conector miniaturizado que, como o nome sugere, foi
originalmente desenvolvido pela Lucent. Ele vem crescendo bastante em popularidade, sobretudo para
uso em fibras 'monomodo'. Ele é o mais comumente usado em transceivers 10 Gigabit Ethernet.

'ADSL - pq upstream é menor que downstream?'
Asymmetric digital subscriber line (ADSL) is a type of digital subscriber line (DSL)
technology, a data communications technology that enables faster data transmission over
copper telephone lines than a conventional voiceband modem can provide. ADSL differs 
from the less common symmetric digital subscriber line (SDSL). Bandwidth (and bit rate)
is greater toward the customer premises (known as downstream) than the reverse (known 
as upstream). This is why it is called asymmetric. Providers usually market ADSL as a
service for consumers to receive Internet access in a relatively passive mode: able to
use the higher speed direction for the download from the Internet but not needing to 
run servers that would require high speed in the other direction.

'jumboframe do gigabit ethernet'
In computer networking, jumbo frames are Ethernet frames with more than 1500 bytes of
payload.[1] Conventionally, jumbo frames can carry up to 9000 bytes of payload, but 
variations exist and some care must be taken using the term. Many Gigabit Ethernet 
switches and Gigabit Ethernet network interface cards can support jumbo frames. Some
Fast Ethernet switches and Fast Ethernet network interface cards can also support jumbo
frames. Most national research and education networks (such as Internet2, National 
LambdaRail, ESnet, GÉANT and AARNet) support jumbo frames, but most commercial Internet
service providers do not.

'MTU'
In computer networking, the maximum transmission unit (MTU) of a communications
protocol of a layer is the size (in bytes or octets) of the largest protocol data
unit that the layer can pass onwards. MTU parameters usually appear in association 
with a communications interface (NIC, serial port, etc.). Standards (Ethernet, for 
example) can fix the size of an MTU; or systems (such as point-to-point serial links)
may decide MTU at connect time.

'colisão Ethernet com o protocolo CSMA/CD'
Carrier Sense Multiple Access with Collision Detection é o sistema de gerenciamento de
tráfego que garante o funcionamento das redes Ethernet. As redes Ethernet utilizam uma
topologia lógica de barramento, isto significa que mesmo ao utilizar um hub, as estações
comportam-se com se estivessem todas ligadas a um único cabo. Isso simplifica a transmissão
de dados e barateia os equipamentos, mas em compensação traz um grave problema: as colisões
de pacotes que ocorrem sempre que duas (ou mais) estações tentam transmitir dados ao mesmo
tempo. O sistema CSMA/CD minimiza este problema através de um conjunto de medidas
relativamente simples: Antes de transmitir seu pacote, a estação "escuta" o cabo, para 
verificar se outra estação já está transmitindo. Caso o cabo esteja ocupado ela espera,
caso esteja livre ela transmite. Mesmo assim, como o sinal demora algum tempo para atingir
todas as estações, existe uma possibilidade considerável de que outra estação "escute" o 
cabo antes do sinal chegar até ela, pense que o cabo está livre e também transmita dados. 
Neste caso as duas transmissões colidirão em algum ponto do cabo. A estação que estiver 
mais próxima, a primeira a detectar a colisão, emitirá um sinal de alta freqüência que 
anula todos os sinais que estiverem trafegando através do cabo e alerta as demais estações
sobre o problema. Ao receberem o sinal, todas as estações param de transmitir dados por um
período de tempo aleatório. Com isto, os dados voltam a ser transmitidos, um pacote por vez.
Graças a este sistema, as colisões causam apenas uma pequena perda de tempo, mas não causam
perda de dados. Porém, como as colisões aumentam junto com o número de PCs na rede elas
podem tornar-se um problema sério em redes com mais de 30 ou 50 PCs. Neste caso é possível
utilizar switchs para dividir o tráfego da rede. Um switch divide a rede em dois (ou mais) 
segmentos,diminuindo o número de colisões de pacotes.

#ROTEAMENTO

'TTL no cabeçalho do protocolo IP'
Time to live (TTL) or hop limit is a mechanism that limits the lifespan or lifetime of 
data in a computer or network. In computer networking, TTL prevents a data packet from 
circulating indefinitely. The TTL field is set by the sender of the datagram, and 
reduced by every router on the route to its destination. In theory, under IPv4, time
to live is measured in seconds, although every host that passes the datagram must 
reduce the TTL by at least one unit.

'tabela de roteamento'
In computer networking a routing table, or routing information base (RIB), is a data table
stored in a router or a networked computer that lists the routes to particular network 
destinations, and in some cases, metrics (distances) associated with those routes. The 
routing table contains information about the topology of the network immediately around it.
The construction of routing tables is the primary goal of routing protocols. Static routes 
are entries made in a routing table by non-automatic means and which are fixed rather than 
being the result of some network topology "discovery" procedure.

'RIP'
The Routing Information Protocol (RIP) is one of the oldest distance-vector routing
protocols which employ the hop count as a routing metric. RIP prevents routing loops
by implementing a limit on the number of hops allowed in a path from source to 
destination. The maximum number of hops allowed for RIP is 15, which limits the size 
of networks that RIP can support. Each RIP router transmitted full updates every 30 
seconds. RIP uses the User Datagram Protocol (UDP) as its transport protocol, and is 
assigned the reserved port number 520.

'Roteamento estático ou dinâmico'
In static routing (or non-dynamic routing), small networks may use manually configured
routing tables. Larger networks have complex topologies that can change rapidly, making
the manual construction of routing tables unfeasible. Nevertheless, most of the public
switched telephone network (PSTN) uses pre-computed routing tables, with fallback routes
if the most direct route becomes blocked (see routing in the PSTN). Dynamic routing 
attempts to solve this problem by constructing routing tables automatically, based
on information carried by routing protocols, allowing the network to act nearly 
autonomously in avoiding network failures and blockages. Examples of dynamic-routing 
algorithms are the Routing Information Protocol (RIP) and the Open-Shortest-Path-First
protocol (OSPF). Dynamic routing dominates the Internet. However, the configuration of
the routing protocols often requires a skilled touch; networking technology has not
developed to the point of the complete automation of routing.

PERGUNTA!
a) 30 hosts ↔ router ↔ router ↔ 30 hosts
b) 192.168.10.0/24
11000000.10101000.00001010.00000000
255
.255
.255
.0
Com 11000000.10101000.00001010.10000000 posso fazer 2 sub-redes. Como sobraram 7 zeros
no último octeto, cada um das redes pode endereçar 2 7 = 128 – (end.rede + end.broadcast) = 128 – 2 =
126 hospedeiros.
Como só pegamos um bit, 2 7 = 128, logo a máscara é 255.255.255.128
1o rede = 1 a 126 (0 é rede e 127 é broadcast)
2o rede = 129 a 254 (128 é rede e 255 é broadcast)
c)
subrede	   rede 	1o host 	Ultimo host 	broadcast
0 	   0 		1 		126 		127
1 	   128 		129 		254 		255








