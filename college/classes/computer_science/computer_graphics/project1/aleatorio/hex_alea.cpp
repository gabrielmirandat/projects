//Aluno: Gabriel Martins de Miranda
//Matricula: 13/0111350

#include <GL/glew.h> 		//GLEW fornece mecanismos de tempo de execução eficientes para determinar quais extensões OpenGL são suportados
				//na plataforma de destino
#include <GL/freeglut.h>	//GLUT cria a comunicação entre a openGL e o sistema operacional vigente
#include "../../include/Angel.h"	//inclui header de definição do Angel::vec4 e cria interface com InitShader.cpp

typedef Angel::vec4 point4;	//define um ponto de 4 posições
typedef Angel::vec4 color4;	//define color4 como um vetor de 4 posições

void mydisplay( void );	//função callback para glutDisplayFunc()
void init( void );	//função de controle entre a CPU e a GPU, define o vertex shader e o fragment shader
void idle( void);	//função callback de inatividade. É contuamente chamada enquanto não há eventos para manusear.

point4 vertice[7] = {			//cria os pontos do hexágono, precisamos de 7
  point4( 0.0, 0.0, 0.0, 1.0 ),//1
  point4( 0.5, 0.0, 0.0, 1.0 ),//2
  point4( 0.25, 0.43,0.0, 1.0 ),//3
  point4(-0.25, 0.43,0.0, 1.0 ),//4
  point4(-0.5, 0.0, 0.0, 1.0 ),//5
  point4(-0.25,-0.43,0.0, 1.0 ),//6
  point4( 0.25,-0.43,0.0, 1.0 ) //7
};

point4 points[18] = {vertice[0],vertice[1],vertice[2],vertice[0],vertice[2],vertice[3],vertice[0],vertice[3],vertice[4],vertice[0],vertice[4],
		     vertice[5],vertice[0],vertice[5],vertice[6],vertice[0],vertice[6],vertice[1] };

GLfloat Theta[3] = { 0.0, 0.5, 0.0 };
GLuint theta; // The location of the "theta" shader uniform variable
		     
int main (int argc, char** argv) {
  glutInit( &argc, argv);	//inicializa a biblioteca glut					
  glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB ); //define o modo de exibição inicial (no caso usando só o buffer principal e cores RGBA)
  glutInitWindowSize( 800, 800 );		 //seta o tamanho da janela a ser mostrada (no caso, 800x800 pixels)
  glutCreateWindow( "Hexágono" );		 //cria janela cujo tamanho foi definido anteriormente, cujo identificador é Hexágono. 
  
  glutDisplayFunc( mydisplay );			 //define o callback para exibição da janela atual
  glutIdleFunc( idle );				 //define o callbck para inatividade
  
  glewInit();	//inicializa biblioteca glew ()
  
  init();
  
  glutMainLoop();	//entra no ciclo de eventos glut, esperando entradas do usuário.
  
}

void mydisplay( void ) {
  glClear( GL_COLOR_BUFFER_BIT );	//limpa o buffer com as cores definidas em glClearColor.

  glUniform3fv( theta, 1, Theta);	//especifica o valor da variável uniforme para o atual objeto do programa
  
  glDrawArrays( GL_TRIANGLES, 0, 18);	//renderiza primitivas do array de dados.

  glFlush();				//leva tudo o que foi criado nos buffers e imprime na tela para que possamos ver.
}

void idle ( void ) {
  static GLfloat angle = rand()%90;

  Theta[0] = sin(angle);		//define as cores aleatórias do hexágono
  Theta[1] = cos(angle);
  Theta[2] = Theta[1]+Theta[0];
  angle += 0.005;

  glutPostRedisplay();
}

void init( void ) {
  
  srand(time(NULL));
  
  // Carrega os shaders e usa o programa de shader resultante
  GLuint program = InitShader( "shader.vert", "shader.frag" );	//Carrega os programas de definição do vertex shader e do fragment shader
  glUseProgram( program );		//Instala um objeto programa como parte do estado de renderização atual.

  // Cria um vertex array object
  GLuint vao;		//container para o vertex array objetct
  glGenVertexArrays( 1, &vao );	//gera nome do vertex array object
  glBindVertexArray( vao );	//vincula o vertex array object

  // Cria e inicializa um buffer object
  GLuint buffer;	//container para o buffer object
  glGenBuffers( 1, &buffer );	//gera nome do buffer object
  glBindBuffer( GL_ARRAY_BUFFER, buffer );	//vincula o buffer object
  glBufferData( GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW );	//aloca espaço na GPU para o buffer object

  // Seta os arrays de vértices
  GLuint vPosition = glGetAttribLocation( program, "vPosition" );	//Retorna a localização de uma variável atributo
  glEnableVertexAttribArray( vPosition );	//ativa o atributo do array de vértices
  glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0, 
          BUFFER_OFFSET(0) );	//define um array de vértices dos dados do atributo

  theta = glGetUniformLocation( program, "theta" );	//retorna a localização da variável uniforme
  
  glClearColor( 1.0, 1.0, 1.0, 1.0 );	//define a cor de limpar a tela como branco
}


