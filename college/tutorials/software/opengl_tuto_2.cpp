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
  -A conexão é feita criando-se um programa dos dois shaders. Como foram programados para trabalhar juntos, a conexão é necessária.  
            'GLuint shaderProgram = glCreateProgram();'
            'glAttachShader(shaderProgram, vertexShader);'
            'glAttachShader(shaderProgram, fragmentShader);'
  -Desde que o fragment shader nos permite escrever para múltiplos buffers, você precisa explicitamente especificar que saída será escrita 
   em que buffer. Isto precisa ser feito antes de linkar o programa. Como isto é 0 por default e só tem uma saída, a linha que se segue não
   é necessária.
	    'glBindFragDataLocation(shaderProgram, 0, "outColor");'
	    
   -Use glDrawBuffers quando renderizar múltiplos buffers, pois apenas uma saída será criada por default.
   
      'Linkando o programa'
   -Depois de conectar ambos os shaders, a conexão é feita linkando o programa. É possível fazer mudanças nos shaders depois que foram adiciona-
    a um programa (ou múltiplos programas), mas o resultado atual não muda até que um programa seja linkado de novo.
   -Um objeto shader pode ser deletado com 'glDeleteShader', mas não será removido antes de ser desconectado de todos os programas com
    glDetachShader.
	    'glLinkProgram(shaderProgram);' //para começar a usar os shaders dentro do programa
	    'glUseProgram(shaderProgram);'  //assim como o vertex buffer, apenas um programa pode ser ativado por vez.
	    
      'Criando o link entre dados de vértice e atributos'
   -Embora tenhamos nossos dados de vértices e shaders agora, OpenGL ainda não sabe como os atributos são formatados e ordenados.
    Você primeiro precisa recuperar uma referência para a entrada 'position'  no vertex shader.
	    'GLint posAttrib = glGetAttribLocation(shaderProgram, "position");'
   -A localização é um número dependendo da ordem das definições de entrada. A primeira e única entrada position neste exemplo sempre terá
    localização 0.
   -Com a referência para a entrada, você pode especificar como os dados para aquela entrada são  recuperados do array.
	    'glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);'
		//posAttrib: referencia a entrada
		//2: especifica o número de valores para aquela entrada, que é o mesmo número de componentes de vec.
		//GL_FLOAT: tipo de cada componente.
		//GL_FALSE: especifica se os valores de entrada devem ser normalizados entre -1.0 e 1.0 se não forem nºs de ponto flutuante.
		//Os últimos dois especificam como os atributos são mandados embora dentro do vertex array.
		//stride: quantos bytes estão entre cada posição do atributo no array. 0 significa sem dados. Este é atualmente o caso 
		  //o caso já que a posição de cada vértice imediatamente seguida pela posiçao do próximo vértice.
  