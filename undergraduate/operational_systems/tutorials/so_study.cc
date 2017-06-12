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
    • Segmentação: divide memória física e virtual em unidades de tamanho variável
    • Segmentação paginada
    
    slide 48 - paginação
  



