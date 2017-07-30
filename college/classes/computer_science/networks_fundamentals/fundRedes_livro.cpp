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

5 - 1.1.2