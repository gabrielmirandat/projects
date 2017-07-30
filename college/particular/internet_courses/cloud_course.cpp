HADDOP(plataforma de software em Java de computação distribuída voltada para clusters e processamento de grandes massas de dados.), 
ELASTICSEARCH(search server based on Lucene), 
SDN(software defined networking)

Cloud Models
- 'IaaS (Infrastructure as a Service)'
- 'PaaS (Platform as a Service)'
- 'SaaS (Software as a Service)'
- 'VM (Virtual Machine)'
examples of the Google Cloud, Amazon Cloud, and the iCloud.

'Cloud Computing' enables us to easily use software as well as processing platforms and computing 
infrastructure (that are not equipped on our computers and smartphones) from any location through
Internet services. 

'Big Data' provides us with new intelligence from massive data sets, which can help in situation/condition/status 
analysis and decision making.

'CDN' is the best technology to provide information/contents to Internet users in the quickest 
and most efficient way. 'Content Delivery Network'. Sistema de computadores interligados em rede
através da Internet, que cooperam de modo transparente para fornecer conteúdo (particularmente 
grandes conteúdos de mídia) a usuários finais.

'cloud computing' (including SaaS, PaaS, IaaS).
'big data' (including Hadoop, MapReduce, HDFS).
'CDN' (including hierarchical content delivery models)

'Cloud Computing'
Tipo abrir um microsoft PowerPoint no celular só tento rede (sem o programa instalado e sem ser windows).

Public Cloud - permite acesso publico a sistemas e serviços.
Private Cloud - acesso a serviços dentro de uma organizaçao.
Community Cloud - acessada por uma comunidade de organizaçoes.
Hybrid Cloud - nuvem publica + nuvem particularl.
Em:
'SaaS' - software	(programas ao usuario - crm, email, jogos, desktop virtual)
'PaaS' - plataforma  (programas executaveis para aplicativos ao usuario - armazenamento, servidor web)
'IaaS' - infraestrutura. (computaçao e segurança - armazenamento reserva, poder de processamento e maquinas virtuais)
-> O modelo de serviço que esta abaixo comporta o gerenciamento, o poder de processamento e a segurança do modelo de cima.
-> Cliente: acessa atraves de navegador web, app movel ou outro. 
NaaS(network), DaaS(database), BaaS(business)
-> Alta eficiencia, confiabilidade e flexibilidade.
-> Nao precisa software, pois todos pertencem a nuvem.

-> Google App Engine = PaaS
-> Google Cloud Storage = SaaS
-> Google Big Query = big datas SQL
-> Google Compute Engine = IaaS
-> Google Cloud Endpoints = Android, iOS, JavaScript clients.
-> Google Cloud DNS = 
-> Google Cloud Datastore = NoSQL data storage.
-> Google Cloud SQL = fully managed by MySQL database.
-> Amazon S3 - Simple Storage Service
-> Amazon Public Web Services
-> Amazon Cloud Drive
-> Amazon Cloud Player
-> Apple iCloud

'Big Data'
Big Data examples:
- past event of the H1N1 flu virus spread prevention.
- smartphone marketing.
- industrial examples of Big Data in use by Wal-Mart, Amazon.com, and Citibank.
- Hadoop: reliable shared storage Big Data analysis system.
- MapReduce and HDFS (Hadoop Distributed FileSystem).

- Quando a Google previu a quantidade de infectados por virus filtrando as pesquisas de todo mundo sobre o virus.
- Walmart guarda todas as compras dos usuarios e sabe o que eles mais compram.
- Amazon interesse do usuario: como eles sabem o que nos pesquisamos e temos interesse?
- CitiBank para padroes de comercio e condiçoes economicas. Ajuda ZARA e H&M.
- Empresas de telefonia preverem para onde mandar mais celulares para serem comprados.

Os 4 desafios V's em Big Data:
- Volume	- tamanho dos dados
- Variedade	- formatos de dados
- Velocidade	- de streaming de dados
- Veraciade	- confiabilidade dos dados

'Hadoop' - maquina de analise big data.
Desafios:
- falha de hardware - armazenar grandes dados em hardware tem grandes chances de perda.
- custo - necessidade de computadores para backup.
- combinar dados analisados - bem dificil.

Haddop = sistema confiavel de analise e armazenamento compartilhados.
       = HDFS + MapReduce
'HDFS' = Sistema de arquivos distribuidos Haddop.
     = gerenciar armazenamento de rede de computadores.
     = otimizado para armazenar grandes arquivos com padroes de acesso aos dados streaming.
     = WORM = gravar uma vez, ler muitas vezes.
     = 2 tipos de nos: Namenode(no master), Datanode(no trabalhador).
'NameNode' = gerencia o namespace do sistema de arquivos.
	   = mantem arvores de diretorios e metadados dos arquivos.
	   = armazena em dois tipos de arquivos: Namespace Image e Edit Log.
'DataNodes' = armazenam e recuperam blocos quando solicitado pelo cliente ou namenode.
MapReduce = analise de dados. Funçoes mapear e reduzir.
	  = abstrai o problema de analise dos dados armazenados.
	  = usa chaves e valores.
	  = analise força bruta. = 'processo de consulta em lote'.
	  - Seek time = tempo para achar um arquivo.
	  - Transfer rate = velocidade para mover arquivo.
	  = MapReduce 2 usa YARN(Yet Another Resource Negotiator)
	  = HDFS
	  = 
'MapReduce vs rdbms(Relational database management system)'
RDBMS eh bom para atualizar uma pequena parte de um grande banco de dados.
	  = usa uma B-tree tradicional.
	  = bom para grande quantidade de pequenas atualizaçoes.
MapReduce eh bom para atualizar tudo.
	  = sort e merge.
	  = bom para WORM.
'Tipos de dados'
- Estruturados: estrutura formal = XML.
- Semi-estruturado: estrutura guia, que pode ser ignorada.
- Nao estruturados: como texto ou imagem.








