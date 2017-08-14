#include <GL/glew.h>
#include <GL/freeglut.h>
#include "../../include/Angel.h"

typedef Angel::vec4 point4;
typedef Angel::vec4 color4;

void mydisplay( void );
void init( void );
void idle( void );

const int NumVertices = 3;


point4 points[6*NumVertices] = {
  /* giro antihorário na  base */
  point4( -.5, -.5,  .5, 1 ), //P0 Base
  point4(  .5, -.5,  .5, 1 ), //P1 Base
  point4(  .5, -.5, -.5, 1 ), //P2 Base
  
  point4(  .5, -.5, -.5, 1 ), //P2 Base
  point4( -.5, -.5, -.5, 1 ), //P3 Base
  point4( -.5, -.5,  .5, 1 ), //P0 Base
  /* Fim da especificação da base */

  point4( -.5, -.5,  .5, 1 ), //P0 Face Frontal
  point4(  .5, -.5,  .5, 1 ), //P1 Face Frontal
  point4(   0,  .5,   0, 1 ), //P4 Face Frontal

  point4(  .5, -.5, -.5, 1 ), //P2 Face Posterior
  point4( -.5, -.5, -.5, 1 ), //P3 Face Posterior
  point4(   0,  .5,   0, 1 ), //P4 Face Posterior

  point4(  .5, -.5,  .5, 1 ), //P1 Lateral Direita
  point4(  .5, -.5, -.5, 1 ), //P2 Lateral Direita
  point4(   0,  .5,   0, 1 ), //P4 Lateral Direita

  point4( -.5, -.5, -.5, 1 ), //P3 Lateral Esquerda
  point4( -.5, -.5,  .5, 1 ), //P0 Lateral Esquerda
  point4(   0,  .5,   0, 1 ), //P4 Lateral Esquerda

};

color4 colors[6*NumVertices] = {
  color4( 1, 0, 0, 1 ),//red
  color4( 1, 0, 0, 1 ),//red
  color4( 1, 0, 0, 1 ),//red
  color4( 1, 0, 0, 1 ),//red
  color4( 1, 0, 0, 1 ),//red
  color4( 1, 0, 0, 1 ),//red

  color4( 0, 1, 0, 1 ),//green
  color4( 0, 1, 0, 1 ),//green
  color4( 0, 1, 0, 1 ),//green

  color4( 1, 1, 0, 1 ),//yellow
  color4( 1, 1, 0, 1 ),//yellow
  color4( 1, 1, 0, 1 ),//yellow

  color4( 0, 0, 1, 1 ),//blue
  color4( 0, 0, 1, 1 ),//blue
  color4( 0, 0, 1, 1 ),//blue

  color4( 1, 0, 1, 1 ),//magenta
  color4( 1, 0, 1, 1 ),//
  color4( 1, 0, 1, 1 ),//

};


GLuint mvmLoc; // The location of the modelview matrix shader uniform variable
mat4 ModelView;
/* A  matriz  de  modelagem  e  visualização  (vulgo  ModelView)  será
 iniciada no lado cliente.  Permite colocar cópias da geometria básica
 com propriedades distintas em locais diferentes */


GLfloat angulo = 0;
GLuint theta;


int main (int argc, char** argv) {
  glutInit( &argc, argv);
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize( 800, 800 );
  glutCreateWindow( "Piramide" );

  glutDisplayFunc( mydisplay );
  glutIdleFunc( idle );

  glewInit();

  init();

  glutMainLoop();

}





void mydisplay( void ) {
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

  glUniform1f( theta, angulo );
  /* Início da primeira pirâmide */
  ModelView = RotateY(angulo) * Scale(.35) * Translate(0, -.288675, 0.5);
  glUniformMatrix4fv(mvmLoc, 1, GL_TRUE, ModelView);
  glDrawArrays( GL_TRIANGLES, 0, 6*NumVertices);
  /* Fim da primeira pirâmide */

  /* Início da segunda pirâmide */
  ModelView = RotateY(3*angulo) * Translate(0, 0, .75) * Scale(.225);
  glUniformMatrix4fv(mvmLoc, 1, GL_TRUE, ModelView);
  glDrawArrays( GL_TRIANGLES, 0, 6*NumVertices);
  /* Fim da segunda pirâmide */

   /* Início da terceira pirâmide */
  ModelView = ModelView * RotateY(10*angulo)* Translate(0, 0, .95) * Scale(.175);
  /* Faz a 3ª pirâmide  ser um satélite da 2ª, ou seja,  a 3ª gira em
     torno da  2ª e o conjunto  gira em torno  da 1ª (que gira  em seu
     próprio eixo Y)!
   */
  glUniformMatrix4fv(mvmLoc, 1, GL_TRUE, ModelView);
  glDrawArrays( GL_TRIANGLES, 0, 6*NumVertices);
  /* Fim da terceira pirâmide */

  glutSwapBuffers();
}



void idle ( void ) {
  angulo += .25;
  glutPostRedisplay();
}

void init( void ) {
  // Load shaders and use the resulting shader program
  GLuint program = InitShader( "tri.vert", "tri.frag" );
  glUseProgram( program );

  // Create a vertex array object
  GLuint vao;
  glGenVertexArrays( 1, &vao );
  glBindVertexArray( vao );

  // Create and initalize a buffer object
  GLuint buffer;
  glGenBuffers( 1, &buffer );
  glBindBuffer( GL_ARRAY_BUFFER, buffer );
  glBufferData( GL_ARRAY_BUFFER, sizeof(points) + sizeof(colors), NULL, GL_STATIC_DRAW );
  glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(points), points);
  glBufferSubData( GL_ARRAY_BUFFER, sizeof(points), sizeof(colors), colors);


  // set up vertex arrays
  GLuint vPosition = glGetAttribLocation( program, "vPosition" );
  glEnableVertexAttribArray( vPosition );
  glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0, 
          BUFFER_OFFSET(0) );

  GLuint vColor = glGetAttribLocation( program, "vColor" );
  glEnableVertexAttribArray( vColor );
  glVertexAttribPointer( vColor, 4, GL_FLOAT, GL_FALSE, 0,
			 BUFFER_OFFSET(sizeof(points)) );

  mvmLoc = glGetUniformLocation( program, "mvm" );
  theta = glGetUniformLocation( program, "theta" );

  glEnable(GL_DEPTH_TEST);
  //glEnable(GL_CULL_FACE);

  glClearColor( .9, .9, .9, 1.0 );
}
