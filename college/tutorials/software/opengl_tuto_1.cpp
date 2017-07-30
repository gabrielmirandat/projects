 _____________________________________________________________________________________________
|Tipo de dado OpenGL		Representa��o interna	Tipo de dado C equivalente    Sufixo  |
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
	
*vari�veis de estado
        habilitar modo=> glEnable();
        desabilitar modo=> glDisable();
        
*fun��es p/ saber valor da vari�vel de estado(DEPENDE DO TIPO DE DADO):
        glGetBooleanv(); //obter value booleano
        glGetDoublev();
        glGetFloatv();
        glGetIntegerv();
        glGetPointerv();
        ou glIsEnabled() //pergunta se modo est� habilitado(0 ou 1)
        
        ex:
        #         int luz;
        #         glEnable(GL_LIGHTING); 	//Habilita luz - GL_LIGHTING � a vari�vel de estado
        #         luz = glIsEnabled(GL_LIGHTING); // retorna 1 (verdadeiro)
        #         glDisable(GL_LIGHTING); //Desabilita luz
        #         luz = glIsEnabled(GL_LIGHTING); // retorna 0 (falso)

        
PRIMEIRO PROGRAMA:
*O arquivo <GL/glut.h> cont�m os prot�tipos das fun��es utilizadas pelo programa. 
Ele tamb�m inclui os headers gl.h e glu.h que definem, respectivamente, as bibliotecas de fun��es OpenGL e GLU.

*glutInit(&argc, argv); //inicia GLUT

*glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //avisa a GLUT que tipo de modo de exibi��o deve ser usado quando a
janela � criada. Neste caso os argumentos indicam a cria��o de uma janela single-buffered (GLUT_SINGLE) com o modo
de cores RGBA (GLUT_RGB). O primeiro significa que todos os comandos de desenho s�o feitos na janela de exibi��o. 
Uma alternativa � uma janela double-buffered, onde os comandos de desenho s�o executados para criar uma cena fora da
tela para depois rapidamente coloc�-la na view (ou janela de visualiza��o). Este m�todo � geralmente utilizado para 
produzir efeitos de anima��o. O modo de cores RGBA significa que as cores s�o especificadas atrav�s do fornecimento de
intensidades dos componentes red, green e blue separadas. 

*glutCreateWindow("Primeiro Programa"); //� o comando da biblioteca GLUT que cria a janela. Neste caso, � criada uma
janela com o nome "Primeiro Programa". Este argumento corresponde a legenda para a barra de t�tulo da janela. 

*glutDisplayFunc(Desenha); estabelece a fun��o "Desenha" previamente definida como a fun��o callback de exibi��o. 
Isto significa que a GLUT chama a fun��o sempre que a janela precisar ser redesenhada. Esta chamada ocorre, por 
exemplo, quando a janela � redimensionada ou encoberta. � nesta fun��o que se deve colocar as chamadas de fun��es 
OpenGL, por exemplo, para modelar e exibir um objeto. 

*Inicializa(); n�o � uma fun��o OpenGL nem GLUT, � apenas uma conven��o utilizada exemplos apresentados por [Wright 2000],
nos quais este tutorial est� baseado. Nesta fun��o s�o feitas as inicializa��es OpenGL que devem ser executadas antes do
rendering. Muitos estados OpenGL devem ser determinados somente uma vez e n�o a cada vez que a fun��o ?Desenha? � chamada. 

*glutMainLoop(); � a fun��o que faz com que comece a execu��o da ?m�quina de estados? e processa todas as mensagens espec�ficas
do sistema operacional, tais como teclas e bot�es do mouse pressionados, at� que o programa termine. 

*glClearColor(0.0f, 0.0f, 1.0f, 1.0f); � a fun��o que determina a cor utilizada para limpar a janela. Seu prot�tipo �: 
void glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alfa);. GLclampf � definido como um float na
maioria das implementa��es de OpenGL. O intervalo para cada componente red, green, blue � de 0 a 1. O componente alfa � 
usado para efeitos especiais, tal como transpar�ncia. 

*glClear(GL_COLOR_BUFFER_BIT); "limpa" um buffer particular ou combina��es de buffers, onde buffer � uma �rea de armazenamento 
para informa��es da imagem. Os componentes RGB s�o geralmente referenciados como color buffer ou pixel buffer. Existem v�rios 
tipos de buffer, mas por enquanto s� � necess�rio entender que o color buffer � onde a imagem � armazenada internamente e limpar 
o buffer com glClear remove o desenho da janela. 

*glFlush(); faz com que qualquer comando OpenGL n�o executado seja executado. Neste primeiro exemplo tem apenas a fun��o glClear.

*glutInitWindowSize(400,350); especifica o tamanho em pixels da janela GLUT.

*glutInitWindowPosition(10,10); especifica a localiza��o inicial da janela GLUT, que neste caso � o canto superior esquerdo da tela do computador

*glutReshapeFunc(AlteraTamanhoJanela); estabelece a fun��o "AlteraTamanhoJanela" previamente definida como a fun��o callback de altera��o do tamanho da janela. Isto �,
sempre que a janela � maximizada, minimizada, etc., a fun��o "AlteraTamanhoJanela" � executada para reinicializar o sistema de coordenadas.

*glColor3f(1.0f, 0.0f, 0.0f); determina a cor que ser� usada para o desenho (linhas e preenchimento). A sele��o da cor � feita da mesma maneira que na fun��o glClearColor,
sendo que n�o � necess�rio especificar o componente alfa, cujo valor default � 1.0 (completamente opaco).

*glBegin(GL_QUADS);? glEnd(); usada para desenhar um quadrado preenchido a partir dos v�rtices especificados entre glBegin e glEnd. O cap�tulo 9 descreve a utiliza��o destas
fun��es. OpenGL mapeia as coordenadas dos v�rtices para a posi��o atual da janela de visualiza��o na fun��o callback ?AlteraTamanhoJanela?.
Antes de descrever os par�metros e comandos da fun��o ?AlteraTamanhoJanela?, � necess�rio revisar alguns conceitos e especifica��es. Em quase todos ambientes de janelas,
o usu�rio pode alterar o tamanho e dimens�es da janela em qualquer momento. Quando isto ocorre, o conte�do da janela � redesenhado levando em conta as novas dimens�es.
Normalmente, o esperado � que a escala do desenho seja alterada de maneira que ele fique dentro da janela, independente do tamanho da janela de visualiza��o ou do desenho.
Assim, uma janela pequena ter� o desenho completo, mas pequeno, e uma janela grande ter� o desenho completo e maior.
Apesar do exemplo mostrar um quadrado 2D, o desenho � feito em um espa�o de coordenadas 3D. A fun��o glBegin(GL_QUADS);? glEnd(); desenha o quadrado no plano
xy em z=0. Portanto, � necess�rio determinar o tamanho da viewport (janela onde ser� feito o desenho) e do volume de visualiza��o (parte do universo da aplica��o
que ser� mapeada para viewport), pois estes par�metros influenciam o espa�o de coordenadas e a escala do desenhos 2D e 3D na janela.
Sempre que o tamanho da janela � alterado, a viewport e o volume de visualiza��o devem ser redefinidos de acordo com as novas dimens�es da janela. Assim,
a apar�ncia do desenho n�o � alterada (por exemplo, um quadrado n�o vira um ret�ngulo). Como a altera��o do tamanho da janela � detectada e gerenciada de 
maneira diferente em cada ambiente, a biblioteca GLUT fornece a fun��o glutReshapeFunc, descrita anteriormente, que registra a fun��o callback que a GLUT 
ir� chamar sempre que houver esta altera��o. A fun��o passada para a glutReshapeFunc deve ter o seguinte prot�tipo: void AlteraTamanhoJanela(GLsizei w, 
GLsizei h);. O nome "AlteraTamanhoJanela" foi escolhido porque descreve o que a fun��o faz. Os par�metros recebidos sempre que o tamanho da janela � alterado 
s�o a sua nova largura e a sua nova altura, respectivamente. Esta informa��o � usada para modificar o mapeamento do sistema de coordenadas desejado para o 
sistema de coordenadas da tela com a ajuda de duas fun��es uma OpenGL, glViewport, e uma da biblioteca GLU, gluOrtho2D. Estas e outras fun��es chamadas na 
"AlteraTamanhoJanela", que definem como a viewport � especificada, s�o descritas a seguir.

*glViewport(0, 0, w, h); recebe como par�metro a nova largura e altura da janela. O prot�tipo desta fun��o �: 
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height);. Seus par�metros especificam o canto inferior esquerdo da viewport (x,y) dentro da 
janela, e a sua largura e altura em pixels (width e height). Geralmente x e y s�o zero, mas � poss�vel usar a viewport para visualizar mais de uma 
cena em diferentes �reas da janela. Em outras palavras, a viewport define a �rea dentro janela, em coordenadas de tela, que OpenGL pode usar para 
fazer o desenho. O volume de visualiza��o �, ent�o, mapeado para a nova viewport.

*gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f); � usada para determinar que a proje��o ortogr�fica (2D) ser� utilizada para exibir na tela a imagem 2D que
est� na janela de sele��o definida atrav�s dos par�metros passados para esta fun��o. O prot�tipo desta fun��o �: void gluOrtho2D(GLdouble left, GLdouble
right, GLdouble bottom, GLdouble top);. No sistema de coordenadas cartesianas, os valores left e right especificam os limites m�nimo e m�ximo no eixo X;
analogamente, bottom e top especificam os limites m�nimo e m�ximo no eixo Y.

*glMatrixMode(GL_PROJECTION); e glLoadIdentity(); servem, respectivamente, para avisar a OpenGL que todas as futuras altera��es, tais como opera��es de escala,
rota��o e transla��o, ir�o afetar a "c�mera" (ou observador), e para inicializar o sistema de coordenadas antes da execu��o de qualquer opera��o de manipula��o
de matrizes. Sem este comando, cada chamada sucessiva de gluOrtho2D poderia resultar em uma corrup��o do volume de visualiza��o. Em outras palavras, a matriz
de proje��o � onde o volume de visualiza��o, que neste caso � um plano, � definido; a fun��o gluOrtho2D n�o estabelece realmente o volume de visualiza��o utilizado
para fazer o recorte, apenas modifica o volume existente; ela multiplica a matriz que descreve o volume de visualiza��o corrente pela matriz que descreve o novo 
volume de visualiza��o, cujas coordenadas s�o recebidas por par�metro.

*glMatrixMode(GL_MODELVIEW); avisa a OpenGL que todas as futuras altera��es, tais como opera��es de escala, rota��o e transla��o, ir�o afetar os modelos 
da cena, ou em outras palavras, o que � desenhado. A fun��o glLoadIdentity(); chamada em seguida, faz com que a matriz corrente seja inicializada com 
a matriz identidade (nenhuma transforma��o � acumulada)

*glBegin()
glEnd() ; desenha algo na tela. � necess�rio passar uma lista de v�rtices, que deve ser feito entre glBegin() e glEnd();
O argumento passado para glBegin() determina qual objeto ser� desenhado.
            glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2i(100, 50);
	glVertex2i(100, 130);
	glVertex2i(150, 130);
	    glEnd();


Para desenhar outras primitivas, basta trocar GL_POINTS, que exibe um ponto para cada chamada ao comando glVertex, por:

    GL_LINES: exibe uma linha a cada dois comandos glVertex;

    GL_LINE_STRIP: exibe uma seq��ncia de linhas conectando os pontos definidos por glVertex;

    GL_LINE_LOOP: exibe uma seq��ncia de linhas conectando os pontos definidos por glVertex e ao final liga o primeiro como �ltimo ponto;

    GL_POLYGON: exibe um pol�gono convexo preenchido, definido por uma seq��ncia de chamadas a glVertex;

    GL_TRIANGLES: exibe um tri�ngulo preenchido a cada tr�s pontos definidos por glVertex;

    GL_TRIANGLE_STRIP: exibe uma seq��ncia de tri�ngulos baseados no trio de v�rtices v0, v1, v2, depois, v2, v1, v3, depois, v2, v3, v4 e assim por diante;

    GL_TRIANGLE_FAN: exibe uma seq��ncia de tri�ngulos conectados baseados no trio de v�rtices v0, v1, v2, depois, v0, v2, v3, depois, v0, v3, v4 e assim por diante;

    GL_QUADS: exibe um quadrado preenchido conectando cada quatro pontos definidos por glVertex;

    GL_QUAD_STRIP: exibe uma seq��ncia de quadril�teros conectados a cada quatro v�rtices; primeiro v0, v1, v3, v2, depois, v2, v3, v5, v4, depois, v4, v5, v7, v6, e assim por diante

*glVertex2i pertence � biblioteca GL e possui dois argumentos inteiros. De maneira an�loga, conforme explicado no cap�tulo 4, tamb�m � poss�vel passar valores de ponto flutuante
no lugar de inteiros, e tr�s coordenadas (x,y,z) no lugar de duas usando, por exemplo, as seguintes chamadas �s fun��es OpenGL:
glVertex2d(100.0, 50.0);
glVertex3f(50.0, 50.0, 50.0); Al�m disso, para cada v�rtice � poss�vel definir uma cor diferente.

	Transforma��es
*glPushMatrix()
glPopMatrix() ; A cada transforma��o que � aplicada, esta matriz � alterada e usada para desenhar os objetos a partir daquele momento. A cada nova altera��o � feita uma composi��o de matrizes. 
Para evitar este efeito "cumulativo", � necess�rio utilizar as fun��es glPushMatrix() e glPopMatrix(), que salvam e restauram, respectivamente, a matriz atual em uma pilha interna da OpenGL.

*glTranslatef; A transla��o � feita atrav�s da fun��o glTranslatef(Tx, Ty, Tz), que pode receber tr�s n�meros float ou double (glTranslated) como par�metro. Neste caso, a matriz atual � multiplicada 
por uma matriz de transla��o baseada nos valores dados.

*glRotatef; A rota��o � feita atrav�s da fun��o glRotatef(�ngulo, x, y, z), que pode receber quatro n�meros float ou double (glRotated) como par�metro. Neste caso, a matriz atual � multiplicada por 
uma matriz de rota��o de "�ngulo" graus ao redor do eixo definido pelo vetor "x,y,z" no sentido anti-hor�rio.

*glScalef(); A escala � feita atrav�s da fun��o glScalef(Ex, Ey, Ez), que pode receber tr�s n�meros float ou double (glScaled) como par�metro. Neste caso, a matriz atual � multiplicada por uma matriz 
de escala baseada nos valores dados.

*glutTimerFunc(33, Timer, 1); estabelece a fun��o Timer previamente definida como a fun��o callback de anima��o. Seu prot�tipo �: void glutTimerFunc(unsigned int msecs, void (*func)(int value), int value);. 
Esta fun��o faz a GLUT esperar msecs milisegundos antes de chamar a fun��o func. � poss�vel passar um valor definido pelo usu�rio no par�metro value. Como esta fun��o � "disparada" apenas 
uma vez, para se ter uma anima��o cont�nua � necess�rio reinicializar o timer novamente na fun��o Timer.

*void Timer(int value) � a fun��o chamada pela glutTimerFunc. No exemplo, as vari�veis utilizadas para determinar a posi��o do ret�ngulo s�o atualizadas nesta fun��o.

Antes de prosseguir com a descri��o das fun��es, � necess�rio explicar o funcionamento do double-buffering, que � uma das caracter�sticas mais importantes em qualquer pacote gr�fico que est� 
dispon�vel na GLUT. Double-buffering permite que um desenho seja exibido na tela enquanto est� sendo realizado o rendering em um offscreen buffer. Ent�o, um comando de swap coloca a imagem 
na tela instantaneamente. Isto � �til, principalmente, por dois motivos: 
- Alguns desenhos complexos podem levar um certo tempo para serem feitos, e n�o � desejado que cada passo da composi��o da imagem seja vis�vel; ent�o, � poss�vel compor uma imagem e 
exibi-la somente depois de completa, de maneira que o usu�rio nunca v� uma imagem parcial, pois ela � exibida somente quando est� pronta. 
- No caso de uma anima��o, cada quadro (ou frame) � desenhado no offscreen buffer e � exibido (swapped) rapidamente depois de pronto.

*glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB), j� explicada anteriormente, foi usada para trocar o modo de exibi��o de GLUT_SINGLE para GLUT_DOUBLE. Isto faz com que todo o rendering 
seja feito em um offscreen buffer.

*glutSwapBuffers(); � usada no lugar da glFlush porque quando � feita a troca (ou swap) de buffers, � realizada implicitamente uma opera��o de flush. Esta fun��o continua fazendo o flush mesmo que 
o programa esteja sendo executado no modo single-buffer, por�m com uma qualidade bastante inferior.

GERENCIAMENTO DE EVENTOS
*glutKeyboardFunc 
	Estabelece a fun��o callback que � chamada pela GLUT cada vez que uma tecla que gera c�digo ASCII � pressionada (por exemplo: a, b, A, b, 1, 2). Al�m do valor ASCII da tecla, a posi��o 
(x,y) do mouse quando a tecla foi pressionada tamb�m � retornada. Par�metros de entrada da fun��o callback: (unsigned char key, int x, int y).

*glutSpecialFunc 
	Estabelece a fun��o callback que � chamada pela GLUT cada vez que uma tecla que gera c�digo n�o-ASCII � pressionada, tais como Home, End, PgUp, PgDn, F1 e F2. Al�m da constante 
que identifica a tecla, a posi��o corrente (x,y) do mouse quando a tecla foi pressionada tamb�m � retornada. Par�metros de entrada da fun��o callback: (unsigned char key, int x, int y). Os valores v�lidos 
para o primeiro par�metro s�o: GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, 
GLUT_KEY_F11, GLUT_KEY_F12, GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE_UP, GLUT_KEY_PAGE_DOWN, GLUT_KEY_HOME, GLUT_KEY_END, 
GLUT_KEY_INSERT.

*glutMouseFunc 
	Estabelece a fun��o callback que � chamada pela GLUT cada vez que ocorre um evento de mouse. Par�metros de entrada da fun��o callback: (int button, int state, int x, int y). Tr�s valores s�o v�lidos 
para o par�metro button: GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON e GLUT_RIGHT_BUTTON. O par�metro state pode ser GLUT_UP ou GLUT_DOWN. Os par�metros x e y indicam a localiza��o do 
mouse no momento que o evento ocorreu.

UTILIZANDO MENUS E EXIBINDO CARACTERES
*glutBitmapCharacter 
	Uma das fontes suportadas pela GLUT � a bitmap, onde cada caracter corresponde a um bitmap que � gerado com a fun��o glBitmap. A fun��o glutBitmapCharacter exibe um caracter deste tipo usando 
OpenGL. Os par�metros de entrada desta fun��o s�o: (void *font, int character). O primeiro par�metro identifica a fonte que ser� utilizada, e o segundo o caracter. As fontes dispon�veis s�o: GLUT_BITMAP_8_BY_13, 
GLUT_BITMAP_9_BY_15, GLUT_BITMAP_TIMES_ROMAN_10, GLUT_BITMAP_TIMES_ROMAN_24, GLUT_BITMAP_HELVETICA_10, GLUT_BITMAP_HELVETICA_12, GLUT_BITMAP_HELVETICA_18

*glutMotionFunc 
Estabelece a fun��o callback que � chamada pela GLUT cada vez que o mouse � movido sobre a janela corrente enquanto um ou mais de seus bot�es est�o pressionados. Par�metros de entrada da fun��o 
callback: (int x, int y). Os par�metros x e y indicam a posi��o do mouse em coordenadas da janela.

*glutPassiveMotionFunc 
Estabelece a fun��o callback que � chamada pela GLUT cada vez que o mouse � movido sobre a janela corrente enquanto nenhum de seus bot�es est� pressionado. Par�metros de entrada da fun��o 
callback: (int x, int y). Os par�metros x e y indicam a posi��o do mouse em coordenadas da janela.

*glutCreateMenu 
Cria um novo menu pop-up e estabelece a fun��o callback que ser� chamada pela GLUT quando uma de suas entradas for selecionada. Par�metros de entrada da fun��o callback: (int value), onde value 
corresponde ao valor que identifica a entrada do menu que foi selecionada.

*glutAddMenuEntry 
Adiciona uma entrada no final do menu corrente. Os par�metros de entrada desta fun��o s�o: (char *name, int value), onde name � o conjunto de caracteres que ser� exibido como uma entrada do menu, 
e value � o valor que ser� passado para a fun��o callback caso esta entrada seja selecionada.

*glutAddSubMenu 
Adiciona um submenu no final do menu corrente. Os par�metros de entrada desta fun��o s�o: (char *name, int menu), onde name � o conjunto de caracteres que ser� exibido como uma entrada do menu, 
a partir da qual ser� aberto o submenu, e menu � o identificador do submenu.

*glutAttachMenu 
Fun��o que "relaciona" um bot�o do mouse com o identificador do menu corrente. O par�metro de entrada desta fun��o � (int button), que corresponde ao identificador do bot�o do mouse 
(GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON ou GLUT_RIGHT_BUTTON).

DESENHANDO EM 3D

 **Arrumar o trip� e posicionar a c�mera para fotografar a cena - equivalente a especificar as transforma��es de visualiza��o (veja a fun��o gluLookAt descrita mais abaixo);

 **Arrumar a cena para ser fotografada, incluindo ou excluindo objetos/pessoas - equivalente � etapa de modelagem (inclui as tranforma��es geom�tricas, glTranslatef, glScalef, glRotatef, e o desenho dos objetos);

 **Escolher a lente da c�mera ou ajustar o zoom - equivalente a especificar as transforma��es de proje��o (veja a fun��o gluPerspective descrita mais abaixo);

 **Determinar o tamanho final da foto (maior ou menor) - equivalente a especificar a viewport (fun��es glViewport e ChangeSize).

*gluPerspective(angle,fAspect,0.1,500);Esta fun��o estabelece os par�metros da Proje��o Perspectiva, atualizando a matriz de proje��o perspectiva. Seu prot�tipo �:
void gluPerspective( GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar );. Descri��o dos par�metros: fovy � o �ngulo, em graus, na dire��o y (usada para determinar a "altura" do volume 
de visualiza��o); aspect � a raz�o de aspecto que determina a �rea de visualiza��o na dire��o x, e seu valor � a raz�o em x (largura) e y (altura); zNear, que sempre deve ter um valor positivo maior do 
que zero, � a dist�ncia do observador at� o plano de corte mais pr�ximo (em z); zFar, que tamb�m sempre tem um valor positivo maior do que zero, � a dist�ncia do observador at� o plano de corte 
mais afastado (em z). Esta fun��o sempre deve ser definida ANTES da fun��o gluLookAt, e no modo GL_PROJECTION.

*gluLookAt(0,80,200, 0,0,0, 0,1,0); define a transforma��o de visualiza��o. Atrav�s dos seus argumentos � poss�vel indicar a posi��o da c�mera e para onde ela est� direcionada. Seu prot�tipo �: 
void gluLookAt( GLdouble eyex, GLdouble eyey, GLdouble eyez, GLdouble centerx, GLdouble centery, GLdouble centerz, GLdouble upx, GLdouble upy, GLdouble upz );. Descri��o dos par�metros: 
eyex, eyey e eyez s�o usados para definir as coordenadas x, y e z, respectivamente, da posi��o da c�mera (ou observador); centerx, centery e centerz s�o usados para definir as coordenadas x, y e z, 
respectivamente, da posi��o do alvo, isto �, para onde o observador est� olhando (normalmente, o centro da cena); upx, upy e upz s�o as coordenadas x, y e z, que estabelecem o vetor up 
(indica o "lado de cima" de uma cena 3D) 

*glutWireTeapot(50.0f); � usada para desenhar o wire-frame de um teapot (ou bule de ch�). Seu prot�tipo �: 
glutWireTeapot(GLdoouble size);, onde o par�metro size indica um raio aproximado do teapot. Uma esfera com este raio ir� "envolver" totalmente o modelo


Assim como o teapot, a biblioteca GLUT tamb�m possui fun��es para desenhar outros objetos 3D. Estas fun��es est�o listadas abaixo [Woo 1999]: 
- void glutWireCube(GLdouble size); 
- void glutWireSphere(GLdouble radius, GLint slices, GLint stacks); 
- void glutWireCone(GLdouble radius, GLdouble height, GLint slices, GLint stacks); 
- void glutWireTorus(GLdouble innerRadius, GLdouble outerRadius, GLint nsides, GLint rings); 
- void glutWireIcosahedron(void); 
- void glutWireOctahedron(void); 
- void glutWireTetrahedron(void); 
- void glutWireDodecahedron(GLdouble radius); 

*obs* Os par�metros slices e stacks que aparecem no prot�tipo de algumas fun��es, significam, respectivamente, o n�mero de subdivis�es em torno do eixo z (como se fossem linhas longitudinais) 
e o n�mero de subdivis�es ao longo do eixo z (como se fossem linhas latitudinais). J� rings e nsides correspondem, respectivamente, ao n�mero de se��es que ser�o usadas para formar o torus, 
e ao n�mero de subdivis�es para cada se��o.
*obs* Todas estas fun��es tamb�m podem ser usadas para desenhar objetos s�lidos, ao inv�s de exibir apenas o seu wire-frame. Para isto, basta substituir a substring Wire do nome da fun��o por Solid.

*glShadeModel(); � usada para especificar a t�cnica de coloriza��o desejada. Inicialmente, � preciso definir o modelo de coloriza��o que ser� utilizado. OpenGL fornece dois modelos: uma pol�gono 
preenchido pode ser desenhado com uma �nica cor (GL_FLAT), ou com uma varia��o de tonalidades (GL_SMOOTH, tamb�m chamado de modelo de coloriza��o de Gouraud.

*obs* Quando objetos 3D s�lidos s�o exibidos, � importante desenhar os objetos que est�o mais pr�ximos do observador (ou posi��o da c�mera), eliminando objetos que ficam "escondidos", 
ou "parcialmente escondidos", por estes. Sendo assim,algoritmos de remo��o de elementos escondidos foram desenvolvidos para determinar as linhas, arestas, superf�cies ou volumes que 
s�o vis�veis ou n�o para um observador localizado em um ponto espec�fico no espa�o. A complexidade do problema dos elementos ocultos resultou em um grande n�mero de solu��es na Computa��o Gr�fica.
 OpenGL possui um depth buffer que trabalha atrav�s da associa��o de uma profundidade, ou dist�ncia, do plano de visualiza��o (geralmente o plano de corte mais pr�ximo do observador) com cada pixel 
da window. Inicialmente, os valores de profundidade s�o especificados para serem o maior poss�vel atrav�s do comando glClear(GL_DEPTH_BUFFER_BIT). Entretanto, habilitando o depth-buffering 
atrav�s dos comandos glutInitDisplayMode(GLUT_DEPTH | ...) e glEnable(GL_DEPTH_TEST), antes de cada pixel ser desenhado � feita uma compara��o com o valor de profundidade j� armazenado. 
Se o valor de profundidade for menor (est� mais pr�ximo) o pixel � desenhado e o valor de profundidade � atualizado. Caso contr�rio as informa��es do pixel s�o desprezadas.Em OpenGL a cor de uma fonte 
de luz � caracterizada pela quantidade de vermelho (R), verde (G) e azul (B) que ela emite, e o material de uma superf�cie � caracterizado pela porcentagem dos componentes R, G e B que chegam 
e s�o refletidos em v�rias dire��es. No modelo de ilumina��o a luz em uma cena vem de v�rias fontes de luz que podem ser "ligadas" ou "desligadas" individualmente. A luz pode vir de uma dire��o ou 
posi��o (por exemplo, uma l�mpada) ou como resultado de v�rias reflex�es (luz ambiente - n�o � poss�vel determinar de onde ela vem, mas ela desaparece quando a fonte de luz � desligada).No modelo de ilumina��o OpenGL a fonte de luz tem efeito somente 
quando existem superf�cies que absorvem e refletem luz. Assume-se que cada superf�cie � composta de um material com v�rias propriedades. O material pode emitir luz, refletir parte da luz incidente em todas as 
dire��es, ou refletir uma parte da luz incidente numa �nica dire��o, tal com um espelho. Ent�o, OpenGL considera que a luz � dividida em quatro componentes independentes (que s�o colocadas juntas):
		*Ambiente: resultado da luz refletida no ambiente; � uma luz que vem de todas as dire��es;
		*Difusa: luz que vem de uma dire��o, atinge a superf�cie e � refletida em todas as dire��es; assim, parece possuir o mesmo brilho independente de onde a c�mera est� posicionada;
		*Especular: luz que vem de uma dire��o e tende a ser refletida numa �nica dire��o;
		*Emissiva: simula a luz que se origina de um objeto; a cor emissiva de uma superf�cie adiciona intensidade ao objeto, mas n�o � afetada por qualquer fonte de luz; 
			ela tamb�m n�o introduz luz adicional da cena.
A cor do material de um objeto depende da porcentagem de luz vermelha, verde e azul incidente que ele reflete. Assim como as luzes, o material possui cor ambiente, difusa e especular diferentes, que 
determinam como ser� a luz refletida. Isto � combinado com as propriedades das fontes de luz, de tal maneira que a reflex�o ambiente e difusa definem a cor do material. A especular � geralmente cinza ou branca.
Os componentes de cor especificados para a luz possuem um significado diferente dos componentes de cor especificados para os materiais. Para a luz, os n�meros correspondem a uma porcentagem da 
intensidade total para cada cor. Se os valores R, G e B para a cor da luz s�o 1, a luz � branca com o maior brilho poss�vel. Se os valores s�o 0.5 a cor ainda � branca, mas possui metade da intensidade, 
por isso parece cinza. Se R=G=1 e B=0, a luz parece amarela.Para os materiais, os n�meros correspondem �s propor��es refletidas destas cores. Se R=1, G=0.5 e B=0 para um material, este material reflete 
toda luz vermelha incidente, metade da luz verde e nada da luz azul. Assim, simplificadamente, a luz que chega no observador � dada por (LR.MR, LG.MG, LB.MB), onde (LR, LG, LB) s�o os componentes da luz 
e (MR, MG, MB) os componentes do material.

*glShadeModel(GL_SMOOTH); estabelece o modelo de coloriza��o: GL_FLAT (a cor n�o varia na primitiva que � desenhada - um exemplo de primitiva � o tri�ngulo); ou GL_SMOOTH (a cor de cada ponto da 
primitiva � interpolada a partir da cor calculada nos v�rtices). Seu prot�tipo �: void glShadeModel(GLenum mode);. Descri��o dos par�metros: mode especifica o modelo de coloriza��o, sendo que o default 
� GL_SMOOTH.

*glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade); estabelece os par�metros do material que ser�o usados pelo modelo de ilumina��o. Possui algumas varia��es cujos prot�tipos s�o: 
*glMaterialf(GLenum face, GLenum pname, GLfloat param); 
*glMateriali(GLenum face, GLenum pname, GLint param); 
*glMaterialfv(GLenum face, GLenum pname, const GLfloat *params); 
*glMaterialiv(GLenum face, GLenum pname, const GLint *params); 
Descri��o dos par�metros: 
-face determina se as propriedades do material dos pol�gonos que est�o sendo especificadas s�o front (GL_FRONT), back (GL_BACK) ou ambas (GL_FRONT_AND_BACK); 
-pname para as duas primeiras varia��es especifica o par�metro de um �nico valor que est� sendo determinado (atualmente apenas GL_SHININESS possui um �nico valor como par�metro); para as duas 
�ltimas varia��es, que recebem um vetor como par�metro, pode determinar as seguintes propriedades do material: GL_AMBIENT, GL_DIFFUSE, GL_SPECULAR, GL_EMISSION, GL_SHININESS, 
GL_AMBIENT_AND_DIFFUSE ou GL_COLOR_INDEXES; 
-param (GLfloat ou GLint) especifica o valor que ser� atribu�do para o par�metro determinado por pname (neste caso, GL_SHININESS); 
-params (GLfloat* ou GLint*) um vetor de n�meros reais ou inteiros que cont�m as componentes da propriedade que est� sendo espeficada; 
Atrav�s desta fun��o � poss�vel determinar as propriedades de reflet�ncia do material dos pol�gonos. As propriedades GL_AMBIENT, GL_DIFFUSE e GL_SPECULAR afetam a maneira na qual as 
componentes de luz incidente s�o refletidas. GL_EMISSION � usado para materiais que possuem "luz pr�pria". GL_SHININESS pode variar de 0 a 128 (quanto maior o valor, maior � a �rea de 
highlight especular na superf�cie). GL_COLOR_INDEXES � usado para as propriedades de reflet�ncia do material no modo de �ndice de cores.

*glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente); estabelece os par�metros do modelo de ilumina��o usado por OpenGL. � poss�vel especificar um, ou todos os tr�s modelos: 
- GL_LIGHT_MODEL_AMBIENT � usado para especificar a luz ambiente default para uma cena, que tem um valor RGBA default de (0.2, 0.2, 0.2, 1.0); 
- GL_LIGHT_MODEL_TWO_SIDE � usado para indicar se ambos os lados de um pol�gono s�o iluminados (por default apenas o lado frontal � iluminado); 
- GL_LIGHT_MODEL_LOCAL_VIEWER modifica o c�lculo dos �ngulos de reflex�o especular; 
Possui algumas varia��es cujos prot�tipos s�o: 
*glLightModelf(GLenum pname, GLfloat param); 
*glLightModeli(GLenum pname, GLint param); 
*glLightModelfv(GLenum pname, const GLfloat *params); 
*glLightModeliv(GLenum pname, const GLint *params); 
Descri��o dos par�metros: 
-pname especifica um par�metro do modelo de ilumina��o: GL_LIGHT_MODEL_AMBIENT, GL_LIGHT_MODEL_LOCAL_VIEWER ou GL_LIGHT_MODEL_TWO_SIDE; 
-param (GLfloat ou GLint) para GL_LIGHT_MODEL_LOCAL_VIEWER um valor 0.0 indica que os �ngulos da componente especular tomam a dire��o de visualiza��o como sendo paralela ao eixo z, 
e qualquer outro valor indica que a visualiza��o ocorre a partir da origem do sistema de refer�ncia da c�mera; para GL_LIGHT_MODEL_TWO_SIDE um valor 0.0 indica que somente os pol�gonos 
frontais s�o inclu�dos nos c�lculos de ilumina��o, e qualquer outro valor indica que todos os pol�gonos s�o inclu�dos nos c�lculos de ilumina��o; 
-params (GLfloat* ou GLint*) para GL_LIGHT_MODEL_AMBIENT ou GL_LIGHT_MODEL_LOCAL_VIEWER, aponta para um vetor de n�meros inteiros ou reais; para GL_LIGHT_MODEL_AMBIENT o 
conte�do do vetor indica os valores das componentes RGBA da luz ambiente.

*glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); estabelece os par�metros da fonte de luz para uma das oito fontes de luz dispon�veis. Possui algumas varia��es cujos prot�tipos s�o: 
*glLightf(GLenum light, GLenum pname, GLfloat param); 
*glLighti(GLenum light, GLenum pname, GLint param); 
*glLightfv(GLenum light, GLenum pname, const GLfloat *params); 
*glLightiv(GLenum light, GLenum pname, const GLint *params); 
As duas primeiras varia��es requerem apenas um �nico valor para determinar uma das seguintes propriedades: GL_SPOT_EXPONENT, GL_SPOT_CUTOFF, GL_CONSTANT_ATTENUATION, 
GL_LINEAR_ATTENUATION e GL_QUADRATIC_ATTENUATION. As duas �ltimas varia��es s�o usadas para par�metros de luz que requerem um vetor com m�ltiplos valores (GL_AMBIENT, GL_DIFFUSE, 
GL_SPECULAR, GL_POSITION e GL_SPOT_DIRECTION). 
Descri��o dos par�metros: 
-light especifica qual fonte de luz est� sendo alterada (varia de 0 a GL_MAX_LIGHTS); valores constantes de luz s�o enumerados de GL_LIGHT0 a GL_LIGHT7 
-pname especifica qual par�metro de luz est� sendo determinado pela chamada desta fun��o (GL_AMBIENT, GL_DIFFUSE, GL_SPECULAR, GL_POSITION, GL_SPOT_DIRECTION, GL_SPOT_EXPONENT, 
GL_SPOT_CUTOFF. GL_CONSTANT_ATTENUATION, GL_LINEAR_ATTENUATION, GL_QUADRATIC_ATTENUATION); 
-param (GLfloat ou GLint) para par�metros que s�o especificados por um �nico valor (param); estes par�metros, v�lidos somente para spotlights, s�o GL_SPOT_EXPONENT, GL_SPOT_CUTOFF, 
GL_CONSTANT_ATTENUATION, GL_LINEAR_ATTENUATION e GL_QUADRATIC_ATTENUATION. 
-params (GLfloat* ou GLint*) um vetor de valores que descrevem os par�metros que est�o sendo especificados.

*glEnable(GL_COLOR_MATERIAL); conforme j� explicado no cap�tulo 6, a fun��o glEnable � usada para habilitar uma vari�vel de estado OpenGL. Neste caso, est�o sendo habilitadas: GL_COLOR_MATERIAL 
(atribui a cor para o material a partir da cor corrente), GL_DEPTH_TEST (controla as compara��es de profundidade e atualiza o depth buffer), GL_LIGHTING (habilita a ilumina��o) e GL_LIGHT0
 (habilita a luz de n�mero 0).

*glutSwapBuffers(); e glutInitDisplayMode(GLUT_DOUBLE...); j� explicadas anteriormente, s�o usadas para evitar que a imagem fique "piscando" a cada intera��o (por exemplo, quando se faz zoom-in e zoom-out).

*obs* Tamb�m � poss�vel eliminar o "brilho" do objeto, como se o material fosse opaco. Neste caso, basta eliminar a componente especular removendo as seguintes linhas do c�digo fonte: 
     GLfloat especularidade[4]={1.0,1.0,1.0,1.0}; 
     GLint especMaterial = 60; 
     glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade); 
     glMateriali(GL_FRONT,GL_SHININESS,especMaterial); 
     glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );

*obs*Quando se trabalha com uma malha, normalmente s�o passadas como argumento para a fun��o glBegin() as primitivas GL_QUADS, GL_POLYGON e GL_TRIANGLES (cap�tulo 9). 
GL_TRIANGLE_STRIP e GL_QUAD_STRIP tamb�m podem ser usadas, desde que se tenha certeza de que os v�rtices e faces est�o ordenados da maneira correta.
Conforme se observa no c�digo acima, � necess�rio informar o vetor normal normal de cada face, pois OpenGL usa esta informa��o para calcular a cor de cada face de acordo com os 
par�metros de ilumina��o. A fun��o usada para especificar o vetor normal � glNormal3f, e os seus par�metros s�o as componentes x, y e z do vetor normal, respectivamente.













