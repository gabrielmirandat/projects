Camada de Aplicação;
Camada de Transporte;
Camada de Rede;
Camada de Enlace;
Camada Física.

HUB, SWITCH, ROTEADOR, MODEM (=!)
 
'Hub'
O hub é um equipamento bem antigo, sendo um dos primeiros a serem usados pelas empresas em redes locais. Basicamente, ele conecta os computadores
de uma rede e possibilita a transmissão das informações entre eles. Porém, é exatamente nesta transmissão que está o seu ponto fraco: ao pegar 
a informação de um computador para enviar, ele passa as informações por todos os computadores até encontrar o destinatário final.  Isto causa 
um tráfego enorme, além de expor os dados a qualquer um que esteja conectado nela, gerando um sério problema de segurança.

'Switch'
Criado principalmente para resolver os problemas que o 'hub' apresentava, o switch é um equipamento que apresenta basicamente a mesma função 
executada de uma maneira diversa. Diferente de seu antecessor, um 'comutador', como também é chamado, recebe a informação a ser transmitida e a 
repassa apenas para o destinatário, evitando expô-la a outros computadores. O processo é realizado decodificando o cabeçalho do pacote e 
localizando as informações do receptor dos dados. O aparelho guarda os endereços dos destinatários em uma tabela na sua memória. Desta forma, ele
consegue entregar as informações unicamente à máquina destinada e, assim, consegue ainda diminuir o tráfego da rede. Mesmo assim, é possível 
capturar informações, através de técnicas de sniffer.

'Roteador'
O roteador é um equipamento que faz o papel de um intermediador, possibilitando a troca de pacotes entre redes separadas. Este trabalho é 
realizado seguindo um conjunto de regras que são encontradas na tabela de roteamento. O uso de aparelhos do gênero é comum em situações em
que é necessário interligar redes diferentes, mas que, ao mesmo tempo, é preciso mantê-las isoladas. Na prática, quem está em uma delas não
consegue enxergar diretamente a outra, a menos que utilize o dispositivo como “caminho”para isso. Permite que vários dispositivos se conectem 
à mesma rede ('wifi'). Também é chamado de ponto de acesso wireless.

'Modem'
O modem é um dispositivo eletrônico que modula um sinal digital em uma onda analógica, capaz de ser transmitida pela linha telefônica, e que 
demodula o sinal analógico e o converte novamente para o formato digital original, criando uma comunicação entre dois pontos. É exatamente por 
causa desta característica que o aparelho tem este nome, que vem da junção das palavras (mo)dulador e (dem)odulador. No entanto, é importante 
salientar que, diferente dos modems para acesso discado, os 'ADSL' não precisam converter o sinal de digital para analógico e vice-versa, porque 
ele é sempre digital - o que pode, inclusive, ser visto no nome da tecnologia: 'ADSL – Asymmetric Digital Subscriber Line.' Permite conexão de 
um aparelho('cabo do desktop ethernet'). Já o 'modem ADSL' permite a mesma comunicação através de cabos de telefonia em vez do ethernet e são 
mais rápidos.

'Socket x porta'
 Em documentos de RFC (Request for Comments) relacionado a TCP ou UDP, um socket em um computador é definido como a combinação de um endereço 
 IP, um protocolo, e o número da porta do protocolo.
 
 'Telnet(não criptografado) e ssh(criptografado)'
 Protocolo para login remoto. Acesso a outros computadores remotamente.

'examinando os links e os switchs que transportam dados..'

'hospedeiros/sistemas finais' = conectam-se para usar da internet
-> sistemas finais são conectáveis através de uma rede de 'links de comunicação (enlaces)' e 'switchs de pacotes (comutadores de pacotes)'.
-> existem vários tipos de enlaces de comunicação feitos de diferentes tipos de materias físicos, incluindo cabos coaxiciais, 
	fibra ótica e espectros de radio
-> diferentes enlaces transferem dados em diferentes rates: bits/second
-> quando um hospedeiro tem dados para mandar para outro hospedeiro, o mandador segmenta o dado e adiciona bytes de cabeçalho em cada segmento,
	cada um destes segmentos chama-se pacote e quando chegam são desfragmentados
-> um 'comutador de pacotes' toma um pacote de um de seus 'enlaces de comunicação' de entrada e passam o pacote para um de seus 
'enlaces de comunicação' de sáida.
-> são 'comutadores de pacotes' : 'roteadores'(usados no núcleo da rede) e 'comutadores da camada de enlace'(usados na rede de acesso).

'IP' - especificam o formato dos pacotes que são enviados e recebidos pelos roteadores e sistemas finais

###############################################################################################################################################
Camada de Aplicação;
Camada de Transporte;
Camada de Rede;
Camada de Enlace;
Camada Física.

#Nomenclaturas
'ISP' - internet service provider (provedor de serviços de internet)
- Um ISP é uma empresa que fornece acesso à Internet, em geral, mediante o pagamento de uma taxa. As maneiras mais comuns de conectar-se com 
um ISP são usando uma 'linha telefônica (dial-up)' ou 'uma conexão de banda larga (cabo ou DSL)'. Muitos ISPs prestam serviços adicionais, 
como contas de email, navegadores da Web e espaço para a criação de um site.

'DSL' - digital subscriber line (linha do assinante digital)
- DSL ou ainda xDSL é uma família de tecnologias que fornecem um meio de transmissão digital de dados, aproveitando a própria rede de telefonia
que chega na maioria das residências. As velocidades típicas de download de uma linha DSL variam de 128 kilobits por segundo (kbps) até 52 Mbits/s
dependendo da tecnologia implementada e oferecida aos clientes. As velocidades de upload são menores do que as de download para o ADSL e são 
iguais para o caso do SDSL.

'ADSL' - asymmetric digital subscriber line (linha do assinante digital assimétrica)
- Asymmetric Digital Subscriber Line (ADSL) é um formato de DSL, uma tecnologia de comunicação de dados que permite uma transmissão de dados mais
rápida através de 'linhas de telefone' do que um modem convencional pode oferecer. 'rede de telefone x cabo de rede' 

'Comutador de pacotes' - roteador ou comutador da camada de enlace

'Estação-base' - wifi

'RFC e IETF' - request for comments (pedido de comentários) e Internet Engineering Task Force.
- As RFCs são documentos técnicos que detalham o funcionamento de todos os aspectos do protocolo proposto e são desenvolvidos e mantidos pelo IETF 
(Internet Enginnering Task Force), instituição que especifica os padrões que serão implementados e utilizados em toda a internet.

'Switch' - comutador
- Um comutador (em inglês switch) é uma ponte multiportas, o que quer dizer que se trata de um elemento ativo que age no nível 2 do 'modelo OSI',
é um equipamento que interliga os computadores em uma rede, os cabos de rede de cada computador se ligam a ele, que então direciona os dados 
enviados de um computador especificamente para outro.

'Protocolos modem' 
- uso de linha telefônica para se acessar a internet.  A conexão faz-se graças a um modem, um aparelho capaz de converter os dados numéricos 
do computador em sinais analógicos (podendo circular na linha telefónica por modulação de amplitude ou de frequência, assim como a voz quando 
utiliza o telefone). Permite uma comunicação standard entre as diferentes máquinas que utilizam um modem, sobrecarregando a linha telefónica. 
São o 'SLIP' e o 'PPP'.

'SLIP' - serial line internet protocol (protocolo de internet de ligação serial)
- sem conexão, precede o 'TCP/IP'.

'PPP' - point to point protocol (protocolo ponto a ponto)
- são pacotes em datagramas, orientados à conexão. Melhores que o 'SLIP'.

'TCP' - transmission control protocol (protocolo de controle de transmissão)
- um dos quais se assenta o núcleo da internet. A versatilidade e robustez deste protocolo tornou-o adequado a redes globais, já que este 
verifica se os dados são enviados de forma correta, na sequência apropriada e sem erros, pela rede. O TCP é um protocolo de nível da 'camada de 
'transporte' (camada 4) do 'Modelo OSI' e é sobre o qual que se assentam a maioria das aplicações cibernéticas, como o 'SSH', 'FTP', 'HTTP' 
— portanto, a World Wide Web.

'UDP' - user datagram protocol (protocolo de datagrama de usuário)
- o protocolo UDP (User Datagram Protocol) é um protocolo não orientado para a conexão da camada transporte do modelo TCP/IP. Este protocolo é 
muito simples já que não fornece controlo de erros (não está orientado para a conexão…).

'HTTP' - hypertext transfer protocol (protocolo de transferência de hypertexto)
- O Hypertext Transfer Protocol (HTTP), em português Protocolo de Transferência de Hipertexto, é um protocolo de comunicação (na camada de 
aplicação segundo o 'Modelo OSI') utilizado para sistemas de informação de hipermídia, distribuídos e colaborativos.

'FTP' - file transfer protocol (protocolo de transferência de arquivos)
- FTP ou File Transfer Protocol (em português, Protocolo de Transferência de Arquivos) é uma forma bastante rápida e versátil de transferir 
arquivos (Portugal: conhecidos como ficheiros), sendo uma das mais usadas na Internet.

'SMTP' - simple mail transfer protocol
- Simple Mail Transfer Protocol (abreviado SMTP. Traduzido do inglês, significa "Protocolo de transferência de correio simples") é o protocolo 
padrão para envio de e-mails através da Internet. Ele foi padronizado pela RFC 821.

'DNS' - domain name system (domínio de nomes do sistema)
- O Domain Name System (DNS) é um sistema de gerenciamento de nomes hierárquico e distribuído para computadores, serviços ou qualquer recurso 
conectado à Internet ou em uma rede privada. Ele baseia-se em nomes hierárquicos e permite a inscrição de vários dados digitados além do nome 
do host e seu IP.
  
'IP' - internet protocol (protocolo de internet)
- IP significa Internet Protocol e é um número que seu computador (ou roteador) recebe quando se conecta à Internet. É através desse número que
seu computador é identificado e pode enviar e receber dados.

'QOS' - quality of service (qualidade de serviço)
- Em 'redes de comutação de circuitos', refere-se à probabilidade de sucesso em estabelecer uma ligação a um destino. Em 'redes de comutação de 
'pacotes' refere-se à garantia de largura de banda ou, como em muitos casos, é utilizada informalmente para referir a probabilidade de um pacote 
circular entre dois pontos de rede.

'FDMA' - frequency division multiple access (múltiplo acesso por divisão de frequência)
- FDMA (Frequency Division Multiple Access, ou Múltiplo Acesso por Divisão de Frequência) é um método de acesso ao canal que baseia-se na 
divisão da banda de frequência disponibilizada em faixas de frequência relativamente estreitas, 30KHz cada, as quais são denominadas canais 
e que são alocadas exclusivamente a um usuário durante todo o tempo de sua conexão (chamada). Esse tipo de técnica requer filtros passa-faixa 
de alta rejeição de banda. Além desse detalhe é utilizada a banda de guarda entre frequências adjacentes para não haver a necessidade de lidar
com desvios de frequência dos osciladores locais e minimizar a interferência entre canais adjacentes.

'TDMA' - time division multiple access (acesso múltiplo por divisão de tempo)
- Time Division Multiple Access , que quer dizer "Acesso Múltiplo por Divisão de Tempo". O TDMA é um sistema de celular digital que funciona
dividindo um canal de frequência em até oito intervalos de tempo distintos.

'TDM' - time division multiplexing (multiplexador por divisão de tempo)
- Este tipo de multiplexação, permite transmitir simultaneamente vários sinais, dentro do mesmo espaço físico (meio de transmissão), onde cada 
sinal (canal de comunicação), possui um tempo próprio e definido de uso da banda para transmissão.

'FDM' - frequency division multiplexing (multiplexador por divisão de frequência)
- Multiplexação por divisão de frequência (MDF), ou do inglês Frequency Division Multiplexing - FDM, é um tipo de multiplexação que permite 
transmitir simultaneamente vários sinais, dentro do mesmo espaço físico (meio de transmissão), onde cada sinal (canal de comunicação), possui 
uma banda espectral própria e bem definida.

'HTTPS' - hyper text transfer protocol secure - protocolo de transferência de hipertexto seguro
- HTTPS (Hyper Text Transfer Protocol Secure - protocolo de transferência de hipertexto seguro) é uma implementação do protocolo HTTP sobre 
uma camada adicional de segurança que utiliza o protocolo SSL/TLS. Essa camada adicional permite que os dados sejam transmitidos por meio de 
uma conexão criptografada e que se verifique a autenticidade do servidor e do cliente por meio de certificados digitais. A porta TCP usada por 
norma para o protocolo HTTPS é a 443.

'Splitter' - Ao contrário dos filtros comuns os splitters geralmente ficam ligados logo na entrada de linha de uma residência ou empresa, onde 
deste podem/devem derivar um par de fios que vão directamente para o modem e outro par para os dispositivos de voz. Desta forma o splitter tem 
a função de concentrar o sinal DSL apenas em um par de fios, evitando assim que o sinal DSL percorra toda a instalação interna perdendo as suas 
características ou sofrendo interferências.

'HFC' - hybrid fiber coax (fibra coaxial híbrida)
HFC (Hybrid Fiber Coax) é um termo usado em telecomunicações que identifica o tipo de rede utilizada.
Uma Rede híbrida, como a HFC utiliza simultaneamente 'Fibra óptica' e 'Cabos Metálicos'.
- Usada tanto para TV analógica, TV digital de alta definição como para acessar a internet em alta velocidade.
- É uma rede com taxa de transmissão 'compartilhada' e não 'dedicada' como no caso da 'ADSL'.
- Possui taxa de transmissão de até 38Mbps por canal utilizado. Utilizando DOCSIS 3.0 vários canais podem ser utilizados em conjunto atigindo 
  taxas de transmissão elevadas como 1Gbps.

'LAN' - local area network (rede local)
- rede de área local (acrônimo de local area network - LAN), ou ainda rede local, é uma rede de computadores utilizada na interconexão de 
equipamentos processadores com a finalidade de troca de dados. Um conceito mais preciso seria: é um conjunto de hardware e software que permite
a computadores individuais estabelecerem comunicação entre si, trocando e compartilhando informações e recursos. Tais redes são denominadas 
locais por cobrirem apenas uma área limitada (1 km no máximo, além do que passam a ser denominadas 'MANs'). Redes em áreas maiores necessitam 
de tecnologias mais sofisticadas, visto que, fisicamente, quanto maior a distância de um nó da rede ao outro, maior a taxa de erros que ocorrerão
devido à degradação do sinal.

'WLAN' - Wireless Local Area Network (rede local wifi)
- Wireless LAN ou WLAN (Wireless Local Area Network - Rede de área local sem-fio) é uma rede local que usa ondas de rádio para fazer uma conexão 
Internet ou entre uma rede, ao contrário da rede fixa ADSL ou conexão-TV, que geralmente usa cabos.

'WWAN' - Wireless Wide Area Network (Rede de longa distância sem-fio)
- WWAN (Wireless Wide Area Network - Rede de longa distância sem-fio) é uma tecnologia que as operadoras de celulares utilizam para criar a sua 
rede de transmissão (CDMA, GSM, etc). Com o advento das comunicações sem fio (wi-fi), surgiram diversos meios de transmitir dados sem se estar 
conectado por um cabo.

'TP' - twisted pair (par entrelaçado)
- Par de fios trançados de cobre isolados.

'ICMP' - Internet Control Message Protocol
-  protocolo integrante do Protocolo IP, definido pelo RFC 792, e utilizado para fornecer relatórios de erros à fonte original. Qualquer 
computador que utilize IP precisa aceitar as mensagens ICMP e alterar o seu comportamento de acordo com o erro relatado. Os gateways devem estar
programados para enviar mensagens ICMP quando receberem datagramas que provoquem algum erro.É um protocolo de controle, que opera no nível 3 
do modelo OSI (junto com o protocolo IP - rede). Ao contrário do TCP e UDP, o ICMP não é usado para a transmissão de dados, mas nem por isso deixa
de desempenhar diversas funções importantes. A mais trivial delas é o ping, que usamos para verificar se uma determinada máquina está online.

'backbone' - rede principal pela qual os dados de todos os clientes da Internet passam. É a espinha dorsal da Internet.

#aulas
'Capítulo 1 - Redes de computadores e a Internet'
- Visão geral:
  • O que é a Internet
  • O que é um protocolo?
  • Bordas da rede
  • Núcleo da rede
  • Rede de acesso e meio físico
  • Estrutura de Internet/ISP
  • Desempenho: perda, atraso
  • Camadas de protocolo, modelos de serviços
  • Modelagem de redes
- Uso da internet como exemplo

'1.1 O que é Internet?'
Tudo passa por um roteador antes!

'ISP' - internet service provider (provedor de serviços de internet)
• Milhões de elementos de computação interligados: 
  - hospedeiros = sistemas finais
• Executando aplicações distribuídas
• Enlaces de comunicação: fibra, cobre, rádio, satélite 
  - taxa de transmissão = largura de banda
• Roteadores: enviam pacotes (blocos de dados)
• Protocolos: controlam o envio e a recepção de mensagens
  - ex.: TCP, IP, HTTP, FTP, PPP
• Internet: “rede das redes”
  - fracamente hierárquica
  - Internet pública e Internets privadas (intranets)
• Internet standards
  - 'RFC': Request for comments
  - 'IETF': Internet Engineering Task Force
  
'1.1.1 Serviços de Internet'
• Infra-estrutura de comunicação permite aplicações distribuídas:
  - Web, e-mail, jogos, e-commerce, e-health, compartilhamento de arquivos
• Serviços de comunicação oferecidos:
  - sem conexão
  - orientado à conexão
  
'1.1.2 Protocolos de rede'
• Toda atividade de comunicação na Internet é governada por protocolos

'1.1.3 Uma visão mais de perto da estrutura da rede'
• Borda da rede: aplicações e hospedeiros
• Núcleo da rede: roteadores, rede das redes
• Redes de acesso, meio físico: enlaces de comunicação

'1.2 Borda da rede'
• Sistemas finais (hospedeiros):
  - Executam programas de aplicação
  - Ex.: Web, e-mail
  - Localizam-se nas extremidades da rede
• Modelo cliente/servidor
  - O cliente toma a iniciativa enviando pedidos que são respondidos por servidores
  - Ex.: Web client (browser)/server, e-mail, BitTorrent
• Modelo peer-to-peer:
  - Mínimo (ou nenhum) uso de servidores dedicados
  - Ex.: Whatsapp, Skype
• 'Serviço orientado à conexão'
  - Meta: transferência de dados entre sistemas finais.
  - Handshaking: estabelece as condições para o envio de dados antes de enviá-los
    - Alô: protocolo humano
    - Estados de “conexão” controlam a troca de mensagens entre dois hospedeiros
  - 'TCP - Transmission Control Protocol'
    - Realiza o serviço orientado à conexão da Internet
  - 'Serviço TCP [RFC 793]'
    - Transferência de dados confiável e seqüêncial, orientada à cadeia de bytes
      - Perdas: reconhecimentos e retransmissões
    - Controle de fluxo:
      - Evita que o transmissor afogue o receptor
    - Controle de congestão:
      - Transmissor reduz sua taxa quando a rede fica congestionada
• 'Serviço sem conexão'
  - Meta: transferência de dados entre sistemas finais. O mesmo de antes!
  - 'UDP - User Datagram Protocol [RFC 768]'
    - oferece o serviço sem conexão da Internet
      - Transferência de dados não confiável
      - Sem controle de fluxo
      - Sem controle de congestão
    - App’s usando TCP:
      - HTTP (Web), FTP (transferência de arquivo), Telnet (login remoto), SMTP (e-mail)
    - App’s usando UDP:
      - Streaming media, teleconferência, DNS telefonia IP
     
'1.3 Núcleo da rede'
• Malha de roteadores interconectados
• A questão fundamental:
  - como os dados são transferidos através da rede?
    - Comutação de circuitos: usa um canal dedicado para cada conexão.
      Ex.: rede telefônica
    - Comutação de pacotes: dados são enviados em “blocos” discretos.
• 'comutação de circuitos' 
  - Recursos fim-a-fim são reservados por “chamada”
  - Taxa de transmissão, capacidade dos comutadores
  - Recursos dedicados: não há compartilhamento
  - Desempenho análogo aos circuitos físicos ('QOS' garantido)
  - Exige estabelecimento de conexão
  - Recursos da rede (ex.: capacidade de transmissão) dividida em “pedaços”
    - “Pedaços” alocados às chamadas
    - “Pedaço” do recurso desperdiçado se não for usado pelo dono da chamada (sem divisão)
    - Formas de divisão da capacidade de transmissão em “pedaços”
      - 'Divisão em freqüência (FDMA)'
      - 'Divisão temporal (TDMA)'
• 'comutação de pacotes'
  - Cada fluxo de dados fim-a-fim é dividido em pacotes
    - Os recursos da rede são compartilhados em bases estatísticas
    - Cada pacote usa toda a banda disponível ao ser transmitido
    - Recursos são usados na medida do necessário
  - Contenção de recursos:
    - A demanda agregada por recursos pode exceder a capacidade disponível
    - Congestão: filas de pacotes, espera para uso do link
    - Armazena e reenvia: pacotes se movem um “salto” por vez
      - O nó recebe o pacote completo antes de encaminhá-lo
  - Banda passante é dividida em “slots”
  - Alocação fixa
  - Reserva de recursos
  - 'multiplexação estatística:'
    - A seqüência de pacotes A e B não possui padrão específico à multiplexação estatística
    - No 'TDM', cada hospedeiro adquire o mesmo slot dentro do frame TDM.
• 'comutação de pacotes x comutação de circuitos'
  - Comutação de pacotes permite que mais usuários usem a mesma rede!
    - Enlace de 1 Mbit/s
    - Cada usuário:
      - 100 Kbits/s quando “ativo”
      - Ativo 10% do tempo
   - Comutação de circuitos:
    - 10 usuários comutação de pacotes:
    - Com 35 usuários, probabilidade > 10 ativos menor que 0,0004
   - A comutação de pacotes é sempre melhor?
    - Ótima para dados esporádicos
      - Melhor compartilhamento de recursos
      - Não há estabelecimento de chamada
    - Congestionamento excessivo: atraso e perda de pacotes
      - Protocolos são necessários para transferência confiável, controle de congestionamento
    - Como obter um comportamento semelhante ao de um circuito físico?
      - Garantias de taxa de transmissão são necessárias para aplicações de áudio/vídeo
      - Problema ainda sem solução (capítulo 6).
• 'Comutação de pacotes: armazena e reenvia'
  - Leva L/R segundos para enviar pacotes de L bits para o link com R bps
  - O pacote todo deve chegar no roteador antes que seja transmitido para o próximo link: armazena e reenvia
  - Atraso = 3L/R
• 'Redes de comutação de pacotes: roteamento'
  - Objetivo: mover pacotes entre roteadores da origem ao destino
    - Iremos estudar vários algoritmos de seleção de caminhos (capítulo 4)
  - 'Redes datagrama':
    - O endereço de destino determina o próximo salto
    - Rotas podem mudar durante uma sessão
    - Analogia: dirigir perguntando o caminho
    - Diversos roteadores são autônomos ao decidir qual será o caminho adotado pelos pacotes.
  - 'Rede de circuitos virtuais':
    - Cada pacote leva um número (virtual circuit ID), o número determina o próximo salto
    - O caminho é fixo e escolhido no instante de estabelecimento da conexão, permanece fixo durante toda a conexão
    - Cada pacote possui em seu cabeçalho a informação sobre a qual circuito pertence e, independentemente do seu ponto de partida, fará o mesmo 
      caminho até chegar a um destino específico
  - Roteadores mantêm estado por conexão
  
• 'Taxonomia da rede'
  - Rede de datagramas não é nem orientada à conexão nem não orientada à conexão
  - A Internet provê serviços com orientação à conexão (TCP) e serviços sem orientação à conexão (UDP) para as apps.
  
'1.4 Acesso à rede e meio físico'
P.: Como conectar o sistema final ao roteador de borda?
  • Redes de acesso residencial
  • Redes de acesso institucionais (escolas, bancos, empresas)
  • Redes de acesso móveis
    - Lembre-se :
      - largura de banda (bits por segundo) da rede de acesso?
      - Compartilhado ou dedicado?
• 'Acesso residencial: redes ponto-a-ponto'
  - 'ADSL': Asymmetric Digital Subscriber Line
  - Até 1 Mbps de upstream na década de 90 (antes tipicamente < 256 kbps)
  - Até 8 Mbps de downstream na década de 90 (antes tipicamente < 1 Mbps)
  - FDM:
      50 kHz – 1 MHz para downstream
      4 kHz – 50 kHz para upstream
      0 kHz – 4 kHz para telefonia comum
• 'Acesso residencial: cable modems'
  - 'HFC: híbrido fibra e coaxial'
    - Assimétrico: até 30 Mbps upstream, 2 Mbps downstream a partir do ano 2000
  - Rede de cabo e fibra liga residências ao roteador do 'ISP'
    - Acesso 'compartilhado' das casas de um condomínio ou de um bairro
  - Deployment: disponível via companhias de TV a cabo.
• 'Acesso institucional: redes de área local'
  - A rede local (LAN) da companhia/univ 'conecta sistemas finais ao roteador' de acesso
  -  Ethernet:
    - Cabo compartilhado ou dedicado 'conecta sistemas finais e o roteador'
    - 10 Mbs, 100 Mbps, Gigabit Ethernet
    - LANs: capítulo 5 
• 'Redes de acesso sem fio'
  - Rede de acesso sem fio 'compartilhada' conecta sistemas finais ao roteador
    - Através de “ponto de acesso” da estação base
  -  LANs sem fio ('WLAN'):
    - 802.11b (WiFi): 11 Mbps
    - 802.11a/b/g/n/ac
  - Wireless Wide-Area Network ('WWAN'):
    - Provido pelo operador telecom
    - 2G, 3G, 4G
  
  LAN – Rede Local 
  As chamadas Local Area Networks, ou Redes Locais, interligam computadores presentes dentro de um mesmo espaço físico. Isso pode acontecer 
  dentro de uma empresa, de uma escola ou dentro da sua própria casa, sendo possível a troca de informações e recursos entre os dispositivos 
  participantes. 
  
  MAN – Rede Metropolitana 
  Imaginemos, por exemplo, que uma empresa possui dois escritórios em uma mesma cidade e deseja que os computadores permaneçam interligados.
  Para isso existe a Metropolitan Area Network, ou Rede Metropolitana, que conecta diversas Redes Locais dentro de algumas dezenas de quilômetros. 
  
  WAN – Rede de Longa Distância 
  A Wide Area Network, ou Rede de Longa Distância, vai um pouco além da MAN e consegue abranger uma área maior, como um país ou até mesmo 
  um continente. 
  
  WLAN – Rede Local Sem Fio 
  Para quem quer acabar com os cabos, a WLAN, ou Rede Local Sem Fio, pode ser uma opção. Esse tipo de rede conecta-se à internet e é bastante 
  usado tanto em ambientes residenciais quanto em empresas e em lugares públicos. 
  
  WMAN – Rede Metropolitana Sem Fio
  Esta é a versão sem fio da MAN, com um alcance de dezenas de quilômetros, sendo possível conectar redes de escritórios de uma mesma empresa 
  ou de campus de universidades.
  
  WWAN – Rede de Longa Distância Sem Fio 
  Com um alcance ainda maior, a WWAN, ou Rede de Longa Distância Sem Fio, alcança diversas partes do mundo. Justamente por isso, a WWAN está 
  mais sujeita a ruídos. 
  
  SAN – Rede de Área de Armazenamento 
  As SANs, ou Redes de Área de Armazenamento, são utilizadas para fazer a comunicação de um servidor e outros computadores, ficando restritas 
  a isso. PAN – Rede de Área Pessoal As redes do tipo PAN, ou Redes de Área Pessoal, são usadas para que dispositivos se comuniquem dentro de 
  uma distância bastante limitada. Um exemplo disso são as redes Bluetooth e UWB.
  
• 'Componentes típicos de uma rede residencial:'
  - ADSL ou cable modem
  - Roteador/firewall
  - Ethernet
  - Ponto de acesso sem fio
  
• 'Meios físicos'
  - Bit: propaga-se entre os pares transmissor/ receptor
  - Enlace físico: meio que fica entre o transmissor e o receptor
  - Meios guiados:
    - Os sinais se propagam me meios sólidos com caminho fixo: cobre, fibra
  - Meios não guiados:
    - Propagação livre, ex.: rádio
  - 'Twisted Pair (TP)'
  - Par de fios trançados de cobre isolados
    - Categoria 3: taxas de transmissão até 10 Mbps
    - Categoria 5: 100 Mbps Ethernet
  - 'Cabo coaxial:'
    - Dois condutores de cobre concêntricos
    - bidirecional 
    - legado da ethernet 
  - 'Cabo de filbra óptica'
    - Fibra de vidro transportando pulsos de luz, cada pulso é um bit
    - Alta velocidade de operação (ponto-a-ponto)
    - Baixa taxa de erros:
    - Repetidores bem espaçados; imunidade a ruídos eletromagnéticos
    - Usado para longas distâncias.
  - 'Rádio'
    - Sinal transportado como campo eletromagnético
    - Não há fios físicos
    - Bidirecional
    - 'Bluetooth', 'wifi', '3G'
    - O ambiente afeta a propagação:
      - Reflexão
      - Obstrução por objetos
      - Interferência
    - Tipos de canais de rádio:
      - Microondas terrestre
	- Canais de até 45 Mbps
      - LAN (ex.: extensão pelo WiFi (WLAN))
	- 2 Mbps, 11 Mbps até 300 Mbps
      - Wide-area (ex.: extensão pela rede celular (WWAN))
	- Ex., 3G: centenas de kbps
      - Satélite
	- Canal de até 50 Mbps (ou vários canais menores)
	- 270 ms de atraso fim-a-fim
	- Geossíncrono versus LEOS

'1.5 Estrutura da Internet e ISPs'
• No centro: ISPs de “zona-1” (ex.: UUNet, BBN/Genuity, Sprint, AT&T), cobertura national/international
  - Sprint é a 'backbone'
• ISPs de ”Zona-2”: ISPs menores (freqüentemente regionais)
  - Conectam-se a um ou mais ISPs de Zona-1, possivelmente a outros ISPs de Zona-2  
• ISPs de “Zona-3” e ISPs locais
  - Última rede de acesso (“hop”) (mais próxima dos sistemas finais)
• Um pacote passa através de muitas redes
  
'1.6 Atraso e perda em redes de comutação de pacotes'
Filas de pacotes em buffers de roteadores
• Taxa de chegada de pacotes ao link ultrapassa a capacidade do link de saída
• Fila de pacotes esperam por sua vez

Fontes de atraso de pacotes:
1. Processamento nos nós:
  • Verifica erros de bit
  • Determina link de saída
2. Enfileiramento
  • Tempo de espera no link de saída para transmissão
  • Depende do nível de congestionamento do roteador
3. Atraso de transmissão:
  • R= largura de banda do link (bps)
  • L= tamanho do pacote (bits)
  • Tempo para enviar bits ao link = L/R
4. Atraso de propagação:
  • d = comprimento do link físico
  • s = velocidade de propagação no meio (~2x10 8 m/s)
  • Atraso de propagação = d/s

'Atraso nodal'
d.no = d.proc + d.fila + d.trans + d.prop

• d.proc = atraso de processamento
    • Tipicamente uns poucos microssegundos ou menos
• d.fila = atraso de fila
    • Depende do congestionamento
• d.trans = atraso de transmissão
    • = L/R, significante para links de baixa velocidade
• d.prop = atraso de propagação
    • Uns poucos microssegundos a centenas de milissegundos
    
• R = largura de banda do link (bps)
• L = tamanho do pacote (bits)
• A = taxa média de chegada de pacotes

Intensidade de tráfego = La/R
• La/R ~ 0: atraso médio de fila pequeno
• La/R -> 1: atraso se torna grande
• La/R > 1: mais trabalho chega do que a capacidade de transmissão.
O atraso médio cresce indefinidamente!

• Como são os atrasos e perdas na Internet “real”?
Programa Traceroute: fornece medidas do atraso da fonte para o roteador
ao longo de caminhos fim-a-fim da Internet até o destino. Para todo i:
• Envia três pacotes que alcançarão o roteador i no caminho até o destino
• O roteador i retornará pacotes ao emissor
• O emissor cronometra o intervalo entre transmissão e resposta.

• A fila (isto é, buffer) no buffer que precede o link possui
capacidade finita
• Quando um pacote chega a uma fila cheia, ele é descartado
(isto é, perdido)
• O pacote perdido pode ser retransmitido pelo nó anterior, pelo
sistema final do emissor, ou não ser retransmitido

'1.7 Camadas de protocolo, modelos de serviço'

Redes são complexas
• Muitos componentes:
• Hospedeiros
• Roteadores
• Enlaces de vários tipos
• Aplicações
• Protocolos
• Hardware, software

Camadas: cada camada implementa um serviço
• Via suas próprias ações internas
• Confiando em serviços fornecidos pela camada inferior

'Pilha de protocolos da Internet'
• Aplicação: suporta as aplicações de rede
     • FTP, SMTP, HTTP
• Transporte: transferência de dados hospedeiro-hospedeiro
    • TCP, UDP
• Rede: roteamento de datagramas da origem ao destino
    • IP, protocolos de roteamento
• Enlace: transferência de dados entre elementos vizinhos da rede
    • PPP, Ethernet
• Física: bits “nos fios dos canais”

'2. Camada de aplicação'
//----------------------------------------- 
 HTTP(tcp 80) - hypertext transfer protocol - camada de aplicação da web
 FTP (tcp 21) - file transfer protocol	    - transferência de arquivos de e para o computador remoto
 correio
    SMTP(tcp 25) - simple mail transfer protocol - cliente->servidor; servidor->servidor
    POP3(tcp 110)- Post Office Protocol 	 - servidor-cliente - “download-and-delete”
    IMAP(tcp 143) - Internet Mail Access Protocol - servidor-cliente - Mantém todas as mensagens no servidor.
 DNS()
 P2P()
 Telnet(tcp)
 RTP(tcp/udp)
 NSF(tcp/udp)
 RTP(udp)
 Cookies = banco de dados beckend
 'MIME: multimedia mail extension'
//----------------------------------------
• E-mail
• Web
• Mensagem instantânea
• Login remoto
• P2P file sharing
• Jogos de rede multi-usuário
• Streaming stored videoclipes
• Telefonia via Internet
• Videoconferência em tempo real
• Computação paralela massiva
    
- Nenhum software é escrito para dispositivos no núcleo da rede

Cliente-servidor x P2P pura
'Arquitetura cliente-servidor'
Servidor:
• Hospedeiro sempre ativo
• Endereço IP permanente
• Fornece serviços solicitados pelo cliente
Clientes:
• Comunicam-se com o servidor
• Pode ser conectado intermitentemente
• Pode ter endereço IP dinâmico
• Não se comunicam diretamente uns com os outros
'Arquitetura P2P pura'
• Nem sempre no servidor
• Sistemas finais arbitrários comunicam-se diretamente
• Pares são intermitentemente conectados e trocam endereços IP
• Ex.: Gnutella
Altamente escaláveis mas difíceis de gerenciar
'Híbrida de cliente-servidor e P2P'
'Napster' - Transferência de arquivo P2P, conteúdo de registro dos pares no servidor central.
'Instant messaging' - Bate-papo entre dois usuários é P2P.

Comunicação de processos
'Processo': programa executando num hospedeiro. Interprocesso ou entre cliente e servidor.
'Sockets': Um processo envia/recebe mensagens para/de seu socket. O socket é análogo a uma porta.
'Para identificar o processo':
- endereço IP (mas muitos processos podem estar em execução no mesmo hospedeiro).
- número da porta associada ao processo.
file transfer		sem perdas		não sensivel
e-mail			sem perdas		não sensivel
web documents		tolerante		não sensivel
real time		tolerante		sensivel
stored audio-video	tolerante		sensivel
jogos			tolerante		sensivel
e-business		sem perdas		sensivel

TCP = Orientado à conexão, confiável, controle de fluxo, controle de congestionamento.
UDP = Nada.

Web e HTTP - 1.0 e 1.1
- Página Web consiste de objetos
  • Objeto pode ser arquivo HTML, imagem JPEG, Java applet, arquivo de áudio,...
  • de arquivo-HTML base que inclui vários objetos referenciados (urls)
  www.someschool.edu('hospedeiro')/someDept/pic.gif('caminho')
  • Cliente: browser que solicita, recebe e apresenta objetos da Web.
  • Servidor: envia objetos em resposta a pedidos.
- stateless
'HTTP não persistente'
A conexão TCP é desfeita ao final da entrega de cada objeto. A conexão NÃO PERSISTE para outros objetos.
O browser pode abrir várias conexões TCP simultâneas (paralelismo). Pode sobrecarregar o Servidor 
(administração de mais buffers e variáveis TCP no lado Cliente e Servidor) e tem maior tempo de resposta 
(requisição de conexão a cada objeto solicitado). O HTTP/1.0 utiliza HTTP não persistente.

- O 1.0, no máximo, um objeto é enviado sobre uma conexão TCP.
2. Cliente HTTP envia HTTP request message (contendo a URL) para o socket da conexão TCP.
3. Servidor HTTP recebe mensagem de pedido, forma response message contendo o objeto solicitado (someDepartment/
home.index), envia mensagem para o socket.
'RRT (Round-Trip Time)': tempo para enviar um pequeno pacote que vai do cliente para o servidor e retorna.
Total = 2RTT+ tempo de transmissão
'HTTP persistente'
HTTP persistente Múltiplos objetos podem ser enviados sobre uma mesma conexão TCP (com paralelismo ou 
sem paralelismo). Sem paralelismo, o Servidor fica ocioso entre o final do envio do objeto e a recepção 
da requisição de envio do próximo objeto (desperdício de recurso) e maior tempo de reposta para montar a 
página WEB. O HTTP/1.1 utiliza conexões persistentes em seu modo padrão.

- O 1.1, Múltiplos objetos podem ser enviados sobre uma conexão TCP entre o cliente e o servidor.
- Requer 2 RTTs por objeto
- OS deve manipular e alocar recursos do hospedeiro para cada conexão TCP. Mas os browsers freqüentemente 
abrem conexões TCP paralelas para buscar objetos referenciados.
  'Persistente sem pipelining:'
  - cliente emite novas requisições apenas quando a resposta anterior for recebida. Um RTT para cada objeto.
  'Persistente com pipelining:'
  - Padrão no HTTP/1.1. O cliente envia requisições assim que encontra um objeto referenciado. Um RTT para todos.
'HTTP request'
- ASCII (formato legível para humanos)
- Linha de pedido (comandos GET, POST, HEAD )
- Carriage return, line feed indica fim da mensagem
- Post: entrada de formulário
- Url: usa GET
HTTP 1.0 = GET, POST, HEAD
HTTP/1.1 = GET, POST, HEAD, PUT
DELETE = Apaga o arquivo especificado no campo de URL
'HTTP response'
"Client request Server, Server response Client"
Códigos de status das respostas
200 OK, 301 Moved permanently(erro servidor), 400 Bad request(erro cliente), 505 (erro outros).
/* telnet cis.poly.edu 80
 * GET /~ross/ HTTP/1.1
   host: cis.poly.edu
 */ 
Web caching (Proxy) = instalado pelo ISP. Reduz tempo de resposta e tráfego.

Correio eletrônico
Três componentes principais:
• Agentes de usuário			- Outlook
• Servidores de correio			- Caixa postal, fila de mensagens, smtp
• Simple mail transfer protocol: SMTP
 
DNS
Cliente quer o IP para www.amazon.com; 1 a aprox.:
• Cliente consulta um servidor de raiz para encontrar o servidor DNS com
• Cliente consulta o servidor DNS com para obter o servidor DNS amazon.com
• Cliente consulta o servidor DNS amazon.com para obter o endereço IP para
www.amazon.com
'Servidores top-level domain (TLD)': responsáveis pelos domínios com, org, net,
edu etc e todos os domínios top-level nacionais uk, fr, ca, jp.
'Servidores DNS autorizados': servidores DNS de organizações, provêm nome de
hospedeiro autorizado para mapeamentos IP para servidores de organizações
(ex.: Web e mail).
Cabeçalho da msg
• Identificação: número de 16 bits para consulta, resposta usa o mesmo número
• Flags:
• Consulta ou resposta
• Recursão desejada
• Recursão disponível
• Resposta é autorizada

• Exemplo: empresa recém-criada “Network Utopia”
•  Registrar o nome networkuptopia.com num “registrar” (ex.: Network Solutions)
• É necessário fornecer ao registrar os nomes e endereços IP do seu servidor nomes autorizados (primário e secundário)
• Registrar insere dois RRs no servidor TLD do domínio com:
'Name Server e Address'

P2P
o arquivo é copiado do PC de Bob para o notebook de Alice: HTTP
• enquanto Alice faz o download, outros usuários fazem upload de Alice.

Gnutella: protocolo
• Mensagem de consulta (query) é enviada pelas conexões TCP existentes
• Os pares encaminham a mensagem de consulta

'3. Camada de transporte'
//----------------------------------------- 
UDP: transporte não orientado à conexão
TCP: transporte orientado à conexão
//----------------------------------------- 
• Multiplexação/demultiplexação
• Transferência de dados confiável
• Controle de fluxo
• Controle de congestionamento

- Fornecem comunicação lógica entre processos de aplicação em diferentes hospedeiros.
- Executados nos sistemas finais.
'Lado emissor': quebra as mensagens da aplicação em segmentos e envia para a camada de rede.
'Lado receptor': remonta os segmentos em mensagens e passa para a camada de aplicação.

• 'Camada de rede': comunicação lógica entre os hospedeiros.
• 'Camada de transporte': comunicação lógica entre os processos.
• Depende dos serviços da camada de rede.

'TCP'
- Confiável, garante ordem de entrega.
- Controle de congestionamento.
    • Controle de fluxo
    • Orientado à conexão
'Ponto-a-ponto, Confiável, seqüencial byte stream, Pipelined, Buffers de transmissão e de recepção,
'Controle de fluxo, Dados full-duplex, Orientado à conexão.
- Desenvolver incrementalmente o transmissor e o receptor de um protocolo confiável de transferência de dados ('rdt')
- Canal de transmissão perfeitamente confiável
    • Não há erros de bits
    • Não há perdas de pacotes
- FSMs separadas para transmissor e receptor:
    • Transmissor envia dados para o canal subjacente
    • Receptor lê os dados do canal subjacente
'rdt2.0': canal com erros de bit.
A questão: como recuperar esses erros:
    • Reconhecimentos (ACKs): receptor avisa explicitamente ao transmissor que o pacote foi recebido corretamente
    • Reconhecimentos negativos (NAKs): receptor avisa explicitamente ao transmissor que o pacote tem erros
    • Transmissor reenvia o pacote quando da recepção de um NAK
    • Novos mecanismos no rdt2.0 (além do rdt1.0):
    • Detecção de erros
    • Retorno do receptor: mensagens de controle (ACK, NAK) rcvr->sender
O que acontece se o ACK/NAK é corrompido?
    • Transmissor não sabe o que aconteceu no receptor!
    • Não pode apenas retransmitir: possível duplicata
'rdt2.1: discussão'
'rdt2.2: um protocolo sem NAK'
'rdt3.0: canais com erros e perdas'
    Nova hipótese: canal de transmissão pode também perder pacotes (dados aos ACKs)
    olhar fórmula de desempenho
'Protocolos com paralelismo (pipelining)'
Paralelismo: transmissor envia vários pacotes ao mesmo tempo, todos esperando para serem reconhecidos
    • Faixa de números de seqüência deve ser aumentada
    • Armazenamento no transmissor e/ou no receptor
    Duas formas genéricas: 'go-Back-N', 'retransmissão seletiva'.
'go-Back-N'
    - Go-Back-N
    Transmissor:
      • Número de seqüência com k bits no cabeçalho do pacote
      • “janela” de até N pacotes não reconhecidos, consecutivos, são permitidos
    • ACK(n): reconhece todos os pacotes até o número de seqüência N (incluindo este limite). “ACK cumulativo”
    • Pode receber ACKs duplicados (veja receptor)
    • Temporizador para cada pacote enviado e não confirmado
    • Tempo de confirmação (n): retransmite pacote n e todos os pacotes com número de seqüência maior que estejam dentro da janela
    Receptor:
    • Somente ACK: sempre envia ACK para pacotes corretamente recebidos com o mais alto número de seqüência em ordem
    • Pode gerar ACKs duplicados
    • Precisa lembrar apenas do expectedseqnum
    • Pacotes fora de ordem:
    • Descarta (não armazena) -> não há buffer de recepção!
    • Reconhece pacote com o mais alto número de seqüência em ordem
'Retransmissão seletiva'
• Janela de transmissão
• N números de seqüência consecutivos
• Novamente limita a quantidade de pacotes enviados, mas não reconhecidos
janelas do transmissor e do receptor
Se o próximo número de seqüência disponível está na janela, envia o pacote
Fora de ordem: armazena
'Estrutura do segmento TCP'
URG: dados urgentes (pouco usados)
ACK: campo de ACK é válido
PSH: produz envio de dados (pouco usado)
RST, SYN, FIN: estabelec. de conexão (comandos de criação e término)
Internet checksum (como no UDP)
contagem por bytes de dados (não segmentos!)
número de bytes receptor está pronto para aceitar
Números de seqüência: • Número do primeiro byte nos segmentos de dados
ACKs:•  Número do próximo byteesperado do outro lado
'TCP Round Trip Time e temporização'
Muito longo: a reação à perda de segmento fica lenta ou Muito curto: temporização prematura(Retransmissões desnecessárias)
'SampleRTT'= Usar várias medidas recentes.
ver fórmula
Primeiro estimar o quanto o SampleRTT se desvia do EstimatedRTT
Então ajustar o intervalo de temporização
'TCP: transferência de dados confiável'
'TCP: controle de fluxo'
- Controle de fluxo Transmissor não deve esgotar os buffers de recepção enviando dados rápido demais.
- Serviço de speed-matching: encontra a taxa de envio adequada à taxa de vazão da aplicação receptora.
(suponha que o receptor TCP descarte segmentos fora de ordem)
'Gerenciamento de conexão TCP'
- TCP transmissor estabelece conexão com o receptor antes de trocar segmentos de dados
'Three way handshake:'
  Passo 1: sistema final cliente envia TCP SYN ao servidor
    • Especifica número de seqüência inicial
  Passo 2: sistema final servidor que recebe o SYN, responde com segmento SYNACK
    • Reconhece o SYN recebido
    • Aloca buffers
    • Especifica o número de seqüência inicial do servidor
  Passo 3: o sistema final cliente reconhece o SYNACK
	   cliente recebe FIN, responde com ACK.
	   • Entra “espera temporizada” - vai responder com ACK a FINs recebidos
  Passo 4: servidor, recebe ACK.
    • Conexão fechada
    • Nota: com uma pequena modificação, pode-se manipular FINs simultâneos

'Princípios de controle de congestionamento'
- Só leitura! 
- Quando a conexão começa, a taxa aumenta rapidamente de modo exponencial até a ocorrência do primeiro evento de perda.
    • Após 3 ACKs duplicados:
    • CongWin é cortado pela metade
    • Janela então cresce linearmente
'TCP throughput'
'Futuro do TCP'
'Eqüidade do TCP'


'UDP'
- Não confiável, sem ordem de entrega.
    • Extensão do “melhor esforço” do IP
- Sem garantia de atraso e sem garantia de banda
• Serviço “best effort” , segmentos UDP podem ser:
    • Perdidos
    • Entregues fora de ordem para a aplicação
• Cabeçalho de segmento reduzido
• Não há controle de congestionamento: UDP pode enviar segmentos tão rápido quanto desejado (e possível)
- aplicações de mutimídia contínua (streaming)
    • Tolerantes à perda
    • Sensíveis à taxa
'checksum - 16bits'
    - detectar “erros” (ex.: bits trocados) no segmento transmitido
    - Checksum: soma (complemento de 1 da soma) do conteúdo do segmento
    - Transmissor coloca o valor do checksum no campo de checksum do UDP
    - Receptor verifica se o checksum calculado é igual ao valor do campo checksum

'Multiplexação/demultiplexação'
Multiplexação (emissor) = coleta dados de múltiplos sockets, envelopa os dados com cabeçalho (usado depois para demultiplexação).


Demultiplexação(receptor) = entrega os segmentos recebidos ao socket correto.
• O hospedeiro usa endereços IP e números de porta para direcionar o segmento ao socket apropriado
'Não orientada à conexão'
  - Cria sockets com números de porta
  - Socket UDP identificado por 2 valores: (endereço IP de destino, número da porta de destino)
  - Quando o hospedeiro recebe o segmento UDP:
    • Verifica o número da porta de destino no segmento
    • Direciona o segmento UDP para o socket com este número de porta
  - Datagramas com IP de origem diferentes e/ou portas de origem diferentes são direcionados para o mesmo socket
  - DatagramSocket serverSocket = new DatagramSocket(6428/*porta de destino*/);
'Orientada à conexão'
  - Socket TCP identificado por 4 valores:(Endereço IP de origem, End. porta de origem, Endereço IP de destino, End. porta de destino)
  - Hospedeiro receptor usa os quatro valores para direcionar o segmento ao socket apropriado
  - Hospedeiro servidor pode suportar vários sockets TCP simultâneos
    • Cada socket é identificado pelos seus próprios 4 valores
    • Servidores Web possuem sockets diferentes para cada cliente conectado
    • HTTP não persistente terá um socket diferente para cada requisição

'CAMADA DE REDE'

• Roteamento (seleção de caminho) - diferente de comutaçao
• Escalabilidade
• Como funciona um roteador
• Tópicos avançados: IPv6, mobilidade
• Instanciação e implementação na Internet

4.1 Introdução
4.2 Circuito virtual e redes de datagrama
4.3 O que há dentro de um roteador
4.4 IP: Protocolo da Internet
    • Formato do datagrama
    • Endereçamento IPv4
    • ICMP
    • IPv6
• 4.5 Algoritmos de roteamento
    • Link state
    • Distance vector
    • Roteamento hierárquico
• 4.6 Roteamento na Internet
    • RIP
    • OSPF
    • BGP
• 4.7 Roteamento de broadcast e multicast

• Comutação (repasse): mover pacotes da entrada do roteador para a saída apropriada do roteador
•  Roteamento: determinar a rota a ser seguida pelos pacotes desde a origem até o destino.
    • Algoritmos de roteamento
    
enlace: ATM, frame relay, X.25

- antes que os datagramas fluam, dois hospedeiros finais e roteadores entre eles estabelecem conexão virtual
    ❍  roteadores são envolvidos
    
Arquitetura de rede: Internet, ATM
Modelo de serviço: melhor esforço, CBR, VBR, ABR, UBR
Banda: 	não, taxa constante, taxa garantida, mínimo garantido
Perda: sim, não
Ordem: sim, não
Tempo: sim, não
Realimentação de congestão: não(examina perdas), não há congestão, sim, não

'conexão e sem-conexão'
sem-conexão: rede de datagrama
com conexão: circuito virtual

'circuito virtual'
- a rede controla a conexão entre a origem e o destino, como ligação telefônica
- cada pacote transporta um identificador do CV

Um VC consiste de:
1.Caminho da origem até o destino
2.Números de VC, um número para cada link ao longo do caminho
3.Entradas em tabelas de comutação em roteadores ao longo do caminho
• Pacotes pertencentes a um VC carregam um número de VC.
•  O número de VC deve ser trocado em cada link.
• Novos números de VC vêm da tabela de comutação

• Não existe estabelecimento de conexão na camada de rede
• Pacotes para o mesmo destino podem seguir diferentes rotas

ATM - Originário da telefonia

Duas funções-chave do roteador:
• Executar algoritmos/protocolos ('RIP', 'OSPF', 'BGP')
• Comutar os datagramas do link de entrada para o link de saída

• 'Buffering' necessário quando datagramas chegam do switch mais rápido do que a taxa de transmissão
Queueing (atraso) e perda devido ao buffer overflow da porta de saída!
• 'Disciplina de agendamento' escolhe entre os datagramas na fila para transmissão

IP header

versão
tam header
num max saltos
prot. camada superior
tam total datagrama
flags fragmentação
marca de tempo
registro de rota

'MTU' - maximum transfer size 
• “remontagem” ocorre apenas no destino final
• O cabeçalho IP é usado para identificar e ordenar datagramas relacionados

• Interface: conexão entre roteador ou hospedeiro e enlace físico
• Roteador tem tipicamente múltiplas interfaces
• Hospedeiros podem ter múltiplas interfaces
• Endereços IP são associados com interfaces, não com o hospedeiro ou com o roteador

• Parte da sub-rede (bits de ordem superior)
• Part do hospedeiro (bits de ordem inferior)
• subredes podem alcançar fisicamente uns aos outros sem intervenção de roteador.

'CIDR': Classless InterDomain Routing
'DHCP': dynamic host configuration protocol: obtém dinamicamente endereços IP de um servidor
'ICANN': internet corporation for assigned names and numbers
    • Aloca endereços
    • Gerencia DNS
    • Atribui nomes de domínios e resolve disputas
    
'NAT': Network Address Translation
'ICMP': Internet Control Message Protocol

• Usado por computadores e roteadores para troca de informação de controle da camada de rede
• Error reporting: hospedeiro, rede, porta ou protocolo 
• Echo request/reply (usado pela aplicação ping)

'traceroute' faz isso três vezes = envia series de segmentos a partir de TTL=1 e vai aumentando.

IPV6
'Priority': permitir definir prioridades diferenciadas para vários fluxos de informação
'Flow label': identifica datagramas do mesmo “fluxo.” (conceito de “fluxo” não é bem definido).
'Next header': identifica o protocolo da camada superior ou um header auxiliar
• 'Checksum': removido inteiramente para reduzir o tempo de processamento em cada salto
• 'Options': são permitidas, mas são alocadas em cabeçalhos suplementares, indicados pelo campo “Next header”
• 'ICMPv6': nova versão de ICMP
• 'Tipos de mensagens adicionais' , ex.: “Packet Too Big”
• 'Funções de gerenciamento' de grupos multicast

• 'Tunelamento': IPv6 transportado dentro de pacotes IPv4 entre roteadores IPv4

'Algoritmo de roteamento': algoritmo que encontra o caminho de menor custo.
Algoritmos “link state” (LS), distance vector (VD - estatico ou dinamico).
distance vector = algoritmo de Bellman-Ford (programação dinâmica).

'Roteamento hierárquico'
• Agrega roteadores em regiões, “sistemas autônomos ” (AS)
• Roteadores no mesmo AS rodam o mesmo protocolo de roteamento
• Link direto para um roteador em outro AS por um Roteador Gateway

Roteamento intra-AS - Também conhecido como Interior Gateway Protocols ('IGP')
• Protocolos de roteamento intra-AS mais comuns:
• RIP: Routing Information Protocol
• OSPF: Open Shortest Path First
• IGRP: Interior Gateway Routing Protocol (proprietário da Cisco)

'RIP'
• Algoritmo do tipo vetor distância
• Incluso na distribuição do BSD-UNIX em 1982
• Métrica de distância: # de saltos (máx. = 15 saltos)
• Vetores de distância: trocados a cada 30 s via Response Message (também chamado advertisement, ou anúncio)
• Cada anúncio indica rotas para até 25 redes de destino

'OSPF (Open Shortest Path First)'
•“open”: publicamente disponível
• Usa algoritmo do tipo link state
• Disseminação de pacotes LS
• Mapa topológico em cada nó
• Usa algoritmo de Dijkstra para cálculo de rotas
• Anúncios do OSPF transportam um registro para cada roteador vizinho
• Anúncios são distribuídos para todo o AS (via flooding)
• Transportado por mensagens OSPF diretamente sobre IP (melhor do que TCP ou UDP)
•  Hierarquia de dois níveis: área local e backbone.
• Anúncios de link state apenas nas áreas
• Cada nó tem a topologia detalhada da área, mas somente direções conhecidas 
  (caminhos mais curtos) para redes em outra áreas.

'BGP (Border Gateway Protocol): é o padrão de fato para uso na Internet'
• BGP provê cada AS dos meios para:
  1. Obter informações de alcance de sub-rede dos Ass. Vizinhos
  2. Propagar informações de alcance para todos os roteadores internos ao AS
  3. Determinar “boas” rotas para as sub-redes baseado em informações de alcance e política
• Permite que uma subnet comunique sua existência para o resto da Internet: “Estou aqui”
• Mensagens BGP são trocadas usando o TCP
• Mensagens BGP:
• OPEN: abre conexão TCP para o peer e autentica o transmissor
• UPDATE: comunica novo caminho (ou retira um antigo)
• KEEPALIVE mantém a conexão ativa na ausência de atualizações (updates); também ACKs OPEN request
• NOTIFICATION: reporta erros em mensagens anteriores; também usado para fechar a conexão

'DVMRP': distance vector multicast routing protocol, RFC1075
• flood and prune: reverse path forwarding, source-based tree

'PIM': Protocol Independent Multicast
O que foi coberto:
• Serviços da camada de rede
• Princípios de roteamento: link state e distance vector
• Roteamento hierárquico
• IP
• Protocolos de roteamento da Internet: RIP, OSPF, BGP
• O que há dentro de um roteador?
• IPv6

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
networks. ARP was defined by RFC 826
 in 1982, is Internet Standard STD 37, and is also the 
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


#APLICAÇÂO

-DNS= traduzir de um 'nome de domínio' para seu respectivo 'endereço IP'.
    = 'em caches' browser->SO-> Recursive Resolver -> servidor Root -> TLD Name Server -> 'sem cache' Authoritative Name Servers -> Web Server
	- Recursive Resolver		= operado pelo ISP, faz todo o caminho
	- servidor Root			= 13 no mundo em vários físicos. Informações 'TLD - Top Level Domain' como .com 
	- TLD Name Server		= Informações do segundo nível do domínio, dos Authoritative Name Servers
	- Authoritative Name Servers	= Informações IP de qualquer hierarquia do domínio. Mais de um para casos de falha e segurança
	-  Web Server			= contém conteúdo do IP
	 ('Domain Registrar e Glue Records')
	 
	 
#TRANSPORTE
	 
-TCP= orientado à conexão. '3-way handshake'.
    = cabeçalho
	- números de porta de fonte e destino: para camadas superiores
	- campos de número de sequência e de reconhecimento: comunicação confiável
	- campo de janela de recepção: controle de fluxo
	- campo de comprimento de cabeçalho
	- campo de opções
	- campo de flag: 6 bits
	    - ACK: reconhecimento
	    - RST: resetar
	    - SYN: sincronizar números de sequência
	    - FIN: finalizar a transmissão
    = 3-way handshake
	- servidor escuta própria porta (abertura passiva)
	- cliente inicia comunicaçao	(abertura ativa)
	- SYN: cliente: 	 SYN - this->seq=A			//Seq=42, ACK=79, dados='C'
	- SYN-ACK: servidor: SYN-ACK - this->seq=B   - this->req=A+1  	//Seq=79, ACK=43, dados='C'
	- ACK: cliente: 	 ACK - this->seq=A+1 - this->req=B+1	//Seq=43, ACK=80
	FIN - ACK - FIN - ACK

#REDE

-NAT= solução para baixo range do IPv4 ('endereços públicos e endereços privados')
    = NAT está presente no roteador - entre rede privada e o resto do mundo - mapeamento tabelado
    = endereçamento dos dispositivos privados feito pelo 'DHCP'
    = A(10.0.0.0 a 10.255.255.255);B(172.16.0.0 a 172.31.255.255);C(192.168.0.0 a 192.168.255.255)
    = endereço público adquirido de uma ISP (exclusívo - chamado 'gateway')
      - Estático:    1pra1     - mesmo público para mesmo privado
      - Dinâmico:    1pra1     - IPs públicos à medida dos pedidos
      - Overloading: 1praTodos - 1 público para a rede local - necessita portas('PAT') 
      
#ENLACE/FÍSICA
      
-ATM= alta velocidade; comutação de pacotes; cabeamento de cobre, em par trançado, ou fibra óptica; full duplex
    = provê 'QoS' - contrato com canal virtual - exigindo uma série de coisas dele.
    = ponto-a-ponto com switchs(comutadores) - caminhos virtuais(sem roteadores)
    = células/53b (dados/48b +cabeçalho/5b) = tamanho fixo
    = conexão entre 'LANs' por 'WAN'
    = implementado em hardware. Aúdio e vídeo em tempo real
    = dados em ordem(o que não acontece em geral no TCP)
    = sem limite de velocidade, eficiência não afetada pela distância
    = gerência melhor que o Ethernet. Problema = custo
    = cabeçalho
      - VPI: caminhos virtuais
      - VCI: canais virtuais
      - PTI: tipo de células, congestionamento de nó e questão de segmentação do pacote
      - CLP: prioridade para o descarte de células
      - HEC: verificação de erros no header	
    = ATM cria canal virtual->negocia 'QoS' com canal->manda células->cada comutador olhar header para saber caminho
    
#ROTEAMENTO

-OSPF= usado para distribuir informações de roteamento IP ao longo de um único 'AS'(Autonomous System) em uma rede IP
     = Shortest Path First(menor caminho de Dijkstra)
     = criado para substituir o protocolo 'RIP'(limitações em redes de grande porte) que manda tabela de roteamento a cada 30 segundos
     = Cada área é uma divisão lógica do AS e funciona como uma entrada de roteamento único
     = é um robusto link-state 'IGP'= rede autônoma - empresa com vários núcleos
     = tabela de roteamento enviada aos roteadores próximos só quando há mudança
     = roteadores com tabela de topologia->Dijkstra->SPF Tree->	tabela de roteamento
     = cabeçalho
	- Version Number
	- Type: tipo de pacote.Hello packet, Description packet, Link-state request packet, Link-state update packet e LSA
	- Packet length
	- Router ID: identificador do roteador
	- Area ID: identificador da área
	- Checksum: tamanho do cabeçalho + dados sem autenticação
	- AuType
	- Authentication: para verificar integridade do pacote







