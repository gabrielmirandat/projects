  pipeline - Em computação gráfica 3D, o pipeline de gráficos ou pipeline de processamento refere-se à sequência de passos utilizados para 
	     criar uma representação rasterizada 2D de uma cena 3D.Claramente falando, uma vez que um modelo 3D foi criado, por exemplo, em um
	     vídeo game ou qualquer outra animação de computador 3D, o pipeline de gráficos é o processo de transformar esse modelo em 3D para 
	     o que os monitores de computador possam representá-lo.
	     
  pixel shader - O Pixel Shader (semelhante ao Vertex shader) é um programa que é processado no pipeline da GPU (graphic processing unity), ele
		 é capaz de trabalhar na estrutura dos pixels depois que um modelo 3D é rasterizado. Com o pixel shader podemos criar efeitos 
		 na imagem, como efeitos de vidro, rugosidade,desfoque e etc, esse efeitos são conhecidos como pos-effects. É amplamente 
		 utilizado na área de jogos que necessitam que os processos sejam rápidos,e por o pixel shader ser executado na GPU (placa de 
		 vídeo) deixa a CPU mais livre para os cálculos matemáticos e lógicos do jogo.Para criar programas de Pixel Shader, pode-se 
		 usar as linguagens GLSL (OpenGL Shading Language) que é utilizada para API gráfica OpenGL.
		 
  vertex shader - O Vertex Shader é o estágio Shader programável no pipeline de renderização que lida com o processamento de vértices 
		  individuais. Vertex shaders são dados Atributo Vertex alimentados, conforme especificado a partir de um objeto de matriz 
		  vértice por um comando de desenho. Um shader vértice recebe um único vértice do fluxo de vértice e gera um único vértice 
		  para o fluxo de saída de vértice. Deve haver um mapeamento 1: 1 de vértices de entrada para saída vértices.Vertex shaders
		  normalmente executam transformações para o espaço pós-projeção, para consumo pelo estágio Vertex pós-processamento. Eles 
		  também podem ser usados ​​para fazer a iluminação por vértice, ou para realizar trabalhos de instalação para as fases 
		  posteriores de sombreamento.
		 
  Clipping - É tratar uma imagem para que nela apareça somente aquilo que deve aparecer, em outras palavras, significa recortar objetos para 
	     manter as partes que podem ser vistas e retirar o que não pode. Em uma cena tri-dimensional, por exemplo, não é possível ver todas
	     as superfícies de todos os objetos, pois suas faces se sobrepõem de acordo com o ângulo de visão. 
		 
  OpenGL é Shader-Based.
  
  Será de interesse:
    -OpenGL 3.2 e posteriores
    -OpenGL ES 2.0 (mobile devices)
    -webGL
    
  Para checar versão do opengl:
    'sudo apt-get install mesa-utils'
    'glxinfo | grep "OpenGL version"'
    
  Documentação
    www.opengl.org
    
  'O que é computação gŕafica'
    Computação gráfica aborda todos os aspectos de criação de imagens com um computador. Envolve 'Hardware','Software' e 'Aplicações'.
    
    Um CRT: Pode ser usado tanto como line-drawing device (caligráfico) ou como frame buffer (modo rasterização) 
      Esta escrita linha a linha tem um alto custo
      
      
    Começou com:
      1) Strip charts - Um gravador de gráfico é um dispositivo eletromecânico que registra uma tendência de entrada de energia elétrica ou 
	  mecânica em um pedaço de papel (o gráfico).
      2) Pen plotters
      3) Telas CRT
      
    • Wireframe graphics - objeto todo desenhado com grades.
    • Sketchpad - pad em que você desenha e aparece na tela do computador.
    • Processadores de exibiçao(DPU).
	-Hospedeiro compila lista de exibição(arquivo que contém os gráficos) e envia para DPU.
    • Tubos de armazenamento.
	-Não precisa de refresh constante.
	
    Gráficos rasterizados: 
      Imagem produzida como uma matriz(o raster) de elementos de imagem(pixels) no frame buffer.
      Nos permite irmos de linhas e grades a polígonos preenchidos.
      
    Novas capacidades de hardware:
      Mapeamento de textura
      Blending
      Acumulação, buffers estêncil
      Fotorrealismo
      Cartões gráficos
      Cinema
      Pipelines programáveis
      
  'Formação da imagem'
    Em computação gráfica, imagens são formadas de forma análoga à como são formadas em sistemas de imagens físicos.
      -Como câmeras, microscópios, telescópios e o sistema visual humano.
      
    Base física para a formação das imagens
      Luz
      Cor
      Percepção

    Elementos de formação da imagem
      -Objetos
      -Observador
      -Fontes de luz
      -Atributos que governam como a luz interage com os materiais na cena.
    
    Luz
      -Geralmente comprimentos de onda entre 350-750 nm. onde as longas são vermelhas e as curtas azuis.
      
    Ray tracing e ótica geométrica
      -Ray tracing (traçado de raios) é um algoritmo de computação gráfica usado para síntese (renderização) de imagens tridimensionais.O 
      método utilizado pelo algoritmo, baseia-se na simulação do trajecto que os raios de luz percorreriam no mundo real, mas, neste caso, de 
      trás para a frente. Muito utilizado no cinema, televisão e efeitos especiais devido ao grande realismo. Menos adequado para jogos de 
      computador, por requerer aplicações em tempo real.
      -O problema é que é muito lento para aplicações interativas.
      -Ray tracing com GPU é como se fosse tempo real.
      
    Luminância
      -Monocromática
      -Valores são níveis de cinza
      -Análogo com filme preto e branco ou televisão
      
    Imagem colorida
      -Tem atributos de matiz, saturação e brilho.
      -Porém, o sistema visual humano tem dois tipos de sensores:
	-Bastonetes: monocromática, visão noturna
	-Cones: sensibilidade a cor (são três tipos de cones: um para vermelho, outro verde e outro azul - 'RGB' )
      -Cor aditiva: Combinação das cores da tríade.
      -Cor subtrativa: Forma uma cor, filtrando a luz branca com filtros de ciano(C), magenta(M), e amarelo(Y).
	-usado em interações de material-luz, impressão e filme negativo.
	
    Modelo sintético da câmera
      - p = objeto
      - plano da imagem = plano onde a imagem será projetada (não necessariamente dentro da câmera)
      - projeção de p = imagem formada no plano da imagem
      - centro de projeção = distância focal (o pinhole, onde fica o obturador)
      
    Iluminação global x local
      -Não se pode calcular a cor e a sombra de cada objeto independentemente.
	-Alguns objetos são bloqueados da luz
	-A luz pode refletir de objeto para objeto
	-Muitos objetos podem ser translúcidos.
	
  'Modelos e arquiteturas'
    Objetivos: Aprender design de sistemas gráficos
	       Introduzir arquitetura de pipeline
	       Examinar componentes de software para um sistema gráfico interativo.
	       
    Numa API, precisamos especificar: objetos, materiais, observador, luz.
    
    Abordagens físicas
      -Ray tracing : segue raios de luz do centro de projeção até serem absorvidos pelos objetos ou irem ao infinito.
		     Podem manipular efeitos globais = múltiplas reflexões, objetos translúcidos.
		     Devagar
		     Deve ter uma base de dados inteiramente disponível em todos os momentos.
      -Radiosidade : abordagem baseada em energia
		     Muito lento.
		     
    Abordagens práticas
      -Processar objetos um por vez na ordem em que são gerados pela aplicação. É considerada apenas iluminação local.
      
    Arquitetura do pipeline
      Vertices -> Processador de vértices -> Assembler primitivo e Clipper -> Rasterizador -> Processador de fragmentos -> Pixels
	    programa de aplicação											tela
      -Todos os passos são implementáveis no cartão gráfico do hardware.
      
      "Processador de vértices"
	-processo de converter representações de um objeto de um sistema de coordenadas para outro. Também processa cor nos vértices.
	 coordenadas do objeto -> coordenadas da câmera -> coordenadas da tela
	-cada mudança de coordenadas equivale a uma transformação de matriz
	
      "Projeção"
	-processo que combina o vizualizador 3D com objetos 3D para produzir imagens 2D.
	-Projeção perspectiva: todos os projetores se encontram no centro de projeção.
	-Projeção paralela: projetores são paralelos, centro de projeção é subistituído pela direção da projeção.
	
      "Assembler primitivo"
	-onde vértices são agrupados em objetos geométricos antes do clipping e da rasterizaçao.
	-segmentos de linhas, polígonos, curvas e superfícies.
	
      "Clipping"
	-Assim como câmeras reais não "enxergam" todo o mundo, a câmera virtual também não.
	-Aqui, objetos que não estão dentro do volume de visualização são "descartados" da cena.
	
      "Rasterização"
	-Se um objeto não foi descartado, os pixels contidos no frame buffer recebem cores.
	-produz um conjunto de fragmentos para cada objeto. Fragmentos são "pixels em potencial", que tem um lugar no frame buffer, além de 
	 atributos de cor e profundidade.
	-Atributos dos vértices são interpolados sobre os objetos pelo rasterizador.
	
      "Processador de fragmentos"
	-Fragmentos são processados para determinar a cor do pixel correspondente no frame buffer.
	-Cores podem ser determinadas por mapeamento de texturas ou interpolação de cores do vértice.
	-Fragmentos podem ser bloqueados por outros fragmentos que estão mais perto da camera.
	  -removedor de superfície escondida.
	  
    API
      -interface de software pela qual o programdor vê o sistema gráfico.
      programa de aplicação -> biblioteca de gráficos(API) -> hardware
      -contém funções que especificam o que precisamos para formar uma imagem = objetos, visualizador, fontes de luz, materiais, entradas de 
       dispositivos, etc..
       "exemplo (baseado em GPU)"
	  vec3 points[3];
	  points[0] = vec3(0.0,0.0,0.0);
	  points[1] = vec3(0.0,1.0,0.0);
	  points[2] = vec3(0.0,0.0,1.0);
	  
	  -"array é mandado pra GPU"
	  -"diz para a GPU renderizar como um triângulo"
      
   Especificações da câmera
    -seis graus de liberdade (translações e rotações).
    -lentes
    -tamanho do filme
    -orientação do plano do filme
    
   Luzes e materiais
    -Tipos de luzes
      -fontes pontuais ou distribuídas, perto ou longe, propriedades de cor.
    -Propriedades do material
      -absorção: propriedades de cor
      -reflexão: difuso ou especular.
      
  VBO - fornece métodos para carregar dados de vértice (posição, vetor normal, cor, etc.) para o dispositivo de vídeo para renderização de 
	modo não-imediata. VBOs oferecem ganhos substanciais de desempenho em relação à renderização de modo-imediato principalmente porque os
	dados residem na memória do dispositivo de vídeo, em vez de memória do sistema e para que possa ser prestado diretamente pelo 
	dispositivo de vídeo.
  VAO - OpenGL objeto que armazena todo o estado necessário para fornecer dados de vértice (com uma exceção menor observado abaixo). Ele
	armazena o formato dos dados vértice, bem como os objetos de buffer (ver abaixo) que fornecem as matrizes de dados vértice. Note-se
	que Vaos não copie, congelar ou armazenar o conteúdo dos buffers referenciados - se você alterar qualquer um dos dados nos buffers 
	referenciados por uma VAO existente, essas mudanças serão vistas pelos usuários do VAO.
  
  'Evolução do Pipeline Gráfico'
  Objetivos:
    -mostrar que roda em GPUs Intel;
    -mostrar a estrutura típica de um programa enfatizando as partes "imutáveis;"
    -mostrar como a CPU comunica com a GPU via VAOs e VBOs;
    -mostrar como ler, compilar e linkar os shaders;
    -mostrar exemplos simples de vertex e fragment shaders ;
    
    -OpenGL só renderiza triângulos, pois:
      São 'simples' e 'convexos'.
      
    -Nessas versões modernas de OpenGL(que nós definimos como as versões a partir da versão 3.1), são aplicativos OpenGL inteiramente 
     baseado em shaders. Na verdade, a maior parte deste curso irá discutir shaders e operações que suportam.
     
    -Usaremos pipeline de gráficos baseado em shader.
    
    -Evolução do pipeline:
      1.0 => pipeline funcão-fixa, modificáveis apenas com input de valores às funções.
      2.0 => adicionou shaders programáveis: 'vertex shading' e 'fragment shading'.
		•vertex shading possibilitou a aplicação de controle total sobre a manipulação da Geometria 3D fornecida pela aplicação.
		•fragment shading permitiu à aplicação recursos de 'shading pixels (-termo usado na determinação das cores do pixel)'.
      3.0=> introduz o deprecation model(método usado para remover as características da OpenGL).
	    introduziu uma mudana em como o contexto do OpenGL era usado. 
	    OpenGL usa uma estrutura de dados opaca chamada 'contexto', que usa para armazenar shaders e outros dados. De duas formas:
	      1) full contexts: incluindo coisas deprecated.
	      2) foward-compatible contexts: só o novo estilo.
      3.1=> removeu pipeline de funções-fixas.
	    programas são obrigados a definir os shaders.
	    quase todos os dados são armazenados em GPU
	    todos os vertex data são enviados usando buffer de objetos.
      3.2=> adiciona novo estágio de shading - 'geometry shaders - (modifica primitivas geométricas dentro do pipeline gráfico)',
	    geometry shader fica entre o vertex shader e o 'primitive setup and rasterization', fase cujo usuário não tem acesso.
	    introduz novos profiles aos contextos já existentes: core(apenas contexto atual) e compatible(tudo o que já teve).
      4.2=> inclui novos estágios de shading: 'tessallation-control-sader' e 'tessallation-evaluations-shader'.
		  tessalation = forma repetida de novo e de novo cobrindo um plano sem ficar nenhum gap.
		  
  'Estrutura do programa'
    'main()' Especificar funções callback
	     Abrir uma ou mais janelas com as propriedades requeridas
	     Entrar no loop de eventos (última declaração executável)
	     Maioria das funções GLUT
	   
    'init()' Seta as variáveis de estado
	     Visualização 
	     Atributos
	     Permite cores mais flexíveis
	     
    'initShader()' Lê, compila e  linka shaders
    Esconde detalhes de como setar os shaders
    
    callbacks - função de renderização (display)
		funções de entrada e saída
		
    - Problema chave é o que precisamos formar um array de dados para mandar para a GPU e então renderizá-lo.
    
    #include<GL/glut.h> já inclui gl.h
    
    'glutInit' permite adiquirir argumentos de linha de comando e inicializa o sistema.
    'glutInitDisplayMode' exige propriedades da janela (contexto de renderização - cor, nº de buffer e tipo, separados por OU lógico)
    'glutWindowSize' em pixels
    'glutWindowPosition' do canto superior esquerdo da tela
    'glutCreateWindow' cria janela com título especificado como parâmetro
    'glutDisplayFunc' callback da função de renderizar a tela
    'glutMainLoop' entra no loop de eventos infinito.
    
    Modo imediato: Toda vez que um vértice é especificado na aplicação, sua localização é mandada pra GPU, isto cria um gargalo entre a CPU
		   e a GPU.
		   'O melhor seria mandar o array uma vez e armazená-lo na GPU para múltiplas renderizações'
		   
    'Display callback' Uma vez que mandamos os dados para a GLUT, podemos iniciar a renderização.
		       Arrays são buffer objects '(geometrias)' que contém vertex arrays '(vértices)'.
		       
    Vértices podem conter vários atributos : Posição, cor, coordenadas de textura e dados da aplicação.
    'Vertex arrays' armazena esses dados.
    
    'Vertex Array Object' 
    Conteineriza todos os dados de vértices (posição, cores)
    Necessita nome para buffer e ativamento.
    
    'Gluint abuffer;'
    'glGenVertexArrays(1, &abuffer);' declara vertex array object no nome passado como parâmetros
    'glBindVertexArray(abuffer);' ativa o vertex array object passado como parâmetro. Nos permite trocar entre VBOs(buffer objects).
    Neste ponto temos um atual vertex array, mas sem nenhum conteúdo.
    
    'Buffer Object'
    Buffers objects nos permite tranferir grandes quantidades de dados para a GPU.
    Precisa ser criado, ativado e identificar dados.
    
    'Gluint buffer;'						declarado
    'glGenBuffers(1, &buffer);'					criado	
    'glBindBuffer(GL_ARRAY_BUFFER, buffer);'			ativado
    'glBufferData(GL_ARRAY_BUFFER, sizeof(points), points);'	associado a dados
    Dados no atual vertex array são mandados para a GPU
    
    'Init()'
    Vertex array objects e buffer objects são setados na init()
    Aqui também é definido o clear color e outros parâmetros OpenGL
    Também seta shaders como parte da inicialização (Leitura, Compilação e Linkagem)
    
    Câmera na origem (0,0) apontando para o eixo z negativo. Bounding Box de tamanho 2.
    
    Viewport : subjanela dentro da janela criada.
    Em openGL, projeções são manipuladas por uma matriz de projeção (transformação). Funções de transformação também são usadas para mudanças
    em sistemas de coordenadas. 3 opções:
	Código de aplicação
	funções GLSL
	vec.h e mat.h
	
  'Shaders (linguagem GLSL - OpenGL Shading Language)'
    GLSL dados primitivos: Matrizes, Vetores e Samplers (texturas).
      vec2, vec3, vec4
      mat2, mat3, mat4 ('armazenada por colunas')	'm[linha][coluna]'
      
      vec3 a = vec3(1.0,2.0,1.0)
      vec2 b = vec2(a)
      
      - Funções padrão em C
	Trigonométricas
	Aritméticas
	Normalize, reflect, length
	Operadores sobrecarregados para matriz e vetores (+,-,*)..
	
	'Para referir-se a um elemento:'
	  - []
	  - . juntamente com:
	    x, y, z, w componentes de um sistema de coordenadas homogêneas.
	    r, g, b, a componentes do sistema de cores RGBA.
	    s, t, p, q componentes do sistema de coordenadas de textura.
	    é tudo a mesma coisa: a[2], a.b, a.z, a.p
	    'é permitido a sintaxe:' b.xyz = a.yzx;
    
   'Conectando Shaders com Aplicações'
    1) Ler códigos fonte dos shaders (em GLSL)
      - glShaderSource recebe o arquivo de shader como uma string
    2) Compilar os shaders
    3) Criar um programa objeto
      - é um container para os shaders(pode conter múltiplos shaders)
      'Todas as funções definidas no InitShader.cpp', seria myProgObj o program no código.
      
      GLuint myProgObj;
      myProgObj = glCreateProgram(); /* identifiquei onde os códigos objeto dos shader serão armazenados */
      glCompileShader( shader ); /* a variável shader contém o fonte do shader */
      glAttachShader( myProgObj, shader ); /* o código compilado é acrescentado a myProgObj */
      glLinkProgram( myProgObj ); /* linkei o código objeto em myProgObj */
      glUseProgram( myProgObj );/* tornei myProgObj ativo */
    4) Linkar os shaders no programa objeto
    5) Linkar as variáveis na aplicação que correspondam a variáveis nos shaders ('Vertex attributes' e 'Uniform variables')
    
      - Vertex attributes são declarados nos shaders, o linker forma uma tabela, aplicação obtém um índice dessa tabela e amarra-o a uma vari-
	ável da aplicação. (similar para variáveis uniform)
   
   
   'Qualificadores'
    - Atributos de vértices são interpolados pelo rasterizador se tornando atributos do fragmento.
      'de Atributos'
      - variáveis atributo-qualificadas podem ser mudadas no máximo uma vez por vértice.
      - Antes tinha a gl_Position, hoje definidas pelo usuário (aplicação).
      'Uniforme'
      - Variáveis que são constantes para toda a primitiva (line,triangles)
      - Podem ser mudadas na aplicação e enviadas para os shaders.
      - Não podem ser mudadas nos shaders.
      - Usadas para passar informação ao shader tais como o bounding box de uma primitiva.
      'Varying'
      - Variáveis que são passadas do vertex shader para o fragment shader.
      - automaticamente interpoladas pelo rasterizador.
      - usamos out no vertex shader e in no fragment shader, antigamente era varying.
      
      
    aplicação -> vertex shader -> primitive assemply
       GPU
       
      aplicação -> fragment shader  ->  frame buffer
    rasterizador
    
    'in' - indica que a variável é de entrada
    'out' - indica que a variável é de saída
    'gl_Position' -  é variável interna de saída da GLSL (em desuso) para saída no vertex shader.
    'gl_FragColor' -  é a variável interna que especifica a cor de saída do fragmento no Fragment Shader.
    'glDrawArrays' - manda os dados para o Vertex Shader
    
    
    'vertex shader'
      - Aplicações:
	  - Movimentar vértices:	Morphing (transformar objeto em outro)
					Movimento ondulatório
					Fractais
	  - Iluminação:			Modelos mais realísticos
					Cartoon shaders (animado)
    
    'fragment shader'
      - Aplicações:
	  - Cálculo de iluminação baseado em fragmentos:	
	  - Mapeamento de textura:		smooth shading (suavizar/arredondar as arestas triangulares juntando normais dos vértices)
						environment mapping (superfície do objeto espelhando o ambiente)
						bump mapping (texturas em geral)
  
  
  'Cores e atributos'
      'Primitivas OpenGL'
	  GL_POINTS - desenha pontos
	  GL_LINES - desenha linhas
	  GL_LINE_STRIP - desenha um grupo conectado de segmentos de linha do primeiro vértice ao último.
	  GL_LINE_LOOP - como um GL_LINE_STRIP com as duas pontas unidas.
	  GL_TRIANGLES - desenha triângulos.
	  GL_TRIANGLE_STRIP - desenha um grupo conectado de triângulos. Um triângulo é definido para cada vértice presente depois dos dois 
			      primeiros vértices.'(n, n+1, n+2)'
	  GL_TRIANGLE_FAN - desenha um grupo conectado de triângulos. Um triângulo é definido para cada vértice presente depois dos dois 
			      primeiros vértices.'(1, n+1, n+2)'
			      
	  'OpenGL só mostra triângulos'
	    -simples: arestas nunca se cortam.
	    -convexos: todos os segmentos entre pontos estão dentro do polígono.
	    -flat: todos os vértices estão num mesmo plano.
	    
	    A aplicação deve tesselar um polígono em triângulos (triangulação).
	    OpenGL 4.1 contém um tesselador (2 shaders de tesselação)
	    
	    -triângulos longos e finos renderizam mal.
	
	  'Atributos' determinam a aparência dos objetos.
	    -Cores(pontos, retas, polígonos)
	    -tamanho e largura(pontos, retas)
	    -padronagem(retas, polígonos) 'atrás do 3D com pontilhados ou segmentos de retas'
	    -modo poligonal
		-exibe preenchido: cor sólida ou padrongem
		-exibe arestas
		-exibe os vértices
	    cor Degradê = default é smooth shading 'interpolação de cores' 
	    
	  'Cores'
	    -atribuídas no 'fragment shader' mas podem ser determinadas nos dois shaders ou na aplicação.
	    -cor na aplicação: passa para o vertex shader como uma variável 'Uniform' ou como um atributo do vértice.
	    -cor no vertex shader: passa para o fragment shader como uma variável varying( já em desuso).
	    -cor no fragment color: pode alterar via código no shader.
		
  "Programando em OpenGL"
    'Aplicações 3D'
      -ou nos preocupamos com a ordem em que as primitivas são renderizadas ou usamos a "remoção de superfícies escondidas".
      
    'Curva de Sierpinski' ->> Fractal
      1)comece com um triângulo.
      2)conecte os bissetores dos lados e remova o triângulo central.
      3)repita (no lim->infinito, temos um fractal).
	  A área tende a zero.
	  O perímetro tende a infinito.
	    
    'generalizando para 3D'
      1)começar com tetraedro.
      2)podemos subdividir cada uma das 4 faces.
      3)parece que removemos um tetraedro sólido do centro deixando 4 tetraedros menores.
      4)código praticamente idêntico ao exemplo 2D.
      
    'Remoção de Superfícies Escondidas'
      1)queremos ver apenas as superfícies a frente de outras (não temos visão de raio-X).
      2)OpenGL determina a superfície escondida usando z-buffer o qual armazena as distâncias dos objetos em relação ao observador.
      3)O algoritmo usa um novo buffer, z-buffer , para armazenar a informação de profundidade enquanto a “geometria” percorre o pipeline.
      4)É necessário requisitar em main.
	  'glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH )'
      5)habilitar em init
	  'glEnable( GL_DEPTH_TEST )'
      6)limpar no callback do display
	  'glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT )'
    
    
    "Representação"
      Introduzir sistemas de coordenadas para representar espaços vetoriais e frames para representar espaços afins.
      
      - Se um conjunto de vetores for linearmente independente, não podemos representar um deles em função dos demais.
      - O número máximo de vetores linearmente independentes é fixo e denominado 'dimensão' do espaço.
      - Qualquer conjunto de n vetores LI formam uma base para o espeço.
	  'v = a1.v1 + a2.v2 + ... + an.vn, onde {ai} são únicos.
	  
      - Precisamos de um 'frame' de referência para relacionar pontos e objetos ao nosso mundo físico.
      
      Coordenadas do mundo
      Coordenadas de câmera
      
      Um sistema de coordenadas é insuficiente para representar pontos.
      - Se trabalharmos em um espaço afim então podemos adicionar um único ponto, a origem , a base vetorial para formar um frame.
      
      'vetor' = a1.v1 + a2.v2 + a3.v3 = [a1 a2 a3 0]
      'ponto' = Po + b1.v1 + b2.v2 + b3.v3 = [b1 b2 b3 1]
      
      'Assim obtemos uma representação em um sistema de coordenadas homogêneas em quatro dimensões que serve para ambos'
      
      'Coordenadas homogêneas'
      Para visualização ortográfica podemos manter w = 0 para vetores e w = 1 para pontos.
      Para visualização perspectiva precisamos de divisão perspectiva.
      
      Qualquer ponto ou vetor pode ser representado em qualquer frame.
      Podemos representar Qo, u1, u2, u3 em termos de Po, v1, v2, v3
      'frame' = ponto inicial mais direção.
      
      Dentro de dois frames qualquer ponto ou vetor tem uma representação da mesma forma:
	a = [a1 a2 a3 a4]	a4 = b4 = 1 para pontos
	b = [b1 b2 b3 b4]	a4 = b4 = 0 para vetores
	
	A matriz M é 4 x 4 e especifica uma transformação 'afim' expressa em coordenadas homogêneas.
	
	1) Toda transformação linear é equivalente a mudança de frames.
	2) Toda transformação afim preserva retas.
	3) Entretanto, uma transformação afim tem apenas 12 graus de liberdade porque 4 dos elementos na matriz são fixas e são um subconjunto
	   de todas as possíveis 4 x 4 transformações lineares.
	   
	-Em OPENGL o frame base no qual começamos é o frame do mundo.
	-Eventualmente representamos entidades no frame da câmera mudando a representação do mundo através do uso da matriz denominada 
	 modelview.
	 
	 'p' = ABCp = A(B(Cp)) = a ordem de multiplicações é da direita para a esquerda.
	 As rotações em torno de eixos são ditas com ângulos de euler.
	 
	 'rotação de ponto fora da origem' = M = T(pf)R(Θ)T(-pf)
	 
    "Geometria"
    Escalares, vetores, pontos = operações matemáticas entre eles de forma independente de sistema de coordenadas.
    Maioria dos resultados geométricos são independentes do sistema de coordenadas.
    Precisamos de 3 elementos básicos em geometria:
					    'Escalares', 'Vetores', 'Pontos'
					    
	Escalares podem ser definidos como membros de conjuntos os quais podem ser combinados por duas operações (adição e multiplicação)
	  obedecendo alguns princípios fundamentais (associatividade, comutatividade, inversas).
	  
	Vetor é uma quantidade com dois atributos: direção e magnitude.
	
	Espaços Vetoriais são insuficientes para geometria. Pontos são necessários.
	
	Pontos tem local no espaço. 
	  - subtração ponto-ponto gera um vetor
	  - soma ponto vetor também gera um ponto.
	  
	  Retas (forma paramétrica)
	  Considere todos os pontos da forma P(a) = Po + ad.
	  Conjunto de todos os pontos que passam por Po na direção do vetor d.
	  
	    'explicita': y = mx + h
	    'implícita': ax + by + c = 0
	    'paramétrica': x(a) = ax0 + (1 - a)x1
	    
	  Um plano pode ser definido por um ponto e dois vetores ou por três pontos.
	  
    "Projeções"
    No entanto, até agora, tudo foi especificado em -1 a 1 em X, Y e Z.
    
    'Para tranformar um volume de modelagem:'
      mat4Model;
      GLuint modelLoc;
      void mydisplay( void ) {
	Model = Scale(0.01);
	glUniformMatrix4fv(modelLoc, 1, GL_TRUE, Model);
      }
      void init( void ) {
	modelLoc = glGetUniformLocation( program, "model" );
	glUniformMatrix4fv(modelLoc, 1, GL_TRUE, Model);
      }
      
      A matriz de projeção default da OpenGL é a ortogonal.Os raios projetores são perpendiculares ao plano de projeção Portanto, não importa 
      quão perto ou longe um objeto esteja do plano de projeção o tamanho será sempre o mesmo!
      
      'Projetar em prespectiva e transladar "camera"'
        mat4 View;
	GLuint viewLoc;
	mat4 Projecao;
	GLuint projLoc;
	void mydisplay( void ) {
	  View = Translate( 0, 0, -2 );
	  glUniformMatrix4fv(viewLoc, 1, GL_TRUE, View);
	  Projecao = Perspective(30, 	//ângulo medido na direção Y
				  1,	//aspect rate do tronco de pirâmide (largura/altura)
			          1, 	//distância znear
			        10);	//distância zfar
	  glUniformMatrix4fv(projLoc, 1, GL_TRUE, Projecao);
	}
	void init(void) {
	  viewLoc = glGetUniformLocation( program, "view" );
	  glUniformMatrix4fv(viewLoc, 1, GL_TRUE, View);
	  
	  projLoc = glGetUniformLocation( program, "proj" );
	  glUniformMatrix4fv(projLoc, 1, GL_TRUE, Projecao);
	}
	