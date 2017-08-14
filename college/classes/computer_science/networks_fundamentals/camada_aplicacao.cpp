Existem diversos tipos de servidores:
- Servidor web: responsável pelo armazenamento de páginas de um determinado 'site', requisitados pelos clientes através de 'browsers'.
- Servidor de banco de dados: possui e manipula informações contidas em um banco de dados.
- Servidor DNS: responsáveis pela conversão de 'endereços de sites' em 'endereços IP' e vice-versa.
- Servidor proxy: atua como um 'cache', armazenando páginas da internet recém-visitadas, aumentando a velocidade de carregamento destas 
  páginas ao chamá-las novamente.
  
Clientes e servidores comunicam-se através de 'protocolos', assim como dois ou mais computadores de redes.

--SSL e HTTPS--
'https://www.youtube.com/watch?v=SJJmoDZ3il8'
'https://www.youtube.com/watch?v=JCvPnwpWVUQ'|v|

'SSL' - Secure Socket Layer (encripta informações confidenciais de clientes para que a informação não seja interceptada no caminho a um server)
      - Tanto o site quanto o interceptador podem ter a public key (codificadora), mas só o server tem a private key (decodificadora)
HTTPS - HTTP + SSL

Quando o usuário clica num link http ou escreve um endereço http e dá enter:
  - browser faz conexão TCP entre a porta http 443 e o server.
  - Se der certo, começa o ssl handshake. 
    - Browser manda o 'client hello' e 
    - server responde com o 'server hello', aqui são discutidos dados sobre versão e outras informações do ssl em uso. 
    - Server manda então seu 'certificado digital' para o browser, que contém a public key e endereço do server. 
    - Server manda o 'server hello done'. 
    - Browser manda o 'certificate verify'. 
    - Browser manda o 'change cipher spec'.
    - Browser manda a mensagem 'finished' até agora. 
    - Server responde com 'change cipher spec'. 
    - Server manda mensagem 'finished' até agora.
    - Server manda 'Symmetric Secret Key' daquela sessão ssl entre browser e server. 
    - Browser manda chave encriptada com a chava public. 
    - Server recebe chave.
    
-----------------------------------DNS-----------------------------------
'https://www.youtube.com/watch?v=2ZUxoi7YNgs'

-----------'http://computer.howstuffworks.com/dns.htm' |v|-----------
How Domain Name Servers Work

Tanto computadores quando servidores tem um ip.

Quando você insere um URL no seu navegador da Web, o servidor DNS usa seus recursos para resolver o nome para o endereço IP para o servidor 
Web apropriado.

DNS é um protocolo dentro do conjunto de padrões para como os computadores trocam dados na Internet e em muitas redes privadas , conhecidas 
como o conjunto de protocolos TCP / IP.

Sua função básica é a de transformar um nome de domínio fácil de usar como " howstuffworks.com " em um Protocolo de Internet (IP) como 
70.42.251.42 que os computadores usam para identificar uns aos outros na rede. 

Você apenas se conecta a um domain name server (DNS server ou name server), que manipula uma massiva base de dados que mapeia nomes de domínios 
a endereços IP, sendo o processo chamado DNS name resolution.

Você sempre pode pular o serviço DNS escrevendo o endereço IP do servidor diretamente no browser. Porém, vale lembrar que o endereço IP de um 
Web site pode mudar com o tempo, e alguns sites associam multiplos endereços de IP com um unico nome de domínio.

Como seu computador sabe qual servidor DNS usar? Quando você se conecta em uma rede doméstica, ISP ou rede wifi, o modem ou roteador que 
atribui endereços de rede do seu computador também envia algumas informações importantes sobre a configuração de rede para o seu computador
ou dispositivo móvel. Essa configuração inclui um ou mais servidores DNS que o dispositivo deve usar quando traduzir nomes DNS para endereços 
IP.

-> Servidores DNS processam bilhões de pedidos pela internet o tempo todo.
-> Milhões de pessoas adicionam e mudam nomes de domínios e endereços IP a cada dia.

O IP do seu computador vem servidor DHCP da sua rede. Ele faz com que seu PC tenha um endereço IP e outras configurações de rede quando você 
está online. Por ser Dynamic Host Configuration Protocol, seu IP muda constantemente. Servidores web e outros computadores que precisam 
de um ponto consistente de contato usam endereços IP estáticos. É o mesmo IP sempre que está online. Para ter esta certeza, o IP é associado com 
endereço MAC (Media Access Control) para aquela interface de rede. Toda interface de rede tem um único MAC associado.
É raro um usuário final usar IP estático.

A última palavra do nome de domínio (depois do último ponto) representa um 'top-level domain', que são controlados pela 'IANA' na chamada 
'Root Zone Database'. com - coomercial web sites, embora abertos para qualquer um.

O primeiro nome do domínio, como www ou mail, é o 'host name'. Ele especifica o nome de uma máquina específica (com endereço IP específico)
em um domínio, dedicada a um objetivo específico.

--------------------'https://howdns.works/ep1/' |v|--------------------
O que acontece quando vc poe um site no browser.

-> menino digita site 'dnsimple.com'.
-> browser procura nome do dominio na cache, não acha
-> browser pede pro SO procurar o nome do dominio na cache dele, não acha
-> SO então pede pro resolver server (servidor fora de casa - ele é o seu ISP), já que nem o browser nem o SO sabem o IP do nome do dominio
-> Resolver primeiro olha na cache dele, não acha
-> Resolver pede pro root server
-> root server não sabe localizar o dominio, mas sabe como localizar o TLD (Top-level domain)domain server .COM.
-> Então o resolver armazena esta informação.
'Este root server é apenas 1 dos 13 root name servers que existem hoje em dia. Eles ficam no topo da hierarquia DNS.'
'Estão espalhados na Terra e são operados por 12 organizações diferentes.'
'Eles são nomeados como [letra].root-servers.net, onde letra vai de A a M'
'Porém cada organização provê vários servidores físicos distribuídos pelo globo'
'A coordenação das TLDs é feita pela ICANN (Corporation for Assigned Names and Numbers)'
Outros tipos de TLD incluem:
1. TLDs de código de país. ISO com 2 letras = .jp,.fr
2. TLDs de código de país internacionalizadas, ou seja, escritas em linguas nativas
3. TLDs genéricas. ISO com 3 ou mais letras = .net, .org, .edu, ...
4. TLDs de infraestrutura, que levam de IP para nome do domínio = .arpa
5. Hoje em dia várias genéricas são criadas = .hot, .pizza, .app, ..
-> Resolver pede o ip pro TLD domain server .COM
-> TLD domain server .COM não sabe, mas sabe os authoritative name servers para o domínio dnsimple.com, armazenamos para ele pelo 
   Domain Registrar
'Estes servers são:'
'ns1.dnsimple.com ; ns2.dnsimple.com; .. ; ns4.dnsimple.com'
-> Resolver vai até o server ns1.dnsimple.com e pede o IP. Todos os 4 server anteriores sabem. Eles sabem como resolver qualquer 
domínio gerenciado por dnsimple.com, ou seja, estes servers respondem as perguntas de DNS.
-> Resolver conseguiu o IP de um dos quatro Authoritative name server do domínio dnsimple.com!
-> Resolver diz o IP pro SO, e este armazena armazena esta informação para buscas futuras.

Mas como foi acessado o subdomínio ns1.dnsimple.com sem passar pelo dominio dnsimple.com? Por causa dos Glue records, o resolver
recebeu também pelo menos 1 IP para cada authoritative name servers.

---'http://www.verisign.com/en_US/domain-names/online/how-dns-works/index.xhtml'---           
-> Tudo conectado na internet - laptops, tablets, telefones móveis, websites - tem um endereço IP feito por números.

1º server DNS = 'recursive resolver', que pode ser operado pelo seu ISP, operadora sem fio ou fornecedor terceirizado.
o 'resolver' sabe quais outros servidores DNS ele precisa perguntar para responder a pergunta original.
ele vai atrás de 1 dos root servers.

2º server DNS = 'root servers', sendo que cada um sabe todas as informações TLD.
existem 13 root servers em mais de 300 localidades pelo planeta.
O DNS te assegura que a pergunta vai ser mandada para um server próximo.
resolver vai atrás do TLD name server correspondente.

3º server DNS = 'TLD Name Servers', um para cada .??.
O TLD server dá o endereço IP do 'domains name server (ou authoritative name servers)'
resolver vai atrás de um dos domain name server.

4º server DNS = 'domain name servers', sabe o ip da pergunta original e dá ao resolver.

-----------------------------------------------------------------------------------                 
1.png (http://computer.howstuffworks.com/dns.htm)

    