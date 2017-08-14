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
  /* giro antihorário na face interna da base
  point4( -.5, -.5,  .5, 1 ), //P0 Base
  point4(  .5, -.5,  .5, 1 ), //P1 Base
  point4(  .5, -.5, -.5, 1 ), //P2 Base
  //
  point4(  .5, -.5, -.5, 1 ), //P2 Base
  point4( -.5, -.5, -.5, 1 ), //P3 Base
  point4( -.5, -.5,  .5, 1 ), //P0 Base
  */
  point4( -.5, -.5,  .5, 1 ), //P0 Base
  point4(  .5, -.5, -.5, 1 ), //P2 Base
  point4(  .5, -.5,  .5, 1 ), //P1 Base
  point4( -.5, -.5,  .5, 1 ), //P0 Base
  point4( -.5, -.5, -.5, 1 ), //P3 Base
  point4(  .5, -.5, -.5, 1 ), //P2 Base
  //o giro acima é horario


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


mat4 ModelView;
GLuint mvmLoc; 


mat4 Projecao = Perspective(20, 1, 1, 100);
//quanto menor o ângulo, mais próximo (maior) os objetos parecerão
GLuint projLoc;

GLfloat angulo = 0.0;


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

  mat4 View = Translate(0, 0, -25);

  ModelView =   View * Scale(1.5, 1.5, 1.5) * RotateY(3*angulo);
  glUniformMatrix4fv(mvmLoc, 1, GL_TRUE, ModelView);
  glDrawArrays( GL_TRIANGLES, 0, 6*NumVertices);


 
  ModelView =  ModelView*Scale(.5,.5,.5)*Translate(0,0,-10)*RotateY(2*angulo);
  glUniformMatrix4fv(mvmLoc, 1, GL_TRUE, ModelView);
  glDrawArrays( GL_TRIANGLES, 0, 6*NumVertices);

 

  ModelView = ModelView*RotateX(9*angulo)*Scale(.25,.25,.25)*Translate(0,0,-3);
  glUniformMatrix4fv(mvmLoc, 1, GL_TRUE, ModelView);
  glDrawArrays( GL_TRIANGLES, 0, 6*NumVertices);

  //**************************************************
  //**************************************************
  const float pi = 3.141592;
  float c1 = cos(pi/4)/sin(pi/4);
  float c2 = cos(pi/8)/sin(pi/8);

  mat4 torto = mat4(1,   0,     0,   0, 
                    0,   1,     0,   0, 
                  -c1, -c2,     1,   0, 
                    0,   0,     0,   1 );


  ModelView = Scale(.8, -.8, .8) * torto * Translate(-5,-2.5,-50) * RotateY(5*angulo);
  // descomente a linha abaixo para por em movimento
  //ModelView = 0.0015 * RotateY(10*angulo) * ModelView;
  glUniformMatrix4fv(mvmLoc, 1, GL_TRUE, ModelView);
  glDrawArrays( GL_TRIANGLES, 0, 6*NumVertices);



  glUniformMatrix4fv(projLoc, 1, GL_TRUE, Projecao);

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
  projLoc = glGetUniformLocation( program, "proj" );

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  glClearColor( .9, .9, .9, 1.0 );
}
