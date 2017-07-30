//Aluno: Gabriel Martins de Miranda
//Matricula: 13/0111350

#include <GL/glew.h> 		//GLEW fornece mecanismos de tempo de execução eficientes para determinar quais extensões OpenGL são suportados
				//na plataforma de destino
#include <GL/freeglut.h>	//GLUT cria a comunicação entre a openGL e o sistema operacional vigente
#include "../../include/Angel.h"	//inclui header de definição do Angel::vec4 e cria interface com InitShader.cpp

typedef Angel::vec4 point4;	//define um ponto de 4 posições
typedef Angel::vec4 color4;	//define vetor color4 de 4 posições

void mydisplay( void );	//função callback para glutDisplayFunc()
void init( void );	//função de controle entre a CPU e a GPU, define o vertex shader e o fragment shader

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

color4 cor[7] = {			//cria as 3 cores que são usadas para definir pontos do hexágono
  color4( 0.0, 0.0, 0.0, 1.0 ),//1
  color4( 1.0, 0.0, 0.0, 1.0 ),//2
  color4( 0.0, 1.0, 0.0, 1.0 ),//3
  color4( 0.0, 0.0, 1.0, 1.0 ),//4
  color4( 1.0, 1.0, 0.0, 1.0 ),//5
  color4( 1.0, 0.0, 1.0, 1.0 ),//6
  color4( 0.0, 1.0, 1.0, 1.0 ),//7
};	

color4 colors[18] = {cor[0],cor[1],cor[2],cor[0],cor[2],cor[3],cor[0],cor[3],cor[4],cor[0],cor[4],
		     cor[5],cor[0],cor[5],cor[6],cor[0],cor[6],cor[1] };
		     

int main (int argc, char** argv) {
  glutInit( &argc, argv);	//inicializa a biblioteca glut					
  glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB ); //define o modo de exibição inicial (no caso usando só o buffer principal e cores RGBA)
  glutInitWindowSize( 800, 800 );		 //seta o tamanho da janela a ser mostrada (no caso, 800x800 pixels)
  glutCreateWindow( "Hexágono" );		 //cria janela cujo tamanho foi definido anteriormente, cujo identificador é Hexágono. 
  
  glutDisplayFunc( mydisplay );			 //define o callback para exibição da janela atual
  
  glewInit();	//inicializa biblioteca glew ()
  
  init();
  
  glutMainLoop();	//entra no ciclo de eventos glut, esperando entradas do usuário.
  
}

void mydisplay( void ) {
  glClear( GL_COLOR_BUFFER_BIT );	//limpa o buffer com as cores definidas em glClearColor.

  glDrawArrays( GL_TRIANGLES, 0, 18);	//renderiza primitivas do array de dados.

  glFlush();				//leva tudo o que foi criado nos buffers e imprime na tela para que possamos ver.
}

void init( void ) {
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
  glBufferData( GL_ARRAY_BUFFER, sizeof(points) + sizeof(colors),
		NULL, GL_STATIC_DRAW );	//aloca espaço na GPU para o buffer object
  glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(points), points);	//atualiza um subconjunto de armazenamento de dados de um buffer object
  glBufferSubData( GL_ARRAY_BUFFER, sizeof(points), sizeof(colors), colors);
  
  // Seta os arrays de vértices
  GLuint vPosition = glGetAttribLocation( program, "vPosition" );	//Retorna a localização de uma variável atributo das posições
  glEnableVertexAttribArray( vPosition );	//ativa o atributo do array de vértices
  glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0, 
          BUFFER_OFFSET(0) );	//define um array de vértices dos dados do atributo das posições
  
  GLuint vColor = glGetAttribLocation( program, "vColor" );		////Retorna a localização de uma variável atributo das cores
  glEnableVertexAttribArray( vColor );		//ativa o atributo do array de cores
  glVertexAttribPointer( vColor, 4, GL_FLOAT, GL_FALSE, 0,
	  BUFFER_OFFSET(sizeof(points)) );	//define um array de vértices dos dados do atributo das cores


  glClearColor( 1.0, 1.0, 1.0, 1.0 );	//define a cor de limpar a tela como branco
}


