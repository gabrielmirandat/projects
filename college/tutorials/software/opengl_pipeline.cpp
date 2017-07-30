Pipeline gráfico
  -Todo vértice tem atributos que você escolhe. Em geral são: posição 3D e no mundo e coordenadas de textura.
  
  O 'vertex shader' é um pequeno programa em execução na sua placa gráfica que processa cada um desses vértices de entrada individualmente. 
  Este é o lugar onde a transformação de perspectiva tem lugar, que projeta vértices com uma posição de mundo 3D em sua tela 2D! Ele também 
  passa atributos importantes, como cor e textura coordena mais abaixo na pipeline.
  
  O 'geometry shader' é totalmente opcional e foi recentemente introduzido. Diferente do vertex shader, pode mandar mais dados de saída do que
  vieram dados na sua entrada.Toma as primitivas do estágio do shape assembly como entrada e pode ou passar a primitiva, ou modificá-la pri-
  meiro, descartar completamente ou até substituir por outras primitivas. O estágio pode reduzir a quantidade de dados que precisa ser transfe-
  rido. Você pode passar vértices como point vertices, juntamente com um atributo para sua posição no mundo, cor e material e os atuais cubos
  produzidos podem ser produzidos no geometry shader com pontos como entrada!
  
  Após os shaders e conversões para coordenadas de tela, o rasterizador torna as partes visíveis dos shaders em fragments de tamanho de pixel.
  Os atributos de vértices vindos do vertex shader e do geometry shader são interpolados e passados como entrada para o fragment shader
  para cada fragmento.
  
  O 'fragment shader' processa cada fragmento individual juntamente com seus atributos interpolados e deve ter como saída a cor final.Isto
  geralmente é feito amostrando da textura usando as coordenadas de atributo dos vértices interpolados da textura ou simplemente outputando
  a cor. Em cenários mais avançados, pode também fazer cálculos relacionados à luz e sombra e efeitos especiais. Também tem a abilidade de 
  descartar certos fragmentos.
  
  'Vertex input'
  A primeira coisa que precisa decidir é quais dados o cartão gráfico vai precisar para desenhar sua cena corretamente.
  Como foi mencinado, estes dados vêm na forma de vertex attributes. Todo e qualquer atributo começa como posição do mundo.
  Quando seus vértices tiverem sido processados pelo pipeline , suas coordenadas terão sido transformadas em device coordinates.
  Coordendas x e y do dispositivo são mapeadas na tela entre -1 e 1.
  A ordem dos vértices não tem de ser sequencial (isto é, a ordem na qual são formadas as formas), mas isto obriga a fornecer dados adicionais 
  na forma de um element buffer.
  Com um 'Vertex Buffer Object (VBO)' você carrega os dados de vértice na GPU, assim você não precisa ficar mandadando estes dados para lá toda
  hora.
	      'GLuint vbo;	      //Container necessário para tornar o VBO ativo e para destrui-lo'
	      'glGenBuffers(1, &vbo); // Generate 1 buffer'			relação vertex buffer object -> array buffer
	      'glBindBuffer(GL_ARRAY_BUFFER, vbo); //carrega o dado atual e o torna ativo. Isto faz do VBO que criamos o ativo array buffer'
										agora que está ativo podemos copiar dados de vértice para ele.
	       'glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);'
										note que não se refere ao id fo VBO, mas ao array buffer ativo
  Daqui os vértices com seus atributos foram copiados para GPU. Como os atributos podem ser mandados em qualquer ordem, ainda precisamos espe-
  dificar para a GPU como manipular estes atributos, fazemos isto nos arquivos de shader.
  
  'Shaders'
    -Aqui podemos decidir por aplicação quais atributos cada vértice deve ter. OpenGL irá compilar seu programa a partir da fonte em tempo de 
    execução e copiá-lo para a placa gráfica.
    
      'Vertex Shader'
	 -É o programa na GPU que processa cada vértice e seus atributos como aparecem no vertex array.
	 -Seu dever é outputar a posição final dos vértices em coordenadas do dispositivo e outputar todos os dados que o fragment shader requerir.
    É por isso que transformações 3D devem acontecer aqui.
   -O fragment shader  depende dos atributos como coordenadas de cor e textura, que provavelmente será passado de input para output sem 
    qualquer cálculo.
   -GLSL foi construído com tipos vetoriais e matriciais identificados por vec* e mat * identificadores. O tipo dos valores dentro destas
    construções é sempre um flutuador.
   -vec de cor podem ser acessados com vec.r, vec.g, vec.b e vec.a em vez de vec.x, vec.y e vec.z.
   -A posição final do vértice é atribuído a variável especial 'gl_Position'.
   -Para ests funcionar corretamente, o último valor w necessita ter um valor de 1.0f.
  
      'Fragment Shader'  
  -A saída do vertex shader é interpolada sobre todos os pixels na tela coberta por uma primitiva. Estes pixels são chamados fragmentos e é 
   isso que o fragment shader opera. 
  -Assim como o vertex shader, ele também tem uma saída obrigatória, a cor final do fragmento.
  -Está por sua conta escrever o código para calcular esta cor do vértice de cores, coordenadas de textura e outros tipos de dados que vem 
   do vertex shader.
  -Perceba que não temos uma variável pronta para outputting de cor, como uma gl_FragColor. O motivo é porque o fragment shader pode de
   fato outputar váris cores.
  
      'Compilando Shaders'
  -Assim como vertex buffers, começa com a criação de um shader object e carregando dados para ele.
          'GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);' //compila vertex shader. No caso de fragmentShader = GL_FRAGMENT_SHADER
          'glShaderSource(vertexShader, 1, &vertexSource, NULL);'
          'glCompileShader(vertexShader);'
          checar se compilou direito 'GLint status;'  //se status for GL_TRUE
                                     'glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);' 
          para ver log da compilação 'char buffer[512];'
                                     'glGetShaderInfoLog(vertexShader, 512, NULL, buffer);'
 
  'Combinando shaders em um programa'
  -A conexão é feita criando-se um program dos dois shaders.  
            'GLuint shaderProgram = glCreateProgram();'
            'glAttachShader(shaderProgram, vertexShader);'
            'glAttachShader(shaderProgram, fragmentShader);'
  