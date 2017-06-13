Gerente de Memória
  - Determinar o esquema de gerência de memória que será utilizado pelo sistema operacional e implementá-lo eficientemente.
  - Controlar a alocação de pedaços da memória a processos
  - Liberar pedaços de memória que estavam alocados a processos e não são mais necessários.
  
  
• Monoprogramado: apenas um processo ativo por vez (pode-se reservar quase toda a memória RAM para ele)
  •  bare machine: sem esquema, usuario com controle absoluto
                   ruim: sem sistema operacional, usuário deve implementar baixo nível
  •  monitor residente: memória dividida em área de usuário e sistema operacional
                        hardware adicional: impedir que usuário acesse memória do SO
                        ruim: monousuário (CPU sub-aproveitada)
  
  
• Multiprogramação: mais de um processo ativo em memória RAM por vez (exige divisão da memória em partes)
  • Partições fixas (MFT-fixo): conjunto de partiçoes de tamanho fixo
                           processo roda na mesma partição até terminar
                           relocação: rearrumação de endereços dos processos para ocuparem buracos
                                      modificar instruções: no momento da carga de endereços relocáveis. Ruim
                                      registradores base e limite: adiciona base a cada endereço de acesso à memória e limite protege. Bom
                           swapping: coloca alguns processos ativos em disco (swap-in é do disco para a memória)
  • Partições variáveis (MVT-variável): divide memória RAM em partições de tamanho variável
                                        objetivo é satisfazer uma solicitação de tamanho n dada uma lista de buracos livres
                                        first fit: primeiro que cabe
                                        best fit: menor que cabe
                                        worst fit: maior que cabe
                                        fragmentação externa: existe espaço, mas não contínuo
                                        compactação de memória: mover processos na memória para unificar buracos
                                                                muito pesado, nesse tempo nenhum processo executa
                                        alocação de espaço: no caso de área de dados de processo crescer com o tempo
                                                            aloca-se um espaço maior para evitar relocações
                                        controle de alocação de memória
                                          mapa de bits: memória dividida em unidades de alocação de tamanho fixo (UAS)
                                                        cada unidade é um bit do mapa (0 - UA livre; 1 - UA alocada)
                                                        não muito usado, busca muito lenta se memória muito grande
                                          lista encadeada: segmentos livres e ocupados em listas (mais usado)
                                                           <buraco/processo><endereço inicio><ponteiro próximo>
                                                           lista duplamente encadeada: permite merge de buracos
                                                           duas listas separadas: uma para buracos e uma para processos
                                                                                  classifica por tamanho dos buracos
                                                                                  overhead por manter listar ordenada
  • Memória virtual: problema diferente, controlar alocação de memória para processos que não cabem em memória RAM
                     quebra processos em unidades menores (se feita pelo programador chama-se overlay)
                     a partir daqui: processo não referencias mais endereços físicos, mas endereços virtuais
                     máquinas com 32 bits podem endereçar 2^32-1 endereços virtuais
                     ao executar uma instrução, endereços virtuais devem ser traduzidos para endereços físicos
    • Paginação: divide memória física e virtual em unidades de tamanho fixo
                 |
                 CPU solicita endereço virtual virtual x
                 endereço convertido para físico através de tabela de páginas
                 contém mapeamento do endereço virtual para o endereço físico
                 endereço físico colocado no barramento de memória
                 |
                 impossível fazer com software, alto overhead por acesso
                 hardware adicional: MMU (mapeamento de endereços)
                 endereço virtual dividido em páginas (tamanho fixo)
                 |
                 memória RAM dividida em page frames, mesmo tamanho da página
                 As page frames são as casas das páginas enquanto estiverem na memória
                 |
                 A CPU envia endereço virtual à MMU
                 Na MMU, endereço dividido em (p,d), substitui p por f, põe no barramento (f,d)
                 |
                 A MMU detecta não mapeamento pelo bit de presença
                 MMU força um trap ao SO chamado page fault
                 SO escolhe uma página que deve desocupar a memória se cheia, e carrega no lugar
                 Tabela de páginas alterada
                 Instrução de page fault reexecutada
                 |
                 Uma tabela de páginas é uma estrutura de dados para cada processo
                 Além disso, devemos lembrar que a tabela de páginas (ou parte dela) deve residir na MMU.
                 |
                 Armazenar tabela de páginas totalmente na MMU
                    num conjunto de registradores especiais
                    cada registrador tem uma entrada na tabela
                    cada vez que há troca de contexto, a tabela do processo é carregada no conjunto de registradores
                 Armazenar parte da tabela de páginas na MMU e parte em memória
                    Tabela armazena na memória principal e registrador contem endereço de inicio da tabela
                    MMU tem uma TLB com algumas entradas
                 |
                 Foward-mapped: uma entrada para cada página e a frame é obtida através desta entrada
                 Invertida: entrada é frame, usa hash
                 |
                 Algoritmos para resolver page fault
                    Ótimo: retira pagina que será referenciada num futuro mais distante
                    NRU:  {R=1 sempre que pag acessada, M=1 sempre que pag escrita}
                          {zera R e M se contexto carregado, zera R periodicamente}
                          {classes| 0[R=0;M=0], 1[R=0;M=1], 2[R=1;M=0], 3[R=1;M=1]}
                          SO escolhe página de menor classe
                    FIFO: página carregada a mais tempo
                          se page fault atualiza tempo
                    Segunda: FIFO
                             {se R=0, substitui; se R=1, zera R e coloca página no fim da fila}
                             {continua até R=0}
                    Relógio: Segunda
                             Páginas em fila circular
                             Ponteiro que aponta para página mais antiga
                             {se R=0, substitui; se R=1, zera R e ponteiro aponta para a próxima página}
                             {continua até R=0}
                    LRU: substitui página referenciada no passado mais distante (de pilha, sem Belady)
                         lista encadeada organizada pelo tempo do último acesso
                         
                         NFU: simulação da LRU por software (menos caro)
                              contador para cada página
                              adiciona R a cada passada
                              página muito referenciada raramente escolhida (referencias não esquecidas)
                         NFU com Aging
                              A cada clock, shifta contador para a direita e insere R à esquerda
                 |
                 Lock de páginas: impede de ser escolhida para substituição
                 |
                 Tratando page fault
                    1. O hardware gera um trap para o kernel e salva o PC corrente na pilha.
                    2. O hardware gera um trap para o kernel e salva o PC corrente na pilha.
                    3. O SO recebe o trap e determina que ocorreu um page fault. O SO determina a 
                       página virtual necessária para resolver o page fault (geralmente o número 
                       da página virtual está em um registrador especial).
                    4. Tendo o endereço virtual em falta, o SO verifica se o endereço é válido e 
                       se houve violação de proteção
                    5. O SO determina uma page frame livre para a página em falta. Se não houver 
                       moldura livre executa o algoritmo de substituição.
                   
    • Segmentação: divide memória física e virtual em unidades de tamanho variável
    • Segmentação paginada: paginar os segmentos
                           Cada processo possui uma tabela de segmentos
                           Cada segmento tem uma entrada na tabela de segmentos
                           A tabela de segmentos aponta para a tabela de páginas do segmento em questão
    
Gerente de arquivos
  Para simplificar o tratamento dos vários dispositivos, o SO fornece uma visão lógica e uniforme 
    do sistema de armazenamento, o arquivo.
  Arquivo é uma entidade lógica mapeada em dispositivos físicos.
  Sistema de arquivos abstrai e gerencia arquivos
  
  Estruturação interna do arquivo
      Sequência de bytes: sem estrutura. SO sem noção dos campos.
                          acesso não otimizado, mas livre (MS/DOS e Unix)
      Sequência de registros: com registros de tamanho fixo
                              leitura e escrita retornam um registro
                              acesso otimizado por registros, perda de flexibilidade (CP/M)
      Árvore de registros: arquivo é árvore de registros de tamanho variável
                           árvore ordenada pelo campo chave do registro
                           acesso randômico otimizado, complexo,  sistema grande porte (MUMPS)
                             
  Tipos de arquivos suportados no UNIX e DOS
      Arquivos regulares: contém dados do usuário
      Arquivos diretório: utilizados na manutenção do sistema de arquivos
      Arquivos especiais: ligados a dispositivos de E/S
      
  Métodos de acesso ao arquivo: como os dados serão recuperados pelo usuário
      Acesso sequencial: fita magnética
      Acesso direto (aleatório): disco
      
  Atributos contidos na TABELA DE ARQUIVOS
      proteção: indica permissões de acesso ao arquivo
      password: para acessar o arquivo
      
  Tabela de arquivos
      Possui uma entrada para cada arquivo. Contem info referente ao arquivo
      
      CREATE: cria entrada para novo arquivo no diretório e na tabela de arquivos do diretorio em que se encontra.
              com nome do criador, data de criação e permissões de acesso.

      DELETE: libera espaço ocupado pelo arquivo, deleta entrada do diretório e deleta entrada na tabela de arquivos.

      OPEN: cria mapeamento entre entrada na tabela de arquivos para a tabela de processos do processo que executou o open.
            este passo é feito por meio da tabela de descritores de arquivos. Retorna um descritor de arquivo, que será 
            utilizado em todas as operações subsequentes sobre o arquivo.

      CLOSE: desfaz o mapeamento entre a entrada da tabela de arquivos referente ao arquivo da entrada da tabela de processos
             do processo.

      RENAME: simplesmente altera o nome do arquivo na tabela de arquivos.
    
  Arquivos mapeados em memória
      Colocar arquivo no espaço de endereçamento do processo
      MAP como OPEN - em vez de usar descritor de arquivos, retorna um ponteiro para o início do arquivo
      Leituras e escritas são feitas através de acessos à memória
      
  Organização dos arquivos
      Diretório único: -
      Árvore arbitrária de diretórios: -
      Um diretório por usuário: -
        
  Armazenamento de arquivos
      Alocação contígua: reserva espaço contíguo em disco
      Alocação com lista encadeada e índice
      i-Nodos: cada arquivo possui uma pequena tabela chamada i-nodos
                 a tabela i-nodos de cada arquivo possui atributos e 
                 endereços dos blocos físicos alocados ao arquivos
               Os primeiros endereços de disco são armazenados no próprio i-nodo, 
               que é transferido do disco para a memória no momento da abertura do arquivo.
      UNIX organiza diretórios em árvore por i-nodos
      
  Gerência de espaço em disco
      Lista encadeada: guarda somente blocos livres
      Mapa de bits
      
  Consistência do SA
      Lê-se todos os i-nodos. Cada vez que um número de bloco for lido, seu contador de utilização é incrementado.
      Lê-se a lista de blocos livres. Cada vez que um número de bloco for lido, seu contador de presença nos blocos lidos é incrementado.
        
      Inconstência 1 - Bloco perdido
      BL = 0; BU = 0
      Solução: Neste caso, o bloco é simplesmente adicionado à lista de blocos livres
      
      Inconsistência 2 - Duplicação do bloco livre
      BL = 2; BU = 0
      Solução: retira-se a duplicação da lista de blocos livres
      
      Inconstência 3 - Bloco duplicado
      BL = 0; BU = 2
      O sistema de arquivos fica consistente mas provavelmente houve corrupção da informação. O erro deve ser
      apresentado na console
      
      Inconstência 4 - Bloco usado e livre
      BL = 1; BU = 1
      Solução: remove-se o bloco da lista de blocos livres
      
  Desempenho do SA
      buffer cache: Área em memória que armazena temporariamente os blocos de disco mais utilizados
      A gerência precisa prever o que fazer quando a área reservada estiver cheia
      Da mesma forma que as páginas, devemos escolher um bloco para ser retirado da buffer cache
      
      Neste sistema:..
        Retorno de sucesso em escrita indica que dado foi escrito na buffer cache, e não no disco
        Blocos são divididos em blocos críticos e blocos de dados.
        Os críticos são sempre escritos na buffer cache e no disco
        Um daemon periodicamente escreve os dados da buffer cache em disco
        
        
Clocks
  Clocks so acessados por um driver de dispositivo
  data: DDMMYY = nro de insterrupcoes desde 1/1/70
        a cada nova interrupção este valor é incrementado
        O time-of-day é geralmente armazenado em um registrador especial alimentado por uma bateria.
    
  Funções do driver do clock
    •  Manter o tempo real
    •  Implementar o quantum do escalonador
    •  Contabilizar o uso do processador
    •  Gerenciar a chamada ALARM
    •  Fornecer watch-dogs
    •  Monitorar o sistema

  Quantum
  - A cada transição ready-running, o escalonador inicializa um contador com o valor do quantum.
      
  



