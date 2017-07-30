 _____________________________________________________________________________________________
|Tipo de dado OpenGL		Representação interna	Tipo de dado C equivalente    Sufixo  |
|								              	              |
|GLbyte				8-bit integer		signed char		        b     |
|GLshort			16-bit integer		short			        s     |
|GLint, GLsizei			32-bit integer		int ou long		        i     |
|GLfloat, GLclampf		32-bit floating-point	float		                f     |
|GLdouble, GLclampd		64-bit floating-point	double			        d     |
|GLubyte, GLboolean		8-bit unsigned integer	unsigned char		        ub    |
|GLushort			16-bit unsigned integer	unsigned short		        us    |
|GLuint, GLenum, GLbitfield	32-bit unsigned integer	unsigned long ou unsigned int	ui    |
|_____________________________________________________________________________________________|

*funcao opengl
	<PrefixoBiblioteca> <ComandoRaiz> <ContadorArgumentosOpcional> <TipoArgumentosOpcional>
	ex: glColor3f();
	
*variáveis de estado
        habilitar modo=> glEnable();
        desabilitar modo=> glDisable();
        
*funções p/ saber valor da variável de estado(DEPENDE DO TIPO DE DADO):
        glGetBooleanv(); //obter value booleano
        glGetDoublev();
        glGetFloatv();
        glGetIntegerv();
        glGetPointerv();
        ou glIsEnabled() //pergunta se modo está habilitado(0 ou 1)
        
        ex:
        #         int luz;
        #         glEnable(GL_LIGHTING); 	//Habilita luz - GL_LIGHTING é a variável de estado
        #         luz = glIsEnabled(GL_LIGHTING); // retorna 1 (verdadeiro)
        #         glDisable(GL_LIGHTING); //Desabilita luz
        #         luz = glIsEnabled(GL_LIGHTING); // retorna 0 (falso)

        
PRIMEIRO PROGRAMA:
*O arquivo <GL/glut.h> contém os protótipos das funções utilizadas pelo programa. 
Ele também inclui os headers gl.h e glu.h que definem, respectivamente, as bibliotecas de funções OpenGL e GLU.

*glutInit(&argc, argv); //inicia GLUT

*glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //avisa a GLUT que tipo de modo de exibição deve ser usado quando a
janela é criada. Neste caso os argumentos indicam a criação de uma janela single-buffered (GLUT_SINGLE) com o modo
de cores RGBA (GLUT_RGB). O primeiro significa que todos os comandos de desenho são feitos na janela de exibição. 
Uma alternativa é uma janela double-buffered, onde os comandos de desenho são executados para criar uma cena fora da
tela para depois rapidamente colocá-la na view (ou janela de visualização). Este método é geralmente utilizado para 
produzir efeitos de animação. O modo de cores RGBA significa que as cores são especificadas através do fornecimento de
intensidades dos componentes red, green e blue separadas. 

*glutCreateWindow("Primeiro Programa"); //é o comando da biblioteca GLUT que cria a janela. Neste caso, é criada uma
janela com o nome "Primeiro Programa". Este argumento corresponde a legenda para a barra de título da janela. 

*glutDisplayFunc(Desenha); estabelece a função "Desenha" previamente definida como a função callback de exibição. 
Isto significa que a GLUT chama a função sempre que a janela precisar ser redesenhada. Esta chamada ocorre, por 
exemplo, quando a janela é redimensionada ou encoberta. É nesta função que se deve colocar as chamadas de funções 
OpenGL, por exemplo, para modelar e exibir um objeto. 

*Inicializa(); não é uma função OpenGL nem GLUT, é apenas uma convenção utilizada exemplos apresentados por [Wright 2000],
nos quais este tutorial está baseado. Nesta função são feitas as inicializações OpenGL que devem ser executadas antes do
rendering. Muitos estados OpenGL devem ser determinados somente uma vez e não a cada vez que a função ?Desenha? é chamada. 

*glutMainLoop(); é a função que faz com que comece a execução da ?máquina de estados? e processa todas as mensagens específicas
do sistema operacional, tais como teclas e botões do mouse pressionados, até que o programa termine. 

*glClearColor(0.0f, 0.0f, 1.0f, 1.0f); é a função que determina a cor utilizada para limpar a janela. Seu protótipo é: 
void glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alfa);. GLclampf é definido como um float na
maioria das implementações de OpenGL. O intervalo para cada componente red, green, blue é de 0 a 1. O componente alfa é 
usado para efeitos especiais, tal como transparência. 

*glClear(GL_COLOR_BUFFER_BIT); "limpa" um buffer particular ou combinações de buffers, onde buffer é uma área de armazenamento 
para informações da imagem. Os componentes RGB são geralmente referenciados como color buffer ou pixel buffer. Existem vários 
tipos de buffer, mas por enquanto só é necessário entender que o color buffer é onde a imagem é armazenada internamente e limpar 
o buffer com glClear remove o desenho da janela. 

*glFlush(); faz com que qualquer comando OpenGL não executado seja executado. Neste primeiro exemplo tem apenas a função glClear.

*glutInitWindowSize(400,350); especifica o tamanho em pixels da janela GLUT.

*glutInitWindowPosition(10,10); especifica a localização inicial da janela GLUT, que neste caso é o canto superior esquerdo da tela do computador

*glutReshapeFunc(AlteraTamanhoJanela); estabelece a função "AlteraTamanhoJanela" previamente definida como a função callback de alteração do tamanho da janela. Isto é,
sempre que a janela é maximizada, minimizada, etc., a função "AlteraTamanhoJanela" é executada para reinicializar o sistema de coordenadas.

*glColor3f(1.0f, 0.0f, 0.0f); determina a cor que será usada para o desenho (linhas e preenchimento). A seleção da cor é feita da mesma maneira que na função glClearColor,
sendo que não é necessário especificar o componente alfa, cujo valor default é 1.0 (completamente opaco).

*glBegin(GL_QUADS);? glEnd(); usada para desenhar um quadrado preenchido a partir dos vértices especificados entre glBegin e glEnd. O capítulo 9 descreve a utilização destas
funções. OpenGL mapeia as coordenadas dos vértices para a posição atual da janela de visualização na função callback ?AlteraTamanhoJanela?.
Antes de descrever os parâmetros e comandos da função ?AlteraTamanhoJanela?, é necessário revisar alguns conceitos e especificações. Em quase todos ambientes de janelas,
o usuário pode alterar o tamanho e dimensões da janela em qualquer momento. Quando isto ocorre, o conteúdo da janela é redesenhado levando em conta as novas dimensões.
Normalmente, o esperado é que a escala do desenho seja alterada de maneira que ele fique dentro da janela, independente do tamanho da janela de visualização ou do desenho.
Assim, uma janela pequena terá o desenho completo, mas pequeno, e uma janela grande terá o desenho completo e maior.
Apesar do exemplo mostrar um quadrado 2D, o desenho é feito em um espaço de coordenadas 3D. A função glBegin(GL_QUADS);? glEnd(); desenha o quadrado no plano
xy em z=0. Portanto, é necessário determinar o tamanho da viewport (janela onde será feito o desenho) e do volume de visualização (parte do universo da aplicação
que será mapeada para viewport), pois estes parâmetros influenciam o espaço de coordenadas e a escala do desenhos 2D e 3D na janela.
Sempre que o tamanho da janela é alterado, a viewport e o volume de visualização devem ser redefinidos de acordo com as novas dimensões da janela. Assim,
a aparência do desenho não é alterada (por exemplo, um quadrado não vira um retângulo). Como a alteração do tamanho da janela é detectada e gerenciada de 
maneira diferente em cada ambiente, a biblioteca GLUT fornece a função glutReshapeFunc, descrita anteriormente, que registra a função callback que a GLUT 
irá chamar sempre que houver esta alteração. A função passada para a glutReshapeFunc deve ter o seguinte protótipo: void AlteraTamanhoJanela(GLsizei w, 
GLsizei h);. O nome "AlteraTamanhoJanela" foi escolhido porque descreve o que a função faz. Os parâmetros recebidos sempre que o tamanho da janela é alterado 
são a sua nova largura e a sua nova altura, respectivamente. Esta informação é usada para modificar o mapeamento do sistema de coordenadas desejado para o 
sistema de coordenadas da tela com a ajuda de duas funções uma OpenGL, glViewport, e uma da biblioteca GLU, gluOrtho2D. Estas e outras funções chamadas na 
"AlteraTamanhoJanela", que definem como a viewport é especificada, são descritas a seguir.

*glViewport(0, 0, w, h); recebe como parâmetro a nova largura e altura da janela. O protótipo desta função é: 
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height);. Seus parâmetros especificam o canto inferior esquerdo da viewport (x,y) dentro da 
janela, e a sua largura e altura em pixels (width e height). Geralmente x e y são zero, mas é possível usar a viewport para visualizar mais de uma 
cena em diferentes áreas da janela. Em outras palavras, a viewport define a área dentro janela, em coordenadas de tela, que OpenGL pode usar para 
fazer o desenho. O volume de visualização é, então, mapeado para a nova viewport.

*gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f); é usada para determinar que a projeção ortográfica (2D) será utilizada para exibir na tela a imagem 2D que
está na janela de seleção definida através dos parâmetros passados para esta função. O protótipo desta função é: void gluOrtho2D(GLdouble left, GLdouble
right, GLdouble bottom, GLdouble top);. No sistema de coordenadas cartesianas, os valores left e right especificam os limites mínimo e máximo no eixo X;
analogamente, bottom e top especificam os limites mínimo e máximo no eixo Y.

*glMatrixMode(GL_PROJECTION); e glLoadIdentity(); servem, respectivamente, para avisar a OpenGL que todas as futuras alterações, tais como operações de escala,
rotação e translação, irão afetar a "câmera" (ou observador), e para inicializar o sistema de coordenadas antes da execução de qualquer operação de manipulação
de matrizes. Sem este comando, cada chamada sucessiva de gluOrtho2D poderia resultar em uma corrupção do volume de visualização. Em outras palavras, a matriz
de projeção é onde o volume de visualização, que neste caso é um plano, é definido; a função gluOrtho2D não estabelece realmente o volume de visualização utilizado
para fazer o recorte, apenas modifica o volume existente; ela multiplica a matriz que descreve o volume de visualização corrente pela matriz que descreve o novo 
volume de visualização, cujas coordenadas são recebidas por parâmetro.

*glMatrixMode(GL_MODELVIEW); avisa a OpenGL que todas as futuras alterações, tais como operações de escala, rotação e translação, irão afetar os modelos 
da cena, ou em outras palavras, o que é desenhado. A função glLoadIdentity(); chamada em seguida, faz com que a matriz corrente seja inicializada com 
a matriz identidade (nenhuma transformação é acumulada)

*glBegin()
glEnd() ; desenha algo na tela. É necessário passar uma lista de vértices, que deve ser feito entre glBegin() e glEnd();
O argumento passado para glBegin() determina qual objeto será desenhado.
            glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2i(100, 50);
	glVertex2i(100, 130);
	glVertex2i(150, 130);
	    glEnd();


Para desenhar outras primitivas, basta trocar GL_POINTS, que exibe um ponto para cada chamada ao comando glVertex, por:

    GL_LINES: exibe uma linha a cada dois comandos glVertex;

    GL_LINE_STRIP: exibe uma seqüência de linhas conectando os pontos definidos por glVertex;

    GL_LINE_LOOP: exibe uma seqüência de linhas conectando os pontos definidos por glVertex e ao final liga o primeiro como último ponto;

    GL_POLYGON: exibe um polígono convexo preenchido, definido por uma seqüência de chamadas a glVertex;

    GL_TRIANGLES: exibe um triângulo preenchido a cada três pontos definidos por glVertex;

    GL_TRIANGLE_STRIP: exibe uma seqüência de triângulos baseados no trio de vértices v0, v1, v2, depois, v2, v1, v3, depois, v2, v3, v4 e assim por diante;

    GL_TRIANGLE_FAN: exibe uma seqüência de triângulos conectados baseados no trio de vértices v0, v1, v2, depois, v0, v2, v3, depois, v0, v3, v4 e assim por diante;

    GL_QUADS: exibe um quadrado preenchido conectando cada quatro pontos definidos por glVertex;

    GL_QUAD_STRIP: exibe uma seqüência de quadriláteros conectados a cada quatro vértices; primeiro v0, v1, v3, v2, depois, v2, v3, v5, v4, depois, v4, v5, v7, v6, e assim por diante

*glVertex2i pertence à biblioteca GL e possui dois argumentos inteiros. De maneira análoga, conforme explicado no capítulo 4, também é possível passar valores de ponto flutuante
no lugar de inteiros, e três coordenadas (x,y,z) no lugar de duas usando, por exemplo, as seguintes chamadas às funções OpenGL:
glVertex2d(100.0, 50.0);
glVertex3f(50.0, 50.0, 50.0); Além disso, para cada vértice é possível definir uma cor diferente.

	Transformações
*glPushMatrix()
glPopMatrix() ; A cada transformação que é aplicada, esta matriz é alterada e usada para desenhar os objetos a partir daquele momento. A cada nova alteração é feita uma composição de matrizes. 
Para evitar este efeito "cumulativo", é necessário utilizar as funções glPushMatrix() e glPopMatrix(), que salvam e restauram, respectivamente, a matriz atual em uma pilha interna da OpenGL.

*glTranslatef; A translação é feita através da função glTranslatef(Tx, Ty, Tz), que pode receber três números float ou double (glTranslated) como parâmetro. Neste caso, a matriz atual é multiplicada 
por uma matriz de translação baseada nos valores dados.

*glRotatef; A rotação é feita através da função glRotatef(Ângulo, x, y, z), que pode receber quatro números float ou double (glRotated) como parâmetro. Neste caso, a matriz atual é multiplicada por 
uma matriz de rotação de "Ângulo" graus ao redor do eixo definido pelo vetor "x,y,z" no sentido anti-horário.

*glScalef(); A escala é feita através da função glScalef(Ex, Ey, Ez), que pode receber três números float ou double (glScaled) como parâmetro. Neste caso, a matriz atual é multiplicada por uma matriz 
de escala baseada nos valores dados.

*glutTimerFunc(33, Timer, 1); estabelece a função Timer previamente definida como a função callback de animação. Seu protótipo é: void glutTimerFunc(unsigned int msecs, void (*func)(int value), int value);. 
Esta função faz a GLUT esperar msecs milisegundos antes de chamar a função func. É possível passar um valor definido pelo usuário no parâmetro value. Como esta função é "disparada" apenas 
uma vez, para se ter uma animação contínua é necessário reinicializar o timer novamente na função Timer.

*void Timer(int value) é a função chamada pela glutTimerFunc. No exemplo, as variáveis utilizadas para determinar a posição do retângulo são atualizadas nesta função.

Antes de prosseguir com a descrição das funções, é necessário explicar o funcionamento do double-buffering, que é uma das características mais importantes em qualquer pacote gráfico que está 
disponível na GLUT. Double-buffering permite que um desenho seja exibido na tela enquanto está sendo realizado o rendering em um offscreen buffer. Então, um comando de swap coloca a imagem 
na tela instantaneamente. Isto é útil, principalmente, por dois motivos: 
- Alguns desenhos complexos podem levar um certo tempo para serem feitos, e não é desejado que cada passo da composição da imagem seja visível; então, é possível compor uma imagem e 
exibi-la somente depois de completa, de maneira que o usuário nunca vê uma imagem parcial, pois ela é exibida somente quando está pronta. 
- No caso de uma animação, cada quadro (ou frame) é desenhado no offscreen buffer e é exibido (swapped) rapidamente depois de pronto.

*glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB), já explicada anteriormente, foi usada para trocar o modo de exibição de GLUT_SINGLE para GLUT_DOUBLE. Isto faz com que todo o rendering 
seja feito em um offscreen buffer.

*glutSwapBuffers(); é usada no lugar da glFlush porque quando é feita a troca (ou swap) de buffers, é realizada implicitamente uma operação de flush. Esta função continua fazendo o flush mesmo que 
o programa esteja sendo executado no modo single-buffer, porém com uma qualidade bastante inferior.

GERENCIAMENTO DE EVENTOS
*glutKeyboardFunc 
	Estabelece a função callback que é chamada pela GLUT cada vez que uma tecla que gera código ASCII é pressionada (por exemplo: a, b, A, b, 1, 2). Além do valor ASCII da tecla, a posição 
(x,y) do mouse quando a tecla foi pressionada também é retornada. Parâmetros de entrada da função callback: (unsigned char key, int x, int y).

*glutSpecialFunc 
	Estabelece a função callback que é chamada pela GLUT cada vez que uma tecla que gera código não-ASCII é pressionada, tais como Home, End, PgUp, PgDn, F1 e F2. Além da constante 
que identifica a tecla, a posição corrente (x,y) do mouse quando a tecla foi pressionada também é retornada. Parâmetros de entrada da função callback: (unsigned char key, int x, int y). Os valores válidos 
para o primeiro parâmetro são: GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, 
GLUT_KEY_F11, GLUT_KEY_F12, GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE_UP, GLUT_KEY_PAGE_DOWN, GLUT_KEY_HOME, GLUT_KEY_END, 
GLUT_KEY_INSERT.

*glutMouseFunc 
	Estabelece a função callback que é chamada pela GLUT cada vez que ocorre um evento de mouse. Parâmetros de entrada da função callback: (int button, int state, int x, int y). Três valores são válidos 
para o parâmetro button: GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON e GLUT_RIGHT_BUTTON. O parâmetro state pode ser GLUT_UP ou GLUT_DOWN. Os parâmetros x e y indicam a localização do 
mouse no momento que o evento ocorreu.

UTILIZANDO MENUS E EXIBINDO CARACTERES
*glutBitmapCharacter 
	Uma das fontes suportadas pela GLUT é a bitmap, onde cada caracter corresponde a um bitmap que é gerado com a função glBitmap. A função glutBitmapCharacter exibe um caracter deste tipo usando 
OpenGL. Os parâmetros de entrada desta função são: (void *font, int character). O primeiro parâmetro identifica a fonte que será utilizada, e o segundo o caracter. As fontes disponíveis são: GLUT_BITMAP_8_BY_13, 
GLUT_BITMAP_9_BY_15, GLUT_BITMAP_TIMES_ROMAN_10, GLUT_BITMAP_TIMES_ROMAN_24, GLUT_BITMAP_HELVETICA_10, GLUT_BITMAP_HELVETICA_12, GLUT_BITMAP_HELVETICA_18

*glutMotionFunc 
Estabelece a função callback que é chamada pela GLUT cada vez que o mouse é movido sobre a janela corrente enquanto um ou mais de seus botões estão pressionados. Parâmetros de entrada da função 
callback: (int x, int y). Os parâmetros x e y indicam a posição do mouse em coordenadas da janela.

*glutPassiveMotionFunc 
Estabelece a função callback que é chamada pela GLUT cada vez que o mouse é movido sobre a janela corrente enquanto nenhum de seus botões está pressionado. Parâmetros de entrada da função 
callback: (int x, int y). Os parâmetros x e y indicam a posição do mouse em coordenadas da janela.

*glutCreateMenu 
Cria um novo menu pop-up e estabelece a função callback que será chamada pela GLUT quando uma de suas entradas for selecionada. Parâmetros de entrada da função callback: (int value), onde value 
corresponde ao valor que identifica a entrada do menu que foi selecionada.

*glutAddMenuEntry 
Adiciona uma entrada no final do menu corrente. Os parâmetros de entrada desta função são: (char *name, int value), onde name é o conjunto de caracteres que será exibido como uma entrada do menu, 
e value é o valor que será passado para a função callback caso esta entrada seja selecionada.

*glutAddSubMenu 
Adiciona um submenu no final do menu corrente. Os parâmetros de entrada desta função são: (char *name, int menu), onde name é o conjunto de caracteres que será exibido como uma entrada do menu, 
a partir da qual será aberto o submenu, e menu é o identificador do submenu.

*glutAttachMenu 
Função que "relaciona" um botão do mouse com o identificador do menu corrente. O parâmetro de entrada desta função é (int button), que corresponde ao identificador do botão do mouse 
(GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON ou GLUT_RIGHT_BUTTON).

DESENHANDO EM 3D

 **Arrumar o tripé e posicionar a câmera para fotografar a cena - equivalente a especificar as transformações de visualização (veja a função gluLookAt descrita mais abaixo);

 **Arrumar a cena para ser fotografada, incluindo ou excluindo objetos/pessoas - equivalente à etapa de modelagem (inclui as tranformações geométricas, glTranslatef, glScalef, glRotatef, e o desenho dos objetos);

 **Escolher a lente da câmera ou ajustar o zoom - equivalente a especificar as transformações de projeção (veja a função gluPerspective descrita mais abaixo);

 **Determinar o tamanho final da foto (maior ou menor) - equivalente a especificar a viewport (funções glViewport e ChangeSize).

*gluPerspective(angle,fAspect,0.1,500);Esta função estabelece os parâmetros da Projeção Perspectiva, atualizando a matriz de projeção perspectiva. Seu protótipo é:
void gluPerspective( GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar );. Descrição dos parâmetros: fovy é o ângulo, em graus, na direção y (usada para determinar a "altura" do volume 
de visualização); aspect é a razão de aspecto que determina a área de visualização na direção x, e seu valor é a razão em x (largura) e y (altura); zNear, que sempre deve ter um valor positivo maior do 
que zero, é a distância do observador até o plano de corte mais próximo (em z); zFar, que também sempre tem um valor positivo maior do que zero, é a distância do observador até o plano de corte 
mais afastado (em z). Esta função sempre deve ser definida ANTES da função gluLookAt, e no modo GL_PROJECTION.

*gluLookAt(0,80,200, 0,0,0, 0,1,0); define a transformação de visualização. Através dos seus argumentos é possível indicar a posição da câmera e para onde ela está direcionada. Seu protótipo é: 
void gluLookAt( GLdouble eyex, GLdouble eyey, GLdouble eyez, GLdouble centerx, GLdouble centery, GLdouble centerz, GLdouble upx, GLdouble upy, GLdouble upz );. Descrição dos parâmetros: 
eyex, eyey e eyez são usados para definir as coordenadas x, y e z, respectivamente, da posição da câmera (ou observador); centerx, centery e centerz são usados para definir as coordenadas x, y e z, 
respectivamente, da posição do alvo, isto é, para onde o observador está olhando (normalmente, o centro da cena); upx, upy e upz são as coordenadas x, y e z, que estabelecem o vetor up 
(indica o "lado de cima" de uma cena 3D) 

*glutWireTeapot(50.0f); é usada para desenhar o wire-frame de um teapot (ou bule de chá). Seu protótipo é: 
glutWireTeapot(GLdoouble size);, onde o parâmetro size indica um raio aproximado do teapot. Uma esfera com este raio irá "envolver" totalmente o modelo


Assim como o teapot, a biblioteca GLUT também possui funções para desenhar outros objetos 3D. Estas funções estão listadas abaixo [Woo 1999]: 
- void glutWireCube(GLdouble size); 
- void glutWireSphere(GLdouble radius, GLint slices, GLint stacks); 
- void glutWireCone(GLdouble radius, GLdouble height, GLint slices, GLint stacks); 
- void glutWireTorus(GLdouble innerRadius, GLdouble outerRadius, GLint nsides, GLint rings); 
- void glutWireIcosahedron(void); 
- void glutWireOctahedron(void); 
- void glutWireTetrahedron(void); 
- void glutWireDodecahedron(GLdouble radius); 

*obs* Os parâmetros slices e stacks que aparecem no protótipo de algumas funções, significam, respectivamente, o número de subdivisões em torno do eixo z (como se fossem linhas longitudinais) 
e o número de subdivisões ao longo do eixo z (como se fossem linhas latitudinais). Já rings e nsides correspondem, respectivamente, ao número de seções que serão usadas para formar o torus, 
e ao número de subdivisões para cada seção.
*obs* Todas estas funções também podem ser usadas para desenhar objetos sólidos, ao invés de exibir apenas o seu wire-frame. Para isto, basta substituir a substring Wire do nome da função por Solid.

*glShadeModel(); é usada para especificar a técnica de colorização desejada. Inicialmente, é preciso definir o modelo de colorização que será utilizado. OpenGL fornece dois modelos: uma polígono 
preenchido pode ser desenhado com uma única cor (GL_FLAT), ou com uma variação de tonalidades (GL_SMOOTH, também chamado de modelo de colorização de Gouraud.

*obs* Quando objetos 3D sólidos são exibidos, é importante desenhar os objetos que estão mais próximos do observador (ou posição da câmera), eliminando objetos que ficam "escondidos", 
ou "parcialmente escondidos", por estes. Sendo assim,algoritmos de remoção de elementos escondidos foram desenvolvidos para determinar as linhas, arestas, superfícies ou volumes que 
são visíveis ou não para um observador localizado em um ponto específico no espaço. A complexidade do problema dos elementos ocultos resultou em um grande número de soluções na Computação Gráfica.
 OpenGL possui um depth buffer que trabalha através da associação de uma profundidade, ou distância, do plano de visualização (geralmente o plano de corte mais próximo do observador) com cada pixel 
da window. Inicialmente, os valores de profundidade são especificados para serem o maior possível através do comando glClear(GL_DEPTH_BUFFER_BIT). Entretanto, habilitando o depth-buffering 
através dos comandos glutInitDisplayMode(GLUT_DEPTH | ...) e glEnable(GL_DEPTH_TEST), antes de cada pixel ser desenhado é feita uma comparação com o valor de profundidade já armazenado. 
Se o valor de profundidade for menor (está mais próximo) o pixel é desenhado e o valor de profundidade é atualizado. Caso contrário as informações do pixel são desprezadas.Em OpenGL a cor de uma fonte 
de luz é caracterizada pela quantidade de vermelho (R), verde (G) e azul (B) que ela emite, e o material de uma superfície é caracterizado pela porcentagem dos componentes R, G e B que chegam 
e são refletidos em várias direções. No modelo de iluminação a luz em uma cena vem de várias fontes de luz que podem ser "ligadas" ou "desligadas" individualmente. A luz pode vir de uma direção ou 
posição (por exemplo, uma lâmpada) ou como resultado de várias reflexões (luz ambiente - não é possível determinar de onde ela vem, mas ela desaparece quando a fonte de luz é desligada).No modelo de iluminação OpenGL a fonte de luz tem efeito somente 
quando existem superfícies que absorvem e refletem luz. Assume-se que cada superfície é composta de um material com várias propriedades. O material pode emitir luz, refletir parte da luz incidente em todas as 
direções, ou refletir uma parte da luz incidente numa única direção, tal com um espelho. Então, OpenGL considera que a luz é dividida em quatro componentes independentes (que são colocadas juntas):
		*Ambiente: resultado da luz refletida no ambiente; é uma luz que vem de todas as direções;
		*Difusa: luz que vem de uma direção, atinge a superfície e é refletida em todas as direções; assim, parece possuir o mesmo brilho independente de onde a câmera está posicionada;
		*Especular: luz que vem de uma direção e tende a ser refletida numa única direção;
		*Emissiva: simula a luz que se origina de um objeto; a cor emissiva de uma superfície adiciona intensidade ao objeto, mas não é afetada por qualquer fonte de luz; 
			ela também não introduz luz adicional da cena.
A cor do material de um objeto depende da porcentagem de luz vermelha, verde e azul incidente que ele reflete. Assim como as luzes, o material possui cor ambiente, difusa e especular diferentes, que 
determinam como será a luz refletida. Isto é combinado com as propriedades das fontes de luz, de tal maneira que a reflexão ambiente e difusa definem a cor do material. A especular é geralmente cinza ou branca.
Os componentes de cor especificados para a luz possuem um significado diferente dos componentes de cor especificados para os materiais. Para a luz, os números correspondem a uma porcentagem da 
intensidade total para cada cor. Se os valores R, G e B para a cor da luz são 1, a luz é branca com o maior brilho possível. Se os valores são 0.5 a cor ainda é branca, mas possui metade da intensidade, 
por isso parece cinza. Se R=G=1 e B=0, a luz parece amarela.Para os materiais, os números correspondem às proporções refletidas destas cores. Se R=1, G=0.5 e B=0 para um material, este material reflete 
toda luz vermelha incidente, metade da luz verde e nada da luz azul. Assim, simplificadamente, a luz que chega no observador é dada por (LR.MR, LG.MG, LB.MB), onde (LR, LG, LB) são os componentes da luz 
e (MR, MG, MB) os componentes do material.

*glShadeModel(GL_SMOOTH); estabelece o modelo de colorização: GL_FLAT (a cor não varia na primitiva que é desenhada - um exemplo de primitiva é o triângulo); ou GL_SMOOTH (a cor de cada ponto da 
primitiva é interpolada a partir da cor calculada nos vértices). Seu protótipo é: void glShadeModel(GLenum mode);. Descrição dos parâmetros: mode especifica o modelo de colorização, sendo que o default 
é GL_SMOOTH.

*glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade); estabelece os parâmetros do material que serão usados pelo modelo de iluminação. Possui algumas variações cujos protótipos são: 
*glMaterialf(GLenum face, GLenum pname, GLfloat param); 
*glMateriali(GLenum face, GLenum pname, GLint param); 
*glMaterialfv(GLenum face, GLenum pname, const GLfloat *params); 
*glMaterialiv(GLenum face, GLenum pname, const GLint *params); 
Descrição dos parâmetros: 
-face determina se as propriedades do material dos polígonos que estão sendo especificadas são front (GL_FRONT), back (GL_BACK) ou ambas (GL_FRONT_AND_BACK); 
-pname para as duas primeiras variações especifica o parâmetro de um único valor que está sendo determinado (atualmente apenas GL_SHININESS possui um único valor como parâmetro); para as duas 
últimas variações, que recebem um vetor como parâmetro, pode determinar as seguintes propriedades do material: GL_AMBIENT, GL_DIFFUSE, GL_SPECULAR, GL_EMISSION, GL_SHININESS, 
GL_AMBIENT_AND_DIFFUSE ou GL_COLOR_INDEXES; 
-param (GLfloat ou GLint) especifica o valor que será atribuído para o parâmetro determinado por pname (neste caso, GL_SHININESS); 
-params (GLfloat* ou GLint*) um vetor de números reais ou inteiros que contém as componentes da propriedade que está sendo espeficada; 
Através desta função é possível determinar as propriedades de refletância do material dos polígonos. As propriedades GL_AMBIENT, GL_DIFFUSE e GL_SPECULAR afetam a maneira na qual as 
componentes de luz incidente são refletidas. GL_EMISSION é usado para materiais que possuem "luz própria". GL_SHININESS pode variar de 0 a 128 (quanto maior o valor, maior é a área de 
highlight especular na superfície). GL_COLOR_INDEXES é usado para as propriedades de refletância do material no modo de índice de cores.

*glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente); estabelece os parâmetros do modelo de iluminação usado por OpenGL. É possível especificar um, ou todos os três modelos: 
- GL_LIGHT_MODEL_AMBIENT é usado para especificar a luz ambiente default para uma cena, que tem um valor RGBA default de (0.2, 0.2, 0.2, 1.0); 
- GL_LIGHT_MODEL_TWO_SIDE é usado para indicar se ambos os lados de um polígono são iluminados (por default apenas o lado frontal é iluminado); 
- GL_LIGHT_MODEL_LOCAL_VIEWER modifica o cálculo dos ângulos de reflexão especular; 
Possui algumas variações cujos protótipos são: 
*glLightModelf(GLenum pname, GLfloat param); 
*glLightModeli(GLenum pname, GLint param); 
*glLightModelfv(GLenum pname, const GLfloat *params); 
*glLightModeliv(GLenum pname, const GLint *params); 
Descrição dos parâmetros: 
-pname especifica um parâmetro do modelo de iluminação: GL_LIGHT_MODEL_AMBIENT, GL_LIGHT_MODEL_LOCAL_VIEWER ou GL_LIGHT_MODEL_TWO_SIDE; 
-param (GLfloat ou GLint) para GL_LIGHT_MODEL_LOCAL_VIEWER um valor 0.0 indica que os ângulos da componente especular tomam a direção de visualização como sendo paralela ao eixo z, 
e qualquer outro valor indica que a visualização ocorre a partir da origem do sistema de referência da câmera; para GL_LIGHT_MODEL_TWO_SIDE um valor 0.0 indica que somente os polígonos 
frontais são incluídos nos cálculos de iluminação, e qualquer outro valor indica que todos os polígonos são incluídos nos cálculos de iluminação; 
-params (GLfloat* ou GLint*) para GL_LIGHT_MODEL_AMBIENT ou GL_LIGHT_MODEL_LOCAL_VIEWER, aponta para um vetor de números inteiros ou reais; para GL_LIGHT_MODEL_AMBIENT o 
conteúdo do vetor indica os valores das componentes RGBA da luz ambiente.

*glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); estabelece os parâmetros da fonte de luz para uma das oito fontes de luz disponíveis. Possui algumas variações cujos protótipos são: 
*glLightf(GLenum light, GLenum pname, GLfloat param); 
*glLighti(GLenum light, GLenum pname, GLint param); 
*glLightfv(GLenum light, GLenum pname, const GLfloat *params); 
*glLightiv(GLenum light, GLenum pname, const GLint *params); 
As duas primeiras variações requerem apenas um único valor para determinar uma das seguintes propriedades: GL_SPOT_EXPONENT, GL_SPOT_CUTOFF, GL_CONSTANT_ATTENUATION, 
GL_LINEAR_ATTENUATION e GL_QUADRATIC_ATTENUATION. As duas últimas variações são usadas para parâmetros de luz que requerem um vetor com múltiplos valores (GL_AMBIENT, GL_DIFFUSE, 
GL_SPECULAR, GL_POSITION e GL_SPOT_DIRECTION). 
Descrição dos parâmetros: 
-light especifica qual fonte de luz está sendo alterada (varia de 0 a GL_MAX_LIGHTS); valores constantes de luz são enumerados de GL_LIGHT0 a GL_LIGHT7 
-pname especifica qual parâmetro de luz está sendo determinado pela chamada desta função (GL_AMBIENT, GL_DIFFUSE, GL_SPECULAR, GL_POSITION, GL_SPOT_DIRECTION, GL_SPOT_EXPONENT, 
GL_SPOT_CUTOFF. GL_CONSTANT_ATTENUATION, GL_LINEAR_ATTENUATION, GL_QUADRATIC_ATTENUATION); 
-param (GLfloat ou GLint) para parâmetros que são especificados por um único valor (param); estes parâmetros, válidos somente para spotlights, são GL_SPOT_EXPONENT, GL_SPOT_CUTOFF, 
GL_CONSTANT_ATTENUATION, GL_LINEAR_ATTENUATION e GL_QUADRATIC_ATTENUATION. 
-params (GLfloat* ou GLint*) um vetor de valores que descrevem os parâmetros que estão sendo especificados.

*glEnable(GL_COLOR_MATERIAL); conforme já explicado no capítulo 6, a função glEnable é usada para habilitar uma variável de estado OpenGL. Neste caso, estão sendo habilitadas: GL_COLOR_MATERIAL 
(atribui a cor para o material a partir da cor corrente), GL_DEPTH_TEST (controla as comparações de profundidade e atualiza o depth buffer), GL_LIGHTING (habilita a iluminação) e GL_LIGHT0
 (habilita a luz de número 0).

*glutSwapBuffers(); e glutInitDisplayMode(GLUT_DOUBLE...); já explicadas anteriormente, são usadas para evitar que a imagem fique "piscando" a cada interação (por exemplo, quando se faz zoom-in e zoom-out).

*obs* Também é possível eliminar o "brilho" do objeto, como se o material fosse opaco. Neste caso, basta eliminar a componente especular removendo as seguintes linhas do código fonte: 
     GLfloat especularidade[4]={1.0,1.0,1.0,1.0}; 
     GLint especMaterial = 60; 
     glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade); 
     glMateriali(GL_FRONT,GL_SHININESS,especMaterial); 
     glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );

*obs*Quando se trabalha com uma malha, normalmente são passadas como argumento para a função glBegin() as primitivas GL_QUADS, GL_POLYGON e GL_TRIANGLES (capítulo 9). 
GL_TRIANGLE_STRIP e GL_QUAD_STRIP também podem ser usadas, desde que se tenha certeza de que os vértices e faces estão ordenados da maneira correta.
Conforme se observa no código acima, é necessário informar o vetor normal normal de cada face, pois OpenGL usa esta informação para calcular a cor de cada face de acordo com os 
parâmetros de iluminação. A função usada para especificar o vetor normal é glNormal3f, e os seus parâmetros são as componentes x, y e z do vetor normal, respectivamente.













