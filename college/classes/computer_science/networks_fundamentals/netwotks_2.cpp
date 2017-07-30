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