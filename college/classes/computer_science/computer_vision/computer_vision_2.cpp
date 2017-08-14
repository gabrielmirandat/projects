OpenCV
   C/C++,  Python,  Visual  Basic,  Ruby,  Matlab
   Linux  (POSIX,  ROS),  Windows,  Mac  OS  X
   Eficiência  Computacional
    Foco  em  tempo  real,  C  otimizado,  processadores  multi.

OpenCV  -­‐  Funcionalidades
   Manipulação  de  dados  de  imagens
   E/S  de  imagem  e  vídeo
   Manipulação  de  matrizes  e  vetores
   Rotinas  de  álgebra  linear
   Estruturas  de  dados  dinâmicas
   Processamento  de  imagem  básico
   Análise  estrutural
   Calibragem  de  câmera
   Análise  de  movimento  (tracking)
   Reconhecimento  de  objetos
   GUI  Básica
   Rotulagem  de  imagem

OpenCV  -­‐  Módulos
   cxcore
    -Estruturas  de  dados  e  álgebra  linear.
    -Transformadas  de  dados,  persistência  de  objetos,  gerenciamento  de memória,  manipulação  de  erros,  carregamento  dinâmico  de
      código.
    -Desenho,  texto,  matemática  básica
   cv
    -Processamento  de  imagem,  análise  de  estrutura,  movimento  e  tracking, reconhecimento  de  padrões,  calibragem  de  câmera  (em C)
   cvcam
    -Interface  de  câmera
   cvaux
    -Eigen  objects  (técnica  de  reconhecimento),  gestures,  contorno  de  regiões, matching  de  formas,  descritores  de  texturas,
      tracking  de  olhos  e  bocas, descoberta  de  esqueletos,  segmentação  de  background-­‐foreground, calibragem  de  câmera  (em  C++)
    -Alguns  migrarão  para  cv,  outros, não.
   HighGUI
    -Interface  de  usuário
    -Armazenamento  e  chamada  de  imagem/vídeo
   ml
    -Aprendizagem  de  máquina
    -Clustering,  classificação  e  análise  de  dados
    -Suficientemente  genérica

OpenCV -- Usos
  Câmeras  de  vigilância,  imagens  e  vídeo  na  web,
interfaces  de  jogos,  imagens  aéreas,    monitoramento
de  segurança,  veículos  não-­‐tripulados,  análises
biomédicas,  inspeção  automática  de  produção,
robótica .

  "Câmera"
  "Profundidade "caixa" é o comprimento focal efetivo"
  Abertura menor = menos luz, difração

  Um sensor de imagem digital, agindo como a retina dos olhos, capta a luminosidade das imagens que são projetadas sobre ele continuamente e
dá início ao processo de captura de uma instância ou de uma sequência de instâncias da imagem consecutivamente.
  Os sensores de imagem CCD (dispositivo de carga acoplada) e CMOS (semicondutor de óxido metálico complementar) partem do mesmo ponto: precisam
converter luz em elétrons. Se você leu o artigo Como funcionam as células solares, compreende a tecnologia usada para realizar esta conversão.
Uma maneira simplificada de pensar sobre o sensor usado em uma câmera digital (ou filmadora) é considerá-lo como tendo uma matriz 2D de
milhares ou milhões de pequenas células solares, cada uma das quais transforma a luz de uma pequena parte da imagem em elétrons. Tanto os
dispositivos CCD como CMOS realizam esta tarefa usando diversas tecnologias.

  -Abertura do pinhole conhecida como obturador.
  - Ponto chamado de Centro de Projeção (ponto focal ou centro ótico).
  - Imagem é formada no Plano de Imagem.

  "Projeção" (3D - 2D)
  - Muito pontos no mesmo raio = 1 ponto.
  - De pontos-a-pontos : projeção indefinida.
  - De retas a retas (Colinearidade preservada) : projeta um ponto.
  - De planos a planos : projeta uma reta.

  "Problema da perspectiva"
  - Retas convergem.

  "Projeção ortográfica"
  - Caso especial de projeção perspectiva
  - Distância do centro de projeção ao plano da imagem é infinita (câmera de fundo infinito)
  - "As linhas ficam paralelas!!"

  "Lentes (Solução)"
  - Adição de lentes.
  - Concentra todos os raios do mesmo ponto do objeto no mesmo ponto do filme.
  - Todos os raios paralelos, após passarem pela lente, se encontram no ponto da distância focal.
  - Há uma distância específica onde o objeto estará “em foco”.
  - Mudar o tamanho da abertura afeta a profundidade.
  - Campo de visão depende do comprimento focal.
  - "perspectiva fraca = linhas paralelas" = aumentar comprimento focal e aumentar distância da câmera.

  Uma câmera digital troca o filme por uma matriz de sensores−
    Cada célula na matriz é um diodo sensível a luz que converte fótons em elétrons−
      Dois tipos comuns
	 Charge Coupled Device (CCD)
	 Complementary metal oxide semiconductor (CMOS)

  "Luz" - o que determina o brilho de um pixel?
  "Radiometria" Em óptica, radiometria é um conjunto de técnicas de medição de radiação eletromagnética, incluindo luz visível. Técnicas
  radiométricas caracterizam a distribuição da potência da radiação no espaço, ao contrário das técnicas fotométricas, que caracterizam a
  interação da luz com o olho humano. A radiometria é distinta das técnicas de óptica quântica tais como contagem de fótons.

  propriedades_fonte_de_luz->formato_superfície->propriedades_reflectância_superfície->ótica->exposição->características_sensor

  "Radiância (L)"
  -Energia do raio de luz.

  "Irradiância (E)"
  -energia que chega à superfície do objeto.
  -dependente da inclinação do ângulo.

  "Ângulo sólido (dW)"
  -área projetada em esfera unitária.

  Podemos considerar o uso de lentes no cálculo da relação entre radiância e irradiância.
  -A irradiância da imagem é linearmente dependente da radiância da cena.
  -Irradiância diminui em função do ângulo de incidência.

  "Câmera digital"
  -O trabalho da ADC, que é um chip dentro da sua câmera digital, é classificar as tensões dos pixels em níveis de brilho e de atribuir a cada
   nível para um número binário, composto de zeros e uns. A maioria dos consumidores câmaras digitais utilizam, pelo menos, um ADC de 8 bits,
   que permite até 256 valores para o brilho de cada pixel.

  radiância_cena(L)->lentes->sensor_irradiância(E)->obturador(passagem_luz)->exposição_sensor(X)->CCD->voltagens_analógicas->ADC->
			     valores_digitais->remapeamento->valores_digitais_finais(Z), sendo 'Z = função de mapeamento da câmera'

  -Precisamos estimar a curva f, seja com objetos de conhecida irradiância(calibração), ou por exposições fixas de abertura.

  "Raio de luz atingindo um ponto do objeto"
  -Absorção, refração, reflexão, fluorescência.

  Reflexão difusa, especular

  "Estéreo fotométrico"
  -Na computação gráfica e, mais especificamente, as aplicações de visão computacional, fotométrica estéreo é o processo de criação de um modelo
  tridimensional (3D) ou a representação de uma imagem bidimensional (2D) com base na forma como os objetos na imagem refletir ou refratar luz.
  Quando um algoritmo estéreo fotométrico é aplicada a um objecto, deve haver mais do que uma imagem de fonte disponível para a análise. Para
  cada uma das imagens de origem a ser utilizado, o objecto geral deve aparecer numa posição estática, enquanto a fonte de luz é movido para
  revelar diferentes aspectos da superfície do objecto.
  -Técnica de mínimos-quadrados (3D a partir de várias imagens 2D).
  -Limitações:	-projeçao ortográfica
		-reflectância e luz simples
		-sem sombras, sem inter-reflexões
		-erros numéricos

  "Cor"
  -Interação luz física-sistema visual.
  -'Espectro de reflectância de superfícies'
  -Cor observada é o resultado da interação do spectro da fonte de luz com a reflectância da superfície.
  - 3 tipos de cones (10:5:1 de red, green, blue).
  -Cones e bastonetes são como filtros : perda de informação.
  -O sistema visual adapta­se a luz do ambiente, não da cena.

  "Reflectância"
  -Reflectância é a proporção entre o fluxo de radiação eletromagnética incidente numa superfície e o fluxo que é refletido. Frequentemente a
  reflectância é apresentada sob a forma de percentagem. (fluxo_radiação_eletromagnética_refletido/fluxo_radiação_eletromagnética_incidente).

  "Espaços de Cor"
  -RGB
  -CIE XYZ
  -HSV

  "Percepção de Cor"
  -Constância e luminosidade (ajuste do sistema visual)
  -efeitos instantâneos (fundo)
  -efeitos graduais (adaptações)
  -efeitos semânticos (experiência)

  "Calibração de Câmera"

  'K = param. intrínsecos'
  'R,t = param. extrínsecos' -->graus de liberdade da câmera(6 graus, incluindo rotação e translação).
  'Xi = ponto 3D'
  'xi = imagem'
  'P = matriz de transformação entre x e X. Usada para estimar K,R e t'
  'H = matriz de rotação/translação usada na homografia'

  objetivo: Dado um conjunto de imagens:	-estimar parâmetros internos(intrínsecos) da câmera ':matriz K'
						-estimar parâmtros externos(extrínsecos) da câmera ':matriz R,t'
  motivo:
    -projeções 3D-2D e 2D-3D são necessárias para resolver problemas de visão.
    -para extrair informação 3D é necessário mais de um ponto de vista.

  -Dado x e X, podemos estimar K,R e t primeiro calculando P.
      Em geral calibração consiste em estimar P, dado somente x.
      'x=PX'
      -Calculamos 'P=K[R|t]' dado que 'xi=PXi', através de 2 passos:
	1)Calcula-se P.
	2)Decompor P em K,R,t pela decomposição QR.
	-->(i)Concatenamos as equações de (n>=6) correspondências para gerar 2n equações simnultâneas, que podem ser escritas:
	      Ap = 0, onde A é uma matriz 2n X 12.
			  'caso n=1' /X Y Z 1 0 0 0 0 -xX -xY -xZ -x\.p = 0
				     \0 0 0 0 X Y Z 1 -yX -yY -yZ -y/
	   (ii)Em geral, isso não terá uma solução exata, mas uma solução linear que minimiza |Ap|, sujeita que |p| = 1 é obtido
	       do autovetor com menor autovalor de AtA.Ou equivalentemente do vetor correspondente ao menor valor singular do SVD de A.

	   (iii)Esta solução linear é então usada como o ponto de começo para uma minimização não-linear  da diferença entre os pontos
		medidos e projetados.
	--> A primeira submatriz 3x3, M de P, é o produto (M = KR) de uma matriz triangular superior e matriz de rotaçao.
	   (i) Fator M em KR usando matriz de decomposição QR. Isto determina K e R.
	   (ii)Acha matriz K trangular.

    'Calibração com OpenCV'
      ● Preparar um tabuleiro com medidas conhecidas.
      ● Colocar câmera em posicão e orientacão fixas.
      ● Tirar várias fotos do tabuleiro em orientacões diferentes.
      ● Tendo como dados as fotos tiradas usar as funcões do OpenCV para calcular os parâmetros intrínsecos e extrínsecos da câmera.

      -Com isto, podemos:	-inserir distorção radial
				-corrigir distorção

  "Homografia" - Transformações Planares Projetivas

  'H = matriz de mudança da homografia (rotação, translação da imagem) '
  'x = pontos da imagem de input'
  'x'' = pontos da imagem de saída (outro plano)'
  ''
    -Duas imagens da mesma superf[icie planar estão relacionadas por uma homografia H
    -'x'' = Hx'
    -Para retificar uma imagem com homografia:
      1) Escolher no mínimo 4 pontos do mesmo plano da imagem_entrada.
      2) Determinar os 4 pontos correspondentes em um plano que você escolher.
      3) Calcular H dado que x'' = Hx
      4) Realocar cada pixel da imagem_entrada usando H.

      --> H a partir x e x''
	1) Como h é apenas definido até dimensionar, resolva para o vetor unitário ĥ.
	2) Minimize ||Aĥ||²
	3) Solução: ĥ = autovalor de AtA com o menor autovalor.

	'H pelo OpenCV'
	    cvFindHomography(src,dest,H);

    'Correspondência de Imagens/Alinhamento'
    -Dobrar/Moldar (“Warping”)
      ● Dada uma imagem e uma Transformacão T, como seria a imagem resultante?
    -Alinhamento
      ● Dadas duas imagens com pontos correspondentes, como computar a Transformacão T?

    -Tipicas projeções/transformações globais:
      'translation'
      'rotation'
      'aspect' (envolve relação altura/largura)
      'affine'
      'perspective'

      "Afim"
      Transformações afins são combinações de:
	-Transformações lineares, e
	-Translações.
      Linhas paralelas continuam paralelas.

      "Projetiva"
      Transformações projetivas são combinações de:
	-Transformações afins, e
	-warps(dobrar/moldar) projetivas.
      Linhas paralelas não precisam continuar paralelas.

      "Panorama"
      Com o mesmo centro de projeção podemos gerar qualquer outra visada sintética.
      Mosaico é uma vista sintética reprojetada em um plano.

      Extensão: ao mudar o centro da câmera a imagem final é que será o centro final das projecões.
		  'ver placa do carro de frente'

  "Panoramas (Mosaicos)"
  -Calculando possíveis correspondências
  ● Método RANSAC (RANdom SAmple Consensus)
  -Objetivos do alinhamento:
    -Panoramas.
    -Reconhecimento de objetos.
-Tipos de alinhamento:
    ● Direto (com correspondências de pixels conhecidas). Busca/Pesquisa com ajuste de pixels.
    ● Baseado em Atributos (sem correspondências conhecidas). Busca/Pesquisa onde atributos estão correlacionados.
-Como ajuste de modelos:
    -Encontrar M que minimiza pontos fora do intervalo da reta.
    -Achar transformação T que minimiza.

    ● Primeiro passo: Extrair Atributos.
    ● Segundo passo: Calcular supostas correspondências.
    ● Terceiro passo: Laco {Supor Transformação T com um pequeno grupo de correspondências}
    ● Quarto passo: Laco {Verificar Transformação T  buscando consistência com outras correspondências}
    ● Moldar Imagem Final para Mosaico.

    Tipos de Transformacão 2D:
        ● Similaridade (escala, translação, rotação).
        ● Afim
        ● Projetiva(Homografia)

    Ajustando uma Transformacão Afim conhecendo as correspondências
        ● Sistema linear com 6 incógnitas (minimizar ajuste com SVD).
    Não conhecendo as correspondências?
        ● Descritores dos atributos na vizinhanca de pontos  de interesse precisam ser calculados e comparados.

    Descritores dos Atributos:
        -Tipos comuns de descritores:
        ● Vetor de intensidades (– Diferencas quadráticas).
                                (– Correlac ão normalizada).
        -Desvantagens de descritores de intensidade comuns:
        ● Pequenas translações podem alterar significativamente a correspondência.

        -Possível solucão: Uso de histogramas.

        "SIFT (Scale Invariant Feature Transform)"
            ● Dividir superfície em 4x4
            ● Calcular histograma de orientações do gradiente (8 direções) em cada sub­espaco.
            ● Descritor resultante 4x4x8 = 128 dimensões.

        -Ajuste de Alinhamento usando Atributos:
            ● Gerar pequeno grupo de supostas correspondências entre atributos.
            ● Encontrar as correspondências  é um problema típico de busca/pesquisa de dados:
            – Busca Exaustiva (para cada atributo em uma imagem encontrar as distâncias de todos os atributos na segunda imagem e decidir pelas
              correspondências mais próximas).
            – Vizinhanca mais próxima (otimização local: mét.guloso)
                ● Árvores de busca
                ● Hashing

            -Rejeição de elementos fora da busca (outliers).
            Estratégias para lidar com “outliers” entre os candidatos a correspondências:
                ● RANSAC
                ● Alinhamento incremental
                ● Transformada de Hough
                ● Hashing (espalhamento)

                RANdom SAmple Consensus (RANSAC)
                    ● Laco:
                    – Randomicamente selecione um grupo “semente” de supostas correspondências
                    – Computar a Transformação T para o grupo
                    – Encontrar os mais consistentes (inliers) com a Transformação T
                    – Se o número de consistentes for suficientemente grande, recomputar usando mínimos quadrados para este grupo
                    ● Manter a Transformação R com o maior número de consistentes.

                Alinhamento incremental
                    ● Escolher somente supostas correspondências na vizinhanca, usando restrições locais e aumentar o número a partir dessas.

                Usando Transformada de Hough
                Usando dispersão/hashing.
                Usando Homografias (i.e. além de transformacões afins)
                    ● Transformação entre duas vistas de uma superfície plana.
                    ● Transformação entre imagens de duas câmeras que compartilham o mesmo centro.


            Questões importantes em aplicacões de alinhamento
            ● Escolha do modelo de alinhamento geométrico (robustez x corretude)
            ● Escolha do descritor (e.g. SIFT, descritores invariantes)
            ● Estratégia de busca para supostas correspondências (e.g. exaustiva, Incremental,Hough, Hashing)
            ● Estratégia de Teste e Verificação de Hipóteses

  "Detectores de Bordas"
  Estudos indicam que bordas são relevantes características detectadas pelo sistema visual de mamíferos.
            Detecção de Bordas
            ● META:
            – Identificar mudanças abruptas em uma imagem (descontinuidades)
            – Pode conter mais informação semântica
            – Mais compacta que pixels
            ● Do ponto de vista artístico:
            – Não há uma única representação;
            – Há uso de conhecimento do artista de elementos intrínsecos dos objetos.

            Por que bordas?
            ● Extrair informação, reconhecer objetos
            ● Recuperar geometria e ponto de visada

            Origem das bordas:
            ● Descontinuidade da normal da superfície
            ● Descontinuidade de profundidade
            ● Descontinuidade de cor na superfície
            ● Descontinuidade de iluminação

            Descritores de Bordas
            ● Direção: perpendicular à direção de máxima mudança de intensidade (i.e., normal à borda)
            ● Módulo/valor: relacionado ao contraste local da imagem naquela normal.
            ● Posição: Localização em (x,y) da borda.

            Passos Importantes em Detectar Bordas
            (1) Suavização: suprimir o máximo de ruído possível, sem destruir bordas verdadeiras.
            (2) Realce: aplicar diferenciação/derivação para realçar a qualidade de bordas (i.e., agudização).
            (3) Corte por limiar: determinar quais pixels de borda devem ser descartados como ruído e quais devem ser retidos (i.e., limiar na magnitude
                da borda).
            (4) Localização: determinar a localização exata da borda. Resolução sub-pixel pode ser necessária para algumas aplicações para estimar a
                localização de forma mais precisa que espaçamento entre pixels.

            Bordas usando derivadas (O gradiente aponta na direção de maior crescimento de intensidade dos pixels)
            ● Frequentemente, pontos de borda são detectados por:
            (1) Detectando os máximos ou mínimos da primeira derivada.
            (2) Detectando os cruzamentos-de-zero da segunda derivada.

            Representação do Gradiente
            ● O gradiente é um vetor que tem magnitude e direção:

            Propriedade Isotrópica da magnitude do gradiente
            • A magnitude do gradiente detecta bordas em todas as direções.

  "Detector de bordas Canny e ajuste de retas por RANSAC"
  Detector de Canny
    ● Talvez detector de bordas mais utilizado
    ● Utiliza a ideia de que a derivada da Gaussiana aproxima a melhor localização e relação sinal-ruído.

    Ajuste de Parâmetros como Busca
    ● Escolher um modelo paramétrico para representar características (e.g. reta, circunferência, elipse)
    ● Que modelo melhor representa os pontos?
    ● Como selecionar os pontos aceitáveis e rejeitar os outros?
    ● Não é viável testar todas as possibilidades (Complexidade computacional)

    Abordagem por Votação
    ● Subconjuntos consistentes entre si são contados positivamente (votos)
    ● Outros são descartados

    "Pontos de interesse e extracao em imagens"

    Atributos locais tendem a ser mais robustos a:
    -Oclusões.
    -Articulações.
    -Variações intra-categorias.

    Solução geral
    -Encontrar conjunto de key-points distintivos.
    -Definir região em volta de cada keypoint.
    -Extrair e normalizar o conteúdo da região.
    -Computar descritor local da região normalizada.
    -casar descritores locais.

    Invariância a transformações geométricas(translação, rotação e escala).
    Invariancia a transformacoes fotometricas(variações de luz, ruído, borramento e quantização).
    Oclusão e corte.

        'Harris'
        Invariante a translação, rotação.
        Não invariante à escala.
            -Considerar círculos de vários tamanhos em volta do ponto.
            -Regiões de tamanhos correspondentes vão parecerem o mesmo em ambas as imagens.

            ●Harris-Laplacian
            -Achar máximo local de:
                -detector de cantos (coord. da imagem).
                -Laplaciano usado para escala.

            ●SIFT(Loew)
            -Achar máximo local de:
                -Diferenças de gaussianas no espaço e escala.

"Geometria Multi­vista"
● Objetivo  é recuperar estrutura 3D
● Quais elementos podem ser usados para inferir 3D?
    -Shading (sombreamento).
    -Textura.
    -Foco.
    -Perspectiva.
    -Movimento.

    Iremos explorar perspectiva e movimento.

    ● Geometria multi­vista é importante porque a recuperação a partir de uma imagem somente é ambígua.
        -Eixo z é uma reta.

    Com duas vistas
    ● Estrutura (Geometria da cena): Dados pontos correspondentes em 2, ou mais, imagens, onde  é a pré­imagem desses pontos em
     3D?
    ● Correspondência (Casamento Estéreo): Dado um ponto em apenas uma imagem, como ele restringe a posição no ponto
     correspondente x' em outra imagem?.
    ● Geometria de Câmeras (Movimento): Dado um conjunto de pontos correspondentes em duas imagens, quais são as câmeras para
     as duas vistas?

    Triangulação
    ● Dadas projeções de um ponto 3D em duas, ou mais imagens (com matrizes de calibração conhecidas), encontrar as coordenadas
     do ponto?
    ● Ruído e erros numéricos dificultam encontrar a exata interseção dos raios R1 e R2.
    ● Encontrar menor segmento que conecta os dois raios e fazer X ser o ponto central.

    Triangulação: Abordagem Linear
    -Produto vetorial como multiplicação de matrizes.

    Triangulação: Abordagem não-Linear
    -Encontrar X que minimiza.

    Geometria Epipolar
    ● Linha Base: reta conectando os centros das câmeras
    ● Plano Epipolar: plano contendo a linha base
    ● Retas Epipolares: interseções do plano epipolar com os planos das imagens (sempre em pares correspondentes).

    Modos:
    -Câmera convergentes. 'o usado'
    -Movimento paralelo ao plano da imagem.

    Restrição Epipolar
    ● Ao observar um ponto x em uma imagem, onde estará o ponto correspondente x' na outra imagem?
    ● Casamentos potenciais para x estarão na reta epipolar l'
    ● Casamentos potenciais para x' estarão na reta epipolar l

    Restrição Epipolar: Caso calibrado
    ● Parâmetros intrínsecos e extrínsecos são conhecidos
    ● Pode­se multiplicar a matriz de projeção de cada câmera pelo inverso da matriz de calibração e obter coordenadas
      normalizadas
    ● Ajustar o sistema de coordenadas globais para o sistema da primeira câmera.
    ● Matriz Essencial.
    ● E é rank 2 e tem 5 graus de liberdade (em escala).

    Restrição Epipolar: Caso Não calibrado
    ● As matrizes de calibração K e K' das duas câmeras é desconhecido.
    ● Podemos escrever a restrição epipolar em termos de coordenadas normalizadas desconhecidas.
    ● Matriz Fundamental.
        -Solução:
        Algoritmo dos oito-pontos e normalização.
        É um algoritmo utilizado na visão computacional para estimar a matriz essencial ou da matriz fundamental relacionado com
        um par estéreo de câmara de um conjunto de pontos de imagem correspondente.

"Multi-vistas e Estéreo"
● Dadas várias imagens de um mesmo objeto ou  cena, como calcular sua forma 3D?

Situacões possíveis
● Número arbitrário de imagens
● Posições arbitrárias de câmeras
● Câmeras calibradas, ou não calibradas
● Representação 3D:
    – Mapas de profundidade
    – Nuvens de pontos
    – Superfícies
    – Modelos volumétricos
    – Malhas, triangulação

    Formulacões típicas
    ● Fusão de pares de imagens em mapa de profundidade.
    ● Estéreogramas - perceber imagens fundidas dando uma experiência 3D.
    ● Autoestéreogramas.
    ● Interpolação de vistas = disparidade.

    -Algoritmo básico: Calcular correspondência estéreo.
    ● Para cada pixel na primeira imagem
    – Encontrar reta epipolar correspondente na 2a. imagem
    – Examinar os pixels e selecionar o melhor candidato
    – Fazer triangulação das correspondências para obter informação de profundidade.

    Cálculo da profundidade, a partir da disparidade.


    -Reprojete os planos das imagens em um plano comum à linha entre os centros óticos.
    -A movimentação do pixel é horizontal após esta transformação.
    -2 homografias (transformação 3x3), uma para cada reprojeção da imagem de entrada.
    Problema da correspondência:  qual hipótese  é correta?

    Restricões possíveis para o cálculo
    -Slide uma janela pelo scan da direita e compare o conteúdo daquela janela com a janela de referência na imagem esquerda.
    -Custo de matching: SSD ou correlação normalizada.

    Tamanho da janela?
    Pequena? Mais detalhes, menos ruídos.
    Grande? Maps de suavização com disparidades, menos detalhes.

    Quando a restrição da similaridade pode falhar?
    -Superfícies com textura, oclusões, repetições, superfícies não-lambertianas, especularidades.

    Extensões dos métodos:
    Graph cuts, Ground truth.

    Usando luz estruturada : estéreo ativo
    ● Projete padrões de luzes "estruturadas" no objeto.
        -Simplifica o problema de correspondência
        -Permite usar só uma câmera

    Usando laser
    ● Triangulação ótica
        -Projete um simples feixe de luz.
        -Escaneie pela superfície do objeto.
        -Isto é uma versão bem precisa do scan com luz estruturada.

    Estéreo com múltiplas vistas.

    Exemplos: estéreo volumétrico
        -Imagens de entrada(Calibradas).
        -Objetivo, determinar ocupância, "cor" dos pontos no volume da cena.
        -Algoritmo Space Carving
            ● Inicia para um volume V contendo a cena verdadeira.
            ● Escolhe um voxel (pixel 3D) na superfície atual.
            ● Projeta para imagens de entradas visíveis.
            ● Esculpir se não for foto-consistente.
            ● Repita até que convirja.

        Pegue um pixel na visada virtual
        Projete o raio visual correspondente em cada outra vista para obter um set de linhas epipolares.
        Encontre intervalos onde linhas epipolares se sobrepõem com silhuetas.
        Eleve intervalos de volta no raio 3D e encontre a interseção dele.

        Exemplo: possível obter precisão?
            ● Extrair features
            ● Obter pequeno set de matches iniciais
            ● Iterativamente expandir matches para locais próximos
            ● Use restrições visuais para filtrar os falsos matches
            ● Formar a reconstrução da superfície.

"Estrutura a partir de movimento"
        Estrutura a partir de movimento.
            ● Dadas m imagens de n pontos 3D fixos
            Problema: Estimar m matrizes de projeções Pi e n pontos 3D Xj das mn correspondências xij.

        Hierarquia das transformações 3D.
            ● Projetiva (15 graus de liberdade): Preserva intersecção e tangencia.
            ● Afim(12 graus de liberdade): Preserva paralelismo e razões de volume.
            ● Similaridade(7 graus de liberdade): Preserva paralelismo, razões de volumes.
            ● Euclidiana (6 graus de liberdade): Preserva ângulos, tamanhos.

            ● Sem restrições na matriz de calibração da câmera ou na cena, obtemos uma reconstrução projetiva.
            ● Precisamos de informação adicional para evoluir a reconstrução para afim, similar ou euclidiana.

            Afim
            -centro no infinito.

            Projeção ortográfica
            -distância do centro de projeção para o plano da imagem é infinito.

            Auto-Calibração
            ● Auto-calibração é o processo de determinar os parâmtros intrínsecos da câmera diretamente de imagens não calibradas.
            ● Por exemplo, quando as imagens são obtidas por uma única câmera se movendo, podemos usar a restrição de que os parâmetros intrínsecos da
             matriz devem ser fixos para todas as imagens.
                -Computar reconstrução projetiva inicial e encontrar matriz de transformação projetiva 3D Q pela qual todas as matrizes são da forma
                 Pi = K[Ri|ti].
            ● Pode usar a restrições na forma da matriz de calibração: zero oblíquo.

"Visão e movimento"
    Aplicacões de segmentacão em vídeo
    Subtração de Fundo
        ● Forme uma estimação inicial do fundo.
        ● Para cada frame:
            -Atualize a estimativa usando um movimento médio.
            -Subtraia a estimativa do fundo do fundo.
            -Etiquete como front cada pixel onde a magnitude da diferença é maior do que algum limiar.
            -Use filtro de média para limpar os resultados.

    Aplicações
    Segmetação de movimento
        ● Segmente o vídeo em múltiplos objetos de movimento coerentes.
    As vezes, movimento é a única pista.
        - Não agrupado, proximidade, similaridade, destino comum, região comum.

    Usos de Movimento
        ● Estimar estrutura 3D
        ● Segmentação de objetos baseada em movimento
        ● Aprendizado de modelos dinâmicos
        ● Reconhecimento de eventos e atividades
        ● Melhoria de qualidade em vídeo (estabilização)

    Técnicas de estimativa de movimento
        ● Métodos diretos
        – Recupera movimento a cada pixel a partir de variações de luminosidade
        – Uso com menor movimento
        ● Métodos baseados em atributos
        – Extrai atributos (e.g. cantos, textura) e os acompanha
        – Uso com maior movimento

    Campo de Movimento
        ● O campo de movimento é a projeção da movimentação da cena 3D na imagem.

    Campo de Movimento e parallax
        ● P(t) é um ponto 3D se movendo.
        ● Velocidade do ponto na cena: V = dP/dt.
        ● p(t) = (x(t),y(t)) é a projeção de P na imagem.
        ● Aparente velocidade V na imagem: dados pelas componentes vx = dx/dt e vy = dy/dt.
        ● Estas componentes são conhecidas como campos de movimento da imagem.

    Fluxo  Óptico
        ● Movimento aparente de padrões de brilho na imagem
        ● Idealmente, fluxo  óptico seria igual ao campo de movimento
        ● Pode ser causado por mudancas de luz, não movimento.

        ● Dados dois frames subsequentes, estime o aparente campo de movimento u(x,y) e v(x,y) entre eles.
            -Constancia do brilho: projeção do mesmo ponto parece o mesmo em cada frame.
            -Movimentação pequena: pontos não se movem para longe.
            -Coerência espacial: pontos se mexem como seus vizinhos.

        Resolvendo o problema do obturador:
            -Problema de mínimos quadrados.

        Interpretando os autovalores
        Classificação dos pontos da imagem usando autovalores no segundo momento da imagem.
            -Canto, região de pouca textura, região de muita textura.

        Estimativa de fluxo óptico
            - Começar com baixa resolução e ir aumetando.

"Rastremanto"

    'Rastreamento por atributos'
    ● Considerando fluxo óptico, seria possível calculá-lo par a par de imagens em uma sequência de vídeo
    ● Dado um ponto em uma imagem, em princípio seria possível reconstruí­lo (i.e. achar estrutura 3D) seguindo o caminho do fluxo óptico.
    
    'Desafios em Rastreamento'
    ● Ambiguidade do Fluxo Óptico (quais atributos seriam os melhores?).
    ● Movimentos expressivos (usar busca discreta ao invés do algoritmo Lucas­Kanade).
    ● Mudancas na forma, cor e orientacão (permitir flexibilidade no casamento de atributos).
    ● Oclusões (mecanismo de adicão e retirada de atributos).
    ● Deriva (“drift”, erros acumulam ao longo do tempo. Necessário saber quando terminar o rastreamento).
    
    'Como lidar com grandes variacões de movimento'
    ● Definir uma pequena área em volta do pixel como máscara.
    ● Tentar correspondência dentro da área de busca (como em estéreo).
    ● Usar métrica como SSD ou correlacão. (Soma das distâncias Quadradas).
    ● Após encontrar a melhor correspondência usar Lucas-­Kanade para refinar.
    
    'Rastreamento em muitos quadros'
    ● Selecionar atributos no 1o. Quadro:
      –Para cada quadro:
      –Calcular posicões dos atributos.
      –Busca discreta ou Lucas­Kanade.
      –Terminar rastreamentos inconsistentes.
      –Calcular semelhanca entre atributos.
      –Iniciar novos rastreamentos se necessário.
      
      'Melhores atributos para rastrear'
      * Encontrar boas características usando auto-valores da matriz de segundo-momento.
	(boas características para track são características que dão segurança ao track).
      * De frame a frame, faça o track com Lucas-Kanade e um modelo de translação pura.
	(mais robusto para pequenos deslocamentos, pode ser estimado de vizinhanças pequenas).
      * Checar consistência dos tracks por registro afim com a primeira instância observada de característica.
	(modelo afim é mais acurado para grandes deslocamentos).
	(comparando com o primeiro frame ajuda a minimizar o drift).
	
      'Rastreamento com Modelos Dinâmicos'
      ● Ideia principal:
	– Dado um modelo de movimento esperado, predizer onde os objetos ocorrerão no próximo quadro, mesmo antes deles aparecerem.
	● Restringir busca do objeto.
	● Estimativas são melhoradas pois o ruído das medidas diminuem com a suavidade das trajetórias.
	
      'Modelo Geral para Rastreamento'
      - O movimento do objeto de interesse é caracterizado por um estado subjacente X.
      - O estado X dá origem à medições ou observações Y.
      - A cada tempo t, o estado muda para Xt e tomamos uma nova observação Yt.
      
      'Passos do rastreamento'
      - Predição: qual é o próximo estado do objeto dadas medidas passadas? 
			    P(Xt|Y0 = y0,...,Yt-1 = yt-1)
      - Correção: Calcular uma estimativa atualizada do estado da predição e medidas.
			    P(Xt|Y0 = y0,...,Yt-1 = yt-1, Yt = yt)
      - Tracking pode ser visto como o processo de propagação da distribuição posterior do estado dado de medidas pelo tempo.
      
      'Premissar'
      - Apenas o passado imediato importa.
			    P(Xt| X0,...,Xt-1) = P(Xt| Xt-1)
      - Medições dependem apenas do estado atual
			    P(Yt| X0,Y0,...,Xt-1, Yt-1, Xt) = P(Yt|Xt)
			    
      'Modelo Dinâmicos Lineares'
      - Modelos dinâmicos: estado sofre transformação linear mais ruído gaussiano.
      - Modelo de observação: estado da medida é transformada linearmente com o ruído gaussiano.
      
      Exemplo (velocidade constante 1D)
      - vetor de estado é posição e velocidade.
      
      Exemplo (aceleracão constante 1D) 
      - vetor de estado é posição, velocidade e aceleração.
      
      'Filtro de Kalman'
      ● Método para rastrear modelos dinâmicos lineares com ruído gaussiano.
      ● Os estados (predicão e correcão) são gaussianos
	–Necessário ter média e covariância.
	–Cálculos diretos.
	
      - Dados estados corretos do passo de tempo anterior e todas as medidas até a atual, prever a distribuição em cima do passo atual.
      - Dadas as predições de estado e medida atual, atualizar predição do estado.
      
      'Filtro de Kalman 1D: Predição'
      ● Modelo dinâmico linear define a evolução do estado de predição, com ruído.
      ● Queremos estimar a distribuição para o próximo estado de predição.
      ● Atualiza a média.
      ● Atualiza a variância.
      'Filtro de Kalman 1D: Correção'
      ● Mapeando de estados para medidas.
      ● Predizer estado.
      ● Queremos estimar a distribuição corrigida.
      ● Atualize a média.
      ● Atualize a variância.
      'Predição x correção'
      - O que acontece se a predição é incerta? A medição é ignorada!
      - O que acontece se a medição é incerta? A predição é ignorada!
      'Prós e contras'
      ● +: simples refinamentos, fáceis de calcular, compactos.
      ●­ -: distribuicão unimodal, somente uma hipótese é testada.
      ●­ -: classes de movimentos restritas pelo modelo linear.
      
      'Outras técnicas: Amostragem Fatorada'
      ● Representa a distribuição de estado não-paramétricamente.
	- Predição: pontos de amostra da densidade principal para o estado
	- Correção: pesos das amostras de acordo com P(Y|X)
	'Filtro de partículas'
	1) Comece com amostras com peso do passo de tempo anterior.
	2) Amostra e deslocamento de acordo com o modelo dinâmico.
	3) Espalhar devido à aleatoriedade; isto é a prediçao da densidade P(Xt| Yt).
	4) Empese as amostras de acordo com a observação da densidade.
	5) Chegar à estimativa da densidade corrigida.
 	
     'Como associar dados a uma possível medida?' Problema geral em Visão.
						  Em movimento?
      
    
    "COMO ESCREVER O PROJETO FINAL"
    Escrevemos papers principalmente para IMPRESSIONAR OUTROS, GANHAR RECONHECIMENTO E SER PROMOVIDO.
    Objetivo: infectar a mente do leitor com SUA IDEIA, como um virus.
    Papers são bem mais duráveis do que programas (pense em Mozart).
    As grandes ideias são literalmente sem valor se você mantê-las para si mesmo.
    
    Ideia -> pesquisa -> escrever paper   (NÃO)
    Ideia -> escrever o paper -> pesquisa (SIM)
      - Nos força a sermos claros, focados.
      - Torna claro o que não entendemos.
      - Abre caminho para dialogar com outros: verificação da realidade, critica e colaboração.
      
    NÃO FIQUE INTIMIDADO
    'FALÀCIA' = você precisa ter uma ideia fantástica antes de poder escrever um paper (todo mundo faz isto).
    
    'VERDADE' = escreva um paper, sobre QUALQUER IDEIA, NÃO IMPORTA O QUÃO MAGRICELA OU INSIGNIFICANTE ELA POSSA PARECER PARA VOCÊ!!
    
    Escrever o paper é como vc desenvolve a ideia em primeiro lugar..
    Geralmente acontece de ser mais interessante e desafiador do que parece ser.
    
    O Objetivo do PAPER é: transmitir uma ideia da sua cabeça para a cabeça do leitor.
    Tudo serve este simples objetivo.
    
    O objetivo do PAPER NÂO É: descrever o sistema do WizWoz.
			       O leitor não tem um WizWoz.
			       Ela está interessada em materias do cérebro reusáveis, não em artefatos executáveis.
			       
    Transmitindo sua ideia:
      -Aqui está o problema.
      -É um problema interessante.
      -É um problema não-resolvido.
      -Aqui está minha ideia.
      -Minha ideia funciona(detalhes, dados)
      -Aqui está como minha ideia é comparada com abordagens de outras pessoas.
      
    Estrutura:
      -Abstract (4 sentenças)
      -Introdução (uma página)
      -Problema (uma página)
      -Minha ideia(duas páginas)
      -Os detalhes(5 páginas)
      -Trabalhos relacionados (1-2 páginas)
      -Conclusão e trabalhos futuros (0.5 paginas)
      
  Abstract
    -Geralmente escrevo o abstract por último
    -Usado pelos membros do comitte para decidir quais papers irão ler
    -4 sentenças:
      - Estado do problema
      - Dizer porque é um problema interessante
      - Soluções alcançadas
      - Dizer o que se segue da sua solução (pra que/quem e porque o trabalho vai ser pratico)
      
  Introdução
    -Descreva o problema
      -Use um exemplo para introduzir o problema
    -Indicar suas contribuições
      -Escreva a lista de contribuições primeiro.
      -A lista de contribuição dirige o resto do paper: O PAPER FUNDAMENTA AS AFIRMAÇÕES QUE VOCÊ FEZ!
      -O leitor pensa: "cara!! Se ele relmente conseguiu desenvolver isto, será uma leitura massa! Melhor eu ler isso."
      -Lista com marcadores de contribuição.
      -"NÃO FAÇA O LEITOR ESPECULAR QUAIS SÃO SUAS CONTRIBUIÇÕES"
      -Contribuições devem ser refutáveis (questionáveis) - diz o que você fez de forma que possa ser questionada pelo leitor. Não diga que testou
       e foi a melhor coisa.
      -"NÃO USAR 'O RESTO DO PAPER É...'" 
	Use referências futuras tiradas na narrativa da introdução.
	A introdução (incluindo as contribuições) devem examinar o resto do paper, e portanto refira-se a frente em cada parte imporante.
    -e isto é tudo!
    
  Problema (uma página)
  Minha ideia(duas páginas)
  Os detalhes(5 páginas)
    -Nenhuma trabalho relacionado ainda! Seu leitor está triste. (Me sinto cansado)
    -Problema 1: descrever abordagens alternativas fica entre o leitor e sua ideia.
    -Problema 2: o leitor não sabe nada sobre o problema ainda. Então sua (aparada cuidadosamente) descrição de várias técnicas compensadas 
     é absolutamente incompreensível. (sinto-me estúpido).
    -Em vez disso, concentre-se absolutamente numa narrativa que:
      -'Descreva o problema, e porque ele é interessante.'
      -'Descreva sua ideia.'
      -'Defenda sua ideia, mostrando como ela resolve o problema, e preenchendo os detalhes.'
      -'Pelo caminho, cite trabalhos relacionados na passagem, mas adie discussão para o fim.' SÓ MOSTRE AS DIREFENÇAS NO FIM
      
    -A carga útil do seu paper.
    -"COLOCAR DETALHES O TEMPO TODO"
    -Parece incrível! Mas os leitores vão dormir. Num paper, você DEVE mostrar os detalhes, mas PRIMEIRO transmita a idéia. 
    -"INTRODUZA O PROBLEMA, E SUA IDEIA, USANDO EXEMPLOS E SÓ ENTÃO APRESENTE O CASO GERAL!"
    
    -Transmitindo sua ideia
    -Explique ela como se estivesse falando com alguém usando um quadro-branco.
    -Transmiti-la é a ideia primária, não secundária.
    -Uma vez que o leitor tem a intuição, ele pode entender os detalhes.
    -Mesmo que ele pule os detalhes, ela ainda tem um entendimento.
    
    -Evidencia
    -Sua introdução faz reinvidicações
    -O corpo do paper provê evidencias para suportar cada reinvidicação
    -Cheque cada reinvidicação na introdução, identifique as evidências, e referencie-as na frente.
    -Evidencias podem ser: análise e comparação, teoremas, medidas, estudos de caso.
    
  Trabalhos relacionados (1-2 páginas)
    -'FALÁCIA' Para fazer meu trabalho parecer bom, tenho que fazer o trabalho dos outros parecer ruim.
    -Dar crédito aos outros não diminui o crédito do seu paper. "CRÉDITO NÃO É COMO DINHEIRO".
      - Calorosamente reconhecer pessoas que te ajudaram.
      - Ser generoso para a competição. 
      - Reconhecer fraquezas da sua abordagem.
      - Falhar em dar créditos para outros pode quebrar seu paper.
      - Se você diz que uma ideia é sua, e o árbitro souber que não é, então ou:
	  +Você não sabe que isto é uma ideia antiga (RUIM).
	  +Ou você sabe, mas está dizendo que é seu (MUITO RUIM)
	  
  Tendo certeza que trabalho relacionado é acurado
    - Um bom plano: quando você pensar que está pronto, mande o rascunho para a competição dizendo: 
      "você poderia me ajudar a garantir que eu descrevi o seu trabalho de forma justa?"
    - Frequentemente eles irão responder com uma crítica justa.
    - Eles são como se fossem seus árbitros de qualquer forma, então obter seus comentários de frente é muito bom.
    
  O processo
    -Comece cedo. Bem cedo.
      -Papers escritos às pressas são rejeitados.
      -Papers são como vinho: eles precisam de tempo para amadurecer.
    -Colaboração
    -Use CVS para suportar colaboração.
    
  Obtendo ajuda
    - Tenha seu paper lido pela maior quantidade de cobaias possível.
    - Experts são melhores.
    - Não experts são também muito bons.
    - Cada leitor pode ler seu paper pela primeira vez apenas uma vez! Então use-os com cuidado.
    - Explique exatamente o que você quer ("Eu me perdi aqui" é muito mais importante que "palavras tolas são mal-soletradas")
    
    Cada revisão é ouro em pó, esteja sempre lisonjeado a receber críticas!!
    Sei que é MUITO MUITO MUITO difícil.
    Mas é MUITO MUITO MUITO MUITO importante.
    
  Material básico
    Entregue até a data limite
    Mantenha as restrições de tamanho
      -Não passe as margens
      -Não use fonte pequena
      -Na ocasiao, de suporte as suas evidencias (por exemplo, dados experimentais, prova escrita) em um apêndice.
      -Sempre use um spell checker
      
    Dê forte estrutura visual ao paper usando:
      -seções e sub-seções
      -itálicos
      -tópicos
      -códigos
      
    Use voz ativa
    A voz passiva é "respeitável" mas ela mata seu paper. Evite-a a todo custo.
    Use "WE" para nós/autores e "YOU" para vocês, leitores.
    
    Use linguagem "SIMPLES" e "DIRETA". Sem enrolar para dizer uma coisa. Diga na lata.
    
    Sumário
    - Se você nçao lembra mais nada.
      - Identifique sua ideia principal.
      - Faça suas contribuições de forma explícita.
      - Use exemplos.
      - http://www-2.cs.cmu.edu/afs/cs.cmu.edu/user/mleone/web/how-to.html
      
   
1) O que é esperado de cada projeto individual?

- A entrega deve ter 1 texto em formato de artigo (seguindo especificamente o modelo de 6 páginas do IEEE de http://www.cvpr2011.org/sites/default/files/cvpr2011AuthorKit.zip)

- O código original, na plataforma OpenCV, com um arquivo -readme- exemplificando como compilar o código e especificidades da implementacão, e um arquivo executável com a demonstracão.

- Uma apresentacão oral, com demonstracão, do projeto realizado.


2) Exemplos de projetos, e especificacões adequadas?

- O texto a ser entregue especifica um roteiro das especificacões de um projeto:

2.1) Introducão: deve-se aqui especificar qual o problema que está sendo abordado;
                  por que ele é importante;
                  qual é o trabalho relacionado (explicar esse trabalho);
2.2) Método: descrever o método sendo implementado;
              o que você fez de diferente do autor original;
              qual parte do código é sua autoria, e quais (e de onde) são as
                outras partes;
              como executar o sistema;
2.3) Resultados: descrever os resultados conseguidos;
                  como eles podem ser comparados com os resultados do original;
                 
2.4) Discussão: julgar as vantagens e desvantagens da solucão implementada;
                como ele poderia ser melhorado;

2.5) Referências usadas, completas e precisas.

"IMPORTANTE"
- Fontes sugeridas para os projetos seriam os artigos apresentados na CVPR, ICCV, ECCV ou BMVC (Os artigos, não os cursos e tutoriais). Cada 
artigo lida com um problema desse tipo, e certamente um (ou até mais de um) pode servir para um ajuste do problema inicial que você está pensando.
Todos os artigos completos podem ser acessados de uma máquina a partir da UnB (ou na BCE) pois a UnB possui assinatura IEEE.
(O link é http://ieeexplore.ieee.org/xpl/mostRecentIssue.jsp?punumber=5521877).
O importante é você escolher um, definir seu(s) objetivos específicos e comecar a implementacão.