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
    
  



