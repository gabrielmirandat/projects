#include <GL/glew.h>
#include <GL/freeglut.h>
#include "../../include/Angel.h"

typedef Angel::vec4 point4;


void mydisplay( void );
void init( void );



point4 points[4] = {
  point4( -50, -50, 0, 1 ),//notem a coordenada em Z
  point4(  50, -50, 0, 1 ),// Z == 0
  point4(  50,  50, 0, 1 ),//notem a coordenada em Z
  point4( -50,  50, 0, 1 ),// Z == 0
};


mat4 Model;
GLuint modelLoc;

int main (int argc, char** argv) {
  glutInit( &argc, argv);
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );

  glutInitWindowSize( 800, 800 );
  glutCreateWindow( "Quadrado!" );

  glewInit();

  glutDisplayFunc( mydisplay );
  init();

  glutMainLoop();

}

void mydisplay( void ) {
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  /* Como as coordenadas dos vértices estão fora do 
         Volume de Modelagem Canônico (-1, 1, -1, 1, -1, 1)
     precisamos colocar as coordenadas dentro. Para isso, faremos
     uma redução de escala das coordenadas em 1/100.
   */
  Model = Scale( .01 );
  glUniformMatrix4fv(modelLoc, 1, GL_TRUE, Model);

  glDrawArrays( GL_TRIANGLE_FAN, 0, 4);

  glutSwapBuffers();
}



void init( void ) {
  // Load shaders and use the resulting shader program
  GLuint program = InitShader( "ex2.vert", "tri.frag" );
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

  glClearColor( 1.0, 1.0, 1.0, 1.0 );
}
