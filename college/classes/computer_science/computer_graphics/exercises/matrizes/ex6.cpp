#include <GL/glew.h>
#include <GL/freeglut.h>
#include "../../include/Angel.h"

typedef Angel::vec4 point4;


void mydisplay( void );
void init( void );


//Os pontos definem um Quadrado num plano a 45º com respeito ao Plano Y = 0
point4 points[4] = {
  point4( -50, -50,  50, 1 ),//notem a coordenada em Z
  point4(  50, -50,  50, 1 ),// Z == 50
  point4(  50,  50, -50, 1 ),//notem a coordenada em Z
  point4( -50,  50, -50, 1 ),// Z == -50
};

mat4 Model;
GLuint modelLoc;
mat4 View;
GLuint viewLoc;
mat4 Projecao;
GLuint projLoc;

int main (int argc, char** argv) {
  glutInit( &argc, argv);
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );

  glutInitWindowSize( 800, 800 );
  glutCreateWindow( "Quadrado centrado na Origem!" );

  glewInit();

  glutDisplayFunc( mydisplay );
  init();

  glutMainLoop();

}

void mydisplay( void ) {
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  /* Como as coordenadas dos vértices estão fora do 
         Volume de Modelagem Canônico (-1, 1, -1, 1, -1, 1)
     precisamos colocar as coordenadas dentro. 
   */

  Model = Scale(.01) * RotateY(89); 
  glUniformMatrix4fv(modelLoc, 1, GL_TRUE, Model);
  /*
     Vamos agora deslocar a câmera na direção positiva de Z
     (ou, dá na mesma, o frame de modelagem na direção negativa de Z)
   */
  View = Translate( 0, 0, -2 );
  glUniformMatrix4fv(viewLoc, 1, GL_TRUE, View);

  /*
    Agora vamos projetar o nosso modelo conforme visto pela câmera
    na posição (0, 0 -2) só que em perspectiva através de uma lente 
    com abertura de 30º (em Y). Notem que quanto maior o ângulo mais 
    distante a figura parece estar.
   */
  //Projecao = Ortho(-1,1,-1,1,-1000,1000);
  Projecao = Perspective(60, 1, 1, 100);
  glUniformMatrix4fv(projLoc, 1, GL_TRUE, Projecao);

  glDrawArrays( GL_TRIANGLE_FAN, 0, 4);

  glutSwapBuffers();
}



void init( void ) {
  // Load shaders and use the resulting shader program
  GLuint program = InitShader( "ex4.vert", "tri.frag" );
  glUseProgram( program );

  // Create a vertex array object
  GLuint vao;
  glGenVertexArrays( 1, &vao );
  glBindVertexArray( vao );

  // Create and initalize a buffer object
  GLuint buffer;
  glGenBuffers( 1, &buffer );
  glBindBuffer( GL_ARRAY_BUFFER, buffer );
  glBufferData( GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW );

  // set up vertex arrays
  GLuint vPosition = glGetAttribLocation( program, "vPosition" );
  glEnableVertexAttribArray( vPosition );
  glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0, 
          BUFFER_OFFSET(0) );

  modelLoc = glGetUniformLocation( program, "model" );
  glUniformMatrix4fv(modelLoc, 1, GL_TRUE, Model);

  viewLoc = glGetUniformLocation( program, "view" );
  glUniformMatrix4fv(viewLoc, 1, GL_TRUE, View);

  projLoc = glGetUniformLocation( program, "proj" );
  glUniformMatrix4fv(projLoc, 1, GL_TRUE, Projecao);

  glClearColor( 1.0, 1.0, 1.0, 1.0 );
}
